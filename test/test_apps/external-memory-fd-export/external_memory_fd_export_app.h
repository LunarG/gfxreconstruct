/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#ifndef GFXRECON_TESTAPP_EXTERNAL_MEMORY_FD_EXPORT_H
#define GFXRECON_TESTAPP_EXTERNAL_MEMORY_FD_EXPORT_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(external_memory_fd_export)

class App : public gfxrecon::test::TestAppBase
{
  public:
    App()                      = default;
    virtual ~App()             = default;
    App(const App&)            = delete;
    App& operator=(const App&) = delete;
    App(App&&)                 = delete;
    App& operator=(App&&)      = delete;

  private:
    const uint32_t buffer_size_       = sizeof(uint32_t[42]);
    VkBuffer       buffer_            = VK_NULL_HANDLE;
    VkDeviceMemory exportable_memory_ = VK_NULL_HANDLE;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config) override;

    uint32_t find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags);
    void     create_buffer();

    int     get_exportable_fd();
    void    send_exportable_fd(int exportable_fd);
    ssize_t send_int(int conn_fd, int data);

    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

GFXRECON_END_NAMESPACE(external_memory_fd_export)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_EXTERNAL_MEMORY_FD_EXPORT_H
