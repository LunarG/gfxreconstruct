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

#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H

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
struct EncoderPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {}
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    static void Dispatch(VulkanCaptureManager* manager,
        const VkInstanceCreateInfo*             pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkInstance*                             pInstance)
    {
        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, pCreateInfo, pAllocator, pInstance);
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(manager, instance, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyInstance_PreCall(manager->GetBlockIndex(), instance, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceCount,
        VkPhysicalDevice*                       pPhysicalDevices)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, instance, pPhysicalDeviceCount, pPhysicalDevices);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDevices_PreCall(manager->GetBlockIndex(), instance, pPhysicalDeviceCount, pPhysicalDevices);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures*               pFeatures)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures_PreCall(manager->GetBlockIndex(), physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties*                     pFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties_PreCall(manager->GetBlockIndex(), physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkImageType                             type,
        VkImageTiling                           tiling,
        VkImageUsageFlags                       usage,
        VkImageCreateFlags                      flags,
        VkImageFormatProperties*                pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties_PreCall(manager->GetBlockIndex(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties*             pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties*                pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties*       pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkDeviceCreateInfo*               pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDevice*                               pDevice)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, physicalDevice, pCreateInfo, pAllocator, pDevice);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDevice_PreCall(manager->GetBlockIndex(), physicalDevice, pCreateInfo, pAllocator, pDevice);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, device, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDevice_PreCall(manager->GetBlockIndex(), device, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                queueFamilyIndex,
        uint32_t                                queueIndex,
        VkQueue*                                pQueue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, device, queueFamilyIndex, queueIndex, pQueue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceQueue_PreCall(manager->GetBlockIndex(), device, queueFamilyIndex, queueIndex, pQueue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo*                     pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit_PreCall(manager->GetBlockIndex(), queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, queue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueWaitIdle_PreCall(manager->GetBlockIndex(), queue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DeviceWaitIdle_PreCall(manager->GetBlockIndex(), device);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryAllocateInfo*             pAllocateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDeviceMemory*                         pMemory)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, device, pAllocateInfo, pAllocator, pMemory);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateMemory_PreCall(manager->GetBlockIndex(), device, pAllocateInfo, pAllocator, pMemory);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, device, memory, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeMemory_PreCall(manager->GetBlockIndex(), device, memory, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkDeviceSize                            offset,
        VkDeviceSize                            size,
        VkMemoryMapFlags                        flags,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, device, memory, offset, size, flags, ppData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MapMemory_PreCall(manager->GetBlockIndex(), device, memory, offset, size, flags, ppData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, device, memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UnmapMemory_PreCall(manager->GetBlockIndex(), device, memory);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                memoryRangeCount,
        const VkMappedMemoryRange*              pMemoryRanges)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, device, memoryRangeCount, pMemoryRanges);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FlushMappedMemoryRanges_PreCall(manager->GetBlockIndex(), device, memoryRangeCount, pMemoryRanges);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                memoryRangeCount,
        const VkMappedMemoryRange*              pMemoryRanges)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, device, memoryRangeCount, pMemoryRanges);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.InvalidateMappedMemoryRanges_PreCall(manager->GetBlockIndex(), device, memoryRangeCount, pMemoryRanges);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkDeviceSize*                           pCommittedMemoryInBytes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, device, memory, pCommittedMemoryInBytes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryCommitment_PreCall(manager->GetBlockIndex(), device, memory, pCommittedMemoryInBytes);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBuffer                                buffer,
        VkDeviceMemory                          memory,
        VkDeviceSize                            memoryOffset)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, device, buffer, memory, memoryOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory_PreCall(manager->GetBlockIndex(), device, buffer, memory, memoryOffset);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        VkDeviceMemory                          memory,
        VkDeviceSize                            memoryOffset)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, device, image, memory, memoryOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory_PreCall(manager->GetBlockIndex(), device, image, memory, memoryOffset);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBuffer                                buffer,
        VkMemoryRequirements*                   pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, device, buffer, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements_PreCall(manager->GetBlockIndex(), device, buffer, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        VkMemoryRequirements*                   pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, device, image, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements_PreCall(manager->GetBlockIndex(), device, image, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements*        pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements_PreCall(manager->GetBlockIndex(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties_PreCall(manager->GetBlockIndex(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t                                bindInfoCount,
        const VkBindSparseInfo*                 pBindInfo,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, queue, bindInfoCount, pBindInfo, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindSparseInfo* pBindInfo_unwrapped = UnwrapStructArrayHandles(pBindInfo, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueBindSparse_PreCall(manager->GetBlockIndex(), queue, bindInfoCount, pBindInfo, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkFenceCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, device, pCreateInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateFence_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFence                                 fence,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, device, fence, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyFence_PreCall(manager->GetBlockIndex(), device, fence, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                fenceCount,
        const VkFence*                          pFences)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, device, fenceCount, pFences);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetFences_PreCall(manager->GetBlockIndex(), device, fenceCount, pFences);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, device, fence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceStatus_PreCall(manager->GetBlockIndex(), device, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                fenceCount,
        const VkFence*                          pFences,
        VkBool32                                waitAll,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, device, fenceCount, pFences, waitAll, timeout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitForFences_PreCall(manager->GetBlockIndex(), device, fenceCount, pFences, waitAll, timeout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSemaphore*                            pSemaphore)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, device, pCreateInfo, pAllocator, pSemaphore);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSemaphore_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pSemaphore);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, device, semaphore, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySemaphore_PreCall(manager->GetBlockIndex(), device, semaphore, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkEventCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkEvent*                                pEvent)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, device, pCreateInfo, pAllocator, pEvent);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateEvent_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pEvent);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkEvent                                 event,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, device, event, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyEvent_PreCall(manager->GetBlockIndex(), device, event, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetEventStatus_PreCall(manager->GetBlockIndex(), device, event);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetEvent_PreCall(manager->GetBlockIndex(), device, event);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkEvent                                 event)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, device, event);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetEvent_PreCall(manager->GetBlockIndex(), device, event);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkQueryPoolCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkQueryPool*                            pQueryPool)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pQueryPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateQueryPool_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pQueryPool);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, device, queryPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyQueryPool_PreCall(manager->GetBlockIndex(), device, queryPool, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    static void Dispatch(VulkanCaptureManager* manager,
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueryPoolResults_PreCall(manager->GetBlockIndex(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferCreateInfo*               pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkBuffer*                               pBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, device, pCreateInfo, pAllocator, pBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateBuffer_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBuffer                                buffer,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, device, buffer, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyBuffer_PreCall(manager->GetBlockIndex(), device, buffer, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferViewCreateInfo*           pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkBufferView*                           pView)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, device, pCreateInfo, pAllocator, pView);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateBufferView_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pView);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkBufferView                            bufferView,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, device, bufferView, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyBufferView_PreCall(manager->GetBlockIndex(), device, bufferView, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageCreateInfo*                pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkImage*                                pImage)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, device, pCreateInfo, pAllocator, pImage);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImage_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pImage);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, device, image, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyImage_PreCall(manager->GetBlockIndex(), device, image, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkImageSubresource*               pSubresource,
        VkSubresourceLayout*                    pLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, device, image, pSubresource, pLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSubresourceLayout_PreCall(manager->GetBlockIndex(), device, image, pSubresource, pLayout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageViewCreateInfo*            pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkImageView*                            pView)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, device, pCreateInfo, pAllocator, pView);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImageView_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pView);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImageView                             imageView,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, device, imageView, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyImageView_PreCall(manager->GetBlockIndex(), device, imageView, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkShaderModuleCreateInfo*         pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkShaderModule*                         pShaderModule)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, device, pCreateInfo, pAllocator, pShaderModule);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateShaderModule_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pShaderModule);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderModule                          shaderModule,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, device, shaderModule, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyShaderModule_PreCall(manager->GetBlockIndex(), device, shaderModule, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPipelineCacheCreateInfo*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPipelineCache*                        pPipelineCache)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, device, pCreateInfo, pAllocator, pPipelineCache);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePipelineCache_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pPipelineCache);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, device, pipelineCache, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipelineCache_PreCall(manager->GetBlockIndex(), device, pipelineCache, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, device, pipelineCache, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineCacheData_PreCall(manager->GetBlockIndex(), device, pipelineCache, pDataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         dstCache,
        uint32_t                                srcCacheCount,
        const VkPipelineCache*                  pSrcCaches)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, device, dstCache, srcCacheCount, pSrcCaches);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MergePipelineCaches_PreCall(manager->GetBlockIndex(), device, dstCache, srcCacheCount, pSrcCaches);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkGraphicsPipelineCreateInfo*     pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGraphicsPipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateGraphicsPipelines_PreCall(manager->GetBlockIndex(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkComputePipelineCreateInfo*      pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkComputePipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateComputePipelines_PreCall(manager->GetBlockIndex(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, device, pipeline, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipeline_PreCall(manager->GetBlockIndex(), device, pipeline, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPipelineLayoutCreateInfo*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPipelineLayout*                       pPipelineLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, device, pCreateInfo, pAllocator, pPipelineLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePipelineLayout_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pPipelineLayout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineLayout                        pipelineLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, device, pipelineLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipelineLayout_PreCall(manager->GetBlockIndex(), device, pipelineLayout, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSamplerCreateInfo*              pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSampler*                              pSampler)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, device, pCreateInfo, pAllocator, pSampler);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSamplerCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSampler_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pSampler);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSampler                               sampler,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, device, sampler, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySampler_PreCall(manager->GetBlockIndex(), device, sampler, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorSetLayout*                  pSetLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, device, pCreateInfo, pAllocator, pSetLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorSetLayout_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pSetLayout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorSetLayout                   descriptorSetLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, device, descriptorSetLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorSetLayout_PreCall(manager->GetBlockIndex(), device, descriptorSetLayout, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorPoolCreateInfo*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorPool*                       pDescriptorPool)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorPool_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pDescriptorPool);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, device, descriptorPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorPool_PreCall(manager->GetBlockIndex(), device, descriptorPool, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        VkDescriptorPoolResetFlags              flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, device, descriptorPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetDescriptorPool_PreCall(manager->GetBlockIndex(), device, descriptorPool, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetAllocateInfo*      pAllocateInfo,
        VkDescriptorSet*                        pDescriptorSets)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, device, pAllocateInfo, pDescriptorSets);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateDescriptorSets_PreCall(manager->GetBlockIndex(), device, pAllocateInfo, pDescriptorSets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorPool                        descriptorPool,
        uint32_t                                descriptorSetCount,
        const VkDescriptorSet*                  pDescriptorSets)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, device, descriptorPool, descriptorSetCount, pDescriptorSets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeDescriptorSets_PreCall(manager->GetBlockIndex(), device, descriptorPool, descriptorSetCount, pDescriptorSets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                descriptorWriteCount,
        const VkWriteDescriptorSet*             pDescriptorWrites,
        uint32_t                                descriptorCopyCount,
        const VkCopyDescriptorSet*              pDescriptorCopies)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);
    const VkCopyDescriptorSet* pDescriptorCopies_unwrapped = UnwrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateDescriptorSets_PreCall(manager->GetBlockIndex(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkFramebufferCreateInfo*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFramebuffer*                          pFramebuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, device, pCreateInfo, pAllocator, pFramebuffer);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFramebufferCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateFramebuffer_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pFramebuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFramebuffer                           framebuffer,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, device, framebuffer, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyFramebuffer_PreCall(manager->GetBlockIndex(), device, framebuffer, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkRenderPassCreateInfo*           pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkRenderPass                            renderPass,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, device, renderPass, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyRenderPass_PreCall(manager->GetBlockIndex(), device, renderPass, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkRenderPass                            renderPass,
        VkExtent2D*                             pGranularity)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, device, renderPass, pGranularity);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRenderAreaGranularity_PreCall(manager->GetBlockIndex(), device, renderPass, pGranularity);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkCommandPoolCreateInfo*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkCommandPool*                          pCommandPool)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, device, pCreateInfo, pAllocator, pCommandPool);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateCommandPool_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pCommandPool);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, device, commandPool, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyCommandPool_PreCall(manager->GetBlockIndex(), device, commandPool, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolResetFlags                 flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetCommandPool_PreCall(manager->GetBlockIndex(), device, commandPool, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkCommandBufferAllocateInfo*      pAllocateInfo,
        VkCommandBuffer*                        pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, device, pAllocateInfo, pCommandBuffers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCommandBufferAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateCommandBuffers_PreCall(manager->GetBlockIndex(), device, pAllocateInfo, pCommandBuffers);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        uint32_t                                commandBufferCount,
        const VkCommandBuffer*                  pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, device, commandPool, commandBufferCount, pCommandBuffers);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeCommandBuffers_PreCall(manager->GetBlockIndex(), device, commandPool, commandBufferCount, pCommandBuffers);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCommandBufferBeginInfo*         pBeginInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, commandBuffer, pBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCommandBufferBeginInfo* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BeginCommandBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, pBeginInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EndCommandBuffer_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCommandBufferResetFlags               flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, commandBuffer, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetCommandBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipeline                              pipeline)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindPipeline_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineBindPoint, pipeline);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewport_PreCall(manager->GetBlockIndex(), commandBuffer, firstViewport, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstScissor,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, commandBuffer, firstScissor, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissor_PreCall(manager->GetBlockIndex(), commandBuffer, firstScissor, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   lineWidth)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, commandBuffer, lineWidth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineWidth_PreCall(manager->GetBlockIndex(), commandBuffer, lineWidth);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   depthBiasConstantFactor,
        float                                   depthBiasClamp,
        float                                   depthBiasSlopeFactor)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBias_PreCall(manager->GetBlockIndex(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const float                             blendConstants[4])
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, commandBuffer, blendConstants);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetBlendConstants_PreCall(manager->GetBlockIndex(), commandBuffer, blendConstants);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   minDepthBounds,
        float                                   maxDepthBounds)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, commandBuffer, minDepthBounds, maxDepthBounds);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBounds_PreCall(manager->GetBlockIndex(), commandBuffer, minDepthBounds, maxDepthBounds);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                compareMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, commandBuffer, faceMask, compareMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilCompareMask_PreCall(manager->GetBlockIndex(), commandBuffer, faceMask, compareMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                writeMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, commandBuffer, faceMask, writeMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilWriteMask_PreCall(manager->GetBlockIndex(), commandBuffer, faceMask, writeMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkStencilFaceFlags                      faceMask,
        uint32_t                                reference)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, commandBuffer, faceMask, reference);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilReference_PreCall(manager->GetBlockIndex(), commandBuffer, faceMask, reference);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindDescriptorSets_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        VkIndexType                             indexType)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, commandBuffer, buffer, offset, indexType);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindIndexBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, indexType);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstBinding,
        uint32_t                                bindingCount,
        const VkBuffer*                         pBuffers,
        const VkDeviceSize*                     pOffsets)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers_PreCall(manager->GetBlockIndex(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                vertexCount,
        uint32_t                                instanceCount,
        uint32_t                                firstVertex,
        uint32_t                                firstInstance)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDraw_PreCall(manager->GetBlockIndex(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexed_PreCall(manager->GetBlockIndex(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirect_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirect_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatch_PreCall(manager->GetBlockIndex(), commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, commandBuffer, buffer, offset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchIndirect_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                srcBuffer,
        VkBuffer                                dstBuffer,
        uint32_t                                regionCount,
        const VkBufferCopy*                     pRegions)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage_PreCall(manager->GetBlockIndex(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage_PreCall(manager->GetBlockIndex(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage_PreCall(manager->GetBlockIndex(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        VkDeviceSize                            dataSize,
        const void*                             pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdUpdateBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        VkDeviceSize                            size,
        uint32_t                                data)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, commandBuffer, dstBuffer, dstOffset, size, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdFillBuffer_PreCall(manager->GetBlockIndex(), commandBuffer, dstBuffer, dstOffset, size, data);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearColorImage_PreCall(manager->GetBlockIndex(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearDepthStencilImage_PreCall(manager->GetBlockIndex(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                attachmentCount,
        const VkClearAttachment*                pAttachments,
        uint32_t                                rectCount,
        const VkClearRect*                      pRects)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearAttachments_PreCall(manager->GetBlockIndex(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage_PreCall(manager->GetBlockIndex(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags                    stageMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent_PreCall(manager->GetBlockIndex(), commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags                    stageMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent_PreCall(manager->GetBlockIndex(), commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents_PreCall(manager->GetBlockIndex(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier_PreCall(manager->GetBlockIndex(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        VkQueryControlFlags                     flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, commandBuffer, queryPool, query, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginQuery_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, query, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, commandBuffer, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndQuery_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, query);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetQueryPool_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, firstQuery, queryCount);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlagBits                 pipelineStage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, commandBuffer, pipelineStage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineStage, queryPool, query);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyQueryPoolResults_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, commandBuffer, layout, stageFlags, offset, size, pValues);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPushConstants_PreCall(manager->GetBlockIndex(), commandBuffer, layout, stageFlags, offset, size, pValues);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        VkSubpassContents                       contents)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, commandBuffer, pRenderPassBegin, contents);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass_PreCall(manager->GetBlockIndex(), commandBuffer, pRenderPassBegin, contents);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSubpassContents                       contents)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, commandBuffer, contents);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass_PreCall(manager->GetBlockIndex(), commandBuffer, contents);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                commandBufferCount,
        const VkCommandBuffer*                  pCommandBuffers)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, commandBuffer, commandBufferCount, pCommandBuffers);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdExecuteCommands_PreCall(manager->GetBlockIndex(), commandBuffer, commandBufferCount, pCommandBuffers);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindBufferMemoryInfo*           pBindInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory2_PreCall(manager->GetBlockIndex(), device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindImageMemoryInfo*            pBindInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory2_PreCall(manager->GetBlockIndex(), device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                heapIndex,
        uint32_t                                localDeviceIndex,
        uint32_t                                remoteDeviceIndex,
        VkPeerMemoryFeatureFlags*               pPeerMemoryFeatures)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeatures_PreCall(manager->GetBlockIndex(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                deviceMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, commandBuffer, deviceMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDeviceMask_PreCall(manager->GetBlockIndex(), commandBuffer, deviceMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchBase_PreCall(manager->GetBlockIndex(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceGroupCount,
        VkPhysicalDeviceGroupProperties*        pPhysicalDeviceGroupProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroups_PreCall(manager->GetBlockIndex(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageMemoryRequirementsInfo2*   pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements2_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferMemoryRequirementsInfo2*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageSparseMemoryRequirementsInfo2* pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2_PreCall(manager->GetBlockIndex(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures2*              pFeatures)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2_PreCall(manager->GetBlockIndex(), physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties2*            pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties2*                    pFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2*               pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, physicalDevice, pImageFormatInfo, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, pImageFormatInfo, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties2*               pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties2*      pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
        uint32_t*                               pPropertyCount,
        VkSparseImageFormatProperties2*         pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2_PreCall(manager->GetBlockIndex(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolTrimFlags                  flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.TrimCommandPool_PreCall(manager->GetBlockIndex(), device, commandPool, flags);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceQueueInfo2*               pQueueInfo,
        VkQueue*                                pQueue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, device, pQueueInfo, pQueue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceQueue2_PreCall(manager->GetBlockIndex(), device, pQueueInfo, pQueue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSamplerYcbcrConversion*               pYcbcrConversion)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, device, pCreateInfo, pAllocator, pYcbcrConversion);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversion_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pYcbcrConversion);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSamplerYcbcrConversion                ycbcrConversion,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, device, ycbcrConversion, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversion_PreCall(manager->GetBlockIndex(), device, ycbcrConversion, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorUpdateTemplate*             pDescriptorUpdateTemplate)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplate_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorUpdateTemplate              descriptorUpdateTemplate,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplate_PreCall(manager->GetBlockIndex(), device, descriptorUpdateTemplate, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
        VkExternalBufferProperties*             pExternalBufferProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
        VkExternalFenceProperties*              pExternalFenceProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFenceProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
        VkExternalSemaphoreProperties*          pExternalSemaphoreProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphoreProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        VkDescriptorSetLayoutSupport*           pSupport)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, device, pCreateInfo, pSupport);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupport_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pSupport);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCount_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCount_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkRenderPassCreateInfo2*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass2_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        const VkSubpassBeginInfo*               pSubpassBeginInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass2_PreCall(manager->GetBlockIndex(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassBeginInfo*               pSubpassBeginInfo,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass2_PreCall(manager->GetBlockIndex(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, commandBuffer, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass2_PreCall(manager->GetBlockIndex(), commandBuffer, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, device, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetQueryPool_PreCall(manager->GetBlockIndex(), device, queryPool, firstQuery, queryCount);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        uint64_t*                               pValue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, device, semaphore, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreCounterValue_PreCall(manager->GetBlockIndex(), device, semaphore, pValue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreWaitInfo*              pWaitInfo,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, device, pWaitInfo, timeout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitSemaphores_PreCall(manager->GetBlockIndex(), device, pWaitInfo, timeout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreSignalInfo*            pSignalInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, device, pSignalInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SignalSemaphore_PreCall(manager->GetBlockIndex(), device, pSignalInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddress_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddress_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddress_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pToolCount,
        VkPhysicalDeviceToolProperties*         pToolProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, physicalDevice, pToolCount, pToolProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceToolProperties_PreCall(manager->GetBlockIndex(), physicalDevice, pToolCount, pToolProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPrivateDataSlotCreateInfo*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPrivateDataSlot*                      pPrivateDataSlot)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, device, pCreateInfo, pAllocator, pPrivateDataSlot);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePrivateDataSlot_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pPrivateDataSlot);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPrivateDataSlot                       privateDataSlot,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, device, privateDataSlot, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPrivateDataSlot_PreCall(manager->GetBlockIndex(), device, privateDataSlot, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t                                data)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetPrivateData_PreCall(manager->GetBlockIndex(), device, objectType, objectHandle, privateDataSlot, data);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t*                               pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPrivateData_PreCall(manager->GetBlockIndex(), device, objectType, objectHandle, privateDataSlot, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, commandBuffer, event, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent2_PreCall(manager->GetBlockIndex(), commandBuffer, event, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags2                   stageMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent2_PreCall(manager->GetBlockIndex(), commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                eventCount,
        const VkEvent*                          pEvents,
        const VkDependencyInfo*                 pDependencyInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents2_PreCall(manager->GetBlockIndex(), commandBuffer, eventCount, pEvents, pDependencyInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, commandBuffer, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier2_PreCall(manager->GetBlockIndex(), commandBuffer, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, commandBuffer, stage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp2_PreCall(manager->GetBlockIndex(), commandBuffer, stage, queryPool, query);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo2*                    pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit2_PreCall(manager->GetBlockIndex(), queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferInfo2*                pCopyBufferInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, commandBuffer, pCopyBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer2_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyBufferInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageInfo2*                 pCopyImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, commandBuffer, pCopyImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage2_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferToImageInfo2*         pCopyBufferToImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage2_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyBufferToImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageToBufferInfo2*         pCopyImageToBufferInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyImageToBufferInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkBlitImageInfo2*                 pBlitImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, commandBuffer, pBlitImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage2_PreCall(manager->GetBlockIndex(), commandBuffer, pBlitImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkResolveImageInfo2*              pResolveImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, commandBuffer, pResolveImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage2_PreCall(manager->GetBlockIndex(), commandBuffer, pResolveImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderingInfo*                  pRenderingInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, commandBuffer, pRenderingInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRendering_PreCall(manager->GetBlockIndex(), commandBuffer, pRenderingInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRendering_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCullModeFlags                         cullMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, commandBuffer, cullMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCullMode_PreCall(manager->GetBlockIndex(), commandBuffer, cullMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFrontFace                             frontFace)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, commandBuffer, frontFace);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFrontFace_PreCall(manager->GetBlockIndex(), commandBuffer, frontFace);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPrimitiveTopology                     primitiveTopology)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, commandBuffer, primitiveTopology);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveTopology_PreCall(manager->GetBlockIndex(), commandBuffer, primitiveTopology);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, commandBuffer, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWithCount_PreCall(manager->GetBlockIndex(), commandBuffer, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, commandBuffer, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissorWithCount_PreCall(manager->GetBlockIndex(), commandBuffer, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers2_PreCall(manager->GetBlockIndex(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, commandBuffer, depthTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthTestEnable_PreCall(manager->GetBlockIndex(), commandBuffer, depthTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthWriteEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, commandBuffer, depthWriteEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthWriteEnable_PreCall(manager->GetBlockIndex(), commandBuffer, depthWriteEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCompareOp                             depthCompareOp)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, commandBuffer, depthCompareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthCompareOp_PreCall(manager->GetBlockIndex(), commandBuffer, depthCompareOp);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBoundsTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnable_PreCall(manager->GetBlockIndex(), commandBuffer, depthBoundsTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stencilTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, commandBuffer, stencilTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilTestEnable_PreCall(manager->GetBlockIndex(), commandBuffer, stencilTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilOp_PreCall(manager->GetBlockIndex(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                rasterizerDiscardEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnable_PreCall(manager->GetBlockIndex(), commandBuffer, rasterizerDiscardEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBiasEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, commandBuffer, depthBiasEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBiasEnable_PreCall(manager->GetBlockIndex(), commandBuffer, depthBiasEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                primitiveRestartEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, commandBuffer, primitiveRestartEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnable_PreCall(manager->GetBlockIndex(), commandBuffer, primitiveRestartEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceBufferMemoryRequirements* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirements_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirements_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirements_PreCall(manager->GetBlockIndex(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkSurfaceKHR                            surface,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, instance, surface, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySurfaceKHR_PreCall(manager->GetBlockIndex(), instance, surface, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        VkSurfaceKHR                            surface,
        VkBool32*                               pSupported)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, surface, pSupported);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceSupportKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, surface, pSupported);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        VkSurfaceCapabilitiesKHR*               pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, physicalDevice, surface, pSurfaceCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, surface, pSurfaceCapabilities);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pSurfaceFormatCount,
        VkSurfaceFormatKHR*                     pSurfaceFormats)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormatsKHR_PreCall(manager->GetBlockIndex(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pPresentModeCount,
        VkPresentModeKHR*                       pPresentModes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, physicalDevice, surface, pPresentModeCount, pPresentModes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, surface, pPresentModeCount, pPresentModes);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSwapchainCreateInfoKHR*         pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSwapchainKHR*                         pSwapchain)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pSwapchain);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSwapchainCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSwapchainKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pSwapchain);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, device, swapchain, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySwapchainKHR_PreCall(manager->GetBlockIndex(), device, swapchain, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint32_t*                               pSwapchainImageCount,
        VkImage*                                pSwapchainImages)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, device, swapchain, pSwapchainImageCount, pSwapchainImages);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainImagesKHR_PreCall(manager->GetBlockIndex(), device, swapchain, pSwapchainImageCount, pSwapchainImages);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint64_t                                timeout,
        VkSemaphore                             semaphore,
        VkFence                                 fence,
        uint32_t*                               pImageIndex)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, device, swapchain, timeout, semaphore, fence, pImageIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireNextImageKHR_PreCall(manager->GetBlockIndex(), device, swapchain, timeout, semaphore, fence, pImageIndex);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        const VkPresentInfoKHR*                 pPresentInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, queue, pPresentInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueuePresentKHR_PreCall(manager->GetBlockIndex(), queue, pPresentInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceGroupPresentCapabilitiesKHR*    pDeviceGroupPresentCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, device, pDeviceGroupPresentCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPresentCapabilitiesKHR_PreCall(manager->GetBlockIndex(), device, pDeviceGroupPresentCapabilities);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSurfaceKHR                            surface,
        VkDeviceGroupPresentModeFlagsKHR*       pModes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, device, surface, pModes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModesKHR_PreCall(manager->GetBlockIndex(), device, surface, pModes);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        uint32_t*                               pRectCount,
        VkRect2D*                               pRects)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, physicalDevice, surface, pRectCount, pRects);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDevicePresentRectanglesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, surface, pRectCount, pRects);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAcquireNextImageInfoKHR*        pAcquireInfo,
        uint32_t*                               pImageIndex)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, device, pAcquireInfo, pImageIndex);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAcquireNextImageInfoKHR* pAcquireInfo_unwrapped = UnwrapStructPtrHandles(pAcquireInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireNextImage2KHR_PreCall(manager->GetBlockIndex(), device, pAcquireInfo, pImageIndex);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPropertiesKHR*                 pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPlanePropertiesKHR*            pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                planeIndex,
        uint32_t*                               pDisplayCount,
        VkDisplayKHR*                           pDisplays)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, physicalDevice, planeIndex, pDisplayCount, pDisplays);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneSupportedDisplaysKHR_PreCall(manager->GetBlockIndex(), physicalDevice, planeIndex, pDisplayCount, pDisplays);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        uint32_t*                               pPropertyCount,
        VkDisplayModePropertiesKHR*             pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, physicalDevice, display, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayModePropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, display, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        const VkDisplayModeCreateInfoKHR*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDisplayModeKHR*                       pMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, physicalDevice, display, pCreateInfo, pAllocator, pMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDisplayModeKHR_PreCall(manager->GetBlockIndex(), physicalDevice, display, pCreateInfo, pAllocator, pMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayModeKHR                        mode,
        uint32_t                                planeIndex,
        VkDisplayPlaneCapabilitiesKHR*          pCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, physicalDevice, mode, planeIndex, pCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilitiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, mode, planeIndex, pCapabilities);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkDisplaySurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDisplaySurfaceCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDisplayPlaneSurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                swapchainCount,
        const VkSwapchainCreateInfoKHR*         pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkSwapchainKHR*                         pSwapchains)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSwapchainCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, swapchainCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSharedSwapchainsKHR_PreCall(manager->GetBlockIndex(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkXlibSurfaceCreateInfoKHR*       pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateXlibSurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        Display*                                dpy,
        VisualID                                visualID)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, dpy, visualID);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, dpy, visualID);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkXcbSurfaceCreateInfoKHR*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateXcbSurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        xcb_connection_t*                       connection,
        xcb_visualid_t                          visual_id)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, connection, visual_id);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, connection, visual_id);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkWaylandSurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateWaylandSurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        struct wl_display*                      display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, display);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkAndroidSurfaceCreateInfoKHR*    pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAndroidSurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkWin32SurfaceCreateInfoKHR*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateWin32SurfaceKHR_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkVideoProfileInfoKHR*            pVideoProfile,
        VkVideoCapabilitiesKHR*                 pCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, physicalDevice, pVideoProfile, pCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pVideoProfile, pCapabilities);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo,
        uint32_t*                               pVideoFormatPropertyCount,
        VkVideoFormatPropertiesKHR*             pVideoFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkVideoSessionCreateInfoKHR*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkVideoSessionKHR*                      pVideoSession)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pVideoSession);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateVideoSessionKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pVideoSession);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, device, videoSession, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyVideoSessionKHR_PreCall(manager->GetBlockIndex(), device, videoSession, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        uint32_t*                               pMemoryRequirementsCount,
        VkVideoSessionMemoryRequirementsKHR*    pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetVideoSessionMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionKHR                       videoSession,
        uint32_t                                bindSessionMemoryInfoCount,
        const VkBindVideoSessionMemoryInfoKHR*  pBindSessionMemoryInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos_unwrapped = UnwrapStructArrayHandles(pBindSessionMemoryInfos, bindSessionMemoryInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindVideoSessionMemoryKHR_PreCall(manager->GetBlockIndex(), device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkVideoSessionParametersKHR*            pVideoSessionParameters)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pVideoSessionParameters);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoSessionParametersCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pVideoSessionParameters);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionParametersKHR             videoSessionParameters,
        const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pUpdateInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), device, videoSessionParameters, pUpdateInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkVideoSessionParametersKHR             videoSessionParameters,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, device, videoSessionParameters, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), device, videoSessionParameters, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoBeginCodingInfoKHR*        pBeginInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, commandBuffer, pBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoBeginCodingInfoKHR* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginVideoCodingKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pBeginInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoEndCodingInfoKHR*          pEndCodingInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, commandBuffer, pEndCodingInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndVideoCodingKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pEndCodingInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoCodingControlInfoKHR*      pCodingControlInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, commandBuffer, pCodingControlInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdControlVideoCodingKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pCodingControlInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoDecodeInfoKHR*             pDecodeInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, commandBuffer, pDecodeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoDecodeInfoKHR* pDecodeInfo_unwrapped = UnwrapStructPtrHandles(pDecodeInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDecodeVideoKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pDecodeInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderingInfo*                  pRenderingInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, commandBuffer, pRenderingInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderingKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pRenderingInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderingKHR_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceFeatures2*              pFeatures)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, physicalDevice, pFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pFeatures);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceProperties2*            pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, physicalDevice, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkFormat                                format,
        VkFormatProperties2*                    pFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, physicalDevice, format, pFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, format, pFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2*               pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pImageFormatInfo, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pImageFormatInfo, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pQueueFamilyPropertyCount,
        VkQueueFamilyProperties2*               pQueueFamilyProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkPhysicalDeviceMemoryProperties2*      pMemoryProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, physicalDevice, pMemoryProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pMemoryProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
        uint32_t*                               pPropertyCount,
        VkSparseImageFormatProperties2*         pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, physicalDevice, pFormatInfo, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                heapIndex,
        uint32_t                                localDeviceIndex,
        uint32_t                                remoteDeviceIndex,
        VkPeerMemoryFeatureFlags*               pPeerMemoryFeatures)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(manager->GetBlockIndex(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                deviceMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, commandBuffer, deviceMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDeviceMaskKHR_PreCall(manager->GetBlockIndex(), commandBuffer, deviceMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchBaseKHR_PreCall(manager->GetBlockIndex(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkCommandPool                           commandPool,
        VkCommandPoolTrimFlags                  flags)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, device, commandPool, flags);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.TrimCommandPoolKHR_PreCall(manager->GetBlockIndex(), device, commandPool, flags);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        uint32_t*                               pPhysicalDeviceGroupCount,
        VkPhysicalDeviceGroupProperties*        pPhysicalDeviceGroupProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroupsKHR_PreCall(manager->GetBlockIndex(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
        VkExternalBufferProperties*             pExternalBufferProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryGetWin32HandleInfoKHR*    pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandleKHR_PreCall(manager->GetBlockIndex(), device, pGetWin32HandleInfo, pHandle);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        HANDLE                                  handle,
        VkMemoryWin32HandlePropertiesKHR*       pMemoryWin32HandleProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, device, handleType, handle, pMemoryWin32HandleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandlePropertiesKHR_PreCall(manager->GetBlockIndex(), device, handleType, handle, pMemoryWin32HandleProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryGetFdInfoKHR*             pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryFdKHR_PreCall(manager->GetBlockIndex(), device, pGetFdInfo, pFd);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        int                                     fd,
        VkMemoryFdPropertiesKHR*                pMemoryFdProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, device, handleType, fd, pMemoryFdProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryFdPropertiesKHR_PreCall(manager->GetBlockIndex(), device, handleType, fd, pMemoryFdProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
        VkExternalSemaphoreProperties*          pExternalSemaphoreProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, device, pImportSemaphoreWin32HandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreWin32HandleKHR_PreCall(manager->GetBlockIndex(), device, pImportSemaphoreWin32HandleInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreWin32HandleKHR_PreCall(manager->GetBlockIndex(), device, pGetWin32HandleInfo, pHandle);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImportSemaphoreFdInfoKHR*       pImportSemaphoreFdInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, device, pImportSemaphoreFdInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreFdKHR_PreCall(manager->GetBlockIndex(), device, pImportSemaphoreFdInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreGetFdInfoKHR*          pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreFdKHR_PreCall(manager->GetBlockIndex(), device, pGetFdInfo, pFd);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPushDescriptorSetKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDescriptorUpdateTemplate*             pDescriptorUpdateTemplate)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplateKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorUpdateTemplate              descriptorUpdateTemplate,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, device, descriptorUpdateTemplate, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplateKHR_PreCall(manager->GetBlockIndex(), device, descriptorUpdateTemplate, pAllocator);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkRenderPassCreateInfo2*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkRenderPass*                           pRenderPass)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pRenderPass);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass2KHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pRenderPass);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkRenderPassBeginInfo*            pRenderPassBegin,
        const VkSubpassBeginInfo*               pSubpassBeginInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassBeginInfo*               pSubpassBeginInfo,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSubpassEndInfo*                 pSubpassEndInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, commandBuffer, pSubpassEndInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pSubpassEndInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainStatusKHR_PreCall(manager->GetBlockIndex(), device, swapchain);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
        VkExternalFenceProperties*              pExternalFenceProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImportFenceWin32HandleInfoKHR*  pImportFenceWin32HandleInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, device, pImportFenceWin32HandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportFenceWin32HandleKHR_PreCall(manager->GetBlockIndex(), device, pImportFenceWin32HandleInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkFenceGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, device, pGetWin32HandleInfo, pHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceWin32HandleKHR_PreCall(manager->GetBlockIndex(), device, pGetWin32HandleInfo, pHandle);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImportFenceFdInfoKHR*           pImportFenceFdInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, device, pImportFenceFdInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportFenceFdInfoKHR* pImportFenceFdInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportFenceFdKHR_PreCall(manager->GetBlockIndex(), device, pImportFenceFdInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkFenceGetFdInfoKHR*              pGetFdInfo,
        int*                                    pFd)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, device, pGetFdInfo, pFd);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkFenceGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceFdKHR_PreCall(manager->GetBlockIndex(), device, pGetFdInfo, pFd);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        uint32_t*                               pCounterCount,
        VkPerformanceCounterKHR*                pCounters,
        VkPerformanceCounterDescriptionKHR*     pCounterDescriptions)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo,
        uint32_t*                               pNumPasses)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAcquireProfilingLockInfoKHR*    pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, device, pInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireProfilingLockKHR_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseProfilingLockKHR_PreCall(manager->GetBlockIndex(), device);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        VkSurfaceCapabilities2KHR*              pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        uint32_t*                               pSurfaceFormatCount,
        VkSurfaceFormat2KHR*                    pSurfaceFormats)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormats2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayProperties2KHR*                pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkDisplayPlaneProperties2KHR*           pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display,
        uint32_t*                               pPropertyCount,
        VkDisplayModeProperties2KHR*            pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, physicalDevice, display, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayModeProperties2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, display, pPropertyCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkDisplayPlaneInfo2KHR*           pDisplayPlaneInfo,
        VkDisplayPlaneCapabilities2KHR*         pCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, physicalDevice, pDisplayPlaneInfo, pCapabilities);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo_unwrapped = UnwrapStructPtrHandles(pDisplayPlaneInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilities2KHR_PreCall(manager->GetBlockIndex(), physicalDevice, pDisplayPlaneInfo, pCapabilities);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageMemoryRequirementsInfo2*   pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferMemoryRequirementsInfo2*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageSparseMemoryRequirementsInfo2* pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSamplerYcbcrConversion*               pYcbcrConversion)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pYcbcrConversion);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversionKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pYcbcrConversion);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSamplerYcbcrConversion                ycbcrConversion,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, device, ycbcrConversion, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversionKHR_PreCall(manager->GetBlockIndex(), device, ycbcrConversion, pAllocator);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindBufferMemoryInfo*           pBindInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory2KHR_PreCall(manager->GetBlockIndex(), device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindImageMemoryInfo*            pBindInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory2KHR_PreCall(manager->GetBlockIndex(), device, bindInfoCount, pBindInfos);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetLayoutCreateInfo*  pCreateInfo,
        VkDescriptorSetLayoutSupport*           pSupport)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, device, pCreateInfo, pSupport);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupportKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pSupport);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCountKHR_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountKHR_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSemaphore                             semaphore,
        uint64_t*                               pValue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, device, semaphore, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreCounterValueKHR_PreCall(manager->GetBlockIndex(), device, semaphore, pValue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreWaitInfo*              pWaitInfo,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, device, pWaitInfo, timeout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitSemaphoresKHR_PreCall(manager->GetBlockIndex(), device, pWaitInfo, timeout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreSignalInfo*            pSignalInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, device, pSignalInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SignalSemaphoreKHR_PreCall(manager->GetBlockIndex(), device, pSignalInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pFragmentShadingRateCount,
        VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(manager->GetBlockIndex(), physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkExtent2D*                       pFragmentSize,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2])
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, commandBuffer, pFragmentSize, combinerOps);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pFragmentSize, combinerOps);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint64_t                                presentId,
        uint64_t                                timeout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, device, swapchain, presentId, timeout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitForPresentKHR_PreCall(manager->GetBlockIndex(), device, swapchain, presentId, timeout);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddressKHR_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddressKHR_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAllocationCallbacks*            pAllocator,
        VkDeferredOperationKHR*                 pDeferredOperation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, device, pAllocator, pDeferredOperation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDeferredOperationKHR_PreCall(manager->GetBlockIndex(), device, pAllocator, pDeferredOperation);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, device, operation, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDeferredOperationKHR_PreCall(manager->GetBlockIndex(), device, operation, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeferredOperationMaxConcurrencyKHR_PreCall(manager->GetBlockIndex(), device, operation);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeferredOperationResultKHR_PreCall(manager->GetBlockIndex(), device, operation);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  operation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, device, operation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DeferredOperationJoinKHR_PreCall(manager->GetBlockIndex(), device, operation);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPipelineInfoKHR*                pPipelineInfo,
        uint32_t*                               pExecutableCount,
        VkPipelineExecutablePropertiesKHR*      pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, device, pPipelineInfo, pExecutableCount, pProperties);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineInfoKHR* pPipelineInfo_unwrapped = UnwrapStructPtrHandles(pPipelineInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutablePropertiesKHR_PreCall(manager->GetBlockIndex(), device, pPipelineInfo, pExecutableCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPipelineExecutableInfoKHR*      pExecutableInfo,
        uint32_t*                               pStatisticCount,
        VkPipelineExecutableStatisticKHR*       pStatistics)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, device, pExecutableInfo, pStatisticCount, pStatistics);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutableStatisticsKHR_PreCall(manager->GetBlockIndex(), device, pExecutableInfo, pStatisticCount, pStatistics);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPipelineExecutableInfoKHR*      pExecutableInfo,
        uint32_t*                               pInternalRepresentationCount,
        VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutableInternalRepresentationsKHR_PreCall(manager->GetBlockIndex(), device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryMapInfoKHR*               pMemoryMapInfo,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory2KHR>::Dispatch(manager, device, pMemoryMapInfo, ppData);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryMapInfoKHR* pMemoryMapInfo_unwrapped = UnwrapStructPtrHandles(pMemoryMapInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MapMemory2KHR_PreCall(manager->GetBlockIndex(), device, pMemoryMapInfo, ppData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryUnmapInfoKHR*             pMemoryUnmapInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory2KHR>::Dispatch(manager, device, pMemoryUnmapInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo_unwrapped = UnwrapStructPtrHandles(pMemoryUnmapInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UnmapMemory2KHR_PreCall(manager->GetBlockIndex(), device, pMemoryUnmapInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkVideoEncodeInfoKHR*             pEncodeInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, commandBuffer, pEncodeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkVideoEncodeInfoKHR* pEncodeInfo_unwrapped = UnwrapStructPtrHandles(pEncodeInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEncodeVideoKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pEncodeInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, commandBuffer, event, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, event, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkEvent                                 event,
        VkPipelineStageFlags2                   stageMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, commandBuffer, event, stageMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, event, stageMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                eventCount,
        const VkEvent*                          pEvents,
        const VkDependencyInfo*                 pDependencyInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, commandBuffer, eventCount, pEvents, pDependencyInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, eventCount, pEvents, pDependencyInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDependencyInfo*                 pDependencyInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, commandBuffer, pDependencyInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pDependencyInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkQueryPool                             queryPool,
        uint32_t                                query)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, commandBuffer, stage, queryPool, query);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, stage, queryPool, query);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t                                submitCount,
        const VkSubmitInfo2*                    pSubmits,
        VkFence                                 fence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit2KHR_PreCall(manager->GetBlockIndex(), queue, submitCount, pSubmits, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlags2                   stage,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        uint32_t                                marker)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, commandBuffer, stage, dstBuffer, dstOffset, marker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteBufferMarker2AMD_PreCall(manager->GetBlockIndex(), commandBuffer, stage, dstBuffer, dstOffset, marker);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t*                               pCheckpointDataCount,
        VkCheckpointData2NV*                    pCheckpointData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueueCheckpointData2NV_PreCall(manager->GetBlockIndex(), queue, pCheckpointDataCount, pCheckpointData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferInfo2*                pCopyBufferInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyBufferInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageInfo2*                 pCopyImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, commandBuffer, pCopyImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyBufferToImageInfo2*         pCopyBufferToImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, commandBuffer, pCopyBufferToImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyBufferToImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyImageToBufferInfo2*         pCopyImageToBufferInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, commandBuffer, pCopyImageToBufferInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pCopyImageToBufferInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkBlitImageInfo2*                 pBlitImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, commandBuffer, pBlitImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pBlitImageInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkResolveImageInfo2*              pResolveImageInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, commandBuffer, pResolveImageInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, pResolveImageInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkDeviceAddress                         indirectDeviceAddress)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, commandBuffer, indirectDeviceAddress);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysIndirect2KHR_PreCall(manager->GetBlockIndex(), commandBuffer, indirectDeviceAddress);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceBufferMemoryRequirements* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceImageMemoryRequirements*  pInfo,
        uint32_t*                               pSparseMemoryRequirementCount,
        VkSparseImageMemoryRequirements2*       pSparseMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDebugReportCallbackEXT*               pCallback)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pCallback);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDebugReportCallbackEXT_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pCallback);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugReportCallbackEXT                callback,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, instance, callback, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDebugReportCallbackEXT_PreCall(manager->GetBlockIndex(), instance, callback, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugReportMessageEXT_PreCall(manager->GetBlockIndex(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDebugMarkerObjectTagInfoEXT*    pTagInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, device, pTagInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugMarkerObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugMarkerSetObjectTagEXT_PreCall(manager->GetBlockIndex(), device, pTagInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDebugMarkerObjectNameInfoEXT*   pNameInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, device, pNameInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugMarkerObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugMarkerSetObjectNameEXT_PreCall(manager->GetBlockIndex(), device, pNameInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugMarkerMarkerInfoEXT*       pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerBeginEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerEndEXT_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugMarkerMarkerInfoEXT*       pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerInsertEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pMarkerInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindTransformFeedbackBuffersEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstCounterBuffer,
        uint32_t                                counterBufferCount,
        const VkBuffer*                         pCounterBuffers,
        const VkDeviceSize*                     pCounterBufferOffsets)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginTransformFeedbackEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstCounterBuffer,
        uint32_t                                counterBufferCount,
        const VkBuffer*                         pCounterBuffers,
        const VkDeviceSize*                     pCounterBufferOffsets)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndTransformFeedbackEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        VkQueryControlFlags                     flags,
        uint32_t                                index)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, flags, index);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginQueryIndexedEXT_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, query, flags, index);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkQueryPool                             queryPool,
        uint32_t                                query,
        uint32_t                                index)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, commandBuffer, queryPool, query, index);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndQueryIndexedEXT_PreCall(manager->GetBlockIndex(), commandBuffer, queryPool, query, index);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectByteCountEXT_PreCall(manager->GetBlockIndex(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImageViewHandleInfoNVX*         pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImageViewHandleInfoNVX* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageViewHandleNVX_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImageView                             imageView,
        VkImageViewAddressPropertiesNVX*        pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, device, imageView, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageViewAddressNVX_PreCall(manager->GetBlockIndex(), device, imageView, pProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCountAMD_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountAMD_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        VkShaderStageFlagBits                   shaderStage,
        VkShaderInfoTypeAMD                     infoType,
        size_t*                                 pInfoSize,
        void*                                   pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderInfoAMD_PreCall(manager->GetBlockIndex(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateStreamDescriptorSurfaceGGP_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(manager->GetBlockIndex(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        VkExternalMemoryHandleTypeFlagsNV       handleType,
        HANDLE*                                 pHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, device, memory, handleType, pHandle);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandleNV_PreCall(manager->GetBlockIndex(), device, memory, handleType, pHandle);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkViSurfaceCreateInfoNN*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateViSurfaceNN_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, commandBuffer, pConditionalRenderingBegin);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin_unwrapped = UnwrapStructPtrHandles(pConditionalRenderingBegin, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginConditionalRenderingEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pConditionalRenderingBegin);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndConditionalRenderingEXT_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewportWScalingNV*             pViewportWScalings)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportWScalings);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWScalingNV_PreCall(manager->GetBlockIndex(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, physicalDevice, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseDisplayEXT_PreCall(manager->GetBlockIndex(), physicalDevice, display);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        Display*                                dpy,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, physicalDevice, dpy, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireXlibDisplayEXT_PreCall(manager->GetBlockIndex(), physicalDevice, dpy, display);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        Display*                                dpy,
        RROutput                                rrOutput,
        VkDisplayKHR*                           pDisplay)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, physicalDevice, dpy, rrOutput, pDisplay);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRandROutputDisplayEXT_PreCall(manager->GetBlockIndex(), physicalDevice, dpy, rrOutput, pDisplay);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSurfaceKHR                            surface,
        VkSurfaceCapabilities2EXT*              pSurfaceCapabilities)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, physicalDevice, surface, pSurfaceCapabilities);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(manager->GetBlockIndex(), physicalDevice, surface, pSurfaceCapabilities);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDisplayKHR                            display,
        const VkDisplayPowerInfoEXT*            pDisplayPowerInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, device, display, pDisplayPowerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DisplayPowerControlEXT_PreCall(manager->GetBlockIndex(), device, display, pDisplayPowerInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDeviceEventInfoEXT*             pDeviceEventInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, device, pDeviceEventInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.RegisterDeviceEventEXT_PreCall(manager->GetBlockIndex(), device, pDeviceEventInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDisplayKHR                            display,
        const VkDisplayEventInfoEXT*            pDisplayEventInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkFence*                                pFence)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, device, display, pDisplayEventInfo, pAllocator, pFence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.RegisterDisplayEventEXT_PreCall(manager->GetBlockIndex(), device, display, pDisplayEventInfo, pAllocator, pFence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        VkSurfaceCounterFlagBitsEXT             counter,
        uint64_t*                               pCounterValue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, device, swapchain, counter, pCounterValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainCounterEXT_PreCall(manager->GetBlockIndex(), device, swapchain, counter, pCounterValue);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        VkRefreshCycleDurationGOOGLE*           pDisplayTimingProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, device, swapchain, pDisplayTimingProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRefreshCycleDurationGOOGLE_PreCall(manager->GetBlockIndex(), device, swapchain, pDisplayTimingProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain,
        uint32_t*                               pPresentationTimingCount,
        VkPastPresentationTimingGOOGLE*         pPresentationTimings)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, device, swapchain, pPresentationTimingCount, pPresentationTimings);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPastPresentationTimingGOOGLE_PreCall(manager->GetBlockIndex(), device, swapchain, pPresentationTimingCount, pPresentationTimings);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstDiscardRectangle,
        uint32_t                                discardRectangleCount,
        const VkRect2D*                         pDiscardRectangles)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                discardRectangleEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, commandBuffer, discardRectangleEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, discardRectangleEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkDiscardRectangleModeEXT               discardRectangleMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, commandBuffer, discardRectangleMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, discardRectangleMode);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                swapchainCount,
        const VkSwapchainKHR*                   pSwapchains,
        const VkHdrMetadataEXT*                 pMetadata)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, device, swapchainCount, pSwapchains, pMetadata);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetHdrMetadataEXT_PreCall(manager->GetBlockIndex(), device, swapchainCount, pSwapchains, pMetadata);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkIOSSurfaceCreateInfoMVK*        pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateIOSSurfaceMVK_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkMacOSSurfaceCreateInfoMVK*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMacOSSurfaceMVK_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDebugUtilsObjectNameInfoEXT*    pNameInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, device, pNameInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugUtilsObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDebugUtilsObjectNameEXT_PreCall(manager->GetBlockIndex(), device, pNameInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDebugUtilsObjectTagInfoEXT*     pTagInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, device, pTagInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDebugUtilsObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDebugUtilsObjectTagEXT_PreCall(manager->GetBlockIndex(), device, pTagInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueBeginDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), queue, pLabelInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, queue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueEndDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), queue);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, queue, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueInsertDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), queue, pLabelInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pLabelInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), commandBuffer);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkDebugUtilsLabelEXT*             pLabelInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, commandBuffer, pLabelInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdInsertDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pLabelInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkDebugUtilsMessengerEXT*               pMessenger)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pMessenger);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDebugUtilsMessengerEXT_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pMessenger);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugUtilsMessengerEXT                messenger,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, instance, messenger, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDebugUtilsMessengerEXT_PreCall(manager->GetBlockIndex(), instance, messenger, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT  messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT         messageTypes,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, pCallbackData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SubmitDebugUtilsMessageEXT_PreCall(manager->GetBlockIndex(), instance, messageSeverity, messageTypes, pCallbackData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const struct AHardwareBuffer*           buffer,
        VkAndroidHardwareBufferPropertiesANDROID* pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, device, buffer, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAndroidHardwareBufferPropertiesANDROID_PreCall(manager->GetBlockIndex(), device, buffer, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
        struct AHardwareBuffer**                pBuffer)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, device, pInfo, pBuffer);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryAndroidHardwareBufferANDROID_PreCall(manager->GetBlockIndex(), device, pInfo, pBuffer);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkSampleLocationsInfoEXT*         pSampleLocationsInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, commandBuffer, pSampleLocationsInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleLocationsEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pSampleLocationsInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkSampleCountFlagBits                   samples,
        VkMultisamplePropertiesEXT*             pMultisampleProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, physicalDevice, samples, pMultisampleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(manager->GetBlockIndex(), physicalDevice, samples, pMultisampleProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        VkImageDrmFormatModifierPropertiesEXT*  pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, device, image, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageDrmFormatModifierPropertiesEXT_PreCall(manager->GetBlockIndex(), device, image, pProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkValidationCacheCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkValidationCacheEXT*                   pValidationCache)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pValidationCache);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateValidationCacheEXT_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pValidationCache);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkValidationCacheEXT                    validationCache,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, device, validationCache, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyValidationCacheEXT_PreCall(manager->GetBlockIndex(), device, validationCache, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkValidationCacheEXT                    dstCache,
        uint32_t                                srcCacheCount,
        const VkValidationCacheEXT*             pSrcCaches)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, device, dstCache, srcCacheCount, pSrcCaches);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MergeValidationCachesEXT_PreCall(manager->GetBlockIndex(), device, dstCache, srcCacheCount, pSrcCaches);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkValidationCacheEXT                    validationCache,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, device, validationCache, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetValidationCacheDataEXT_PreCall(manager->GetBlockIndex(), device, validationCache, pDataSize, pData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImageView                             imageView,
        VkImageLayout                           imageLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, commandBuffer, imageView, imageLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindShadingRateImageNV_PreCall(manager->GetBlockIndex(), commandBuffer, imageView, imageLayout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkShadingRatePaletteNV*           pShadingRatePalettes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportShadingRatePaletteNV_PreCall(manager->GetBlockIndex(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoarseSampleOrderTypeNV               sampleOrderType,
        uint32_t                                customSampleOrderCount,
        const VkCoarseSampleOrderCustomNV*      pCustomSampleOrders)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoarseSampleOrderNV_PreCall(manager->GetBlockIndex(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkAccelerationStructureNV*              pAccelerationStructure)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pAccelerationStructure);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAccelerationStructureNV_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pAccelerationStructure);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureNV               accelerationStructure,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, device, accelerationStructure, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyAccelerationStructureNV_PreCall(manager->GetBlockIndex(), device, accelerationStructure, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
        VkMemoryRequirements2KHR*               pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureMemoryRequirementsNV_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                bindInfoCount,
        const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, device, bindInfoCount, pBindInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBindAccelerationStructureMemoryInfoNV* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindAccelerationStructureMemoryNV_PreCall(manager->GetBlockIndex(), device, bindInfoCount, pBindInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructureNV_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkAccelerationStructureNV               dst,
        VkAccelerationStructureNV               src,
        VkCopyAccelerationStructureModeKHR      mode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, commandBuffer, dst, src, mode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureNV_PreCall(manager->GetBlockIndex(), commandBuffer, dst, src, mode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysNV_PreCall(manager->GetBlockIndex(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkRayTracingPipelineCreateInfoNV* pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRayTracingPipelineCreateInfoNV* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRayTracingPipelinesNV_PreCall(manager->GetBlockIndex(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesKHR_PreCall(manager->GetBlockIndex(), device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesNV_PreCall(manager->GetBlockIndex(), device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureNV               accelerationStructure,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, device, accelerationStructure, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureHandleNV_PreCall(manager->GetBlockIndex(), device, accelerationStructure, dataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesNV_PreCall(manager->GetBlockIndex(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                shader)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, device, pipeline, shader);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CompileDeferredNV_PreCall(manager->GetBlockIndex(), device, pipeline, shader);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        const void*                             pHostPointer,
        VkMemoryHostPointerPropertiesEXT*       pMemoryHostPointerProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, device, handleType, pHostPointer, pMemoryHostPointerProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryHostPointerPropertiesEXT_PreCall(manager->GetBlockIndex(), device, handleType, pHostPointer, pMemoryHostPointerProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineStageFlagBits                 pipelineStage,
        VkBuffer                                dstBuffer,
        VkDeviceSize                            dstOffset,
        uint32_t                                marker)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteBufferMarkerAMD_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pTimeDomainCount,
        VkTimeDomainEXT*                        pTimeDomains)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, physicalDevice, pTimeDomainCount, pTimeDomains);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(manager->GetBlockIndex(), physicalDevice, pTimeDomainCount, pTimeDomains);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                timestampCount,
        const VkCalibratedTimestampInfoEXT*     pTimestampInfos,
        uint64_t*                               pTimestamps,
        uint64_t*                               pMaxDeviation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetCalibratedTimestampsEXT_PreCall(manager->GetBlockIndex(), device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                taskCount,
        uint32_t                                firstTask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, commandBuffer, taskCount, firstTask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksNV_PreCall(manager->GetBlockIndex(), commandBuffer, taskCount, firstTask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectNV_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountNV_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstExclusiveScissor,
        uint32_t                                exclusiveScissorCount,
        const VkBool32*                         pExclusiveScissorEnables)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExclusiveScissorEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstExclusiveScissor,
        uint32_t                                exclusiveScissorCount,
        const VkRect2D*                         pExclusiveScissors)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExclusiveScissorNV_PreCall(manager->GetBlockIndex(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const void*                             pCheckpointMarker)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, commandBuffer, pCheckpointMarker);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCheckpointNV_PreCall(manager->GetBlockIndex(), commandBuffer, pCheckpointMarker);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        uint32_t*                               pCheckpointDataCount,
        VkCheckpointDataNV*                     pCheckpointData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, queue, pCheckpointDataCount, pCheckpointData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueueCheckpointDataNV_PreCall(manager->GetBlockIndex(), queue, pCheckpointDataCount, pCheckpointData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkInitializePerformanceApiInfoINTEL* pInitializeInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, device, pInitializeInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.InitializePerformanceApiINTEL_PreCall(manager->GetBlockIndex(), device, pInitializeInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, device);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UninitializePerformanceApiINTEL_PreCall(manager->GetBlockIndex(), device);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceMarkerInfoINTEL*     pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceMarkerINTEL_PreCall(manager->GetBlockIndex(), commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, commandBuffer, pMarkerInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceStreamMarkerINTEL_PreCall(manager->GetBlockIndex(), commandBuffer, pMarkerInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkPerformanceOverrideInfoINTEL*   pOverrideInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, commandBuffer, pOverrideInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceOverrideINTEL_PreCall(manager->GetBlockIndex(), commandBuffer, pOverrideInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
        VkPerformanceConfigurationINTEL*        pConfiguration)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, device, pAcquireInfo, pConfiguration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquirePerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), device, pAcquireInfo, pConfiguration);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPerformanceConfigurationINTEL         configuration)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, device, configuration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleasePerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), device, configuration);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkQueue                                 queue,
        VkPerformanceConfigurationINTEL         configuration)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, queue, configuration);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSetPerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), queue, configuration);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPerformanceParameterTypeINTEL         parameter,
        VkPerformanceValueINTEL*                pValue)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, device, parameter, pValue);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPerformanceParameterINTEL_PreCall(manager->GetBlockIndex(), device, parameter, pValue);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapChain,
        VkBool32                                localDimmingEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, device, swapChain, localDimmingEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetLocalDimmingAMD_PreCall(manager->GetBlockIndex(), device, swapChain, localDimmingEnable);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImagePipeSurfaceFUCHSIA_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkMetalSurfaceCreateInfoEXT*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMetalSurfaceEXT_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkBufferDeviceAddressInfo*        pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddressEXT_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pToolCount,
        VkPhysicalDeviceToolProperties*         pToolProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, physicalDevice, pToolCount, pToolProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceToolPropertiesEXT_PreCall(manager->GetBlockIndex(), physicalDevice, pToolCount, pToolProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pPropertyCount,
        VkCooperativeMatrixPropertiesNV*        pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, physicalDevice, pPropertyCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(manager->GetBlockIndex(), physicalDevice, pPropertyCount, pProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t*                               pCombinationCount,
        VkFramebufferMixedSamplesCombinationNV* pCombinations)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, physicalDevice, pCombinationCount, pCombinations);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(manager->GetBlockIndex(), physicalDevice, pCombinationCount, pCombinations);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        uint32_t*                               pPresentModeCount,
        VkPresentModeKHR*                       pPresentModes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(manager->GetBlockIndex(), physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireFullScreenExclusiveModeEXT_PreCall(manager->GetBlockIndex(), device, swapchain);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkSwapchainKHR                          swapchain)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, device, swapchain);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseFullScreenExclusiveModeEXT_PreCall(manager->GetBlockIndex(), device, swapchain);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPhysicalDeviceSurfaceInfo2KHR*  pSurfaceInfo,
        VkDeviceGroupPresentModeFlagsKHR*       pModes)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, device, pSurfaceInfo, pModes);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModes2EXT_PreCall(manager->GetBlockIndex(), device, pSurfaceInfo, pModes);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkHeadlessSurfaceCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateHeadlessSurfaceEXT_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                lineStippleFactor,
        uint16_t                                lineStipplePattern)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, commandBuffer, lineStippleFactor, lineStipplePattern);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineStippleEXT_PreCall(manager->GetBlockIndex(), commandBuffer, lineStippleFactor, lineStipplePattern);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkQueryPool                             queryPool,
        uint32_t                                firstQuery,
        uint32_t                                queryCount)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, device, queryPool, firstQuery, queryCount);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetQueryPoolEXT_PreCall(manager->GetBlockIndex(), device, queryPool, firstQuery, queryCount);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCullModeFlags                         cullMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, commandBuffer, cullMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCullModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, cullMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFrontFace                             frontFace)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, commandBuffer, frontFace);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFrontFaceEXT_PreCall(manager->GetBlockIndex(), commandBuffer, frontFace);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPrimitiveTopology                     primitiveTopology)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, commandBuffer, primitiveTopology);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveTopologyEXT_PreCall(manager->GetBlockIndex(), commandBuffer, primitiveTopology);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                viewportCount,
        const VkViewport*                       pViewports)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, commandBuffer, viewportCount, pViewports);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWithCountEXT_PreCall(manager->GetBlockIndex(), commandBuffer, viewportCount, pViewports);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                scissorCount,
        const VkRect2D*                         pScissors)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, commandBuffer, scissorCount, pScissors);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissorWithCountEXT_PreCall(manager->GetBlockIndex(), commandBuffer, scissorCount, pScissors);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers2EXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, commandBuffer, depthTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthTestEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthWriteEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, commandBuffer, depthWriteEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthWriteEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthWriteEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCompareOp                             depthCompareOp)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, commandBuffer, depthCompareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthCompareOpEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthCompareOp);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBoundsTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, commandBuffer, depthBoundsTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthBoundsTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stencilTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, commandBuffer, stencilTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilTestEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, stencilTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilOpEXT_PreCall(manager->GetBlockIndex(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkReleaseSwapchainImagesInfoEXT*  pReleaseInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, device, pReleaseInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo_unwrapped = UnwrapStructPtrHandles(pReleaseInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseSwapchainImagesEXT_PreCall(manager->GetBlockIndex(), device, pReleaseInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
        VkMemoryRequirements2*                  pMemoryRequirements)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, device, pInfo, pMemoryRequirements);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetGeneratedCommandsMemoryRequirementsNV_PreCall(manager->GetBlockIndex(), device, pInfo, pMemoryRequirements);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkGeneratedCommandsInfoNV*        pGeneratedCommandsInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, commandBuffer, pGeneratedCommandsInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPreprocessGeneratedCommandsNV_PreCall(manager->GetBlockIndex(), commandBuffer, pGeneratedCommandsInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                isPreprocessed,
        const VkGeneratedCommandsInfoNV*        pGeneratedCommandsInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdExecuteGeneratedCommandsNV_PreCall(manager->GetBlockIndex(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPipelineBindPoint                     pipelineBindPoint,
        VkPipeline                              pipeline,
        uint32_t                                groupIndex)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, commandBuffer, pipelineBindPoint, pipeline, groupIndex);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindPipelineShaderGroupNV_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkIndirectCommandsLayoutNV*             pIndirectCommandsLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateIndirectCommandsLayoutNV_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkIndirectCommandsLayoutNV              indirectCommandsLayout,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, device, indirectCommandsLayout, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyIndirectCommandsLayoutNV_PreCall(manager->GetBlockIndex(), device, indirectCommandsLayout, pAllocator);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        int32_t                                 drmFd,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, physicalDevice, drmFd, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireDrmDisplayEXT_PreCall(manager->GetBlockIndex(), physicalDevice, drmFd, display);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        int32_t                                 drmFd,
        uint32_t                                connectorId,
        VkDisplayKHR*                           display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, physicalDevice, drmFd, connectorId, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDrmDisplayEXT_PreCall(manager->GetBlockIndex(), physicalDevice, drmFd, connectorId, display);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkPrivateDataSlotCreateInfo*      pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkPrivateDataSlot*                      pPrivateDataSlot)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pPrivateDataSlot);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePrivateDataSlotEXT_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pPrivateDataSlot);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPrivateDataSlot                       privateDataSlot,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, device, privateDataSlot, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPrivateDataSlotEXT_PreCall(manager->GetBlockIndex(), device, privateDataSlot, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t                                data)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, data);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetPrivateDataEXT_PreCall(manager->GetBlockIndex(), device, objectType, objectHandle, privateDataSlot, data);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkObjectType                            objectType,
        uint64_t                                objectHandle,
        VkPrivateDataSlot                       privateDataSlot,
        uint64_t*                               pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, device, objectType, objectHandle, privateDataSlot, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPrivateDataEXT_PreCall(manager->GetBlockIndex(), device, objectType, objectHandle, privateDataSlot, pData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkFragmentShadingRateNV                 shadingRate,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2])
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, commandBuffer, shadingRate, combinerOps);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateEnumNV_PreCall(manager->GetBlockIndex(), commandBuffer, shadingRate, combinerOps);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkImage                                 image,
        const VkImageSubresource2EXT*           pSubresource,
        VkSubresourceLayout2EXT*                pLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, device, image, pSubresource, pLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSubresourceLayout2EXT_PreCall(manager->GetBlockIndex(), device, image, pSubresource, pLayout);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceFaultCountsEXT*                 pFaultCounts,
        VkDeviceFaultInfoEXT*                   pFaultInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, device, pFaultCounts, pFaultInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceFaultInfoEXT_PreCall(manager->GetBlockIndex(), device, pFaultCounts, pFaultInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        VkDisplayKHR                            display)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, physicalDevice, display);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireWinrtDisplayNV_PreCall(manager->GetBlockIndex(), physicalDevice, display);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                deviceRelativeId,
        VkDisplayKHR*                           pDisplay)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, physicalDevice, deviceRelativeId, pDisplay);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetWinrtDisplayNV_PreCall(manager->GetBlockIndex(), physicalDevice, deviceRelativeId, pDisplay);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkDirectFBSurfaceCreateInfoEXT*   pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDirectFBSurfaceEXT_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        IDirectFB*                              dfb)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, physicalDevice, queueFamilyIndex, dfb);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, dfb);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                vertexBindingDescriptionCount,
        const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
        uint32_t                                vertexAttributeDescriptionCount,
        const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetVertexInputEXT_PreCall(manager->GetBlockIndex(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
        zx_handle_t*                            pZirconHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, device, pGetZirconHandleInfo, pZirconHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), device, pGetZirconHandleInfo, pZirconHandle);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkExternalMemoryHandleTypeFlagBits      handleType,
        zx_handle_t                             zirconHandle,
        VkMemoryZirconHandlePropertiesFUCHSIA*  pMemoryZirconHandleProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, device, handleType, zirconHandle, pMemoryZirconHandleProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(manager->GetBlockIndex(), device, handleType, zirconHandle, pMemoryZirconHandleProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, device, pImportSemaphoreZirconHandleInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), device, pImportSemaphoreZirconHandleInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
        zx_handle_t*                            pZirconHandle)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, device, pGetZirconHandleInfo, pZirconHandle);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), device, pGetZirconHandleInfo, pZirconHandle);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkImageView                             imageView,
        VkImageLayout                           imageLayout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, commandBuffer, imageView, imageLayout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindInvocationMaskHUAWEI_PreCall(manager->GetBlockIndex(), commandBuffer, imageView, imageLayout);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMemoryGetRemoteAddressInfoNV*   pMemoryGetRemoteAddressInfo,
        VkRemoteAddressNV*                      pAddress)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, device, pMemoryGetRemoteAddressInfo, pAddress);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo_unwrapped = UnwrapStructPtrHandles(pMemoryGetRemoteAddressInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryRemoteAddressNV_PreCall(manager->GetBlockIndex(), device, pMemoryGetRemoteAddressInfo, pAddress);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                patchControlPoints)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, commandBuffer, patchControlPoints);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPatchControlPointsEXT_PreCall(manager->GetBlockIndex(), commandBuffer, patchControlPoints);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                rasterizerDiscardEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, commandBuffer, rasterizerDiscardEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, rasterizerDiscardEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthBiasEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, commandBuffer, depthBiasEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBiasEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthBiasEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkLogicOp                               logicOp)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, commandBuffer, logicOp);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLogicOpEXT_PreCall(manager->GetBlockIndex(), commandBuffer, logicOp);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                primitiveRestartEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, commandBuffer, primitiveRestartEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, primitiveRestartEnable);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkInstance                              instance,
        const VkScreenSurfaceCreateInfoQNX*     pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkSurfaceKHR*                           pSurface)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, instance, pCreateInfo, pAllocator, pSurface);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateScreenSurfaceQNX_PreCall(manager->GetBlockIndex(), instance, pCreateInfo, pAllocator, pSurface);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        uint32_t                                queueFamilyIndex,
        struct _screen_window*                  window)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, physicalDevice, queueFamilyIndex, window);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(manager->GetBlockIndex(), physicalDevice, queueFamilyIndex, window);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                attachmentCount,
        const VkBool32*                         pColorWriteEnables)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, commandBuffer, attachmentCount, pColorWriteEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorWriteEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, attachmentCount, pColorWriteEnables);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMultiEXT_PreCall(manager->GetBlockIndex(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMultiIndexedEXT_PreCall(manager->GetBlockIndex(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMicromapCreateInfoEXT*          pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkMicromapEXT*                          pMicromap)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, device, pCreateInfo, pAllocator, pMicromap);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapCreateInfoEXT* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMicromapEXT_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pMicromap);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkMicromapEXT                           micromap,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, device, micromap, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyMicromapEXT_PreCall(manager->GetBlockIndex(), device, micromap, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                infoCount,
        const VkMicromapBuildInfoEXT*           pInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, commandBuffer, infoCount, pInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildMicromapsEXT_PreCall(manager->GetBlockIndex(), commandBuffer, infoCount, pInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        uint32_t                                infoCount,
        const VkMicromapBuildInfoEXT*           pInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, device, deferredOperation, infoCount, pInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BuildMicromapsEXT_PreCall(manager->GetBlockIndex(), device, deferredOperation, infoCount, pInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMicromapInfoEXT*            pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMicromapEXT_PreCall(manager->GetBlockIndex(), device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMicromapToMemoryInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMicromapToMemoryEXT_PreCall(manager->GetBlockIndex(), device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMemoryToMicromapInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMemoryToMicromapEXT_PreCall(manager->GetBlockIndex(), device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                micromapCount,
        const VkMicromapEXT*                    pMicromaps,
        VkQueryType                             queryType,
        size_t                                  dataSize,
        void*                                   pData,
        size_t                                  stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WriteMicromapsPropertiesEXT_PreCall(manager->GetBlockIndex(), device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMicromapInfoEXT*            pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMicromapEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMicromapToMemoryInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMicromapToMemoryEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMemoryToMicromapInfoEXT*    pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMemoryToMicromapEXT_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteMicromapsPropertiesEXT_PreCall(manager->GetBlockIndex(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkMicromapVersionInfoEXT*         pVersionInfo,
        VkAccelerationStructureCompatibilityKHR* pCompatibility)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, device, pVersionInfo, pCompatibility);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMicromapCompatibilityEXT_PreCall(manager->GetBlockIndex(), device, pVersionInfo, pCompatibility);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureBuildTypeKHR     buildType,
        const VkMicromapBuildInfoEXT*           pBuildInfo,
        VkMicromapBuildSizesInfoEXT*            pSizeInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, device, buildType, pBuildInfo, pSizeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkMicromapBuildInfoEXT* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMicromapBuildSizesEXT_PreCall(manager->GetBlockIndex(), device, buildType, pBuildInfo, pSizeInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawClusterHUAWEI_PreCall(manager->GetBlockIndex(), commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, commandBuffer, buffer, offset);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawClusterIndirectHUAWEI_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeviceMemory                          memory,
        float                                   priority)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, device, memory, priority);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDeviceMemoryPriorityEXT_PreCall(manager->GetBlockIndex(), device, memory, priority);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
        VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, device, pBindingReference, pHostMapping);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkDescriptorSetBindingReferenceVALVE* pBindingReference_unwrapped = UnwrapStructPtrHandles(pBindingReference, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(manager->GetBlockIndex(), device, pBindingReference, pHostMapping);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDescriptorSet                         descriptorSet,
        void**                                  ppData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, device, descriptorSet, ppData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetHostMappingVALVE_PreCall(manager->GetBlockIndex(), device, descriptorSet, ppData);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkTessellationDomainOrigin              domainOrigin)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, commandBuffer, domainOrigin);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetTessellationDomainOriginEXT_PreCall(manager->GetBlockIndex(), commandBuffer, domainOrigin);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthClampEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, commandBuffer, depthClampEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClampEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthClampEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkPolygonMode                           polygonMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, commandBuffer, polygonMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPolygonModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, polygonMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSampleCountFlagBits                   rasterizationSamples)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, commandBuffer, rasterizationSamples);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizationSamplesEXT_PreCall(manager->GetBlockIndex(), commandBuffer, rasterizationSamples);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkSampleCountFlagBits                   samples,
        const VkSampleMask*                     pSampleMask)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, commandBuffer, samples, pSampleMask);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleMaskEXT_PreCall(manager->GetBlockIndex(), commandBuffer, samples, pSampleMask);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                alphaToCoverageEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, commandBuffer, alphaToCoverageEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetAlphaToCoverageEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, alphaToCoverageEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                alphaToOneEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, commandBuffer, alphaToOneEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetAlphaToOneEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, alphaToOneEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                logicOpEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, commandBuffer, logicOpEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLogicOpEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, logicOpEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkBool32*                         pColorBlendEnables)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorBlendEquationEXT*          pColorBlendEquations)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendEquationEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorComponentFlags*            pColorWriteMasks)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorWriteMaskEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                rasterizationStream)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, commandBuffer, rasterizationStream);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizationStreamEXT_PreCall(manager->GetBlockIndex(), commandBuffer, rasterizationStream);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkConservativeRasterizationModeEXT      conservativeRasterizationMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, commandBuffer, conservativeRasterizationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetConservativeRasterizationModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, conservativeRasterizationMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        float                                   extraPrimitiveOverestimationSize)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, commandBuffer, extraPrimitiveOverestimationSize);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, extraPrimitiveOverestimationSize);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                depthClipEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, commandBuffer, depthClipEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClipEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, depthClipEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                sampleLocationsEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, commandBuffer, sampleLocationsEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleLocationsEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, sampleLocationsEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstAttachment,
        uint32_t                                attachmentCount,
        const VkColorBlendAdvancedEXT*          pColorBlendAdvanced)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendAdvancedEXT_PreCall(manager->GetBlockIndex(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkProvokingVertexModeEXT                provokingVertexMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, commandBuffer, provokingVertexMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetProvokingVertexModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, provokingVertexMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkLineRasterizationModeEXT              lineRasterizationMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, commandBuffer, lineRasterizationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineRasterizationModeEXT_PreCall(manager->GetBlockIndex(), commandBuffer, lineRasterizationMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                stippledLineEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, commandBuffer, stippledLineEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineStippleEnableEXT_PreCall(manager->GetBlockIndex(), commandBuffer, stippledLineEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                negativeOneToOne)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, commandBuffer, negativeOneToOne);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClipNegativeOneToOneEXT_PreCall(manager->GetBlockIndex(), commandBuffer, negativeOneToOne);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                viewportWScalingEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, commandBuffer, viewportWScalingEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWScalingEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, viewportWScalingEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                firstViewport,
        uint32_t                                viewportCount,
        const VkViewportSwizzleNV*              pViewportSwizzles)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, commandBuffer, firstViewport, viewportCount, pViewportSwizzles);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportSwizzleNV_PreCall(manager->GetBlockIndex(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                coverageToColorEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, commandBuffer, coverageToColorEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageToColorEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageToColorEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                coverageToColorLocation)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, commandBuffer, coverageToColorLocation);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageToColorLocationNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageToColorLocation);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoverageModulationModeNV              coverageModulationMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, commandBuffer, coverageModulationMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationModeNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageModulationMode);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                coverageModulationTableEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, commandBuffer, coverageModulationTableEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageModulationTableEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                coverageModulationTableCount,
        const float*                            pCoverageModulationTable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, commandBuffer, coverageModulationTableCount, pCoverageModulationTable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                shadingRateImageEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, commandBuffer, shadingRateImageEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetShadingRateImageEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, shadingRateImageEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBool32                                representativeFragmentTestEnable)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, commandBuffer, representativeFragmentTestEnable);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRepresentativeFragmentTestEnableNV_PreCall(manager->GetBlockIndex(), commandBuffer, representativeFragmentTestEnable);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkCoverageReductionModeNV               coverageReductionMode)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, commandBuffer, coverageReductionMode);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageReductionModeNV_PreCall(manager->GetBlockIndex(), commandBuffer, coverageReductionMode);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderModule                          shaderModule,
        VkShaderModuleIdentifierEXT*            pIdentifier)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, device, shaderModule, pIdentifier);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderModuleIdentifierEXT_PreCall(manager->GetBlockIndex(), device, shaderModule, pIdentifier);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkShaderModuleCreateInfo*         pCreateInfo,
        VkShaderModuleIdentifierEXT*            pIdentifier)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, device, pCreateInfo, pIdentifier);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderModuleCreateInfoIdentifierEXT_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pIdentifier);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkPhysicalDevice                        physicalDevice,
        const VkOpticalFlowImageFormatInfoNV*   pOpticalFlowImageFormatInfo,
        uint32_t*                               pFormatCount,
        VkOpticalFlowImageFormatPropertiesNV*   pImageFormatProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(manager->GetBlockIndex(), physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkOpticalFlowSessionCreateInfoNV* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkOpticalFlowSessionNV*                 pSession)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, device, pCreateInfo, pAllocator, pSession);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateOpticalFlowSessionNV_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pSession);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkOpticalFlowSessionNV                  session,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, device, session, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyOpticalFlowSessionNV_PreCall(manager->GetBlockIndex(), device, session, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkOpticalFlowSessionNV                  session,
        VkOpticalFlowSessionBindingPointNV      bindingPoint,
        VkImageView                             view,
        VkImageLayout                           layout)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, device, session, bindingPoint, view, layout);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindOpticalFlowSessionImageNV_PreCall(manager->GetBlockIndex(), device, session, bindingPoint, view, layout);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkOpticalFlowSessionNV                  session,
        const VkOpticalFlowExecuteInfoNV*       pExecuteInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, commandBuffer, session, pExecuteInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdOpticalFlowExecuteNV_PreCall(manager->GetBlockIndex(), commandBuffer, session, pExecuteInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateShadersEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                createInfoCount,
        const VkShaderCreateInfoEXT*            pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkShaderEXT*                            pShaders)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShadersEXT>::Dispatch(manager, device, createInfoCount, pCreateInfos, pAllocator, pShaders);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkShaderCreateInfoEXT* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateShadersEXT_PreCall(manager->GetBlockIndex(), device, createInfoCount, pCreateInfos, pAllocator, pShaders);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderEXT                             shader,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderEXT>::Dispatch(manager, device, shader, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyShaderEXT_PreCall(manager->GetBlockIndex(), device, shader, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkShaderEXT                             shader,
        size_t*                                 pDataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT>::Dispatch(manager, device, shader, pDataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderBinaryDataEXT_PreCall(manager->GetBlockIndex(), device, shader, pDataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadersEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                stageCount,
        const VkShaderStageFlagBits*            pStages,
        const VkShaderEXT*                      pShaders)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadersEXT>::Dispatch(manager, commandBuffer, stageCount, pStages, pShaders);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindShadersEXT_PreCall(manager->GetBlockIndex(), commandBuffer, stageCount, pStages, pShaders);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkFramebuffer                           framebuffer,
        uint32_t*                               pPropertiesCount,
        VkTilePropertiesQCOM*                   pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, device, framebuffer, pPropertiesCount, pProperties);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFramebufferTilePropertiesQCOM_PreCall(manager->GetBlockIndex(), device, framebuffer, pPropertiesCount, pProperties);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkRenderingInfo*                  pRenderingInfo,
        VkTilePropertiesQCOM*                   pProperties)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, device, pRenderingInfo, pProperties);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDynamicRenderingTilePropertiesQCOM_PreCall(manager->GetBlockIndex(), device, pRenderingInfo, pProperties);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*            pAllocator,
        VkAccelerationStructureKHR*             pAccelerationStructure)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, device, pCreateInfo, pAllocator, pAccelerationStructure);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), device, pCreateInfo, pAllocator, pAccelerationStructure);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureKHR              accelerationStructure,
        const VkAllocationCallbacks*            pAllocator)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, device, accelerationStructure, pAllocator);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), device, accelerationStructure, pAllocator);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                infoCount,
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresKHR_PreCall(manager->GetBlockIndex(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresIndirectKHR_PreCall(manager->GetBlockIndex(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyAccelerationStructureToMemoryKHR_PreCall(manager->GetBlockIndex(), device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, device, deferredOperation, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMemoryToAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), device, deferredOperation, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        uint32_t                                accelerationStructureCount,
        const VkAccelerationStructureKHR*       pAccelerationStructures,
        VkQueryType                             queryType,
        size_t                                  dataSize,
        void*                                   pData,
        size_t                                  stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WriteAccelerationStructuresPropertiesKHR_PreCall(manager->GetBlockIndex(), device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureToMemoryKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, commandBuffer, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMemoryToAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, device, pInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureDeviceAddressInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureDeviceAddressKHR_PreCall(manager->GetBlockIndex(), device, pInfo);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesKHR_PreCall(manager->GetBlockIndex(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
        VkAccelerationStructureCompatibilityKHR* pCompatibility)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, device, pVersionInfo, pCompatibility);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceAccelerationStructureCompatibilityKHR_PreCall(manager->GetBlockIndex(), device, pVersionInfo, pCompatibility);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkAccelerationStructureBuildTypeKHR     buildType,
        const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
        const uint32_t*                         pMaxPrimitiveCounts,
        VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureBuildSizesKHR_PreCall(manager->GetBlockIndex(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkDeferredOperationKHR                  deferredOperation,
        VkPipelineCache                         pipelineCache,
        uint32_t                                createInfoCount,
        const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
        const VkAllocationCallbacks*            pAllocator,
        VkPipeline*                             pPipelines)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkRayTracingPipelineCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRayTracingPipelinesKHR_PreCall(manager->GetBlockIndex(), device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                firstGroup,
        uint32_t                                groupCount,
        size_t                                  dataSize,
        void*                                   pData)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, device, pipeline, firstGroup, groupCount, dataSize, pData);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(manager->GetBlockIndex(), device, pipeline, firstGroup, groupCount, dataSize, pData);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysIndirectKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkDevice                                device,
        VkPipeline                              pipeline,
        uint32_t                                group,
        VkShaderGroupShaderKHR                  groupShader)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, device, pipeline, group, groupShader);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupStackSizeKHR_PreCall(manager->GetBlockIndex(), device, pipeline, group, groupShader);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                pipelineStackSize)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, commandBuffer, pipelineStackSize);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRayTracingPipelineStackSizeKHR_PreCall(manager->GetBlockIndex(), commandBuffer, pipelineStackSize);
        }
    }
};


template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        uint32_t                                groupCountX,
        uint32_t                                groupCountY,
        uint32_t                                groupCountZ)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, commandBuffer, groupCountX, groupCountY, groupCountZ);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksEXT_PreCall(manager->GetBlockIndex(), commandBuffer, groupCountX, groupCountY, groupCountZ);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    static void Dispatch(VulkanCaptureManager* manager,
        VkCommandBuffer                         commandBuffer,
        VkBuffer                                buffer,
        VkDeviceSize                            offset,
        uint32_t                                drawCount,
        uint32_t                                stride)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, commandBuffer, buffer, offset, drawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectEXT_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, drawCount, stride);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
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

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountEXT_PreCall(manager->GetBlockIndex(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
        }
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H
