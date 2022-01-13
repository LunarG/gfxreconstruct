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
    struct CreateInfo : public VkSwapchainCreateInfoKHR
    {
        PFN_vkCreateSwapchainKHR    pfn_vkCreateSwapchainKHR{ nullptr };
        PFN_vkDestroySwapchainKHR   pfn_vkDestroySwapchainKHR{ nullptr };
        PFN_vkGetSwapchainImagesKHR pfn_vkGetSwapchainImagesKHR{ nullptr };
        PFN_vkCreateImage           pfn_vkCreateImage{ nullptr };
        PFN_vkDestroyImage          pfn_vkDestroyImage{ nullptr };
        PFN_vkAllocateMemory        pfn_vkAllocateMemory{ nullptr };
        PFN_vkBindImageMemory       pfn_vkBindImageMemory{ nullptr };
        PFN_vkFreeMemory            pfn_vkFreeMemory{ nullptr };
        PFN_vkAcquireNextImageKHR   pfn_vkAcquireNextImageKHR{ nullptr };
        PFN_vkAcquireNextImage2KHR  pfn_vkAcquireNextImage2KHR{ nullptr };
        PFN_vkQueuePresentKHR       pfn_vkQueuePresentKHR{ nullptr };
        VkBool32                    enabled{};
        uint32_t                    imageCount{};
    };

    static VkResult
    Create(VkPhysicalDevice vkPhysicalDevice, VkDevice vkDevice, const CreateInfo* pCreateInfo, VulkanVirtualSwapchain* pVulkanVirtualSwapchain);

    VulkanVirtualSwapchain(VulkanVirtualSwapchain&& other);
    VulkanVirtualSwapchain& operator=(VulkanVirtualSwapchain&& other);
    ~VulkanVirtualSwapchain();

    VkResult GetSwapchainImagesKHR(uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
    VkResult AcquireNextImage(uint64_t timeout, VkSemaphore vkSemaphore, VkFence vkFence, uint32_t* pImageIndex);
    VkResult AcquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
    VkResult QueuePresentKHR(VkQueue vkQueue, const VkPresentInfoKHR* pPresentInfo);

    const CreateInfo&           GetCreateInfo() const;
    VkBool32                    IsEnabled() const;
    void                        IsEnabled(VkBool32 enabled);
    VkDevice                    GetDevice() const;
    VkSwapchainKHR              GetSwapchain() const;
    VkDeviceMemory              GetDeviceMemory() const;
    const std::vector<VkImage>& GetSwapchainImages() const;
    const std::vector<VkImage>& GetVirtualSwapchainImages() const;
    void                        Reset();

  private:
    VkResult CreateSwapchain();
    VkResult CreateImages();
    VkResult AllocateAndBindImageMemory(VkPhysicalDevice vkPhysicalDevice);

    CreateInfo           m_create_info{};
    VkBool32             m_enabled{ };
    VkDevice             m_vk_device{ VK_NULL_HANDLE };
    VkSwapchainKHR       m_vk_swapchain{ VK_NULL_HANDLE };
    VkDeviceMemory       m_vk_device_memory{ VK_NULL_HANDLE };
    std::vector<VkImage> m_vk_swapchain_images;
    std::vector<VkImage> m_vk_virtual_swapchain_images;

    VulkanVirtualSwapchain(const VulkanVirtualSwapchain&) = default;
    VulkanVirtualSwapchain& operator=(const VulkanVirtualSwapchain&) = default;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // VULKAN_VIRTUAL_SWAPCHAIN_H
