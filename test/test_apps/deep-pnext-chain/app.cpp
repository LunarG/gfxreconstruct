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

#include "deep_pnext_chain_app.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(deep_pnext_chain)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::configure_device_builder(test::DeviceBuilder&        device_builder,
                                   test::PhysicalDevice const& physical_device,
                                   vkmock::TestConfig*         test_config)
{
    for (auto& private_data_create_info : private_data_create_infos_)
    {
        private_data_create_info.sType                       = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO;
        private_data_create_info.pNext                       = nullptr;
        private_data_create_info.privateDataSlotRequestCount = 1;
        device_builder.add_pNext(&private_data_create_info);
    }
}

bool App::frame(const int frame_num)
{
    return false;
}

GFXRECON_END_NAMESPACE(deep_pnext_chain)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
