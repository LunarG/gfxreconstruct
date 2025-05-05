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

#ifndef GFXRECON_TESTAPP_ACQUIRED_IMAGE_H
#define GFXRECON_TESTAPP_ACQUIRED_IMAGE_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(acquired_image)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

class App : public gfxrecon::test::TestAppBase
{
  public:
    App() = default;

  private:
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool command_pools_[MAX_FRAMES_IN_FLIGHT];

    size_t current_frame_ = 0;

    std::vector<VkSwapchainKHR> old_swapchains_;
    VkSemaphore                 initial_semaphore_ = VK_NULL_HANDLE;
    test::Sync                  sync_;

    uint32_t       staging_memory_size_ = 0;
    VkDeviceMemory staging_memory_      = VK_NULL_HANDLE;
    VkBuffer       staging_buffer_      = VK_NULL_HANDLE;

    VkCommandBuffer create_and_begin_command_buffer();
    void            recreate_swapchain();
    void            cleanup() override;
    bool            frame(const int frame_num) override;
    void            setup() override;

    void create_staging_buffer();
    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;

    void configure_swapchain_builder(test::SwapchainBuilder& swapchain_builder,
                                     vkmock::TestConfig*     test_config) override;
};

GFXRECON_END_NAMESPACE(acquired_image)
GFXRECON_END_NAMESPACE(testapp)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_ACQUIRED_IMAGE_H
