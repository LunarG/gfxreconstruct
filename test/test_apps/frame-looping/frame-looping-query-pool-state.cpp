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

#include <frame_looping_query_pool_state_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_query_pool_state)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);

    // No window, no surface, no swapchain. Nothing here is visual.
    instance_builder.set_headless(true);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector, vkmock::TestConfig*)
{
    phys_device_selector.add_required_extension(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);
}

void App::configure_device_builder(test::DeviceBuilder& device_builder, test::PhysicalDevice const&, vkmock::TestConfig*)
{
    frame_boundary_features_.sType         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
    frame_boundary_features_.pNext         = nullptr;
    frame_boundary_features_.frameBoundary = VK_TRUE;
    device_builder.add_pNext(&frame_boundary_features_);
}

void App::create_query_pool()
{
    VkQueryPoolCreateInfo pool_info = {};
    pool_info.sType                 = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
    pool_info.queryType             = VK_QUERY_TYPE_TIMESTAMP;
    pool_info.queryCount            = NUM_FRAMES;

    VERIFY_VK_RESULT("failed to create query pool", init.disp.createQueryPool(&pool_info, nullptr, &query_pool_));

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pool_;
    VkCommandBuffer command_buffer            = VK_NULL_HANDLE;
    VERIFY_VK_RESULT("failed to allocate command buffer",
                     init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    init.disp.cmdResetQueryPool(command_buffer, query_pool_, 0, NUM_FRAMES);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;

    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));
    VERIFY_VK_RESULT("failed to wait on queue", init.disp.queueWaitIdle(graphics_queue_));
}

bool App::frame(const int frame_num)
{
    const bool keep_running = (frame_num + 1) < NUM_FRAMES;

    VERIFY_VK_RESULT("failed to reset command pool", init.disp.resetCommandPool(command_pool_, 0));

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pool_;
    VkCommandBuffer command_buffer            = VK_NULL_HANDLE;
    VERIFY_VK_RESULT("failed to allocate command buffer",
                     init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    // The command under test. The frame deliberately never resets the pool, so this write is only
    // legal because setup left this frame's query unavailable and nothing has written it since.
    init.disp.cmdWriteTimestamp(command_buffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, query_pool_, frame_num);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    VkSubmitInfo work_submit_info       = {};
    work_submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    work_submit_info.commandBufferCount = 1;
    work_submit_info.pCommandBuffers    = &command_buffer;

    VERIFY_VK_RESULT("failed to submit queue",
                     init.disp.queueSubmit(graphics_queue_, 1, &work_submit_info, VK_NULL_HANDLE));

    // Settles the timestamp before it is read, and leaves nothing in flight for the next frame.
    VERIFY_VK_RESULT("failed to wait on queue", init.disp.queueWaitIdle(graphics_queue_));

    uint64_t timestamp = 0;
    VERIFY_VK_RESULT("failed to get query pool results",
                     init.disp.getQueryPoolResults(query_pool_,
                                                   frame_num,
                                                   1,
                                                   sizeof(timestamp),
                                                   &timestamp,
                                                   sizeof(timestamp),
                                                   VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT));

    VkFrameBoundaryEXT frame_boundary = {};
    frame_boundary.sType              = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
    frame_boundary.flags              = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
    frame_boundary.frameID            = static_cast<uint64_t>(frame_num);

    VkSubmitInfo boundary_submit_info = {};
    boundary_submit_info.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    boundary_submit_info.pNext        = &frame_boundary;

    VERIFY_VK_RESULT("failed to submit frame boundary",
                     init.disp.queueSubmit(graphics_queue_, 1, &boundary_submit_info, VK_NULL_HANDLE));

    return keep_running;
}

void App::cleanup()
{
    init.disp.destroyQueryPool(query_pool_, nullptr);
    init.disp.destroyCommandPool(command_pool_, nullptr);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");

    // A queue family with no valid timestamp bits cannot write timestamps at all, which would leave
    // the capture with nothing to restore.
    VERIFY_CONDITION("graphics queue family does not support timestamps",
                     init.device.queue_families[*queue_family_index].timestampValidBits != 0);

    command_pool_ = test::create_command_pool(init.disp, *queue_family_index);

    create_query_pool();
}

GFXRECON_END_NAMESPACE(frame_looping_query_pool_state)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
