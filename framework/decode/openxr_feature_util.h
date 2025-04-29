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

#ifndef GFXRECON_DECODE_OPENXR_FEATURE_FILTER_UTIL_H
#define GFXRECON_DECODE_OPENXR_FEATURE_FILTER_UTIL_H

#if ENABLE_OPENXR_SUPPORT

#include "util/defines.h"

#include "openxr/openxr.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(feature_util)

XrResult GetApiLayers(PFN_xrEnumerateApiLayerProperties instance_layer_proc, std::vector<XrApiLayerProperties>* layers);

bool IsSupportedApiLayer(const std::vector<XrApiLayerProperties>& properties, const char* layer);

XrResult GetInstanceExtensions(PFN_xrEnumerateInstanceExtensionProperties instance_extension_proc,
                               std::vector<XrExtensionProperties>*        properties);

bool IsSupportedExtension(const std::vector<XrExtensionProperties>& properties, const char* extension);

void RemoveUnsupportedExtensions(const std::vector<XrExtensionProperties>& properties,
                                 std::vector<const char*>*                 extensions);

GFXRECON_END_NAMESPACE(feature_util)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_FEATURE_FILTER_UTIL_H
