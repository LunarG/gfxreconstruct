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

#ifndef GFXRECON_DECODE_VULKAN_VIRTUAL_SWAPCHAIN_H
#define GFXRECON_DECODE_VULKAN_VIRTUAL_SWAPCHAIN_H

#include "decode/vulkan_swapchain.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanVirtualSwapchain : public VulkanSwapchain
{
  public:
    virtual ~VulkanVirtualSwapchain() override {}

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
                                                      SwapchainImageTracker&       swapchain_image_tracker) override
    {}

  protected:
    // Structure necessary to track the necessary information related to the virtual swapchain images
    struct VirtualImage
    {
        VkDeviceMemory                        memory{ VK_NULL_HANDLE };
        VkImage                               image{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData   memory_allocator_data{ 0 };
        VulkanResourceAllocator::ResourceData resource_allocator_data{ 0 };
    };

    // Structure to store data required per device queue family to properly handle creating the
    // virtual swapchain images and copying that data to the actual swapchain images.
    struct CopyCmdData
    {
        VkCommandPool                command_pool;
        std::vector<VkCommandBuffer> command_buffers;
        std::vector<VkFence>         fences;
        std::vector<VkSemaphore>     semaphores;
    };

    // Structure to track VulkanVirtualSwapchain private data specific to a particular VkSwapchainKHR handle.
    // Offscreen only need virtual_swapchain_images.
    struct SwapchainResourceData
    {
        // Create a map that correlates copy command data with a queue family index.
        std::unordered_map<uint32_t, CopyCmdData> copy_cmd_data;

        // Swapchain images, these include the virtual ones created by this
        // class that are returned in place of the hardware ones, as well
        // as a vector of the actual hardware ones used during replay.
        std::vector<VirtualImage> virtual_swapchain_images;
        std::vector<VkImage>      replay_swapchain_images;
    };

    bool AddSwapchainResourceData(VkSwapchainKHR swapchain);

    VkResult CreateSwapchainResourceData(const VulkanDeviceInfo*       device_info,
                                         const VulkanSwapchainKHRInfo* swapchain_info,
                                         uint32_t                      capture_image_count,
                                         uint32_t*                     replay_image_count,
                                         VkImage*                      images,
                                         bool                          offscreen);

    void CleanSwapchainResourceData(const VulkanDeviceInfo* device_info, const VulkanSwapchainKHRInfo* swapchain_info);

    VkResult CreateVirtualSwapchainImage(const VulkanDeviceInfo*  device_info,
                                         const VkImageCreateInfo& image_create_info,
                                         VirtualImage&            image);

    // Create an unordered map to associate the swapchain resource data with a particular Vulkan swapchain
    std::unordered_map<VkSwapchainKHR, std::unique_ptr<SwapchainResourceData>> swapchain_resources_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_VIRTUAL_SWAPCHAIN_H
