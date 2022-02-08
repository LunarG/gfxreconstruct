/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef VULKAN_VIRTUAL_SWAPCHAIN_H
#define VULKAN_VIRTUAL_SWAPCHAIN_H

#include "graphics/vulkan_util.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class VulkanVirtualSwapchain final
{
  public:
    struct DispatchTable
    {
        // VkSwapchainKHR entry points
        PFN_vkCreateSwapchainKHR    pfn_vkCreateSwapchainKHR{ nullptr };
        PFN_vkDestroySwapchainKHR   pfn_vkDestroySwapchainKHR{ nullptr };
        PFN_vkGetSwapchainImagesKHR pfn_vkGetSwapchainImagesKHR{ nullptr };
        PFN_vkAcquireNextImageKHR   pfn_vkAcquireNextImageKHR{ nullptr };
        PFN_vkAcquireNextImage2KHR  pfn_vkAcquireNextImage2KHR{ nullptr };
        // VkQueue entry points
        PFN_vkQueuePresentKHR pfn_vkQueuePresentKHR{ nullptr };
        PFN_vkQueueSubmit     pfn_vkQueueSubmit{ nullptr };
        PFN_vkQueueSubmit2    pfn_vkQueueSubmit2{ nullptr };
        // VkRenderPass entry points
        PFN_vkCreateRenderPass  pfn_vkCreateRenderPass{ nullptr };
        PFN_vkCreateRenderPass2 pfn_vkCreateRenderPass2{ nullptr };
        PFN_vkDestroyRenderPass pfn_vkDestroyRenderPass{ nullptr };
        // VkCommandPool entry points
        PFN_vkCreateCommandPool      pfn_vkCreateCommandPool{ nullptr };
        PFN_vkDestroyCommandPool     pfn_vkDestroyCommandPool{ nullptr };
        PFN_vkAllocateCommandBuffers pfn_vkAllocateCommandBuffers{ nullptr };
        // VkCommandBuffer entry points
        PFN_vkCmdBeginRendering   pfn_vkCmdBeginRendering{ nullptr };
        PFN_vkCmdBeginRenderPass  pfn_vkCmdBeginRenderPass{ nullptr };
        PFN_vkCmdBeginRenderPass2 pfn_vkCmdBeginRenderPass2{ nullptr };
        PFN_vkCmdEndRendering     pfn_vkCmdEndRendering{ nullptr };
        PFN_vkCmdEndRenderPass    pfn_vkCmdEndRenderPass{ nullptr };
        PFN_vkCmdEndRenderPass2   pfn_vkCmdEndRenderPass2{ nullptr };
        PFN_vkCmdNextSubpass      pfn_vkCmdNextSubpass{ nullptr };
        PFN_vkCmdNextSubpass2     pfn_vkCmdNextSubpass2{ nullptr };
        PFN_vkCmdPipelineBarrier  pfn_vkCmdPipelineBarrier{ nullptr };
        PFN_vkCmdPipelineBarrier2 pfn_vkCmdPipelineBarrier2{ nullptr };
    };

    struct CreateInfo : public VkSwapchainCreateInfoKHR
    {
        DispatchTable dispatch{};
        uint32_t      imageCount{};
    };

    static VkResult Create(VkDevice                vkDevice,
                           const CreateInfo*       pCreateInfo,
                           VmaAllocator            vmaAllocator,
                           VulkanVirtualSwapchain* pVulkanVirtualSwapchain);
    VulkanVirtualSwapchain(VulkanVirtualSwapchain&& other);
    VulkanVirtualSwapchain& operator=(VulkanVirtualSwapchain&& other);
    ~VulkanVirtualSwapchain();
    void Reset();

    // VkSwapchainKHR entry points
    VkResult GetSwapchainImagesKHR(uint32_t* pSwapchainImageCount, VkImage* pVkSwapchainImages);
    VkResult AcquireNextImageKHR(uint64_t timeout, VkSemaphore vkSemaphore, VkFence vkFence, uint32_t* pImageIndex);
    VkResult AcquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
    // VkQueue entry points
    VkResult QueuePresentKHR(VkQueue vkQueue, const VkPresentInfoKHR* pPresentInfo);
    VkResult QueueSubmit(VkQueue vkQueue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence vkFence);
    VkResult QueueSubmit2(VkQueue vkQueue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence vkFence);
    // VkRenderPass entry points
    VkResult CreateRenderPass(const VkRenderPassCreateInfo* pCreateInfo, VkRenderPass* pVkRenderPass);
    VkResult CreateRenderPass2(const VkRenderPassCreateInfo2* pCreateInfo, VkRenderPass* pVkRenderPass);
    void     DestroyRenderPass(VkRenderPass vkRenderPass);
    // VkCmdBuffer entry points
    void CmdBeginRendering(VkCommandBuffer vkCommandBuffer, const VkRenderingInfo* pRenderingInfo);
    void CmdBeginRenderPass(VkCommandBuffer              vkCommandBuffer,
                            const VkRenderPassBeginInfo* pRenderPassBeginInfo,
                            VkSubpassContents            subpassContents);
    void CmdBeginRenderPass2(VkCommandBuffer              vkCommandBuffer,
                             const VkRenderPassBeginInfo* pRenderPassBeginInfo,
                             const VkSubpassBeginInfo*    pSubpassBeginInfo);
    void CmdEndRendering(VkCommandBuffer vkCommandBuffer);
    void CmdEndRenderPass(VkCommandBuffer vkCommandBuffer);
    void CmdEndRenderPass2(VkCommandBuffer vkCommandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
    void CmdNextSubpass(VkCommandBuffer vkCommandBuffer, VkSubpassContents contents);
    void CmdNextSubpass2(VkCommandBuffer           vkCommandBuffer,
                         const VkSubpassBeginInfo* pSubpassBeginInfo,
                         const VkSubpassEndInfo*   pSubpassEndInfo);
    void CmdPipelineBarrier(VkCommandBuffer              vkCommandBuffer,
                            VkPipelineStageFlags         srcStageMask,
                            VkPipelineStageFlags         dstStageMask,
                            VkDependencyFlags            dependencyFlags,
                            uint32_t                     memoryBarrierCount,
                            const VkMemoryBarrier*       pMemoryBarriers,
                            uint32_t                     bufferMemoryBarrierCount,
                            const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                            uint32_t                     imageMemoryBarrierCount,
                            const VkImageMemoryBarrier*  pImageMemoryBarriers);
    void CmdPipelineBarrier2(VkCommandBuffer vkCommandBuffer, const VkDependencyInfo* pDependencyInfo);

  private:
    class Image;

    DispatchTable        m_dispatch{};
    VkDevice             m_vk_device{ VMA_NULL };
    VkCommandPool        m_vk_command_pool{ VK_NULL_HANDLE };
    VkSwapchainKHR       m_vk_swapchain{ VMA_NULL };
    std::vector<VkImage> m_vk_images;
    std::vector<Image>   m_virtual_images;

    VulkanVirtualSwapchain(const VulkanVirtualSwapchain&) = default;
    VulkanVirtualSwapchain& operator=(const VulkanVirtualSwapchain&) = default;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // VULKAN_VIRTUAL_SWAPCHAIN_H
