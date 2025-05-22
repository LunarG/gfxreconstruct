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

#ifndef GFXRECON_TESTAPP_HOST_IMAGE_COPY_H
#define GFXRECON_TESTAPP_HOST_IMAGE_COPY_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(host_image_copy)

class App : public gfxrecon::test::TestAppBase
{
    VkPhysicalDeviceHostImageCopyFeaturesEXT host_image_copy_features_;

    VkQueue  queue_;
    uint32_t queue_index_;

    const uint32_t image_width_  = 256u;
    const uint32_t image_height_ = 256u;
    const uint32_t buffer_size_  = image_width_ * image_height_ * 4u;

    VkBuffer       src_buffer_;
    VkDeviceMemory src_buffer_memory_;
    VkBuffer       dst_buffer_;
    VkDeviceMemory dst_buffer_memory_;
    VkImage        src_image_;
    VkDeviceMemory src_image_memory_;
    VkImage        dst_image_;
    VkDeviceMemory dst_image_memory_;

    VkCommandPool   command_pool_;
    VkCommandBuffer command_buffer_;
    VkFence         fence_;

    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*) override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device,
                                  vkmock::TestConfig*) override;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_buffers_and_images();
    void     allocate_command_buffer();
    void     cleanup() override;
    bool     frame(const int frame_num) override;
    void     setup() override;
};

GFXRECON_END_NAMESPACE(host_image_copy)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_HOST_IMAGE_COPY_H
