/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

#include "vulkan_captured_swapchain.h"
#include "swapchain_image_tracker.h"

#include <assert.h>

namespace gfxrecon
{
namespace compatibility
{

VkResult VulkanCapturedSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR     func,
                                                     const SwapchainCreationInfo* create_info,
                                                     const VkAllocationCallbacks* allocator,
                                                     VkSwapchainKHR*              swapchain)
{
    instance_table_           = create_info->instance_table;
    device_table_             = create_info->device_table;
    resource_alloc_callbacks_ = create_info->resource_alloc_callbacks;
    log_error_                = create_info->log_error;
    log_warning_              = create_info->log_warning;
    log_info_                 = create_info->log_info;
    swapchain_image_tracker_  = new SwapchainImageTracker();

    const SwapchainInfo* new_swapchain_info =
        CreateSwapchainInfo(create_info->create_info, create_info->swapchain_capture_id);
    if (new_swapchain_info == nullptr)
    {
        log_error_("Captured Swapchain failed creating SwapchainInfo struct");
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    VkResult res = func(create_info->device, create_info->create_info, allocator, swapchain);
    if (res != VK_SUCCESS)
    {
        FreeSwapchainInfo(new_swapchain_info);
    }
    else
    {
        swapchain_infos_[*swapchain] = new_swapchain_info;
    }

    return res;
}

void VulkanCapturedSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                                  VkDevice                     device,
                                                  VkSwapchainKHR               swapchain,
                                                  const VkAllocationCallbacks* allocator)
{
    func(device, swapchain, allocator);

    auto create_info = swapchain_infos_.find(swapchain);
    if (create_info != swapchain_infos_.end())
    {
        FreeSwapchainInfo(swapchain_infos_[swapchain]);
        swapchain_infos_.erase(swapchain);
    }

    if (swapchain_image_tracker_)
    {
        delete swapchain_image_tracker_;
        swapchain_image_tracker_ = nullptr;
    }
}

VkResult VulkanCapturedSwapchain::GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                                        VkPhysicalDevice            physical_device,
                                                        VkDevice                    device,
                                                        VkSwapchainKHR              swapchain,
                                                        uint32_t                    capture_image_count,
                                                        uint32_t*                   replay_count_ptr,
                                                        uint32_t*                   image_count,
                                                        VkImage*                    images)
{
    auto result = func(device, swapchain, image_count, images);

    if ((image_count != nullptr) && (capture_image_count != *image_count))
    {
        log_warning_("The number of images returned by vkGetSwapchainImageKHR is different than the number "
                     "returned at capture, which may cause replay to fail.");
        log_warning_(
            "Try replay with the virtual swapchain mode via removing \"--use-captured-swapchain-indices\" option.");
    }

    return result;
}

VkResult VulkanCapturedSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR              func,
                                                  const std::vector<uint32_t>&       capture_image_indices,
                                                  const std::vector<VkSwapchainKHR>& swapchains,
                                                  VkQueue                            queue,
                                                  const VkPresentInfoKHR*            present_info)
{
    return func(queue, present_info);
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStateCommand(
    VkPhysicalDevice                                              physical_device,
    VkDevice                                                      device,
    const std::unordered_map<uint32_t, VkDeviceQueueCreateFlags>& queue_family_creation_flags,
    VkSwapchainKHR                                                swapchain,
    uint32_t*                                                     replay_count_ptr,
    std::vector<AcquiredIndexData>&                               acquired_info,
    VkSurfaceKHR                                                  surface,
    VkSurfaceCapabilitiesKHR&                                     surface_caps,
    uint32_t                                                      last_presented_image,
    const std::vector<AllocatedImageData>&                        image_info)
{
    const SwapchainInfo* swapchain_info = nullptr;

    auto sc_ci = swapchain_infos_.find(swapchain);
    if (sc_ci != swapchain_infos_.end())
    {
        swapchain_info = swapchain_infos_[swapchain];
    }
    else
    {
        log_error_("Failed to find SwapchainInfo for VkSwapchainKHR object (handle = 0x%" PRIx64 ")", swapchain);
        return;
    }

    assert((instance_table_ != nullptr) && (device_table_ != nullptr));

    uint32_t image_count = 0;
    VkResult result      = VK_SUCCESS;

    uint32_t capture_image_count = static_cast<uint32_t>(image_info.size());
    result                       = GetSwapchainImagesKHR(device_table_->GetSwapchainImagesKHR,
                                   physical_device,
                                   device,
                                   swapchain,
                                   capture_image_count,
                                   replay_count_ptr,
                                   &image_count,
                                   nullptr);
    if (result == VK_SUCCESS)
    {
        // Determine if it is possible to acquire all images at the same time.
        assert(image_count >= surface_caps.minImageCount);
        uint32_t max_acquired_images = (image_count - surface_caps.minImageCount) + 1;

        if (image_count > max_acquired_images)
        {
            // Cannot acquire all images at the same time.
            ProcessSetSwapchainImageStateQueueSubmit(device,
                                                     queue_family_creation_flags,
                                                     swapchain,
                                                     swapchain_info,
                                                     acquired_info,
                                                     last_presented_image,
                                                     image_info);
        }
        else
        {
            ProcessSetSwapchainImageStatePreAcquire(device, swapchain, swapchain_info, acquired_info, image_info);
        }
    }
    else
    {
        log_warning_("Failed image initialization for VkSwapchainKHR object (ID = %" PRIu64 ", handle = 0x%" PRIx64 ")",
                     swapchain_info->capture_id,
                     swapchain);
    }
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStatePreAcquire(VkDevice                        device,
                                                                      VkSwapchainKHR                  swapchain,
                                                                      const SwapchainInfo*            swapchain_info,
                                                                      std::vector<AcquiredIndexData>& acquired_info,
                                                                      const std::vector<AllocatedImageData>& image_info)
{
    assert(device_table_ != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         transition_queue   = VK_NULL_HANDLE;
    VkCommandPool   transition_pool    = VK_NULL_HANDLE;
    VkCommandBuffer transition_command = VK_NULL_HANDLE;
    uint32_t        queue_family_index = swapchain_info->create_info.pQueueFamilyIndices[0];

    // TODO: Improved queue selection?
    device_table_->GetDeviceQueue(device, queue_family_index, 0, &transition_queue);

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    result = device_table_->CreateCommandPool(device, &pool_create_info, nullptr, &transition_pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = transition_pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        device_table_->AllocateCommandBuffers(device, &command_allocate_info, &transition_command);
    }

    if (result == VK_SUCCESS)
    {
        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
        begin_info.pNext                    = nullptr;
        begin_info.flags                    = 0;
        begin_info.pInheritanceInfo         = nullptr;

        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.pNext              = nullptr;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &transition_command;

        VkImageMemoryBarrier image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        image_barrier.pNext                           = nullptr;
        image_barrier.srcAccessMask                   = 0;
        image_barrier.dstAccessMask                   = 0;
        image_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.baseMipLevel   = 0;
        image_barrier.subresourceRange.levelCount     = 1;
        image_barrier.subresourceRange.baseArrayLayer = 0;
        image_barrier.subresourceRange.layerCount     = 1;

        for (size_t i = 0; i < image_info.size(); ++i)
        {
            // Pre-acquire and transition swapchain images while processing trimming state snapshot.
            if (image_info[i].image != VK_NULL_HANDLE)
            {
                VkImage  image       = image_info[i].image;
                uint32_t image_index = 0;

                VkFence     acquire_fence     = VK_NULL_HANDLE;
                VkSemaphore acquire_semaphore = VK_NULL_HANDLE;

                VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
                fence_create_info.pNext             = nullptr;
                fence_create_info.flags             = 0;

                VkSemaphoreCreateInfo semaphore_create_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
                semaphore_create_info.pNext                 = nullptr;
                semaphore_create_info.flags                 = 0;

                result = device_table_->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);

                if (result == VK_SUCCESS)
                {
                    result =
                        device_table_->CreateSemaphore(device, &semaphore_create_info, nullptr, &acquire_semaphore);
                }

                if (result == VK_SUCCESS)
                {
                    result = device_table_->AcquireNextImageKHR(device,
                                                                swapchain,
                                                                std::numeric_limits<uint64_t>::max(),
                                                                acquire_semaphore,
                                                                acquire_fence,
                                                                &image_index);
                    if (image_index != static_cast<uint32_t>(i))
                    {
                        log_warning_("The image index returned by vkAcquireNextImageKHR is different than the "
                                     "expected index during setup");
                    }

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        result = device_table_->WaitForFences(
                            device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());

                        VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[image_index].image_layout);
                        if ((result == VK_SUCCESS) && (image_layout != VK_IMAGE_LAYOUT_UNDEFINED))
                        {
                            image_barrier.newLayout = image_layout;
                            image_barrier.image     = image;

                            result = device_table_->BeginCommandBuffer(transition_command, &begin_info);

                            if (result == VK_SUCCESS)
                            {
                                device_table_->CmdPipelineBarrier(transition_command,
                                                                  VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                                  VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                                  0,
                                                                  0,
                                                                  nullptr,
                                                                  0,
                                                                  nullptr,
                                                                  1,
                                                                  &image_barrier);
                                device_table_->EndCommandBuffer(transition_command);

                                result = device_table_->ResetFences(device, 1, &acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = device_table_->QueueSubmit(transition_queue, 1, &submit_info, acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = device_table_->WaitForFences(
                                    device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                            }
                        }

                        if (result == VK_SUCCESS)
                        {
                            if (image_info[image_index].acquired)
                            {
                                acquired_info[i] = { image_index, true };

                                // The upcoming frames expect the image to be acquired. The synchronization objects
                                // used to acquire the image were already set to the appropriate signaled state when
                                // created, so the temporary objects used to acquire the image here can be
                                // destroyed.
                                device_table_->DestroyFence(device, acquire_fence, nullptr);
                                device_table_->DestroySemaphore(device, acquire_semaphore, nullptr);
                            }
                            else
                            {
                                // The upcoming frames do not expect the image to be acquired. We will store the
                                // image and the synchronization objects used to acquire it in a data structure.
                                // Replay of vkAcquireNextImage will retrieve and use the stored objects.
                                swapchain_image_tracker_->TrackPreAcquiredImage(
                                    swapchain, image_index, acquire_semaphore, acquire_fence);
                            }
                        }
                        else
                        {
                            log_warning_("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                         ") for swapchain state initialization",
                                         image_info[i].image_id);
                        }
                    }
                }
            }
            else
            {
                log_warning_("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                             image_info[i].image_id);
            }
        }
    }
    else
    {
        log_warning_("Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64
                     ")",
                     swapchain);
    }

    if (transition_pool != VK_NULL_HANDLE)
    {
        device_table_->DestroyCommandPool(device, transition_pool, nullptr);
    }
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStateQueueSubmit(
    VkDevice                                                      device,
    const std::unordered_map<uint32_t, VkDeviceQueueCreateFlags>& queue_family_creation_flags,
    VkSwapchainKHR                                                swapchain,
    const SwapchainInfo*                                          swapchain_info,
    std::vector<AcquiredIndexData>&                               acquired_info,
    uint32_t                                                      last_presented_image,
    const std::vector<AllocatedImageData>&                        image_info)
{
    assert(device_table_ != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         queue              = VK_NULL_HANDLE;
    VkCommandPool   pool               = VK_NULL_HANDLE;
    VkCommandBuffer command            = VK_NULL_HANDLE;
    VkFence         wait_fence         = VK_NULL_HANDLE;
    uint32_t        queue_family_index = swapchain_info->create_info.pQueueFamilyIndices[0];

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    const auto queue_family_flags = queue_family_creation_flags.find(queue_family_index);
    assert(queue_family_flags != queue_family_creation_flags.end());
    if (queue_family_flags->second != 0)
    {
        const VkDeviceQueueInfo2 queue_info = {
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, nullptr, queue_family_flags->second, queue_family_index, 0
        };
        device_table_->GetDeviceQueue2(device, &queue_info, &queue);
    }
    else
    {
        device_table_->GetDeviceQueue(device, queue_family_index, 0, &queue);
    }

    result = device_table_->CreateCommandPool(device, &pool_create_info, nullptr, &pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        result = device_table_->AllocateCommandBuffers(device, &command_allocate_info, &command);
    }

    if (result == VK_SUCCESS)
    {
        VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
        fence_create_info.pNext             = nullptr;
        fence_create_info.flags             = VK_FENCE_CREATE_SIGNALED_BIT;

        result = device_table_->CreateFence(device, &fence_create_info, nullptr, &wait_fence);
    }

    if (result == VK_SUCCESS)
    {
        VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
        begin_info.pNext                    = nullptr;
        begin_info.flags                    = 0;
        begin_info.pInheritanceInfo         = nullptr;

        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.pNext              = nullptr;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &command;

        VkImageMemoryBarrier image_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        image_barrier.pNext                           = nullptr;
        image_barrier.srcAccessMask                   = 0;
        image_barrier.dstAccessMask                   = 0;
        image_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.newLayout                       = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        image_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.baseMipLevel   = 0;
        image_barrier.subresourceRange.levelCount     = 1;
        image_barrier.subresourceRange.baseArrayLayer = 0;
        image_barrier.subresourceRange.layerCount     = 1;

        VkPresentInfoKHR present_info   = { VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
        present_info.pNext              = nullptr;
        present_info.waitSemaphoreCount = 0;
        present_info.pWaitSemaphores    = nullptr;
        present_info.swapchainCount     = 1;
        present_info.pSwapchains        = &swapchain;
        present_info.pResults           = nullptr;

        // Acquire, transition to the present source layout, and present each image.
        for (size_t i = 0; i < image_info.size(); ++i)
        {
            if (image_info[i].image != VK_NULL_HANDLE)
            {
                VkImage  image       = image_info[i].image;
                uint32_t image_index = 0;

                result = device_table_->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = device_table_->AcquireNextImageKHR(device,
                                                                swapchain,
                                                                std::numeric_limits<uint64_t>::max(),
                                                                VK_NULL_HANDLE,
                                                                wait_fence,
                                                                &image_index);
                    if (image_index != static_cast<uint32_t>(i))
                    {
                        log_warning_("The image index returned by vkAcquireNextImageKHR is different than the "
                                     "expected index during setup");
                    }
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    result = device_table_->WaitForFences(
                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        image_barrier.image        = image;
                        present_info.pImageIndices = &image_index;

                        result = device_table_->BeginCommandBuffer(command, &begin_info);
                    }

                    if (result == VK_SUCCESS)
                    {
                        device_table_->CmdPipelineBarrier(command,
                                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                          VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                          0,
                                                          0,
                                                          nullptr,
                                                          0,
                                                          nullptr,
                                                          1,
                                                          &image_barrier);
                        device_table_->EndCommandBuffer(command);

                        result = device_table_->ResetFences(device, 1, &wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = device_table_->QueueSubmit(queue, 1, &submit_info, wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = device_table_->WaitForFences(
                            device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = device_table_->QueuePresentKHR(queue, &present_info);
                    }

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        result = device_table_->QueueWaitIdle(queue);
                    }
                }

                if (result != VK_SUCCESS)
                {
                    log_warning_("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                 ") for swapchain state initialization",
                                 image_info[i].image_id);
                }
            }
            else
            {
                log_warning_("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                             image_info[i].image_id);
            }
        }

        // Second pass to set image acquired state.
        // Acquire all images up to the last presented image, to increase the chance that the first image
        // acquired on replay is the same image acquired by the first captured frame.
        for (size_t i = 0; i < image_info.size(); ++i)
        {
            if ((image_info[i].image != VK_NULL_HANDLE) && ((image_info[i].acquired) || (i <= last_presented_image)))
            {
                VkImage  image       = image_info[i].image;
                uint32_t image_index = 0;

                result = device_table_->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = device_table_->AcquireNextImageKHR(device,
                                                                swapchain,
                                                                std::numeric_limits<uint64_t>::max(),
                                                                VK_NULL_HANDLE,
                                                                wait_fence,
                                                                &image_index);
                    if (image_index != static_cast<uint32_t>(i))
                    {
                        log_warning_("The image index returned by vkAcquireNextImageKHR is different than the "
                                     "expected index during setup");
                    }
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    result = device_table_->WaitForFences(
                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        if (image_info[i].acquired)
                        {
                            acquired_info[i] = { image_index, true };

                            // Transition the image to the expected layout and keep it acquired.
                            VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[i].image_layout);
                            if ((image_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                                (image_layout != VK_IMAGE_LAYOUT_PRESENT_SRC_KHR))
                            {

                                image_barrier.newLayout = image_layout;
                                image_barrier.image     = image;

                                result = device_table_->BeginCommandBuffer(command, &begin_info);

                                if (result == VK_SUCCESS)
                                {
                                    device_table_->CmdPipelineBarrier(command,
                                                                      VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                                      VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                                      0,
                                                                      0,
                                                                      nullptr,
                                                                      0,
                                                                      nullptr,
                                                                      1,
                                                                      &image_barrier);
                                    device_table_->EndCommandBuffer(command);

                                    result = device_table_->ResetFences(device, 1, &wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = device_table_->QueueSubmit(queue, 1, &submit_info, wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = device_table_->WaitForFences(
                                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                                }
                            }
                        }
                        else
                        {
                            // Image is not expected to be in the acquired state, so present it.
                            present_info.pImageIndices = &image_index;

                            result = device_table_->QueuePresentKHR(queue, &present_info);

                            if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                            {
                                result = device_table_->QueueWaitIdle(queue);
                            }
                        }
                    }
                }

                if (result != VK_SUCCESS)
                {
                    log_warning_("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                 ") for swapchain state initialization",
                                 image_info[i].image_id);
                }
            }
        }
    }
    else
    {
        log_warning_("Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64
                     ")",
                     swapchain);
    }

    if (pool != VK_NULL_HANDLE)
    {
        device_table_->DestroyCommandPool(device, pool, nullptr);
    }

    if (wait_fence != VK_NULL_HANDLE)
    {
        device_table_->DestroyFence(device, wait_fence, nullptr);
    }
}

bool VulkanCapturedSwapchain::RetrievePreAcquiredImage(VkSwapchainKHR swapchain,
                                                       uint32_t       image_index,
                                                       VkSemaphore*   semaphore,
                                                       VkFence*       fence)
{
    return swapchain_image_tracker_->RetrievePreAcquiredImage(swapchain, image_index, semaphore, fence);
}

} // namespace compatibility
} // namespace gfxrecon
