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

        device_table_->FreeCommandBuffers(device,
                                          swapchain_info->blit_command_pool,
                                          static_cast<uint32_t>(swapchain_info->blit_command_buffers.size()),
                                          swapchain_info->blit_command_buffers.data());
        device_table_->DestroyCommandPool(device, swapchain_info->blit_command_pool, nullptr);

        for (const SwapchainKHRInfo::VirtualImage& image_info : swapchain_info->virtual_images)
        {
            allocator->DestroyImageDirect(image_info.image, nullptr, image_info.resource_allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }
        for (const auto semaphore : swapchain_info->blit_semaphores)
        {
            device_table_->DestroySemaphore(device, semaphore, nullptr);
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
    VkDevice             device             = VK_NULL_HANDLE;
    VkSwapchainKHR       swapchain          = VK_NULL_HANDLE;
    uint32_t*            replay_image_count = nullptr;
    std::vector<VkImage> replay_swapchain_images;

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
            replay_swapchain_images.resize(*replay_image_count);
        }
    }

    // TODO: Adjust the swapchain image format if the specified format is not supported by the replay device.

    auto result = func(device, swapchain, replay_image_count, replay_swapchain_images.data());

    if ((result == VK_SUCCESS) && (image_count != nullptr))
    {
        if (swapchain_info->blit_command_pool == VK_NULL_HANDLE)
        {
            device_table_->GetDeviceQueue(
                device, swapchain_info->queue_family_indices[0], 0, &swapchain_info->blit_queue);

            VkCommandPoolCreateInfo command_pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
            command_pool_create_info.flags =
                VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
            command_pool_create_info.queueFamilyIndex = swapchain_info->queue_family_indices[0];
            VkResult result                           = device_table_->CreateCommandPool(
                device, &command_pool_create_info, nullptr, &swapchain_info->blit_command_pool);
            if (result != VK_SUCCESS)
            {
                return result;
            }

            for (uint32_t i = 0; i < capture_image_count; ++i)
            {
                VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
                allocate_info.pNext                       = nullptr;
                allocate_info.commandPool                 = swapchain_info->blit_command_pool;
                allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                allocate_info.commandBufferCount          = 1;
                VkCommandBuffer command_buffer            = VK_NULL_HANDLE;
                result = device_table_->AllocateCommandBuffers(device, &allocate_info, &command_buffer);
                if (result != VK_SUCCESS)
                {
                    return result;
                }
                swapchain_info->blit_command_buffers.emplace_back(command_buffer);

                VkSemaphoreCreateInfo semaphore_create_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
                semaphore_create_info.pNext                 = nullptr;
                semaphore_create_info.flags                 = 0;
                VkSemaphore semaphore                       = VK_NULL_HANDLE;
                result = device_table_->CreateSemaphore(device, &semaphore_create_info, nullptr, &semaphore);
                if (result != VK_SUCCESS)
                {
                    return result;
                }
                swapchain_info->blit_semaphores.emplace_back(semaphore);
            }
        }
        // Return the capture count.  The virtual swapchain will create a number of virtual images equal to the capture
        // count.  The virtual images will be returned to the caller in place of the real swapchain images.
        (*image_count) = capture_image_count;

        if ((device_info != nullptr) && (swapchain_info != nullptr) && (images != nullptr))
        {
            // Store the retrieved images and create new images to return to the caller.  The replay call always
            // retrieves the full swapchain image count, so this only needs to be done once.  It does not need to handle
            // the VK_INCOMPLETE case that the virtual image creation must handle.
            if (swapchain_info->swapchain_images.empty())
            {
                swapchain_info->swapchain_images = std::vector<VkImage>(
                    replay_swapchain_images.data(), std::next(replay_swapchain_images.data(), *replay_image_count));
            }

            // If the call was made more than once because the first call returned VK_INCOMPLETE, only the new images
            // returned by the second call will have virtual images created and appended to the end of the virtual image
            // array.
            if (capture_image_count != swapchain_info->virtual_images.size())
            {
                uint32_t start_index = static_cast<uint32_t>(swapchain_info->virtual_images.size());

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

                auto command_buffer = swapchain_info->blit_command_buffers[0];
                result              = device_table_->ResetCommandBuffer(command_buffer, 0);
                if (result != VK_SUCCESS)
                {
                    return result;
                }

                result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
                if (result != VK_SUCCESS)
                {
                    return result;
                }

                for (uint32_t i = start_index; i < capture_image_count; ++i)
                {
                    SwapchainKHRInfo::VirtualImage image;

                    result = CreateSwapchainImage(device_info, image_create_info, image);

                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Failed to create virtual swapchain image for swapchain (ID = %" PRIu64 ")",
                                           swapchain_info->capture_id);
                        break;
                    }
                    swapchain_info->virtual_images.emplace_back(std::move(image));
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
                    barrier.image = replay_swapchain_images[i];
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

                VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_TRANSFER_BIT;

                VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
                submit_info.commandBufferCount = 1;
                submit_info.pCommandBuffers    = &command_buffer;

                result = device_table_->QueueSubmit(swapchain_info->blit_queue, 1, &submit_info, VK_NULL_HANDLE);
                if (result != VK_SUCCESS)
                {
                    return result;
                }
                result = device_table_->QueueWaitIdle(swapchain_info->blit_queue);
                if (result != VK_SUCCESS)
                {
                    return result;
                }
            }
            for (uint32_t i = 0; i < capture_image_count; ++i)
            {
                images[i] = swapchain_info->virtual_images[i].image;
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

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    return func(device, swapchain, timeout, semaphore, fence, image_index);
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

    return func(device, acquire_info, image_index);
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                                 const std::vector<uint32_t>&          capture_image_indices,
                                                 const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                 const QueueInfo*                      queue_info,
                                                 const VkPresentInfoKHR*               present_info)
{
    VkQueue queue = VK_NULL_HANDLE;
    if (queue_info == nullptr)
    {
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }
    queue = queue_info->handle;

    // TODO: Note that this blit could also be used to scale the image, which would allow replay to support an option
    // for changing the window/swapchain size when the virtual swapchain mode is active.  The virtual image would
    // continue to use the captured swapchain image size, and be scaled to the replay swapchain image size with
    // vkCmdBlitImage.

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    // 0: virtual image, 1: swapchain image
    std::array<VkImageMemoryBarrier, 2> initial_barriers;
    std::array<VkImageMemoryBarrier, 2> final_barriers;

    initial_barriers[0] = {
        VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        nullptr,
        VK_ACCESS_NONE,
        VK_ACCESS_TRANSFER_READ_BIT,
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
        VK_QUEUE_FAMILY_IGNORED,
        VK_QUEUE_FAMILY_IGNORED,
        VK_NULL_HANDLE,
        VkImageSubresourceRange{
            VK_IMAGE_ASPECT_COLOR_BIT,
            0,
            1,
            0,
            0,
        },
    };

    final_barriers[0]               = initial_barriers[0];
    final_barriers[0].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    final_barriers[0].dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
    final_barriers[0].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    final_barriers[0].newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    initial_barriers[1]               = initial_barriers[0];
    initial_barriers[1].dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    initial_barriers[1].newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

    final_barriers[1]           = final_barriers[0];
    final_barriers[1].oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

    VkImageSubresourceLayers subresource = {
        VK_IMAGE_ASPECT_COLOR_BIT,
        0,
        0,
        0,
    };

    VkOffset3D offsets[2] = {
        {
            0,
            0,
            0,
        },
        {
            0,
            0,
            1,
        },
    };

    auto                     length = present_info->swapchainCount;
    std::vector<VkSemaphore> semaphores;

    for (uint32_t i = 0; i < length; ++i)
    {
        uint32_t    capture_image_index = capture_image_indices[i];
        uint32_t    replay_image_index  = present_info->pImageIndices[i];
        const auto* swapchain_info      = swapchain_infos[i];
        const auto& virtual_image       = swapchain_info->virtual_images[capture_image_index];
        const auto& swapchain_image     = swapchain_info->swapchain_images[replay_image_index];

        auto     command_buffer = swapchain_info->blit_command_buffers[capture_image_index];
        VkResult result         = device_table_->ResetCommandBuffer(command_buffer, 0);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        auto semaphore = swapchain_info->blit_semaphores[capture_image_index];
        semaphores.emplace_back(semaphore);

        initial_barriers[0].image                       = virtual_image.image;
        initial_barriers[0].subresourceRange.layerCount = swapchain_info->image_array_layers;
        initial_barriers[1].image                       = swapchain_image;
        initial_barriers[1].subresourceRange.layerCount = swapchain_info->image_array_layers;

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          2,
                                          initial_barriers.data());

        subresource.layerCount = swapchain_info->image_array_layers;

        offsets[1].x     = static_cast<int32_t>(swapchain_info->width);
        offsets[1].y     = static_cast<int32_t>(swapchain_info->height);
        VkImageBlit blit = {
            subresource,
            { offsets[0], offsets[1] },
            subresource,
            { offsets[0], offsets[1] },
        };

        device_table_->CmdBlitImage(command_buffer,
                                    virtual_image.image,
                                    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                    swapchain_image,
                                    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                    1,
                                    &blit,
                                    VK_FILTER_NEAREST);

        final_barriers[0].image                       = virtual_image.image;
        final_barriers[0].subresourceRange.layerCount = swapchain_info->image_array_layers;
        final_barriers[1].image                       = swapchain_image;
        final_barriers[1].subresourceRange.layerCount = swapchain_info->image_array_layers;

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          2,
                                          final_barriers.data());

        result = device_table_->EndCommandBuffer(command_buffer);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_TRANSFER_BIT;

        VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.waitSemaphoreCount   = present_info->waitSemaphoreCount;
        submit_info.pWaitSemaphores      = present_info->pWaitSemaphores;
        submit_info.pWaitDstStageMask    = &wait_stage;
        submit_info.commandBufferCount   = 1;
        submit_info.pCommandBuffers      = &command_buffer;
        submit_info.signalSemaphoreCount = 1;
        submit_info.pSignalSemaphores    = &semaphore;

        result = device_table_->QueueSubmit(swapchain_info->blit_queue, 1, &submit_info, VK_NULL_HANDLE);
        if (result != VK_SUCCESS)
        {
            return result;
        }
    }

    VkPresentInfoKHR modified_present_info   = *present_info;
    modified_present_info.waitSemaphoreCount = static_cast<uint32_t>(semaphores.size());
    modified_present_info.pWaitSemaphores    = semaphores.data();
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

void VulkanVirtualSwapchain::CmdPipelineBarrier(PFN_vkCmdPipelineBarrier     func,
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

VkResult VulkanVirtualSwapchain::CreateSwapchainImage(const DeviceInfo*               device_info,
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
            }

            allocator->DestroyImageDirect(image.image, nullptr, image.resource_allocator_data);
        }
    }
    return result;
}

int32_t VulkanVirtualSwapchain::FindFirstPresentSrcLayout(const VkRenderPassCreateInfo* create_info) const
{
    if ((create_info != nullptr) && (create_info->pAttachments != nullptr))
    {
        uint32_t count        = create_info->attachmentCount;
        auto     descriptions = create_info->pAttachments;

        for (uint32_t i = 0; i < count; ++i)
        {
            // TODO: This should also look at the initialLayout values.
            if (descriptions[i].finalLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                return i;
            }
        }
    }

    return -1;
}

int32_t VulkanVirtualSwapchain::FindFirstPresentSrcLayout(const VkRenderPassCreateInfo2* create_info) const
{
    if ((create_info != nullptr) && (create_info->pAttachments != nullptr))
    {
        uint32_t count        = create_info->attachmentCount;
        auto     descriptions = create_info->pAttachments;

        for (uint32_t i = 0; i < count; ++i)
        {
            // TODO: This should also look at the initialLayout values.
            if (descriptions[i].finalLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                return i;
            }
        }
    }

    return -1;
}

int32_t VulkanVirtualSwapchain::FindFirstPresentSrcLayout(uint32_t count, const VkImageMemoryBarrier* barriers) const
{
    if (barriers != nullptr)
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            // TODO: This should also look at the oldLayout values.
            if (barriers[i].newLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                return i;
            }
        }
    }

    return -1;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
