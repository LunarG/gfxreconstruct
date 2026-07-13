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

#include "util/api_version_info.h"

#if defined(GFXRECON_ENABLE_VULKAN)
#include "vulkan/vulkan_core.h"
#endif

#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif

#if defined(D3D12_SUPPORT)
#include "d3d12.h"
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(GFXRECON_ENABLE_VULKAN)
std::string GetVulkanHeaderVersionString()
{
    return std::string("Vulkan Header Version ") + std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) +
           "." + std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
           std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
}
#endif

#if ENABLE_OPENXR_SUPPORT
std::string GetOpenXrHeaderVersionString()
{
    return std::string("OpenXR Header Version ") + std::to_string(XR_VERSION_MAJOR(XR_CURRENT_API_VERSION)) + "." +
           std::to_string(XR_VERSION_MINOR(XR_CURRENT_API_VERSION)) + "." +
           std::to_string(XR_VERSION_PATCH(XR_CURRENT_API_VERSION));
}
#endif

#if defined(D3D12_SUPPORT)
std::string GetD3D12SdkVersionString()
{
    return std::string("D3D12 SDK Version ") + std::to_string(D3D12_SDK_VERSION);
}
#endif

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
