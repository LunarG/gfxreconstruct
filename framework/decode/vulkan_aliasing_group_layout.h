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

#ifndef GFXRECON_DECODE_VULKAN_ALIASING_GROUP_LAYOUT_H
#define GFXRECON_DECODE_VULKAN_ALIASING_GROUP_LAYOUT_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief   The single allocation the members of an aliasing group share at replay.
 *
 * Members sit at `bind_offset - base_offset` inside it, the offsets the capture used.
 */
struct AliasingGroupLayout
{
    VkDeviceSize base_offset{ 0 };      ///< smallest captured bind offset of the members
    VkDeviceSize union_size{ 0 };       ///< bytes the allocation needs, rounded up to alignment
    VkDeviceSize alignment{ 0 };        ///< alignment the allocation needs
    uint32_t     memory_type_bits{ 0 }; ///< memory types every member accepts
    bool         valid{ false };        ///< false when no single allocation can hold every member
};

/**
 * @brief   ComputeAliasingGroupLayout sizes the allocation an aliasing group needs.
 *
 * The result is invalid when the group is empty, when the members share no memory type, or when the
 * extent overflows. A group with an invalid layout is dropped and its members are placed one by one.
 *
 * @param   members            the group's members, with their replay memory requirements
 * @param   minimum_alignment  alignment the allocation must have whatever the members ask for
 * @return  the layout.
 */
AliasingGroupLayout
ComputeAliasingGroupLayout(const std::vector<VulkanResourceAllocator::AliasingGroupMember>& members,
                           VkDeviceSize                                                     minimum_alignment);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ALIASING_GROUP_LAYOUT_H
