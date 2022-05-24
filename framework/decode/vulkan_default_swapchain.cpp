/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "decode/vulkan_default_swapchain.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanDefaultSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
                                                    const DeviceInfo*               device_info,
                                                    const VkSwapchainCreateInfoKHR* create_info,
                                                    const VkAllocationCallbacks*    allocator,
                                                    VkSwapchainKHR*                 swapchain,
                                                    const VkPhysicalDevice          physical_device,
                                                    const encode::InstanceTable*    instance_table,
                                                    const encode::DeviceTable*      device_table)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    return func(device, create_info, allocator, swapchain);
}

void VulkanDefaultSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                                 const DeviceInfo*            device_info,
                                                 const SwapchainKHRInfo*      swapchain_info,
                                                 const VkAllocationCallbacks* allocator)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    func(device, swapchain, allocator);
}

VkResult VulkanDefaultSwapchain::GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                                       const DeviceInfo*           device_info,
                                                       SwapchainKHRInfo*           swapchain_info,
                                                       uint32_t                    capture_image_count,
                                                       uint32_t*                   image_count,
                                                       VkImage*                    images)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    auto result = func(device, swapchain, image_count, images);

    if ((image_count != nullptr) && (capture_image_count != *image_count))
    {
        GFXRECON_LOG_FATAL("The number of images returned by vkGetSwapchainImageKHR is different than the number "
                           "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_FATAL(
            "Try replay with the virtual swapchain mode enabled via the \"--virtual-swapchain\" option.");
    }

    return result;
}

VkResult VulkanDefaultSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                     const DeviceInfo*         device_info,
                                                     SwapchainKHRInfo*         swapchain_info,
                                                     uint64_t                  timeout,
                                                     SemaphoreInfo*            semaphore_info,
                                                     FenceInfo*                fence_info,
                                                     uint32_t                  capture_image_index,
                                                     uint32_t*                 image_index)
{
    VkSemaphore semaphore = VK_NULL_HANDLE;
    VkFence     fence     = VK_NULL_HANDLE;

    if (semaphore_info != nullptr)
    {
        semaphore = semaphore_info->handle;
    }

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    return AcquireNextImageKHR(
        func, device_info, swapchain_info, timeout, semaphore, fence, capture_image_index, image_index);
}

VkResult VulkanDefaultSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                     const DeviceInfo*         device_info,
                                                     SwapchainKHRInfo*         swapchain_info,
                                                     uint64_t                  timeout,
                                                     VkSemaphore               semaphore,
                                                     VkFence                   fence,
                                                     uint32_t                  capture_image_index,
                                                     uint32_t*                 image_index)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    auto result = func(device, swapchain, timeout, semaphore, fence, image_index);

    if ((image_index != nullptr) && (capture_image_index != *image_index))
    {
        GFXRECON_LOG_FATAL("The image index returned by vkAcquireNextImageKHR is different than the index "
                           "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_FATAL(
            "Try replay with the virtual swapchain mode enabled via the \"--virtual-swapchain\" option.");
    }

    return result;
}

VkResult VulkanDefaultSwapchain::AcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                                      const DeviceInfo*                device_info,
                                                      SwapchainKHRInfo*                swapchain_info,
                                                      const VkAcquireNextImageInfoKHR* acquire_info,
                                                      uint32_t                         capture_image_index,
                                                      uint32_t*                        image_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(swapchain_info);

    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    auto result = func(device, acquire_info, image_index);

    if ((image_index != nullptr) && (capture_image_index != *image_index))
    {
        GFXRECON_LOG_FATAL("The image index returned by vkAcquireNextImageKHR is different than the index "
                           "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_FATAL(
            "Try replay with the virtual swapchain mode enabled via the \"--virtual-swapchain\" option.");
    }

    return result;
}

VkResult VulkanDefaultSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                                 const std::vector<uint32_t>&          capture_image_indices,
                                                 const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                 const QueueInfo*                      queue_info,
                                                 const VkPresentInfoKHR*               present_info)
{
    VkQueue queue = VK_NULL_HANDLE;

    if (queue_info != nullptr)
    {
        queue = queue_info->handle;
    }

    return func(queue, present_info);
}

VkResult VulkanDefaultSwapchain::CreateRenderPass(PFN_vkCreateRenderPass        func,
                                                  const DeviceInfo*             device_info,
                                                  const VkRenderPassCreateInfo* create_info,
                                                  const VkAllocationCallbacks*  allocator,
                                                  VkRenderPass*                 render_pass)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    return func(device, create_info, allocator, render_pass);
}

VkResult VulkanDefaultSwapchain::CreateRenderPass2(PFN_vkCreateRenderPass2        func,
                                                   const DeviceInfo*              device_info,
                                                   const VkRenderPassCreateInfo2* create_info,
                                                   const VkAllocationCallbacks*   allocator,
                                                   VkRenderPass*                  render_pass)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    return func(device, create_info, allocator, render_pass);
}

void VulkanDefaultSwapchain::CmdPipelineBarrier(PFN_vkCmdPipelineBarrier     func,
                                                const CommandBufferInfo*     command_buffer_info,
                                                VkPipelineStageFlags         src_stage_mask,
                                                VkPipelineStageFlags         dst_stage_mask,
                                                VkDependencyFlags            dependency_flags,
                                                uint32_t                     memory_barrier_count,
                                                const VkMemoryBarrier*       memory_barriers,
                                                uint32_t                     buffer_memory_barrier_count,
                                                const VkBufferMemoryBarrier* buffer_memory_barriers,
                                                uint32_t                     image_memory_barrier_count,
                                                const VkImageMemoryBarrier*  image_memory_barriers)
{
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    if (command_buffer_info != nullptr)
    {
        command_buffer = command_buffer_info->handle;
    }

    func(command_buffer,
         src_stage_mask,
         dst_stage_mask,
         dependency_flags,
         memory_barrier_count,
         memory_barriers,
         buffer_memory_barrier_count,
         buffer_memory_barriers,
         image_memory_barrier_count,
         image_memory_barriers);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
