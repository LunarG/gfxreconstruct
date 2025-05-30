/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_TESTAPP_MULTISAMPLE_DEPTH_H
#define GFXRECON_TESTAPP_MULTISAMPLE_DEPTH_H

#include <vulkan/vulkan_core.h>
#include <vk_mem_alloc.h>

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(multisample_depth)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

class App : public gfxrecon::test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkImage>       depth_images_;
    std::vector<VmaAllocation> depth_image_allocations_;
    std::vector<VkImageView>   depth_image_views_;

    std::vector<VkImage>       render_targets_;
    std::vector<VmaAllocation> render_target_allocations_;
    std::vector<VkImageView>   render_target_views_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass     render_pass_;
    VkPipelineLayout pipeline_layout_;
    VkPipeline       graphics_pipeline_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    gfxrecon::test::Sync sync_;
    VmaAllocator         allocator_;

    void create_allocator();
    void create_render_targets();
    void create_depth_buffers();
    void create_render_pass();
    void create_graphics_pipeline();
    void create_framebuffers();
    void recreate_swapchain();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
    void configure_swapchain_builder(gfxrecon::test::SwapchainBuilder& swapchain_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(multisample_depth)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_MULTISAMPLE_DEPTH_H
