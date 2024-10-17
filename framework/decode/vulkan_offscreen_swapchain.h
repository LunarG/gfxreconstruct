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

#ifndef GFXRECON_DECODE_VULKAN_OFFSCREEN_SWAPCHAIN_H
#define GFXRECON_DECODE_VULKAN_OFFSCREEN_SWAPCHAIN_H

#include "decode/vulkan_virtual_swapchain.h"

#include "decode/screenshot_handler.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanOffscreenSwapchain : public VulkanVirtualSwapchain
{
  public:
    virtual ~VulkanOffscreenSwapchain() override {}

    virtual VkResult CreateSurface(VkResult                            original_result,
                                   VulkanInstanceInfo*                 instance_info,
                                   const std::string&                  wsi_extension,
                                   VkFlags                             flags,
                                   HandlePointerDecoder<VkSurfaceKHR>* surface,
                                   const encode::VulkanInstanceTable*  instance_table,
                                   application::Application*           application,
                                   const int32_t                       xpos,
                                   const int32_t                       ypos,
                                   const uint32_t                      width,
                                   const uint32_t                      height,
                                   bool                                force_windowed = false) override;

    virtual void DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                const VulkanInstanceInfo*    instance_info,
                                const VulkanSurfaceKHRInfo*  surface_info,
                                const VkAllocationCallbacks* allocator) override;

    virtual VkResult CreateSwapchainKHR(VkResult                              original_result,
                                        PFN_vkCreateSwapchainKHR              func,
                                        const VulkanDeviceInfo*               device_info,
                                        const VkSwapchainCreateInfoKHR*       create_info,
                                        const VkAllocationCallbacks*          allocator,
                                        HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                        const encode::VulkanDeviceTable*      device_table) override;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR     func,
                                     const VulkanDeviceInfo*       device_info,
                                     const VulkanSwapchainKHRInfo* swapchain_info,
                                     const VkAllocationCallbacks*  allocator) override;

    virtual VkResult GetSwapchainImagesKHR(VkResult                    original_result,
                                           PFN_vkGetSwapchainImagesKHR func,
                                           const VulkanDeviceInfo*     device_info,
                                           VulkanSwapchainKHRInfo*     swapchain_info,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) override;

    virtual VkResult AcquireNextImageKHR(VkResult                  original_result,
                                         PFN_vkAcquireNextImageKHR func,
                                         const VulkanDeviceInfo*   device_info,
                                         VulkanSwapchainKHRInfo*   swapchain_info,
                                         uint64_t                  timeout,
                                         VkSemaphore               semaphore,
                                         VkFence                   fence,
                                         uint32_t                  capture_image_index,
                                         uint32_t*                 image_index) override;

    virtual VkResult AcquireNextImage2KHR(VkResult                         original_result,
                                          PFN_vkAcquireNextImage2KHR       func,
                                          const VulkanDeviceInfo*          device_info,
                                          VulkanSwapchainKHRInfo*          swapchain_info,
                                          const VkAcquireNextImageInfoKHR* acquire_info,
                                          uint32_t                         capture_image_index,
                                          uint32_t*                        image_index) override;

    virtual VkResult QueuePresentKHR(VkResult                                    original_result,
                                     PFN_vkQueuePresentKHR                       func,
                                     const std::vector<uint32_t>&                capture_image_indices,
                                     const std::vector<VulkanSwapchainKHRInfo*>& swapchain_infos,
                                     const VulkanQueueInfo*                      queue_info,
                                     const VkPresentInfoKHR*                     present_info) override;

  private:
    const uint32_t default_queue_family_index_{ 0 };
    VkQueue        default_queue_{ VK_NULL_HANDLE }; // default_queue_family_index_,0

    VkResult SignalSemaphoresFence(const VulkanQueueInfo* queue_info,
                                   uint32_t               wait_semaphore_count,
                                   const VkSemaphore*     wait_semaphores,
                                   uint32_t               signal_semaphore_count,
                                   const VkSemaphore*     signal_semaphores,
                                   VkFence                fence);

    VkFrameBoundaryEXT frame_boundary_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OFFSCREEN_SWAPCHAIN_H
