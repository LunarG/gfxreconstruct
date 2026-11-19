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

#ifndef GFXRECON_TESTAPP_SECONDARY_DRAW_TWICE_H
#define GFXRECON_TESTAPP_SECONDARY_DRAW_TWICE_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(secondary_draw_twice)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * A secondary command buffer that holds a single vkCmdDraw is executed twice by the same primary, through two
 * vkCmdExecuteCommands inside one render pass. The draw covers a small offscreen render target with the color of a
 * uniform buffer and is blended additively, so each execution leaves the render target with different contents:
 * 0.25 after the first execution of a frame and 0.5 after the second.
 *
 * This is the --dump-resources scenario where one dumped draw call has several executions in the same render pass:
 * each execution must get its own render target dumps and its own entry in the output json, while the uniform
 * buffer, which does not change, is dumped once and referenced by both entries.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    // The offscreen render target the draw call is blended into
    VkImage        render_target_        = VK_NULL_HANDLE;
    VkDeviceMemory render_target_memory_ = VK_NULL_HANDLE;
    VkImageView    render_target_view_   = VK_NULL_HANDLE;
    VkRenderPass   render_pass_          = VK_NULL_HANDLE;
    VkFramebuffer  framebuffer_          = VK_NULL_HANDLE;

    VkShaderModule        vertex_shader_         = VK_NULL_HANDLE;
    VkShaderModule        fragment_shader_       = VK_NULL_HANDLE;
    VkDescriptorSetLayout descriptor_set_layout_ = VK_NULL_HANDLE;
    VkPipelineLayout      pipeline_layout_       = VK_NULL_HANDLE;
    VkPipeline            graphics_pipeline_     = VK_NULL_HANDLE;
    VkDescriptorPool      descriptor_pool_       = VK_NULL_HANDLE;
    VkDescriptorSet       descriptor_set_        = VK_NULL_HANDLE;

    // The buffer with the color every execution of the draw call adds
    VkBuffer       uniform_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory uniform_buffer_memory_ = VK_NULL_HANDLE;

    void create_render_target();
    void create_uniform_buffer();
    void create_descriptor_set();
    void create_graphics_pipeline();
    void initialize_uniform_buffer();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

GFXRECON_END_NAMESPACE(secondary_draw_twice)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SECONDARY_DRAW_TWICE_H
