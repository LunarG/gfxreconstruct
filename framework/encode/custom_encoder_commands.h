/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_ENCODE_CUSTOM_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_CUSTOM_ENCODER_COMMANDS_H

#include "encode/trace_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct CustomEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(TraceManager*, VkResult, Args...)
    {}
};

// Dispatch custom command to initialize capture at instance creation.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>
{
    template <typename... Args>
    static void Dispatch(TraceManager*, VkResult result, Args...)
    {
        TraceManager::CheckCreateInstanceStatus(result);
    }
};

// Dispatch custom command to finalize capture at instance destruction.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(TraceManager*, Args...)
    {
        TraceManager::DestroyInstance();
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkEnumeratePhysicalDevices(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties2(
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceQueueFamilyProperties2(
            format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceSupportKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfaceFormatsKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkGetPhysicalDeviceSurfacePresentModesKHR(result, args...);
    }
};

// Dispatch custom command to set xcb keyboard connection during create xlib surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateXlibSurfaceKHR(args...);
    }
};

// Dispatch custom command to set xcb keyboard connection during create xcb surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateXcbSurfaceKHR(args...);
    }
};

// Dispatch custom command to give implementation warning during create wayland surface
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateWaylandSurfaceKHR(args...);
    }
};

// Dispatch custom command for window resize command generation.
template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateSwapchain(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAcquireNextImageKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkAcquireNextImage2KHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkQueuePresentKHR(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkGetBufferMemoryRequirements2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindBufferMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkBindImageMemory2(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdEndRenderPass2(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPipelineBarrier(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdExecuteCommands(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkResetCommandPool(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkMapMemory(result, args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkFlushMappedMemoryRanges(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkUnmapMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkFreeMemory(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkFreeMemory(args...);
    }
};

template <>
struct CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkQueueSubmit(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkQueueSubmit(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkQueueBindSparse(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSets(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSetWithTemplate(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkUpdateDescriptorSetWithTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPushDescriptorSetKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdPushDescriptorSetWithTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, VkResult result, Args... args)
    {
        manager->PostProcess_vkResetDescriptorPool(result, args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateDescriptorUpdateTemplate(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PreProcess_vkCreateDescriptorUpdateTemplateKHR(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginQuery(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdBeginQueryIndexedEXT(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteTimestamp(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdWriteAccelerationStructuresPropertiesNV(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkCmdResetQueryPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkResetQueryPool(args...);
    }
};

template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(TraceManager* manager, Args... args)
    {
        manager->PostProcess_vkResetQueryPool(args...);
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_ENCODER_COMMANDS_H
