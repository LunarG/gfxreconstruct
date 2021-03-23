/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_feature_util.h"

#include "util/logging.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

VkResult GetInstanceExtensions(PFN_vkEnumerateInstanceExtensionProperties instance_extension_proc,
                               std::vector<VkExtensionProperties>*        properties)
{
    assert(properties != nullptr);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (instance_extension_proc != nullptr)
    {
        uint32_t count = 0;
        result         = instance_extension_proc(nullptr, &count, nullptr);

        if ((result == VK_SUCCESS) && (count > 0))
        {
            properties->resize(count);
            result = instance_extension_proc(nullptr, &count, properties->data());
        }
    }

    return result;
}

VkResult GetDeviceExtensions(VkPhysicalDevice                         physical_device,
                             PFN_vkEnumerateDeviceExtensionProperties device_extension_proc,
                             std::vector<VkExtensionProperties>*      properties)
{
    assert(properties != nullptr);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((physical_device != VK_NULL_HANDLE) && (device_extension_proc != nullptr))
    {
        uint32_t count = 0;
        result         = device_extension_proc(physical_device, nullptr, &count, nullptr);

        if ((result == VK_SUCCESS) && (count > 0))
        {
            properties->resize(count);
            result = device_extension_proc(physical_device, nullptr, &count, properties->data());
        }
    }

    return result;
}

bool IsSupportedExtension(const std::vector<VkExtensionProperties>& properties, const char* extension)
{
    assert(extension != nullptr);

    for (const auto& property : properties)
    {
        if (util::platform::StringCompare(property.extensionName, extension) == 0)
        {
            return true;
        }
    }

    return false;
}

void RemoveUnsupportedExtensions(const std::vector<VkExtensionProperties>& properties,
                                 std::vector<const char*>*                 extensions)
{
    assert(extensions != nullptr);

    auto extensionIter = extensions->begin();
    while (extensionIter != extensions->end())
    {
        if (!IsSupportedExtension(properties, *extensionIter))
        {
            GFXRECON_LOG_WARNING("Extension %s, which is not supported by the replay device, will not be enabled",
                                 *extensionIter);
            extensionIter = extensions->erase(extensionIter);
        }
        else
        {
            ++extensionIter;
        }
    }
}

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
