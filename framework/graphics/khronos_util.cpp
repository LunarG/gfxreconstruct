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

#include "graphics/khronos_util.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

const std::vector<std::string> kVulkanLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#elif defined(__APPLE__)
    "libvulkan.dylib", "libvulkan.1.dylib", "libMoltenVK.dylib"
#else
    "libvulkan.so.1", "libvulkan.so"
#endif
};
const std::vector<std::string> kOpenXrLoaderLibNames = {
#if defined(WIN32)
    "openxr_loader-1.dll"
#elif defined(__APPLE__)
    "libopenxr_loader.dylib", "libopenxr_loader.1.dylib"
#else
    "libopenxr_loader.so.1", "libopenxr_loader.so"
#endif
};

util::platform::LibraryHandle InitializeKhronosLoader(KhronosLoaderType type)
{
    switch (type)
    {
        case KhronosLoader_Vulkan:
            return util::platform::OpenLibrary(kVulkanLoaderLibNames);
        case KhronosLoader_OpenXR:
            return util::platform::OpenLibrary(kOpenXrLoaderLibNames);
        default:
            GFXRECON_LOG_FATAL("Unsupported Khronos Loader option %d", type);
            GFXRECON_ASSERT(false);

#if defined(WIN32)
            return reinterpret_cast<util::platform::LibraryHandle>(INVALID_HANDLE_VALUE);
#else
            return nullptr;
#endif
    }
}

void ReleaseKhronosLoader(util::platform::LibraryHandle loader_handle)
{
    if (loader_handle != nullptr)
    {
        util::platform::CloseLibrary(loader_handle);
    }
}

bool ImageHasUsage(VkImageUsageFlags usage_flags, VkImageUsageFlagBits bit)
{
    return (usage_flags & bit) == bit;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
