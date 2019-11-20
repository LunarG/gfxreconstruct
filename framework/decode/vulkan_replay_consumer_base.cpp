/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "decode/vulkan_replay_consumer_base.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/vulkan_enum_util.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cstdint>
#include <limits>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#else
    "libvulkan.so", "libvulkan.so.1"
#endif
};

const std::unordered_set<std::string> kSurfaceExtensions = {
    VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_MVK_IOS_SURFACE_EXTENSION_NAME, VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
    VK_KHR_MIR_SURFACE_EXTENSION_NAME,     VK_NN_VI_SURFACE_EXTENSION_NAME,   VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME,   VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

// Device extensions to enable for trimming state setup, when available.
const std::unordered_set<std::string> kTrimStateSetupDeviceExtensions = { VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME };

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugReportCallback(VkDebugReportFlagsEXT      flags,
                                                          VkDebugReportObjectTypeEXT objectType,
                                                          uint64_t                   object,
                                                          size_t                     location,
                                                          int32_t                    messageCode,
                                                          const char*                pLayerPrefix,
                                                          const char*                pMessage,
                                                          void*                      pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(objectType);
    GFXRECON_UNREFERENCED_PARAMETER(object);
    GFXRECON_UNREFERENCED_PARAMETER(location);
    GFXRECON_UNREFERENCED_PARAMETER(messageCode);
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pLayerPrefix != nullptr) && (pMessage != nullptr) &&
        ((flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) == VK_DEBUG_REPORT_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG REPORT: %s: %s", pLayerPrefix, pMessage);
    }

    return VK_FALSE;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugUtilsCallback(VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
                                                         VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
                                                         const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                         void*                                       pUserData)
{
    GFXRECON_UNREFERENCED_PARAMETER(pUserData);

    if ((pCallbackData != nullptr) && (pCallbackData->pMessageIdName != nullptr) &&
        (pCallbackData->pMessage != nullptr) &&
        ((messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) &&
        ((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) ==
         VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT))
    {
        GFXRECON_WRITE_CONSOLE("DEBUG MESSENGER: %s: %s", pCallbackData->pMessageIdName, pCallbackData->pMessage);
    }

    return VK_FALSE;
}

VulkanReplayConsumerBase::VulkanReplayConsumerBase(WindowFactory* window_factory, const ReplayOptions& options) :
    loader_handle_(nullptr), get_instance_proc_addr_(nullptr), create_instance_proc_(nullptr),
    window_factory_(window_factory), options_(options), loading_trim_state_(false)
{
    assert(window_factory != nullptr);
}

VulkanReplayConsumerBase::~VulkanReplayConsumerBase()
{
    // Destroy any windows that were created for Vulkan surfaces.
    for (const auto& entry : window_map_)
    {
        window_factory_->Destroy(entry.second);
    }

    if (loader_handle_ != nullptr)
    {
        util::platform::CloseLibrary(loader_handle_);
    }
}

void VulkanReplayConsumerBase::ProcessStateBeginMarker(uint64_t frame_number)
{
    GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, frame_number);
    loading_trim_state_ = true;
}

void VulkanReplayConsumerBase::ProcessStateEndMarker(uint64_t frame_number)
{
    GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);
    loading_trim_state_ = false;
}

void VulkanReplayConsumerBase::ProcessDisplayMessageCommand(const std::string& message)
{
    GFXRECON_LOG_INFO("Trace Message: %s", message.c_str());
}

void VulkanReplayConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                        uint64_t       offset,
                                                        uint64_t       size,
                                                        const uint8_t* data)
{
    // We need to find the device memory associated with this ID, and then lookup its mapped pointer.
    const DeviceMemoryInfo* memory_info = object_info_table_.GetDeviceMemoryInfo(memory_id);

    if (memory_info != nullptr)
    {
        assert(memory_info->handle != VK_NULL_HANDLE);

        auto entry = memory_map_.find(memory_info->handle);

        if ((entry != memory_map_.end()) && (entry->second != nullptr))
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
            memcpy(static_cast<uint8_t*>(entry->second) + offset, data, static_cast<size_t>(size));
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping memory fill for VkDeviceMemory object (ID = %" PRIu64 ") that is not mapped",
                                 memory_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping memory fill for unrecognized VkDeviceMemory object (ID = %" PRIu64 ")",
                             memory_id);
    }
}

void VulkanReplayConsumerBase::ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    // We need to find the surface associated with this ID, and then lookup its window.
    const SurfaceKHRInfo* surface_info = object_info_table_.GetSurfaceKHRInfo(surface_id);

    if (surface_info != nullptr)
    {
        assert(surface_info->handle != VK_NULL_HANDLE);

        auto entry = window_map_.find(surface_info->handle);

        if ((entry != window_map_.end()) && (entry->second != nullptr))
        {
            Window* window = entry->second;
            window->SetSize(width, height);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping window resize for VkSurface object (ID = %" PRIu64
                                 ") without an associated window",
                                 surface_id);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping window resize for unrecognized VkSurface object (ID = %" PRIu64 ")", surface_id);
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    const DeviceInfo*       device_info    = object_info_table_.GetDeviceInfo(device_id);
    const SwapchainKHRInfo* swapchain_info = object_info_table_.GetSwapchainKHRInfo(swapchain_id);

    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        assert((device_info->handle != VK_NULL_HANDLE) && (swapchain_info->handle != VK_NULL_HANDLE));

        VkDevice       device    = device_info->handle;
        VkSwapchainKHR swapchain = swapchain_info->handle;

        VkPhysicalDevice physical_device = device_parents_[device];
        VkSurfaceKHR     surface         = swapchain_surfaces_[swapchain];
        assert((physical_device != VK_NULL_HANDLE) && (surface != VK_NULL_HANDLE));

        auto instance_table = GetInstanceTable(physical_device);
        auto device_table   = GetDeviceTable(device);
        assert((instance_table != nullptr) && (device_table != nullptr));

        VkSurfaceCapabilitiesKHR surface_caps;
        uint32_t                 image_count = 0;

        VkResult result =
            instance_table->GetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface, &surface_caps);

        if (result == VK_SUCCESS)
        {
            result = device_table->GetSwapchainImagesKHR(device, swapchain, &image_count, nullptr);
        }

        if (result == VK_SUCCESS)
        {
            // TODO: Handle swapchain image count mismatch on replay.
            assert(image_info.size() == image_count);

            // Determine if it is possible to acquire all images at the same time.
            assert(image_count >= surface_caps.minImageCount);
            uint32_t max_acquired_images = (image_count - surface_caps.minImageCount) + 1;

            if (image_count > max_acquired_images)
            {
                // Cannot acquire all images at the same time.
                ProcessSetSwapchainImageStateQueueSubmit(device, swapchain, last_presented_image, image_info);
            }
            else
            {
                ProcessSetSwapchainImageStatePreAcquire(device, swapchain, image_info);
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Failed image initialization for VkSwapchainKHR object (ID = %" PRIu64
                                 ", handle = 0x%" PRIx64 ")",
                                 swapchain_id,
                                 swapchain);
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkSwapchainKHR object (ID = %" PRIu64 ")",
                                 swapchain_id);
        }
        else if (swapchain_info != nullptr)
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice object (ID = %" PRIu64 ")",
                                 device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping image acquire for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkSwapchainKHR (ID = %" PRIu64 ") objects",
                                 device_id,
                                 swapchain_id);
        }
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStatePreAcquire(
    VkDevice device, VkSwapchainKHR swapchain, const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         transition_queue   = VK_NULL_HANDLE;
    VkCommandPool   transition_pool    = VK_NULL_HANDLE;
    VkCommandBuffer transition_command = VK_NULL_HANDLE;
    uint32_t        queue_family_index = swapchain_queue_families_[swapchain];

    // TODO: Improved queue selection?
    table->GetDeviceQueue(device, queue_family_index, 0, &transition_queue);

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    result = table->CreateCommandPool(device, &pool_create_info, nullptr, &transition_pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = transition_pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        table->AllocateCommandBuffers(device, &command_allocate_info, &transition_command);
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
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

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

                result = table->CreateFence(device, &fence_create_info, nullptr, &acquire_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->CreateSemaphore(device, &semaphore_create_info, nullptr, &acquire_semaphore);
                }

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        acquire_semaphore,
                                                        acquire_fence,
                                                        &image_index);

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        // TODO: Handle case where image acquired at replay does not match image acquired at
                        // capture.
                        assert(image_index == i);

                        result =
                            table->WaitForFences(device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());

                        VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[image_index].image_layout);
                        if ((result == VK_SUCCESS) && (image_layout != VK_IMAGE_LAYOUT_UNDEFINED))
                        {
                            image_barrier.newLayout = image_layout;
                            image_barrier.image     = image;

                            result = table->BeginCommandBuffer(transition_command, &begin_info);

                            if (result == VK_SUCCESS)
                            {
                                table->CmdPipelineBarrier(transition_command,
                                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                          VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                          0,
                                                          0,
                                                          nullptr,
                                                          0,
                                                          nullptr,
                                                          1,
                                                          &image_barrier);
                                table->EndCommandBuffer(transition_command);

                                result = table->ResetFences(device, 1, &acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = table->QueueSubmit(transition_queue, 1, &submit_info, acquire_fence);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = table->WaitForFences(
                                    device, 1, &acquire_fence, true, std::numeric_limits<uint64_t>::max());
                            }
                        }

                        if (result == VK_SUCCESS)
                        {
                            if (image_info[image_index].acquired)
                            {
                                // The upcoming frames expect the image to be acquired. The synchronization objects
                                // used to acquire the image were already set to the appropriate signaled state when
                                // created, so the temporary objects used to acquire the image here can be
                                // destroyed.
                                table->DestroyFence(device, acquire_fence, nullptr);
                                table->DestroySemaphore(device, acquire_semaphore, nullptr);
                            }
                            else
                            {
                                // The upcoming frames do not expect the image to be acquired. We will store the
                                // image and the synchronization objects used to acquire it in a data structure.
                                // Replay of vkAcquireNextImage will retrieve and use the stored objects.
                                swapchain_image_tracker_.TrackPreAcquiredImage(
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
        table->DestroyCommandPool(device, transition_pool, nullptr);
    }
}

void VulkanReplayConsumerBase::ProcessSetSwapchainImageStateQueueSubmit(
    VkDevice                                            device,
    VkSwapchainKHR                                      swapchain,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_info)
{
    auto table = GetDeviceTable(device);
    assert(table != nullptr);

    VkResult        result             = VK_SUCCESS;
    VkQueue         queue              = VK_NULL_HANDLE;
    VkCommandPool   pool               = VK_NULL_HANDLE;
    VkCommandBuffer command            = VK_NULL_HANDLE;
    VkFence         wait_fence         = VK_NULL_HANDLE;
    uint32_t        queue_family_index = swapchain_queue_families_[swapchain];

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.pNext                   = nullptr;
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex        = queue_family_index;

    // TODO: Improved queue selection?
    table->GetDeviceQueue(device, queue_family_index, 0, &queue);

    result = table->CreateCommandPool(device, &pool_create_info, nullptr, &pool);

    if (result == VK_SUCCESS)
    {
        VkCommandBufferAllocateInfo command_allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        command_allocate_info.pNext                       = nullptr;
        command_allocate_info.commandBufferCount          = 1;
        command_allocate_info.commandPool                 = pool;
        command_allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

        result = table->AllocateCommandBuffers(device, &command_allocate_info, &command);
    }

    if (result == VK_SUCCESS)
    {
        VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
        fence_create_info.pNext             = nullptr;
        fence_create_info.flags             = VK_FENCE_CREATE_SIGNALED_BIT;

        result = table->CreateFence(device, &fence_create_info, nullptr, &wait_fence);
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
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

            if (image_entry != nullptr)
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = table->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        VK_NULL_HANDLE,
                                                        wait_fence,
                                                        &image_index);
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    // TODO: Handle case where image acquired at replay does not match image acquired at capture.
                    assert(image_index == i);

                    result = table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        image_barrier.image        = image;
                        present_info.pImageIndices = &image_index;

                        result = table->BeginCommandBuffer(command, &begin_info);
                    }

                    if (result == VK_SUCCESS)
                    {
                        table->CmdPipelineBarrier(command,
                                                  VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                  VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                  0,
                                                  0,
                                                  nullptr,
                                                  0,
                                                  nullptr,
                                                  1,
                                                  &image_barrier);
                        table->EndCommandBuffer(command);

                        result = table->ResetFences(device, 1, &wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = table->QueueSubmit(queue, 1, &submit_info, wait_fence);
                    }

                    if (result == VK_SUCCESS)
                    {
                        result =
                            table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                    }

                    if (result == VK_SUCCESS)
                    {
                        result = table->QueuePresentKHR(queue, &present_info);
                    }

                    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                    {
                        result = table->QueueWaitIdle(queue);
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
            const ImageInfo* image_entry = object_info_table_.GetImageInfo(image_info[i].image_id);

            if ((image_entry != nullptr) && ((image_info[i].acquired) || (i <= last_presented_image)))
            {
                assert(image_entry->handle != VK_NULL_HANDLE);

                VkImage  image       = image_entry->handle;
                uint32_t image_index = 0;

                result = table->ResetFences(device, 1, &wait_fence);

                if (result == VK_SUCCESS)
                {
                    result = table->AcquireNextImageKHR(device,
                                                        swapchain,
                                                        std::numeric_limits<uint64_t>::max(),
                                                        VK_NULL_HANDLE,
                                                        wait_fence,
                                                        &image_index);
                }

                if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                {
                    // TODO: Handle case where image acquired at replay does not match image acquired at capture.
                    assert(image_index == i);

                    result = table->WaitForFences(device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());

                    if (result == VK_SUCCESS)
                    {
                        if (image_info[i].acquired)
                        {
                            // Transition the image to the expected layout and keep it acquired.
                            VkImageLayout image_layout = static_cast<VkImageLayout>(image_info[i].image_layout);
                            if ((image_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                                (image_layout != VK_IMAGE_LAYOUT_PRESENT_SRC_KHR))
                            {

                                image_barrier.newLayout = image_layout;
                                image_barrier.image     = image;

                                result = table->BeginCommandBuffer(command, &begin_info);

                                if (result == VK_SUCCESS)
                                {
                                    table->CmdPipelineBarrier(command,
                                                              VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                              VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                              0,
                                                              0,
                                                              nullptr,
                                                              0,
                                                              nullptr,
                                                              1,
                                                              &image_barrier);
                                    table->EndCommandBuffer(command);

                                    result = table->ResetFences(device, 1, &wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = table->QueueSubmit(queue, 1, &submit_info, wait_fence);
                                }

                                if (result == VK_SUCCESS)
                                {
                                    result = table->WaitForFences(
                                        device, 1, &wait_fence, true, std::numeric_limits<uint64_t>::max());
                                }
                            }
                        }
                        else
                        {
                            // Image is not expected to be in the acquired state, so present it.
                            present_info.pImageIndices = &image_index;

                            result = table->QueuePresentKHR(queue, &present_info);

                            if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
                            {
                                result = table->QueueWaitIdle(queue);
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
        table->DestroyCommandPool(device, pool, nullptr);
    }

    if (wait_fence != VK_NULL_HANDLE)
    {
        table->DestroyFence(device, wait_fence, nullptr);
    }
}

void VulkanReplayConsumerBase::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                               uint64_t         max_resource_size,
                                                               uint64_t         max_copy_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(max_resource_size);

    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

    if (device_info != nullptr)
    {
        assert(device_info->handle != VK_NULL_HANDLE);

        VkResult       result = VK_SUCCESS;
        VkDevice       device = device_info->handle;
        VkBuffer       buffer = VK_NULL_HANDLE;
        VkDeviceMemory memory = VK_NULL_HANDLE;

        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        VkPhysicalDevice physical_device = device_parents_[device];
        assert(physical_device != VK_NULL_HANDLE);

        VkPhysicalDeviceMemoryProperties properties;
        auto                             instance_table = GetInstanceTable(physical_device);
        assert(instance_table != nullptr);

        instance_table->GetPhysicalDeviceMemoryProperties(physical_device, &properties);

        const auto& available_extensions      = trim_device_extensions_[physical_device];
        bool        have_shader_stencil_write = false;

        if (std::find(available_extensions.begin(),
                      available_extensions.end(),
                      VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME) != available_extensions.end())
        {
            have_shader_stencil_write = true;
        }

        resource_initializers_.emplace(device,
                                       std::make_unique<VulkanResourceInitializer>(
                                           device, max_copy_size, properties, have_shader_stencil_write, table));
    }
}

void VulkanReplayConsumerBase::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);

    if (device_info != nullptr)
    {
        resource_initializers_.erase(device_info->handle);
    }
}

void VulkanReplayConsumerBase::ProcessInitBufferCommand(format::HandleId device_id,
                                                        format::HandleId buffer_id,
                                                        uint64_t         data_size,
                                                        const uint8_t*   data)
{
    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);
    const BufferInfo* buffer_info = object_info_table_.GetBufferInfo(buffer_id);

    if ((device_info != nullptr) && (buffer_info != nullptr))
    {
        assert((device_info->handle != VK_NULL_HANDLE) && (buffer_info->handle != VK_NULL_HANDLE));

        VkResult result = VK_SUCCESS;
        VkDevice device = device_info->handle;
        VkBuffer buffer = buffer_info->handle;

        const BufferProperties& info = buffer_info_[buffer];

        VulkanResourceInitializer* initializer = nullptr;

        auto initializer_iter = resource_initializers_.find(device);
        if (initializer_iter != resource_initializers_.end())
        {
            initializer = initializer_iter->second.get();
        }

        if (initializer != nullptr)
        {
            if ((info.memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
            {
                assert(info.memory != VK_NULL_HANDLE);

                result = initializer->LoadData(info.memory, info.bind_offset, data_size, data);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("State snapshot mapped memory copy failed for VkBuffer object (ID = %" PRIu64
                                         ", handle = 0x%" PRIx64 ")",
                                         buffer_id,
                                         buffer);
                }
            }
            else
            {
                VkBufferCopy copy_region;
                copy_region.srcOffset = 0;
                copy_region.dstOffset = 0;
                copy_region.size      = data_size;

                result = initializer->InitializeBuffer(
                    data_size, data, info.queue_family_index, buffer, info.usage, 1, &copy_region);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_WARNING("State snapshot staging buffer copy failed for VkBuffer object (ID = %" PRIu64
                                         ", handle = 0x%" PRIx64 ")",
                                         buffer_id,
                                         buffer);
                }
            }
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot buffer upload for unrecognized VkBuffer object (ID = %" PRIu64 ")", buffer_id);
        }
        else if (buffer_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot buffer upload for unrecognized VkDevice object (ID = %" PRIu64 ")", device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping state snapshot buffer upload for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkBuffer (ID = %" PRIu64 ") objects",
                                 device_id,
                                 buffer_id);
        }
    }
}

void VulkanReplayConsumerBase::ProcessInitImageCommand(format::HandleId             device_id,
                                                       format::HandleId             image_id,
                                                       uint64_t                     data_size,
                                                       uint32_t                     aspect,
                                                       uint32_t                     layout,
                                                       const std::vector<uint64_t>& level_sizes,
                                                       const uint8_t*               data)
{
    const DeviceInfo* device_info = object_info_table_.GetDeviceInfo(device_id);
    const ImageInfo*  image_info  = object_info_table_.GetImageInfo(image_id);

    if ((device_info != nullptr) && (image_info != nullptr))
    {
        VkDevice device = device_info->handle;
        VkImage  image  = image_info->handle;

        assert((device != VK_NULL_HANDLE) && (image != VK_NULL_HANDLE));

        VkResult                   result      = VK_SUCCESS;
        const ImageProperties&     info        = image_info_[image];
        VulkanResourceInitializer* initializer = nullptr;

        auto initializer_iter = resource_initializers_.find(device);
        if (initializer_iter != resource_initializers_.end())
        {
            initializer = initializer_iter->second.get();
        }

        if (initializer != nullptr)
        {
            std::vector<VkBufferImageCopy> copy_regions;

            if (data_size > 0)
            {
                if ((info.tiling == VK_IMAGE_TILING_LINEAR) &&
                    (info.memory_property_flags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) ==
                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
                {
                    assert(info.memory != VK_NULL_HANDLE);

                    result = initializer->LoadData(info.memory, info.bind_offset, data_size, data);

                    if (result != VK_SUCCESS)
                    {
                        GFXRECON_LOG_WARNING(
                            "State snapshot mapped memory copy failed for VkImage object (ID = %" PRIu64
                            ", handle = 0x%" PRIx64 ")",
                            image_id,
                            image);
                    }
                }
                else
                {
                    // Create one copy region per mip-level.
                    VkBufferImageCopy copy_region;
                    copy_region.bufferRowLength                 = 0; // Request tightly packed data.
                    copy_region.bufferImageHeight               = 0; // Request tightly packed data.
                    copy_region.bufferOffset                    = 0;
                    copy_region.imageOffset.x                   = 0;
                    copy_region.imageOffset.y                   = 0;
                    copy_region.imageOffset.z                   = 0;
                    copy_region.imageSubresource.aspectMask     = aspect;
                    copy_region.imageSubresource.baseArrayLayer = 0;
                    copy_region.imageSubresource.layerCount     = info.layer_count;

                    assert(info.level_count == level_sizes.size());

                    for (uint32_t i = 0; i < info.level_count; ++i)
                    {
                        copy_region.imageSubresource.mipLevel = i;
                        copy_region.imageExtent.width         = std::max(1u, (info.extent.width >> i));
                        copy_region.imageExtent.height        = std::max(1u, (info.extent.height >> i));
                        copy_region.imageExtent.depth         = std::max(1u, (info.extent.depth >> i));

                        copy_regions.push_back(copy_region);
                        copy_region.bufferOffset += level_sizes[i];
                    }
                }
            }

            if (!copy_regions.empty())
            {
                result = initializer->InitializeImage(data_size,
                                                      data,
                                                      info.queue_family_index,
                                                      image,
                                                      info.type,
                                                      info.format,
                                                      info.extent,
                                                      static_cast<VkImageAspectFlagBits>(aspect),
                                                      info.sample_count,
                                                      info.usage,
                                                      static_cast<VkImageLayout>(info.initial_layout),
                                                      static_cast<VkImageLayout>(layout),
                                                      info.layer_count,
                                                      static_cast<uint32_t>(copy_regions.size()),
                                                      copy_regions.data());
            }
            else if ((layout != VK_IMAGE_LAYOUT_UNDEFINED) && (layout != VK_IMAGE_LAYOUT_PREINITIALIZED))
            {
                // Only transition to the final layout when a staging copy is not required for image data upload.
                result = initializer->TransitionImage(info.queue_family_index,
                                                      image,
                                                      info.format,
                                                      static_cast<VkImageAspectFlagBits>(aspect),
                                                      static_cast<VkImageLayout>(info.initial_layout),
                                                      static_cast<VkImageLayout>(layout),
                                                      info.layer_count,
                                                      info.level_count);
            }

            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING(
                    "State snapshot image upload/layout transition failed for VkImage object (ID = %" PRIu64
                    ", handle = 0x%" PRIx64 ")",
                    image_id,
                    image);
            }
        }
    }
    else
    {
        if (device_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot image upload for unrecognized VkImage object (ID = %" PRIu64 ")", image_id);
        }
        else if (image_info != nullptr)
        {
            GFXRECON_LOG_WARNING(
                "Skipping state snapshot image upload for unrecognized VkDevice object (ID = %" PRIu64 ")", device_id);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping state snapshot image upload for unrecognized VkDevice (ID = %" PRIu64
                                 ") and VkImage (ID = %" PRIu64 ") objects",
                                 device_id,
                                 image_id);
        }
    }
}

void VulkanReplayConsumerBase::RaiseFatalError(const char* message) const
{
    // TODO: Should there be a default action if no error handler has been provided?
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void VulkanReplayConsumerBase::InitializeLoader()
{
    for (auto name : kLoaderLibNames)
    {
        loader_handle_ = util::platform::OpenLibrary(name.c_str());
        if (loader_handle_ != nullptr)
        {
            get_instance_proc_addr_ = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
                util::platform::GetProcAddress(loader_handle_, "vkGetInstanceProcAddr"));
            break;
        }
    }

    if (get_instance_proc_addr_ != nullptr)
    {
        create_instance_proc_ =
            reinterpret_cast<PFN_vkCreateInstance>(get_instance_proc_addr_(nullptr, "vkCreateInstance"));
    }

    if (create_instance_proc_ == nullptr)
    {
        GFXRECON_LOG_FATAL("Failed to load Vulkan runtime library; please ensure that the path to the Vulkan "
                           "loader (eg. %s) has been added to the appropriate system path",
                           kLoaderLibNames[0].c_str());
        RaiseFatalError("Failed to load Vulkan runtime library");
    }
}

void VulkanReplayConsumerBase::AddInstanceTable(VkInstance instance)
{
    encode::DispatchKey dispatch_key = encode::GetDispatchKey(instance);

    get_device_proc_addrs_[dispatch_key] =
        reinterpret_cast<PFN_vkGetDeviceProcAddr>(get_instance_proc_addr_(instance, "vkGetDeviceProcAddr"));
    create_device_procs_[dispatch_key] =
        reinterpret_cast<PFN_vkCreateDevice>(get_instance_proc_addr_(instance, "vkCreateDevice"));

    encode::InstanceTable& table = instance_tables_[dispatch_key];
    encode::LoadInstanceTable(get_instance_proc_addr_, instance, &table);
}

void VulkanReplayConsumerBase::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    encode::DeviceTable& table = device_tables_[encode::GetDispatchKey(device)];
    encode::LoadDeviceTable(gpa, device, &table);
}

PFN_vkGetDeviceProcAddr VulkanReplayConsumerBase::GetDeviceAddrProc(VkPhysicalDevice physical_device)
{
    return get_device_proc_addrs_[encode::GetDispatchKey(physical_device)];
}

PFN_vkCreateDevice VulkanReplayConsumerBase::GetCreateDeviceProc(VkPhysicalDevice physical_device)
{
    return create_device_procs_[encode::GetDispatchKey(physical_device)];
}

const encode::InstanceTable* VulkanReplayConsumerBase::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(encode::GetDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::DeviceTable* VulkanReplayConsumerBase::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(encode::GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

void* VulkanReplayConsumerBase::PreProcessExternalObject(uint64_t          object_id,
                                                         format::ApiCallId call_id,
                                                         const char*       call_name)
{
    void* object = nullptr;

    if ((call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR) ||
        (call_id == format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR))
    {
        // The window system related handles are ignored by replay.
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }

    return object;
}

void VulkanReplayConsumerBase::PostProcessExternalObject(
    VkResult replay_result, uint64_t object_id, void* object, format::ApiCallId call_id, const char* call_name)
{
    GFXRECON_UNREFERENCED_PARAMETER(replay_result);
    GFXRECON_UNREFERENCED_PARAMETER(object_id);
    GFXRECON_UNREFERENCED_PARAMETER(object);

    if (call_id == format::ApiCallId::ApiCall_vkMapMemory)
    {
        // Mapped memory tracking is handled by mapping the VkDeviceMemory handle to the mapped pointer, rather than
        // mapping the captured pointer address to the pointer mapped on replay.  The memory needs to be tracked by
        // handle so that it can be removed from the unordered_map when memory is unmapped or freed.
    }
    else
    {
        GFXRECON_LOG_WARNING("Skipping object handle mapping for unsupported external object type processed by %s",
                             call_name);
    }
}

const VkAllocationCallbacks* VulkanReplayConsumerBase::GetAllocationCallbacks(
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& original_callbacks)
{
    // Replay does not currently attempt emulate the captured application's use of VkAllocationCallbacks.
    GFXRECON_UNREFERENCED_PARAMETER(original_callbacks);
    return nullptr;
}

void VulkanReplayConsumerBase::CheckResult(const char* func_name, VkResult original, VkResult replay)
{
    if (original != replay)
    {
        if ((replay < 0) && (replay != VK_ERROR_FORMAT_NOT_SUPPORTED))
        {
            // Raise a fatal error if replay produced an error that did not occur during capture.  Format not supported
            // errors are not treated as fatal, but will be reported as warnings below, allowing the replay to attempt
            // to continue for the case where an application may have queried for formats that it did not use.
            GFXRECON_LOG_FATAL("API call %s returned error value %s that does not match the result from the "
                               "capture file: %s.  Replay cannot continue.",
                               func_name,
                               enumutil::GetResultValueString(replay),
                               enumutil::GetResultValueString(original));

            RaiseFatalError(enumutil::GetResultDescription(replay));
        }
        else if (!((replay == VK_SUCCESS) &&
                   ((original == VK_TIMEOUT) || (original == VK_NOT_READY) || (original == VK_ERROR_OUT_OF_DATE_KHR))))
        {
            // Report differences between replay result and capture result, unless the replay results indicates
            // that a wait operation completed before the original or a WSI function succeeded when the original failed.
            GFXRECON_LOG_WARNING(
                "API call %s returned value %s that does not match return value from capture file: %s.",
                func_name,
                enumutil::GetResultValueString(replay),
                enumutil::GetResultValueString(original));
        }
    }
}

void VulkanReplayConsumerBase::ProcessPhysicalDeviceProperties(VkPhysicalDevice                  physical_device,
                                                               const VkPhysicalDeviceProperties* capture_properties,
                                                               const VkPhysicalDeviceProperties* replay_properties)
{
    if (device_properties_.find(physical_device) == device_properties_.end())
    {
        PhysicalDeviceProperties properties = { (*capture_properties), (*replay_properties) };
        device_properties_.emplace(physical_device, properties);
    }
}

void VulkanReplayConsumerBase::OverridePhysicalDevice(VkPhysicalDevice* physical_device)
{
    assert((physical_device != nullptr) && (options_.override_gpu_index >= 0));

    // Match the current physical device with its parent instance.
    VkInstance instance = VK_NULL_HANDLE;

    for (const auto& entry : instance_devices_)
    {
        auto result =
            std::find(entry.second.replay_devices.begin(), entry.second.replay_devices.end(), (*physical_device));
        if (result != entry.second.replay_devices.end())
        {
            instance = entry.first;
            break;
        }
    }

    if (instance != VK_NULL_HANDLE)
    {
        auto devices_entry = instance_devices_.find(instance);
        if (devices_entry != instance_devices_.end())
        {
            const auto& replay_devices = devices_entry->second.replay_devices;

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(int32_t, replay_devices.size());
            int32_t replay_devices_size = static_cast<int32_t>(replay_devices.size());

            if (options_.override_gpu_index < replay_devices_size)
            {
                VkPhysicalDevice override_device = replay_devices[options_.override_gpu_index];

                if (override_device != (*physical_device))
                {
                    GFXRECON_LOG_INFO("Overriding replay device with GPU%d", options_.override_gpu_index);
                    GFXRECON_LOG_INFO("  Available devices are:");
                    for (int32_t i = 0; i < replay_devices_size; ++i)
                    {
                        GFXRECON_LOG_INFO("    [%d] %p", i, replay_devices[i]);
                    }
                    GFXRECON_LOG_INFO("  Original device is: %p", *physical_device);
                    GFXRECON_LOG_INFO("  Override device is: %p", override_device);

                    // Warn about potential incompatibilities when replay device type does not match capture
                    // device type.
                    auto capture_entry = device_properties_.find(*physical_device);
                    auto replay_entry  = device_properties_.find(override_device);
                    if ((capture_entry != device_properties_.end()) && (replay_entry != device_properties_.end()))
                    {
                        const auto& capture_properties = capture_entry->second.capture_properties;
                        const auto& replay_properties  = replay_entry->second.replay_properties;
                        if ((capture_properties.vendorID != replay_properties.vendorID) &&
                            (capture_properties.deviceID != replay_properties.deviceID))
                        {
                            GFXRECON_LOG_WARNING(
                                "The type of device selected for replay differs from the type of the original capture "
                                "device; replay may fail due to device incompatibilities:");
                            GFXRECON_LOG_WARNING(
                                "  Capture device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                                capture_properties.vendorID,
                                capture_properties.deviceID,
                                capture_properties.deviceName);
                            GFXRECON_LOG_WARNING(
                                "  Replay device info:\t[vendorID = 0x%x, deviceId = 0x%x, deviceName = %s]",
                                replay_properties.vendorID,
                                replay_properties.deviceID,
                                replay_properties.deviceName);
                        }
                    }
                    else
                    {
                        // No query was made for physical device properties prior to device creation at capture,
                        // so provide a generic warning.
                        GFXRECON_LOG_WARNING(
                            "If the type of device selected for replay differs from the type of the original capture "
                            "device, replay may fail due to device incompatibilities");
                    }

                    (*physical_device) = override_device;
                }
            }
            else
            {
                GFXRECON_LOG_ERROR(
                    "The zero-based index specified for replay device override (%d) exceeds the total number of "
                    "available physical devices (%d). The specified index requires that at least %d devices be "
                    "available. The override will not be applied.",
                    options_.override_gpu_index,
                    replay_devices_size,
                    (options_.override_gpu_index + 1));
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Replay device override failed to find a list of physical devices associated with "
                               "the current instance; the override will not be applied")
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Replay device override failed to match the original physical device handle with an "
                           "instance; the override will not be applied")
    }
}

bool VulkanReplayConsumerBase::CheckTrimDeviceExtensions(VkPhysicalDevice           physical_device,
                                                         std::vector<std::string>** extensions)
{
    bool have_extensions = false;
    auto table           = GetInstanceTable(physical_device);
    assert(table != nullptr);

    uint32_t count  = 0;
    VkResult result = table->EnumerateDeviceExtensionProperties(physical_device, nullptr, &count, nullptr);

    if ((result == VK_SUCCESS) && (count > 0))
    {
        std::vector<VkExtensionProperties> properties;
        properties.resize(count);

        result = table->EnumerateDeviceExtensionProperties(physical_device, nullptr, &count, properties.data());

        if (result == VK_SUCCESS)
        {
            assert(count == properties.size());

            auto& entry = trim_device_extensions_[physical_device];

            for (const auto& property : properties)
            {
                if (kTrimStateSetupDeviceExtensions.find(property.extensionName) !=
                    kTrimStateSetupDeviceExtensions.end())
                {
                    entry.push_back(property.extensionName);
                }
            }

            have_extensions = !entry.empty();

            if (extensions != nullptr)
            {
                (*extensions) = &entry;
            }
        }
    }

    return have_extensions;
}

VkResult VulkanReplayConsumerBase::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* surface)
{
    // Create a window for our surface.
    Window* window = window_factory_->Create(
        kDefaultWindowPositionX, kDefaultWindowPositionY, kDefaultWindowWidth, kDefaultWindowHeight);

    if (window == nullptr)
    {
        // Failure to create a window is a fatal error.
        GFXRECON_LOG_FATAL("Failed to create a window for use with surface creation.  Replay cannot continue.");
        RaiseFatalError("Replay has encountered a fatal error and cannot continue (window creation failed)");
    }

    VkResult result = window->CreateSurface(GetInstanceTable(instance), instance, flags, surface);

    if ((result == VK_SUCCESS) && (surface != nullptr))
    {
        VkSurfaceKHR key = (*surface);

        assert(window_map_.find(key) == window_map_.end());

        window_map_.insert(std::make_pair(key, window));
    }
    else
    {
        window_factory_->Destroy(window);
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateInstance(VkResult original_result,
                                                 const StructPointerDecoder<Decoded_VkInstanceCreateInfo>&  pCreateInfo,
                                                 const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                                 HandlePointerDecoder<VkInstance>*                          pInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((pInstance != nullptr) && (pInstance->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();
    auto replay_instance    = pInstance->GetHandlePointer();

    if (loader_handle_ == nullptr)
    {
        InitializeLoader();
    }

    // Replace WSI extension in extension list.
    std::vector<const char*> filtered_extensions;
    VkInstanceCreateInfo     modified_create_info{};

    if (replay_create_info != nullptr)
    {
        if (replay_create_info->ppEnabledExtensionNames)
        {
            for (uint32_t i = 0; i < replay_create_info->enabledExtensionCount; ++i)
            {
                const char* current_extension = replay_create_info->ppEnabledExtensionNames[i];
                if (kSurfaceExtensions.find(current_extension) != kSurfaceExtensions.end())
                {
                    filtered_extensions.push_back(window_factory_->GetSurfaceExtensionName());
                }
                else
                {
                    filtered_extensions.push_back(current_extension);
                }
            }
        }

        modified_create_info                         = (*replay_create_info);
        modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(filtered_extensions.size());
        modified_create_info.ppEnabledExtensionNames = filtered_extensions.data();
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateInstance parameter pCreateInfo is NULL.");
    }

    // Disable layers; any layers needed for replay should be enabled for the replay app with the VK_INSTANCE_LAYERS
    // environment variable or debug.vulkan.layers Android property.
    if (modified_create_info.enabledLayerCount > 0)
    {
        GFXRECON_LOG_INFO(
            "Replay has removed the following layers from VkInstanceCreateInfo when calling vkCreateInstance:");

        for (uint32_t i = 0; i < modified_create_info.enabledLayerCount; ++i)
        {
            GFXRECON_LOG_INFO("\t%s", modified_create_info.ppEnabledLayerNames[i]);
        }

        modified_create_info.enabledLayerCount   = 0;
        modified_create_info.ppEnabledLayerNames = nullptr;
    }

    VkResult result = create_instance_proc_(&modified_create_info, GetAllocationCallbacks(pAllocator), replay_instance);

    if ((replay_instance != nullptr) && (result == VK_SUCCESS))
    {
        AddInstanceTable(*replay_instance);
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateDevice(VkResult                  original_result,
                                               const PhysicalDeviceInfo* physical_device_info,
                                               const StructPointerDecoder<Decoded_VkDeviceCreateInfo>&    pCreateInfo,
                                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                               HandlePointerDecoder<VkDevice>*                            pDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((physical_device_info != nullptr) && (pDevice != nullptr) && (pDevice->GetHandlePointer() != nullptr));

    VkResult                result               = VK_ERROR_INITIALIZATION_FAILED;
    VkPhysicalDevice        physical_device      = physical_device_info->handle;
    PFN_vkGetDeviceProcAddr get_device_proc_addr = GetDeviceAddrProc(physical_device);
    PFN_vkCreateDevice      create_device_proc   = GetCreateDeviceProc(physical_device);

    if ((get_device_proc_addr != nullptr) && (create_device_proc != nullptr))
    {
        auto replay_create_info = pCreateInfo.GetPointer();
        auto replay_device      = pDevice->GetHandlePointer();

        if (options_.override_gpu_index >= 0)
        {
            OverridePhysicalDevice(&physical_device);
        }

        std::vector<std::string>* extensions = nullptr;
        if (loading_trim_state_ && CheckTrimDeviceExtensions(physical_device, &extensions))
        {
            std::vector<const char*> modified_extensions;
            VkDeviceCreateInfo       modified_create_info{};

            if (replay_create_info != nullptr)
            {
                if (replay_create_info->ppEnabledExtensionNames)
                {
                    modified_extensions.insert(
                        modified_extensions.begin(),
                        replay_create_info->ppEnabledExtensionNames,
                        (replay_create_info->ppEnabledExtensionNames + replay_create_info->enabledExtensionCount));
                }

                for (const auto& extension : *extensions)
                {
                    if (std::find(modified_extensions.begin(), modified_extensions.end(), extension) ==
                        modified_extensions.end())
                    {
                        modified_extensions.push_back(extension.c_str());
                    }
                }

                modified_create_info                         = (*replay_create_info);
                modified_create_info.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
                modified_create_info.ppEnabledExtensionNames = modified_extensions.data();
            }
            else
            {
                GFXRECON_LOG_WARNING("The vkCreateDevice parameter pCreateInfo is NULL.");
            }

            result = create_device_proc(
                physical_device, &modified_create_info, GetAllocationCallbacks(pAllocator), replay_device);
        }
        else
        {
            result = create_device_proc(
                physical_device, replay_create_info, GetAllocationCallbacks(pAllocator), replay_device);
        }

        if ((replay_device != nullptr) && (result == VK_SUCCESS))
        {
            AddDeviceTable(*replay_device, get_device_proc_addr);
            device_parents_[*replay_device] = physical_device;
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideEnumeratePhysicalDevices(PFN_vkEnumeratePhysicalDevices          func,
                                                           VkResult                                original_result,
                                                           const InstanceInfo*                     instance_info,
                                                           PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                           HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pPhysicalDeviceCount != nullptr) &&
           (pPhysicalDeviceCount->GetPointer() != nullptr) && (pPhysicalDevices != nullptr));

    VkInstance        instance            = instance_info->handle;
    uint32_t          replay_device_count = (*pPhysicalDeviceCount->GetPointer());
    VkPhysicalDevice* replay_devices      = pPhysicalDevices->GetHandlePointer();

    VkResult result = func(instance, &replay_device_count, replay_devices);

    if ((result >= 0) && (replay_devices != nullptr) && (instance_devices_.find(instance) == instance_devices_.end()))
    {
        InstanceDevices         devices;
        uint32_t                capture_device_count = (*pPhysicalDeviceCount->GetPointer());
        const format::HandleId* capture_devices      = pPhysicalDevices->GetPointer();

        for (uint32_t i = 0; i < capture_device_count; ++i)
        {
            devices.capture_devices.push_back(capture_devices[i]);
        }

        for (uint32_t i = 0; i < replay_device_count; ++i)
        {
            devices.replay_devices.push_back(replay_devices[i]);
        }

        instance_devices_.emplace(instance, devices);
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties(
    PFN_vkGetPhysicalDeviceProperties                         func,
    const PhysicalDeviceInfo*                                 physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    assert((physical_device_info != nullptr) && (pProperties != nullptr) && (pProperties->GetPointer() != nullptr) &&
           (pProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    ProcessPhysicalDeviceProperties(physical_device, pProperties->GetPointer(), replay_properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties2(
    PFN_vkGetPhysicalDeviceProperties2                         func,
    const PhysicalDeviceInfo*                                  physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    assert((physical_device_info != nullptr) && (pProperties != nullptr) && (pProperties->GetPointer() != nullptr) &&
           (pProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    auto capture_properties = pProperties->GetPointer();
    ProcessPhysicalDeviceProperties(physical_device, &capture_properties->properties, &replay_properties->properties);
}

void VulkanReplayConsumerBase::OverrideGetPhysicalDeviceProperties2KHR(
    PFN_vkGetPhysicalDeviceProperties2KHR                         func,
    const PhysicalDeviceInfo*                                     physical_device_info,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2KHR>* pProperties)
{
    assert((physical_device_info != nullptr) && (pProperties != nullptr) && (pProperties->GetPointer() != nullptr) &&
           (pProperties->GetOutputPointer() != nullptr));

    VkPhysicalDevice physical_device   = physical_device_info->handle;
    auto             replay_properties = pProperties->GetOutputPointer();

    func(physical_device, replay_properties);

    auto capture_properties = pProperties->GetPointer();
    ProcessPhysicalDeviceProperties(physical_device, &capture_properties->properties, &replay_properties->properties);
}

VkResult VulkanReplayConsumerBase::OverrideWaitForFences(PFN_vkWaitForFences                  func,
                                                         VkResult                             original_result,
                                                         const DeviceInfo*                    device_info,
                                                         uint32_t                             fenceCount,
                                                         const HandlePointerDecoder<VkFence>& pFences,
                                                         VkBool32                             waitAll,
                                                         uint64_t                             timeout)
{
    assert(device_info != nullptr);

    VkResult result;
    VkDevice device = device_info->handle;

    if (original_result == VK_SUCCESS)
    {
        // Ensure that wait for fences waits until the fences have been signaled (or error occurs) by changing the
        // timeout to UINT64_MAX.
        result = func(device, fenceCount, pFences.GetHandlePointer(), waitAll, std::numeric_limits<uint64_t>::max());
    }
    else if (original_result == VK_TIMEOUT)
    {
        // Try to get a timeout result with a 0 timeout.
        result = func(device, fenceCount, pFences.GetHandlePointer(), waitAll, 0);
    }
    else
    {
        result = func(device, fenceCount, pFences.GetHandlePointer(), waitAll, timeout);
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetFenceStatus(PFN_vkGetFenceStatus func,
                                                          VkResult             original_result,
                                                          const DeviceInfo*    device_info,
                                                          const FenceInfo*     fence_info)
{
    assert((device_info != nullptr) && (fence_info != nullptr));

    VkResult result;
    VkDevice device = device_info->handle;
    VkFence  fence  = fence_info->handle;

    do
    {
        result = func(device, fence);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetEventStatus(PFN_vkGetEventStatus func,
                                                          VkResult             original_result,
                                                          const DeviceInfo*    device_info,
                                                          const EventInfo*     event_info)
{
    assert((device_info != nullptr) && (event_info != nullptr));

    VkResult result;
    VkDevice device = device_info->handle;
    VkEvent  event  = event_info->handle;

    do
    {
        result = func(device, event);
    } while ((original_result == VK_EVENT_SET) && (result == VK_EVENT_RESET));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideGetQueryPoolResults(PFN_vkGetQueryPoolResults func,
                                                               VkResult                  original_result,
                                                               const DeviceInfo*         device_info,
                                                               const QueryPoolInfo*      query_pool_info,
                                                               uint32_t                  firstQuery,
                                                               uint32_t                  queryCount,
                                                               size_t                    dataSize,
                                                               PointerDecoder<uint8_t>*  pData,
                                                               VkDeviceSize              stride,
                                                               VkQueryResultFlags        flags)
{
    assert((device_info != nullptr) && (query_pool_info != nullptr) && (pData != nullptr) &&
           (pData->GetOutputPointer() != nullptr));

    VkResult    result;
    VkDevice    device     = device_info->handle;
    VkQueryPool query_pool = query_pool_info->handle;

    do
    {
        result = func(device, query_pool, firstQuery, queryCount, dataSize, pData->GetOutputPointer(), stride, flags);
    } while ((original_result == VK_SUCCESS) && (result == VK_NOT_READY));

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateCommandBuffers(
    PFN_vkAllocateCommandBuffers                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                           pCommandBuffers)
{
    assert((device_info != nullptr) && (pCommandBuffers != nullptr) &&
           (pCommandBuffers->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device_info->handle, pAllocateInfo.GetPointer(), pCommandBuffers->GetHandlePointer());
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateCommandBuffers call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateDescriptorSets(
    PFN_vkAllocateDescriptorSets                                     func,
    VkResult                                                         original_result,
    const DeviceInfo*                                                device_info,
    const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                           pDescriptorSets)
{
    assert((device_info != nullptr) && (pDescriptorSets != nullptr) &&
           (pDescriptorSets->GetHandlePointer() != nullptr));

    VkResult result = original_result;

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        result = func(device_info->handle, pAllocateInfo.GetPointer(), pDescriptorSets->GetHandlePointer());
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateDescriptorSets call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAllocateMemory(
    PFN_vkAllocateMemory                                       func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>&  pAllocateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*                      pMemory)
{
    assert((device_info != nullptr) && (pMemory != nullptr) && (pMemory->GetHandlePointer() != nullptr));

    VkResult                    result               = original_result;
    const VkMemoryAllocateInfo* replay_allocate_info = pAllocateInfo.GetPointer();

    if ((original_result >= 0) || !options_.skip_failed_allocations)
    {
        VkDevice device        = device_info->handle;
        auto     replay_memory = pMemory->GetHandlePointer();

        result = func(device, replay_allocate_info, GetAllocationCallbacks(pAllocator), replay_memory);

        if ((result == VK_SUCCESS) && (replay_allocate_info != nullptr) && ((*replay_memory) != VK_NULL_HANDLE))
        {
            VkPhysicalDevice physical_device = device_parents_[device];
            assert(physical_device != VK_NULL_HANDLE);

            auto table = GetInstanceTable(physical_device);
            assert(table != nullptr);

            // TODO: Store memory properties with physical device handle to avoid multiple property queries.
            VkPhysicalDeviceMemoryProperties properties;
            table->GetPhysicalDeviceMemoryProperties(physical_device, &properties);

            assert(replay_allocate_info->memoryTypeIndex < properties.memoryTypeCount);
            memory_properties_[*replay_memory] =
                properties.memoryTypes[replay_allocate_info->memoryTypeIndex].propertyFlags;
        }
    }
    else
    {
        GFXRECON_LOG_INFO("Skipping vkAllocateMemory call that failed during capture with error %s",
                          enumutil::GetResultValueString(original_result));
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideMapMemory(PFN_vkMapMemory         func,
                                                     VkResult                original_result,
                                                     const DeviceInfo*       device_info,
                                                     const DeviceMemoryInfo* memory_info,
                                                     VkDeviceSize            offset,
                                                     VkDeviceSize            size,
                                                     VkMemoryMapFlags        flags,
                                                     void**                  ppData)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (memory_info != nullptr));

    VkDevice       device = device_info->handle;
    VkDeviceMemory memory = memory_info->handle;

    VkResult result = func(device, memory, offset, size, flags, ppData);

    if ((result == VK_SUCCESS) && (ppData != nullptr) && ((*ppData) != nullptr))
    {
        memory_map_.insert(std::make_pair(memory, *ppData));
    }

    return result;
}

void VulkanReplayConsumerBase::OverrideUnmapMemory(PFN_vkUnmapMemory       func,
                                                   const DeviceInfo*       device_info,
                                                   const DeviceMemoryInfo* memory_info)
{
    assert((device_info != nullptr) && (memory_info != nullptr));

    VkDevice       device = device_info->handle;
    VkDeviceMemory memory = memory_info->handle;

    memory_map_.erase(memory);

    func(device, memory);
}

void VulkanReplayConsumerBase::OverrideFreeMemory(PFN_vkFreeMemory        func,
                                                  const DeviceInfo*       device_info,
                                                  const DeviceMemoryInfo* memory_info,
                                                  const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    assert(device_info != nullptr);

    VkDevice       device = device_info->handle;
    VkDeviceMemory memory = VK_NULL_HANDLE;

    if (memory_info != nullptr)
    {
        memory = memory_info->handle;
    }

    memory_map_.erase(memory);

    func(device, memory, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideBindBufferMemory(PFN_vkBindBufferMemory  func,
                                                            VkResult                original_result,
                                                            const DeviceInfo*       device_info,
                                                            const BufferInfo*       buffer_info,
                                                            const DeviceMemoryInfo* memory_info,
                                                            VkDeviceSize            memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (buffer_info != nullptr) && (memory_info != nullptr));

    VkDevice       device = device_info->handle;
    VkBuffer       buffer = buffer_info->handle;
    VkDeviceMemory memory = memory_info->handle;

    VkResult result = func(device, buffer, memory, memoryOffset);

    if (result == VK_SUCCESS)
    {
        BufferProperties& info     = buffer_info_[buffer];
        info.memory                = memory;
        info.memory_property_flags = memory_properties_[memory];
        info.bind_offset           = memoryOffset;
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindBufferMemory2(
    PFN_vkBindBufferMemory2                                     func,
    VkResult                                                    original_result,
    const DeviceInfo*                                           device_info,
    uint32_t                                                    bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert(device_info != nullptr);

    const VkBindBufferMemoryInfo* replay_bind_info = pBindInfos.GetPointer();

    VkResult result = func(device_info->handle, bindInfoCount, replay_bind_info);

    if ((result == VK_SUCCESS) && (replay_bind_info != nullptr))
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            const VkBindBufferMemoryInfo* bind_info = &replay_bind_info[i];

            BufferProperties& info     = buffer_info_[bind_info->buffer];
            info.memory                = bind_info->memory;
            info.memory_property_flags = memory_properties_[bind_info->memory];
            info.bind_offset           = bind_info->memoryOffset;
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindImageMemory(PFN_vkBindImageMemory   func,
                                                           VkResult                original_result,
                                                           const DeviceInfo*       device_info,
                                                           const ImageInfo*        image_info,
                                                           const DeviceMemoryInfo* memory_info,
                                                           VkDeviceSize            memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (image_info != nullptr) && (memory_info != nullptr));

    VkDevice       device = device_info->handle;
    VkImage        image  = image_info->handle;
    VkDeviceMemory memory = memory_info->handle;

    VkResult result = func(device, image, memory, memoryOffset);

    if (result == VK_SUCCESS)
    {
        ImageProperties& info      = image_info_[image];
        info.memory                = memory;
        info.memory_property_flags = memory_properties_[memory];
        info.bind_offset           = memoryOffset;
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideBindImageMemory2(
    PFN_vkBindImageMemory2                                     func,
    VkResult                                                   original_result,
    const DeviceInfo*                                          device_info,
    uint32_t                                                   bindInfoCount,
    const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert(device_info != nullptr);

    const VkBindImageMemoryInfo* replay_bind_info = pBindInfos.GetPointer();

    VkResult result = func(device_info->handle, bindInfoCount, replay_bind_info);

    if ((result == VK_SUCCESS) && (replay_bind_info != nullptr))
    {
        for (uint32_t i = 0; i < bindInfoCount; ++i)
        {
            const VkBindImageMemoryInfo* bind_info = &replay_bind_info[i];

            ImageProperties& info      = image_info_[bind_info->image];
            info.memory                = bind_info->memory;
            info.memory_property_flags = memory_properties_[bind_info->memory];
            info.bind_offset           = bind_info->memoryOffset;
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateBuffer(PFN_vkCreateBuffer                                      func,
                                               VkResult                                                original_result,
                                               const DeviceInfo*                                       device_info,
                                               const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
                                               const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                               HandlePointerDecoder<VkBuffer>*                            pBuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pBuffer != nullptr) && (pBuffer->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();
    auto replay_buffer      = pBuffer->GetHandlePointer();

    VkResult result = func(device_info->handle, replay_create_info, GetAllocationCallbacks(pAllocator), replay_buffer);

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_buffer) != VK_NULL_HANDLE))
    {
        BufferProperties& info = buffer_info_[*replay_buffer];
        info.usage             = replay_create_info->usage;

        if ((replay_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            info.queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            info.queue_family_index = 0;
        }
    }

    return result;
}

VkResult
VulkanReplayConsumerBase::OverrideCreateImage(PFN_vkCreateImage                                      func,
                                              VkResult                                               original_result,
                                              const DeviceInfo*                                      device_info,
                                              const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
                                              const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
                                              HandlePointerDecoder<VkImage>*                             pImage)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pImage != nullptr) && (pImage->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();
    auto replay_image       = pImage->GetHandlePointer();

    VkResult result = func(device_info->handle, replay_create_info, GetAllocationCallbacks(pAllocator), replay_image);

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_image) != VK_NULL_HANDLE))
    {
        ImageProperties& info = image_info_[*replay_image];
        info.usage            = replay_create_info->usage;
        info.type             = replay_create_info->imageType;
        info.format           = replay_create_info->format;
        info.extent           = replay_create_info->extent;
        info.tiling           = replay_create_info->tiling;
        info.sample_count     = replay_create_info->samples;
        info.initial_layout   = replay_create_info->initialLayout;
        info.layer_count      = replay_create_info->arrayLayers;
        info.level_count      = replay_create_info->mipLevels;

        if ((replay_create_info->sharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            info.queue_family_index = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            info.queue_family_index = 0;
        }
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateDescriptorUpdateTemplate(
    PFN_vkCreateDescriptorUpdateTemplate                                      func,
    VkResult                                                                  original_result,
    const DeviceInfo*                                                         device_info,
    const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&                pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>*                         pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pDescriptorUpdateTemplate != nullptr) &&
           (pDescriptorUpdateTemplate->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();

    if (replay_create_info != nullptr)
    {
        // Modify the layout of the update template entries to match the tight packing performed by the trace encoding.
        // The trace encoding wrote the update template entries as a tightly packed array of VkDescriptorImageInfo
        // values, followed by an array of VkDescriptorBufferInfo values, followed by an array of VkBufferView values.
        VkDescriptorUpdateTemplateCreateInfo override_create_info = (*replay_create_info);

        std::vector<VkDescriptorUpdateTemplateEntry> entries(
            override_create_info.pDescriptorUpdateEntries,
            (override_create_info.pDescriptorUpdateEntries + override_create_info.descriptorUpdateEntryCount));

        // Count the number of values of each type.
        size_t image_info_count        = 0;
        size_t buffer_info_count       = 0;
        size_t texel_buffer_view_count = 0;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                buffer_info_count += entry->descriptorCount;
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                texel_buffer_view_count += entry->descriptorCount;
            }
            else
            {
                assert(false);
            }
        }

        // Compute start offsets for each type.
        size_t image_info_offset        = 0;
        size_t buffer_info_offset       = image_info_count * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count * sizeof(VkDescriptorBufferInfo));

        // Track descriptor image type.
        DescriptorImageTypes image_types;

        for (auto entry = entries.begin(); entry != entries.end(); ++entry)
        {
            VkDescriptorType type = entry->descriptorType;

            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                image_types.insert(image_types.end(), entry->descriptorCount, entry->descriptorType);

                entry->stride = sizeof(VkDescriptorImageInfo);
                entry->offset = image_info_offset;
                image_info_offset += entry->descriptorCount * sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                entry->stride = sizeof(VkDescriptorBufferInfo);
                entry->offset = buffer_info_offset;
                buffer_info_offset += entry->descriptorCount * sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                entry->stride = sizeof(VkBufferView);
                entry->offset = texel_buffer_view_offset;
                texel_buffer_view_offset += entry->descriptorCount * sizeof(VkBufferView);
            }
            else
            {
                assert(false);
            }
        }

        override_create_info.pDescriptorUpdateEntries = entries.data();

        auto replay_template = pDescriptorUpdateTemplate->GetHandlePointer();

        VkResult result =
            func(device_info->handle, &override_create_info, GetAllocationCallbacks(pAllocator), replay_template);

        if ((result == VK_SUCCESS) && ((*replay_template) != VK_NULL_HANDLE))
        {
            descriptor_update_template_image_types_.emplace(*replay_template, image_types);
        }

        return result;
    }
    else
    {
        return func(device_info->handle,
                    replay_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pDescriptorUpdateTemplate->GetHandlePointer());
    }
}

void VulkanReplayConsumerBase::OverrideDestroyDescriptorUpdateTemplate(
    PFN_vkDestroyDescriptorUpdateTemplate                      func,
    const DeviceInfo*                                          device_info,
    const DescriptorUpdateTemplateInfo*                        descriptor_update_template_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    assert(device_info != nullptr);

    VkDevice                   device                     = device_info->handle;
    VkDescriptorUpdateTemplate descriptor_update_template = VK_NULL_HANDLE;

    if (descriptor_update_template_info != nullptr)
    {
        descriptor_update_template = descriptor_update_template_info->handle;
    }

    descriptor_update_template_image_types_.erase(descriptor_update_template);

    func(device, descriptor_update_template, GetAllocationCallbacks(pAllocator));
}

VkResult VulkanReplayConsumerBase::OverrideCreatePipelineCache(
    PFN_vkCreatePipelineCache                                      func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&     pAllocator,
    HandlePointerDecoder<VkPipelineCache>*                         pPipelineCache)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pPipelineCache != nullptr) && (pPipelineCache->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();

    if (options_.omit_pipeline_cache_data && (replay_create_info != nullptr))
    {
        // Make a shallow copy of the create info structure and clear the cache data.
        VkPipelineCacheCreateInfo override_create_info = (*replay_create_info);
        override_create_info.initialDataSize           = 0;
        override_create_info.pInitialData              = nullptr;

        return func(device_info->handle,
                    &override_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
    else
    {
        return func(device_info->handle,
                    replay_create_info,
                    GetAllocationCallbacks(pAllocator),
                    pPipelineCache->GetHandlePointer());
    }
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugReportCallbackEXT(
    PFN_vkCreateDebugReportCallbackEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&              pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>*                         pCallback)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pCallback != nullptr) && (pCallback->GetHandlePointer() != nullptr));

    VkDebugReportCallbackCreateInfoEXT modified_create_info{};

    if (!pCreateInfo.IsNull())
    {
        modified_create_info             = (*pCreateInfo.GetPointer());
        modified_create_info.pfnCallback = DebugReportCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugReportCallbackEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pCallback->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateDebugUtilsMessengerEXT(
    PFN_vkCreateDebugUtilsMessengerEXT                                      func,
    VkResult                                                                original_result,
    const InstanceInfo*                                                     instance_info,
    const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&              pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>*                         pMessenger)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((instance_info != nullptr) && (pMessenger != nullptr) && (pMessenger->GetHandlePointer() != nullptr));

    VkDebugUtilsMessengerCreateInfoEXT modified_create_info{};
    if (!pCreateInfo.IsNull())
    {
        modified_create_info                 = (*pCreateInfo.GetPointer());
        modified_create_info.pfnUserCallback = DebugUtilsCallback;
    }
    else
    {
        GFXRECON_LOG_WARNING("The vkCreateDebugUtilsMessengerEXT parameter pCreateInfo is NULL.");
    }

    return func(instance_info->handle,
                &modified_create_info,
                GetAllocationCallbacks(pAllocator),
                pMessenger->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateSwapchainKHR(
    PFN_vkCreateSwapchainKHR                                      func,
    VkResult                                                      original_result,
    const DeviceInfo*                                             device_info,
    const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&    pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*                         pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pSwapchain != nullptr) && (pSwapchain->GetHandlePointer() != nullptr));

    auto replay_create_info = pCreateInfo.GetPointer();
    auto replay_swapchain   = pSwapchain->GetHandlePointer();

    VkResult result =
        func(device_info->handle, replay_create_info, GetAllocationCallbacks(pAllocator), replay_swapchain);

    if ((result == VK_SUCCESS) && (replay_create_info != nullptr) && ((*replay_swapchain) != VK_NULL_HANDLE))
    {
        if ((replay_create_info->imageSharingMode == VK_SHARING_MODE_CONCURRENT) &&
            (replay_create_info->queueFamilyIndexCount > 0) && (replay_create_info->pQueueFamilyIndices != nullptr))
        {
            swapchain_queue_families_[*replay_swapchain] = replay_create_info->pQueueFamilyIndices[0];
        }
        else
        {
            swapchain_queue_families_[*replay_swapchain] = 0;
        }

        swapchain_surfaces_[*replay_swapchain] = replay_create_info->surface;
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                               VkResult                  original_result,
                                                               const DeviceInfo*         device_info,
                                                               const SwapchainKHRInfo*   swapchain_info,
                                                               uint64_t                  timeout,
                                                               const SemaphoreInfo*      semaphore_info,
                                                               const FenceInfo*          fence_info,
                                                               PointerDecoder<uint32_t>* pImageIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (swapchain_info != nullptr) && (pImageIndex != nullptr) &&
           (pImageIndex->GetPointer() != nullptr));

    VkResult       result               = VK_SUCCESS;
    VkDevice       device               = device_info->handle;
    VkSwapchainKHR swapchain            = swapchain_info->handle;
    VkSemaphore    semaphore            = (semaphore_info != nullptr) ? semaphore_info->handle : VK_NULL_HANDLE;
    VkFence        fence                = (fence_info != nullptr) ? fence_info->handle : VK_NULL_HANDLE;
    VkSemaphore    preacquire_semaphore = VK_NULL_HANDLE;
    VkFence        preacquire_fence     = VK_NULL_HANDLE;
    uint32_t       captured_index       = (*pImageIndex->GetPointer());

    if (swapchain_image_tracker_.RetrievePreAcquiredImage(
            swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
    {
        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        // The image has already been acquired. Swap the synchronization objects.
        if (semaphore != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the semaphore can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceSemaphore(semaphore, preacquire_semaphore);
            preacquire_semaphore = semaphore;
        }

        if (fence != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the fence can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceFence(fence, preacquire_fence);
            preacquire_fence = fence;
        }

        table->DestroySemaphore(device, preacquire_semaphore, nullptr);
        table->DestroyFence(device, preacquire_fence, nullptr);
    }
    else
    {
        assert(pImageIndex->GetOutputPointer() != nullptr);

        result = func(device, swapchain, timeout, semaphore, fence, pImageIndex->GetOutputPointer());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideAcquireNextImage2KHR(
    PFN_vkAcquireNextImage2KHR                                     func,
    VkResult                                                       original_result,
    const DeviceInfo*                                              device_info,
    const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
    PointerDecoder<uint32_t>*                                      pImageIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(original_result);

    assert((device_info != nullptr) && (pAcquireInfo.GetPointer() != nullptr) && (pImageIndex != nullptr) &&
           (pImageIndex->GetPointer() != nullptr));

    VkResult    result               = VK_SUCCESS;
    VkDevice    device               = device_info->handle;
    VkSemaphore preacquire_semaphore = VK_NULL_HANDLE;
    VkFence     preacquire_fence     = VK_NULL_HANDLE;
    auto        replay_acquire_info  = pAcquireInfo.GetPointer();
    uint32_t    captured_index       = (*pImageIndex->GetPointer());

    if (swapchain_image_tracker_.RetrievePreAcquiredImage(
            replay_acquire_info->swapchain, captured_index, &preacquire_semaphore, &preacquire_fence))
    {
        auto table = GetDeviceTable(device);
        assert(table != nullptr);

        // The image has already been acquired. Swap the synchronization objects.
        if (replay_acquire_info->semaphore != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the semaphore can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceSemaphore(replay_acquire_info->semaphore, preacquire_semaphore);
            preacquire_semaphore = replay_acquire_info->semaphore;
        }

        if (replay_acquire_info->fence != VK_NULL_HANDLE)
        {
            // TODO: This should be processed at a higher level where the original handle IDs are available, so that the
            // swap can be performed with the original handle ID and the fence can be guaranteed not to be used
            // after destroy.
            object_info_table_.ReplaceFence(replay_acquire_info->fence, preacquire_fence);
            preacquire_fence = replay_acquire_info->fence;
        }

        table->DestroySemaphore(device, preacquire_semaphore, nullptr);
        table->DestroyFence(device, preacquire_fence, nullptr);
    }
    else
    {
        assert(pImageIndex->GetOutputPointer() != nullptr);

        result = func(device, replay_acquire_info, pImageIndex->GetOutputPointer());
    }

    return result;
}

VkResult VulkanReplayConsumerBase::OverrideCreateAndroidSurfaceKHR(
    PFN_vkCreateAndroidSurfaceKHR                                      func,
    VkResult                                                           original_result,
    const InstanceInfo*                                                instance_info,
    const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(instance_info != nullptr);

    auto replay_create_info = pCreateInfo.GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info->handle, replay_create_info->flags, pSurface->GetHandlePointer());
}

VkResult VulkanReplayConsumerBase::OverrideCreateWin32SurfaceKHR(
    PFN_vkCreateWin32SurfaceKHR                                      func,
    VkResult                                                         original_result,
    const InstanceInfo*                                              instance_info,
    const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&       pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                              pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(instance_info != nullptr);

    auto replay_create_info = pCreateInfo.GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info->handle, replay_create_info->flags, pSurface->GetHandlePointer());
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWin32PresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR func,
    const PhysicalDeviceInfo*                          physical_device_info,
    uint32_t                                           queueFamilyIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateXcbSurfaceKHR(
    PFN_vkCreateXcbSurfaceKHR                                      func,
    VkResult                                                       original_result,
    const InstanceInfo*                                            instance_info,
    const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&     pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                            pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(instance_info != nullptr);

    auto replay_create_info = pCreateInfo.GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info->handle, replay_create_info->flags, pSurface->GetHandlePointer());
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXcbPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR func,
    const PhysicalDeviceInfo*                        physical_device_info,
    uint32_t                                         queueFamilyIndex,
    xcb_connection_t*                                connection,
    xcb_visualid_t                                   visual_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(connection);
    GFXRECON_UNREFERENCED_PARAMETER(visual_id);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateXlibSurfaceKHR(
    PFN_vkCreateXlibSurfaceKHR                                      func,
    VkResult                                                        original_result,
    const InstanceInfo*                                             instance_info,
    const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&      pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                             pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(instance_info != nullptr);

    auto replay_create_info = pCreateInfo.GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info->handle, replay_create_info->flags, pSurface->GetHandlePointer());
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceXlibPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR func,
    const PhysicalDeviceInfo*                         physical_device_info,
    uint32_t                                          queueFamilyIndex,
    Display*                                          dpy,
    VisualID                                          visualID)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(dpy);
    GFXRECON_UNREFERENCED_PARAMETER(visualID);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

VkResult VulkanReplayConsumerBase::OverrideCreateWaylandSurfaceKHR(
    PFN_vkCreateWaylandSurfaceKHR                                      func,
    VkResult                                                           original_result,
    const InstanceInfo*                                                instance_info,
    const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>&         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                                pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(original_result);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    assert(instance_info != nullptr);

    auto replay_create_info = pCreateInfo.GetPointer();

    assert((replay_create_info != nullptr) && (pSurface != nullptr) && (pSurface->GetHandlePointer() != nullptr));

    return CreateSurface(instance_info->handle, replay_create_info->flags, pSurface->GetHandlePointer());
}

VkBool32 VulkanReplayConsumerBase::OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(
    PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR func,
    const PhysicalDeviceInfo*                            physical_device_info,
    uint32_t                                             queueFamilyIndex,
    struct wl_display*                                   display)
{
    GFXRECON_UNREFERENCED_PARAMETER(func);
    GFXRECON_UNREFERENCED_PARAMETER(display);

    assert(physical_device_info != nullptr);

    VkPhysicalDevice physical_device = physical_device_info->handle;

    return window_factory_->GetPhysicalDevicePresentationSupport(
        GetInstanceTable(physical_device), physical_device, queueFamilyIndex);
}

void VulkanReplayConsumerBase::OverrideDestroySurfaceKHR(
    PFN_vkDestroySurfaceKHR                                    func,
    const InstanceInfo*                                        instance_info,
    const SurfaceKHRInfo*                                      surface_info,
    const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator)
{
    assert(instance_info != nullptr);

    VkInstance   instance = instance_info->handle;
    VkSurfaceKHR surface  = VK_NULL_HANDLE;

    if (surface_info != nullptr)
    {
        surface = surface_info->handle;
    }

    func(instance, surface, GetAllocationCallbacks(pAllocator));

    if (surface != VK_NULL_HANDLE)
    {
        auto entry = window_map_.find(surface);

        if (entry != window_map_.end())
        {
            window_factory_->Destroy(entry->second);
            window_map_.erase(entry);
        }
    }
}

void VulkanReplayConsumerBase::MapDescriptorUpdateTemplateHandles(VkDescriptorUpdateTemplate update_template,
                                                                  const DescriptorUpdateTemplateDecoder& decoder)
{
    size_t image_info_count        = decoder.GetImageInfoCount();
    size_t buffer_info_count       = decoder.GetBufferInfoCount();
    size_t texel_buffer_view_count = decoder.GetTexelBufferViewCount();

    if (image_info_count > 0)
    {
        auto image_types_iter = descriptor_update_template_image_types_.find(update_template);
        if (image_types_iter != descriptor_update_template_image_types_.end())
        {
            Decoded_VkDescriptorImageInfo* structs = decoder.GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(image_types_iter->second[i], &structs[i], object_info_table_);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Missing descriptor update template image descriptor type info; attempting to map both "
                               "VkDescriptorImageInfo handles");

            Decoded_VkDescriptorImageInfo* structs = decoder.GetImageInfoMetaStructPointer();
            for (size_t i = 0; i < image_info_count; ++i)
            {
                MapStructHandles(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &structs[i], object_info_table_);
            }
        }
    }

    if (buffer_info_count > 0)
    {
        MapStructArrayHandles(decoder.GetBufferInfoMetaStructPointer(), buffer_info_count, object_info_table_);
    }

    if (texel_buffer_view_count > 0)
    {
        MapHandles<BufferViewInfo>(decoder.GetTexelBufferViewHandleIdsPointer(),
                                   texel_buffer_view_count,
                                   decoder.GetTexelBufferViewPointer(),
                                   texel_buffer_view_count,
                                   &VulkanObjectInfoTable::GetBufferViewInfo);
    }
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(format::HandleId device,
                                                                         format::HandleId descriptorSet,
                                                                         format::HandleId descriptorUpdateTemplate,
                                                                         const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = MapHandle<DescriptorUpdateTemplateInfo>(
        descriptorUpdateTemplate, &VulkanObjectInfoTable::GetDescriptorUpdateTemplateInfo);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplate(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    format::HandleId                       commandBuffer,
    format::HandleId                       descriptorUpdateTemplate,
    format::HandleId                       layout,
    uint32_t                               set,
    const DescriptorUpdateTemplateDecoder& pData)
{
    VkCommandBuffer in_commandBuffer =
        MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = MapHandle<DescriptorUpdateTemplateInfo>(
        descriptorUpdateTemplate, &VulkanObjectInfoTable::GetDescriptorUpdateTemplateInfo);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_commandBuffer)
        ->CmdPushDescriptorSetWithTemplateKHR(
            in_commandBuffer, in_descriptorUpdateTemplate, in_layout, set, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    format::HandleId                       device,
    format::HandleId                       descriptorSet,
    format::HandleId                       descriptorUpdateTemplate,
    const DescriptorUpdateTemplateDecoder& pData)
{
    VkDevice        in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet =
        MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    VkDescriptorUpdateTemplate in_descriptorUpdateTemplate = MapHandle<DescriptorUpdateTemplateInfo>(
        descriptorUpdateTemplate, &VulkanObjectInfoTable::GetDescriptorUpdateTemplateInfo);

    MapDescriptorUpdateTemplateHandles(in_descriptorUpdateTemplate, pData);

    GetDeviceTable(in_device)->UpdateDescriptorSetWithTemplateKHR(
        in_device, in_descriptorSet, in_descriptorUpdateTemplate, pData.GetPointer());
}

void VulkanReplayConsumerBase::Process_vkRegisterObjectsNVX(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    format::HandleId                                           objectTable,
    uint32_t                                                   objectCount,
    const StructPointerDecoder<Decoded_VkObjectTableEntryNVX>& ppObjectTableEntries,
    const PointerDecoder<uint32_t>&                            pObjectIndices)
{
    VkDevice         in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkObjectTableNVX in_objectTable =
        MapHandle<ObjectTableNVXInfo>(objectTable, &VulkanObjectInfoTable::GetObjectTableNVXInfo);
    const uint32_t* in_pObjectIndices = reinterpret_cast<const uint32_t*>(pObjectIndices.GetPointer());

    assert(objectCount == ppObjectTableEntries.GetLength());

    VkObjectTableEntryNVX**         in_ppObjectTableEntries         = ppObjectTableEntries.GetPointer();
    Decoded_VkObjectTableEntryNVX** in_ppObjectTableEntries_wrapper = ppObjectTableEntries.GetMetaStructPointer();

    // Map the object table entry handles.
    if ((in_ppObjectTableEntries != nullptr) && (in_ppObjectTableEntries_wrapper != nullptr))
    {
        for (size_t i = 0; i < objectCount; ++i)
        {
            if (in_ppObjectTableEntries[i] != nullptr)
            {
                VkObjectEntryTypeNVX type = in_ppObjectTableEntries[i]->type;

                if (type == VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTableDescriptorSetEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_info_table_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX)
                {
                    MapStructHandles(
                        reinterpret_cast<Decoded_VkObjectTablePipelineEntryNVX*>(in_ppObjectTableEntries_wrapper[i]),
                        object_info_table_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX)
                {
                    MapStructHandles(
                        reinterpret_cast<Decoded_VkObjectTableIndexBufferEntryNVX*>(in_ppObjectTableEntries_wrapper[i]),
                        object_info_table_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTableVertexBufferEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_info_table_);
                }
                else if (type == VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX)
                {
                    MapStructHandles(reinterpret_cast<Decoded_VkObjectTablePushConstantEntryNVX*>(
                                         in_ppObjectTableEntries_wrapper[i]),
                                     object_info_table_);
                }
                else
                {
                    assert(true);
                    GFXRECON_LOG_ERROR("Skipping entry with unrecognized type at ppObjectTableEntries[%d] when "
                                       "processing vkRegisterObjectsNVX",
                                       i);
                }
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "Skipping null entry at ppObjectTableEntries[%d] when processing vkRegisterObjectsNVX", i);
            }
        }
    }

    VkResult replay_result = GetDeviceTable(in_device)->RegisterObjectsNVX(
        in_device, in_objectTable, objectCount, in_ppObjectTableEntries, in_pObjectIndices);

    CheckResult("vkRegisterObjectsNVX", returnValue, replay_result);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
