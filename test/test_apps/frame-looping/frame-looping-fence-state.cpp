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

#include <frame_looping_fence_state_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_fence_state)

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

void App::create_fences()
{
    // Unsignaled, and created here in setup. Setup is replayed once no matter what --loop-frame is
    // given, so no repetition of a frame can hand itself a fresh unsignaled fence for free. That is
    // what makes a missing fence fixup observable instead of self-healing.
    VkFenceCreateInfo fence_info = {};
    fence_info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fence_info.flags             = 0;

    for (auto& fence : fences_)
    {
        VERIFY_VK_RESULT("failed to create fence", init.disp.createFence(&fence_info, nullptr, &fence));
    }
}

bool App::frame(const int frame_num)
{
    // frame_num counts from zero, so this runs frames 0 through NUM_FRAMES - 1 and the capture is
    // exactly NUM_FRAMES frames long. It also picks out this frame's fence.
    const bool keep_running = (frame_num + 1) < NUM_FRAMES;

    // One empty submit is the whole frame: it signals this frame's fence and, through its pNext, ends
    // the frame in place of a present.
    VkFrameBoundaryEXT frame_boundary = {};
    frame_boundary.sType              = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
    frame_boundary.flags              = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
    frame_boundary.frameID            = static_cast<uint64_t>(frame_num);

    VkSubmitInfo submit_info = {};
    submit_info.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext        = &frame_boundary;

    // The frame deliberately never resets the fence.
    VERIFY_VK_RESULT("failed to submit queue",
                     init.disp.queueSubmit(graphics_queue_, 1, &submit_info, fences_[frame_num]));

    // Keeps each frame self-contained, so the fence is settled before the frame boundary work runs.
    VERIFY_VK_RESULT("failed to wait on queue", init.disp.queueWaitIdle(graphics_queue_));

    return keep_running;
}

void App::cleanup()
{
    for (auto fence : fences_)
    {
        init.disp.destroyFence(fence, nullptr);
    }
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    create_fences();
}

GFXRECON_END_NAMESPACE(frame_looping_fence_state)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
