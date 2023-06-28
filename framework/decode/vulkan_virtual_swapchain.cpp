/*
** Copyright (c) 2021-2022 LunarG, Inc.
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

#include "decode/vulkan_virtual_swapchain.h"

#include "decode/vulkan_resource_allocator.h"

#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanVirtualSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
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
    instance_table_ = instance_table;
    device_table_   = device_table;

    VkSwapchainCreateInfoKHR modified_create_info = *create_info;
    modified_create_info.imageUsage =
        modified_create_info.imageUsage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

    VkSurfaceCapabilitiesKHR surfCapabilities;
    auto                     result = instance_table_->GetPhysicalDeviceSurfaceCapabilitiesKHR(
        physical_device, create_info->surface, &surfCapabilities);
    GFXRECON_ASSERT(result == VK_SUCCESS);

    if (modified_create_info.minImageCount < surfCapabilities.minImageCount)
    {
        modified_create_info.minImageCount = surfCapabilities.minImageCount;
    }
    if ((surfCapabilities.maxImageCount > 0) && (modified_create_info.minImageCount > surfCapabilities.maxImageCount))
    {
        modified_create_info.minImageCount = surfCapabilities.maxImageCount;
    }
    return func(device, &modified_create_info, allocator, swapchain);
}

void VulkanVirtualSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                                 const DeviceInfo*            device_info,
                                                 const SwapchainKHRInfo*      swapchain_info,
                                                 const VkAllocationCallbacks* allocator)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        device    = device_info->handle;
        swapchain = swapchain_info->handle;

        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        for (const ImageInfo& image_info : swapchain_info->image_infos)
        {
            allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
        for (const SwapchainKHRInfo::VirtualImage& image_info : swapchain_info->virtual_swapchain_images)
        {
            allocator->DestroyImageDirect(image_info.image, nullptr, image_info.resource_allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
        for (uint32_t ii = 0; ii < static_cast<uint32_t>(swapchain_info->blit_command_pools.size()); ++ii)
        {
            device_table_->FreeCommandBuffers(device,
                                              swapchain_info->blit_command_pools[ii],
                                              static_cast<uint32_t>(swapchain_info->blit_command_buffers[ii].size()),
                                              swapchain_info->blit_command_buffers[ii].data());
            device_table_->DestroyCommandPool(device, swapchain_info->blit_command_pools[ii], nullptr);
        }
        for (auto& semaphore_vec : swapchain_info->blit_semaphores)
        {
            for (auto& semaphore : semaphore_vec)
            {
                device_table_->DestroySemaphore(device, semaphore, nullptr);
            }
        }
    }
    func(device, swapchain, allocator);
}

VkResult VulkanVirtualSwapchain::GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                                       const DeviceInfo*           device_info,
                                                       SwapchainKHRInfo*           swapchain_info,
                                                       uint32_t                    capture_image_count,
                                                       uint32_t*                   image_count,
                                                       VkImage*                    images)
{
    VkDevice       device             = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain          = VK_NULL_HANDLE;
    uint32_t*      replay_image_count = nullptr;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain          = swapchain_info->handle;
        replay_image_count = &swapchain_info->replay_image_count;

        if (images != nullptr)
        {
            swapchain_info->replay_swapchain_images.resize(*replay_image_count);
        }
    }

    // TODO: Adjust the swapchain image format if the specified format is not supported by the replay device.

    auto result = func(device, swapchain, replay_image_count, swapchain_info->replay_swapchain_images.data());

    if (static_cast<uint32_t>(swapchain_info->capture_to_replay_index.size()) != capture_image_count)
    {
        swapchain_info->capture_to_replay_index.resize(capture_image_count);
    }

    if ((result == VK_SUCCESS) && (image_count != nullptr))
    {
        uint32_t blit_queue_family_index = 0;

        // Determine what queue to use for the initial virtual image setup
        VkQueue                              initial_blit_queue = VK_NULL_HANDLE;
        uint32_t                             property_count     = 0;
        std::vector<VkQueueFamilyProperties> props;

        instance_table_->GetPhysicalDeviceQueueFamilyProperties(device_info->parent, &property_count, nullptr);
        props.resize(property_count);
        instance_table_->GetPhysicalDeviceQueueFamilyProperties(device_info->parent, &property_count, props.data());

        for (uint32_t queue_family_index = 0; queue_family_index < property_count; ++queue_family_index)
        {
            if (props[queue_family_index].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                blit_queue_family_index = queue_family_index;
                device_table_->GetDeviceQueue(device, blit_queue_family_index, 0, &initial_blit_queue);
                if (initial_blit_queue != VK_NULL_HANDLE)
                {
                    break;
                }
            }
        }

        // Make sure we have enough storage for each of our tracked components (Command pools,
        // Command Buffers, Semaphores, etc) as many queue families that are available.
        // This is because at any point, the application may get a Device queue from that family and
        // use it during the present.
        uint32_t start_size = static_cast<uint32_t>(swapchain_info->blit_command_pools.size());
        uint32_t new_count  = property_count;
        if (start_size < new_count)
        {
            swapchain_info->blit_command_pools.resize(new_count);
            swapchain_info->blit_command_buffers.resize(new_count);
            swapchain_info->blit_semaphores.resize(new_count);
            for (uint32_t ii = start_size; ii < new_count; ++ii)
            {
                swapchain_info->blit_command_pools[ii] = VK_NULL_HANDLE;
            }

            for (uint32_t queue_family_index = 0; queue_family_index < property_count; ++queue_family_index)
            {
                // Create one command pool per queue.
                if (swapchain_info->blit_command_pools[queue_family_index] == VK_NULL_HANDLE)
                {
                    VkCommandPoolCreateInfo command_pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
                    command_pool_create_info.flags =
                        VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
                    command_pool_create_info.queueFamilyIndex = queue_family_index;
                    VkResult result =
                        device_table_->CreateCommandPool(device,
                                                         &command_pool_create_info,
                                                         nullptr,
                                                         &swapchain_info->blit_command_pools[queue_family_index]);
                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR(
                            "Virtual swapchain failed creating command pool %d for swapchain (ID = %" PRIu64 ")",
                            queue_family_index,
                            swapchain_info->capture_id);
                        return result;
                    }
                }

                // Create one command buffer per queue per swapchain image so that we don't reset a command buffer that
                // may be in active use.
                uint32_t command_buffer_count =
                    static_cast<uint32_t>(swapchain_info->blit_command_buffers[queue_family_index].size());
                if (command_buffer_count < capture_image_count)
                {
                    swapchain_info->blit_command_buffers[queue_family_index].resize(capture_image_count);

                    uint32_t                    new_count     = capture_image_count - command_buffer_count;
                    VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
                    allocate_info.pNext                       = nullptr;
                    allocate_info.commandPool                 = swapchain_info->blit_command_pools[queue_family_index];
                    allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                    allocate_info.commandBufferCount          = new_count;
                    result                                    = device_table_->AllocateCommandBuffers(
                        device,
                        &allocate_info,
                        &swapchain_info->blit_command_buffers[queue_family_index][command_buffer_count]);
                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Virtual swapchain failed allocating internal command buffer %d for "
                                           "swapchain (ID = %" PRIu64 ")",
                                           queue_family_index,
                                           swapchain_info->capture_id);
                        return result;
                    }
                }

                uint32_t semaphore_count =
                    static_cast<uint32_t>(swapchain_info->blit_semaphores[queue_family_index].size());
                if (semaphore_count < capture_image_count)
                {
                    swapchain_info->blit_semaphores[queue_family_index].resize(capture_image_count);

                    for (uint32_t ii = semaphore_count; ii < capture_image_count; ++ii)
                    {
                        VkSemaphoreCreateInfo semaphore_create_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
                        semaphore_create_info.pNext                 = nullptr;
                        semaphore_create_info.flags                 = 0;
                        VkSemaphore semaphore                       = 0;
                        result = device_table_->CreateSemaphore(device, &semaphore_create_info, nullptr, &semaphore);
                        if (result != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR(
                                "Virtual swapchain failed creating internal BLIT semaphore for swapchain (ID = %" PRIu64
                                ")",
                                swapchain_info->capture_id);
                            return result;
                        }
                        swapchain_info->blit_semaphores[queue_family_index][ii] = semaphore;
                    }
                }
            }
        }

        // Return the capture count.  The virtual swapchain will create a number of virtual images equal to the capture
        // count.  The virtual images will be returned to the caller in place of the real swapchain images.
        (*image_count) = capture_image_count;

        if ((device_info != nullptr) && (swapchain_info != nullptr) && (images != nullptr))
        {
            uint32_t virtual_swapchain_count = static_cast<uint32_t>(swapchain_info->virtual_swapchain_images.size());

            // If the call was made more than once because the first call returned VK_INCOMPLETE, only the new images
            // returned by the second call will have virtual images created and appended to the end of the virtual image
            // array.
            if (virtual_swapchain_count < capture_image_count)
            {
                // TODO: This is the same code used in VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR, which
                // should be moved to a shared graphics utility function.

                //  Create an image for the virtual swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
                VkImageCreateInfo image_create_info = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
                image_create_info.pNext             = nullptr;
                image_create_info.flags             = 0;
                image_create_info.imageType         = VK_IMAGE_TYPE_2D;
                image_create_info.format            = swapchain_info->format;
                image_create_info.extent            = { swapchain_info->width, swapchain_info->height, 1 };
                image_create_info.mipLevels         = 1;
                image_create_info.arrayLayers       = swapchain_info->image_array_layers;
                image_create_info.samples           = VK_SAMPLE_COUNT_1_BIT;
                image_create_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
                image_create_info.usage             = swapchain_info->image_usage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
                image_create_info.sharingMode       = swapchain_info->image_sharing_mode;
                image_create_info.queueFamilyIndexCount =
                    static_cast<uint32_t>(swapchain_info->queue_family_indices.size());
                image_create_info.pQueueFamilyIndices = swapchain_info->queue_family_indices.data();
                image_create_info.initialLayout       = VK_IMAGE_LAYOUT_UNDEFINED;

                if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                    VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
                {
                    image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
                }

                VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
                begin_info.pNext                    = nullptr;
                begin_info.flags                    = 0;
                begin_info.pInheritanceInfo         = nullptr;

                auto command_buffer = swapchain_info->blit_command_buffers[blit_queue_family_index][0];

                result = device_table_->ResetCommandBuffer(command_buffer, 0);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR(
                        "Virtual swapchain failed resetting internal command buffer %d for swapchain (ID = %" PRIu64
                        ")",
                        blit_queue_family_index,
                        swapchain_info->capture_id);
                    return result;
                }

                result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR(
                        "Virtual swapchain failed starting internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                        blit_queue_family_index,
                        swapchain_info->capture_id);
                    return result;
                }

                for (uint32_t i = virtual_swapchain_count; i < capture_image_count; ++i)
                {
                    SwapchainKHRInfo::VirtualImage image;

                    result = CreateVirtualSwapchainImage(device_info, image_create_info, image);

                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Failed to create virtual swapchain image for swapchain (ID = %" PRIu64 ")",
                                           swapchain_info->capture_id);
                        break;
                    }
                    swapchain_info->virtual_swapchain_images.emplace_back(std::move(image));
                }

                VkImageMemoryBarrier barrier = {
                    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                    nullptr,
                    VK_ACCESS_NONE,
                    VK_ACCESS_NONE,
                    VK_IMAGE_LAYOUT_UNDEFINED,
                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                    VK_QUEUE_FAMILY_IGNORED,
                    VK_QUEUE_FAMILY_IGNORED,
                    VK_NULL_HANDLE,
                    VkImageSubresourceRange{
                        VK_IMAGE_ASPECT_COLOR_BIT,
                        0,
                        image_create_info.mipLevels,
                        0,
                        image_create_info.arrayLayers,
                    },
                };

                for (uint32_t i = 0; i < *replay_image_count; ++i)
                {
                    barrier.image = swapchain_info->replay_swapchain_images[i];
                    device_table_->CmdPipelineBarrier(command_buffer,
                                                      VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                      VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                      0,
                                                      0,
                                                      nullptr,
                                                      0,
                                                      nullptr,
                                                      1,
                                                      &barrier);
                }

                result = device_table_->EndCommandBuffer(command_buffer);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR(
                        "Virtual swapchain failed ending internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                        blit_queue_family_index,
                        swapchain_info->capture_id);
                    return result;
                }

                VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
                submit_info.commandBufferCount = 1;
                submit_info.pCommandBuffers    = &command_buffer;

                result = device_table_->QueueSubmit(initial_blit_queue, 1, &submit_info, VK_NULL_HANDLE);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR(
                        "Virtual swapchain failed submitting internal command buffer %d for swapchain (ID = %" PRIu64
                        ")",
                        blit_queue_family_index,
                        swapchain_info->capture_id);
                    return result;
                }
                result = device_table_->QueueWaitIdle(initial_blit_queue);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR(
                        "Virtual swapchain failed waiting for internal command buffer %d for swapchain (ID = %" PRIu64
                        ")",
                        blit_queue_family_index,
                        swapchain_info->capture_id);
                    return result;
                }
            }

            for (uint32_t i = 0; i < capture_image_count; ++i)
            {
                images[i] = swapchain_info->virtual_swapchain_images[i].image;
            }
        }
    }

    return result;
}

VkResult VulkanVirtualSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
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

VkResult VulkanVirtualSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
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
    VkResult       result    = VK_NOT_READY;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    result = func(device, swapchain, timeout, semaphore, fence, image_index);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Virtual swapchain failed AcquireNextImageKHR 0x%08x for swapchain (ID = %" PRIu64 ")",
                           result,
                           swapchain_info->capture_id);
    }
    return result;
}

VkResult VulkanVirtualSwapchain::AcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                                      const DeviceInfo*                device_info,
                                                      SwapchainKHRInfo*                swapchain_info,
                                                      const VkAcquireNextImageInfoKHR* acquire_info,
                                                      uint32_t                         capture_image_index,
                                                      uint32_t*                        image_index)
{
    VkDevice device = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    VkResult result = func(device, acquire_info, image_index);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Virtual swapchain failed AcquireNextImage2KHR 0x%08x for swapchain (ID = %" PRIu64 ")",
                           result,
                           swapchain_info->capture_id);
    }
    return result;
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                                 const std::vector<uint32_t>&          capture_image_indices,
                                                 const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                 const QueueInfo*                      queue_info,
                                                 const VkPresentInfoKHR*               present_info)
{
    VkResult result = VK_ERROR_UNKNOWN;
    VkQueue  queue  = VK_NULL_HANDLE;
    if (queue_info == nullptr)
    {
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }
    queue = queue_info->handle;

    // TODO: Note that this blit could also be used to scale the image, which would allow replay to support an option
    // for changing the window/swapchain size when the virtual swapchain mode is active.  The virtual image would
    // continue to use the captured swapchain image size, and be scaled to the replay swapchain image size with
    // vkCmdBlitImage.

    VkCommandBufferBeginInfo begin_info  = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    VkImageSubresourceLayers subresource = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 0 };
    VkOffset3D               offset      = { 0, 0, 0 };

    auto                     swapchainCount = present_info->swapchainCount;
    std::vector<VkSemaphore> present_wait_semaphores;

    std::vector<VkPipelineStageFlags> wait_stages;
    wait_stages.resize(present_info->waitSemaphoreCount);
    for (uint32_t j = 0; j < present_info->waitSemaphoreCount; ++j)
    {
        wait_stages.push_back(VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);
    }

    for (uint32_t i = 0; i < swapchainCount; ++i)
    {
        const auto* swapchain_info      = swapchain_infos[i];
        uint32_t    capture_image_index = capture_image_indices[i];
        uint32_t    replay_image_index  = present_info->pImageIndices[i];
        const auto& virtual_image       = swapchain_info->virtual_swapchain_images[capture_image_index];
        const auto& replay_image        = swapchain_info->replay_swapchain_images[replay_image_index];

        // Use a command buffer and semaphore from the same queue index
        assert(swapchain_info->device_info->queue_family_indices.find(queue) !=
               swapchain_info->device_info->queue_family_indices.end());
        uint32_t queue_family_index = swapchain_info->device_info->queue_family_indices[queue];
        auto     command_buffer     = swapchain_info->blit_command_buffers[queue_family_index][capture_image_index];
        auto     blit_semaphore     = swapchain_info->blit_semaphores[queue_family_index][capture_image_index];

        std::vector<VkSemaphore> wait_semaphores;
        std::vector<VkSemaphore> signal_semaphores;

        // Only wait on the first Blit
        if (i == 0)
        {
            if (present_info->waitSemaphoreCount > 0)
            {
                for (uint32_t j = 0; j < present_info->waitSemaphoreCount; ++j)
                {
                    wait_semaphores.push_back(present_info->pWaitSemaphores[j]);
                }
            }
        }
        // Only trigger a semaphore on the last Blit
        // NOTE: Not an "else if" because the first Blit and last Blit might be the
        //       same Blit.
        if (i == swapchainCount - 1)
        {
            signal_semaphores.push_back(blit_semaphore);
            present_wait_semaphores.emplace_back(blit_semaphore);
        }

        subresource.layerCount   = swapchain_info->image_array_layers;
        VkExtent3D  image_extent = { swapchain_info->width, swapchain_info->height, 1 };
        VkImageCopy image_copy   = { subresource, offset, subresource, offset, image_extent };

        result = device_table_->ResetCommandBuffer(command_buffer, 0);
        if (result != VK_SUCCESS)
        {
            return result;
        }
        result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        // NOTE: vkCmdCopyImage works on Queues of types including Graphics, Compute
        //       and Transfer.  So should work on any queues we get a vkQueuePresentKHR from.
        device_table_->CmdCopyImage(command_buffer,
                                    virtual_image.image,
                                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                    replay_image,
                                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                    1,
                                    &image_copy);

        result = device_table_->EndCommandBuffer(command_buffer);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.waitSemaphoreCount   = static_cast<uint32_t>(wait_semaphores.size());
        submit_info.pWaitSemaphores      = wait_semaphores.data();
        submit_info.pWaitDstStageMask    = wait_stages.data();
        submit_info.signalSemaphoreCount = static_cast<uint32_t>(signal_semaphores.size());
        submit_info.pSignalSemaphores    = signal_semaphores.data();
        submit_info.commandBufferCount   = 1;
        submit_info.pCommandBuffers      = &command_buffer;

        result = device_table_->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);

        if (result != VK_SUCCESS)
        {
            return result;
        }
    }
    VkPresentInfoKHR modified_present_info   = *present_info;
    modified_present_info.waitSemaphoreCount = static_cast<uint32_t>(present_wait_semaphores.size());
    modified_present_info.pWaitSemaphores    = present_wait_semaphores.data();
    return func(queue, &modified_present_info);
}

VkResult VulkanVirtualSwapchain::CreateRenderPass(PFN_vkCreateRenderPass        func,
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

VkResult VulkanVirtualSwapchain::CreateRenderPass2(PFN_vkCreateRenderPass2        func,
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

VkResult VulkanVirtualSwapchain::CreateVirtualSwapchainImage(const DeviceInfo*               device_info,
                                                             const VkImageCreateInfo&        image_create_info,
                                                             SwapchainKHRInfo::VirtualImage& image)
{
    // TODO: This is the same code used in VulkanReplayConsumerBase::CreateSwapchainImage, which
    // should be moved to a shared graphics utility function.

    VulkanResourceAllocator* allocator = device_info->allocator.get();
    assert(allocator != nullptr);

    VkResult result =
        allocator->CreateImageDirect(&image_create_info, nullptr, &image.image, &image.resource_allocator_data);

    if (result == VK_SUCCESS)
    {
        if ((instance_table_ == nullptr) || (device_table_ == nullptr))
        {
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }

        VkMemoryRequirements memory_reqs;
        device_table_->GetImageMemoryRequirements(device_info->handle, image.image, &memory_reqs);

        VkMemoryPropertyFlags property_flags    = VK_QUEUE_FLAG_BITS_MAX_ENUM;
        uint32_t              memory_type_index = std::numeric_limits<uint32_t>::max();
        {
            VkPhysicalDeviceMemoryProperties properties;
            instance_table_->GetPhysicalDeviceMemoryProperties(device_info->parent, &properties);

            for (uint32_t i = 0; i < properties.memoryTypeCount; i++)
            {
                if ((memory_reqs.memoryTypeBits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & property_flags) != 0))
                {
                    memory_type_index = i;
                    break;
                }
            }
            assert(memory_type_index != std::numeric_limits<uint32_t>::max());
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        result = allocator->AllocateMemoryDirect(&alloc_info, nullptr, &image.memory, &image.memory_allocator_data);

        if (result == VK_SUCCESS)
        {
            VkMemoryPropertyFlags flags;
            result = allocator->BindImageMemoryDirect(
                image.image, image.memory, 0, image.resource_allocator_data, image.memory_allocator_data, &flags);
        }

        if (result != VK_SUCCESS)
        {
            if (image.memory != VK_NULL_HANDLE)
            {
                allocator->FreeMemoryDirect(image.memory, nullptr, image.memory_allocator_data);
                image.memory = VK_NULL_HANDLE;
            }

            allocator->DestroyImageDirect(image.image, nullptr, image.resource_allocator_data);
            image.image = VK_NULL_HANDLE;
        }
    }
    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
