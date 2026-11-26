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

#ifndef GFXRECON_TESTAPP_SECONDARY_DISPATCH_TWICE_H
#define GFXRECON_TESTAPP_SECONDARY_DISPATCH_TWICE_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(secondary_dispatch_twice)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * A secondary command buffer that holds a single vkCmdDispatch is executed twice by the same primary, through two
 * vkCmdExecuteCommands. The dispatch adds (add + i) to every element i of a small storage buffer, where add comes
 * from a uniform buffer, so each execution leaves the storage buffer with different contents: after the n-th
 * execution since the start, element i holds n * (add + i).
 *
 * This is the --dump-resources scenario where one dumped command has several executions in the same submission:
 * each execution must get its own "before" and "after" dump of the storage buffer and its own entry in the output
 * json, while the uniform buffer, which does not change, is dumped once.
 */
class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    VkShaderModule        compute_shader_        = VK_NULL_HANDLE;
    VkDescriptorSetLayout descriptor_set_layout_ = VK_NULL_HANDLE;
    VkPipelineLayout      pipeline_layout_       = VK_NULL_HANDLE;
    VkPipeline            compute_pipeline_      = VK_NULL_HANDLE;
    VkDescriptorPool      descriptor_pool_       = VK_NULL_HANDLE;
    VkDescriptorSet       descriptor_set_        = VK_NULL_HANDLE;

    // The buffer every execution of the dispatch updates in place, and the buffer with the value it adds.
    VkBuffer       storage_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory storage_buffer_memory_ = VK_NULL_HANDLE;
    VkBuffer       uniform_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory uniform_buffer_memory_ = VK_NULL_HANDLE;

    void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void create_buffers();
    void create_descriptor_set();
    void create_compute_pipeline();
    void initialize_buffers();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

GFXRECON_END_NAMESPACE(secondary_dispatch_twice)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SECONDARY_DISPATCH_TWICE_H
