/*
** Copyright (c) 2026 LunarG, Inc.
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

#include <serialize_compute_and_transfer_app.h>

#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(serialize_compute_and_transfer)

// SPIR-V for a trivial compute shader with no descriptors:
//   #version 450
//   layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
//   void main() {}
static const uint32_t kComputeShaderSpirv[] = {
    0x07230203, 0x00010000, 0x000d000b, 0x0000000a, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0005000f, 0x00000005,
    0x00000004, 0x6e69616d, 0x00000000, 0x00060010, 0x00000004, 0x00000011, 0x00000001, 0x00000001, 0x00000001,
    0x00030003, 0x00000002, 0x000001c2, 0x000a0004, 0x475f4c47, 0x4c474f4f, 0x70635f45, 0x74735f70, 0x5f656c79,
    0x656e696c, 0x7269645f, 0x69746365, 0x00006576, 0x00080004, 0x475f4c47, 0x4c474f4f, 0x6e695f45, 0x64756c63,
    0x69645f65, 0x74636572, 0x00657669, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00040047, 0x00000009,
    0x0000000b, 0x00000019, 0x00020013, 0x00000002, 0x00030021, 0x00000003, 0x00000002, 0x00040015, 0x00000006,
    0x00000020, 0x00000000, 0x00040017, 0x00000007, 0x00000006, 0x00000003, 0x0004002b, 0x00000006, 0x00000008,
    0x00000001, 0x0006002c, 0x00000007, 0x00000009, 0x00000008, 0x00000008, 0x00000008, 0x00050036, 0x00000002,
    0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005, 0x000100fd, 0x00010038
};

const VkDeviceSize BUFFER_SIZE = 256;

const int NUM_FRAMES = 3;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory)
{
    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = size;
    buffer_info.usage              = usage;
    buffer_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;
    VERIFY_VK_RESULT("failed to create buffer", init.disp.createBuffer(&buffer_info, nullptr, buffer));

    VkMemoryRequirements memory_requirements;
    init.disp.getBufferMemoryRequirements(*buffer, &memory_requirements);

    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex      = find_memory_type(
        memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    VERIFY_VK_RESULT("failed to allocate buffer memory", init.disp.allocateMemory(&allocate_info, nullptr, memory));

    VERIFY_VK_RESULT("failed to bind buffer memory", init.disp.bindBufferMemory(*buffer, *memory, 0));
}

void App::create_buffers()
{
    // Two buffers copied back and forth as the transfer work.
    create_buffer(BUFFER_SIZE,
                  VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &buffer_a_,
                  &buffer_a_memory_);
    create_buffer(BUFFER_SIZE,
                  VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &buffer_b_,
                  &buffer_b_memory_);

    // Indirect-args buffer for vkCmdDispatchIndirect, filled with a single workgroup.
    create_buffer(sizeof(VkDispatchIndirectCommand),
                  VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT,
                  &indirect_buffer_,
                  &indirect_buffer_memory_);

    void* data = nullptr;
    VERIFY_VK_RESULT("failed to map indirect buffer",
                     init.disp.mapMemory(indirect_buffer_memory_, 0, sizeof(VkDispatchIndirectCommand), 0, &data));
    VkDispatchIndirectCommand indirect_command{ 1, 1, 1 };
    memcpy(data, &indirect_command, sizeof(indirect_command));
    init.disp.unmapMemory(indirect_buffer_memory_);
}

void App::create_compute_pipeline()
{
    VkShaderModuleCreateInfo shader_module_info = {};
    shader_module_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_module_info.codeSize                 = sizeof(kComputeShaderSpirv);
    shader_module_info.pCode                    = kComputeShaderSpirv;
    VERIFY_VK_RESULT("failed to create compute shader module",
                     init.disp.createShaderModule(&shader_module_info, nullptr, &compute_shader_));

    // No descriptor sets and no push constants: the shader only needs to make the dispatches valid.
    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    VERIFY_VK_RESULT("failed to create pipeline layout",
                     init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_));

    VkComputePipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_info.stage.sType                 = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    pipeline_info.stage.stage                 = VK_SHADER_STAGE_COMPUTE_BIT;
    pipeline_info.stage.module                = compute_shader_;
    pipeline_info.stage.pName                 = "main";
    pipeline_info.layout                      = pipeline_layout_;
    VERIFY_VK_RESULT("failed to create compute pipeline",
                     init.disp.createComputePipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &compute_pipeline_));
}

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain(true);
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
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        // The test does not render: transition the acquired image straight to PRESENT_SRC so it can be presented.
        {
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_NONE;
            image_barrier.dstAccessMask               = VK_ACCESS_NONE;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        // Transfer, then a run of compute dispatches, then transfer again. With --serialize-compute-and-transfer the
        // replay tool injects a pipeline barrier before and after each of the three dispatches below.
        VkBufferCopy copy_region = {};
        copy_region.size         = BUFFER_SIZE;

        init.disp.cmdCopyBuffer(command_buffer, buffer_a_, buffer_b_, 1, &copy_region);

        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, compute_pipeline_);
        init.disp.cmdDispatch(command_buffer, 1, 1, 1);
        init.disp.cmdDispatchBase(command_buffer, 0, 0, 0, 1, 1, 1);
        init.disp.cmdDispatchIndirect(command_buffer, indirect_buffer_, 0);

        init.disp.cmdCopyBuffer(command_buffer, buffer_b_, buffer_a_, 1, &copy_region);

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

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[image_index] };
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
        recreate_swapchain(true);
        return frame_num >= NUM_FRAMES;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return IS_RUNNING(frame_num);
}

void App::cleanup()
{
    init.disp.destroyPipeline(compute_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyShaderModule(compute_shader_, nullptr);

    init.disp.destroyBuffer(buffer_a_, nullptr);
    init.disp.freeMemory(buffer_a_memory_, nullptr);
    init.disp.destroyBuffer(buffer_b_, nullptr);
    init.disp.freeMemory(buffer_b_memory_, nullptr);
    init.disp.destroyBuffer(indirect_buffer_, nullptr);
    init.disp.freeMemory(indirect_buffer_memory_, nullptr);

    for (size_t i = 0; i < sync_.finished_semaphore.size(); ++i)
    {
        init.disp.destroySemaphore(sync_.finished_semaphore[i], nullptr);
    }
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
    {
        init.disp.destroySemaphore(sync_.available_semaphores[i], nullptr);
        init.disp.destroyFence(sync_.in_flight_fences[i], nullptr);
    }

    for (auto command_pool : command_pools_)
    {
        init.disp.destroyCommandPool(command_pool, nullptr);
    }
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = test::create_command_pool(init.disp, *queue_family_index);
    }

    sync_ = test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    create_compute_pipeline();
    create_buffers();
}

GFXRECON_END_NAMESPACE(serialize_compute_and_transfer)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
