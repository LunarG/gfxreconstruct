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

#ifndef  GFXRECON_GENERATED_VULKAN_DECODER_ARGS_H
#define  GFXRECON_GENERATED_VULKAN_DECODER_ARGS_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <tuple>

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(args)

struct CreateInstance
{
    VkResult result;
    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkInstance> pInstance;

    auto GetTuple() const { return std::tie(result, pCreateInfo, pAllocator, pInstance); }
};


struct DestroyInstance
{
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, pAllocator); }
};


struct EnumeratePhysicalDevices
{
    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceCount, pPhysicalDevices); }
};


struct GetPhysicalDeviceFeatures
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceFormatProperties
{
    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties
{
    VkResult result;
    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties); }
};


struct GetPhysicalDeviceProperties
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties
{
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct CreateDevice
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDevice> pDevice;

    auto GetTuple() const { return std::tie(result, physicalDevice, pCreateInfo, pAllocator, pDevice); }
};


struct DestroyDevice
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pAllocator); }
};


struct GetDeviceQueue
{
    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    HandlePointerDecoder<VkQueue> pQueue;

    auto GetTuple() const { return std::tie(device, queueFamilyIndex, queueIndex, pQueue); }
};


struct QueueSubmit
{
    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct QueueWaitIdle
{
    VkResult result;
    format::HandleId queue;

    auto GetTuple() const { return std::tie(result, queue); }
};


struct DeviceWaitIdle
{
    VkResult result;
    format::HandleId device;

    auto GetTuple() const { return std::tie(result, device); }
};


struct AllocateMemory
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeviceMemory> pMemory;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pAllocator, pMemory); }
};


struct FreeMemory
{
    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, memory, pAllocator); }
};


struct MapMemory
{
    VkResult result;
    format::HandleId device;
    format::HandleId memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(result, device, memory, offset, size, flags, ppData); }
};


struct UnmapMemory
{
    format::HandleId device;
    format::HandleId memory;

    auto GetTuple() const { return std::tie(device, memory); }
};


struct FlushMappedMemoryRanges
{
    VkResult result;
    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;

    auto GetTuple() const { return std::tie(result, device, memoryRangeCount, pMemoryRanges); }
};


struct InvalidateMappedMemoryRanges
{
    VkResult result;
    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;

    auto GetTuple() const { return std::tie(result, device, memoryRangeCount, pMemoryRanges); }
};


struct GetDeviceMemoryCommitment
{
    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    auto GetTuple() const { return std::tie(device, memory, pCommittedMemoryInBytes); }
};


struct BindBufferMemory
{
    VkResult result;
    format::HandleId device;
    format::HandleId buffer;
    format::HandleId memory;
    VkDeviceSize memoryOffset;

    auto GetTuple() const { return std::tie(result, device, buffer, memory, memoryOffset); }
};


struct BindImageMemory
{
    VkResult result;
    format::HandleId device;
    format::HandleId image;
    format::HandleId memory;
    VkDeviceSize memoryOffset;

    auto GetTuple() const { return std::tie(result, device, image, memory, memoryOffset); }
};


struct GetBufferMemoryRequirements
{
    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, buffer, pMemoryRequirements); }
};


struct GetImageMemoryRequirements
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, image, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements
{
    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct GetPhysicalDeviceSparseImageFormatProperties
{
    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties); }
};


struct QueueBindSparse
{
    VkResult result;
    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, bindInfoCount, pBindInfo, fence); }
};


struct CreateFence
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pFence); }
};


struct DestroyFence
{
    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, fence, pAllocator); }
};


struct ResetFences
{
    VkResult result;
    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;

    auto GetTuple() const { return std::tie(result, device, fenceCount, pFences); }
};


struct GetFenceStatus
{
    VkResult result;
    format::HandleId device;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, device, fence); }
};


struct WaitForFences
{
    VkResult result;
    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;
    VkBool32 waitAll;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, fenceCount, pFences, waitAll, timeout); }
};


struct CreateSemaphore
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSemaphore> pSemaphore;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSemaphore); }
};


struct DestroySemaphore
{
    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, semaphore, pAllocator); }
};


struct CreateQueryPool
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkQueryPool> pQueryPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pQueryPool); }
};


struct DestroyQueryPool
{
    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, queryPool, pAllocator); }
};


struct GetQueryPoolResults
{
    VkResult result;
    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    auto GetTuple() const { return std::tie(result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags); }
};


struct CreateBuffer
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBuffer> pBuffer;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pBuffer); }
};


struct DestroyBuffer
{
    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, buffer, pAllocator); }
};


struct CreateImage
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImage> pImage;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pImage); }
};


struct DestroyImage
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, image, pAllocator); }
};


struct GetImageSubresourceLayout
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct CreateImageView
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImageView> pView;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pView); }
};


struct DestroyImageView
{
    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, imageView, pAllocator); }
};


struct CreateCommandPool
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkCommandPool> pCommandPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pCommandPool); }
};


struct DestroyCommandPool
{
    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, commandPool, pAllocator); }
};


struct ResetCommandPool
{
    VkResult result;
    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolResetFlags flags;

    auto GetTuple() const { return std::tie(result, device, commandPool, flags); }
};


struct AllocateCommandBuffers
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pCommandBuffers); }
};


struct FreeCommandBuffers
{
    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(device, commandPool, commandBufferCount, pCommandBuffers); }
};


struct BeginCommandBuffer
{
    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pBeginInfo); }
};


struct EndCommandBuffer
{
    VkResult result;
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(result, commandBuffer); }
};


struct ResetCommandBuffer
{
    VkResult result;
    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;

    auto GetTuple() const { return std::tie(result, commandBuffer, flags); }
};


struct CmdCopyBuffer
{
    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions); }
};


struct CmdCopyImage
{
    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageCopy> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions); }
};


struct CmdCopyBufferToImage
{
    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions); }
};


struct CmdCopyImageToBuffer
{
    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions); }
};


struct CmdUpdateBuffer
{
    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(commandBuffer, dstBuffer, dstOffset, dataSize, pData); }
};


struct CmdFillBuffer
{
    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    auto GetTuple() const { return std::tie(commandBuffer, dstBuffer, dstOffset, size, data); }
};


struct CmdPipelineBarrier
{
    format::HandleId commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    auto GetTuple() const { return std::tie(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers); }
};


struct CmdBeginQuery
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, flags); }
};


struct CmdEndQuery
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query); }
};


struct CmdResetQueryPool
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, firstQuery, queryCount); }
};


struct CmdWriteTimestamp
{
    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStage, queryPool, query); }
};


struct CmdCopyQueryPoolResults
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags); }
};


struct CmdExecuteCommands
{
    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(commandBuffer, commandBufferCount, pCommandBuffers); }
};


struct CreateEvent
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkEvent> pEvent;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pEvent); }
};


struct DestroyEvent
{
    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, event, pAllocator); }
};


struct GetEventStatus
{
    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct SetEvent
{
    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct ResetEvent
{
    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct CreateBufferView
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBufferView> pView;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pView); }
};


struct DestroyBufferView
{
    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, bufferView, pAllocator); }
};


struct CreateShaderModule
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderModule> pShaderModule;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pShaderModule); }
};


struct DestroyShaderModule
{
    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, shaderModule, pAllocator); }
};


struct CreatePipelineCache
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineCache> pPipelineCache;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPipelineCache); }
};


struct DestroyPipelineCache
{
    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineCache, pAllocator); }
};


struct GetPipelineCacheData
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pipelineCache, pDataSize, pData); }
};


struct MergePipelineCaches
{
    VkResult result;
    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkPipelineCache> pSrcCaches;

    auto GetTuple() const { return std::tie(result, device, dstCache, srcCacheCount, pSrcCaches); }
};


struct CreateComputePipelines
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;

    auto GetTuple() const { return std::tie(result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }
};


struct DestroyPipeline
{
    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipeline, pAllocator); }
};


struct CreatePipelineLayout
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineLayout> pPipelineLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPipelineLayout); }
};


struct DestroyPipelineLayout
{
    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineLayout, pAllocator); }
};


struct CreateSampler
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSampler> pSampler;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSampler); }
};


struct DestroySampler
{
    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, sampler, pAllocator); }
};


struct CreateDescriptorSetLayout
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSetLayout); }
};


struct DestroyDescriptorSetLayout
{
    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorSetLayout, pAllocator); }
};


struct CreateDescriptorPool
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorPool> pDescriptorPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorPool); }
};


struct DestroyDescriptorPool
{
    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorPool, pAllocator); }
};


struct ResetDescriptorPool
{
    VkResult result;
    format::HandleId device;
    format::HandleId descriptorPool;
    VkDescriptorPoolResetFlags flags;

    auto GetTuple() const { return std::tie(result, device, descriptorPool, flags); }
};


struct AllocateDescriptorSets
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pDescriptorSets); }
};


struct FreeDescriptorSets
{
    VkResult result;
    format::HandleId device;
    format::HandleId descriptorPool;
    uint32_t descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;

    auto GetTuple() const { return std::tie(result, device, descriptorPool, descriptorSetCount, pDescriptorSets); }
};


struct UpdateDescriptorSets
{
    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    auto GetTuple() const { return std::tie(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies); }
};


struct CmdBindPipeline
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline); }
};


struct CmdBindDescriptorSets
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    uint32_t dynamicOffsetCount;
    PointerDecoder<uint32_t> pDynamicOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets); }
};


struct CmdClearColorImage
{
    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    auto GetTuple() const { return std::tie(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges); }
};


struct CmdDispatch
{
    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDispatchIndirect
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset); }
};


struct CmdSetEvent
{
    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdResetEvent
{
    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents
{
    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    auto GetTuple() const { return std::tie(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers); }
};


struct CmdPushConstants
{
    format::HandleId commandBuffer;
    format::HandleId layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    PointerDecoder<uint8_t> pValues;

    auto GetTuple() const { return std::tie(commandBuffer, layout, stageFlags, offset, size, pValues); }
};


struct CreateGraphicsPipelines
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;

    auto GetTuple() const { return std::tie(result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }
};


struct CreateFramebuffer
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFramebuffer> pFramebuffer;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pFramebuffer); }
};


struct DestroyFramebuffer
{
    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, framebuffer, pAllocator); }
};


struct CreateRenderPass
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct DestroyRenderPass
{
    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, renderPass, pAllocator); }
};


struct GetRenderAreaGranularity
{
    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, renderPass, pGranularity); }
};


struct CmdSetViewport
{
    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewports); }
};


struct CmdSetScissor
{
    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, firstScissor, scissorCount, pScissors); }
};


struct CmdSetLineWidth
{
    format::HandleId commandBuffer;
    float lineWidth;

    auto GetTuple() const { return std::tie(commandBuffer, lineWidth); }
};


struct CmdSetDepthBias
{
    format::HandleId commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor); }
};


struct CmdSetBlendConstants
{
    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    auto GetTuple() const { return std::tie(commandBuffer, blendConstants); }
};


struct CmdSetDepthBounds
{
    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    auto GetTuple() const { return std::tie(commandBuffer, minDepthBounds, maxDepthBounds); }
};


struct CmdSetStencilCompareMask
{
    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, compareMask); }
};


struct CmdSetStencilWriteMask
{
    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, writeMask); }
};


struct CmdSetStencilReference
{
    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, reference); }
};


struct CmdBindIndexBuffer
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, indexType); }
};


struct CmdBindVertexBuffers
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets); }
};


struct CmdDraw
{
    format::HandleId commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    auto GetTuple() const { return std::tie(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance); }
};


struct CmdDrawIndexed
{
    format::HandleId commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;

    auto GetTuple() const { return std::tie(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance); }
};


struct CmdDrawIndirect
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawIndexedIndirect
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdBlitImage
{
    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageBlit> pRegions;
    VkFilter filter;

    auto GetTuple() const { return std::tie(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter); }
};


struct CmdClearDepthStencilImage
{
    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    auto GetTuple() const { return std::tie(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges); }
};


struct CmdClearAttachments
{
    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    auto GetTuple() const { return std::tie(commandBuffer, attachmentCount, pAttachments, rectCount, pRects); }
};


struct CmdResolveImage
{
    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions); }
};


struct CmdBeginRenderPass
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, contents); }
};


struct CmdNextSubpass
{
    format::HandleId commandBuffer;
    VkSubpassContents contents;

    auto GetTuple() const { return std::tie(commandBuffer, contents); }
};


struct CmdEndRenderPass
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct BindBufferMemory2
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct BindImageMemory2
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct GetDeviceGroupPeerMemoryFeatures
{
    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    auto GetTuple() const { return std::tie(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }
};


struct CmdSetDeviceMask
{
    format::HandleId commandBuffer;
    uint32_t deviceMask;

    auto GetTuple() const { return std::tie(commandBuffer, deviceMask); }
};


struct EnumeratePhysicalDeviceGroups
{
    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }
};


struct GetImageMemoryRequirements2
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetBufferMemoryRequirements2
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements2
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct GetPhysicalDeviceFeatures2
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceProperties2
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceFormatProperties2
{
    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties2
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pImageFormatInfo, pImageFormatProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties2
{
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties2
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct GetPhysicalDeviceSparseImageFormatProperties2
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pFormatInfo, pPropertyCount, pProperties); }
};


struct TrimCommandPool
{
    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    auto GetTuple() const { return std::tie(device, commandPool, flags); }
};


struct GetDeviceQueue2
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    HandlePointerDecoder<VkQueue> pQueue;

    auto GetTuple() const { return std::tie(device, pQueueInfo, pQueue); }
};


struct GetPhysicalDeviceExternalBufferProperties
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }
};


struct GetPhysicalDeviceExternalFenceProperties
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }
};


struct GetPhysicalDeviceExternalSemaphoreProperties
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }
};


struct CmdDispatchBase
{
    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ); }
};


struct CreateDescriptorUpdateTemplate
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }
};


struct DestroyDescriptorUpdateTemplate
{
    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorUpdateTemplate, pAllocator); }
};


struct GetDescriptorSetLayoutSupport
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pSupport); }
};


struct CreateSamplerYcbcrConversion
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pYcbcrConversion); }
};


struct DestroySamplerYcbcrConversion
{
    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, ycbcrConversion, pAllocator); }
};


struct ResetQueryPool
{
    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(device, queryPool, firstQuery, queryCount); }
};


struct GetSemaphoreCounterValue
{
    VkResult result;
    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;

    auto GetTuple() const { return std::tie(result, device, semaphore, pValue); }
};


struct WaitSemaphores
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, pWaitInfo, timeout); }
};


struct SignalSemaphore
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;

    auto GetTuple() const { return std::tie(result, device, pSignalInfo); }
};


struct GetBufferDeviceAddress
{
    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetBufferOpaqueCaptureAddress
{
    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetDeviceMemoryOpaqueCaptureAddress
{
    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdDrawIndirectCount
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct CmdDrawIndexedIndirectCount
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct CreateRenderPass2
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct CmdBeginRenderPass2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }
};


struct CmdNextSubpass2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }
};


struct CmdEndRenderPass2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassEndInfo); }
};


struct GetPhysicalDeviceToolProperties
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pToolCount, pToolProperties); }
};


struct CreatePrivateDataSlot
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPrivateDataSlot); }
};


struct DestroyPrivateDataSlot
{
    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, privateDataSlot, pAllocator); }
};


struct SetPrivateData
{
    VkResult result;
    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    uint64_t data;

    auto GetTuple() const { return std::tie(result, device, objectType, objectHandle, privateDataSlot, data); }
};


struct GetPrivateData
{
    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    auto GetTuple() const { return std::tie(device, objectType, objectHandle, privateDataSlot, pData); }
};


struct CmdPipelineBarrier2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDependencyInfo); }
};


struct CmdWriteTimestamp2
{
    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, stage, queryPool, query); }
};


struct QueueSubmit2
{
    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct CmdCopyBuffer2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferInfo); }
};


struct CmdCopyImage2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageInfo); }
};


struct CmdCopyBufferToImage2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferToImageInfo); }
};


struct CmdCopyImageToBuffer2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageToBufferInfo); }
};


struct GetDeviceBufferMemoryRequirements
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageMemoryRequirements
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageSparseMemoryRequirements
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CmdSetEvent2
{
    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, event, pDependencyInfo); }
};


struct CmdResetEvent2
{
    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents2
{
    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    auto GetTuple() const { return std::tie(commandBuffer, eventCount, pEvents, pDependencyInfos); }
};


struct CmdBlitImage2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBlitImageInfo); }
};


struct CmdResolveImage2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pResolveImageInfo); }
};


struct CmdBeginRendering
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingInfo); }
};


struct CmdEndRendering
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdSetCullMode
{
    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    auto GetTuple() const { return std::tie(commandBuffer, cullMode); }
};


struct CmdSetFrontFace
{
    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    auto GetTuple() const { return std::tie(commandBuffer, frontFace); }
};


struct CmdSetPrimitiveTopology
{
    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveTopology); }
};


struct CmdSetViewportWithCount
{
    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, viewportCount, pViewports); }
};


struct CmdSetScissorWithCount
{
    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, scissorCount, pScissors); }
};


struct CmdBindVertexBuffers2
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;
    PointerDecoder<VkDeviceSize> pStrides;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides); }
};


struct CmdSetDepthTestEnable
{
    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthTestEnable); }
};


struct CmdSetDepthWriteEnable
{
    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthWriteEnable); }
};


struct CmdSetDepthCompareOp
{
    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    auto GetTuple() const { return std::tie(commandBuffer, depthCompareOp); }
};


struct CmdSetDepthBoundsTestEnable
{
    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBoundsTestEnable); }
};


struct CmdSetStencilTestEnable
{
    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stencilTestEnable); }
};


struct CmdSetStencilOp
{
    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp); }
};


struct CmdSetRasterizerDiscardEnable
{
    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizerDiscardEnable); }
};


struct CmdSetDepthBiasEnable
{
    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasEnable); }
};


struct CmdSetPrimitiveRestartEnable
{
    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartEnable); }
};


struct MapMemory2
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfo> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(result, device, pMemoryMapInfo, ppData); }
};


struct UnmapMemory2
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo> pMemoryUnmapInfo;

    auto GetTuple() const { return std::tie(result, device, pMemoryUnmapInfo); }
};


struct GetDeviceImageSubresourceLayout
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, pInfo, pLayout); }
};


struct GetImageSubresourceLayout2
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct CopyMemoryToImage
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo> pCopyMemoryToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyMemoryToImageInfo); }
};


struct CopyImageToMemory
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo> pCopyImageToMemoryInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToMemoryInfo); }
};


struct CopyImageToImage
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo> pCopyImageToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToImageInfo); }
};


struct TransitionImageLayout
{
    VkResult result;
    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo> pTransitions;

    auto GetTuple() const { return std::tie(result, device, transitionCount, pTransitions); }
};


struct CmdPushDescriptorSet
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites); }
};


struct CmdBindDescriptorSets2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo> pBindDescriptorSetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorSetsInfo); }
};


struct CmdPushConstants2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfo> pPushConstantsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushConstantsInfo); }
};


struct CmdPushDescriptorSet2
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo> pPushDescriptorSetInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushDescriptorSetInfo); }
};


struct CmdSetLineStipple
{
    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct CmdBindIndexBuffer2
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, size, indexType); }
};


struct GetRenderingAreaGranularity
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfo> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, pRenderingAreaInfo, pGranularity); }
};


struct CmdSetRenderingAttachmentLocations
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo> pLocationInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLocationInfo); }
};


struct CmdSetRenderingInputAttachmentIndices
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo> pInputAttachmentIndexInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInputAttachmentIndexInfo); }
};


struct DestroySurfaceKHR
{
    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, surface, pAllocator); }
};


struct GetPhysicalDeviceSurfaceSupportKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    format::HandleId surface;
    PointerDecoder<VkBool32> pSupported;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, surface, pSupported); }
};


struct GetPhysicalDeviceSurfaceCapabilitiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceCapabilities); }
};


struct GetPhysicalDeviceSurfaceFormatsKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats); }
};


struct GetPhysicalDeviceSurfacePresentModesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pPresentModeCount, pPresentModes); }
};


struct CreateSwapchainKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchain;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSwapchain); }
};


struct DestroySwapchainKHR
{
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, swapchain, pAllocator); }
};


struct GetSwapchainImagesKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    HandlePointerDecoder<VkImage> pSwapchainImages;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainImageCount, pSwapchainImages); }
};


struct AcquireNextImageKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    uint64_t timeout;
    format::HandleId semaphore;
    format::HandleId fence;
    PointerDecoder<uint32_t> pImageIndex;

    auto GetTuple() const { return std::tie(result, device, swapchain, timeout, semaphore, fence, pImageIndex); }
};


struct QueuePresentKHR
{
    VkResult result;
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;

    auto GetTuple() const { return std::tie(result, queue, pPresentInfo); }
};


struct GetDeviceGroupPresentCapabilitiesKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;

    auto GetTuple() const { return std::tie(result, device, pDeviceGroupPresentCapabilities); }
};


struct GetDeviceGroupSurfacePresentModesKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;

    auto GetTuple() const { return std::tie(result, device, surface, pModes); }
};


struct GetPhysicalDevicePresentRectanglesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pRectCount, pRects); }
};


struct AcquireNextImage2KHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;

    auto GetTuple() const { return std::tie(result, device, pAcquireInfo, pImageIndex); }
};


struct GetPhysicalDeviceDisplayPropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceDisplayPlanePropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetDisplayPlaneSupportedDisplaysKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    HandlePointerDecoder<VkDisplayKHR> pDisplays;

    auto GetTuple() const { return std::tie(result, physicalDevice, planeIndex, pDisplayCount, pDisplays); }
};


struct GetDisplayModePropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, display, pPropertyCount, pProperties); }
};


struct CreateDisplayModeKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDisplayModeKHR> pMode;

    auto GetTuple() const { return std::tie(result, physicalDevice, display, pCreateInfo, pAllocator, pMode); }
};


struct GetDisplayPlaneCapabilitiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, mode, planeIndex, pCapabilities); }
};


struct CreateDisplayPlaneSurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateSharedSwapchainsKHR
{
    VkResult result;
    format::HandleId device;
    uint32_t swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;

    auto GetTuple() const { return std::tie(result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains); }
};


struct CreateXlibSurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceXlibPresentationSupportKHR
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dpy;
    size_t visualID;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, dpy, visualID); }
};


struct CreateXcbSurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceXcbPresentationSupportKHR
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    uint32_t visual_id;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, connection, visual_id); }
};


struct CreateWaylandSurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceWaylandPresentationSupportKHR
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, display); }
};


struct CreateAndroidSurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateWin32SurfaceKHR
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceWin32PresentationSupportKHR
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex); }
};


struct GetPhysicalDeviceVideoCapabilitiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR> pVideoProfile;
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pVideoProfile, pCapabilities); }
};


struct GetPhysicalDeviceVideoFormatPropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR> pVideoFormatInfo;
    PointerDecoder<uint32_t> pVideoFormatPropertyCount;
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR> pVideoFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties); }
};


struct CreateVideoSessionKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionKHR> pVideoSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pVideoSession); }
};


struct DestroyVideoSessionKHR
{
    format::HandleId device;
    format::HandleId videoSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, videoSession, pAllocator); }
};


struct GetVideoSessionMemoryRequirementsKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId videoSession;
    PointerDecoder<uint32_t> pMemoryRequirementsCount;
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR> pMemoryRequirements;

    auto GetTuple() const { return std::tie(result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements); }
};


struct BindVideoSessionMemoryKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId videoSession;
    uint32_t bindSessionMemoryInfoCount;
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR> pBindSessionMemoryInfos;

    auto GetTuple() const { return std::tie(result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos); }
};


struct CreateVideoSessionParametersKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionParametersKHR> pVideoSessionParameters;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pVideoSessionParameters); }
};


struct UpdateVideoSessionParametersKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR> pUpdateInfo;

    auto GetTuple() const { return std::tie(result, device, videoSessionParameters, pUpdateInfo); }
};


struct DestroyVideoSessionParametersKHR
{
    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, videoSessionParameters, pAllocator); }
};


struct CmdBeginVideoCodingKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR> pBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBeginInfo); }
};


struct CmdEndVideoCodingKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR> pEndCodingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pEndCodingInfo); }
};


struct CmdControlVideoCodingKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR> pCodingControlInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCodingControlInfo); }
};


struct CmdDecodeVideoKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR> pDecodeInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDecodeInfo); }
};


struct CmdBeginRenderingKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingInfo); }
};


struct CmdEndRenderingKHR
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct GetPhysicalDeviceFeatures2KHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceProperties2KHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceFormatProperties2KHR
{
    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pImageFormatInfo, pImageFormatProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties2KHR
{
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties2KHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct GetPhysicalDeviceSparseImageFormatProperties2KHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pFormatInfo, pPropertyCount, pProperties); }
};


struct GetDeviceGroupPeerMemoryFeaturesKHR
{
    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    auto GetTuple() const { return std::tie(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }
};


struct CmdSetDeviceMaskKHR
{
    format::HandleId commandBuffer;
    uint32_t deviceMask;

    auto GetTuple() const { return std::tie(commandBuffer, deviceMask); }
};


struct CmdDispatchBaseKHR
{
    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ); }
};


struct TrimCommandPoolKHR
{
    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    auto GetTuple() const { return std::tie(device, commandPool, flags); }
};


struct EnumeratePhysicalDeviceGroupsKHR
{
    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }
};


struct GetPhysicalDeviceExternalBufferPropertiesKHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }
};


struct GetMemoryWin32HandleKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct GetMemoryWin32HandlePropertiesKHR
{
    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, handle, pMemoryWin32HandleProperties); }
};


struct GetMemoryFdKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct GetMemoryFdPropertiesKHR
{
    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, fd, pMemoryFdProperties); }
};


struct GetPhysicalDeviceExternalSemaphorePropertiesKHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }
};


struct ImportSemaphoreWin32HandleKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreWin32HandleInfo); }
};


struct GetSemaphoreWin32HandleKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct ImportSemaphoreFdKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreFdInfo); }
};


struct GetSemaphoreFdKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct CmdPushDescriptorSetKHR
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites); }
};


struct CreateDescriptorUpdateTemplateKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }
};


struct DestroyDescriptorUpdateTemplateKHR
{
    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorUpdateTemplate, pAllocator); }
};


struct CreateRenderPass2KHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct CmdBeginRenderPass2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }
};


struct CmdNextSubpass2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }
};


struct CmdEndRenderPass2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassEndInfo); }
};


struct GetSwapchainStatusKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct GetPhysicalDeviceExternalFencePropertiesKHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }
};


struct ImportFenceWin32HandleKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportFenceWin32HandleInfo); }
};


struct GetFenceWin32HandleKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct ImportFenceFdKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;

    auto GetTuple() const { return std::tie(result, device, pImportFenceFdInfo); }
};


struct GetFenceFdKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<uint32_t> pCounterCount;
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR> pCounters;
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR> pCounterDescriptions;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions); }
};


struct GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR> pPerformanceQueryCreateInfo;
    PointerDecoder<uint32_t> pNumPasses;

    auto GetTuple() const { return std::tie(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses); }
};


struct AcquireProfilingLockKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct ReleaseProfilingLockKHR
{
    format::HandleId device;

    auto GetTuple() const { return std::tie(device); }
};


struct GetPhysicalDeviceSurfaceCapabilities2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities); }
};


struct GetPhysicalDeviceSurfaceFormats2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats); }
};


struct GetPhysicalDeviceDisplayProperties2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceDisplayPlaneProperties2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetDisplayModeProperties2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, display, pPropertyCount, pProperties); }
};


struct GetDisplayPlaneCapabilities2KHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pDisplayPlaneInfo, pCapabilities); }
};


struct GetImageMemoryRequirements2KHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetBufferMemoryRequirements2KHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements2KHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CreateSamplerYcbcrConversionKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pYcbcrConversion); }
};


struct DestroySamplerYcbcrConversionKHR
{
    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, ycbcrConversion, pAllocator); }
};


struct BindBufferMemory2KHR
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct BindImageMemory2KHR
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct GetDescriptorSetLayoutSupportKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pSupport); }
};


struct CmdDrawIndirectCountKHR
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct CmdDrawIndexedIndirectCountKHR
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct GetSemaphoreCounterValueKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;

    auto GetTuple() const { return std::tie(result, device, semaphore, pValue); }
};


struct WaitSemaphoresKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, pWaitInfo, timeout); }
};


struct SignalSemaphoreKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;

    auto GetTuple() const { return std::tie(result, device, pSignalInfo); }
};


struct GetPhysicalDeviceFragmentShadingRatesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pFragmentShadingRateCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR> pFragmentShadingRates;

    auto GetTuple() const { return std::tie(result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates); }
};


struct CmdSetFragmentShadingRateKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkExtent2D> pFragmentSize;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    auto GetTuple() const { return std::tie(commandBuffer, pFragmentSize, combinerOps); }
};


struct CmdSetRenderingAttachmentLocationsKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo> pLocationInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLocationInfo); }
};


struct CmdSetRenderingInputAttachmentIndicesKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo> pInputAttachmentIndexInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInputAttachmentIndexInfo); }
};


struct WaitForPresentKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    uint64_t presentId;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, swapchain, presentId, timeout); }
};


struct GetBufferDeviceAddressKHR
{
    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetBufferOpaqueCaptureAddressKHR
{
    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetDeviceMemoryOpaqueCaptureAddressKHR
{
    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CreateDeferredOperationKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeferredOperationKHR> pDeferredOperation;

    auto GetTuple() const { return std::tie(result, device, pAllocator, pDeferredOperation); }
};


struct DestroyDeferredOperationKHR
{
    format::HandleId device;
    format::HandleId operation;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, operation, pAllocator); }
};


struct GetDeferredOperationMaxConcurrencyKHR
{
    uint32_t result;
    format::HandleId device;
    format::HandleId operation;

    auto GetTuple() const { return std::tie(result, device, operation); }
};


struct GetDeferredOperationResultKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId operation;

    auto GetTuple() const { return std::tie(result, device, operation); }
};


struct GetPipelineExecutablePropertiesKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineInfoKHR> pPipelineInfo;
    PointerDecoder<uint32_t> pExecutableCount;
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, pExecutableCount, pProperties); }
};


struct GetPipelineExecutableStatisticsKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pStatisticCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR> pStatistics;

    auto GetTuple() const { return std::tie(result, device, pExecutableInfo, pStatisticCount, pStatistics); }
};


struct GetPipelineExecutableInternalRepresentationsKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pInternalRepresentationCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR> pInternalRepresentations;

    auto GetTuple() const { return std::tie(result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations); }
};


struct MapMemory2KHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfo> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(result, device, pMemoryMapInfo, ppData); }
};


struct UnmapMemory2KHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo> pMemoryUnmapInfo;

    auto GetTuple() const { return std::tie(result, device, pMemoryUnmapInfo); }
};


struct GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR> pQualityLevelInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR> pQualityLevelProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pQualityLevelInfo, pQualityLevelProperties); }
};


struct GetEncodedVideoSessionParametersKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR> pVideoSessionParametersInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR> pFeedbackInfo;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData); }
};


struct CmdEncodeVideoKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR> pEncodeInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pEncodeInfo); }
};


struct CmdSetEvent2KHR
{
    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, event, pDependencyInfo); }
};


struct CmdResetEvent2KHR
{
    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents2KHR
{
    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    auto GetTuple() const { return std::tie(commandBuffer, eventCount, pEvents, pDependencyInfos); }
};


struct CmdPipelineBarrier2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDependencyInfo); }
};


struct CmdWriteTimestamp2KHR
{
    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, stage, queryPool, query); }
};


struct QueueSubmit2KHR
{
    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct CmdBindIndexBuffer3KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindIndexBuffer3InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdBindVertexBuffers3KHR
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    StructPointerDecoder<Decoded_VkBindVertexBuffer3InfoKHR> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBindingInfos); }
};


struct CmdDrawIndirect2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawIndexedIndirect2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDispatchIndirect2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdCopyMemoryToImageKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdCopyImageToMemoryKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdUpdateMemoryKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR> pDstRange;
    VkAddressCommandFlagsKHR dstFlags;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(commandBuffer, pDstRange, dstFlags, dataSize, pData); }
};


struct CmdFillMemoryKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR> pDstRange;
    VkAddressCommandFlagsKHR dstFlags;
    uint32_t data;

    auto GetTuple() const { return std::tie(commandBuffer, pDstRange, dstFlags, data); }
};


struct CmdCopyQueryPoolResultsToMemoryKHR
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRangeKHR> pDstRange;
    VkAddressCommandFlagsKHR dstFlags;
    VkQueryResultFlags queryResultFlags;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, firstQuery, queryCount, pDstRange, dstFlags, queryResultFlags); }
};


struct CmdDrawIndirectCount2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawIndexedIndirectCount2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdBeginConditionalRendering2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfo2EXT> pConditionalRenderingBegin;

    auto GetTuple() const { return std::tie(commandBuffer, pConditionalRenderingBegin); }
};


struct CmdBindTransformFeedbackBuffers2EXT
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBindingInfos); }
};


struct CmdBeginTransformFeedback2EXT
{
    format::HandleId commandBuffer;
    uint32_t firstCounterRange;
    uint32_t counterRangeCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pCounterInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos); }
};


struct CmdEndTransformFeedback2EXT
{
    format::HandleId commandBuffer;
    uint32_t firstCounterRange;
    uint32_t counterRangeCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pCounterInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos); }
};


struct CmdDrawIndirectByteCount2EXT
{
    format::HandleId commandBuffer;
    uint32_t instanceCount;
    uint32_t firstInstance;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pCounterInfo;
    uint32_t counterOffset;
    uint32_t vertexStride;

    auto GetTuple() const { return std::tie(commandBuffer, instanceCount, firstInstance, pCounterInfo, counterOffset, vertexStride); }
};


struct CmdDrawMeshTasksIndirect2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawMeshTasksIndirectCount2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdWriteMarkerToMemoryAMD
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkMemoryMarkerInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CreateAccelerationStructure2KHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfo2KHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct CmdCopyBuffer2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferInfo); }
};


struct CmdCopyImage2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageInfo); }
};


struct CmdCopyBufferToImage2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferToImageInfo); }
};


struct CmdCopyImageToBuffer2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageToBufferInfo); }
};


struct CmdBlitImage2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBlitImageInfo); }
};


struct CmdResolveImage2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pResolveImageInfo); }
};


struct CmdTraceRaysIndirect2KHR
{
    format::HandleId commandBuffer;
    VkDeviceAddress indirectDeviceAddress;

    auto GetTuple() const { return std::tie(commandBuffer, indirectDeviceAddress); }
};


struct GetDeviceBufferMemoryRequirementsKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageMemoryRequirementsKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageSparseMemoryRequirementsKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CmdBindIndexBuffer2KHR
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, size, indexType); }
};


struct GetRenderingAreaGranularityKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfo> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, pRenderingAreaInfo, pGranularity); }
};


struct GetDeviceImageSubresourceLayoutKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, pInfo, pLayout); }
};


struct GetImageSubresourceLayout2KHR
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct WaitForPresent2KHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkPresentWait2InfoKHR> pPresentWait2Info;

    auto GetTuple() const { return std::tie(result, device, swapchain, pPresentWait2Info); }
};


struct CreatePipelineBinariesKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineBinaryCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    StructPointerDecoder<Decoded_VkPipelineBinaryHandlesInfoKHR> pBinaries;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pBinaries); }
};


struct DestroyPipelineBinaryKHR
{
    format::HandleId device;
    format::HandleId pipelineBinary;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineBinary, pAllocator); }
};


struct GetPipelineKeyKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCreateInfoKHR> pPipelineCreateInfo;
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR> pPipelineKey;

    auto GetTuple() const { return std::tie(result, device, pPipelineCreateInfo, pPipelineKey); }
};


struct GetPipelineBinaryDataKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineBinaryDataInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR> pPipelineBinaryKey;
    PointerDecoder<size_t> pPipelineBinaryDataSize;
    PointerDecoder<uint8_t> pPipelineBinaryData;

    auto GetTuple() const { return std::tie(result, device, pInfo, pPipelineBinaryKey, pPipelineBinaryDataSize, pPipelineBinaryData); }
};


struct ReleaseCapturedPipelineDataKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseCapturedPipelineDataInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(result, device, pInfo, pAllocator); }
};


struct ReleaseSwapchainImagesKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR> pReleaseInfo;

    auto GetTuple() const { return std::tie(result, device, pReleaseInfo); }
};


struct GetPhysicalDeviceCooperativeMatrixPropertiesKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct CmdSetLineStippleKHR
{
    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct GetPhysicalDeviceCalibrateableTimeDomainsKHR
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;

    auto GetTuple() const { return std::tie(result, physicalDevice, pTimeDomainCount, pTimeDomains); }
};


struct GetCalibratedTimestampsKHR
{
    VkResult result;
    format::HandleId device;
    uint32_t timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t> pTimestamps;
    PointerDecoder<uint64_t> pMaxDeviation;

    auto GetTuple() const { return std::tie(result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation); }
};


struct CmdBindDescriptorSets2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo> pBindDescriptorSetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorSetsInfo); }
};


struct CmdPushConstants2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfo> pPushConstantsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushConstantsInfo); }
};


struct CmdPushDescriptorSet2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo> pPushDescriptorSetInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushDescriptorSetInfo); }
};


struct CmdSetDescriptorBufferOffsets2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT> pSetDescriptorBufferOffsetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSetDescriptorBufferOffsetsInfo); }
};


struct CmdBindDescriptorBufferEmbeddedSamplers2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT> pBindDescriptorBufferEmbeddedSamplersInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo); }
};


struct CmdCopyMemoryIndirectKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR> pCopyMemoryIndirectInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryIndirectInfo); }
};


struct CmdCopyMemoryToImageIndirectKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR> pCopyMemoryToImageIndirectInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryToImageIndirectInfo); }
};


struct GetDeviceFaultReportsKHR
{
    VkResult result;
    format::HandleId device;
    uint64_t timeout;
    PointerDecoder<uint32_t> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoKHR> pFaultInfo;

    auto GetTuple() const { return std::tie(result, device, timeout, pFaultCounts, pFaultInfo); }
};


struct GetDeviceFaultDebugInfoKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultDebugInfoKHR> pDebugInfo;

    auto GetTuple() const { return std::tie(result, device, pDebugInfo); }
};


struct CmdEndRendering2KHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR> pRenderingEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingEndInfo); }
};


struct FrameBoundaryANDROID
{
    format::HandleId device;
    format::HandleId semaphore;
    format::HandleId image;

    auto GetTuple() const { return std::tie(device, semaphore, image); }
};


struct CreateDebugReportCallbackEXT
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugReportCallbackEXT> pCallback;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pCallback); }
};


struct DestroyDebugReportCallbackEXT
{
    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, callback, pAllocator); }
};


struct DebugReportMessageEXT
{
    format::HandleId instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    size_t location;
    int32_t messageCode;
    StringDecoder pLayerPrefix;
    StringDecoder pMessage;

    auto GetTuple() const { return std::tie(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage); }
};


struct DebugMarkerSetObjectTagEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;

    auto GetTuple() const { return std::tie(result, device, pTagInfo); }
};


struct DebugMarkerSetObjectNameEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;

    auto GetTuple() const { return std::tie(result, device, pNameInfo); }
};


struct CmdDebugMarkerBeginEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pMarkerInfo); }
};


struct CmdDebugMarkerEndEXT
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdDebugMarkerInsertEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pMarkerInfo); }
};


struct CmdBindTransformFeedbackBuffersEXT
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes); }
};


struct CmdBeginTransformFeedbackEXT
{
    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }
};


struct CmdEndTransformFeedbackEXT
{
    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }
};


struct CmdBeginQueryIndexedEXT
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
    uint32_t index;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, flags, index); }
};


struct CmdEndQueryIndexedEXT
{
    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    uint32_t index;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, index); }
};


struct CmdDrawIndirectByteCountEXT
{
    format::HandleId commandBuffer;
    uint32_t instanceCount;
    uint32_t firstInstance;
    format::HandleId counterBuffer;
    VkDeviceSize counterBufferOffset;
    uint32_t counterOffset;
    uint32_t vertexStride;

    auto GetTuple() const { return std::tie(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride); }
};


struct GetImageViewHandleNVX
{
    uint32_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetImageViewHandle64NVX
{
    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetImageViewAddressNVX
{
    VkResult result;
    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX> pProperties;

    auto GetTuple() const { return std::tie(result, device, imageView, pProperties); }
};


struct GetDeviceCombinedImageSamplerIndexNVX
{
    uint64_t result;
    format::HandleId device;
    uint64_t imageViewIndex;
    uint64_t samplerIndex;

    auto GetTuple() const { return std::tie(result, device, imageViewIndex, samplerIndex); }
};


struct CmdDrawIndirectCountAMD
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct CmdDrawIndexedIndirectCountAMD
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct GetShaderInfoAMD
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    VkShaderStageFlagBits shaderStage;
    VkShaderInfoTypeAMD infoType;
    PointerDecoder<size_t> pInfoSize;
    PointerDecoder<uint8_t> pInfo;

    auto GetTuple() const { return std::tie(result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo); }
};


struct CreateStreamDescriptorSurfaceGGP
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceExternalImageFormatPropertiesNV
{
    VkResult result;
    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkExternalMemoryHandleTypeFlagsNV externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties); }
};


struct GetMemoryWin32HandleNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, memory, handleType, pHandle); }
};


struct CreateViSurfaceNN
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CmdBeginConditionalRenderingEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    auto GetTuple() const { return std::tie(commandBuffer, pConditionalRenderingBegin); }
};


struct CmdEndConditionalRenderingEXT
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdSetViewportWScalingNV
{
    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewportWScalings); }
};


struct ReleaseDisplayEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, display); }
};


struct AcquireXlibDisplayEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    uint64_t dpy;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, dpy, display); }
};


struct GetRandROutputDisplayEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    uint64_t dpy;
    size_t rrOutput;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;

    auto GetTuple() const { return std::tie(result, physicalDevice, dpy, rrOutput, pDisplay); }
};


struct GetPhysicalDeviceSurfaceCapabilities2EXT
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceCapabilities); }
};


struct DisplayPowerControlEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;

    auto GetTuple() const { return std::tie(result, device, display, pDisplayPowerInfo); }
};


struct RegisterDeviceEventEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;

    auto GetTuple() const { return std::tie(result, device, pDeviceEventInfo, pAllocator, pFence); }
};


struct RegisterDisplayEventEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;

    auto GetTuple() const { return std::tie(result, device, display, pDisplayEventInfo, pAllocator, pFence); }
};


struct GetSwapchainCounterEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;

    auto GetTuple() const { return std::tie(result, device, swapchain, counter, pCounterValue); }
};


struct GetRefreshCycleDurationGOOGLE
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;

    auto GetTuple() const { return std::tie(result, device, swapchain, pDisplayTimingProperties); }
};


struct GetPastPresentationTimingGOOGLE
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;

    auto GetTuple() const { return std::tie(result, device, swapchain, pPresentationTimingCount, pPresentationTimings); }
};


struct CmdSetDiscardRectangleEXT
{
    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    auto GetTuple() const { return std::tie(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles); }
};


struct CmdSetDiscardRectangleEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 discardRectangleEnable;

    auto GetTuple() const { return std::tie(commandBuffer, discardRectangleEnable); }
};


struct CmdSetDiscardRectangleModeEXT
{
    format::HandleId commandBuffer;
    VkDiscardRectangleModeEXT discardRectangleMode;

    auto GetTuple() const { return std::tie(commandBuffer, discardRectangleMode); }
};


struct SetHdrMetadataEXT
{
    format::HandleId device;
    uint32_t swapchainCount;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    auto GetTuple() const { return std::tie(device, swapchainCount, pSwapchains, pMetadata); }
};


struct CreateIOSSurfaceMVK
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateMacOSSurfaceMVK
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct SetDebugUtilsObjectNameEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;

    auto GetTuple() const { return std::tie(result, device, pNameInfo); }
};


struct SetDebugUtilsObjectTagEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;

    auto GetTuple() const { return std::tie(result, device, pTagInfo); }
};


struct QueueBeginDebugUtilsLabelEXT
{
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(queue, pLabelInfo); }
};


struct QueueEndDebugUtilsLabelEXT
{
    format::HandleId queue;

    auto GetTuple() const { return std::tie(queue); }
};


struct QueueInsertDebugUtilsLabelEXT
{
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(queue, pLabelInfo); }
};


struct CmdBeginDebugUtilsLabelEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLabelInfo); }
};


struct CmdEndDebugUtilsLabelEXT
{
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdInsertDebugUtilsLabelEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLabelInfo); }
};


struct CreateDebugUtilsMessengerEXT
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pMessenger); }
};


struct DestroyDebugUtilsMessengerEXT
{
    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, messenger, pAllocator); }
};


struct SubmitDebugUtilsMessageEXT
{
    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    auto GetTuple() const { return std::tie(instance, messageSeverity, messageTypes, pCallbackData); }
};


struct GetAndroidHardwareBufferPropertiesANDROID
{
    VkResult result;
    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;

    auto GetTuple() const { return std::tie(result, device, buffer, pProperties); }
};


struct GetMemoryAndroidHardwareBufferANDROID
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t, void*> pBuffer;

    auto GetTuple() const { return std::tie(result, device, pInfo, pBuffer); }
};


struct CreateGpaSessionAMD
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaSessionCreateInfoAMD> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkGpaSessionAMD> pGpaSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pGpaSession); }
};


struct DestroyGpaSessionAMD
{
    format::HandleId device;
    format::HandleId gpaSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, gpaSession, pAllocator); }
};


struct SetGpaDeviceClockModeAMD
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaDeviceClockModeInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetGpaDeviceClockInfoAMD
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaDeviceGetClockInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdBeginGpaSessionAMD
{
    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession); }
};


struct CmdEndGpaSessionAMD
{
    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession); }
};


struct CmdBeginGpaSampleAMD
{
    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;
    StructPointerDecoder<Decoded_VkGpaSampleBeginInfoAMD> pGpaSampleBeginInfo;
    PointerDecoder<uint32_t> pSampleID;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession, pGpaSampleBeginInfo, pSampleID); }
};


struct CmdEndGpaSampleAMD
{
    format::HandleId commandBuffer;
    format::HandleId gpaSession;
    uint32_t sampleID;

    auto GetTuple() const { return std::tie(commandBuffer, gpaSession, sampleID); }
};


struct GetGpaSessionStatusAMD
{
    VkResult result;
    format::HandleId device;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, device, gpaSession); }
};


struct GetGpaSessionResultsAMD
{
    VkResult result;
    format::HandleId device;
    format::HandleId gpaSession;
    uint32_t sampleID;
    PointerDecoder<size_t> pSizeInBytes;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, gpaSession, sampleID, pSizeInBytes, pData); }
};


struct ResetGpaSessionAMD
{
    VkResult result;
    format::HandleId device;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, device, gpaSession); }
};


struct CmdCopyGpaSessionResultsAMD
{
    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(commandBuffer, gpaSession); }
};


struct CmdSetSampleLocationsEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSampleLocationsInfo); }
};


struct GetPhysicalDeviceMultisamplePropertiesEXT
{
    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    auto GetTuple() const { return std::tie(physicalDevice, samples, pMultisampleProperties); }
};


struct GetImageDrmFormatModifierPropertiesEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT> pProperties;

    auto GetTuple() const { return std::tie(result, device, image, pProperties); }
};


struct CreateValidationCacheEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkValidationCacheEXT> pValidationCache;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pValidationCache); }
};


struct DestroyValidationCacheEXT
{
    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, validationCache, pAllocator); }
};


struct MergeValidationCachesEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkValidationCacheEXT> pSrcCaches;

    auto GetTuple() const { return std::tie(result, device, dstCache, srcCacheCount, pSrcCaches); }
};


struct GetValidationCacheDataEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, validationCache, pDataSize, pData); }
};


struct CmdBindShadingRateImageNV
{
    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    auto GetTuple() const { return std::tie(commandBuffer, imageView, imageLayout); }
};


struct CmdSetViewportShadingRatePaletteNV
{
    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes); }
};


struct CmdSetCoarseSampleOrderNV
{
    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    auto GetTuple() const { return std::tie(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders); }
};


struct CreateAccelerationStructureNV
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct DestroyAccelerationStructureNV
{
    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, accelerationStructure, pAllocator); }
};


struct GetAccelerationStructureMemoryRequirementsNV
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct BindAccelerationStructureMemoryNV
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct CmdBuildAccelerationStructureNV
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV> pInfo;
    format::HandleId instanceData;
    VkDeviceSize instanceOffset;
    VkBool32 update;
    format::HandleId dst;
    format::HandleId src;
    format::HandleId scratch;
    VkDeviceSize scratchOffset;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset); }
};


struct CmdCopyAccelerationStructureNV
{
    format::HandleId commandBuffer;
    format::HandleId dst;
    format::HandleId src;
    VkCopyAccelerationStructureModeKHR mode;

    auto GetTuple() const { return std::tie(commandBuffer, dst, src, mode); }
};


struct CmdTraceRaysNV
{
    format::HandleId commandBuffer;
    format::HandleId raygenShaderBindingTableBuffer;
    VkDeviceSize raygenShaderBindingOffset;
    format::HandleId missShaderBindingTableBuffer;
    VkDeviceSize missShaderBindingOffset;
    VkDeviceSize missShaderBindingStride;
    format::HandleId hitShaderBindingTableBuffer;
    VkDeviceSize hitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride;
    format::HandleId callableShaderBindingTableBuffer;
    VkDeviceSize callableShaderBindingOffset;
    VkDeviceSize callableShaderBindingStride;
    uint32_t width;
    uint32_t height;
    uint32_t depth;

    auto GetTuple() const { return std::tie(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth); }
};


struct CreateRayTracingPipelinesNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;

    auto GetTuple() const { return std::tie(result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }
};


struct GetRayTracingShaderGroupHandlesKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pipeline, firstGroup, groupCount, dataSize, pData); }
};


struct GetRayTracingShaderGroupHandlesNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pipeline, firstGroup, groupCount, dataSize, pData); }
};


struct GetAccelerationStructureHandleNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId accelerationStructure;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, accelerationStructure, dataSize, pData); }
};


struct CmdWriteAccelerationStructuresPropertiesNV
{
    format::HandleId commandBuffer;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    auto GetTuple() const { return std::tie(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery); }
};


struct CompileDeferredNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t shader;

    auto GetTuple() const { return std::tie(result, device, pipeline, shader); }
};


struct GetMemoryHostPointerPropertiesEXT
{
    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, pHostPointer, pMemoryHostPointerProperties); }
};


struct CmdWriteBufferMarkerAMD
{
    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker); }
};


struct CmdWriteBufferMarker2AMD
{
    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    auto GetTuple() const { return std::tie(commandBuffer, stage, dstBuffer, dstOffset, marker); }
};


struct GetPhysicalDeviceCalibrateableTimeDomainsEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;

    auto GetTuple() const { return std::tie(result, physicalDevice, pTimeDomainCount, pTimeDomains); }
};


struct GetCalibratedTimestampsEXT
{
    VkResult result;
    format::HandleId device;
    uint32_t timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t> pTimestamps;
    PointerDecoder<uint64_t> pMaxDeviation;

    auto GetTuple() const { return std::tie(result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation); }
};


struct CmdDrawMeshTasksNV
{
    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    auto GetTuple() const { return std::tie(commandBuffer, taskCount, firstTask); }
};


struct CmdDrawMeshTasksIndirectNV
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawMeshTasksIndirectCountNV
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


struct CmdSetExclusiveScissorEnableNV
{
    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    PointerDecoder<VkBool32> pExclusiveScissorEnables;

    auto GetTuple() const { return std::tie(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables); }
};


struct CmdSetExclusiveScissorNV
{
    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    auto GetTuple() const { return std::tie(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors); }
};


struct CmdSetCheckpointNV
{
    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    auto GetTuple() const { return std::tie(commandBuffer, pCheckpointMarker); }
};


struct GetQueueCheckpointDataNV
{
    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    auto GetTuple() const { return std::tie(queue, pCheckpointDataCount, pCheckpointData); }
};


struct GetQueueCheckpointData2NV
{
    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointData2NV> pCheckpointData;

    auto GetTuple() const { return std::tie(queue, pCheckpointDataCount, pCheckpointData); }
};


struct SetSwapchainPresentTimingQueueSizeEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    uint32_t size;

    auto GetTuple() const { return std::tie(result, device, swapchain, size); }
};


struct GetSwapchainTimingPropertiesEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSwapchainTimingPropertiesEXT> pSwapchainTimingProperties;
    PointerDecoder<uint64_t> pSwapchainTimingPropertiesCounter;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainTimingProperties, pSwapchainTimingPropertiesCounter); }
};


struct GetSwapchainTimeDomainPropertiesEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSwapchainTimeDomainPropertiesEXT> pSwapchainTimeDomainProperties;
    PointerDecoder<uint64_t> pTimeDomainsCounter;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainTimeDomainProperties, pTimeDomainsCounter); }
};


struct GetPastPresentationTimingEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPastPresentationTimingInfoEXT> pPastPresentationTimingInfo;
    StructPointerDecoder<Decoded_VkPastPresentationTimingPropertiesEXT> pPastPresentationTimingProperties;

    auto GetTuple() const { return std::tie(result, device, pPastPresentationTimingInfo, pPastPresentationTimingProperties); }
};


struct InitializePerformanceApiINTEL
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL> pInitializeInfo;

    auto GetTuple() const { return std::tie(result, device, pInitializeInfo); }
};


struct UninitializePerformanceApiINTEL
{
    format::HandleId device;

    auto GetTuple() const { return std::tie(device); }
};


struct CmdSetPerformanceMarkerINTEL
{
    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL> pMarkerInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pMarkerInfo); }
};


struct CmdSetPerformanceStreamMarkerINTEL
{
    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL> pMarkerInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pMarkerInfo); }
};


struct CmdSetPerformanceOverrideINTEL
{
    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL> pOverrideInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pOverrideInfo); }
};


struct AcquirePerformanceConfigurationINTEL
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL> pAcquireInfo;
    HandlePointerDecoder<VkPerformanceConfigurationINTEL> pConfiguration;

    auto GetTuple() const { return std::tie(result, device, pAcquireInfo, pConfiguration); }
};


struct ReleasePerformanceConfigurationINTEL
{
    VkResult result;
    format::HandleId device;
    format::HandleId configuration;

    auto GetTuple() const { return std::tie(result, device, configuration); }
};


struct QueueSetPerformanceConfigurationINTEL
{
    VkResult result;
    format::HandleId queue;
    format::HandleId configuration;

    auto GetTuple() const { return std::tie(result, queue, configuration); }
};


struct GetPerformanceParameterINTEL
{
    VkResult result;
    format::HandleId device;
    VkPerformanceParameterTypeINTEL parameter;
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL> pValue;

    auto GetTuple() const { return std::tie(result, device, parameter, pValue); }
};


struct SetLocalDimmingAMD
{
    format::HandleId device;
    format::HandleId swapChain;
    VkBool32 localDimmingEnable;

    auto GetTuple() const { return std::tie(device, swapChain, localDimmingEnable); }
};


struct CreateImagePipeSurfaceFUCHSIA
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateMetalSurfaceEXT
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetBufferDeviceAddressEXT
{
    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetPhysicalDeviceToolPropertiesEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pToolCount, pToolProperties); }
};


struct GetPhysicalDeviceCooperativeMatrixPropertiesNV
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pCombinationCount;
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV> pCombinations;

    auto GetTuple() const { return std::tie(result, physicalDevice, pCombinationCount, pCombinations); }
};


struct GetPhysicalDeviceSurfacePresentModes2EXT
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes); }
};


struct AcquireFullScreenExclusiveModeEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct ReleaseFullScreenExclusiveModeEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct GetDeviceGroupSurfacePresentModes2EXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;

    auto GetTuple() const { return std::tie(result, device, pSurfaceInfo, pModes); }
};


struct CreateHeadlessSurfaceEXT
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CmdSetLineStippleEXT
{
    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct ResetQueryPoolEXT
{
    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(device, queryPool, firstQuery, queryCount); }
};


struct CmdSetCullModeEXT
{
    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    auto GetTuple() const { return std::tie(commandBuffer, cullMode); }
};


struct CmdSetFrontFaceEXT
{
    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    auto GetTuple() const { return std::tie(commandBuffer, frontFace); }
};


struct CmdSetPrimitiveTopologyEXT
{
    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveTopology); }
};


struct CmdSetViewportWithCountEXT
{
    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, viewportCount, pViewports); }
};


struct CmdSetScissorWithCountEXT
{
    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, scissorCount, pScissors); }
};


struct CmdBindVertexBuffers2EXT
{
    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;
    PointerDecoder<VkDeviceSize> pStrides;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides); }
};


struct CmdSetDepthTestEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthTestEnable); }
};


struct CmdSetDepthWriteEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthWriteEnable); }
};


struct CmdSetDepthCompareOpEXT
{
    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    auto GetTuple() const { return std::tie(commandBuffer, depthCompareOp); }
};


struct CmdSetDepthBoundsTestEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBoundsTestEnable); }
};


struct CmdSetStencilTestEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stencilTestEnable); }
};


struct CmdSetStencilOpEXT
{
    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp); }
};


struct CopyMemoryToImageEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo> pCopyMemoryToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyMemoryToImageInfo); }
};


struct CopyImageToMemoryEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo> pCopyImageToMemoryInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToMemoryInfo); }
};


struct CopyImageToImageEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo> pCopyImageToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToImageInfo); }
};


struct TransitionImageLayoutEXT
{
    VkResult result;
    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo> pTransitions;

    auto GetTuple() const { return std::tie(result, device, transitionCount, pTransitions); }
};


struct GetImageSubresourceLayout2EXT
{
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct ReleaseSwapchainImagesEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR> pReleaseInfo;

    auto GetTuple() const { return std::tie(result, device, pReleaseInfo); }
};


struct GetGeneratedCommandsMemoryRequirementsNV
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct CmdPreprocessGeneratedCommandsNV
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pGeneratedCommandsInfo); }
};


struct CmdExecuteGeneratedCommandsNV
{
    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, isPreprocessed, pGeneratedCommandsInfo); }
};


struct CmdBindPipelineShaderGroupNV
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;
    uint32_t groupIndex;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline, groupIndex); }
};


struct CreateIndirectCommandsLayoutNV
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutNV> pIndirectCommandsLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout); }
};


struct DestroyIndirectCommandsLayoutNV
{
    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectCommandsLayout, pAllocator); }
};


struct CmdSetDepthBias2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT> pDepthBiasInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDepthBiasInfo); }
};


struct AcquireDrmDisplayEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    int32_t drmFd;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, drmFd, display); }
};


struct GetDrmDisplayEXT
{
    VkResult result;
    format::HandleId physicalDevice;
    int32_t drmFd;
    uint32_t connectorId;
    HandlePointerDecoder<VkDisplayKHR> display;

    auto GetTuple() const { return std::tie(result, physicalDevice, drmFd, connectorId, display); }
};


struct CreatePrivateDataSlotEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPrivateDataSlot); }
};


struct DestroyPrivateDataSlotEXT
{
    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, privateDataSlot, pAllocator); }
};


struct SetPrivateDataEXT
{
    VkResult result;
    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    uint64_t data;

    auto GetTuple() const { return std::tie(result, device, objectType, objectHandle, privateDataSlot, data); }
};


struct GetPrivateDataEXT
{
    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    auto GetTuple() const { return std::tie(device, objectType, objectHandle, privateDataSlot, pData); }
};


struct QueueSetPerfHintQCOM
{
    VkResult result;
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPerfHintInfoQCOM> pPerfHintInfo;

    auto GetTuple() const { return std::tie(result, queue, pPerfHintInfo); }
};


struct CmdDispatchTileQCOM
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM> pDispatchTileInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDispatchTileInfo); }
};


struct CmdBeginPerTileExecutionQCOM
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM> pPerTileBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPerTileBeginInfo); }
};


struct CmdEndPerTileExecutionQCOM
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM> pPerTileEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPerTileEndInfo); }
};


struct GetDescriptorSetLayoutSizeEXT
{
    format::HandleId device;
    format::HandleId layout;
    PointerDecoder<VkDeviceSize> pLayoutSizeInBytes;

    auto GetTuple() const { return std::tie(device, layout, pLayoutSizeInBytes); }
};


struct GetDescriptorSetLayoutBindingOffsetEXT
{
    format::HandleId device;
    format::HandleId layout;
    uint32_t binding;
    PointerDecoder<VkDeviceSize> pOffset;

    auto GetTuple() const { return std::tie(device, layout, binding, pOffset); }
};


struct GetDescriptorEXT
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorGetInfoEXT> pDescriptorInfo;
    size_t dataSize;
    PointerDecoder<uint8_t> pDescriptor;

    auto GetTuple() const { return std::tie(device, pDescriptorInfo, dataSize, pDescriptor); }
};


struct CmdBindDescriptorBuffersEXT
{
    format::HandleId commandBuffer;
    uint32_t bufferCount;
    StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, bufferCount, pBindingInfos); }
};


struct CmdSetDescriptorBufferOffsetsEXT
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t firstSet;
    uint32_t setCount;
    PointerDecoder<uint32_t> pBufferIndices;
    PointerDecoder<VkDeviceSize> pOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets); }
};


struct CmdBindDescriptorBufferEmbeddedSamplersEXT
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, set); }
};


struct CmdSetFragmentShadingRateEnumNV
{
    format::HandleId commandBuffer;
    VkFragmentShadingRateNV shadingRate;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    auto GetTuple() const { return std::tie(commandBuffer, shadingRate, combinerOps); }
};


struct GetDeviceFaultInfoEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT> pFaultInfo;

    auto GetTuple() const { return std::tie(result, device, pFaultCounts, pFaultInfo); }
};


struct AcquireWinrtDisplayNV
{
    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, display); }
};


struct GetWinrtDisplayNV
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t deviceRelativeId;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;

    auto GetTuple() const { return std::tie(result, physicalDevice, deviceRelativeId, pDisplay); }
};


struct CreateDirectFBSurfaceEXT
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceDirectFBPresentationSupportEXT
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dfb;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, dfb); }
};


struct CmdSetVertexInputEXT
{
    format::HandleId commandBuffer;
    uint32_t vertexBindingDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT> pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT> pVertexAttributeDescriptions;

    auto GetTuple() const { return std::tie(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions); }
};


struct GetMemoryZirconHandleFUCHSIA
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;

    auto GetTuple() const { return std::tie(result, device, pGetZirconHandleInfo, pZirconHandle); }
};


struct GetMemoryZirconHandlePropertiesFUCHSIA
{
    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint32_t zirconHandle;
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA> pMemoryZirconHandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, zirconHandle, pMemoryZirconHandleProperties); }
};


struct ImportSemaphoreZirconHandleFUCHSIA
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA> pImportSemaphoreZirconHandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreZirconHandleInfo); }
};


struct GetSemaphoreZirconHandleFUCHSIA
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;

    auto GetTuple() const { return std::tie(result, device, pGetZirconHandleInfo, pZirconHandle); }
};


struct CmdBindInvocationMaskHUAWEI
{
    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    auto GetTuple() const { return std::tie(commandBuffer, imageView, imageLayout); }
};


struct GetMemoryRemoteAddressNV
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV> pMemoryGetRemoteAddressInfo;
    PointerDecoder<uint64_t, void*> pAddress;

    auto GetTuple() const { return std::tie(result, device, pMemoryGetRemoteAddressInfo, pAddress); }
};


struct CmdSetPatchControlPointsEXT
{
    format::HandleId commandBuffer;
    uint32_t patchControlPoints;

    auto GetTuple() const { return std::tie(commandBuffer, patchControlPoints); }
};


struct CmdSetRasterizerDiscardEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizerDiscardEnable); }
};


struct CmdSetDepthBiasEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasEnable); }
};


struct CmdSetLogicOpEXT
{
    format::HandleId commandBuffer;
    VkLogicOp logicOp;

    auto GetTuple() const { return std::tie(commandBuffer, logicOp); }
};


struct CmdSetPrimitiveRestartEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartEnable); }
};


struct CreateScreenSurfaceQNX
{
    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceScreenPresentationSupportQNX
{
    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t window;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, window); }
};


struct CmdSetColorWriteEnableEXT
{
    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorWriteEnables;

    auto GetTuple() const { return std::tie(commandBuffer, attachmentCount, pColorWriteEnables); }
};


struct CmdDrawMultiEXT
{
    format::HandleId commandBuffer;
    uint32_t drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT> pVertexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride); }
};


struct CmdDrawMultiIndexedEXT
{
    format::HandleId commandBuffer;
    uint32_t drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT> pIndexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;
    PointerDecoder<int32_t> pVertexOffset;

    auto GetTuple() const { return std::tie(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset); }
};


struct CreateMicromapEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkMicromapEXT> pMicromap;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pMicromap); }
};


struct DestroyMicromapEXT
{
    format::HandleId device;
    format::HandleId micromap;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, micromap, pAllocator); }
};


struct CmdBuildMicromapsEXT
{
    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos); }
};


struct BuildMicromapsEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, infoCount, pInfos); }
};


struct CopyMicromapEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMicromapToMemoryEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMemoryToMicromapEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct WriteMicromapsPropertiesEXT
{
    VkResult result;
    format::HandleId device;
    uint32_t micromapCount;
    HandlePointerDecoder<VkMicromapEXT> pMicromaps;
    VkQueryType queryType;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    size_t stride;

    auto GetTuple() const { return std::tie(result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride); }
};


struct CmdCopyMicromapEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMicromapToMemoryEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryToMicromapEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdWriteMicromapsPropertiesEXT
{
    format::HandleId commandBuffer;
    uint32_t micromapCount;
    HandlePointerDecoder<VkMicromapEXT> pMicromaps;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    auto GetTuple() const { return std::tie(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery); }
};


struct GetDeviceMicromapCompatibilityEXT
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    auto GetTuple() const { return std::tie(device, pVersionInfo, pCompatibility); }
};


struct GetMicromapBuildSizesEXT
{
    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pBuildInfo;
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT> pSizeInfo;

    auto GetTuple() const { return std::tie(device, buildType, pBuildInfo, pSizeInfo); }
};


struct CmdDrawClusterHUAWEI
{
    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDrawClusterIndirectHUAWEI
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset); }
};


struct SetDeviceMemoryPriorityEXT
{
    format::HandleId device;
    format::HandleId memory;
    float priority;

    auto GetTuple() const { return std::tie(device, memory, priority); }
};


struct CmdSetDispatchParametersARM
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchParametersARM> pDispatchParameters;

    auto GetTuple() const { return std::tie(commandBuffer, pDispatchParameters); }
};


struct GetDescriptorSetLayoutHostMappingInfoVALVE
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE> pBindingReference;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE> pHostMapping;

    auto GetTuple() const { return std::tie(device, pBindingReference, pHostMapping); }
};


struct GetDescriptorSetHostMappingVALVE
{
    format::HandleId device;
    format::HandleId descriptorSet;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(device, descriptorSet, ppData); }
};


struct GetPipelineIndirectMemoryRequirementsNV
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pMemoryRequirements); }
};


struct CmdUpdatePipelineIndirectBufferNV
{
    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline); }
};


struct GetPipelineIndirectDeviceAddressNV
{
    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdSetDepthClampEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthClampEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthClampEnable); }
};


struct CmdSetPolygonModeEXT
{
    format::HandleId commandBuffer;
    VkPolygonMode polygonMode;

    auto GetTuple() const { return std::tie(commandBuffer, polygonMode); }
};


struct CmdSetRasterizationSamplesEXT
{
    format::HandleId commandBuffer;
    VkSampleCountFlagBits rasterizationSamples;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizationSamples); }
};


struct CmdSetSampleMaskEXT
{
    format::HandleId commandBuffer;
    VkSampleCountFlagBits samples;
    PointerDecoder<VkSampleMask> pSampleMask;

    auto GetTuple() const { return std::tie(commandBuffer, samples, pSampleMask); }
};


struct CmdSetAlphaToCoverageEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 alphaToCoverageEnable;

    auto GetTuple() const { return std::tie(commandBuffer, alphaToCoverageEnable); }
};


struct CmdSetAlphaToOneEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 alphaToOneEnable;

    auto GetTuple() const { return std::tie(commandBuffer, alphaToOneEnable); }
};


struct CmdSetLogicOpEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 logicOpEnable;

    auto GetTuple() const { return std::tie(commandBuffer, logicOpEnable); }
};


struct CmdSetColorBlendEnableEXT
{
    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorBlendEnables;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables); }
};


struct CmdSetColorBlendEquationEXT
{
    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT> pColorBlendEquations;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations); }
};


struct CmdSetColorWriteMaskEXT
{
    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkColorComponentFlags> pColorWriteMasks;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks); }
};


struct CmdSetTessellationDomainOriginEXT
{
    format::HandleId commandBuffer;
    VkTessellationDomainOrigin domainOrigin;

    auto GetTuple() const { return std::tie(commandBuffer, domainOrigin); }
};


struct CmdSetRasterizationStreamEXT
{
    format::HandleId commandBuffer;
    uint32_t rasterizationStream;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizationStream); }
};


struct CmdSetConservativeRasterizationModeEXT
{
    format::HandleId commandBuffer;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;

    auto GetTuple() const { return std::tie(commandBuffer, conservativeRasterizationMode); }
};


struct CmdSetExtraPrimitiveOverestimationSizeEXT
{
    format::HandleId commandBuffer;
    float extraPrimitiveOverestimationSize;

    auto GetTuple() const { return std::tie(commandBuffer, extraPrimitiveOverestimationSize); }
};


struct CmdSetDepthClipEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 depthClipEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthClipEnable); }
};


struct CmdSetSampleLocationsEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 sampleLocationsEnable;

    auto GetTuple() const { return std::tie(commandBuffer, sampleLocationsEnable); }
};


struct CmdSetColorBlendAdvancedEXT
{
    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT> pColorBlendAdvanced;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced); }
};


struct CmdSetProvokingVertexModeEXT
{
    format::HandleId commandBuffer;
    VkProvokingVertexModeEXT provokingVertexMode;

    auto GetTuple() const { return std::tie(commandBuffer, provokingVertexMode); }
};


struct CmdSetLineRasterizationModeEXT
{
    format::HandleId commandBuffer;
    VkLineRasterizationModeEXT lineRasterizationMode;

    auto GetTuple() const { return std::tie(commandBuffer, lineRasterizationMode); }
};


struct CmdSetLineStippleEnableEXT
{
    format::HandleId commandBuffer;
    VkBool32 stippledLineEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stippledLineEnable); }
};


struct CmdSetDepthClipNegativeOneToOneEXT
{
    format::HandleId commandBuffer;
    VkBool32 negativeOneToOne;

    auto GetTuple() const { return std::tie(commandBuffer, negativeOneToOne); }
};


struct CmdSetViewportWScalingEnableNV
{
    format::HandleId commandBuffer;
    VkBool32 viewportWScalingEnable;

    auto GetTuple() const { return std::tie(commandBuffer, viewportWScalingEnable); }
};


struct CmdSetViewportSwizzleNV
{
    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewportSwizzles); }
};


struct CmdSetCoverageToColorEnableNV
{
    format::HandleId commandBuffer;
    VkBool32 coverageToColorEnable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageToColorEnable); }
};


struct CmdSetCoverageToColorLocationNV
{
    format::HandleId commandBuffer;
    uint32_t coverageToColorLocation;

    auto GetTuple() const { return std::tie(commandBuffer, coverageToColorLocation); }
};


struct CmdSetCoverageModulationModeNV
{
    format::HandleId commandBuffer;
    VkCoverageModulationModeNV coverageModulationMode;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationMode); }
};


struct CmdSetCoverageModulationTableEnableNV
{
    format::HandleId commandBuffer;
    VkBool32 coverageModulationTableEnable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationTableEnable); }
};


struct CmdSetCoverageModulationTableNV
{
    format::HandleId commandBuffer;
    uint32_t coverageModulationTableCount;
    PointerDecoder<float> pCoverageModulationTable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationTableCount, pCoverageModulationTable); }
};


struct CmdSetShadingRateImageEnableNV
{
    format::HandleId commandBuffer;
    VkBool32 shadingRateImageEnable;

    auto GetTuple() const { return std::tie(commandBuffer, shadingRateImageEnable); }
};


struct CmdSetRepresentativeFragmentTestEnableNV
{
    format::HandleId commandBuffer;
    VkBool32 representativeFragmentTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, representativeFragmentTestEnable); }
};


struct CmdSetCoverageReductionModeNV
{
    format::HandleId commandBuffer;
    VkCoverageReductionModeNV coverageReductionMode;

    auto GetTuple() const { return std::tie(commandBuffer, coverageReductionMode); }
};


struct GetShaderModuleIdentifierEXT
{
    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    auto GetTuple() const { return std::tie(device, shaderModule, pIdentifier); }
};


struct GetShaderModuleCreateInfoIdentifierEXT
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pIdentifier); }
};


struct GetPhysicalDeviceOpticalFlowImageFormatsNV
{
    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t> pFormatCount;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties); }
};


struct CreateOpticalFlowSessionNV
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkOpticalFlowSessionNV> pSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSession); }
};


struct DestroyOpticalFlowSessionNV
{
    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, session, pAllocator); }
};


struct BindOpticalFlowSessionImageNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId session;
    VkOpticalFlowSessionBindingPointNV bindingPoint;
    format::HandleId view;
    VkImageLayout layout;

    auto GetTuple() const { return std::tie(result, device, session, bindingPoint, view, layout); }
};


struct CmdOpticalFlowExecuteNV
{
    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV> pExecuteInfo;

    auto GetTuple() const { return std::tie(commandBuffer, session, pExecuteInfo); }
};


struct AntiLagUpdateAMD
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAntiLagDataAMD> pData;

    auto GetTuple() const { return std::tie(device, pData); }
};


struct CreateShadersEXT
{
    VkResult result;
    format::HandleId device;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderEXT> pShaders;

    auto GetTuple() const { return std::tie(result, device, createInfoCount, pCreateInfos, pAllocator, pShaders); }
};


struct DestroyShaderEXT
{
    format::HandleId device;
    format::HandleId shader;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, shader, pAllocator); }
};


struct GetShaderBinaryDataEXT
{
    VkResult result;
    format::HandleId device;
    format::HandleId shader;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, shader, pDataSize, pData); }
};


struct CmdBindShadersEXT
{
    format::HandleId commandBuffer;
    uint32_t stageCount;
    PointerDecoder<VkShaderStageFlagBits> pStages;
    HandlePointerDecoder<VkShaderEXT> pShaders;

    auto GetTuple() const { return std::tie(commandBuffer, stageCount, pStages, pShaders); }
};


struct CmdSetDepthClampRangeEXT
{
    format::HandleId commandBuffer;
    VkDepthClampModeEXT depthClampMode;
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT> pDepthClampRange;

    auto GetTuple() const { return std::tie(commandBuffer, depthClampMode, pDepthClampRange); }
};


struct GetFramebufferTilePropertiesQCOM
{
    VkResult result;
    format::HandleId device;
    format::HandleId framebuffer;
    PointerDecoder<uint32_t> pPropertiesCount;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;

    auto GetTuple() const { return std::tie(result, device, framebuffer, pPropertiesCount, pProperties); }
};


struct GetDynamicRenderingTilePropertiesQCOM
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pRenderingInfo, pProperties); }
};


struct GetPhysicalDeviceCooperativeVectorPropertiesNV
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeVectorPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct ConvertCooperativeVectorMatrixNV
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdConvertCooperativeVectorMatrixNV
{
    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV> pInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos); }
};


struct SetLatencySleepModeNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV> pSleepModeInfo;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSleepModeInfo); }
};


struct LatencySleepNV
{
    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV> pSleepInfo;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSleepInfo); }
};


struct SetLatencyMarkerNV
{
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    auto GetTuple() const { return std::tie(device, swapchain, pLatencyMarkerInfo); }
};


struct GetLatencyTimingsNV
{
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    auto GetTuple() const { return std::tie(device, swapchain, pLatencyMarkerInfo); }
};


struct QueueNotifyOutOfBandNV
{
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV> pQueueTypeInfo;

    auto GetTuple() const { return std::tie(queue, pQueueTypeInfo); }
};


struct CreateDataGraphPipelinesARM
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkDataGraphPipelineCreateInfoARM> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines); }
};


struct CreateDataGraphPipelineSessionARM
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionCreateInfoARM> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDataGraphPipelineSessionARM> pSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSession); }
};


struct GetDataGraphPipelineSessionBindPointRequirementsARM
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM> pInfo;
    PointerDecoder<uint32_t> pBindPointRequirementCount;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementARM> pBindPointRequirements;

    auto GetTuple() const { return std::tie(result, device, pInfo, pBindPointRequirementCount, pBindPointRequirements); }
};


struct GetDataGraphPipelineSessionMemoryRequirementsARM
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct BindDataGraphPipelineSessionMemoryARM
{
    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct DestroyDataGraphPipelineSessionARM
{
    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, session, pAllocator); }
};


struct CmdDispatchDataGraphARM
{
    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, session, pInfo); }
};


struct GetDataGraphPipelineAvailablePropertiesARM
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM> pPipelineInfo;
    PointerDecoder<uint32_t> pPropertiesCount;
    PointerDecoder<VkDataGraphPipelinePropertyARM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, pPropertiesCount, pProperties); }
};


struct GetDataGraphPipelinePropertiesARM
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM> pPipelineInfo;
    uint32_t propertiesCount;
    StructPointerDecoder<Decoded_VkDataGraphPipelinePropertyQueryResultARM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, propertiesCount, pProperties); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<uint32_t> pQueueFamilyDataGraphPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM> pQueueFamilyDataGraphProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphPropertyCount, pQueueFamilyDataGraphProperties); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM
{
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM> pQueueFamilyDataGraphProcessingEngineInfo;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM> pQueueFamilyDataGraphProcessingEngineProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyDataGraphProcessingEngineInfo, pQueueFamilyDataGraphProcessingEngineProperties); }
};


struct CmdSetAttachmentFeedbackLoopEnableEXT
{
    format::HandleId commandBuffer;
    VkImageAspectFlags aspectMask;

    auto GetTuple() const { return std::tie(commandBuffer, aspectMask); }
};


struct CmdBindTileMemoryQCOM
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM> pTileMemoryBindInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pTileMemoryBindInfo); }
};


struct CmdDecompressMemoryEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT> pDecompressMemoryInfoEXT;

    auto GetTuple() const { return std::tie(commandBuffer, pDecompressMemoryInfoEXT); }
};


struct CmdDecompressMemoryIndirectCountEXT
{
    format::HandleId commandBuffer;
    VkMemoryDecompressionMethodFlagsEXT decompressionMethod;
    VkDeviceAddress indirectCommandsAddress;
    VkDeviceAddress indirectCommandsCountAddress;
    uint32_t maxDecompressionCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride); }
};


struct GetPartitionedAccelerationStructuresBuildSizesNV
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPartitionedAccelerationStructureInstancesInputNV> pInfo;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    auto GetTuple() const { return std::tie(device, pInfo, pSizeInfo); }
};


struct CmdBuildPartitionedAccelerationStructuresNV
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV> pBuildInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBuildInfo); }
};


struct GetGeneratedCommandsMemoryRequirementsEXT
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct CmdPreprocessGeneratedCommandsEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT> pGeneratedCommandsInfo;
    format::HandleId stateCommandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer); }
};


struct CmdExecuteGeneratedCommandsEXT
{
    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, isPreprocessed, pGeneratedCommandsInfo); }
};


struct CreateIndirectCommandsLayoutEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT> pIndirectCommandsLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout); }
};


struct DestroyIndirectCommandsLayoutEXT
{
    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectCommandsLayout, pAllocator); }
};


struct CreateIndirectExecutionSetEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectExecutionSetCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectExecutionSetEXT> pIndirectExecutionSet;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectExecutionSet); }
};


struct DestroyIndirectExecutionSetEXT
{
    format::HandleId device;
    format::HandleId indirectExecutionSet;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, pAllocator); }
};


struct UpdateIndirectExecutionSetPipelineEXT
{
    format::HandleId device;
    format::HandleId indirectExecutionSet;
    uint32_t executionSetWriteCount;
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetPipelineEXT> pExecutionSetWrites;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites); }
};


struct UpdateIndirectExecutionSetShaderEXT
{
    format::HandleId device;
    format::HandleId indirectExecutionSet;
    uint32_t executionSetWriteCount;
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetShaderEXT> pExecutionSetWrites;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites); }
};


struct GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV
{
    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetMemoryMetalHandleEXT
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetMetalHandleInfoEXT> pGetMetalHandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetMetalHandleInfo, pHandle); }
};


struct GetMemoryMetalHandlePropertiesEXT
{
    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHandle;
    StructPointerDecoder<Decoded_VkMemoryMetalHandlePropertiesEXT> pMemoryMetalHandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, pHandle, pMemoryMetalHandleProperties); }
};


struct EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM
{
    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<uint32_t> pCounterCount;
    StructPointerDecoder<Decoded_VkPerformanceCounterARM> pCounters;
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionARM> pCounterDescriptions;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions); }
};


struct CmdEndRendering2EXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR> pRenderingEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingEndInfo); }
};


struct CmdBeginCustomResolveEXT
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT> pBeginCustomResolveInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBeginCustomResolveInfo); }
};


struct CmdSetComputeOccupancyPriorityNV
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV> pParameters;

    auto GetTuple() const { return std::tie(commandBuffer, pParameters); }
};


struct CmdSetPrimitiveRestartIndexEXT
{
    format::HandleId commandBuffer;
    uint32_t primitiveRestartIndex;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartIndex); }
};


struct CreateAccelerationStructureKHR
{
    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct DestroyAccelerationStructureKHR
{
    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, accelerationStructure, pAllocator); }
};


struct CmdBuildAccelerationStructuresKHR
{
    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*> ppBuildRangeInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos, ppBuildRangeInfos); }
};


struct CmdBuildAccelerationStructuresIndirectKHR
{
    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    PointerDecoder<VkDeviceAddress> pIndirectDeviceAddresses;
    PointerDecoder<uint32_t> pIndirectStrides;
    PointerDecoder<uint32_t*> ppMaxPrimitiveCounts;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts); }
};


struct CopyAccelerationStructureToMemoryKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMemoryToAccelerationStructureKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct WriteAccelerationStructuresPropertiesKHR
{
    VkResult result;
    format::HandleId device;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType queryType;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    size_t stride;

    auto GetTuple() const { return std::tie(result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride); }
};


struct CmdCopyAccelerationStructureKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyAccelerationStructureToMemoryKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryToAccelerationStructureKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct GetAccelerationStructureDeviceAddressKHR
{
    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdWriteAccelerationStructuresPropertiesKHR
{
    format::HandleId commandBuffer;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    auto GetTuple() const { return std::tie(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery); }
};


struct GetDeviceAccelerationStructureCompatibilityKHR
{
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    auto GetTuple() const { return std::tie(device, pVersionInfo, pCompatibility); }
};


struct GetAccelerationStructureBuildSizesKHR
{
    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pBuildInfo;
    PointerDecoder<uint32_t> pMaxPrimitiveCounts;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    auto GetTuple() const { return std::tie(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo); }
};


struct CmdTraceRaysKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    uint32_t width;
    uint32_t height;
    uint32_t depth;

    auto GetTuple() const { return std::tie(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth); }
};


struct GetRayTracingCaptureReplayShaderGroupHandlesKHR
{
    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pipeline, firstGroup, groupCount, dataSize, pData); }
};


struct CmdTraceRaysIndirectKHR
{
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    VkDeviceAddress indirectDeviceAddress;

    auto GetTuple() const { return std::tie(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress); }
};


struct GetRayTracingShaderGroupStackSizeKHR
{
    VkDeviceSize result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t group;
    VkShaderGroupShaderKHR groupShader;

    auto GetTuple() const { return std::tie(result, device, pipeline, group, groupShader); }
};


struct CmdSetRayTracingPipelineStackSizeKHR
{
    format::HandleId commandBuffer;
    uint32_t pipelineStackSize;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStackSize); }
};


struct CmdDrawMeshTasksEXT
{
    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDrawMeshTasksIndirectEXT
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawMeshTasksIndirectCountEXT
{
    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride); }
};


GFXRECON_END_NAMESPACE(args)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_DECODER_ARGS_H
