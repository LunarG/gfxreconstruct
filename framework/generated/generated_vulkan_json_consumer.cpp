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
#include "decode/vulkan_decoder_args.h"

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
    args::CreateInstance&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateInstance");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pInstance"], &args.pInstance);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    args::DestroyInstance&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyInstance");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDevices&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDevices");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pPhysicalDeviceCount"], &args.pPhysicalDeviceCount);
        HandleToJson(jargs["pPhysicalDevices"], &args.pPhysicalDevices);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFeatures"], &args.pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        FieldToJson(jargs["pFormatProperties"], &args.pFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        jargs["type"] = args.type;
        jargs["tiling"] = args.tiling;
        jargs["usage"] = VkImageUsageFlags_t{args.usage};
        jargs["flags"] = VkImageCreateFlags_t{args.flags};
        FieldToJson(jargs["pImageFormatProperties"], &args.pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pQueueFamilyPropertyCount"], &args.pQueueFamilyPropertyCount);
        FieldToJson(jargs["pQueueFamilyProperties"], &args.pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pMemoryProperties"], &args.pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    args::CreateDevice&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDevice");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pDevice"], &args.pDevice);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    args::DestroyDevice&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDevice");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceQueue");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["queueIndex"] = args.queueIndex;
        HandleToJson(jargs["pQueue"], &args.pQueue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit");
    jdata[format::kNameSubmitIndex] = ++submit_index_;
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        jargs["submitCount"] = args.submitCount;
        FieldToJson(jargs["pSubmits"], &args.pSubmits);
        HandleToJson(jargs["fence"], args.fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    args::QueueWaitIdle&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueWaitIdle");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    args::DeviceWaitIdle&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeviceWaitIdle");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    args::AllocateMemory&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateMemory");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAllocateInfo"], &args.pAllocateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pMemory"], &args.pMemory);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    args::FreeMemory&                           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeMemory");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    args::MapMemory&                            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
        jargs["offset"] = args.offset;
        jargs["size"] = args.size;
        jargs["flags"] = VkMemoryMapFlags_t{args.flags};
        FieldToJsonAsHex(jargs["ppData"], args.ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::FlushMappedMemoryRanges&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFlushMappedMemoryRanges");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["memoryRangeCount"] = args.memoryRangeCount;
        FieldToJson(jargs["pMemoryRanges"], &args.pMemoryRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::InvalidateMappedMemoryRanges&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInvalidateMappedMemoryRanges");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["memoryRangeCount"] = args.memoryRangeCount;
        FieldToJson(jargs["pMemoryRanges"], &args.pMemoryRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryCommitment&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryCommitment");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
        FieldToJson(jargs["pCommittedMemoryInBytes"], &args.pCommittedMemoryInBytes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["buffer"], args.buffer);
        HandleToJson(jargs["memory"], args.memory);
        jargs["memoryOffset"] = args.memoryOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        HandleToJson(jargs["memory"], args.memory);
        jargs["memoryOffset"] = args.memoryOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["buffer"], args.buffer);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pSparseMemoryRequirementCount"], &args.pSparseMemoryRequirementCount);
        FieldToJson(jargs["pSparseMemoryRequirements"], &args.pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        jargs["type"] = args.type;
        jargs["samples"] = args.samples;
        jargs["usage"] = VkImageUsageFlags_t{args.usage};
        jargs["tiling"] = args.tiling;
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    args::QueueBindSparse&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBindSparse");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfo"], &args.pBindInfo);
        HandleToJson(jargs["fence"], args.fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    args::CreateFence&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateFence");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pFence"], &args.pFence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    args::DestroyFence&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFence");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["fence"], args.fence);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    args::ResetFences&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetFences");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["fenceCount"] = args.fenceCount;
        HandleToJson(jargs["pFences"], &args.pFences);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    args::GetFenceStatus&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceStatus");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["fence"], args.fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    args::WaitForFences&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForFences");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["fenceCount"] = args.fenceCount;
        HandleToJson(jargs["pFences"], &args.pFences);
        Bool32ToJson(jargs["waitAll"], args.waitAll);
        jargs["timeout"] = args.timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    args::CreateSemaphore&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSemaphore");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSemaphore"], &args.pSemaphore);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    args::DestroySemaphore&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySemaphore");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["semaphore"], args.semaphore);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    args::CreateQueryPool&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateQueryPool");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pQueryPool"], &args.pQueryPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    args::DestroyQueryPool&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyQueryPool");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["queryPool"], args.queryPool);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::GetQueryPoolResults&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueryPoolResults");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
        jargs["stride"] = args.stride;
        jargs["flags"] = VkQueryResultFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    args::CreateBuffer&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateBuffer");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pBuffer"], &args.pBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyBuffer&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBuffer");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["buffer"], args.buffer);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    args::CreateImage&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImage");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pImage"], &args.pImage);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    args::DestroyImage&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImage");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pSubresource"], &args.pSubresource);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    args::CreateImageView&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImageView");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pView"], &args.pView);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    args::DestroyImageView&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImageView");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["imageView"], args.imageView);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    args::CreateCommandPool&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateCommandPool");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pCommandPool"], &args.pCommandPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    args::DestroyCommandPool&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyCommandPool");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["commandPool"], args.commandPool);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    args::ResetCommandPool&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandPool");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["commandPool"], args.commandPool);
        jargs["flags"] = VkCommandPoolResetFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::AllocateCommandBuffers&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateCommandBuffers");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAllocateInfo"], &args.pAllocateInfo);
        HandleToJson(jargs["pCommandBuffers"], &args.pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::FreeCommandBuffers&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeCommandBuffers");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["commandPool"], args.commandPool);
        jargs["commandBufferCount"] = args.commandBufferCount;
        HandleToJson(jargs["pCommandBuffers"], &args.pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::BeginCommandBuffer&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBeginCommandBuffer");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBeginInfo"], &args.pBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::EndCommandBuffer&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEndCommandBuffer");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::ResetCommandBuffer&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandBuffer");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["flags"] = VkCommandBufferResetFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcBuffer"], args.srcBuffer);
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcImage"], args.srcImage);
        jargs["srcImageLayout"] = args.srcImageLayout;
        HandleToJson(jargs["dstImage"], args.dstImage);
        jargs["dstImageLayout"] = args.dstImageLayout;
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcBuffer"], args.srcBuffer);
        HandleToJson(jargs["dstImage"], args.dstImage);
        jargs["dstImageLayout"] = args.dstImageLayout;
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcImage"], args.srcImage);
        jargs["srcImageLayout"] = args.srcImageLayout;
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdateBuffer");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["dstOffset"] = args.dstOffset;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdFillBuffer");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["dstOffset"] = args.dstOffset;
        jargs["size"] = args.size;
        jargs["data"] = args.data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["srcStageMask"] = VkPipelineStageFlags_t{args.srcStageMask};
        jargs["dstStageMask"] = VkPipelineStageFlags_t{args.dstStageMask};
        jargs["dependencyFlags"] = VkDependencyFlags_t{args.dependencyFlags};
        jargs["memoryBarrierCount"] = args.memoryBarrierCount;
        FieldToJson(jargs["pMemoryBarriers"], &args.pMemoryBarriers);
        jargs["bufferMemoryBarrierCount"] = args.bufferMemoryBarrierCount;
        FieldToJson(jargs["pBufferMemoryBarriers"], &args.pBufferMemoryBarriers);
        jargs["imageMemoryBarrierCount"] = args.imageMemoryBarrierCount;
        FieldToJson(jargs["pImageMemoryBarriers"], &args.pImageMemoryBarriers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQuery&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginQuery");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
        jargs["flags"] = VkQueryControlFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    args::CmdEndQuery&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQuery");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::CmdResetQueryPool&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetQueryPool");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineStage"] = args.pipelineStage;
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyQueryPoolResults");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["dstOffset"] = args.dstOffset;
        jargs["stride"] = args.stride;
        jargs["flags"] = VkQueryResultFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteCommands");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["commandBufferCount"] = args.commandBufferCount;
        HandleToJson(jargs["pCommandBuffers"], &args.pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    args::CreateEvent&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateEvent");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pEvent"], &args.pEvent);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    args::DestroyEvent&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyEvent");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["event"], args.event);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    args::GetEventStatus&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEventStatus");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["event"], args.event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    args::SetEvent&                             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetEvent");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["event"], args.event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    args::ResetEvent&                           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetEvent");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["event"], args.event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    args::CreateBufferView&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateBufferView");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pView"], &args.pView);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    args::DestroyBufferView&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBufferView");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["bufferView"], args.bufferView);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderModule&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderModule");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["shaderModule"], args.shaderModule);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineCache&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineCache");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    args::MergePipelineCaches&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMergePipelineCaches");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["dstCache"], args.dstCache);
        jargs["srcCacheCount"] = args.srcCacheCount;
        HandleToJson(jargs["pSrcCaches"], &args.pSrcCaches);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    args::CreateComputePipelines&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateComputePipelines");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelines"], &args.pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    args::DestroyPipeline&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipeline");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineLayout&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePipelineLayout");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelineLayout"], &args.pPipelineLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineLayout&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineLayout");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineLayout"], args.pipelineLayout);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    args::CreateSampler&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSampler");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSampler"], &args.pSampler);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    args::DestroySampler&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySampler");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["sampler"], args.sampler);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorSetLayout&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorSetLayout");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSetLayout"], &args.pSetLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorSetLayout&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorSetLayout");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorSetLayout"], args.descriptorSetLayout);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorPool&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorPool");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pDescriptorPool"], &args.pDescriptorPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorPool&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorPool");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorPool"], args.descriptorPool);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::ResetDescriptorPool&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetDescriptorPool");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorPool"], args.descriptorPool);
        jargs["flags"] = VkDescriptorPoolResetFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::AllocateDescriptorSets&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateDescriptorSets");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAllocateInfo"], &args.pAllocateInfo);
        HandleToJson(jargs["pDescriptorSets"], &args.pDescriptorSets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::FreeDescriptorSets&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeDescriptorSets");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorPool"], args.descriptorPool);
        jargs["descriptorSetCount"] = args.descriptorSetCount;
        HandleToJson(jargs["pDescriptorSets"], &args.pDescriptorSets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::UpdateDescriptorSets&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateDescriptorSets");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["descriptorWriteCount"] = args.descriptorWriteCount;
        FieldToJson(jargs["pDescriptorWrites"], &args.pDescriptorWrites);
        jargs["descriptorCopyCount"] = args.descriptorCopyCount;
        FieldToJson(jargs["pDescriptorCopies"], &args.pDescriptorCopies);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipeline");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["pipeline"], args.pipeline);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["layout"], args.layout);
        jargs["firstSet"] = args.firstSet;
        jargs["descriptorSetCount"] = args.descriptorSetCount;
        HandleToJson(jargs["pDescriptorSets"], &args.pDescriptorSets);
        jargs["dynamicOffsetCount"] = args.dynamicOffsetCount;
        FieldToJson(jargs["pDynamicOffsets"], &args.pDynamicOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearColorImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["image"], args.image);
        jargs["imageLayout"] = args.imageLayout;
        FieldToJson(jargs["pColor"], &args.pColor);
        jargs["rangeCount"] = args.rangeCount;
        FieldToJson(jargs["pRanges"], &args.pRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    args::CmdDispatch&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatch");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["groupCountX"] = args.groupCountX;
        jargs["groupCountY"] = args.groupCountY;
        jargs["groupCountZ"] = args.groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent&                          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        jargs["stageMask"] = VkPipelineStageFlags_t{args.stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        jargs["stageMask"] = VkPipelineStageFlags_t{args.stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["eventCount"] = args.eventCount;
        HandleToJson(jargs["pEvents"], &args.pEvents);
        jargs["srcStageMask"] = VkPipelineStageFlags_t{args.srcStageMask};
        jargs["dstStageMask"] = VkPipelineStageFlags_t{args.dstStageMask};
        jargs["memoryBarrierCount"] = args.memoryBarrierCount;
        FieldToJson(jargs["pMemoryBarriers"], &args.pMemoryBarriers);
        jargs["bufferMemoryBarrierCount"] = args.bufferMemoryBarrierCount;
        FieldToJson(jargs["pBufferMemoryBarriers"], &args.pBufferMemoryBarriers);
        jargs["imageMemoryBarrierCount"] = args.imageMemoryBarrierCount;
        FieldToJson(jargs["pImageMemoryBarriers"], &args.pImageMemoryBarriers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    args::CreateGraphicsPipelines&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateGraphicsPipelines");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelines"], &args.pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    args::CreateFramebuffer&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateFramebuffer");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pFramebuffer"], &args.pFramebuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyFramebuffer&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFramebuffer");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["framebuffer"], args.framebuffer);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pRenderPass"], &args.pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    args::DestroyRenderPass&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyRenderPass");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["renderPass"], args.renderPass);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderAreaGranularity&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderAreaGranularity");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["renderPass"], args.renderPass);
        FieldToJson(jargs["pGranularity"], &args.pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewport&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewport");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstViewport"] = args.firstViewport;
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pViewports"], &args.pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissor&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissor");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstScissor"] = args.firstScissor;
        jargs["scissorCount"] = args.scissorCount;
        FieldToJson(jargs["pScissors"], &args.pScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineWidth&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineWidth");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["lineWidth"], args.lineWidth);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["depthBiasConstantFactor"], args.depthBiasConstantFactor);
        FieldToJson(jargs["depthBiasClamp"], args.depthBiasClamp);
        FieldToJson(jargs["depthBiasSlopeFactor"], args.depthBiasSlopeFactor);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    args::CmdSetBlendConstants&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetBlendConstants");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["blendConstants"], args.blendConstants);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBounds&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBounds");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["minDepthBounds"], args.minDepthBounds);
        FieldToJson(jargs["maxDepthBounds"], args.maxDepthBounds);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilCompareMask&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilCompareMask");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["faceMask"] = VkStencilFaceFlags_t{args.faceMask};
        jargs["compareMask"] = args.compareMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilWriteMask&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilWriteMask");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["faceMask"] = VkStencilFaceFlags_t{args.faceMask};
        jargs["writeMask"] = args.writeMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilReference&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilReference");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["faceMask"] = VkStencilFaceFlags_t{args.faceMask};
        jargs["reference"] = args.reference;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["indexType"] = args.indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        HandleToJson(jargs["pBuffers"], &args.pBuffers);
        FieldToJson(jargs["pOffsets"], &args.pOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    args::CmdDraw&                              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDraw");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["vertexCount"] = args.vertexCount;
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstVertex"] = args.firstVertex;
        jargs["firstInstance"] = args.firstInstance;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexed&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexed");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["indexCount"] = args.indexCount;
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstIndex"] = args.firstIndex;
        jargs["vertexOffset"] = args.vertexOffset;
        jargs["firstInstance"] = args.firstInstance;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirect");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["drawCount"] = args.drawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirect");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["drawCount"] = args.drawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcImage"], args.srcImage);
        jargs["srcImageLayout"] = args.srcImageLayout;
        HandleToJson(jargs["dstImage"], args.dstImage);
        jargs["dstImageLayout"] = args.dstImageLayout;
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
        jargs["filter"] = args.filter;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearDepthStencilImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["image"], args.image);
        jargs["imageLayout"] = args.imageLayout;
        FieldToJson(jargs["pDepthStencil"], &args.pDepthStencil);
        jargs["rangeCount"] = args.rangeCount;
        FieldToJson(jargs["pRanges"], &args.pRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    args::CmdClearAttachments&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearAttachments");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["attachmentCount"] = args.attachmentCount;
        FieldToJson(jargs["pAttachments"], &args.pAttachments);
        jargs["rectCount"] = args.rectCount;
        FieldToJson(jargs["pRects"], &args.pRects);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["srcImage"], args.srcImage);
        jargs["srcImageLayout"] = args.srcImageLayout;
        HandleToJson(jargs["dstImage"], args.dstImage);
        jargs["dstImageLayout"] = args.dstImageLayout;
        jargs["regionCount"] = args.regionCount;
        FieldToJson(jargs["pRegions"], &args.pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderPassBegin"], &args.pRenderPassBegin);
        jargs["contents"] = args.contents;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["contents"] = args.contents;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeatures&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPeerMemoryFeatures");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["heapIndex"] = args.heapIndex;
        jargs["localDeviceIndex"] = args.localDeviceIndex;
        jargs["remoteDeviceIndex"] = args.remoteDeviceIndex;
        FieldToJson(jargs["pPeerMemoryFeatures"], &args.pPeerMemoryFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMask&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMask");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["deviceMask"] = args.deviceMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroups&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceGroups");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pPhysicalDeviceGroupCount"], &args.pPhysicalDeviceGroupCount);
        FieldToJson(jargs["pPhysicalDeviceGroupProperties"], &args.pPhysicalDeviceGroupProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pSparseMemoryRequirementCount"], &args.pSparseMemoryRequirementCount);
        FieldToJson(jargs["pSparseMemoryRequirements"], &args.pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFeatures"], &args.pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        FieldToJson(jargs["pFormatProperties"], &args.pFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pImageFormatInfo"], &args.pImageFormatInfo);
        FieldToJson(jargs["pImageFormatProperties"], &args.pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pQueueFamilyPropertyCount"], &args.pQueueFamilyPropertyCount);
        FieldToJson(jargs["pQueueFamilyProperties"], &args.pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pMemoryProperties"], &args.pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFormatInfo"], &args.pFormatInfo);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPool&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPool");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["commandPool"], args.commandPool);
        jargs["flags"] = VkCommandPoolTrimFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue2&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceQueue2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pQueueInfo"], &args.pQueueInfo);
        HandleToJson(jargs["pQueue"], &args.pQueue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalBufferInfo"], &args.pExternalBufferInfo);
        FieldToJson(jargs["pExternalBufferProperties"], &args.pExternalBufferProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFenceProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFenceProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalFenceInfo"], &args.pExternalFenceInfo);
        FieldToJson(jargs["pExternalFenceProperties"], &args.pExternalFenceProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphoreProperties& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalSemaphoreInfo"], &args.pExternalSemaphoreInfo);
        FieldToJson(jargs["pExternalSemaphoreProperties"], &args.pExternalSemaphoreProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBase&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchBase");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["baseGroupX"] = args.baseGroupX;
        jargs["baseGroupY"] = args.baseGroupY;
        jargs["baseGroupZ"] = args.baseGroupZ;
        jargs["groupCountX"] = args.groupCountX;
        jargs["groupCountY"] = args.groupCountY;
        jargs["groupCountZ"] = args.groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplate&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorUpdateTemplate");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pDescriptorUpdateTemplate"], &args.pDescriptorUpdateTemplate);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplate&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplate");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorUpdateTemplate"], args.descriptorUpdateTemplate);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupport&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupport");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pSupport"], &args.pSupport);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversion&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSamplerYcbcrConversion");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pYcbcrConversion"], &args.pYcbcrConversion);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversion&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversion");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["ycbcrConversion"], args.ycbcrConversion);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPool&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetQueryPool");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValue&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreCounterValue");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["semaphore"], args.semaphore);
        FieldToJson(jargs["pValue"], &args.pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphores&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitSemaphores");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pWaitInfo"], &args.pWaitInfo);
        jargs["timeout"] = args.timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphore&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphore");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pSignalInfo"], &args.pSignalInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddress&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddress");
    FieldToJsonAsHex(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddress&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddress");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddress&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCount");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCount");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pRenderPass"], &args.pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderPassBegin"], &args.pRenderPassBegin);
        FieldToJson(jargs["pSubpassBeginInfo"], &args.pSubpassBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSubpassBeginInfo"], &args.pSubpassBeginInfo);
        FieldToJson(jargs["pSubpassEndInfo"], &args.pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSubpassEndInfo"], &args.pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolProperties&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceToolProperties");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pToolCount"], &args.pToolCount);
        FieldToJson(jargs["pToolProperties"], &args.pToolProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlot&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePrivateDataSlot");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPrivateDataSlot"], &args.pPrivateDataSlot);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlot&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlot");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    args::SetPrivateData&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetPrivateData");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["objectType"] = args.objectType;
        HandleToJson(jargs["objectHandle"], args.objectHandle);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        jargs["data"] = args.data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    args::GetPrivateData&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPrivateData");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["objectType"] = args.objectType;
        HandleToJson(jargs["objectHandle"], args.objectHandle);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        FieldToJson(jargs["pData"], &args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDependencyInfo"], &args.pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["stage"] = VkPipelineStageFlags2_t{args.stage};
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit2");
    jdata[format::kNameSubmitIndex] = ++submit_index_;
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        jargs["submitCount"] = args.submitCount;
        FieldToJson(jargs["pSubmits"], &args.pSubmits);
        HandleToJson(jargs["fence"], args.fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyBufferInfo"], &args.pCopyBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyImageInfo"], &args.pCopyImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyBufferToImageInfo"], &args.pCopyBufferToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyImageToBufferInfo"], &args.pCopyImageToBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirements&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirements&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirements& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSparseMemoryRequirements");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pSparseMemoryRequirementCount"], &args.pSparseMemoryRequirementCount);
        FieldToJson(jargs["pSparseMemoryRequirements"], &args.pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        FieldToJson(jargs["pDependencyInfo"], &args.pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        jargs["stageMask"] = VkPipelineStageFlags2_t{args.stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["eventCount"] = args.eventCount;
        HandleToJson(jargs["pEvents"], &args.pEvents);
        FieldToJson(jargs["pDependencyInfos"], &args.pDependencyInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBlitImageInfo"], &args.pBlitImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pResolveImageInfo"], &args.pResolveImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRendering");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderingInfo"], &args.pRenderingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullMode&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullMode");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["cullMode"] = VkCullModeFlags_t{args.cullMode};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFace&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFace");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["frontFace"] = args.frontFace;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopology&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopology");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["primitiveTopology"] = args.primitiveTopology;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCount&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCount");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pViewports"], &args.pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCount&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCount");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["scissorCount"] = args.scissorCount;
        FieldToJson(jargs["pScissors"], &args.pScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        HandleToJson(jargs["pBuffers"], &args.pBuffers);
        FieldToJson(jargs["pOffsets"], &args.pOffsets);
        FieldToJson(jargs["pSizes"], &args.pSizes);
        FieldToJson(jargs["pStrides"], &args.pStrides);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnable&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthTestEnable"], args.depthTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnable&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthWriteEnable"], args.depthWriteEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOp&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOp");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["depthCompareOp"] = args.depthCompareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnable&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthBoundsTestEnable"], args.depthBoundsTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnable&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["stencilTestEnable"], args.stencilTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOp&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilOp");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["faceMask"] = VkStencilFaceFlags_t{args.faceMask};
        jargs["failOp"] = args.failOp;
        jargs["passOp"] = args.passOp;
        jargs["depthFailOp"] = args.depthFailOp;
        jargs["compareOp"] = args.compareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnable&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["rasterizerDiscardEnable"], args.rasterizerDiscardEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnable&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthBiasEnable"], args.depthBiasEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnable&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnable");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["primitiveRestartEnable"], args.primitiveRestartEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    args::MapMemory2&                           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pMemoryMapInfo"], &args.pMemoryMapInfo);
        FieldToJsonAsHex(jargs["ppData"], args.ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2&                         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pMemoryUnmapInfo"], &args.pMemoryUnmapInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayout&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayout");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pSubresource"], &args.pSubresource);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImage(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImage&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImage");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyMemoryToImageInfo"], &args.pCopyMemoryToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemory(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemory&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemory");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyImageToMemoryInfo"], &args.pCopyImageToMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImage(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImage&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImage");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyImageToImageInfo"], &args.pCopyImageToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayout&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTransitionImageLayout");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["transitionCount"] = args.transitionCount;
        FieldToJson(jargs["pTransitions"], &args.pTransitions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["layout"], args.layout);
        jargs["set"] = args.set;
        jargs["descriptorWriteCount"] = args.descriptorWriteCount;
        FieldToJson(jargs["pDescriptorWrites"], &args.pDescriptorWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBindDescriptorSetsInfo"], &args.pBindDescriptorSetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushConstants2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPushConstantsInfo"], &args.pPushConstantsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPushDescriptorSetInfo"], &args.pPushDescriptorSetInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStipple&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStipple");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["lineStippleFactor"] = args.lineStippleFactor;
        jargs["lineStipplePattern"] = args.lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer2");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["size"] = args.size;
        jargs["indexType"] = args.indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularity&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularity");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pRenderingAreaInfo"], &args.pRenderingAreaInfo);
        FieldToJson(jargs["pGranularity"], &args.pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocations&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingAttachmentLocations");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pLocationInfo"], &args.pLocationInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndices& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingInputAttachmentIndices");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInputAttachmentIndexInfo"], &args.pInputAttachmentIndexInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySurfaceKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySurfaceKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceSupportKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceSupportKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        HandleToJson(jargs["surface"], args.surface);
        Bool32ToJson(jargs["pSupported"], &args.pSupported);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pSurfaceCapabilities"], &args.pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormatsKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pSurfaceFormatCount"], &args.pSurfaceFormatCount);
        FieldToJson(jargs["pSurfaceFormats"], &args.pSurfaceFormats);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pPresentModeCount"], &args.pPresentModeCount);
        FieldToJson(jargs["pPresentModes"], &args.pPresentModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSwapchainKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSwapchainKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSwapchain"], &args.pSwapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySwapchainKHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySwapchainKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainImagesKHR&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainImagesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pSwapchainImageCount"], &args.pSwapchainImageCount);
        HandleToJson(jargs["pSwapchainImages"], &args.pSwapchainImages);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImageKHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireNextImageKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        jargs["timeout"] = args.timeout;
        HandleToJson(jargs["semaphore"], args.semaphore);
        HandleToJson(jargs["fence"], args.fence);
        FieldToJson(jargs["pImageIndex"], &args.pImageIndex);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    args::QueuePresentKHR&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueuePresentKHR");
    jdata[format::kNameSubmitIndex] = ++submit_index_;
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pPresentInfo"], &args.pPresentInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPresentCapabilitiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pDeviceGroupPresentCapabilities"], &args.pDeviceGroupPresentCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupSurfacePresentModesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pModes"], &args.pModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDevicePresentRectanglesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDevicePresentRectanglesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pRectCount"], &args.pRectCount);
        FieldToJson(jargs["pRects"], &args.pRects);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImage2KHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireNextImage2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAcquireInfo"], &args.pAcquireInfo);
        FieldToJson(jargs["pImageIndex"], &args.pImageIndex);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneSupportedDisplaysKHR&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneSupportedDisplaysKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["planeIndex"] = args.planeIndex;
        FieldToJson(jargs["pDisplayCount"], &args.pDisplayCount);
        HandleToJson(jargs["pDisplays"], &args.pDisplays);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModePropertiesKHR&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayModePropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["display"], args.display);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayModeKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDisplayModeKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["display"], args.display);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pMode"], &args.pMode);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilitiesKHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneCapabilitiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["mode"], args.mode);
        jargs["planeIndex"] = args.planeIndex;
        FieldToJson(jargs["pCapabilities"], &args.pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayPlaneSurfaceKHR&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDisplayPlaneSurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSharedSwapchainsKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSharedSwapchainsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["swapchainCount"] = args.swapchainCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSwapchains"], &args.pSwapchains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXlibSurfaceKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateXlibSurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXlibPresentationSupportKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["dpy"] = args.dpy;
        jargs["visualID"] = args.visualID;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXcbSurfaceKHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateXcbSurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXcbPresentationSupportKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["connection"] = args.connection;
        jargs["visual_id"] = args.visual_id;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWaylandSurfaceKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateWaylandSurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWaylandPresentationSupportKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["display"] = args.display;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAndroidSurfaceKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAndroidSurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWin32SurfaceKHR&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateWin32SurfaceKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWin32PresentationSupportKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoCapabilitiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pVideoProfile"], &args.pVideoProfile);
        FieldToJson(jargs["pCapabilities"], &args.pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoFormatPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pVideoFormatInfo"], &args.pVideoFormatInfo);
        FieldToJson(jargs["pVideoFormatPropertyCount"], &args.pVideoFormatPropertyCount);
        FieldToJson(jargs["pVideoFormatProperties"], &args.pVideoFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionKHR&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateVideoSessionKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pVideoSession"], &args.pVideoSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionKHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["videoSession"], args.videoSession);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetVideoSessionMemoryRequirementsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetVideoSessionMemoryRequirementsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["videoSession"], args.videoSession);
        FieldToJson(jargs["pMemoryRequirementsCount"], &args.pMemoryRequirementsCount);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::BindVideoSessionMemoryKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindVideoSessionMemoryKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["videoSession"], args.videoSession);
        jargs["bindSessionMemoryInfoCount"] = args.bindSessionMemoryInfoCount;
        FieldToJson(jargs["pBindSessionMemoryInfos"], &args.pBindSessionMemoryInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionParametersKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateVideoSessionParametersKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pVideoSessionParameters"], &args.pVideoSessionParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::UpdateVideoSessionParametersKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateVideoSessionParametersKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["videoSessionParameters"], args.videoSessionParameters);
        FieldToJson(jargs["pUpdateInfo"], &args.pUpdateInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionParametersKHR&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionParametersKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["videoSessionParameters"], args.videoSessionParameters);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginVideoCodingKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBeginInfo"], &args.pBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndVideoCodingKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndVideoCodingKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pEndCodingInfo"], &args.pEndCodingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdControlVideoCodingKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdControlVideoCodingKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCodingControlInfo"], &args.pCodingControlInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecodeVideoKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDecodeInfo"], &args.pDecodeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderingKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderingInfo"], &args.pRenderingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderingKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderingKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2KHR&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFeatures"], &args.pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2KHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        FieldToJson(jargs["pFormatProperties"], &args.pFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pImageFormatInfo"], &args.pImageFormatInfo);
        FieldToJson(jargs["pImageFormatProperties"], &args.pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pQueueFamilyPropertyCount"], &args.pQueueFamilyPropertyCount);
        FieldToJson(jargs["pQueueFamilyProperties"], &args.pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pMemoryProperties"], &args.pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFormatInfo"], &args.pFormatInfo);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeaturesKHR&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["heapIndex"] = args.heapIndex;
        jargs["localDeviceIndex"] = args.localDeviceIndex;
        jargs["remoteDeviceIndex"] = args.remoteDeviceIndex;
        FieldToJson(jargs["pPeerMemoryFeatures"], &args.pPeerMemoryFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMaskKHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMaskKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["deviceMask"] = args.deviceMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBaseKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchBaseKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["baseGroupX"] = args.baseGroupX;
        jargs["baseGroupY"] = args.baseGroupY;
        jargs["baseGroupZ"] = args.baseGroupZ;
        jargs["groupCountX"] = args.groupCountX;
        jargs["groupCountY"] = args.groupCountY;
        jargs["groupCountZ"] = args.groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPoolKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPoolKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["commandPool"], args.commandPool);
        jargs["flags"] = VkCommandPoolTrimFlags_t{args.flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroupsKHR&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceGroupsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pPhysicalDeviceGroupCount"], &args.pPhysicalDeviceGroupCount);
        FieldToJson(jargs["pPhysicalDeviceGroupProperties"], &args.pPhysicalDeviceGroupProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalBufferInfo"], &args.pExternalBufferInfo);
        FieldToJson(jargs["pExternalBufferProperties"], &args.pExternalBufferProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandleKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetWin32HandleInfo"], &args.pGetWin32HandleInfo);
        FieldToJson(jargs["pHandle"], args.pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandlePropertiesKHR&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandlePropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["handleType"] = args.handleType;
        jargs["handle"] = args.handle;
        FieldToJson(jargs["pMemoryWin32HandleProperties"], &args.pMemoryWin32HandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdKHR&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryFdKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetFdInfo"], &args.pGetFdInfo);
        FieldToJson(jargs["pFd"], &args.pFd);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdPropertiesKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryFdPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["handleType"] = args.handleType;
        jargs["fd"] = args.fd;
        FieldToJson(jargs["pMemoryFdProperties"], &args.pMemoryFdProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalSemaphoreInfo"], &args.pExternalSemaphoreInfo);
        FieldToJson(jargs["pExternalSemaphoreProperties"], &args.pExternalSemaphoreProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreWin32HandleKHR&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreWin32HandleKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pImportSemaphoreWin32HandleInfo"], &args.pImportSemaphoreWin32HandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreWin32HandleKHR&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreWin32HandleKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetWin32HandleInfo"], &args.pGetWin32HandleInfo);
        FieldToJson(jargs["pHandle"], args.pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreFdKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreFdKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pImportSemaphoreFdInfo"], &args.pImportSemaphoreFdInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreFdKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreFdKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetFdInfo"], &args.pGetFdInfo);
        FieldToJson(jargs["pFd"], &args.pFd);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["layout"], args.layout);
        jargs["set"] = args.set;
        jargs["descriptorWriteCount"] = args.descriptorWriteCount;
        FieldToJson(jargs["pDescriptorWrites"], &args.pDescriptorWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplateKHR&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorUpdateTemplateKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pDescriptorUpdateTemplate"], &args.pDescriptorUpdateTemplate);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplateKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplateKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorUpdateTemplate"], args.descriptorUpdateTemplate);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2KHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pRenderPass"], &args.pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderPassBegin"], &args.pRenderPassBegin);
        FieldToJson(jargs["pSubpassBeginInfo"], &args.pSubpassBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2KHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSubpassBeginInfo"], &args.pSubpassBeginInfo);
        FieldToJson(jargs["pSubpassEndInfo"], &args.pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2KHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSubpassEndInfo"], &args.pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainStatusKHR&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainStatusKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFencePropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pExternalFenceInfo"], &args.pExternalFenceInfo);
        FieldToJson(jargs["pExternalFenceProperties"], &args.pExternalFenceProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceWin32HandleKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceWin32HandleKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pImportFenceWin32HandleInfo"], &args.pImportFenceWin32HandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceWin32HandleKHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceWin32HandleKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetWin32HandleInfo"], &args.pGetWin32HandleInfo);
        FieldToJson(jargs["pHandle"], args.pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceFdKHR&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceFdKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pImportFenceFdInfo"], &args.pImportFenceFdInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceFdKHR&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceFdKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetFdInfo"], &args.pGetFdInfo);
        FieldToJson(jargs["pFd"], &args.pFd);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        FieldToJson(jargs["pCounterCount"], &args.pCounterCount);
        FieldToJson(jargs["pCounters"], &args.pCounters);
        FieldToJson(jargs["pCounterDescriptions"], &args.pCounterDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPerformanceQueryCreateInfo"], &args.pPerformanceQueryCreateInfo);
        FieldToJson(jargs["pNumPasses"], &args.pNumPasses);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireProfilingLockKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireProfilingLockKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseProfilingLockKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseProfilingLockKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pSurfaceInfo"], &args.pSurfaceInfo);
        FieldToJson(jargs["pSurfaceCapabilities"], &args.pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormats2KHR&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pSurfaceInfo"], &args.pSurfaceInfo);
        FieldToJson(jargs["pSurfaceFormatCount"], &args.pSurfaceFormatCount);
        FieldToJson(jargs["pSurfaceFormats"], &args.pSurfaceFormats);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayProperties2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModeProperties2KHR&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayModeProperties2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["display"], args.display);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilities2KHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneCapabilities2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pDisplayPlaneInfo"], &args.pDisplayPlaneInfo);
        FieldToJson(jargs["pCapabilities"], &args.pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2KHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2KHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2KHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pSparseMemoryRequirementCount"], &args.pSparseMemoryRequirementCount);
        FieldToJson(jargs["pSparseMemoryRequirements"], &args.pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversionKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSamplerYcbcrConversionKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pYcbcrConversion"], &args.pYcbcrConversion);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversionKHR&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversionKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["ycbcrConversion"], args.ycbcrConversion);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2KHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2KHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupportKHR&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupportKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pSupport"], &args.pSupport);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCountKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCountKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValueKHR&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreCounterValueKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["semaphore"], args.semaphore);
        FieldToJson(jargs["pValue"], &args.pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphoresKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitSemaphoresKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pWaitInfo"], &args.pWaitInfo);
        jargs["timeout"] = args.timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphoreKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphoreKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pSignalInfo"], &args.pSignalInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFragmentShadingRatesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pFragmentShadingRateCount"], &args.pFragmentShadingRateCount);
        FieldToJson(jargs["pFragmentShadingRates"], &args.pFragmentShadingRates);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateKHR&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pFragmentSize"], &args.pFragmentSize);
        FieldToJson(jargs["combinerOps"], args.combinerOps);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocationsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingAttachmentLocationsKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pLocationInfo"], &args.pLocationInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndicesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingInputAttachmentIndicesKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInputAttachmentIndexInfo"], &args.pInputAttachmentIndexInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresentKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForPresentKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        jargs["presentId"] = args.presentId;
        jargs["timeout"] = args.timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressKHR");
    FieldToJsonAsHex(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddressKHR&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddressKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddressKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDeferredOperationKHR&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDeferredOperationKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pDeferredOperation"], &args.pDeferredOperation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDeferredOperationKHR&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDeferredOperationKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["operation"], args.operation);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationMaxConcurrencyKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationMaxConcurrencyKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["operation"], args.operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationResultKHR&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationResultKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["operation"], args.operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    args::DeferredOperationJoinKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeferredOperationJoinKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["operation"], args.operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutablePropertiesKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutablePropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pPipelineInfo"], &args.pPipelineInfo);
        FieldToJson(jargs["pExecutableCount"], &args.pExecutableCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableStatisticsKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutableStatisticsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pExecutableInfo"], &args.pExecutableInfo);
        FieldToJson(jargs["pStatisticCount"], &args.pStatisticCount);
        FieldToJson(jargs["pStatistics"], &args.pStatistics);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableInternalRepresentationsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutableInternalRepresentationsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pExecutableInfo"], &args.pExecutableInfo);
        FieldToJson(jargs["pInternalRepresentationCount"], &args.pInternalRepresentationCount);
        FieldToJson(jargs["pInternalRepresentations"], &args.pInternalRepresentations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::MapMemory2KHR&                        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pMemoryMapInfo"], &args.pMemoryMapInfo);
        FieldToJsonAsHex(jargs["ppData"], args.ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2KHR&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pMemoryUnmapInfo"], &args.pMemoryUnmapInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pQualityLevelInfo"], &args.pQualityLevelInfo);
        FieldToJson(jargs["pQualityLevelProperties"], &args.pQualityLevelProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::GetEncodedVideoSessionParametersKHR&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEncodedVideoSessionParametersKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pVideoSessionParametersInfo"], &args.pVideoSessionParametersInfo);
        FieldToJson(jargs["pFeedbackInfo"], &args.pFeedbackInfo);
        FieldToJson(jargs["pDataSize"], &args.pDataSize);
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEncodeVideoKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pEncodeInfo"], &args.pEncodeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        FieldToJson(jargs["pDependencyInfo"], &args.pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2KHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["event"], args.event);
        jargs["stageMask"] = VkPipelineStageFlags2_t{args.stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["eventCount"] = args.eventCount;
        HandleToJson(jargs["pEvents"], &args.pEvents);
        FieldToJson(jargs["pDependencyInfos"], &args.pDependencyInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDependencyInfo"], &args.pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2KHR&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["stage"] = VkPipelineStageFlags2_t{args.stage};
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2KHR&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit2KHR");
    jdata[format::kNameSubmitIndex] = ++submit_index_;
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        jargs["submitCount"] = args.submitCount;
        FieldToJson(jargs["pSubmits"], &args.pSubmits);
        HandleToJson(jargs["fence"], args.fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer3KHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer3KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers3KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers3KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        FieldToJson(jargs["pBindingInfos"], &args.pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect2KHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirect2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect2KHR&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirect2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect2KHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryKHR&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyMemoryInfo"], &args.pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToImageKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyMemoryInfo"], &args.pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyMemoryInfo"], &args.pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateMemoryKHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdateMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDstRange"], &args.pDstRange);
        jargs["dstFlags"] = VkAddressCommandFlagsKHR_t{args.dstFlags};
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdFillMemoryKHR&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdFillMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDstRange"], &args.pDstRange);
        jargs["dstFlags"] = VkAddressCommandFlagsKHR_t{args.dstFlags};
        jargs["data"] = args.data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResultsToMemoryKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyQueryPoolResultsToMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
        FieldToJson(jargs["pDstRange"], &args.pDstRange);
        jargs["dstFlags"] = VkAddressCommandFlagsKHR_t{args.dstFlags};
        jargs["queryResultFlags"] = VkQueryResultFlags_t{args.queryResultFlags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount2KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCount2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount2KHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCount2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRendering2EXT&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRendering2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pConditionalRenderingBegin"], &args.pConditionalRenderingBegin);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffers2EXT&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTransformFeedbackBuffers2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        FieldToJson(jargs["pBindingInfos"], &args.pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedback2EXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginTransformFeedback2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstCounterRange"] = args.firstCounterRange;
        jargs["counterRangeCount"] = args.counterRangeCount;
        FieldToJson(jargs["pCounterInfos"], &args.pCounterInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedback2EXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndTransformFeedback2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstCounterRange"] = args.firstCounterRange;
        jargs["counterRangeCount"] = args.counterRangeCount;
        FieldToJson(jargs["pCounterInfos"], &args.pCounterInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCount2EXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectByteCount2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstInstance"] = args.firstInstance;
        FieldToJson(jargs["pCounterInfo"], &args.pCounterInfo);
        jargs["counterOffset"] = args.counterOffset;
        jargs["vertexStride"] = args.vertexStride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirect2EXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirect2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCount2EXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCount2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMarkerToMemoryAMD&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteMarkerToMemoryAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructure2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructure2KHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructure2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pAccelerationStructure"], &args.pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyBufferInfo"], &args.pCopyBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyImageInfo"], &args.pCopyImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyBufferToImageInfo"], &args.pCopyBufferToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyImageToBufferInfo"], &args.pCopyImageToBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBlitImageInfo"], &args.pBlitImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pResolveImageInfo"], &args.pResolveImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirect2KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirect2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJsonAsHex(jargs["indirectDeviceAddress"], args.indirectDeviceAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirementsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirementsKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirementsKHR&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirementsKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirementsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSparseMemoryRequirementsKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pSparseMemoryRequirementCount"], &args.pSparseMemoryRequirementCount);
        FieldToJson(jargs["pSparseMemoryRequirements"], &args.pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["size"] = args.size;
        jargs["indexType"] = args.indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularityKHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularityKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pRenderingAreaInfo"], &args.pRenderingAreaInfo);
        FieldToJson(jargs["pGranularity"], &args.pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayoutKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayoutKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2KHR&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2KHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pSubresource"], &args.pSubresource);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitForPresent2KHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresent2KHR&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForPresent2KHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pPresentWait2Info"], &args.pPresentWait2Info);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineBinariesKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePipelineBinariesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        FieldToJson(jargs["pBinaries"], &args.pBinaries);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineBinaryKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineBinaryKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineBinary"], args.pipelineBinary);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineKeyKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineKeyKHR&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineKeyKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pPipelineCreateInfo"], &args.pPipelineCreateInfo);
        FieldToJson(jargs["pPipelineKey"], &args.pPipelineKey);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineBinaryDataKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineBinaryDataKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineBinaryDataKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pPipelineBinaryKey"], &args.pPipelineBinaryKey);
        FieldToJson(jargs["pPipelineBinaryDataSize"], &args.pPipelineBinaryDataSize);
        FieldToJson(jargs["pPipelineBinaryData"], args.pPipelineBinaryData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseCapturedPipelineDataKHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseCapturedPipelineDataKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesKHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pReleaseInfo"], &args.pReleaseInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleKHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["lineStippleFactor"] = args.lineStippleFactor;
        jargs["lineStipplePattern"] = args.lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pTimeDomainCount"], &args.pTimeDomainCount);
        FieldToJson(jargs["pTimeDomains"], &args.pTimeDomains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsKHR&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetCalibratedTimestampsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["timestampCount"] = args.timestampCount;
        FieldToJson(jargs["pTimestampInfos"], &args.pTimestampInfos);
        FieldToJson(jargs["pTimestamps"], &args.pTimestamps);
        FieldToJson(jargs["pMaxDeviation"], &args.pMaxDeviation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBindDescriptorSetsInfo"], &args.pBindDescriptorSetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2KHR&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushConstants2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPushConstantsInfo"], &args.pPushConstantsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPushDescriptorSetInfo"], &args.pPushDescriptorSetInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsets2EXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDescriptorBufferOffsets2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSetDescriptorBufferOffsetsInfo"], &args.pSetDescriptorBufferOffsetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBindDescriptorBufferEmbeddedSamplersInfo"], &args.pBindDescriptorBufferEmbeddedSamplersInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryIndirectKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryIndirectKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyMemoryIndirectInfo"], &args.pCopyMemoryIndirectInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToImageIndirectKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pCopyMemoryToImageIndirectInfo"], &args.pCopyMemoryToImageIndirectInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultReportsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultReportsKHR&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultReportsKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["timeout"] = args.timeout;
        FieldToJson(jargs["pFaultCounts"], &args.pFaultCounts);
        FieldToJson(jargs["pFaultInfo"], &args.pFaultInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultDebugInfoKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultDebugInfoKHR&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultDebugInfoKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pDebugInfo"], &args.pDebugInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2KHR&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering2KHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderingEndInfo"], &args.pRenderingEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    args::FrameBoundaryANDROID&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFrameBoundaryANDROID");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["semaphore"], args.semaphore);
        HandleToJson(jargs["image"], args.image);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugReportCallbackEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDebugReportCallbackEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pCallback"], &args.pCallback);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugReportCallbackEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugReportCallbackEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        HandleToJson(jargs["callback"], args.callback);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    args::DebugReportMessageEXT&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugReportMessageEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        jargs["flags"] = VkDebugReportFlagsEXT_t{args.flags};
        jargs["objectType"] = args.objectType;
        HandleToJson(jargs["object"], args.object);
        jargs["location"] = args.location;
        jargs["messageCode"] = args.messageCode;
        FieldToJson(jargs["pLayerPrefix"], &args.pLayerPrefix);
        FieldToJson(jargs["pMessage"], &args.pMessage);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectTagEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectTagEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pTagInfo"], &args.pTagInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectNameEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectNameEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pNameInfo"], &args.pNameInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerBeginEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerBeginEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pMarkerInfo"], &args.pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerEndEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerEndEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerInsertEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerInsertEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pMarkerInfo"], &args.pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTransformFeedbackBuffersEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        HandleToJson(jargs["pBuffers"], &args.pBuffers);
        FieldToJson(jargs["pOffsets"], &args.pOffsets);
        FieldToJson(jargs["pSizes"], &args.pSizes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginTransformFeedbackEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstCounterBuffer"] = args.firstCounterBuffer;
        jargs["counterBufferCount"] = args.counterBufferCount;
        HandleToJson(jargs["pCounterBuffers"], &args.pCounterBuffers);
        FieldToJson(jargs["pCounterBufferOffsets"], &args.pCounterBufferOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndTransformFeedbackEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstCounterBuffer"] = args.firstCounterBuffer;
        jargs["counterBufferCount"] = args.counterBufferCount;
        HandleToJson(jargs["pCounterBuffers"], &args.pCounterBuffers);
        FieldToJson(jargs["pCounterBufferOffsets"], &args.pCounterBufferOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQueryIndexedEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginQueryIndexedEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
        jargs["flags"] = VkQueryControlFlags_t{args.flags};
        jargs["index"] = args.index;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndQueryIndexedEXT&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQueryIndexedEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["query"] = args.query;
        jargs["index"] = args.index;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectByteCountEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstInstance"] = args.firstInstance;
        HandleToJson(jargs["counterBuffer"], args.counterBuffer);
        jargs["counterBufferOffset"] = args.counterBufferOffset;
        jargs["counterOffset"] = args.counterOffset;
        jargs["vertexStride"] = args.vertexStride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandleNVX&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandleNVX");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandle64NVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandle64NVX&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandle64NVX");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewAddressNVX&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewAddressNVX");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["imageView"], args.imageView);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceCombinedImageSamplerIndexNVX(
    const ApiCallInfo&                          call_info,
    args::GetDeviceCombinedImageSamplerIndexNVX& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceCombinedImageSamplerIndexNVX");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["imageViewIndex"] = args.imageViewIndex;
        jargs["samplerIndex"] = args.samplerIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCountAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCountAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetShaderInfoAMD&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderInfoAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["shaderStage"] = args.shaderStage;
        jargs["infoType"] = args.infoType;
        FieldToJson(jargs["pInfoSize"], &args.pInfoSize);
        FieldToJson(jargs["pInfo"], args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    args::CreateStreamDescriptorSurfaceGGP&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateStreamDescriptorSurfaceGGP");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["format"] = args.format;
        jargs["type"] = args.type;
        jargs["tiling"] = args.tiling;
        jargs["usage"] = VkImageUsageFlags_t{args.usage};
        jargs["flags"] = VkImageCreateFlags_t{args.flags};
        jargs["externalHandleType"] = VkExternalMemoryHandleTypeFlagsNV_t{args.externalHandleType};
        FieldToJson(jargs["pExternalImageFormatProperties"], &args.pExternalImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleNV&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandleNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
        jargs["handleType"] = VkExternalMemoryHandleTypeFlagsNV_t{args.handleType};
        FieldToJson(jargs["pHandle"], args.pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    args::CreateViSurfaceNN&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateViSurfaceNN");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRenderingEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pConditionalRenderingBegin"], &args.pConditionalRenderingBegin);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndConditionalRenderingEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndConditionalRenderingEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingNV&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstViewport"] = args.firstViewport;
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pViewportWScalings"], &args.pViewportWScalings);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseDisplayEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseDisplayEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["display"], args.display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireXlibDisplayEXT&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireXlibDisplayEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["dpy"] = args.dpy;
        HandleToJson(jargs["display"], args.display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetRandROutputDisplayEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRandROutputDisplayEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["dpy"] = args.dpy;
        jargs["rrOutput"] = args.rrOutput;
        HandleToJson(jargs["pDisplay"], &args.pDisplay);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2EXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["surface"], args.surface);
        FieldToJson(jargs["pSurfaceCapabilities"], &args.pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    args::DisplayPowerControlEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDisplayPowerControlEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["display"], args.display);
        FieldToJson(jargs["pDisplayPowerInfo"], &args.pDisplayPowerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDeviceEventEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkRegisterDeviceEventEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pDeviceEventInfo"], &args.pDeviceEventInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pFence"], &args.pFence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDisplayEventEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkRegisterDisplayEventEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["display"], args.display);
        FieldToJson(jargs["pDisplayEventInfo"], &args.pDisplayEventInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pFence"], &args.pFence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainCounterEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainCounterEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        jargs["counter"] = args.counter;
        FieldToJson(jargs["pCounterValue"], &args.pCounterValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetRefreshCycleDurationGOOGLE&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRefreshCycleDurationGOOGLE");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pDisplayTimingProperties"], &args.pDisplayTimingProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingGOOGLE&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPastPresentationTimingGOOGLE");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pPresentationTimingCount"], &args.pPresentationTimingCount);
        FieldToJson(jargs["pPresentationTimings"], &args.pPresentationTimings);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstDiscardRectangle"] = args.firstDiscardRectangle;
        jargs["discardRectangleCount"] = args.discardRectangleCount;
        FieldToJson(jargs["pDiscardRectangles"], &args.pDiscardRectangles);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEnableEXT&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["discardRectangleEnable"], args.discardRectangleEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleModeEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["discardRectangleMode"] = args.discardRectangleMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    args::SetHdrMetadataEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetHdrMetadataEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["swapchainCount"] = args.swapchainCount;
        HandleToJson(jargs["pSwapchains"], &args.pSwapchains);
        FieldToJson(jargs["pMetadata"], &args.pMetadata);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateIOSSurfaceMVK&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIOSSurfaceMVK");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateMacOSSurfaceMVK&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMacOSSurfaceMVK");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectNameEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectNameEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pNameInfo"], &args.pNameInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectTagEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectTagEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pTagInfo"], &args.pTagInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueBeginDebugUtilsLabelEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBeginDebugUtilsLabelEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pLabelInfo"], &args.pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueEndDebugUtilsLabelEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueEndDebugUtilsLabelEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueInsertDebugUtilsLabelEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueInsertDebugUtilsLabelEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pLabelInfo"], &args.pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginDebugUtilsLabelEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginDebugUtilsLabelEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pLabelInfo"], &args.pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndDebugUtilsLabelEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndDebugUtilsLabelEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdInsertDebugUtilsLabelEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdInsertDebugUtilsLabelEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pLabelInfo"], &args.pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugUtilsMessengerEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDebugUtilsMessengerEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pMessenger"], &args.pMessenger);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugUtilsMessengerEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugUtilsMessengerEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        HandleToJson(jargs["messenger"], args.messenger);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    args::SubmitDebugUtilsMessageEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSubmitDebugUtilsMessageEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        jargs["messageSeverity"] = args.messageSeverity;
        jargs["messageTypes"] = VkDebugUtilsMessageTypeFlagsEXT_t{args.messageTypes};
        FieldToJson(jargs["pCallbackData"], &args.pCallbackData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    args::GetAndroidHardwareBufferPropertiesANDROID& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAndroidHardwareBufferPropertiesANDROID");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["buffer"] = args.buffer;
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    args::GetMemoryAndroidHardwareBufferANDROID& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryAndroidHardwareBufferANDROID");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pBuffer"], args.pBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CreateGpaSessionAMD&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateGpaSessionAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pGpaSession"], &args.pGpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::DestroyGpaSessionAMD&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyGpaSessionAMD");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetGpaDeviceClockModeAMD(
    const ApiCallInfo&                          call_info,
    args::SetGpaDeviceClockModeAMD&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetGpaDeviceClockModeAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGpaDeviceClockInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaDeviceClockInfoAMD&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGpaDeviceClockInfoAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSessionAMD&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginGpaSessionAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSessionAMD&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndGpaSessionAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSampleAMD&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginGpaSampleAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
        FieldToJson(jargs["pGpaSampleBeginInfo"], &args.pGpaSampleBeginInfo);
        FieldToJson(jargs["pSampleID"], &args.pSampleID);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSampleAMD&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndGpaSampleAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
        jargs["sampleID"] = args.sampleID;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGpaSessionStatusAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionStatusAMD&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGpaSessionStatusAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionResultsAMD&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGpaSessionResultsAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
        jargs["sampleID"] = args.sampleID;
        FieldToJson(jargs["pSizeInBytes"], &args.pSizeInBytes);
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::ResetGpaSessionAMD&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetGpaSessionAMD");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::CmdCopyGpaSessionResultsAMD&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyGpaSessionResultsAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["gpaSession"], args.gpaSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pSampleLocationsInfo"], &args.pSampleLocationsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMultisamplePropertiesEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["samples"] = args.samples;
        FieldToJson(jargs["pMultisampleProperties"], &args.pMultisampleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetImageDrmFormatModifierPropertiesEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageDrmFormatModifierPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::CreateValidationCacheEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateValidationCacheEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pValidationCache"], &args.pValidationCache);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyValidationCacheEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyValidationCacheEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["validationCache"], args.validationCache);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    args::MergeValidationCachesEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMergeValidationCachesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["dstCache"], args.dstCache);
        jargs["srcCacheCount"] = args.srcCacheCount;
        HandleToJson(jargs["pSrcCaches"], &args.pSrcCaches);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetValidationCacheDataEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetValidationCacheDataEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["validationCache"], args.validationCache);
        FieldToJson(jargs["pDataSize"], &args.pDataSize);
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadingRateImageNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["imageView"], args.imageView);
        jargs["imageLayout"] = args.imageLayout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportShadingRatePaletteNV&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportShadingRatePaletteNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstViewport"] = args.firstViewport;
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pShadingRatePalettes"], &args.pShadingRatePalettes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoarseSampleOrderNV&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoarseSampleOrderNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["sampleOrderType"] = args.sampleOrderType;
        jargs["customSampleOrderCount"] = args.customSampleOrderCount;
        FieldToJson(jargs["pCustomSampleOrders"], &args.pCustomSampleOrders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureNV&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructureNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pAccelerationStructure"], &args.pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["accelerationStructure"], args.accelerationStructure);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureMemoryRequirementsNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureMemoryRequirementsNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    args::BindAccelerationStructureMemoryNV&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindAccelerationStructureMemoryNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructureNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildAccelerationStructureNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        HandleToJson(jargs["instanceData"], args.instanceData);
        jargs["instanceOffset"] = args.instanceOffset;
        Bool32ToJson(jargs["update"], args.update);
        HandleToJson(jargs["dst"], args.dst);
        HandleToJson(jargs["src"], args.src);
        HandleToJson(jargs["scratch"], args.scratch);
        jargs["scratchOffset"] = args.scratchOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["dst"], args.dst);
        HandleToJson(jargs["src"], args.src);
        jargs["mode"] = args.mode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysNV&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["raygenShaderBindingTableBuffer"], args.raygenShaderBindingTableBuffer);
        jargs["raygenShaderBindingOffset"] = args.raygenShaderBindingOffset;
        HandleToJson(jargs["missShaderBindingTableBuffer"], args.missShaderBindingTableBuffer);
        jargs["missShaderBindingOffset"] = args.missShaderBindingOffset;
        jargs["missShaderBindingStride"] = args.missShaderBindingStride;
        HandleToJson(jargs["hitShaderBindingTableBuffer"], args.hitShaderBindingTableBuffer);
        jargs["hitShaderBindingOffset"] = args.hitShaderBindingOffset;
        jargs["hitShaderBindingStride"] = args.hitShaderBindingStride;
        HandleToJson(jargs["callableShaderBindingTableBuffer"], args.callableShaderBindingTableBuffer);
        jargs["callableShaderBindingOffset"] = args.callableShaderBindingOffset;
        jargs["callableShaderBindingStride"] = args.callableShaderBindingStride;
        jargs["width"] = args.width;
        jargs["height"] = args.height;
        jargs["depth"] = args.depth;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    args::CreateRayTracingPipelinesNV&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRayTracingPipelinesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelines"], &args.pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesKHR&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupHandlesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["firstGroup"] = args.firstGroup;
        jargs["groupCount"] = args.groupCount;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesNV&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupHandlesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["firstGroup"] = args.firstGroup;
        jargs["groupCount"] = args.groupCount;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureHandleNV&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureHandleNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["accelerationStructure"], args.accelerationStructure);
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteAccelerationStructuresPropertiesNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["accelerationStructureCount"] = args.accelerationStructureCount;
        HandleToJson(jargs["pAccelerationStructures"], &args.pAccelerationStructures);
        jargs["queryType"] = args.queryType;
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    args::CompileDeferredNV&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCompileDeferredNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["shader"] = args.shader;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryHostPointerPropertiesEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryHostPointerPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["handleType"] = args.handleType;
        jargs["pHostPointer"] = args.pHostPointer;
        FieldToJson(jargs["pMemoryHostPointerProperties"], &args.pMemoryHostPointerProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteBufferMarkerAMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineStage"] = args.pipelineStage;
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["dstOffset"] = args.dstOffset;
        jargs["marker"] = args.marker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteBufferMarker2AMD");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["stage"] = VkPipelineStageFlags2_t{args.stage};
        HandleToJson(jargs["dstBuffer"], args.dstBuffer);
        jargs["dstOffset"] = args.dstOffset;
        jargs["marker"] = args.marker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pTimeDomainCount"], &args.pTimeDomainCount);
        FieldToJson(jargs["pTimeDomains"], &args.pTimeDomains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetCalibratedTimestampsEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["timestampCount"] = args.timestampCount;
        FieldToJson(jargs["pTimestampInfos"], &args.pTimestampInfos);
        FieldToJson(jargs["pTimestamps"], &args.pTimestamps);
        FieldToJson(jargs["pMaxDeviation"], &args.pMaxDeviation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksNV&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["taskCount"] = args.taskCount;
        jargs["firstTask"] = args.firstTask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["drawCount"] = args.drawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCountNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorEnableNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExclusiveScissorEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstExclusiveScissor"] = args.firstExclusiveScissor;
        jargs["exclusiveScissorCount"] = args.exclusiveScissorCount;
        Bool32ToJson(jargs["pExclusiveScissorEnables"], &args.pExclusiveScissorEnables);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorNV&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExclusiveScissorNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstExclusiveScissor"] = args.firstExclusiveScissor;
        jargs["exclusiveScissorCount"] = args.exclusiveScissorCount;
        FieldToJson(jargs["pExclusiveScissors"], &args.pExclusiveScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCheckpointNV&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCheckpointNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pCheckpointMarker"] = args.pCheckpointMarker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointDataNV&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointDataNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pCheckpointDataCount"], &args.pCheckpointDataCount);
        FieldToJson(jargs["pCheckpointData"], &args.pCheckpointData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointData2NV&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointData2NV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pCheckpointDataCount"], &args.pCheckpointDataCount);
        FieldToJson(jargs["pCheckpointData"], &args.pCheckpointData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetSwapchainPresentTimingQueueSizeEXT(
    const ApiCallInfo&                          call_info,
    args::SetSwapchainPresentTimingQueueSizeEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetSwapchainPresentTimingQueueSizeEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        jargs["size"] = args.size;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainTimingPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimingPropertiesEXT&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainTimingPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pSwapchainTimingProperties"], &args.pSwapchainTimingProperties);
        FieldToJson(jargs["pSwapchainTimingPropertiesCounter"], &args.pSwapchainTimingPropertiesCounter);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainTimeDomainPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimeDomainPropertiesEXT&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainTimeDomainPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pSwapchainTimeDomainProperties"], &args.pSwapchainTimeDomainProperties);
        FieldToJson(jargs["pTimeDomainsCounter"], &args.pTimeDomainsCounter);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPastPresentationTimingEXT(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPastPresentationTimingEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pPastPresentationTimingInfo"], &args.pPastPresentationTimingInfo);
        FieldToJson(jargs["pPastPresentationTimingProperties"], &args.pPastPresentationTimingProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::InitializePerformanceApiINTEL&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInitializePerformanceApiINTEL");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInitializeInfo"], &args.pInitializeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::UninitializePerformanceApiINTEL&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUninitializePerformanceApiINTEL");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceMarkerINTEL&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceMarkerINTEL");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pMarkerInfo"], &args.pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceStreamMarkerINTEL&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceStreamMarkerINTEL");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pMarkerInfo"], &args.pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceOverrideINTEL&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceOverrideINTEL");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pOverrideInfo"], &args.pOverrideInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::AcquirePerformanceConfigurationINTEL& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquirePerformanceConfigurationINTEL");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pAcquireInfo"], &args.pAcquireInfo);
        HandleToJson(jargs["pConfiguration"], &args.pConfiguration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::ReleasePerformanceConfigurationINTEL& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleasePerformanceConfigurationINTEL");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["configuration"], args.configuration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerformanceConfigurationINTEL& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerformanceConfigurationINTEL");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        HandleToJson(jargs["configuration"], args.configuration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    args::GetPerformanceParameterINTEL&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPerformanceParameterINTEL");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["parameter"] = args.parameter;
        FieldToJson(jargs["pValue"], &args.pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    args::SetLocalDimmingAMD&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLocalDimmingAMD");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapChain"], args.swapChain);
        Bool32ToJson(jargs["localDimmingEnable"], args.localDimmingEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::CreateImagePipeSurfaceFUCHSIA&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImagePipeSurfaceFUCHSIA");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMetalSurfaceEXT&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMetalSurfaceEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressEXT");
    FieldToJsonAsHex(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolPropertiesEXT&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceToolPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pToolCount"], &args.pToolCount);
        FieldToJson(jargs["pToolProperties"], &args.pToolProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pCombinationCount"], &args.pCombinationCount);
        FieldToJson(jargs["pCombinations"], &args.pCombinations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModes2EXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pSurfaceInfo"], &args.pSurfaceInfo);
        FieldToJson(jargs["pPresentModeCount"], &args.pPresentModeCount);
        FieldToJson(jargs["pPresentModes"], &args.pPresentModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireFullScreenExclusiveModeEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireFullScreenExclusiveModeEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseFullScreenExclusiveModeEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseFullScreenExclusiveModeEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModes2EXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupSurfacePresentModes2EXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pSurfaceInfo"], &args.pSurfaceInfo);
        FieldToJson(jargs["pModes"], &args.pModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateHeadlessSurfaceEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateHeadlessSurfaceEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["lineStippleFactor"] = args.lineStippleFactor;
        jargs["lineStipplePattern"] = args.lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPoolEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetQueryPoolEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
        jargs["queryCount"] = args.queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullModeEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["cullMode"] = VkCullModeFlags_t{args.cullMode};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFaceEXT&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFaceEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["frontFace"] = args.frontFace;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopologyEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopologyEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["primitiveTopology"] = args.primitiveTopology;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCountEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCountEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pViewports"], &args.pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCountEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCountEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["scissorCount"] = args.scissorCount;
        FieldToJson(jargs["pScissors"], &args.pScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstBinding"] = args.firstBinding;
        jargs["bindingCount"] = args.bindingCount;
        HandleToJson(jargs["pBuffers"], &args.pBuffers);
        FieldToJson(jargs["pOffsets"], &args.pOffsets);
        FieldToJson(jargs["pSizes"], &args.pSizes);
        FieldToJson(jargs["pStrides"], &args.pStrides);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnableEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthTestEnable"], args.depthTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnableEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthWriteEnable"], args.depthWriteEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOpEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOpEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["depthCompareOp"] = args.depthCompareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnableEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthBoundsTestEnable"], args.depthBoundsTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnableEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["stencilTestEnable"], args.stencilTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOpEXT&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilOpEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["faceMask"] = VkStencilFaceFlags_t{args.faceMask};
        jargs["failOp"] = args.failOp;
        jargs["passOp"] = args.passOp;
        jargs["depthFailOp"] = args.depthFailOp;
        jargs["compareOp"] = args.compareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImageEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImageEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyMemoryToImageInfo"], &args.pCopyMemoryToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemoryEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemoryEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyImageToMemoryInfo"], &args.pCopyImageToMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImageEXT&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImageEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCopyImageToImageInfo"], &args.pCopyImageToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayoutEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTransitionImageLayoutEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["transitionCount"] = args.transitionCount;
        FieldToJson(jargs["pTransitions"], &args.pTransitions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2EXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2EXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["image"], args.image);
        FieldToJson(jargs["pSubresource"], &args.pSubresource);
        FieldToJson(jargs["pLayout"], &args.pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pReleaseInfo"], &args.pReleaseInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pGeneratedCommandsInfo"], &args.pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["isPreprocessed"], args.isPreprocessed);
        FieldToJson(jargs["pGeneratedCommandsInfo"], &args.pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipelineShaderGroupNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["groupIndex"] = args.groupIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectCommandsLayoutNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pIndirectCommandsLayout"], &args.pIndirectCommandsLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectCommandsLayoutNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["indirectCommandsLayout"], args.indirectCommandsLayout);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias2EXT&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDepthBiasInfo"], &args.pDepthBiasInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireDrmDisplayEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireDrmDisplayEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["drmFd"] = args.drmFd;
        HandleToJson(jargs["display"], args.display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetDrmDisplayEXT&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDrmDisplayEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["drmFd"] = args.drmFd;
        jargs["connectorId"] = args.connectorId;
        HandleToJson(jargs["display"], &args.display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlotEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePrivateDataSlotEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPrivateDataSlot"], &args.pPrivateDataSlot);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlotEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlotEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::SetPrivateDataEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetPrivateDataEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["objectType"] = args.objectType;
        HandleToJson(jargs["objectHandle"], args.objectHandle);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        jargs["data"] = args.data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetPrivateDataEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPrivateDataEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["objectType"] = args.objectType;
        HandleToJson(jargs["objectHandle"], args.objectHandle);
        HandleToJson(jargs["privateDataSlot"], args.privateDataSlot);
        FieldToJson(jargs["pData"], &args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerfHintQCOM(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerfHintQCOM&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerfHintQCOM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pPerfHintInfo"], &args.pPerfHintInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchTileQCOM&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchTileQCOM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDispatchTileInfo"], &args.pDispatchTileInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBeginPerTileExecutionQCOM&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginPerTileExecutionQCOM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPerTileBeginInfo"], &args.pPerTileBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdEndPerTileExecutionQCOM&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndPerTileExecutionQCOM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pPerTileEndInfo"], &args.pPerTileEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSizeEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSizeEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSizeEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["layout"], args.layout);
        FieldToJson(jargs["pLayoutSizeInBytes"], &args.pLayoutSizeInBytes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutBindingOffsetEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutBindingOffsetEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["layout"], args.layout);
        jargs["binding"] = args.binding;
        FieldToJson(jargs["pOffset"], &args.pOffset);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorEXT&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pDescriptorInfo"], &args.pDescriptorInfo);
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pDescriptor"], args.pDescriptor);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBuffersEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["bufferCount"] = args.bufferCount;
        FieldToJson(jargs["pBindingInfos"], &args.pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsetsEXT&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDescriptorBufferOffsetsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["layout"], args.layout);
        jargs["firstSet"] = args.firstSet;
        jargs["setCount"] = args.setCount;
        FieldToJson(jargs["pBufferIndices"], &args.pBufferIndices);
        FieldToJson(jargs["pOffsets"], &args.pOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["layout"], args.layout);
        jargs["set"] = args.set;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateEnumNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateEnumNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["shadingRate"] = args.shadingRate;
        FieldToJson(jargs["combinerOps"], args.combinerOps);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultInfoEXT&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultInfoEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pFaultCounts"], &args.pFaultCounts);
        FieldToJson(jargs["pFaultInfo"], &args.pFaultInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::AcquireWinrtDisplayNV&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireWinrtDisplayNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        HandleToJson(jargs["display"], args.display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::GetWinrtDisplayNV&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetWinrtDisplayNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["deviceRelativeId"] = args.deviceRelativeId;
        HandleToJson(jargs["pDisplay"], &args.pDisplay);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDirectFBSurfaceEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDirectFBSurfaceEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["dfb"] = args.dfb;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetVertexInputEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetVertexInputEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["vertexBindingDescriptionCount"] = args.vertexBindingDescriptionCount;
        FieldToJson(jargs["pVertexBindingDescriptions"], &args.pVertexBindingDescriptions);
        jargs["vertexAttributeDescriptionCount"] = args.vertexAttributeDescriptionCount;
        FieldToJson(jargs["pVertexAttributeDescriptions"], &args.pVertexAttributeDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandleFUCHSIA&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryZirconHandleFUCHSIA");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetZirconHandleInfo"], &args.pGetZirconHandleInfo);
        FieldToJson(jargs["pZirconHandle"], &args.pZirconHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandlePropertiesFUCHSIA& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["handleType"] = args.handleType;
        jargs["zirconHandle"] = args.zirconHandle;
        FieldToJson(jargs["pMemoryZirconHandleProperties"], &args.pMemoryZirconHandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreZirconHandleFUCHSIA&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreZirconHandleFUCHSIA");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pImportSemaphoreZirconHandleInfo"], &args.pImportSemaphoreZirconHandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreZirconHandleFUCHSIA&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreZirconHandleFUCHSIA");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetZirconHandleInfo"], &args.pGetZirconHandleInfo);
        FieldToJson(jargs["pZirconHandle"], &args.pZirconHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindInvocationMaskHUAWEI");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["imageView"], args.imageView);
        jargs["imageLayout"] = args.imageLayout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryRemoteAddressNV&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryRemoteAddressNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pMemoryGetRemoteAddressInfo"], &args.pMemoryGetRemoteAddressInfo);
        FieldToJson(jargs["pAddress"], args.pAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPatchControlPointsEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPatchControlPointsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["patchControlPoints"] = args.patchControlPoints;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnableEXT&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["rasterizerDiscardEnable"], args.rasterizerDiscardEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnableEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthBiasEnable"], args.depthBiasEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEXT&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["logicOp"] = args.logicOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnableEXT&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["primitiveRestartEnable"], args.primitiveRestartEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    args::CreateScreenSurfaceQNX&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateScreenSurfaceQNX");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["instance"], args.instance);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSurface"], &args.pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceScreenPresentationSupportQNX& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
    Bool32ToJson(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        jargs["window"] = args.window;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteEnableEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["attachmentCount"] = args.attachmentCount;
        Bool32ToJson(jargs["pColorWriteEnables"], &args.pColorWriteEnables);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiEXT&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMultiEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["drawCount"] = args.drawCount;
        FieldToJson(jargs["pVertexInfo"], &args.pVertexInfo);
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstInstance"] = args.firstInstance;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiIndexedEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMultiIndexedEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["drawCount"] = args.drawCount;
        FieldToJson(jargs["pIndexInfo"], &args.pIndexInfo);
        jargs["instanceCount"] = args.instanceCount;
        jargs["firstInstance"] = args.firstInstance;
        jargs["stride"] = args.stride;
        FieldToJson(jargs["pVertexOffset"], &args.pVertexOffset);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMicromapEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMicromapEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pMicromap"], &args.pMicromap);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyMicromapEXT&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyMicromapEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["micromap"], args.micromap);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBuildMicromapsEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildMicromapsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["infoCount"] = args.infoCount;
        FieldToJson(jargs["pInfos"], &args.pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::BuildMicromapsEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBuildMicromapsEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        jargs["infoCount"] = args.infoCount;
        FieldToJson(jargs["pInfos"], &args.pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapEXT&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMicromapEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapToMemoryEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMicromapToMemoryEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToMicromapEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToMicromapEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::WriteMicromapsPropertiesEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWriteMicromapsPropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["micromapCount"] = args.micromapCount;
        HandleToJson(jargs["pMicromaps"], &args.pMicromaps);
        jargs["queryType"] = args.queryType;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapEXT&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapToMemoryEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapToMemoryEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToMicromapEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToMicromapEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMicromapsPropertiesEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteMicromapsPropertiesEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["micromapCount"] = args.micromapCount;
        HandleToJson(jargs["pMicromaps"], &args.pMicromaps);
        jargs["queryType"] = args.queryType;
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMicromapCompatibilityEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMicromapCompatibilityEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pVersionInfo"], &args.pVersionInfo);
        FieldToJson(jargs["pCompatibility"], &args.pCompatibility);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMicromapBuildSizesEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMicromapBuildSizesEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["buildType"] = args.buildType;
        FieldToJson(jargs["pBuildInfo"], &args.pBuildInfo);
        FieldToJson(jargs["pSizeInfo"], &args.pSizeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterHUAWEI&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterHUAWEI");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["groupCountX"] = args.groupCountX;
        jargs["groupCountY"] = args.groupCountY;
        jargs["groupCountZ"] = args.groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterIndirectHUAWEI");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    args::SetDeviceMemoryPriorityEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDeviceMemoryPriorityEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["memory"], args.memory);
        FieldToJson(jargs["priority"], args.priority);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    args::CmdSetDispatchParametersARM&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDispatchParametersARM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDispatchParameters"], &args.pDispatchParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutHostMappingInfoVALVE& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pBindingReference"], &args.pBindingReference);
        FieldToJson(jargs["pHostMapping"], &args.pHostMapping);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetHostMappingVALVE&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetHostMappingVALVE");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["descriptorSet"], args.descriptorSet);
        FieldToJsonAsHex(jargs["ppData"], args.ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectMemoryRequirementsNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectMemoryRequirementsNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdatePipelineIndirectBufferNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineBindPoint"] = args.pipelineBindPoint;
        HandleToJson(jargs["pipeline"], args.pipeline);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectDeviceAddressNV&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectDeviceAddressNV");
    FieldToJsonAsHex(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampEnableEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthClampEnable"], args.depthClampEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPolygonModeEXT&                 args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPolygonModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["polygonMode"] = args.polygonMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationSamplesEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationSamplesEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["rasterizationSamples"] = args.rasterizationSamples;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleMaskEXT&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleMaskEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["samples"] = args.samples;
        FieldToJson(jargs["pSampleMask"], &args.pSampleMask);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToCoverageEnableEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToCoverageEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["alphaToCoverageEnable"], args.alphaToCoverageEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToOneEnableEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToOneEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["alphaToOneEnable"], args.alphaToOneEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEnableEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["logicOpEnable"], args.logicOpEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEnableEXT&            args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstAttachment"] = args.firstAttachment;
        jargs["attachmentCount"] = args.attachmentCount;
        Bool32ToJson(jargs["pColorBlendEnables"], &args.pColorBlendEnables);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEquationEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendEquationEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstAttachment"] = args.firstAttachment;
        jargs["attachmentCount"] = args.attachmentCount;
        FieldToJson(jargs["pColorBlendEquations"], &args.pColorBlendEquations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteMaskEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteMaskEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstAttachment"] = args.firstAttachment;
        jargs["attachmentCount"] = args.attachmentCount;
        FieldToJson(jargs["pColorWriteMasks"], &args.pColorWriteMasks);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetTessellationDomainOriginEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetTessellationDomainOriginEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["domainOrigin"] = args.domainOrigin;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationStreamEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationStreamEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["rasterizationStream"] = args.rasterizationStream;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetConservativeRasterizationModeEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetConservativeRasterizationModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["conservativeRasterizationMode"] = args.conservativeRasterizationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetExtraPrimitiveOverestimationSizeEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["extraPrimitiveOverestimationSize"], args.extraPrimitiveOverestimationSize);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipEnableEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["depthClipEnable"], args.depthClipEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEnableEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["sampleLocationsEnable"], args.sampleLocationsEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendAdvancedEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendAdvancedEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstAttachment"] = args.firstAttachment;
        jargs["attachmentCount"] = args.attachmentCount;
        FieldToJson(jargs["pColorBlendAdvanced"], &args.pColorBlendAdvanced);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetProvokingVertexModeEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetProvokingVertexModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["provokingVertexMode"] = args.provokingVertexMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineRasterizationModeEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineRasterizationModeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["lineRasterizationMode"] = args.lineRasterizationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEnableEXT&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["stippledLineEnable"], args.stippledLineEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipNegativeOneToOneEXT&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["negativeOneToOne"], args.negativeOneToOne);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingEnableNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["viewportWScalingEnable"], args.viewportWScalingEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportSwizzleNV&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportSwizzleNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["firstViewport"] = args.firstViewport;
        jargs["viewportCount"] = args.viewportCount;
        FieldToJson(jargs["pViewportSwizzles"], &args.pViewportSwizzles);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorEnableNV&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["coverageToColorEnable"], args.coverageToColorEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorLocationNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorLocationNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["coverageToColorLocation"] = args.coverageToColorLocation;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationModeNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationModeNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["coverageModulationMode"] = args.coverageModulationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableEnableNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["coverageModulationTableEnable"], args.coverageModulationTableEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableNV&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["coverageModulationTableCount"] = args.coverageModulationTableCount;
        FieldToJson(jargs["pCoverageModulationTable"], &args.pCoverageModulationTable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetShadingRateImageEnableNV&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetShadingRateImageEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["shadingRateImageEnable"], args.shadingRateImageEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetRepresentativeFragmentTestEnableNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["representativeFragmentTestEnable"], args.representativeFragmentTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageReductionModeNV&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageReductionModeNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["coverageReductionMode"] = args.coverageReductionMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateTensorARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkTensorCreateInfoARM>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkTensorARM>*          pTensor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateTensorARM");
    jdata[format::kNameReturn] = returnValue;
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pTensor"], pTensor);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyTensorARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            tensor,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyTensorARM");
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        HandleToJson(args["tensor"], tensor);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateTensorViewARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkTensorViewCreateInfoARM>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkTensorViewARM>*      pView)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateTensorViewARM");
    jdata[format::kNameReturn] = returnValue;
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pView"], pView);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyTensorViewARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            tensorView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyTensorViewARM");
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        HandleToJson(args["tensorView"], tensorView);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkTensorMemoryRequirementsInfoARM>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetTensorMemoryRequirementsARM");
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindTensorMemoryARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindTensorMemoryInfoARM>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindTensorMemoryARM");
    jdata[format::kNameReturn] = returnValue;
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceTensorMemoryRequirementsARM>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceTensorMemoryRequirementsARM");
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyTensorInfoARM>* pCopyTensorInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyTensorARM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyTensorInfo"], pCopyTensorInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalTensorInfoARM>* pExternalTensorInfo,
    StructPointerDecoder<Decoded_VkExternalTensorPropertiesARM>* pExternalTensorProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalTensorPropertiesARM");
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalTensorInfo"], pExternalTensorInfo);
        FieldToJson(args["pExternalTensorProperties"], pExternalTensorProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleIdentifierEXT&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleIdentifierEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["shaderModule"], args.shaderModule);
        FieldToJson(jargs["pIdentifier"], &args.pIdentifier);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleCreateInfoIdentifierEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pIdentifier"], &args.pIdentifier);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pOpticalFlowImageFormatInfo"], &args.pOpticalFlowImageFormatInfo);
        FieldToJson(jargs["pFormatCount"], &args.pFormatCount);
        FieldToJson(jargs["pImageFormatProperties"], &args.pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::CreateOpticalFlowSessionNV&           args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateOpticalFlowSessionNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSession"], &args.pSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::DestroyOpticalFlowSessionNV&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyOpticalFlowSessionNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["session"], args.session);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    args::BindOpticalFlowSessionImageNV&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindOpticalFlowSessionImageNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["session"], args.session);
        jargs["bindingPoint"] = args.bindingPoint;
        HandleToJson(jargs["view"], args.view);
        jargs["layout"] = args.layout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    args::CmdOpticalFlowExecuteNV&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdOpticalFlowExecuteNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["session"], args.session);
        FieldToJson(jargs["pExecuteInfo"], &args.pExecuteInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAntiLagUpdateAMD(
    const ApiCallInfo&                          call_info,
    args::AntiLagUpdateAMD&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAntiLagUpdateAMD");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pData"], &args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CreateShadersEXT&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateShadersEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pShaders"], &args.pShaders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderEXT&                     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["shader"], args.shader);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderBinaryDataEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderBinaryDataEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["shader"], args.shader);
        FieldToJson(jargs["pDataSize"], &args.pDataSize);
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadersEXT&                    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadersEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["stageCount"] = args.stageCount;
        FieldToJson(jargs["pStages"], &args.pStages);
        HandleToJson(jargs["pShaders"], &args.pShaders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampRangeEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampRangeEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["depthClampMode"] = args.depthClampMode;
        FieldToJson(jargs["pDepthClampRange"], &args.pDepthClampRange);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetFramebufferTilePropertiesQCOM&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFramebufferTilePropertiesQCOM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["framebuffer"], args.framebuffer);
        FieldToJson(jargs["pPropertiesCount"], &args.pPropertiesCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetDynamicRenderingTilePropertiesQCOM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDynamicRenderingTilePropertiesQCOM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pRenderingInfo"], &args.pRenderingInfo);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::ConvertCooperativeVectorMatrixNV&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkConvertCooperativeVectorMatrixNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::CmdConvertCooperativeVectorMatrixNV&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdConvertCooperativeVectorMatrixNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["infoCount"] = args.infoCount;
        FieldToJson(jargs["pInfos"], &args.pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencySleepModeNV&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLatencySleepModeNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pSleepModeInfo"], &args.pSleepModeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    args::LatencySleepNV&                       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkLatencySleepNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pSleepInfo"], &args.pSleepInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencyMarkerNV&                   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLatencyMarkerNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pLatencyMarkerInfo"], &args.pLatencyMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    args::GetLatencyTimingsNV&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetLatencyTimingsNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["swapchain"], args.swapchain);
        FieldToJson(jargs["pLatencyMarkerInfo"], &args.pLatencyMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    args::QueueNotifyOutOfBandNV&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueNotifyOutOfBandNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["queue"], args.queue);
        FieldToJson(jargs["pQueueTypeInfo"], &args.pQueueTypeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelinesARM&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDataGraphPipelinesARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelines"], &args.pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelineSessionARM&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDataGraphPipelineSessionARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pSession"], &args.pSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionBindPointRequirementsARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineSessionBindPointRequirementsARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pBindPointRequirementCount"], &args.pBindPointRequirementCount);
        FieldToJson(jargs["pBindPointRequirements"], &args.pBindPointRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionMemoryRequirementsARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineSessionMemoryRequirementsARM");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindDataGraphPipelineSessionMemoryARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindDataGraphPipelineSessionMemoryARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["bindInfoCount"] = args.bindInfoCount;
        FieldToJson(jargs["pBindInfos"], &args.pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::DestroyDataGraphPipelineSessionARM&   args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDataGraphPipelineSessionARM");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["session"], args.session);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchDataGraphARM&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchDataGraphARM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["session"], args.session);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineAvailablePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineAvailablePropertiesARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineAvailablePropertiesARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pPipelineInfo"], &args.pPipelineInfo);
        FieldToJson(jargs["pPropertiesCount"], &args.pPropertiesCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelinePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelinePropertiesARM&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelinePropertiesARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pPipelineInfo"], &args.pPipelineInfo);
        jargs["propertiesCount"] = args.propertiesCount;
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        FieldToJson(jargs["pQueueFamilyDataGraphPropertyCount"], &args.pQueueFamilyDataGraphPropertyCount);
        FieldToJson(jargs["pQueueFamilyDataGraphProperties"], &args.pQueueFamilyDataGraphProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pQueueFamilyDataGraphProcessingEngineInfo"], &args.pQueueFamilyDataGraphProcessingEngineInfo);
        FieldToJson(jargs["pQueueFamilyDataGraphProcessingEngineProperties"], &args.pQueueFamilyDataGraphProcessingEngineProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAttachmentFeedbackLoopEnableEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["aspectMask"] = VkImageAspectFlags_t{args.aspectMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBindTileMemoryQCOM&                args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTileMemoryQCOM");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pTileMemoryBindInfo"], &args.pTileMemoryBindInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryEXT&               args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecompressMemoryEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pDecompressMemoryInfoEXT"], &args.pDecompressMemoryInfoEXT);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryIndirectCountEXT&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecompressMemoryIndirectCountEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["decompressionMethod"] = VkMemoryDecompressionMethodFlagsEXT_t{args.decompressionMethod};
        FieldToJsonAsHex(jargs["indirectCommandsAddress"], args.indirectCommandsAddress);
        FieldToJsonAsHex(jargs["indirectCommandsCountAddress"], args.indirectCommandsCountAddress);
        jargs["maxDecompressionCount"] = args.maxDecompressionCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
    const ApiCallInfo&                          call_info,
    args::GetPartitionedAccelerationStructuresBuildSizesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPartitionedAccelerationStructuresBuildSizesNV");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pSizeInfo"], &args.pSizeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildPartitionedAccelerationStructuresNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildPartitionedAccelerationStructuresNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBuildInfo"], &args.pBuildInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGeneratedCommandsMemoryRequirementsEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
        FieldToJson(jargs["pMemoryRequirements"], &args.pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pGeneratedCommandsInfo"], &args.pGeneratedCommandsInfo);
        HandleToJson(jargs["stateCommandBuffer"], args.stateCommandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        Bool32ToJson(jargs["isPreprocessed"], args.isPreprocessed);
        FieldToJson(jargs["pGeneratedCommandsInfo"], &args.pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutEXT&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectCommandsLayoutEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pIndirectCommandsLayout"], &args.pIndirectCommandsLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutEXT&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectCommandsLayoutEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["indirectCommandsLayout"], args.indirectCommandsLayout);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectExecutionSetEXT&        args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectExecutionSetEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pIndirectExecutionSet"], &args.pIndirectExecutionSet);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectExecutionSetEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectExecutionSetEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["indirectExecutionSet"], args.indirectExecutionSet);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateIndirectExecutionSetPipelineEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetPipelineEXT& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateIndirectExecutionSetPipelineEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["indirectExecutionSet"], args.indirectExecutionSet);
        jargs["executionSetWriteCount"] = args.executionSetWriteCount;
        FieldToJson(jargs["pExecutionSetWrites"], &args.pExecutionSetWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateIndirectExecutionSetShaderEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetShaderEXT&  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateIndirectExecutionSetShaderEXT");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["indirectExecutionSet"], args.indirectExecutionSet);
        jargs["executionSetWriteCount"] = args.executionSetWriteCount;
        FieldToJson(jargs["pExecutionSetWrites"], &args.pExecutionSetWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        FieldToJson(jargs["pPropertyCount"], &args.pPropertyCount);
        FieldToJson(jargs["pProperties"], &args.pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryMetalHandleEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandleEXT&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryMetalHandleEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pGetMetalHandleInfo"], &args.pGetMetalHandleInfo);
        FieldToJson(jargs["pHandle"], args.pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryMetalHandlePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandlePropertiesEXT&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryMetalHandlePropertiesEXT");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["handleType"] = args.handleType;
        jargs["pHandle"] = args.pHandle;
        FieldToJson(jargs["pMemoryMetalHandleProperties"], &args.pMemoryMetalHandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["physicalDevice"], args.physicalDevice);
        jargs["queueFamilyIndex"] = args.queueFamilyIndex;
        FieldToJson(jargs["pCounterCount"], &args.pCounterCount);
        FieldToJson(jargs["pCounters"], &args.pCounters);
        FieldToJson(jargs["pCounterDescriptions"], &args.pCounterDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2EXT&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering2EXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRenderingEndInfo"], &args.pRenderingEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginCustomResolveEXT&             args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginCustomResolveEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pBeginCustomResolveInfo"], &args.pBeginCustomResolveInfo);
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
    jdata[format::kNameReturn] = returnValue;
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pQueueFamilyDataGraphProperties"], pQueueFamilyDataGraphProperties);
        FieldToJson(args["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo);
        FieldToJson(args["pFormatCount"], pFormatCount);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
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
    jdata[format::kNameReturn] = returnValue;
    auto& args = jdata[format::kNameArgs];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pQueueFamilyDataGraphProperties"], pQueueFamilyDataGraphProperties);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetComputeOccupancyPriorityNV&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetComputeOccupancyPriorityNV");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pParameters"], &args.pParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartIndexEXT&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartIndexEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["primitiveRestartIndex"] = args.primitiveRestartIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureKHR&       args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructureKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pCreateInfo"], &args.pCreateInfo);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pAccelerationStructure"], &args.pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["accelerationStructure"], args.accelerationStructure);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildAccelerationStructuresKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["infoCount"] = args.infoCount;
        FieldToJson(jargs["pInfos"], &args.pInfos);
        FieldToJson(jargs["ppBuildRangeInfos"], &args.ppBuildRangeInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CopyAccelerationStructureToMemoryKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyAccelerationStructureToMemoryKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToAccelerationStructureKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToAccelerationStructureKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::WriteAccelerationStructuresPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWriteAccelerationStructuresPropertiesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["accelerationStructureCount"] = args.accelerationStructureCount;
        HandleToJson(jargs["pAccelerationStructures"], &args.pAccelerationStructures);
        jargs["queryType"] = args.queryType;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureDeviceAddressKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureDeviceAddressKHR");
    FieldToJsonAsHex(jdata[format::kNameReturn], args.result);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pInfo"], &args.pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteAccelerationStructuresPropertiesKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["accelerationStructureCount"] = args.accelerationStructureCount;
        HandleToJson(jargs["pAccelerationStructures"], &args.pAccelerationStructures);
        jargs["queryType"] = args.queryType;
        HandleToJson(jargs["queryPool"], args.queryPool);
        jargs["firstQuery"] = args.firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceAccelerationStructureCompatibilityKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        FieldToJson(jargs["pVersionInfo"], &args.pVersionInfo);
        FieldToJson(jargs["pCompatibility"], &args.pCompatibility);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureBuildSizesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureBuildSizesKHR");
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        jargs["buildType"] = args.buildType;
        FieldToJson(jargs["pBuildInfo"], &args.pBuildInfo);
        FieldToJson(jargs["pMaxPrimitiveCounts"], &args.pMaxPrimitiveCounts);
        FieldToJson(jargs["pSizeInfo"], &args.pSizeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysKHR&                      args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRaygenShaderBindingTable"], &args.pRaygenShaderBindingTable);
        FieldToJson(jargs["pMissShaderBindingTable"], &args.pMissShaderBindingTable);
        FieldToJson(jargs["pHitShaderBindingTable"], &args.pHitShaderBindingTable);
        FieldToJson(jargs["pCallableShaderBindingTable"], &args.pCallableShaderBindingTable);
        jargs["width"] = args.width;
        jargs["height"] = args.height;
        jargs["depth"] = args.depth;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                          call_info,
    args::CreateRayTracingPipelinesKHR&         args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRayTracingPipelinesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["deferredOperation"], args.deferredOperation);
        HandleToJson(jargs["pipelineCache"], args.pipelineCache);
        jargs["createInfoCount"] = args.createInfoCount;
        FieldToJson(jargs["pCreateInfos"], &args.pCreateInfos);
        FieldToJson(jargs["pAllocator"], &args.pAllocator);
        HandleToJson(jargs["pPipelines"], &args.pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["firstGroup"] = args.firstGroup;
        jargs["groupCount"] = args.groupCount;
        jargs["dataSize"] = args.dataSize;
        FieldToJson(jargs["pData"], args.pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirectKHR&              args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirectKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        FieldToJson(jargs["pRaygenShaderBindingTable"], &args.pRaygenShaderBindingTable);
        FieldToJson(jargs["pMissShaderBindingTable"], &args.pMissShaderBindingTable);
        FieldToJson(jargs["pHitShaderBindingTable"], &args.pHitShaderBindingTable);
        FieldToJson(jargs["pCallableShaderBindingTable"], &args.pCallableShaderBindingTable);
        FieldToJsonAsHex(jargs["indirectDeviceAddress"], args.indirectDeviceAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupStackSizeKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupStackSizeKHR");
    jdata[format::kNameReturn] = args.result;
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["device"], args.device);
        HandleToJson(jargs["pipeline"], args.pipeline);
        jargs["group"] = args.group;
        jargs["groupShader"] = args.groupShader;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRayTracingPipelineStackSizeKHR& args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["pipelineStackSize"] = args.pipelineStackSize;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksEXT&                  args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        jargs["groupCountX"] = args.groupCountX;
        jargs["groupCountY"] = args.groupCountY;
        jargs["groupCountZ"] = args.groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        jargs["drawCount"] = args.drawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCountEXT");
    jdata[format::kNameCommandIndex] = GetCommandBufferRecordIndex(args.commandBuffer);
    auto& jargs = jdata[format::kNameArgs];
        HandleToJson(jargs["commandBuffer"], args.commandBuffer);
        HandleToJson(jargs["buffer"], args.buffer);
        jargs["offset"] = args.offset;
        HandleToJson(jargs["countBuffer"], args.countBuffer);
        jargs["countBufferOffset"] = args.countBufferOffset;
        jargs["maxDrawCount"] = args.maxDrawCount;
        jargs["stride"] = args.stride;
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
