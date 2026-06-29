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

#ifndef GFXRECON_TESTAPP_SERIALIZE_COMPUTE_AND_TRANSFER_H
#define GFXRECON_TESTAPP_SERIALIZE_COMPUTE_AND_TRANSFER_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(serialize_compute_and_transfer)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * Minimal app that, each frame, records transfer (vkCmdCopyBuffer) and compute (vkCmdDispatch,
 * vkCmdDispatchBase, vkCmdDispatchIndirect) commands into a single command buffer interleaved with each other, then
 * submits it while waiting on the binary swapchain-acquire semaphore. It deliberately uses a trivial empty compute
 * shader with no descriptors, keeping the focus on the dispatch commands that gfxrecon-replay
 * --serialize-compute-and-transfer wraps with injected pipeline barriers.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    // Trivial compute pipeline (empty shader, no descriptors) used to make the dispatches valid.
    VkShaderModule   compute_shader_   = VK_NULL_HANDLE;
    VkPipelineLayout pipeline_layout_  = VK_NULL_HANDLE;
    VkPipeline       compute_pipeline_ = VK_NULL_HANDLE;

    // Two buffers copied back and forth (the transfer work), and an indirect-args buffer for vkCmdDispatchIndirect.
    VkBuffer       buffer_a_               = VK_NULL_HANDLE;
    VkDeviceMemory buffer_a_memory_        = VK_NULL_HANDLE;
    VkBuffer       buffer_b_               = VK_NULL_HANDLE;
    VkDeviceMemory buffer_b_memory_        = VK_NULL_HANDLE;
    VkBuffer       indirect_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory indirect_buffer_memory_ = VK_NULL_HANDLE;

    void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void create_buffers();
    void create_compute_pipeline();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(serialize_compute_and_transfer)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SERIALIZE_COMPUTE_AND_TRANSFER_H
