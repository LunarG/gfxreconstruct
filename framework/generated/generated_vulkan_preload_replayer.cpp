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

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "generated/generated_vulkan_preload_replayer.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "generated/generated_vulkan_preload_decoder.h"
#include "generated/generated_vulkan_preload_replayer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanPreloadReplayer::Replay_vkCreateInstance(Packet_vkCreateInstance* packet)
{
    vulkan_replay_consumer_->Process_vkCreateInstance(packet->call_info, packet->return_value, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pInstance));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyInstance(Packet_vkDestroyInstance* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyInstance(packet->call_info, packet->instance, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkEnumeratePhysicalDevices(Packet_vkEnumeratePhysicalDevices* packet)
{
    vulkan_replay_consumer_->Process_vkEnumeratePhysicalDevices(packet->call_info, packet->return_value, packet->instance, &(packet->pPhysicalDeviceCount), &(packet->pPhysicalDevices));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFeatures(Packet_vkGetPhysicalDeviceFeatures* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFeatures(packet->call_info, packet->physicalDevice, &(packet->pFeatures));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFormatProperties(Packet_vkGetPhysicalDeviceFormatProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFormatProperties(packet->call_info, packet->physicalDevice, packet->format, &(packet->pFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceImageFormatProperties(Packet_vkGetPhysicalDeviceImageFormatProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceImageFormatProperties(packet->call_info, packet->return_value, packet->physicalDevice, packet->format, packet->type, packet->tiling, packet->usage, packet->flags, &(packet->pImageFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceProperties(Packet_vkGetPhysicalDeviceProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceProperties(packet->call_info, packet->physicalDevice, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceQueueFamilyProperties(Packet_vkGetPhysicalDeviceQueueFamilyProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceQueueFamilyProperties(packet->call_info, packet->physicalDevice, &(packet->pQueueFamilyPropertyCount), &(packet->pQueueFamilyProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceMemoryProperties(Packet_vkGetPhysicalDeviceMemoryProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceMemoryProperties(packet->call_info, packet->physicalDevice, &(packet->pMemoryProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDevice(Packet_vkCreateDevice* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDevice(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pDevice));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDevice(Packet_vkDestroyDevice* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDevice(packet->call_info, packet->device, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceQueue(Packet_vkGetDeviceQueue* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceQueue(packet->call_info, packet->device, packet->queueFamilyIndex, packet->queueIndex, &(packet->pQueue));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueSubmit(Packet_vkQueueSubmit* packet)
{
    vulkan_replay_consumer_->Process_vkQueueSubmit(packet->call_info, packet->return_value, packet->queue, packet->submitCount, &(packet->pSubmits), packet->fence);

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueWaitIdle(Packet_vkQueueWaitIdle* packet)
{
    vulkan_replay_consumer_->Process_vkQueueWaitIdle(packet->call_info, packet->return_value, packet->queue);

    return;
}

void VulkanPreloadReplayer::Replay_vkDeviceWaitIdle(Packet_vkDeviceWaitIdle* packet)
{
    vulkan_replay_consumer_->Process_vkDeviceWaitIdle(packet->call_info, packet->return_value, packet->device);

    return;
}

void VulkanPreloadReplayer::Replay_vkAllocateMemory(Packet_vkAllocateMemory* packet)
{
    vulkan_replay_consumer_->Process_vkAllocateMemory(packet->call_info, packet->return_value, packet->device, &(packet->pAllocateInfo), &(packet->pAllocator), &(packet->pMemory));

    return;
}

void VulkanPreloadReplayer::Replay_vkFreeMemory(Packet_vkFreeMemory* packet)
{
    vulkan_replay_consumer_->Process_vkFreeMemory(packet->call_info, packet->device, packet->memory, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkMapMemory(Packet_vkMapMemory* packet)
{
    vulkan_replay_consumer_->Process_vkMapMemory(packet->call_info, packet->return_value, packet->device, packet->memory, packet->offset, packet->size, packet->flags, &(packet->ppData));

    return;
}

void VulkanPreloadReplayer::Replay_vkUnmapMemory(Packet_vkUnmapMemory* packet)
{
    vulkan_replay_consumer_->Process_vkUnmapMemory(packet->call_info, packet->device, packet->memory);

    return;
}

void VulkanPreloadReplayer::Replay_vkFlushMappedMemoryRanges(Packet_vkFlushMappedMemoryRanges* packet)
{
    vulkan_replay_consumer_->Process_vkFlushMappedMemoryRanges(packet->call_info, packet->return_value, packet->device, packet->memoryRangeCount, &(packet->pMemoryRanges));

    return;
}

void VulkanPreloadReplayer::Replay_vkInvalidateMappedMemoryRanges(Packet_vkInvalidateMappedMemoryRanges* packet)
{
    vulkan_replay_consumer_->Process_vkInvalidateMappedMemoryRanges(packet->call_info, packet->return_value, packet->device, packet->memoryRangeCount, &(packet->pMemoryRanges));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceMemoryCommitment(Packet_vkGetDeviceMemoryCommitment* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceMemoryCommitment(packet->call_info, packet->device, packet->memory, &(packet->pCommittedMemoryInBytes));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindBufferMemory(Packet_vkBindBufferMemory* packet)
{
    vulkan_replay_consumer_->Process_vkBindBufferMemory(packet->call_info, packet->return_value, packet->device, packet->buffer, packet->memory, packet->memoryOffset);

    return;
}

void VulkanPreloadReplayer::Replay_vkBindImageMemory(Packet_vkBindImageMemory* packet)
{
    vulkan_replay_consumer_->Process_vkBindImageMemory(packet->call_info, packet->return_value, packet->device, packet->image, packet->memory, packet->memoryOffset);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferMemoryRequirements(Packet_vkGetBufferMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferMemoryRequirements(packet->call_info, packet->device, packet->buffer, &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageMemoryRequirements(Packet_vkGetImageMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageMemoryRequirements(packet->call_info, packet->device, packet->image, &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSparseMemoryRequirements(Packet_vkGetImageSparseMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSparseMemoryRequirements(packet->call_info, packet->device, packet->image, &(packet->pSparseMemoryRequirementCount), &(packet->pSparseMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSparseImageFormatProperties(Packet_vkGetPhysicalDeviceSparseImageFormatProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSparseImageFormatProperties(packet->call_info, packet->physicalDevice, packet->format, packet->type, packet->samples, packet->usage, packet->tiling, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueBindSparse(Packet_vkQueueBindSparse* packet)
{
    vulkan_replay_consumer_->Process_vkQueueBindSparse(packet->call_info, packet->return_value, packet->queue, packet->bindInfoCount, &(packet->pBindInfo), packet->fence);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateFence(Packet_vkCreateFence* packet)
{
    vulkan_replay_consumer_->Process_vkCreateFence(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pFence));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyFence(Packet_vkDestroyFence* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyFence(packet->call_info, packet->device, packet->fence, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkResetFences(Packet_vkResetFences* packet)
{
    vulkan_replay_consumer_->Process_vkResetFences(packet->call_info, packet->return_value, packet->device, packet->fenceCount, &(packet->pFences));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetFenceStatus(Packet_vkGetFenceStatus* packet)
{
    vulkan_replay_consumer_->Process_vkGetFenceStatus(packet->call_info, packet->return_value, packet->device, packet->fence);

    return;
}

void VulkanPreloadReplayer::Replay_vkWaitForFences(Packet_vkWaitForFences* packet)
{
    vulkan_replay_consumer_->Process_vkWaitForFences(packet->call_info, packet->return_value, packet->device, packet->fenceCount, &(packet->pFences), packet->waitAll, packet->timeout);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSemaphore(Packet_vkCreateSemaphore* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSemaphore(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSemaphore));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySemaphore(Packet_vkDestroySemaphore* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySemaphore(packet->call_info, packet->device, packet->semaphore, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateEvent(Packet_vkCreateEvent* packet)
{
    vulkan_replay_consumer_->Process_vkCreateEvent(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pEvent));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyEvent(Packet_vkDestroyEvent* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyEvent(packet->call_info, packet->device, packet->event, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetEventStatus(Packet_vkGetEventStatus* packet)
{
    vulkan_replay_consumer_->Process_vkGetEventStatus(packet->call_info, packet->return_value, packet->device, packet->event);

    return;
}

void VulkanPreloadReplayer::Replay_vkSetEvent(Packet_vkSetEvent* packet)
{
    vulkan_replay_consumer_->Process_vkSetEvent(packet->call_info, packet->return_value, packet->device, packet->event);

    return;
}

void VulkanPreloadReplayer::Replay_vkResetEvent(Packet_vkResetEvent* packet)
{
    vulkan_replay_consumer_->Process_vkResetEvent(packet->call_info, packet->return_value, packet->device, packet->event);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateQueryPool(Packet_vkCreateQueryPool* packet)
{
    vulkan_replay_consumer_->Process_vkCreateQueryPool(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pQueryPool));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyQueryPool(Packet_vkDestroyQueryPool* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyQueryPool(packet->call_info, packet->device, packet->queryPool, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetQueryPoolResults(Packet_vkGetQueryPoolResults* packet)
{
    vulkan_replay_consumer_->Process_vkGetQueryPoolResults(packet->call_info, packet->return_value, packet->device, packet->queryPool, packet->firstQuery, packet->queryCount, packet->dataSize, &(packet->pData), packet->stride, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateBuffer(Packet_vkCreateBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCreateBuffer(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pBuffer));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyBuffer(Packet_vkDestroyBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyBuffer(packet->call_info, packet->device, packet->buffer, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateBufferView(Packet_vkCreateBufferView* packet)
{
    vulkan_replay_consumer_->Process_vkCreateBufferView(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pView));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyBufferView(Packet_vkDestroyBufferView* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyBufferView(packet->call_info, packet->device, packet->bufferView, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateImage(Packet_vkCreateImage* packet)
{
    vulkan_replay_consumer_->Process_vkCreateImage(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pImage));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyImage(Packet_vkDestroyImage* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyImage(packet->call_info, packet->device, packet->image, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSubresourceLayout(Packet_vkGetImageSubresourceLayout* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSubresourceLayout(packet->call_info, packet->device, packet->image, &(packet->pSubresource), &(packet->pLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateImageView(Packet_vkCreateImageView* packet)
{
    vulkan_replay_consumer_->Process_vkCreateImageView(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pView));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyImageView(Packet_vkDestroyImageView* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyImageView(packet->call_info, packet->device, packet->imageView, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateShaderModule(Packet_vkCreateShaderModule* packet)
{
    vulkan_replay_consumer_->Process_vkCreateShaderModule(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pShaderModule));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyShaderModule(Packet_vkDestroyShaderModule* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyShaderModule(packet->call_info, packet->device, packet->shaderModule, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreatePipelineCache(Packet_vkCreatePipelineCache* packet)
{
    vulkan_replay_consumer_->Process_vkCreatePipelineCache(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pPipelineCache));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyPipelineCache(Packet_vkDestroyPipelineCache* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyPipelineCache(packet->call_info, packet->device, packet->pipelineCache, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineCacheData(Packet_vkGetPipelineCacheData* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineCacheData(packet->call_info, packet->return_value, packet->device, packet->pipelineCache, &(packet->pDataSize), &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkMergePipelineCaches(Packet_vkMergePipelineCaches* packet)
{
    vulkan_replay_consumer_->Process_vkMergePipelineCaches(packet->call_info, packet->return_value, packet->device, packet->dstCache, packet->srcCacheCount, &(packet->pSrcCaches));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateGraphicsPipelines(Packet_vkCreateGraphicsPipelines* packet)
{
    vulkan_replay_consumer_->Process_vkCreateGraphicsPipelines(packet->call_info, packet->return_value, packet->device, packet->pipelineCache, packet->createInfoCount, &(packet->pCreateInfos), &(packet->pAllocator), &(packet->pPipelines));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateComputePipelines(Packet_vkCreateComputePipelines* packet)
{
    vulkan_replay_consumer_->Process_vkCreateComputePipelines(packet->call_info, packet->return_value, packet->device, packet->pipelineCache, packet->createInfoCount, &(packet->pCreateInfos), &(packet->pAllocator), &(packet->pPipelines));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyPipeline(Packet_vkDestroyPipeline* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyPipeline(packet->call_info, packet->device, packet->pipeline, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreatePipelineLayout(Packet_vkCreatePipelineLayout* packet)
{
    vulkan_replay_consumer_->Process_vkCreatePipelineLayout(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pPipelineLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyPipelineLayout(Packet_vkDestroyPipelineLayout* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyPipelineLayout(packet->call_info, packet->device, packet->pipelineLayout, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSampler(Packet_vkCreateSampler* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSampler(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSampler));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySampler(Packet_vkDestroySampler* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySampler(packet->call_info, packet->device, packet->sampler, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDescriptorSetLayout(Packet_vkCreateDescriptorSetLayout* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDescriptorSetLayout(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSetLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDescriptorSetLayout(Packet_vkDestroyDescriptorSetLayout* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDescriptorSetLayout(packet->call_info, packet->device, packet->descriptorSetLayout, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDescriptorPool(Packet_vkCreateDescriptorPool* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDescriptorPool(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pDescriptorPool));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDescriptorPool(Packet_vkDestroyDescriptorPool* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDescriptorPool(packet->call_info, packet->device, packet->descriptorPool, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkResetDescriptorPool(Packet_vkResetDescriptorPool* packet)
{
    vulkan_replay_consumer_->Process_vkResetDescriptorPool(packet->call_info, packet->return_value, packet->device, packet->descriptorPool, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkAllocateDescriptorSets(Packet_vkAllocateDescriptorSets* packet)
{
    vulkan_replay_consumer_->Process_vkAllocateDescriptorSets(packet->call_info, packet->return_value, packet->device, &(packet->pAllocateInfo), &(packet->pDescriptorSets));

    return;
}

void VulkanPreloadReplayer::Replay_vkFreeDescriptorSets(Packet_vkFreeDescriptorSets* packet)
{
    vulkan_replay_consumer_->Process_vkFreeDescriptorSets(packet->call_info, packet->return_value, packet->device, packet->descriptorPool, packet->descriptorSetCount, &(packet->pDescriptorSets));

    return;
}

void VulkanPreloadReplayer::Replay_vkUpdateDescriptorSets(Packet_vkUpdateDescriptorSets* packet)
{
    vulkan_replay_consumer_->Process_vkUpdateDescriptorSets(packet->call_info, packet->device, packet->descriptorWriteCount, &(packet->pDescriptorWrites), packet->descriptorCopyCount, &(packet->pDescriptorCopies));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateFramebuffer(Packet_vkCreateFramebuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCreateFramebuffer(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pFramebuffer));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyFramebuffer(Packet_vkDestroyFramebuffer* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyFramebuffer(packet->call_info, packet->device, packet->framebuffer, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateRenderPass(Packet_vkCreateRenderPass* packet)
{
    vulkan_replay_consumer_->Process_vkCreateRenderPass(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pRenderPass));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyRenderPass(Packet_vkDestroyRenderPass* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyRenderPass(packet->call_info, packet->device, packet->renderPass, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRenderAreaGranularity(Packet_vkGetRenderAreaGranularity* packet)
{
    vulkan_replay_consumer_->Process_vkGetRenderAreaGranularity(packet->call_info, packet->device, packet->renderPass, &(packet->pGranularity));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateCommandPool(Packet_vkCreateCommandPool* packet)
{
    vulkan_replay_consumer_->Process_vkCreateCommandPool(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pCommandPool));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyCommandPool(Packet_vkDestroyCommandPool* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyCommandPool(packet->call_info, packet->device, packet->commandPool, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkResetCommandPool(Packet_vkResetCommandPool* packet)
{
    vulkan_replay_consumer_->Process_vkResetCommandPool(packet->call_info, packet->return_value, packet->device, packet->commandPool, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkAllocateCommandBuffers(Packet_vkAllocateCommandBuffers* packet)
{
    vulkan_replay_consumer_->Process_vkAllocateCommandBuffers(packet->call_info, packet->return_value, packet->device, &(packet->pAllocateInfo), &(packet->pCommandBuffers));

    return;
}

void VulkanPreloadReplayer::Replay_vkFreeCommandBuffers(Packet_vkFreeCommandBuffers* packet)
{
    vulkan_replay_consumer_->Process_vkFreeCommandBuffers(packet->call_info, packet->device, packet->commandPool, packet->commandBufferCount, &(packet->pCommandBuffers));

    return;
}

void VulkanPreloadReplayer::Replay_vkBeginCommandBuffer(Packet_vkBeginCommandBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkBeginCommandBuffer(packet->call_info, packet->return_value, packet->commandBuffer, &(packet->pBeginInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkEndCommandBuffer(Packet_vkEndCommandBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkEndCommandBuffer(packet->call_info, packet->return_value, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkResetCommandBuffer(Packet_vkResetCommandBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkResetCommandBuffer(packet->call_info, packet->return_value, packet->commandBuffer, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindPipeline(Packet_vkCmdBindPipeline* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindPipeline(packet->call_info, packet->commandBuffer, packet->pipelineBindPoint, packet->pipeline);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewport(Packet_vkCmdSetViewport* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewport(packet->call_info, packet->commandBuffer, packet->firstViewport, packet->viewportCount, &(packet->pViewports));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetScissor(Packet_vkCmdSetScissor* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetScissor(packet->call_info, packet->commandBuffer, packet->firstScissor, packet->scissorCount, &(packet->pScissors));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLineWidth(Packet_vkCmdSetLineWidth* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLineWidth(packet->call_info, packet->commandBuffer, packet->lineWidth);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBias(Packet_vkCmdSetDepthBias* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBias(packet->call_info, packet->commandBuffer, packet->depthBiasConstantFactor, packet->depthBiasClamp, packet->depthBiasSlopeFactor);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetBlendConstants(Packet_vkCmdSetBlendConstants* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetBlendConstants(packet->call_info, packet->commandBuffer, &(packet->blendConstants));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBounds(Packet_vkCmdSetDepthBounds* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBounds(packet->call_info, packet->commandBuffer, packet->minDepthBounds, packet->maxDepthBounds);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilCompareMask(Packet_vkCmdSetStencilCompareMask* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilCompareMask(packet->call_info, packet->commandBuffer, packet->faceMask, packet->compareMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilWriteMask(Packet_vkCmdSetStencilWriteMask* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilWriteMask(packet->call_info, packet->commandBuffer, packet->faceMask, packet->writeMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilReference(Packet_vkCmdSetStencilReference* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilReference(packet->call_info, packet->commandBuffer, packet->faceMask, packet->reference);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindDescriptorSets(Packet_vkCmdBindDescriptorSets* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindDescriptorSets(packet->call_info, packet->commandBuffer, packet->pipelineBindPoint, packet->layout, packet->firstSet, packet->descriptorSetCount, &(packet->pDescriptorSets), packet->dynamicOffsetCount, &(packet->pDynamicOffsets));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindIndexBuffer(Packet_vkCmdBindIndexBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindIndexBuffer(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->indexType);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindVertexBuffers(Packet_vkCmdBindVertexBuffers* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindVertexBuffers(packet->call_info, packet->commandBuffer, packet->firstBinding, packet->bindingCount, &(packet->pBuffers), &(packet->pOffsets));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDraw(Packet_vkCmdDraw* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDraw(packet->call_info, packet->commandBuffer, packet->vertexCount, packet->instanceCount, packet->firstVertex, packet->firstInstance);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndexed(Packet_vkCmdDrawIndexed* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndexed(packet->call_info, packet->commandBuffer, packet->indexCount, packet->instanceCount, packet->firstIndex, packet->vertexOffset, packet->firstInstance);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndirect(Packet_vkCmdDrawIndirect* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndirect(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->drawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndexedIndirect(Packet_vkCmdDrawIndexedIndirect* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndexedIndirect(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->drawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDispatch(Packet_vkCmdDispatch* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDispatch(packet->call_info, packet->commandBuffer, packet->groupCountX, packet->groupCountY, packet->groupCountZ);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDispatchIndirect(Packet_vkCmdDispatchIndirect* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDispatchIndirect(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBuffer(Packet_vkCmdCopyBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBuffer(packet->call_info, packet->commandBuffer, packet->srcBuffer, packet->dstBuffer, packet->regionCount, &(packet->pRegions));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImage(Packet_vkCmdCopyImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImage(packet->call_info, packet->commandBuffer, packet->srcImage, packet->srcImageLayout, packet->dstImage, packet->dstImageLayout, packet->regionCount, &(packet->pRegions));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBlitImage(Packet_vkCmdBlitImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBlitImage(packet->call_info, packet->commandBuffer, packet->srcImage, packet->srcImageLayout, packet->dstImage, packet->dstImageLayout, packet->regionCount, &(packet->pRegions), packet->filter);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBufferToImage(Packet_vkCmdCopyBufferToImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBufferToImage(packet->call_info, packet->commandBuffer, packet->srcBuffer, packet->dstImage, packet->dstImageLayout, packet->regionCount, &(packet->pRegions));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImageToBuffer(Packet_vkCmdCopyImageToBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImageToBuffer(packet->call_info, packet->commandBuffer, packet->srcImage, packet->srcImageLayout, packet->dstBuffer, packet->regionCount, &(packet->pRegions));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdUpdateBuffer(Packet_vkCmdUpdateBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCmdUpdateBuffer(packet->call_info, packet->commandBuffer, packet->dstBuffer, packet->dstOffset, packet->dataSize, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdFillBuffer(Packet_vkCmdFillBuffer* packet)
{
    vulkan_replay_consumer_->Process_vkCmdFillBuffer(packet->call_info, packet->commandBuffer, packet->dstBuffer, packet->dstOffset, packet->size, packet->data);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdClearColorImage(Packet_vkCmdClearColorImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdClearColorImage(packet->call_info, packet->commandBuffer, packet->image, packet->imageLayout, &(packet->pColor), packet->rangeCount, &(packet->pRanges));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdClearDepthStencilImage(Packet_vkCmdClearDepthStencilImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdClearDepthStencilImage(packet->call_info, packet->commandBuffer, packet->image, packet->imageLayout, &(packet->pDepthStencil), packet->rangeCount, &(packet->pRanges));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdClearAttachments(Packet_vkCmdClearAttachments* packet)
{
    vulkan_replay_consumer_->Process_vkCmdClearAttachments(packet->call_info, packet->commandBuffer, packet->attachmentCount, &(packet->pAttachments), packet->rectCount, &(packet->pRects));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResolveImage(Packet_vkCmdResolveImage* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResolveImage(packet->call_info, packet->commandBuffer, packet->srcImage, packet->srcImageLayout, packet->dstImage, packet->dstImageLayout, packet->regionCount, &(packet->pRegions));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetEvent(Packet_vkCmdSetEvent* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetEvent(packet->call_info, packet->commandBuffer, packet->event, packet->stageMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResetEvent(Packet_vkCmdResetEvent* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResetEvent(packet->call_info, packet->commandBuffer, packet->event, packet->stageMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWaitEvents(Packet_vkCmdWaitEvents* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWaitEvents(packet->call_info, packet->commandBuffer, packet->eventCount, &(packet->pEvents), packet->srcStageMask, packet->dstStageMask, packet->memoryBarrierCount, &(packet->pMemoryBarriers), packet->bufferMemoryBarrierCount, &(packet->pBufferMemoryBarriers), packet->imageMemoryBarrierCount, &(packet->pImageMemoryBarriers));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPipelineBarrier(Packet_vkCmdPipelineBarrier* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPipelineBarrier(packet->call_info, packet->commandBuffer, packet->srcStageMask, packet->dstStageMask, packet->dependencyFlags, packet->memoryBarrierCount, &(packet->pMemoryBarriers), packet->bufferMemoryBarrierCount, &(packet->pBufferMemoryBarriers), packet->imageMemoryBarrierCount, &(packet->pImageMemoryBarriers));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginQuery(Packet_vkCmdBeginQuery* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginQuery(packet->call_info, packet->commandBuffer, packet->queryPool, packet->query, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndQuery(Packet_vkCmdEndQuery* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndQuery(packet->call_info, packet->commandBuffer, packet->queryPool, packet->query);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResetQueryPool(Packet_vkCmdResetQueryPool* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResetQueryPool(packet->call_info, packet->commandBuffer, packet->queryPool, packet->firstQuery, packet->queryCount);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteTimestamp(Packet_vkCmdWriteTimestamp* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteTimestamp(packet->call_info, packet->commandBuffer, packet->pipelineStage, packet->queryPool, packet->query);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyQueryPoolResults(Packet_vkCmdCopyQueryPoolResults* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyQueryPoolResults(packet->call_info, packet->commandBuffer, packet->queryPool, packet->firstQuery, packet->queryCount, packet->dstBuffer, packet->dstOffset, packet->stride, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPushConstants(Packet_vkCmdPushConstants* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushConstants(packet->call_info, packet->commandBuffer, packet->layout, packet->stageFlags, packet->offset, packet->size, &(packet->pValues));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginRenderPass(Packet_vkCmdBeginRenderPass* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginRenderPass(packet->call_info, packet->commandBuffer, &(packet->pRenderPassBegin), packet->contents);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdNextSubpass(Packet_vkCmdNextSubpass* packet)
{
    vulkan_replay_consumer_->Process_vkCmdNextSubpass(packet->call_info, packet->commandBuffer, packet->contents);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndRenderPass(Packet_vkCmdEndRenderPass* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndRenderPass(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdExecuteCommands(Packet_vkCmdExecuteCommands* packet)
{
    vulkan_replay_consumer_->Process_vkCmdExecuteCommands(packet->call_info, packet->commandBuffer, packet->commandBufferCount, &(packet->pCommandBuffers));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindBufferMemory2(Packet_vkBindBufferMemory2* packet)
{
    vulkan_replay_consumer_->Process_vkBindBufferMemory2(packet->call_info, packet->return_value, packet->device, packet->bindInfoCount, &(packet->pBindInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindImageMemory2(Packet_vkBindImageMemory2* packet)
{
    vulkan_replay_consumer_->Process_vkBindImageMemory2(packet->call_info, packet->return_value, packet->device, packet->bindInfoCount, &(packet->pBindInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceGroupPeerMemoryFeatures(Packet_vkGetDeviceGroupPeerMemoryFeatures* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceGroupPeerMemoryFeatures(packet->call_info, packet->device, packet->heapIndex, packet->localDeviceIndex, packet->remoteDeviceIndex, &(packet->pPeerMemoryFeatures));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDeviceMask(Packet_vkCmdSetDeviceMask* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDeviceMask(packet->call_info, packet->commandBuffer, packet->deviceMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDispatchBase(Packet_vkCmdDispatchBase* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDispatchBase(packet->call_info, packet->commandBuffer, packet->baseGroupX, packet->baseGroupY, packet->baseGroupZ, packet->groupCountX, packet->groupCountY, packet->groupCountZ);

    return;
}

void VulkanPreloadReplayer::Replay_vkEnumeratePhysicalDeviceGroups(Packet_vkEnumeratePhysicalDeviceGroups* packet)
{
    vulkan_replay_consumer_->Process_vkEnumeratePhysicalDeviceGroups(packet->call_info, packet->return_value, packet->instance, &(packet->pPhysicalDeviceGroupCount), &(packet->pPhysicalDeviceGroupProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageMemoryRequirements2(Packet_vkGetImageMemoryRequirements2* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageMemoryRequirements2(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferMemoryRequirements2(Packet_vkGetBufferMemoryRequirements2* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferMemoryRequirements2(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSparseMemoryRequirements2(Packet_vkGetImageSparseMemoryRequirements2* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSparseMemoryRequirements2(packet->call_info, packet->device, &(packet->pInfo), &(packet->pSparseMemoryRequirementCount), &(packet->pSparseMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFeatures2(Packet_vkGetPhysicalDeviceFeatures2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFeatures2(packet->call_info, packet->physicalDevice, &(packet->pFeatures));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceProperties2(Packet_vkGetPhysicalDeviceProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceProperties2(packet->call_info, packet->physicalDevice, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFormatProperties2(Packet_vkGetPhysicalDeviceFormatProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFormatProperties2(packet->call_info, packet->physicalDevice, packet->format, &(packet->pFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceImageFormatProperties2(Packet_vkGetPhysicalDeviceImageFormatProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceImageFormatProperties2(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pImageFormatInfo), &(packet->pImageFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceQueueFamilyProperties2(Packet_vkGetPhysicalDeviceQueueFamilyProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceQueueFamilyProperties2(packet->call_info, packet->physicalDevice, &(packet->pQueueFamilyPropertyCount), &(packet->pQueueFamilyProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceMemoryProperties2(Packet_vkGetPhysicalDeviceMemoryProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceMemoryProperties2(packet->call_info, packet->physicalDevice, &(packet->pMemoryProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSparseImageFormatProperties2(Packet_vkGetPhysicalDeviceSparseImageFormatProperties2* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(packet->call_info, packet->physicalDevice, &(packet->pFormatInfo), &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkTrimCommandPool(Packet_vkTrimCommandPool* packet)
{
    vulkan_replay_consumer_->Process_vkTrimCommandPool(packet->call_info, packet->device, packet->commandPool, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceQueue2(Packet_vkGetDeviceQueue2* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceQueue2(packet->call_info, packet->device, &(packet->pQueueInfo), &(packet->pQueue));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSamplerYcbcrConversion(Packet_vkCreateSamplerYcbcrConversion* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSamplerYcbcrConversion(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pYcbcrConversion));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySamplerYcbcrConversion(Packet_vkDestroySamplerYcbcrConversion* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySamplerYcbcrConversion(packet->call_info, packet->device, packet->ycbcrConversion, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDescriptorUpdateTemplate(Packet_vkCreateDescriptorUpdateTemplate* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDescriptorUpdateTemplate(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pDescriptorUpdateTemplate));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDescriptorUpdateTemplate(Packet_vkDestroyDescriptorUpdateTemplate* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDescriptorUpdateTemplate(packet->call_info, packet->device, packet->descriptorUpdateTemplate, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalBufferProperties(Packet_vkGetPhysicalDeviceExternalBufferProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalBufferProperties(packet->call_info, packet->physicalDevice, &(packet->pExternalBufferInfo), &(packet->pExternalBufferProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalFenceProperties(Packet_vkGetPhysicalDeviceExternalFenceProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalFenceProperties(packet->call_info, packet->physicalDevice, &(packet->pExternalFenceInfo), &(packet->pExternalFenceProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalSemaphoreProperties(Packet_vkGetPhysicalDeviceExternalSemaphoreProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(packet->call_info, packet->physicalDevice, &(packet->pExternalSemaphoreInfo), &(packet->pExternalSemaphoreProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDescriptorSetLayoutSupport(Packet_vkGetDescriptorSetLayoutSupport* packet)
{
    vulkan_replay_consumer_->Process_vkGetDescriptorSetLayoutSupport(packet->call_info, packet->device, &(packet->pCreateInfo), &(packet->pSupport));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndirectCount(Packet_vkCmdDrawIndirectCount* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndirectCount(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndexedIndirectCount(Packet_vkCmdDrawIndexedIndirectCount* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndexedIndirectCount(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateRenderPass2(Packet_vkCreateRenderPass2* packet)
{
    vulkan_replay_consumer_->Process_vkCreateRenderPass2(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pRenderPass));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginRenderPass2(Packet_vkCmdBeginRenderPass2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginRenderPass2(packet->call_info, packet->commandBuffer, &(packet->pRenderPassBegin), &(packet->pSubpassBeginInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdNextSubpass2(Packet_vkCmdNextSubpass2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdNextSubpass2(packet->call_info, packet->commandBuffer, &(packet->pSubpassBeginInfo), &(packet->pSubpassEndInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndRenderPass2(Packet_vkCmdEndRenderPass2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndRenderPass2(packet->call_info, packet->commandBuffer, &(packet->pSubpassEndInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkResetQueryPool(Packet_vkResetQueryPool* packet)
{
    vulkan_replay_consumer_->Process_vkResetQueryPool(packet->call_info, packet->device, packet->queryPool, packet->firstQuery, packet->queryCount);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSemaphoreCounterValue(Packet_vkGetSemaphoreCounterValue* packet)
{
    vulkan_replay_consumer_->Process_vkGetSemaphoreCounterValue(packet->call_info, packet->return_value, packet->device, packet->semaphore, &(packet->pValue));

    return;
}

void VulkanPreloadReplayer::Replay_vkWaitSemaphores(Packet_vkWaitSemaphores* packet)
{
    vulkan_replay_consumer_->Process_vkWaitSemaphores(packet->call_info, packet->return_value, packet->device, &(packet->pWaitInfo), packet->timeout);

    return;
}

void VulkanPreloadReplayer::Replay_vkSignalSemaphore(Packet_vkSignalSemaphore* packet)
{
    vulkan_replay_consumer_->Process_vkSignalSemaphore(packet->call_info, packet->return_value, packet->device, &(packet->pSignalInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferDeviceAddress(Packet_vkGetBufferDeviceAddress* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferDeviceAddress(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferOpaqueCaptureAddress(Packet_vkGetBufferOpaqueCaptureAddress* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferOpaqueCaptureAddress(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceMemoryOpaqueCaptureAddress(Packet_vkGetDeviceMemoryOpaqueCaptureAddress* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceMemoryOpaqueCaptureAddress(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceToolProperties(Packet_vkGetPhysicalDeviceToolProperties* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceToolProperties(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pToolCount), &(packet->pToolProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreatePrivateDataSlot(Packet_vkCreatePrivateDataSlot* packet)
{
    vulkan_replay_consumer_->Process_vkCreatePrivateDataSlot(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pPrivateDataSlot));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyPrivateDataSlot(Packet_vkDestroyPrivateDataSlot* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyPrivateDataSlot(packet->call_info, packet->device, packet->privateDataSlot, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetPrivateData(Packet_vkSetPrivateData* packet)
{
    vulkan_replay_consumer_->Process_vkSetPrivateData(packet->call_info, packet->return_value, packet->device, packet->objectType, packet->objectHandle, packet->privateDataSlot, packet->data);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPrivateData(Packet_vkGetPrivateData* packet)
{
    vulkan_replay_consumer_->Process_vkGetPrivateData(packet->call_info, packet->device, packet->objectType, packet->objectHandle, packet->privateDataSlot, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetEvent2(Packet_vkCmdSetEvent2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetEvent2(packet->call_info, packet->commandBuffer, packet->event, &(packet->pDependencyInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResetEvent2(Packet_vkCmdResetEvent2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResetEvent2(packet->call_info, packet->commandBuffer, packet->event, packet->stageMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWaitEvents2(Packet_vkCmdWaitEvents2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWaitEvents2(packet->call_info, packet->commandBuffer, packet->eventCount, &(packet->pEvents), &(packet->pDependencyInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPipelineBarrier2(Packet_vkCmdPipelineBarrier2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPipelineBarrier2(packet->call_info, packet->commandBuffer, &(packet->pDependencyInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteTimestamp2(Packet_vkCmdWriteTimestamp2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteTimestamp2(packet->call_info, packet->commandBuffer, packet->stage, packet->queryPool, packet->query);

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueSubmit2(Packet_vkQueueSubmit2* packet)
{
    vulkan_replay_consumer_->Process_vkQueueSubmit2(packet->call_info, packet->return_value, packet->queue, packet->submitCount, &(packet->pSubmits), packet->fence);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBuffer2(Packet_vkCmdCopyBuffer2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBuffer2(packet->call_info, packet->commandBuffer, &(packet->pCopyBufferInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImage2(Packet_vkCmdCopyImage2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImage2(packet->call_info, packet->commandBuffer, &(packet->pCopyImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBufferToImage2(Packet_vkCmdCopyBufferToImage2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBufferToImage2(packet->call_info, packet->commandBuffer, &(packet->pCopyBufferToImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImageToBuffer2(Packet_vkCmdCopyImageToBuffer2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImageToBuffer2(packet->call_info, packet->commandBuffer, &(packet->pCopyImageToBufferInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBlitImage2(Packet_vkCmdBlitImage2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBlitImage2(packet->call_info, packet->commandBuffer, &(packet->pBlitImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResolveImage2(Packet_vkCmdResolveImage2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResolveImage2(packet->call_info, packet->commandBuffer, &(packet->pResolveImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginRendering(Packet_vkCmdBeginRendering* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginRendering(packet->call_info, packet->commandBuffer, &(packet->pRenderingInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndRendering(Packet_vkCmdEndRendering* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndRendering(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCullMode(Packet_vkCmdSetCullMode* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCullMode(packet->call_info, packet->commandBuffer, packet->cullMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetFrontFace(Packet_vkCmdSetFrontFace* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetFrontFace(packet->call_info, packet->commandBuffer, packet->frontFace);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPrimitiveTopology(Packet_vkCmdSetPrimitiveTopology* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPrimitiveTopology(packet->call_info, packet->commandBuffer, packet->primitiveTopology);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportWithCount(Packet_vkCmdSetViewportWithCount* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportWithCount(packet->call_info, packet->commandBuffer, packet->viewportCount, &(packet->pViewports));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetScissorWithCount(Packet_vkCmdSetScissorWithCount* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetScissorWithCount(packet->call_info, packet->commandBuffer, packet->scissorCount, &(packet->pScissors));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindVertexBuffers2(Packet_vkCmdBindVertexBuffers2* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindVertexBuffers2(packet->call_info, packet->commandBuffer, packet->firstBinding, packet->bindingCount, &(packet->pBuffers), &(packet->pOffsets), &(packet->pSizes), &(packet->pStrides));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthTestEnable(Packet_vkCmdSetDepthTestEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthTestEnable(packet->call_info, packet->commandBuffer, packet->depthTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthWriteEnable(Packet_vkCmdSetDepthWriteEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthWriteEnable(packet->call_info, packet->commandBuffer, packet->depthWriteEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthCompareOp(Packet_vkCmdSetDepthCompareOp* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthCompareOp(packet->call_info, packet->commandBuffer, packet->depthCompareOp);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBoundsTestEnable(Packet_vkCmdSetDepthBoundsTestEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBoundsTestEnable(packet->call_info, packet->commandBuffer, packet->depthBoundsTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilTestEnable(Packet_vkCmdSetStencilTestEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilTestEnable(packet->call_info, packet->commandBuffer, packet->stencilTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilOp(Packet_vkCmdSetStencilOp* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilOp(packet->call_info, packet->commandBuffer, packet->faceMask, packet->failOp, packet->passOp, packet->depthFailOp, packet->compareOp);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRasterizerDiscardEnable(Packet_vkCmdSetRasterizerDiscardEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRasterizerDiscardEnable(packet->call_info, packet->commandBuffer, packet->rasterizerDiscardEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBiasEnable(Packet_vkCmdSetDepthBiasEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBiasEnable(packet->call_info, packet->commandBuffer, packet->depthBiasEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPrimitiveRestartEnable(Packet_vkCmdSetPrimitiveRestartEnable* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPrimitiveRestartEnable(packet->call_info, packet->commandBuffer, packet->primitiveRestartEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceBufferMemoryRequirements(Packet_vkGetDeviceBufferMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceBufferMemoryRequirements(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceImageMemoryRequirements(Packet_vkGetDeviceImageMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceImageMemoryRequirements(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceImageSparseMemoryRequirements(Packet_vkGetDeviceImageSparseMemoryRequirements* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceImageSparseMemoryRequirements(packet->call_info, packet->device, &(packet->pInfo), &(packet->pSparseMemoryRequirementCount), &(packet->pSparseMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySurfaceKHR(Packet_vkDestroySurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySurfaceKHR(packet->call_info, packet->instance, packet->surface, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceSupportKHR(Packet_vkGetPhysicalDeviceSurfaceSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceSupportKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->surface, &(packet->pSupported));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->surface, &(packet->pSurfaceCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceFormatsKHR(Packet_vkGetPhysicalDeviceSurfaceFormatsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->surface, &(packet->pSurfaceFormatCount), &(packet->pSurfaceFormats));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfacePresentModesKHR(Packet_vkGetPhysicalDeviceSurfacePresentModesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->surface, &(packet->pPresentModeCount), &(packet->pPresentModes));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSwapchainKHR(Packet_vkCreateSwapchainKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSwapchainKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSwapchain));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySwapchainKHR(Packet_vkDestroySwapchainKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySwapchainKHR(packet->call_info, packet->device, packet->swapchain, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSwapchainImagesKHR(Packet_vkGetSwapchainImagesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetSwapchainImagesKHR(packet->call_info, packet->return_value, packet->device, packet->swapchain, &(packet->pSwapchainImageCount), &(packet->pSwapchainImages));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireNextImageKHR(Packet_vkAcquireNextImageKHR* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireNextImageKHR(packet->call_info, packet->return_value, packet->device, packet->swapchain, packet->timeout, packet->semaphore, packet->fence, &(packet->pImageIndex));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueuePresentKHR(Packet_vkQueuePresentKHR* packet)
{
    vulkan_replay_consumer_->Process_vkQueuePresentKHR(packet->call_info, packet->return_value, packet->queue, &(packet->pPresentInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceGroupPresentCapabilitiesKHR(Packet_vkGetDeviceGroupPresentCapabilitiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceGroupPresentCapabilitiesKHR(packet->call_info, packet->return_value, packet->device, &(packet->pDeviceGroupPresentCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceGroupSurfacePresentModesKHR(Packet_vkGetDeviceGroupSurfacePresentModesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceGroupSurfacePresentModesKHR(packet->call_info, packet->return_value, packet->device, packet->surface, &(packet->pModes));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDevicePresentRectanglesKHR(Packet_vkGetPhysicalDevicePresentRectanglesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDevicePresentRectanglesKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->surface, &(packet->pRectCount), &(packet->pRects));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireNextImage2KHR(Packet_vkAcquireNextImage2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireNextImage2KHR(packet->call_info, packet->return_value, packet->device, &(packet->pAcquireInfo), &(packet->pImageIndex));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceDisplayPropertiesKHR(Packet_vkGetPhysicalDeviceDisplayPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDisplayPlaneSupportedDisplaysKHR(Packet_vkGetDisplayPlaneSupportedDisplaysKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDisplayPlaneSupportedDisplaysKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->planeIndex, &(packet->pDisplayCount), &(packet->pDisplays));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDisplayModePropertiesKHR(Packet_vkGetDisplayModePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDisplayModePropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->display, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDisplayModeKHR(Packet_vkCreateDisplayModeKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDisplayModeKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->display, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pMode));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDisplayPlaneCapabilitiesKHR(Packet_vkGetDisplayPlaneCapabilitiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDisplayPlaneCapabilitiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->mode, packet->planeIndex, &(packet->pCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDisplayPlaneSurfaceKHR(Packet_vkCreateDisplayPlaneSurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDisplayPlaneSurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSharedSwapchainsKHR(Packet_vkCreateSharedSwapchainsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSharedSwapchainsKHR(packet->call_info, packet->return_value, packet->device, packet->swapchainCount, &(packet->pCreateInfos), &(packet->pAllocator), &(packet->pSwapchains));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateXlibSurfaceKHR(Packet_vkCreateXlibSurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateXlibSurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceXlibPresentationSupportKHR(Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->dpy, packet->visualID);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateXcbSurfaceKHR(Packet_vkCreateXcbSurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateXcbSurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceXcbPresentationSupportKHR(Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->connection, packet->visual_id);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateWaylandSurfaceKHR(Packet_vkCreateWaylandSurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateWaylandSurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceWaylandPresentationSupportKHR(Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->display);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateAndroidSurfaceKHR(Packet_vkCreateAndroidSurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateAndroidSurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateWin32SurfaceKHR(Packet_vkCreateWin32SurfaceKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateWin32SurfaceKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceWin32PresentationSupportKHR(Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceVideoCapabilitiesKHR(Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pVideoProfile), &(packet->pCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceVideoFormatPropertiesKHR(Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pVideoFormatInfo), &(packet->pVideoFormatPropertyCount), &(packet->pVideoFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateVideoSessionKHR(Packet_vkCreateVideoSessionKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateVideoSessionKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pVideoSession));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyVideoSessionKHR(Packet_vkDestroyVideoSessionKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyVideoSessionKHR(packet->call_info, packet->device, packet->videoSession, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetVideoSessionMemoryRequirementsKHR(Packet_vkGetVideoSessionMemoryRequirementsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetVideoSessionMemoryRequirementsKHR(packet->call_info, packet->return_value, packet->device, packet->videoSession, &(packet->pMemoryRequirementsCount), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindVideoSessionMemoryKHR(Packet_vkBindVideoSessionMemoryKHR* packet)
{
    vulkan_replay_consumer_->Process_vkBindVideoSessionMemoryKHR(packet->call_info, packet->return_value, packet->device, packet->videoSession, packet->bindSessionMemoryInfoCount, &(packet->pBindSessionMemoryInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateVideoSessionParametersKHR(Packet_vkCreateVideoSessionParametersKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateVideoSessionParametersKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pVideoSessionParameters));

    return;
}

void VulkanPreloadReplayer::Replay_vkUpdateVideoSessionParametersKHR(Packet_vkUpdateVideoSessionParametersKHR* packet)
{
    vulkan_replay_consumer_->Process_vkUpdateVideoSessionParametersKHR(packet->call_info, packet->return_value, packet->device, packet->videoSessionParameters, &(packet->pUpdateInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyVideoSessionParametersKHR(Packet_vkDestroyVideoSessionParametersKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyVideoSessionParametersKHR(packet->call_info, packet->device, packet->videoSessionParameters, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginVideoCodingKHR(Packet_vkCmdBeginVideoCodingKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginVideoCodingKHR(packet->call_info, packet->commandBuffer, &(packet->pBeginInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndVideoCodingKHR(Packet_vkCmdEndVideoCodingKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndVideoCodingKHR(packet->call_info, packet->commandBuffer, &(packet->pEndCodingInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdControlVideoCodingKHR(Packet_vkCmdControlVideoCodingKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdControlVideoCodingKHR(packet->call_info, packet->commandBuffer, &(packet->pCodingControlInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDecodeVideoKHR(Packet_vkCmdDecodeVideoKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDecodeVideoKHR(packet->call_info, packet->commandBuffer, &(packet->pDecodeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginRenderingKHR(Packet_vkCmdBeginRenderingKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginRenderingKHR(packet->call_info, packet->commandBuffer, &(packet->pRenderingInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndRenderingKHR(Packet_vkCmdEndRenderingKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndRenderingKHR(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFeatures2KHR(Packet_vkGetPhysicalDeviceFeatures2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFeatures2KHR(packet->call_info, packet->physicalDevice, &(packet->pFeatures));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceProperties2KHR(Packet_vkGetPhysicalDeviceProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceProperties2KHR(packet->call_info, packet->physicalDevice, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFormatProperties2KHR(Packet_vkGetPhysicalDeviceFormatProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFormatProperties2KHR(packet->call_info, packet->physicalDevice, packet->format, &(packet->pFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceImageFormatProperties2KHR(Packet_vkGetPhysicalDeviceImageFormatProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pImageFormatInfo), &(packet->pImageFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceQueueFamilyProperties2KHR(Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(packet->call_info, packet->physicalDevice, &(packet->pQueueFamilyPropertyCount), &(packet->pQueueFamilyProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceMemoryProperties2KHR(Packet_vkGetPhysicalDeviceMemoryProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceMemoryProperties2KHR(packet->call_info, packet->physicalDevice, &(packet->pMemoryProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(packet->call_info, packet->physicalDevice, &(packet->pFormatInfo), &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceGroupPeerMemoryFeaturesKHR(Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(packet->call_info, packet->device, packet->heapIndex, packet->localDeviceIndex, packet->remoteDeviceIndex, &(packet->pPeerMemoryFeatures));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDeviceMaskKHR(Packet_vkCmdSetDeviceMaskKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDeviceMaskKHR(packet->call_info, packet->commandBuffer, packet->deviceMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDispatchBaseKHR(Packet_vkCmdDispatchBaseKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDispatchBaseKHR(packet->call_info, packet->commandBuffer, packet->baseGroupX, packet->baseGroupY, packet->baseGroupZ, packet->groupCountX, packet->groupCountY, packet->groupCountZ);

    return;
}

void VulkanPreloadReplayer::Replay_vkTrimCommandPoolKHR(Packet_vkTrimCommandPoolKHR* packet)
{
    vulkan_replay_consumer_->Process_vkTrimCommandPoolKHR(packet->call_info, packet->device, packet->commandPool, packet->flags);

    return;
}

void VulkanPreloadReplayer::Replay_vkEnumeratePhysicalDeviceGroupsKHR(Packet_vkEnumeratePhysicalDeviceGroupsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkEnumeratePhysicalDeviceGroupsKHR(packet->call_info, packet->return_value, packet->instance, &(packet->pPhysicalDeviceGroupCount), &(packet->pPhysicalDeviceGroupProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalBufferPropertiesKHR(Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(packet->call_info, packet->physicalDevice, &(packet->pExternalBufferInfo), &(packet->pExternalBufferProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryWin32HandleKHR(Packet_vkGetMemoryWin32HandleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryWin32HandleKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetWin32HandleInfo), &(packet->pHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryWin32HandlePropertiesKHR(Packet_vkGetMemoryWin32HandlePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryWin32HandlePropertiesKHR(packet->call_info, packet->return_value, packet->device, packet->handleType, packet->handle, &(packet->pMemoryWin32HandleProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryFdKHR(Packet_vkGetMemoryFdKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryFdKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetFdInfo), &(packet->pFd));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryFdPropertiesKHR(Packet_vkGetMemoryFdPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryFdPropertiesKHR(packet->call_info, packet->return_value, packet->device, packet->handleType, packet->fd, &(packet->pMemoryFdProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(packet->call_info, packet->physicalDevice, &(packet->pExternalSemaphoreInfo), &(packet->pExternalSemaphoreProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkImportSemaphoreWin32HandleKHR(Packet_vkImportSemaphoreWin32HandleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkImportSemaphoreWin32HandleKHR(packet->call_info, packet->return_value, packet->device, &(packet->pImportSemaphoreWin32HandleInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSemaphoreWin32HandleKHR(Packet_vkGetSemaphoreWin32HandleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetSemaphoreWin32HandleKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetWin32HandleInfo), &(packet->pHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkImportSemaphoreFdKHR(Packet_vkImportSemaphoreFdKHR* packet)
{
    vulkan_replay_consumer_->Process_vkImportSemaphoreFdKHR(packet->call_info, packet->return_value, packet->device, &(packet->pImportSemaphoreFdInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSemaphoreFdKHR(Packet_vkGetSemaphoreFdKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetSemaphoreFdKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetFdInfo), &(packet->pFd));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPushDescriptorSetKHR(Packet_vkCmdPushDescriptorSetKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushDescriptorSetKHR(packet->call_info, packet->commandBuffer, packet->pipelineBindPoint, packet->layout, packet->set, packet->descriptorWriteCount, &(packet->pDescriptorWrites));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDescriptorUpdateTemplateKHR(Packet_vkCreateDescriptorUpdateTemplateKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDescriptorUpdateTemplateKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pDescriptorUpdateTemplate));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDescriptorUpdateTemplateKHR(Packet_vkDestroyDescriptorUpdateTemplateKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDescriptorUpdateTemplateKHR(packet->call_info, packet->device, packet->descriptorUpdateTemplate, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateRenderPass2KHR(Packet_vkCreateRenderPass2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateRenderPass2KHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pRenderPass));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginRenderPass2KHR(Packet_vkCmdBeginRenderPass2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginRenderPass2KHR(packet->call_info, packet->commandBuffer, &(packet->pRenderPassBegin), &(packet->pSubpassBeginInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdNextSubpass2KHR(Packet_vkCmdNextSubpass2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdNextSubpass2KHR(packet->call_info, packet->commandBuffer, &(packet->pSubpassBeginInfo), &(packet->pSubpassEndInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndRenderPass2KHR(Packet_vkCmdEndRenderPass2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndRenderPass2KHR(packet->call_info, packet->commandBuffer, &(packet->pSubpassEndInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSwapchainStatusKHR(Packet_vkGetSwapchainStatusKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetSwapchainStatusKHR(packet->call_info, packet->return_value, packet->device, packet->swapchain);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalFencePropertiesKHR(Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(packet->call_info, packet->physicalDevice, &(packet->pExternalFenceInfo), &(packet->pExternalFenceProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkImportFenceWin32HandleKHR(Packet_vkImportFenceWin32HandleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkImportFenceWin32HandleKHR(packet->call_info, packet->return_value, packet->device, &(packet->pImportFenceWin32HandleInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetFenceWin32HandleKHR(Packet_vkGetFenceWin32HandleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetFenceWin32HandleKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetWin32HandleInfo), &(packet->pHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkImportFenceFdKHR(Packet_vkImportFenceFdKHR* packet)
{
    vulkan_replay_consumer_->Process_vkImportFenceFdKHR(packet->call_info, packet->return_value, packet->device, &(packet->pImportFenceFdInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetFenceFdKHR(Packet_vkGetFenceFdKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetFenceFdKHR(packet->call_info, packet->return_value, packet->device, &(packet->pGetFdInfo), &(packet->pFd));

    return;
}

void VulkanPreloadReplayer::Replay_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR* packet)
{
    vulkan_replay_consumer_->Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, &(packet->pCounterCount), &(packet->pCounters), &(packet->pCounterDescriptions));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(packet->call_info, packet->physicalDevice, &(packet->pPerformanceQueryCreateInfo), &(packet->pNumPasses));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireProfilingLockKHR(Packet_vkAcquireProfilingLockKHR* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireProfilingLockKHR(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkReleaseProfilingLockKHR(Packet_vkReleaseProfilingLockKHR* packet)
{
    vulkan_replay_consumer_->Process_vkReleaseProfilingLockKHR(packet->call_info, packet->device);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceCapabilities2KHR(Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pSurfaceInfo), &(packet->pSurfaceCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceFormats2KHR(Packet_vkGetPhysicalDeviceSurfaceFormats2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pSurfaceInfo), &(packet->pSurfaceFormatCount), &(packet->pSurfaceFormats));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceDisplayProperties2KHR(Packet_vkGetPhysicalDeviceDisplayProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceDisplayProperties2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDisplayModeProperties2KHR(Packet_vkGetDisplayModeProperties2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDisplayModeProperties2KHR(packet->call_info, packet->return_value, packet->physicalDevice, packet->display, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDisplayPlaneCapabilities2KHR(Packet_vkGetDisplayPlaneCapabilities2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDisplayPlaneCapabilities2KHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pDisplayPlaneInfo), &(packet->pCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageMemoryRequirements2KHR(Packet_vkGetImageMemoryRequirements2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageMemoryRequirements2KHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferMemoryRequirements2KHR(Packet_vkGetBufferMemoryRequirements2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferMemoryRequirements2KHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSparseMemoryRequirements2KHR(Packet_vkGetImageSparseMemoryRequirements2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSparseMemoryRequirements2KHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pSparseMemoryRequirementCount), &(packet->pSparseMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateSamplerYcbcrConversionKHR(Packet_vkCreateSamplerYcbcrConversionKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateSamplerYcbcrConversionKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pYcbcrConversion));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroySamplerYcbcrConversionKHR(Packet_vkDestroySamplerYcbcrConversionKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroySamplerYcbcrConversionKHR(packet->call_info, packet->device, packet->ycbcrConversion, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindBufferMemory2KHR(Packet_vkBindBufferMemory2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkBindBufferMemory2KHR(packet->call_info, packet->return_value, packet->device, packet->bindInfoCount, &(packet->pBindInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindImageMemory2KHR(Packet_vkBindImageMemory2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkBindImageMemory2KHR(packet->call_info, packet->return_value, packet->device, packet->bindInfoCount, &(packet->pBindInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDescriptorSetLayoutSupportKHR(Packet_vkGetDescriptorSetLayoutSupportKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDescriptorSetLayoutSupportKHR(packet->call_info, packet->device, &(packet->pCreateInfo), &(packet->pSupport));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndirectCountKHR(Packet_vkCmdDrawIndirectCountKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndirectCountKHR(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndexedIndirectCountKHR(Packet_vkCmdDrawIndexedIndirectCountKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndexedIndirectCountKHR(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSemaphoreCounterValueKHR(Packet_vkGetSemaphoreCounterValueKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetSemaphoreCounterValueKHR(packet->call_info, packet->return_value, packet->device, packet->semaphore, &(packet->pValue));

    return;
}

void VulkanPreloadReplayer::Replay_vkWaitSemaphoresKHR(Packet_vkWaitSemaphoresKHR* packet)
{
    vulkan_replay_consumer_->Process_vkWaitSemaphoresKHR(packet->call_info, packet->return_value, packet->device, &(packet->pWaitInfo), packet->timeout);

    return;
}

void VulkanPreloadReplayer::Replay_vkSignalSemaphoreKHR(Packet_vkSignalSemaphoreKHR* packet)
{
    vulkan_replay_consumer_->Process_vkSignalSemaphoreKHR(packet->call_info, packet->return_value, packet->device, &(packet->pSignalInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceFragmentShadingRatesKHR(Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pFragmentShadingRateCount), &(packet->pFragmentShadingRates));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetFragmentShadingRateKHR(Packet_vkCmdSetFragmentShadingRateKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetFragmentShadingRateKHR(packet->call_info, packet->commandBuffer, &(packet->pFragmentSize), &(packet->combinerOps));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRenderingAttachmentLocationsKHR(Packet_vkCmdSetRenderingAttachmentLocationsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRenderingAttachmentLocationsKHR(packet->call_info, packet->commandBuffer, &(packet->pLocationInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRenderingInputAttachmentIndicesKHR(Packet_vkCmdSetRenderingInputAttachmentIndicesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRenderingInputAttachmentIndicesKHR(packet->call_info, packet->commandBuffer, &(packet->pInputAttachmentIndexInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkWaitForPresentKHR(Packet_vkWaitForPresentKHR* packet)
{
    vulkan_replay_consumer_->Process_vkWaitForPresentKHR(packet->call_info, packet->return_value, packet->device, packet->swapchain, packet->presentId, packet->timeout);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferDeviceAddressKHR(Packet_vkGetBufferDeviceAddressKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferDeviceAddressKHR(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferOpaqueCaptureAddressKHR(Packet_vkGetBufferOpaqueCaptureAddressKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferOpaqueCaptureAddressKHR(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceMemoryOpaqueCaptureAddressKHR(Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDeferredOperationKHR(Packet_vkCreateDeferredOperationKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDeferredOperationKHR(packet->call_info, packet->return_value, packet->device, &(packet->pAllocator), &(packet->pDeferredOperation));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDeferredOperationKHR(Packet_vkDestroyDeferredOperationKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDeferredOperationKHR(packet->call_info, packet->device, packet->operation, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeferredOperationMaxConcurrencyKHR(Packet_vkGetDeferredOperationMaxConcurrencyKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeferredOperationMaxConcurrencyKHR(packet->call_info, packet->return_value, packet->device, packet->operation);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeferredOperationResultKHR(Packet_vkGetDeferredOperationResultKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeferredOperationResultKHR(packet->call_info, packet->return_value, packet->device, packet->operation);

    return;
}

void VulkanPreloadReplayer::Replay_vkDeferredOperationJoinKHR(Packet_vkDeferredOperationJoinKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDeferredOperationJoinKHR(packet->call_info, packet->return_value, packet->device, packet->operation);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineExecutablePropertiesKHR(Packet_vkGetPipelineExecutablePropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineExecutablePropertiesKHR(packet->call_info, packet->return_value, packet->device, &(packet->pPipelineInfo), &(packet->pExecutableCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineExecutableStatisticsKHR(Packet_vkGetPipelineExecutableStatisticsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineExecutableStatisticsKHR(packet->call_info, packet->return_value, packet->device, &(packet->pExecutableInfo), &(packet->pStatisticCount), &(packet->pStatistics));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineExecutableInternalRepresentationsKHR(Packet_vkGetPipelineExecutableInternalRepresentationsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineExecutableInternalRepresentationsKHR(packet->call_info, packet->return_value, packet->device, &(packet->pExecutableInfo), &(packet->pInternalRepresentationCount), &(packet->pInternalRepresentations));

    return;
}

void VulkanPreloadReplayer::Replay_vkMapMemory2KHR(Packet_vkMapMemory2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkMapMemory2KHR(packet->call_info, packet->return_value, packet->device, &(packet->pMemoryMapInfo), &(packet->ppData));

    return;
}

void VulkanPreloadReplayer::Replay_vkUnmapMemory2KHR(Packet_vkUnmapMemory2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkUnmapMemory2KHR(packet->call_info, packet->return_value, packet->device, &(packet->pMemoryUnmapInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pQualityLevelInfo), &(packet->pQualityLevelProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetEncodedVideoSessionParametersKHR(Packet_vkGetEncodedVideoSessionParametersKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetEncodedVideoSessionParametersKHR(packet->call_info, packet->return_value, packet->device, &(packet->pVideoSessionParametersInfo), &(packet->pFeedbackInfo), &(packet->pDataSize), &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEncodeVideoKHR(Packet_vkCmdEncodeVideoKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEncodeVideoKHR(packet->call_info, packet->commandBuffer, &(packet->pEncodeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetEvent2KHR(Packet_vkCmdSetEvent2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetEvent2KHR(packet->call_info, packet->commandBuffer, packet->event, &(packet->pDependencyInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResetEvent2KHR(Packet_vkCmdResetEvent2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResetEvent2KHR(packet->call_info, packet->commandBuffer, packet->event, packet->stageMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWaitEvents2KHR(Packet_vkCmdWaitEvents2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWaitEvents2KHR(packet->call_info, packet->commandBuffer, packet->eventCount, &(packet->pEvents), &(packet->pDependencyInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPipelineBarrier2KHR(Packet_vkCmdPipelineBarrier2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPipelineBarrier2KHR(packet->call_info, packet->commandBuffer, &(packet->pDependencyInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteTimestamp2KHR(Packet_vkCmdWriteTimestamp2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteTimestamp2KHR(packet->call_info, packet->commandBuffer, packet->stage, packet->queryPool, packet->query);

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueSubmit2KHR(Packet_vkQueueSubmit2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkQueueSubmit2KHR(packet->call_info, packet->return_value, packet->queue, packet->submitCount, &(packet->pSubmits), packet->fence);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteBufferMarker2AMD(Packet_vkCmdWriteBufferMarker2AMD* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteBufferMarker2AMD(packet->call_info, packet->commandBuffer, packet->stage, packet->dstBuffer, packet->dstOffset, packet->marker);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetQueueCheckpointData2NV(Packet_vkGetQueueCheckpointData2NV* packet)
{
    vulkan_replay_consumer_->Process_vkGetQueueCheckpointData2NV(packet->call_info, packet->queue, &(packet->pCheckpointDataCount), &(packet->pCheckpointData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBuffer2KHR(Packet_vkCmdCopyBuffer2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBuffer2KHR(packet->call_info, packet->commandBuffer, &(packet->pCopyBufferInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImage2KHR(Packet_vkCmdCopyImage2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImage2KHR(packet->call_info, packet->commandBuffer, &(packet->pCopyImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyBufferToImage2KHR(Packet_vkCmdCopyBufferToImage2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyBufferToImage2KHR(packet->call_info, packet->commandBuffer, &(packet->pCopyBufferToImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyImageToBuffer2KHR(Packet_vkCmdCopyImageToBuffer2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyImageToBuffer2KHR(packet->call_info, packet->commandBuffer, &(packet->pCopyImageToBufferInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBlitImage2KHR(Packet_vkCmdBlitImage2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBlitImage2KHR(packet->call_info, packet->commandBuffer, &(packet->pBlitImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdResolveImage2KHR(Packet_vkCmdResolveImage2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdResolveImage2KHR(packet->call_info, packet->commandBuffer, &(packet->pResolveImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdTraceRaysIndirect2KHR(Packet_vkCmdTraceRaysIndirect2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdTraceRaysIndirect2KHR(packet->call_info, packet->commandBuffer, packet->indirectDeviceAddress);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceBufferMemoryRequirementsKHR(Packet_vkGetDeviceBufferMemoryRequirementsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceBufferMemoryRequirementsKHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceImageMemoryRequirementsKHR(Packet_vkGetDeviceImageMemoryRequirementsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceImageMemoryRequirementsKHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceImageSparseMemoryRequirementsKHR(Packet_vkGetDeviceImageSparseMemoryRequirementsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceImageSparseMemoryRequirementsKHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pSparseMemoryRequirementCount), &(packet->pSparseMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindIndexBuffer2KHR(Packet_vkCmdBindIndexBuffer2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindIndexBuffer2KHR(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->size, packet->indexType);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRenderingAreaGranularityKHR(Packet_vkGetRenderingAreaGranularityKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetRenderingAreaGranularityKHR(packet->call_info, packet->device, &(packet->pRenderingAreaInfo), &(packet->pGranularity));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceImageSubresourceLayoutKHR(Packet_vkGetDeviceImageSubresourceLayoutKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceImageSubresourceLayoutKHR(packet->call_info, packet->device, &(packet->pInfo), &(packet->pLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSubresourceLayout2KHR(Packet_vkGetImageSubresourceLayout2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSubresourceLayout2KHR(packet->call_info, packet->device, packet->image, &(packet->pSubresource), &(packet->pLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLineStippleKHR(Packet_vkCmdSetLineStippleKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLineStippleKHR(packet->call_info, packet->commandBuffer, packet->lineStippleFactor, packet->lineStipplePattern);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pTimeDomainCount), &(packet->pTimeDomains));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetCalibratedTimestampsKHR(Packet_vkGetCalibratedTimestampsKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetCalibratedTimestampsKHR(packet->call_info, packet->return_value, packet->device, packet->timestampCount, &(packet->pTimestampInfos), &(packet->pTimestamps), &(packet->pMaxDeviation));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindDescriptorSets2KHR(Packet_vkCmdBindDescriptorSets2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindDescriptorSets2KHR(packet->call_info, packet->commandBuffer, &(packet->pBindDescriptorSetsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPushConstants2KHR(Packet_vkCmdPushConstants2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushConstants2KHR(packet->call_info, packet->commandBuffer, &(packet->pPushConstantsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPushDescriptorSet2KHR(Packet_vkCmdPushDescriptorSet2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushDescriptorSet2KHR(packet->call_info, packet->commandBuffer, &(packet->pPushDescriptorSetInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDescriptorBufferOffsets2EXT(Packet_vkCmdSetDescriptorBufferOffsets2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDescriptorBufferOffsets2EXT(packet->call_info, packet->commandBuffer, &(packet->pSetDescriptorBufferOffsetsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(packet->call_info, packet->commandBuffer, &(packet->pBindDescriptorBufferEmbeddedSamplersInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkFrameBoundaryANDROID(Packet_vkFrameBoundaryANDROID* packet)
{
    vulkan_replay_consumer_->Process_vkFrameBoundaryANDROID(packet->call_info, packet->device, packet->semaphore, packet->image);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDebugReportCallbackEXT(Packet_vkCreateDebugReportCallbackEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDebugReportCallbackEXT(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pCallback));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDebugReportCallbackEXT(Packet_vkDestroyDebugReportCallbackEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDebugReportCallbackEXT(packet->call_info, packet->instance, packet->callback, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkDebugReportMessageEXT(Packet_vkDebugReportMessageEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDebugReportMessageEXT(packet->call_info, packet->instance, packet->flags, packet->objectType, packet->object, packet->location, packet->messageCode, &(packet->pLayerPrefix), &(packet->pMessage));

    return;
}

void VulkanPreloadReplayer::Replay_vkDebugMarkerSetObjectTagEXT(Packet_vkDebugMarkerSetObjectTagEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDebugMarkerSetObjectTagEXT(packet->call_info, packet->return_value, packet->device, &(packet->pTagInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkDebugMarkerSetObjectNameEXT(Packet_vkDebugMarkerSetObjectNameEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDebugMarkerSetObjectNameEXT(packet->call_info, packet->return_value, packet->device, &(packet->pNameInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDebugMarkerBeginEXT(Packet_vkCmdDebugMarkerBeginEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDebugMarkerBeginEXT(packet->call_info, packet->commandBuffer, &(packet->pMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDebugMarkerEndEXT(Packet_vkCmdDebugMarkerEndEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDebugMarkerEndEXT(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDebugMarkerInsertEXT(Packet_vkCmdDebugMarkerInsertEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDebugMarkerInsertEXT(packet->call_info, packet->commandBuffer, &(packet->pMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindTransformFeedbackBuffersEXT(Packet_vkCmdBindTransformFeedbackBuffersEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindTransformFeedbackBuffersEXT(packet->call_info, packet->commandBuffer, packet->firstBinding, packet->bindingCount, &(packet->pBuffers), &(packet->pOffsets), &(packet->pSizes));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginTransformFeedbackEXT(Packet_vkCmdBeginTransformFeedbackEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginTransformFeedbackEXT(packet->call_info, packet->commandBuffer, packet->firstCounterBuffer, packet->counterBufferCount, &(packet->pCounterBuffers), &(packet->pCounterBufferOffsets));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndTransformFeedbackEXT(Packet_vkCmdEndTransformFeedbackEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndTransformFeedbackEXT(packet->call_info, packet->commandBuffer, packet->firstCounterBuffer, packet->counterBufferCount, &(packet->pCounterBuffers), &(packet->pCounterBufferOffsets));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginQueryIndexedEXT(Packet_vkCmdBeginQueryIndexedEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginQueryIndexedEXT(packet->call_info, packet->commandBuffer, packet->queryPool, packet->query, packet->flags, packet->index);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndQueryIndexedEXT(Packet_vkCmdEndQueryIndexedEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndQueryIndexedEXT(packet->call_info, packet->commandBuffer, packet->queryPool, packet->query, packet->index);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndirectByteCountEXT(Packet_vkCmdDrawIndirectByteCountEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndirectByteCountEXT(packet->call_info, packet->commandBuffer, packet->instanceCount, packet->firstInstance, packet->counterBuffer, packet->counterBufferOffset, packet->counterOffset, packet->vertexStride);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageViewHandleNVX(Packet_vkGetImageViewHandleNVX* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageViewHandleNVX(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageViewAddressNVX(Packet_vkGetImageViewAddressNVX* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageViewAddressNVX(packet->call_info, packet->return_value, packet->device, packet->imageView, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndirectCountAMD(Packet_vkCmdDrawIndirectCountAMD* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndirectCountAMD(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawIndexedIndirectCountAMD(Packet_vkCmdDrawIndexedIndirectCountAMD* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawIndexedIndirectCountAMD(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetShaderInfoAMD(Packet_vkGetShaderInfoAMD* packet)
{
    vulkan_replay_consumer_->Process_vkGetShaderInfoAMD(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->shaderStage, packet->infoType, &(packet->pInfoSize), &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateStreamDescriptorSurfaceGGP(Packet_vkCreateStreamDescriptorSurfaceGGP* packet)
{
    vulkan_replay_consumer_->Process_vkCreateStreamDescriptorSurfaceGGP(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(packet->call_info, packet->return_value, packet->physicalDevice, packet->format, packet->type, packet->tiling, packet->usage, packet->flags, packet->externalHandleType, &(packet->pExternalImageFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryWin32HandleNV(Packet_vkGetMemoryWin32HandleNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryWin32HandleNV(packet->call_info, packet->return_value, packet->device, packet->memory, packet->handleType, &(packet->pHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateViSurfaceNN(Packet_vkCreateViSurfaceNN* packet)
{
    vulkan_replay_consumer_->Process_vkCreateViSurfaceNN(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginConditionalRenderingEXT(Packet_vkCmdBeginConditionalRenderingEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginConditionalRenderingEXT(packet->call_info, packet->commandBuffer, &(packet->pConditionalRenderingBegin));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndConditionalRenderingEXT(Packet_vkCmdEndConditionalRenderingEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndConditionalRenderingEXT(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportWScalingNV(Packet_vkCmdSetViewportWScalingNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportWScalingNV(packet->call_info, packet->commandBuffer, packet->firstViewport, packet->viewportCount, &(packet->pViewportWScalings));

    return;
}

void VulkanPreloadReplayer::Replay_vkReleaseDisplayEXT(Packet_vkReleaseDisplayEXT* packet)
{
    vulkan_replay_consumer_->Process_vkReleaseDisplayEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->display);

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireXlibDisplayEXT(Packet_vkAcquireXlibDisplayEXT* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireXlibDisplayEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->dpy, packet->display);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRandROutputDisplayEXT(Packet_vkGetRandROutputDisplayEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetRandROutputDisplayEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->dpy, packet->rrOutput, &(packet->pDisplay));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfaceCapabilities2EXT(Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->surface, &(packet->pSurfaceCapabilities));

    return;
}

void VulkanPreloadReplayer::Replay_vkDisplayPowerControlEXT(Packet_vkDisplayPowerControlEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDisplayPowerControlEXT(packet->call_info, packet->return_value, packet->device, packet->display, &(packet->pDisplayPowerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkRegisterDeviceEventEXT(Packet_vkRegisterDeviceEventEXT* packet)
{
    vulkan_replay_consumer_->Process_vkRegisterDeviceEventEXT(packet->call_info, packet->return_value, packet->device, &(packet->pDeviceEventInfo), &(packet->pAllocator), &(packet->pFence));

    return;
}

void VulkanPreloadReplayer::Replay_vkRegisterDisplayEventEXT(Packet_vkRegisterDisplayEventEXT* packet)
{
    vulkan_replay_consumer_->Process_vkRegisterDisplayEventEXT(packet->call_info, packet->return_value, packet->device, packet->display, &(packet->pDisplayEventInfo), &(packet->pAllocator), &(packet->pFence));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSwapchainCounterEXT(Packet_vkGetSwapchainCounterEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetSwapchainCounterEXT(packet->call_info, packet->return_value, packet->device, packet->swapchain, packet->counter, &(packet->pCounterValue));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRefreshCycleDurationGOOGLE(Packet_vkGetRefreshCycleDurationGOOGLE* packet)
{
    vulkan_replay_consumer_->Process_vkGetRefreshCycleDurationGOOGLE(packet->call_info, packet->return_value, packet->device, packet->swapchain, &(packet->pDisplayTimingProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPastPresentationTimingGOOGLE(Packet_vkGetPastPresentationTimingGOOGLE* packet)
{
    vulkan_replay_consumer_->Process_vkGetPastPresentationTimingGOOGLE(packet->call_info, packet->return_value, packet->device, packet->swapchain, &(packet->pPresentationTimingCount), &(packet->pPresentationTimings));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDiscardRectangleEXT(Packet_vkCmdSetDiscardRectangleEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDiscardRectangleEXT(packet->call_info, packet->commandBuffer, packet->firstDiscardRectangle, packet->discardRectangleCount, &(packet->pDiscardRectangles));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDiscardRectangleEnableEXT(Packet_vkCmdSetDiscardRectangleEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDiscardRectangleEnableEXT(packet->call_info, packet->commandBuffer, packet->discardRectangleEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDiscardRectangleModeEXT(Packet_vkCmdSetDiscardRectangleModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDiscardRectangleModeEXT(packet->call_info, packet->commandBuffer, packet->discardRectangleMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkSetHdrMetadataEXT(Packet_vkSetHdrMetadataEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSetHdrMetadataEXT(packet->call_info, packet->device, packet->swapchainCount, &(packet->pSwapchains), &(packet->pMetadata));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateIOSSurfaceMVK(Packet_vkCreateIOSSurfaceMVK* packet)
{
    vulkan_replay_consumer_->Process_vkCreateIOSSurfaceMVK(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateMacOSSurfaceMVK(Packet_vkCreateMacOSSurfaceMVK* packet)
{
    vulkan_replay_consumer_->Process_vkCreateMacOSSurfaceMVK(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetDebugUtilsObjectNameEXT(Packet_vkSetDebugUtilsObjectNameEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSetDebugUtilsObjectNameEXT(packet->call_info, packet->return_value, packet->device, &(packet->pNameInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetDebugUtilsObjectTagEXT(Packet_vkSetDebugUtilsObjectTagEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSetDebugUtilsObjectTagEXT(packet->call_info, packet->return_value, packet->device, &(packet->pTagInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueBeginDebugUtilsLabelEXT(Packet_vkQueueBeginDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkQueueBeginDebugUtilsLabelEXT(packet->call_info, packet->queue, &(packet->pLabelInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueEndDebugUtilsLabelEXT(Packet_vkQueueEndDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkQueueEndDebugUtilsLabelEXT(packet->call_info, packet->queue);

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueInsertDebugUtilsLabelEXT(Packet_vkQueueInsertDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkQueueInsertDebugUtilsLabelEXT(packet->call_info, packet->queue, &(packet->pLabelInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBeginDebugUtilsLabelEXT(Packet_vkCmdBeginDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBeginDebugUtilsLabelEXT(packet->call_info, packet->commandBuffer, &(packet->pLabelInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdEndDebugUtilsLabelEXT(Packet_vkCmdEndDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdEndDebugUtilsLabelEXT(packet->call_info, packet->commandBuffer);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdInsertDebugUtilsLabelEXT(Packet_vkCmdInsertDebugUtilsLabelEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdInsertDebugUtilsLabelEXT(packet->call_info, packet->commandBuffer, &(packet->pLabelInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDebugUtilsMessengerEXT(Packet_vkCreateDebugUtilsMessengerEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDebugUtilsMessengerEXT(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pMessenger));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyDebugUtilsMessengerEXT(Packet_vkDestroyDebugUtilsMessengerEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyDebugUtilsMessengerEXT(packet->call_info, packet->instance, packet->messenger, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkSubmitDebugUtilsMessageEXT(Packet_vkSubmitDebugUtilsMessageEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSubmitDebugUtilsMessageEXT(packet->call_info, packet->instance, packet->messageSeverity, packet->messageTypes, &(packet->pCallbackData));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetAndroidHardwareBufferPropertiesANDROID(Packet_vkGetAndroidHardwareBufferPropertiesANDROID* packet)
{
    vulkan_replay_consumer_->Process_vkGetAndroidHardwareBufferPropertiesANDROID(packet->call_info, packet->return_value, packet->device, packet->buffer, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryAndroidHardwareBufferANDROID(Packet_vkGetMemoryAndroidHardwareBufferANDROID* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryAndroidHardwareBufferANDROID(packet->call_info, packet->return_value, packet->device, &(packet->pInfo), &(packet->pBuffer));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetSampleLocationsEXT(Packet_vkCmdSetSampleLocationsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetSampleLocationsEXT(packet->call_info, packet->commandBuffer, &(packet->pSampleLocationsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceMultisamplePropertiesEXT(Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(packet->call_info, packet->physicalDevice, packet->samples, &(packet->pMultisampleProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageDrmFormatModifierPropertiesEXT(Packet_vkGetImageDrmFormatModifierPropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageDrmFormatModifierPropertiesEXT(packet->call_info, packet->return_value, packet->device, packet->image, &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateValidationCacheEXT(Packet_vkCreateValidationCacheEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateValidationCacheEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pValidationCache));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyValidationCacheEXT(Packet_vkDestroyValidationCacheEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyValidationCacheEXT(packet->call_info, packet->device, packet->validationCache, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkMergeValidationCachesEXT(Packet_vkMergeValidationCachesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkMergeValidationCachesEXT(packet->call_info, packet->return_value, packet->device, packet->dstCache, packet->srcCacheCount, &(packet->pSrcCaches));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetValidationCacheDataEXT(Packet_vkGetValidationCacheDataEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetValidationCacheDataEXT(packet->call_info, packet->return_value, packet->device, packet->validationCache, &(packet->pDataSize), &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindShadingRateImageNV(Packet_vkCmdBindShadingRateImageNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindShadingRateImageNV(packet->call_info, packet->commandBuffer, packet->imageView, packet->imageLayout);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportShadingRatePaletteNV(Packet_vkCmdSetViewportShadingRatePaletteNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportShadingRatePaletteNV(packet->call_info, packet->commandBuffer, packet->firstViewport, packet->viewportCount, &(packet->pShadingRatePalettes));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoarseSampleOrderNV(Packet_vkCmdSetCoarseSampleOrderNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoarseSampleOrderNV(packet->call_info, packet->commandBuffer, packet->sampleOrderType, packet->customSampleOrderCount, &(packet->pCustomSampleOrders));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateAccelerationStructureNV(Packet_vkCreateAccelerationStructureNV* packet)
{
    vulkan_replay_consumer_->Process_vkCreateAccelerationStructureNV(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pAccelerationStructure));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyAccelerationStructureNV(Packet_vkDestroyAccelerationStructureNV* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyAccelerationStructureNV(packet->call_info, packet->device, packet->accelerationStructure, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetAccelerationStructureMemoryRequirementsNV(Packet_vkGetAccelerationStructureMemoryRequirementsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetAccelerationStructureMemoryRequirementsNV(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindAccelerationStructureMemoryNV(Packet_vkBindAccelerationStructureMemoryNV* packet)
{
    vulkan_replay_consumer_->Process_vkBindAccelerationStructureMemoryNV(packet->call_info, packet->return_value, packet->device, packet->bindInfoCount, &(packet->pBindInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBuildAccelerationStructureNV(Packet_vkCmdBuildAccelerationStructureNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBuildAccelerationStructureNV(packet->call_info, packet->commandBuffer, &(packet->pInfo), packet->instanceData, packet->instanceOffset, packet->update, packet->dst, packet->src, packet->scratch, packet->scratchOffset);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyAccelerationStructureNV(Packet_vkCmdCopyAccelerationStructureNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyAccelerationStructureNV(packet->call_info, packet->commandBuffer, packet->dst, packet->src, packet->mode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdTraceRaysNV(Packet_vkCmdTraceRaysNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdTraceRaysNV(packet->call_info, packet->commandBuffer, packet->raygenShaderBindingTableBuffer, packet->raygenShaderBindingOffset, packet->missShaderBindingTableBuffer, packet->missShaderBindingOffset, packet->missShaderBindingStride, packet->hitShaderBindingTableBuffer, packet->hitShaderBindingOffset, packet->hitShaderBindingStride, packet->callableShaderBindingTableBuffer, packet->callableShaderBindingOffset, packet->callableShaderBindingStride, packet->width, packet->height, packet->depth);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateRayTracingPipelinesNV(Packet_vkCreateRayTracingPipelinesNV* packet)
{
    vulkan_replay_consumer_->Process_vkCreateRayTracingPipelinesNV(packet->call_info, packet->return_value, packet->device, packet->pipelineCache, packet->createInfoCount, &(packet->pCreateInfos), &(packet->pAllocator), &(packet->pPipelines));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRayTracingShaderGroupHandlesKHR(Packet_vkGetRayTracingShaderGroupHandlesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetRayTracingShaderGroupHandlesKHR(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->firstGroup, packet->groupCount, packet->dataSize, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRayTracingShaderGroupHandlesNV(Packet_vkGetRayTracingShaderGroupHandlesNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetRayTracingShaderGroupHandlesNV(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->firstGroup, packet->groupCount, packet->dataSize, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetAccelerationStructureHandleNV(Packet_vkGetAccelerationStructureHandleNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetAccelerationStructureHandleNV(packet->call_info, packet->return_value, packet->device, packet->accelerationStructure, packet->dataSize, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteAccelerationStructuresPropertiesNV(Packet_vkCmdWriteAccelerationStructuresPropertiesNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteAccelerationStructuresPropertiesNV(packet->call_info, packet->commandBuffer, packet->accelerationStructureCount, &(packet->pAccelerationStructures), packet->queryType, packet->queryPool, packet->firstQuery);

    return;
}

void VulkanPreloadReplayer::Replay_vkCompileDeferredNV(Packet_vkCompileDeferredNV* packet)
{
    vulkan_replay_consumer_->Process_vkCompileDeferredNV(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->shader);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryHostPointerPropertiesEXT(Packet_vkGetMemoryHostPointerPropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryHostPointerPropertiesEXT(packet->call_info, packet->return_value, packet->device, packet->handleType, packet->pHostPointer, &(packet->pMemoryHostPointerProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteBufferMarkerAMD(Packet_vkCmdWriteBufferMarkerAMD* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteBufferMarkerAMD(packet->call_info, packet->commandBuffer, packet->pipelineStage, packet->dstBuffer, packet->dstOffset, packet->marker);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pTimeDomainCount), &(packet->pTimeDomains));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetCalibratedTimestampsEXT(Packet_vkGetCalibratedTimestampsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetCalibratedTimestampsEXT(packet->call_info, packet->return_value, packet->device, packet->timestampCount, &(packet->pTimestampInfos), &(packet->pTimestamps), &(packet->pMaxDeviation));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksNV(Packet_vkCmdDrawMeshTasksNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksNV(packet->call_info, packet->commandBuffer, packet->taskCount, packet->firstTask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksIndirectNV(Packet_vkCmdDrawMeshTasksIndirectNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksIndirectNV(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->drawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksIndirectCountNV(Packet_vkCmdDrawMeshTasksIndirectCountNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksIndirectCountNV(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetExclusiveScissorEnableNV(Packet_vkCmdSetExclusiveScissorEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetExclusiveScissorEnableNV(packet->call_info, packet->commandBuffer, packet->firstExclusiveScissor, packet->exclusiveScissorCount, &(packet->pExclusiveScissorEnables));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetExclusiveScissorNV(Packet_vkCmdSetExclusiveScissorNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetExclusiveScissorNV(packet->call_info, packet->commandBuffer, packet->firstExclusiveScissor, packet->exclusiveScissorCount, &(packet->pExclusiveScissors));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCheckpointNV(Packet_vkCmdSetCheckpointNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCheckpointNV(packet->call_info, packet->commandBuffer, packet->pCheckpointMarker);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetQueueCheckpointDataNV(Packet_vkGetQueueCheckpointDataNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetQueueCheckpointDataNV(packet->call_info, packet->queue, &(packet->pCheckpointDataCount), &(packet->pCheckpointData));

    return;
}

void VulkanPreloadReplayer::Replay_vkInitializePerformanceApiINTEL(Packet_vkInitializePerformanceApiINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkInitializePerformanceApiINTEL(packet->call_info, packet->return_value, packet->device, &(packet->pInitializeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkUninitializePerformanceApiINTEL(Packet_vkUninitializePerformanceApiINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkUninitializePerformanceApiINTEL(packet->call_info, packet->device);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPerformanceMarkerINTEL(Packet_vkCmdSetPerformanceMarkerINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPerformanceMarkerINTEL(packet->call_info, packet->return_value, packet->commandBuffer, &(packet->pMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPerformanceStreamMarkerINTEL(Packet_vkCmdSetPerformanceStreamMarkerINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPerformanceStreamMarkerINTEL(packet->call_info, packet->return_value, packet->commandBuffer, &(packet->pMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPerformanceOverrideINTEL(Packet_vkCmdSetPerformanceOverrideINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPerformanceOverrideINTEL(packet->call_info, packet->return_value, packet->commandBuffer, &(packet->pOverrideInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquirePerformanceConfigurationINTEL(Packet_vkAcquirePerformanceConfigurationINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkAcquirePerformanceConfigurationINTEL(packet->call_info, packet->return_value, packet->device, &(packet->pAcquireInfo), &(packet->pConfiguration));

    return;
}

void VulkanPreloadReplayer::Replay_vkReleasePerformanceConfigurationINTEL(Packet_vkReleasePerformanceConfigurationINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkReleasePerformanceConfigurationINTEL(packet->call_info, packet->return_value, packet->device, packet->configuration);

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueSetPerformanceConfigurationINTEL(Packet_vkQueueSetPerformanceConfigurationINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkQueueSetPerformanceConfigurationINTEL(packet->call_info, packet->return_value, packet->queue, packet->configuration);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPerformanceParameterINTEL(Packet_vkGetPerformanceParameterINTEL* packet)
{
    vulkan_replay_consumer_->Process_vkGetPerformanceParameterINTEL(packet->call_info, packet->return_value, packet->device, packet->parameter, &(packet->pValue));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetLocalDimmingAMD(Packet_vkSetLocalDimmingAMD* packet)
{
    vulkan_replay_consumer_->Process_vkSetLocalDimmingAMD(packet->call_info, packet->device, packet->swapChain, packet->localDimmingEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateImagePipeSurfaceFUCHSIA(Packet_vkCreateImagePipeSurfaceFUCHSIA* packet)
{
    vulkan_replay_consumer_->Process_vkCreateImagePipeSurfaceFUCHSIA(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateMetalSurfaceEXT(Packet_vkCreateMetalSurfaceEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateMetalSurfaceEXT(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetBufferDeviceAddressEXT(Packet_vkGetBufferDeviceAddressEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetBufferDeviceAddressEXT(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceToolPropertiesEXT(Packet_vkGetPhysicalDeviceToolPropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceToolPropertiesEXT(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pToolCount), &(packet->pToolProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pPropertyCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pCombinationCount), &(packet->pCombinations));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceSurfacePresentModes2EXT(Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pSurfaceInfo), &(packet->pPresentModeCount), &(packet->pPresentModes));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireFullScreenExclusiveModeEXT(Packet_vkAcquireFullScreenExclusiveModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireFullScreenExclusiveModeEXT(packet->call_info, packet->return_value, packet->device, packet->swapchain);

    return;
}

void VulkanPreloadReplayer::Replay_vkReleaseFullScreenExclusiveModeEXT(Packet_vkReleaseFullScreenExclusiveModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkReleaseFullScreenExclusiveModeEXT(packet->call_info, packet->return_value, packet->device, packet->swapchain);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceGroupSurfacePresentModes2EXT(Packet_vkGetDeviceGroupSurfacePresentModes2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceGroupSurfacePresentModes2EXT(packet->call_info, packet->return_value, packet->device, &(packet->pSurfaceInfo), &(packet->pModes));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateHeadlessSurfaceEXT(Packet_vkCreateHeadlessSurfaceEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateHeadlessSurfaceEXT(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLineStippleEXT(Packet_vkCmdSetLineStippleEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLineStippleEXT(packet->call_info, packet->commandBuffer, packet->lineStippleFactor, packet->lineStipplePattern);

    return;
}

void VulkanPreloadReplayer::Replay_vkResetQueryPoolEXT(Packet_vkResetQueryPoolEXT* packet)
{
    vulkan_replay_consumer_->Process_vkResetQueryPoolEXT(packet->call_info, packet->device, packet->queryPool, packet->firstQuery, packet->queryCount);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCullModeEXT(Packet_vkCmdSetCullModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCullModeEXT(packet->call_info, packet->commandBuffer, packet->cullMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetFrontFaceEXT(Packet_vkCmdSetFrontFaceEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetFrontFaceEXT(packet->call_info, packet->commandBuffer, packet->frontFace);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPrimitiveTopologyEXT(Packet_vkCmdSetPrimitiveTopologyEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPrimitiveTopologyEXT(packet->call_info, packet->commandBuffer, packet->primitiveTopology);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportWithCountEXT(Packet_vkCmdSetViewportWithCountEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportWithCountEXT(packet->call_info, packet->commandBuffer, packet->viewportCount, &(packet->pViewports));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetScissorWithCountEXT(Packet_vkCmdSetScissorWithCountEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetScissorWithCountEXT(packet->call_info, packet->commandBuffer, packet->scissorCount, &(packet->pScissors));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindVertexBuffers2EXT(Packet_vkCmdBindVertexBuffers2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindVertexBuffers2EXT(packet->call_info, packet->commandBuffer, packet->firstBinding, packet->bindingCount, &(packet->pBuffers), &(packet->pOffsets), &(packet->pSizes), &(packet->pStrides));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthTestEnableEXT(Packet_vkCmdSetDepthTestEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthTestEnableEXT(packet->call_info, packet->commandBuffer, packet->depthTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthWriteEnableEXT(Packet_vkCmdSetDepthWriteEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthWriteEnableEXT(packet->call_info, packet->commandBuffer, packet->depthWriteEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthCompareOpEXT(Packet_vkCmdSetDepthCompareOpEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthCompareOpEXT(packet->call_info, packet->commandBuffer, packet->depthCompareOp);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBoundsTestEnableEXT(Packet_vkCmdSetDepthBoundsTestEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBoundsTestEnableEXT(packet->call_info, packet->commandBuffer, packet->depthBoundsTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilTestEnableEXT(Packet_vkCmdSetStencilTestEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilTestEnableEXT(packet->call_info, packet->commandBuffer, packet->stencilTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetStencilOpEXT(Packet_vkCmdSetStencilOpEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetStencilOpEXT(packet->call_info, packet->commandBuffer, packet->faceMask, packet->failOp, packet->passOp, packet->depthFailOp, packet->compareOp);

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyMemoryToImageEXT(Packet_vkCopyMemoryToImageEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyMemoryToImageEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCopyMemoryToImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyImageToMemoryEXT(Packet_vkCopyImageToMemoryEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyImageToMemoryEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCopyImageToMemoryInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyImageToImageEXT(Packet_vkCopyImageToImageEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyImageToImageEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCopyImageToImageInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkTransitionImageLayoutEXT(Packet_vkTransitionImageLayoutEXT* packet)
{
    vulkan_replay_consumer_->Process_vkTransitionImageLayoutEXT(packet->call_info, packet->return_value, packet->device, packet->transitionCount, &(packet->pTransitions));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetImageSubresourceLayout2EXT(Packet_vkGetImageSubresourceLayout2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetImageSubresourceLayout2EXT(packet->call_info, packet->device, packet->image, &(packet->pSubresource), &(packet->pLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkReleaseSwapchainImagesEXT(Packet_vkReleaseSwapchainImagesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkReleaseSwapchainImagesEXT(packet->call_info, packet->return_value, packet->device, &(packet->pReleaseInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetGeneratedCommandsMemoryRequirementsNV(Packet_vkGetGeneratedCommandsMemoryRequirementsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetGeneratedCommandsMemoryRequirementsNV(packet->call_info, packet->device, &(packet->pInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdPreprocessGeneratedCommandsNV(Packet_vkCmdPreprocessGeneratedCommandsNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPreprocessGeneratedCommandsNV(packet->call_info, packet->commandBuffer, &(packet->pGeneratedCommandsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdExecuteGeneratedCommandsNV(Packet_vkCmdExecuteGeneratedCommandsNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdExecuteGeneratedCommandsNV(packet->call_info, packet->commandBuffer, packet->isPreprocessed, &(packet->pGeneratedCommandsInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindPipelineShaderGroupNV(Packet_vkCmdBindPipelineShaderGroupNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindPipelineShaderGroupNV(packet->call_info, packet->commandBuffer, packet->pipelineBindPoint, packet->pipeline, packet->groupIndex);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateIndirectCommandsLayoutNV(Packet_vkCreateIndirectCommandsLayoutNV* packet)
{
    vulkan_replay_consumer_->Process_vkCreateIndirectCommandsLayoutNV(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pIndirectCommandsLayout));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyIndirectCommandsLayoutNV(Packet_vkDestroyIndirectCommandsLayoutNV* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyIndirectCommandsLayoutNV(packet->call_info, packet->device, packet->indirectCommandsLayout, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBias2EXT(Packet_vkCmdSetDepthBias2EXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBias2EXT(packet->call_info, packet->commandBuffer, &(packet->pDepthBiasInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireDrmDisplayEXT(Packet_vkAcquireDrmDisplayEXT* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireDrmDisplayEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->drmFd, packet->display);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDrmDisplayEXT(Packet_vkGetDrmDisplayEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetDrmDisplayEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->drmFd, packet->connectorId, &(packet->display));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreatePrivateDataSlotEXT(Packet_vkCreatePrivateDataSlotEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreatePrivateDataSlotEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pPrivateDataSlot));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyPrivateDataSlotEXT(Packet_vkDestroyPrivateDataSlotEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyPrivateDataSlotEXT(packet->call_info, packet->device, packet->privateDataSlot, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetPrivateDataEXT(Packet_vkSetPrivateDataEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSetPrivateDataEXT(packet->call_info, packet->return_value, packet->device, packet->objectType, packet->objectHandle, packet->privateDataSlot, packet->data);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPrivateDataEXT(Packet_vkGetPrivateDataEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPrivateDataEXT(packet->call_info, packet->device, packet->objectType, packet->objectHandle, packet->privateDataSlot, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetFragmentShadingRateEnumNV(Packet_vkCmdSetFragmentShadingRateEnumNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetFragmentShadingRateEnumNV(packet->call_info, packet->commandBuffer, packet->shadingRate, &(packet->combinerOps));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceFaultInfoEXT(Packet_vkGetDeviceFaultInfoEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceFaultInfoEXT(packet->call_info, packet->return_value, packet->device, &(packet->pFaultCounts), &(packet->pFaultInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkAcquireWinrtDisplayNV(Packet_vkAcquireWinrtDisplayNV* packet)
{
    vulkan_replay_consumer_->Process_vkAcquireWinrtDisplayNV(packet->call_info, packet->return_value, packet->physicalDevice, packet->display);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetWinrtDisplayNV(Packet_vkGetWinrtDisplayNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetWinrtDisplayNV(packet->call_info, packet->return_value, packet->physicalDevice, packet->deviceRelativeId, &(packet->pDisplay));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateDirectFBSurfaceEXT(Packet_vkCreateDirectFBSurfaceEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateDirectFBSurfaceEXT(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->dfb);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetVertexInputEXT(Packet_vkCmdSetVertexInputEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetVertexInputEXT(packet->call_info, packet->commandBuffer, packet->vertexBindingDescriptionCount, &(packet->pVertexBindingDescriptions), packet->vertexAttributeDescriptionCount, &(packet->pVertexAttributeDescriptions));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryZirconHandleFUCHSIA(Packet_vkGetMemoryZirconHandleFUCHSIA* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryZirconHandleFUCHSIA(packet->call_info, packet->return_value, packet->device, &(packet->pGetZirconHandleInfo), &(packet->pZirconHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryZirconHandlePropertiesFUCHSIA(Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(packet->call_info, packet->return_value, packet->device, packet->handleType, packet->zirconHandle, &(packet->pMemoryZirconHandleProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkImportSemaphoreZirconHandleFUCHSIA(Packet_vkImportSemaphoreZirconHandleFUCHSIA* packet)
{
    vulkan_replay_consumer_->Process_vkImportSemaphoreZirconHandleFUCHSIA(packet->call_info, packet->return_value, packet->device, &(packet->pImportSemaphoreZirconHandleInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetSemaphoreZirconHandleFUCHSIA(Packet_vkGetSemaphoreZirconHandleFUCHSIA* packet)
{
    vulkan_replay_consumer_->Process_vkGetSemaphoreZirconHandleFUCHSIA(packet->call_info, packet->return_value, packet->device, &(packet->pGetZirconHandleInfo), &(packet->pZirconHandle));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindInvocationMaskHUAWEI(Packet_vkCmdBindInvocationMaskHUAWEI* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindInvocationMaskHUAWEI(packet->call_info, packet->commandBuffer, packet->imageView, packet->imageLayout);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMemoryRemoteAddressNV(Packet_vkGetMemoryRemoteAddressNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetMemoryRemoteAddressNV(packet->call_info, packet->return_value, packet->device, &(packet->pMemoryGetRemoteAddressInfo), &(packet->pAddress));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPatchControlPointsEXT(Packet_vkCmdSetPatchControlPointsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPatchControlPointsEXT(packet->call_info, packet->commandBuffer, packet->patchControlPoints);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRasterizerDiscardEnableEXT(Packet_vkCmdSetRasterizerDiscardEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRasterizerDiscardEnableEXT(packet->call_info, packet->commandBuffer, packet->rasterizerDiscardEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthBiasEnableEXT(Packet_vkCmdSetDepthBiasEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthBiasEnableEXT(packet->call_info, packet->commandBuffer, packet->depthBiasEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLogicOpEXT(Packet_vkCmdSetLogicOpEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLogicOpEXT(packet->call_info, packet->commandBuffer, packet->logicOp);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPrimitiveRestartEnableEXT(Packet_vkCmdSetPrimitiveRestartEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPrimitiveRestartEnableEXT(packet->call_info, packet->commandBuffer, packet->primitiveRestartEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateScreenSurfaceQNX(Packet_vkCreateScreenSurfaceQNX* packet)
{
    vulkan_replay_consumer_->Process_vkCreateScreenSurfaceQNX(packet->call_info, packet->return_value, packet->instance, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSurface));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceScreenPresentationSupportQNX(Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(packet->call_info, packet->return_value, packet->physicalDevice, packet->queueFamilyIndex, packet->window);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetColorWriteEnableEXT(Packet_vkCmdSetColorWriteEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetColorWriteEnableEXT(packet->call_info, packet->commandBuffer, packet->attachmentCount, &(packet->pColorWriteEnables));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMultiEXT(Packet_vkCmdDrawMultiEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMultiEXT(packet->call_info, packet->commandBuffer, packet->drawCount, &(packet->pVertexInfo), packet->instanceCount, packet->firstInstance, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMultiIndexedEXT(Packet_vkCmdDrawMultiIndexedEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMultiIndexedEXT(packet->call_info, packet->commandBuffer, packet->drawCount, &(packet->pIndexInfo), packet->instanceCount, packet->firstInstance, packet->stride, &(packet->pVertexOffset));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateMicromapEXT(Packet_vkCreateMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateMicromapEXT(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pMicromap));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyMicromapEXT(Packet_vkDestroyMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyMicromapEXT(packet->call_info, packet->device, packet->micromap, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBuildMicromapsEXT(Packet_vkCmdBuildMicromapsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBuildMicromapsEXT(packet->call_info, packet->commandBuffer, packet->infoCount, &(packet->pInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkBuildMicromapsEXT(Packet_vkBuildMicromapsEXT* packet)
{
    vulkan_replay_consumer_->Process_vkBuildMicromapsEXT(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, packet->infoCount, &(packet->pInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyMicromapEXT(Packet_vkCopyMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyMicromapEXT(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyMicromapToMemoryEXT(Packet_vkCopyMicromapToMemoryEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyMicromapToMemoryEXT(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyMemoryToMicromapEXT(Packet_vkCopyMemoryToMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCopyMemoryToMicromapEXT(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkWriteMicromapsPropertiesEXT(Packet_vkWriteMicromapsPropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkWriteMicromapsPropertiesEXT(packet->call_info, packet->return_value, packet->device, packet->micromapCount, &(packet->pMicromaps), packet->queryType, packet->dataSize, &(packet->pData), packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyMicromapEXT(Packet_vkCmdCopyMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyMicromapEXT(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyMicromapToMemoryEXT(Packet_vkCmdCopyMicromapToMemoryEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyMicromapToMemoryEXT(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyMemoryToMicromapEXT(Packet_vkCmdCopyMemoryToMicromapEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyMemoryToMicromapEXT(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteMicromapsPropertiesEXT(Packet_vkCmdWriteMicromapsPropertiesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteMicromapsPropertiesEXT(packet->call_info, packet->commandBuffer, packet->micromapCount, &(packet->pMicromaps), packet->queryType, packet->queryPool, packet->firstQuery);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceMicromapCompatibilityEXT(Packet_vkGetDeviceMicromapCompatibilityEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceMicromapCompatibilityEXT(packet->call_info, packet->device, &(packet->pVersionInfo), &(packet->pCompatibility));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetMicromapBuildSizesEXT(Packet_vkGetMicromapBuildSizesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetMicromapBuildSizesEXT(packet->call_info, packet->device, packet->buildType, &(packet->pBuildInfo), &(packet->pSizeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawClusterHUAWEI(Packet_vkCmdDrawClusterHUAWEI* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawClusterHUAWEI(packet->call_info, packet->commandBuffer, packet->groupCountX, packet->groupCountY, packet->groupCountZ);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawClusterIndirectHUAWEI(Packet_vkCmdDrawClusterIndirectHUAWEI* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawClusterIndirectHUAWEI(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset);

    return;
}

void VulkanPreloadReplayer::Replay_vkSetDeviceMemoryPriorityEXT(Packet_vkSetDeviceMemoryPriorityEXT* packet)
{
    vulkan_replay_consumer_->Process_vkSetDeviceMemoryPriorityEXT(packet->call_info, packet->device, packet->memory, packet->priority);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDescriptorSetLayoutHostMappingInfoVALVE(Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE* packet)
{
    vulkan_replay_consumer_->Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(packet->call_info, packet->device, &(packet->pBindingReference), &(packet->pHostMapping));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDescriptorSetHostMappingVALVE(Packet_vkGetDescriptorSetHostMappingVALVE* packet)
{
    vulkan_replay_consumer_->Process_vkGetDescriptorSetHostMappingVALVE(packet->call_info, packet->device, packet->descriptorSet, &(packet->ppData));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineIndirectMemoryRequirementsNV(Packet_vkGetPipelineIndirectMemoryRequirementsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineIndirectMemoryRequirementsNV(packet->call_info, packet->device, &(packet->pCreateInfo), &(packet->pMemoryRequirements));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdUpdatePipelineIndirectBufferNV(Packet_vkCmdUpdatePipelineIndirectBufferNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdUpdatePipelineIndirectBufferNV(packet->call_info, packet->commandBuffer, packet->pipelineBindPoint, packet->pipeline);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPipelineIndirectDeviceAddressNV(Packet_vkGetPipelineIndirectDeviceAddressNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPipelineIndirectDeviceAddressNV(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthClampEnableEXT(Packet_vkCmdSetDepthClampEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthClampEnableEXT(packet->call_info, packet->commandBuffer, packet->depthClampEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetPolygonModeEXT(Packet_vkCmdSetPolygonModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetPolygonModeEXT(packet->call_info, packet->commandBuffer, packet->polygonMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRasterizationSamplesEXT(Packet_vkCmdSetRasterizationSamplesEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRasterizationSamplesEXT(packet->call_info, packet->commandBuffer, packet->rasterizationSamples);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetSampleMaskEXT(Packet_vkCmdSetSampleMaskEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetSampleMaskEXT(packet->call_info, packet->commandBuffer, packet->samples, &(packet->pSampleMask));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetAlphaToCoverageEnableEXT(Packet_vkCmdSetAlphaToCoverageEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetAlphaToCoverageEnableEXT(packet->call_info, packet->commandBuffer, packet->alphaToCoverageEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetAlphaToOneEnableEXT(Packet_vkCmdSetAlphaToOneEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetAlphaToOneEnableEXT(packet->call_info, packet->commandBuffer, packet->alphaToOneEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLogicOpEnableEXT(Packet_vkCmdSetLogicOpEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLogicOpEnableEXT(packet->call_info, packet->commandBuffer, packet->logicOpEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetColorBlendEnableEXT(Packet_vkCmdSetColorBlendEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetColorBlendEnableEXT(packet->call_info, packet->commandBuffer, packet->firstAttachment, packet->attachmentCount, &(packet->pColorBlendEnables));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetColorBlendEquationEXT(Packet_vkCmdSetColorBlendEquationEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetColorBlendEquationEXT(packet->call_info, packet->commandBuffer, packet->firstAttachment, packet->attachmentCount, &(packet->pColorBlendEquations));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetColorWriteMaskEXT(Packet_vkCmdSetColorWriteMaskEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetColorWriteMaskEXT(packet->call_info, packet->commandBuffer, packet->firstAttachment, packet->attachmentCount, &(packet->pColorWriteMasks));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetTessellationDomainOriginEXT(Packet_vkCmdSetTessellationDomainOriginEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetTessellationDomainOriginEXT(packet->call_info, packet->commandBuffer, packet->domainOrigin);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRasterizationStreamEXT(Packet_vkCmdSetRasterizationStreamEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRasterizationStreamEXT(packet->call_info, packet->commandBuffer, packet->rasterizationStream);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetConservativeRasterizationModeEXT(Packet_vkCmdSetConservativeRasterizationModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetConservativeRasterizationModeEXT(packet->call_info, packet->commandBuffer, packet->conservativeRasterizationMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetExtraPrimitiveOverestimationSizeEXT(Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(packet->call_info, packet->commandBuffer, packet->extraPrimitiveOverestimationSize);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthClipEnableEXT(Packet_vkCmdSetDepthClipEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthClipEnableEXT(packet->call_info, packet->commandBuffer, packet->depthClipEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetSampleLocationsEnableEXT(Packet_vkCmdSetSampleLocationsEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetSampleLocationsEnableEXT(packet->call_info, packet->commandBuffer, packet->sampleLocationsEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetColorBlendAdvancedEXT(Packet_vkCmdSetColorBlendAdvancedEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetColorBlendAdvancedEXT(packet->call_info, packet->commandBuffer, packet->firstAttachment, packet->attachmentCount, &(packet->pColorBlendAdvanced));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetProvokingVertexModeEXT(Packet_vkCmdSetProvokingVertexModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetProvokingVertexModeEXT(packet->call_info, packet->commandBuffer, packet->provokingVertexMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLineRasterizationModeEXT(Packet_vkCmdSetLineRasterizationModeEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLineRasterizationModeEXT(packet->call_info, packet->commandBuffer, packet->lineRasterizationMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetLineStippleEnableEXT(Packet_vkCmdSetLineStippleEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetLineStippleEnableEXT(packet->call_info, packet->commandBuffer, packet->stippledLineEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetDepthClipNegativeOneToOneEXT(Packet_vkCmdSetDepthClipNegativeOneToOneEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetDepthClipNegativeOneToOneEXT(packet->call_info, packet->commandBuffer, packet->negativeOneToOne);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportWScalingEnableNV(Packet_vkCmdSetViewportWScalingEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportWScalingEnableNV(packet->call_info, packet->commandBuffer, packet->viewportWScalingEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetViewportSwizzleNV(Packet_vkCmdSetViewportSwizzleNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetViewportSwizzleNV(packet->call_info, packet->commandBuffer, packet->firstViewport, packet->viewportCount, &(packet->pViewportSwizzles));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageToColorEnableNV(Packet_vkCmdSetCoverageToColorEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageToColorEnableNV(packet->call_info, packet->commandBuffer, packet->coverageToColorEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageToColorLocationNV(Packet_vkCmdSetCoverageToColorLocationNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageToColorLocationNV(packet->call_info, packet->commandBuffer, packet->coverageToColorLocation);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageModulationModeNV(Packet_vkCmdSetCoverageModulationModeNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageModulationModeNV(packet->call_info, packet->commandBuffer, packet->coverageModulationMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageModulationTableEnableNV(Packet_vkCmdSetCoverageModulationTableEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageModulationTableEnableNV(packet->call_info, packet->commandBuffer, packet->coverageModulationTableEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageModulationTableNV(Packet_vkCmdSetCoverageModulationTableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageModulationTableNV(packet->call_info, packet->commandBuffer, packet->coverageModulationTableCount, &(packet->pCoverageModulationTable));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetShadingRateImageEnableNV(Packet_vkCmdSetShadingRateImageEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetShadingRateImageEnableNV(packet->call_info, packet->commandBuffer, packet->shadingRateImageEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRepresentativeFragmentTestEnableNV(Packet_vkCmdSetRepresentativeFragmentTestEnableNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRepresentativeFragmentTestEnableNV(packet->call_info, packet->commandBuffer, packet->representativeFragmentTestEnable);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetCoverageReductionModeNV(Packet_vkCmdSetCoverageReductionModeNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetCoverageReductionModeNV(packet->call_info, packet->commandBuffer, packet->coverageReductionMode);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetShaderModuleIdentifierEXT(Packet_vkGetShaderModuleIdentifierEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetShaderModuleIdentifierEXT(packet->call_info, packet->device, packet->shaderModule, &(packet->pIdentifier));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetShaderModuleCreateInfoIdentifierEXT(Packet_vkGetShaderModuleCreateInfoIdentifierEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetShaderModuleCreateInfoIdentifierEXT(packet->call_info, packet->device, &(packet->pCreateInfo), &(packet->pIdentifier));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(packet->call_info, packet->return_value, packet->physicalDevice, &(packet->pOpticalFlowImageFormatInfo), &(packet->pFormatCount), &(packet->pImageFormatProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateOpticalFlowSessionNV(Packet_vkCreateOpticalFlowSessionNV* packet)
{
    vulkan_replay_consumer_->Process_vkCreateOpticalFlowSessionNV(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pSession));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyOpticalFlowSessionNV(Packet_vkDestroyOpticalFlowSessionNV* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyOpticalFlowSessionNV(packet->call_info, packet->device, packet->session, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkBindOpticalFlowSessionImageNV(Packet_vkBindOpticalFlowSessionImageNV* packet)
{
    vulkan_replay_consumer_->Process_vkBindOpticalFlowSessionImageNV(packet->call_info, packet->return_value, packet->device, packet->session, packet->bindingPoint, packet->view, packet->layout);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdOpticalFlowExecuteNV(Packet_vkCmdOpticalFlowExecuteNV* packet)
{
    vulkan_replay_consumer_->Process_vkCmdOpticalFlowExecuteNV(packet->call_info, packet->commandBuffer, packet->session, &(packet->pExecuteInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateShadersEXT(Packet_vkCreateShadersEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCreateShadersEXT(packet->call_info, packet->return_value, packet->device, packet->createInfoCount, &(packet->pCreateInfos), &(packet->pAllocator), &(packet->pShaders));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyShaderEXT(Packet_vkDestroyShaderEXT* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyShaderEXT(packet->call_info, packet->device, packet->shader, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetShaderBinaryDataEXT(Packet_vkGetShaderBinaryDataEXT* packet)
{
    vulkan_replay_consumer_->Process_vkGetShaderBinaryDataEXT(packet->call_info, packet->return_value, packet->device, packet->shader, &(packet->pDataSize), &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBindShadersEXT(Packet_vkCmdBindShadersEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBindShadersEXT(packet->call_info, packet->commandBuffer, packet->stageCount, &(packet->pStages), &(packet->pShaders));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetFramebufferTilePropertiesQCOM(Packet_vkGetFramebufferTilePropertiesQCOM* packet)
{
    vulkan_replay_consumer_->Process_vkGetFramebufferTilePropertiesQCOM(packet->call_info, packet->return_value, packet->device, packet->framebuffer, &(packet->pPropertiesCount), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDynamicRenderingTilePropertiesQCOM(Packet_vkGetDynamicRenderingTilePropertiesQCOM* packet)
{
    vulkan_replay_consumer_->Process_vkGetDynamicRenderingTilePropertiesQCOM(packet->call_info, packet->return_value, packet->device, &(packet->pRenderingInfo), &(packet->pProperties));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetLatencySleepModeNV(Packet_vkSetLatencySleepModeNV* packet)
{
    vulkan_replay_consumer_->Process_vkSetLatencySleepModeNV(packet->call_info, packet->return_value, packet->device, packet->swapchain, &(packet->pSleepModeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkLatencySleepNV(Packet_vkLatencySleepNV* packet)
{
    vulkan_replay_consumer_->Process_vkLatencySleepNV(packet->call_info, packet->return_value, packet->device, packet->swapchain, &(packet->pSleepInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkSetLatencyMarkerNV(Packet_vkSetLatencyMarkerNV* packet)
{
    vulkan_replay_consumer_->Process_vkSetLatencyMarkerNV(packet->call_info, packet->device, packet->swapchain, &(packet->pLatencyMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetLatencyTimingsNV(Packet_vkGetLatencyTimingsNV* packet)
{
    vulkan_replay_consumer_->Process_vkGetLatencyTimingsNV(packet->call_info, packet->device, packet->swapchain, &(packet->pLatencyMarkerInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkQueueNotifyOutOfBandNV(Packet_vkQueueNotifyOutOfBandNV* packet)
{
    vulkan_replay_consumer_->Process_vkQueueNotifyOutOfBandNV(packet->call_info, packet->queue, &(packet->pQueueTypeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetAttachmentFeedbackLoopEnableEXT(Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(packet->call_info, packet->commandBuffer, packet->aspectMask);

    return;
}

void VulkanPreloadReplayer::Replay_vkCreateAccelerationStructureKHR(Packet_vkCreateAccelerationStructureKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateAccelerationStructureKHR(packet->call_info, packet->return_value, packet->device, &(packet->pCreateInfo), &(packet->pAllocator), &(packet->pAccelerationStructure));

    return;
}

void VulkanPreloadReplayer::Replay_vkDestroyAccelerationStructureKHR(Packet_vkDestroyAccelerationStructureKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDestroyAccelerationStructureKHR(packet->call_info, packet->device, packet->accelerationStructure, &(packet->pAllocator));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBuildAccelerationStructuresKHR(Packet_vkCmdBuildAccelerationStructuresKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBuildAccelerationStructuresKHR(packet->call_info, packet->commandBuffer, packet->infoCount, &(packet->pInfos), &(packet->ppBuildRangeInfos));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdBuildAccelerationStructuresIndirectKHR(Packet_vkCmdBuildAccelerationStructuresIndirectKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdBuildAccelerationStructuresIndirectKHR(packet->call_info, packet->commandBuffer, packet->infoCount, &(packet->pInfos), &(packet->pIndirectDeviceAddresses), &(packet->pIndirectStrides), &(packet->ppMaxPrimitiveCounts));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyAccelerationStructureToMemoryKHR(Packet_vkCopyAccelerationStructureToMemoryKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCopyAccelerationStructureToMemoryKHR(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCopyMemoryToAccelerationStructureKHR(Packet_vkCopyMemoryToAccelerationStructureKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCopyMemoryToAccelerationStructureKHR(packet->call_info, packet->return_value, packet->device, packet->deferredOperation, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkWriteAccelerationStructuresPropertiesKHR(Packet_vkWriteAccelerationStructuresPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkWriteAccelerationStructuresPropertiesKHR(packet->call_info, packet->return_value, packet->device, packet->accelerationStructureCount, &(packet->pAccelerationStructures), packet->queryType, packet->dataSize, &(packet->pData), packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyAccelerationStructureKHR(Packet_vkCmdCopyAccelerationStructureKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyAccelerationStructureKHR(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyAccelerationStructureToMemoryKHR(Packet_vkCmdCopyAccelerationStructureToMemoryKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyAccelerationStructureToMemoryKHR(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdCopyMemoryToAccelerationStructureKHR(Packet_vkCmdCopyMemoryToAccelerationStructureKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdCopyMemoryToAccelerationStructureKHR(packet->call_info, packet->commandBuffer, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetAccelerationStructureDeviceAddressKHR(Packet_vkGetAccelerationStructureDeviceAddressKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetAccelerationStructureDeviceAddressKHR(packet->call_info, packet->return_value, packet->device, &(packet->pInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdWriteAccelerationStructuresPropertiesKHR(Packet_vkCmdWriteAccelerationStructuresPropertiesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdWriteAccelerationStructuresPropertiesKHR(packet->call_info, packet->commandBuffer, packet->accelerationStructureCount, &(packet->pAccelerationStructures), packet->queryType, packet->queryPool, packet->firstQuery);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetDeviceAccelerationStructureCompatibilityKHR(Packet_vkGetDeviceAccelerationStructureCompatibilityKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetDeviceAccelerationStructureCompatibilityKHR(packet->call_info, packet->device, &(packet->pVersionInfo), &(packet->pCompatibility));

    return;
}

void VulkanPreloadReplayer::Replay_vkGetAccelerationStructureBuildSizesKHR(Packet_vkGetAccelerationStructureBuildSizesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetAccelerationStructureBuildSizesKHR(packet->call_info, packet->device, packet->buildType, &(packet->pBuildInfo), &(packet->pMaxPrimitiveCounts), &(packet->pSizeInfo));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdTraceRaysKHR(Packet_vkCmdTraceRaysKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdTraceRaysKHR(packet->call_info, packet->commandBuffer, &(packet->pRaygenShaderBindingTable), &(packet->pMissShaderBindingTable), &(packet->pHitShaderBindingTable), &(packet->pCallableShaderBindingTable), packet->width, packet->height, packet->depth);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->firstGroup, packet->groupCount, packet->dataSize, &(packet->pData));

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdTraceRaysIndirectKHR(Packet_vkCmdTraceRaysIndirectKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdTraceRaysIndirectKHR(packet->call_info, packet->commandBuffer, &(packet->pRaygenShaderBindingTable), &(packet->pMissShaderBindingTable), &(packet->pHitShaderBindingTable), &(packet->pCallableShaderBindingTable), packet->indirectDeviceAddress);

    return;
}

void VulkanPreloadReplayer::Replay_vkGetRayTracingShaderGroupStackSizeKHR(Packet_vkGetRayTracingShaderGroupStackSizeKHR* packet)
{
    vulkan_replay_consumer_->Process_vkGetRayTracingShaderGroupStackSizeKHR(packet->call_info, packet->return_value, packet->device, packet->pipeline, packet->group, packet->groupShader);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdSetRayTracingPipelineStackSizeKHR(Packet_vkCmdSetRayTracingPipelineStackSizeKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdSetRayTracingPipelineStackSizeKHR(packet->call_info, packet->commandBuffer, packet->pipelineStackSize);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksEXT(Packet_vkCmdDrawMeshTasksEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksEXT(packet->call_info, packet->commandBuffer, packet->groupCountX, packet->groupCountY, packet->groupCountZ);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksIndirectEXT(Packet_vkCmdDrawMeshTasksIndirectEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksIndirectEXT(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->drawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::Replay_vkCmdDrawMeshTasksIndirectCountEXT(Packet_vkCmdDrawMeshTasksIndirectCountEXT* packet)
{
    vulkan_replay_consumer_->Process_vkCmdDrawMeshTasksIndirectCountEXT(packet->call_info, packet->commandBuffer, packet->buffer, packet->offset, packet->countBuffer, packet->countBufferOffset, packet->maxDrawCount, packet->stride);

    return;
}

void VulkanPreloadReplayer::ReplayFunctionCall(format::PacketCallId& packet_call_id, void* packet)
{
    switch(packet_call_id)
    {
    default:
        VulkanPreloadReplayerBase::ReplayFunctionCall(packet_call_id, packet);
        break;

    case format::PacketCallId::PacketCall_vkCreateInstance:
        Replay_vkCreateInstance(reinterpret_cast<Packet_vkCreateInstance*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyInstance:
        Replay_vkDestroyInstance(reinterpret_cast<Packet_vkDestroyInstance*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkEnumeratePhysicalDevices:
        Replay_vkEnumeratePhysicalDevices(reinterpret_cast<Packet_vkEnumeratePhysicalDevices*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFeatures:
        Replay_vkGetPhysicalDeviceFeatures(reinterpret_cast<Packet_vkGetPhysicalDeviceFeatures*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFormatProperties:
        Replay_vkGetPhysicalDeviceFormatProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceFormatProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceImageFormatProperties:
        Replay_vkGetPhysicalDeviceImageFormatProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceImageFormatProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceProperties:
        Replay_vkGetPhysicalDeviceProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties:
        Replay_vkGetPhysicalDeviceQueueFamilyProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceQueueFamilyProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceMemoryProperties:
        Replay_vkGetPhysicalDeviceMemoryProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceMemoryProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDevice:
        Replay_vkCreateDevice(reinterpret_cast<Packet_vkCreateDevice*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDevice:
        Replay_vkDestroyDevice(reinterpret_cast<Packet_vkDestroyDevice*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceQueue:
        Replay_vkGetDeviceQueue(reinterpret_cast<Packet_vkGetDeviceQueue*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueSubmit:
        Replay_vkQueueSubmit(reinterpret_cast<Packet_vkQueueSubmit*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueWaitIdle:
        Replay_vkQueueWaitIdle(reinterpret_cast<Packet_vkQueueWaitIdle*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDeviceWaitIdle:
        Replay_vkDeviceWaitIdle(reinterpret_cast<Packet_vkDeviceWaitIdle*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAllocateMemory:
        Replay_vkAllocateMemory(reinterpret_cast<Packet_vkAllocateMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkFreeMemory:
        Replay_vkFreeMemory(reinterpret_cast<Packet_vkFreeMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkMapMemory:
        Replay_vkMapMemory(reinterpret_cast<Packet_vkMapMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkUnmapMemory:
        Replay_vkUnmapMemory(reinterpret_cast<Packet_vkUnmapMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkFlushMappedMemoryRanges:
        Replay_vkFlushMappedMemoryRanges(reinterpret_cast<Packet_vkFlushMappedMemoryRanges*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkInvalidateMappedMemoryRanges:
        Replay_vkInvalidateMappedMemoryRanges(reinterpret_cast<Packet_vkInvalidateMappedMemoryRanges*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceMemoryCommitment:
        Replay_vkGetDeviceMemoryCommitment(reinterpret_cast<Packet_vkGetDeviceMemoryCommitment*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindBufferMemory:
        Replay_vkBindBufferMemory(reinterpret_cast<Packet_vkBindBufferMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindImageMemory:
        Replay_vkBindImageMemory(reinterpret_cast<Packet_vkBindImageMemory*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferMemoryRequirements:
        Replay_vkGetBufferMemoryRequirements(reinterpret_cast<Packet_vkGetBufferMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageMemoryRequirements:
        Replay_vkGetImageMemoryRequirements(reinterpret_cast<Packet_vkGetImageMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSparseMemoryRequirements:
        Replay_vkGetImageSparseMemoryRequirements(reinterpret_cast<Packet_vkGetImageSparseMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties:
        Replay_vkGetPhysicalDeviceSparseImageFormatProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceSparseImageFormatProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueBindSparse:
        Replay_vkQueueBindSparse(reinterpret_cast<Packet_vkQueueBindSparse*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateFence:
        Replay_vkCreateFence(reinterpret_cast<Packet_vkCreateFence*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyFence:
        Replay_vkDestroyFence(reinterpret_cast<Packet_vkDestroyFence*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetFences:
        Replay_vkResetFences(reinterpret_cast<Packet_vkResetFences*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetFenceStatus:
        Replay_vkGetFenceStatus(reinterpret_cast<Packet_vkGetFenceStatus*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWaitForFences:
        Replay_vkWaitForFences(reinterpret_cast<Packet_vkWaitForFences*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSemaphore:
        Replay_vkCreateSemaphore(reinterpret_cast<Packet_vkCreateSemaphore*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySemaphore:
        Replay_vkDestroySemaphore(reinterpret_cast<Packet_vkDestroySemaphore*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateEvent:
        Replay_vkCreateEvent(reinterpret_cast<Packet_vkCreateEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyEvent:
        Replay_vkDestroyEvent(reinterpret_cast<Packet_vkDestroyEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetEventStatus:
        Replay_vkGetEventStatus(reinterpret_cast<Packet_vkGetEventStatus*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetEvent:
        Replay_vkSetEvent(reinterpret_cast<Packet_vkSetEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetEvent:
        Replay_vkResetEvent(reinterpret_cast<Packet_vkResetEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateQueryPool:
        Replay_vkCreateQueryPool(reinterpret_cast<Packet_vkCreateQueryPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyQueryPool:
        Replay_vkDestroyQueryPool(reinterpret_cast<Packet_vkDestroyQueryPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetQueryPoolResults:
        Replay_vkGetQueryPoolResults(reinterpret_cast<Packet_vkGetQueryPoolResults*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateBuffer:
        Replay_vkCreateBuffer(reinterpret_cast<Packet_vkCreateBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyBuffer:
        Replay_vkDestroyBuffer(reinterpret_cast<Packet_vkDestroyBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateBufferView:
        Replay_vkCreateBufferView(reinterpret_cast<Packet_vkCreateBufferView*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyBufferView:
        Replay_vkDestroyBufferView(reinterpret_cast<Packet_vkDestroyBufferView*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateImage:
        Replay_vkCreateImage(reinterpret_cast<Packet_vkCreateImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyImage:
        Replay_vkDestroyImage(reinterpret_cast<Packet_vkDestroyImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSubresourceLayout:
        Replay_vkGetImageSubresourceLayout(reinterpret_cast<Packet_vkGetImageSubresourceLayout*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateImageView:
        Replay_vkCreateImageView(reinterpret_cast<Packet_vkCreateImageView*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyImageView:
        Replay_vkDestroyImageView(reinterpret_cast<Packet_vkDestroyImageView*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateShaderModule:
        Replay_vkCreateShaderModule(reinterpret_cast<Packet_vkCreateShaderModule*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyShaderModule:
        Replay_vkDestroyShaderModule(reinterpret_cast<Packet_vkDestroyShaderModule*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreatePipelineCache:
        Replay_vkCreatePipelineCache(reinterpret_cast<Packet_vkCreatePipelineCache*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyPipelineCache:
        Replay_vkDestroyPipelineCache(reinterpret_cast<Packet_vkDestroyPipelineCache*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineCacheData:
        Replay_vkGetPipelineCacheData(reinterpret_cast<Packet_vkGetPipelineCacheData*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkMergePipelineCaches:
        Replay_vkMergePipelineCaches(reinterpret_cast<Packet_vkMergePipelineCaches*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateGraphicsPipelines:
        Replay_vkCreateGraphicsPipelines(reinterpret_cast<Packet_vkCreateGraphicsPipelines*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateComputePipelines:
        Replay_vkCreateComputePipelines(reinterpret_cast<Packet_vkCreateComputePipelines*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyPipeline:
        Replay_vkDestroyPipeline(reinterpret_cast<Packet_vkDestroyPipeline*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreatePipelineLayout:
        Replay_vkCreatePipelineLayout(reinterpret_cast<Packet_vkCreatePipelineLayout*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyPipelineLayout:
        Replay_vkDestroyPipelineLayout(reinterpret_cast<Packet_vkDestroyPipelineLayout*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSampler:
        Replay_vkCreateSampler(reinterpret_cast<Packet_vkCreateSampler*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySampler:
        Replay_vkDestroySampler(reinterpret_cast<Packet_vkDestroySampler*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDescriptorSetLayout:
        Replay_vkCreateDescriptorSetLayout(reinterpret_cast<Packet_vkCreateDescriptorSetLayout*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDescriptorSetLayout:
        Replay_vkDestroyDescriptorSetLayout(reinterpret_cast<Packet_vkDestroyDescriptorSetLayout*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDescriptorPool:
        Replay_vkCreateDescriptorPool(reinterpret_cast<Packet_vkCreateDescriptorPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDescriptorPool:
        Replay_vkDestroyDescriptorPool(reinterpret_cast<Packet_vkDestroyDescriptorPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetDescriptorPool:
        Replay_vkResetDescriptorPool(reinterpret_cast<Packet_vkResetDescriptorPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAllocateDescriptorSets:
        Replay_vkAllocateDescriptorSets(reinterpret_cast<Packet_vkAllocateDescriptorSets*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkFreeDescriptorSets:
        Replay_vkFreeDescriptorSets(reinterpret_cast<Packet_vkFreeDescriptorSets*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkUpdateDescriptorSets:
        Replay_vkUpdateDescriptorSets(reinterpret_cast<Packet_vkUpdateDescriptorSets*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateFramebuffer:
        Replay_vkCreateFramebuffer(reinterpret_cast<Packet_vkCreateFramebuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyFramebuffer:
        Replay_vkDestroyFramebuffer(reinterpret_cast<Packet_vkDestroyFramebuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateRenderPass:
        Replay_vkCreateRenderPass(reinterpret_cast<Packet_vkCreateRenderPass*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyRenderPass:
        Replay_vkDestroyRenderPass(reinterpret_cast<Packet_vkDestroyRenderPass*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRenderAreaGranularity:
        Replay_vkGetRenderAreaGranularity(reinterpret_cast<Packet_vkGetRenderAreaGranularity*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateCommandPool:
        Replay_vkCreateCommandPool(reinterpret_cast<Packet_vkCreateCommandPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyCommandPool:
        Replay_vkDestroyCommandPool(reinterpret_cast<Packet_vkDestroyCommandPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetCommandPool:
        Replay_vkResetCommandPool(reinterpret_cast<Packet_vkResetCommandPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAllocateCommandBuffers:
        Replay_vkAllocateCommandBuffers(reinterpret_cast<Packet_vkAllocateCommandBuffers*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkFreeCommandBuffers:
        Replay_vkFreeCommandBuffers(reinterpret_cast<Packet_vkFreeCommandBuffers*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBeginCommandBuffer:
        Replay_vkBeginCommandBuffer(reinterpret_cast<Packet_vkBeginCommandBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkEndCommandBuffer:
        Replay_vkEndCommandBuffer(reinterpret_cast<Packet_vkEndCommandBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetCommandBuffer:
        Replay_vkResetCommandBuffer(reinterpret_cast<Packet_vkResetCommandBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindPipeline:
        Replay_vkCmdBindPipeline(reinterpret_cast<Packet_vkCmdBindPipeline*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewport:
        Replay_vkCmdSetViewport(reinterpret_cast<Packet_vkCmdSetViewport*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetScissor:
        Replay_vkCmdSetScissor(reinterpret_cast<Packet_vkCmdSetScissor*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLineWidth:
        Replay_vkCmdSetLineWidth(reinterpret_cast<Packet_vkCmdSetLineWidth*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBias:
        Replay_vkCmdSetDepthBias(reinterpret_cast<Packet_vkCmdSetDepthBias*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetBlendConstants:
        Replay_vkCmdSetBlendConstants(reinterpret_cast<Packet_vkCmdSetBlendConstants*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBounds:
        Replay_vkCmdSetDepthBounds(reinterpret_cast<Packet_vkCmdSetDepthBounds*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilCompareMask:
        Replay_vkCmdSetStencilCompareMask(reinterpret_cast<Packet_vkCmdSetStencilCompareMask*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilWriteMask:
        Replay_vkCmdSetStencilWriteMask(reinterpret_cast<Packet_vkCmdSetStencilWriteMask*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilReference:
        Replay_vkCmdSetStencilReference(reinterpret_cast<Packet_vkCmdSetStencilReference*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindDescriptorSets:
        Replay_vkCmdBindDescriptorSets(reinterpret_cast<Packet_vkCmdBindDescriptorSets*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindIndexBuffer:
        Replay_vkCmdBindIndexBuffer(reinterpret_cast<Packet_vkCmdBindIndexBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindVertexBuffers:
        Replay_vkCmdBindVertexBuffers(reinterpret_cast<Packet_vkCmdBindVertexBuffers*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDraw:
        Replay_vkCmdDraw(reinterpret_cast<Packet_vkCmdDraw*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndexed:
        Replay_vkCmdDrawIndexed(reinterpret_cast<Packet_vkCmdDrawIndexed*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndirect:
        Replay_vkCmdDrawIndirect(reinterpret_cast<Packet_vkCmdDrawIndirect*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndexedIndirect:
        Replay_vkCmdDrawIndexedIndirect(reinterpret_cast<Packet_vkCmdDrawIndexedIndirect*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDispatch:
        Replay_vkCmdDispatch(reinterpret_cast<Packet_vkCmdDispatch*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDispatchIndirect:
        Replay_vkCmdDispatchIndirect(reinterpret_cast<Packet_vkCmdDispatchIndirect*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBuffer:
        Replay_vkCmdCopyBuffer(reinterpret_cast<Packet_vkCmdCopyBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImage:
        Replay_vkCmdCopyImage(reinterpret_cast<Packet_vkCmdCopyImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBlitImage:
        Replay_vkCmdBlitImage(reinterpret_cast<Packet_vkCmdBlitImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBufferToImage:
        Replay_vkCmdCopyBufferToImage(reinterpret_cast<Packet_vkCmdCopyBufferToImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImageToBuffer:
        Replay_vkCmdCopyImageToBuffer(reinterpret_cast<Packet_vkCmdCopyImageToBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdUpdateBuffer:
        Replay_vkCmdUpdateBuffer(reinterpret_cast<Packet_vkCmdUpdateBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdFillBuffer:
        Replay_vkCmdFillBuffer(reinterpret_cast<Packet_vkCmdFillBuffer*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdClearColorImage:
        Replay_vkCmdClearColorImage(reinterpret_cast<Packet_vkCmdClearColorImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdClearDepthStencilImage:
        Replay_vkCmdClearDepthStencilImage(reinterpret_cast<Packet_vkCmdClearDepthStencilImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdClearAttachments:
        Replay_vkCmdClearAttachments(reinterpret_cast<Packet_vkCmdClearAttachments*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResolveImage:
        Replay_vkCmdResolveImage(reinterpret_cast<Packet_vkCmdResolveImage*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetEvent:
        Replay_vkCmdSetEvent(reinterpret_cast<Packet_vkCmdSetEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResetEvent:
        Replay_vkCmdResetEvent(reinterpret_cast<Packet_vkCmdResetEvent*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWaitEvents:
        Replay_vkCmdWaitEvents(reinterpret_cast<Packet_vkCmdWaitEvents*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPipelineBarrier:
        Replay_vkCmdPipelineBarrier(reinterpret_cast<Packet_vkCmdPipelineBarrier*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginQuery:
        Replay_vkCmdBeginQuery(reinterpret_cast<Packet_vkCmdBeginQuery*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndQuery:
        Replay_vkCmdEndQuery(reinterpret_cast<Packet_vkCmdEndQuery*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResetQueryPool:
        Replay_vkCmdResetQueryPool(reinterpret_cast<Packet_vkCmdResetQueryPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteTimestamp:
        Replay_vkCmdWriteTimestamp(reinterpret_cast<Packet_vkCmdWriteTimestamp*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyQueryPoolResults:
        Replay_vkCmdCopyQueryPoolResults(reinterpret_cast<Packet_vkCmdCopyQueryPoolResults*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPushConstants:
        Replay_vkCmdPushConstants(reinterpret_cast<Packet_vkCmdPushConstants*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginRenderPass:
        Replay_vkCmdBeginRenderPass(reinterpret_cast<Packet_vkCmdBeginRenderPass*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdNextSubpass:
        Replay_vkCmdNextSubpass(reinterpret_cast<Packet_vkCmdNextSubpass*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndRenderPass:
        Replay_vkCmdEndRenderPass(reinterpret_cast<Packet_vkCmdEndRenderPass*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdExecuteCommands:
        Replay_vkCmdExecuteCommands(reinterpret_cast<Packet_vkCmdExecuteCommands*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindBufferMemory2:
        Replay_vkBindBufferMemory2(reinterpret_cast<Packet_vkBindBufferMemory2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindImageMemory2:
        Replay_vkBindImageMemory2(reinterpret_cast<Packet_vkBindImageMemory2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceGroupPeerMemoryFeatures:
        Replay_vkGetDeviceGroupPeerMemoryFeatures(reinterpret_cast<Packet_vkGetDeviceGroupPeerMemoryFeatures*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDeviceMask:
        Replay_vkCmdSetDeviceMask(reinterpret_cast<Packet_vkCmdSetDeviceMask*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDispatchBase:
        Replay_vkCmdDispatchBase(reinterpret_cast<Packet_vkCmdDispatchBase*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkEnumeratePhysicalDeviceGroups:
        Replay_vkEnumeratePhysicalDeviceGroups(reinterpret_cast<Packet_vkEnumeratePhysicalDeviceGroups*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageMemoryRequirements2:
        Replay_vkGetImageMemoryRequirements2(reinterpret_cast<Packet_vkGetImageMemoryRequirements2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferMemoryRequirements2:
        Replay_vkGetBufferMemoryRequirements2(reinterpret_cast<Packet_vkGetBufferMemoryRequirements2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSparseMemoryRequirements2:
        Replay_vkGetImageSparseMemoryRequirements2(reinterpret_cast<Packet_vkGetImageSparseMemoryRequirements2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFeatures2:
        Replay_vkGetPhysicalDeviceFeatures2(reinterpret_cast<Packet_vkGetPhysicalDeviceFeatures2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceProperties2:
        Replay_vkGetPhysicalDeviceProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFormatProperties2:
        Replay_vkGetPhysicalDeviceFormatProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceFormatProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceImageFormatProperties2:
        Replay_vkGetPhysicalDeviceImageFormatProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceImageFormatProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties2:
        Replay_vkGetPhysicalDeviceQueueFamilyProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceQueueFamilyProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceMemoryProperties2:
        Replay_vkGetPhysicalDeviceMemoryProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceMemoryProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties2:
        Replay_vkGetPhysicalDeviceSparseImageFormatProperties2(reinterpret_cast<Packet_vkGetPhysicalDeviceSparseImageFormatProperties2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkTrimCommandPool:
        Replay_vkTrimCommandPool(reinterpret_cast<Packet_vkTrimCommandPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceQueue2:
        Replay_vkGetDeviceQueue2(reinterpret_cast<Packet_vkGetDeviceQueue2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSamplerYcbcrConversion:
        Replay_vkCreateSamplerYcbcrConversion(reinterpret_cast<Packet_vkCreateSamplerYcbcrConversion*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySamplerYcbcrConversion:
        Replay_vkDestroySamplerYcbcrConversion(reinterpret_cast<Packet_vkDestroySamplerYcbcrConversion*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDescriptorUpdateTemplate:
        Replay_vkCreateDescriptorUpdateTemplate(reinterpret_cast<Packet_vkCreateDescriptorUpdateTemplate*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDescriptorUpdateTemplate:
        Replay_vkDestroyDescriptorUpdateTemplate(reinterpret_cast<Packet_vkDestroyDescriptorUpdateTemplate*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalBufferProperties:
        Replay_vkGetPhysicalDeviceExternalBufferProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalBufferProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalFenceProperties:
        Replay_vkGetPhysicalDeviceExternalFenceProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalFenceProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalSemaphoreProperties:
        Replay_vkGetPhysicalDeviceExternalSemaphoreProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalSemaphoreProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDescriptorSetLayoutSupport:
        Replay_vkGetDescriptorSetLayoutSupport(reinterpret_cast<Packet_vkGetDescriptorSetLayoutSupport*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndirectCount:
        Replay_vkCmdDrawIndirectCount(reinterpret_cast<Packet_vkCmdDrawIndirectCount*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndexedIndirectCount:
        Replay_vkCmdDrawIndexedIndirectCount(reinterpret_cast<Packet_vkCmdDrawIndexedIndirectCount*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateRenderPass2:
        Replay_vkCreateRenderPass2(reinterpret_cast<Packet_vkCreateRenderPass2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginRenderPass2:
        Replay_vkCmdBeginRenderPass2(reinterpret_cast<Packet_vkCmdBeginRenderPass2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdNextSubpass2:
        Replay_vkCmdNextSubpass2(reinterpret_cast<Packet_vkCmdNextSubpass2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndRenderPass2:
        Replay_vkCmdEndRenderPass2(reinterpret_cast<Packet_vkCmdEndRenderPass2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetQueryPool:
        Replay_vkResetQueryPool(reinterpret_cast<Packet_vkResetQueryPool*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSemaphoreCounterValue:
        Replay_vkGetSemaphoreCounterValue(reinterpret_cast<Packet_vkGetSemaphoreCounterValue*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWaitSemaphores:
        Replay_vkWaitSemaphores(reinterpret_cast<Packet_vkWaitSemaphores*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSignalSemaphore:
        Replay_vkSignalSemaphore(reinterpret_cast<Packet_vkSignalSemaphore*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferDeviceAddress:
        Replay_vkGetBufferDeviceAddress(reinterpret_cast<Packet_vkGetBufferDeviceAddress*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferOpaqueCaptureAddress:
        Replay_vkGetBufferOpaqueCaptureAddress(reinterpret_cast<Packet_vkGetBufferOpaqueCaptureAddress*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceMemoryOpaqueCaptureAddress:
        Replay_vkGetDeviceMemoryOpaqueCaptureAddress(reinterpret_cast<Packet_vkGetDeviceMemoryOpaqueCaptureAddress*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceToolProperties:
        Replay_vkGetPhysicalDeviceToolProperties(reinterpret_cast<Packet_vkGetPhysicalDeviceToolProperties*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreatePrivateDataSlot:
        Replay_vkCreatePrivateDataSlot(reinterpret_cast<Packet_vkCreatePrivateDataSlot*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyPrivateDataSlot:
        Replay_vkDestroyPrivateDataSlot(reinterpret_cast<Packet_vkDestroyPrivateDataSlot*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetPrivateData:
        Replay_vkSetPrivateData(reinterpret_cast<Packet_vkSetPrivateData*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPrivateData:
        Replay_vkGetPrivateData(reinterpret_cast<Packet_vkGetPrivateData*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetEvent2:
        Replay_vkCmdSetEvent2(reinterpret_cast<Packet_vkCmdSetEvent2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResetEvent2:
        Replay_vkCmdResetEvent2(reinterpret_cast<Packet_vkCmdResetEvent2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWaitEvents2:
        Replay_vkCmdWaitEvents2(reinterpret_cast<Packet_vkCmdWaitEvents2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPipelineBarrier2:
        Replay_vkCmdPipelineBarrier2(reinterpret_cast<Packet_vkCmdPipelineBarrier2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteTimestamp2:
        Replay_vkCmdWriteTimestamp2(reinterpret_cast<Packet_vkCmdWriteTimestamp2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueSubmit2:
        Replay_vkQueueSubmit2(reinterpret_cast<Packet_vkQueueSubmit2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBuffer2:
        Replay_vkCmdCopyBuffer2(reinterpret_cast<Packet_vkCmdCopyBuffer2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImage2:
        Replay_vkCmdCopyImage2(reinterpret_cast<Packet_vkCmdCopyImage2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBufferToImage2:
        Replay_vkCmdCopyBufferToImage2(reinterpret_cast<Packet_vkCmdCopyBufferToImage2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImageToBuffer2:
        Replay_vkCmdCopyImageToBuffer2(reinterpret_cast<Packet_vkCmdCopyImageToBuffer2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBlitImage2:
        Replay_vkCmdBlitImage2(reinterpret_cast<Packet_vkCmdBlitImage2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResolveImage2:
        Replay_vkCmdResolveImage2(reinterpret_cast<Packet_vkCmdResolveImage2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginRendering:
        Replay_vkCmdBeginRendering(reinterpret_cast<Packet_vkCmdBeginRendering*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndRendering:
        Replay_vkCmdEndRendering(reinterpret_cast<Packet_vkCmdEndRendering*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCullMode:
        Replay_vkCmdSetCullMode(reinterpret_cast<Packet_vkCmdSetCullMode*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetFrontFace:
        Replay_vkCmdSetFrontFace(reinterpret_cast<Packet_vkCmdSetFrontFace*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPrimitiveTopology:
        Replay_vkCmdSetPrimitiveTopology(reinterpret_cast<Packet_vkCmdSetPrimitiveTopology*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportWithCount:
        Replay_vkCmdSetViewportWithCount(reinterpret_cast<Packet_vkCmdSetViewportWithCount*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetScissorWithCount:
        Replay_vkCmdSetScissorWithCount(reinterpret_cast<Packet_vkCmdSetScissorWithCount*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindVertexBuffers2:
        Replay_vkCmdBindVertexBuffers2(reinterpret_cast<Packet_vkCmdBindVertexBuffers2*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthTestEnable:
        Replay_vkCmdSetDepthTestEnable(reinterpret_cast<Packet_vkCmdSetDepthTestEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthWriteEnable:
        Replay_vkCmdSetDepthWriteEnable(reinterpret_cast<Packet_vkCmdSetDepthWriteEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthCompareOp:
        Replay_vkCmdSetDepthCompareOp(reinterpret_cast<Packet_vkCmdSetDepthCompareOp*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBoundsTestEnable:
        Replay_vkCmdSetDepthBoundsTestEnable(reinterpret_cast<Packet_vkCmdSetDepthBoundsTestEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilTestEnable:
        Replay_vkCmdSetStencilTestEnable(reinterpret_cast<Packet_vkCmdSetStencilTestEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilOp:
        Replay_vkCmdSetStencilOp(reinterpret_cast<Packet_vkCmdSetStencilOp*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRasterizerDiscardEnable:
        Replay_vkCmdSetRasterizerDiscardEnable(reinterpret_cast<Packet_vkCmdSetRasterizerDiscardEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBiasEnable:
        Replay_vkCmdSetDepthBiasEnable(reinterpret_cast<Packet_vkCmdSetDepthBiasEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPrimitiveRestartEnable:
        Replay_vkCmdSetPrimitiveRestartEnable(reinterpret_cast<Packet_vkCmdSetPrimitiveRestartEnable*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceBufferMemoryRequirements:
        Replay_vkGetDeviceBufferMemoryRequirements(reinterpret_cast<Packet_vkGetDeviceBufferMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceImageMemoryRequirements:
        Replay_vkGetDeviceImageMemoryRequirements(reinterpret_cast<Packet_vkGetDeviceImageMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceImageSparseMemoryRequirements:
        Replay_vkGetDeviceImageSparseMemoryRequirements(reinterpret_cast<Packet_vkGetDeviceImageSparseMemoryRequirements*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySurfaceKHR:
        Replay_vkDestroySurfaceKHR(reinterpret_cast<Packet_vkDestroySurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceSupportKHR:
        Replay_vkGetPhysicalDeviceSurfaceSupportKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        Replay_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceFormatsKHR:
        Replay_vkGetPhysicalDeviceSurfaceFormatsKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceFormatsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfacePresentModesKHR:
        Replay_vkGetPhysicalDeviceSurfacePresentModesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfacePresentModesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSwapchainKHR:
        Replay_vkCreateSwapchainKHR(reinterpret_cast<Packet_vkCreateSwapchainKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySwapchainKHR:
        Replay_vkDestroySwapchainKHR(reinterpret_cast<Packet_vkDestroySwapchainKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSwapchainImagesKHR:
        Replay_vkGetSwapchainImagesKHR(reinterpret_cast<Packet_vkGetSwapchainImagesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireNextImageKHR:
        Replay_vkAcquireNextImageKHR(reinterpret_cast<Packet_vkAcquireNextImageKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueuePresentKHR:
        Replay_vkQueuePresentKHR(reinterpret_cast<Packet_vkQueuePresentKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceGroupPresentCapabilitiesKHR:
        Replay_vkGetDeviceGroupPresentCapabilitiesKHR(reinterpret_cast<Packet_vkGetDeviceGroupPresentCapabilitiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceGroupSurfacePresentModesKHR:
        Replay_vkGetDeviceGroupSurfacePresentModesKHR(reinterpret_cast<Packet_vkGetDeviceGroupSurfacePresentModesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDevicePresentRectanglesKHR:
        Replay_vkGetPhysicalDevicePresentRectanglesKHR(reinterpret_cast<Packet_vkGetPhysicalDevicePresentRectanglesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireNextImage2KHR:
        Replay_vkAcquireNextImage2KHR(reinterpret_cast<Packet_vkAcquireNextImage2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceDisplayPropertiesKHR:
        Replay_vkGetPhysicalDeviceDisplayPropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceDisplayPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
        Replay_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDisplayPlaneSupportedDisplaysKHR:
        Replay_vkGetDisplayPlaneSupportedDisplaysKHR(reinterpret_cast<Packet_vkGetDisplayPlaneSupportedDisplaysKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDisplayModePropertiesKHR:
        Replay_vkGetDisplayModePropertiesKHR(reinterpret_cast<Packet_vkGetDisplayModePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDisplayModeKHR:
        Replay_vkCreateDisplayModeKHR(reinterpret_cast<Packet_vkCreateDisplayModeKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDisplayPlaneCapabilitiesKHR:
        Replay_vkGetDisplayPlaneCapabilitiesKHR(reinterpret_cast<Packet_vkGetDisplayPlaneCapabilitiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDisplayPlaneSurfaceKHR:
        Replay_vkCreateDisplayPlaneSurfaceKHR(reinterpret_cast<Packet_vkCreateDisplayPlaneSurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSharedSwapchainsKHR:
        Replay_vkCreateSharedSwapchainsKHR(reinterpret_cast<Packet_vkCreateSharedSwapchainsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateXlibSurfaceKHR:
        Replay_vkCreateXlibSurfaceKHR(reinterpret_cast<Packet_vkCreateXlibSurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceXlibPresentationSupportKHR:
        Replay_vkGetPhysicalDeviceXlibPresentationSupportKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateXcbSurfaceKHR:
        Replay_vkCreateXcbSurfaceKHR(reinterpret_cast<Packet_vkCreateXcbSurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        Replay_vkGetPhysicalDeviceXcbPresentationSupportKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateWaylandSurfaceKHR:
        Replay_vkCreateWaylandSurfaceKHR(reinterpret_cast<Packet_vkCreateWaylandSurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR:
        Replay_vkGetPhysicalDeviceWaylandPresentationSupportKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateAndroidSurfaceKHR:
        Replay_vkCreateAndroidSurfaceKHR(reinterpret_cast<Packet_vkCreateAndroidSurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateWin32SurfaceKHR:
        Replay_vkCreateWin32SurfaceKHR(reinterpret_cast<Packet_vkCreateWin32SurfaceKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceWin32PresentationSupportKHR:
        Replay_vkGetPhysicalDeviceWin32PresentationSupportKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceVideoCapabilitiesKHR:
        Replay_vkGetPhysicalDeviceVideoCapabilitiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR:
        Replay_vkGetPhysicalDeviceVideoFormatPropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateVideoSessionKHR:
        Replay_vkCreateVideoSessionKHR(reinterpret_cast<Packet_vkCreateVideoSessionKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyVideoSessionKHR:
        Replay_vkDestroyVideoSessionKHR(reinterpret_cast<Packet_vkDestroyVideoSessionKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetVideoSessionMemoryRequirementsKHR:
        Replay_vkGetVideoSessionMemoryRequirementsKHR(reinterpret_cast<Packet_vkGetVideoSessionMemoryRequirementsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindVideoSessionMemoryKHR:
        Replay_vkBindVideoSessionMemoryKHR(reinterpret_cast<Packet_vkBindVideoSessionMemoryKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateVideoSessionParametersKHR:
        Replay_vkCreateVideoSessionParametersKHR(reinterpret_cast<Packet_vkCreateVideoSessionParametersKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkUpdateVideoSessionParametersKHR:
        Replay_vkUpdateVideoSessionParametersKHR(reinterpret_cast<Packet_vkUpdateVideoSessionParametersKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyVideoSessionParametersKHR:
        Replay_vkDestroyVideoSessionParametersKHR(reinterpret_cast<Packet_vkDestroyVideoSessionParametersKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginVideoCodingKHR:
        Replay_vkCmdBeginVideoCodingKHR(reinterpret_cast<Packet_vkCmdBeginVideoCodingKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndVideoCodingKHR:
        Replay_vkCmdEndVideoCodingKHR(reinterpret_cast<Packet_vkCmdEndVideoCodingKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdControlVideoCodingKHR:
        Replay_vkCmdControlVideoCodingKHR(reinterpret_cast<Packet_vkCmdControlVideoCodingKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDecodeVideoKHR:
        Replay_vkCmdDecodeVideoKHR(reinterpret_cast<Packet_vkCmdDecodeVideoKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginRenderingKHR:
        Replay_vkCmdBeginRenderingKHR(reinterpret_cast<Packet_vkCmdBeginRenderingKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndRenderingKHR:
        Replay_vkCmdEndRenderingKHR(reinterpret_cast<Packet_vkCmdEndRenderingKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFeatures2KHR:
        Replay_vkGetPhysicalDeviceFeatures2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceFeatures2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceProperties2KHR:
        Replay_vkGetPhysicalDeviceProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFormatProperties2KHR:
        Replay_vkGetPhysicalDeviceFormatProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceFormatProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceImageFormatProperties2KHR:
        Replay_vkGetPhysicalDeviceImageFormatProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceImageFormatProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
        Replay_vkGetPhysicalDeviceQueueFamilyProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceMemoryProperties2KHR:
        Replay_vkGetPhysicalDeviceMemoryProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceMemoryProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
        Replay_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceGroupPeerMemoryFeaturesKHR:
        Replay_vkGetDeviceGroupPeerMemoryFeaturesKHR(reinterpret_cast<Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDeviceMaskKHR:
        Replay_vkCmdSetDeviceMaskKHR(reinterpret_cast<Packet_vkCmdSetDeviceMaskKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDispatchBaseKHR:
        Replay_vkCmdDispatchBaseKHR(reinterpret_cast<Packet_vkCmdDispatchBaseKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkTrimCommandPoolKHR:
        Replay_vkTrimCommandPoolKHR(reinterpret_cast<Packet_vkTrimCommandPoolKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkEnumeratePhysicalDeviceGroupsKHR:
        Replay_vkEnumeratePhysicalDeviceGroupsKHR(reinterpret_cast<Packet_vkEnumeratePhysicalDeviceGroupsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR:
        Replay_vkGetPhysicalDeviceExternalBufferPropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryWin32HandleKHR:
        Replay_vkGetMemoryWin32HandleKHR(reinterpret_cast<Packet_vkGetMemoryWin32HandleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryWin32HandlePropertiesKHR:
        Replay_vkGetMemoryWin32HandlePropertiesKHR(reinterpret_cast<Packet_vkGetMemoryWin32HandlePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryFdKHR:
        Replay_vkGetMemoryFdKHR(reinterpret_cast<Packet_vkGetMemoryFdKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryFdPropertiesKHR:
        Replay_vkGetMemoryFdPropertiesKHR(reinterpret_cast<Packet_vkGetMemoryFdPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
        Replay_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkImportSemaphoreWin32HandleKHR:
        Replay_vkImportSemaphoreWin32HandleKHR(reinterpret_cast<Packet_vkImportSemaphoreWin32HandleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSemaphoreWin32HandleKHR:
        Replay_vkGetSemaphoreWin32HandleKHR(reinterpret_cast<Packet_vkGetSemaphoreWin32HandleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkImportSemaphoreFdKHR:
        Replay_vkImportSemaphoreFdKHR(reinterpret_cast<Packet_vkImportSemaphoreFdKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSemaphoreFdKHR:
        Replay_vkGetSemaphoreFdKHR(reinterpret_cast<Packet_vkGetSemaphoreFdKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPushDescriptorSetKHR:
        Replay_vkCmdPushDescriptorSetKHR(reinterpret_cast<Packet_vkCmdPushDescriptorSetKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDescriptorUpdateTemplateKHR:
        Replay_vkCreateDescriptorUpdateTemplateKHR(reinterpret_cast<Packet_vkCreateDescriptorUpdateTemplateKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDescriptorUpdateTemplateKHR:
        Replay_vkDestroyDescriptorUpdateTemplateKHR(reinterpret_cast<Packet_vkDestroyDescriptorUpdateTemplateKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateRenderPass2KHR:
        Replay_vkCreateRenderPass2KHR(reinterpret_cast<Packet_vkCreateRenderPass2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginRenderPass2KHR:
        Replay_vkCmdBeginRenderPass2KHR(reinterpret_cast<Packet_vkCmdBeginRenderPass2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdNextSubpass2KHR:
        Replay_vkCmdNextSubpass2KHR(reinterpret_cast<Packet_vkCmdNextSubpass2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndRenderPass2KHR:
        Replay_vkCmdEndRenderPass2KHR(reinterpret_cast<Packet_vkCmdEndRenderPass2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSwapchainStatusKHR:
        Replay_vkGetSwapchainStatusKHR(reinterpret_cast<Packet_vkGetSwapchainStatusKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalFencePropertiesKHR:
        Replay_vkGetPhysicalDeviceExternalFencePropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkImportFenceWin32HandleKHR:
        Replay_vkImportFenceWin32HandleKHR(reinterpret_cast<Packet_vkImportFenceWin32HandleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetFenceWin32HandleKHR:
        Replay_vkGetFenceWin32HandleKHR(reinterpret_cast<Packet_vkGetFenceWin32HandleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkImportFenceFdKHR:
        Replay_vkImportFenceFdKHR(reinterpret_cast<Packet_vkImportFenceFdKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetFenceFdKHR:
        Replay_vkGetFenceFdKHR(reinterpret_cast<Packet_vkGetFenceFdKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR:
        Replay_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(reinterpret_cast<Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR:
        Replay_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireProfilingLockKHR:
        Replay_vkAcquireProfilingLockKHR(reinterpret_cast<Packet_vkAcquireProfilingLockKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkReleaseProfilingLockKHR:
        Replay_vkReleaseProfilingLockKHR(reinterpret_cast<Packet_vkReleaseProfilingLockKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR:
        Replay_vkGetPhysicalDeviceSurfaceCapabilities2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceFormats2KHR:
        Replay_vkGetPhysicalDeviceSurfaceFormats2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceFormats2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceDisplayProperties2KHR:
        Replay_vkGetPhysicalDeviceDisplayProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceDisplayProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
        Replay_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(reinterpret_cast<Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDisplayModeProperties2KHR:
        Replay_vkGetDisplayModeProperties2KHR(reinterpret_cast<Packet_vkGetDisplayModeProperties2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDisplayPlaneCapabilities2KHR:
        Replay_vkGetDisplayPlaneCapabilities2KHR(reinterpret_cast<Packet_vkGetDisplayPlaneCapabilities2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageMemoryRequirements2KHR:
        Replay_vkGetImageMemoryRequirements2KHR(reinterpret_cast<Packet_vkGetImageMemoryRequirements2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferMemoryRequirements2KHR:
        Replay_vkGetBufferMemoryRequirements2KHR(reinterpret_cast<Packet_vkGetBufferMemoryRequirements2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSparseMemoryRequirements2KHR:
        Replay_vkGetImageSparseMemoryRequirements2KHR(reinterpret_cast<Packet_vkGetImageSparseMemoryRequirements2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateSamplerYcbcrConversionKHR:
        Replay_vkCreateSamplerYcbcrConversionKHR(reinterpret_cast<Packet_vkCreateSamplerYcbcrConversionKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroySamplerYcbcrConversionKHR:
        Replay_vkDestroySamplerYcbcrConversionKHR(reinterpret_cast<Packet_vkDestroySamplerYcbcrConversionKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindBufferMemory2KHR:
        Replay_vkBindBufferMemory2KHR(reinterpret_cast<Packet_vkBindBufferMemory2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindImageMemory2KHR:
        Replay_vkBindImageMemory2KHR(reinterpret_cast<Packet_vkBindImageMemory2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDescriptorSetLayoutSupportKHR:
        Replay_vkGetDescriptorSetLayoutSupportKHR(reinterpret_cast<Packet_vkGetDescriptorSetLayoutSupportKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndirectCountKHR:
        Replay_vkCmdDrawIndirectCountKHR(reinterpret_cast<Packet_vkCmdDrawIndirectCountKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndexedIndirectCountKHR:
        Replay_vkCmdDrawIndexedIndirectCountKHR(reinterpret_cast<Packet_vkCmdDrawIndexedIndirectCountKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSemaphoreCounterValueKHR:
        Replay_vkGetSemaphoreCounterValueKHR(reinterpret_cast<Packet_vkGetSemaphoreCounterValueKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWaitSemaphoresKHR:
        Replay_vkWaitSemaphoresKHR(reinterpret_cast<Packet_vkWaitSemaphoresKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSignalSemaphoreKHR:
        Replay_vkSignalSemaphoreKHR(reinterpret_cast<Packet_vkSignalSemaphoreKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceFragmentShadingRatesKHR:
        Replay_vkGetPhysicalDeviceFragmentShadingRatesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetFragmentShadingRateKHR:
        Replay_vkCmdSetFragmentShadingRateKHR(reinterpret_cast<Packet_vkCmdSetFragmentShadingRateKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRenderingAttachmentLocationsKHR:
        Replay_vkCmdSetRenderingAttachmentLocationsKHR(reinterpret_cast<Packet_vkCmdSetRenderingAttachmentLocationsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRenderingInputAttachmentIndicesKHR:
        Replay_vkCmdSetRenderingInputAttachmentIndicesKHR(reinterpret_cast<Packet_vkCmdSetRenderingInputAttachmentIndicesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWaitForPresentKHR:
        Replay_vkWaitForPresentKHR(reinterpret_cast<Packet_vkWaitForPresentKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferDeviceAddressKHR:
        Replay_vkGetBufferDeviceAddressKHR(reinterpret_cast<Packet_vkGetBufferDeviceAddressKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferOpaqueCaptureAddressKHR:
        Replay_vkGetBufferOpaqueCaptureAddressKHR(reinterpret_cast<Packet_vkGetBufferOpaqueCaptureAddressKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR:
        Replay_vkGetDeviceMemoryOpaqueCaptureAddressKHR(reinterpret_cast<Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDeferredOperationKHR:
        Replay_vkCreateDeferredOperationKHR(reinterpret_cast<Packet_vkCreateDeferredOperationKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDeferredOperationKHR:
        Replay_vkDestroyDeferredOperationKHR(reinterpret_cast<Packet_vkDestroyDeferredOperationKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeferredOperationMaxConcurrencyKHR:
        Replay_vkGetDeferredOperationMaxConcurrencyKHR(reinterpret_cast<Packet_vkGetDeferredOperationMaxConcurrencyKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeferredOperationResultKHR:
        Replay_vkGetDeferredOperationResultKHR(reinterpret_cast<Packet_vkGetDeferredOperationResultKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDeferredOperationJoinKHR:
        Replay_vkDeferredOperationJoinKHR(reinterpret_cast<Packet_vkDeferredOperationJoinKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineExecutablePropertiesKHR:
        Replay_vkGetPipelineExecutablePropertiesKHR(reinterpret_cast<Packet_vkGetPipelineExecutablePropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineExecutableStatisticsKHR:
        Replay_vkGetPipelineExecutableStatisticsKHR(reinterpret_cast<Packet_vkGetPipelineExecutableStatisticsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineExecutableInternalRepresentationsKHR:
        Replay_vkGetPipelineExecutableInternalRepresentationsKHR(reinterpret_cast<Packet_vkGetPipelineExecutableInternalRepresentationsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkMapMemory2KHR:
        Replay_vkMapMemory2KHR(reinterpret_cast<Packet_vkMapMemory2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkUnmapMemory2KHR:
        Replay_vkUnmapMemory2KHR(reinterpret_cast<Packet_vkUnmapMemory2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR:
        Replay_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetEncodedVideoSessionParametersKHR:
        Replay_vkGetEncodedVideoSessionParametersKHR(reinterpret_cast<Packet_vkGetEncodedVideoSessionParametersKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEncodeVideoKHR:
        Replay_vkCmdEncodeVideoKHR(reinterpret_cast<Packet_vkCmdEncodeVideoKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetEvent2KHR:
        Replay_vkCmdSetEvent2KHR(reinterpret_cast<Packet_vkCmdSetEvent2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResetEvent2KHR:
        Replay_vkCmdResetEvent2KHR(reinterpret_cast<Packet_vkCmdResetEvent2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWaitEvents2KHR:
        Replay_vkCmdWaitEvents2KHR(reinterpret_cast<Packet_vkCmdWaitEvents2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPipelineBarrier2KHR:
        Replay_vkCmdPipelineBarrier2KHR(reinterpret_cast<Packet_vkCmdPipelineBarrier2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteTimestamp2KHR:
        Replay_vkCmdWriteTimestamp2KHR(reinterpret_cast<Packet_vkCmdWriteTimestamp2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueSubmit2KHR:
        Replay_vkQueueSubmit2KHR(reinterpret_cast<Packet_vkQueueSubmit2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteBufferMarker2AMD:
        Replay_vkCmdWriteBufferMarker2AMD(reinterpret_cast<Packet_vkCmdWriteBufferMarker2AMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetQueueCheckpointData2NV:
        Replay_vkGetQueueCheckpointData2NV(reinterpret_cast<Packet_vkGetQueueCheckpointData2NV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBuffer2KHR:
        Replay_vkCmdCopyBuffer2KHR(reinterpret_cast<Packet_vkCmdCopyBuffer2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImage2KHR:
        Replay_vkCmdCopyImage2KHR(reinterpret_cast<Packet_vkCmdCopyImage2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyBufferToImage2KHR:
        Replay_vkCmdCopyBufferToImage2KHR(reinterpret_cast<Packet_vkCmdCopyBufferToImage2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyImageToBuffer2KHR:
        Replay_vkCmdCopyImageToBuffer2KHR(reinterpret_cast<Packet_vkCmdCopyImageToBuffer2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBlitImage2KHR:
        Replay_vkCmdBlitImage2KHR(reinterpret_cast<Packet_vkCmdBlitImage2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdResolveImage2KHR:
        Replay_vkCmdResolveImage2KHR(reinterpret_cast<Packet_vkCmdResolveImage2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdTraceRaysIndirect2KHR:
        Replay_vkCmdTraceRaysIndirect2KHR(reinterpret_cast<Packet_vkCmdTraceRaysIndirect2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceBufferMemoryRequirementsKHR:
        Replay_vkGetDeviceBufferMemoryRequirementsKHR(reinterpret_cast<Packet_vkGetDeviceBufferMemoryRequirementsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceImageMemoryRequirementsKHR:
        Replay_vkGetDeviceImageMemoryRequirementsKHR(reinterpret_cast<Packet_vkGetDeviceImageMemoryRequirementsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceImageSparseMemoryRequirementsKHR:
        Replay_vkGetDeviceImageSparseMemoryRequirementsKHR(reinterpret_cast<Packet_vkGetDeviceImageSparseMemoryRequirementsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindIndexBuffer2KHR:
        Replay_vkCmdBindIndexBuffer2KHR(reinterpret_cast<Packet_vkCmdBindIndexBuffer2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRenderingAreaGranularityKHR:
        Replay_vkGetRenderingAreaGranularityKHR(reinterpret_cast<Packet_vkGetRenderingAreaGranularityKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceImageSubresourceLayoutKHR:
        Replay_vkGetDeviceImageSubresourceLayoutKHR(reinterpret_cast<Packet_vkGetDeviceImageSubresourceLayoutKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSubresourceLayout2KHR:
        Replay_vkGetImageSubresourceLayout2KHR(reinterpret_cast<Packet_vkGetImageSubresourceLayout2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR:
        Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLineStippleKHR:
        Replay_vkCmdSetLineStippleKHR(reinterpret_cast<Packet_vkCmdSetLineStippleKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR:
        Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(reinterpret_cast<Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetCalibratedTimestampsKHR:
        Replay_vkGetCalibratedTimestampsKHR(reinterpret_cast<Packet_vkGetCalibratedTimestampsKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindDescriptorSets2KHR:
        Replay_vkCmdBindDescriptorSets2KHR(reinterpret_cast<Packet_vkCmdBindDescriptorSets2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPushConstants2KHR:
        Replay_vkCmdPushConstants2KHR(reinterpret_cast<Packet_vkCmdPushConstants2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPushDescriptorSet2KHR:
        Replay_vkCmdPushDescriptorSet2KHR(reinterpret_cast<Packet_vkCmdPushDescriptorSet2KHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDescriptorBufferOffsets2EXT:
        Replay_vkCmdSetDescriptorBufferOffsets2EXT(reinterpret_cast<Packet_vkCmdSetDescriptorBufferOffsets2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT:
        Replay_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(reinterpret_cast<Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkFrameBoundaryANDROID:
        Replay_vkFrameBoundaryANDROID(reinterpret_cast<Packet_vkFrameBoundaryANDROID*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDebugReportCallbackEXT:
        Replay_vkCreateDebugReportCallbackEXT(reinterpret_cast<Packet_vkCreateDebugReportCallbackEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDebugReportCallbackEXT:
        Replay_vkDestroyDebugReportCallbackEXT(reinterpret_cast<Packet_vkDestroyDebugReportCallbackEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDebugReportMessageEXT:
        Replay_vkDebugReportMessageEXT(reinterpret_cast<Packet_vkDebugReportMessageEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDebugMarkerSetObjectTagEXT:
        Replay_vkDebugMarkerSetObjectTagEXT(reinterpret_cast<Packet_vkDebugMarkerSetObjectTagEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDebugMarkerSetObjectNameEXT:
        Replay_vkDebugMarkerSetObjectNameEXT(reinterpret_cast<Packet_vkDebugMarkerSetObjectNameEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDebugMarkerBeginEXT:
        Replay_vkCmdDebugMarkerBeginEXT(reinterpret_cast<Packet_vkCmdDebugMarkerBeginEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDebugMarkerEndEXT:
        Replay_vkCmdDebugMarkerEndEXT(reinterpret_cast<Packet_vkCmdDebugMarkerEndEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDebugMarkerInsertEXT:
        Replay_vkCmdDebugMarkerInsertEXT(reinterpret_cast<Packet_vkCmdDebugMarkerInsertEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindTransformFeedbackBuffersEXT:
        Replay_vkCmdBindTransformFeedbackBuffersEXT(reinterpret_cast<Packet_vkCmdBindTransformFeedbackBuffersEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginTransformFeedbackEXT:
        Replay_vkCmdBeginTransformFeedbackEXT(reinterpret_cast<Packet_vkCmdBeginTransformFeedbackEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndTransformFeedbackEXT:
        Replay_vkCmdEndTransformFeedbackEXT(reinterpret_cast<Packet_vkCmdEndTransformFeedbackEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginQueryIndexedEXT:
        Replay_vkCmdBeginQueryIndexedEXT(reinterpret_cast<Packet_vkCmdBeginQueryIndexedEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndQueryIndexedEXT:
        Replay_vkCmdEndQueryIndexedEXT(reinterpret_cast<Packet_vkCmdEndQueryIndexedEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndirectByteCountEXT:
        Replay_vkCmdDrawIndirectByteCountEXT(reinterpret_cast<Packet_vkCmdDrawIndirectByteCountEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageViewHandleNVX:
        Replay_vkGetImageViewHandleNVX(reinterpret_cast<Packet_vkGetImageViewHandleNVX*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageViewAddressNVX:
        Replay_vkGetImageViewAddressNVX(reinterpret_cast<Packet_vkGetImageViewAddressNVX*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndirectCountAMD:
        Replay_vkCmdDrawIndirectCountAMD(reinterpret_cast<Packet_vkCmdDrawIndirectCountAMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawIndexedIndirectCountAMD:
        Replay_vkCmdDrawIndexedIndirectCountAMD(reinterpret_cast<Packet_vkCmdDrawIndexedIndirectCountAMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetShaderInfoAMD:
        Replay_vkGetShaderInfoAMD(reinterpret_cast<Packet_vkGetShaderInfoAMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateStreamDescriptorSurfaceGGP:
        Replay_vkCreateStreamDescriptorSurfaceGGP(reinterpret_cast<Packet_vkCreateStreamDescriptorSurfaceGGP*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
        Replay_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(reinterpret_cast<Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryWin32HandleNV:
        Replay_vkGetMemoryWin32HandleNV(reinterpret_cast<Packet_vkGetMemoryWin32HandleNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateViSurfaceNN:
        Replay_vkCreateViSurfaceNN(reinterpret_cast<Packet_vkCreateViSurfaceNN*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginConditionalRenderingEXT:
        Replay_vkCmdBeginConditionalRenderingEXT(reinterpret_cast<Packet_vkCmdBeginConditionalRenderingEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndConditionalRenderingEXT:
        Replay_vkCmdEndConditionalRenderingEXT(reinterpret_cast<Packet_vkCmdEndConditionalRenderingEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportWScalingNV:
        Replay_vkCmdSetViewportWScalingNV(reinterpret_cast<Packet_vkCmdSetViewportWScalingNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkReleaseDisplayEXT:
        Replay_vkReleaseDisplayEXT(reinterpret_cast<Packet_vkReleaseDisplayEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireXlibDisplayEXT:
        Replay_vkAcquireXlibDisplayEXT(reinterpret_cast<Packet_vkAcquireXlibDisplayEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRandROutputDisplayEXT:
        Replay_vkGetRandROutputDisplayEXT(reinterpret_cast<Packet_vkGetRandROutputDisplayEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT:
        Replay_vkGetPhysicalDeviceSurfaceCapabilities2EXT(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDisplayPowerControlEXT:
        Replay_vkDisplayPowerControlEXT(reinterpret_cast<Packet_vkDisplayPowerControlEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkRegisterDeviceEventEXT:
        Replay_vkRegisterDeviceEventEXT(reinterpret_cast<Packet_vkRegisterDeviceEventEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkRegisterDisplayEventEXT:
        Replay_vkRegisterDisplayEventEXT(reinterpret_cast<Packet_vkRegisterDisplayEventEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSwapchainCounterEXT:
        Replay_vkGetSwapchainCounterEXT(reinterpret_cast<Packet_vkGetSwapchainCounterEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRefreshCycleDurationGOOGLE:
        Replay_vkGetRefreshCycleDurationGOOGLE(reinterpret_cast<Packet_vkGetRefreshCycleDurationGOOGLE*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPastPresentationTimingGOOGLE:
        Replay_vkGetPastPresentationTimingGOOGLE(reinterpret_cast<Packet_vkGetPastPresentationTimingGOOGLE*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDiscardRectangleEXT:
        Replay_vkCmdSetDiscardRectangleEXT(reinterpret_cast<Packet_vkCmdSetDiscardRectangleEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDiscardRectangleEnableEXT:
        Replay_vkCmdSetDiscardRectangleEnableEXT(reinterpret_cast<Packet_vkCmdSetDiscardRectangleEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDiscardRectangleModeEXT:
        Replay_vkCmdSetDiscardRectangleModeEXT(reinterpret_cast<Packet_vkCmdSetDiscardRectangleModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetHdrMetadataEXT:
        Replay_vkSetHdrMetadataEXT(reinterpret_cast<Packet_vkSetHdrMetadataEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateIOSSurfaceMVK:
        Replay_vkCreateIOSSurfaceMVK(reinterpret_cast<Packet_vkCreateIOSSurfaceMVK*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateMacOSSurfaceMVK:
        Replay_vkCreateMacOSSurfaceMVK(reinterpret_cast<Packet_vkCreateMacOSSurfaceMVK*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetDebugUtilsObjectNameEXT:
        Replay_vkSetDebugUtilsObjectNameEXT(reinterpret_cast<Packet_vkSetDebugUtilsObjectNameEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetDebugUtilsObjectTagEXT:
        Replay_vkSetDebugUtilsObjectTagEXT(reinterpret_cast<Packet_vkSetDebugUtilsObjectTagEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueBeginDebugUtilsLabelEXT:
        Replay_vkQueueBeginDebugUtilsLabelEXT(reinterpret_cast<Packet_vkQueueBeginDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueEndDebugUtilsLabelEXT:
        Replay_vkQueueEndDebugUtilsLabelEXT(reinterpret_cast<Packet_vkQueueEndDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueInsertDebugUtilsLabelEXT:
        Replay_vkQueueInsertDebugUtilsLabelEXT(reinterpret_cast<Packet_vkQueueInsertDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBeginDebugUtilsLabelEXT:
        Replay_vkCmdBeginDebugUtilsLabelEXT(reinterpret_cast<Packet_vkCmdBeginDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdEndDebugUtilsLabelEXT:
        Replay_vkCmdEndDebugUtilsLabelEXT(reinterpret_cast<Packet_vkCmdEndDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdInsertDebugUtilsLabelEXT:
        Replay_vkCmdInsertDebugUtilsLabelEXT(reinterpret_cast<Packet_vkCmdInsertDebugUtilsLabelEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDebugUtilsMessengerEXT:
        Replay_vkCreateDebugUtilsMessengerEXT(reinterpret_cast<Packet_vkCreateDebugUtilsMessengerEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyDebugUtilsMessengerEXT:
        Replay_vkDestroyDebugUtilsMessengerEXT(reinterpret_cast<Packet_vkDestroyDebugUtilsMessengerEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSubmitDebugUtilsMessageEXT:
        Replay_vkSubmitDebugUtilsMessageEXT(reinterpret_cast<Packet_vkSubmitDebugUtilsMessageEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetAndroidHardwareBufferPropertiesANDROID:
        Replay_vkGetAndroidHardwareBufferPropertiesANDROID(reinterpret_cast<Packet_vkGetAndroidHardwareBufferPropertiesANDROID*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryAndroidHardwareBufferANDROID:
        Replay_vkGetMemoryAndroidHardwareBufferANDROID(reinterpret_cast<Packet_vkGetMemoryAndroidHardwareBufferANDROID*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetSampleLocationsEXT:
        Replay_vkCmdSetSampleLocationsEXT(reinterpret_cast<Packet_vkCmdSetSampleLocationsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceMultisamplePropertiesEXT:
        Replay_vkGetPhysicalDeviceMultisamplePropertiesEXT(reinterpret_cast<Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageDrmFormatModifierPropertiesEXT:
        Replay_vkGetImageDrmFormatModifierPropertiesEXT(reinterpret_cast<Packet_vkGetImageDrmFormatModifierPropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateValidationCacheEXT:
        Replay_vkCreateValidationCacheEXT(reinterpret_cast<Packet_vkCreateValidationCacheEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyValidationCacheEXT:
        Replay_vkDestroyValidationCacheEXT(reinterpret_cast<Packet_vkDestroyValidationCacheEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkMergeValidationCachesEXT:
        Replay_vkMergeValidationCachesEXT(reinterpret_cast<Packet_vkMergeValidationCachesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetValidationCacheDataEXT:
        Replay_vkGetValidationCacheDataEXT(reinterpret_cast<Packet_vkGetValidationCacheDataEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindShadingRateImageNV:
        Replay_vkCmdBindShadingRateImageNV(reinterpret_cast<Packet_vkCmdBindShadingRateImageNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportShadingRatePaletteNV:
        Replay_vkCmdSetViewportShadingRatePaletteNV(reinterpret_cast<Packet_vkCmdSetViewportShadingRatePaletteNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoarseSampleOrderNV:
        Replay_vkCmdSetCoarseSampleOrderNV(reinterpret_cast<Packet_vkCmdSetCoarseSampleOrderNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateAccelerationStructureNV:
        Replay_vkCreateAccelerationStructureNV(reinterpret_cast<Packet_vkCreateAccelerationStructureNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyAccelerationStructureNV:
        Replay_vkDestroyAccelerationStructureNV(reinterpret_cast<Packet_vkDestroyAccelerationStructureNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetAccelerationStructureMemoryRequirementsNV:
        Replay_vkGetAccelerationStructureMemoryRequirementsNV(reinterpret_cast<Packet_vkGetAccelerationStructureMemoryRequirementsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindAccelerationStructureMemoryNV:
        Replay_vkBindAccelerationStructureMemoryNV(reinterpret_cast<Packet_vkBindAccelerationStructureMemoryNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBuildAccelerationStructureNV:
        Replay_vkCmdBuildAccelerationStructureNV(reinterpret_cast<Packet_vkCmdBuildAccelerationStructureNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyAccelerationStructureNV:
        Replay_vkCmdCopyAccelerationStructureNV(reinterpret_cast<Packet_vkCmdCopyAccelerationStructureNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdTraceRaysNV:
        Replay_vkCmdTraceRaysNV(reinterpret_cast<Packet_vkCmdTraceRaysNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateRayTracingPipelinesNV:
        Replay_vkCreateRayTracingPipelinesNV(reinterpret_cast<Packet_vkCreateRayTracingPipelinesNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRayTracingShaderGroupHandlesKHR:
        Replay_vkGetRayTracingShaderGroupHandlesKHR(reinterpret_cast<Packet_vkGetRayTracingShaderGroupHandlesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRayTracingShaderGroupHandlesNV:
        Replay_vkGetRayTracingShaderGroupHandlesNV(reinterpret_cast<Packet_vkGetRayTracingShaderGroupHandlesNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetAccelerationStructureHandleNV:
        Replay_vkGetAccelerationStructureHandleNV(reinterpret_cast<Packet_vkGetAccelerationStructureHandleNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteAccelerationStructuresPropertiesNV:
        Replay_vkCmdWriteAccelerationStructuresPropertiesNV(reinterpret_cast<Packet_vkCmdWriteAccelerationStructuresPropertiesNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCompileDeferredNV:
        Replay_vkCompileDeferredNV(reinterpret_cast<Packet_vkCompileDeferredNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryHostPointerPropertiesEXT:
        Replay_vkGetMemoryHostPointerPropertiesEXT(reinterpret_cast<Packet_vkGetMemoryHostPointerPropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteBufferMarkerAMD:
        Replay_vkCmdWriteBufferMarkerAMD(reinterpret_cast<Packet_vkCmdWriteBufferMarkerAMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT:
        Replay_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(reinterpret_cast<Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetCalibratedTimestampsEXT:
        Replay_vkGetCalibratedTimestampsEXT(reinterpret_cast<Packet_vkGetCalibratedTimestampsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksNV:
        Replay_vkCmdDrawMeshTasksNV(reinterpret_cast<Packet_vkCmdDrawMeshTasksNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksIndirectNV:
        Replay_vkCmdDrawMeshTasksIndirectNV(reinterpret_cast<Packet_vkCmdDrawMeshTasksIndirectNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksIndirectCountNV:
        Replay_vkCmdDrawMeshTasksIndirectCountNV(reinterpret_cast<Packet_vkCmdDrawMeshTasksIndirectCountNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetExclusiveScissorEnableNV:
        Replay_vkCmdSetExclusiveScissorEnableNV(reinterpret_cast<Packet_vkCmdSetExclusiveScissorEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetExclusiveScissorNV:
        Replay_vkCmdSetExclusiveScissorNV(reinterpret_cast<Packet_vkCmdSetExclusiveScissorNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCheckpointNV:
        Replay_vkCmdSetCheckpointNV(reinterpret_cast<Packet_vkCmdSetCheckpointNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetQueueCheckpointDataNV:
        Replay_vkGetQueueCheckpointDataNV(reinterpret_cast<Packet_vkGetQueueCheckpointDataNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkInitializePerformanceApiINTEL:
        Replay_vkInitializePerformanceApiINTEL(reinterpret_cast<Packet_vkInitializePerformanceApiINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkUninitializePerformanceApiINTEL:
        Replay_vkUninitializePerformanceApiINTEL(reinterpret_cast<Packet_vkUninitializePerformanceApiINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPerformanceMarkerINTEL:
        Replay_vkCmdSetPerformanceMarkerINTEL(reinterpret_cast<Packet_vkCmdSetPerformanceMarkerINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPerformanceStreamMarkerINTEL:
        Replay_vkCmdSetPerformanceStreamMarkerINTEL(reinterpret_cast<Packet_vkCmdSetPerformanceStreamMarkerINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPerformanceOverrideINTEL:
        Replay_vkCmdSetPerformanceOverrideINTEL(reinterpret_cast<Packet_vkCmdSetPerformanceOverrideINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquirePerformanceConfigurationINTEL:
        Replay_vkAcquirePerformanceConfigurationINTEL(reinterpret_cast<Packet_vkAcquirePerformanceConfigurationINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkReleasePerformanceConfigurationINTEL:
        Replay_vkReleasePerformanceConfigurationINTEL(reinterpret_cast<Packet_vkReleasePerformanceConfigurationINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueSetPerformanceConfigurationINTEL:
        Replay_vkQueueSetPerformanceConfigurationINTEL(reinterpret_cast<Packet_vkQueueSetPerformanceConfigurationINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPerformanceParameterINTEL:
        Replay_vkGetPerformanceParameterINTEL(reinterpret_cast<Packet_vkGetPerformanceParameterINTEL*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetLocalDimmingAMD:
        Replay_vkSetLocalDimmingAMD(reinterpret_cast<Packet_vkSetLocalDimmingAMD*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateImagePipeSurfaceFUCHSIA:
        Replay_vkCreateImagePipeSurfaceFUCHSIA(reinterpret_cast<Packet_vkCreateImagePipeSurfaceFUCHSIA*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateMetalSurfaceEXT:
        Replay_vkCreateMetalSurfaceEXT(reinterpret_cast<Packet_vkCreateMetalSurfaceEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetBufferDeviceAddressEXT:
        Replay_vkGetBufferDeviceAddressEXT(reinterpret_cast<Packet_vkGetBufferDeviceAddressEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceToolPropertiesEXT:
        Replay_vkGetPhysicalDeviceToolPropertiesEXT(reinterpret_cast<Packet_vkGetPhysicalDeviceToolPropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV:
        Replay_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(reinterpret_cast<Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV:
        Replay_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(reinterpret_cast<Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceSurfacePresentModes2EXT:
        Replay_vkGetPhysicalDeviceSurfacePresentModes2EXT(reinterpret_cast<Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireFullScreenExclusiveModeEXT:
        Replay_vkAcquireFullScreenExclusiveModeEXT(reinterpret_cast<Packet_vkAcquireFullScreenExclusiveModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkReleaseFullScreenExclusiveModeEXT:
        Replay_vkReleaseFullScreenExclusiveModeEXT(reinterpret_cast<Packet_vkReleaseFullScreenExclusiveModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceGroupSurfacePresentModes2EXT:
        Replay_vkGetDeviceGroupSurfacePresentModes2EXT(reinterpret_cast<Packet_vkGetDeviceGroupSurfacePresentModes2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateHeadlessSurfaceEXT:
        Replay_vkCreateHeadlessSurfaceEXT(reinterpret_cast<Packet_vkCreateHeadlessSurfaceEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLineStippleEXT:
        Replay_vkCmdSetLineStippleEXT(reinterpret_cast<Packet_vkCmdSetLineStippleEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkResetQueryPoolEXT:
        Replay_vkResetQueryPoolEXT(reinterpret_cast<Packet_vkResetQueryPoolEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCullModeEXT:
        Replay_vkCmdSetCullModeEXT(reinterpret_cast<Packet_vkCmdSetCullModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetFrontFaceEXT:
        Replay_vkCmdSetFrontFaceEXT(reinterpret_cast<Packet_vkCmdSetFrontFaceEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPrimitiveTopologyEXT:
        Replay_vkCmdSetPrimitiveTopologyEXT(reinterpret_cast<Packet_vkCmdSetPrimitiveTopologyEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportWithCountEXT:
        Replay_vkCmdSetViewportWithCountEXT(reinterpret_cast<Packet_vkCmdSetViewportWithCountEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetScissorWithCountEXT:
        Replay_vkCmdSetScissorWithCountEXT(reinterpret_cast<Packet_vkCmdSetScissorWithCountEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindVertexBuffers2EXT:
        Replay_vkCmdBindVertexBuffers2EXT(reinterpret_cast<Packet_vkCmdBindVertexBuffers2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthTestEnableEXT:
        Replay_vkCmdSetDepthTestEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthTestEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthWriteEnableEXT:
        Replay_vkCmdSetDepthWriteEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthWriteEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthCompareOpEXT:
        Replay_vkCmdSetDepthCompareOpEXT(reinterpret_cast<Packet_vkCmdSetDepthCompareOpEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBoundsTestEnableEXT:
        Replay_vkCmdSetDepthBoundsTestEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthBoundsTestEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilTestEnableEXT:
        Replay_vkCmdSetStencilTestEnableEXT(reinterpret_cast<Packet_vkCmdSetStencilTestEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetStencilOpEXT:
        Replay_vkCmdSetStencilOpEXT(reinterpret_cast<Packet_vkCmdSetStencilOpEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyMemoryToImageEXT:
        Replay_vkCopyMemoryToImageEXT(reinterpret_cast<Packet_vkCopyMemoryToImageEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyImageToMemoryEXT:
        Replay_vkCopyImageToMemoryEXT(reinterpret_cast<Packet_vkCopyImageToMemoryEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyImageToImageEXT:
        Replay_vkCopyImageToImageEXT(reinterpret_cast<Packet_vkCopyImageToImageEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkTransitionImageLayoutEXT:
        Replay_vkTransitionImageLayoutEXT(reinterpret_cast<Packet_vkTransitionImageLayoutEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetImageSubresourceLayout2EXT:
        Replay_vkGetImageSubresourceLayout2EXT(reinterpret_cast<Packet_vkGetImageSubresourceLayout2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkReleaseSwapchainImagesEXT:
        Replay_vkReleaseSwapchainImagesEXT(reinterpret_cast<Packet_vkReleaseSwapchainImagesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetGeneratedCommandsMemoryRequirementsNV:
        Replay_vkGetGeneratedCommandsMemoryRequirementsNV(reinterpret_cast<Packet_vkGetGeneratedCommandsMemoryRequirementsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdPreprocessGeneratedCommandsNV:
        Replay_vkCmdPreprocessGeneratedCommandsNV(reinterpret_cast<Packet_vkCmdPreprocessGeneratedCommandsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdExecuteGeneratedCommandsNV:
        Replay_vkCmdExecuteGeneratedCommandsNV(reinterpret_cast<Packet_vkCmdExecuteGeneratedCommandsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindPipelineShaderGroupNV:
        Replay_vkCmdBindPipelineShaderGroupNV(reinterpret_cast<Packet_vkCmdBindPipelineShaderGroupNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateIndirectCommandsLayoutNV:
        Replay_vkCreateIndirectCommandsLayoutNV(reinterpret_cast<Packet_vkCreateIndirectCommandsLayoutNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyIndirectCommandsLayoutNV:
        Replay_vkDestroyIndirectCommandsLayoutNV(reinterpret_cast<Packet_vkDestroyIndirectCommandsLayoutNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBias2EXT:
        Replay_vkCmdSetDepthBias2EXT(reinterpret_cast<Packet_vkCmdSetDepthBias2EXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireDrmDisplayEXT:
        Replay_vkAcquireDrmDisplayEXT(reinterpret_cast<Packet_vkAcquireDrmDisplayEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDrmDisplayEXT:
        Replay_vkGetDrmDisplayEXT(reinterpret_cast<Packet_vkGetDrmDisplayEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreatePrivateDataSlotEXT:
        Replay_vkCreatePrivateDataSlotEXT(reinterpret_cast<Packet_vkCreatePrivateDataSlotEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyPrivateDataSlotEXT:
        Replay_vkDestroyPrivateDataSlotEXT(reinterpret_cast<Packet_vkDestroyPrivateDataSlotEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetPrivateDataEXT:
        Replay_vkSetPrivateDataEXT(reinterpret_cast<Packet_vkSetPrivateDataEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPrivateDataEXT:
        Replay_vkGetPrivateDataEXT(reinterpret_cast<Packet_vkGetPrivateDataEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetFragmentShadingRateEnumNV:
        Replay_vkCmdSetFragmentShadingRateEnumNV(reinterpret_cast<Packet_vkCmdSetFragmentShadingRateEnumNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceFaultInfoEXT:
        Replay_vkGetDeviceFaultInfoEXT(reinterpret_cast<Packet_vkGetDeviceFaultInfoEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkAcquireWinrtDisplayNV:
        Replay_vkAcquireWinrtDisplayNV(reinterpret_cast<Packet_vkAcquireWinrtDisplayNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetWinrtDisplayNV:
        Replay_vkGetWinrtDisplayNV(reinterpret_cast<Packet_vkGetWinrtDisplayNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateDirectFBSurfaceEXT:
        Replay_vkCreateDirectFBSurfaceEXT(reinterpret_cast<Packet_vkCreateDirectFBSurfaceEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT:
        Replay_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(reinterpret_cast<Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetVertexInputEXT:
        Replay_vkCmdSetVertexInputEXT(reinterpret_cast<Packet_vkCmdSetVertexInputEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryZirconHandleFUCHSIA:
        Replay_vkGetMemoryZirconHandleFUCHSIA(reinterpret_cast<Packet_vkGetMemoryZirconHandleFUCHSIA*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryZirconHandlePropertiesFUCHSIA:
        Replay_vkGetMemoryZirconHandlePropertiesFUCHSIA(reinterpret_cast<Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkImportSemaphoreZirconHandleFUCHSIA:
        Replay_vkImportSemaphoreZirconHandleFUCHSIA(reinterpret_cast<Packet_vkImportSemaphoreZirconHandleFUCHSIA*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetSemaphoreZirconHandleFUCHSIA:
        Replay_vkGetSemaphoreZirconHandleFUCHSIA(reinterpret_cast<Packet_vkGetSemaphoreZirconHandleFUCHSIA*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindInvocationMaskHUAWEI:
        Replay_vkCmdBindInvocationMaskHUAWEI(reinterpret_cast<Packet_vkCmdBindInvocationMaskHUAWEI*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMemoryRemoteAddressNV:
        Replay_vkGetMemoryRemoteAddressNV(reinterpret_cast<Packet_vkGetMemoryRemoteAddressNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPatchControlPointsEXT:
        Replay_vkCmdSetPatchControlPointsEXT(reinterpret_cast<Packet_vkCmdSetPatchControlPointsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRasterizerDiscardEnableEXT:
        Replay_vkCmdSetRasterizerDiscardEnableEXT(reinterpret_cast<Packet_vkCmdSetRasterizerDiscardEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthBiasEnableEXT:
        Replay_vkCmdSetDepthBiasEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthBiasEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLogicOpEXT:
        Replay_vkCmdSetLogicOpEXT(reinterpret_cast<Packet_vkCmdSetLogicOpEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPrimitiveRestartEnableEXT:
        Replay_vkCmdSetPrimitiveRestartEnableEXT(reinterpret_cast<Packet_vkCmdSetPrimitiveRestartEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateScreenSurfaceQNX:
        Replay_vkCreateScreenSurfaceQNX(reinterpret_cast<Packet_vkCreateScreenSurfaceQNX*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceScreenPresentationSupportQNX:
        Replay_vkGetPhysicalDeviceScreenPresentationSupportQNX(reinterpret_cast<Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetColorWriteEnableEXT:
        Replay_vkCmdSetColorWriteEnableEXT(reinterpret_cast<Packet_vkCmdSetColorWriteEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMultiEXT:
        Replay_vkCmdDrawMultiEXT(reinterpret_cast<Packet_vkCmdDrawMultiEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMultiIndexedEXT:
        Replay_vkCmdDrawMultiIndexedEXT(reinterpret_cast<Packet_vkCmdDrawMultiIndexedEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateMicromapEXT:
        Replay_vkCreateMicromapEXT(reinterpret_cast<Packet_vkCreateMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyMicromapEXT:
        Replay_vkDestroyMicromapEXT(reinterpret_cast<Packet_vkDestroyMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBuildMicromapsEXT:
        Replay_vkCmdBuildMicromapsEXT(reinterpret_cast<Packet_vkCmdBuildMicromapsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBuildMicromapsEXT:
        Replay_vkBuildMicromapsEXT(reinterpret_cast<Packet_vkBuildMicromapsEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyMicromapEXT:
        Replay_vkCopyMicromapEXT(reinterpret_cast<Packet_vkCopyMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyMicromapToMemoryEXT:
        Replay_vkCopyMicromapToMemoryEXT(reinterpret_cast<Packet_vkCopyMicromapToMemoryEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyMemoryToMicromapEXT:
        Replay_vkCopyMemoryToMicromapEXT(reinterpret_cast<Packet_vkCopyMemoryToMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWriteMicromapsPropertiesEXT:
        Replay_vkWriteMicromapsPropertiesEXT(reinterpret_cast<Packet_vkWriteMicromapsPropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyMicromapEXT:
        Replay_vkCmdCopyMicromapEXT(reinterpret_cast<Packet_vkCmdCopyMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyMicromapToMemoryEXT:
        Replay_vkCmdCopyMicromapToMemoryEXT(reinterpret_cast<Packet_vkCmdCopyMicromapToMemoryEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyMemoryToMicromapEXT:
        Replay_vkCmdCopyMemoryToMicromapEXT(reinterpret_cast<Packet_vkCmdCopyMemoryToMicromapEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteMicromapsPropertiesEXT:
        Replay_vkCmdWriteMicromapsPropertiesEXT(reinterpret_cast<Packet_vkCmdWriteMicromapsPropertiesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceMicromapCompatibilityEXT:
        Replay_vkGetDeviceMicromapCompatibilityEXT(reinterpret_cast<Packet_vkGetDeviceMicromapCompatibilityEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetMicromapBuildSizesEXT:
        Replay_vkGetMicromapBuildSizesEXT(reinterpret_cast<Packet_vkGetMicromapBuildSizesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawClusterHUAWEI:
        Replay_vkCmdDrawClusterHUAWEI(reinterpret_cast<Packet_vkCmdDrawClusterHUAWEI*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawClusterIndirectHUAWEI:
        Replay_vkCmdDrawClusterIndirectHUAWEI(reinterpret_cast<Packet_vkCmdDrawClusterIndirectHUAWEI*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetDeviceMemoryPriorityEXT:
        Replay_vkSetDeviceMemoryPriorityEXT(reinterpret_cast<Packet_vkSetDeviceMemoryPriorityEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE:
        Replay_vkGetDescriptorSetLayoutHostMappingInfoVALVE(reinterpret_cast<Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDescriptorSetHostMappingVALVE:
        Replay_vkGetDescriptorSetHostMappingVALVE(reinterpret_cast<Packet_vkGetDescriptorSetHostMappingVALVE*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineIndirectMemoryRequirementsNV:
        Replay_vkGetPipelineIndirectMemoryRequirementsNV(reinterpret_cast<Packet_vkGetPipelineIndirectMemoryRequirementsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdUpdatePipelineIndirectBufferNV:
        Replay_vkCmdUpdatePipelineIndirectBufferNV(reinterpret_cast<Packet_vkCmdUpdatePipelineIndirectBufferNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPipelineIndirectDeviceAddressNV:
        Replay_vkGetPipelineIndirectDeviceAddressNV(reinterpret_cast<Packet_vkGetPipelineIndirectDeviceAddressNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthClampEnableEXT:
        Replay_vkCmdSetDepthClampEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthClampEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetPolygonModeEXT:
        Replay_vkCmdSetPolygonModeEXT(reinterpret_cast<Packet_vkCmdSetPolygonModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRasterizationSamplesEXT:
        Replay_vkCmdSetRasterizationSamplesEXT(reinterpret_cast<Packet_vkCmdSetRasterizationSamplesEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetSampleMaskEXT:
        Replay_vkCmdSetSampleMaskEXT(reinterpret_cast<Packet_vkCmdSetSampleMaskEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetAlphaToCoverageEnableEXT:
        Replay_vkCmdSetAlphaToCoverageEnableEXT(reinterpret_cast<Packet_vkCmdSetAlphaToCoverageEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetAlphaToOneEnableEXT:
        Replay_vkCmdSetAlphaToOneEnableEXT(reinterpret_cast<Packet_vkCmdSetAlphaToOneEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLogicOpEnableEXT:
        Replay_vkCmdSetLogicOpEnableEXT(reinterpret_cast<Packet_vkCmdSetLogicOpEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetColorBlendEnableEXT:
        Replay_vkCmdSetColorBlendEnableEXT(reinterpret_cast<Packet_vkCmdSetColorBlendEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetColorBlendEquationEXT:
        Replay_vkCmdSetColorBlendEquationEXT(reinterpret_cast<Packet_vkCmdSetColorBlendEquationEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetColorWriteMaskEXT:
        Replay_vkCmdSetColorWriteMaskEXT(reinterpret_cast<Packet_vkCmdSetColorWriteMaskEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetTessellationDomainOriginEXT:
        Replay_vkCmdSetTessellationDomainOriginEXT(reinterpret_cast<Packet_vkCmdSetTessellationDomainOriginEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRasterizationStreamEXT:
        Replay_vkCmdSetRasterizationStreamEXT(reinterpret_cast<Packet_vkCmdSetRasterizationStreamEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetConservativeRasterizationModeEXT:
        Replay_vkCmdSetConservativeRasterizationModeEXT(reinterpret_cast<Packet_vkCmdSetConservativeRasterizationModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT:
        Replay_vkCmdSetExtraPrimitiveOverestimationSizeEXT(reinterpret_cast<Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthClipEnableEXT:
        Replay_vkCmdSetDepthClipEnableEXT(reinterpret_cast<Packet_vkCmdSetDepthClipEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetSampleLocationsEnableEXT:
        Replay_vkCmdSetSampleLocationsEnableEXT(reinterpret_cast<Packet_vkCmdSetSampleLocationsEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetColorBlendAdvancedEXT:
        Replay_vkCmdSetColorBlendAdvancedEXT(reinterpret_cast<Packet_vkCmdSetColorBlendAdvancedEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetProvokingVertexModeEXT:
        Replay_vkCmdSetProvokingVertexModeEXT(reinterpret_cast<Packet_vkCmdSetProvokingVertexModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLineRasterizationModeEXT:
        Replay_vkCmdSetLineRasterizationModeEXT(reinterpret_cast<Packet_vkCmdSetLineRasterizationModeEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetLineStippleEnableEXT:
        Replay_vkCmdSetLineStippleEnableEXT(reinterpret_cast<Packet_vkCmdSetLineStippleEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetDepthClipNegativeOneToOneEXT:
        Replay_vkCmdSetDepthClipNegativeOneToOneEXT(reinterpret_cast<Packet_vkCmdSetDepthClipNegativeOneToOneEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportWScalingEnableNV:
        Replay_vkCmdSetViewportWScalingEnableNV(reinterpret_cast<Packet_vkCmdSetViewportWScalingEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetViewportSwizzleNV:
        Replay_vkCmdSetViewportSwizzleNV(reinterpret_cast<Packet_vkCmdSetViewportSwizzleNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageToColorEnableNV:
        Replay_vkCmdSetCoverageToColorEnableNV(reinterpret_cast<Packet_vkCmdSetCoverageToColorEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageToColorLocationNV:
        Replay_vkCmdSetCoverageToColorLocationNV(reinterpret_cast<Packet_vkCmdSetCoverageToColorLocationNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageModulationModeNV:
        Replay_vkCmdSetCoverageModulationModeNV(reinterpret_cast<Packet_vkCmdSetCoverageModulationModeNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageModulationTableEnableNV:
        Replay_vkCmdSetCoverageModulationTableEnableNV(reinterpret_cast<Packet_vkCmdSetCoverageModulationTableEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageModulationTableNV:
        Replay_vkCmdSetCoverageModulationTableNV(reinterpret_cast<Packet_vkCmdSetCoverageModulationTableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetShadingRateImageEnableNV:
        Replay_vkCmdSetShadingRateImageEnableNV(reinterpret_cast<Packet_vkCmdSetShadingRateImageEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRepresentativeFragmentTestEnableNV:
        Replay_vkCmdSetRepresentativeFragmentTestEnableNV(reinterpret_cast<Packet_vkCmdSetRepresentativeFragmentTestEnableNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetCoverageReductionModeNV:
        Replay_vkCmdSetCoverageReductionModeNV(reinterpret_cast<Packet_vkCmdSetCoverageReductionModeNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetShaderModuleIdentifierEXT:
        Replay_vkGetShaderModuleIdentifierEXT(reinterpret_cast<Packet_vkGetShaderModuleIdentifierEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetShaderModuleCreateInfoIdentifierEXT:
        Replay_vkGetShaderModuleCreateInfoIdentifierEXT(reinterpret_cast<Packet_vkGetShaderModuleCreateInfoIdentifierEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV:
        Replay_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(reinterpret_cast<Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateOpticalFlowSessionNV:
        Replay_vkCreateOpticalFlowSessionNV(reinterpret_cast<Packet_vkCreateOpticalFlowSessionNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyOpticalFlowSessionNV:
        Replay_vkDestroyOpticalFlowSessionNV(reinterpret_cast<Packet_vkDestroyOpticalFlowSessionNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkBindOpticalFlowSessionImageNV:
        Replay_vkBindOpticalFlowSessionImageNV(reinterpret_cast<Packet_vkBindOpticalFlowSessionImageNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdOpticalFlowExecuteNV:
        Replay_vkCmdOpticalFlowExecuteNV(reinterpret_cast<Packet_vkCmdOpticalFlowExecuteNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateShadersEXT:
        Replay_vkCreateShadersEXT(reinterpret_cast<Packet_vkCreateShadersEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyShaderEXT:
        Replay_vkDestroyShaderEXT(reinterpret_cast<Packet_vkDestroyShaderEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetShaderBinaryDataEXT:
        Replay_vkGetShaderBinaryDataEXT(reinterpret_cast<Packet_vkGetShaderBinaryDataEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBindShadersEXT:
        Replay_vkCmdBindShadersEXT(reinterpret_cast<Packet_vkCmdBindShadersEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetFramebufferTilePropertiesQCOM:
        Replay_vkGetFramebufferTilePropertiesQCOM(reinterpret_cast<Packet_vkGetFramebufferTilePropertiesQCOM*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDynamicRenderingTilePropertiesQCOM:
        Replay_vkGetDynamicRenderingTilePropertiesQCOM(reinterpret_cast<Packet_vkGetDynamicRenderingTilePropertiesQCOM*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetLatencySleepModeNV:
        Replay_vkSetLatencySleepModeNV(reinterpret_cast<Packet_vkSetLatencySleepModeNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkLatencySleepNV:
        Replay_vkLatencySleepNV(reinterpret_cast<Packet_vkLatencySleepNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkSetLatencyMarkerNV:
        Replay_vkSetLatencyMarkerNV(reinterpret_cast<Packet_vkSetLatencyMarkerNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetLatencyTimingsNV:
        Replay_vkGetLatencyTimingsNV(reinterpret_cast<Packet_vkGetLatencyTimingsNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkQueueNotifyOutOfBandNV:
        Replay_vkQueueNotifyOutOfBandNV(reinterpret_cast<Packet_vkQueueNotifyOutOfBandNV*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetAttachmentFeedbackLoopEnableEXT:
        Replay_vkCmdSetAttachmentFeedbackLoopEnableEXT(reinterpret_cast<Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCreateAccelerationStructureKHR:
        Replay_vkCreateAccelerationStructureKHR(reinterpret_cast<Packet_vkCreateAccelerationStructureKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkDestroyAccelerationStructureKHR:
        Replay_vkDestroyAccelerationStructureKHR(reinterpret_cast<Packet_vkDestroyAccelerationStructureKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBuildAccelerationStructuresKHR:
        Replay_vkCmdBuildAccelerationStructuresKHR(reinterpret_cast<Packet_vkCmdBuildAccelerationStructuresKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdBuildAccelerationStructuresIndirectKHR:
        Replay_vkCmdBuildAccelerationStructuresIndirectKHR(reinterpret_cast<Packet_vkCmdBuildAccelerationStructuresIndirectKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyAccelerationStructureToMemoryKHR:
        Replay_vkCopyAccelerationStructureToMemoryKHR(reinterpret_cast<Packet_vkCopyAccelerationStructureToMemoryKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCopyMemoryToAccelerationStructureKHR:
        Replay_vkCopyMemoryToAccelerationStructureKHR(reinterpret_cast<Packet_vkCopyMemoryToAccelerationStructureKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkWriteAccelerationStructuresPropertiesKHR:
        Replay_vkWriteAccelerationStructuresPropertiesKHR(reinterpret_cast<Packet_vkWriteAccelerationStructuresPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyAccelerationStructureKHR:
        Replay_vkCmdCopyAccelerationStructureKHR(reinterpret_cast<Packet_vkCmdCopyAccelerationStructureKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyAccelerationStructureToMemoryKHR:
        Replay_vkCmdCopyAccelerationStructureToMemoryKHR(reinterpret_cast<Packet_vkCmdCopyAccelerationStructureToMemoryKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdCopyMemoryToAccelerationStructureKHR:
        Replay_vkCmdCopyMemoryToAccelerationStructureKHR(reinterpret_cast<Packet_vkCmdCopyMemoryToAccelerationStructureKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetAccelerationStructureDeviceAddressKHR:
        Replay_vkGetAccelerationStructureDeviceAddressKHR(reinterpret_cast<Packet_vkGetAccelerationStructureDeviceAddressKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdWriteAccelerationStructuresPropertiesKHR:
        Replay_vkCmdWriteAccelerationStructuresPropertiesKHR(reinterpret_cast<Packet_vkCmdWriteAccelerationStructuresPropertiesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetDeviceAccelerationStructureCompatibilityKHR:
        Replay_vkGetDeviceAccelerationStructureCompatibilityKHR(reinterpret_cast<Packet_vkGetDeviceAccelerationStructureCompatibilityKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetAccelerationStructureBuildSizesKHR:
        Replay_vkGetAccelerationStructureBuildSizesKHR(reinterpret_cast<Packet_vkGetAccelerationStructureBuildSizesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdTraceRaysKHR:
        Replay_vkCmdTraceRaysKHR(reinterpret_cast<Packet_vkCmdTraceRaysKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR:
        Replay_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(reinterpret_cast<Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdTraceRaysIndirectKHR:
        Replay_vkCmdTraceRaysIndirectKHR(reinterpret_cast<Packet_vkCmdTraceRaysIndirectKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkGetRayTracingShaderGroupStackSizeKHR:
        Replay_vkGetRayTracingShaderGroupStackSizeKHR(reinterpret_cast<Packet_vkGetRayTracingShaderGroupStackSizeKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdSetRayTracingPipelineStackSizeKHR:
        Replay_vkCmdSetRayTracingPipelineStackSizeKHR(reinterpret_cast<Packet_vkCmdSetRayTracingPipelineStackSizeKHR*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksEXT:
        Replay_vkCmdDrawMeshTasksEXT(reinterpret_cast<Packet_vkCmdDrawMeshTasksEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksIndirectEXT:
        Replay_vkCmdDrawMeshTasksIndirectEXT(reinterpret_cast<Packet_vkCmdDrawMeshTasksIndirectEXT*>(packet));
        break;
    case format::PacketCallId::PacketCall_vkCmdDrawMeshTasksIndirectCountEXT:
        Replay_vkCmdDrawMeshTasksIndirectCountEXT(reinterpret_cast<Packet_vkCmdDrawMeshTasksIndirectCountEXT*>(packet));
        break;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
