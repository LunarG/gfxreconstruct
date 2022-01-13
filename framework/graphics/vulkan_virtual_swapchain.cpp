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

#include "graphics/vulkan_virtual_swapchain.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

VkResult VulkanVirtualSwapchain::Create(VkPhysicalDevice        vkPhysicalDevice,
                                        VkDevice                vkDevice,
                                        const CreateInfo*       pCreateInfo,
                                        VulkanVirtualSwapchain* pVulkanVirtualSwapchain)
{
    assert(vkDevice);
    assert(pCreateInfo);
    assert(pCreateInfo->pfn_vkCreateSwapchainKHR);
    assert(pCreateInfo->pfn_vkDestroySwapchainKHR);
    assert(pCreateInfo->pfn_vkGetSwapchainImagesKHR);
    assert(pCreateInfo->pfn_vkCreateImage);
    assert(pCreateInfo->pfn_vkDestroyImage);
    assert(pCreateInfo->pfn_vkAllocateMemory);
    assert(pCreateInfo->pfn_vkBindImageMemory);
    assert(pCreateInfo->pfn_vkFreeMemory);
    assert(pCreateInfo->pfn_vkAcquireNextImageKHR || pCreateInfo->pfn_vkAcquireNextImage2KHR);
    assert(pCreateInfo->pfn_vkQueuePresentKHR);
    assert(pVulkanVirtualSwapchain);
    pVulkanVirtualSwapchain->Reset();
    pVulkanVirtualSwapchain->m_create_info = *pCreateInfo;
    pVulkanVirtualSwapchain->m_enabled     = pVulkanVirtualSwapchain->m_create_info.enabled;
    pVulkanVirtualSwapchain->m_vk_device   = vkDevice;
    VK_RESULT_SCOPE_BEGIN
    {
        VK_RESULT(pVulkanVirtualSwapchain->CreateSwapchain());
        VK_RESULT(pVulkanVirtualSwapchain->CreateImages());
        VK_RESULT(pVulkanVirtualSwapchain->AllocateAndBindImageMemory(vkPhysicalDevice));
    }
    VK_RESULT_SCOPE_END
    return vk_result;
}

VulkanVirtualSwapchain::VulkanVirtualSwapchain(VulkanVirtualSwapchain&& other)
{
    *this = std::move(other);
}

VulkanVirtualSwapchain& VulkanVirtualSwapchain::operator=(VulkanVirtualSwapchain&& other)
{
    if (this != &other)
    {
        m_create_info                 = std::move(other.m_create_info);
        m_enabled                     = std::move(other.m_enabled);
        m_vk_device                   = std::move(other.m_vk_device);
        m_vk_swapchain                = std::move(other.m_vk_swapchain);
        m_vk_device_memory            = std::move(other.m_vk_device_memory);
        m_vk_swapchain_images         = std::move(other.m_vk_swapchain_images);
        m_vk_virtual_swapchain_images = std::move(other.m_vk_virtual_swapchain_images);
        other.m_vk_device             = VK_NULL_HANDLE;
        other.m_vk_swapchain          = VK_NULL_HANDLE;
        other.m_vk_device_memory      = VK_NULL_HANDLE;
    }
    return *this;
}

VulkanVirtualSwapchain::~VulkanVirtualSwapchain()
{
    Reset();
}

VkResult VulkanVirtualSwapchain::GetSwapchainImagesKHR(uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{
    if (m_enabled)
    {
        if (pSwapchainImageCount)
        {
            if (pSwapchainImages)
            {
                for (size_t i = 0; i < *pSwapchainImageCount && i < m_vk_virtual_swapchain_images.size(); ++i)
                {
                    pSwapchainImages[i] = m_vk_virtual_swapchain_images[i];
                }
            }
            else
            {
                *pSwapchainImageCount = static_cast<uint32_t>(m_vk_virtual_swapchain_images.size());
            }
        }
    }
    else
    {
        assert(m_create_info.pfn_vkGetSwapchainImagesKHR);
        return m_create_info.pfn_vkGetSwapchainImagesKHR(
            m_vk_device, m_vk_swapchain, pSwapchainImageCount, pSwapchainImages);
    }
}

VkResult VulkanVirtualSwapchain::AcquireNextImage(uint64_t    timeout,
                                                  VkSemaphore vkSemaphore,
                                                  VkFence     vkFence,
                                                  uint32_t*   pImageIndex)
{
    if (m_enabled)
    {
        VkAcquireNextImageInfoKHR acquireNextImageInfo{};
        acquireNextImageInfo.sType     = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
        acquireNextImageInfo.swapchain = m_vk_swapchain;
        acquireNextImageInfo.timeout   = timeout;
        acquireNextImageInfo.semaphore = vkSemaphore;
        acquireNextImageInfo.fence     = vkFence;
        return AcquireNextImage2KHR(&acquireNextImageInfo, pImageIndex);
    }
    else
    {
        assert(m_create_info.pfn_vkAcquireNextImageKHR);
        return m_create_info.pfn_vkAcquireNextImageKHR(
            m_vk_device, m_vk_swapchain, timeout, vkSemaphore, vkFence, pImageIndex);
    }
}

VkResult VulkanVirtualSwapchain::AcquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                      uint32_t*                        pImageIndex)
{
    if (m_enabled)
    {}
    else
    {
        assert(m_create_info.pfn_vkAcquireNextImage2KHR);
        return m_create_info.pfn_vkAcquireNextImage2KHR(m_vk_device, pAcquireInfo, pImageIndex);
    }
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
{
    if (m_enabled)
    {}
    else
    {
        assert(m_create_info.pfn_vkQueuePresentKHR);
        return m_create_info.pfn_vkQueuePresentKHR(queue, pPresentInfo);
    }
}

const VulkanVirtualSwapchain::CreateInfo& VulkanVirtualSwapchain::GetCreateInfo() const
{
    return m_create_info;
}

VkBool32 VulkanVirtualSwapchain::IsEnabled() const
{
    return m_enabled;
}

void VulkanVirtualSwapchain::IsEnabled(VkBool32 enabled)
{
    m_enabled = enabled;
}

VkDevice VulkanVirtualSwapchain::GetDevice() const
{
    return m_vk_device;
}

VkSwapchainKHR VulkanVirtualSwapchain::GetSwapchain() const
{
    return m_vk_swapchain;
}

VkDeviceMemory VulkanVirtualSwapchain::GetDeviceMemory() const
{
    return m_vk_device_memory;
}

const std::vector<VkImage>& VulkanVirtualSwapchain::GetSwapchainImages() const
{
    return m_vk_swapchain_images;
}

const std::vector<VkImage>& VulkanVirtualSwapchain::GetVirtualSwapchainImages() const
{
    return m_vk_virtual_swapchain_images;
}

VkResult VulkanVirtualSwapchain::CreateSwapchain()
{
    VK_RESULT_SCOPE_BEGIN
    {
        // Create VkSwapchain with VK_IMAGE_USAGE_TRANSFER_DST_BIT enabled so that we
        //  can blit into the VkSwapchain when VkQueuePresentKHR() is called...
        m_create_info.imageUsage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        VK_RESULT(m_create_info.pfn_vkCreateSwapchainKHR(m_vk_device, &m_create_info, nullptr, &m_vk_swapchain));
        uint32_t swapchain_image_count = 0;
        VK_RESULT(
            m_create_info.pfn_vkGetSwapchainImagesKHR(m_vk_device, m_vk_swapchain, &swapchain_image_count, nullptr));
        m_vk_swapchain_images.resize(swapchain_image_count);
        VK_RESULT(m_create_info.pfn_vkGetSwapchainImagesKHR(
            m_vk_device, m_vk_swapchain, &swapchain_image_count, m_vk_swapchain_images.data()));
    }
    VK_RESULT_SCOPE_END
    return vk_result;
}

VkResult VulkanVirtualSwapchain::CreateImages()
{
    VK_RESULT_SCOPE_BEGIN
    {
        VkImageCreateInfo imageCreateInfo{};
        imageCreateInfo.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageCreateInfo.imageType             = VK_IMAGE_TYPE_2D;
        imageCreateInfo.format                = m_create_info.imageFormat;
        imageCreateInfo.extent.width          = m_create_info.imageExtent.width;
        imageCreateInfo.extent.height         = m_create_info.imageExtent.height;
        imageCreateInfo.extent.depth          = 1;
        imageCreateInfo.mipLevels             = 1;
        imageCreateInfo.arrayLayers           = m_create_info.imageArrayLayers;
        imageCreateInfo.samples               = VK_SAMPLE_COUNT_1_BIT;
        imageCreateInfo.tiling                = VK_IMAGE_TILING_OPTIMAL;
        imageCreateInfo.usage                 = m_create_info.imageUsage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        imageCreateInfo.sharingMode           = m_create_info.imageSharingMode;
        imageCreateInfo.queueFamilyIndexCount = m_create_info.queueFamilyIndexCount;
        imageCreateInfo.pQueueFamilyIndices   = m_create_info.pQueueFamilyIndices;
        imageCreateInfo.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
        m_vk_virtual_swapchain_images.resize(m_create_info.imageCount ? m_create_info.imageCount : m_vk_swapchain_images.size());
        for (size_t i = 0; i < m_vk_virtual_swapchain_images.size() && vk_result == VK_SUCCESS; ++i)
        {
            assert(m_create_info.pfn_vkCreateImage);
            VK_RESULT(m_create_info.pfn_vkCreateImage(
                m_vk_device, &imageCreateInfo, nullptr, &m_vk_virtual_swapchain_images[i]));
        }
    }
    VK_RESULT_SCOPE_END
    return vk_result;
}

VkResult VulkanVirtualSwapchain::AllocateAndBindImageMemory(VkPhysicalDevice vkPhysicalDevice)
{
    VK_RESULT_SCOPE_BEGIN
    {
        // TODO : Documentation
        for (auto vk_image : m_vk_virtual_swapchain_images)
        {
            // TODO :
        }

        // TODO : Documentation
        VkMemoryAllocateInfo memoryAllocateInfo{};
        memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        memoryAllocateInfo.allocationSize = 0; // TODO :
        memoryAllocateInfo.memoryTypeIndex = 0; // TODO :
        assert(m_create_info.pfn_vkAllocateMemory);
        VK_RESULT(m_create_info.pfn_vkAllocateMemory(m_vk_device, &memoryAllocateInfo, nullptr, &m_vk_device_memory));

        // TODO : Documentation
        for (auto vk_image : m_vk_virtual_swapchain_images)
        {
            // TODO :
        }
    }
    VK_RESULT_SCOPE_END
    return vk_result;
}

void VulkanVirtualSwapchain::Reset()
{
    assert((m_vk_device == VK_NULL_HANDLE) == (m_vk_swapchain == VK_NULL_HANDLE));
    if (m_vk_device && m_vk_swapchain)
    {
        for (auto vk_image : m_vk_virtual_swapchain_images)
        {
            assert(m_create_info.pfn_vkDestroyImage);
            m_create_info.pfn_vkDestroyImage(m_vk_device, vk_image, nullptr);
        }
        if (m_vk_device_memory)
        {
            assert(m_create_info.pfn_vkFreeMemory);
            m_create_info.pfn_vkFreeMemory(m_vk_device, m_vk_device_memory, nullptr);
        }
        if (m_vk_swapchain)
        {
            assert(m_create_info.pfn_vkDestroySwapchainKHR);
            m_create_info.pfn_vkDestroySwapchainKHR(m_vk_device, m_vk_swapchain, nullptr);
        }
    }
    m_create_info      = {};
    m_enabled          = VK_FALSE;
    m_vk_device        = VK_NULL_HANDLE;
    m_vk_swapchain     = VK_NULL_HANDLE;
    m_vk_device_memory = VK_NULL_HANDLE;
    m_vk_swapchain_images.clear();
    m_vk_virtual_swapchain_images.clear();
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
