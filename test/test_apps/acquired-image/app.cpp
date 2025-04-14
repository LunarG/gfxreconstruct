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

#include <iostream>

#include <vulkan/vulkan_core.h>

#include <test_app_base.h>

#include <SDL3/SDL_main.h>

#include <util/logging.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(acquired_image)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

class App : public gfxrecon::test::TestAppBase
{
  public:
    App() = default;

  private:
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    std::vector<VkSwapchainKHR> old_swapchains_;
    VkSemaphore                 initial_semaphore_ = VK_NULL_HANDLE;
    test::Sync                  sync_;

    uint32_t       staging_memory_size_ = 0;
    VkDeviceMemory staging_memory_      = VK_NULL_HANDLE;
    VkBuffer       staging_buffer_      = VK_NULL_HANDLE;

    VkCommandBuffer create_and_begin_command_buffer();
    void            recreate_swapchain();
    void            cleanup() override;
    bool            frame(const int frame_num) override;
    void            setup() override;

    void create_staging_buffer();
    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;

    void configure_swapchain_builder(test::SwapchainBuilder& swapchain_builder,
                                     vkmock::TestConfig*     test_config) override;
};

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::configure_swapchain_builder(test::SwapchainBuilder& swapchain_builder, vkmock::TestConfig* test_config)
{
    GFXRECON_UNREFERENCED_PARAMETER(test_config);
    swapchain_builder.set_destroy_old_swapchain(false);
    swapchain_builder.add_image_usage_flags(VK_IMAGE_USAGE_TRANSFER_DST_BIT);
}

void App::recreate_swapchain()
{
    old_swapchains_.push_back(init.swapchain.swapchain);
    TestAppBase::recreate_swapchain(false);
}

VkCommandBuffer App::create_and_begin_command_buffer()
{
    init.disp.resetCommandPool(command_pools_[current_frame_], 0);

    VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[current_frame_];
    VkCommandBuffer command_buffer            = VK_NULL_HANDLE;
    VkResult        result                    = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);

    VkCommandBufferBeginInfo begin_info{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    result = init.disp.beginCommandBuffer(command_buffer, &begin_info);
    VERIFY_VK_RESULT("failed to begin command buffer", result);

    return command_buffer;
}

const int NUM_FRAMES = 10;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = VK_SUCCESS;

    VkCommandBuffer command_buffer  = VK_NULL_HANDLE;
    VkImage         swapchain_image = VK_NULL_HANDLE;

    if (frame_num == 0)
    {
        result =
            init.disp.acquireNextImageKHR(init.swapchain, UINT64_MAX, initial_semaphore_, VK_NULL_HANDLE, &image_index);

        swapchain_image = init.swapchain_images[image_index];

        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw test::vulkan_exception("failed to acquire first image", result);
        }

        // Recreate swapchain using old swapchain and continue as nothing happened
        recreate_swapchain();

        // Use previosly acquired image for some command
        command_buffer = create_and_begin_command_buffer();

        {
            VkImageMemoryBarrier image_barrier        = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
            image_barrier.image                       = swapchain_image;
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_NONE;
            image_barrier.dstAccessMask               = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }
    }

    result = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain();
        return IS_RUNNING(frame_num);
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw test::vulkan_exception("failed to acquire next image", result);
    }

    if (sync_.image_in_flight[image_index] != VK_NULL_HANDLE)
    {
        init.disp.waitForFences(1, &sync_.image_in_flight[image_index], VK_TRUE, UINT64_MAX);
    }
    sync_.image_in_flight[image_index] = sync_.in_flight_fences[current_frame_];

    if (command_buffer == VK_NULL_HANDLE)
    {
        command_buffer = create_and_begin_command_buffer();
    }

    {
        VkImageMemoryBarrier image_barrier        = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        image_barrier.image                       = init.swapchain_images[image_index];
        image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.newLayout                   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
        image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
        image_barrier.srcAccessMask               = VK_ACCESS_NONE;
        image_barrier.dstAccessMask               = VK_ACCESS_TRANSFER_WRITE_BIT;
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &image_barrier);
    }

    VkBufferImageCopy buffer_image_copy               = {};
    buffer_image_copy.bufferOffset                    = 0u;
    buffer_image_copy.bufferRowLength                 = 0u;
    buffer_image_copy.bufferImageHeight               = 0u;
    buffer_image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    buffer_image_copy.imageSubresource.mipLevel       = 0u;
    buffer_image_copy.imageSubresource.baseArrayLayer = 0u;
    buffer_image_copy.imageSubresource.layerCount     = 1u;
    buffer_image_copy.imageOffset                     = { 0, 0, 0 };
    buffer_image_copy.imageExtent = { init.swapchain.extent.width, init.swapchain.extent.height, 1 };
    init.disp.cmdCopyBufferToImage(command_buffer,
                                   staging_buffer_,
                                   init.swapchain_images[image_index],
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   1u,
                                   &buffer_image_copy);

    {
        VkImageMemoryBarrier image_barrier        = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
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

    VkSubmitInfo submitInfo = { VK_STRUCTURE_TYPE_SUBMIT_INFO };

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

    VkPresentInfoKHR present_info   = { VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
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

void App::create_staging_buffer()
{
    VkImage              swapchain_image = init.swapchain_images[0];
    VkMemoryRequirements image_mem_reqs  = {};
    init.disp.getImageMemoryRequirements(swapchain_image, &image_mem_reqs);
    staging_memory_size_ = image_mem_reqs.size;

    VkBufferCreateInfo create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.size               = staging_memory_size_;
    create_info.usage              = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

    VkResult result = init.disp.createBuffer(&create_info, nullptr, &staging_buffer_);
    VERIFY_VK_RESULT("failed to create staging buffer", result);

    VkMemoryRequirements mem_reqs = {};
    init.disp.getBufferMemoryRequirements(staging_buffer_, &mem_reqs);
    GFXRECON_ASSERT(mem_reqs.size >= staging_memory_size_);

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.allocationSize       = mem_reqs.size;
    alloc_info.memoryTypeIndex      = find_memory_type(
        mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

    result = init.disp.allocateMemory(&alloc_info, nullptr, &staging_memory_);
    VERIFY_VK_RESULT("failed to allocate staging memory", result);

    result = init.disp.bindBufferMemory(staging_buffer_, staging_memory_, 0);
    VERIFY_VK_RESULT("failed to bind memory to staging buffer", result);

    if (init.test_config != nullptr)
    {
        // Skip memory fill when testing with mock driver
        return;
    }

    // Fill with initial content
    void* staging_ptr = nullptr;
    result            = init.disp.mapMemory(staging_memory_, 0, staging_memory_size_, 0, &staging_ptr);
    VERIFY_VK_RESULT("failed to map staging memory", result);

    const uint32_t channel_count = 4; // RGBA
    const uint32_t width         = init.swapchain.extent.width;
    const uint32_t height        = init.swapchain.extent.height;
    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            const uint32_t pixel_offset = x + y * width;
            const uint32_t byte_offset  = pixel_offset * channel_count;
            uint8_t*       r_channel    = static_cast<uint8_t*>(staging_ptr) + byte_offset;
            uint8_t*       g_channel    = r_channel + 1;
            uint8_t*       b_channel    = g_channel + 1;

            *r_channel = (255 * x) / width;
            *g_channel = (255 * y) / height;
            *b_channel = (*r_channel + *g_channel) / 2;
        }
    }

    init.disp.unmapMemory(staging_memory_);
}

void App::cleanup()
{
    for (auto swapchain : old_swapchains_)
    {
        init.disp.destroySwapchainKHR(swapchain, nullptr);
    }
    init.disp.destroySemaphore(initial_semaphore_, nullptr);

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

    init.disp.freeMemory(staging_memory_, nullptr);
    init.disp.destroyBuffer(staging_buffer_, nullptr);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(gfxrecon::test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = gfxrecon::test::create_command_pool(init.disp, *queue_family_index);
    }

    VkSemaphoreCreateInfo semaphore_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
    VkResult              result         = init.disp.createSemaphore(&semaphore_info, nullptr, &initial_semaphore_);
    VERIFY_VK_RESULT("failed to create initial semaphore", result);

    sync_ = gfxrecon::test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    create_staging_buffer();
}

GFXRECON_END_NAMESPACE(acquired_image)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

int main(int argc, char* argv[])
{
    try
    {
        gfxrecon::test_app::acquired_image::App app{};
        app.run("acquired-image");
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
