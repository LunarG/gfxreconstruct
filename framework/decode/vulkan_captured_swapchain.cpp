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

#include "decode/vulkan_captured_swapchain.h"
#include "decode/decoder_util.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanCapturedSwapchain::CreateSwapchainKHR(VkResult                              original_result,
                                                     PFN_vkCreateSwapchainKHR              func,
                                                     const VulkanDeviceInfo*               device_info,
                                                     const VkSwapchainCreateInfoKHR*       create_info,
                                                     const VkAllocationCallbacks*          allocator,
                                                     HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                                     const encode::VulkanDeviceTable*      device_table)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }
    device_table_         = device_table;
    auto replay_swapchain = swapchain->GetHandlePointer();
    return func(device, create_info, allocator, replay_swapchain);
}

void VulkanCapturedSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR     func,
                                                  const VulkanDeviceInfo*       device_info,
                                                  const VulkanSwapchainKHRInfo* swapchain_info,
                                                  const VkAllocationCallbacks*  allocator)
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

VkResult VulkanCapturedSwapchain::GetSwapchainImagesKHR(VkResult                    original_result,
                                                        PFN_vkGetSwapchainImagesKHR func,
                                                        const VulkanDeviceInfo*     device_info,
                                                        VulkanSwapchainKHRInfo*     swapchain_info,
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
        GFXRECON_LOG_WARNING("The number of images returned by vkGetSwapchainImageKHR is different than the number "
                             "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_WARNING(
            "Try replay with the virtual swapchain mode via removing \"--use-captured-swapchain-indices\" option.");
    }

    return result;
}

VkResult VulkanCapturedSwapchain::AcquireNextImageKHR(VkResult                  original_result,
                                                      PFN_vkAcquireNextImageKHR func,
                                                      const VulkanDeviceInfo*   device_info,
                                                      VulkanSwapchainKHRInfo*   swapchain_info,
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
        GFXRECON_LOG_WARNING("The image index returned by vkAcquireNextImageKHR is different than the index "
                             "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_WARNING(
            "Try replay with the virtual swapchain mode via removing \"--use-captured-swapchain-indices\" option.");
    }

    return result;
}

VkResult VulkanCapturedSwapchain::AcquireNextImage2KHR(VkResult                         original_result,
                                                       PFN_vkAcquireNextImage2KHR       func,
                                                       const VulkanDeviceInfo*          device_info,
                                                       VulkanSwapchainKHRInfo*          swapchain_info,
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
        GFXRECON_LOG_WARNING("The image index returned by vkAcquireNextImageKHR is different than the index "
                             "returned at capture, which may cause replay to fail.");
        GFXRECON_LOG_WARNING(
            "Try replay with the virtual swapchain mode via removing \"--use-captured-swapchain-indices\" option.");
    }

    return result;
}

VkResult VulkanCapturedSwapchain::QueuePresentKHR(VkResult                                    original_result,
                                                  PFN_vkQueuePresentKHR                       func,
                                                  const std::vector<uint32_t>&                capture_image_indices,
                                                  const std::vector<VulkanSwapchainKHRInfo*>& swapchain_infos,
                                                  const VulkanQueueInfo*                      queue_info,
                                                  const VkPresentInfoKHR*                     present_info)
{
    VkQueue queue = VK_NULL_HANDLE;

    if (queue_info != nullptr)
    {
        queue = queue_info->handle;
    }

    return func(queue, present_info);
}

VkResult VulkanCapturedSwapchain::CreateRenderPass(VkResult                      original_result,
                                                   PFN_vkCreateRenderPass        func,
                                                   const VulkanDeviceInfo*       device_info,
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

VkResult VulkanCapturedSwapchain::CreateRenderPass2(VkResult                       original_result,
                                                    PFN_vkCreateRenderPass2        func,
                                                    const VulkanDeviceInfo*        device_info,
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

void VulkanCapturedSwapchain::CmdPipelineBarrier(PFN_vkCmdPipelineBarrier       func,
                                                 const VulkanCommandBufferInfo* command_buffer_info,
                                                 VkPipelineStageFlags           src_stage_mask,
                                                 VkPipelineStageFlags           dst_stage_mask,
                                                 VkDependencyFlags              dependency_flags,
                                                 uint32_t                       memory_barrier_count,
                                                 const VkMemoryBarrier*         memory_barriers,
                                                 uint32_t                       buffer_memory_barrier_count,
                                                 const VkBufferMemoryBarrier*   buffer_memory_barriers,
                                                 uint32_t                       image_memory_barrier_count,
                                                 const VkImageMemoryBarrier*    image_memory_barriers)
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

void VulkanCapturedSwapchain::CmdPipelineBarrier2(PFN_vkCmdPipelineBarrier2 func,
                                                  VulkanCommandBufferInfo*  command_buffer_info,
                                                  const VkDependencyInfo*   pDependencyInfo)
{

    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    if (command_buffer_info != nullptr)
    {
        command_buffer = command_buffer_info->handle;
    }

    func(command_buffer, pDependencyInfo);
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStateCommand(
    const VulkanDeviceInfo*                             device_info,
    VulkanSwapchainKHRInfo*                             swapchain_info,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info,
    const VulkanObjectInfoTable&                        object_info_table,
    SwapchainImageTracker&                              swapchain_image_tracker)
{
    VkDevice       device    = device_info->handle;
    VkSwapchainKHR swapchain = swapchain_info->handle;

    VkPhysicalDevice physical_device = device_info->parent;
    assert(physical_device != VK_NULL_HANDLE);

    const VulkanSurfaceKHRInfo* surface_info = object_info_table.GetVkSurfaceKHRInfo(swapchain_info->surface_id);
    if (surface_info->surface_creation_skipped)
    {
        return;
    }

    VkSurfaceKHR surface = swapchain_info->surface;
    assert((surface_info != nullptr) && (instance_table_ != nullptr) && (device_table_ != nullptr));

    VkSurfaceCapabilitiesKHR surface_caps;
    uint32_t                 image_count = 0;

    const auto& entry  = surface_info->surface_capabilities.find(physical_device);
    VkResult    result = VK_SUCCESS;
    if (entry != surface_info->surface_capabilities.end())
    {
        surface_caps = entry->second;
    }
    else
    {
        result = instance_table_->GetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &surface_caps);
    }

    if (result == VK_SUCCESS)
    {
        uint32_t capture_image_count = static_cast<uint32_t>(image_info.size());
        result                       = GetSwapchainImagesKHR(VK_SUCCESS,
                                       device_table_->GetSwapchainImagesKHR,
                                       device_info,
                                       swapchain_info,
                                       capture_image_count,
                                       &image_count,
                                       nullptr);
    }

    if (result == VK_SUCCESS)
    {
        // Determine if it is possible to acquire all images at the same time.
        assert(image_count >= surface_caps.minImageCount);
        uint32_t max_acquired_images = (image_count - surface_caps.minImageCount) + 1;

        if (image_count > max_acquired_images)
        {
            // Cannot acquire all images at the same time.
            ProcessSetSwapchainImageStateQueueSubmit(
                device_info, swapchain_info, last_presented_image, image_info, object_info_table);
        }
        else
        {
            ProcessSetSwapchainImageStatePreAcquire(
                device_info, swapchain_info, image_info, object_info_table, swapchain_image_tracker);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed image initialization for VkSwapchainKHR object (ID = %" PRIu64
                             ", handle = 0x%" PRIx64 ")",
                             swapchain_info->capture_id,
                             swapchain);
    }
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStatePreAcquire(
    const VulkanDeviceInfo*                             device_info,
    VulkanSwapchainKHRInfo*                             swapchain_info,
    const std::vector<format::SwapchainImageStateInfo>& image_info,
    const VulkanObjectInfoTable&                        object_info_table,
    SwapchainImageTracker&                              swapchain_image_tracker)
{
    VkDevice device = device_info->handle;
    assert(device_table_ != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         transition_queue   = VK_NULL_HANDLE;
    VkCommandPool   transition_pool    = VK_NULL_HANDLE;
    VkCommandBuffer transition_command = VK_NULL_HANDLE;
    VkSwapchainKHR  swapchain          = swapchain_info->handle;
    uint32_t        queue_family_index = swapchain_info->queue_family_indices[0];

    // TODO: Improved queue selection?
    transition_queue = GetDeviceQueue(device_table_, device_info, queue_family_index, 0);

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
            const VulkanImageInfo* image_entry = object_info_table.GetVkImageInfo(image_info[i].image_id);

            // Pre-acquire and transition swapchain images while processing trimming state snapshot.
            if (image_entry != nullptr)
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
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
                    result = AcquireNextImageKHR(VK_SUCCESS,
                                                 device_table_->AcquireNextImageKHR,
                                                 device_info,
                                                 swapchain_info,
                                                 std::numeric_limits<uint64_t>::max(),
                                                 acquire_semaphore,
                                                 acquire_fence,
                                                 static_cast<uint32_t>(i),
                                                 &image_index);

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
                                swapchain_info->acquired_indices[i] = { image_index, true };

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
                                swapchain_image_tracker.TrackPreAcquiredImage(
                                    swapchain, image_index, acquire_semaphore, acquire_fence);
                            }
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                                 ") for swapchain state initialization",
                                                 image_info[i].image_id);
                        }
                    }
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64 ")",
            swapchain);
    }

    if (transition_pool != VK_NULL_HANDLE)
    {
        device_table_->DestroyCommandPool(device, transition_pool, nullptr);
    }
}

void VulkanCapturedSwapchain::ProcessSetSwapchainImageStateQueueSubmit(
    const VulkanDeviceInfo*                             device_info,
    VulkanSwapchainKHRInfo*                             swapchain_info,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info,
    const VulkanObjectInfoTable&                        object_info_table)
{
    auto device = device_info->handle;
    assert(device_table_ != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         queue              = VK_NULL_HANDLE;
    VkCommandPool   pool               = VK_NULL_HANDLE;
    VkCommandBuffer command            = VK_NULL_HANDLE;
    VkFence         wait_fence         = VK_NULL_HANDLE;
    VkSwapchainKHR  swapchain          = swapchain_info->handle;
    uint32_t        queue_family_index = swapchain_info->queue_family_indices[0];

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    queue = GetDeviceQueue(device_table_, device_info, queue_family_index, 0);

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
            const VulkanImageInfo* image_entry = object_info_table.GetVkImageInfo(image_info[i].image_id);

            if (image_entry != nullptr)
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = device_table_->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = AcquireNextImageKHR(VK_SUCCESS,
                                                 device_table_->AcquireNextImageKHR,
                                                 device_info,
                                                 swapchain_info,
                                                 std::numeric_limits<uint64_t>::max(),
                                                 VK_NULL_HANDLE,
                                                 wait_fence,
                                                 static_cast<uint32_t>(i),
                                                 &image_index);
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
                    GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                         ") for swapchain state initialization",
                                         image_info[i].image_id);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }

        // Second pass to set image acquired state.
        // Acquire all images up to the last presented image, to increase the chance that the first image
        // acquired on replay is the same image acquired by the first captured frame.
        for (size_t i = 0; i < image_info.size(); ++i)
        {
            const VulkanImageInfo* image_entry = object_info_table.GetVkImageInfo(image_info[i].image_id);

            if ((image_entry != nullptr) && ((image_info[i].acquired) || (i <= last_presented_image)))
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = device_table_->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = AcquireNextImageKHR(VK_SUCCESS,
                                                 device_table_->AcquireNextImageKHR,
                                                 device_info,
                                                 swapchain_info,
                                                 std::numeric_limits<uint64_t>::max(),
                                                 VK_NULL_HANDLE,
                                                 wait_fence,
                                                 static_cast<uint32_t>(i),
                                                 &image_index);
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    result = device_table_->WaitForFences(
                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        if (image_info[i].acquired)
                        {
                            swapchain_info->acquired_indices[i] = { image_index, true };

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
                    GFXRECON_LOG_WARNING("Failed to acquire and transition VkImage object (ID = %" PRIu64
                                         ") for swapchain state initialization",
                                         image_info[i].image_id);
                }
            }
            else if (image_entry == nullptr)
            {
                GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkImage object (ID = %" PRIu64 ")",
                                     image_info[i].image_id);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Failed to create image initialization resources for VkSwapchainKHR object (handle = 0x%" PRIx64 ")",
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
