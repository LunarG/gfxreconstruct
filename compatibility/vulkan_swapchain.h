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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"

#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(compatibility)

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

class SwapchainImageTracker;

class VulkanSwapchain
{
  public:
    virtual ~VulkanSwapchain() {}

    virtual VkResult CreateSwapchainKHR(PFN_vkCreateSwapchainKHR          func,
                                        VkDevice                          device,
                                        const VkSwapchainCreateInfoKHR*   create_info,
                                        const ResourceAllocatorCallbacks* resource_alloc_callbacks,
                                        const VkAllocationCallbacks*      allocator,
                                        VkSwapchainKHR*                   swapchain,
                                        const VkPhysicalDevice            physical_device,
                                        const encode::InstanceTable*      instance_table,
                                        const encode::DeviceTable*        device_table) = 0;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR       func,
                                     VkDevice                        device,
                                     const decode::SwapchainKHRInfo* swapchain_info,
                                     const VkAllocationCallbacks*    allocator) = 0;

    virtual VkResult GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                           VkPhysicalDevice            physical_device,
                                           VkDevice                    device,
                                           decode::SwapchainKHRInfo*   swapchain_info,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) = 0;

    virtual VkResult QueuePresentKHR(PFN_vkQueuePresentKHR                         func,
                                     const std::vector<uint32_t>&                  capture_image_indices,
                                     const std::vector<decode::SwapchainKHRInfo*>& swapchain_infos,
                                     VkQueue                                       queue,
                                     const VkPresentInfoKHR*                       present_info) = 0;

    virtual void ProcessSetSwapchainImageStateCommand(
        VkPhysicalDevice                                              physical_device,
        VkDevice                                                      device,
        const std::unordered_map<uint32_t, VkDeviceQueueCreateFlags>& queue_family_creation_flags,
        decode::SwapchainKHRInfo*                                     swapchain_info,
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
    const encode::InstanceTable* instance_table_{ nullptr };
    const encode::DeviceTable*   device_table_{ nullptr };
    ResourceAllocatorCallbacks   resource_alloc_callbacks_;
    SwapchainImageTracker*       swapchain_image_tracker_{ nullptr };
};

GFXRECON_END_NAMESPACE(compatibility)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_COMPATIBILITY_VULKAN_SWAPCHAIN_H
