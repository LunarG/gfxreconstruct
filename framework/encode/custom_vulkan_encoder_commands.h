/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_CUSTOM_VULKAN_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_CUSTOM_VULKAN_ENCODER_COMMANDS_H

#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct CustomEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, VkResult, Args...)
    {}
};

// Dispatch custom command to initialize capture at instance creation.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, VkResult result, Args...)
    {
        VulkanCaptureManager::CheckVkCreateInstanceStatus(result);
    }
};

// Dispatch custom command to finalize capture at instance destruction.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*, Args...)
    {
        VulkanCaptureManager::DestroyInstance();
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkEnumeratePhysicalDevices(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkEnumeratePhysicalDeviceGroups(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkEnumeratePhysicalDeviceGroups(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties2(
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties2(
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceSupportKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceCapabilities2KHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceFormatsKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceFormats2KHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfacePresentModesKHR(result, args...);
    }
};

// Dispatch custom command to set xcb keyboard connection during create xlib surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateXlibSurfaceKHR(args...);
    }
};

// Dispatch custom command to set xcb keyboard connection during create xcb surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateXcbSurfaceKHR(args...);
    }
};

// Dispatch custom command to set wayland keyboard connection during create wayland surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateWaylandSurfaceKHR(args...);
    }
};

// Dispatch custom command to clean up implementation in wayland surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkDestroySurfaceKHR(args...);
    }
};

// Dispatch custom command for window resize command generation.
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateSwapchainKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCreateSwapchainKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAcquireNextImageKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAcquireNextImage2KHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         VkResult                                               result,
                         Args... args)
    {
        manager->PostProcess_vkQueuePresentKHR(current_lock, result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFrameBoundaryANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         Args... args)
    {
        manager->PostProcess_vkFrameBoundaryANDROID(current_lock, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceBufferMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceBufferMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceImageMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceImageMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageSparseMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageSparseMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetImageSparseMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceImageSparseMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetDeviceImageSparseMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkCreateBuffer(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkCreateImage(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPipelineBarrier(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPipelineBarrier2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPipelineBarrier2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdExecuteCommands(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkTrimCommandPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkTrimCommandPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkResetCommandPool(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkMapMemory(result, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkFlushMappedMemoryRanges(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkUnmapMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkFreeMemory(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkFreeMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkQueueBindSparse(args...);
    }
};

#if ENABLE_OPENXR_SUPPORT
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkDestroyFence(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkResetFences(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetFenceStatus(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkWaitForFences(args...);
    }
};

#endif

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkWaitForFences(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkResetFences(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetFenceStatus(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         Args... args)
    {
        manager->PreProcess_vkQueueSubmit(current_lock, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         VkResult                                               result,
                         Args... args)
    {
        manager->PostProcess_vkQueueSubmit(current_lock, result, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         Args... args)
    {
        manager->PreProcess_vkQueueSubmit2(current_lock, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         Args... args)
    {
        manager->PreProcess_vkQueueSubmit2(current_lock, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         VkResult                                               result,
                         Args... args)
    {
        manager->PostProcess_vkQueueSubmit2(current_lock, result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager*                                  manager,
                         std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                         VkResult                                               result,
                         Args... args)
    {
        manager->PostProcess_vkQueueSubmit2(current_lock, result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkQueueBindSparse(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSets(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSetWithTemplate(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSetWithTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPushDescriptorSetKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPushDescriptorSetWithTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPushDescriptorSetWithTemplate2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkResetDescriptorPool(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCreateDescriptorUpdateTemplate(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCreateDescriptorUpdateTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginQuery(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginQueryIndexedEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteTimestamp(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteTimestamp2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteTimestamp2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteAccelerationStructuresPropertiesNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdResetQueryPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkResetQueryPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkResetQueryPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferDeviceAddress(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferDeviceAddress(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferDeviceAddress(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetBufferOpaqueCaptureAddress(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetBufferOpaqueCaptureAddress(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetAccelerationStructureDeviceAddressKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAcquireFullScreenExclusiveModeEXT(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfacePresentModes2EXT(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkReleaseFullScreenExclusiveModeEXT(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetDeviceGroupSurfacePresentModesKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetDeviceGroupSurfacePresentModes2EXT(result, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindBufferMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindBufferMemory2(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindBufferMemory2(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindImageMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindImageMemory2(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBindImageMemory2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkSetPrivateData(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkSetPrivateData(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkSetLocalDimmingAMD(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDebugMarkerInsertEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdInsertDebugUtilsLabelEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBindPipeline(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBindDescriptorSets(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBindDescriptorSets2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdTraceRaysIndirect2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdTraceRaysIndirectKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdTraceRaysNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdTraceRaysKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDispatch(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDispatchIndirect(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDispatchBase(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDispatchBaseKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDraw(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndexed(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndirect(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndexedIndirect(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndirectCount(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndexedIndirectCount(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndirectCountKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawIndexedIndirectCountKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBuffer(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBufferToImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImageToBuffer(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBuffer2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImage2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBufferToImage2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImageToBuffer2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBuffer2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImage2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyBufferToImage2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdCopyImageToBuffer2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBlitImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBlitImage2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBlitImage2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdUpdateBuffer(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdFillBuffer(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdClearColorImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdClearDepthStencilImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdResolveImage(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdResolveImage2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdResolveImage2KHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksIndirectNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksIndirectCountNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksIndirectEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdDrawMeshTasksIndirectCountEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRendering(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRendering(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkSetDebugUtilsObjectNameEXT(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkSetDebugUtilsObjectTagEXT(result, args...);
    }
};

#if ENABLE_OPENXR_SUPPORT
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkCreateFence(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkImportFenceWin32HandleKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PostProcess_vkImportFenceFdKHR(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        manager->PreProcess_vkBeginCommandBuffer(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBeginCommandBuffer(result, args...);
    }
};

#endif // ENABLE_OPENXR_SUPPORT

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_VULKAN_ENCODER_COMMANDS_H
