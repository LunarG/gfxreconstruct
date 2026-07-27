/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include <bit>
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

    static constexpr size_t kBlockSize         = 512;
    static constexpr size_t kBlockSizePotShift = std::countr_zero(kBlockSize);

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
    // Avoid including xxhash.h here. Define a compatible type for XXH128_hash_t
    struct Hash128
    {
        uint64_t low64;
        uint64_t high64;

        template <typename T>
        bool operator!=(const T& other) const
        {
            return low64 != other.low64 || high64 != other.high64;
        }
    };

    using HashArray = std::vector<Hash128>;

    struct MemoryInfo
    {
        uint64_t              allocation_size{ 0 };
        VkMemoryPropertyFlags property_flags{ 0 };
        const uint8_t*        mapped_data{ nullptr };
        uint64_t              mapped_offset{ 0 };
        uint64_t              mapped_size{ 0 };
        util::RangeList       exposed_ranges;

        struct RangeHashes
        {
            RangeHashes() = delete;
            RangeHashes(size_t tb, size_t lbs) :
                total_blocks(tb), last_block_size(lbs), current_hashes(tb), previous_hashes(tb)
            {}

            size_t total_blocks;
            size_t last_block_size;

            HashArray current_hashes;
            HashArray previous_hashes;
        };

        // Map per offset
        std::unordered_map<uint64_t, RangeHashes> valid_range_hashes;
    };

    using MemoryInfoMap      = std::unordered_map<format::HandleId, MemoryInfo>;
    using MemoryInfoIterator = MemoryInfoMap::iterator;

  private:
    static uint64_t ClampRangeSize(uint64_t offset, uint64_t size, uint64_t limit);

    void EmitRange(MemoryInfoIterator        memory_info_entry,
                   uint64_t                  offset,
                   uint64_t                  size,
                   const ModifiedMemoryFunc& handle_modified);

    void EmitMappedIntersections(MemoryInfoIterator        memory_info_entry,
                                 const util::RangeList&    ranges,
                                 const ModifiedMemoryFunc& handle_modified);

    void ProcessActiveRange(uint64_t                       memory_id,
                            const uint8_t*                 data,
                            size_t                         offset_in_mapping,
                            const MemoryInfo::RangeHashes& range_info,
                            size_t                         start_index,
                            size_t                         end_index,
                            const ModifiedMemoryFunc&      handle_modified);

    template <typename PerBlockFn>
    void ForEachBlock(const MemoryInfo::RangeHashes& range_info, PerBlockFn&& fn)
    {
        const size_t full_blocks =
            range_info.last_block_size == kBlockSize ? range_info.total_blocks : range_info.total_blocks - 1;

        for (size_t i = 0; i < full_blocks; ++i)
        {
            fn(i, kBlockSize);
        }

        // Handle last, possibly partial, block
        if (full_blocks == range_info.total_blocks - 1)
        {
            fn(full_blocks, range_info.last_block_size);
        }
    }

  private:
    std::mutex    tracked_memory_lock_;
    MemoryInfoMap memory_info_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_SMART_MEMORY_TRACKER_H
