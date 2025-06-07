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

#ifndef GFXRECON_TESTAPP_PIPELINE_BINARIES_APP_H
#define GFXRECON_TESTAPP_PIPELINE_BINARIES_APP_H

#include <test_app_base.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(pipeline_binaries)

class App : public gfxrecon::test::TestAppBase
{
  private:
    VkPhysicalDeviceDynamicRenderingFeatures  dynamic_rendering_features_;
    VkPhysicalDevicePipelineBinaryFeaturesKHR pipeline_binary_features_;

    VkQueue graphics_queue_;

    VkPipelineLayout pipeline_layout_;
    VkPipeline       graphics_pipeline_;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*) override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device,
                                  vkmock::TestConfig*) override;
    void create_graphics_pipeline();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

GFXRECON_END_NAMESPACE(pipeline_binaries)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_PIPELINE_BINARIES_APP_H
