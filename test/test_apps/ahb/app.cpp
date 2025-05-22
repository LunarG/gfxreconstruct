/*
** Copyright (c) 2025 LunarG, Inc.
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

#include "ahb_app.h"

#include <iostream>
#include <array>
#include <vulkan/vulkan_core.h>
#include <util/logging.h>
#include <android/hardware_buffer.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(ahb)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }
    instance_builder.enable_extension(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                             vkmock::TestConfig*           test_config)
{
    phys_device_selector.add_required_extension(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_MAINTENANCE1_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_BIND_MEMORY_2_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_EXTENSION_NAME);
}

void App::configure_swapchain_builder(test::SwapchainBuilder& swapchain_builder, vkmock::TestConfig* test_config)
{
    swapchain_builder.add_image_usage_flags(VK_IMAGE_USAGE_TRANSFER_DST_BIT);
}

void App::recreate_swapchain()
{
    init.disp.deviceWaitIdle();
    TestAppBase::recreate_swapchain(false);
}

const int NUM_FRAMES = 10;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain();
        return IS_RUNNING(frame_num);
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw gfxrecon::test::vulkan_exception("failed to acquire next image", result);
    }

    if (sync_.image_in_flight[image_index] != VK_NULL_HANDLE)
    {
        init.disp.waitForFences(1, &sync_.image_in_flight[image_index], VK_TRUE, UINT64_MAX);
    }
    sync_.image_in_flight[image_index] = sync_.in_flight_fences[current_frame_];

    init.disp.resetCommandPool(command_pools_[current_frame_], 0);
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[current_frame_];
    VkCommandBuffer command_buffer;
    result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(command_buffer, &begin_info);
        VERIFY_VK_RESULT("failed to create command buffer", result);

        copy_ahb_image_to_color_image(command_buffer, init.swapchain_images[image_index]);

        {
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_TRANSFER_WRITE_BIT;
            image_barrier.dstAccessMask               = VK_ACCESS_NONE;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        result = init.disp.endCommandBuffer(command_buffer);
        VERIFY_VK_RESULT("failed to end command buffer", result);
    }

    VkSubmitInfo submitInfo = {};
    submitInfo.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore          wait_semaphores[] = { sync_.available_semaphores[current_frame_] };
    VkPipelineStageFlags wait_stages[]     = { VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT };
    submitInfo.waitSemaphoreCount          = 1;
    submitInfo.pWaitSemaphores             = wait_semaphores;
    submitInfo.pWaitDstStageMask           = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers    = &command_buffer;

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[current_frame_] };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores    = signal_semaphores;

    init.disp.resetFences(1, &sync_.in_flight_fences[current_frame_]);

    result = init.disp.queueSubmit(graphics_queue_, 1, &submitInfo, sync_.in_flight_fences[current_frame_]);
    VERIFY_VK_RESULT("failed to submit queue", result);

    VkPresentInfoKHR present_info = {};
    present_info.sType            = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    present_info.waitSemaphoreCount = 1;
    present_info.pWaitSemaphores    = signal_semaphores;

    VkSwapchainKHR swapChains[] = { init.swapchain };
    present_info.swapchainCount = 1;
    present_info.pSwapchains    = swapChains;

    present_info.pImageIndices = &image_index;

    result = init.disp.queuePresentKHR(present_queue_, &present_info);
    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR)
    {
        recreate_swapchain();
        return frame_num >= NUM_FRAMES;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return IS_RUNNING(frame_num);
}

void App::cleanup()
{
    init.disp.freeMemory(image_memory_, nullptr);
    init.disp.destroyImage(image_, nullptr);
    AHardwareBuffer_release(ahb_);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
    {
        init.disp.destroySemaphore(sync_.finished_semaphore[i], nullptr);
        init.disp.destroySemaphore(sync_.available_semaphores[i], nullptr);
        init.disp.destroyFence(sync_.in_flight_fences[i], nullptr);
    }

    for (auto command_pool : command_pools_)
    {
        init.disp.destroyCommandPool(command_pool, nullptr);
    }
}

void App::get_queues()
{
    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(gfxrecon::test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;
}

void App::create_command_pools()
{
    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = gfxrecon::test::create_command_pool(init.disp, *queue_family_index);
    }
}

uint32_t App::find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags)
{
    VkPhysicalDeviceMemoryProperties memory_properties;
    init.inst_disp.getPhysicalDeviceMemoryProperties(init.physical_device, &memory_properties);

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((memoryTypeBits & (1 << i)) && (memory_properties.memoryTypes[i].propertyFlags & memory_property_flags) > 0)
        {
            return i;
            break;
        }
    }

    throw std::runtime_error("Could not find required memory type");
}

void App::create_ahb()
{
    image_width_  = init.swapchain.extent.width;
    image_height_ = init.swapchain.extent.height;

    AHardwareBuffer_Desc desc = {};
    desc.format               = AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM;
    desc.width                = image_width_;
    desc.height               = image_height_;
    desc.layers               = 1;
    desc.usage                = AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE;

    int ahb_result = AHardwareBuffer_allocate(&desc, &ahb_);
    if (ahb_result != 0)
    {
        throw std::runtime_error("Failed to allocate Android hardware buffer");
    }
}

void App::import_ahb_as_image()
{
    GFXRECON_ASSERT(ahb_ != nullptr);

    VkAndroidHardwareBufferFormatPropertiesANDROID format_properties = {
        VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID
    };

    VkAndroidHardwareBufferPropertiesANDROID properties = {
        VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, &format_properties
    };

    VkResult result = init.disp.getAndroidHardwareBufferPropertiesANDROID(ahb_, &properties);
    VERIFY_VK_RESULT("failed to get AHB properties", result);
    GFXRECON_ASSERT(format_properties.format = VK_FORMAT_R8G8B8A8_UNORM);

    ahb_size_ = properties.allocationSize;
    GFXRECON_ASSERT(ahb_size_ != 0);

    VkExternalMemoryImageCreateInfo external_memory_image_create_info = {
        VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO
    };
    external_memory_image_create_info.handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;

    VkImageUsageFlags image_usage  = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    VkImageLayout     final_layout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

    VkImageCreateInfo image_info{ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    image_info.pNext                 = &external_memory_image_create_info;
    image_info.flags                 = 0u;
    image_info.imageType             = VK_IMAGE_TYPE_2D;
    image_info.format                = format_properties.format;
    image_info.extent                = { image_width_, image_height_, 1 };
    image_info.mipLevels             = 1u;
    image_info.arrayLayers           = 1u;
    image_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    image_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage                 = image_usage;
    image_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    image_info.queueFamilyIndexCount = 0u;
    image_info.pQueueFamilyIndices   = nullptr;
    image_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    result = init.disp.createImage(&image_info, nullptr, &image_);
    VERIFY_VK_RESULT("failed to create image", result);

    VkImportAndroidHardwareBufferInfoANDROID import_ahb_info = {
        VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID
    };
    import_ahb_info.buffer = ahb_;

    VkMemoryDedicatedAllocateInfo dedicated_allocate_info = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO };
    dedicated_allocate_info.pNext                         = &import_ahb_info;
    dedicated_allocate_info.image                         = image_;

    VkMemoryAllocateInfo memory_allocate_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    memory_allocate_info.pNext                = &dedicated_allocate_info;
    memory_allocate_info.allocationSize       = ahb_size_;
    uint32_t memory_index = find_memory_type(properties.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    memory_allocate_info.memoryTypeIndex = memory_index;

    result = init.disp.allocateMemory(&memory_allocate_info, nullptr, &image_memory_);
    VERIFY_VK_RESULT("failed to allocate memory", result);

    result = init.disp.bindImageMemory(image_, image_memory_, 0);
    VERIFY_VK_RESULT("failed to bind memory to image", result);
}

VkCommandBuffer App::allocate_command_buffer(VkCommandPool command_pool)
{
    VkCommandBufferAllocateInfo command_buffer_allocate_info;
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.pNext              = nullptr;
    command_buffer_allocate_info.commandPool        = command_pool;
    command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = 1u;

    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    VkResult        result         = init.disp.allocateCommandBuffers(&command_buffer_allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);
    return command_buffer;
}

void App::fill_ahb_image()
{
    GFXRECON_ASSERT(image_ != VK_NULL_HANDLE);

    // create staging buffer
    VkBufferCreateInfo create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.size               = ahb_size_;
    create_info.usage              = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

    VkBuffer staging_buffer = VK_NULL_HANDLE;
    VkResult result         = init.disp.createBuffer(&create_info, nullptr, &staging_buffer);
    VERIFY_VK_RESULT("failed to create staging buffer", result);

    VkMemoryRequirements memory_reqs = {};
    init.disp.getBufferMemoryRequirements(staging_buffer, &memory_reqs);
    GFXRECON_ASSERT(memory_reqs.size >= ahb_size_);

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.allocationSize       = memory_reqs.size;
    alloc_info.memoryTypeIndex      = find_memory_type(
        memory_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

    VkDeviceMemory staging_memory = VK_NULL_HANDLE;
    result                        = init.disp.allocateMemory(&alloc_info, nullptr, &staging_memory);
    VERIFY_VK_RESULT("failed to allocate staging memory", result);

    result = init.disp.bindBufferMemory(staging_buffer, staging_memory, 0);
    VERIFY_VK_RESULT("failed to bind memory to staging buffer", result);

    // fill staging buffer
    {
        void* staging_ptr = nullptr;
        result            = init.disp.mapMemory(staging_memory, 0, ahb_size_, 0, &staging_ptr);
        VERIFY_VK_RESULT("failed to map staging memory", result);

        const uint32_t channel_count = 4; // RGBA
        for (uint32_t y = 0; y < image_height_; ++y)
        {
            for (uint32_t x = 0; x < image_width_; ++x)
            {
                const uint32_t pixel_offset = x + y * image_width_;
                const uint32_t byte_offset  = pixel_offset * channel_count;
                uint8_t*       r_channel    = static_cast<uint8_t*>(staging_ptr) + byte_offset;
                uint8_t*       g_channel    = r_channel + 1;
                uint8_t*       b_channel    = g_channel + 1;
                uint8_t*       a_channel    = b_channel + 1;

                *r_channel = (255 * x) / image_width_;
                *g_channel = (255 * y) / image_height_;
                *b_channel = (*r_channel + *g_channel) / 2;
                *a_channel = 255;
            }
        }

        init.disp.unmapMemory(staging_memory);
    }

    // copy command from staging buffer to image
    VkFenceCreateInfo fence_create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };

    VkFence fence = VK_NULL_HANDLE;
    init.disp.createFence(&fence_create_info, nullptr, &fence);

    VkCommandBuffer command_buffer = allocate_command_buffer(command_pools_[0]);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };

    result = init.disp.beginCommandBuffer(command_buffer, &begin_info);
    VERIFY_VK_RESULT("failed to begin command buffer", result);

    VkBufferImageCopy buffer_image_copy;
    buffer_image_copy.bufferOffset                    = 0u;
    buffer_image_copy.bufferRowLength                 = 0u;
    buffer_image_copy.bufferImageHeight               = 0u;
    buffer_image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    buffer_image_copy.imageSubresource.mipLevel       = 0u;
    buffer_image_copy.imageSubresource.baseArrayLayer = 0u;
    buffer_image_copy.imageSubresource.layerCount     = 1u;
    buffer_image_copy.imageOffset                     = { 0, 0, 0 };
    buffer_image_copy.imageExtent                     = { image_width_, image_height_, 1u };
    init.disp.cmdCopyBufferToImage(
        command_buffer, staging_buffer, image_, VK_IMAGE_LAYOUT_GENERAL, 1u, &buffer_image_copy);

    result = init.disp.endCommandBuffer(command_buffer);
    VERIFY_VK_RESULT("failed to end command buffer", result);

    VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.commandBufferCount = 1u;
    submit_info.pCommandBuffers    = &command_buffer;

    result = init.disp.queueSubmit(graphics_queue_, 1u, &submit_info, fence);
    VERIFY_VK_RESULT("failed to submit command buffer", result);

    // wait for it to finish
    result = init.disp.waitForFences(1u, &fence, VK_TRUE, UINT64_MAX);
    VERIFY_VK_RESULT("failed to wait for fences", result);

    // destroy objects
    init.disp.destroyFence(fence, nullptr);
    init.disp.freeCommandBuffers(command_pools_[0], 1, &command_buffer);
    init.disp.freeMemory(staging_memory, nullptr);
    init.disp.destroyBuffer(staging_buffer, nullptr);
}

void App::copy_ahb_image_to_color_image(VkCommandBuffer command_buffer, VkImage color_image)
{
    GFXRECON_ASSERT(image_ != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    // Prepare images for copy
    std::array<VkImageMemoryBarrier, 2> barriers = {};

    barriers[0].sType            = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barriers[0].oldLayout        = VK_IMAGE_LAYOUT_UNDEFINED;
    barriers[0].newLayout        = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    barriers[0].srcAccessMask    = VK_ACCESS_NONE;
    barriers[0].dstAccessMask    = VK_ACCESS_TRANSFER_READ_BIT;
    barriers[0].subresourceRange = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };
    barriers[0].image            = image_;

    barriers[1].sType            = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barriers[1].oldLayout        = VK_IMAGE_LAYOUT_UNDEFINED;
    barriers[1].newLayout        = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    barriers[1].dstAccessMask    = VK_ACCESS_TRANSFER_WRITE_BIT;
    barriers[1].subresourceRange = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };
    barriers[1].image            = color_image;

    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 barriers.size(),
                                 barriers.data());

    VkImageCopy copy    = {};
    copy.extent         = { image_width_, image_height_, 1 };
    copy.srcSubresource = VkImageSubresourceLayers{ VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 };
    copy.dstSubresource = copy.srcSubresource;

    init.disp.cmdCopyImage(command_buffer,
                           image_,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           color_image,
                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                           1,
                           &copy);
}

void App::setup()
{
    get_queues();
    create_command_pools();
    create_ahb();
    import_ahb_as_image();
    fill_ahb_image();

    sync_ = gfxrecon::test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);
}

GFXRECON_END_NAMESPACE(ahb)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
