/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2015-2020 Valve Corporation
** Copyright (c) 2015-2020 LunarG, Inc.
** Copyright (c) 2024 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#ifndef GFXRECON_UTIL_WRITE_WATCH_TRACKER_H
#define GFXRECON_UTIL_WRITE_WATCH_TRACKER_H

#include "util/defines.h"
#include "util/platform.h"
#include "util/page_status_tracker.h"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class WriteWatchTracker
{
  public:
    static const uintptr_t kNullShadowHandle = 0;

  public:
    // Callback for processing modified memory. The function parameters are the ID of the modified memory object,
    // a pointer to the start of the modified memory range, the offset from the initial mapped memory pointer to
    // the modified range pointer, and the size of the modified range.
    typedef std::function<void(uint64_t, void*, size_t, size_t)> ModifiedMemoryFunc;

  public:
    WriteWatchTracker();

    ~WriteWatchTracker();

    bool GetTrackedMemory(uint64_t tracker_key, void** memory);

    void* AddTrackedMemory(uint64_t  tracker_key,
                           uint64_t  memory_id,
                           void*     mapped_memory,
                           size_t    mapped_range,
                           uintptr_t shadow_memory_handle);

    void RemoveTrackedMemory(uint64_t memory_id);

    // Replace the memory ID and memory allocation for the specified entry, optionally retrieving the pointer to the
    // shadow memory. Primarily intended for updating mapped memory info associated with persistent shadow memory
    // allocations.
    bool UpdateTrackedMemory(uint64_t tracker_key, uint64_t memory_id, void* mapped_memory, void** shadow_memory);

    void ProcessMemoryEntry(uint64_t tracker_key, const ModifiedMemoryFunc& handle_modified);

    void ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified);

    size_t GetAlignedSize(size_t size) const;

    void* AllocateMemory(size_t aligned_size);

    void FreeMemory(void* pMemory, size_t aligned_size);

    uintptr_t AllocatePersistentShadowMemory(size_t size);

    void FreePersistentShadowMemory(uintptr_t shadow_memory_handle);

  private:
    struct MemoryInfo
    {
        MemoryInfo(uint64_t mi, void* mm, size_t mr, void* sm, size_t sr, size_t tp, size_t lss, bool os) :
            status_tracker(tp), memory_id(mi), mapped_memory(mm), mapped_range(mr), shadow_memory(sm), shadow_range(sr),
            total_pages(tp), last_segment_size(lss), is_modified(false), own_shadow_memory(os)
        {
            modified_addresses = std::make_unique<void*[]>(total_pages);
        }

        PageStatusTracker status_tracker;

        uint64_t memory_id;     // ID of the mapped memory to be tracked.
        void*    mapped_memory; // Pointer to mapped memory to be tracked.
        size_t   mapped_range;  // Size of the mapped memory range.
        void*    shadow_memory; // Shadow memory for mapped memory types that cannot be tracked by guard pages.
        size_t   shadow_range; // Size of the shadow memory allocation, which is the mapped memory size adjusted to be a
                               // multiple of system page size.
        size_t total_pages;    // Total number of pages contained by the mapped memory.
        size_t last_segment_size; // Size of the last segment of the mapped memory, which may not be a full page.
        bool   is_modified;
        bool   own_shadow_memory;

        std::unique_ptr<void*[]> modified_addresses; // Memory for retrieving modified pages with GetWriteWatch.
    };

    struct ShadowMemoryInfo
    {
        ShadowMemoryInfo(void* sm, size_t ss, size_t tp, size_t lss) :
            memory(sm), size(ss), total_pages(tp), last_segment_size(lss)
        {}

        void*  memory;            // Pointer to the shadow memory.
        size_t size;              // Page-aligned size of the shadow memory.
        size_t total_pages;       // Total number of pages in the shadow memory.
        size_t last_segment_size; // Size of the last segment of the mapped memory.
    };

    typedef std::unordered_map<uint64_t, MemoryInfo> MemoryInfoMap;

  private:
    size_t GetSystemPagePotShift() const;
    size_t GetMemorySegmentSize(const MemoryInfo* memory_info, size_t page_index) const;
    void   MemoryCopy(void* destination, const void* source, size_t size);
    void   LoadActiveWriteStates(MemoryInfo* memory_info);
    void   ProcessEntry(MemoryInfo* memory_info, const ModifiedMemoryFunc& handle_modified);
    void   ProcessActiveRange(MemoryInfo*               memory_info,
                              size_t                    start_index,
                              size_t                    end_index,
                              const ModifiedMemoryFunc& handle_modified);

    size_t GetOffsetFromPageStart(void* address) const
    {
        return reinterpret_cast<uintptr_t>(address) & (system_page_size_ - 1);
    }

    void* AlignToPageStart(void* address) const
    {
        return static_cast<uint8_t*>(address) - GetOffsetFromPageStart(address);
    }

  private:
    MemoryInfoMap memory_info_;
    const size_t  system_page_size_;
    const size_t  system_page_pot_shift_;
    std::mutex    tracked_memory_lock_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_WRITE_WATCH_TRACKER_H
