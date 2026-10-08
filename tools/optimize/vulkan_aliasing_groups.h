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

#ifndef GFXRECON_VULKAN_ALIASING_GROUPS_H
#define GFXRECON_VULKAN_ALIASING_GROUPS_H

#include "format/format.h"
#include "util/defines.h"

#include <cstdint>
#include <limits>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

/**
 * @brief   One resource bound to device memory, as seen in the capture stream.
 *
 * This is the whole input to the grouping: no Vulkan objects, no device, no decoders, so the rule
 * below can be exercised on synthetic shapes.
 */
struct AliasingCandidate
{
    /// A resource whose extent in memory could not be determined.
    static constexpr uint64_t kUnknownFootprint = 0;

    /// A resource that is still alive at the end of the capture.
    static constexpr uint64_t kNeverDestroyed = std::numeric_limits<uint64_t>::max();

    format::HandleId resource_id{ format::kNullHandleId };
    format::HandleId memory_id{ format::kNullHandleId };
    uint64_t         bind_offset{ 0 };
    uint64_t         footprint{ kUnknownFootprint };
    uint64_t         bind_index{ 0 };
    uint64_t         destroy_index{ kNeverDestroyed };
};

/**
 * @brief   A set of candidates that alias one another inside one device memory object.
 */
struct AliasingGroup
{
    format::HandleId    memory_id{ format::kNullHandleId };
    uint32_t            group_id{ 0 };
    std::vector<size_t> members; ///< Indices into the candidate list, ascending.
};

/**
 * @brief   Group the resources that alias one another.
 *
 * Two candidates in the same memory object alias when their lifetimes overlap and their memory
 * ranges overlap:
 * - 'lifetime' is the half-open block-index interval [bind_index, destroy_index),
 *   so a slot reused after its previous occupant is gone does not group.
 * - 'range' is the half-open [bind_offset, bind_offset + footprint) interval.
 *   when a footprint is unknown the test falls back to an equal bind offset
 *   (two resources at one address alias whatever their sizes are).
 * - a resource that overlaps any member joins that member's group.
 *
 * @param   candidates  the bound resources to group, in capture order.
 * @return  the groups of two or more members, ordered by their first member; group ids start at 1.
 */
std::vector<AliasingGroup> ComputeAliasingGroups(const std::vector<AliasingCandidate>& candidates);

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_ALIASING_GROUPS_H
