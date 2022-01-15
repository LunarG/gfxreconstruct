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

#include <algorithm>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

/*

Purpose

    -   During execution of a Vulkan application, the order that VkImages are
    acquired from a VkSwapchainKHR may not be deterministic.  This means that
    a replay of a captured stream may acquire VkImages in a different order.
    The actual outcome of any given replay is highly dependent on many
    variables including (but not limited to) platform, graphics hardware,
    graphics driver, WSI extension, etc.  This may result in flickering or
    other visual corruption during playback.  To mitigate this, virtual
    swapchain provides a mechanism for creating deterministic sequences of
    VkImage acquisition.

Design principles

    -   Do not rely on external state tracking

    -   Has minimal interaction points with other gfxrecon systems

    -   Makes no assumptions about other gfxrecon systems

Notes

    -   There's a decision to make when deciding whether to playback with or
    without virtual swapchain enabled.  There can be different performance impacts
    based on many variables including (but not limited to) memory barriers, CPU vs
    GPU load at capture time vs playback time, memory usage for virtual swapchain,
    etc.

    -   There are a handful of extensions that impact VkSwapchainKHR that aren't
    addressed here

TODO

    -   Testing plan
    -   Integration
    -   Identify edge cases, extensions, caveats, etc...


*/

class VulkanVirtualSwapchain::Image final
{
  public:
    Image() = default;

    static VkResult Create(VmaAllocator vmaAllocator, const VkImageCreateInfo* pImageCreateInfo, Image* pImage)
    {
        assert(vmaAllocator);
        assert(pImageCreateInfo);
        assert(pImage);
        pImage->Reset();
        pImage->m_vma_allocator = vmaAllocator;
        VK_RESULT_SCOPE_BEGIN
        {
            VmaAllocationCreateInfo allocation_create_info{};
            allocation_create_info.usage = VMA_MEMORY_USAGE_GPU_ONLY;
            VK_RESULT(vmaCreateImage(pImage->m_vma_allocator,
                                     pImageCreateInfo,
                                     &allocation_create_info,
                                     &pImage->m_vk_image,
                                     &pImage->m_vma_allocation,
                                     nullptr));
        }
        VK_RESULT_SCOPE_END
        return vk_result;
    }

    Image(Image&& other) { *this = std::move(other); }

    Image& operator=(Image&& other)
    {
        if (this != &other)
        {
            m_vma_allocator  = std::move(other.m_vma_allocator);
            m_vk_image       = std::move(other.m_vk_image);
            m_vma_allocation = std::move(other.m_vma_allocation);
            // Make sure that we clear m_vk_image in the object we move from since we're using that handle to trigger
            // cleanup in Reset()...
            other.m_vk_image = VK_NULL_HANDLE;
        }
        return *this;
    }

    ~Image() { Reset(); }

    void Reset()
    {
        if (m_vk_image)
        {
            assert(m_vma_allocation);
            assert(m_vma_allocator);
            vmaDestroyImage(m_vma_allocator, m_vk_image, m_vma_allocation);
        }
        m_vma_allocator  = VMA_NULL;
        m_vk_image       = VK_NULL_HANDLE;
        m_vma_allocation = VMA_NULL;
    }

    VkImage GetVkImage() const { return m_vk_image; }

  private:
    VmaAllocator  m_vma_allocator{ VMA_NULL };
    VkImage       m_vk_image{ VK_NULL_HANDLE };
    VmaAllocation m_vma_allocation{ VMA_NULL };

    Image(const Image&) = default;
    Image& operator=(const Image&) = default;
};

VkResult VulkanVirtualSwapchain::Create(VkDevice                vkDevice,
                                        const CreateInfo*       pCreateInfo,
                                        VmaAllocator            vmaAllocator,
                                        VulkanVirtualSwapchain* pVulkanVirtualSwapchain)
{
    assert(vkDevice);
    assert(pCreateInfo);
    assert(pCreateInfo->dispatch.pfn_vkCreateSwapchainKHR);
    assert(pCreateInfo->dispatch.pfn_vkDestroySwapchainKHR);
    assert(pCreateInfo->dispatch.pfn_vkGetSwapchainImagesKHR);
    assert(pCreateInfo->dispatch.pfn_vkAcquireNextImageKHR || pCreateInfo->dispatch.pfn_vkAcquireNextImage2KHR);
    assert(pCreateInfo->dispatch.pfn_vkQueuePresentKHR);
    assert(vmaAllocator);
    assert(pVulkanVirtualSwapchain);
    pVulkanVirtualSwapchain->Reset();
    pVulkanVirtualSwapchain->m_vk_device = vkDevice;
    pVulkanVirtualSwapchain->m_dispatch  = pCreateInfo->dispatch;
    VK_RESULT_SCOPE_BEGIN
    {
        // Create VkSwapchain with VK_IMAGE_USAGE_TRANSFER_DST_BIT enabled so that we can blit into the VkSwapchain when
        // VkQueuePresentKHR() is called...
        auto create_info = *pCreateInfo;
        create_info.imageUsage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        VkSwapchainKHR vk_swapchain = VK_NULL_HANDLE;
        VK_RESULT(pCreateInfo->dispatch.pfn_vkCreateSwapchainKHR(vkDevice, &create_info, nullptr, &vk_swapchain));
        pVulkanVirtualSwapchain->m_vk_swapchain = vk_swapchain;

        // Get VkSwapchain VkImages...
        uint32_t image_count = 0;
        VK_RESULT(pCreateInfo->dispatch.pfn_vkGetSwapchainImagesKHR(vkDevice, vk_swapchain, &image_count, nullptr));
        pVulkanVirtualSwapchain->m_vk_images.resize(image_count);
        VK_RESULT(pCreateInfo->dispatch.pfn_vkGetSwapchainImagesKHR(
            vkDevice, vk_swapchain, &image_count, pVulkanVirtualSwapchain->m_vk_images.data()));

        // TODO : Check if we can blit...if not, prepare for draw call copies...
        // Create virtual Images with VK_IMAGE_USAGE_TRANSFER_SRC_BIT enabled...
        VkImageCreateInfo image_create_info{};
        image_create_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        image_create_info.imageType             = VK_IMAGE_TYPE_2D;
        image_create_info.format                = pCreateInfo->imageFormat;
        image_create_info.extent.width          = pCreateInfo->imageExtent.width;
        image_create_info.extent.height         = pCreateInfo->imageExtent.height;
        image_create_info.extent.depth          = 1;
        image_create_info.mipLevels             = 1;
        image_create_info.arrayLayers           = pCreateInfo->imageArrayLayers;
        image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
        image_create_info.usage                 = pCreateInfo->imageUsage | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        image_create_info.sharingMode           = pCreateInfo->imageSharingMode;
        image_create_info.queueFamilyIndexCount = pCreateInfo->queueFamilyIndexCount;
        image_create_info.pQueueFamilyIndices   = pCreateInfo->pQueueFamilyIndices;
        image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
        pVulkanVirtualSwapchain->m_virtual_images.resize(
            std::max(static_cast<size_t>(pCreateInfo->imageCount), pVulkanVirtualSwapchain->m_vk_images.size()));
        for (auto& virtual_image : pVulkanVirtualSwapchain->m_virtual_images)
        {
            VK_RESULT(Image::Create(vmaAllocator, &image_create_info, &virtual_image));
        }
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
        m_vk_device      = std::move(other.m_vk_device);
        m_dispatch       = std::move(other.m_dispatch);
        m_vk_swapchain   = std::move(other.m_vk_swapchain);
        m_vk_images      = std::move(other.m_vk_images);
        m_virtual_images = std::move(other.m_virtual_images);
        // Make sure that we clear m_vk_swapchain in the object we move from since we're using that handle to trigger
        // cleanup in Reset()...
        other.m_vk_swapchain = VK_NULL_HANDLE;
    }
    return *this;
}

VulkanVirtualSwapchain::~VulkanVirtualSwapchain()
{
    Reset();
}

void VulkanVirtualSwapchain::Reset()
{
    if (m_vk_swapchain)
    {
        assert(m_vk_device);
        assert(m_dispatch.pfn_vkDestroySwapchainKHR);
        m_dispatch.pfn_vkDestroySwapchainKHR(m_vk_device, m_vk_swapchain, nullptr);
    }
    m_dispatch     = {};
    m_vk_device    = VK_NULL_HANDLE;
    m_vk_swapchain = VK_NULL_HANDLE;
    m_vk_images.clear();
    m_virtual_images.clear();
}

VkResult VulkanVirtualSwapchain::GetSwapchainImagesKHR(uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{
    auto vk_result = VK_INCOMPLETE;
    if (pSwapchainImageCount)
    {
        if (pSwapchainImages)
        {
            for (size_t i = 0; i < *pSwapchainImageCount && i < m_virtual_images.size(); ++i)
            {
                pSwapchainImages[i] = m_virtual_images[i].GetVkImage();
            }
            if (m_virtual_images.size() <= *pSwapchainImageCount)
            {
                vk_result = VK_SUCCESS;
            }
        }
        else
        {
            *pSwapchainImageCount = static_cast<uint32_t>(m_virtual_images.size());
            vk_result             = VK_SUCCESS;
        }
    }
    return vk_result;
}

VkResult VulkanVirtualSwapchain::AcquireNextImageKHR(uint64_t    timeout,
                                                     VkSemaphore vkSemaphore,
                                                     VkFence     vkFence,
                                                     uint32_t*   pImageIndex)
{
    VkAcquireNextImageInfoKHR acquireNextImageInfo{};
    acquireNextImageInfo.sType     = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
    acquireNextImageInfo.swapchain = m_vk_swapchain;
    acquireNextImageInfo.timeout   = timeout;
    acquireNextImageInfo.semaphore = vkSemaphore;
    acquireNextImageInfo.fence     = vkFence;
    return AcquireNextImage2KHR(&acquireNextImageInfo, pImageIndex);
}

VkResult VulkanVirtualSwapchain::AcquireNextImage2KHR(const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                      uint32_t*                        pImageIndex)
{
    auto vkResult = VK_ERROR_UNKNOWN;
    return vkResult;
}

VkResult VulkanVirtualSwapchain::QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
{
    auto vkResult = VK_ERROR_UNKNOWN;
    return vkResult;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
