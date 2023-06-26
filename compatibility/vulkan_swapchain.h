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

#ifndef GFXRECON_COMPATIBILITY_VULKAN_SWAPCHAIN_H
#define GFXRECON_COMPATIBILITY_VULKAN_SWAPCHAIN_H

#include <cinttypes>
#include <cstdint>
#include <cstring>
#include <unordered_map>
#include <vector>

#include "vulkan/vulkan.h"

namespace gfxrecon
{
namespace compatibility
{

// Defines for logging functions
typedef void (*LogFunctionPointer)(const char* message, ...);

// Defines for callback functions required to allocate/bind/free resources
typedef VkResult (*pfnCreateImageResource)(void*                        allocator_class,
                                           const VkImageCreateInfo*     create_info,
                                           const VkAllocationCallbacks* allocation_callbacks,
                                           VkImage*                     image,
                                           uintptr_t*                   resource_id);
typedef void (*pfnDestroyImageResource)(void*                        allocator_class,
                                        VkImage                      image,
                                        const VkAllocationCallbacks* allocation_callbacks,
                                        uintptr_t                    resource_id);
typedef VkResult (*pfnAllocateDeviceMemoryResource)(void*                        allocator_class,
                                                    const VkMemoryAllocateInfo*  allocate_info,
                                                    const VkAllocationCallbacks* allocation_callbacks,
                                                    VkDeviceMemory*              memory,
                                                    uintptr_t*                   resource_id);
typedef void (*pfnFreeDeviceMemoryResource)(void*                        allocator_class,
                                            VkDeviceMemory               memory,
                                            const VkAllocationCallbacks* allocation_callbacks,
                                            uintptr_t                    resource_id);
typedef VkResult (*pfnBindImageResourceToDeviceMemoryResource)(void*                  allocator_class,
                                                               VkImage                image,
                                                               VkDeviceMemory         memory,
                                                               VkDeviceSize           memory_offset,
                                                               uintptr_t              image_resource_id,
                                                               uintptr_t              memory_resource_id,
                                                               VkMemoryPropertyFlags* bind_memory_properties);

// Resource allocator callback structure used to pass in and store all the necessary
// information to call back out into the replay tool for handling memory.
struct ResourceAllocatorCallbacks
{
    void*                                      allocator_class;
    pfnCreateImageResource                     create_image_resource{ nullptr };
    pfnDestroyImageResource                    destroy_image_resource{ nullptr };
    pfnAllocateDeviceMemoryResource            allocate_device_memory_resource{ nullptr };
    pfnFreeDeviceMemoryResource                free_device_memory_resource{ nullptr };
    pfnBindImageResourceToDeviceMemoryResource bind_image_resource_to_device_resource{ nullptr };

    ResourceAllocatorCallbacks& operator=(const ResourceAllocatorCallbacks& source)
    {
        allocator_class                        = source.allocator_class;
        create_image_resource                  = source.create_image_resource;
        destroy_image_resource                 = source.destroy_image_resource;
        allocate_device_memory_resource        = source.allocate_device_memory_resource;
        free_device_memory_resource            = source.free_device_memory_resource;
        bind_image_resource_to_device_resource = source.bind_image_resource_to_device_resource;
        return *this;
    }
};

struct FunctionPointerTable
{
    PFN_vkGetPhysicalDeviceMemoryProperties       pfnGetPhysicalDeviceMemoryProperties;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR pfnGetPhysicalDeviceSurfaceCapabilitiesKHR;
    PFN_vkGetImageMemoryRequirements              pfnGetImageMemoryRequirements;
    PFN_vkGetDeviceQueue                          pfnGetDeviceQueue;
    PFN_vkGetDeviceQueue2                         pfnGetDeviceQueue2;
    PFN_vkCreateCommandPool                       pfnCreateCommandPool;
    PFN_vkDestroyCommandPool                      pfnDestroyCommandPool;
    PFN_vkAllocateCommandBuffers                  pfnAllocateCommandBuffers;
    PFN_vkCreateFence                             pfnCreateFence;
    PFN_vkDestroyFence                            pfnDestroyFence;
    PFN_vkResetFences                             pfnResetFences;
    PFN_vkWaitForFences                           pfnWaitForFences;
    PFN_vkCreateSemaphore                         pfnCreateSemaphore;
    PFN_vkDestroySemaphore                        pfnDestroySemaphore;
    PFN_vkBeginCommandBuffer                      pfnBeginCommandBuffer;
    PFN_vkCmdPipelineBarrier                      pfnCmdPipelineBarrier;
    PFN_vkCmdBlitImage                            pfnCmdBlitImage;
    PFN_vkEndCommandBuffer                        pfnEndCommandBuffer;
    PFN_vkResetCommandBuffer                      pfnResetCommandBuffer;
    PFN_vkFreeCommandBuffers                      pfnFreeCommandBuffers;
    PFN_vkQueueSubmit                             pfnQueueSubmit;
    PFN_vkQueuePresentKHR                         pfnQueuePresentKHR;
    PFN_vkQueueWaitIdle                           pfnQueueWaitIdle;
    PFN_vkGetSwapchainImagesKHR                   pfnGetSwapchainImagesKHR;
    PFN_vkAcquireNextImageKHR                     pfnAcquireNextImageKHR;
};

// Internal structure for tracking data
struct AllocatedImageData
{
    VkImage        image{ VK_NULL_HANDLE };
    uint64_t       image_id{ 0ULL };
    uint32_t       image_layout{ 0 };
    bool           acquired{ false };
    VkDeviceMemory memory{ VK_NULL_HANDLE };
    uintptr_t      memory_resource_id{ 0 };
    uintptr_t      image_resource_id{ 0 };
};

struct SwapchainCreationInfo
{
    VkDevice                        device;
    const VkPhysicalDevice          physical_device;
    const VkSwapchainCreateInfoKHR* create_info;
    ResourceAllocatorCallbacks      resource_alloc_callbacks;
    uint64_t                        swapchain_capture_id;
    LogFunctionPointer              log_error;
    LogFunctionPointer              log_warning;
    LogFunctionPointer              log_info;
    FunctionPointerTable            func_table;
};

class SwapchainImageTracker;

class VulkanSwapchain
{
  public:
    virtual ~VulkanSwapchain() {}

    virtual VkResult CreateSwapchainKHR(PFN_vkCreateSwapchainKHR     func,
                                        const SwapchainCreationInfo* create_info,
                                        const VkAllocationCallbacks* allocator,
                                        VkSwapchainKHR*              swapchain) = 0;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                     VkDevice                     device,
                                     VkSwapchainKHR               swapchain,
                                     const VkAllocationCallbacks* allocator) = 0;

    virtual VkResult GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                           VkPhysicalDevice            physical_device,
                                           VkDevice                    device,
                                           VkSwapchainKHR              swapchain,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   replay_count_ptr,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) = 0;

    virtual VkResult QueuePresentKHR(PFN_vkQueuePresentKHR              func,
                                     const std::vector<uint32_t>&       capture_image_indices,
                                     const std::vector<VkSwapchainKHR>& swapchains,
                                     VkQueue                            queue,
                                     const VkPresentInfoKHR*            present_info) = 0;

    struct AcquiredIndexData
    {
        uint32_t index = { 0 };
        bool     acquired{ false };
    };

    virtual void ProcessSetSwapchainImageStateCommand(
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
    {}

    virtual bool
    RetrievePreAcquiredImage(VkSwapchainKHR swapchain, uint32_t image_index, VkSemaphore* semaphore, VkFence* fence)
    {
        return false;
    }

  protected:
    struct SwapchainInfo
    {
        VkSwapchainCreateInfoKHR create_info;
        uint64_t                 capture_id;
    };
    SwapchainInfo* CreateSwapchainInfo(const VkSwapchainCreateInfoKHR* old_ci, uint64_t capture_id)
    {
        SwapchainInfo* new_si = new SwapchainInfo;
        if (new_si != nullptr)
        {
            bool copy_queue_indices = false;

            new_si->create_info.sType            = old_ci->sType;
            new_si->create_info.pNext            = nullptr;
            new_si->create_info.flags            = old_ci->flags;
            new_si->create_info.surface          = old_ci->surface;
            new_si->create_info.minImageCount    = old_ci->minImageCount;
            new_si->create_info.imageFormat      = old_ci->imageFormat;
            new_si->create_info.imageColorSpace  = old_ci->imageColorSpace;
            new_si->create_info.imageExtent      = { old_ci->imageExtent.width, old_ci->imageExtent.height };
            new_si->create_info.imageArrayLayers = old_ci->imageArrayLayers;
            new_si->create_info.imageUsage       = old_ci->imageUsage;
            new_si->create_info.imageSharingMode = old_ci->imageSharingMode;
            new_si->create_info.preTransform     = old_ci->preTransform;
            new_si->create_info.compositeAlpha   = old_ci->compositeAlpha;
            new_si->create_info.presentMode      = old_ci->presentMode;
            new_si->create_info.clipped          = old_ci->clipped;
            new_si->create_info.oldSwapchain     = old_ci->oldSwapchain;
            new_si->capture_id                   = capture_id;

            // TODO: This is a duplicate of `vulkan_replay_consumer_base.cpp` line 5003.
            // There can be only one,
            if (old_ci->imageSharingMode == VK_SHARING_MODE_CONCURRENT && old_ci->queueFamilyIndexCount > 0 &&
                old_ci->pQueueFamilyIndices != nullptr)
            {
                new_si->create_info.queueFamilyIndexCount = old_ci->queueFamilyIndexCount;
                copy_queue_indices                        = true;
            }
            else
            {
                new_si->create_info.queueFamilyIndexCount = 1;
            }
            uint32_t* index_array = new uint32_t[new_si->create_info.queueFamilyIndexCount];
            if (index_array != nullptr)
            {
                if (copy_queue_indices)
                {
                    for (uint32_t i = 0; i < old_ci->queueFamilyIndexCount; ++i)
                    {
                        index_array[i] = old_ci->pQueueFamilyIndices[i];
                    }
                }
                else
                {
                    index_array[0] = 0;
                }
                new_si->create_info.pQueueFamilyIndices = index_array;
            }
            else
            {
                delete new_si;
                new_si = nullptr;
            }
        }
        return new_si;
    }

    void FreeSwapchainInfo(const SwapchainInfo* si)
    {
        if (si)
        {
            delete[] si->create_info.pQueueFamilyIndices;
            delete si;
        }
    }

    FunctionPointerTable       func_table_;
    ResourceAllocatorCallbacks resource_alloc_callbacks_;
    LogFunctionPointer         log_error_{ nullptr };
    LogFunctionPointer         log_warning_{ nullptr };
    LogFunctionPointer         log_info_{ nullptr };

    SwapchainImageTracker*                                   swapchain_image_tracker_{ nullptr };
    std::unordered_map<VkSwapchainKHR, const SwapchainInfo*> swapchain_infos_;
};

} // namespace compatibility
} // namespace gfxrecon

#endif // GFXRECON_COMPATIBILITY_VULKAN_SWAPCHAIN_H
