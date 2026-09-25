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

#include <direct_driver_loading_app.h>

#include <stdexcept>

namespace gfxrecon
{

namespace test_app
{

namespace direct_driver_loading
{

void App::configure_instance_builder(gfxrecon::test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    // The triangle app sets this too. Its override is private, so the setting is repeated here.
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    // The test app base already opened the mock ICD library to read the test configuration. Hand its entry
    // point to the loader, the way an application with a bundled driver does.
    void* entry_point = get_mock_icd_proc("vk_icdGetInstanceProcAddr");
    if (entry_point == nullptr)
    {
        throw std::runtime_error("The direct-driver-loading app needs GFXRECON_TESTAPP_MOCK_ICD to point at the "
                                 "mock ICD library.");
    }

    driver_info_.sType                  = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG;
    driver_info_.pfnGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddrLUNARG>(entry_point);

    driver_list_.sType       = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG;
    driver_list_.mode        = VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG;
    driver_list_.driverCount = 1;
    driver_list_.pDrivers    = &driver_info_;

    instance_builder.enable_extension(VK_LUNARG_DIRECT_DRIVER_LOADING_EXTENSION_NAME);
    instance_builder.add_pNext(&driver_list_);

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

} // namespace direct_driver_loading

} // namespace test_app

} // namespace gfxrecon
