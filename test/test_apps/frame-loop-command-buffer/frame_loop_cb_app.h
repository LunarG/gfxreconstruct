/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_TESTAPP_FRAME_LOOP_COMMAND_BUFFER_APP_H
#define GFXRECON_TESTAPP_FRAME_LOOP_COMMAND_BUFFER_APP_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_loop_command_buffer)

const size_t   MAX_FRAMES_IN_FLIGHT = 2;
const size_t   FRAMES_UNTIL_EXIT    = 1000;

class App : public gfxrecon::test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass          render_pass_;
    VkPipelineLayout      pipeline_layout_;
    VkPipeline            graphics_pipeline_;

    VkCommandPool   command_pool_;
    VkCommandBuffer command_buffers_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_;
    size_t current_in_flight_frame_ = 0;
    size_t last_in_flight_frame_    = MAX_FRAMES_IN_FLIGHT - 1;

    gfxrecon::test::Sync sync_;
    VkFence              immediate_fence_;
    VkFence              intra_cb_fence_;

    void create_render_pass();
    void create_graphics_pipeline();
    void create_framebuffers();
    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config);
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config);
    bool frame(const int frame_num);
    void setup();
    void cleanup();
};

GFXRECON_END_NAMESPACE(frame_loop_command_buffer)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_FRAME_LOOP_COMMAND_BUFFER_APP_H
