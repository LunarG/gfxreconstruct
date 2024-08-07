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

#ifndef GFXRECON_DECODE_VULKAN_CAPTURED_SWAPCHAIN_H
#define GFXRECON_DECODE_VULKAN_CAPTURED_SWAPCHAIN_H

#include "decode/vulkan_swapchain.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanCapturedSwapchain : public VulkanSwapchain
{
  public:
    virtual ~VulkanCapturedSwapchain() override {}

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

    virtual VkResult CreateRenderPass(VkResult                      original_result,
                                      PFN_vkCreateRenderPass        func,
                                      const VulkanDeviceInfo*       device_info,
                                      const VkRenderPassCreateInfo* create_info,
                                      const VkAllocationCallbacks*  allocator,
                                      VkRenderPass*                 render_pass) override;

    virtual VkResult CreateRenderPass2(VkResult                       original_result,
                                       PFN_vkCreateRenderPass2        func,
                                       const VulkanDeviceInfo*        device_info,
                                       const VkRenderPassCreateInfo2* create_info,
                                       const VkAllocationCallbacks*   allocator,
                                       VkRenderPass*                  render_pass) override;

    virtual void CmdPipelineBarrier(PFN_vkCmdPipelineBarrier       func,
                                    const VulkanCommandBufferInfo* command_buffer_info,
                                    VkPipelineStageFlags           src_stage_mask,
                                    VkPipelineStageFlags           dst_stage_mask,
                                    VkDependencyFlags              dependency_flags,
                                    uint32_t                       memory_barrier_count,
                                    const VkMemoryBarrier*         memory_barriers,
                                    uint32_t                       buffer_memory_barrier_count,
                                    const VkBufferMemoryBarrier*   buffer_memory_barriers,
                                    uint32_t                       image_memory_barrier_count,
                                    const VkImageMemoryBarrier*    image_memory_barriers) override;

    virtual void CmdPipelineBarrier2(PFN_vkCmdPipelineBarrier2 func,
                                     VulkanCommandBufferInfo*  command_buffer_info,
                                     const VkDependencyInfo*   pDependencyInfo) override;

    virtual void ProcessSetSwapchainImageStateCommand(const VulkanDeviceInfo* device_info,
                                                      VulkanSwapchainKHRInfo* swapchain_info,
                                                      uint32_t                last_presented_image,
                                                      const std::vector<format::SwapchainImageStateInfo>& image_info,
                                                      const CommonObjectInfoTable& object_info_table,
                                                      SwapchainImageTracker&       swapchain_image_tracker) override;

  private:
    // When processing swapchain image state for the trimming state setup, acquire all swapchain images to transition to
    // the expected layout and keep them acquired until first use.
    void ProcessSetSwapchainImageStatePreAcquire(const VulkanDeviceInfo*                             device_info,
                                                 VulkanSwapchainKHRInfo*                             swapchain_info,
                                                 const std::vector<format::SwapchainImageStateInfo>& image_info,
                                                 const CommonObjectInfoTable&                        object_info_table,
                                                 SwapchainImageTracker& swapchain_image_tracker);

    // When processing swapchain image state for the trimming state setup, acquire an image, transition it to
    // the expected layout, and then call queue present if the image is not expected to be in the acquired state so that
    // no more than one image is acquired at a time.
    void ProcessSetSwapchainImageStateQueueSubmit(const VulkanDeviceInfo* device_info,
                                                  VulkanSwapchainKHRInfo* swapchain_info,
                                                  uint32_t                last_presented_image,
                                                  const std::vector<format::SwapchainImageStateInfo>& image_info,
                                                  const CommonObjectInfoTable& object_info_table);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CAPTURED_SWAPCHAIN_H
