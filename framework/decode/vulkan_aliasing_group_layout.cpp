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

#include "decode/vulkan_aliasing_group_layout.h"

#include "util/alignment_utils.h"

#include <algorithm>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

AliasingGroupLayout ComputeAliasingGroupLayout(const std::vector<VulkanResourceAllocator::AliasingGroupMember>& members,
                                               VkDeviceSize minimum_alignment)
{
    AliasingGroupLayout layout;
    if (members.empty())
    {
        return layout;
    }

    layout.base_offset      = std::numeric_limits<VkDeviceSize>::max();
    layout.memory_type_bits = std::numeric_limits<uint32_t>::max();
    layout.alignment        = minimum_alignment;

    for (const auto& member : members)
    {
        layout.base_offset = std::min(layout.base_offset, member.bind_offset);
    }

    for (const auto& member : members)
    {
        layout.alignment = std::max(layout.alignment, member.requirements.alignment);
        layout.memory_type_bits &= member.requirements.memoryTypeBits;

        // The union is measured in replay bytes from the group base, per member.
        const VkDeviceSize local = member.bind_offset - layout.base_offset;
        if (member.requirements.size > std::numeric_limits<VkDeviceSize>::max() - local)
        {
            return AliasingGroupLayout{};
        }
        layout.union_size = std::max(layout.union_size, local + member.requirements.size);
    }

    if (layout.memory_type_bits == 0 || layout.union_size == 0)
    {
        return AliasingGroupLayout{};
    }

    if (layout.alignment != 0)
    {
        if (layout.union_size > std::numeric_limits<VkDeviceSize>::max() - (layout.alignment - 1))
        {
            return AliasingGroupLayout{};
        }
        layout.union_size = util::aligned_value(layout.union_size, layout.alignment);
    }

    layout.valid = true;
    return layout;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
