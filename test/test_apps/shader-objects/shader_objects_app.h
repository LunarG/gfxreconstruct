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

#ifndef GFXRECON_TESTAPP_SHADER_OBJECTS_APP_H
#define GFXRECON_TESTAPP_SHADER_OBJECTS_APP_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(shader_objects)

const size_t MAX_FRAMES_IN_FLIGHT = 2;

class App : public gfxrecon::test::TestAppBase
{
  public:
    App() = default;

  private:
    VkQueue graphics_queue_;
    VkQueue present_queue_;

    VkCommandPool   command_pool_;
    VkCommandBuffer command_buffers_[MAX_FRAMES_IN_FLIGHT];

    VkShaderEXT shaders_[5];

    size_t current_frame_ = 0;

    gfxrecon::test::Sync sync_;

    VkPhysicalDeviceDynamicRenderingFeatures dynamic_rendering_features_;
    VkPhysicalDeviceShaderObjectFeaturesEXT  shader_object_features_;
    VkPhysicalDeviceFeatures2                features2_;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;

    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*) override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device,
                                  vkmock::TestConfig*) override;

    void create_shader_objects();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

GFXRECON_END_NAMESPACE(shader_objects)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SHADER_OBJECTS_APP_H
