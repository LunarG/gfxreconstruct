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
#include "decode/vulkan_decode_typed_struct.h"
#include "decode/vulkan_pnext_node.h"
#include "format/format.h"
#include "generated/generated_vulkan_schema_types.h"
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
    using api_element = schema::vulkan::api_elements::CreateInstance;

    VkResult result;
    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkInstance> pInstance;

    auto GetTuple() const { return std::tie(result, pCreateInfo, pAllocator, pInstance); }
};


struct DestroyInstance
{
    using api_element = schema::vulkan::api_elements::DestroyInstance;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, pAllocator); }
};


struct EnumeratePhysicalDevices
{
    using api_element = schema::vulkan::api_elements::EnumeratePhysicalDevices;

    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceCount, pPhysicalDevices); }
};


struct GetPhysicalDeviceFeatures
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFeatures;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceFormatProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFormatProperties;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceImageFormatProperties;

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
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceProperties;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyProperties;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceMemoryProperties;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct CreateDevice
{
    using api_element = schema::vulkan::api_elements::CreateDevice;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDevice> pDevice;

    auto GetTuple() const { return std::tie(result, physicalDevice, pCreateInfo, pAllocator, pDevice); }
};


struct DestroyDevice
{
    using api_element = schema::vulkan::api_elements::DestroyDevice;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pAllocator); }
};


struct GetDeviceQueue
{
    using api_element = schema::vulkan::api_elements::GetDeviceQueue;

    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    HandlePointerDecoder<VkQueue> pQueue;

    auto GetTuple() const { return std::tie(device, queueFamilyIndex, queueIndex, pQueue); }
};


struct QueueSubmit
{
    using api_element = schema::vulkan::api_elements::QueueSubmit;

    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct QueueWaitIdle
{
    using api_element = schema::vulkan::api_elements::QueueWaitIdle;

    VkResult result;
    format::HandleId queue;

    auto GetTuple() const { return std::tie(result, queue); }
};


struct DeviceWaitIdle
{
    using api_element = schema::vulkan::api_elements::DeviceWaitIdle;

    VkResult result;
    format::HandleId device;

    auto GetTuple() const { return std::tie(result, device); }
};


struct AllocateMemory
{
    using api_element = schema::vulkan::api_elements::AllocateMemory;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeviceMemory> pMemory;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pAllocator, pMemory); }
};


struct FreeMemory
{
    using api_element = schema::vulkan::api_elements::FreeMemory;

    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, memory, pAllocator); }
};


struct MapMemory
{
    using api_element = schema::vulkan::api_elements::MapMemory;

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
    using api_element = schema::vulkan::api_elements::UnmapMemory;

    format::HandleId device;
    format::HandleId memory;

    auto GetTuple() const { return std::tie(device, memory); }
};


struct FlushMappedMemoryRanges
{
    using api_element = schema::vulkan::api_elements::FlushMappedMemoryRanges;

    VkResult result;
    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;

    auto GetTuple() const { return std::tie(result, device, memoryRangeCount, pMemoryRanges); }
};


struct InvalidateMappedMemoryRanges
{
    using api_element = schema::vulkan::api_elements::InvalidateMappedMemoryRanges;

    VkResult result;
    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;

    auto GetTuple() const { return std::tie(result, device, memoryRangeCount, pMemoryRanges); }
};


struct GetDeviceMemoryCommitment
{
    using api_element = schema::vulkan::api_elements::GetDeviceMemoryCommitment;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    auto GetTuple() const { return std::tie(device, memory, pCommittedMemoryInBytes); }
};


struct BindBufferMemory
{
    using api_element = schema::vulkan::api_elements::BindBufferMemory;

    VkResult result;
    format::HandleId device;
    format::HandleId buffer;
    format::HandleId memory;
    VkDeviceSize memoryOffset;

    auto GetTuple() const { return std::tie(result, device, buffer, memory, memoryOffset); }
};


struct BindImageMemory
{
    using api_element = schema::vulkan::api_elements::BindImageMemory;

    VkResult result;
    format::HandleId device;
    format::HandleId image;
    format::HandleId memory;
    VkDeviceSize memoryOffset;

    auto GetTuple() const { return std::tie(result, device, image, memory, memoryOffset); }
};


struct GetBufferMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetBufferMemoryRequirements;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, buffer, pMemoryRequirements); }
};


struct GetImageMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetImageMemoryRequirements;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, image, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetImageSparseMemoryRequirements;

    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct GetPhysicalDeviceSparseImageFormatProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSparseImageFormatProperties;

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
    using api_element = schema::vulkan::api_elements::QueueBindSparse;

    VkResult result;
    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, bindInfoCount, pBindInfo, fence); }
};


struct CreateFence
{
    using api_element = schema::vulkan::api_elements::CreateFence;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pFence); }
};


struct DestroyFence
{
    using api_element = schema::vulkan::api_elements::DestroyFence;

    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, fence, pAllocator); }
};


struct ResetFences
{
    using api_element = schema::vulkan::api_elements::ResetFences;

    VkResult result;
    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;

    auto GetTuple() const { return std::tie(result, device, fenceCount, pFences); }
};


struct GetFenceStatus
{
    using api_element = schema::vulkan::api_elements::GetFenceStatus;

    VkResult result;
    format::HandleId device;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, device, fence); }
};


struct WaitForFences
{
    using api_element = schema::vulkan::api_elements::WaitForFences;

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
    using api_element = schema::vulkan::api_elements::CreateSemaphore;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSemaphore> pSemaphore;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSemaphore); }
};


struct DestroySemaphore
{
    using api_element = schema::vulkan::api_elements::DestroySemaphore;

    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, semaphore, pAllocator); }
};


struct CreateQueryPool
{
    using api_element = schema::vulkan::api_elements::CreateQueryPool;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkQueryPool> pQueryPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pQueryPool); }
};


struct DestroyQueryPool
{
    using api_element = schema::vulkan::api_elements::DestroyQueryPool;

    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, queryPool, pAllocator); }
};


struct GetQueryPoolResults
{
    using api_element = schema::vulkan::api_elements::GetQueryPoolResults;

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
    using api_element = schema::vulkan::api_elements::CreateBuffer;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBuffer> pBuffer;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pBuffer); }
};


struct DestroyBuffer
{
    using api_element = schema::vulkan::api_elements::DestroyBuffer;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, buffer, pAllocator); }
};


struct CreateImage
{
    using api_element = schema::vulkan::api_elements::CreateImage;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImage> pImage;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pImage); }
};


struct DestroyImage
{
    using api_element = schema::vulkan::api_elements::DestroyImage;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, image, pAllocator); }
};


struct GetImageSubresourceLayout
{
    using api_element = schema::vulkan::api_elements::GetImageSubresourceLayout;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct CreateImageView
{
    using api_element = schema::vulkan::api_elements::CreateImageView;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImageView> pView;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pView); }
};


struct DestroyImageView
{
    using api_element = schema::vulkan::api_elements::DestroyImageView;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, imageView, pAllocator); }
};


struct CreateCommandPool
{
    using api_element = schema::vulkan::api_elements::CreateCommandPool;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkCommandPool> pCommandPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pCommandPool); }
};


struct DestroyCommandPool
{
    using api_element = schema::vulkan::api_elements::DestroyCommandPool;

    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, commandPool, pAllocator); }
};


struct ResetCommandPool
{
    using api_element = schema::vulkan::api_elements::ResetCommandPool;

    VkResult result;
    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolResetFlags flags;

    auto GetTuple() const { return std::tie(result, device, commandPool, flags); }
};


struct AllocateCommandBuffers
{
    using api_element = schema::vulkan::api_elements::AllocateCommandBuffers;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pCommandBuffers); }
};


struct FreeCommandBuffers
{
    using api_element = schema::vulkan::api_elements::FreeCommandBuffers;

    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(device, commandPool, commandBufferCount, pCommandBuffers); }
};


struct BeginCommandBuffer
{
    using api_element = schema::vulkan::api_elements::BeginCommandBuffer;

    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pBeginInfo); }
};


struct EndCommandBuffer
{
    using api_element = schema::vulkan::api_elements::EndCommandBuffer;

    VkResult result;
    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(result, commandBuffer); }
};


struct ResetCommandBuffer
{
    using api_element = schema::vulkan::api_elements::ResetCommandBuffer;

    VkResult result;
    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;

    auto GetTuple() const { return std::tie(result, commandBuffer, flags); }
};


struct CmdCopyBuffer
{
    using api_element = schema::vulkan::api_elements::CmdCopyBuffer;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    auto GetTuple() const { return std::tie(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions); }
};


struct CmdCopyImage
{
    using api_element = schema::vulkan::api_elements::CmdCopyImage;

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
    using api_element = schema::vulkan::api_elements::CmdCopyBufferToImage;

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
    using api_element = schema::vulkan::api_elements::CmdCopyImageToBuffer;

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
    using api_element = schema::vulkan::api_elements::CmdUpdateBuffer;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(commandBuffer, dstBuffer, dstOffset, dataSize, pData); }
};


struct CmdFillBuffer
{
    using api_element = schema::vulkan::api_elements::CmdFillBuffer;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    auto GetTuple() const { return std::tie(commandBuffer, dstBuffer, dstOffset, size, data); }
};


struct CmdPipelineBarrier
{
    using api_element = schema::vulkan::api_elements::CmdPipelineBarrier;

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
    using api_element = schema::vulkan::api_elements::CmdBeginQuery;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, flags); }
};


struct CmdEndQuery
{
    using api_element = schema::vulkan::api_elements::CmdEndQuery;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query); }
};


struct CmdResetQueryPool
{
    using api_element = schema::vulkan::api_elements::CmdResetQueryPool;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, firstQuery, queryCount); }
};


struct CmdWriteTimestamp
{
    using api_element = schema::vulkan::api_elements::CmdWriteTimestamp;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStage, queryPool, query); }
};


struct CmdCopyQueryPoolResults
{
    using api_element = schema::vulkan::api_elements::CmdCopyQueryPoolResults;

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
    using api_element = schema::vulkan::api_elements::CmdExecuteCommands;

    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    auto GetTuple() const { return std::tie(commandBuffer, commandBufferCount, pCommandBuffers); }
};


struct CreateEvent
{
    using api_element = schema::vulkan::api_elements::CreateEvent;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkEvent> pEvent;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pEvent); }
};


struct DestroyEvent
{
    using api_element = schema::vulkan::api_elements::DestroyEvent;

    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, event, pAllocator); }
};


struct GetEventStatus
{
    using api_element = schema::vulkan::api_elements::GetEventStatus;

    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct SetEvent
{
    using api_element = schema::vulkan::api_elements::SetEvent;

    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct ResetEvent
{
    using api_element = schema::vulkan::api_elements::ResetEvent;

    VkResult result;
    format::HandleId device;
    format::HandleId event;

    auto GetTuple() const { return std::tie(result, device, event); }
};


struct CreateBufferView
{
    using api_element = schema::vulkan::api_elements::CreateBufferView;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBufferView> pView;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pView); }
};


struct DestroyBufferView
{
    using api_element = schema::vulkan::api_elements::DestroyBufferView;

    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, bufferView, pAllocator); }
};


struct CreateShaderModule
{
    using api_element = schema::vulkan::api_elements::CreateShaderModule;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderModule> pShaderModule;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pShaderModule); }
};


struct DestroyShaderModule
{
    using api_element = schema::vulkan::api_elements::DestroyShaderModule;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, shaderModule, pAllocator); }
};


struct CreatePipelineCache
{
    using api_element = schema::vulkan::api_elements::CreatePipelineCache;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineCache> pPipelineCache;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPipelineCache); }
};


struct DestroyPipelineCache
{
    using api_element = schema::vulkan::api_elements::DestroyPipelineCache;

    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineCache, pAllocator); }
};


struct GetPipelineCacheData
{
    using api_element = schema::vulkan::api_elements::GetPipelineCacheData;

    VkResult result;
    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, pipelineCache, pDataSize, pData); }
};


struct MergePipelineCaches
{
    using api_element = schema::vulkan::api_elements::MergePipelineCaches;

    VkResult result;
    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkPipelineCache> pSrcCaches;

    auto GetTuple() const { return std::tie(result, device, dstCache, srcCacheCount, pSrcCaches); }
};


struct CreateComputePipelines
{
    using api_element = schema::vulkan::api_elements::CreateComputePipelines;

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
    using api_element = schema::vulkan::api_elements::DestroyPipeline;

    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipeline, pAllocator); }
};


struct CreatePipelineLayout
{
    using api_element = schema::vulkan::api_elements::CreatePipelineLayout;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineLayout> pPipelineLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPipelineLayout); }
};


struct DestroyPipelineLayout
{
    using api_element = schema::vulkan::api_elements::DestroyPipelineLayout;

    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineLayout, pAllocator); }
};


struct CreateSampler
{
    using api_element = schema::vulkan::api_elements::CreateSampler;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSampler> pSampler;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSampler); }
};


struct DestroySampler
{
    using api_element = schema::vulkan::api_elements::DestroySampler;

    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, sampler, pAllocator); }
};


struct CreateDescriptorSetLayout
{
    using api_element = schema::vulkan::api_elements::CreateDescriptorSetLayout;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSetLayout); }
};


struct DestroyDescriptorSetLayout
{
    using api_element = schema::vulkan::api_elements::DestroyDescriptorSetLayout;

    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorSetLayout, pAllocator); }
};


struct CreateDescriptorPool
{
    using api_element = schema::vulkan::api_elements::CreateDescriptorPool;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorPool> pDescriptorPool;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorPool); }
};


struct DestroyDescriptorPool
{
    using api_element = schema::vulkan::api_elements::DestroyDescriptorPool;

    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorPool, pAllocator); }
};


struct ResetDescriptorPool
{
    using api_element = schema::vulkan::api_elements::ResetDescriptorPool;

    VkResult result;
    format::HandleId device;
    format::HandleId descriptorPool;
    VkDescriptorPoolResetFlags flags;

    auto GetTuple() const { return std::tie(result, device, descriptorPool, flags); }
};


struct AllocateDescriptorSets
{
    using api_element = schema::vulkan::api_elements::AllocateDescriptorSets;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;

    auto GetTuple() const { return std::tie(result, device, pAllocateInfo, pDescriptorSets); }
};


struct FreeDescriptorSets
{
    using api_element = schema::vulkan::api_elements::FreeDescriptorSets;

    VkResult result;
    format::HandleId device;
    format::HandleId descriptorPool;
    uint32_t descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;

    auto GetTuple() const { return std::tie(result, device, descriptorPool, descriptorSetCount, pDescriptorSets); }
};


struct UpdateDescriptorSets
{
    using api_element = schema::vulkan::api_elements::UpdateDescriptorSets;

    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    auto GetTuple() const { return std::tie(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies); }
};


struct CmdBindPipeline
{
    using api_element = schema::vulkan::api_elements::CmdBindPipeline;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline); }
};


struct CmdBindDescriptorSets
{
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorSets;

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
    using api_element = schema::vulkan::api_elements::CmdClearColorImage;

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
    using api_element = schema::vulkan::api_elements::CmdDispatch;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDispatchIndirect
{
    using api_element = schema::vulkan::api_elements::CmdDispatchIndirect;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset); }
};


struct CmdSetEvent
{
    using api_element = schema::vulkan::api_elements::CmdSetEvent;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdResetEvent
{
    using api_element = schema::vulkan::api_elements::CmdResetEvent;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents
{
    using api_element = schema::vulkan::api_elements::CmdWaitEvents;

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
    using api_element = schema::vulkan::api_elements::CmdPushConstants;

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
    using api_element = schema::vulkan::api_elements::CreateGraphicsPipelines;

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
    using api_element = schema::vulkan::api_elements::CreateFramebuffer;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFramebuffer> pFramebuffer;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pFramebuffer); }
};


struct DestroyFramebuffer
{
    using api_element = schema::vulkan::api_elements::DestroyFramebuffer;

    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, framebuffer, pAllocator); }
};


struct CreateRenderPass
{
    using api_element = schema::vulkan::api_elements::CreateRenderPass;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct DestroyRenderPass
{
    using api_element = schema::vulkan::api_elements::DestroyRenderPass;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, renderPass, pAllocator); }
};


struct GetRenderAreaGranularity
{
    using api_element = schema::vulkan::api_elements::GetRenderAreaGranularity;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, renderPass, pGranularity); }
};


struct CmdSetViewport
{
    using api_element = schema::vulkan::api_elements::CmdSetViewport;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewports); }
};


struct CmdSetScissor
{
    using api_element = schema::vulkan::api_elements::CmdSetScissor;

    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, firstScissor, scissorCount, pScissors); }
};


struct CmdSetLineWidth
{
    using api_element = schema::vulkan::api_elements::CmdSetLineWidth;

    format::HandleId commandBuffer;
    float lineWidth;

    auto GetTuple() const { return std::tie(commandBuffer, lineWidth); }
};


struct CmdSetDepthBias
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBias;

    format::HandleId commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor); }
};


struct CmdSetBlendConstants
{
    using api_element = schema::vulkan::api_elements::CmdSetBlendConstants;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    auto GetTuple() const { return std::tie(commandBuffer, blendConstants); }
};


struct CmdSetDepthBounds
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBounds;

    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    auto GetTuple() const { return std::tie(commandBuffer, minDepthBounds, maxDepthBounds); }
};


struct CmdSetStencilCompareMask
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilCompareMask;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, compareMask); }
};


struct CmdSetStencilWriteMask
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilWriteMask;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, writeMask); }
};


struct CmdSetStencilReference
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilReference;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    auto GetTuple() const { return std::tie(commandBuffer, faceMask, reference); }
};


struct CmdBindIndexBuffer
{
    using api_element = schema::vulkan::api_elements::CmdBindIndexBuffer;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, indexType); }
};


struct CmdBindVertexBuffers
{
    using api_element = schema::vulkan::api_elements::CmdBindVertexBuffers;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets); }
};


struct CmdDraw
{
    using api_element = schema::vulkan::api_elements::CmdDraw;

    format::HandleId commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    auto GetTuple() const { return std::tie(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance); }
};


struct CmdDrawIndexed
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndexed;

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
    using api_element = schema::vulkan::api_elements::CmdDrawIndirect;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawIndexedIndirect
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirect;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdBlitImage
{
    using api_element = schema::vulkan::api_elements::CmdBlitImage;

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
    using api_element = schema::vulkan::api_elements::CmdClearDepthStencilImage;

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
    using api_element = schema::vulkan::api_elements::CmdClearAttachments;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    auto GetTuple() const { return std::tie(commandBuffer, attachmentCount, pAttachments, rectCount, pRects); }
};


struct CmdResolveImage
{
    using api_element = schema::vulkan::api_elements::CmdResolveImage;

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
    using api_element = schema::vulkan::api_elements::CmdBeginRenderPass;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, contents); }
};


struct CmdNextSubpass
{
    using api_element = schema::vulkan::api_elements::CmdNextSubpass;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    auto GetTuple() const { return std::tie(commandBuffer, contents); }
};


struct CmdEndRenderPass
{
    using api_element = schema::vulkan::api_elements::CmdEndRenderPass;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct BindBufferMemory2
{
    using api_element = schema::vulkan::api_elements::BindBufferMemory2;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct BindImageMemory2
{
    using api_element = schema::vulkan::api_elements::BindImageMemory2;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct GetDeviceGroupPeerMemoryFeatures
{
    using api_element = schema::vulkan::api_elements::GetDeviceGroupPeerMemoryFeatures;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    auto GetTuple() const { return std::tie(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }
};


struct CmdSetDeviceMask
{
    using api_element = schema::vulkan::api_elements::CmdSetDeviceMask;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    auto GetTuple() const { return std::tie(commandBuffer, deviceMask); }
};


struct EnumeratePhysicalDeviceGroups
{
    using api_element = schema::vulkan::api_elements::EnumeratePhysicalDeviceGroups;

    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }
};


struct GetImageMemoryRequirements2
{
    using api_element = schema::vulkan::api_elements::GetImageMemoryRequirements2;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetBufferMemoryRequirements2
{
    using api_element = schema::vulkan::api_elements::GetBufferMemoryRequirements2;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements2
{
    using api_element = schema::vulkan::api_elements::GetImageSparseMemoryRequirements2;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct GetPhysicalDeviceFeatures2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFeatures2;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceProperties2;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceFormatProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFormatProperties2;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceImageFormatProperties2;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pImageFormatInfo, pImageFormatProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyProperties2;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceMemoryProperties2;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct GetPhysicalDeviceSparseImageFormatProperties2
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSparseImageFormatProperties2;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pFormatInfo, pPropertyCount, pProperties); }
};


struct TrimCommandPool
{
    using api_element = schema::vulkan::api_elements::TrimCommandPool;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    auto GetTuple() const { return std::tie(device, commandPool, flags); }
};


struct GetDeviceQueue2
{
    using api_element = schema::vulkan::api_elements::GetDeviceQueue2;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    HandlePointerDecoder<VkQueue> pQueue;

    auto GetTuple() const { return std::tie(device, pQueueInfo, pQueue); }
};


struct GetPhysicalDeviceExternalBufferProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalBufferProperties;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }
};


struct GetPhysicalDeviceExternalFenceProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalFenceProperties;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }
};


struct GetPhysicalDeviceExternalSemaphoreProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalSemaphoreProperties;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }
};


struct CmdDispatchBase
{
    using api_element = schema::vulkan::api_elements::CmdDispatchBase;

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
    using api_element = schema::vulkan::api_elements::CreateDescriptorUpdateTemplate;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }
};


struct DestroyDescriptorUpdateTemplate
{
    using api_element = schema::vulkan::api_elements::DestroyDescriptorUpdateTemplate;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorUpdateTemplate, pAllocator); }
};


struct GetDescriptorSetLayoutSupport
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetLayoutSupport;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pSupport); }
};


struct CreateSamplerYcbcrConversion
{
    using api_element = schema::vulkan::api_elements::CreateSamplerYcbcrConversion;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pYcbcrConversion); }
};


struct DestroySamplerYcbcrConversion
{
    using api_element = schema::vulkan::api_elements::DestroySamplerYcbcrConversion;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, ycbcrConversion, pAllocator); }
};


struct ResetQueryPool
{
    using api_element = schema::vulkan::api_elements::ResetQueryPool;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(device, queryPool, firstQuery, queryCount); }
};


struct GetSemaphoreCounterValue
{
    using api_element = schema::vulkan::api_elements::GetSemaphoreCounterValue;

    VkResult result;
    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;

    auto GetTuple() const { return std::tie(result, device, semaphore, pValue); }
};


struct WaitSemaphores
{
    using api_element = schema::vulkan::api_elements::WaitSemaphores;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, pWaitInfo, timeout); }
};


struct SignalSemaphore
{
    using api_element = schema::vulkan::api_elements::SignalSemaphore;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;

    auto GetTuple() const { return std::tie(result, device, pSignalInfo); }
};


struct GetBufferDeviceAddress
{
    using api_element = schema::vulkan::api_elements::GetBufferDeviceAddress;

    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetBufferOpaqueCaptureAddress
{
    using api_element = schema::vulkan::api_elements::GetBufferOpaqueCaptureAddress;

    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetDeviceMemoryOpaqueCaptureAddress
{
    using api_element = schema::vulkan::api_elements::GetDeviceMemoryOpaqueCaptureAddress;

    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdDrawIndirectCount
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectCount;

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
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirectCount;

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
    using api_element = schema::vulkan::api_elements::CreateRenderPass2;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct CmdBeginRenderPass2
{
    using api_element = schema::vulkan::api_elements::CmdBeginRenderPass2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }
};


struct CmdNextSubpass2
{
    using api_element = schema::vulkan::api_elements::CmdNextSubpass2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }
};


struct CmdEndRenderPass2
{
    using api_element = schema::vulkan::api_elements::CmdEndRenderPass2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassEndInfo); }
};


struct GetPhysicalDeviceToolProperties
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceToolProperties;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pToolCount, pToolProperties); }
};


struct CreatePrivateDataSlot
{
    using api_element = schema::vulkan::api_elements::CreatePrivateDataSlot;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPrivateDataSlot); }
};


struct DestroyPrivateDataSlot
{
    using api_element = schema::vulkan::api_elements::DestroyPrivateDataSlot;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, privateDataSlot, pAllocator); }
};


struct SetPrivateData
{
    using api_element = schema::vulkan::api_elements::SetPrivateData;

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
    using api_element = schema::vulkan::api_elements::GetPrivateData;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    auto GetTuple() const { return std::tie(device, objectType, objectHandle, privateDataSlot, pData); }
};


struct CmdPipelineBarrier2
{
    using api_element = schema::vulkan::api_elements::CmdPipelineBarrier2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDependencyInfo); }
};


struct CmdWriteTimestamp2
{
    using api_element = schema::vulkan::api_elements::CmdWriteTimestamp2;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, stage, queryPool, query); }
};


struct QueueSubmit2
{
    using api_element = schema::vulkan::api_elements::QueueSubmit2;

    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct CmdCopyBuffer2
{
    using api_element = schema::vulkan::api_elements::CmdCopyBuffer2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferInfo); }
};


struct CmdCopyImage2
{
    using api_element = schema::vulkan::api_elements::CmdCopyImage2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageInfo); }
};


struct CmdCopyBufferToImage2
{
    using api_element = schema::vulkan::api_elements::CmdCopyBufferToImage2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferToImageInfo); }
};


struct CmdCopyImageToBuffer2
{
    using api_element = schema::vulkan::api_elements::CmdCopyImageToBuffer2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageToBufferInfo); }
};


struct GetDeviceBufferMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetDeviceBufferMemoryRequirements;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageMemoryRequirements;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageSparseMemoryRequirements
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageSparseMemoryRequirements;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CmdSetEvent2
{
    using api_element = schema::vulkan::api_elements::CmdSetEvent2;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, event, pDependencyInfo); }
};


struct CmdResetEvent2
{
    using api_element = schema::vulkan::api_elements::CmdResetEvent2;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents2
{
    using api_element = schema::vulkan::api_elements::CmdWaitEvents2;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    auto GetTuple() const { return std::tie(commandBuffer, eventCount, pEvents, pDependencyInfos); }
};


struct CmdBlitImage2
{
    using api_element = schema::vulkan::api_elements::CmdBlitImage2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBlitImageInfo); }
};


struct CmdResolveImage2
{
    using api_element = schema::vulkan::api_elements::CmdResolveImage2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pResolveImageInfo); }
};


struct CmdBeginRendering
{
    using api_element = schema::vulkan::api_elements::CmdBeginRendering;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingInfo); }
};


struct CmdEndRendering
{
    using api_element = schema::vulkan::api_elements::CmdEndRendering;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdSetCullMode
{
    using api_element = schema::vulkan::api_elements::CmdSetCullMode;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    auto GetTuple() const { return std::tie(commandBuffer, cullMode); }
};


struct CmdSetFrontFace
{
    using api_element = schema::vulkan::api_elements::CmdSetFrontFace;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    auto GetTuple() const { return std::tie(commandBuffer, frontFace); }
};


struct CmdSetPrimitiveTopology
{
    using api_element = schema::vulkan::api_elements::CmdSetPrimitiveTopology;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveTopology); }
};


struct CmdSetViewportWithCount
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportWithCount;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, viewportCount, pViewports); }
};


struct CmdSetScissorWithCount
{
    using api_element = schema::vulkan::api_elements::CmdSetScissorWithCount;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, scissorCount, pScissors); }
};


struct CmdBindVertexBuffers2
{
    using api_element = schema::vulkan::api_elements::CmdBindVertexBuffers2;

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
    using api_element = schema::vulkan::api_elements::CmdSetDepthTestEnable;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthTestEnable); }
};


struct CmdSetDepthWriteEnable
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthWriteEnable;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthWriteEnable); }
};


struct CmdSetDepthCompareOp
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthCompareOp;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    auto GetTuple() const { return std::tie(commandBuffer, depthCompareOp); }
};


struct CmdSetDepthBoundsTestEnable
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBoundsTestEnable;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBoundsTestEnable); }
};


struct CmdSetStencilTestEnable
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilTestEnable;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stencilTestEnable); }
};


struct CmdSetStencilOp
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilOp;

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
    using api_element = schema::vulkan::api_elements::CmdSetRasterizerDiscardEnable;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizerDiscardEnable); }
};


struct CmdSetDepthBiasEnable
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBiasEnable;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasEnable); }
};


struct CmdSetPrimitiveRestartEnable
{
    using api_element = schema::vulkan::api_elements::CmdSetPrimitiveRestartEnable;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartEnable); }
};


struct MapMemory2
{
    using api_element = schema::vulkan::api_elements::MapMemory2;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfo> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(result, device, pMemoryMapInfo, ppData); }
};


struct UnmapMemory2
{
    using api_element = schema::vulkan::api_elements::UnmapMemory2;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo> pMemoryUnmapInfo;

    auto GetTuple() const { return std::tie(result, device, pMemoryUnmapInfo); }
};


struct GetDeviceImageSubresourceLayout
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageSubresourceLayout;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, pInfo, pLayout); }
};


struct GetImageSubresourceLayout2
{
    using api_element = schema::vulkan::api_elements::GetImageSubresourceLayout2;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct CopyMemoryToImage
{
    using api_element = schema::vulkan::api_elements::CopyMemoryToImage;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo> pCopyMemoryToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyMemoryToImageInfo); }
};


struct CopyImageToMemory
{
    using api_element = schema::vulkan::api_elements::CopyImageToMemory;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo> pCopyImageToMemoryInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToMemoryInfo); }
};


struct CopyImageToImage
{
    using api_element = schema::vulkan::api_elements::CopyImageToImage;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo> pCopyImageToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToImageInfo); }
};


struct TransitionImageLayout
{
    using api_element = schema::vulkan::api_elements::TransitionImageLayout;

    VkResult result;
    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo> pTransitions;

    auto GetTuple() const { return std::tie(result, device, transitionCount, pTransitions); }
};


struct CmdPushDescriptorSet
{
    using api_element = schema::vulkan::api_elements::CmdPushDescriptorSet;

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
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorSets2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo> pBindDescriptorSetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorSetsInfo); }
};


struct CmdPushConstants2
{
    using api_element = schema::vulkan::api_elements::CmdPushConstants2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfo> pPushConstantsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushConstantsInfo); }
};


struct CmdPushDescriptorSet2
{
    using api_element = schema::vulkan::api_elements::CmdPushDescriptorSet2;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo> pPushDescriptorSetInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushDescriptorSetInfo); }
};


struct CmdSetLineStipple
{
    using api_element = schema::vulkan::api_elements::CmdSetLineStipple;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct CmdBindIndexBuffer2
{
    using api_element = schema::vulkan::api_elements::CmdBindIndexBuffer2;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, size, indexType); }
};


struct GetRenderingAreaGranularity
{
    using api_element = schema::vulkan::api_elements::GetRenderingAreaGranularity;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfo> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, pRenderingAreaInfo, pGranularity); }
};


struct CmdSetRenderingAttachmentLocations
{
    using api_element = schema::vulkan::api_elements::CmdSetRenderingAttachmentLocations;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo> pLocationInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLocationInfo); }
};


struct CmdSetRenderingInputAttachmentIndices
{
    using api_element = schema::vulkan::api_elements::CmdSetRenderingInputAttachmentIndices;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo> pInputAttachmentIndexInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInputAttachmentIndexInfo); }
};


struct DestroySurfaceKHR
{
    using api_element = schema::vulkan::api_elements::DestroySurfaceKHR;

    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, surface, pAllocator); }
};


struct GetPhysicalDeviceSurfaceSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceSupportKHR;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    format::HandleId surface;
    PointerDecoder<VkBool32> pSupported;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, surface, pSupported); }
};


struct GetPhysicalDeviceSurfaceCapabilitiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceCapabilitiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceCapabilities); }
};


struct GetPhysicalDeviceSurfaceFormatsKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceFormatsKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats); }
};


struct GetPhysicalDeviceSurfacePresentModesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfacePresentModesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pPresentModeCount, pPresentModes); }
};


struct CreateSwapchainKHR
{
    using api_element = schema::vulkan::api_elements::CreateSwapchainKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchain;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSwapchain); }
};


struct DestroySwapchainKHR
{
    using api_element = schema::vulkan::api_elements::DestroySwapchainKHR;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, swapchain, pAllocator); }
};


struct GetSwapchainImagesKHR
{
    using api_element = schema::vulkan::api_elements::GetSwapchainImagesKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    HandlePointerDecoder<VkImage> pSwapchainImages;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainImageCount, pSwapchainImages); }
};


struct AcquireNextImageKHR
{
    using api_element = schema::vulkan::api_elements::AcquireNextImageKHR;

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
    using api_element = schema::vulkan::api_elements::QueuePresentKHR;

    VkResult result;
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;

    auto GetTuple() const { return std::tie(result, queue, pPresentInfo); }
};


struct GetDeviceGroupPresentCapabilitiesKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceGroupPresentCapabilitiesKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;

    auto GetTuple() const { return std::tie(result, device, pDeviceGroupPresentCapabilities); }
};


struct GetDeviceGroupSurfacePresentModesKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceGroupSurfacePresentModesKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;

    auto GetTuple() const { return std::tie(result, device, surface, pModes); }
};


struct GetPhysicalDevicePresentRectanglesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDevicePresentRectanglesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pRectCount, pRects); }
};


struct AcquireNextImage2KHR
{
    using api_element = schema::vulkan::api_elements::AcquireNextImage2KHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;

    auto GetTuple() const { return std::tie(result, device, pAcquireInfo, pImageIndex); }
};


struct GetPhysicalDeviceDisplayPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceDisplayPropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceDisplayPlanePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceDisplayPlanePropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetDisplayPlaneSupportedDisplaysKHR
{
    using api_element = schema::vulkan::api_elements::GetDisplayPlaneSupportedDisplaysKHR;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    HandlePointerDecoder<VkDisplayKHR> pDisplays;

    auto GetTuple() const { return std::tie(result, physicalDevice, planeIndex, pDisplayCount, pDisplays); }
};


struct GetDisplayModePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetDisplayModePropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, display, pPropertyCount, pProperties); }
};


struct CreateDisplayModeKHR
{
    using api_element = schema::vulkan::api_elements::CreateDisplayModeKHR;

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
    using api_element = schema::vulkan::api_elements::GetDisplayPlaneCapabilitiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, mode, planeIndex, pCapabilities); }
};


struct CreateDisplayPlaneSurfaceKHR
{
    using api_element = schema::vulkan::api_elements::CreateDisplayPlaneSurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateSharedSwapchainsKHR
{
    using api_element = schema::vulkan::api_elements::CreateSharedSwapchainsKHR;

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
    using api_element = schema::vulkan::api_elements::CreateXlibSurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceXlibPresentationSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceXlibPresentationSupportKHR;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dpy;
    size_t visualID;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, dpy, visualID); }
};


struct CreateXcbSurfaceKHR
{
    using api_element = schema::vulkan::api_elements::CreateXcbSurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceXcbPresentationSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceXcbPresentationSupportKHR;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    uint32_t visual_id;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, connection, visual_id); }
};


struct CreateWaylandSurfaceKHR
{
    using api_element = schema::vulkan::api_elements::CreateWaylandSurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceWaylandPresentationSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceWaylandPresentationSupportKHR;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, display); }
};


struct CreateAndroidSurfaceKHR
{
    using api_element = schema::vulkan::api_elements::CreateAndroidSurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateWin32SurfaceKHR
{
    using api_element = schema::vulkan::api_elements::CreateWin32SurfaceKHR;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceWin32PresentationSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceWin32PresentationSupportKHR;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex); }
};


struct GetPhysicalDeviceVideoCapabilitiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceVideoCapabilitiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR> pVideoProfile;
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pVideoProfile, pCapabilities); }
};


struct GetPhysicalDeviceVideoFormatPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceVideoFormatPropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR> pVideoFormatInfo;
    PointerDecoder<uint32_t> pVideoFormatPropertyCount;
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR> pVideoFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties); }
};


struct CreateVideoSessionKHR
{
    using api_element = schema::vulkan::api_elements::CreateVideoSessionKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionKHR> pVideoSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pVideoSession); }
};


struct DestroyVideoSessionKHR
{
    using api_element = schema::vulkan::api_elements::DestroyVideoSessionKHR;

    format::HandleId device;
    format::HandleId videoSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, videoSession, pAllocator); }
};


struct GetVideoSessionMemoryRequirementsKHR
{
    using api_element = schema::vulkan::api_elements::GetVideoSessionMemoryRequirementsKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId videoSession;
    PointerDecoder<uint32_t> pMemoryRequirementsCount;
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR> pMemoryRequirements;

    auto GetTuple() const { return std::tie(result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements); }
};


struct BindVideoSessionMemoryKHR
{
    using api_element = schema::vulkan::api_elements::BindVideoSessionMemoryKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId videoSession;
    uint32_t bindSessionMemoryInfoCount;
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR> pBindSessionMemoryInfos;

    auto GetTuple() const { return std::tie(result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos); }
};


struct CreateVideoSessionParametersKHR
{
    using api_element = schema::vulkan::api_elements::CreateVideoSessionParametersKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionParametersKHR> pVideoSessionParameters;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pVideoSessionParameters); }
};


struct UpdateVideoSessionParametersKHR
{
    using api_element = schema::vulkan::api_elements::UpdateVideoSessionParametersKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR> pUpdateInfo;

    auto GetTuple() const { return std::tie(result, device, videoSessionParameters, pUpdateInfo); }
};


struct DestroyVideoSessionParametersKHR
{
    using api_element = schema::vulkan::api_elements::DestroyVideoSessionParametersKHR;

    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, videoSessionParameters, pAllocator); }
};


struct CmdBeginVideoCodingKHR
{
    using api_element = schema::vulkan::api_elements::CmdBeginVideoCodingKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR> pBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBeginInfo); }
};


struct CmdEndVideoCodingKHR
{
    using api_element = schema::vulkan::api_elements::CmdEndVideoCodingKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR> pEndCodingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pEndCodingInfo); }
};


struct CmdControlVideoCodingKHR
{
    using api_element = schema::vulkan::api_elements::CmdControlVideoCodingKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR> pCodingControlInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCodingControlInfo); }
};


struct CmdDecodeVideoKHR
{
    using api_element = schema::vulkan::api_elements::CmdDecodeVideoKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR> pDecodeInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDecodeInfo); }
};


struct CmdBeginRenderingKHR
{
    using api_element = schema::vulkan::api_elements::CmdBeginRenderingKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingInfo); }
};


struct CmdEndRenderingKHR
{
    using api_element = schema::vulkan::api_elements::CmdEndRenderingKHR;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct GetPhysicalDeviceFeatures2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFeatures2KHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    auto GetTuple() const { return std::tie(physicalDevice, pFeatures); }
};


struct GetPhysicalDeviceProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceProperties2KHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pProperties); }
};


struct GetPhysicalDeviceFormatProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFormatProperties2KHR;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    auto GetTuple() const { return std::tie(physicalDevice, format, pFormatProperties); }
};


struct GetPhysicalDeviceImageFormatProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceImageFormatProperties2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pImageFormatInfo, pImageFormatProperties); }
};


struct GetPhysicalDeviceQueueFamilyProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyProperties2KHR;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties); }
};


struct GetPhysicalDeviceMemoryProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceMemoryProperties2KHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pMemoryProperties); }
};


struct GetPhysicalDeviceSparseImageFormatProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSparseImageFormatProperties2KHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pFormatInfo, pPropertyCount, pProperties); }
};


struct GetDeviceGroupPeerMemoryFeaturesKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceGroupPeerMemoryFeaturesKHR;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    auto GetTuple() const { return std::tie(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures); }
};


struct CmdSetDeviceMaskKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetDeviceMaskKHR;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    auto GetTuple() const { return std::tie(commandBuffer, deviceMask); }
};


struct CmdDispatchBaseKHR
{
    using api_element = schema::vulkan::api_elements::CmdDispatchBaseKHR;

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
    using api_element = schema::vulkan::api_elements::TrimCommandPoolKHR;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    auto GetTuple() const { return std::tie(device, commandPool, flags); }
};


struct EnumeratePhysicalDeviceGroupsKHR
{
    using api_element = schema::vulkan::api_elements::EnumeratePhysicalDeviceGroupsKHR;

    VkResult result;
    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;

    auto GetTuple() const { return std::tie(result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties); }
};


struct GetPhysicalDeviceExternalBufferPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalBufferPropertiesKHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalBufferInfo, pExternalBufferProperties); }
};


struct GetMemoryWin32HandleKHR
{
    using api_element = schema::vulkan::api_elements::GetMemoryWin32HandleKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct GetMemoryWin32HandlePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetMemoryWin32HandlePropertiesKHR;

    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, handle, pMemoryWin32HandleProperties); }
};


struct GetMemoryFdKHR
{
    using api_element = schema::vulkan::api_elements::GetMemoryFdKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct GetMemoryFdPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetMemoryFdPropertiesKHR;

    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, fd, pMemoryFdProperties); }
};


struct GetPhysicalDeviceExternalSemaphorePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalSemaphorePropertiesKHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties); }
};


struct ImportSemaphoreWin32HandleKHR
{
    using api_element = schema::vulkan::api_elements::ImportSemaphoreWin32HandleKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreWin32HandleInfo); }
};


struct GetSemaphoreWin32HandleKHR
{
    using api_element = schema::vulkan::api_elements::GetSemaphoreWin32HandleKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct ImportSemaphoreFdKHR
{
    using api_element = schema::vulkan::api_elements::ImportSemaphoreFdKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreFdInfo); }
};


struct GetSemaphoreFdKHR
{
    using api_element = schema::vulkan::api_elements::GetSemaphoreFdKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct CmdPushDescriptorSetKHR
{
    using api_element = schema::vulkan::api_elements::CmdPushDescriptorSetKHR;

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
    using api_element = schema::vulkan::api_elements::CreateDescriptorUpdateTemplateKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate); }
};


struct DestroyDescriptorUpdateTemplateKHR
{
    using api_element = schema::vulkan::api_elements::DestroyDescriptorUpdateTemplateKHR;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, descriptorUpdateTemplate, pAllocator); }
};


struct CreateRenderPass2KHR
{
    using api_element = schema::vulkan::api_elements::CreateRenderPass2KHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pRenderPass); }
};


struct CmdBeginRenderPass2KHR
{
    using api_element = schema::vulkan::api_elements::CmdBeginRenderPass2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderPassBegin, pSubpassBeginInfo); }
};


struct CmdNextSubpass2KHR
{
    using api_element = schema::vulkan::api_elements::CmdNextSubpass2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo); }
};


struct CmdEndRenderPass2KHR
{
    using api_element = schema::vulkan::api_elements::CmdEndRenderPass2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSubpassEndInfo); }
};


struct GetSwapchainStatusKHR
{
    using api_element = schema::vulkan::api_elements::GetSwapchainStatusKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct GetPhysicalDeviceExternalFencePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalFencePropertiesKHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalFenceInfo, pExternalFenceProperties); }
};


struct ImportFenceWin32HandleKHR
{
    using api_element = schema::vulkan::api_elements::ImportFenceWin32HandleKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportFenceWin32HandleInfo); }
};


struct GetFenceWin32HandleKHR
{
    using api_element = schema::vulkan::api_elements::GetFenceWin32HandleKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetWin32HandleInfo, pHandle); }
};


struct ImportFenceFdKHR
{
    using api_element = schema::vulkan::api_elements::ImportFenceFdKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;

    auto GetTuple() const { return std::tie(result, device, pImportFenceFdInfo); }
};


struct GetFenceFdKHR
{
    using api_element = schema::vulkan::api_elements::GetFenceFdKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;

    auto GetTuple() const { return std::tie(result, device, pGetFdInfo, pFd); }
};


struct EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR
{
    using api_element = schema::vulkan::api_elements::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;

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
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR> pPerformanceQueryCreateInfo;
    PointerDecoder<uint32_t> pNumPasses;

    auto GetTuple() const { return std::tie(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses); }
};


struct AcquireProfilingLockKHR
{
    using api_element = schema::vulkan::api_elements::AcquireProfilingLockKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct ReleaseProfilingLockKHR
{
    using api_element = schema::vulkan::api_elements::ReleaseProfilingLockKHR;

    format::HandleId device;

    auto GetTuple() const { return std::tie(device); }
};


struct GetPhysicalDeviceSurfaceCapabilities2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceCapabilities2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities); }
};


struct GetPhysicalDeviceSurfaceFormats2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceFormats2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats); }
};


struct GetPhysicalDeviceDisplayProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceDisplayProperties2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceDisplayPlaneProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceDisplayPlaneProperties2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetDisplayModeProperties2KHR
{
    using api_element = schema::vulkan::api_elements::GetDisplayModeProperties2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, display, pPropertyCount, pProperties); }
};


struct GetDisplayPlaneCapabilities2KHR
{
    using api_element = schema::vulkan::api_elements::GetDisplayPlaneCapabilities2KHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, pDisplayPlaneInfo, pCapabilities); }
};


struct GetImageMemoryRequirements2KHR
{
    using api_element = schema::vulkan::api_elements::GetImageMemoryRequirements2KHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetBufferMemoryRequirements2KHR
{
    using api_element = schema::vulkan::api_elements::GetBufferMemoryRequirements2KHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetImageSparseMemoryRequirements2KHR
{
    using api_element = schema::vulkan::api_elements::GetImageSparseMemoryRequirements2KHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CreateSamplerYcbcrConversionKHR
{
    using api_element = schema::vulkan::api_elements::CreateSamplerYcbcrConversionKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pYcbcrConversion); }
};


struct DestroySamplerYcbcrConversionKHR
{
    using api_element = schema::vulkan::api_elements::DestroySamplerYcbcrConversionKHR;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, ycbcrConversion, pAllocator); }
};


struct BindBufferMemory2KHR
{
    using api_element = schema::vulkan::api_elements::BindBufferMemory2KHR;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct BindImageMemory2KHR
{
    using api_element = schema::vulkan::api_elements::BindImageMemory2KHR;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct GetDescriptorSetLayoutSupportKHR
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetLayoutSupportKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pSupport); }
};


struct CmdDrawIndirectCountKHR
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectCountKHR;

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
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirectCountKHR;

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
    using api_element = schema::vulkan::api_elements::GetSemaphoreCounterValueKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;

    auto GetTuple() const { return std::tie(result, device, semaphore, pValue); }
};


struct WaitSemaphoresKHR
{
    using api_element = schema::vulkan::api_elements::WaitSemaphoresKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, pWaitInfo, timeout); }
};


struct SignalSemaphoreKHR
{
    using api_element = schema::vulkan::api_elements::SignalSemaphoreKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;

    auto GetTuple() const { return std::tie(result, device, pSignalInfo); }
};


struct GetPhysicalDeviceFragmentShadingRatesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceFragmentShadingRatesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pFragmentShadingRateCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR> pFragmentShadingRates;

    auto GetTuple() const { return std::tie(result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates); }
};


struct CmdSetFragmentShadingRateKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetFragmentShadingRateKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkExtent2D> pFragmentSize;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    auto GetTuple() const { return std::tie(commandBuffer, pFragmentSize, combinerOps); }
};


struct CmdSetRenderingAttachmentLocationsKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetRenderingAttachmentLocationsKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo> pLocationInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLocationInfo); }
};


struct CmdSetRenderingInputAttachmentIndicesKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetRenderingInputAttachmentIndicesKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo> pInputAttachmentIndexInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInputAttachmentIndexInfo); }
};


struct WaitForPresentKHR
{
    using api_element = schema::vulkan::api_elements::WaitForPresentKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    uint64_t presentId;
    uint64_t timeout;

    auto GetTuple() const { return std::tie(result, device, swapchain, presentId, timeout); }
};


struct GetBufferDeviceAddressKHR
{
    using api_element = schema::vulkan::api_elements::GetBufferDeviceAddressKHR;

    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetBufferOpaqueCaptureAddressKHR
{
    using api_element = schema::vulkan::api_elements::GetBufferOpaqueCaptureAddressKHR;

    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetDeviceMemoryOpaqueCaptureAddressKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceMemoryOpaqueCaptureAddressKHR;

    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CreateDeferredOperationKHR
{
    using api_element = schema::vulkan::api_elements::CreateDeferredOperationKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeferredOperationKHR> pDeferredOperation;

    auto GetTuple() const { return std::tie(result, device, pAllocator, pDeferredOperation); }
};


struct DestroyDeferredOperationKHR
{
    using api_element = schema::vulkan::api_elements::DestroyDeferredOperationKHR;

    format::HandleId device;
    format::HandleId operation;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, operation, pAllocator); }
};


struct GetDeferredOperationMaxConcurrencyKHR
{
    using api_element = schema::vulkan::api_elements::GetDeferredOperationMaxConcurrencyKHR;

    uint32_t result;
    format::HandleId device;
    format::HandleId operation;

    auto GetTuple() const { return std::tie(result, device, operation); }
};


struct GetDeferredOperationResultKHR
{
    using api_element = schema::vulkan::api_elements::GetDeferredOperationResultKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId operation;

    auto GetTuple() const { return std::tie(result, device, operation); }
};


struct GetPipelineExecutablePropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPipelineExecutablePropertiesKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineInfoKHR> pPipelineInfo;
    PointerDecoder<uint32_t> pExecutableCount;
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, pExecutableCount, pProperties); }
};


struct GetPipelineExecutableStatisticsKHR
{
    using api_element = schema::vulkan::api_elements::GetPipelineExecutableStatisticsKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pStatisticCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR> pStatistics;

    auto GetTuple() const { return std::tie(result, device, pExecutableInfo, pStatisticCount, pStatistics); }
};


struct GetPipelineExecutableInternalRepresentationsKHR
{
    using api_element = schema::vulkan::api_elements::GetPipelineExecutableInternalRepresentationsKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pInternalRepresentationCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR> pInternalRepresentations;

    auto GetTuple() const { return std::tie(result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations); }
};


struct MapMemory2KHR
{
    using api_element = schema::vulkan::api_elements::MapMemory2KHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfo> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(result, device, pMemoryMapInfo, ppData); }
};


struct UnmapMemory2KHR
{
    using api_element = schema::vulkan::api_elements::UnmapMemory2KHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo> pMemoryUnmapInfo;

    auto GetTuple() const { return std::tie(result, device, pMemoryUnmapInfo); }
};


struct GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR> pQualityLevelInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR> pQualityLevelProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pQualityLevelInfo, pQualityLevelProperties); }
};


struct GetEncodedVideoSessionParametersKHR
{
    using api_element = schema::vulkan::api_elements::GetEncodedVideoSessionParametersKHR;

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
    using api_element = schema::vulkan::api_elements::CmdEncodeVideoKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR> pEncodeInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pEncodeInfo); }
};


struct CmdSetEvent2KHR
{
    using api_element = schema::vulkan::api_elements::CmdSetEvent2KHR;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, event, pDependencyInfo); }
};


struct CmdResetEvent2KHR
{
    using api_element = schema::vulkan::api_elements::CmdResetEvent2KHR;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    auto GetTuple() const { return std::tie(commandBuffer, event, stageMask); }
};


struct CmdWaitEvents2KHR
{
    using api_element = schema::vulkan::api_elements::CmdWaitEvents2KHR;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    auto GetTuple() const { return std::tie(commandBuffer, eventCount, pEvents, pDependencyInfos); }
};


struct CmdPipelineBarrier2KHR
{
    using api_element = schema::vulkan::api_elements::CmdPipelineBarrier2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDependencyInfo); }
};


struct CmdWriteTimestamp2KHR
{
    using api_element = schema::vulkan::api_elements::CmdWriteTimestamp2KHR;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    auto GetTuple() const { return std::tie(commandBuffer, stage, queryPool, query); }
};


struct QueueSubmit2KHR
{
    using api_element = schema::vulkan::api_elements::QueueSubmit2KHR;

    VkResult result;
    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;

    auto GetTuple() const { return std::tie(result, queue, submitCount, pSubmits, fence); }
};


struct CmdBindIndexBuffer3KHR
{
    using api_element = schema::vulkan::api_elements::CmdBindIndexBuffer3KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindIndexBuffer3InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdBindVertexBuffers3KHR
{
    using api_element = schema::vulkan::api_elements::CmdBindVertexBuffers3KHR;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    StructPointerDecoder<Decoded_VkBindVertexBuffer3InfoKHR> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBindingInfos); }
};


struct CmdDrawIndirect2KHR
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirect2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawIndexedIndirect2KHR
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirect2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDispatchIndirect2KHR
{
    using api_element = schema::vulkan::api_elements::CmdDispatchIndirect2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdCopyMemoryToImageKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryToImageKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdCopyImageToMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyImageToMemoryKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR> pCopyMemoryInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryInfo); }
};


struct CmdUpdateMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdUpdateMemoryKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR> pDstRange;
    VkAddressCommandFlagsKHR dstFlags;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(commandBuffer, pDstRange, dstFlags, dataSize, pData); }
};


struct CmdFillMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdFillMemoryKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR> pDstRange;
    VkAddressCommandFlagsKHR dstFlags;
    uint32_t data;

    auto GetTuple() const { return std::tie(commandBuffer, pDstRange, dstFlags, data); }
};


struct CmdCopyQueryPoolResultsToMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyQueryPoolResultsToMemoryKHR;

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
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectCount2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawIndexedIndirectCount2KHR
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirectCount2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdBeginConditionalRendering2EXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginConditionalRendering2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfo2EXT> pConditionalRenderingBegin;

    auto GetTuple() const { return std::tie(commandBuffer, pConditionalRenderingBegin); }
};


struct CmdBindTransformFeedbackBuffers2EXT
{
    using api_element = schema::vulkan::api_elements::CmdBindTransformFeedbackBuffers2EXT;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstBinding, bindingCount, pBindingInfos); }
};


struct CmdBeginTransformFeedback2EXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginTransformFeedback2EXT;

    format::HandleId commandBuffer;
    uint32_t firstCounterRange;
    uint32_t counterRangeCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pCounterInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos); }
};


struct CmdEndTransformFeedback2EXT
{
    using api_element = schema::vulkan::api_elements::CmdEndTransformFeedback2EXT;

    format::HandleId commandBuffer;
    uint32_t firstCounterRange;
    uint32_t counterRangeCount;
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT> pCounterInfos;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos); }
};


struct CmdDrawIndirectByteCount2EXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectByteCount2EXT;

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
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirect2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdDrawMeshTasksIndirectCount2EXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirectCount2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdWriteMarkerToMemoryAMD
{
    using api_element = schema::vulkan::api_elements::CmdWriteMarkerToMemoryAMD;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkMemoryMarkerInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CreateAccelerationStructure2KHR
{
    using api_element = schema::vulkan::api_elements::CreateAccelerationStructure2KHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfo2KHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct CmdCopyBuffer2KHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyBuffer2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferInfo); }
};


struct CmdCopyImage2KHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyImage2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageInfo); }
};


struct CmdCopyBufferToImage2KHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyBufferToImage2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyBufferToImageInfo); }
};


struct CmdCopyImageToBuffer2KHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyImageToBuffer2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyImageToBufferInfo); }
};


struct CmdBlitImage2KHR
{
    using api_element = schema::vulkan::api_elements::CmdBlitImage2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBlitImageInfo); }
};


struct CmdResolveImage2KHR
{
    using api_element = schema::vulkan::api_elements::CmdResolveImage2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pResolveImageInfo); }
};


struct CmdTraceRaysIndirect2KHR
{
    using api_element = schema::vulkan::api_elements::CmdTraceRaysIndirect2KHR;

    format::HandleId commandBuffer;
    VkDeviceAddress indirectDeviceAddress;

    auto GetTuple() const { return std::tie(commandBuffer, indirectDeviceAddress); }
};


struct GetDeviceBufferMemoryRequirementsKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceBufferMemoryRequirementsKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageMemoryRequirementsKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageMemoryRequirementsKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct GetDeviceImageSparseMemoryRequirementsKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageSparseMemoryRequirementsKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements); }
};


struct CmdBindIndexBuffer2KHR
{
    using api_element = schema::vulkan::api_elements::CmdBindIndexBuffer2KHR;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, size, indexType); }
};


struct GetRenderingAreaGranularityKHR
{
    using api_element = schema::vulkan::api_elements::GetRenderingAreaGranularityKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfo> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    auto GetTuple() const { return std::tie(device, pRenderingAreaInfo, pGranularity); }
};


struct GetDeviceImageSubresourceLayoutKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceImageSubresourceLayoutKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, pInfo, pLayout); }
};


struct GetImageSubresourceLayout2KHR
{
    using api_element = schema::vulkan::api_elements::GetImageSubresourceLayout2KHR;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct WaitForPresent2KHR
{
    using api_element = schema::vulkan::api_elements::WaitForPresent2KHR;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkPresentWait2InfoKHR> pPresentWait2Info;

    auto GetTuple() const { return std::tie(result, device, swapchain, pPresentWait2Info); }
};


struct CreatePipelineBinariesKHR
{
    using api_element = schema::vulkan::api_elements::CreatePipelineBinariesKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineBinaryCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    StructPointerDecoder<Decoded_VkPipelineBinaryHandlesInfoKHR> pBinaries;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pBinaries); }
};


struct DestroyPipelineBinaryKHR
{
    using api_element = schema::vulkan::api_elements::DestroyPipelineBinaryKHR;

    format::HandleId device;
    format::HandleId pipelineBinary;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, pipelineBinary, pAllocator); }
};


struct GetPipelineKeyKHR
{
    using api_element = schema::vulkan::api_elements::GetPipelineKeyKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCreateInfoKHR> pPipelineCreateInfo;
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR> pPipelineKey;

    auto GetTuple() const { return std::tie(result, device, pPipelineCreateInfo, pPipelineKey); }
};


struct GetPipelineBinaryDataKHR
{
    using api_element = schema::vulkan::api_elements::GetPipelineBinaryDataKHR;

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
    using api_element = schema::vulkan::api_elements::ReleaseCapturedPipelineDataKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseCapturedPipelineDataInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(result, device, pInfo, pAllocator); }
};


struct ReleaseSwapchainImagesKHR
{
    using api_element = schema::vulkan::api_elements::ReleaseSwapchainImagesKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR> pReleaseInfo;

    auto GetTuple() const { return std::tie(result, device, pReleaseInfo); }
};


struct GetPhysicalDeviceCooperativeMatrixPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCooperativeMatrixPropertiesKHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct CmdSetLineStippleKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetLineStippleKHR;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct GetPhysicalDeviceCalibrateableTimeDomainsKHR
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCalibrateableTimeDomainsKHR;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;

    auto GetTuple() const { return std::tie(result, physicalDevice, pTimeDomainCount, pTimeDomains); }
};


struct GetCalibratedTimestampsKHR
{
    using api_element = schema::vulkan::api_elements::GetCalibratedTimestampsKHR;

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
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorSets2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo> pBindDescriptorSetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorSetsInfo); }
};


struct CmdPushConstants2KHR
{
    using api_element = schema::vulkan::api_elements::CmdPushConstants2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfo> pPushConstantsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushConstantsInfo); }
};


struct CmdPushDescriptorSet2KHR
{
    using api_element = schema::vulkan::api_elements::CmdPushDescriptorSet2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo> pPushDescriptorSetInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPushDescriptorSetInfo); }
};


struct CmdSetDescriptorBufferOffsets2EXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDescriptorBufferOffsets2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT> pSetDescriptorBufferOffsetsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSetDescriptorBufferOffsetsInfo); }
};


struct CmdBindDescriptorBufferEmbeddedSamplers2EXT
{
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorBufferEmbeddedSamplers2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT> pBindDescriptorBufferEmbeddedSamplersInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo); }
};


struct CmdCopyMemoryIndirectKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryIndirectKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR> pCopyMemoryIndirectInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryIndirectInfo); }
};


struct CmdCopyMemoryToImageIndirectKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryToImageIndirectKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR> pCopyMemoryToImageIndirectInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyMemoryToImageIndirectInfo); }
};


struct GetDeviceFaultReportsKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceFaultReportsKHR;

    VkResult result;
    format::HandleId device;
    uint64_t timeout;
    PointerDecoder<uint32_t> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoKHR> pFaultInfo;

    auto GetTuple() const { return std::tie(result, device, timeout, pFaultCounts, pFaultInfo); }
};


struct GetDeviceFaultDebugInfoKHR
{
    using api_element = schema::vulkan::api_elements::GetDeviceFaultDebugInfoKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultDebugInfoKHR> pDebugInfo;

    auto GetTuple() const { return std::tie(result, device, pDebugInfo); }
};


struct CmdEndRendering2KHR
{
    using api_element = schema::vulkan::api_elements::CmdEndRendering2KHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR> pRenderingEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingEndInfo); }
};


struct FrameBoundaryANDROID
{
    using api_element = schema::vulkan::api_elements::FrameBoundaryANDROID;

    format::HandleId device;
    format::HandleId semaphore;
    format::HandleId image;

    auto GetTuple() const { return std::tie(device, semaphore, image); }
};


struct CreateDebugReportCallbackEXT
{
    using api_element = schema::vulkan::api_elements::CreateDebugReportCallbackEXT;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugReportCallbackEXT> pCallback;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pCallback); }
};


struct DestroyDebugReportCallbackEXT
{
    using api_element = schema::vulkan::api_elements::DestroyDebugReportCallbackEXT;

    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, callback, pAllocator); }
};


struct DebugReportMessageEXT
{
    using api_element = schema::vulkan::api_elements::DebugReportMessageEXT;

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
    using api_element = schema::vulkan::api_elements::DebugMarkerSetObjectTagEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;

    auto GetTuple() const { return std::tie(result, device, pTagInfo); }
};


struct DebugMarkerSetObjectNameEXT
{
    using api_element = schema::vulkan::api_elements::DebugMarkerSetObjectNameEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;

    auto GetTuple() const { return std::tie(result, device, pNameInfo); }
};


struct CmdDebugMarkerBeginEXT
{
    using api_element = schema::vulkan::api_elements::CmdDebugMarkerBeginEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pMarkerInfo); }
};


struct CmdDebugMarkerEndEXT
{
    using api_element = schema::vulkan::api_elements::CmdDebugMarkerEndEXT;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdDebugMarkerInsertEXT
{
    using api_element = schema::vulkan::api_elements::CmdDebugMarkerInsertEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pMarkerInfo); }
};


struct CmdBindTransformFeedbackBuffersEXT
{
    using api_element = schema::vulkan::api_elements::CmdBindTransformFeedbackBuffersEXT;

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
    using api_element = schema::vulkan::api_elements::CmdBeginTransformFeedbackEXT;

    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }
};


struct CmdEndTransformFeedbackEXT
{
    using api_element = schema::vulkan::api_elements::CmdEndTransformFeedbackEXT;

    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    auto GetTuple() const { return std::tie(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets); }
};


struct CmdBeginQueryIndexedEXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginQueryIndexedEXT;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
    uint32_t index;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, flags, index); }
};


struct CmdEndQueryIndexedEXT
{
    using api_element = schema::vulkan::api_elements::CmdEndQueryIndexedEXT;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    uint32_t index;

    auto GetTuple() const { return std::tie(commandBuffer, queryPool, query, index); }
};


struct CmdDrawIndirectByteCountEXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectByteCountEXT;

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
    using api_element = schema::vulkan::api_elements::GetImageViewHandleNVX;

    uint32_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetImageViewHandle64NVX
{
    using api_element = schema::vulkan::api_elements::GetImageViewHandle64NVX;

    uint64_t result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetImageViewAddressNVX
{
    using api_element = schema::vulkan::api_elements::GetImageViewAddressNVX;

    VkResult result;
    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX> pProperties;

    auto GetTuple() const { return std::tie(result, device, imageView, pProperties); }
};


struct GetDeviceCombinedImageSamplerIndexNVX
{
    using api_element = schema::vulkan::api_elements::GetDeviceCombinedImageSamplerIndexNVX;

    uint64_t result;
    format::HandleId device;
    uint64_t imageViewIndex;
    uint64_t samplerIndex;

    auto GetTuple() const { return std::tie(result, device, imageViewIndex, samplerIndex); }
};


struct CmdDrawIndirectCountAMD
{
    using api_element = schema::vulkan::api_elements::CmdDrawIndirectCountAMD;

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
    using api_element = schema::vulkan::api_elements::CmdDrawIndexedIndirectCountAMD;

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
    using api_element = schema::vulkan::api_elements::GetShaderInfoAMD;

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
    using api_element = schema::vulkan::api_elements::CreateStreamDescriptorSurfaceGGP;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceExternalImageFormatPropertiesNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalImageFormatPropertiesNV;

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
    using api_element = schema::vulkan::api_elements::GetMemoryWin32HandleNV;

    VkResult result;
    format::HandleId device;
    format::HandleId memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, memory, handleType, pHandle); }
};


struct CreateViSurfaceNN
{
    using api_element = schema::vulkan::api_elements::CreateViSurfaceNN;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CmdBeginConditionalRenderingEXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginConditionalRenderingEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    auto GetTuple() const { return std::tie(commandBuffer, pConditionalRenderingBegin); }
};


struct CmdEndConditionalRenderingEXT
{
    using api_element = schema::vulkan::api_elements::CmdEndConditionalRenderingEXT;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdSetViewportWScalingNV
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportWScalingNV;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewportWScalings); }
};


struct ReleaseDisplayEXT
{
    using api_element = schema::vulkan::api_elements::ReleaseDisplayEXT;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, display); }
};


struct AcquireXlibDisplayEXT
{
    using api_element = schema::vulkan::api_elements::AcquireXlibDisplayEXT;

    VkResult result;
    format::HandleId physicalDevice;
    uint64_t dpy;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, dpy, display); }
};


struct GetRandROutputDisplayEXT
{
    using api_element = schema::vulkan::api_elements::GetRandROutputDisplayEXT;

    VkResult result;
    format::HandleId physicalDevice;
    uint64_t dpy;
    size_t rrOutput;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;

    auto GetTuple() const { return std::tie(result, physicalDevice, dpy, rrOutput, pDisplay); }
};


struct GetPhysicalDeviceSurfaceCapabilities2EXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfaceCapabilities2EXT;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;

    auto GetTuple() const { return std::tie(result, physicalDevice, surface, pSurfaceCapabilities); }
};


struct DisplayPowerControlEXT
{
    using api_element = schema::vulkan::api_elements::DisplayPowerControlEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;

    auto GetTuple() const { return std::tie(result, device, display, pDisplayPowerInfo); }
};


struct RegisterDeviceEventEXT
{
    using api_element = schema::vulkan::api_elements::RegisterDeviceEventEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;

    auto GetTuple() const { return std::tie(result, device, pDeviceEventInfo, pAllocator, pFence); }
};


struct RegisterDisplayEventEXT
{
    using api_element = schema::vulkan::api_elements::RegisterDisplayEventEXT;

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
    using api_element = schema::vulkan::api_elements::GetSwapchainCounterEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;

    auto GetTuple() const { return std::tie(result, device, swapchain, counter, pCounterValue); }
};


struct GetRefreshCycleDurationGOOGLE
{
    using api_element = schema::vulkan::api_elements::GetRefreshCycleDurationGOOGLE;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;

    auto GetTuple() const { return std::tie(result, device, swapchain, pDisplayTimingProperties); }
};


struct GetPastPresentationTimingGOOGLE
{
    using api_element = schema::vulkan::api_elements::GetPastPresentationTimingGOOGLE;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;

    auto GetTuple() const { return std::tie(result, device, swapchain, pPresentationTimingCount, pPresentationTimings); }
};


struct CmdSetDiscardRectangleEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDiscardRectangleEXT;

    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    auto GetTuple() const { return std::tie(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles); }
};


struct CmdSetDiscardRectangleEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDiscardRectangleEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 discardRectangleEnable;

    auto GetTuple() const { return std::tie(commandBuffer, discardRectangleEnable); }
};


struct CmdSetDiscardRectangleModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDiscardRectangleModeEXT;

    format::HandleId commandBuffer;
    VkDiscardRectangleModeEXT discardRectangleMode;

    auto GetTuple() const { return std::tie(commandBuffer, discardRectangleMode); }
};


struct SetHdrMetadataEXT
{
    using api_element = schema::vulkan::api_elements::SetHdrMetadataEXT;

    format::HandleId device;
    uint32_t swapchainCount;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    auto GetTuple() const { return std::tie(device, swapchainCount, pSwapchains, pMetadata); }
};


struct CreateIOSSurfaceMVK
{
    using api_element = schema::vulkan::api_elements::CreateIOSSurfaceMVK;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateMacOSSurfaceMVK
{
    using api_element = schema::vulkan::api_elements::CreateMacOSSurfaceMVK;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct SetDebugUtilsObjectNameEXT
{
    using api_element = schema::vulkan::api_elements::SetDebugUtilsObjectNameEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;

    auto GetTuple() const { return std::tie(result, device, pNameInfo); }
};


struct SetDebugUtilsObjectTagEXT
{
    using api_element = schema::vulkan::api_elements::SetDebugUtilsObjectTagEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;

    auto GetTuple() const { return std::tie(result, device, pTagInfo); }
};


struct QueueBeginDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::QueueBeginDebugUtilsLabelEXT;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(queue, pLabelInfo); }
};


struct QueueEndDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::QueueEndDebugUtilsLabelEXT;

    format::HandleId queue;

    auto GetTuple() const { return std::tie(queue); }
};


struct QueueInsertDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::QueueInsertDebugUtilsLabelEXT;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(queue, pLabelInfo); }
};


struct CmdBeginDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginDebugUtilsLabelEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLabelInfo); }
};


struct CmdEndDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::CmdEndDebugUtilsLabelEXT;

    format::HandleId commandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer); }
};


struct CmdInsertDebugUtilsLabelEXT
{
    using api_element = schema::vulkan::api_elements::CmdInsertDebugUtilsLabelEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pLabelInfo); }
};


struct CreateDebugUtilsMessengerEXT
{
    using api_element = schema::vulkan::api_elements::CreateDebugUtilsMessengerEXT;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pMessenger); }
};


struct DestroyDebugUtilsMessengerEXT
{
    using api_element = schema::vulkan::api_elements::DestroyDebugUtilsMessengerEXT;

    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(instance, messenger, pAllocator); }
};


struct SubmitDebugUtilsMessageEXT
{
    using api_element = schema::vulkan::api_elements::SubmitDebugUtilsMessageEXT;

    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    auto GetTuple() const { return std::tie(instance, messageSeverity, messageTypes, pCallbackData); }
};


struct GetAndroidHardwareBufferPropertiesANDROID
{
    using api_element = schema::vulkan::api_elements::GetAndroidHardwareBufferPropertiesANDROID;

    VkResult result;
    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;

    auto GetTuple() const { return std::tie(result, device, buffer, pProperties); }
};


struct GetMemoryAndroidHardwareBufferANDROID
{
    using api_element = schema::vulkan::api_elements::GetMemoryAndroidHardwareBufferANDROID;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t, void*> pBuffer;

    auto GetTuple() const { return std::tie(result, device, pInfo, pBuffer); }
};


struct CreateGpaSessionAMD
{
    using api_element = schema::vulkan::api_elements::CreateGpaSessionAMD;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaSessionCreateInfoAMD> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkGpaSessionAMD> pGpaSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pGpaSession); }
};


struct DestroyGpaSessionAMD
{
    using api_element = schema::vulkan::api_elements::DestroyGpaSessionAMD;

    format::HandleId device;
    format::HandleId gpaSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, gpaSession, pAllocator); }
};


struct SetGpaDeviceClockModeAMD
{
    using api_element = schema::vulkan::api_elements::SetGpaDeviceClockModeAMD;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaDeviceClockModeInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetGpaDeviceClockInfoAMD
{
    using api_element = schema::vulkan::api_elements::GetGpaDeviceClockInfoAMD;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkGpaDeviceGetClockInfoAMD> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdBeginGpaSessionAMD
{
    using api_element = schema::vulkan::api_elements::CmdBeginGpaSessionAMD;

    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession); }
};


struct CmdEndGpaSessionAMD
{
    using api_element = schema::vulkan::api_elements::CmdEndGpaSessionAMD;

    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession); }
};


struct CmdBeginGpaSampleAMD
{
    using api_element = schema::vulkan::api_elements::CmdBeginGpaSampleAMD;

    VkResult result;
    format::HandleId commandBuffer;
    format::HandleId gpaSession;
    StructPointerDecoder<Decoded_VkGpaSampleBeginInfoAMD> pGpaSampleBeginInfo;
    PointerDecoder<uint32_t> pSampleID;

    auto GetTuple() const { return std::tie(result, commandBuffer, gpaSession, pGpaSampleBeginInfo, pSampleID); }
};


struct CmdEndGpaSampleAMD
{
    using api_element = schema::vulkan::api_elements::CmdEndGpaSampleAMD;

    format::HandleId commandBuffer;
    format::HandleId gpaSession;
    uint32_t sampleID;

    auto GetTuple() const { return std::tie(commandBuffer, gpaSession, sampleID); }
};


struct GetGpaSessionStatusAMD
{
    using api_element = schema::vulkan::api_elements::GetGpaSessionStatusAMD;

    VkResult result;
    format::HandleId device;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, device, gpaSession); }
};


struct GetGpaSessionResultsAMD
{
    using api_element = schema::vulkan::api_elements::GetGpaSessionResultsAMD;

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
    using api_element = schema::vulkan::api_elements::ResetGpaSessionAMD;

    VkResult result;
    format::HandleId device;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(result, device, gpaSession); }
};


struct CmdCopyGpaSessionResultsAMD
{
    using api_element = schema::vulkan::api_elements::CmdCopyGpaSessionResultsAMD;

    format::HandleId commandBuffer;
    format::HandleId gpaSession;

    auto GetTuple() const { return std::tie(commandBuffer, gpaSession); }
};


struct CmdSetSampleLocationsEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetSampleLocationsEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pSampleLocationsInfo); }
};


struct GetPhysicalDeviceMultisamplePropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceMultisamplePropertiesEXT;

    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    auto GetTuple() const { return std::tie(physicalDevice, samples, pMultisampleProperties); }
};


struct GetImageDrmFormatModifierPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetImageDrmFormatModifierPropertiesEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT> pProperties;

    auto GetTuple() const { return std::tie(result, device, image, pProperties); }
};


struct CreateValidationCacheEXT
{
    using api_element = schema::vulkan::api_elements::CreateValidationCacheEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkValidationCacheEXT> pValidationCache;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pValidationCache); }
};


struct DestroyValidationCacheEXT
{
    using api_element = schema::vulkan::api_elements::DestroyValidationCacheEXT;

    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, validationCache, pAllocator); }
};


struct MergeValidationCachesEXT
{
    using api_element = schema::vulkan::api_elements::MergeValidationCachesEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkValidationCacheEXT> pSrcCaches;

    auto GetTuple() const { return std::tie(result, device, dstCache, srcCacheCount, pSrcCaches); }
};


struct GetValidationCacheDataEXT
{
    using api_element = schema::vulkan::api_elements::GetValidationCacheDataEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, validationCache, pDataSize, pData); }
};


struct CmdBindShadingRateImageNV
{
    using api_element = schema::vulkan::api_elements::CmdBindShadingRateImageNV;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    auto GetTuple() const { return std::tie(commandBuffer, imageView, imageLayout); }
};


struct CmdSetViewportShadingRatePaletteNV
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportShadingRatePaletteNV;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes); }
};


struct CmdSetCoarseSampleOrderNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoarseSampleOrderNV;

    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    auto GetTuple() const { return std::tie(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders); }
};


struct CreateAccelerationStructureNV
{
    using api_element = schema::vulkan::api_elements::CreateAccelerationStructureNV;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct DestroyAccelerationStructureNV
{
    using api_element = schema::vulkan::api_elements::DestroyAccelerationStructureNV;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, accelerationStructure, pAllocator); }
};


struct GetAccelerationStructureMemoryRequirementsNV
{
    using api_element = schema::vulkan::api_elements::GetAccelerationStructureMemoryRequirementsNV;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct BindAccelerationStructureMemoryNV
{
    using api_element = schema::vulkan::api_elements::BindAccelerationStructureMemoryNV;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct CmdBuildAccelerationStructureNV
{
    using api_element = schema::vulkan::api_elements::CmdBuildAccelerationStructureNV;

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
    using api_element = schema::vulkan::api_elements::CmdCopyAccelerationStructureNV;

    format::HandleId commandBuffer;
    format::HandleId dst;
    format::HandleId src;
    VkCopyAccelerationStructureModeKHR mode;

    auto GetTuple() const { return std::tie(commandBuffer, dst, src, mode); }
};


struct CmdTraceRaysNV
{
    using api_element = schema::vulkan::api_elements::CmdTraceRaysNV;

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
    using api_element = schema::vulkan::api_elements::CreateRayTracingPipelinesNV;

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
    using api_element = schema::vulkan::api_elements::GetRayTracingShaderGroupHandlesKHR;

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
    using api_element = schema::vulkan::api_elements::GetRayTracingShaderGroupHandlesNV;

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
    using api_element = schema::vulkan::api_elements::GetAccelerationStructureHandleNV;

    VkResult result;
    format::HandleId device;
    format::HandleId accelerationStructure;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, accelerationStructure, dataSize, pData); }
};


struct CmdWriteAccelerationStructuresPropertiesNV
{
    using api_element = schema::vulkan::api_elements::CmdWriteAccelerationStructuresPropertiesNV;

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
    using api_element = schema::vulkan::api_elements::CompileDeferredNV;

    VkResult result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t shader;

    auto GetTuple() const { return std::tie(result, device, pipeline, shader); }
};


struct GetMemoryHostPointerPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetMemoryHostPointerPropertiesEXT;

    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, pHostPointer, pMemoryHostPointerProperties); }
};


struct CmdWriteBufferMarkerAMD
{
    using api_element = schema::vulkan::api_elements::CmdWriteBufferMarkerAMD;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker); }
};


struct CmdWriteBufferMarker2AMD
{
    using api_element = schema::vulkan::api_elements::CmdWriteBufferMarker2AMD;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    auto GetTuple() const { return std::tie(commandBuffer, stage, dstBuffer, dstOffset, marker); }
};


struct GetPhysicalDeviceCalibrateableTimeDomainsEXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCalibrateableTimeDomainsEXT;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;

    auto GetTuple() const { return std::tie(result, physicalDevice, pTimeDomainCount, pTimeDomains); }
};


struct GetCalibratedTimestampsEXT
{
    using api_element = schema::vulkan::api_elements::GetCalibratedTimestampsEXT;

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
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksNV;

    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    auto GetTuple() const { return std::tie(commandBuffer, taskCount, firstTask); }
};


struct CmdDrawMeshTasksIndirectNV
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirectNV;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawMeshTasksIndirectCountNV
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirectCountNV;

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
    using api_element = schema::vulkan::api_elements::CmdSetExclusiveScissorEnableNV;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    PointerDecoder<VkBool32> pExclusiveScissorEnables;

    auto GetTuple() const { return std::tie(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables); }
};


struct CmdSetExclusiveScissorNV
{
    using api_element = schema::vulkan::api_elements::CmdSetExclusiveScissorNV;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    auto GetTuple() const { return std::tie(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors); }
};


struct CmdSetCheckpointNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCheckpointNV;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    auto GetTuple() const { return std::tie(commandBuffer, pCheckpointMarker); }
};


struct GetQueueCheckpointDataNV
{
    using api_element = schema::vulkan::api_elements::GetQueueCheckpointDataNV;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    auto GetTuple() const { return std::tie(queue, pCheckpointDataCount, pCheckpointData); }
};


struct GetQueueCheckpointData2NV
{
    using api_element = schema::vulkan::api_elements::GetQueueCheckpointData2NV;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointData2NV> pCheckpointData;

    auto GetTuple() const { return std::tie(queue, pCheckpointDataCount, pCheckpointData); }
};


struct SetSwapchainPresentTimingQueueSizeEXT
{
    using api_element = schema::vulkan::api_elements::SetSwapchainPresentTimingQueueSizeEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    uint32_t size;

    auto GetTuple() const { return std::tie(result, device, swapchain, size); }
};


struct GetSwapchainTimingPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetSwapchainTimingPropertiesEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSwapchainTimingPropertiesEXT> pSwapchainTimingProperties;
    PointerDecoder<uint64_t> pSwapchainTimingPropertiesCounter;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainTimingProperties, pSwapchainTimingPropertiesCounter); }
};


struct GetSwapchainTimeDomainPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetSwapchainTimeDomainPropertiesEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSwapchainTimeDomainPropertiesEXT> pSwapchainTimeDomainProperties;
    PointerDecoder<uint64_t> pTimeDomainsCounter;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSwapchainTimeDomainProperties, pTimeDomainsCounter); }
};


struct GetPastPresentationTimingEXT
{
    using api_element = schema::vulkan::api_elements::GetPastPresentationTimingEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPastPresentationTimingInfoEXT> pPastPresentationTimingInfo;
    StructPointerDecoder<Decoded_VkPastPresentationTimingPropertiesEXT> pPastPresentationTimingProperties;

    auto GetTuple() const { return std::tie(result, device, pPastPresentationTimingInfo, pPastPresentationTimingProperties); }
};


struct InitializePerformanceApiINTEL
{
    using api_element = schema::vulkan::api_elements::InitializePerformanceApiINTEL;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL> pInitializeInfo;

    auto GetTuple() const { return std::tie(result, device, pInitializeInfo); }
};


struct UninitializePerformanceApiINTEL
{
    using api_element = schema::vulkan::api_elements::UninitializePerformanceApiINTEL;

    format::HandleId device;

    auto GetTuple() const { return std::tie(device); }
};


struct CmdSetPerformanceMarkerINTEL
{
    using api_element = schema::vulkan::api_elements::CmdSetPerformanceMarkerINTEL;

    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL> pMarkerInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pMarkerInfo); }
};


struct CmdSetPerformanceStreamMarkerINTEL
{
    using api_element = schema::vulkan::api_elements::CmdSetPerformanceStreamMarkerINTEL;

    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL> pMarkerInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pMarkerInfo); }
};


struct CmdSetPerformanceOverrideINTEL
{
    using api_element = schema::vulkan::api_elements::CmdSetPerformanceOverrideINTEL;

    VkResult result;
    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL> pOverrideInfo;

    auto GetTuple() const { return std::tie(result, commandBuffer, pOverrideInfo); }
};


struct AcquirePerformanceConfigurationINTEL
{
    using api_element = schema::vulkan::api_elements::AcquirePerformanceConfigurationINTEL;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL> pAcquireInfo;
    HandlePointerDecoder<VkPerformanceConfigurationINTEL> pConfiguration;

    auto GetTuple() const { return std::tie(result, device, pAcquireInfo, pConfiguration); }
};


struct ReleasePerformanceConfigurationINTEL
{
    using api_element = schema::vulkan::api_elements::ReleasePerformanceConfigurationINTEL;

    VkResult result;
    format::HandleId device;
    format::HandleId configuration;

    auto GetTuple() const { return std::tie(result, device, configuration); }
};


struct QueueSetPerformanceConfigurationINTEL
{
    using api_element = schema::vulkan::api_elements::QueueSetPerformanceConfigurationINTEL;

    VkResult result;
    format::HandleId queue;
    format::HandleId configuration;

    auto GetTuple() const { return std::tie(result, queue, configuration); }
};


struct GetPerformanceParameterINTEL
{
    using api_element = schema::vulkan::api_elements::GetPerformanceParameterINTEL;

    VkResult result;
    format::HandleId device;
    VkPerformanceParameterTypeINTEL parameter;
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL> pValue;

    auto GetTuple() const { return std::tie(result, device, parameter, pValue); }
};


struct SetLocalDimmingAMD
{
    using api_element = schema::vulkan::api_elements::SetLocalDimmingAMD;

    format::HandleId device;
    format::HandleId swapChain;
    VkBool32 localDimmingEnable;

    auto GetTuple() const { return std::tie(device, swapChain, localDimmingEnable); }
};


struct CreateImagePipeSurfaceFUCHSIA
{
    using api_element = schema::vulkan::api_elements::CreateImagePipeSurfaceFUCHSIA;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CreateMetalSurfaceEXT
{
    using api_element = schema::vulkan::api_elements::CreateMetalSurfaceEXT;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetBufferDeviceAddressEXT
{
    using api_element = schema::vulkan::api_elements::GetBufferDeviceAddressEXT;

    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct GetPhysicalDeviceToolPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceToolPropertiesEXT;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pToolCount, pToolProperties); }
};


struct GetPhysicalDeviceCooperativeMatrixPropertiesNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCooperativeMatrixPropertiesNV;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pCombinationCount;
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV> pCombinations;

    auto GetTuple() const { return std::tie(result, physicalDevice, pCombinationCount, pCombinations); }
};


struct GetPhysicalDeviceSurfacePresentModes2EXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceSurfacePresentModes2EXT;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;

    auto GetTuple() const { return std::tie(result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes); }
};


struct AcquireFullScreenExclusiveModeEXT
{
    using api_element = schema::vulkan::api_elements::AcquireFullScreenExclusiveModeEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct ReleaseFullScreenExclusiveModeEXT
{
    using api_element = schema::vulkan::api_elements::ReleaseFullScreenExclusiveModeEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;

    auto GetTuple() const { return std::tie(result, device, swapchain); }
};


struct GetDeviceGroupSurfacePresentModes2EXT
{
    using api_element = schema::vulkan::api_elements::GetDeviceGroupSurfacePresentModes2EXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;

    auto GetTuple() const { return std::tie(result, device, pSurfaceInfo, pModes); }
};


struct CreateHeadlessSurfaceEXT
{
    using api_element = schema::vulkan::api_elements::CreateHeadlessSurfaceEXT;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct CmdSetLineStippleEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetLineStippleEXT;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    auto GetTuple() const { return std::tie(commandBuffer, lineStippleFactor, lineStipplePattern); }
};


struct ResetQueryPoolEXT
{
    using api_element = schema::vulkan::api_elements::ResetQueryPoolEXT;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    auto GetTuple() const { return std::tie(device, queryPool, firstQuery, queryCount); }
};


struct CmdSetCullModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetCullModeEXT;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    auto GetTuple() const { return std::tie(commandBuffer, cullMode); }
};


struct CmdSetFrontFaceEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetFrontFaceEXT;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    auto GetTuple() const { return std::tie(commandBuffer, frontFace); }
};


struct CmdSetPrimitiveTopologyEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetPrimitiveTopologyEXT;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveTopology); }
};


struct CmdSetViewportWithCountEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportWithCountEXT;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    auto GetTuple() const { return std::tie(commandBuffer, viewportCount, pViewports); }
};


struct CmdSetScissorWithCountEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetScissorWithCountEXT;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    auto GetTuple() const { return std::tie(commandBuffer, scissorCount, pScissors); }
};


struct CmdBindVertexBuffers2EXT
{
    using api_element = schema::vulkan::api_elements::CmdBindVertexBuffers2EXT;

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
    using api_element = schema::vulkan::api_elements::CmdSetDepthTestEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthTestEnable); }
};


struct CmdSetDepthWriteEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthWriteEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthWriteEnable); }
};


struct CmdSetDepthCompareOpEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthCompareOpEXT;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    auto GetTuple() const { return std::tie(commandBuffer, depthCompareOp); }
};


struct CmdSetDepthBoundsTestEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBoundsTestEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBoundsTestEnable); }
};


struct CmdSetStencilTestEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilTestEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stencilTestEnable); }
};


struct CmdSetStencilOpEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetStencilOpEXT;

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
    using api_element = schema::vulkan::api_elements::CopyMemoryToImageEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo> pCopyMemoryToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyMemoryToImageInfo); }
};


struct CopyImageToMemoryEXT
{
    using api_element = schema::vulkan::api_elements::CopyImageToMemoryEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo> pCopyImageToMemoryInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToMemoryInfo); }
};


struct CopyImageToImageEXT
{
    using api_element = schema::vulkan::api_elements::CopyImageToImageEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo> pCopyImageToImageInfo;

    auto GetTuple() const { return std::tie(result, device, pCopyImageToImageInfo); }
};


struct TransitionImageLayoutEXT
{
    using api_element = schema::vulkan::api_elements::TransitionImageLayoutEXT;

    VkResult result;
    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo> pTransitions;

    auto GetTuple() const { return std::tie(result, device, transitionCount, pTransitions); }
};


struct GetImageSubresourceLayout2EXT
{
    using api_element = schema::vulkan::api_elements::GetImageSubresourceLayout2EXT;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2> pLayout;

    auto GetTuple() const { return std::tie(device, image, pSubresource, pLayout); }
};


struct ReleaseSwapchainImagesEXT
{
    using api_element = schema::vulkan::api_elements::ReleaseSwapchainImagesEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR> pReleaseInfo;

    auto GetTuple() const { return std::tie(result, device, pReleaseInfo); }
};


struct GetGeneratedCommandsMemoryRequirementsNV
{
    using api_element = schema::vulkan::api_elements::GetGeneratedCommandsMemoryRequirementsNV;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct CmdPreprocessGeneratedCommandsNV
{
    using api_element = schema::vulkan::api_elements::CmdPreprocessGeneratedCommandsNV;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pGeneratedCommandsInfo); }
};


struct CmdExecuteGeneratedCommandsNV
{
    using api_element = schema::vulkan::api_elements::CmdExecuteGeneratedCommandsNV;

    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, isPreprocessed, pGeneratedCommandsInfo); }
};


struct CmdBindPipelineShaderGroupNV
{
    using api_element = schema::vulkan::api_elements::CmdBindPipelineShaderGroupNV;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;
    uint32_t groupIndex;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline, groupIndex); }
};


struct CreateIndirectCommandsLayoutNV
{
    using api_element = schema::vulkan::api_elements::CreateIndirectCommandsLayoutNV;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutNV> pIndirectCommandsLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout); }
};


struct DestroyIndirectCommandsLayoutNV
{
    using api_element = schema::vulkan::api_elements::DestroyIndirectCommandsLayoutNV;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectCommandsLayout, pAllocator); }
};


struct CmdSetDepthBias2EXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBias2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT> pDepthBiasInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDepthBiasInfo); }
};


struct AcquireDrmDisplayEXT
{
    using api_element = schema::vulkan::api_elements::AcquireDrmDisplayEXT;

    VkResult result;
    format::HandleId physicalDevice;
    int32_t drmFd;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, drmFd, display); }
};


struct GetDrmDisplayEXT
{
    using api_element = schema::vulkan::api_elements::GetDrmDisplayEXT;

    VkResult result;
    format::HandleId physicalDevice;
    int32_t drmFd;
    uint32_t connectorId;
    HandlePointerDecoder<VkDisplayKHR> display;

    auto GetTuple() const { return std::tie(result, physicalDevice, drmFd, connectorId, display); }
};


struct CreatePrivateDataSlotEXT
{
    using api_element = schema::vulkan::api_elements::CreatePrivateDataSlotEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pPrivateDataSlot); }
};


struct DestroyPrivateDataSlotEXT
{
    using api_element = schema::vulkan::api_elements::DestroyPrivateDataSlotEXT;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, privateDataSlot, pAllocator); }
};


struct SetPrivateDataEXT
{
    using api_element = schema::vulkan::api_elements::SetPrivateDataEXT;

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
    using api_element = schema::vulkan::api_elements::GetPrivateDataEXT;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    auto GetTuple() const { return std::tie(device, objectType, objectHandle, privateDataSlot, pData); }
};


struct QueueSetPerfHintQCOM
{
    using api_element = schema::vulkan::api_elements::QueueSetPerfHintQCOM;

    VkResult result;
    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPerfHintInfoQCOM> pPerfHintInfo;

    auto GetTuple() const { return std::tie(result, queue, pPerfHintInfo); }
};


struct CmdDispatchTileQCOM
{
    using api_element = schema::vulkan::api_elements::CmdDispatchTileQCOM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM> pDispatchTileInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pDispatchTileInfo); }
};


struct CmdBeginPerTileExecutionQCOM
{
    using api_element = schema::vulkan::api_elements::CmdBeginPerTileExecutionQCOM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM> pPerTileBeginInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPerTileBeginInfo); }
};


struct CmdEndPerTileExecutionQCOM
{
    using api_element = schema::vulkan::api_elements::CmdEndPerTileExecutionQCOM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM> pPerTileEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pPerTileEndInfo); }
};


struct GetDescriptorSetLayoutSizeEXT
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetLayoutSizeEXT;

    format::HandleId device;
    format::HandleId layout;
    PointerDecoder<VkDeviceSize> pLayoutSizeInBytes;

    auto GetTuple() const { return std::tie(device, layout, pLayoutSizeInBytes); }
};


struct GetDescriptorSetLayoutBindingOffsetEXT
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetLayoutBindingOffsetEXT;

    format::HandleId device;
    format::HandleId layout;
    uint32_t binding;
    PointerDecoder<VkDeviceSize> pOffset;

    auto GetTuple() const { return std::tie(device, layout, binding, pOffset); }
};


struct GetDescriptorEXT
{
    using api_element = schema::vulkan::api_elements::GetDescriptorEXT;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorGetInfoEXT> pDescriptorInfo;
    size_t dataSize;
    PointerDecoder<uint8_t> pDescriptor;

    auto GetTuple() const { return std::tie(device, pDescriptorInfo, dataSize, pDescriptor); }
};


struct CmdBindDescriptorBuffersEXT
{
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorBuffersEXT;

    format::HandleId commandBuffer;
    uint32_t bufferCount;
    StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT> pBindingInfos;

    auto GetTuple() const { return std::tie(commandBuffer, bufferCount, pBindingInfos); }
};


struct CmdSetDescriptorBufferOffsetsEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDescriptorBufferOffsetsEXT;

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
    using api_element = schema::vulkan::api_elements::CmdBindDescriptorBufferEmbeddedSamplersEXT;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, layout, set); }
};


struct CmdSetFragmentShadingRateEnumNV
{
    using api_element = schema::vulkan::api_elements::CmdSetFragmentShadingRateEnumNV;

    format::HandleId commandBuffer;
    VkFragmentShadingRateNV shadingRate;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    auto GetTuple() const { return std::tie(commandBuffer, shadingRate, combinerOps); }
};


struct GetDeviceFaultInfoEXT
{
    using api_element = schema::vulkan::api_elements::GetDeviceFaultInfoEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT> pFaultInfo;

    auto GetTuple() const { return std::tie(result, device, pFaultCounts, pFaultInfo); }
};


struct AcquireWinrtDisplayNV
{
    using api_element = schema::vulkan::api_elements::AcquireWinrtDisplayNV;

    VkResult result;
    format::HandleId physicalDevice;
    format::HandleId display;

    auto GetTuple() const { return std::tie(result, physicalDevice, display); }
};


struct GetWinrtDisplayNV
{
    using api_element = schema::vulkan::api_elements::GetWinrtDisplayNV;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t deviceRelativeId;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;

    auto GetTuple() const { return std::tie(result, physicalDevice, deviceRelativeId, pDisplay); }
};


struct CreateDirectFBSurfaceEXT
{
    using api_element = schema::vulkan::api_elements::CreateDirectFBSurfaceEXT;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceDirectFBPresentationSupportEXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceDirectFBPresentationSupportEXT;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dfb;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, dfb); }
};


struct CmdSetVertexInputEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetVertexInputEXT;

    format::HandleId commandBuffer;
    uint32_t vertexBindingDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT> pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT> pVertexAttributeDescriptions;

    auto GetTuple() const { return std::tie(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions); }
};


struct GetMemoryZirconHandleFUCHSIA
{
    using api_element = schema::vulkan::api_elements::GetMemoryZirconHandleFUCHSIA;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;

    auto GetTuple() const { return std::tie(result, device, pGetZirconHandleInfo, pZirconHandle); }
};


struct GetMemoryZirconHandlePropertiesFUCHSIA
{
    using api_element = schema::vulkan::api_elements::GetMemoryZirconHandlePropertiesFUCHSIA;

    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint32_t zirconHandle;
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA> pMemoryZirconHandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, zirconHandle, pMemoryZirconHandleProperties); }
};


struct ImportSemaphoreZirconHandleFUCHSIA
{
    using api_element = schema::vulkan::api_elements::ImportSemaphoreZirconHandleFUCHSIA;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA> pImportSemaphoreZirconHandleInfo;

    auto GetTuple() const { return std::tie(result, device, pImportSemaphoreZirconHandleInfo); }
};


struct GetSemaphoreZirconHandleFUCHSIA
{
    using api_element = schema::vulkan::api_elements::GetSemaphoreZirconHandleFUCHSIA;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;

    auto GetTuple() const { return std::tie(result, device, pGetZirconHandleInfo, pZirconHandle); }
};


struct CmdBindInvocationMaskHUAWEI
{
    using api_element = schema::vulkan::api_elements::CmdBindInvocationMaskHUAWEI;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    auto GetTuple() const { return std::tie(commandBuffer, imageView, imageLayout); }
};


struct GetMemoryRemoteAddressNV
{
    using api_element = schema::vulkan::api_elements::GetMemoryRemoteAddressNV;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV> pMemoryGetRemoteAddressInfo;
    PointerDecoder<uint64_t, void*> pAddress;

    auto GetTuple() const { return std::tie(result, device, pMemoryGetRemoteAddressInfo, pAddress); }
};


struct CmdSetPatchControlPointsEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetPatchControlPointsEXT;

    format::HandleId commandBuffer;
    uint32_t patchControlPoints;

    auto GetTuple() const { return std::tie(commandBuffer, patchControlPoints); }
};


struct CmdSetRasterizerDiscardEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetRasterizerDiscardEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizerDiscardEnable); }
};


struct CmdSetDepthBiasEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthBiasEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthBiasEnable); }
};


struct CmdSetLogicOpEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetLogicOpEXT;

    format::HandleId commandBuffer;
    VkLogicOp logicOp;

    auto GetTuple() const { return std::tie(commandBuffer, logicOp); }
};


struct CmdSetPrimitiveRestartEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetPrimitiveRestartEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartEnable); }
};


struct CreateScreenSurfaceQNX
{
    using api_element = schema::vulkan::api_elements::CreateScreenSurfaceQNX;

    VkResult result;
    format::HandleId instance;
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;

    auto GetTuple() const { return std::tie(result, instance, pCreateInfo, pAllocator, pSurface); }
};


struct GetPhysicalDeviceScreenPresentationSupportQNX
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceScreenPresentationSupportQNX;

    VkBool32 result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t window;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, window); }
};


struct CmdSetColorWriteEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetColorWriteEnableEXT;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorWriteEnables;

    auto GetTuple() const { return std::tie(commandBuffer, attachmentCount, pColorWriteEnables); }
};


struct CmdDrawMultiEXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawMultiEXT;

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
    using api_element = schema::vulkan::api_elements::CmdDrawMultiIndexedEXT;

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
    using api_element = schema::vulkan::api_elements::CreateMicromapEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkMicromapEXT> pMicromap;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pMicromap); }
};


struct DestroyMicromapEXT
{
    using api_element = schema::vulkan::api_elements::DestroyMicromapEXT;

    format::HandleId device;
    format::HandleId micromap;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, micromap, pAllocator); }
};


struct CmdBuildMicromapsEXT
{
    using api_element = schema::vulkan::api_elements::CmdBuildMicromapsEXT;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos); }
};


struct BuildMicromapsEXT
{
    using api_element = schema::vulkan::api_elements::BuildMicromapsEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, infoCount, pInfos); }
};


struct CopyMicromapEXT
{
    using api_element = schema::vulkan::api_elements::CopyMicromapEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMicromapToMemoryEXT
{
    using api_element = schema::vulkan::api_elements::CopyMicromapToMemoryEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMemoryToMicromapEXT
{
    using api_element = schema::vulkan::api_elements::CopyMemoryToMicromapEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct WriteMicromapsPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::WriteMicromapsPropertiesEXT;

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
    using api_element = schema::vulkan::api_elements::CmdCopyMicromapEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMicromapToMemoryEXT
{
    using api_element = schema::vulkan::api_elements::CmdCopyMicromapToMemoryEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryToMicromapEXT
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryToMicromapEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdWriteMicromapsPropertiesEXT
{
    using api_element = schema::vulkan::api_elements::CmdWriteMicromapsPropertiesEXT;

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
    using api_element = schema::vulkan::api_elements::GetDeviceMicromapCompatibilityEXT;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    auto GetTuple() const { return std::tie(device, pVersionInfo, pCompatibility); }
};


struct GetMicromapBuildSizesEXT
{
    using api_element = schema::vulkan::api_elements::GetMicromapBuildSizesEXT;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pBuildInfo;
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT> pSizeInfo;

    auto GetTuple() const { return std::tie(device, buildType, pBuildInfo, pSizeInfo); }
};


struct CmdDrawClusterHUAWEI
{
    using api_element = schema::vulkan::api_elements::CmdDrawClusterHUAWEI;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDrawClusterIndirectHUAWEI
{
    using api_element = schema::vulkan::api_elements::CmdDrawClusterIndirectHUAWEI;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset); }
};


struct SetDeviceMemoryPriorityEXT
{
    using api_element = schema::vulkan::api_elements::SetDeviceMemoryPriorityEXT;

    format::HandleId device;
    format::HandleId memory;
    float priority;

    auto GetTuple() const { return std::tie(device, memory, priority); }
};


struct CmdSetDispatchParametersARM
{
    using api_element = schema::vulkan::api_elements::CmdSetDispatchParametersARM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDispatchParametersARM> pDispatchParameters;

    auto GetTuple() const { return std::tie(commandBuffer, pDispatchParameters); }
};


struct GetDescriptorSetLayoutHostMappingInfoVALVE
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetLayoutHostMappingInfoVALVE;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE> pBindingReference;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE> pHostMapping;

    auto GetTuple() const { return std::tie(device, pBindingReference, pHostMapping); }
};


struct GetDescriptorSetHostMappingVALVE
{
    using api_element = schema::vulkan::api_elements::GetDescriptorSetHostMappingVALVE;

    format::HandleId device;
    format::HandleId descriptorSet;
    PointerDecoder<uint64_t, void*> ppData;

    auto GetTuple() const { return std::tie(device, descriptorSet, ppData); }
};


struct GetPipelineIndirectMemoryRequirementsNV
{
    using api_element = schema::vulkan::api_elements::GetPipelineIndirectMemoryRequirementsNV;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pMemoryRequirements); }
};


struct CmdUpdatePipelineIndirectBufferNV
{
    using api_element = schema::vulkan::api_elements::CmdUpdatePipelineIndirectBufferNV;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineBindPoint, pipeline); }
};


struct GetPipelineIndirectDeviceAddressNV
{
    using api_element = schema::vulkan::api_elements::GetPipelineIndirectDeviceAddressNV;

    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdSetDepthClampEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthClampEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthClampEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthClampEnable); }
};


struct CmdSetPolygonModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetPolygonModeEXT;

    format::HandleId commandBuffer;
    VkPolygonMode polygonMode;

    auto GetTuple() const { return std::tie(commandBuffer, polygonMode); }
};


struct CmdSetRasterizationSamplesEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetRasterizationSamplesEXT;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits rasterizationSamples;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizationSamples); }
};


struct CmdSetSampleMaskEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetSampleMaskEXT;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits samples;
    PointerDecoder<VkSampleMask> pSampleMask;

    auto GetTuple() const { return std::tie(commandBuffer, samples, pSampleMask); }
};


struct CmdSetAlphaToCoverageEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetAlphaToCoverageEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 alphaToCoverageEnable;

    auto GetTuple() const { return std::tie(commandBuffer, alphaToCoverageEnable); }
};


struct CmdSetAlphaToOneEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetAlphaToOneEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 alphaToOneEnable;

    auto GetTuple() const { return std::tie(commandBuffer, alphaToOneEnable); }
};


struct CmdSetLogicOpEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetLogicOpEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 logicOpEnable;

    auto GetTuple() const { return std::tie(commandBuffer, logicOpEnable); }
};


struct CmdSetColorBlendEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetColorBlendEnableEXT;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorBlendEnables;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables); }
};


struct CmdSetColorBlendEquationEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetColorBlendEquationEXT;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT> pColorBlendEquations;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations); }
};


struct CmdSetColorWriteMaskEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetColorWriteMaskEXT;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkColorComponentFlags> pColorWriteMasks;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks); }
};


struct CmdSetTessellationDomainOriginEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetTessellationDomainOriginEXT;

    format::HandleId commandBuffer;
    VkTessellationDomainOrigin domainOrigin;

    auto GetTuple() const { return std::tie(commandBuffer, domainOrigin); }
};


struct CmdSetRasterizationStreamEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetRasterizationStreamEXT;

    format::HandleId commandBuffer;
    uint32_t rasterizationStream;

    auto GetTuple() const { return std::tie(commandBuffer, rasterizationStream); }
};


struct CmdSetConservativeRasterizationModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetConservativeRasterizationModeEXT;

    format::HandleId commandBuffer;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;

    auto GetTuple() const { return std::tie(commandBuffer, conservativeRasterizationMode); }
};


struct CmdSetExtraPrimitiveOverestimationSizeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetExtraPrimitiveOverestimationSizeEXT;

    format::HandleId commandBuffer;
    float extraPrimitiveOverestimationSize;

    auto GetTuple() const { return std::tie(commandBuffer, extraPrimitiveOverestimationSize); }
};


struct CmdSetDepthClipEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthClipEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 depthClipEnable;

    auto GetTuple() const { return std::tie(commandBuffer, depthClipEnable); }
};


struct CmdSetSampleLocationsEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetSampleLocationsEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 sampleLocationsEnable;

    auto GetTuple() const { return std::tie(commandBuffer, sampleLocationsEnable); }
};


struct CmdSetColorBlendAdvancedEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetColorBlendAdvancedEXT;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT> pColorBlendAdvanced;

    auto GetTuple() const { return std::tie(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced); }
};


struct CmdSetProvokingVertexModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetProvokingVertexModeEXT;

    format::HandleId commandBuffer;
    VkProvokingVertexModeEXT provokingVertexMode;

    auto GetTuple() const { return std::tie(commandBuffer, provokingVertexMode); }
};


struct CmdSetLineRasterizationModeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetLineRasterizationModeEXT;

    format::HandleId commandBuffer;
    VkLineRasterizationModeEXT lineRasterizationMode;

    auto GetTuple() const { return std::tie(commandBuffer, lineRasterizationMode); }
};


struct CmdSetLineStippleEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetLineStippleEnableEXT;

    format::HandleId commandBuffer;
    VkBool32 stippledLineEnable;

    auto GetTuple() const { return std::tie(commandBuffer, stippledLineEnable); }
};


struct CmdSetDepthClipNegativeOneToOneEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthClipNegativeOneToOneEXT;

    format::HandleId commandBuffer;
    VkBool32 negativeOneToOne;

    auto GetTuple() const { return std::tie(commandBuffer, negativeOneToOne); }
};


struct CmdSetViewportWScalingEnableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportWScalingEnableNV;

    format::HandleId commandBuffer;
    VkBool32 viewportWScalingEnable;

    auto GetTuple() const { return std::tie(commandBuffer, viewportWScalingEnable); }
};


struct CmdSetViewportSwizzleNV
{
    using api_element = schema::vulkan::api_elements::CmdSetViewportSwizzleNV;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;

    auto GetTuple() const { return std::tie(commandBuffer, firstViewport, viewportCount, pViewportSwizzles); }
};


struct CmdSetCoverageToColorEnableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageToColorEnableNV;

    format::HandleId commandBuffer;
    VkBool32 coverageToColorEnable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageToColorEnable); }
};


struct CmdSetCoverageToColorLocationNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageToColorLocationNV;

    format::HandleId commandBuffer;
    uint32_t coverageToColorLocation;

    auto GetTuple() const { return std::tie(commandBuffer, coverageToColorLocation); }
};


struct CmdSetCoverageModulationModeNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageModulationModeNV;

    format::HandleId commandBuffer;
    VkCoverageModulationModeNV coverageModulationMode;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationMode); }
};


struct CmdSetCoverageModulationTableEnableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageModulationTableEnableNV;

    format::HandleId commandBuffer;
    VkBool32 coverageModulationTableEnable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationTableEnable); }
};


struct CmdSetCoverageModulationTableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageModulationTableNV;

    format::HandleId commandBuffer;
    uint32_t coverageModulationTableCount;
    PointerDecoder<float> pCoverageModulationTable;

    auto GetTuple() const { return std::tie(commandBuffer, coverageModulationTableCount, pCoverageModulationTable); }
};


struct CmdSetShadingRateImageEnableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetShadingRateImageEnableNV;

    format::HandleId commandBuffer;
    VkBool32 shadingRateImageEnable;

    auto GetTuple() const { return std::tie(commandBuffer, shadingRateImageEnable); }
};


struct CmdSetRepresentativeFragmentTestEnableNV
{
    using api_element = schema::vulkan::api_elements::CmdSetRepresentativeFragmentTestEnableNV;

    format::HandleId commandBuffer;
    VkBool32 representativeFragmentTestEnable;

    auto GetTuple() const { return std::tie(commandBuffer, representativeFragmentTestEnable); }
};


struct CmdSetCoverageReductionModeNV
{
    using api_element = schema::vulkan::api_elements::CmdSetCoverageReductionModeNV;

    format::HandleId commandBuffer;
    VkCoverageReductionModeNV coverageReductionMode;

    auto GetTuple() const { return std::tie(commandBuffer, coverageReductionMode); }
};


struct CreateTensorARM
{
    using api_element = schema::vulkan::api_elements::CreateTensorARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkTensorCreateInfoARM> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkTensorARM> pTensor;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pTensor); }
};


struct DestroyTensorARM
{
    using api_element = schema::vulkan::api_elements::DestroyTensorARM;

    format::HandleId device;
    format::HandleId tensor;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, tensor, pAllocator); }
};


struct CreateTensorViewARM
{
    using api_element = schema::vulkan::api_elements::CreateTensorViewARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkTensorViewCreateInfoARM> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkTensorViewARM> pView;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pView); }
};


struct DestroyTensorViewARM
{
    using api_element = schema::vulkan::api_elements::DestroyTensorViewARM;

    format::HandleId device;
    format::HandleId tensorView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, tensorView, pAllocator); }
};


struct GetTensorMemoryRequirementsARM
{
    using api_element = schema::vulkan::api_elements::GetTensorMemoryRequirementsARM;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkTensorMemoryRequirementsInfoARM> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct BindTensorMemoryARM
{
    using api_element = schema::vulkan::api_elements::BindTensorMemoryARM;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindTensorMemoryInfoARM> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct GetDeviceTensorMemoryRequirementsARM
{
    using api_element = schema::vulkan::api_elements::GetDeviceTensorMemoryRequirementsARM;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceTensorMemoryRequirementsARM> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct CmdCopyTensorARM
{
    using api_element = schema::vulkan::api_elements::CmdCopyTensorARM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyTensorInfoARM> pCopyTensorInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pCopyTensorInfo); }
};


struct GetPhysicalDeviceExternalTensorPropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceExternalTensorPropertiesARM;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalTensorInfoARM> pExternalTensorInfo;
    StructPointerDecoder<Decoded_VkExternalTensorPropertiesARM> pExternalTensorProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pExternalTensorInfo, pExternalTensorProperties); }
};


struct GetShaderModuleIdentifierEXT
{
    using api_element = schema::vulkan::api_elements::GetShaderModuleIdentifierEXT;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    auto GetTuple() const { return std::tie(device, shaderModule, pIdentifier); }
};


struct GetShaderModuleCreateInfoIdentifierEXT
{
    using api_element = schema::vulkan::api_elements::GetShaderModuleCreateInfoIdentifierEXT;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    auto GetTuple() const { return std::tie(device, pCreateInfo, pIdentifier); }
};


struct GetPhysicalDeviceOpticalFlowImageFormatsNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceOpticalFlowImageFormatsNV;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t> pFormatCount;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties); }
};


struct CreateOpticalFlowSessionNV
{
    using api_element = schema::vulkan::api_elements::CreateOpticalFlowSessionNV;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkOpticalFlowSessionNV> pSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSession); }
};


struct DestroyOpticalFlowSessionNV
{
    using api_element = schema::vulkan::api_elements::DestroyOpticalFlowSessionNV;

    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, session, pAllocator); }
};


struct BindOpticalFlowSessionImageNV
{
    using api_element = schema::vulkan::api_elements::BindOpticalFlowSessionImageNV;

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
    using api_element = schema::vulkan::api_elements::CmdOpticalFlowExecuteNV;

    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV> pExecuteInfo;

    auto GetTuple() const { return std::tie(commandBuffer, session, pExecuteInfo); }
};


struct AntiLagUpdateAMD
{
    using api_element = schema::vulkan::api_elements::AntiLagUpdateAMD;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAntiLagDataAMD> pData;

    auto GetTuple() const { return std::tie(device, pData); }
};


struct CreateShadersEXT
{
    using api_element = schema::vulkan::api_elements::CreateShadersEXT;

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
    using api_element = schema::vulkan::api_elements::DestroyShaderEXT;

    format::HandleId device;
    format::HandleId shader;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, shader, pAllocator); }
};


struct GetShaderBinaryDataEXT
{
    using api_element = schema::vulkan::api_elements::GetShaderBinaryDataEXT;

    VkResult result;
    format::HandleId device;
    format::HandleId shader;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;

    auto GetTuple() const { return std::tie(result, device, shader, pDataSize, pData); }
};


struct CmdBindShadersEXT
{
    using api_element = schema::vulkan::api_elements::CmdBindShadersEXT;

    format::HandleId commandBuffer;
    uint32_t stageCount;
    PointerDecoder<VkShaderStageFlagBits> pStages;
    HandlePointerDecoder<VkShaderEXT> pShaders;

    auto GetTuple() const { return std::tie(commandBuffer, stageCount, pStages, pShaders); }
};


struct CmdSetDepthClampRangeEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetDepthClampRangeEXT;

    format::HandleId commandBuffer;
    VkDepthClampModeEXT depthClampMode;
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT> pDepthClampRange;

    auto GetTuple() const { return std::tie(commandBuffer, depthClampMode, pDepthClampRange); }
};


struct GetFramebufferTilePropertiesQCOM
{
    using api_element = schema::vulkan::api_elements::GetFramebufferTilePropertiesQCOM;

    VkResult result;
    format::HandleId device;
    format::HandleId framebuffer;
    PointerDecoder<uint32_t> pPropertiesCount;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;

    auto GetTuple() const { return std::tie(result, device, framebuffer, pPropertiesCount, pProperties); }
};


struct GetDynamicRenderingTilePropertiesQCOM
{
    using api_element = schema::vulkan::api_elements::GetDynamicRenderingTilePropertiesQCOM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pRenderingInfo, pProperties); }
};


struct GetPhysicalDeviceCooperativeVectorPropertiesNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCooperativeVectorPropertiesNV;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeVectorPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct ConvertCooperativeVectorMatrixNV
{
    using api_element = schema::vulkan::api_elements::ConvertCooperativeVectorMatrixNV;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdConvertCooperativeVectorMatrixNV
{
    using api_element = schema::vulkan::api_elements::CmdConvertCooperativeVectorMatrixNV;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV> pInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos); }
};


struct SetLatencySleepModeNV
{
    using api_element = schema::vulkan::api_elements::SetLatencySleepModeNV;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV> pSleepModeInfo;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSleepModeInfo); }
};


struct LatencySleepNV
{
    using api_element = schema::vulkan::api_elements::LatencySleepNV;

    VkResult result;
    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV> pSleepInfo;

    auto GetTuple() const { return std::tie(result, device, swapchain, pSleepInfo); }
};


struct SetLatencyMarkerNV
{
    using api_element = schema::vulkan::api_elements::SetLatencyMarkerNV;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    auto GetTuple() const { return std::tie(device, swapchain, pLatencyMarkerInfo); }
};


struct GetLatencyTimingsNV
{
    using api_element = schema::vulkan::api_elements::GetLatencyTimingsNV;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    auto GetTuple() const { return std::tie(device, swapchain, pLatencyMarkerInfo); }
};


struct QueueNotifyOutOfBandNV
{
    using api_element = schema::vulkan::api_elements::QueueNotifyOutOfBandNV;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV> pQueueTypeInfo;

    auto GetTuple() const { return std::tie(queue, pQueueTypeInfo); }
};


struct CreateDataGraphPipelinesARM
{
    using api_element = schema::vulkan::api_elements::CreateDataGraphPipelinesARM;

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
    using api_element = schema::vulkan::api_elements::CreateDataGraphPipelineSessionARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionCreateInfoARM> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDataGraphPipelineSessionARM> pSession;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pSession); }
};


struct GetDataGraphPipelineSessionBindPointRequirementsARM
{
    using api_element = schema::vulkan::api_elements::GetDataGraphPipelineSessionBindPointRequirementsARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM> pInfo;
    PointerDecoder<uint32_t> pBindPointRequirementCount;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementARM> pBindPointRequirements;

    auto GetTuple() const { return std::tie(result, device, pInfo, pBindPointRequirementCount, pBindPointRequirements); }
};


struct GetDataGraphPipelineSessionMemoryRequirementsARM
{
    using api_element = schema::vulkan::api_elements::GetDataGraphPipelineSessionMemoryRequirementsARM;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct BindDataGraphPipelineSessionMemoryARM
{
    using api_element = schema::vulkan::api_elements::BindDataGraphPipelineSessionMemoryARM;

    VkResult result;
    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM> pBindInfos;

    auto GetTuple() const { return std::tie(result, device, bindInfoCount, pBindInfos); }
};


struct DestroyDataGraphPipelineSessionARM
{
    using api_element = schema::vulkan::api_elements::DestroyDataGraphPipelineSessionARM;

    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, session, pAllocator); }
};


struct CmdDispatchDataGraphARM
{
    using api_element = schema::vulkan::api_elements::CmdDispatchDataGraphARM;

    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, session, pInfo); }
};


struct GetDataGraphPipelineAvailablePropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetDataGraphPipelineAvailablePropertiesARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM> pPipelineInfo;
    PointerDecoder<uint32_t> pPropertiesCount;
    PointerDecoder<VkDataGraphPipelinePropertyARM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, pPropertiesCount, pProperties); }
};


struct GetDataGraphPipelinePropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetDataGraphPipelinePropertiesARM;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM> pPipelineInfo;
    uint32_t propertiesCount;
    StructPointerDecoder<Decoded_VkDataGraphPipelinePropertyQueryResultARM> pProperties;

    auto GetTuple() const { return std::tie(result, device, pPipelineInfo, propertiesCount, pProperties); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<uint32_t> pQueueFamilyDataGraphPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM> pQueueFamilyDataGraphProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphPropertyCount, pQueueFamilyDataGraphProperties); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM> pQueueFamilyDataGraphProcessingEngineInfo;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM> pQueueFamilyDataGraphProcessingEngineProperties;

    auto GetTuple() const { return std::tie(physicalDevice, pQueueFamilyDataGraphProcessingEngineInfo, pQueueFamilyDataGraphProcessingEngineProperties); }
};


struct CmdSetAttachmentFeedbackLoopEnableEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetAttachmentFeedbackLoopEnableEXT;

    format::HandleId commandBuffer;
    VkImageAspectFlags aspectMask;

    auto GetTuple() const { return std::tie(commandBuffer, aspectMask); }
};


struct CmdBindTileMemoryQCOM
{
    using api_element = schema::vulkan::api_elements::CmdBindTileMemoryQCOM;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM> pTileMemoryBindInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pTileMemoryBindInfo); }
};


struct CmdDecompressMemoryEXT
{
    using api_element = schema::vulkan::api_elements::CmdDecompressMemoryEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT> pDecompressMemoryInfoEXT;

    auto GetTuple() const { return std::tie(commandBuffer, pDecompressMemoryInfoEXT); }
};


struct CmdDecompressMemoryIndirectCountEXT
{
    using api_element = schema::vulkan::api_elements::CmdDecompressMemoryIndirectCountEXT;

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
    using api_element = schema::vulkan::api_elements::GetPartitionedAccelerationStructuresBuildSizesNV;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPartitionedAccelerationStructureInstancesInputNV> pInfo;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    auto GetTuple() const { return std::tie(device, pInfo, pSizeInfo); }
};


struct CmdBuildPartitionedAccelerationStructuresNV
{
    using api_element = schema::vulkan::api_elements::CmdBuildPartitionedAccelerationStructuresNV;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV> pBuildInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBuildInfo); }
};


struct GetGeneratedCommandsMemoryRequirementsEXT
{
    using api_element = schema::vulkan::api_elements::GetGeneratedCommandsMemoryRequirementsEXT;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    auto GetTuple() const { return std::tie(device, pInfo, pMemoryRequirements); }
};


struct CmdPreprocessGeneratedCommandsEXT
{
    using api_element = schema::vulkan::api_elements::CmdPreprocessGeneratedCommandsEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT> pGeneratedCommandsInfo;
    format::HandleId stateCommandBuffer;

    auto GetTuple() const { return std::tie(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer); }
};


struct CmdExecuteGeneratedCommandsEXT
{
    using api_element = schema::vulkan::api_elements::CmdExecuteGeneratedCommandsEXT;

    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT> pGeneratedCommandsInfo;

    auto GetTuple() const { return std::tie(commandBuffer, isPreprocessed, pGeneratedCommandsInfo); }
};


struct CreateIndirectCommandsLayoutEXT
{
    using api_element = schema::vulkan::api_elements::CreateIndirectCommandsLayoutEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT> pIndirectCommandsLayout;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout); }
};


struct DestroyIndirectCommandsLayoutEXT
{
    using api_element = schema::vulkan::api_elements::DestroyIndirectCommandsLayoutEXT;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectCommandsLayout, pAllocator); }
};


struct CreateIndirectExecutionSetEXT
{
    using api_element = schema::vulkan::api_elements::CreateIndirectExecutionSetEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectExecutionSetCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectExecutionSetEXT> pIndirectExecutionSet;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pIndirectExecutionSet); }
};


struct DestroyIndirectExecutionSetEXT
{
    using api_element = schema::vulkan::api_elements::DestroyIndirectExecutionSetEXT;

    format::HandleId device;
    format::HandleId indirectExecutionSet;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, pAllocator); }
};


struct UpdateIndirectExecutionSetPipelineEXT
{
    using api_element = schema::vulkan::api_elements::UpdateIndirectExecutionSetPipelineEXT;

    format::HandleId device;
    format::HandleId indirectExecutionSet;
    uint32_t executionSetWriteCount;
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetPipelineEXT> pExecutionSetWrites;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites); }
};


struct UpdateIndirectExecutionSetShaderEXT
{
    using api_element = schema::vulkan::api_elements::UpdateIndirectExecutionSetShaderEXT;

    format::HandleId device;
    format::HandleId indirectExecutionSet;
    uint32_t executionSetWriteCount;
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetShaderEXT> pExecutionSetWrites;

    auto GetTuple() const { return std::tie(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites); }
};


struct GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV;

    VkResult result;
    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pPropertyCount, pProperties); }
};


struct GetMemoryMetalHandleEXT
{
    using api_element = schema::vulkan::api_elements::GetMemoryMetalHandleEXT;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetMetalHandleInfoEXT> pGetMetalHandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;

    auto GetTuple() const { return std::tie(result, device, pGetMetalHandleInfo, pHandle); }
};


struct GetMemoryMetalHandlePropertiesEXT
{
    using api_element = schema::vulkan::api_elements::GetMemoryMetalHandlePropertiesEXT;

    VkResult result;
    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHandle;
    StructPointerDecoder<Decoded_VkMemoryMetalHandlePropertiesEXT> pMemoryMetalHandleProperties;

    auto GetTuple() const { return std::tie(result, device, handleType, pHandle, pMemoryMetalHandleProperties); }
};


struct EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM
{
    using api_element = schema::vulkan::api_elements::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM;

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
    using api_element = schema::vulkan::api_elements::CmdEndRendering2EXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR> pRenderingEndInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pRenderingEndInfo); }
};


struct CmdBeginCustomResolveEXT
{
    using api_element = schema::vulkan::api_elements::CmdBeginCustomResolveEXT;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT> pBeginCustomResolveInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pBeginCustomResolveInfo); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM> pQueueFamilyDataGraphProperties;
    StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatInfoARM> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t> pFormatCount;
    StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatPropertiesARM> pImageFormatProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphProperties, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties); }
};


struct GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM;

    VkResult result;
    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM> pQueueFamilyDataGraphProperties;
    TypedStructDecoder pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphProperties, pProperties); }
};


struct CmdSetComputeOccupancyPriorityNV
{
    using api_element = schema::vulkan::api_elements::CmdSetComputeOccupancyPriorityNV;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV> pParameters;

    auto GetTuple() const { return std::tie(commandBuffer, pParameters); }
};


struct GetPhysicalDeviceCooperativeMatrixProperties2EXT
{
    using api_element = schema::vulkan::api_elements::GetPhysicalDeviceCooperativeMatrixProperties2EXT;

    VkResult result;
    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceCooperativeMatrixInfo2EXT> pCooperativeMatrixInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixProperties2EXT> pProperties;

    auto GetTuple() const { return std::tie(result, physicalDevice, pCooperativeMatrixInfo, pPropertyCount, pProperties); }
};


struct CmdSetPrimitiveRestartIndexEXT
{
    using api_element = schema::vulkan::api_elements::CmdSetPrimitiveRestartIndexEXT;

    format::HandleId commandBuffer;
    uint32_t primitiveRestartIndex;

    auto GetTuple() const { return std::tie(commandBuffer, primitiveRestartIndex); }
};


struct CreateAccelerationStructureKHR
{
    using api_element = schema::vulkan::api_elements::CreateAccelerationStructureKHR;

    VkResult result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;

    auto GetTuple() const { return std::tie(result, device, pCreateInfo, pAllocator, pAccelerationStructure); }
};


struct DestroyAccelerationStructureKHR
{
    using api_element = schema::vulkan::api_elements::DestroyAccelerationStructureKHR;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    auto GetTuple() const { return std::tie(device, accelerationStructure, pAllocator); }
};


struct CmdBuildAccelerationStructuresKHR
{
    using api_element = schema::vulkan::api_elements::CmdBuildAccelerationStructuresKHR;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*> ppBuildRangeInfos;

    auto GetTuple() const { return std::tie(commandBuffer, infoCount, pInfos, ppBuildRangeInfos); }
};


struct CmdBuildAccelerationStructuresIndirectKHR
{
    using api_element = schema::vulkan::api_elements::CmdBuildAccelerationStructuresIndirectKHR;

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
    using api_element = schema::vulkan::api_elements::CopyAccelerationStructureToMemoryKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct CopyMemoryToAccelerationStructureKHR
{
    using api_element = schema::vulkan::api_elements::CopyMemoryToAccelerationStructureKHR;

    VkResult result;
    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, deferredOperation, pInfo); }
};


struct WriteAccelerationStructuresPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::WriteAccelerationStructuresPropertiesKHR;

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
    using api_element = schema::vulkan::api_elements::CmdCopyAccelerationStructureKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyAccelerationStructureToMemoryKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyAccelerationStructureToMemoryKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct CmdCopyMemoryToAccelerationStructureKHR
{
    using api_element = schema::vulkan::api_elements::CmdCopyMemoryToAccelerationStructureKHR;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(commandBuffer, pInfo); }
};


struct GetAccelerationStructureDeviceAddressKHR
{
    using api_element = schema::vulkan::api_elements::GetAccelerationStructureDeviceAddressKHR;

    VkDeviceAddress result;
    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;

    auto GetTuple() const { return std::tie(result, device, pInfo); }
};


struct CmdWriteAccelerationStructuresPropertiesKHR
{
    using api_element = schema::vulkan::api_elements::CmdWriteAccelerationStructuresPropertiesKHR;

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
    using api_element = schema::vulkan::api_elements::GetDeviceAccelerationStructureCompatibilityKHR;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    auto GetTuple() const { return std::tie(device, pVersionInfo, pCompatibility); }
};


struct GetAccelerationStructureBuildSizesKHR
{
    using api_element = schema::vulkan::api_elements::GetAccelerationStructureBuildSizesKHR;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pBuildInfo;
    PointerDecoder<uint32_t> pMaxPrimitiveCounts;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    auto GetTuple() const { return std::tie(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo); }
};


struct CmdTraceRaysKHR
{
    using api_element = schema::vulkan::api_elements::CmdTraceRaysKHR;

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
    using api_element = schema::vulkan::api_elements::GetRayTracingCaptureReplayShaderGroupHandlesKHR;

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
    using api_element = schema::vulkan::api_elements::CmdTraceRaysIndirectKHR;

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
    using api_element = schema::vulkan::api_elements::GetRayTracingShaderGroupStackSizeKHR;

    VkDeviceSize result;
    format::HandleId device;
    format::HandleId pipeline;
    uint32_t group;
    VkShaderGroupShaderKHR groupShader;

    auto GetTuple() const { return std::tie(result, device, pipeline, group, groupShader); }
};


struct CmdSetRayTracingPipelineStackSizeKHR
{
    using api_element = schema::vulkan::api_elements::CmdSetRayTracingPipelineStackSizeKHR;

    format::HandleId commandBuffer;
    uint32_t pipelineStackSize;

    auto GetTuple() const { return std::tie(commandBuffer, pipelineStackSize); }
};


struct CmdDrawMeshTasksEXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksEXT;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    auto GetTuple() const { return std::tie(commandBuffer, groupCountX, groupCountY, groupCountZ); }
};


struct CmdDrawMeshTasksIndirectEXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirectEXT;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    auto GetTuple() const { return std::tie(commandBuffer, buffer, offset, drawCount, stride); }
};


struct CmdDrawMeshTasksIndirectCountEXT
{
    using api_element = schema::vulkan::api_elements::CmdDrawMeshTasksIndirectCountEXT;

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
