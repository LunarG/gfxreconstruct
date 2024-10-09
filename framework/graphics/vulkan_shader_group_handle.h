/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_SHADER_GROUP_HANDLE_H
#define GFXRECON_GRAPHICS_VULKAN_SHADER_GROUP_HANDLE_H

#include "util/defines.h"
#include "util/logging.h"
#include "util/hash.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

struct shader_group_handle_t
{
    static constexpr uint32_t MAX_HANDLE_SIZE       = 32;
    uint8_t                   data[MAX_HANDLE_SIZE] = {};
    uint32_t                  size                  = 0;

    shader_group_handle_t() = default;

    shader_group_handle_t(const uint8_t* in_data, uint32_t in_size)
    {
        GFXRECON_ASSERT(in_size <= MAX_HANDLE_SIZE);
        memcpy(data, in_data, std::min(in_size, MAX_HANDLE_SIZE));
        size = in_size;
    }

    inline bool operator==(const shader_group_handle_t& other) const
    {
        return size == other.size && memcmp(data, other.data, size) == 0;
    }
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

//! std::hash overload
namespace std
{
template <>
struct hash<gfxrecon::graphics::shader_group_handle_t>
{
    inline size_t operator()(const gfxrecon::graphics::shader_group_handle_t& handle) const
    {
        return gfxrecon::util::hash::hash_range(handle.data, handle.data + handle.size);
    }
};

} // namespace std

#endif // GFXRECON_GRAPHICS_VULKAN_SHADER_GROUP_HANDLE_H
