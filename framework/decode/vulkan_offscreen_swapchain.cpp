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
#include "decode/decoder_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanOffscreenSwapchain::CreateSurface(VkResult                            original_result,
                                                 VulkanInstanceInfo*                 instance_info,
                                                 const std::string&                  wsi_extension,
                                                 VkFlags                             flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>* surface,
                                                 const encode::VulkanInstanceTable*  instance_table,
                                                 application::Application*           application,
                                                 const int32_t                       xpos,
                                                 const int32_t                       ypos,
                                                 const uint32_t                      width,
                                                 const uint32_t                      height,
                                                 bool                                force_windowed)
{
    GFXRECON_ASSERT(surface);

    instance_table_ = instance_table;
    application_    = application;

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for
    // the specified index.
    if ((swapchain_options_.select_surface_index == -1) ||
        (swapchain_options_.select_surface_index == create_surface_count_))
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
            auto surface_info = reinterpret_cast<VulkanSurfaceKHRInfo*>(surface->GetConsumerData(0));
            surface_info->surface_creation_skipped = true;
        }

        GFXRECON_LOG_INFO("Skipping surface creation for surface index %d", create_surface_count_);
    }

    // Count the number of surfaces created for restricting replay to a specific surface.
    ++create_surface_count_;

    return original_result;
}

void VulkanOffscreenSwapchain::DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                              const VulkanInstanceInfo*    instance_info,
                                              const VulkanSurfaceKHRInfo*  surface_info,
                                              const VkAllocationCallbacks* allocator)
{}

VkResult VulkanOffscreenSwapchain::CreateSwapchainKHR(VkResult                              original_result,
                                                      PFN_vkCreateSwapchainKHR              func,
                                                      const VulkanDeviceInfo*               device_info,
                                                      const VkSwapchainCreateInfoKHR*       create_info,
                                                      const VkAllocationCallbacks*          allocator,
                                                      HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                                      const encode::VulkanDeviceTable*      device_table)
{
    GFXRECON_ASSERT(device_info);
    device_table_ = device_table;

    const format::HandleId* id               = swapchain->GetPointer();
    VkSwapchainKHR*         replay_swapchain = swapchain->GetHandlePointer();
    VkDevice                device           = device_info->handle;

    // Give swapchain a fake handle. It's handle id.
    *replay_swapchain = UINT64_TO_VK_HANDLE(VkSwapchainKHR, *id);
    if (!AddSwapchainResourceData(*replay_swapchain))
    {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    default_queue_ = GetDeviceQueue(device_table_, device_info, default_queue_family_index_, 0);

    // If this option is set, a command buffer submission with a `VkFrameBoundaryEXT` must be called each time
    // `vkQueuePresentKHR` should have been called by the offscreen swapchain. So a maximum of work must be done at
    // swapchain creation: Allocation and recording of an empty command buffer, initialization of a `VkFrameBoundaryEXT`
    // structure... (Don't forget to free everything at swapchain destruction)
    if (insert_frame_boundary_)
    {
        VkResult result;
        command_pools_.resize(device_info->queue_family_index_enabled.size());
        command_buffers_.resize(device_info->queue_family_index_enabled.size());

        for (uint32_t family_index = 0; family_index < device_info->queue_family_index_enabled.size(); family_index++)
        {
            if (!device_info->queue_family_index_enabled.at(family_index))
            {
                continue;
            }

            VkCommandPoolCreateInfo commandPoolCreateInfo;
            commandPoolCreateInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
            commandPoolCreateInfo.pNext            = nullptr;
            commandPoolCreateInfo.queueFamilyIndex = family_index;
            commandPoolCreateInfo.flags            = 0;

            result = device_table_->CreateCommandPool(
                device, &commandPoolCreateInfo, nullptr, &command_pools_.at(family_index));
            GFXRECON_ASSERT(result == VK_SUCCESS);

            VkCommandBufferAllocateInfo commandBufferAllocateInfo;
            commandBufferAllocateInfo.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
            commandBufferAllocateInfo.pNext              = nullptr;
            commandBufferAllocateInfo.commandPool        = command_pools_.at(family_index);
            commandBufferAllocateInfo.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
            commandBufferAllocateInfo.commandBufferCount = 1;

            result = device_table_->AllocateCommandBuffers(
                device, &commandBufferAllocateInfo, &command_buffers_.at(family_index));
            GFXRECON_ASSERT(result == VK_SUCCESS);

            VkCommandBufferBeginInfo commandBufferBeginInfo;
            commandBufferBeginInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
            commandBufferBeginInfo.pNext            = nullptr;
            commandBufferBeginInfo.flags            = 0;
            commandBufferBeginInfo.pInheritanceInfo = nullptr;

            result = device_table_->BeginCommandBuffer(command_buffers_.at(family_index), &commandBufferBeginInfo);
            GFXRECON_ASSERT(result == VK_SUCCESS);

            result = device_table_->EndCommandBuffer(command_buffers_.at(family_index));
            GFXRECON_ASSERT(result == VK_SUCCESS);
        }
        frame_boundary_.sType       = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
        frame_boundary_.pNext       = nullptr;
        frame_boundary_.flags       = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
        frame_boundary_.frameID     = 0;
        frame_boundary_.imageCount  = 0;
        frame_boundary_.pImages     = nullptr;
        frame_boundary_.bufferCount = 0;
        frame_boundary_.pBuffers    = nullptr;
        frame_boundary_.tagName     = 0;
        frame_boundary_.tagSize     = 0;
        frame_boundary_.pTag        = nullptr;
    }

    return original_result;
}

void VulkanOffscreenSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR     func,
                                                   const VulkanDeviceInfo*       device_info,
                                                   const VulkanSwapchainKHRInfo* swapchain_info,
                                                   const VkAllocationCallbacks*  allocator)
{
    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        CleanSwapchainResourceData(device_info, swapchain_info);
    }

    if (insert_frame_boundary_ && command_pools_.size() > 0)
    {
        for (const auto& command_pool : command_pools_)
        {
            device_table_->DestroyCommandPool(device_info->handle, command_pool, nullptr);
        }
    }
}

VkResult VulkanOffscreenSwapchain::GetSwapchainImagesKHR(VkResult                    original_result,
                                                         PFN_vkGetSwapchainImagesKHR func,
                                                         const VulkanDeviceInfo*     device_info,
                                                         VulkanSwapchainKHRInfo*     swapchain_info,
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
                                                       const VulkanDeviceInfo*   device_info,
                                                       VulkanSwapchainKHRInfo*   swapchain_info,
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
                                                        const VulkanDeviceInfo*          device_info,
                                                        VulkanSwapchainKHRInfo*          swapchain_info,
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

VkResult VulkanOffscreenSwapchain::QueuePresentKHR(VkResult                                    original_result,
                                                   PFN_vkQueuePresentKHR                       func,
                                                   const std::vector<uint32_t>&                capture_image_indices,
                                                   const std::vector<VulkanSwapchainKHRInfo*>& swapchain_infos,
                                                   const VulkanQueueInfo*                      queue_info,
                                                   const VkPresentInfoKHR*                     present_info)
{
    if (insert_frame_boundary_ && command_buffers_.size() > 0)
    {
        std::vector<VkImage> images(present_info->swapchainCount);
        for (uint32_t i = 0; i < images.size(); ++i)
        {
            images[i] = swapchain_resources_[present_info->pSwapchains[i]]
                            ->virtual_swapchain_images[present_info->pImageIndices[i]]
                            .image;
        }
        frame_boundary_.imageCount = images.size();
        frame_boundary_.pImages    = images.data();
        ++frame_boundary_.frameID;

        std::vector<VkPipelineStageFlags> dstStageFlags(present_info->waitSemaphoreCount,
                                                        VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);

        VkSubmitInfo submitInfo;
        submitInfo.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.pNext                = &frame_boundary_;
        submitInfo.waitSemaphoreCount   = present_info->waitSemaphoreCount;
        submitInfo.pWaitSemaphores      = present_info->pWaitSemaphores;
        submitInfo.pWaitDstStageMask    = dstStageFlags.data();
        submitInfo.commandBufferCount   = 1;
        submitInfo.pCommandBuffers      = &command_buffers_.at(queue_info->family_index);
        submitInfo.signalSemaphoreCount = 0;
        submitInfo.pSignalSemaphores    = nullptr;

        device_table_->QueueSubmit(queue_info->handle, 1, &submitInfo, VK_NULL_HANDLE);
    }
    else if (present_info->waitSemaphoreCount > 0)
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
VkResult VulkanOffscreenSwapchain::SignalSemaphoresFence(const VulkanQueueInfo* queue_info,
                                                         uint32_t               wait_semaphore_count,
                                                         const VkSemaphore*     wait_semaphores,
                                                         uint32_t               signal_semaphore_count,
                                                         const VkSemaphore*     signal_semaphores,
                                                         VkFence                fence)
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
