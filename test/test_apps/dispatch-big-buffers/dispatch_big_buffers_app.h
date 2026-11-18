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

#ifndef GFXRECON_TESTAPP_DISPATCH_BIG_BUFFERS_H
#define GFXRECON_TESTAPP_DISPATCH_BIG_BUFFERS_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(dispatch_big_buffers)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

/**
 * Compute-heavy command buffer for the dump-resources memory footprint scenario. Each frame records many
 * vkCmdDispatch commands that all read and write the same 1 GiB storage buffer; every dispatch also writes a
 * per-workgroup checksum into a small result buffer. Dumping all the dispatches with --dump-resources must not keep
 * a copy of the big buffer per dispatch alive until the end of the submission: on a 16 GiB device that exhausts
 * VRAM before the last dispatch of a frame.
 *
 * When VK_AMD_memory_overallocation_behavior is available the device is created with overallocation disallowed, so
 * running out of VRAM fails with VK_ERROR_OUT_OF_DEVICE_MEMORY instead of spilling into system memory.
 * gfxrecon-replay recreates the device with the same pNext chain.
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

    // The big buffer every dispatch rewrites in place, and the small per-workgroup checksum buffer.
    VkBuffer       big_buffer_           = VK_NULL_HANDLE;
    VkDeviceMemory big_buffer_memory_    = VK_NULL_HANDLE;
    VkBuffer       result_buffer_        = VK_NULL_HANDLE;
    VkDeviceMemory result_buffer_memory_ = VK_NULL_HANDLE;

    // Chained into VkDeviceCreateInfo::pNext, so it must outlive DeviceBuilder::build().
    VkDeviceMemoryOverallocationCreateInfoAMD overallocation_info_ = {};

    void create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void create_buffers();
    void create_descriptor_set();
    void create_compute_pipeline();
    void initialize_buffers();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device,
                                  vkmock::TestConfig*         test_config) override;
};

GFXRECON_END_NAMESPACE(dispatch_big_buffers)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_DISPATCH_BIG_BUFFERS_H
