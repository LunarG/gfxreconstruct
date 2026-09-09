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
/// @file gfxrecon_optimize test main entry point

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "vulkan_aliasing_groups.h"

#include <vector>

using gfxrecon::AliasingCandidate;
using gfxrecon::AliasingGroup;
using gfxrecon::ComputeAliasingGroups;

namespace
{

constexpr gfxrecon::format::HandleId kMemory  = 12;
constexpr gfxrecon::format::HandleId kMemory2 = 15;

// A resource that lives from its bind to the end of the capture, which is what every sample in the
// aliasing test corpus does.
AliasingCandidate Bound(gfxrecon::format::HandleId resource_id,
                        uint64_t                   bind_offset,
                        uint64_t                   footprint,
                        uint64_t                   bind_index,
                        gfxrecon::format::HandleId memory_id = kMemory)
{
    AliasingCandidate candidate;
    candidate.resource_id = resource_id;
    candidate.memory_id   = memory_id;
    candidate.bind_offset = bind_offset;
    candidate.footprint   = footprint;
    candidate.bind_index  = bind_index;
    return candidate;
}

std::vector<gfxrecon::format::HandleId> MemberIds(const std::vector<AliasingCandidate>& candidates,
                                                  const AliasingGroup&                  group)
{
    std::vector<gfxrecon::format::HandleId> ids;
    for (size_t index : group.members)
    {
        ids.push_back(candidates[index].resource_id);
    }
    return ids;
}

} // namespace

TEST_CASE("Aliasing grouping covers the shapes in the aliasing test corpus", "[optimize]")
{
    SECTION("a parent spanning two disjoint children groups all three")
    {
        // The children do not overlap each other, so only closing the relation over the parent puts
        // them in one group.
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10),
                                                         Bound(2, 256, 256, 11),
                                                         Bound(3, 512, 256, 12) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(groups[0].memory_id == kMemory);
        REQUIRE(groups[0].group_id == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2, 3 });
    }

    SECTION("two resources overlapping without a container group")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 512, 1536, 11) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2 });
    }

    SECTION("a full alias at a non-zero offset groups")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 4096, 512, 10), Bound(2, 4096, 512, 11) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2 });
    }

    SECTION("five resources at one offset form one group, not four pairs")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 4096, 512, 10),
                                                         Bound(2, 4096, 512, 11),
                                                         Bound(3, 4096, 512, 12),
                                                         Bound(4, 4096, 512, 13),
                                                         Bound(5, 4096, 512, 14) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(groups[0].members.size() == 5);
    }

    SECTION("nested extents at three distinct offsets form one group")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 8448, 10),
                                                         Bound(2, 4096, 4352, 11),
                                                         Bound(3, 8192, 256, 12) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2, 3 });
    }

    SECTION("a buffer and an image of unequal size at one offset group, and a disjoint pair does not")
    {
        // One memory holds an aliased pair, the other holds two resources whose ranges do not meet.
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 4915200, 10),
                                                         Bound(2, 0, 1228800, 11),
                                                         Bound(3, 0, 4915200, 12, kMemory2),
                                                         Bound(4, 4915200, 1228800, 13, kMemory2) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(groups[0].memory_id == kMemory);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2 });
    }

    SECTION("the larger resource bound second still groups")
    {
        // The bind order the replay-time detection cannot size up front.  Grouping must not depend on
        // which member binds first.
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1228800, 10), Bound(2, 0, 4915200, 11) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 2 });
    }
}

TEST_CASE("Aliasing grouping uses lifetimes to tell aliasing from slot reuse", "[optimize]")
{
    SECTION("a slot reused after its occupant is destroyed does not group")
    {
        std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 0, 1024, 30) };
        candidates[0].destroy_index = 20;

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }

    SECTION("a resource destroyed after the next one binds groups")
    {
        std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 0, 1024, 30) };
        candidates[0].destroy_index = 40;

        REQUIRE(ComputeAliasingGroups(candidates).size() == 1);
    }

    SECTION("a destroy at the exact bind index of the next resource does not group")
    {
        // The lifetime interval is half-open, so the slot is free again at the destroying block.
        std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 0, 1024, 30) };
        candidates[0].destroy_index = 30;

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }

    SECTION("a chain of three sequential occupants of one slot forms no group")
    {
        std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10),
                                                   Bound(2, 0, 1024, 30),
                                                   Bound(3, 0, 1024, 50) };
        candidates[0].destroy_index = 20;
        candidates[1].destroy_index = 40;

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }
}

TEST_CASE("Aliasing grouping treats an unknown footprint as an offset match", "[optimize]")
{
    SECTION("two resources at one offset group even with no footprint")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 4096, AliasingCandidate::kUnknownFootprint, 10),
                                                         Bound(2, 4096, AliasingCandidate::kUnknownFootprint, 11) };

        REQUIRE(ComputeAliasingGroups(candidates).size() == 1);
    }

    SECTION("a resource with no footprint does not group into an enclosing range")
    {
        // Without an extent there is nothing to intersect, so the containment cannot be seen and the
        // resource is left to the per-bind detection at replay.
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 8192, 10),
                                                         Bound(2, 4096, AliasingCandidate::kUnknownFootprint, 11) };

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }
}

TEST_CASE("Aliasing grouping separates memory objects and numbers groups in capture order", "[optimize]")
{
    // Two independent pairs, interleaved in the stream, in two memory objects.  The second memory
    // sorts first by handle id in neither direction by accident: it is the higher id but its pair
    // binds later, so the ids follow the stream, not the handle values.
    const std::vector<AliasingCandidate> candidates{
        Bound(1, 0, 1024, 10), Bound(2, 0, 1024, 11, kMemory2), Bound(3, 0, 1024, 12), Bound(4, 0, 1024, 13, kMemory2)
    };

    const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
    REQUIRE(groups.size() == 2);

    REQUIRE(groups[0].group_id == 1);
    REQUIRE(groups[0].memory_id == kMemory);
    REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 3 });

    REQUIRE(groups[1].group_id == 2);
    REQUIRE(groups[1].memory_id == kMemory2);
    REQUIRE(MemberIds(candidates, groups[1]) == std::vector<gfxrecon::format::HandleId>{ 2, 4 });
}

TEST_CASE("Aliasing grouping leaves a resource that aliases nothing alone", "[optimize]")
{
    SECTION("no candidates")
    {
        REQUIRE(ComputeAliasingGroups({}).empty());
    }

    SECTION("one candidate is not a group")
    {
        REQUIRE(ComputeAliasingGroups({ Bound(1, 0, 1024, 10) }).empty());
    }

    SECTION("adjacent ranges do not overlap")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 1024, 1024, 11) };

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }

    SECTION("the same offset in different memory objects does not group")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10), Bound(2, 0, 1024, 11, kMemory2) };

        REQUIRE(ComputeAliasingGroups(candidates).empty());
    }

    SECTION("an ungrouped resource between two that alias does not join them")
    {
        const std::vector<AliasingCandidate> candidates{ Bound(1, 0, 1024, 10),
                                                         Bound(2, 4096, 1024, 11),
                                                         Bound(3, 512, 1024, 12) };

        const std::vector<AliasingGroup> groups = ComputeAliasingGroups(candidates);
        REQUIRE(groups.size() == 1);
        REQUIRE(MemberIds(candidates, groups[0]) == std::vector<gfxrecon::format::HandleId>{ 1, 3 });
    }
}
