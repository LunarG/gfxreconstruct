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

#ifndef GFXRECON_TESTAPP_FRAME_LOOPING_BUFFER_CONTENTS_H
#define GFXRECON_TESTAPP_FRAME_LOOPING_BUFFER_CONTENTS_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_buffer_contents)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * The triangle app, with the triangle read out of a vertex buffer that the GPU rewrites every frame.
 *
 * The vertex buffer holds a ring of vertices spread around a circle, and each frame rotates the ring
 * by one vertex with a pair of vkCmdCopyBuffer calls through a scratch buffer. The draw always takes
 * the first three vertices, so the triangle jumps to a new position and a new set of corner colours
 * on every frame, and frame N always looks the same no matter how often it is replayed -- but only if
 * the vertex buffer is rewound to its frame N contents first.
 *
 * Replaying with --loop-frame N repeats one frame. Each repetition rotates the ring again, so without
 * buffer content restoration the triangle keeps turning past where frame N left it. With restoration,
 * every repetition reproduces the captured frame N exactly.
 *
 * The rotation has to be GPU work rather than a host write: a host write would be recorded into the
 * frame and replayed with every repetition, putting the same vertices back for free and hiding the
 * bug this app exists to catch.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass     render_pass_;
    VkPipelineLayout pipeline_layout_;
    VkPipeline       graphics_pipeline_;

    // The buffer under test, plus the scratch buffer the rotation copies through.
    VkBuffer       vertex_buffer_         = VK_NULL_HANDLE;
    VkDeviceMemory vertex_buffer_memory_  = VK_NULL_HANDLE;
    VkBuffer       scratch_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory scratch_buffer_memory_ = VK_NULL_HANDLE;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void create_buffers();
    void create_render_pass();
    void create_graphics_pipeline();
    void create_framebuffers();
    void recreate_swapchain();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(frame_looping_buffer_contents)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_FRAME_LOOPING_BUFFER_CONTENTS_H
