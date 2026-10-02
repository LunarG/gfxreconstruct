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

#ifndef GFXRECON_TESTAPP_FRAME_LOOPING_IMAGE_CONTENTS_H
#define GFXRECON_TESTAPP_FRAME_LOOPING_IMAGE_CONTENTS_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_image_contents)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * The triangle app, with the triangle coloured from an image that the GPU rewrites every frame.
 *
 * The content image is a ring of coloured texels, and each frame rotates the ring by one texel with a
 * pair of vkCmdCopyImage calls through a scratch image. The fragment shader always reads the first
 * texel of the ring, so the whole triangle comes out a different flat colour on every frame, and frame
 * N always looks the same no matter how often it is replayed -- but only if the image is rewound to
 * its frame N contents first.
 *
 * Replaying with --loop-frame N repeats one frame. Each repetition rotates the ring again, so without
 * image content restoration the triangle keeps changing colour past where frame N left it. With
 * restoration, every repetition reproduces the captured frame N exactly.
 *
 * The rotation has to be GPU work rather than a host upload: a host upload would be recorded into the
 * frame and replayed with every repetition, putting the same texels back for free and hiding the bug
 * this app exists to catch.
 *
 * The image is sampled rather than only copied, so each repetition also has to be handed back an image
 * in VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL -- the layout the frame's first barrier declares as its
 * old layout -- which exercises layout restoration alongside content restoration.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass     render_pass_;
    VkPipelineLayout pipeline_layout_;
    VkPipeline       graphics_pipeline_;

    // The static geometry the content image is sampled onto.
    VkBuffer       vertex_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory vertex_buffer_memory_ = VK_NULL_HANDLE;

    // The image under test, plus the scratch image the rotation copies through.
    VkImage        content_image_         = VK_NULL_HANDLE;
    VkDeviceMemory content_image_memory_  = VK_NULL_HANDLE;
    VkImageView    content_image_view_    = VK_NULL_HANDLE;
    VkImage        scratch_image_         = VK_NULL_HANDLE;
    VkDeviceMemory scratch_image_memory_  = VK_NULL_HANDLE;

    VkSampler             sampler_               = VK_NULL_HANDLE;
    VkDescriptorPool      descriptor_pool_       = VK_NULL_HANDLE;
    VkDescriptorSetLayout descriptor_set_layout_ = VK_NULL_HANDLE;
    VkDescriptorSet       descriptor_set_        = VK_NULL_HANDLE;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void create_vertex_buffer();
    void create_image(VkImageUsageFlags usage, VkImage* image, VkDeviceMemory* memory);
    void create_images();
    void upload_initial_image_contents();
    void create_descriptor_set();
    void create_render_pass();
    void create_graphics_pipeline();
    void create_framebuffers();
    void recreate_swapchain();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(frame_looping_image_contents)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_FRAME_LOOPING_IMAGE_CONTENTS_H
