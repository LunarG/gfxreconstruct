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

#include "decode/vulkan_virtual_swapchain.h"

#include "decode/vulkan_resource_allocator.h"
#include "decode/decoder_util.h"

#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool VulkanVirtualSwapchain::AddSwapchainResourceData(VkSwapchainKHR swapchain)
{
    auto data = std::make_unique<SwapchainResourceData>();
    if (data == nullptr)
    {
        GFXRECON_LOG_ERROR("Virtual swapchain failed creating swapchain resource data during vkCreateSwapchainKHR");
        return false;
    }
    swapchain_resources_.emplace(swapchain, std::move(data));
    return true;
}

VkResult VulkanVirtualSwapchain::CreateSwapchainKHR(VkResult                              original_result,
                                                    PFN_vkCreateSwapchainKHR              func,
                                                    const VulkanDeviceInfo*               device_info,
                                                    const VkSwapchainCreateInfoKHR*       create_info,
                                                    const VkAllocationCallbacks*          allocator,
                                                    HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                                    const encode::VulkanDeviceTable*      device_table)
{
    VkDevice                 device = VK_NULL_HANDLE;
    VkSurfaceCapabilitiesKHR surfCapabilities{};

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }
    device_table_                    = device_table;
    VkPhysicalDevice physical_device = device_info->parent;

    VkSwapchainCreateInfoKHR modified_create_info = *create_info;
    modified_create_info.imageUsage =
        modified_create_info.imageUsage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

    VkResult result = instance_table_->GetPhysicalDeviceSurfaceCapabilitiesKHR(
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
    auto replay_swapchain = swapchain->GetHandlePointer();

    result = func(device, &modified_create_info, allocator, replay_swapchain);
    if (result == VK_SUCCESS && *replay_swapchain != VK_NULL_HANDLE)
    {
        if (!AddSwapchainResourceData(*replay_swapchain))
        {
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }
    }
    return result;
}

void VulkanVirtualSwapchain::CleanSwapchainResourceData(const VulkanDeviceInfo*       device_info,
                                                        const VulkanSwapchainKHRInfo* swapchain_info)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        device    = device_info->handle;
        swapchain = swapchain_info->handle;

        auto allocator = device_info->allocator.get();
        assert(allocator != nullptr);

        for (const VulkanImageInfo& image_info : swapchain_info->image_infos)
        {
            allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
            allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
        }

        // Delete the virtual swapchain-specific swapchain resource data
        if (swapchain_resources_.find(swapchain) != swapchain_resources_.end())
        {
            auto& swapchain_resources = swapchain_resources_[swapchain];
            for (const VirtualImage& image_info : swapchain_resources->virtual_swapchain_images)
            {
                allocator->DestroyImageDirect(image_info.image, nullptr, image_info.resource_allocator_data);
                allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
            }

            for (auto& copy_cmd_data : swapchain_resources->copy_cmd_data)
            {
                if (copy_cmd_data.second.command_pool != VK_NULL_HANDLE)
                {
                    device_table_->FreeCommandBuffers(
                        device,
                        copy_cmd_data.second.command_pool,
                        static_cast<uint32_t>(copy_cmd_data.second.command_buffers.size()),
                        copy_cmd_data.second.command_buffers.data());
                    device_table_->DestroyCommandPool(device, copy_cmd_data.second.command_pool, nullptr);
                }
                for (auto& semaphore : copy_cmd_data.second.semaphores)
                {
                    device_table_->DestroySemaphore(device, semaphore, nullptr);
                }
            }

            swapchain_resources_.erase(swapchain);
        }
    }
}

void VulkanVirtualSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR     func,
                                                 const VulkanDeviceInfo*       device_info,
                                                 const VulkanSwapchainKHRInfo* swapchain_info,
                                                 const VkAllocationCallbacks*  allocator)
{
    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        CleanSwapchainResourceData(device_info, swapchain_info);

        VkDevice       device    = device_info->handle;
        VkSwapchainKHR swapchain = swapchain_info->handle;
        func(device, swapchain, allocator);
    }
}

// Offscreen only need virtual_swapchain_images. Skip ther other tasks for offscreen.
VkResult VulkanVirtualSwapchain::CreateSwapchainResourceData(const VulkanDeviceInfo*       device_info,
                                                             const VulkanSwapchainKHRInfo* swapchain_info,
                                                             uint32_t                      capture_image_count,
                                                             uint32_t*                     replay_image_count,
                                                             VkImage*                      images,
                                                             bool                          offscreen)
{
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    VkResult       result    = VK_SUCCESS;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }
    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    bool     found_copy_queue_family           = false;
    uint32_t copy_queue_family_index           = VK_QUEUE_FAMILY_IGNORED;
    bool     found_transfer_queue_family_index = false;
    uint32_t transfer_queue_family_index       = 0;

    // Determine what queue to use for the initial virtual image setup
    VkQueue                              initial_copy_queue = VK_NULL_HANDLE;
    uint32_t                             property_count     = 0;
    std::vector<VkQueueFamilyProperties> props;

    instance_table_->GetPhysicalDeviceQueueFamilyProperties(device_info->parent, &property_count, nullptr);
    props.resize(property_count);
    instance_table_->GetPhysicalDeviceQueueFamilyProperties(device_info->parent, &property_count, props.data());

    for (uint32_t queue_family_index = 0; queue_family_index < property_count; ++queue_family_index)
    {
        // If we're past the point of enabled queues, then stop looking because we really can't enable
        // a queue that isn't flagged during device creation.
        if (queue_family_index >= static_cast<uint32_t>(device_info->queue_family_index_enabled.size()))
        {
            break;
        }

        if (!device_info->queue_family_index_enabled[queue_family_index])
        {
            continue;
        }

        // If we find a graphics queue, we're good, so grab it and bail
        if (props[queue_family_index].queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            copy_queue_family_index = queue_family_index;
            found_copy_queue_family = true;
            break;
        }

        // Find a transfer queue as an alternative, just in case
        if (!found_transfer_queue_family_index && props[queue_family_index].queueFlags & VK_QUEUE_TRANSFER_BIT)
        {
            transfer_queue_family_index       = queue_family_index;
            found_transfer_queue_family_index = true;
        }
    }
    if (!found_copy_queue_family)
    {
        if (!found_transfer_queue_family_index)
        {
            GFXRECON_LOG_ERROR("Virtual swapchain failed finding a queue to create initial virtual swapchain "
                               "images for swapchain (ID = %" PRIu64 ")",
                               swapchain_info->capture_id);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }
        copy_queue_family_index = transfer_queue_family_index;
        GFXRECON_LOG_INFO("Virtual swapchain using transfer queue %d to create initial virtual swapchain "
                          "images for swapchain (ID = %" PRIu64 ")",
                          transfer_queue_family_index,
                          swapchain_info->capture_id);
    }

    initial_copy_queue = GetDeviceQueue(device_table_, device_info, copy_queue_family_index, 0);
    if (initial_copy_queue == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_ERROR("Virtual swapchain failed getting device queue %d to create initial virtual swapchain "
                           "images for swapchain (ID = %" PRIu64 ")",
                           copy_queue_family_index,
                           swapchain_info->capture_id);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    auto& swapchain_resources = swapchain_resources_[swapchain];
    if (!offscreen)
    {
        for (uint32_t queue_family_index = 0; queue_family_index < property_count; ++queue_family_index)
        {
            if (swapchain_resources->copy_cmd_data.find(queue_family_index) == swapchain_resources->copy_cmd_data.end())
            {
                // We only want to look at a given queue if it was enabled during device creation time
                // and if it supports present.  Otherwise, we don't need to create a command pool,
                // command buffers, and semaphores for performing the swapchain copy.
                if (device_info->queue_family_index_enabled.size() <= queue_family_index ||
                    !device_info->queue_family_index_enabled[queue_family_index])
                {
                    GFXRECON_LOG_DEBUG("Virtual swapchain skipping creating blit info for queue family %d because it "
                                       "was not enabled by the device",
                                       queue_family_index);
                    continue;
                }

                VkBool32 supported = VK_FALSE;
                result             = instance_table_->GetPhysicalDeviceSurfaceSupportKHR(
                    device_info->parent, queue_family_index, swapchain_info->surface, &supported);
                if (result != VK_SUCCESS || supported == VK_FALSE)
                {
                    GFXRECON_LOG_DEBUG(
                        "Virtual swapchain skipping queue family %d since present support is not present "
                        "for swapchain (ID = %" PRIu64 ")",
                        queue_family_index,
                        swapchain_info->capture_id);
                    continue;
                }

                // Create one command pool per queue.
                VkCommandPoolCreateInfo command_pool_create_info = {
                    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,                                             // sType
                    nullptr,                                                                                // pNext
                    VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT, // flags
                    static_cast<uint32_t>(queue_family_index) // queueFamilyIndex
                };

                CopyCmdData copy_cmd_data = {};
                result                    = device_table_->CreateCommandPool(
                    device, &command_pool_create_info, nullptr, &copy_cmd_data.command_pool);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Virtual swapchain failed creating command pool %d for swapchain (ID = %" PRIu64
                                       ")",
                                       queue_family_index,
                                       swapchain_info->capture_id);
                    return result;
                }
                swapchain_resources->copy_cmd_data.emplace(queue_family_index, std::move(copy_cmd_data));
            }

            auto& copy_cmd_data = swapchain_resources->copy_cmd_data[queue_family_index];

            // Make sure we have enough storage for each of our tracked components (Command pools,
            // Command Buffers, Semaphores, etc) as many queue families that are available.
            // This is because at any point, the application may get a Device queue from that family and
            // use it during the present.
            uint32_t start_size = static_cast<uint32_t>(copy_cmd_data.command_buffers.size());
            uint32_t new_count  = property_count;
            if (start_size < new_count)
            {
                // Create one command buffer per queue per swapchain image so that we don't reset a command buffer that
                // may be in active use.
                uint32_t command_buffer_count = static_cast<uint32_t>(copy_cmd_data.command_buffers.size());
                if (command_buffer_count < capture_image_count)
                {
                    copy_cmd_data.command_buffers.resize(capture_image_count);

                    uint32_t                    new_count     = capture_image_count - command_buffer_count;
                    VkCommandBufferAllocateInfo allocate_info = {
                        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, // sType
                        nullptr,                                        // pNext
                        copy_cmd_data.command_pool,                     // commandPool
                        VK_COMMAND_BUFFER_LEVEL_PRIMARY,                // level
                        new_count                                       // commandBufferCount
                    };

                    result = device_table_->AllocateCommandBuffers(
                        device, &allocate_info, &copy_cmd_data.command_buffers[command_buffer_count]);
                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Virtual swapchain failed allocating internal command buffer %d for "
                                           "swapchain (ID = %" PRIu64 ")",
                                           queue_family_index,
                                           swapchain_info->capture_id);
                        return result;
                    }
                }
                uint32_t semaphore_count = static_cast<uint32_t>(copy_cmd_data.semaphores.size());
                if (semaphore_count < capture_image_count)
                {
                    copy_cmd_data.semaphores.resize(capture_image_count);

                    for (uint32_t ii = semaphore_count; ii < capture_image_count; ++ii)
                    {
                        VkSemaphoreCreateInfo semaphore_create_info = {
                            VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO, // sType
                            nullptr,                                 // pNext
                            0                                        // flags
                        };

                        VkSemaphore semaphore = 0;
                        result = device_table_->CreateSemaphore(device, &semaphore_create_info, nullptr, &semaphore);
                        if (result != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Virtual swapchain failed creating internal copy semaphore for "
                                               "swapchain (ID = %" PRIu64 ")",
                                               swapchain_info->capture_id);
                            return result;
                        }
                        copy_cmd_data.semaphores[ii] = semaphore;
                    }
                }
            }
        }
    }

    uint32_t virtual_swapchain_count = static_cast<uint32_t>(swapchain_resources->virtual_swapchain_images.size());

    // If the call was made more than once because the first call returned VK_INCOMPLETE, only the new images
    // returned by the second call will have virtual images created and appended to the end of the virtual image
    // array.
    if (virtual_swapchain_count < capture_image_count)
    {
        // TODO: This is the same code used in VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR, which
        // should be moved to a shared graphics utility function.

        //  Create an image for the virtual swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
        VkImageCreateInfo image_create_info = {
            VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,                                // sType,
            nullptr,                                                            // pNext
            0,                                                                  // flags
            VK_IMAGE_TYPE_2D,                                                   // imageType
            swapchain_info->format,                                             // format
            VkExtent3D{ swapchain_info->width, swapchain_info->height, 1 },     // extent
            1,                                                                  // mipLevels
            swapchain_info->image_array_layers,                                 // arrayLayers
            VK_SAMPLE_COUNT_1_BIT,                                              // samples
            VK_IMAGE_TILING_OPTIMAL,                                            // tiling
            swapchain_info->image_usage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,      // usage
            swapchain_info->image_sharing_mode,                                 // sharingMode
            static_cast<uint32_t>(swapchain_info->queue_family_indices.size()), // queueFamilyIndexCount
            swapchain_info->queue_family_indices.data(),                        // pQueueFamilyIndices
            VK_IMAGE_LAYOUT_UNDEFINED                                           // initialLayout
        };

        // If compression control structure was present, pass it along to the image
        // create info.
        if (swapchain_info->compression_control)
        {
            image_create_info.pNext = swapchain_info->compression_control.get();
        }

        if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
            VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
        {
            image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        }

        for (uint32_t i = virtual_swapchain_count; i < capture_image_count; ++i)
        {
            VirtualImage image;

            result = CreateVirtualSwapchainImage(device_info, image_create_info, image);

            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Failed to create virtual swapchain image for swapchain (ID = %" PRIu64 ")",
                                   swapchain_info->capture_id);
                break;
            }
            swapchain_resources->virtual_swapchain_images.emplace_back(std::move(image));
        }

        if (!offscreen)
        {
            VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
            begin_info.pNext                    = nullptr;
            begin_info.flags                    = 0;
            begin_info.pInheritanceInfo         = nullptr;

            auto command_buffer = swapchain_resources->copy_cmd_data[copy_queue_family_index].command_buffers[0];

            result = device_table_->ResetCommandBuffer(command_buffer, 0);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "Virtual swapchain failed resetting internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                    copy_queue_family_index,
                    swapchain_info->capture_id);
                return result;
            }

            result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "Virtual swapchain failed starting internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                    copy_queue_family_index,
                    swapchain_info->capture_id);
                return result;
            }

            VkImageMemoryBarrier barrier = {
                VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, // sType
                nullptr,                                // pNext
                VK_ACCESS_NONE,                         // srcAccessMask
                VK_ACCESS_NONE,                         // dstAccessMask
                VK_IMAGE_LAYOUT_UNDEFINED,              // oldLayout
                VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,        // newLayout
                VK_QUEUE_FAMILY_IGNORED,                // srcQueueFamilyIndex
                VK_QUEUE_FAMILY_IGNORED,                // dstQueueFamilyIndex
                VK_NULL_HANDLE,                         // image
                VkImageSubresourceRange{
                    VK_IMAGE_ASPECT_COLOR_BIT,
                    0,
                    image_create_info.mipLevels,
                    0,
                    image_create_info.arrayLayers,
                }, // subResourceRange
            };

            for (uint32_t i = 0; i < *replay_image_count; ++i)
            {
                barrier.image = swapchain_resources->replay_swapchain_images[i];
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
                    copy_queue_family_index,
                    swapchain_info->capture_id);
                return result;
            }

            VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            submit_info.commandBufferCount = 1;
            submit_info.pCommandBuffers    = &command_buffer;

            result = device_table_->QueueSubmit(initial_copy_queue, 1, &submit_info, VK_NULL_HANDLE);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "Virtual swapchain failed submitting internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                    copy_queue_family_index,
                    swapchain_info->capture_id);
                return result;
            }
            result = device_table_->QueueWaitIdle(initial_copy_queue);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "Virtual swapchain failed waiting for internal command buffer %d for swapchain (ID = %" PRIu64 ")",
                    copy_queue_family_index,
                    swapchain_info->capture_id);
                return result;
            }
        }
    }

    for (uint32_t i = 0; i < capture_image_count; ++i)
    {
        images[i] = swapchain_resources->virtual_swapchain_images[i].image;
    }
    return result;
}

VkResult VulkanVirtualSwapchain::GetSwapchainImagesKHR(VkResult                    original_result,
                                                       PFN_vkGetSwapchainImagesKHR func,
                                                       const VulkanDeviceInfo*     device_info,
                                                       VulkanSwapchainKHRInfo*     swapchain_info,
                                                       uint32_t                    capture_image_count,
                                                       uint32_t*                   image_count,
                                                       VkImage*                    images)
{
    VkDevice       device             = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain          = VK_NULL_HANDLE;
    uint32_t*      replay_image_count = nullptr;
    VkResult       result;
    VkImage*       replay_images = images;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain          = swapchain_info->handle;
        replay_image_count = &swapchain_info->replay_image_count;
    }

    // Get the swapchain resource data so we have access to the virtual swapchain-specific information.
    if (swapchain == VK_NULL_HANDLE || swapchain_resources_.find(swapchain) == swapchain_resources_.end())
    {
        GFXRECON_LOG_ERROR(
            "Virtual swapchain vkGetSwapchainImagesKHR missing swapchain resource data for swapchain (ID = %" PRIu64
            ")",
            swapchain_info->capture_id);
    }
    else if (images != nullptr)
    {
        auto& swapchain_resources = swapchain_resources_[swapchain];
        swapchain_resources->replay_swapchain_images.resize(*replay_image_count);

        // Use the resized replay images vector to contain the replay device swapchain images.
        replay_images = swapchain_resources->replay_swapchain_images.data();
    }

    // TODO: Adjust the swapchain image format if the specified format is not supported by the replay device.

    result = func(device, swapchain, replay_image_count, replay_images);

    if ((result == VK_SUCCESS) && (image_count != nullptr))
    {
        // Return the capture count.  The virtual swapchain will create a number of virtual images equal to the capture
        // count.  The virtual images will be returned to the caller in place of the real swapchain images.
        (*image_count) = capture_image_count;

        if (images == nullptr || device_info == nullptr || swapchain_info == nullptr)
        {
            return result;
        }

        return CreateSwapchainResourceData(
            device_info, swapchain_info, capture_image_count, replay_image_count, images, false);
    }

    return result;
}

VkResult VulkanVirtualSwapchain::AcquireNextImageKHR(VkResult                  original_result,
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
    if ((result != VK_SUCCESS) && (result != VK_SUBOPTIMAL_KHR))
    {
        // TODO: Add some handling of optimization with VK_SUBOPTIMAL_KHR.
        GFXRECON_LOG_ERROR("Virtual swapchain failed AcquireNextImageKHR 0x%08x for swapchain (ID = %" PRIu64 ")",
                           result,
                           swapchain_info->capture_id);
    }
    return result;
}

VkResult VulkanVirtualSwapchain::AcquireNextImage2KHR(VkResult                         original_result,
                                                      PFN_vkAcquireNextImage2KHR       func,
                                                      const VulkanDeviceInfo*          device_info,
                                                      VulkanSwapchainKHRInfo*          swapchain_info,
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
    if ((result != VK_SUCCESS) && (result != VK_SUBOPTIMAL_KHR))
    {
        // TODO: Add some handling of optimization with VK_SUBOPTIMAL_KHR.
        GFXRECON_LOG_ERROR("Virtual swapchain failed AcquireNextImage2KHR 0x%08x for swapchain (ID = %" PRIu64 ")",
                           result,
                           swapchain_info->capture_id);
    }
    return result;
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(VkResult                                    original_result,
                                                 PFN_vkQueuePresentKHR                       func,
                                                 const std::vector<uint32_t>&                capture_image_indices,
                                                 const std::vector<VulkanSwapchainKHRInfo*>& swapchain_infos,
                                                 const VulkanQueueInfo*                      queue_info,
                                                 const VkPresentInfoKHR*                     present_info)
{
    VkResult result = VK_ERROR_UNKNOWN;
    if (queue_info == nullptr)
    {
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }
    else if (swapchain_options_.skip_additional_present_blts)
    {
        // If we're to skip the BLT, just go ahead and perform the present even thought it won't
        // produce the valid image to the screen.  The intent for this path is mostly for performance
        // evaluation.
        return func(queue_info->handle, present_info);
    }

    VkQueue  queue              = queue_info->handle;
    uint32_t queue_family_index = queue_info->family_index;

    // TODO: Note that this copy could also be used to scale the image, which would allow replay to support an option
    // for changing the window/swapchain size when the virtual swapchain mode is active.  The virtual image would
    // continue to use the captured swapchain image size, and be scaled to the replay swapchain image size with
    // vkCmdBlitImage.

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };

    VkImageMemoryBarrier initial_barrier_virtual_image;
    VkImageMemoryBarrier initial_barrier_swapchain_image;
    VkImageMemoryBarrier final_barrier_virtual_image;
    VkImageMemoryBarrier final_barrier_swapchain_image;

    initial_barrier_virtual_image = {
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

    final_barrier_virtual_image               = initial_barrier_virtual_image;
    final_barrier_virtual_image.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    final_barrier_virtual_image.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
    final_barrier_virtual_image.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    final_barrier_virtual_image.newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    initial_barrier_swapchain_image               = initial_barrier_virtual_image;
    initial_barrier_swapchain_image.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    initial_barrier_swapchain_image.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

    final_barrier_swapchain_image           = final_barrier_virtual_image;
    final_barrier_swapchain_image.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

    VkImageSubresourceLayers subresource    = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 0 };
    VkOffset3D               offset         = { 0, 0, 0 };
    auto                     swapchainCount = present_info->swapchainCount;
    std::vector<VkSemaphore> present_wait_semaphores;

    // TODO: There is a potential issue here where a vkQueuePresent comes in on a queue (let's call
    // it QueueX) which does not support vkCmdCopyImage (i.e. a video-only queue).  In that case,
    // we would need to insert an emtpy command buffer into the command stream of QueueX which
    // triggers a semaphore (let's say SemA), then we would need to submit the vkCmdCopyImage in a
    // command buffer on a queue that supports it (let's say QueueY) which will wait on SemA to
    // start and signaling another semaphore (SemB) when it is done.  Then, we need to add the
    // QueuePresent to QueueX, but waiting on SemB before it executes.  And that is assuming that
    // the buffer image is even accessible on both Queues!

    for (uint32_t i = 0; i < swapchainCount; ++i)
    {
        const auto* swapchain_info      = swapchain_infos[i];
        uint32_t    capture_image_index = capture_image_indices[i];
        uint32_t    replay_image_index  = present_info->pImageIndices[i];

        // Get the per swapchain resource data so we have access to the virtual swapchain-specific information.
        if (swapchain_resources_.find(swapchain_info->handle) == swapchain_resources_.end())
        {
            GFXRECON_LOG_ERROR(
                "Virtual swapchain vkQueuePresentKHR missing swapchain resource data for swapchain (ID = %" PRIu64 ")",
                swapchain_info->capture_id);
            continue;
        }

        auto& swapchain_resources = swapchain_resources_[swapchain_info->handle];
        assert(swapchain_resources != nullptr);

        // Find the appropriate CommandCopyData struct for this queue family
        if (swapchain_resources->copy_cmd_data.find(queue_family_index) == swapchain_resources->copy_cmd_data.end())
        {
            GFXRECON_LOG_ERROR("Virtual swapchain vkQueuePresentKHR missing swapchain resource copy command data for "
                               "queue (Handle %" PRIu64 ") in swapchain (ID = %" PRIu64 ")",
                               queue,
                               swapchain_info->capture_id);
            continue;
        }

        const auto& virtual_image = swapchain_resources->virtual_swapchain_images[capture_image_index];
        const auto& replay_image  = swapchain_resources->replay_swapchain_images[replay_image_index];

        // Use a command buffer and semaphore from the same queue index
        auto& copy_cmd_data  = swapchain_resources->copy_cmd_data[queue_family_index];
        auto  command_buffer = copy_cmd_data.command_buffers[capture_image_index];
        auto  copy_semaphore = copy_cmd_data.semaphores[capture_image_index];

        std::vector<VkSemaphore> wait_semaphores;
        std::vector<VkSemaphore> signal_semaphores;

        // Only wait for the present semaphore dependencies on the first copy command buffer.
        // The others will automatically inherit that dependency because of their order in the
        // command buffer.
        if (i == 0 && present_info->waitSemaphoreCount > 0)
        {
            wait_semaphores.assign(present_info->pWaitSemaphores,
                                   present_info->pWaitSemaphores + present_info->waitSemaphoreCount);
        }

        // Only trigger a semaphore on the last copy
        if (i == swapchainCount - 1)
        {
            signal_semaphores.push_back(copy_semaphore);
            present_wait_semaphores.emplace_back(copy_semaphore);
        }

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

        initial_barrier_virtual_image.image                         = virtual_image.image;
        initial_barrier_virtual_image.subresourceRange.layerCount   = swapchain_info->image_array_layers;
        initial_barrier_swapchain_image.image                       = replay_image;
        initial_barrier_swapchain_image.subresourceRange.layerCount = swapchain_info->image_array_layers;

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &initial_barrier_virtual_image);

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &initial_barrier_swapchain_image);

        subresource.layerCount   = swapchain_info->image_array_layers;
        VkExtent3D  image_extent = { swapchain_info->width, swapchain_info->height, 1 };
        VkImageCopy image_copy   = { subresource, offset, subresource, offset, image_extent };

        // NOTE: vkCmdCopyImage works on Queues of types including Graphics, Compute
        //       and Transfer.  So should work on any queues we get a vkQueuePresentKHR from.
        device_table_->CmdCopyImage(command_buffer,
                                    virtual_image.image,
                                    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                    replay_image,
                                    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                    1,
                                    &image_copy);

        final_barrier_virtual_image.image                         = virtual_image.image;
        final_barrier_virtual_image.subresourceRange.layerCount   = swapchain_info->image_array_layers;
        final_barrier_swapchain_image.image                       = replay_image;
        final_barrier_swapchain_image.subresourceRange.layerCount = swapchain_info->image_array_layers;

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &final_barrier_virtual_image);

        device_table_->CmdPipelineBarrier(command_buffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &final_barrier_swapchain_image);

        result = device_table_->EndCommandBuffer(command_buffer);
        if (result != VK_SUCCESS)
        {
            return result;
        }

        VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_TRANSFER_BIT;

        VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.waitSemaphoreCount = static_cast<uint32_t>(wait_semaphores.size());
        if (present_info->waitSemaphoreCount > 0)
        {
            submit_info.pWaitSemaphores = wait_semaphores.data();
        }
        else
        {
            submit_info.pWaitSemaphores = nullptr;
        }
        submit_info.pWaitDstStageMask    = &wait_stage;
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

VkResult VulkanVirtualSwapchain::CreateRenderPass(VkResult                      original_result,
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

VkResult VulkanVirtualSwapchain::CreateRenderPass2(VkResult                       original_result,
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

void VulkanVirtualSwapchain::CmdPipelineBarrier(PFN_vkCmdPipelineBarrier       func,
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

void VulkanVirtualSwapchain::CmdPipelineBarrier2(PFN_vkCmdPipelineBarrier2 func,
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

VkResult VulkanVirtualSwapchain::CreateVirtualSwapchainImage(const VulkanDeviceInfo*  device_info,
                                                             const VkImageCreateInfo& image_create_info,
                                                             VirtualImage&            image)
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
