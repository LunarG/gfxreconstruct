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

#include <frame_looping_event_state_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_event_state)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);
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

void App::create_events()
{
    // flags = 0 makes these host-visible events. VK_EVENT_CREATE_DEVICE_ONLY_BIT would take them out
    // of the replayer's event tracking entirely and there would be nothing left to restore.
    VkEventCreateInfo event_info = {};
    event_info.sType             = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
    event_info.flags             = 0;

    for (auto& event : events_)
    {
        VERIFY_VK_RESULT("failed to create event", init.disp.createEvent(&event_info, nullptr, &event));
        VERIFY_VK_RESULT("failed to signal event", init.disp.setEvent(event));
    }
}

bool App::frame(const int frame_num)
{
    // frame_num counts from zero, so this runs frames 0 through NUM_FRAMES - 1 and the capture is
    // exactly NUM_FRAMES frames long. It also picks out this frame's event.
    const bool keep_running = (frame_num + 1) < NUM_FRAMES;

    // The call under test. Nothing has touched this frame's event since setup signaled it, so the
    // capture records VK_EVENT_SET here. A repetition of this frame replays this same call against an
    // event the previous repetition left unsignaled, and the replayer reports the mismatch.
    const VkResult event_status = init.disp.getEventStatus(events_[frame_num]);
    VERIFY_CONDITION("event for this frame was not signaled at the start of the frame", event_status == VK_EVENT_SET);

    VERIFY_VK_RESULT("failed to reset command pool", init.disp.resetCommandPool(command_pool_, 0));

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pool_;
    VkCommandBuffer command_buffer            = VK_NULL_HANDLE;
    VERIFY_VK_RESULT("failed to allocate command buffer", init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    init.disp.cmdResetEvent(command_buffer, events_[frame_num], VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    // This submit is the end of the frame, in place of a present.
    VkFrameBoundaryEXT frame_boundary = {};
    frame_boundary.sType              = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
    frame_boundary.flags              = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
    frame_boundary.frameID            = static_cast<uint64_t>(frame_num);

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext              = &frame_boundary;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;

    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));

    VERIFY_VK_RESULT("failed to wait on queue", init.disp.queueWaitIdle(graphics_queue_));

    return keep_running;
}

void App::cleanup()
{
    init.disp.destroyCommandPool(command_pool_, nullptr);

    for (auto event : events_)
    {
        init.disp.destroyEvent(event, nullptr);
    }
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    create_events();

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    command_pool_ = test::create_command_pool(init.disp, *queue_family_index);
}

GFXRECON_END_NAMESPACE(frame_looping_event_state)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
