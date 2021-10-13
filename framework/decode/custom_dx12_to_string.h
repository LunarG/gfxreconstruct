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

#ifndef GFXRECON_CUSTOM_VULKAN_TO_STRING_H
#define GFXRECON_CUSTOM_VULKAN_TO_STRING_H

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"

#include <d3d12.h>

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <typename VkBitmaskType>
inline std::string BitmaskToString(VkFlags vkFlags)
{
    std::string str;
    VkFlags     index = 0;
    while (vkFlags)
    {
        if (vkFlags & 1)
        {
            if (!str.empty())
            {
                str.append("|");
            }
            str.append(ToString(static_cast<VkBitmaskType>(1 << index)));
        }
        ++index;
        vkFlags >>= 1;
    }
    if (str.empty())
    {
        str.append(ToString(static_cast<VkBitmaskType>(0)));
    }
    return str;
}

template <>
std::string ToString<D3D12_CPU_DESCRIPTOR_HANDLE>(const D3D12_CPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize);

template <>
std::string ToString<D3D12_GPU_DESCRIPTOR_HANDLE>(const D3D12_GPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_VULKAN_TO_STRING_H
