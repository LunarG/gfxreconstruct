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

#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_POST_COMMANDS_H
#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_POST_COMMANDS_H

#include "encode/custom_vulkan_encoder_commands.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"

#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

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
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
    {
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
    static void Dispatch(VulkanCaptureManager* manager, VkInstance instance, const VkAllocationCallbacks* pAllocator)
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
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>
{
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
    {
        assert(manager);
        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(manager, result, queue, submitCount, pSubmits, fence);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
            const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);

            plugin.func_table_post.QueueSubmit_PostCall(manager->GetBlockIndex() - 1, result, queue, submitCount, pSubmits_unwrapped, fence);
        }
    }
};

template<>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>
{
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(manager, result, queue, pPresentInfo);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
            const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

            plugin.func_table_post.QueuePresentKHR_PostCall(manager->GetBlockIndex() - 1, result, queue, pPresentInfo_unwrapped);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDevice_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceQueue_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeMemory_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UnmapMemory_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryCommitment_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyFence_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySemaphore_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyEvent_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyQueryPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyBufferView_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSubresourceLayout_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyImageView_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyShaderModule_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipelineCache_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipeline_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPipelineLayout_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySampler_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorSetLayout_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateDescriptorSets_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyFramebuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyRenderPass_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRenderAreaGranularity_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyCommandPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeCommandBuffers_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindPipeline_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewport_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissor_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineWidth_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBias_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetBlendConstants_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBounds_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilCompareMask_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilWriteMask_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilReference_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindDescriptorSets_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindIndexBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDraw_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexed_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirect_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirect_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatch_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchIndirect_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdUpdateBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdFillBuffer_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearColorImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearDepthStencilImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdClearAttachments_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginQuery_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndQuery_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetQueryPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyQueryPoolResults_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPushConstants_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdExecuteCommands_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeatures_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDeviceMask_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchBase_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.TrimCommandPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceQueue2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySamplerYcbcrConversion_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplate_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFenceProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphoreProperties_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupport_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCount_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCount_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetQueryPool_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPrivateDataSlot_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPrivateData_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRendering_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRendering_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCullMode_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFrontFace_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveTopology_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWithCount_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissorWithCount_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers2_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthTestEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthWriteEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthCompareOp_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilTestEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilOp_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBiasEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnable_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirements_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySurfaceKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySwapchainKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyVideoSessionKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdControlVideoCodingKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDecodeVideoKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderingKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderingKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFeatures2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceProperties2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyProperties2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMemoryProperties2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSparseImageFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPeerMemoryFeaturesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDeviceMaskKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDispatchBaseKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.TrimCommandPoolKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalBufferPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalSemaphorePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPushDescriptorSetKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDescriptorUpdateTemplateKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdNextSubpass2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalFencePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseProfilingLockKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSparseMemoryRequirements2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroySamplerYcbcrConversionKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutSupportKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCountKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFragmentShadingRateKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDeferredOperationKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEncodeVideoKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetEvent2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResetEvent2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWaitEvents2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPipelineBarrier2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteTimestamp2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteBufferMarker2AMD_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueueCheckpointData2NV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBuffer2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImage2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyBufferToImage2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyImageToBuffer2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBlitImage2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdResolveImage2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysIndirect2KHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceBufferMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceImageSparseMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDebugReportCallbackEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugReportMessageEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerBeginEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerEndEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDebugMarkerInsertEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindTransformFeedbackBuffersEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginTransformFeedbackEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndTransformFeedbackEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginQueryIndexedEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndQueryIndexedEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectByteCountEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndirectCountAMD_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawIndexedIndirectCountAMD_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginConditionalRenderingEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndConditionalRenderingEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWScalingNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDiscardRectangleModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetHdrMetadataEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueBeginDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueEndDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueInsertDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBeginDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdEndDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdInsertDebugUtilsLabelEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyDebugUtilsMessengerEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SubmitDebugUtilsMessageEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleLocationsEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceMultisamplePropertiesEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyValidationCacheEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindShadingRateImageNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportShadingRatePaletteNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoarseSampleOrderNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureMemoryRequirementsNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteBufferMarkerAMD_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExclusiveScissorEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExclusiveScissorNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCheckpointNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueueCheckpointDataNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UninitializePerformanceApiINTEL_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetLocalDimmingAMD_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineStippleEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetQueryPoolEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCullModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFrontFaceEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveTopologyEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWithCountEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetScissorWithCountEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindVertexBuffers2EXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthWriteEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthCompareOpEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBoundsTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilTestEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetStencilOpEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetGeneratedCommandsMemoryRequirementsNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPreprocessGeneratedCommandsNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdExecuteGeneratedCommandsNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindPipelineShaderGroupNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyIndirectCommandsLayoutNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyPrivateDataSlotEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPrivateDataEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetFragmentShadingRateEnumNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageSubresourceLayout2EXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetVertexInputEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBindInvocationMaskHUAWEI_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPatchControlPointsEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizerDiscardEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthBiasEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLogicOpEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPrimitiveRestartEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorWriteEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMultiEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMultiIndexedEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildMicromapsEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMicromapToMemoryEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMemoryToMicromapEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteMicromapsPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMicromapCompatibilityEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMicromapBuildSizesEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawClusterHUAWEI_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawClusterIndirectHUAWEI_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDeviceMemoryPriorityEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetLayoutHostMappingInfoVALVE_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDescriptorSetHostMappingVALVE_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetTessellationDomainOriginEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClampEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPolygonModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizationSamplesEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleMaskEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetAlphaToCoverageEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetAlphaToOneEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLogicOpEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendEquationEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorWriteMaskEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRasterizationStreamEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetConservativeRasterizationModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetExtraPrimitiveOverestimationSizeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClipEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetSampleLocationsEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetColorBlendAdvancedEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetProvokingVertexModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineRasterizationModeEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetLineStippleEnableEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetDepthClipNegativeOneToOneEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportWScalingEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetViewportSwizzleNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageToColorEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageToColorLocationNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationModeNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationTableEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageModulationTableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetShadingRateImageEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRepresentativeFragmentTestEnableNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetCoverageReductionModeNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderModuleIdentifierEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderModuleCreateInfoIdentifierEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyOpticalFlowSessionNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdOpticalFlowExecuteNV_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DestroyAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdBuildAccelerationStructuresIndirectKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyAccelerationStructureToMemoryKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdCopyMemoryToAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdWriteAccelerationStructuresPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceAccelerationStructureCompatibilityKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureBuildSizesKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdTraceRaysIndirectKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetRayTracingPipelineStackSizeKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdDrawMeshTasksIndirectCountEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateDescriptorSetWithTemplate_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdPushDescriptorSetWithTemplateKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateDescriptorSetWithTemplateKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddress_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddress_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddress_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceXlibPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceXcbPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceWaylandPresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceWin32PresentationSupportKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddressKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferOpaqueCaptureAddressKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceMemoryOpaqueCaptureAddressKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeferredOperationMaxConcurrencyKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageViewHandleNVX_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetBufferDeviceAddressEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDirectFBPresentationSupportEXT_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceScreenPresentationSupportQNX_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureDeviceAddressKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupStackSizeKHR_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetInstanceProcAddr>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetInstanceProcAddr_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceProcAddr>::Dispatch(manager, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceProcAddr_PostCall(manager->GetBlockIndex() - 1, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDevices_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDevice_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueWaitIdle_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DeviceWaitIdle_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateMemory_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MapMemory_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FlushMappedMemoryRanges_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.InvalidateMappedMemoryRanges_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueBindSparse_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateFence_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetFences_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceStatus_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitForFences_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSemaphore_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateEvent_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetEventStatus_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetEvent_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetEvent_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateQueryPool_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetQueryPoolResults_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateBuffer_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateBufferView_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImage_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImageView_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateShaderModule_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePipelineCache_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineCacheData_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MergePipelineCaches_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateGraphicsPipelines_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateComputePipelines_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePipelineLayout_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSampler_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorSetLayout_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorPool_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetDescriptorPool_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateDescriptorSets_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.FreeDescriptorSets_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateFramebuffer_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateCommandPool_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetCommandPool_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AllocateCommandBuffers_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BeginCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EndCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ResetCommandBuffer_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory2_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory2_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroups_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSamplerYcbcrConversion_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorUpdateTemplate_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass2_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreCounterValue_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitSemaphores_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SignalSemaphore_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceToolProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePrivateDataSlot_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetPrivateData_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceSupportKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormatsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSwapchainKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainImagesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireNextImageKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupPresentCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDevicePresentRectanglesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireNextImage2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlanePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneSupportedDisplaysKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayModePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDisplayModeKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDisplayPlaneSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSharedSwapchainsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateXlibSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateXcbSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateWaylandSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAndroidSurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateWin32SurfaceKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceVideoCapabilitiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceVideoFormatPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateVideoSessionKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetVideoSessionMemoryRequirementsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindVideoSessionMemoryKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.UpdateVideoSessionParametersKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceImageFormatProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceGroupsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandlePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryFdKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryFdPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreFdKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreFdKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDescriptorUpdateTemplateKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRenderPass2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainStatusKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportFenceWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceWin32HandleKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportFenceFdKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFenceFdKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireProfilingLockKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceFormats2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceDisplayPlaneProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayModeProperties2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDisplayPlaneCapabilities2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateSamplerYcbcrConversionKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindBufferMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindImageMemory2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreCounterValueKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitSemaphoresKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SignalSemaphoreKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceFragmentShadingRatesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WaitForPresentKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDeferredOperationKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeferredOperationResultKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DeferredOperationJoinKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutablePropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutableStatisticsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPipelineExecutableInternalRepresentationsKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSubmit2KHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDebugReportCallbackEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugMarkerSetObjectTagEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DebugMarkerSetObjectNameEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageViewAddressNVX_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetShaderInfoAMD_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateStreamDescriptorSurfaceGGP_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceExternalImageFormatPropertiesNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryWin32HandleNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateViSurfaceNN_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireXlibDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRandROutputDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfaceCapabilities2EXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.DisplayPowerControlEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.RegisterDeviceEventEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.RegisterDisplayEventEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSwapchainCounterEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRefreshCycleDurationGOOGLE_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPastPresentationTimingGOOGLE_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateIOSSurfaceMVK_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMacOSSurfaceMVK_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDebugUtilsObjectNameEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetDebugUtilsObjectTagEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDebugUtilsMessengerEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAndroidHardwareBufferPropertiesANDROID_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryAndroidHardwareBufferANDROID_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetImageDrmFormatModifierPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateValidationCacheEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.MergeValidationCachesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetValidationCacheDataEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAccelerationStructureNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindAccelerationStructureMemoryNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRayTracingPipelinesNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingShaderGroupHandlesNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetAccelerationStructureHandleNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CompileDeferredNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryHostPointerPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceCalibrateableTimeDomainsEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetCalibratedTimestampsEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.InitializePerformanceApiINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceMarkerINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceStreamMarkerINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CmdSetPerformanceOverrideINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquirePerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleasePerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.QueueSetPerformanceConfigurationINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPerformanceParameterINTEL_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateImagePipeSurfaceFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMetalSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceToolPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceCooperativeMatrixPropertiesNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceSurfacePresentModes2EXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireFullScreenExclusiveModeEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseFullScreenExclusiveModeEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceGroupSurfacePresentModes2EXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateHeadlessSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ReleaseSwapchainImagesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateIndirectCommandsLayoutNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireDrmDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDrmDisplayEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreatePrivateDataSlotEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.SetPrivateDataEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDeviceFaultInfoEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.AcquireWinrtDisplayNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetWinrtDisplayNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateDirectFBSurfaceEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryZirconHandlePropertiesFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.ImportSemaphoreZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetSemaphoreZirconHandleFUCHSIA_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetMemoryRemoteAddressNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateScreenSurfaceQNX_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BuildMicromapsEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMicromapToMemoryEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMemoryToMicromapEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WriteMicromapsPropertiesEXT_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetPhysicalDeviceOpticalFlowImageFormatsNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateOpticalFlowSessionNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BindOpticalFlowSessionImageNV_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetFramebufferTilePropertiesQCOM_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetDynamicRenderingTilePropertiesQCOM_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyAccelerationStructureToMemoryKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyMemoryToAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.WriteAccelerationStructuresPropertiesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CreateRayTracingPipelinesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.GetRayTracingCaptureReplayShaderGroupHandlesKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceExtensionProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumerateInstanceExtensionProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceExtensionProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumerateDeviceExtensionProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceLayerProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumerateInstanceLayerProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateDeviceLayerProperties>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumerateDeviceLayerProperties_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumerateInstanceVersion>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.EnumerateInstanceVersion_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildAccelerationStructuresKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.BuildAccelerationStructuresKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};

template <>
struct EncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>
{
    template <typename... Args>
    static void Dispatch(VulkanCaptureManager* manager, VkResult result, Args... args)
    {
        assert(manager);

        CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(manager, result, args...);

        for (auto &plugin : manager->GetLoadedPlugins())
        {
            plugin.func_table_post.CopyAccelerationStructureKHR_PostCall(manager->GetBlockIndex() - 1, result, args...);
        }
    }
};


GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_COMMANDS_H
