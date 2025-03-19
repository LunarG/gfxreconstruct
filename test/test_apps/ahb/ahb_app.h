/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_TESTAPP_AHB_H
#define GFXRECON_TESTAPP_AHB_H

#include <test_app_base.h>

#include <util/defines.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(ahb)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

class App : public test::TestAppBase
{
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    uint32_t image_width_  = 0;
    uint32_t image_height_ = 0;

    AHardwareBuffer* ahb_      = nullptr;
    VkDeviceSize     ahb_size_ = 0;

    VkImage        image_        = VK_NULL_HANDLE;
    VkDeviceMemory image_memory_ = VK_NULL_HANDLE;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    test::Sync sync_;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_ahb();
    void     import_ahb_as_image();

    VkCommandBuffer allocate_command_buffer(VkCommandPool command_pool);
    void            fill_ahb_image();
    void            copy_ahb_image_to_color_image(VkCommandBuffer command_buffer, VkImage color_image);

    void get_queues();
    void create_command_pools();
    void recreate_swapchain();

    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config) override;
    void configure_swapchain_builder(test::SwapchainBuilder& swapchain_builder,
                                     vkmock::TestConfig*     test_config) override;
};

GFXRECON_END_NAMESPACE(ahb)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_AHB_H
