/*
** Copyright (c) 2024 LunarG, Inc.
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
#if ENABLE_OPENXR_SUPPORT

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include "decode/openxr_replay_swapchain_state.h"
// #include "decode/vulkan_replay_consumer_base.h"

#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(openxr)

void SwapchainData::InitSwapchainData(const GraphicsBinding&       binding,
                                      const XrSwapchainCreateInfo& info,
                                      XrSwapchain                  replay_handle)
{
    // Save off a reference to the session's graphics binding information
    graphics_binding_ = &binding;

    // Store off a shallow copy
    create_info_      = info;
    create_info_.next = nullptr; // Add supported deep copies below

    if (binding.IsVulkan())
    {
        // The type of the swapchain must match the type of the session
        swapchain_graphics_info_.type = GraphicsBindingType::kVulkan;
        swapchain_graphics_info_.vulkan_info.emplace();
        InitSwapchainData(info, *swapchain_graphics_info_.vulkan_info);
    }
    else
    {
        // WIP: Properly log and handle this
        // WIP: For now catch this to ensure we don't need support
        GFXRECON_LOG_FATAL("Unsupported graphics binding");
    }
}

XrResult SwapchainData::ImportReplaySwapchain(StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    XrResult                    result             = XR_SUCCESS;
    XrSwapchainImageBaseHeader* replay_images      = images->GetOutputPointer();
    size_t                      replay_image_count = images->GetOutputLength();

    if (replay_image_count == 0)
    {
        return result;
    }
    assert(replay_images);

    if (graphics_binding_->IsVulkan())
    {
        XrSwapchainImageVulkanKHR* vk_images = reinterpret_cast<XrSwapchainImageVulkanKHR*>(replay_images);
        assert(vk_images->type == XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR);
        assert(swapchain_graphics_info_.vulkan_info.has_value());
        VulkanSwapchainInfo& vk_info = *swapchain_graphics_info_.vulkan_info;
        vk_info.replay_images = std::vector<XrSwapchainImageVulkanKHR>(vk_images, vk_images + replay_image_count);
    }
    else
    {
        result = XR_ERROR_RUNTIME_FAILURE; // Our version of replay can't handle any other binding than those above
    }

    return result;
}

XrResult SwapchainData::InitVirtualSwapchain(PointerDecoder<uint32_t>*                                 imageCountOutput,
                                             StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* capture_images)
{
    // This call is invalid without a Session with a graphics binding specified
    assert(graphics_binding_);

    XrResult result = XR_ERROR_API_VERSION_UNSUPPORTED; // WIP: Determine if there is a better code for this

    if (graphics_binding_->IsVulkan())
    {
        auto* vk_capture_images =
            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>*>(capture_images);
        result = InitVirtualSwapchain(imageCountOutput, vk_capture_images);
    }
    else
    {
        // This call is only supported for Vulkan graphics bindings
        // WIP: Properly log and handle this
        GFXRECON_LOG_FATAL("Unsupported graphics binding");
        return XR_ERROR_RUNTIME_FAILURE;
    }
    return result;
}

XrResult SwapchainData::InitVirtualSwapchain(PointerDecoder<uint32_t>*                                imageCountOutput,
                                             StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>* capture_images)
{

    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding     = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device      = vk_binding.device;
    const format::HandleId       device_id      = vk_binding.device_id;
    const VkPhysicalDevice       vk_physical    = vk_binding.physicalDevice;
    auto*                        device_table   = vk_binding.device_table;
    auto*                        instance_table = vk_binding.instance_table;

    assert(swapchain_graphics_info_.vulkan_info.has_value());
    VulkanSwapchainInfo& vk_swap = *swapchain_graphics_info_.vulkan_info;

    // Allocate command buffers
    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                                            nullptr,
                                            VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                                            vk_binding.queueFamilyIndex };

    VkResult vk_result = device_table->CreateCommandPool(vk_device, &create_info, nullptr, &vk_swap.command_pool);
    // WIP: Properly log and handle this
    assert(vk_result == VK_SUCCESS);

    VkCommandBufferAllocateInfo cb_alloc_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        nullptr,
        vk_swap.command_pool,
        VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        1,
    };

    VkFenceCreateInfo cb_fence_info = {
        VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        nullptr,
        VK_FENCE_CREATE_SIGNALED_BIT // The first thing we do is wait on the signal
    };

    // Create the virtual images
    uint32_t* output_count = imageCountOutput->GetPointer();
    assert(output_count);

    const Decoded_XrSwapchainImageVulkanKHR* wrappers = capture_images->GetMetaStructPointer();

    VulkanSwapchainInfo::ProxyImage proxy;

    vk_swap.proxy_images.reserve(*output_count);

    for (uint32_t image_entry = 0; image_entry < *output_count; image_entry++)
    {
        const format::HandleId& image_id = wrappers[image_entry].image;

        vk_result = device_table->CreateImage(vk_device, &vk_swap.image_create_info, nullptr, &proxy.image);
        // WIP: Properly log and handle this
        assert(vk_result == VK_SUCCESS);

        VkMemoryRequirements memory_reqs{};
        device_table->GetImageMemoryRequirements(vk_device, proxy.image, &memory_reqs);

        VkMemoryPropertyFlags property_flags    = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
        uint32_t              memory_type_index = std::numeric_limits<uint32_t>::max();
        {
            VkPhysicalDeviceMemoryProperties properties;
            instance_table->GetPhysicalDeviceMemoryProperties(vk_physical, &properties);

            for (uint32_t i = 0; i < properties.memoryTypeCount; i++)
            {
                if ((memory_reqs.memoryTypeBits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & property_flags) != 0))
                {
                    memory_type_index = i;
                    break;
                }
            }
            assert(memory_type_index != std::numeric_limits<uint32_t>::max());
        }

        if (memory_type_index == std::numeric_limits<uint32_t>::max())
        {
            // WIP: Properly log and handle this
            break;
        }

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        vk_result = device_table->AllocateMemory(vk_device, &alloc_info, nullptr, &proxy.memory);

        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->BindImageMemory(vk_device, proxy.image, proxy.memory, 0);

        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->AllocateCommandBuffers(vk_device, &cb_alloc_info, &proxy.command_buffer);
        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        vk_result = device_table->CreateFence(vk_device, &cb_fence_info, nullptr, &proxy.cb_fence);
        if (vk_result != VK_SUCCESS)
        {
            // WIP: Properly log and handle this
            break;
        }

        // Now tell the Vulkan Consumer to map the proxy image to the matching captured image id
        VulkanImageInfo handle_info;
        handle_info.handle             = proxy.image;
        handle_info.memory             = proxy.memory;
        handle_info.is_swapchain_image = true;
        vk_binding.vulkan_consumer->AddImageHandle(device_id, image_id, proxy.image, std::move(handle_info));

        vk_swap.proxy_images.emplace_back(proxy);

        // Safe the unwind on sucess
        proxy = VulkanSwapchainInfo::ProxyImage();
    }

    if (vk_result != VK_SUCCESS)
    {
        xr_result = XR_ERROR_VALIDATION_FAILURE; // WIP: Determine if there is a better code for this
    }

    // If we failed above, need to unwind any work in progress.
    // WIP: Decide what to do about partial swapchain construction
    if (proxy.memory != VK_NULL_HANDLE)
    {
        device_table->FreeMemory(vk_device, proxy.memory, nullptr);
    }

    if (proxy.image != VK_NULL_HANDLE)
    {
        device_table->DestroyImage(vk_device, proxy.image, nullptr);
    }

    if (proxy.command_buffer != VK_NULL_HANDLE)
    {
        device_table->DestroyFence(vk_device, proxy.cb_fence, nullptr);
    }

    if (proxy.command_buffer != VK_NULL_HANDLE)
    {
        device_table->FreeCommandBuffers(vk_device, vk_swap.command_pool, 1, &proxy.command_buffer);
    }

    return xr_result;
}

XrResult SwapchainData::AcquireSwapchainImage(uint32_t capture_index, uint32_t replay_index)
{
    capture_to_replay_map_[capture_index] = replay_index;
    acquire_release_fifo_.push_front(capture_index);

    if (graphics_binding_->IsVulkan())
    {
        return AcquireSwapchainImage(capture_index, replay_index, *swapchain_graphics_info_.vulkan_info);
    }

    // WIP: Properly log and handle this
    GFXRECON_LOG_FATAL("Unsupported graphics binding");
    return XR_ERROR_VALIDATION_FAILURE;
}

XrResult SwapchainData::ReleaseSwapchainImage(StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo)
{
    XrResult xr_result = XR_SUCCESS;

    if (graphics_binding_->IsVulkan())
    {
        return ReleaseSwapchainImage(releaseInfo, *swapchain_graphics_info_.vulkan_info);
    }

    // WIP: Properly log and handle this
    GFXRECON_LOG_FATAL("Unsupported graphics binding");
    return XR_ERROR_VALIDATION_FAILURE;
}

void SwapchainData::WaitedWithoutTimeout()
{
    // WIP: Do we need to track anything here?
    // The calling order will be enforced by the runtime at replay time, and if the application
    // didn't handle XR_TIMEOUT correctly, that's an invalid trace, which the replay runtime may respond poorly
    // to, but it's unsure whether we can do anything about it.
}

void SwapchainData::Clear()
{
    if (graphics_binding_->IsVulkan())
    {
        Clear(*swapchain_graphics_info_.vulkan_info);
        swapchain_graphics_info_.vulkan_info.reset();
    }
}

void SwapchainData::Clear(VulkanSwapchainInfo& vk_swap)
{
    assert(graphics_binding_->IsVulkan());
    const VulkanGraphicsBinding& vk_binding   = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device    = vk_binding.device;
    auto*                        device_table = vk_binding.device_table;

    for (auto& proxy : vk_swap.proxy_images)
    {
        device_table->DestroyImage(vk_device, proxy.image, nullptr);
        device_table->FreeMemory(vk_device, proxy.memory, nullptr);
        device_table->DestroyFence(vk_device, proxy.cb_fence, nullptr);
    }

    vk_swap.proxy_images.clear();
    device_table->DestroyCommandPool(vk_device, vk_swap.command_pool, nullptr);
    vk_swap.command_pool = VK_NULL_HANDLE;
}

XrResult SwapchainData::AcquireSwapchainImage(uint32_t capture_index, uint32_t replay_index, VulkanSwapchainInfo& swap)
{
    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding   = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device    = vk_binding.device;
    auto*                        device_table = vk_binding.device_table;

    VulkanSwapchainInfo::ProxyImage& proxy = swap.proxy_images[capture_index];
    xr_result                              = vk_binding.ResetCommandBuffer(proxy);
    if (!XR_SUCCEEDED(xr_result))
    {
        assert(XR_SUCCEEDED(xr_result));
        return xr_result;
    }

    VkCommandBufferBeginInfo cb_begin = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                     nullptr,
                                     VK_ACCESS_MEMORY_READ_BIT |
                                         VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
                                     VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                                     VK_IMAGE_LAYOUT_UNDEFINED,
                                     swap.layout,
                                     VK_QUEUE_FAMILY_IGNORED,
                                     VK_QUEUE_FAMILY_IGNORED,
                                     proxy.image,
                                     swap.whole_range };

    VkResult vk_result = device_table->BeginCommandBuffer(proxy.command_buffer, &cb_begin);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &barrier);
    vk_result = device_table->EndCommandBuffer(proxy.command_buffer);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0,      nullptr, nullptr, 1,
                                 &proxy.command_buffer,         0,       nullptr };
    vk_result                = device_table->QueueSubmit(vk_binding.queue, 1, &submit_info, proxy.cb_fence);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    return XR_SUCCESS;
}

XrResult SwapchainData::ReleaseSwapchainImage(StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo,
                                              VulkanSwapchainInfo&                                       vk_swap)
{

    // Unpack the graphics binding info, we shouldn't be called unless the binding *is* Vulkan
    assert(graphics_binding_->IsVulkan());

    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    const VulkanGraphicsBinding& vk_binding     = graphics_binding_->GetVulkanBinding();
    const VkDevice               vk_device      = vk_binding.device;
    const format::HandleId       device_id      = vk_binding.device_id;
    const VkPhysicalDevice       vk_physical    = vk_binding.physicalDevice;
    auto*                        device_table   = vk_binding.device_table;
    auto*                        instance_table = vk_binding.instance_table;

    // Copy the head of the AcquireRelease FIFO from the proxy image to the replay image
    assert(!acquire_release_fifo_.empty());
    uint32_t capture_index = acquire_release_fifo_.back();
    acquire_release_fifo_.pop_back();
    auto replay_it = capture_to_replay_map_.find(capture_index);
    assert(replay_it != capture_to_replay_map_.end());
    uint32_t replay_index = replay_it->second;
    VkImage  replay_image = vk_swap.replay_images[replay_index].image;
    capture_to_replay_map_.erase(replay_it);

    VulkanSwapchainInfo::ProxyImage& proxy = vk_swap.proxy_images[capture_index];
    xr_result                              = vk_binding.ResetCommandBuffer(proxy);
    assert(XR_SUCCEEDED(xr_result));

    VkCommandBufferBeginInfo cb_begin = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr
    };

    VkImageMemoryBarrier barriers[2] = {
        { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
          nullptr,
          VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
          VK_ACCESS_TRANSFER_READ_BIT,
          vk_swap.layout,
          VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
          VK_QUEUE_FAMILY_IGNORED,
          VK_QUEUE_FAMILY_IGNORED,
          proxy.image,
          vk_swap.whole_range },
        { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
          nullptr,
          VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT, // WIP: Determine the optimal set of accesses
          VK_ACCESS_TRANSFER_WRITE_BIT,
          vk_swap.layout,
          VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
          VK_QUEUE_FAMILY_IGNORED,
          VK_QUEUE_FAMILY_IGNORED,
          replay_image,
          vk_swap.whole_range }

    };

    VkResult vk_result = device_table->BeginCommandBuffer(proxy.command_buffer, &cb_begin);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     2,
                                     barriers);

    VkImageSubresourceLayers subres_layers = {
        vk_swap.whole_range.aspectMask, 0, vk_swap.whole_range.baseArrayLayer, vk_swap.whole_range.layerCount
    };
    VkOffset3D zero_offset = { 0, 0, 0 };
    VkExtent3D mip_extent  = vk_swap.image_create_info.extent;

    VkImageCopy copy_region = {
        subres_layers, zero_offset, subres_layers, zero_offset, vk_swap.image_create_info.extent
    };

    uint32_t                 mip_count = vk_swap.image_create_info.mipLevels;
    std::vector<VkImageCopy> copy_regions;
    copy_regions.reserve(mip_count);
    for (uint32_t mip_level = 0; mip_level < mip_count; mip_level++)
    {
        subres_layers.mipLevel = mip_level;

        VkExtent3D mip_extent = vk_swap.image_create_info.extent;
        mip_extent.width >>= mip_level;
        mip_extent.height >>= mip_level;

        VkImageCopy copy_region = { subres_layers, zero_offset, subres_layers, zero_offset, mip_extent };
        copy_regions.push_back(copy_region);
    }

    device_table->CmdCopyImage(proxy.command_buffer,
                               proxy.image,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               replay_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               mip_count,
                               copy_regions.data());

    // Transition replay to the required layout
    // We'll defer the proxy image transition until the next acquire
    barriers[1].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    barriers[1].newLayout     = vk_swap.layout;
    barriers[1].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barriers[1].dstAccessMask =
        VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT; // WIP: Determine the optimal set of accesses

    device_table->CmdPipelineBarrier(proxy.command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &barriers[1]);
    vk_result = device_table->EndCommandBuffer(proxy.command_buffer);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr, 0,      nullptr, nullptr, 1,
                                 &proxy.command_buffer,         0,       nullptr };
    vk_result                = device_table->QueueSubmit(vk_binding.queue, 1, &submit_info, proxy.cb_fence);
    if (vk_result != VK_SUCCESS)
        return XR_ERROR_RUNTIME_FAILURE;

    return XR_SUCCESS;
}

void SwapchainData::MapVulkanSwapchainImageFlags(XrSwapchainUsageFlags xr_flags, VkImageCreateInfo& info)
{
    // NOTE: This is Vulkan specific.
    struct ImageUsageMap
    {
        XrSwapchainUsageFlags xr;
        VkImageUsageFlagBits  vk;
    };
    struct ImageCreateMap
    {
        XrSwapchainUsageFlags xr;
        VkImageCreateFlagBits vk;
    };
    static std::array<ImageUsageMap, 7> usage_map = {
        { { XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT },
          { XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT },
          { XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT, VK_IMAGE_USAGE_STORAGE_BIT },
          { XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT, VK_IMAGE_USAGE_TRANSFER_SRC_BIT },
          { XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT, VK_IMAGE_USAGE_TRANSFER_DST_BIT },
          { XR_SWAPCHAIN_USAGE_SAMPLED_BIT, VK_IMAGE_USAGE_SAMPLED_BIT },
          { XR_SWAPCHAIN_USAGE_INPUT_ATTACHMENT_BIT_KHR, VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT } }
    };
    static std::array<ImageCreateMap, 1> create_map = { {
        { XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT, VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT },
    } };

    XrSwapchainUsageFlags mapped_flags = 0;
    for (const auto& entry : usage_map)
    {
        if (entry.xr & xr_flags)
        {
            info.usage |= entry.vk;
            mapped_flags |= entry.xr;
        }
    }
    for (const auto& entry : create_map)
    {
        if (entry.xr & xr_flags)
        {
            info.flags |= entry.vk;
            mapped_flags |= entry.xr;
        }
    }
    // WIP: Properly log and handle this
    assert(xr_flags == mapped_flags);
}

XrResult SwapchainData::InitSwapchainData(const XrSwapchainCreateInfo& xr_info, VulkanSwapchainInfo& vk_swap)
{
    XrResult xr_result = XR_SUCCESS; // WIP: Determine if there is a better code for this

    // Set up the flags and usages
    VkImageCreateInfo& image_create_info = vk_swap.image_create_info;
    image_create_info                    = VkImageCreateInfo{ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO, nullptr };

    MapVulkanSwapchainImageFlags(xr_info.usageFlags, image_create_info);

    // Grab supported extension structs
    auto xr_info_meta = gfxrecon::util::GetNextOfType<XrVulkanSwapchainCreateInfoMETA>(xr_info.next);
    if (xr_info_meta)
    {
        // Apply the extension information
        image_create_info.usage |= xr_info_meta->additionalUsageFlags;
        image_create_info.flags |= xr_info_meta->additionalCreateFlags;

        // Backing store for the deep copy is within the VulkanSwapchainInfo
        vk_swap.xr_info_meta      = *xr_info_meta;
        vk_swap.xr_info_meta.next = nullptr;
        create_info_.next         = &vk_swap.xr_info_meta;
    }

    // Need to be able to copy to the real swapchain
    image_create_info.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;

    // Cube swapchains specific flags
    if (xr_info.faceCount == 6)
    {
        image_create_info.flags |= VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
    }

    // And the reset of the create info
    image_create_info.imageType = VK_IMAGE_TYPE_2D;
    image_create_info.format    = static_cast<VkFormat>(xr_info.format);
    VkExtent3D& extent          = image_create_info.extent;
    extent.width                = xr_info.width;
    extent.height               = xr_info.height;
    extent.depth                = 1U;
    image_create_info.mipLevels = xr_info.mipCount;

    // NOTE: Not sure if these are in face major or array major order, but shouldn't matter
    //       to replay unless runtimes vary.
    image_create_info.arrayLayers = xr_info.arraySize * xr_info.faceCount,

    image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.tiling  = VK_IMAGE_TILING_OPTIMAL;

    image_create_info.sharingMode   = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImageSubresourceRange& subres_range = vk_swap.whole_range;
    subres_range.aspectMask               = 0;
    subres_range.aspectMask |= vkuFormatHasDepth(image_create_info.format) ? VK_IMAGE_ASPECT_DEPTH_BIT : 0;
    subres_range.aspectMask |= vkuFormatHasStencil(image_create_info.format) ? VK_IMAGE_ASPECT_STENCIL_BIT : 0;

    if (subres_range.aspectMask)
    {
        vk_swap.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    }
    else if (vkuFormatIsColor(image_create_info.format))
    {
        subres_range.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        vk_swap.layout          = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }
    else
    {
        // WIP: Properly log and handle this
        assert(subres_range.aspectMask);
        vk_swap.layout = VK_IMAGE_LAYOUT_UNDEFINED;
    }

    subres_range.baseMipLevel   = 0;
    subres_range.levelCount     = image_create_info.mipLevels;
    subres_range.baseArrayLayer = 0;
    subres_range.layerCount     = image_create_info.arrayLayers;

    return xr_result;
}

GFXRECON_END_NAMESPACE(openxr)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
