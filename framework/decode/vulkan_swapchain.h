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

#ifndef GFXRECON_DECODE_VULKAN_SWAPCHAIN_H
#define GFXRECON_DECODE_VULKAN_SWAPCHAIN_H

#include "decode/vulkan_object_info.h"
#include "decode/common_object_info_table.h"
#include "decode/swapchain_image_tracker.h"
#include "decode/window.h"
#include "util/defines.h"
#include "decode/vulkan_replay_options.h"

#include "application/application.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t  kDefaultWindowPositionX = 0;
const int32_t  kDefaultWindowPositionY = 0;
const uint32_t kDefaultWindowWidth     = 320;
const uint32_t kDefaultWindowHeight    = 240;

class ScreenshotHandler;

struct VulkanSwapchainOptions
{
    bool    skip_additional_present_blts{ false };
    int32_t select_surface_index{ -1 };
};

class VulkanSwapchain
{
  public:
    virtual ~VulkanSwapchain() {}

    virtual void Clean();

    void SetOptions(VulkanSwapchainOptions& options) { swapchain_options_ = options; }

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
                                   bool                                force_windowed = false);

    virtual void DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                const VulkanInstanceInfo*    instance_info,
                                const VulkanSurfaceKHRInfo*  surface_info,
                                const VkAllocationCallbacks* allocator);

    virtual VkResult CreateSwapchainKHR(VkResult                              original_result,
                                        PFN_vkCreateSwapchainKHR              func,
                                        const VulkanDeviceInfo*               device_info,
                                        const VkSwapchainCreateInfoKHR*       create_info,
                                        const VkAllocationCallbacks*          allocator,
                                        HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                        const encode::VulkanDeviceTable*      device_table) = 0;

    virtual void DestroySwapchainKHR(PFN_vkDestroySwapchainKHR     func,
                                     const VulkanDeviceInfo*       device_info,
                                     const VulkanSwapchainKHRInfo* swapchain_info,
                                     const VkAllocationCallbacks*  allocator) = 0;

    virtual VkResult GetSwapchainImagesKHR(VkResult                    original_result,
                                           PFN_vkGetSwapchainImagesKHR func,
                                           const VulkanDeviceInfo*     device_info,
                                           VulkanSwapchainKHRInfo*     swapchain_info,
                                           uint32_t                    capture_image_count,
                                           uint32_t*                   image_count,
                                           VkImage*                    images) = 0;

    virtual VkResult AcquireNextImageKHR(VkResult                  original_result,
                                         PFN_vkAcquireNextImageKHR func,
                                         const VulkanDeviceInfo*   device_info,
                                         VulkanSwapchainKHRInfo*   swapchain_info,
                                         uint64_t                  timeout,
                                         VulkanSemaphoreInfo*      semaphore_info,
                                         VulkanFenceInfo*          fence_info,
                                         uint32_t                  capture_image_index,
                                         uint32_t*                 image_index);

    virtual VkResult AcquireNextImageKHR(VkResult                  original_result,
                                         PFN_vkAcquireNextImageKHR func,
                                         const VulkanDeviceInfo*   device_info,
                                         VulkanSwapchainKHRInfo*   swapchain_info,
                                         uint64_t                  timeout,
                                         VkSemaphore               semaphore,
                                         VkFence                   fence,
                                         uint32_t                  capture_image_index,
                                         uint32_t*                 image_index) = 0;

    virtual VkResult AcquireNextImage2KHR(VkResult                         original_result,
                                          PFN_vkAcquireNextImage2KHR       func,
                                          const VulkanDeviceInfo*          device_info,
                                          VulkanSwapchainKHRInfo*          swapchain_info,
                                          const VkAcquireNextImageInfoKHR* acquire_info,
                                          uint32_t                         capture_image_index,
                                          uint32_t*                        image_index) = 0;

    virtual VkResult QueuePresentKHR(VkResult                                    original_result,
                                     PFN_vkQueuePresentKHR                       func,
                                     const std::vector<uint32_t>&                capture_image_indices,
                                     const std::vector<VulkanSwapchainKHRInfo*>& swapchain_infos,
                                     const VulkanQueueInfo*                      queue_info,
                                     const VkPresentInfoKHR*                     present_info) = 0;

    virtual VkResult CreateRenderPass(VkResult                      original_result,
                                      PFN_vkCreateRenderPass        func,
                                      const VulkanDeviceInfo*       device_info,
                                      const VkRenderPassCreateInfo* create_info,
                                      const VkAllocationCallbacks*  allocator,
                                      VkRenderPass*                 render_pass) = 0;

    virtual VkResult CreateRenderPass2(VkResult                       original_result,
                                       PFN_vkCreateRenderPass2        func,
                                       const VulkanDeviceInfo*        device_info,
                                       const VkRenderPassCreateInfo2* create_info,
                                       const VkAllocationCallbacks*   allocator,
                                       VkRenderPass*                  render_pass) = 0;

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
                                    const VkImageMemoryBarrier*    image_memory_barriers) = 0;

    virtual void CmdPipelineBarrier2(PFN_vkCmdPipelineBarrier2 func,
                                     VulkanCommandBufferInfo*  command_buffer_info,
                                     const VkDependencyInfo*   pDependencyInfo) = 0;

    virtual void ProcessSetSwapchainImageStateCommand(const VulkanDeviceInfo* device_info,
                                                      VulkanSwapchainKHRInfo* swapchain_info,
                                                      uint32_t                last_presented_image,
                                                      const std::vector<format::SwapchainImageStateInfo>& image_info,
                                                      const CommonObjectInfoTable& object_info_table,
                                                      SwapchainImageTracker&       swapchain_image_tracker) = 0;

  protected:
    typedef std::unordered_set<Window*> ActiveWindows;

    const encode::VulkanInstanceTable* instance_table_{ nullptr };
    const encode::VulkanDeviceTable*   device_table_{ nullptr };

    application::Application* application_{ nullptr };
    ActiveWindows             active_windows_;
    int32_t                   create_surface_count_{ 0 };
    VulkanSwapchainOptions    swapchain_options_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SWAPCHAIN_H
