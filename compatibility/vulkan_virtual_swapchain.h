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

namespace gfxrecon
{
namespace compatibility
{

class VulkanVirtualSwapchain : public VulkanSwapchain
{
  public:
    virtual ~VulkanVirtualSwapchain() override {}

    virtual VkResult CreateSwapchainKHR(PFN_vkCreateSwapchainKHR     func,
                                        const SwapchainCreationInfo* create_info,
                                        const VkAllocationCallbacks* allocator,
                                        VkSwapchainKHR*              swapchain) override;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                     VkDevice                     device,
                                     VkSwapchainKHR               swapchain,
                                     const VkAllocationCallbacks* allocator) override;

    virtual VkResult GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                           VkPhysicalDevice            physical_device,
                                           VkDevice                    device,
                                           VkSwapchainKHR              swapchain,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   replay_count_ptr,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) override;

    virtual VkResult QueuePresentKHR(PFN_vkQueuePresentKHR              func,
                                     const std::vector<uint32_t>&       capture_image_indices,
                                     const std::vector<VkSwapchainKHR>& swapchains,
                                     VkQueue                            queue,
                                     const VkPresentInfoKHR*            present_info) override;

  private:
    VkResult CreateSwapchainImage(VkPhysicalDevice         physical_device,
                                  VkDevice                 device,
                                  const VkImageCreateInfo& image_create_info,
                                  AllocatedImageData&      image);

    struct VirtualComponents
    {
        VkQueue                      blit_queue{ VK_NULL_HANDLE };
        VkCommandPool                blit_command_pool{ VK_NULL_HANDLE };
        std::vector<VkCommandBuffer> blit_command_buffers;
        std::vector<VkSemaphore>     blit_semaphores;
        std::vector<VkImage>         swapchain_images; // The real swapchain images.

        // Images created by replay, returned in place of the swapchain images.
        std::vector<AllocatedImageData> virtual_images;
    };

    std::unordered_map<VkSwapchainKHR, VirtualComponents*> swapchain_components_;
};

} // namespace compatibility
} // namespace gfxrecon

#endif // GFXRECON_COMPATIBILITY_VULKAN_VIRTUAL_SWAPCHAIN_H
