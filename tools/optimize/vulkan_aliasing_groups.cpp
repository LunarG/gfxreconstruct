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

#include "vulkan_aliasing_groups.h"

#include <algorithm>
#include <map>
#include <numeric>
#include <ranges>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

namespace
{

// Half-open block-index intervals.  A resource destroyed before another one binds never shares its
// slot, which is the render-graph transient pattern the metadata must not group.
bool LifetimesOverlap(const AliasingCandidate& a, const AliasingCandidate& b)
{
    return (a.bind_index < b.destroy_index) && (b.bind_index < a.destroy_index);
}

// Half-open memory ranges where both footprints are known.  Two resources at one offset alias
// whatever their sizes are, so an unknown footprint falls back to an equal offset.
bool RangesOverlap(const AliasingCandidate& a, const AliasingCandidate& b)
{
    if ((a.footprint == AliasingCandidate::kUnknownFootprint) || (b.footprint == AliasingCandidate::kUnknownFootprint))
    {
        return a.bind_offset == b.bind_offset;
    }
    return (a.bind_offset < (b.bind_offset + b.footprint)) && (b.bind_offset < (a.bind_offset + a.footprint));
}

size_t FindRoot(std::vector<size_t>& parents, size_t index)
{
    while (parents[index] != index)
    {
        parents[index] = parents[parents[index]];
        index          = parents[index];
    }
    return index;
}

} // namespace

std::vector<AliasingGroup> ComputeAliasingGroups(const std::vector<AliasingCandidate>& candidates)
{
    std::vector<size_t> parents(candidates.size());
    std::iota(parents.begin(), parents.end(), size_t{ 0 });

    // Only resources in the same memory object can alias, so the quadratic comparison runs per
    // memory object rather than over the whole capture.  An ordered map keeps the result independent
    // of handle hashing.
    std::map<format::HandleId, std::vector<size_t>> by_memory;
    for (size_t index = 0; index < candidates.size(); ++index)
    {
        by_memory[candidates[index].memory_id].push_back(index);
    }

    for (const auto& indices : by_memory | std::views::values)
    {
        for (size_t i = 0; i < indices.size(); ++i)
        {
            for (size_t j = i + 1; j < indices.size(); ++j)
            {
                const AliasingCandidate& a = candidates[indices[i]];
                const AliasingCandidate& b = candidates[indices[j]];

                if (LifetimesOverlap(a, b) && RangesOverlap(a, b))
                {
                    parents[FindRoot(parents, indices[i])] = FindRoot(parents, indices[j]);
                }
            }
        }
    }

    // Collect the components, keyed by their root.  Members come out ascending because the indices go
    // in ascending, but a root is whichever member the unions happened to leave on top, so the
    // components are ordered by their first member before the ids are handed out.
    std::map<size_t, std::vector<size_t>> components;
    for (size_t index = 0; index < candidates.size(); ++index)
    {
        components[FindRoot(parents, index)].push_back(index);
    }

    std::vector<AliasingGroup> groups;
    for (auto& members : components | std::views::values)
    {
        if (members.size() >= 2)
        {
            AliasingGroup group;
            group.memory_id = candidates[members.front()].memory_id;
            group.members   = std::move(members);
            groups.push_back(std::move(group));
        }
    }

    std::ranges::sort(
        groups, [](const AliasingGroup& a, const AliasingGroup& b) { return a.members.front() < b.members.front(); });

    for (size_t index = 0; index < groups.size(); ++index)
    {
        groups[index].group_id = static_cast<uint32_t>(index + 1);
    }

    return groups;
}

GFXRECON_END_NAMESPACE(gfxrecon)
