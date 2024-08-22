/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_UTIL_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#elif defined(__APPLE__)
    "libvulkan.dylib", "libvulkan.1.dylib", "libMoltenVK.dylib"
#else
    "libvulkan.so.1", "libvulkan.so"
#endif
};

util::platform::LibraryHandle InitializeLoader();

void ReleaseLoader(util::platform::LibraryHandle loader_handle);

// Search through the parent's pNext chain for the first struct with the requested struct_type. parent's struct type is
// not checked and parent won't be returned as a result. T and Parent_T must be Vulkan struct pointer types. Return
// nullptr if no matching struct found.
template <typename T, typename Parent_T>
static T* GetPNextStruct(const Parent_T* parent, VkStructureType struct_type)
{
    VkBaseOutStructure* current_struct = reinterpret_cast<const VkBaseOutStructure*>(parent)->pNext;
    while (current_struct != nullptr)
    {
        if (current_struct->sType == struct_type)
        {
            return reinterpret_cast<T*>(current_struct);
        }
        current_struct = current_struct->pNext;
    }
    return nullptr;
}

static const char* kVulkanVrFrameDelimiterString = "vr-marker,frame_end,type,application";

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_UTIL_H
