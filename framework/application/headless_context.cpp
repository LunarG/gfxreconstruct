/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "application/headless_context.h"
#include "application/application.h"
#include "application/headless_window.h"
#include "graphics/vulkan_feature_util.h"
#include "graphics/vulkan_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

HeadlessContext::HeadlessContext(Application* application, bool dpi_aware) : WsiContext(application)
{
    bool supported = false;

    // Check for headless extension support, and report initialization failure when the extension is not present.
    auto loader_handle = graphics::InitializeLoader();
    if (loader_handle != nullptr)
    {
        auto get_instance_proc_addr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
            util::platform::GetProcAddress(loader_handle, "vkGetInstanceProcAddr"));

        if (get_instance_proc_addr != nullptr)
        {
            auto instance_extension_proc = reinterpret_cast<PFN_vkEnumerateInstanceExtensionProperties>(
                get_instance_proc_addr(nullptr, "vkEnumerateInstanceExtensionProperties"));
            std::vector<VkExtensionProperties> properties;

            if (graphics::feature_util::GetInstanceExtensions(instance_extension_proc, &properties) == VK_SUCCESS)
            {
                if (graphics::feature_util::IsSupportedExtension(properties, VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME))
                {
                    supported = true;
                }
            }
        }

        graphics::ReleaseLoader(loader_handle);
    }

    if (supported)
    {
        window_factory_ = std::make_unique<HeadlessWindowFactory>(this);
    }
}

void HeadlessContext::ProcessEvents(bool wait_for_input)
{
    // No winsys events to process for headless.
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
