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
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/callbacks.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanOffscreenSwapchain::CleanDeviceResources(VkDevice device, const graphics::VulkanDeviceTable* device_table)
{
    VulkanVirtualSwapchain::CleanDeviceResources(device, device_table);

    external_sync_type_.erase(device);
}

void VulkanOffscreenSwapchain::SetExternalSyncType(VkDevice device, ExternalSyncType external_sync_type)
{
    external_sync_type_[device] = external_sync_type;
}

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
    swapchain_resources_[*replay_swapchain]->forced_offscreen = true;

    default_queue_ = GetDeviceQueue(device_table_, device_info, default_queue_family_index_, 0);

    // If this option is set, a command buffer submission with a `VkFrameBoundaryEXT` must be called each time
    // `vkQueuePresentKHR` should have been called by the offscreen swapchain. So a maximum of work must be done at
    // swapchain creation: Allocation and recording of an empty command buffer, initialization of a `VkFrameBoundaryEXT`
    // structure... (Don't forget to free everything at swapchain destruction)
    if (swapchain_options_.offscreen_swapchain_frame_boundary)
    {
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
        CreateSwapchainResourceData(device_info, swapchain_info, capture_image_count, replay_image_count, images);
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
        auto it = external_sync_type_.find(device_info->handle);
        GFXRECON_ASSERT(it != external_sync_type_.end());
        return SignalAcquireNextImageSemaphoreFence(device_info, semaphore, fence, it->second);
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
        auto it = external_sync_type_.find(device_info->handle);
        GFXRECON_ASSERT(it != external_sync_type_.end());
        return SignalAcquireNextImageSemaphoreFence(
            device_info, acquire_info->semaphore, acquire_info->fence, it->second);
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
    VkResult result = original_result;

    std::vector<VkPipelineStageFlags> wait_stages(present_info->waitSemaphoreCount,
                                                  VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);

    VkSubmitInfo submit_info;
    submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = present_info->waitSemaphoreCount;
    submit_info.pWaitSemaphores      = present_info->pWaitSemaphores;
    submit_info.pWaitDstStageMask    = wait_stages.data();
    submit_info.commandBufferCount   = 0;
    submit_info.pCommandBuffers      = nullptr;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    std::vector<VkImage> images;
    if (swapchain_options_.offscreen_swapchain_frame_boundary)
    {
        images.resize(present_info->swapchainCount);
        for (uint32_t i = 0; i < images.size(); ++i)
        {
            images[i] = swapchain_resources_[present_info->pSwapchains[i]]
                            ->virtual_swapchain_images[present_info->pImageIndices[i]]
                            .image;
        }
        GFXRECON_NARROWING_ASSIGN(frame_boundary_.imageCount, images.size());
        frame_boundary_.pImages = images.data();
        ++frame_boundary_.frameID;

        submit_info.pNext = &frame_boundary_;
    }

    if (swapchain_options_.offscreen_swapchain_frame_boundary || present_info->waitSemaphoreCount > 0)
    {
        util::MarkInjectedCommandsHelper mark_injected_commands_helper;
        result = device_table_->QueueSubmit(queue_info->handle, 1, &submit_info, VK_NULL_HANDLE);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Offscreen swapchain failed to QueueSubmit on QueuePresentKHR for queue %" PRIu64,
                               queue_info->handle);
        }
    }

    return result;
}

void VulkanOffscreenSwapchain::PresentImageAdHoc(const VulkanDeviceInfo*                    device_info,
                                                 const VulkanSemaphoreInfo*                 semaphore_info,
                                                 const VulkanImageInfo*                     image_info,
                                                 VulkanInstanceInfo*                        instance_info,
                                                 const graphics::VulkanInstanceTable*       instance_table,
                                                 const graphics::VulkanDeviceTable*         device_table,
                                                 application::Application*                  application,
                                                 const std::optional<std::array<float, 2>>& scale)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_info);
    GFXRECON_UNREFERENCED_PARAMETER(semaphore_info);
    GFXRECON_UNREFERENCED_PARAMETER(image_info);
    GFXRECON_UNREFERENCED_PARAMETER(instance_info);
    GFXRECON_UNREFERENCED_PARAMETER(instance_table);
    GFXRECON_UNREFERENCED_PARAMETER(device_table);
    GFXRECON_UNREFERENCED_PARAMETER(application);
    GFXRECON_UNREFERENCED_PARAMETER(scale);

    GFXRECON_LOG_WARNING("%s is not implemented and should not be called", __func__);
}

VkResult VulkanOffscreenSwapchain::SignalAcquireNextImageSemaphoreFence(const VulkanDeviceInfo* device_info,
                                                                        VkSemaphore             semaphore,
                                                                        VkFence                 fence,
                                                                        ExternalSyncType        external_sync_type)
{
    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(semaphore != VK_NULL_HANDLE || fence != VK_NULL_HANDLE);

    VkResult result = VK_ERROR_UNKNOWN;

    util::MarkInjectedCommandsHelper mark_injected_commands_helper;

    switch (external_sync_type)
    {
        case ExternalSyncType::QueueSubmit:
        {
            VkSubmitInfo submit_info;
            submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
            submit_info.pNext                = nullptr;
            submit_info.waitSemaphoreCount   = 0;
            submit_info.pWaitSemaphores      = nullptr;
            submit_info.pWaitDstStageMask    = nullptr;
            submit_info.commandBufferCount   = 0;
            submit_info.pCommandBuffers      = nullptr;
            submit_info.signalSemaphoreCount = (semaphore == VK_NULL_HANDLE ? 0 : 1);
            submit_info.pSignalSemaphores    = (semaphore == VK_NULL_HANDLE ? nullptr : &semaphore);

            result = device_table_->QueueSubmit(default_queue_, 1, &submit_info, fence);

            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Offscreen swapchain failed to signal semaphore and fence by submitting an empty "
                                   "queue submission. (%s)",
                                   util::ToString<VkResult>(result).c_str());
            }

            break;
        }
        case ExternalSyncType::FileDescriptor:
        {
            if (semaphore != VK_NULL_HANDLE)
            {
                VkImportSemaphoreFdInfoKHR import_info;
                import_info.sType      = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR;
                import_info.pNext      = nullptr;
                import_info.semaphore  = semaphore;
                import_info.flags      = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT;
                import_info.handleType = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
                import_info.fd         = -1;

                result = device_table_->ImportSemaphoreFdKHR(device_info->handle, &import_info);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR_ONCE("Offscreen swapchain failed to signal semaphore by importing it as a file "
                                            "descriptor. (%s)",
                                            util::ToString<VkResult>(result).c_str());
                    result = SignalAcquireNextImageSemaphoreFence(
                        device_info, semaphore, VK_NULL_HANDLE, ExternalSyncType::QueueSubmit);
                }
            }

            if (fence != VK_NULL_HANDLE)
            {
                VkImportFenceFdInfoKHR import_info;
                import_info.sType      = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
                import_info.pNext      = nullptr;
                import_info.fence      = fence;
                import_info.flags      = VK_FENCE_IMPORT_TEMPORARY_BIT;
                import_info.handleType = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;
                import_info.fd         = -1;

                result = device_table_->ImportFenceFdKHR(device_info->handle, &import_info);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR_ONCE("Offscreen swapchain failed to signal fence by importing it as a file "
                                            "descriptor. (%s)",
                                            util::ToString<VkResult>(result).c_str());
                    result = SignalAcquireNextImageSemaphoreFence(
                        device_info, VK_NULL_HANDLE, fence, ExternalSyncType::QueueSubmit);
                }
            }

            break;
        }
        default:
        {
            GFXRECON_LOG_FATAL("Unhandled VulkanSwapchain::ExternalSyncType. Seems like a missing implementation.");
        }
    }

    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
