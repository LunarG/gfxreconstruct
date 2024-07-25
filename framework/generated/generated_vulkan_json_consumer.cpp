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

using util::JsonOptions;

void VulkanExportJsonConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateInstance");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pInstance"], pInstance, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyInstance");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pPhysicalDeviceCount"], pPhysicalDeviceCount, json_options);
        HandleToJson(args["pPhysicalDevices"], pPhysicalDevices, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFeatures"], pFeatures, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["type"], type, json_options);
        FieldToJson(args["tiling"], tiling, json_options);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options);
        FieldToJson(VkImageCreateFlags_t(), args["flags"], flags, json_options);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pDevice"], pDevice, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDevice");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["queueIndex"], queueIndex, json_options);
        HandleToJson(args["pQueue"], pQueue, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["submitCount"], submitCount, json_options);
        FieldToJson(args["pSubmits"], pSubmits, json_options);
        HandleToJson(args["fence"], fence, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueWaitIdle");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeviceWaitIdle");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pMemory"], pMemory, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeMemory");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["size"], size, json_options);
        FieldToJson(VkMemoryMapFlags_t(), args["flags"], flags, json_options);
        FieldToJsonAsHex(args["ppData"], ppData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["memoryRangeCount"], memoryRangeCount, json_options);
        FieldToJson(args["pMemoryRanges"], pMemoryRanges, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["memoryRangeCount"], memoryRangeCount, json_options);
        FieldToJson(args["pMemoryRanges"], pMemoryRanges, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryCommitment");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["pCommittedMemoryInBytes"], pCommittedMemoryInBytes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["memoryOffset"], memoryOffset, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["memoryOffset"], memoryOffset, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["type"], type, json_options);
        FieldToJson(args["samples"], samples, json_options);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options);
        FieldToJson(args["tiling"], tiling, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfo"], pBindInfo, json_options);
        HandleToJson(args["fence"], fence, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pFence"], pFence, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFence");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["fence"], fence, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["fenceCount"], fenceCount, json_options);
        HandleToJson(args["pFences"], pFences, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceStatus");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["fence"], fence, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["fenceCount"], fenceCount, json_options);
        HandleToJson(args["pFences"], pFences, json_options);
        Bool32ToJson(args["waitAll"], waitAll, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSemaphore"], pSemaphore, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySemaphore");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["semaphore"], semaphore, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pEvent"], pEvent, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyEvent");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEventStatus");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["event"], event, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetEvent");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["event"], event, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetEvent");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["event"], event, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pQueryPool"], pQueryPool, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyQueryPool");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
        FieldToJson(args["queryCount"], queryCount, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
        FieldToJson(args["stride"], stride, json_options);
        FieldToJson(VkQueryResultFlags_t(), args["flags"], flags, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pBuffer"], pBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBuffer");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pView"], pView, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBufferView");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["bufferView"], bufferView, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pImage"], pImage, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImage");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pSubresource"], pSubresource, json_options);
        FieldToJson(args["pLayout"], pLayout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pView"], pView, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImageView");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["imageView"], imageView, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderModule");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["shaderModule"], shaderModule, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineCache");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["dstCache"], dstCache, json_options);
        FieldToJson(args["srcCacheCount"], srcCacheCount, json_options);
        HandleToJson(args["pSrcCaches"], pSrcCaches, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelines"], pPipelines, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelines"], pPipelines, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipeline");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelineLayout"], pPipelineLayout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineLayout");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineLayout"], pipelineLayout, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSampler"], pSampler, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySampler");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["sampler"], sampler, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSetLayout"], pSetLayout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorSetLayout");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorSetLayout"], descriptorSetLayout, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pDescriptorPool"], pDescriptorPool, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorPool");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options);
        FieldToJson(VkDescriptorPoolResetFlags_t(), args["flags"], flags, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options);
        FieldToJson(args["descriptorSetCount"], descriptorSetCount, json_options);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["descriptorWriteCount"], descriptorWriteCount, json_options);
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites, json_options);
        FieldToJson(args["descriptorCopyCount"], descriptorCopyCount, json_options);
        FieldToJson(args["pDescriptorCopies"], pDescriptorCopies, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pFramebuffer"], pFramebuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFramebuffer");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["framebuffer"], framebuffer, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyRenderPass");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["renderPass"], renderPass, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderAreaGranularity");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["renderPass"], renderPass, json_options);
        FieldToJson(args["pGranularity"], pGranularity, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pCommandPool"], pCommandPool, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyCommandPool");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["commandPool"], commandPool, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["commandPool"], commandPool, json_options);
        FieldToJson(VkCommandPoolResetFlags_t(), args["flags"], flags, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["commandPool"], commandPool, json_options);
        FieldToJson(args["commandBufferCount"], commandBufferCount, json_options);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBeginCommandBuffer");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBeginInfo"], pBeginInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEndCommandBuffer");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandBuffer");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkCommandBufferResetFlags_t(), args["flags"], flags, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipeline");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstViewport"], firstViewport, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pViewports"], pViewports, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstScissor"], firstScissor, json_options);
        FieldToJson(args["scissorCount"], scissorCount, json_options);
        FieldToJson(args["pScissors"], pScissors, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineWidth");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["lineWidth"], lineWidth, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["depthBiasConstantFactor"], depthBiasConstantFactor, json_options);
        FieldToJson(args["depthBiasClamp"], depthBiasClamp, json_options);
        FieldToJson(args["depthBiasSlopeFactor"], depthBiasSlopeFactor, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetBlendConstants");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["blendConstants"], blendConstants, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBounds");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["minDepthBounds"], minDepthBounds, json_options);
        FieldToJson(args["maxDepthBounds"], maxDepthBounds, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilCompareMask");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options);
        FieldToJson(args["compareMask"], compareMask, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilWriteMask");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options);
        FieldToJson(args["writeMask"], writeMask, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilReference");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options);
        FieldToJson(args["reference"], reference, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options);
        HandleToJson(args["layout"], layout, json_options);
        FieldToJson(args["firstSet"], firstSet, json_options);
        FieldToJson(args["descriptorSetCount"], descriptorSetCount, json_options);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options);
        FieldToJson(args["dynamicOffsetCount"], dynamicOffsetCount, json_options);
        FieldToJson(args["pDynamicOffsets"], pDynamicOffsets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["indexType"], indexType, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstBinding"], firstBinding, json_options);
        FieldToJson(args["bindingCount"], bindingCount, json_options);
        HandleToJson(args["pBuffers"], pBuffers, json_options);
        FieldToJson(args["pOffsets"], pOffsets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["vertexCount"], vertexCount, json_options);
        FieldToJson(args["instanceCount"], instanceCount, json_options);
        FieldToJson(args["firstVertex"], firstVertex, json_options);
        FieldToJson(args["firstInstance"], firstInstance, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["indexCount"], indexCount, json_options);
        FieldToJson(args["instanceCount"], instanceCount, json_options);
        FieldToJson(args["firstIndex"], firstIndex, json_options);
        FieldToJson(args["vertexOffset"], vertexOffset, json_options);
        FieldToJson(args["firstInstance"], firstInstance, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["groupCountX"], groupCountX, json_options);
        FieldToJson(args["groupCountY"], groupCountY, json_options);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcBuffer"], srcBuffer, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcImage"], srcImage, json_options);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options);
        HandleToJson(args["dstImage"], dstImage, json_options);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcImage"], srcImage, json_options);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options);
        HandleToJson(args["dstImage"], dstImage, json_options);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
        FieldToJson(args["filter"], filter, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcBuffer"], srcBuffer, json_options);
        HandleToJson(args["dstImage"], dstImage, json_options);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcImage"], srcImage, json_options);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["dstOffset"], dstOffset, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["dstOffset"], dstOffset, json_options);
        FieldToJson(args["size"], size, json_options);
        FieldToJson(args["data"], data, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["imageLayout"], imageLayout, json_options);
        FieldToJson(args["pColor"], pColor, json_options);
        FieldToJson(args["rangeCount"], rangeCount, json_options);
        FieldToJson(args["pRanges"], pRanges, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["imageLayout"], imageLayout, json_options);
        FieldToJson(args["pDepthStencil"], pDepthStencil, json_options);
        FieldToJson(args["rangeCount"], rangeCount, json_options);
        FieldToJson(args["pRanges"], pRanges, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        FieldToJson(args["pAttachments"], pAttachments, json_options);
        FieldToJson(args["rectCount"], rectCount, json_options);
        FieldToJson(args["pRects"], pRects, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["srcImage"], srcImage, json_options);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options);
        HandleToJson(args["dstImage"], dstImage, json_options);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options);
        FieldToJson(args["regionCount"], regionCount, json_options);
        FieldToJson(args["pRegions"], pRegions, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["stageMask"], stageMask, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["stageMask"], stageMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["eventCount"], eventCount, json_options);
        HandleToJson(args["pEvents"], pEvents, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["srcStageMask"], srcStageMask, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["dstStageMask"], dstStageMask, json_options);
        FieldToJson(args["memoryBarrierCount"], memoryBarrierCount, json_options);
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers, json_options);
        FieldToJson(args["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options);
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options);
        FieldToJson(args["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options);
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["srcStageMask"], srcStageMask, json_options);
        FieldToJson(VkPipelineStageFlags_t(), args["dstStageMask"], dstStageMask, json_options);
        FieldToJson(VkDependencyFlags_t(), args["dependencyFlags"], dependencyFlags, json_options);
        FieldToJson(args["memoryBarrierCount"], memoryBarrierCount, json_options);
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers, json_options);
        FieldToJson(args["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options);
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options);
        FieldToJson(args["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options);
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
        FieldToJson(VkQueryControlFlags_t(), args["flags"], flags, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQuery");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
        FieldToJson(args["queryCount"], queryCount, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineStage"], pipelineStage, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
        FieldToJson(args["queryCount"], queryCount, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["dstOffset"], dstOffset, json_options);
        FieldToJson(args["stride"], stride, json_options);
        FieldToJson(VkQueryResultFlags_t(), args["flags"], flags, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options);
        FieldToJson(args["contents"], contents, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["contents"], contents, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteCommands");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["commandBufferCount"], commandBufferCount, json_options);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["heapIndex"], heapIndex, json_options);
        FieldToJson(args["localDeviceIndex"], localDeviceIndex, json_options);
        FieldToJson(args["remoteDeviceIndex"], remoteDeviceIndex, json_options);
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMask");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["deviceMask"], deviceMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["baseGroupX"], baseGroupX, json_options);
        FieldToJson(args["baseGroupY"], baseGroupY, json_options);
        FieldToJson(args["baseGroupZ"], baseGroupZ, json_options);
        FieldToJson(args["groupCountX"], groupCountX, json_options);
        FieldToJson(args["groupCountY"], groupCountY, json_options);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFeatures"], pFeatures, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo, json_options);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFormatInfo"], pFormatInfo, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPool");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["commandPool"], commandPool, json_options);
        FieldToJson(VkCommandPoolTrimFlags_t(), args["flags"], flags, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceQueue2");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pQueueInfo"], pQueueInfo, json_options);
        HandleToJson(args["pQueue"], pQueue, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversion");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplate");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo, json_options);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFenceProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo, json_options);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupport");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pSupport"], pSupport, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
        FieldToJson(args["queryCount"], queryCount, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["semaphore"], semaphore, json_options);
        FieldToJson(args["pValue"], pValue, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pWaitInfo"], pWaitInfo, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphore");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pSignalInfo"], pSignalInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddress");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddress");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pToolCount"], pToolCount, json_options);
        FieldToJson(args["pToolProperties"], pToolProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlot");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["objectType"], objectType, json_options);
        HandleToJson(args["objectHandle"], objectHandle, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["data"], data, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["objectType"], objectType, json_options);
        HandleToJson(args["objectHandle"], objectHandle, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["pData"], pData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(VkPipelineStageFlags2_t(), args["stageMask"], stageMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["eventCount"], eventCount, json_options);
        HandleToJson(args["pEvents"], pEvents, json_options);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["submitCount"], submitCount, json_options);
        FieldToJson(args["pSubmits"], pSubmits, json_options);
        HandleToJson(args["fence"], fence, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRendering");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullMode");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkCullModeFlags_t(), args["cullMode"], cullMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFace");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["frontFace"], frontFace, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopology");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["primitiveTopology"], primitiveTopology, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCount");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pViewports"], pViewports, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCount");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["scissorCount"], scissorCount, json_options);
        FieldToJson(args["pScissors"], pScissors, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstBinding"], firstBinding, json_options);
        FieldToJson(args["bindingCount"], bindingCount, json_options);
        HandleToJson(args["pBuffers"], pBuffers, json_options);
        FieldToJson(args["pOffsets"], pOffsets, json_options);
        FieldToJson(args["pSizes"], pSizes, json_options);
        FieldToJson(args["pStrides"], pStrides, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthTestEnable"], depthTestEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthWriteEnable"], depthWriteEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOp");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["depthCompareOp"], depthCompareOp, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["stencilTestEnable"], stencilTestEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options);
        FieldToJson(args["failOp"], failOp, json_options);
        FieldToJson(args["passOp"], passOp, json_options);
        FieldToJson(args["depthFailOp"], depthFailOp, json_options);
        FieldToJson(args["compareOp"], compareOp, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthBiasEnable"], depthBiasEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnable");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirements");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirements");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySurfaceKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        HandleToJson(args["surface"], surface, json_options);
        Bool32ToJson(args["pSupported"], pSupported, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount, json_options);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount, json_options);
        FieldToJson(args["pPresentModes"], pPresentModes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSwapchain"], pSwapchain, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySwapchainKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pSwapchainImageCount"], pSwapchainImageCount, json_options);
        HandleToJson(args["pSwapchainImages"], pSwapchainImages, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
        HandleToJson(args["semaphore"], semaphore, json_options);
        HandleToJson(args["fence"], fence, json_options);
        FieldToJson(args["pImageIndex"], pImageIndex, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueuePresentKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pPresentInfo"], pPresentInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pDeviceGroupPresentCapabilities"], pDeviceGroupPresentCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pModes"], pModes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pRectCount"], pRectCount, json_options);
        FieldToJson(args["pRects"], pRects, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo, json_options);
        FieldToJson(args["pImageIndex"], pImageIndex, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["planeIndex"], planeIndex, json_options);
        FieldToJson(args["pDisplayCount"], pDisplayCount, json_options);
        HandleToJson(args["pDisplays"], pDisplays, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["display"], display, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["display"], display, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pMode"], pMode, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["mode"], mode, json_options);
        FieldToJson(args["planeIndex"], planeIndex, json_options);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["swapchainCount"], swapchainCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSwapchains"], pSwapchains, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["dpy"], dpy, json_options);
        FieldToJson(args["visualID"], visualID, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["connection"], connection, json_options);
        FieldToJson(args["visual_id"], visual_id, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pVideoProfile"], pVideoProfile, json_options);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pVideoFormatInfo"], pVideoFormatInfo, json_options);
        FieldToJson(args["pVideoFormatPropertyCount"], pVideoFormatPropertyCount, json_options);
        FieldToJson(args["pVideoFormatProperties"], pVideoFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pVideoSession"], pVideoSession, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["videoSession"], videoSession, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["videoSession"], videoSession, json_options);
        FieldToJson(args["pMemoryRequirementsCount"], pMemoryRequirementsCount, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["videoSession"], videoSession, json_options);
        FieldToJson(args["bindSessionMemoryInfoCount"], bindSessionMemoryInfoCount, json_options);
        FieldToJson(args["pBindSessionMemoryInfos"], pBindSessionMemoryInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pVideoSessionParameters"], pVideoSessionParameters, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters, json_options);
        FieldToJson(args["pUpdateInfo"], pUpdateInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionParametersKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginVideoCodingKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBeginInfo"], pBeginInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndVideoCodingKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pEndCodingInfo"], pEndCodingInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdControlVideoCodingKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCodingControlInfo"], pCodingControlInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecodeVideoKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pDecodeInfo"], pDecodeInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderingKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderingKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFeatures"], pFeatures, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo, json_options);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFormatInfo"], pFormatInfo, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["heapIndex"], heapIndex, json_options);
        FieldToJson(args["localDeviceIndex"], localDeviceIndex, json_options);
        FieldToJson(args["remoteDeviceIndex"], remoteDeviceIndex, json_options);
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMaskKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["deviceMask"], deviceMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["baseGroupX"], baseGroupX, json_options);
        FieldToJson(args["baseGroupY"], baseGroupY, json_options);
        FieldToJson(args["baseGroupZ"], baseGroupZ, json_options);
        FieldToJson(args["groupCountX"], groupCountX, json_options);
        FieldToJson(args["groupCountY"], groupCountY, json_options);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPoolKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["commandPool"], commandPool, json_options);
        FieldToJson(VkCommandPoolTrimFlags_t(), args["flags"], flags, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo, json_options);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options);
        FieldToJson(args["pHandle"], pHandle, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["handleType"], handleType, json_options);
        FieldToJson(args["handle"], handle, json_options);
        FieldToJson(args["pMemoryWin32HandleProperties"], pMemoryWin32HandleProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options);
        FieldToJson(args["pFd"], pFd, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["handleType"], handleType, json_options);
        FieldToJson(args["fd"], fd, json_options);
        FieldToJson(args["pMemoryFdProperties"], pMemoryFdProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreWin32HandleKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pImportSemaphoreWin32HandleInfo"], pImportSemaphoreWin32HandleInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options);
        FieldToJson(args["pHandle"], pHandle, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreFdKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pImportSemaphoreFdInfo"], pImportSemaphoreFdInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options);
        FieldToJson(args["pFd"], pFd, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options);
        HandleToJson(args["layout"], layout, json_options);
        FieldToJson(args["set"], set, json_options);
        FieldToJson(args["descriptorWriteCount"], descriptorWriteCount, json_options);
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplateKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainStatusKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo, json_options);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceWin32HandleKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pImportFenceWin32HandleInfo"], pImportFenceWin32HandleInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options);
        FieldToJson(args["pHandle"], pHandle, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceFdKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pImportFenceFdInfo"], pImportFenceFdInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options);
        FieldToJson(args["pFd"], pFd, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["pCounterCount"], pCounterCount, json_options);
        FieldToJson(args["pCounters"], pCounters, json_options);
        FieldToJson(args["pCounterDescriptions"], pCounterDescriptions, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPerformanceQueryCreateInfo"], pPerformanceQueryCreateInfo, json_options);
        FieldToJson(args["pNumPasses"], pNumPasses, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireProfilingLockKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseProfilingLockKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount, json_options);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["display"], display, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pDisplayPlaneInfo"], pDisplayPlaneInfo, json_options);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversionKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupportKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pSupport"], pSupport, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["semaphore"], semaphore, json_options);
        FieldToJson(args["pValue"], pValue, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pWaitInfo"], pWaitInfo, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphoreKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pSignalInfo"], pSignalInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pFragmentShadingRateCount"], pFragmentShadingRateCount, json_options);
        FieldToJson(args["pFragmentShadingRates"], pFragmentShadingRates, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pFragmentSize"], pFragmentSize, json_options);
        FieldToJson(args["combinerOps"], combinerOps, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR>* pLocationInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingAttachmentLocationsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pLocationInfo"], pLocationInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR>* pInputAttachmentIndexInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingInputAttachmentIndicesKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInputAttachmentIndexInfo"], pInputAttachmentIndexInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["presentId"], presentId, json_options);
        FieldToJson(args["timeout"], timeout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddressKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pDeferredOperation"], pDeferredOperation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDeferredOperationKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["operation"], operation, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationMaxConcurrencyKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["operation"], operation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationResultKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["operation"], operation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeferredOperationJoinKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["operation"], operation, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pPipelineInfo"], pPipelineInfo, json_options);
        FieldToJson(args["pExecutableCount"], pExecutableCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo, json_options);
        FieldToJson(args["pStatisticCount"], pStatisticCount, json_options);
        FieldToJson(args["pStatistics"], pStatistics, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo, json_options);
        FieldToJson(args["pInternalRepresentationCount"], pInternalRepresentationCount, json_options);
        FieldToJson(args["pInternalRepresentations"], pInternalRepresentations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pMemoryMapInfo"], pMemoryMapInfo, json_options);
        FieldToJsonAsHex(args["ppData"], ppData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pMemoryUnmapInfo"], pMemoryUnmapInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pQualityLevelInfo"], pQualityLevelInfo, json_options);
        FieldToJson(args["pQualityLevelProperties"], pQualityLevelProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pVideoSessionParametersInfo"], pVideoSessionParametersInfo, json_options);
        FieldToJson(args["pFeedbackInfo"], pFeedbackInfo, json_options);
        FieldToJson(args["pDataSize"], pDataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEncodeVideoKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pEncodeInfo"], pEncodeInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["event"], event, json_options);
        FieldToJson(VkPipelineStageFlags2_t(), args["stageMask"], stageMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["eventCount"], eventCount, json_options);
        HandleToJson(args["pEvents"], pEvents, json_options);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["submitCount"], submitCount, json_options);
        FieldToJson(args["pSubmits"], pSubmits, json_options);
        HandleToJson(args["fence"], fence, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["dstOffset"], dstOffset, json_options);
        FieldToJson(args["marker"], marker, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointData2NV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount, json_options);
        FieldToJson(args["pCheckpointData"], pCheckpointData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirect2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirementsKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["size"], size, json_options);
        FieldToJson(args["indexType"], indexType, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularityKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pRenderingAreaInfo"], pRenderingAreaInfo, json_options);
        FieldToJson(args["pGranularity"], pGranularity, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayoutKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pLayout"], pLayout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pSubresource"], pSubresource, json_options);
        FieldToJson(args["pLayout"], pLayout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["lineStippleFactor"], lineStippleFactor, json_options);
        FieldToJson(args["lineStipplePattern"], lineStipplePattern, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pTimeDomainCount"], pTimeDomainCount, json_options);
        FieldToJson(args["pTimeDomains"], pTimeDomains, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["timestampCount"], timestampCount, json_options);
        FieldToJson(args["pTimestampInfos"], pTimestampInfos, json_options);
        FieldToJson(args["pTimestamps"], pTimestamps, json_options);
        FieldToJson(args["pMaxDeviation"], pMaxDeviation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR>* pBindDescriptorSetsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBindDescriptorSetsInfo"], pBindDescriptorSetsInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR>* pPushConstantsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushConstants2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pPushConstantsInfo"], pPushConstantsInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR>* pPushDescriptorSetInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet2KHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pPushDescriptorSetInfo"], pPushDescriptorSetInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDescriptorBufferOffsets2EXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSetDescriptorBufferOffsetsInfo"], pSetDescriptorBufferOffsetsInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pBindDescriptorBufferEmbeddedSamplersInfo"], pBindDescriptorBufferEmbeddedSamplersInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFrameBoundaryANDROID");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["semaphore"], semaphore, json_options);
        HandleToJson(args["image"], image, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pCallback"], pCallback, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugReportCallbackEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["callback"], callback, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(VkDebugReportFlagsEXT_t(), args["flags"], flags, json_options);
        FieldToJson(args["objectType"], objectType, json_options);
        FieldToJson(args["object"], object, json_options);
        FieldToJson(args["location"], location, json_options);
        FieldToJson(args["messageCode"], messageCode, json_options);
        FieldToJson(args["pLayerPrefix"], pLayerPrefix, json_options);
        FieldToJson(args["pMessage"], pMessage, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectTagEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pTagInfo"], pTagInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectNameEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pNameInfo"], pNameInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerBeginEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerEndEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerInsertEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstBinding"], firstBinding, json_options);
        FieldToJson(args["bindingCount"], bindingCount, json_options);
        HandleToJson(args["pBuffers"], pBuffers, json_options);
        FieldToJson(args["pOffsets"], pOffsets, json_options);
        FieldToJson(args["pSizes"], pSizes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstCounterBuffer"], firstCounterBuffer, json_options);
        FieldToJson(args["counterBufferCount"], counterBufferCount, json_options);
        HandleToJson(args["pCounterBuffers"], pCounterBuffers, json_options);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstCounterBuffer"], firstCounterBuffer, json_options);
        FieldToJson(args["counterBufferCount"], counterBufferCount, json_options);
        HandleToJson(args["pCounterBuffers"], pCounterBuffers, json_options);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
        FieldToJson(VkQueryControlFlags_t(), args["flags"], flags, json_options);
        FieldToJson(args["index"], index, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["query"], query, json_options);
        FieldToJson(args["index"], index, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["instanceCount"], instanceCount, json_options);
        FieldToJson(args["firstInstance"], firstInstance, json_options);
        HandleToJson(args["counterBuffer"], counterBuffer, json_options);
        FieldToJson(args["counterBufferOffset"], counterBufferOffset, json_options);
        FieldToJson(args["counterOffset"], counterOffset, json_options);
        FieldToJson(args["vertexStride"], vertexStride, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandleNVX");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["imageView"], imageView, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["shaderStage"], shaderStage, json_options);
        FieldToJson(args["infoType"], infoType, json_options);
        FieldToJson(args["pInfoSize"], pInfoSize, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["format"], format, json_options);
        FieldToJson(args["type"], type, json_options);
        FieldToJson(args["tiling"], tiling, json_options);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options);
        FieldToJson(VkImageCreateFlags_t(), args["flags"], flags, json_options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), args["externalHandleType"], externalHandleType, json_options);
        FieldToJson(args["pExternalImageFormatProperties"], pExternalImageFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), args["handleType"], handleType, json_options);
        FieldToJson(args["pHandle"], pHandle, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRenderingEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pConditionalRenderingBegin"], pConditionalRenderingBegin, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndConditionalRenderingEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstViewport"], firstViewport, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pViewportWScalings"], pViewportWScalings, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseDisplayEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["dpy"], dpy, json_options);
        HandleToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["dpy"], dpy, json_options);
        FieldToJson(args["rrOutput"], rrOutput, json_options);
        HandleToJson(args["pDisplay"], pDisplay, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["surface"], surface, json_options);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["display"], display, json_options);
        FieldToJson(args["pDisplayPowerInfo"], pDisplayPowerInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pDeviceEventInfo"], pDeviceEventInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pFence"], pFence, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["display"], display, json_options);
        FieldToJson(args["pDisplayEventInfo"], pDisplayEventInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pFence"], pFence, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["counter"], counter, json_options);
        FieldToJson(args["pCounterValue"], pCounterValue, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pDisplayTimingProperties"], pDisplayTimingProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pPresentationTimingCount"], pPresentationTimingCount, json_options);
        FieldToJson(args["pPresentationTimings"], pPresentationTimings, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstDiscardRectangle"], firstDiscardRectangle, json_options);
        FieldToJson(args["discardRectangleCount"], discardRectangleCount, json_options);
        FieldToJson(args["pDiscardRectangles"], pDiscardRectangles, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["discardRectangleEnable"], discardRectangleEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["discardRectangleMode"], discardRectangleMode, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["swapchainCount"], swapchainCount, json_options);
        HandleToJson(args["pSwapchains"], pSwapchains, json_options);
        FieldToJson(args["pMetadata"], pMetadata, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectNameEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pNameInfo"], pNameInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectTagEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pTagInfo"], pTagInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBeginDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueEndDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueInsertDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdInsertDebugUtilsLabelEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pMessenger"], pMessenger, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugUtilsMessengerEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        HandleToJson(args["messenger"], messenger, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["messageSeverity"], messageSeverity, json_options);
        FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t(), args["messageTypes"], messageTypes, json_options);
        FieldToJson(args["pCallbackData"], pCallbackData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pBuffer"], pBuffer, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pSampleLocationsInfo"], pSampleLocationsInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["samples"], samples, json_options);
        FieldToJson(args["pMultisampleProperties"], pMultisampleProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pValidationCache"], pValidationCache, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyValidationCacheEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["validationCache"], validationCache, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["dstCache"], dstCache, json_options);
        FieldToJson(args["srcCacheCount"], srcCacheCount, json_options);
        HandleToJson(args["pSrcCaches"], pSrcCaches, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["validationCache"], validationCache, json_options);
        FieldToJson(args["pDataSize"], pDataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadingRateImageNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["imageView"], imageView, json_options);
        FieldToJson(args["imageLayout"], imageLayout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstViewport"], firstViewport, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pShadingRatePalettes"], pShadingRatePalettes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["sampleOrderType"], sampleOrderType, json_options);
        FieldToJson(args["customSampleOrderCount"], customSampleOrderCount, json_options);
        FieldToJson(args["pCustomSampleOrders"], pCustomSampleOrders, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureMemoryRequirementsNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        HandleToJson(args["instanceData"], instanceData, json_options);
        FieldToJson(args["instanceOffset"], instanceOffset, json_options);
        Bool32ToJson(args["update"], update, json_options);
        HandleToJson(args["dst"], dst, json_options);
        HandleToJson(args["src"], src, json_options);
        HandleToJson(args["scratch"], scratch, json_options);
        FieldToJson(args["scratchOffset"], scratchOffset, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["dst"], dst, json_options);
        HandleToJson(args["src"], src, json_options);
        FieldToJson(args["mode"], mode, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["raygenShaderBindingTableBuffer"], raygenShaderBindingTableBuffer, json_options);
        FieldToJson(args["raygenShaderBindingOffset"], raygenShaderBindingOffset, json_options);
        HandleToJson(args["missShaderBindingTableBuffer"], missShaderBindingTableBuffer, json_options);
        FieldToJson(args["missShaderBindingOffset"], missShaderBindingOffset, json_options);
        FieldToJson(args["missShaderBindingStride"], missShaderBindingStride, json_options);
        HandleToJson(args["hitShaderBindingTableBuffer"], hitShaderBindingTableBuffer, json_options);
        FieldToJson(args["hitShaderBindingOffset"], hitShaderBindingOffset, json_options);
        FieldToJson(args["hitShaderBindingStride"], hitShaderBindingStride, json_options);
        HandleToJson(args["callableShaderBindingTableBuffer"], callableShaderBindingTableBuffer, json_options);
        FieldToJson(args["callableShaderBindingOffset"], callableShaderBindingOffset, json_options);
        FieldToJson(args["callableShaderBindingStride"], callableShaderBindingStride, json_options);
        FieldToJson(args["width"], width, json_options);
        FieldToJson(args["height"], height, json_options);
        FieldToJson(args["depth"], depth, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelines"], pPipelines, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["firstGroup"], firstGroup, json_options);
        FieldToJson(args["groupCount"], groupCount, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["firstGroup"], firstGroup, json_options);
        FieldToJson(args["groupCount"], groupCount, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options);
        FieldToJson(args["queryType"], queryType, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["shader"], shader, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["handleType"], handleType, json_options);
        FieldToJson(args["pHostPointer"], pHostPointer, json_options);
        FieldToJson(args["pMemoryHostPointerProperties"], pMemoryHostPointerProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineStage"], pipelineStage, json_options);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options);
        FieldToJson(args["dstOffset"], dstOffset, json_options);
        FieldToJson(args["marker"], marker, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pTimeDomainCount"], pTimeDomainCount, json_options);
        FieldToJson(args["pTimeDomains"], pTimeDomains, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["timestampCount"], timestampCount, json_options);
        FieldToJson(args["pTimestampInfos"], pTimestampInfos, json_options);
        FieldToJson(args["pTimestamps"], pTimestamps, json_options);
        FieldToJson(args["pMaxDeviation"], pMaxDeviation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["taskCount"], taskCount, json_options);
        FieldToJson(args["firstTask"], firstTask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstExclusiveScissor"], firstExclusiveScissor, json_options);
        FieldToJson(args["exclusiveScissorCount"], exclusiveScissorCount, json_options);
        Bool32ToJson(args["pExclusiveScissorEnables"], pExclusiveScissorEnables, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstExclusiveScissor"], firstExclusiveScissor, json_options);
        FieldToJson(args["exclusiveScissorCount"], exclusiveScissorCount, json_options);
        FieldToJson(args["pExclusiveScissors"], pExclusiveScissors, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCheckpointNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pCheckpointMarker"], pCheckpointMarker, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointDataNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount, json_options);
        FieldToJson(args["pCheckpointData"], pCheckpointData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInitializePerformanceApiINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInitializeInfo"], pInitializeInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUninitializePerformanceApiINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceMarkerINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceStreamMarkerINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceOverrideINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pOverrideInfo"], pOverrideInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo, json_options);
        HandleToJson(args["pConfiguration"], pConfiguration, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleasePerformanceConfigurationINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["configuration"], configuration, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerformanceConfigurationINTEL");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        HandleToJson(args["configuration"], configuration, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["parameter"], parameter, json_options);
        FieldToJson(args["pValue"], pValue, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLocalDimmingAMD");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapChain"], swapChain, json_options);
        Bool32ToJson(args["localDimmingEnable"], localDimmingEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pToolCount"], pToolCount, json_options);
        FieldToJson(args["pToolProperties"], pToolProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pCombinationCount"], pCombinationCount, json_options);
        FieldToJson(args["pCombinations"], pCombinations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount, json_options);
        FieldToJson(args["pPresentModes"], pPresentModes, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireFullScreenExclusiveModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseFullScreenExclusiveModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options);
        FieldToJson(args["pModes"], pModes, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["lineStippleFactor"], lineStippleFactor, json_options);
        FieldToJson(args["lineStipplePattern"], lineStipplePattern, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
        FieldToJson(args["queryCount"], queryCount, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkCullModeFlags_t(), args["cullMode"], cullMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFaceEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["frontFace"], frontFace, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopologyEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["primitiveTopology"], primitiveTopology, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCountEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pViewports"], pViewports, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCountEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["scissorCount"], scissorCount, json_options);
        FieldToJson(args["pScissors"], pScissors, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstBinding"], firstBinding, json_options);
        FieldToJson(args["bindingCount"], bindingCount, json_options);
        HandleToJson(args["pBuffers"], pBuffers, json_options);
        FieldToJson(args["pOffsets"], pOffsets, json_options);
        FieldToJson(args["pSizes"], pSizes, json_options);
        FieldToJson(args["pStrides"], pStrides, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthTestEnable"], depthTestEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthWriteEnable"], depthWriteEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOpEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["depthCompareOp"], depthCompareOp, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["stencilTestEnable"], stencilTestEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options);
        FieldToJson(args["failOp"], failOp, json_options);
        FieldToJson(args["passOp"], passOp, json_options);
        FieldToJson(args["depthFailOp"], depthFailOp, json_options);
        FieldToJson(args["compareOp"], compareOp, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImageEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCopyMemoryToImageInfo"], pCopyMemoryToImageInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemoryEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCopyImageToMemoryInfo"], pCopyImageToMemoryInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImageEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCopyImageToImageInfo"], pCopyImageToImageInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["transitionCount"], transitionCount, json_options);
        FieldToJson(args["pTransitions"], pTransitions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["image"], image, json_options);
        FieldToJson(args["pSubresource"], pSubresource, json_options);
        FieldToJson(args["pLayout"], pLayout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pReleaseInfo"], pReleaseInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["isPreprocessed"], isPreprocessed, json_options);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["groupIndex"], groupIndex, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pIndirectCommandsLayout"], pIndirectCommandsLayout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectCommandsLayoutNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["indirectCommandsLayout"], indirectCommandsLayout, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias2EXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pDepthBiasInfo"], pDepthBiasInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["drmFd"], drmFd, json_options);
        HandleToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["drmFd"], drmFd, json_options);
        FieldToJson(args["connectorId"], connectorId, json_options);
        HandleToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlotEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["objectType"], objectType, json_options);
        HandleToJson(args["objectHandle"], objectHandle, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["data"], data, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["objectType"], objectType, json_options);
        HandleToJson(args["objectHandle"], objectHandle, json_options);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options);
        FieldToJson(args["pData"], pData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateEnumNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["shadingRate"], shadingRate, json_options);
        FieldToJson(args["combinerOps"], combinerOps, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pFaultCounts"], pFaultCounts, json_options);
        FieldToJson(args["pFaultInfo"], pFaultInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireWinrtDisplayNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        HandleToJson(args["display"], display, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["deviceRelativeId"], deviceRelativeId, json_options);
        HandleToJson(args["pDisplay"], pDisplay, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["dfb"], dfb, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["vertexBindingDescriptionCount"], vertexBindingDescriptionCount, json_options);
        FieldToJson(args["pVertexBindingDescriptions"], pVertexBindingDescriptions, json_options);
        FieldToJson(args["vertexAttributeDescriptionCount"], vertexAttributeDescriptionCount, json_options);
        FieldToJson(args["pVertexAttributeDescriptions"], pVertexAttributeDescriptions, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options);
        FieldToJson(args["pZirconHandle"], pZirconHandle, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["handleType"], handleType, json_options);
        FieldToJson(args["zirconHandle"], zirconHandle, json_options);
        FieldToJson(args["pMemoryZirconHandleProperties"], pMemoryZirconHandleProperties, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreZirconHandleFUCHSIA");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pImportSemaphoreZirconHandleInfo"], pImportSemaphoreZirconHandleInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options);
        FieldToJson(args["pZirconHandle"], pZirconHandle, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindInvocationMaskHUAWEI");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["imageView"], imageView, json_options);
        FieldToJson(args["imageLayout"], imageLayout, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pMemoryGetRemoteAddressInfo"], pMemoryGetRemoteAddressInfo, json_options);
        FieldToJson(args["pAddress"], pAddress, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPatchControlPointsEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["patchControlPoints"], patchControlPoints, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthBiasEnable"], depthBiasEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["logicOp"], logicOp, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSurface"], pSurface, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options);
        FieldToJson(args["window"], window, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        Bool32ToJson(args["pColorWriteEnables"], pColorWriteEnables, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["pVertexInfo"], pVertexInfo, json_options);
        FieldToJson(args["instanceCount"], instanceCount, json_options);
        FieldToJson(args["firstInstance"], firstInstance, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["pIndexInfo"], pIndexInfo, json_options);
        FieldToJson(args["instanceCount"], instanceCount, json_options);
        FieldToJson(args["firstInstance"], firstInstance, json_options);
        FieldToJson(args["stride"], stride, json_options);
        FieldToJson(args["pVertexOffset"], pVertexOffset, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pMicromap"], pMicromap, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyMicromapEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["micromap"], micromap, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildMicromapsEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["infoCount"], infoCount, json_options);
        FieldToJson(args["pInfos"], pInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["infoCount"], infoCount, json_options);
        FieldToJson(args["pInfos"], pInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["micromapCount"], micromapCount, json_options);
        HandleToJson(args["pMicromaps"], pMicromaps, json_options);
        FieldToJson(args["queryType"], queryType, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
        FieldToJson(args["stride"], stride, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapToMemoryEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToMicromapEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["micromapCount"], micromapCount, json_options);
        HandleToJson(args["pMicromaps"], pMicromaps, json_options);
        FieldToJson(args["queryType"], queryType, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMicromapCompatibilityEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pVersionInfo"], pVersionInfo, json_options);
        FieldToJson(args["pCompatibility"], pCompatibility, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["buildType"], buildType, json_options);
        FieldToJson(args["pBuildInfo"], pBuildInfo, json_options);
        FieldToJson(args["pSizeInfo"], pSizeInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["groupCountX"], groupCountX, json_options);
        FieldToJson(args["groupCountY"], groupCountY, json_options);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterIndirectHUAWEI");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDeviceMemoryPriorityEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["memory"], memory, json_options);
        FieldToJson(args["priority"], priority, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pBindingReference"], pBindingReference, json_options);
        FieldToJson(args["pHostMapping"], pHostMapping, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetHostMappingVALVE");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["descriptorSet"], descriptorSet, json_options);
        FieldToJsonAsHex(args["ppData"], ppData, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectMemoryRequirementsNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdatePipelineIndirectBufferNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectDeviceAddressNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthClampEnable"], depthClampEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPolygonModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["polygonMode"], polygonMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationSamplesEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["rasterizationSamples"], rasterizationSamples, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleMaskEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["samples"], samples, json_options);
        FieldToJson(args["pSampleMask"], pSampleMask, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToCoverageEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["alphaToCoverageEnable"], alphaToCoverageEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToOneEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["alphaToOneEnable"], alphaToOneEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["logicOpEnable"], logicOpEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        Bool32ToJson(args["pColorBlendEnables"], pColorBlendEnables, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        FieldToJson(args["pColorBlendEquations"], pColorBlendEquations, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        FieldToJson(args["pColorWriteMasks"], pColorWriteMasks, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetTessellationDomainOriginEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["domainOrigin"], domainOrigin, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationStreamEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["rasterizationStream"], rasterizationStream, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetConservativeRasterizationModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["conservativeRasterizationMode"], conservativeRasterizationMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["extraPrimitiveOverestimationSize"], extraPrimitiveOverestimationSize, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["depthClipEnable"], depthClipEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["sampleLocationsEnable"], sampleLocationsEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options);
        FieldToJson(args["pColorBlendAdvanced"], pColorBlendAdvanced, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetProvokingVertexModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["provokingVertexMode"], provokingVertexMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineRasterizationModeEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["lineRasterizationMode"], lineRasterizationMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["stippledLineEnable"], stippledLineEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["negativeOneToOne"], negativeOneToOne, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingEnableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["viewportWScalingEnable"], viewportWScalingEnable, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["firstViewport"], firstViewport, json_options);
        FieldToJson(args["viewportCount"], viewportCount, json_options);
        FieldToJson(args["pViewportSwizzles"], pViewportSwizzles, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorEnableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["coverageToColorEnable"], coverageToColorEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorLocationNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["coverageToColorLocation"], coverageToColorLocation, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationModeNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["coverageModulationMode"], coverageModulationMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableEnableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["coverageModulationTableEnable"], coverageModulationTableEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["coverageModulationTableCount"], coverageModulationTableCount, json_options);
        FieldToJson(args["pCoverageModulationTable"], pCoverageModulationTable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetShadingRateImageEnableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["shadingRateImageEnable"], shadingRateImageEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        Bool32ToJson(args["representativeFragmentTestEnable"], representativeFragmentTestEnable, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageReductionModeNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["coverageReductionMode"], coverageReductionMode, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleIdentifierEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["shaderModule"], shaderModule, json_options);
        FieldToJson(args["pIdentifier"], pIdentifier, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pIdentifier"], pIdentifier, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options);
        FieldToJson(args["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo, json_options);
        FieldToJson(args["pFormatCount"], pFormatCount, json_options);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pSession"], pSession, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyOpticalFlowSessionNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["bindingPoint"], bindingPoint, json_options);
        HandleToJson(args["view"], view, json_options);
        FieldToJson(args["layout"], layout, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdOpticalFlowExecuteNV");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["session"], session, json_options);
        FieldToJson(args["pExecuteInfo"], pExecuteInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pShaders"], pShaders, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderEXT");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["shader"], shader, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["shader"], shader, json_options);
        FieldToJson(args["pDataSize"], pDataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["stageCount"], stageCount, json_options);
        FieldToJson(args["pStages"], pStages, json_options);
        HandleToJson(args["pShaders"], pShaders, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["framebuffer"], framebuffer, json_options);
        FieldToJson(args["pPropertiesCount"], pPropertiesCount, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options);
        FieldToJson(args["pProperties"], pProperties, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pSleepModeInfo"], pSleepModeInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pSleepInfo"], pSleepInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLatencyMarkerNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pLatencyMarkerInfo"], pLatencyMarkerInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetLatencyTimingsNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["swapchain"], swapchain, json_options);
        FieldToJson(args["pLatencyMarkerInfo"], pLatencyMarkerInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV>* pQueueTypeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueNotifyOutOfBandNV");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options);
        FieldToJson(args["pQueueTypeInfo"], pQueueTypeInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(VkImageAspectFlags_t(), args["aspectMask"], aspectMask, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["infoCount"], infoCount, json_options);
        FieldToJson(args["pInfos"], pInfos, json_options);
        FieldToJson(args["ppBuildRangeInfos"], ppBuildRangeInfos, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options);
        FieldToJson(args["queryType"], queryType, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
        FieldToJson(args["stride"], stride, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureDeviceAddressKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pInfo"], pInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options);
        FieldToJson(args["queryType"], queryType, json_options);
        HandleToJson(args["queryPool"], queryPool, json_options);
        FieldToJson(args["firstQuery"], firstQuery, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["pVersionInfo"], pVersionInfo, json_options);
        FieldToJson(args["pCompatibility"], pCompatibility, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        FieldToJson(args["buildType"], buildType, json_options);
        FieldToJson(args["pBuildInfo"], pBuildInfo, json_options);
        FieldToJson(args["pMaxPrimitiveCounts"], pMaxPrimitiveCounts, json_options);
        FieldToJson(args["pSizeInfo"], pSizeInfo, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable, json_options);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable, json_options);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options);
        FieldToJson(args["width"], width, json_options);
        FieldToJson(args["height"], height, json_options);
        FieldToJson(args["depth"], depth, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options);
        FieldToJson(args["pAllocator"], pAllocator, json_options);
        HandleToJson(args["pPipelines"], pPipelines, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["firstGroup"], firstGroup, json_options);
        FieldToJson(args["groupCount"], groupCount, json_options);
        FieldToJson(args["dataSize"], dataSize, json_options);
        FieldToJson(args["pData"], pData, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable, json_options);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable, json_options);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options);
        HandleToJson(args["pipeline"], pipeline, json_options);
        FieldToJson(args["group"], group, json_options);
        FieldToJson(args["groupShader"], groupShader, json_options);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR");
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["pipelineStackSize"], pipelineStackSize, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        FieldToJson(args["groupCountX"], groupCountX, json_options);
        FieldToJson(args["groupCountY"], groupCountY, json_options);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        FieldToJson(args["drawCount"], drawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
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
    const JsonOptions& json_options = GetJsonOptions();
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options);
        HandleToJson(args["buffer"], buffer, json_options);
        FieldToJson(args["offset"], offset, json_options);
        HandleToJson(args["countBuffer"], countBuffer, json_options);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options);
        FieldToJson(args["stride"], stride, json_options);
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
