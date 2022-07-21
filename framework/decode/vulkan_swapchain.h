/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_SWAPCHAIN_H
#define GFXRECON_DECODE_VULKAN_SWAPCHAIN_H

#include "decode/vulkan_object_info.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanSwapchain
{
  public:
    virtual ~VulkanSwapchain() {}

    virtual VkResult CreateSwapchainKHR(PFN_vkCreateSwapchainKHR        func,
                                        const DeviceInfo*               device_info,
                                        const VkSwapchainCreateInfoKHR* create_info,
                                        const VkAllocationCallbacks*    allocator,
                                        VkSwapchainKHR*                 swapchain,
                                        const VkPhysicalDevice          physical_device,
                                        const encode::InstanceTable*    instance_table,
                                        const encode::DeviceTable*      device_table) = 0;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                     const DeviceInfo*            device_info,
                                     const SwapchainKHRInfo*      swapchain_info,
                                     const VkAllocationCallbacks* allocator) = 0;

    virtual VkResult GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                           const DeviceInfo*           device_info,
                                           SwapchainKHRInfo*           swapchain_info,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) = 0;

    virtual VkResult AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                         const DeviceInfo*         device_info,
                                         SwapchainKHRInfo*         swapchain_info,
                                         uint64_t                  timeout,
                                         SemaphoreInfo*            semaphore_info,
                                         FenceInfo*                fence_info,
                                         uint32_t                  capture_image_index,
                                         uint32_t*                 image_index) = 0;

    virtual VkResult AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                         const DeviceInfo*         device_info,
                                         SwapchainKHRInfo*         swapchain_info,
                                         uint64_t                  timeout,
                                         VkSemaphore               semaphore,
                                         VkFence                   fence,
                                         uint32_t                  capture_image_index,
                                         uint32_t*                 image_index) = 0;

    virtual VkResult AcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                          const DeviceInfo*                device_info,
                                          SwapchainKHRInfo*                swapchain_info,
                                          const VkAcquireNextImageInfoKHR* acquire_info,
                                          uint32_t                         capture_image_index,
                                          uint32_t*                        image_index) = 0;

    virtual VkResult QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                     const std::vector<uint32_t>&          capture_image_indices,
                                     const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                     const QueueInfo*                      queue_info,
                                     const VkPresentInfoKHR*               present_info) = 0;

    virtual VkResult CreateRenderPass(PFN_vkCreateRenderPass        func,
                                      const DeviceInfo*             device_info,
                                      const VkRenderPassCreateInfo* create_info,
                                      const VkAllocationCallbacks*  allocator,
                                      VkRenderPass*                 render_pass) = 0;

    virtual VkResult CreateRenderPass2(PFN_vkCreateRenderPass2        func,
                                       const DeviceInfo*              device_info,
                                       const VkRenderPassCreateInfo2* create_info,
                                       const VkAllocationCallbacks*   allocator,
                                       VkRenderPass*                  render_pass) = 0;

    virtual void CmdPipelineBarrier(PFN_vkCmdPipelineBarrier     func,
                                    const CommandBufferInfo*     command_buffer_info,
                                    VkPipelineStageFlags         src_stage_mask,
                                    VkPipelineStageFlags         dst_stage_mask,
                                    VkDependencyFlags            dependency_flags,
                                    uint32_t                     memory_barrier_count,
                                    const VkMemoryBarrier*       memory_barriers,
                                    uint32_t                     buffer_memory_barrier_count,
                                    const VkBufferMemoryBarrier* buffer_memory_barriers,
                                    uint32_t                     image_memory_barrier_count,
                                    const VkImageMemoryBarrier*  image_memory_barriers) = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SWAPCHAIN_H
