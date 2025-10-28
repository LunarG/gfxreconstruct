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
#include "decode/mark_injected_commands.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_struct_get_pnext.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VkResult VulkanOffscreenSwapchain::CreateSurface(VkResult                             original_result,
                                                 VulkanInstanceInfo*                  instance_info,
                                                 const std::string&                   wsi_extension,
                                                 VkFlags                              flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>*  surface,
                                                 const graphics::VulkanInstanceTable* instance_table,
                                                 application::Application*            application)
{
    GFXRECON_ASSERT(surface);

    instance_table_ = instance_table;
    application_    = application;

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for
    // the specified index.
    if ((swapchain_options_.surface_index == -1) || (swapchain_options_.surface_index == create_surface_count_))
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
                                                      const graphics::VulkanDeviceTable*    device_table)
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
    if (swapchain_options_.use_ext_frame_boundary)
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
        submitInfo.commandBufferCount   = 0;
        submitInfo.pCommandBuffers      = nullptr;
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

void VulkanOffscreenSwapchain::FrameBoundaryANDROID(PFN_vkFrameBoundaryANDROID           func,
                                                    const VulkanDeviceInfo*              device_info,
                                                    const VulkanSemaphoreInfo*           semaphore_info,
                                                    const VulkanImageInfo*               image_info,
                                                    VulkanInstanceInfo*                  instance_info,
                                                    const graphics::VulkanInstanceTable* instance_table,
                                                    const graphics::VulkanDeviceTable*   device_table,
                                                    application::Application*            application)
{
    GFXRECON_ASSERT(device_info != nullptr);

    VkSemaphore semaphore = (semaphore_info == nullptr ? VK_NULL_HANDLE : semaphore_info->handle);
    VkImage     image     = (image_info == nullptr ? VK_NULL_HANDLE : image_info->handle);

    if (swapchain_options_.use_ext_frame_boundary)
    {
        frame_boundary_.imageCount = (image == VK_NULL_HANDLE ? 0 : 1);
        frame_boundary_.pImages    = (image == VK_NULL_HANDLE ? nullptr : &image);
        ++frame_boundary_.frameID;

        VkPipelineStageFlags wait_stage_flags = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;

        VkSubmitInfo submitInfo;
        submitInfo.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.pNext                = &frame_boundary_;
        submitInfo.waitSemaphoreCount   = (semaphore == VK_NULL_HANDLE ? 0 : 1);
        submitInfo.pWaitSemaphores      = (semaphore == VK_NULL_HANDLE ? nullptr : &semaphore);
        submitInfo.pWaitDstStageMask    = (semaphore == VK_NULL_HANDLE ? nullptr : &wait_stage_flags);
        submitInfo.commandBufferCount   = 0;
        submitInfo.pCommandBuffers      = nullptr;
        submitInfo.signalSemaphoreCount = 0;
        submitInfo.pSignalSemaphores    = nullptr;

        VkQueue queue;

        decode::BeginInjectedCommands();
        device_table->GetDeviceQueue(device_info->handle, 0, 0, &queue);
        device_table->QueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE);
        decode::EndInjectedCommands();
    }
    else
    {
        func(device_info->handle, semaphore, image);
    }
}

VkResult VulkanOffscreenSwapchain::QueueSubmit(PFN_vkQueueSubmit                    func,
                                               const VulkanQueueInfo*               queue_info,
                                               uint32_t                             submit_count,
                                               const VkSubmitInfo*                  submit_infos,
                                               const Decoded_VkSubmitInfo*          meta_submit_infos,
                                               const VulkanFenceInfo*               fence_info,
                                               VulkanInstanceInfo*                  instance_info,
                                               const graphics::VulkanInstanceTable* instance_table,
                                               const VulkanDeviceInfo*              device_info,
                                               const graphics::VulkanDeviceTable*   device_table,
                                               application::Application*            application,
                                               const CommonObjectInfoTable&         object_info_table)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance_info);
    GFXRECON_UNREFERENCED_PARAMETER(instance_table);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(device_table);
    GFXRECON_UNREFERENCED_PARAMETER(application);

    GFXRECON_ASSERT(queue_info != nullptr && (submit_infos != nullptr || submit_count == 0));

    VkFence fence = (fence_info == nullptr ? VK_NULL_HANDLE : fence_info->handle);

    // If offscreen frame boundaries need to be converted to VkFrameBoundaryEXT
    if (swapchain_options_.use_ext_frame_boundary)
    {
        std::vector<VkSubmitInfo>         modified_submit_infos(submit_infos, submit_infos + submit_count);
        std::vector<VkFrameBoundaryEXT>   inserted_frame_boundaries;
        std::vector<std::vector<VkImage>> inserted_frame_boundaries_images;

        for (uint32_t i = 0; i < submit_count; ++i)
        {
            // If the submit already contains a VkFrameBoundaryEXT, we can assume we don't need to convert it
            if (graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(&submit_infos[i]) == nullptr)
            {
                VkFrameBoundaryEXT*   frame_boundary = nullptr;
                std::vector<VkImage>* images         = nullptr;

                const format::HandleId* command_buffer_ids = meta_submit_infos[i].pCommandBuffers.GetPointer();
                for (uint32_t j = 0; j < submit_infos[i].commandBufferCount; ++j)
                {
                    const VulkanCommandBufferInfo* command_buffer_info =
                        object_info_table.GetVkCommandBufferInfo(command_buffer_ids[j]);

                    if (command_buffer_info->is_frame_boundary)
                    {
                        if (frame_boundary == nullptr)
                        {
                            // Copy the internal frame_boundary_ to initialize the structure
                            inserted_frame_boundaries.push_back(frame_boundary_);
                            inserted_frame_boundaries_images.emplace_back();

                            frame_boundary = &inserted_frame_boundaries.back();
                            images         = &inserted_frame_boundaries_images.back();
                        }

                        for (format::HandleId framebuffer_id : command_buffer_info->frame_buffer_ids)
                        {
                            const VulkanFramebufferInfo* framebuffer_info =
                                object_info_table.GetVkFramebufferInfo(framebuffer_id);
                            for (format::HandleId image_view_id : framebuffer_info->attachment_image_view_ids)
                            {
                                const VulkanImageViewInfo* image_view_info =
                                    object_info_table.GetVkImageViewInfo(image_view_id);
                                const VulkanImageInfo* image_info =
                                    object_info_table.GetVkImageInfo(image_view_info->image_id);

                                images->push_back(image_info->handle);
                            }
                        }
                    }
                }

                if (frame_boundary != nullptr)
                {
                    // All frame boundaries share the same ID in this queue submit
                    frame_boundary->frameID = frame_boundary_.frameID + 1;

                    frame_boundary->pNext      = modified_submit_infos[i].pNext;
                    frame_boundary->imageCount = images->size();
                    frame_boundary->pImages    = images->data();

                    modified_submit_infos[i].pNext = frame_boundary;
                }
            }
        }

        // If the queue submission contains a frame boundary, increment the frame counter
        if (!inserted_frame_boundaries.empty())
        {
            ++frame_boundary_.frameID;
        }

        return func(queue_info->handle, modified_submit_infos.size(), modified_submit_infos.data(), fence);
    }
    else
    {
        return func(queue_info->handle, submit_count, submit_infos, fence);
    }
}

VkResult VulkanOffscreenSwapchain::QueueSubmit2(PFN_vkQueueSubmit2                   func,
                                                const VulkanQueueInfo*               queue_info,
                                                uint32_t                             submit_count,
                                                const VkSubmitInfo2*                 submit_infos,
                                                const Decoded_VkSubmitInfo2*         meta_submit_infos,
                                                const VulkanFenceInfo*               fence_info,
                                                VulkanInstanceInfo*                  instance_info,
                                                const graphics::VulkanInstanceTable* instance_table,
                                                const VulkanDeviceInfo*              device_info,
                                                const graphics::VulkanDeviceTable*   device_table,
                                                application::Application*            application,
                                                const CommonObjectInfoTable&         object_info_table)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance_info);
    GFXRECON_UNREFERENCED_PARAMETER(instance_table);
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(device_table);
    GFXRECON_UNREFERENCED_PARAMETER(application);

    GFXRECON_ASSERT(queue_info != nullptr && (submit_infos != nullptr || submit_count == 0));

    VkFence fence = (fence_info == nullptr ? VK_NULL_HANDLE : fence_info->handle);

    // If offscreen frame boundaries need to be converted to VkFrameBoundaryEXT
    if (swapchain_options_.use_ext_frame_boundary)
    {
        std::vector<VkSubmitInfo2>        modified_submit_infos(submit_infos, submit_infos + submit_count);
        std::vector<VkFrameBoundaryEXT>   inserted_frame_boundaries;
        std::vector<std::vector<VkImage>> inserted_frame_boundaries_images;

        for (uint32_t i = 0; i < submit_count; ++i)
        {
            // If the submit already contains a VkFrameBoundaryEXT, we can assume we don't need to convert it
            if (graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(&submit_infos[i]) == nullptr &&
                meta_submit_infos[i].pCommandBufferInfos != nullptr)
            {
                VkFrameBoundaryEXT*   frame_boundary = nullptr;
                std::vector<VkImage>* images         = nullptr;

                const Decoded_VkCommandBufferSubmitInfo* cmd_buf_sub_info =
                    meta_submit_infos[i].pCommandBufferInfos->GetMetaStructPointer();
                for (uint32_t j = 0; j < submit_infos[i].commandBufferInfoCount; ++j)
                {
                    const VulkanCommandBufferInfo* command_buffer_info =
                        object_info_table.GetVkCommandBufferInfo(cmd_buf_sub_info[j].commandBuffer);

                    if (command_buffer_info->is_frame_boundary)
                    {
                        if (frame_boundary == nullptr)
                        {
                            // Copy the internal frame_boundary_ to initialize the structure
                            inserted_frame_boundaries.push_back(frame_boundary_);
                            inserted_frame_boundaries_images.emplace_back();

                            frame_boundary = &inserted_frame_boundaries.back();
                            images         = &inserted_frame_boundaries_images.back();
                        }

                        for (format::HandleId framebuffer_id : command_buffer_info->frame_buffer_ids)
                        {
                            const VulkanFramebufferInfo* framebuffer_info =
                                object_info_table.GetVkFramebufferInfo(framebuffer_id);
                            for (format::HandleId image_view_id : framebuffer_info->attachment_image_view_ids)
                            {
                                const VulkanImageViewInfo* image_view_info =
                                    object_info_table.GetVkImageViewInfo(image_view_id);
                                const VulkanImageInfo* image_info =
                                    object_info_table.GetVkImageInfo(image_view_info->image_id);

                                images->push_back(image_info->handle);
                            }
                        }
                    }
                }

                if (frame_boundary != nullptr)
                {
                    // All frame boundaries share the same ID in this queue submit
                    frame_boundary->frameID = frame_boundary_.frameID + 1;

                    frame_boundary->pNext      = modified_submit_infos[i].pNext;
                    frame_boundary->imageCount = images->size();
                    frame_boundary->pImages    = images->data();

                    modified_submit_infos[i].pNext = frame_boundary;
                }
            }
        }

        // If the queue submission contains a frame boundary, increment the frame counter
        if (!inserted_frame_boundaries.empty())
        {
            ++frame_boundary_.frameID;
        }

        return func(queue_info->handle, modified_submit_infos.size(), modified_submit_infos.data(), fence);
    }
    else
    {
        return func(queue_info->handle, submit_count, submit_infos, fence);
    }
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
