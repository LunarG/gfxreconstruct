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

#include "decode/vulkan_swapchain.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

void VulkanSwapchain::Clean()
{
    if (options_surface_index_ >= create_surface_count_)
    {
        GFXRECON_LOG_WARNING("Rendering was restricted to surface index %u, but a surface was never created for that "
                             "index; replay created %d surface(s)",
                             options_surface_index_,
                             create_surface_count_);
    }

    // Destroy any windows that were created for Vulkan surfaces.
    for (auto window : active_windows_)
    {
        auto wsi_context    = application_ ? application_->GetWsiContext(window->GetWsiExtension()) : nullptr;
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        GFXRECON_ASSERT(window_factory);
        window_factory->Destroy(window);
    }
}

VkResult VulkanSwapchain::CreateSurface(VkResult                            original_result,
                                        InstanceInfo*                       instance_info,
                                        const std::string&                  wsi_extension,
                                        VkFlags                             flags,
                                        HandlePointerDecoder<VkSurfaceKHR>* surface,
                                        const encode::InstanceTable*        instance_table,
                                        application::Application*           application,
                                        const VulkanReplayOptions&          replay_options)
{
    assert(instance_info != nullptr);

    instance_table_        = instance_table;
    application_           = application;
    options_surface_index_ = replay_options.surface_index;

    VkInstance    instance       = instance_info->handle;
    VkSurfaceKHR* replay_surface = nullptr;
    VkResult      result         = VK_SUCCESS;

    if (surface != nullptr)
    {
        replay_surface = surface->GetHandlePointer();
    }

    // For multi-surface captures, when replay is restricted to a specific surface, only create a surface for
    // the specified index.
    if ((options_surface_index_ == -1) || (options_surface_index_ == create_surface_count_))
    {
        // Create a window for our surface.
        assert(application_);
        auto wsi_context = application_ ? application_->GetWsiContext(wsi_extension, true) : nullptr;
        assert(wsi_context);
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        assert(window_factory);
        auto window =
            window_factory
                ? window_factory->Create(
                      kDefaultWindowPositionX, kDefaultWindowPositionY, kDefaultWindowWidth, kDefaultWindowHeight)
                : nullptr;

        if (window == nullptr)
        {
            // Failure to create a window is a fatal error.
            GFXRECON_LOG_FATAL("Failed to create a window for use with surface creation.  Replay cannot continue.");
            return VK_ERROR_UNKNOWN;
        }

        result = window->CreateSurface(instance_table_, instance, flags, replay_surface);

        if ((result == VK_SUCCESS) && (replay_surface != nullptr))
        {
            auto surface_id   = surface->GetPointer();
            auto surface_info = reinterpret_cast<SurfaceKHRInfo*>(surface->GetConsumerData(0));
            assert((surface_id != nullptr) && (surface_info != nullptr));
            assert(!surface_info->surface_creation_skipped);

            surface_info->window = window;
            active_windows_.insert(window);
        }
        else
        {
            window_factory->Destroy(window);
        }
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

    return result;
}

void VulkanSwapchain::DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                     const InstanceInfo*          instance_info,
                                     const SurfaceKHRInfo*        surface_info,
                                     const VkAllocationCallbacks* allocator)
{
    assert(instance_info != nullptr);

    VkInstance   instance = instance_info->handle;
    VkSurfaceKHR surface  = VK_NULL_HANDLE;
    Window*      window   = nullptr;

    if (surface_info != nullptr)
    {
        surface = surface_info->handle;
        window  = surface_info->window;
    }

    if (window != nullptr)
    {
        window->DestroySurface(instance_table_, instance, surface);
        active_windows_.erase(window);
        auto wsi_context    = application_ ? application_->GetWsiContext(window->GetWsiExtension()) : nullptr;
        auto window_factory = wsi_context ? wsi_context->GetWindowFactory() : nullptr;
        if (window_factory)
        {
            window_factory->Destroy(window);
        }
    }
    else
    {
        func(instance, surface, allocator);
    }
}

VkResult VulkanSwapchain::AcquireNextImageKHR(VkResult                  original_result,
                                              PFN_vkAcquireNextImageKHR func,
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

    return AcquireNextImageKHR(original_result,
                               func,
                               device_info,
                               swapchain_info,
                               timeout,
                               semaphore,
                               fence,
                               capture_image_index,
                               image_index);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
