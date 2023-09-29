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
#include "encode/vulkan_handle_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanOffscreenSwapchain::CreateSurface(VkResult                            original_result,
                                                 InstanceInfo*                       instance_info,
                                                 const std::string&                  wsi_extension,
                                                 VkFlags                             flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>* surface,
                                                 const encode::InstanceTable*        instance_table,
                                                 application::Application*           application,
                                                 int32_t                             options_surface_index)
{
    GFXRECON_ASSERT(surface);

    instance_table_        = instance_table;
    application_           = application;
    options_surface_index_ = options_surface_index;

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for
    // the specified index.
    if ((options_surface_index_ == -1) || (options_surface_index_ == create_surface_count_))
    {

        const format::HandleId* id             = surface->GetPointer();
        VkSurfaceKHR*           replay_surface = surface->GetHandlePointer();

        // Give surface a fake handle. It's handle id.
        *replay_surface = UINT64_TO_VK_HANDLE(VkSurfaceKHR, *id);
    }
    else
    {
        if (surface != nullptr)
        {
            auto surface_info                      = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
            surface_info->surface_creation_skipped = true;
        }

        GFXRECON_LOG_INFO("Skipping surface creation for surface index %d", create_surface_count_);
    }

    // Count the number of surfaces created for restricting replay to a specific surface.
    ++create_surface_count_;

    return original_result;
}

void VulkanOffscreenSwapchain::DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                              const InstanceInfo*          instance_info,
                                              const SurfaceKHRInfo*        surface_info,
                                              const VkAllocationCallbacks* allocator)
{}

VkResult VulkanOffscreenSwapchain::CreateSwapchainKHR(VkResult                              original_result,
                                                      PFN_vkCreateSwapchainKHR              func,
                                                      const DeviceInfo*                     device_info,
                                                      const VkSwapchainCreateInfoKHR*       create_info,
                                                      const VkAllocationCallbacks*          allocator,
                                                      HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                                      const encode::DeviceTable*            device_table)
{
    GFXRECON_ASSERT(device_info);
    device_table_ = device_table;

    const format::HandleId* id               = swapchain->GetPointer();
    VkSwapchainKHR*         replay_swapchain = swapchain->GetHandlePointer();

    // Give swapchain a fake handle. It's handle id.
    *replay_swapchain = UINT64_TO_VK_HANDLE(VkSwapchainKHR, *id);
    if (!AddSwapchainResourceData(*replay_swapchain))
    {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    VkDevice device = device = device_info->handle;
    device_table_->GetDeviceQueue(device, default_queue_family_index_, 0, &default_queue_);

    return original_result;
}

void VulkanOffscreenSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                                   const DeviceInfo*            device_info,
                                                   const SwapchainKHRInfo*      swapchain_info,
                                                   const VkAllocationCallbacks* allocator)
{
    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        CleanSwapchainResourceData(device_info, swapchain_info);
    }
}

VkResult VulkanOffscreenSwapchain::GetSwapchainImagesKHR(VkResult                    original_result,
                                                         PFN_vkGetSwapchainImagesKHR func,
                                                         const DeviceInfo*           device_info,
                                                         SwapchainKHRInfo*           swapchain_info,
                                                         uint32_t                    capture_image_count,
                                                         uint32_t*                   image_count,
                                                         VkImage*                    images)
{
    GFXRECON_ASSERT(swapchain_info);
    uint32_t* replay_image_count = &swapchain_info->replay_image_count;

    if (images == nullptr)
    {
        (*image_count)        = capture_image_count;
        (*replay_image_count) = capture_image_count;
        return original_result;
    }

    VkResult result =
        CreateSwapchainResourceData(device_info, swapchain_info, capture_image_count, replay_image_count, images, true);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Offscreen swapchain failed to CreateSwapchainResourceData for swapchain (ID = %" PRIu64 ")",
                           swapchain_info->capture_id);
        return result;
    }
    return original_result;
}

VkResult VulkanOffscreenSwapchain::AcquireNextImageKHR(VkResult                  original_result,
                                                       PFN_vkAcquireNextImageKHR func,
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

        VkResult result = SignalSemaphoresFence(nullptr, 0, nullptr, signal_semaphore_count, signal_semaphores, fence);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Offscreen swapchain failed to singal semaphore (Handle = %" PRIu64
                               ") or fence (Handle = %" PRIu64 ") for swapchain (ID = %" PRIu64
                               ") on AcquireNextImageKHR",
                               semaphore,
                               fence,
                               swapchain_info->capture_id);
            return result;
        }
    }
    return original_result;
}

VkResult VulkanOffscreenSwapchain::AcquireNextImage2KHR(VkResult                         original_result,
                                                        PFN_vkAcquireNextImage2KHR       func,
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

        VkResult result =
            SignalSemaphoresFence(nullptr, 0, nullptr, signal_semaphore_count, signal_semaphores, acquire_info->fence);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Offscreen swapchain failed to singal semaphore (Handle = %" PRIu64
                               ") or fence (Handle = %" PRIu64 ") for swapchain (ID = %" PRIu64
                               ") on AcquireNextImage2KHR",
                               acquire_info->semaphore,
                               acquire_info->fence,
                               swapchain_info->capture_id);
            return result;
        }
    }
    return original_result;
}

VkResult VulkanOffscreenSwapchain::QueuePresentKHR(VkResult                              original_result,
                                                   PFN_vkQueuePresentKHR                 func,
                                                   const std::vector<uint32_t>&          capture_image_indices,
                                                   const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                   const QueueInfo*                      queue_info,
                                                   const VkPresentInfoKHR*               present_info)
{
    if (present_info->waitSemaphoreCount > 0)
    {
        VkResult result = SignalSemaphoresFence(
            queue_info, present_info->waitSemaphoreCount, present_info->pWaitSemaphores, 0, nullptr, VK_NULL_HANDLE);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Offscreen swapchain failed to wait semaphore (Handle = %" PRIu64
                               ") for queue (ID = %" PRIu64 ") on QueuePresentKHR",
                               present_info->pWaitSemaphores[0],
                               queue_info->handle);
            return result;
        }
    }
    return original_result;
}

// queue_info could be nullptr. It means it doesn't specify a VkQueue and use default_queue. Its purpose is to singal
// semaphores or fence. All VkQueue should work.
VkResult VulkanOffscreenSwapchain::SignalSemaphoresFence(const QueueInfo*   queue_info,
                                                         uint32_t           wait_semaphore_count,
                                                         const VkSemaphore* wait_semaphores,
                                                         uint32_t           signal_semaphore_count,
                                                         const VkSemaphore* signal_semaphores,
                                                         VkFence            fence)
{
    uint32_t queue_family_index = default_queue_family_index_;
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
    else
    {
        queue = default_queue_;
    }
    return device_table_->QueueSubmit(queue, 1, &submit_info, fence);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
