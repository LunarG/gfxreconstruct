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

#ifndef GFXRECON_TESTAPP_SPARSE_RESOURCES_APP_H
#define GFXRECON_TESTAPP_SPARSE_RESOURCES_APP_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(sparse_resources)

const size_t   MAX_FRAMES_IN_FLIGHT = 2;
const size_t   FRAMES_UNTIL_EXIT    = 1000;
const size_t   STAGING_BUFFER_SIZE  = 16 * 1024 * 1024;
const VkFormat IMAGE_FORMAT         = VK_FORMAT_R8G8B8A8_SRGB;

struct Uniforms
{
    float rotation;
};

class App : public gfxrecon::test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    std::vector<VkFramebuffer> framebuffers_;

    VkRenderPass          render_pass_;
    VkDescriptorPool      descriptor_pool_;
    VkDescriptorSetLayout descriptor_layout_;
    VkDescriptorSet       descriptor_set_;
    VkPipelineLayout      pipeline_layout_;
    VkPipeline            graphics_pipeline_;

    VkBuffer                        staging_buffer_;
    uint8_t*                        staging_buffer_ptr_;
    VkBuffer                        sparse_bound_buffer_;
    VkImage                         sparse_bind_image_;
    VkImageView                     sparse_bind_image_view_;
    const uint32_t                  image_size_ = 16;
    const uint32_t                  mip_levels_ = 1;
    VkSampler                       sampler_;
    VkSparseImageMemoryRequirements image_mem_reqs_;
    VkDeviceMemory                  image_backing_memory_;
    VkDeviceMemory                  staging_backing_memory_;
    VkDeviceMemory                  sparse_buffer_backing_memory_;
    uint32_t                        device_memory_type_;
    uint32_t                        staging_memory_type_;

    uint32_t sparse_binding_granularity_;

    VkCommandPool   command_pools_[MAX_FRAMES_IN_FLIGHT];
    VkCommandBuffer command_buffers_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_;
    size_t current_in_flight_frame_ = 0;
    size_t last_in_flight_frame_    = MAX_FRAMES_IN_FLIGHT - 1;

    gfxrecon::test::Sync sync_;
    VkFence              immediate_fence_;

    void create_render_pass();
    void create_graphics_pipeline();
    void create_framebuffers();
    void create_descriptor_set();
    void create_staging_buffer();
    void create_sparse_bound_buffer();
    void create_images();
    void determine_memory_heaps();
    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config);
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config);
    bool frame(const int frame_num);
    void setup();
    void cleanup();
};

GFXRECON_END_NAMESPACE(sparse_resources)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SPARSE_RESOURCES_APP_H
