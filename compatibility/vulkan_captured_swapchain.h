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

#ifndef GFXRECON_COMPATIBILITY_VULKAN_CAPTURED_SWAPCHAIN_H
#define GFXRECON_COMPATIBILITY_VULKAN_CAPTURED_SWAPCHAIN_H

#include "vulkan_swapchain.h"

namespace gfxrecon {
namespace compatibility {

class VulkanCapturedSwapchain : public VulkanSwapchain
{
  public:
    virtual ~VulkanCapturedSwapchain() override {}

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
        const std::vector<AllocatedImageData>&                        image_info) override;

    virtual bool RetrievePreAcquiredImage(VkSwapchainKHR swapchain,
                                          uint32_t       image_index,
                                          VkSemaphore*   semaphore,
                                          VkFence*       fence) override;

  private:
    // When processing swapchain image state for the trimming state setup, acquire all swapchain images to transition to
    // the expected layout and keep them acquired until first use.
    void ProcessSetSwapchainImageStatePreAcquire(VkDevice                               device,
                                                 VkSwapchainKHR                         swapchain,
                                                 const SwapchainInfo*                   swapchain_info,
                                                 std::vector<AcquiredIndexData>&        acquired_info,
                                                 const std::vector<AllocatedImageData>& image_info);

    // When processing swapchain image state for the trimming state setup, acquire an image, transition it to
    // the expected layout, and then call queue present if the image is not expected to be in the acquired state so that
    // no more than one image is acquired at a time.
    void ProcessSetSwapchainImageStateQueueSubmit(
        VkDevice                                                      device,
        const std::unordered_map<uint32_t, VkDeviceQueueCreateFlags>& queue_family_creation_flags,
        VkSwapchainKHR                                                swapchain,
        const SwapchainInfo*                                          swapchain_info,
        std::vector<AcquiredIndexData>&                               acquired_info,
        uint32_t                                                      last_presented_image,
        const std::vector<AllocatedImageData>&                        image_info);
};

} // compatibility
} // gfxrecon

#endif // GFXRECON_COMPATIBILITY_VULKAN_CAPTURED_SWAPCHAIN_H
