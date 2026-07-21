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

#ifndef GFXRECON_ENCODE_VULKAN_SMART_MEMORY_TRACKER_H
#define GFXRECON_ENCODE_VULKAN_SMART_MEMORY_TRACKER_H

#include "format/format.h"
#include "util/range_list.h"

#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <functional>
#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanSmartMemoryTracker
{
  public:
    using ModifiedMemoryFunc = std::function<void(uint64_t, const void*, size_t, size_t)>;

  public:
    VulkanSmartMemoryTracker() = default;

    void TrackMemory(format::HandleId memory_id, uint64_t allocation_size, VkMemoryPropertyFlags property_flags);
    void RemoveMemory(format::HandleId memory_id);

    void MapMemory(format::HandleId memory_id, const void* mapped_data, uint64_t offset, uint64_t size);
    void UnmapMemory(format::HandleId memory_id);

    void
    FlushRange(format::HandleId memory_id, uint64_t offset, uint64_t size, const ModifiedMemoryFunc& handle_modified);
    void FlushMappedMemory(format::HandleId memory_id, const ModifiedMemoryFunc& handle_modified);

    void ProcessSubmit(const std::unordered_map<format::HandleId, util::RangeList>& touched_ranges,
                       const ModifiedMemoryFunc&                                    handle_modified);

  private:
    struct MemoryInfo
    {
        uint64_t              allocation_size{ 0 };
        VkMemoryPropertyFlags property_flags{ 0 };
        const uint8_t*        mapped_data{ nullptr };
        uint64_t              mapped_offset{ 0 };
        uint64_t              mapped_size{ 0 };
        util::RangeList       exposed_ranges;
        util::RangeList       baseline_valid_ranges;
        std::vector<uint8_t>  baseline;
    };

    using MemoryInfoMap      = std::unordered_map<format::HandleId, MemoryInfo>;
    using MemoryInfoIterator = MemoryInfoMap::iterator;

  private:
    static uint64_t ClampRangeSize(uint64_t offset, uint64_t size, uint64_t limit);

    bool EnsureBaseline(MemoryInfo& memory_info);

    void EmitRange(MemoryInfoIterator        memory_info_entry,
                   uint64_t                  offset,
                   uint64_t                  size,
                   const ModifiedMemoryFunc& handle_modified);

    void EmitMappedIntersections(MemoryInfoIterator        memory_info_entry,
                                 const util::RangeList&    ranges,
                                 const ModifiedMemoryFunc& handle_modified);

  private:
    std::mutex    tracked_memory_lock_;
    MemoryInfoMap memory_info_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_SMART_MEMORY_TRACKER_H
