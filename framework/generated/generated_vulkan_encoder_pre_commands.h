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

#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H

#include "encode/vulkan_capture_manager.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "format/api_call_id.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

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
    static void Dispatch(VulkanCaptureManager* manager, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
    {
        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, pCreateInfo, pAllocator, pInstance);

        // for (auto &plugin : manager->GetLoadedPlugins())
        // {
        //     plugin.func_table_pre.CreateInstance_PreCall(manager->GetBlockIndex(), pCreateInfo, pAllocator, pInstance);
        // }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    static void Dispatch(VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator)
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
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    static void Dispatch(VulkanCaptureManager* manager, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
    {
        assert(manager);
        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, queue, submitCount, pSubmits, fence);

        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit_PreCall(manager->GetBlockIndex(), queue, submitCount, pSubmits_unwrapped, fence);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager, VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, queue, pPresentInfo);
        auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
        const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueuePresentKHR_PreCall(manager->GetBlockIndex(), queue, pPresentInfo_unwrapped);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDevices_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDevice_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDevice_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceQueue_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueWaitIdle_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DeviceWaitIdle_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MapMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UnmapMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FlushMappedMemoryRanges_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.InvalidateMappedMemoryRanges_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryCommitment_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueBindSparse_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateFence_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyFence_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetFences_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceStatus_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitForFences_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSemaphore_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySemaphore_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetEventStatus_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateQueryPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyQueryPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueryPoolResults_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateBufferView_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyBufferView_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSubresourceLayout_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImageView_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyImageView_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateShaderModule_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyShaderModule_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePipelineCache_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipelineCache_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineCacheData_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MergePipelineCaches_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateGraphicsPipelines_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateComputePipelines_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipeline_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePipelineLayout_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPipelineLayout_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSampler_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySampler_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorSetLayout_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorSetLayout_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetDescriptorPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateDescriptorSets_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeDescriptorSets_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateDescriptorSets_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateFramebuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyFramebuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyRenderPass_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRenderAreaGranularity_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateCommandPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyCommandPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetCommandPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AllocateCommandBuffers_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.FreeCommandBuffers_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BeginCommandBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EndCommandBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetCommandBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindPipeline_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewport_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissor_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineWidth_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBias_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetBlendConstants_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBounds_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilCompareMask_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilWriteMask_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilReference_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindDescriptorSets_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindIndexBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDraw_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexed_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirect_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirect_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatch_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchIndirect_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdUpdateBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdFillBuffer_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearColorImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearDepthStencilImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdClearAttachments_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginQuery_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndQuery_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetQueryPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyQueryPoolResults_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPushConstants_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdExecuteCommands_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeatures_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDeviceMask_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchBase_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroups_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.TrimCommandPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceQueue2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversion_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversion_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplate_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplate_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFenceProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphoreProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupport_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCount_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCount_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetQueryPool_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreCounterValue_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitSemaphores_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SignalSemaphore_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddress_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddress_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddress_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceToolProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePrivateDataSlot_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPrivateDataSlot_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetPrivateData_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPrivateData_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRendering_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRendering_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCullMode_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFrontFace_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveTopology_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWithCount_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissorWithCount_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers2_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthTestEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthWriteEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthCompareOp_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilTestEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilOp_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBiasEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnable_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirements_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilitiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormatsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSwapchainKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySwapchainKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainImagesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireNextImageKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPresentCapabilitiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDevicePresentRectanglesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireNextImage2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlanePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneSupportedDisplaysKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayModePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDisplayModeKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilitiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDisplayPlaneSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSharedSwapchainsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateXlibSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceXlibPresentationSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateXcbSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceXcbPresentationSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateWaylandSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceWaylandPresentationSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAndroidSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateWin32SurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceWin32PresentationSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoCapabilitiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceVideoFormatPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateVideoSessionKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyVideoSessionKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetVideoSessionMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindVideoSessionMemoryKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyVideoSessionParametersKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginVideoCodingKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndVideoCodingKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdControlVideoCodingKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDecodeVideoKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderingKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderingKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFeatures2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFormatProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceImageFormatProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMemoryProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSparseImageFormatProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupPeerMemoryFeaturesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDeviceMaskKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDispatchBaseKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.TrimCommandPoolKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceGroupsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalBufferPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandleKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandlePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryFdKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryFdPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreWin32HandleKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreWin32HandleKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreFdKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreFdKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPushDescriptorSetKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDescriptorUpdateTemplateKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDescriptorUpdateTemplateKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRenderPass2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginRenderPass2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdNextSubpass2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndRenderPass2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainStatusKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalFencePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportFenceWin32HandleKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceWin32HandleKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportFenceFdKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFenceFdKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireProfilingLockKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseProfilingLockKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceFormats2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDisplayPlaneProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayModeProperties2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDisplayPlaneCapabilities2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSparseMemoryRequirements2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateSamplerYcbcrConversionKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroySamplerYcbcrConversionKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindBufferMemory2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindImageMemory2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCountKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreCounterValueKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitSemaphoresKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SignalSemaphoreKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceFragmentShadingRatesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WaitForPresentKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddressKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferOpaqueCaptureAddressKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMemoryOpaqueCaptureAddressKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDeferredOperationKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDeferredOperationKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeferredOperationMaxConcurrencyKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeferredOperationResultKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DeferredOperationJoinKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutablePropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutableStatisticsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelineExecutableInternalRepresentationsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEncodeVideoKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetEvent2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResetEvent2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWaitEvents2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPipelineBarrier2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteTimestamp2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSubmit2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteBufferMarker2AMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueueCheckpointData2NV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBuffer2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImage2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyBufferToImage2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyImageToBuffer2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBlitImage2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdResolveImage2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysIndirect2KHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceBufferMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceImageSparseMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDebugReportCallbackEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDebugReportCallbackEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugReportMessageEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugMarkerSetObjectTagEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DebugMarkerSetObjectNameEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerBeginEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerEndEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDebugMarkerInsertEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindTransformFeedbackBuffersEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginTransformFeedbackEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndTransformFeedbackEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginQueryIndexedEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndQueryIndexedEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectByteCountEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageViewHandleNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageViewAddressNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndirectCountAMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawIndexedIndirectCountAMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderInfoAMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateStreamDescriptorSurfaceGGP_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceExternalImageFormatPropertiesNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryWin32HandleNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateViSurfaceNN_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginConditionalRenderingEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndConditionalRenderingEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWScalingNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseDisplayEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireXlibDisplayEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRandROutputDisplayEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfaceCapabilities2EXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DisplayPowerControlEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.RegisterDeviceEventEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.RegisterDisplayEventEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSwapchainCounterEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRefreshCycleDurationGOOGLE_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPastPresentationTimingGOOGLE_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDiscardRectangleModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetHdrMetadataEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateIOSSurfaceMVK_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMacOSSurfaceMVK_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDebugUtilsObjectNameEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDebugUtilsObjectTagEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueBeginDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueEndDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueInsertDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBeginDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdEndDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdInsertDebugUtilsLabelEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDebugUtilsMessengerEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyDebugUtilsMessengerEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SubmitDebugUtilsMessageEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAndroidHardwareBufferPropertiesANDROID_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryAndroidHardwareBufferANDROID_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleLocationsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMultisamplePropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageDrmFormatModifierPropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateValidationCacheEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyValidationCacheEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.MergeValidationCachesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetValidationCacheDataEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindShadingRateImageNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportShadingRatePaletteNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoarseSampleOrderNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAccelerationStructureNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyAccelerationStructureNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureMemoryRequirementsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindAccelerationStructureMemoryNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructureNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRayTracingPipelinesNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupHandlesNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureHandleNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CompileDeferredNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryHostPointerPropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteBufferMarkerAMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetCalibratedTimestampsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExclusiveScissorEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExclusiveScissorNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCheckpointNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetQueueCheckpointDataNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.InitializePerformanceApiINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UninitializePerformanceApiINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceMarkerINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceStreamMarkerINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPerformanceOverrideINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquirePerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleasePerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.QueueSetPerformanceConfigurationINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPerformanceParameterINTEL_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetLocalDimmingAMD_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateImagePipeSurfaceFUCHSIA_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMetalSurfaceEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetBufferDeviceAddressEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceToolPropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceSurfacePresentModes2EXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireFullScreenExclusiveModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseFullScreenExclusiveModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceGroupSurfacePresentModes2EXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateHeadlessSurfaceEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineStippleEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ResetQueryPoolEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCullModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFrontFaceEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveTopologyEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWithCountEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetScissorWithCountEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindVertexBuffers2EXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthTestEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthWriteEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthCompareOpEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBoundsTestEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilTestEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetStencilOpEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ReleaseSwapchainImagesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetGeneratedCommandsMemoryRequirementsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPreprocessGeneratedCommandsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdExecuteGeneratedCommandsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindPipelineShaderGroupNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateIndirectCommandsLayoutNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyIndirectCommandsLayoutNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireDrmDisplayEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDrmDisplayEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreatePrivateDataSlotEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyPrivateDataSlotEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetPrivateDataEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPrivateDataEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetFragmentShadingRateEnumNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetImageSubresourceLayout2EXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceFaultInfoEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.AcquireWinrtDisplayNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetWinrtDisplayNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateDirectFBSurfaceEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceDirectFBPresentationSupportEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetVertexInputEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryZirconHandlePropertiesFUCHSIA_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.ImportSemaphoreZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetSemaphoreZirconHandleFUCHSIA_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBindInvocationMaskHUAWEI_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMemoryRemoteAddressNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPatchControlPointsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizerDiscardEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthBiasEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLogicOpEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPrimitiveRestartEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateScreenSurfaceQNX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceScreenPresentationSupportQNX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorWriteEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMultiEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMultiIndexedEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildMicromapsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BuildMicromapsEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMicromapToMemoryEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMemoryToMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WriteMicromapsPropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMicromapToMemoryEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMemoryToMicromapEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteMicromapsPropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceMicromapCompatibilityEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetMicromapBuildSizesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawClusterHUAWEI_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawClusterIndirectHUAWEI_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.SetDeviceMemoryPriorityEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetLayoutHostMappingInfoVALVE_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDescriptorSetHostMappingVALVE_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetTessellationDomainOriginEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClampEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetPolygonModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizationSamplesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleMaskEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetAlphaToCoverageEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetAlphaToOneEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLogicOpEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendEquationEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorWriteMaskEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRasterizationStreamEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetConservativeRasterizationModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetExtraPrimitiveOverestimationSizeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClipEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetSampleLocationsEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetColorBlendAdvancedEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetProvokingVertexModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineRasterizationModeEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetLineStippleEnableEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetDepthClipNegativeOneToOneEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportWScalingEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetViewportSwizzleNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageToColorEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageToColorLocationNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationModeNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageModulationTableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetShadingRateImageEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRepresentativeFragmentTestEnableNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetCoverageReductionModeNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderModuleIdentifierEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetShaderModuleCreateInfoIdentifierEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceOpticalFlowImageFormatsNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateOpticalFlowSessionNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyOpticalFlowSessionNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindOpticalFlowSessionImageNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdOpticalFlowExecuteNV_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetFramebufferTilePropertiesQCOM_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDynamicRenderingTilePropertiesQCOM_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdBuildAccelerationStructuresIndirectKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyAccelerationStructureToMemoryKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyMemoryToAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.WriteAccelerationStructuresPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyAccelerationStructureToMemoryKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdCopyMemoryToAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureDeviceAddressKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdWriteAccelerationStructuresPropertiesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceAccelerationStructureCompatibilityKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureBuildSizesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateRayTracingPipelinesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdTraceRaysIndirectKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetRayTracingShaderGroupStackSizeKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdSetRayTracingPipelineStackSizeKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdDrawMeshTasksIndirectCountEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetInstanceProcAddr_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetDeviceProcAddr_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumerateInstanceExtensionProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumerateDeviceExtensionProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumerateInstanceLayerProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumerateDeviceLayerProperties_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.EnumerateInstanceVersion_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateDescriptorSetWithTemplate_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdPushDescriptorSetWithTemplateKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UpdateDescriptorSetWithTemplateKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BuildAccelerationStructuresKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CopyAccelerationStructureKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateMirSurfaceKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceMirPresentationSupportKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdProcessCommandsNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CmdReserveSpaceForCommandsNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateIndirectCommandsLayoutNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyIndirectCommandsLayoutNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.CreateObjectTableNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.DestroyObjectTableNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterObjectsNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.RegisterObjectsNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.UnregisterObjectsNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPhysicalDeviceGeneratedCommandsPropertiesNVX_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetAccelerationStructureMemoryRequirementsKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.BindAccelerationStructureMemoryKHR_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};

template<>
struct EncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelinePropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_pre.GetPipelinePropertiesEXT_PreCall(manager->GetBlockIndex(), args...);
        }
    }
};


GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_COMMANDS_H
