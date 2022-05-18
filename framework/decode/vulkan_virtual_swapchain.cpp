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

#include "decode/vulkan_virtual_swapchain.h"

#include "decode/vulkan_resource_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanVirtualSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
                                                    const DeviceInfo*               device_info,
                                                    const VkSwapchainCreateInfoKHR* create_info,
                                                    const VkAllocationCallbacks*    allocator,
                                                    VkSwapchainKHR*                 swapchain,
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
    return func(device, create_info, allocator, swapchain);
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
    }

    // TODO: Adjust the swapchain image format if the specified format is not supported by the replay device.

    auto result = func(device, swapchain, replay_image_count, images);

    if ((result == VK_SUCCESS) && (image_count != nullptr))
    {
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
                swapchain_info->swapchain_images = std::vector<VkImage>(images, std::next(images, *replay_image_count));
            }

            // If the call was made more than once because the first call returned VK_INCOMPLETE, only the new images
            // returned by the second call will have virtual images created and appended to the end of the virtual image
            // array.
            if (capture_image_count != swapchain_info->virtual_images.size())
            {
                uint32_t start_index = static_cast<uint32_t>(swapchain_info->virtual_images.size());

                // Set the acquired map count to the capture count, to map the captured index that replay is processing
                // to the real swapchain image to be presented.
                swapchain_info->acquired_index_map.resize(capture_image_count);

                // TODO: This is the same code used in VulkanReplayConsumerBase::OverrideGetSwapchainImagesKHR, which
                // should be moved to a shared graphics utility function.

                //  Create an image for the virtual swapchain.  Based on vkspec.html#swapchain-wsi-image-create-info.
                VkImageCreateInfo image_create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
                image_create_info.pNext                 = nullptr;
                image_create_info.flags                 = 0;
                image_create_info.imageType             = VK_IMAGE_TYPE_2D;
                image_create_info.format                = swapchain_info->format;
                image_create_info.extent                = { swapchain_info->width, swapchain_info->height, 1 };
                image_create_info.mipLevels             = 1;
                image_create_info.arrayLayers           = swapchain_info->image_array_layers;
                image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
                image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
                image_create_info.usage                 = swapchain_info->image_usage;
                image_create_info.sharingMode           = swapchain_info->image_sharing_mode;
                image_create_info.queueFamilyIndexCount = 0;
                image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
                if (swapchain_info->queue_family_index != 0)
                {
                    image_create_info.queueFamilyIndexCount = 1;
                    image_create_info.pQueueFamilyIndices   = &swapchain_info->queue_family_index;
                }

                if ((swapchain_info->image_flags & VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR) ==
                    VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR)
                {
                    image_create_info.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
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
    VkDevice       device    = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    VkSemaphore    semaphore = VK_NULL_HANDLE;
    VkFence        fence     = VK_NULL_HANDLE;

    if (device_info != nullptr)
    {
        device = device_info->handle;
    }

    if (swapchain_info != nullptr)
    {
        swapchain = swapchain_info->handle;
    }

    if (semaphore_info != nullptr)
    {
        semaphore = semaphore_info->handle;
    }

    if (fence_info != nullptr)
    {
        fence = fence_info->handle;
    }

    auto result = func(device, swapchain, timeout, semaphore, fence, image_index);

    if ((swapchain_info != nullptr) && (image_index != nullptr))
    {
        swapchain_info->acquired_index_map[capture_image_index] = *image_index;
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

    auto result = func(device, acquire_info, image_index);

    if ((swapchain_info != nullptr) && (image_index != nullptr))
    {
        swapchain_info->acquired_index_map[capture_image_index] = *image_index;
    }

    return result;
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR   func,
                                                 const QueueInfo*        queue_info,
                                                 const VkPresentInfoKHR* present_info)
{
    VkQueue queue = VK_NULL_HANDLE;

    if (queue_info != nullptr)
    {
        queue = queue_info->handle;
    }

    // TODO: Transfer the image to the real swapchain image. This will require a dispatch table for recording and
    // executing a command buffer to perform a blit.  This will also require access to the SwapchainKHRInfo structures
    // associated with each of the swapchain handles in 'present_info', which may need to be added as a new parameter to
    // the QueuePresentKHR method.  The following will need to be performed.  The code could potentially be similar to
    // or shared with the code used to copy the swapchain image to a buffer for screenshot creation.
    //   1. Obtain the device dispatch table.  This could be added as a new parameter to the QueuePresentKHR method, or
    //   stored in an info structure.
    //   2. Select a queue to perform the transfer.
    //   3. Create a command pool and command buffer.
    //   4. Record command to transition the real swapchain image to the TRANSFER_DST layout (real image determined as
    //   swapchain_info->swapchain_images[swapchain_info->acquired_index_map[present_info->pImageIndicies[i]]]).
    //   5. Record command to copy the virtual image to the real image with vkCmdBlitImage (virtual image determined as
    //   swapchain_info->virtual_images[present_info->pImageIndicies[i]]).  The virtual image will have been
    //   transitioned to/from the TRANSFER_SRC layout by the createrenderpass/pipelinebarrier overrides that replace the
    //   PRESENT_SRC layout with the TRANSFER_SRC layout, so no transition is necessary.
    //   6. Record command to transition the real image to the PRESENT_SRC layout.
    //   7. Submit the command buffer, moving the pWaitSemaphore values from present_info to the queue submit info
    //   struct.  The queue submit info struct should also reference a semaphore to signal, which was created by this
    //   class for use with the blit.
    //   8.  Call vkQueuePresentKHR, replacing the pWaitSeamphore values from present_info, which were waited on by the
    //   queue submission, to the reference the new semaphore that the queue submission signaled.

    // Note that this blit could also be used to scale the image, which would allow replay to support an option for
    // changing the window/swapchain size when the virtual swapchain mode is active.  The virtual image would continue
    // to use the captured swapchain image size, and be scaled to the replay swapchain image size with vkCmdBlitImage.

    return func(queue, present_info);
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

    // Change create_info->pAttachments[*]->finalLayout from PRESENT_SRC to TRANSFER_SRC to prepare the VkImage
    // objects returned by vkGetSwapchainImagesKHR to be copied to the real swapchain images.  We use
    // FindFirstPresentSrcLayout to determine if the render pass uses the PRESENT_SRC layout, and if so we make a copy
    // of the create info to modify.
    int32_t first = FindFirstPresentSrcLayout(create_info);

    if (first >= 0)
    {
        std::vector<VkAttachmentDescription> descriptions(
            create_info->pAttachments, std::next(create_info->pAttachments, create_info->attachmentCount));

        for (uint32_t i = first; i < create_info->attachmentCount; ++i)
        {
            // TODO: This should also change the initialLayout values.
            if (descriptions[i].finalLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                descriptions[i].finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            }
        }

        VkRenderPassCreateInfo modified_create_info = (*create_info);
        modified_create_info.pAttachments           = descriptions.data();

        return func(device, &modified_create_info, allocator, render_pass);
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

    // Change create_info->pAttachments[*]->finalLayout from PRESENT_SRC to TRANSFER_SRC to prepare the VkImage
    // objects returned by vkGetSwapchainImagesKHR to be copied to the real swapchain images.  We use
    // FindFirstPresentSrcLayout to determine if the render pass uses the PRESENT_SRC layout, and if so we make a copy
    // of the create info to modify.
    int32_t first = FindFirstPresentSrcLayout(create_info);

    if (first >= 0)
    {
        std::vector<VkAttachmentDescription2> descriptions(
            create_info->pAttachments, std::next(create_info->pAttachments, create_info->attachmentCount));

        for (uint32_t i = first; i < create_info->attachmentCount; ++i)
        {
            // TODO: This should also change the initialLayout values.
            if (descriptions[i].finalLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                descriptions[i].finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            }
        }

        VkRenderPassCreateInfo2 modified_create_info = (*create_info);
        modified_create_info.pAttachments            = descriptions.data();

        return func(device, &modified_create_info, allocator, render_pass);
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

    // Change image_memory_barriers[*]->oldLayout and image_memory_barriers[*]->newLayout values from PRESENT_SRC
    // to TRANSFER_SRC to prepare the VkImage objects returned by vkGetSwapchainImagesKHR to be copied to the real
    // swapchain images.  We use FindFirstPresentSrcLayout to determine if the pipeline barrier uses the PRESENT_SRC
    // layout, and if so we make a copy of the create info to modify.
    int32_t first = FindFirstPresentSrcLayout(image_memory_barrier_count, image_memory_barriers);

    if (first < 0)
    {
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
    else
    {
        std::vector<VkImageMemoryBarrier> barriers(image_memory_barriers,
                                                   std::next(image_memory_barriers, image_memory_barrier_count));

        for (uint32_t i = first; i < image_memory_barrier_count; ++i)
        {
            // TODO: This should also change the oldLayout values.
            if (barriers[i].newLayout == VK_IMAGE_LAYOUT_PRESENT_SRC_KHR)
            {
                barriers[i].dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                barriers[i].newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            }
        }

        func(command_buffer,
             src_stage_mask,
             VK_PIPELINE_STAGE_TRANSFER_BIT,
             dependency_flags,
             memory_barrier_count,
             memory_barriers,
             buffer_memory_barrier_count,
             buffer_memory_barriers,
             image_memory_barrier_count,
             barriers.data());
    }
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
        // TODO: This requires instance and device tables, which could either be added to the GetSwapchainImagesKHR and
        // CreateSwapchainImage methods as parameters or added to an info struct.
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
