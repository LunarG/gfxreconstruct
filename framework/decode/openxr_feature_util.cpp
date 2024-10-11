/*
** Copyright (c) 2020-2024 LunarG, Inc.
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

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_feature_util.h"

#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <set>
#include <string>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

XrResult GetApiLayers(PFN_xrEnumerateApiLayerProperties enum_layer_pros, std::vector<XrApiLayerProperties>* layers)
{
    assert(layers != nullptr);

    XrResult result = XR_ERROR_INITIALIZATION_FAILED;

    if (enum_layer_pros != nullptr)
    {
        uint32_t layer_count = 0;
        result               = enum_layer_pros(layer_count, nullptr, nullptr);

        if ((result == XR_SUCCESS) && (layer_count > 0))
        {
            layers->assign(layer_count, { XR_TYPE_API_LAYER_PROPERTIES, nullptr });
            result = enum_layer_pros(static_cast<uint32_t>(layers->size()), &layer_count, layers->data());
        }
    }

    return result;
}

bool IsSupportedApiLayer(const std::vector<XrApiLayerProperties>& properties, const char* layer)
{
    assert(layer != nullptr);

    auto pred = [layer](const XrApiLayerProperties& property) { return strcmp(property.layerName, layer) == 0; };
    return std::any_of(properties.begin(), properties.end(), pred);
}

XrResult GetInstanceExtensions(PFN_xrEnumerateInstanceExtensionProperties enum_ext_props,
                               std::vector<XrExtensionProperties>*        properties)
{
    assert(properties != nullptr);

    XrResult result = XR_ERROR_INITIALIZATION_FAILED;

    if (enum_ext_props != nullptr)
    {
        uint32_t count = 0;
        result         = enum_ext_props(nullptr, 0, &count, nullptr);

        if ((result == XR_SUCCESS) && (count > 0))
        {
            properties->assign(count, { XR_TYPE_EXTENSION_PROPERTIES, nullptr });
            result = enum_ext_props(nullptr, static_cast<uint32_t>(properties->size()), &count, properties->data());
        }
    }

    return result;
}

bool IsSupportedExtension(const std::vector<XrExtensionProperties>& properties, const char* extension)
{
    assert(extension != nullptr);

    auto pred = [extension](const XrExtensionProperties& property) {
        return strcmp(property.extensionName, extension) == 0;
    };
    return std::any_of(properties.begin(), properties.end(), pred);
}

void RemoveUnsupportedExtensions(const std::vector<XrExtensionProperties>& properties,
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

#endif // ENABLE_OPENXR_SUPPORT
