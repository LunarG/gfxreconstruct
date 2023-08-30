/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "decode/vulkan_offscreen_swapchain.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const char kDefaultOffscreenFilePrefix[] = "offscreen";

#if defined(__ANDROID__)
const char kDefaultOffscreenDir[] = "/sdcard/";
#else
const char kDefaultOffscreenDir[] = "";
#endif

VkResult VulkanOffscreenSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
                                                      const DeviceInfo*               device_info,
                                                      const VkSwapchainCreateInfoKHR* create_info,
                                                      const VkAllocationCallbacks*    allocator,
                                                      VkSwapchainKHR*                 swapchain,
                                                      const VkPhysicalDevice          physical_device,
                                                      const encode::InstanceTable*    instance_table,
                                                      const encode::DeviceTable*      device_table,
                                                      ScreenshotHandler*              screenshot_handler)
{
    screenshot_handler_ = screenshot_handler;
    return VulkanVirtualSwapchain::CreateSwapchainKHR(func,
                                                      device_info,
                                                      create_info,
                                                      allocator,
                                                      swapchain,
                                                      physical_device,
                                                      instance_table,
                                                      device_table,
                                                      screenshot_handler);
}

VkResult VulkanOffscreenSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                       const DeviceInfo*         device_info,
                                                       SwapchainKHRInfo*         swapchain_info,
                                                       uint64_t                  timeout,
                                                       VkSemaphore               semaphore,
                                                       VkFence                   fence,
                                                       uint32_t                  capture_image_index,
                                                       uint32_t*                 image_index)
{
    *image_index = capture_image_index;
    if (semaphore != VK_NULL_HANDLE || fence != VK_NULL_HANDLE)
    {
        uint32_t           signal_semaphore_count = 0;
        const VkSemaphore* signal_semaphores      = nullptr;

        if (semaphore != VK_NULL_HANDLE)
        {
            signal_semaphore_count = 1;
            signal_semaphores      = &semaphore;
        }

        return SignalSemaphoresFence(
            swapchain_info, capture_image_index, nullptr, 0, nullptr, signal_semaphore_count, signal_semaphores, fence);
    }
    return VK_SUCCESS;
}

VkResult VulkanOffscreenSwapchain::AcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                                        const DeviceInfo*                device_info,
                                                        SwapchainKHRInfo*                swapchain_info,
                                                        const VkAcquireNextImageInfoKHR* acquire_info,
                                                        uint32_t                         capture_image_index,
                                                        uint32_t*                        image_index)
{
    *image_index = capture_image_index;
    if (acquire_info->semaphore != VK_NULL_HANDLE || acquire_info->fence != VK_NULL_HANDLE)
    {
        uint32_t           signal_semaphore_count = 0;
        const VkSemaphore* signal_semaphores      = nullptr;

        if (acquire_info->semaphore != VK_NULL_HANDLE)
        {
            signal_semaphore_count = 1;
            signal_semaphores      = &acquire_info->semaphore;
        }

        return SignalSemaphoresFence(swapchain_info,
                                     capture_image_index,
                                     nullptr,
                                     0,
                                     nullptr,
                                     signal_semaphore_count,
                                     signal_semaphores,
                                     acquire_info->fence);
    }
    return VK_SUCCESS;
}

VkResult VulkanOffscreenSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                                   const std::vector<uint32_t>&          capture_image_indices,
                                                   const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                   const QueueInfo*                      queue_info,
                                                   const VkPresentInfoKHR*               present_info)
{
    for (uint32_t i = 0; i < present_info->swapchainCount; ++i)
    {
        auto swapchain_info = swapchain_infos[i];
        if ((swapchain_info != nullptr) && (swapchain_info->device_info != nullptr) &&
            (swapchain_info->images.size() > 0))
        {
            auto     device_info = swapchain_info->device_info;
            uint32_t image_index = present_info->pImageIndices[i];

            // TODO: This should be stored in the DeviceInfo structure to avoid the need for frequent queries.
            VkPhysicalDeviceMemoryProperties memory_properties;
            instance_table_->GetPhysicalDeviceMemoryProperties(device_info->parent, &memory_properties);

            std::string filename_prefix = kDefaultOffscreenDir;
            filename_prefix += kDefaultOffscreenFilePrefix;

            if (present_info->swapchainCount > 1)
            {
                filename_prefix += "_swapchain_";
                filename_prefix += std::to_string(i);
            }

            filename_prefix += "_frame_";
            filename_prefix += std::to_string(screenshot_handler_->GetCurrentFrame());

            screenshot_handler_->WriteImage(filename_prefix,
                                            device_info->handle,
                                            device_table_,
                                            memory_properties,
                                            device_info->allocator.get(),
                                            swapchain_info->images[image_index],
                                            swapchain_info->format,
                                            swapchain_info->width,
                                            swapchain_info->height,
                                            swapchain_info->width,
                                            swapchain_info->height,
                                            VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
        }
    }

    if (present_info->waitSemaphoreCount > 0)
    {
        auto length = present_info->swapchainCount;
        for (uint32_t i = 0; i < length; ++i)
        {
            return SignalSemaphoresFence(swapchain_infos[i],
                                         capture_image_indices[i],
                                         queue_info,
                                         present_info->waitSemaphoreCount,
                                         present_info->pWaitSemaphores,
                                         0,
                                         nullptr,
                                         VK_NULL_HANDLE);
        }
    }
    return VK_SUCCESS;
}

// queue_info could be nullptr. It means it doesn't specify a VkQueue and use default_queue. Its purpose is to singal
// semaphores or fence. All VkQueue should work.
VkResult VulkanOffscreenSwapchain::SignalSemaphoresFence(SwapchainKHRInfo*  swapchain_info,
                                                         uint32_t           capture_image_index,
                                                         const QueueInfo*   queue_info,
                                                         uint32_t           wait_semaphore_count,
                                                         const VkSemaphore* wait_semaphores,
                                                         uint32_t           signal_semaphore_count,
                                                         const VkSemaphore* signal_semaphores,
                                                         VkFence            fence)
{
    // Get the per swapchain resource data so we have access to the swapchain-specific information.
    if (swapchain_resources_.find(swapchain_info->handle) == swapchain_resources_.end())
    {
        GFXRECON_LOG_ERROR("VulkanOffscreenSwapchain::SignalSemaphoresFence missing swapchain resource data for "
                           "swapchain (ID = %" PRIu64 ")",
                           swapchain_info->capture_id);
        return VK_ERROR_UNKNOWN;
    }

    auto& swapchain_resources = swapchain_resources_[swapchain_info->handle];
    assert(swapchain_resources != nullptr);

    uint32_t queue_family_index = 0;
    if (queue_info)
    {
        queue_family_index = queue_info->family_index;
    }

    VkPipelineStageFlags wait_stage  = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    VkSubmitInfo         submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };

    if (wait_semaphore_count > 0)
    {
        submit_info.waitSemaphoreCount = wait_semaphore_count;
        submit_info.pWaitSemaphores    = wait_semaphores;
        submit_info.pWaitDstStageMask  = &wait_stage;
    }
    if (signal_semaphore_count > 0)
    {
        submit_info.signalSemaphoreCount = signal_semaphore_count;
        submit_info.pSignalSemaphores    = signal_semaphores;
    }

    VkQueue queue = VK_NULL_HANDLE;
    if (queue_info)
    {
        queue = queue_info->handle;
    }
    if (queue == VK_NULL_HANDLE)
    {
        auto     device_info = swapchain_info->device_info;
        VkDevice device      = VK_NULL_HANDLE;
        if (device_info != nullptr)
        {
            device = device_info->handle;
        }
        device_table_->GetDeviceQueue(device, queue_family_index, 0, &queue);
    }
    return device_table_->QueueSubmit(queue, 1, &submit_info, fence);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
