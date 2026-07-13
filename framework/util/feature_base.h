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

#ifndef GFXRECON_UTIL_FEATURE_BASE_H
#define GFXRECON_UTIL_FEATURE_BASE_H

#include "util/defines.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Common interface required of every per-tool Feature base class (e.g. ReplayFeatureBase,
// ConvertFeatureBase, ExtractFeatureBase, OptimizeFeature, InfoFeature) so that a Feature
// registered with FeatureModuleRegistry<T> can always be identified and asked for its
// compiled-header version string, regardless of which tool it belongs to.
class FeatureBase
{
  public:
    virtual ~FeatureBase() = default;

    // Short human-readable API name, e.g. "Vulkan", "D3D12", "OpenXR".
    virtual std::string Label() const = 0;

    // A single line describing the version of the API header this feature was compiled
    // against (see util::GetVulkanHeaderVersionString() and friends in api_version_info.h),
    // suitable for printing as part of a tool's "--version" output. Returns an empty string
    // if this feature has no meaningful compiled-header version to report.
    virtual std::string CompiledHeaderVersionString() const = 0;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FEATURE_BASE_H
