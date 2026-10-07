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

#include <frame_looping_semaphore_state_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_semaphore_state)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);
    instance_builder.set_headless(true);

    // Timeline semaphores are core 1.2, and the builders default to 1.0.
    instance_builder.require_api_version(1, 2, 0);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector, vkmock::TestConfig*)
{
    phys_device_selector.add_required_extension(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);
    phys_device_selector.set_minimum_version(1, 2);
}

void App::configure_device_builder(test::DeviceBuilder& device_builder, test::PhysicalDevice const&, vkmock::TestConfig*)
{
    frame_boundary_features_.sType         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
    frame_boundary_features_.pNext         = nullptr;
    frame_boundary_features_.frameBoundary = VK_TRUE;
    device_builder.add_pNext(&frame_boundary_features_);

    timeline_features_.sType             = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
    timeline_features_.pNext             = nullptr;
    timeline_features_.timelineSemaphore = VK_TRUE;
    device_builder.add_pNext(&timeline_features_);
}

void App::create_semaphores()
{
    // Created here in setup, which is replayed once no matter what --loop-frame is given, so no
    // repetition can hand itself a fresh semaphore for free.
    VkSemaphoreCreateInfo semaphore_info = {};
    semaphore_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    for (auto& semaphore : binary_semaphores_)
    {
        VERIFY_VK_RESULT("failed to create binary semaphore",
                         init.disp.createSemaphore(&semaphore_info, nullptr, &semaphore));
    }

    VkSemaphoreTypeCreateInfo type_info = {};
    type_info.sType                     = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
    type_info.semaphoreType             = VK_SEMAPHORE_TYPE_TIMELINE;
    type_info.initialValue              = 0;
    semaphore_info.pNext                = &type_info;

    VERIFY_VK_RESULT("failed to create timeline semaphore",
                     init.disp.createSemaphore(&semaphore_info, nullptr, &timeline_));
}

bool App::frame(const int frame_num)
{
    const bool keep_running = (frame_num + 1) < NUM_FRAMES;

    // The timeline runs one step per frame, so it stands at frame_num when this frame starts.
    const uint64_t timeline_target = static_cast<uint64_t>(frame_num) + 1;

    // Nothing ever waits on either of these, so the frame leaves both where the previous frame did
    // not: the binary one signaled, the timeline one step further along. A host-side vkResetFences
    // equivalent does not exist for semaphores, so there is nothing here that could quietly undo the
    // drift on replay and hide the bug this app exists to catch.
    VkSemaphore signal_semaphores[] = { binary_semaphores_[frame_num], timeline_ };

    // One value per signal semaphore; the binary one ignores its entry.
    const uint64_t signal_values[] = { 0, timeline_target };

    VkTimelineSemaphoreSubmitInfo timeline_info = {};
    timeline_info.sType                         = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
    timeline_info.signalSemaphoreValueCount     = 2;
    timeline_info.pSignalSemaphoreValues        = signal_values;

    // This submit is the end of the frame, in place of a present.
    VkFrameBoundaryEXT frame_boundary = {};
    frame_boundary.sType              = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
    frame_boundary.pNext              = &timeline_info;
    frame_boundary.flags              = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
    frame_boundary.frameID            = static_cast<uint64_t>(frame_num);

    VkSubmitInfo submit_info        = {};
    submit_info.sType               = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext               = &frame_boundary;
    submit_info.signalSemaphoreCount = 2;
    submit_info.pSignalSemaphores    = signal_semaphores;

    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));

    // Keeps each frame self-contained, so both semaphores are settled before the frame boundary work
    // runs.
    VERIFY_VK_RESULT("failed to wait on queue", init.disp.queueWaitIdle(graphics_queue_));

    uint64_t timeline_value = 0;
    VERIFY_VK_RESULT("failed to read timeline semaphore", init.disp.getSemaphoreCounterValue(timeline_, &timeline_value));
    VERIFY_CONDITION("timeline semaphore did not land on this frame's value", timeline_value == timeline_target);

    return keep_running;
}

void App::cleanup()
{
    for (auto semaphore : binary_semaphores_)
    {
        init.disp.destroySemaphore(semaphore, nullptr);
    }
    init.disp.destroySemaphore(timeline_, nullptr);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    create_semaphores();
}

GFXRECON_END_NAMESPACE(frame_looping_semaphore_state)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
