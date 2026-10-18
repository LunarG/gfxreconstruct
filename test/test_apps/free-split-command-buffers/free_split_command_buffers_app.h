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

#ifndef GFXRECON_TESTAPP_FREE_SPLIT_COMMAND_BUFFERS_H
#define GFXRECON_TESTAPP_FREE_SPLIT_COMMAND_BUFFERS_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(free_split_command_buffers)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * Minimal app that records two legacy (vkCmdBeginRenderPass/vkCmdEndRenderPass) render passes into a single command
 * buffer each frame, submits it, and later frees that command buffer with vkFreeCommandBuffers once its fence has
 * signaled. It never resets its command pools, so every command buffer the app records is released through an
 * explicit free.
 *
 * Replay options that split a command buffer at render pass boundaries (gfxrecon-replay --isolate-render-passes)
 * allocate extra command buffers behind the original one. Freeing the original must release those extra command
 * buffers without touching them afterwards, which is what this app lets the test case check.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass render_pass_;

    VkCommandPool   command_pools_[MAX_FRAMES_IN_FLIGHT];
    VkCommandBuffer command_buffers_[MAX_FRAMES_IN_FLIGHT] = {};

    size_t current_frame_ = 0;

    test::Sync sync_;

    void create_render_pass();
    void create_framebuffers();
    void recreate_swapchain();
    void free_command_buffer(size_t frame_slot);
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(free_split_command_buffers)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_FREE_SPLIT_COMMAND_BUFFERS_H
