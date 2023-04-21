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

#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_POST_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_POST_COMMANDS_H

#include "encode/custom_vulkan_encoder_commands.h"
#include "encode/vulkan_capture_manager.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct EncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {}

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult, Args... args)
    {}
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        const VkInstanceCreateInfo*             pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkInstance*                             pInstance)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, pCreateInfo, pAllocator, pInstance);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateInstance_PostCall(manager->GetBlockIndex() - 1, result, pCreateInfo, pAllocator, pInstance);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, instance, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyInstance_PostCall(manager->GetBlockIndex() - 1, instance, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceCount,
        VkPhysicalDevice*                       pPhysicalDevices)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, result, instance, pPhysicalDeviceCount, pPhysicalDevices);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDevices_PostCall(manager->GetBlockIndex() - 1, result, instance, pPhysicalDeviceCount, pPhysicalDevices);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures*               pFeatures)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties*                     pFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkImageType                             type,
        VkImageTiling                           tiling,
        VkImageUsageFlags                       usage,
        VkImageCreateFlags                      flags,
        VkImageFormatProperties*                pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties*             pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties*                pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties*       pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkDeviceCreateInfo*               pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDevice*                               pDevice)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, result, physicalDevice, pCreateInfo, pAllocator, pDevice);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDevice_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pCreateInfo, pAllocator, pDevice);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, device, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDevice_PostCall(manager->GetBlockIndex() - 1, device, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                queueFamilyIndex,
        uint32_t                                queueIndex,
        VkQueue*                                pQueue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, device, queueFamilyIndex, queueIndex, pQueue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceQueue_PostCall(manager->GetBlockIndex() - 1, device, queueFamilyIndex, queueIndex, pQueue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo*                     pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSubmit_PostCall(manager->GetBlockIndex() - 1, result, queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, result, queue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueWaitIdle_PostCall(manager->GetBlockIndex() - 1, result, queue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, result, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DeviceWaitIdle_PostCall(manager->GetBlockIndex() - 1, result, device);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryAllocateInfo*             pAllocateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDeviceMemory*                         pMemory)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, result, device, pAllocateInfo, pAllocator, pMemory);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateMemory_PostCall(manager->GetBlockIndex() - 1, result, device, pAllocateInfo, pAllocator, pMemory);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, device, memory, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeMemory_PostCall(manager->GetBlockIndex() - 1, device, memory, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkDeviceSize                            offset,
        VkDeviceSize                            size,
        VkMemoryMapFlags                        flags,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, result, device, memory, offset, size, flags, ppData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MapMemory_PostCall(manager->GetBlockIndex() - 1, result, device, memory, offset, size, flags, ppData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, device, memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UnmapMemory_PostCall(manager->GetBlockIndex() - 1, device, memory);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                memoryRangeCount,
        const VkMappedMemoryRange*              pMemoryRanges)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, result, device, memoryRangeCount, pMemoryRanges);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FlushMappedMemoryRanges_PostCall(manager->GetBlockIndex() - 1, result, device, memoryRangeCount, pMemoryRanges);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                memoryRangeCount,
        const VkMappedMemoryRange*              pMemoryRanges)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, result, device, memoryRangeCount, pMemoryRanges);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.InvalidateMappedMemoryRanges_PostCall(manager->GetBlockIndex() - 1, result, device, memoryRangeCount, pMemoryRanges);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkDeviceSize*                           pCommittedMemoryInBytes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, device, memory, pCommittedMemoryInBytes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryCommitment_PostCall(manager->GetBlockIndex() - 1, device, memory, pCommittedMemoryInBytes);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkBuffer                                buffer,
        VkDeviceMemory                          memory,
        VkDeviceSize                            memoryOffset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, result, device, buffer, memory, memoryOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory_PostCall(manager->GetBlockIndex() - 1, result, device, buffer, memory, memoryOffset);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkImage                                 image,
        VkDeviceMemory                          memory,
        VkDeviceSize                            memoryOffset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, result, device, image, memory, memoryOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory_PostCall(manager->GetBlockIndex() - 1, result, device, image, memory, memoryOffset);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBuffer                                buffer,
        VkMemoryRequirements*                   pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, device, buffer, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, buffer, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        VkMemoryRequirements*                   pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, device, image, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, image, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements*        pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkImageType                             type,
        VkSampleCountFlagBits                   samples,
        VkImageUsageFlags                       usage,
        VkImageTiling                           tiling,
        uint32_t*                               pPropertyCount,
        VkSparseImageFormatProperties*          pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        uint32_t                                bindInfoCount,
        const VkBindSparseInfo*                 pBindInfo,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, result, queue, bindInfoCount, pBindInfo, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindSparseInfo* pBindInfo_unwrapped = UnwrapStructArrayHandles(pBindInfo, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueBindSparse_PostCall(manager->GetBlockIndex() - 1, result, queue, bindInfoCount, pBindInfo, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkFenceCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateFence_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFence                                 fence,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, device, fence, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyFence_PostCall(manager->GetBlockIndex() - 1, device, fence, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                fenceCount,
        const VkFence*                          pFences)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, result, device, fenceCount, pFences);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetFences_PostCall(manager->GetBlockIndex() - 1, result, device, fenceCount, pFences);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, result, device, fence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceStatus_PostCall(manager->GetBlockIndex() - 1, result, device, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                fenceCount,
        const VkFence*                          pFences,
        VkBool32                                waitAll,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, result, device, fenceCount, pFences, waitAll, timeout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitForFences_PostCall(manager->GetBlockIndex() - 1, result, device, fenceCount, pFences, waitAll, timeout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSemaphore*                            pSemaphore)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSemaphore);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSemaphore_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pSemaphore);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, device, semaphore, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySemaphore_PostCall(manager->GetBlockIndex() - 1, device, semaphore, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkEventCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkEvent*                                pEvent)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pEvent);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateEvent_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pEvent);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkEvent                                 event,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, device, event, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyEvent_PostCall(manager->GetBlockIndex() - 1, device, event, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, result, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetEventStatus_PostCall(manager->GetBlockIndex() - 1, result, device, event);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, result, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetEvent_PostCall(manager->GetBlockIndex() - 1, result, device, event);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, result, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetEvent_PostCall(manager->GetBlockIndex() - 1, result, device, event);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkQueryPoolCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkQueryPool*                            pQueryPool)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pQueryPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateQueryPool_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pQueryPool);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, device, queryPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyQueryPool_PostCall(manager->GetBlockIndex() - 1, device, queryPool, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount,
        size_t                                  dataSize,
        void*                                   pData,
        VkDeviceSize                            stride,
        VkQueryResultFlags                      flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueryPoolResults_PostCall(manager->GetBlockIndex() - 1, result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkBufferCreateInfo*               pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkBuffer*                               pBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateBuffer_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBuffer                                buffer,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, device, buffer, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyBuffer_PostCall(manager->GetBlockIndex() - 1, device, buffer, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkBufferViewCreateInfo*           pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkBufferView*                           pView)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pView);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateBufferView_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pView);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBufferView                            bufferView,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, device, bufferView, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyBufferView_PostCall(manager->GetBlockIndex() - 1, device, bufferView, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImageCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkImage*                                pImage)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pImage);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImage_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pImage);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, device, image, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyImage_PostCall(manager->GetBlockIndex() - 1, device, image, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkImageSubresource*               pSubresource,
        VkSubresourceLayout*                    pLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, device, image, pSubresource, pLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSubresourceLayout_PostCall(manager->GetBlockIndex() - 1, device, image, pSubresource, pLayout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImageViewCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkImageView*                            pView)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pView);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImageView_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pView);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImageView                             imageView,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, device, imageView, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyImageView_PostCall(manager->GetBlockIndex() - 1, device, imageView, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkShaderModuleCreateInfo*         pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkShaderModule*                         pShaderModule)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pShaderModule);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateShaderModule_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pShaderModule);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderModule                          shaderModule,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, device, shaderModule, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyShaderModule_PostCall(manager->GetBlockIndex() - 1, device, shaderModule, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPipelineCacheCreateInfo*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPipelineCache*                        pPipelineCache)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPipelineCache);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePipelineCache_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pPipelineCache);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, device, pipelineCache, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipelineCache_PostCall(manager->GetBlockIndex() - 1, device, pipelineCache, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, result, device, pipelineCache, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineCacheData_PostCall(manager->GetBlockIndex() - 1, result, device, pipelineCache, pDataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipelineCache                         dstCache,
        uint32_t                                srcCacheCount,
        const VkPipelineCache*                  pSrcCaches)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, result, device, dstCache, srcCacheCount, pSrcCaches);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MergePipelineCaches_PostCall(manager->GetBlockIndex() - 1, result, device, dstCache, srcCacheCount, pSrcCaches);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkGraphicsPipelineCreateInfo*     pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGraphicsPipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateGraphicsPipelines_PostCall(manager->GetBlockIndex() - 1, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkComputePipelineCreateInfo*      pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkComputePipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateComputePipelines_PostCall(manager->GetBlockIndex() - 1, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, device, pipeline, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipeline_PostCall(manager->GetBlockIndex() - 1, device, pipeline, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPipelineLayoutCreateInfo*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPipelineLayout*                       pPipelineLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPipelineLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePipelineLayout_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pPipelineLayout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineLayout                        pipelineLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, device, pipelineLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipelineLayout_PostCall(manager->GetBlockIndex() - 1, device, pipelineLayout, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSamplerCreateInfo*              pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSampler*                              pSampler)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSampler);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSamplerCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSampler_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pSampler);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSampler                               sampler,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, device, sampler, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySampler_PostCall(manager->GetBlockIndex() - 1, device, sampler, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorSetLayout*                  pSetLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSetLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorSetLayout_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pSetLayout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorSetLayout                   descriptorSetLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, device, descriptorSetLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorSetLayout_PostCall(manager->GetBlockIndex() - 1, device, descriptorSetLayout, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDescriptorPoolCreateInfo*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorPool*                       pDescriptorPool)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorPool_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pDescriptorPool);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, device, descriptorPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorPool_PostCall(manager->GetBlockIndex() - 1, device, descriptorPool, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        VkDescriptorPoolResetFlags              flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, result, device, descriptorPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetDescriptorPool_PostCall(manager->GetBlockIndex() - 1, result, device, descriptorPool, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDescriptorSetAllocateInfo*      pAllocateInfo,
        VkDescriptorSet*                        pDescriptorSets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, result, device, pAllocateInfo, pDescriptorSets);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateDescriptorSets_PostCall(manager->GetBlockIndex() - 1, result, device, pAllocateInfo, pDescriptorSets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        uint32_t                                descriptorSetCount,
        const VkDescriptorSet*                  pDescriptorSets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeDescriptorSets_PostCall(manager->GetBlockIndex() - 1, result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                descriptorWriteCount,
        const VkWriteDescriptorSet*             pDescriptorWrites,
        uint32_t                                descriptorCopyCount,
        const VkCopyDescriptorSet*              pDescriptorCopies)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);
    const VkCopyDescriptorSet* pDescriptorCopies_unwrapped = UnwrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateDescriptorSets_PostCall(manager->GetBlockIndex() - 1, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkFramebufferCreateInfo*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFramebuffer*                          pFramebuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pFramebuffer);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFramebufferCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateFramebuffer_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pFramebuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFramebuffer                           framebuffer,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, device, framebuffer, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyFramebuffer_PostCall(manager->GetBlockIndex() - 1, device, framebuffer, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkRenderPassCreateInfo*           pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkRenderPass                            renderPass,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, device, renderPass, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyRenderPass_PostCall(manager->GetBlockIndex() - 1, device, renderPass, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkRenderPass                            renderPass,
        VkExtent2D*                             pGranularity)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, device, renderPass, pGranularity);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRenderAreaGranularity_PostCall(manager->GetBlockIndex() - 1, device, renderPass, pGranularity);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkCommandPoolCreateInfo*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkCommandPool*                          pCommandPool)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pCommandPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateCommandPool_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pCommandPool);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, device, commandPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyCommandPool_PostCall(manager->GetBlockIndex() - 1, device, commandPool, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolResetFlags                 flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, result, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetCommandPool_PostCall(manager->GetBlockIndex() - 1, result, device, commandPool, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkCommandBufferAllocateInfo*      pAllocateInfo,
        VkCommandBuffer*                        pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, result, device, pAllocateInfo, pCommandBuffers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCommandBufferAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateCommandBuffers_PostCall(manager->GetBlockIndex() - 1, result, device, pAllocateInfo, pCommandBuffers);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        uint32_t                                commandBufferCount,
        const VkCommandBuffer*                  pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, device, commandPool, commandBufferCount, pCommandBuffers);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeCommandBuffers_PostCall(manager->GetBlockIndex() - 1, device, commandPool, commandBufferCount, pCommandBuffers);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer,
        const VkCommandBufferBeginInfo*         pBeginInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, result, commandBuffer, pBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCommandBufferBeginInfo* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BeginCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer, pBeginInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, result, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EndCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer,
        VkCommandBufferResetFlags               flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, result, commandBuffer, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipeline                              pipeline)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindPipeline_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineBindPoint, pipeline);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewport_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstViewport, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstScissor,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, commandBuffer, firstScissor, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissor_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstScissor, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   lineWidth)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, commandBuffer, lineWidth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineWidth_PostCall(manager->GetBlockIndex() - 1, commandBuffer, lineWidth);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   depthBiasConstantFactor,
        float                                   depthBiasClamp,
        float                                   depthBiasSlopeFactor)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBias_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const float                             blendConstants[4])
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, commandBuffer, blendConstants);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetBlendConstants_PostCall(manager->GetBlockIndex() - 1, commandBuffer, blendConstants);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   minDepthBounds,
        float                                   maxDepthBounds)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, commandBuffer, minDepthBounds, maxDepthBounds);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBounds_PostCall(manager->GetBlockIndex() - 1, commandBuffer, minDepthBounds, maxDepthBounds);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                compareMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, commandBuffer, faceMask, compareMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilCompareMask_PostCall(manager->GetBlockIndex() - 1, commandBuffer, faceMask, compareMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                writeMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, commandBuffer, faceMask, writeMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilWriteMask_PostCall(manager->GetBlockIndex() - 1, commandBuffer, faceMask, writeMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                reference)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, commandBuffer, faceMask, reference);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilReference_PostCall(manager->GetBlockIndex() - 1, commandBuffer, faceMask, reference);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipelineLayout                        layout,
        uint32_t                                firstSet,
        uint32_t                                descriptorSetCount,
        const VkDescriptorSet*                  pDescriptorSets,
        uint32_t                                dynamicOffsetCount,
        const uint32_t*                         pDynamicOffsets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindDescriptorSets_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkIndexType                             indexType)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, commandBuffer, buffer, offset, indexType);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindIndexBuffer_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, indexType);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstBinding,
        uint32_t                                bindingCount,
        const VkBuffer*                         pBuffers,
        const VkDeviceSize*                     pOffsets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                vertexCount,
        uint32_t                                instanceCount,
        uint32_t                                firstVertex,
        uint32_t                                firstInstance)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDraw_PostCall(manager->GetBlockIndex() - 1, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                indexCount,
        uint32_t                                instanceCount,
        uint32_t                                firstIndex,
        int32_t                                 vertexOffset,
        uint32_t                                firstInstance)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexed_PostCall(manager->GetBlockIndex() - 1, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirect_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirect_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatch_PostCall(manager->GetBlockIndex() - 1, commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, commandBuffer, buffer, offset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchIndirect_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                srcBuffer,
        VkBuffer                                dstBuffer,
        uint32_t                                regionCount,
        const VkBufferCopy*                     pRegions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 srcImage,
        VkImageLayout                           srcImageLayout,
        VkImage                                 dstImage,
        VkImageLayout                           dstImageLayout,
        uint32_t                                regionCount,
        const VkImageCopy*                      pRegions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 srcImage,
        VkImageLayout                           srcImageLayout,
        VkImage                                 dstImage,
        VkImageLayout                           dstImageLayout,
        uint32_t                                regionCount,
        const VkImageBlit*                      pRegions,
        VkFilter                                filter)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                srcBuffer,
        VkImage                                 dstImage,
        VkImageLayout                           dstImageLayout,
        uint32_t                                regionCount,
        const VkBufferImageCopy*                pRegions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 srcImage,
        VkImageLayout                           srcImageLayout,
        VkBuffer                                dstBuffer,
        uint32_t                                regionCount,
        const VkBufferImageCopy*                pRegions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        VkDeviceSize                            dataSize,
        const void*                             pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdUpdateBuffer_PostCall(manager->GetBlockIndex() - 1, commandBuffer, dstBuffer, dstOffset, dataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        VkDeviceSize                            size,
        uint32_t                                data)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, size, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdFillBuffer_PostCall(manager->GetBlockIndex() - 1, commandBuffer, dstBuffer, dstOffset, size, data);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 image,
        VkImageLayout                           imageLayout,
        const VkClearColorValue*                pColor,
        uint32_t                                rangeCount,
        const VkImageSubresourceRange*          pRanges)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearColorImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 image,
        VkImageLayout                           imageLayout,
        const VkClearDepthStencilValue*         pDepthStencil,
        uint32_t                                rangeCount,
        const VkImageSubresourceRange*          pRanges)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearDepthStencilImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                attachmentCount,
        const VkClearAttachment*                pAttachments,
        uint32_t                                rectCount,
        const VkClearRect*                      pRects)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearAttachments_PostCall(manager->GetBlockIndex() - 1, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImage                                 srcImage,
        VkImageLayout                           srcImageLayout,
        VkImage                                 dstImage,
        VkImageLayout                           dstImageLayout,
        uint32_t                                regionCount,
        const VkImageResolve*                   pRegions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags                    stageMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags                    stageMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                eventCount,
        const VkEvent*                          pEvents,
        VkPipelineStageFlags                    srcStageMask,
        VkPipelineStageFlags                    dstStageMask,
        uint32_t                                memoryBarrierCount,
        const VkMemoryBarrier*                  pMemoryBarriers,
        uint32_t                                bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier*            pBufferMemoryBarriers,
        uint32_t                                imageMemoryBarrierCount,
        const VkImageMemoryBarrier*             pImageMemoryBarriers)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents_PostCall(manager->GetBlockIndex() - 1, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags                    srcStageMask,
        VkPipelineStageFlags                    dstStageMask,
        VkDependencyFlags                       dependencyFlags,
        uint32_t                                memoryBarrierCount,
        const VkMemoryBarrier*                  pMemoryBarriers,
        uint32_t                                bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier*            pBufferMemoryBarriers,
        uint32_t                                imageMemoryBarrierCount,
        const VkImageMemoryBarrier*             pImageMemoryBarriers)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier_PostCall(manager->GetBlockIndex() - 1, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        VkQueryControlFlags                     flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, commandBuffer, queryPool, query, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginQuery_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, query, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, commandBuffer, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndQuery_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, query);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetQueryPool_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, firstQuery, queryCount);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlagBits                 pipelineStage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, commandBuffer, pipelineStage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineStage, queryPool, query);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        VkDeviceSize                            stride,
        VkQueryResultFlags                      flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyQueryPoolResults_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineLayout                        layout,
        VkShaderStageFlags                      stageFlags,
        uint32_t                                offset,
        uint32_t                                size,
        const void*                             pValues)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, commandBuffer, layout, stageFlags, offset, size, pValues);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPushConstants_PostCall(manager->GetBlockIndex() - 1, commandBuffer, layout, stageFlags, offset, size, pValues);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        VkSubpassContents                       contents)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, commandBuffer, pRenderPassBegin, contents);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRenderPassBegin, contents);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSubpassContents                       contents)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, commandBuffer, contents);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass_PostCall(manager->GetBlockIndex() - 1, commandBuffer, contents);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                commandBufferCount,
        const VkCommandBuffer*                  pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, commandBuffer, commandBufferCount, pCommandBuffers);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdExecuteCommands_PostCall(manager->GetBlockIndex() - 1, commandBuffer, commandBufferCount, pCommandBuffers);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindBufferMemoryInfo*           pBindInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory2_PostCall(manager->GetBlockIndex() - 1, result, device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindImageMemoryInfo*            pBindInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory2_PostCall(manager->GetBlockIndex() - 1, result, device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                heapIndex,
        uint32_t                                localDeviceIndex,
        uint32_t                                remoteDeviceIndex,
        VkPeerMemoryFeatureFlags*               pPeerMemoryFeatures)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeatures_PostCall(manager->GetBlockIndex() - 1, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                deviceMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, commandBuffer, deviceMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDeviceMask_PostCall(manager->GetBlockIndex() - 1, commandBuffer, deviceMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                baseGroupX,
        uint32_t                                baseGroupY,
        uint32_t                                baseGroupZ,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchBase_PostCall(manager->GetBlockIndex() - 1, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceGroupCount,
        VkPhysicalDeviceGroupProperties*        pPhysicalDeviceGroupProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroups_PostCall(manager->GetBlockIndex() - 1, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageMemoryRequirementsInfo2*   pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferMemoryRequirementsInfo2*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageSparseMemoryRequirementsInfo2* pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures2*              pFeatures)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties2*            pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties2*                    pFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2*               pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties2*               pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties2*      pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
        uint32_t*                               pPropertyCount,
        VkSparseImageFormatProperties2*         pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolTrimFlags                  flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.TrimCommandPool_PostCall(manager->GetBlockIndex() - 1, device, commandPool, flags);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceQueueInfo2*               pQueueInfo,
        VkQueue*                                pQueue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, device, pQueueInfo, pQueue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceQueue2_PostCall(manager->GetBlockIndex() - 1, device, pQueueInfo, pQueue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSamplerYcbcrConversion*               pYcbcrConversion)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pYcbcrConversion);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSamplerYcbcrConversion_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pYcbcrConversion);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSamplerYcbcrConversion                ycbcrConversion,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, device, ycbcrConversion, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySamplerYcbcrConversion_PostCall(manager->GetBlockIndex() - 1, device, ycbcrConversion, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorUpdateTemplate*             pDescriptorUpdateTemplate)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorUpdateTemplate_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorUpdateTemplate              descriptorUpdateTemplate,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplate_PostCall(manager->GetBlockIndex() - 1, device, descriptorUpdateTemplate, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
        VkExternalBufferProperties*             pExternalBufferProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
        VkExternalFenceProperties*              pExternalFenceProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFenceProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
        VkExternalSemaphoreProperties*          pExternalSemaphoreProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphoreProperties_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        VkDescriptorSetLayoutSupport*           pSupport)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, device, pCreateInfo, pSupport);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupport_PostCall(manager->GetBlockIndex() - 1, device, pCreateInfo, pSupport);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCount_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCount_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkRenderPassCreateInfo2*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass2_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        const VkSubpassBeginInfo*               pSubpassBeginInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassBeginInfo*               pSubpassBeginInfo,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, commandBuffer, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, device, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetQueryPool_PostCall(manager->GetBlockIndex() - 1, device, queryPool, firstQuery, queryCount);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        uint64_t*                               pValue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, result, device, semaphore, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreCounterValue_PostCall(manager->GetBlockIndex() - 1, result, device, semaphore, pValue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreWaitInfo*              pWaitInfo,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, result, device, pWaitInfo, timeout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitSemaphores_PostCall(manager->GetBlockIndex() - 1, result, device, pWaitInfo, timeout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreSignalInfo*            pSignalInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, result, device, pSignalInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SignalSemaphore_PostCall(manager->GetBlockIndex() - 1, result, device, pSignalInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDeviceAddress                         result,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddress_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint64_t                                result,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddress_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint64_t                                result,
        VkDevice                                device,
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddress_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pToolCount,
        VkPhysicalDeviceToolProperties*         pToolProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, result, physicalDevice, pToolCount, pToolProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceToolProperties_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pToolCount, pToolProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPrivateDataSlotCreateInfo*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPrivateDataSlot*                      pPrivateDataSlot)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePrivateDataSlot_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPrivateDataSlot                       privateDataSlot,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, device, privateDataSlot, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPrivateDataSlot_PostCall(manager->GetBlockIndex() - 1, device, privateDataSlot, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t                                data)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, result, device, objectType, objectHandle, privateDataSlot, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetPrivateData_PostCall(manager->GetBlockIndex() - 1, result, device, objectType, objectHandle, privateDataSlot, data);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t*                               pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPrivateData_PostCall(manager->GetBlockIndex() - 1, device, objectType, objectHandle, privateDataSlot, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, commandBuffer, event, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags2                   stageMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                eventCount,
        const VkEvent*                          pEvents,
        const VkDependencyInfo*                 pDependencyInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, eventCount, pEvents, pDependencyInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, commandBuffer, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, commandBuffer, stage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stage, queryPool, query);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo2*                    pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSubmit2_PostCall(manager->GetBlockIndex() - 1, result, queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferInfo2*                pCopyBufferInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, commandBuffer, pCopyBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyBufferInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageInfo2*                 pCopyImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, commandBuffer, pCopyImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferToImageInfo2*         pCopyBufferToImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyBufferToImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageToBufferInfo2*         pCopyImageToBufferInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyImageToBufferInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkBlitImageInfo2*                 pBlitImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, commandBuffer, pBlitImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pBlitImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkResolveImageInfo2*              pResolveImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, commandBuffer, pResolveImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pResolveImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderingInfo*                  pRenderingInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, commandBuffer, pRenderingInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRendering_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRenderingInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRendering_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCullModeFlags                         cullMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, commandBuffer, cullMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCullMode_PostCall(manager->GetBlockIndex() - 1, commandBuffer, cullMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFrontFace                             frontFace)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, commandBuffer, frontFace);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFrontFace_PostCall(manager->GetBlockIndex() - 1, commandBuffer, frontFace);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPrimitiveTopology                     primitiveTopology)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, commandBuffer, primitiveTopology);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveTopology_PostCall(manager->GetBlockIndex() - 1, commandBuffer, primitiveTopology);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, commandBuffer, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWithCount_PostCall(manager->GetBlockIndex() - 1, commandBuffer, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, commandBuffer, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissorWithCount_PostCall(manager->GetBlockIndex() - 1, commandBuffer, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstBinding,
        uint32_t                                bindingCount,
        const VkBuffer*                         pBuffers,
        const VkDeviceSize*                     pOffsets,
        const VkDeviceSize*                     pSizes,
        const VkDeviceSize*                     pStrides)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers2_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, commandBuffer, depthTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthTestEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthWriteEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, commandBuffer, depthWriteEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthWriteEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthWriteEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCompareOp                             depthCompareOp)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, commandBuffer, depthCompareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthCompareOp_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthCompareOp);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBoundsTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthBoundsTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stencilTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, commandBuffer, stencilTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilTestEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stencilTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        VkStencilOp                             failOp,
        VkStencilOp                             passOp,
        VkStencilOp                             depthFailOp,
        VkCompareOp                             compareOp)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilOp_PostCall(manager->GetBlockIndex() - 1, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                rasterizerDiscardEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, rasterizerDiscardEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBiasEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, commandBuffer, depthBiasEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBiasEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthBiasEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                primitiveRestartEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, commandBuffer, primitiveRestartEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnable_PostCall(manager->GetBlockIndex() - 1, commandBuffer, primitiveRestartEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceBufferMemoryRequirements* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkSurfaceKHR                            surface,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, instance, surface, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySurfaceKHR_PostCall(manager->GetBlockIndex() - 1, instance, surface, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        VkSurfaceKHR                            surface,
        VkBool32*                               pSupported)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, surface, pSupported);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, surface, pSupported);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        VkSurfaceCapabilitiesKHR*               pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, surface, pSurfaceCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, surface, pSurfaceCapabilities);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pSurfaceFormatCount,
        VkSurfaceFormatKHR*                     pSurfaceFormats)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormatsKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pPresentModeCount,
        VkPresentModeKHR*                       pPresentModes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, result, physicalDevice, surface, pPresentModeCount, pPresentModes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, surface, pPresentModeCount, pPresentModes);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSwapchainCreateInfoKHR*         pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSwapchainKHR*                         pSwapchain)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSwapchain);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSwapchainCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSwapchainKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pSwapchain);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, device, swapchain, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySwapchainKHR_PostCall(manager->GetBlockIndex() - 1, device, swapchain, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint32_t*                               pSwapchainImageCount,
        VkImage*                                pSwapchainImages)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainImagesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, pSwapchainImageCount, pSwapchainImages);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint64_t                                timeout,
        VkSemaphore                             semaphore,
        VkFence                                 fence,
        uint32_t*                               pImageIndex)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, result, device, swapchain, timeout, semaphore, fence, pImageIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireNextImageKHR_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, timeout, semaphore, fence, pImageIndex);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        const VkPresentInfoKHR*                 pPresentInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, queue, pPresentInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueuePresentKHR_PostCall(manager->GetBlockIndex() - 1, result, queue, pPresentInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeviceGroupPresentCapabilitiesKHR*    pDeviceGroupPresentCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, result, device, pDeviceGroupPresentCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPresentCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pDeviceGroupPresentCapabilities);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSurfaceKHR                            surface,
        VkDeviceGroupPresentModeFlagsKHR*       pModes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, result, device, surface, pModes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, surface, pModes);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pRectCount,
        VkRect2D*                               pRects)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, result, physicalDevice, surface, pRectCount, pRects);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDevicePresentRectanglesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, surface, pRectCount, pRects);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkAcquireNextImageInfoKHR*        pAcquireInfo,
        uint32_t*                               pImageIndex)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, result, device, pAcquireInfo, pImageIndex);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAcquireNextImageInfoKHR* pAcquireInfo_unwrapped = UnwrapStructPtrHandles(pAcquireInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireNextImage2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, pAcquireInfo, pImageIndex);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPropertiesKHR*                 pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPlanePropertiesKHR*            pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                planeIndex,
        uint32_t*                               pDisplayCount,
        VkDisplayKHR*                           pDisplays)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneSupportedDisplaysKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, planeIndex, pDisplayCount, pDisplays);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        uint32_t*                               pPropertyCount,
        VkDisplayModePropertiesKHR*             pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, result, physicalDevice, display, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayModePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, display, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        const VkDisplayModeCreateInfoKHR*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDisplayModeKHR*                       pMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDisplayModeKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, display, pCreateInfo, pAllocator, pMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayModeKHR                        mode,
        uint32_t                                planeIndex,
        VkDisplayPlaneCapabilitiesKHR*          pCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, mode, planeIndex, pCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, mode, planeIndex, pCapabilities);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkDisplaySurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDisplaySurfaceCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDisplayPlaneSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                swapchainCount,
        const VkSwapchainCreateInfoKHR*         pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkSwapchainKHR*                         pSwapchains)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSwapchainCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, swapchainCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSharedSwapchainsKHR_PostCall(manager->GetBlockIndex() - 1, result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkXlibSurfaceCreateInfoKHR*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateXlibSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        Display*                                dpy,
        VisualID                                visualID)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, dpy, visualID);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, dpy, visualID);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkXcbSurfaceCreateInfoKHR*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateXcbSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        xcb_connection_t*                       connection,
        xcb_visualid_t                          visual_id)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, connection, visual_id);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, connection, visual_id);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkWaylandSurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateWaylandSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        struct wl_display*                      display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, display);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkAndroidSurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAndroidSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkWin32SurfaceCreateInfoKHR*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateWin32SurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkVideoProfileInfoKHR*            pVideoProfile,
        VkVideoCapabilitiesKHR*                 pCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, result, physicalDevice, pVideoProfile, pCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pVideoProfile, pCapabilities);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo,
        uint32_t*                               pVideoFormatPropertyCount,
        VkVideoFormatPropertiesKHR*             pVideoFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkVideoSessionCreateInfoKHR*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkVideoSessionKHR*                      pVideoSession)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pVideoSession);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateVideoSessionKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pVideoSession);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, device, videoSession, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyVideoSessionKHR_PostCall(manager->GetBlockIndex() - 1, device, videoSession, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        uint32_t*                               pMemoryRequirementsCount,
        VkVideoSessionMemoryRequirementsKHR*    pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetVideoSessionMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        uint32_t                                bindSessionMemoryInfoCount,
        const VkBindVideoSessionMemoryInfoKHR*  pBindSessionMemoryInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos_unwrapped = UnwrapStructArrayHandles(pBindSessionMemoryInfos, bindSessionMemoryInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindVideoSessionMemoryKHR_PostCall(manager->GetBlockIndex() - 1, result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkVideoSessionParametersKHR*            pVideoSessionParameters)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pVideoSessionParameters);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoSessionParametersCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pVideoSessionParameters);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkVideoSessionParametersKHR             videoSessionParameters,
        const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, result, device, videoSessionParameters, pUpdateInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, result, device, videoSessionParameters, pUpdateInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionParametersKHR             videoSessionParameters,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, device, videoSessionParameters, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoBeginCodingInfoKHR*        pBeginInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, commandBuffer, pBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoBeginCodingInfoKHR* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pBeginInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoEndCodingInfoKHR*          pEndCodingInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, commandBuffer, pEndCodingInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pEndCodingInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoCodingControlInfoKHR*      pCodingControlInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, commandBuffer, pCodingControlInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdControlVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCodingControlInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoDecodeInfoKHR*             pDecodeInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, commandBuffer, pDecodeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoDecodeInfoKHR* pDecodeInfo_unwrapped = UnwrapStructPtrHandles(pDecodeInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDecodeVideoKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pDecodeInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderingInfo*                  pRenderingInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, commandBuffer, pRenderingInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderingKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRenderingInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderingKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures2*              pFeatures)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties2*            pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties2*                    pFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2*               pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties2*               pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties2*      pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
        uint32_t*                               pPropertyCount,
        VkSparseImageFormatProperties2*         pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                heapIndex,
        uint32_t                                localDeviceIndex,
        uint32_t                                remoteDeviceIndex,
        VkPeerMemoryFeatureFlags*               pPeerMemoryFeatures)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(manager->GetBlockIndex() - 1, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                deviceMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, commandBuffer, deviceMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDeviceMaskKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, deviceMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                baseGroupX,
        uint32_t                                baseGroupY,
        uint32_t                                baseGroupZ,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchBaseKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolTrimFlags                  flags)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.TrimCommandPoolKHR_PostCall(manager->GetBlockIndex() - 1, device, commandPool, flags);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceGroupCount,
        VkPhysicalDeviceGroupProperties*        pPhysicalDeviceGroupProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroupsKHR_PostCall(manager->GetBlockIndex() - 1, result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
        VkExternalBufferProperties*             pExternalBufferProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryGetWin32HandleInfoKHR*    pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetWin32HandleInfo, pHandle);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        HANDLE                                  handle,
        VkMemoryWin32HandlePropertiesKHR*       pMemoryWin32HandleProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, result, device, handleType, handle, pMemoryWin32HandleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandlePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, handleType, handle, pMemoryWin32HandleProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryGetFdInfoKHR*             pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryFdKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetFdInfo, pFd);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        int                                     fd,
        VkMemoryFdPropertiesKHR*                pMemoryFdProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, result, device, handleType, fd, pMemoryFdProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryFdPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, handleType, fd, pMemoryFdProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
        VkExternalSemaphoreProperties*          pExternalSemaphoreProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, result, device, pImportSemaphoreWin32HandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pImportSemaphoreWin32HandleInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetWin32HandleInfo, pHandle);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImportSemaphoreFdInfoKHR*       pImportSemaphoreFdInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, result, device, pImportSemaphoreFdInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreFdKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pImportSemaphoreFdInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreGetFdInfoKHR*          pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreFdKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetFdInfo, pFd);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipelineLayout                        layout,
        uint32_t                                set,
        uint32_t                                descriptorWriteCount,
        const VkWriteDescriptorSet*             pDescriptorWrites)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPushDescriptorSetKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorUpdateTemplate*             pDescriptorUpdateTemplate)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorUpdateTemplateKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorUpdateTemplate              descriptorUpdateTemplate,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplateKHR_PostCall(manager->GetBlockIndex() - 1, device, descriptorUpdateTemplate, pAllocator);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkRenderPassCreateInfo2*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        const VkSubpassBeginInfo*               pSubpassBeginInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassBeginInfo*               pSubpassBeginInfo,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, commandBuffer, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pSubpassEndInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, result, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainStatusKHR_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
        VkExternalFenceProperties*              pExternalFenceProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImportFenceWin32HandleInfoKHR*  pImportFenceWin32HandleInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, result, device, pImportFenceWin32HandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportFenceWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pImportFenceWin32HandleInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkFenceGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, result, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetWin32HandleInfo, pHandle);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImportFenceFdInfoKHR*           pImportFenceFdInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, result, device, pImportFenceFdInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportFenceFdInfoKHR* pImportFenceFdInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportFenceFdKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pImportFenceFdInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkFenceGetFdInfoKHR*              pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, result, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFenceGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceFdKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pGetFdInfo, pFd);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        uint32_t*                               pCounterCount,
        VkPerformanceCounterKHR*                pCounters,
        VkPerformanceCounterDescriptionKHR*     pCounterDescriptions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo,
        uint32_t*                               pNumPasses)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(manager->GetBlockIndex() - 1, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkAcquireProfilingLockInfoKHR*    pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, result, device, pInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireProfilingLockKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseProfilingLockKHR_PostCall(manager->GetBlockIndex() - 1, device);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        VkSurfaceCapabilities2KHR*              pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        uint32_t*                               pSurfaceFormatCount,
        VkSurfaceFormat2KHR*                    pSurfaceFormats)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormats2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayProperties2KHR*                pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPlaneProperties2KHR*           pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        uint32_t*                               pPropertyCount,
        VkDisplayModeProperties2KHR*            pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, result, physicalDevice, display, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayModeProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, display, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkDisplayPlaneInfo2KHR*           pDisplayPlaneInfo,
        VkDisplayPlaneCapabilities2KHR*         pCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo_unwrapped = UnwrapStructPtrHandles(pDisplayPlaneInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneCapabilities2KHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pDisplayPlaneInfo, pCapabilities);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageMemoryRequirementsInfo2*   pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferMemoryRequirementsInfo2*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageSparseMemoryRequirementsInfo2* pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSamplerYcbcrConversion*               pYcbcrConversion)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pYcbcrConversion);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSamplerYcbcrConversionKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pYcbcrConversion);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSamplerYcbcrConversion                ycbcrConversion,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, device, ycbcrConversion, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySamplerYcbcrConversionKHR_PostCall(manager->GetBlockIndex() - 1, device, ycbcrConversion, pAllocator);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindBufferMemoryInfo*           pBindInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindImageMemoryInfo*            pBindInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, bindInfoCount, pBindInfos);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        VkDescriptorSetLayoutSupport*           pSupport)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, device, pCreateInfo, pSupport);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupportKHR_PostCall(manager->GetBlockIndex() - 1, device, pCreateInfo, pSupport);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCountKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        uint64_t*                               pValue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, result, device, semaphore, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreCounterValueKHR_PostCall(manager->GetBlockIndex() - 1, result, device, semaphore, pValue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreWaitInfo*              pWaitInfo,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, result, device, pWaitInfo, timeout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitSemaphoresKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pWaitInfo, timeout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreSignalInfo*            pSignalInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, result, device, pSignalInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SignalSemaphoreKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pSignalInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pFragmentShadingRateCount,
        VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkExtent2D*                       pFragmentSize,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2])
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, commandBuffer, pFragmentSize, combinerOps);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFragmentShadingRateKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pFragmentSize, combinerOps);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint64_t                                presentId,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, result, device, swapchain, presentId, timeout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitForPresentKHR_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, presentId, timeout);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDeviceAddress                         result,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddressKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint64_t                                result,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddressKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint64_t                                result,
        VkDevice                                device,
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkAllocationCallbacks*            pAllocator,
        VkDeferredOperationKHR*                 pDeferredOperation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, result, device, pAllocator, pDeferredOperation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDeferredOperationKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pAllocator, pDeferredOperation);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, device, operation, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDeferredOperationKHR_PostCall(manager->GetBlockIndex() - 1, device, operation, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint32_t                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, result, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeferredOperationMaxConcurrencyKHR_PostCall(manager->GetBlockIndex() - 1, result, device, operation);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, result, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeferredOperationResultKHR_PostCall(manager->GetBlockIndex() - 1, result, device, operation);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, result, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DeferredOperationJoinKHR_PostCall(manager->GetBlockIndex() - 1, result, device, operation);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPipelineInfoKHR*                pPipelineInfo,
        uint32_t*                               pExecutableCount,
        VkPipelineExecutablePropertiesKHR*      pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, result, device, pPipelineInfo, pExecutableCount, pProperties);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineInfoKHR* pPipelineInfo_unwrapped = UnwrapStructPtrHandles(pPipelineInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutablePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pPipelineInfo, pExecutableCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPipelineExecutableInfoKHR*      pExecutableInfo,
        uint32_t*                               pStatisticCount,
        VkPipelineExecutableStatisticKHR*       pStatistics)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, result, device, pExecutableInfo, pStatisticCount, pStatistics);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutableStatisticsKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pExecutableInfo, pStatisticCount, pStatistics);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPipelineExecutableInfoKHR*      pExecutableInfo,
        uint32_t*                               pInternalRepresentationCount,
        VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutableInternalRepresentationsKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryMapInfoKHR*               pMemoryMapInfo,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory2KHR>::Dispatch(manager, result, device, pMemoryMapInfo, ppData);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryMapInfoKHR* pMemoryMapInfo_unwrapped = UnwrapStructPtrHandles(pMemoryMapInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MapMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, pMemoryMapInfo, ppData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryUnmapInfoKHR*             pMemoryUnmapInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory2KHR>::Dispatch(manager, result, device, pMemoryUnmapInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo_unwrapped = UnwrapStructPtrHandles(pMemoryUnmapInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UnmapMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, device, pMemoryUnmapInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoEncodeInfoKHR*             pEncodeInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, commandBuffer, pEncodeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoEncodeInfoKHR* pEncodeInfo_unwrapped = UnwrapStructPtrHandles(pEncodeInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEncodeVideoKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pEncodeInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, commandBuffer, event, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags2                   stageMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                eventCount,
        const VkEvent*                          pEvents,
        const VkDependencyInfo*                 pDependencyInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, eventCount, pEvents, pDependencyInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, commandBuffer, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, commandBuffer, stage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stage, queryPool, query);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo2*                    pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSubmit2KHR_PostCall(manager->GetBlockIndex() - 1, result, queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        uint32_t                                marker)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, commandBuffer, stage, dstBuffer, dstOffset, marker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteBufferMarker2AMD_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stage, dstBuffer, dstOffset, marker);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t*                               pCheckpointDataCount,
        VkCheckpointData2NV*                    pCheckpointData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueueCheckpointData2NV_PostCall(manager->GetBlockIndex() - 1, queue, pCheckpointDataCount, pCheckpointData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferInfo2*                pCopyBufferInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyBufferInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageInfo2*                 pCopyImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, commandBuffer, pCopyImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferToImageInfo2*         pCopyBufferToImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyBufferToImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageToBufferInfo2*         pCopyImageToBufferInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCopyImageToBufferInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkBlitImageInfo2*                 pBlitImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, commandBuffer, pBlitImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pBlitImageInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkResolveImageInfo2*              pResolveImageInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, commandBuffer, pResolveImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pResolveImageInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkDeviceAddress                         indirectDeviceAddress)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, commandBuffer, indirectDeviceAddress);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysIndirect2KHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, indirectDeviceAddress);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceBufferMemoryRequirements* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDebugReportCallbackEXT*               pCallback)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pCallback);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDebugReportCallbackEXT_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pCallback);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugReportCallbackEXT                callback,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, instance, callback, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDebugReportCallbackEXT_PostCall(manager->GetBlockIndex() - 1, instance, callback, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugReportFlagsEXT                   flags,
        VkDebugReportObjectTypeEXT              objectType,
        uint64_t                                object,
        size_t                                  location,
        int32_t                                 messageCode,
        const char*                             pLayerPrefix,
        const char*                             pMessage)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugReportMessageEXT_PostCall(manager->GetBlockIndex() - 1, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDebugMarkerObjectTagInfoEXT*    pTagInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, result, device, pTagInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugMarkerObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugMarkerSetObjectTagEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pTagInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDebugMarkerObjectNameInfoEXT*   pNameInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, result, device, pNameInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugMarkerObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugMarkerSetObjectNameEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pNameInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugMarkerMarkerInfoEXT*       pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerBeginEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerEndEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugMarkerMarkerInfoEXT*       pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerInsertEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pMarkerInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstBinding,
        uint32_t                                bindingCount,
        const VkBuffer*                         pBuffers,
        const VkDeviceSize*                     pOffsets,
        const VkDeviceSize*                     pSizes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindTransformFeedbackBuffersEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstCounterBuffer,
        uint32_t                                counterBufferCount,
        const VkBuffer*                         pCounterBuffers,
        const VkDeviceSize*                     pCounterBufferOffsets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginTransformFeedbackEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstCounterBuffer,
        uint32_t                                counterBufferCount,
        const VkBuffer*                         pCounterBuffers,
        const VkDeviceSize*                     pCounterBufferOffsets)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndTransformFeedbackEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        VkQueryControlFlags                     flags,
        uint32_t                                index)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, flags, index);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginQueryIndexedEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, query, flags, index);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        uint32_t                                index)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, index);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndQueryIndexedEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, queryPool, query, index);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                instanceCount,
        uint32_t                                firstInstance,
        VkBuffer                                counterBuffer,
        VkDeviceSize                            counterBufferOffset,
        uint32_t                                counterOffset,
        uint32_t                                vertexStride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectByteCountEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        uint32_t                                result,
        VkDevice                                device,
        const VkImageViewHandleInfoNVX*         pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageViewHandleInfoNVX* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageViewHandleNVX_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkImageView                             imageView,
        VkImageViewAddressPropertiesNVX*        pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, result, device, imageView, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageViewAddressNVX_PostCall(manager->GetBlockIndex() - 1, result, device, imageView, pProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCountAMD_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountAMD_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        VkShaderStageFlagBits                   shaderStage,
        VkShaderInfoTypeAMD                     infoType,
        size_t*                                 pInfoSize,
        void*                                   pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderInfoAMD_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateStreamDescriptorSurfaceGGP_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkImageType                             type,
        VkImageTiling                           tiling,
        VkImageUsageFlags                       usage,
        VkImageCreateFlags                      flags,
        VkExternalMemoryHandleTypeFlagsNV       externalHandleType,
        VkExternalImageFormatPropertiesNV*      pExternalImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkExternalMemoryHandleTypeFlagsNV       handleType,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, result, device, memory, handleType, pHandle);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandleNV_PostCall(manager->GetBlockIndex() - 1, result, device, memory, handleType, pHandle);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkViSurfaceCreateInfoNN*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateViSurfaceNN_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, commandBuffer, pConditionalRenderingBegin);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin_unwrapped = UnwrapStructPtrHandles(pConditionalRenderingBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginConditionalRenderingEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pConditionalRenderingBegin);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndConditionalRenderingEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewportWScalingNV*             pViewportWScalings)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportWScalings);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWScalingNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstViewport, viewportCount, pViewportWScalings);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, result, physicalDevice, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, display);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        Display*                                dpy,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, result, physicalDevice, dpy, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireXlibDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, dpy, display);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        Display*                                dpy,
        RROutput                                rrOutput,
        VkDisplayKHR*                           pDisplay)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, result, physicalDevice, dpy, rrOutput, pDisplay);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRandROutputDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, dpy, rrOutput, pDisplay);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        VkSurfaceCapabilities2EXT*              pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, result, physicalDevice, surface, pSurfaceCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, surface, pSurfaceCapabilities);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDisplayKHR                            display,
        const VkDisplayPowerInfoEXT*            pDisplayPowerInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, result, device, display, pDisplayPowerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DisplayPowerControlEXT_PostCall(manager->GetBlockIndex() - 1, result, device, display, pDisplayPowerInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDeviceEventInfoEXT*             pDeviceEventInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, result, device, pDeviceEventInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.RegisterDeviceEventEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pDeviceEventInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDisplayKHR                            display,
        const VkDisplayEventInfoEXT*            pDisplayEventInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, result, device, display, pDisplayEventInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.RegisterDisplayEventEXT_PostCall(manager->GetBlockIndex() - 1, result, device, display, pDisplayEventInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        VkSurfaceCounterFlagBitsEXT             counter,
        uint64_t*                               pCounterValue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, result, device, swapchain, counter, pCounterValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainCounterEXT_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, counter, pCounterValue);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        VkRefreshCycleDurationGOOGLE*           pDisplayTimingProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, result, device, swapchain, pDisplayTimingProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRefreshCycleDurationGOOGLE_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, pDisplayTimingProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint32_t*                               pPresentationTimingCount,
        VkPastPresentationTimingGOOGLE*         pPresentationTimings)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPastPresentationTimingGOOGLE_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain, pPresentationTimingCount, pPresentationTimings);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstDiscardRectangle,
        uint32_t                                discardRectangleCount,
        const VkRect2D*                         pDiscardRectangles)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                discardRectangleEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, commandBuffer, discardRectangleEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, discardRectangleEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkDiscardRectangleModeEXT               discardRectangleMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, commandBuffer, discardRectangleMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, discardRectangleMode);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                swapchainCount,
        const VkSwapchainKHR*                   pSwapchains,
        const VkHdrMetadataEXT*                 pMetadata)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, device, swapchainCount, pSwapchains, pMetadata);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetHdrMetadataEXT_PostCall(manager->GetBlockIndex() - 1, device, swapchainCount, pSwapchains, pMetadata);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkIOSSurfaceCreateInfoMVK*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateIOSSurfaceMVK_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkMacOSSurfaceCreateInfoMVK*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMacOSSurfaceMVK_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDebugUtilsObjectNameInfoEXT*    pNameInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, device, pNameInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugUtilsObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDebugUtilsObjectNameEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pNameInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkDebugUtilsObjectTagInfoEXT*     pTagInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, result, device, pTagInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugUtilsObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDebugUtilsObjectTagEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pTagInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueBeginDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, queue, pLabelInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, queue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueEndDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, queue);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueInsertDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, queue, pLabelInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pLabelInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdInsertDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pLabelInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDebugUtilsMessengerEXT*               pMessenger)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pMessenger);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDebugUtilsMessengerEXT_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pMessenger);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugUtilsMessengerEXT                messenger,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, instance, messenger, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDebugUtilsMessengerEXT_PostCall(manager->GetBlockIndex() - 1, instance, messenger, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT  messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT         messageTypes,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, pCallbackData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SubmitDebugUtilsMessageEXT_PostCall(manager->GetBlockIndex() - 1, instance, messageSeverity, messageTypes, pCallbackData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const struct AHardwareBuffer*           buffer,
        VkAndroidHardwareBufferPropertiesANDROID* pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, result, device, buffer, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAndroidHardwareBufferPropertiesANDROID_PostCall(manager->GetBlockIndex() - 1, result, device, buffer, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
        struct AHardwareBuffer**                pBuffer)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, result, device, pInfo, pBuffer);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryAndroidHardwareBufferANDROID_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo, pBuffer);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSampleLocationsInfoEXT*         pSampleLocationsInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, commandBuffer, pSampleLocationsInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleLocationsEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pSampleLocationsInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSampleCountFlagBits                   samples,
        VkMultisamplePropertiesEXT*             pMultisampleProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, physicalDevice, samples, pMultisampleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(manager->GetBlockIndex() - 1, physicalDevice, samples, pMultisampleProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkImage                                 image,
        VkImageDrmFormatModifierPropertiesEXT*  pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, result, device, image, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageDrmFormatModifierPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, device, image, pProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkValidationCacheCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkValidationCacheEXT*                   pValidationCache)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pValidationCache);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateValidationCacheEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pValidationCache);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkValidationCacheEXT                    validationCache,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, device, validationCache, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyValidationCacheEXT_PostCall(manager->GetBlockIndex() - 1, device, validationCache, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkValidationCacheEXT                    dstCache,
        uint32_t                                srcCacheCount,
        const VkValidationCacheEXT*             pSrcCaches)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, result, device, dstCache, srcCacheCount, pSrcCaches);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MergeValidationCachesEXT_PostCall(manager->GetBlockIndex() - 1, result, device, dstCache, srcCacheCount, pSrcCaches);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkValidationCacheEXT                    validationCache,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, result, device, validationCache, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetValidationCacheDataEXT_PostCall(manager->GetBlockIndex() - 1, result, device, validationCache, pDataSize, pData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImageView                             imageView,
        VkImageLayout                           imageLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, commandBuffer, imageView, imageLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindShadingRateImageNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, imageView, imageLayout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkShadingRatePaletteNV*           pShadingRatePalettes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportShadingRatePaletteNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoarseSampleOrderTypeNV               sampleOrderType,
        uint32_t                                customSampleOrderCount,
        const VkCoarseSampleOrderCustomNV*      pCustomSampleOrders)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoarseSampleOrderNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkAccelerationStructureCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkAccelerationStructureNV*              pAccelerationStructure)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pAccelerationStructure);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pAccelerationStructure);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureNV               accelerationStructure,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, device, accelerationStructure, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, device, accelerationStructure, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
        VkMemoryRequirements2KHR*               pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureMemoryRequirementsNV_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, result, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindAccelerationStructureMemoryInfoNV* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindAccelerationStructureMemoryNV_PostCall(manager->GetBlockIndex() - 1, result, device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkAccelerationStructureInfoNV*    pInfo,
        VkBuffer                                instanceData,
        VkDeviceSize                            instanceOffset,
        VkBool32                                update,
        VkAccelerationStructureNV               dst,
        VkAccelerationStructureNV               src,
        VkBuffer                                scratch,
        VkDeviceSize                            scratchOffset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkAccelerationStructureNV               dst,
        VkAccelerationStructureNV               src,
        VkCopyAccelerationStructureModeKHR      mode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, commandBuffer, dst, src, mode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, dst, src, mode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                raygenShaderBindingTableBuffer,
        VkDeviceSize                            raygenShaderBindingOffset,
        VkBuffer                                missShaderBindingTableBuffer,
        VkDeviceSize                            missShaderBindingOffset,
        VkDeviceSize                            missShaderBindingStride,
        VkBuffer                                hitShaderBindingTableBuffer,
        VkDeviceSize                            hitShaderBindingOffset,
        VkDeviceSize                            hitShaderBindingStride,
        VkBuffer                                callableShaderBindingTableBuffer,
        VkDeviceSize                            callableShaderBindingOffset,
        VkDeviceSize                            callableShaderBindingStride,
        uint32_t                                width,
        uint32_t                                height,
        uint32_t                                depth)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRayTracingPipelineCreateInfoNV* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRayTracingPipelinesNV_PostCall(manager->GetBlockIndex() - 1, result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesNV_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkAccelerationStructureNV               accelerationStructure,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, result, device, accelerationStructure, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureHandleNV_PostCall(manager->GetBlockIndex() - 1, result, device, accelerationStructure, dataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                accelerationStructureCount,
        const VkAccelerationStructureNV*        pAccelerationStructures,
        VkQueryType                             queryType,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                shader)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, result, device, pipeline, shader);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CompileDeferredNV_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, shader);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        const void*                             pHostPointer,
        VkMemoryHostPointerPropertiesEXT*       pMemoryHostPointerProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryHostPointerPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, device, handleType, pHostPointer, pMemoryHostPointerProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlagBits                 pipelineStage,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        uint32_t                                marker)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteBufferMarkerAMD_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pTimeDomainCount,
        VkTimeDomainEXT*                        pTimeDomains)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, result, physicalDevice, pTimeDomainCount, pTimeDomains);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pTimeDomainCount, pTimeDomains);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                timestampCount,
        const VkCalibratedTimestampInfoEXT*     pTimestampInfos,
        uint64_t*                               pTimestamps,
        uint64_t*                               pMaxDeviation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetCalibratedTimestampsEXT_PostCall(manager->GetBlockIndex() - 1, result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                taskCount,
        uint32_t                                firstTask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, commandBuffer, taskCount, firstTask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, taskCount, firstTask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstExclusiveScissor,
        uint32_t                                exclusiveScissorCount,
        const VkBool32*                         pExclusiveScissorEnables)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExclusiveScissorEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstExclusiveScissor,
        uint32_t                                exclusiveScissorCount,
        const VkRect2D*                         pExclusiveScissors)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExclusiveScissorNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const void*                             pCheckpointMarker)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, commandBuffer, pCheckpointMarker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCheckpointNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pCheckpointMarker);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t*                               pCheckpointDataCount,
        VkCheckpointDataNV*                     pCheckpointData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueueCheckpointDataNV_PostCall(manager->GetBlockIndex() - 1, queue, pCheckpointDataCount, pCheckpointData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkInitializePerformanceApiInfoINTEL* pInitializeInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, result, device, pInitializeInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.InitializePerformanceApiINTEL_PostCall(manager->GetBlockIndex() - 1, result, device, pInitializeInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UninitializePerformanceApiINTEL_PostCall(manager->GetBlockIndex() - 1, device);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceMarkerInfoINTEL*     pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, result, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceMarkerINTEL_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, result, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceStreamMarkerINTEL_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceOverrideInfoINTEL*   pOverrideInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, result, commandBuffer, pOverrideInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceOverrideINTEL_PostCall(manager->GetBlockIndex() - 1, result, commandBuffer, pOverrideInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
        VkPerformanceConfigurationINTEL*        pConfiguration)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, result, device, pAcquireInfo, pConfiguration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquirePerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, device, pAcquireInfo, pConfiguration);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPerformanceConfigurationINTEL         configuration)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, result, device, configuration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleasePerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, device, configuration);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkQueue                                 queue,
        VkPerformanceConfigurationINTEL         configuration)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, result, queue, configuration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSetPerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, queue, configuration);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPerformanceParameterTypeINTEL         parameter,
        VkPerformanceValueINTEL*                pValue)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, result, device, parameter, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPerformanceParameterINTEL_PostCall(manager->GetBlockIndex() - 1, result, device, parameter, pValue);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapChain,
        VkBool32                                localDimmingEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, device, swapChain, localDimmingEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetLocalDimmingAMD_PostCall(manager->GetBlockIndex() - 1, device, swapChain, localDimmingEnable);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImagePipeSurfaceFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkMetalSurfaceCreateInfoEXT*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMetalSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDeviceAddress                         result,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddressEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pToolCount,
        VkPhysicalDeviceToolProperties*         pToolProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, result, physicalDevice, pToolCount, pToolProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceToolPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pToolCount, pToolProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkCooperativeMatrixPropertiesNV*        pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, result, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pPropertyCount, pProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pCombinationCount,
        VkFramebufferMixedSamplesCombinationNV* pCombinations)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, result, physicalDevice, pCombinationCount, pCombinations);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pCombinationCount, pCombinations);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        uint32_t*                               pPresentModeCount,
        VkPresentModeKHR*                       pPresentModes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, result, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireFullScreenExclusiveModeEXT_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, result, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseFullScreenExclusiveModeEXT_PostCall(manager->GetBlockIndex() - 1, result, device, swapchain);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        VkDeviceGroupPresentModeFlagsKHR*       pModes)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, result, device, pSurfaceInfo, pModes);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModes2EXT_PostCall(manager->GetBlockIndex() - 1, result, device, pSurfaceInfo, pModes);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkHeadlessSurfaceCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateHeadlessSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                lineStippleFactor,
        uint16_t                                lineStipplePattern)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, commandBuffer, lineStippleFactor, lineStipplePattern);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineStippleEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, lineStippleFactor, lineStipplePattern);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, device, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetQueryPoolEXT_PostCall(manager->GetBlockIndex() - 1, device, queryPool, firstQuery, queryCount);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCullModeFlags                         cullMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, commandBuffer, cullMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCullModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, cullMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFrontFace                             frontFace)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, commandBuffer, frontFace);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFrontFaceEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, frontFace);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPrimitiveTopology                     primitiveTopology)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, commandBuffer, primitiveTopology);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveTopologyEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, primitiveTopology);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, commandBuffer, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWithCountEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, commandBuffer, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissorWithCountEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstBinding,
        uint32_t                                bindingCount,
        const VkBuffer*                         pBuffers,
        const VkDeviceSize*                     pOffsets,
        const VkDeviceSize*                     pSizes,
        const VkDeviceSize*                     pStrides)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers2EXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, commandBuffer, depthTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthWriteEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, commandBuffer, depthWriteEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthWriteEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthWriteEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCompareOp                             depthCompareOp)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, commandBuffer, depthCompareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthCompareOpEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthCompareOp);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBoundsTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthBoundsTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stencilTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, commandBuffer, stencilTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stencilTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        VkStencilOp                             failOp,
        VkStencilOp                             passOp,
        VkStencilOp                             depthFailOp,
        VkCompareOp                             compareOp)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilOpEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkReleaseSwapchainImagesInfoEXT*  pReleaseInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, result, device, pReleaseInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo_unwrapped = UnwrapStructPtrHandles(pReleaseInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseSwapchainImagesEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pReleaseInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetGeneratedCommandsMemoryRequirementsNV_PostCall(manager->GetBlockIndex() - 1, device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkGeneratedCommandsInfoNV*        pGeneratedCommandsInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, commandBuffer, pGeneratedCommandsInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPreprocessGeneratedCommandsNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pGeneratedCommandsInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                isPreprocessed,
        const VkGeneratedCommandsInfoNV*        pGeneratedCommandsInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdExecuteGeneratedCommandsNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipeline                              pipeline,
        uint32_t                                groupIndex)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline, groupIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindPipelineShaderGroupNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineBindPoint, pipeline, groupIndex);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkIndirectCommandsLayoutNV*             pIndirectCommandsLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateIndirectCommandsLayoutNV_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkIndirectCommandsLayoutNV              indirectCommandsLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, device, indirectCommandsLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyIndirectCommandsLayoutNV_PostCall(manager->GetBlockIndex() - 1, device, indirectCommandsLayout, pAllocator);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        int32_t                                 drmFd,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, result, physicalDevice, drmFd, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireDrmDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, drmFd, display);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        int32_t                                 drmFd,
        uint32_t                                connectorId,
        VkDisplayKHR*                           display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, result, physicalDevice, drmFd, connectorId, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDrmDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, drmFd, connectorId, display);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkPrivateDataSlotCreateInfo*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPrivateDataSlot*                      pPrivateDataSlot)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePrivateDataSlotEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPrivateDataSlot                       privateDataSlot,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, device, privateDataSlot, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPrivateDataSlotEXT_PostCall(manager->GetBlockIndex() - 1, device, privateDataSlot, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t                                data)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, result, device, objectType, objectHandle, privateDataSlot, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetPrivateDataEXT_PostCall(manager->GetBlockIndex() - 1, result, device, objectType, objectHandle, privateDataSlot, data);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t*                               pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPrivateDataEXT_PostCall(manager->GetBlockIndex() - 1, device, objectType, objectHandle, privateDataSlot, pData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFragmentShadingRateNV                 shadingRate,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2])
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, commandBuffer, shadingRate, combinerOps);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFragmentShadingRateEnumNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, shadingRate, combinerOps);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkImageSubresource2EXT*           pSubresource,
        VkSubresourceLayout2EXT*                pLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, device, image, pSubresource, pLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSubresourceLayout2EXT_PostCall(manager->GetBlockIndex() - 1, device, image, pSubresource, pLayout);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeviceFaultCountsEXT*                 pFaultCounts,
        VkDeviceFaultInfoEXT*                   pFaultInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, result, device, pFaultCounts, pFaultInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceFaultInfoEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pFaultCounts, pFaultInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, result, physicalDevice, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireWinrtDisplayNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, display);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                deviceRelativeId,
        VkDisplayKHR*                           pDisplay)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, result, physicalDevice, deviceRelativeId, pDisplay);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetWinrtDisplayNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, deviceRelativeId, pDisplay);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkDirectFBSurfaceCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDirectFBSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        IDirectFB*                              dfb)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, dfb);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, dfb);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                vertexBindingDescriptionCount,
        const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
        uint32_t                                vertexAttributeDescriptionCount,
        const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetVertexInputEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
        zx_handle_t*                            pZirconHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, result, device, pGetZirconHandleInfo, pZirconHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, device, pGetZirconHandleInfo, pZirconHandle);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        zx_handle_t                             zirconHandle,
        VkMemoryZirconHandlePropertiesFUCHSIA*  pMemoryZirconHandleProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, device, pImportSemaphoreZirconHandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, device, pImportSemaphoreZirconHandleInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
        zx_handle_t*                            pZirconHandle)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, device, pGetZirconHandleInfo, pZirconHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, device, pGetZirconHandleInfo, pZirconHandle);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImageView                             imageView,
        VkImageLayout                           imageLayout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, commandBuffer, imageView, imageLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindInvocationMaskHUAWEI_PostCall(manager->GetBlockIndex() - 1, commandBuffer, imageView, imageLayout);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMemoryGetRemoteAddressInfoNV*   pMemoryGetRemoteAddressInfo,
        VkRemoteAddressNV*                      pAddress)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, result, device, pMemoryGetRemoteAddressInfo, pAddress);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo_unwrapped = UnwrapStructPtrHandles(pMemoryGetRemoteAddressInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryRemoteAddressNV_PostCall(manager->GetBlockIndex() - 1, result, device, pMemoryGetRemoteAddressInfo, pAddress);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                patchControlPoints)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, commandBuffer, patchControlPoints);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPatchControlPointsEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, patchControlPoints);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                rasterizerDiscardEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, rasterizerDiscardEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBiasEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, commandBuffer, depthBiasEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBiasEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthBiasEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkLogicOp                               logicOp)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, commandBuffer, logicOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLogicOpEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, logicOp);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                primitiveRestartEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, commandBuffer, primitiveRestartEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, primitiveRestartEnable);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkInstance                              instance,
        const VkScreenSurfaceCreateInfoQNX*     pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, result, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateScreenSurfaceQNX_PostCall(manager->GetBlockIndex() - 1, result, instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkBool32                                result,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        struct _screen_window*                  window)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, result, physicalDevice, queueFamilyIndex, window);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, queueFamilyIndex, window);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                attachmentCount,
        const VkBool32*                         pColorWriteEnables)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, commandBuffer, attachmentCount, pColorWriteEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorWriteEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, attachmentCount, pColorWriteEnables);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                drawCount,
        const VkMultiDrawInfoEXT*               pVertexInfo,
        uint32_t                                instanceCount,
        uint32_t                                firstInstance,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMultiEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                drawCount,
        const VkMultiDrawIndexedInfoEXT*        pIndexInfo,
        uint32_t                                instanceCount,
        uint32_t                                firstInstance,
        uint32_t                                stride,
        const int32_t*                          pVertexOffset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMultiIndexedEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkMicromapCreateInfoEXT*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkMicromapEXT*                          pMicromap)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pMicromap);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapCreateInfoEXT* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pMicromap);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkMicromapEXT                           micromap,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, device, micromap, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, device, micromap, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                infoCount,
        const VkMicromapBuildInfoEXT*           pInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, commandBuffer, infoCount, pInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildMicromapsEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, infoCount, pInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        uint32_t                                infoCount,
        const VkMicromapBuildInfoEXT*           pInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, result, device, deferredOperation, infoCount, pInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BuildMicromapsEXT_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, infoCount, pInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMicromapInfoEXT*            pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMicromapToMemoryInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMicromapToMemoryEXT_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMemoryToMicromapInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, result, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMemoryToMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                micromapCount,
        const VkMicromapEXT*                    pMicromaps,
        VkQueryType                             queryType,
        size_t                                  dataSize,
        void*                                   pData,
        size_t                                  stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WriteMicromapsPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMicromapInfoEXT*            pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMicromapToMemoryInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMicromapToMemoryEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMemoryToMicromapInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMemoryToMicromapEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                micromapCount,
        const VkMicromapEXT*                    pMicromaps,
        VkQueryType                             queryType,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteMicromapsPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMicromapVersionInfoEXT*         pVersionInfo,
        VkAccelerationStructureCompatibilityKHR* pCompatibility)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, device, pVersionInfo, pCompatibility);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMicromapCompatibilityEXT_PostCall(manager->GetBlockIndex() - 1, device, pVersionInfo, pCompatibility);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureBuildTypeKHR     buildType,
        const VkMicromapBuildInfoEXT*           pBuildInfo,
        VkMicromapBuildSizesInfoEXT*            pSizeInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, device, buildType, pBuildInfo, pSizeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMicromapBuildSizesEXT_PostCall(manager->GetBlockIndex() - 1, device, buildType, pBuildInfo, pSizeInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawClusterHUAWEI_PostCall(manager->GetBlockIndex() - 1, commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, commandBuffer, buffer, offset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawClusterIndirectHUAWEI_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        float                                   priority)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, device, memory, priority);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDeviceMemoryPriorityEXT_PostCall(manager->GetBlockIndex() - 1, device, memory, priority);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
        VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, device, pBindingReference, pHostMapping);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetBindingReferenceVALVE* pBindingReference_unwrapped = UnwrapStructPtrHandles(pBindingReference, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(manager->GetBlockIndex() - 1, device, pBindingReference, pHostMapping);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorSet                         descriptorSet,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, device, descriptorSet, ppData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetHostMappingVALVE_PostCall(manager->GetBlockIndex() - 1, device, descriptorSet, ppData);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkTessellationDomainOrigin              domainOrigin)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, commandBuffer, domainOrigin);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetTessellationDomainOriginEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, domainOrigin);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthClampEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, commandBuffer, depthClampEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClampEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthClampEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPolygonMode                           polygonMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, commandBuffer, polygonMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPolygonModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, polygonMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSampleCountFlagBits                   rasterizationSamples)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, commandBuffer, rasterizationSamples);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizationSamplesEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, rasterizationSamples);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSampleCountFlagBits                   samples,
        const VkSampleMask*                     pSampleMask)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, commandBuffer, samples, pSampleMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleMaskEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, samples, pSampleMask);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                alphaToCoverageEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, commandBuffer, alphaToCoverageEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetAlphaToCoverageEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, alphaToCoverageEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                alphaToOneEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, commandBuffer, alphaToOneEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetAlphaToOneEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, alphaToOneEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                logicOpEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, commandBuffer, logicOpEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLogicOpEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, logicOpEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkBool32*                         pColorBlendEnables)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorBlendEquationEXT*          pColorBlendEquations)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendEquationEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorComponentFlags*            pColorWriteMasks)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorWriteMaskEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                rasterizationStream)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, commandBuffer, rasterizationStream);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizationStreamEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, rasterizationStream);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkConservativeRasterizationModeEXT      conservativeRasterizationMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, commandBuffer, conservativeRasterizationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetConservativeRasterizationModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, conservativeRasterizationMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   extraPrimitiveOverestimationSize)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, commandBuffer, extraPrimitiveOverestimationSize);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, extraPrimitiveOverestimationSize);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthClipEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, commandBuffer, depthClipEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClipEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, depthClipEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                sampleLocationsEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, commandBuffer, sampleLocationsEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleLocationsEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, sampleLocationsEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorBlendAdvancedEXT*          pColorBlendAdvanced)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendAdvancedEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkProvokingVertexModeEXT                provokingVertexMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, commandBuffer, provokingVertexMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetProvokingVertexModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, provokingVertexMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkLineRasterizationModeEXT              lineRasterizationMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, commandBuffer, lineRasterizationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineRasterizationModeEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, lineRasterizationMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stippledLineEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, commandBuffer, stippledLineEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineStippleEnableEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stippledLineEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                negativeOneToOne)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, commandBuffer, negativeOneToOne);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClipNegativeOneToOneEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, negativeOneToOne);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                viewportWScalingEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, commandBuffer, viewportWScalingEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWScalingEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, viewportWScalingEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewportSwizzleNV*              pViewportSwizzles)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportSwizzles);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportSwizzleNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                coverageToColorEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, commandBuffer, coverageToColorEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageToColorEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageToColorEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                coverageToColorLocation)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, commandBuffer, coverageToColorLocation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageToColorLocationNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageToColorLocation);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoverageModulationModeNV              coverageModulationMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, commandBuffer, coverageModulationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationModeNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageModulationMode);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                coverageModulationTableEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, commandBuffer, coverageModulationTableEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationTableEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageModulationTableEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                coverageModulationTableCount,
        const float*                            pCoverageModulationTable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, commandBuffer, coverageModulationTableCount, pCoverageModulationTable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationTableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                shadingRateImageEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, commandBuffer, shadingRateImageEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetShadingRateImageEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, shadingRateImageEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                representativeFragmentTestEnable)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, commandBuffer, representativeFragmentTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRepresentativeFragmentTestEnableNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, representativeFragmentTestEnable);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoverageReductionModeNV               coverageReductionMode)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, commandBuffer, coverageReductionMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageReductionModeNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, coverageReductionMode);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderModule                          shaderModule,
        VkShaderModuleIdentifierEXT*            pIdentifier)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, device, shaderModule, pIdentifier);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderModuleIdentifierEXT_PostCall(manager->GetBlockIndex() - 1, device, shaderModule, pIdentifier);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkShaderModuleCreateInfo*         pCreateInfo,
        VkShaderModuleIdentifierEXT*            pIdentifier)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, device, pCreateInfo, pIdentifier);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderModuleCreateInfoIdentifierEXT_PostCall(manager->GetBlockIndex() - 1, device, pCreateInfo, pIdentifier);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkPhysicalDevice                        physicalDevice,
        const VkOpticalFlowImageFormatInfoNV*   pOpticalFlowImageFormatInfo,
        uint32_t*                               pFormatCount,
        VkOpticalFlowImageFormatPropertiesNV*   pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(manager->GetBlockIndex() - 1, result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkOpticalFlowSessionCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkOpticalFlowSessionNV*                 pSession)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pSession);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateOpticalFlowSessionNV_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pSession);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkOpticalFlowSessionNV                  session,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, device, session, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyOpticalFlowSessionNV_PostCall(manager->GetBlockIndex() - 1, device, session, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkOpticalFlowSessionNV                  session,
        VkOpticalFlowSessionBindingPointNV      bindingPoint,
        VkImageView                             view,
        VkImageLayout                           layout)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, result, device, session, bindingPoint, view, layout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindOpticalFlowSessionImageNV_PostCall(manager->GetBlockIndex() - 1, result, device, session, bindingPoint, view, layout);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkOpticalFlowSessionNV                  session,
        const VkOpticalFlowExecuteInfoNV*       pExecuteInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, commandBuffer, session, pExecuteInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdOpticalFlowExecuteNV_PostCall(manager->GetBlockIndex() - 1, commandBuffer, session, pExecuteInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateShadersEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                createInfoCount,
        const VkShaderCreateInfoEXT*            pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkShaderEXT*                            pShaders)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShadersEXT>::Dispatch(manager, result, device, createInfoCount, pCreateInfos, pAllocator, pShaders);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderCreateInfoEXT* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateShadersEXT_PostCall(manager->GetBlockIndex() - 1, result, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderEXT                             shader,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderEXT>::Dispatch(manager, device, shader, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyShaderEXT_PostCall(manager->GetBlockIndex() - 1, device, shader, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkShaderEXT                             shader,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT>::Dispatch(manager, result, device, shader, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderBinaryDataEXT_PostCall(manager->GetBlockIndex() - 1, result, device, shader, pDataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadersEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                stageCount,
        const VkShaderStageFlagBits*            pStages,
        const VkShaderEXT*                      pShaders)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadersEXT>::Dispatch(manager, commandBuffer, stageCount, pStages, pShaders);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindShadersEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, stageCount, pStages, pShaders);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkFramebuffer                           framebuffer,
        uint32_t*                               pPropertiesCount,
        VkTilePropertiesQCOM*                   pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, result, device, framebuffer, pPropertiesCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFramebufferTilePropertiesQCOM_PostCall(manager->GetBlockIndex() - 1, result, device, framebuffer, pPropertiesCount, pProperties);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkRenderingInfo*                  pRenderingInfo,
        VkTilePropertiesQCOM*                   pProperties)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, result, device, pRenderingInfo, pProperties);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDynamicRenderingTilePropertiesQCOM_PostCall(manager->GetBlockIndex() - 1, result, device, pRenderingInfo, pProperties);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkAccelerationStructureKHR*             pAccelerationStructure)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, result, device, pCreateInfo, pAllocator, pAccelerationStructure);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pCreateInfo, pAllocator, pAccelerationStructure);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureKHR              accelerationStructure,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, device, accelerationStructure, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, device, accelerationStructure, pAllocator);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                infoCount,
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                infoCount,
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkDeviceAddress*                  pIndirectDeviceAddresses,
        const uint32_t*                         pIndirectStrides,
        const uint32_t* const*                  ppMaxPrimitiveCounts)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresIndirectKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyAccelerationStructureToMemoryKHR_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMemoryToAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        uint32_t                                accelerationStructureCount,
        const VkAccelerationStructureKHR*       pAccelerationStructures,
        VkQueryType                             queryType,
        size_t                                  dataSize,
        void*                                   pData,
        size_t                                  stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WriteAccelerationStructuresPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureToMemoryKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMemoryToAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDeviceAddress                         result,
        VkDevice                                device,
        const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, result, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureDeviceAddressInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureDeviceAddressKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pInfo);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                accelerationStructureCount,
        const VkAccelerationStructureKHR*       pAccelerationStructures,
        VkQueryType                             queryType,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
        VkAccelerationStructureCompatibilityKHR* pCompatibility)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, device, pVersionInfo, pCompatibility);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceAccelerationStructureCompatibilityKHR_PostCall(manager->GetBlockIndex() - 1, device, pVersionInfo, pCompatibility);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureBuildTypeKHR     buildType,
        const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
        const uint32_t*                         pMaxPrimitiveCounts,
        VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureBuildSizesKHR_PostCall(manager->GetBlockIndex() - 1, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkStridedDeviceAddressRegionKHR*  pRaygenShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pMissShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pHitShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pCallableShaderBindingTable,
        uint32_t                                width,
        uint32_t                                height,
        uint32_t                                depth)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRayTracingPipelineCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRayTracingPipelinesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkResult                                result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, result, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkStridedDeviceAddressRegionKHR*  pRaygenShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pMissShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pHitShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR*  pCallableShaderBindingTable,
        VkDeviceAddress                         indirectDeviceAddress)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysIndirectKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDeviceSize                            result,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                group,
        VkShaderGroupShaderKHR                  groupShader)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, result, device, pipeline, group, groupShader);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupStackSizeKHR_PostCall(manager->GetBlockIndex() - 1, result, device, pipeline, group, groupShader);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                pipelineStackSize)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, commandBuffer, pipelineStackSize);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRayTracingPipelineStackSizeKHR_PostCall(manager->GetBlockIndex() - 1, commandBuffer, pipelineStackSize);
        }
    }
};


template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkBuffer                                countBuffer,
        VkDeviceSize                            countBufferOffset,
        uint32_t                                maxDrawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountEXT_PostCall(manager->GetBlockIndex() - 1, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_POST_COMMANDS_H
