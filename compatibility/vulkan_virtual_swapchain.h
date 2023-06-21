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

#ifndef GFXRECON_COMPATIBILITY_VULKAN_VIRTUAL_SWAPCHAIN_H
#define GFXRECON_COMPATIBILITY_VULKAN_VIRTUAL_SWAPCHAIN_H

#include "vulkan_swapchain.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(compatibility)

class VulkanVirtualSwapchain : public VulkanSwapchain
{
  public:
    virtual ~VulkanVirtualSwapchain() override {}

    virtual VkResult CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
                                        VkDevice                        device,
                                        const VkSwapchainCreateInfoKHR* create_info,
                                        const VkAllocationCallbacks*    allocator,
                                        VkSwapchainKHR*                 swapchain,
                                        const VkPhysicalDevice          physical_device,
                                        const encode::InstanceTable*    instance_table,
                                        const encode::DeviceTable*      device_table) override;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR        func,
                                     VkDevice                         device,
                                     decode::VulkanResourceAllocator* resource_allocator,
                                     const decode::SwapchainKHRInfo*  swapchain_info,
                                     const VkAllocationCallbacks*     allocator) override;

    virtual VkResult GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR      func,
                                           VkPhysicalDevice                 physical_device,
                                           VkDevice                         device,
                                           decode::VulkanResourceAllocator* resource_allocator,
                                           decode::SwapchainKHRInfo*        swapchain_info,
                                           uint32_t                         capture_image_count,
                                           uint32_t*                        image_count,
                                           VkImage*                         images) override;

    virtual VkResult QueuePresentKHR(PFN_vkQueuePresentKHR                         func,
                                     const std::vector<uint32_t>&                  capture_image_indices,
                                     const std::vector<decode::SwapchainKHRInfo*>& swapchain_infos,
                                     VkQueue                                       queue,
                                     const VkPresentInfoKHR*                       present_info) override;

    virtual void ProcessSetSwapchainImageStateCommand(
        VkPhysicalDevice                                              physical_device,
        VkDevice                                                      device,
        decode::VulkanResourceAllocator*                              resource_allocator,
        const std::unordered_map<uint32_t, VkDeviceQueueCreateFlags>& queue_family_creation_flags,
        decode::SwapchainKHRInfo*                                     swapchain_info,
        uint32_t                                                      last_presented_image,
        const std::vector<format::SwapchainImageStateInfo>&           image_info,
        const decode::VulkanObjectInfoTable&                          object_info_table,
        decode::SwapchainImageTracker&                                swapchain_image_tracker) override
    {}

  private:
    VkResult CreateSwapchainImage(VkPhysicalDevice                        physical_device,
                                  VkDevice                                device,
                                  decode::VulkanResourceAllocator*        resource_allocator,
                                  const VkImageCreateInfo&                image_create_info,
                                  decode::SwapchainKHRInfo::VirtualImage& image);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(compatibility)

#endif // GFXRECON_COMPATIBILITY_VULKAN_VIRTUAL_SWAPCHAIN_H
