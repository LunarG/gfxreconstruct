/*
** Copyright (c) 2020-2023 LunarG, Inc.
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
#include <set>
#include <string>
#include <vector>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

// There are some extensions which can be enabled by the application, but can be ignored during replay if
// they don't exist.
// For example, the VK_EXT_tooling_info extension is enabled by the GfxReconstruct capture layer
// and may be queried/enabled during instance creation, but is not used for anything other than
// querying layer information.  This can be problematic if the instance replaying attempts to
// enable the extension with no support present on the replay device (usually because the layer is
// no longer there)
std::set<std::string> kIgnorableExtensions = {
    VK_EXT_TOOLING_INFO_EXTENSION_NAME,
    VK_EXT_DEBUG_MARKER_EXTENSION_NAME,
};

VkResult GetInstanceLayers(PFN_vkEnumerateInstanceLayerProperties instance_layer_proc,
                           std::vector<VkLayerProperties>*        layers)
{
    assert(layers != nullptr);

    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (instance_layer_proc != nullptr)
    {
        uint32_t layer_count = 0;
        result               = instance_layer_proc(&layer_count, nullptr);

        if ((result == VK_SUCCESS) && (layer_count > 0))
        {
            layers->resize(layer_count);
            result = instance_layer_proc(&layer_count, layers->data());
        }
    }

    return result;
}

bool IsSupportedLayer(const std::vector<VkLayerProperties>& properties, const char* layer)
{
    assert(layer != nullptr);

    for (const auto& property : properties)
    {
        if (strcmp(property.layerName, layer) == 0)
        {
            return true;
        }
    }

    return false;
}

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

bool IsIgnorableExtension(const char* extension)
{
    return kIgnorableExtensions.count(extension) > 0;
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

void RemoveExtensionIfUnsupported(const std::vector<VkExtensionProperties>& properties,
                                  std::vector<const char*>*                 extensions,
                                  const char*                               extension_to_remove)
{
    if (!feature_util::IsSupportedExtension(properties, extension_to_remove))
    {
        auto extension_iter =
            std::find_if(extensions->begin(), extensions->end(), [&extension_to_remove](const char* extension) {
                return util::platform::StringCompare(extension_to_remove, extension) == 0;
            });
        if (extension_iter != extensions->end())
        {
            GFXRECON_LOG_WARNING("Extension %s, which is not supported by the replay device, will not be enabled",
                                 *extension_iter);
            extensions->erase(extension_iter);
        }
    }
}

// Remove any extensions which can be enabled by the application, but can be ignored during replay if
// they don't exist on the target device.
void RemoveIgnorableExtensions(const std::vector<VkExtensionProperties>& properties,
                               std::vector<const char*>*                 extensions)
{
    assert(extensions != nullptr);

    auto extensionIter = extensions->begin();
    while (extensionIter != extensions->end())
    {
        if (!IsSupportedExtension(properties, *extensionIter))
        {
            if (IsIgnorableExtension(*extensionIter))
            {
                GFXRECON_LOG_INFO("Extension %s, which is not supported by the replay device, will be ignored",
                                  *extensionIter);
                extensionIter = extensions->erase(extensionIter);
            }
            else
            {
                GFXRECON_LOG_WARNING("Extension %s is not supported by the replay device and may cause issues during"
                                     " attempted replay",
                                     *extensionIter);
                ++extensionIter;
            }
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
