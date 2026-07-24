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

// Single source of the "compiled header version" strings each API's tool Features report
// through FeatureBase::CompiledHeaderVersionString(), so every tool prints the same text for
// the same compiled API regardless of which tool it is.

#ifndef GFXRECON_UTIL_API_VERSION_INFO_H
#define GFXRECON_UTIL_API_VERSION_INFO_H

#include "util/defines.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(GFXRECON_ENABLE_VULKAN)
// "Vulkan Header Version X.Y.Z", sourced from vulkan_core.h's VK_HEADER_VERSION_COMPLETE.
std::string GetVulkanHeaderVersionString();
#endif

#if ENABLE_OPENXR_SUPPORT
// "OpenXR Header Version X.Y.Z", sourced from openxr.h's XR_CURRENT_API_VERSION.
std::string GetOpenXrHeaderVersionString();
#endif

#if defined(D3D12_SUPPORT)
// "D3D12 SDK Version X", sourced from d3d12.h's D3D12_SDK_VERSION.
std::string GetD3D12SdkVersionString();
#endif

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_API_VERSION_INFO_H
