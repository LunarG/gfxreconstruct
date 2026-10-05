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

#include <vulkan/vulkan_core.h>

#include <serialize_queue_submissions_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(serialize_queue_submissions)

// One for each entry of the queue-submit the option acts on.
const uint32_t NUM_COMMAND_BUFFERS = 2;

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    instance_builder.set_headless(true);
}

bool App::frame(const int frame_num)
{
    return false;
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
    command_pool_ = test::create_command_pool(init.disp, *queue_family_index);

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = NUM_COMMAND_BUFFERS;
    allocate_info.commandPool                 = command_pool_;

    VkCommandBuffer command_buffers[NUM_COMMAND_BUFFERS] = {};

    VkResult result = init.disp.allocateCommandBuffers(&allocate_info, command_buffers);
    VERIFY_VK_RESULT("failed to allocate command buffers", result);

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    for (VkCommandBuffer command_buffer : command_buffers)
    {
        result = init.disp.beginCommandBuffer(command_buffer, &begin_info);
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        result = init.disp.endCommandBuffer(command_buffer);
        VERIFY_VK_RESULT("failed to end command buffer", result);
    }

    // Use --serialize-queue-submissions to inject semaphores.
    VkSubmitInfo multi_entry_submits[NUM_COMMAND_BUFFERS] = {};
    for (uint32_t i = 0; i < NUM_COMMAND_BUFFERS; ++i)
    {
        multi_entry_submits[i].sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        multi_entry_submits[i].commandBufferCount = 1;
        multi_entry_submits[i].pCommandBuffers    = &command_buffers[i];
    }

    result = init.disp.queueSubmit(graphics_queue_, NUM_COMMAND_BUFFERS, multi_entry_submits, VK_NULL_HANDLE);
    VERIFY_VK_RESULT("failed to submit the two-entry queue submission", result);

    result = init.disp.queueWaitIdle(graphics_queue_);
    VERIFY_VK_RESULT("failed to wait for the queue to become idle", result);
}

void App::cleanup()
{
    if (command_pool_ != VK_NULL_HANDLE){
        init.disp.destroyCommandPool(command_pool_, nullptr);
    }
}

GFXRECON_END_NAMESPACE(serialize_queue_submissions)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
