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

#include "util/write_watch_tracker.h"

#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cinttypes>
#include <windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

WriteWatchTracker::WriteWatchTracker() :
    system_page_size_(util::platform::GetSystemPageSize()), system_page_pot_shift_(GetSystemPagePotShift())
{}

WriteWatchTracker::~WriteWatchTracker() {}

size_t WriteWatchTracker::GetSystemPagePotShift() const
{
    size_t pot_shift = 0;
    size_t page_size = util::platform::GetSystemPageSize();

    if (page_size != 0)
    {
        assert((page_size & (page_size - 1)) == 0);
        while (page_size != 1)
        {
            page_size >>= 1;
            ++pot_shift;
        }
    }

    return pot_shift;
}

size_t WriteWatchTracker::GetAlignedSize(size_t size) const
{
    return util::platform::GetAlignedSize(size, system_page_size_);
}

void* WriteWatchTracker::AllocateMemory(size_t aligned_size)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
        // Always enable write watch.
        void* memory = util::platform::AllocateRawMemory(aligned_size, true);

        if (memory == nullptr)
        {
            GFXRECON_LOG_ERROR("WriteWatchTracker failed to allocate memory with size = %" PRIuPTR
                               " with error code: %u",
                               aligned_size,
                               util::platform::GetSystemLastErrorCode());
        }

        return memory;
    }
    else
    {
        GFXRECON_LOG_ERROR("WriteWatchTracker::AllocateMemory(): aligned_size must be greater than 0.");

        return nullptr;
    }
}

void WriteWatchTracker::FreeMemory(void* memory, size_t aligned_size)
{
    assert(memory != nullptr);

    util::platform::FreeRawMemory(memory, aligned_size);
}

size_t WriteWatchTracker::GetMemorySegmentSize(const MemoryInfo* memory_info, size_t page_index) const
{
    assert(memory_info != nullptr);
    assert(page_index < memory_info->total_pages);

    // If this is the last segment of the tracked memory, we want to know if it is a full page or a partial page.
    return ((page_index + 1) < memory_info->total_pages) ? system_page_size_ : memory_info->last_segment_size;
}

void WriteWatchTracker::MemoryCopy(void* destination, const void* source, size_t size)
{
    util::platform::MemoryCopy(destination, size, source, size);
}

void WriteWatchTracker::LoadActiveWriteStates(MemoryInfo* memory_info)
{
    assert((memory_info != nullptr) && (memory_info->shadow_memory != nullptr));

    auto      modified_addresses = memory_info->modified_addresses.get();
    ULONG_PTR modified_count     = memory_info->total_pages;
    DWORD     granularity        = 0;

    if (GetWriteWatch(WRITE_WATCH_FLAG_RESET,
                      memory_info->shadow_memory,
                      memory_info->shadow_range,
                      modified_addresses,
                      &modified_count,
                      &granularity) == 0)
    {
        if (modified_count > 0)
        {
            memory_info->is_modified = true;

            for (ULONG_PTR i = 0; i < modified_count; ++i)
            {
                // Get offset from the page-aligned start address of the shadow memory to the address of the modified
                // page.
                size_t start_offset =
                    static_cast<uint8_t*>(modified_addresses[i]) - static_cast<uint8_t*>(memory_info->shadow_memory);
                size_t page_index = start_offset >> system_page_pot_shift_;

                memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("WriteWatchTracker failed to retrieve write-modified pages for memory region [start address "
                           "= %p, size = %" PRIuPTR "] (GetWriteWatch() produced error code %u)",
                           memory_info->mapped_memory,
                           memory_info->mapped_range,
                           GetLastError());
    }
}

void WriteWatchTracker::ProcessEntry(MemoryInfo* memory_info, const ModifiedMemoryFunc& handle_modified)
{
    assert(memory_info != nullptr);

    bool   active_range = false;
    size_t start_index  = 0;

    memory_info->is_modified = false;

    for (size_t i = 0; i < memory_info->total_pages; ++i)
    {
        // Concatenate dirty pages to handle as large a range as possible with a single modified memory handler
        // invocation.
        if (memory_info->status_tracker.IsActiveWriteBlock(i))
        {
            memory_info->status_tracker.SetActiveWriteBlock(i, false);
            memory_info->status_tracker.SetActiveReadBlock(i, false);

            if (!active_range)
            {
                active_range = true;
                start_index  = i;
            }
        }
        else
        {
            // If the previous pages were modified by a write operation, process the modified range now.
            if (active_range)
            {
                active_range = false;

                ProcessActiveRange(memory_info, start_index, i, handle_modified);
            }
        }
    }

    if (active_range)
    {
        ProcessActiveRange(memory_info, start_index, memory_info->total_pages, handle_modified);
    }
}

void WriteWatchTracker::ProcessActiveRange(MemoryInfo*               memory_info,
                                           size_t                    start_index,
                                           size_t                    end_index,
                                           const ModifiedMemoryFunc& handle_modified)
{
    assert((memory_info != nullptr) && (memory_info->shadow_memory != nullptr));
    assert(end_index > start_index);

    size_t page_count  = end_index - start_index;
    size_t page_offset = start_index << system_page_pot_shift_;
    size_t page_range  = page_count << system_page_pot_shift_;

    if (end_index == memory_info->total_pages)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= system_page_size_ - memory_info->last_segment_size;
    }

    void* source_address      = static_cast<uint8_t*>(memory_info->shadow_memory) + page_offset;
    void* destination_address = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
    MemoryCopy(destination_address, source_address, page_range);

    // The mapped memory address, page offset, and range values to be provided to the callback, which will process
    // the memory range.
    handle_modified(memory_info->memory_id, memory_info->shadow_memory, page_offset, page_range);
}

bool WriteWatchTracker::GetTrackedMemory(uint64_t tracker_key, void** memory)
{
    assert(memory != nullptr);

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(tracker_key);
    if (entry != memory_info_.end())
    {
        if (entry->second.shadow_memory != nullptr)
        {
            (*memory) = entry->second.shadow_memory;
        }
        else
        {
            (*memory) = entry->second.mapped_memory;
        }

        return true;
    }

    return false;
}

void* WriteWatchTracker::AddTrackedMemory(
    uint64_t tracker_key, uint64_t memory_id, void* mapped_memory, size_t mapped_range, uintptr_t shadow_memory_handle)
{
    void*             shadow_memory      = nullptr;
    size_t            shadow_size        = 0;
    ShadowMemoryInfo* shadow_memory_info = nullptr;

    if (shadow_memory_handle != kNullShadowHandle)
    {
        shadow_memory_info = reinterpret_cast<ShadowMemoryInfo*>(shadow_memory_handle);

        assert(shadow_memory_info->memory != nullptr);

        // Set the shadow memory pointer to the start of the mapped range.
        shadow_memory = static_cast<uint8_t*>(shadow_memory_info->memory);
        shadow_size   = mapped_range;
    }
    else
    {
        shadow_size   = GetAlignedSize(mapped_range);
        shadow_memory = AllocateMemory(shadow_size);
    }

    if (shadow_memory != nullptr)
    {
        void*  aligned_address   = shadow_memory;
        size_t guard_range       = mapped_range;
        size_t total_pages       = guard_range >> system_page_pot_shift_;
        size_t last_segment_size = guard_range & (system_page_size_ - 1); // guard_range % system_page_size_

        if (last_segment_size != 0)
        {
            ++total_pages;
        }
        else
        {
            last_segment_size = system_page_size_;
        }

        std::lock_guard<std::mutex> lock(tracked_memory_lock_);

        GFXRECON_ASSERT(memory_info_.find(tracker_key) == memory_info_.end());

        auto entry = memory_info_.emplace(std::piecewise_construct,
                                          std::forward_as_tuple(tracker_key),
                                          std::forward_as_tuple(memory_id,
                                                                mapped_memory,
                                                                mapped_range,
                                                                shadow_memory,
                                                                shadow_size,
                                                                total_pages,
                                                                last_segment_size,
                                                                shadow_memory_handle == kNullShadowHandle));

        if (!entry.second)
        {
            // For persistent memory, We don't free the shadow allocation now, expecting it to be freed later
            // when the mapped memory object is freed, but will not return a pointer to the shadow memory to the
            // caller.
            if (shadow_memory_handle == kNullShadowHandle)
            {
                FreeMemory(shadow_memory, shadow_size);
            }

            shadow_memory = nullptr;
        }
    }

    return (shadow_memory != nullptr) ? shadow_memory : mapped_memory;
}

void WriteWatchTracker::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        const MemoryInfo& memory_info = entry->second;

        if ((memory_info.shadow_memory != nullptr) && memory_info.own_shadow_memory)
        {
            FreeMemory(memory_info.shadow_memory, memory_info.shadow_range);
        }

        memory_info_.erase(entry);
    }
}

bool WriteWatchTracker::UpdateTrackedMemory(uint64_t tracker_key,
                                            uint64_t memory_id,
                                            void*    mapped_memory,
                                            void**   shadow_memory)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(tracker_key);
    if (entry != memory_info_.end())
    {
        MemoryInfo& memory_info   = entry->second;
        memory_info.memory_id     = memory_id;
        memory_info.mapped_memory = mapped_memory;

        if ((shadow_memory != nullptr) && (entry->second.shadow_memory != nullptr))
        {
            (*shadow_memory) = entry->second.shadow_memory;
        }

        return true;
    }

    return false;
}

uintptr_t WriteWatchTracker::AllocatePersistentShadowMemory(size_t size)
{
    ShadowMemoryInfo* info          = nullptr;
    size_t            shadow_size   = GetAlignedSize(size);
    void*             shadow_memory = AllocateMemory(shadow_size);

    if (shadow_memory != nullptr)
    {
        size_t total_shadow_pages       = shadow_size >> system_page_pot_shift_;
        size_t last_shadow_segment_size = size & (system_page_size_ - 1); // allocation_size % system_page_size_

        info = new ShadowMemoryInfo(shadow_memory, shadow_size, total_shadow_pages, last_shadow_segment_size);
    }

    return reinterpret_cast<uintptr_t>(info);
}

void WriteWatchTracker::FreePersistentShadowMemory(uintptr_t shadow_memory_handle)
{
    auto info = reinterpret_cast<ShadowMemoryInfo*>(shadow_memory_handle);

    if (info != nullptr)
    {
        FreeMemory(info->memory, info->size);
        delete info;
    }
}

void WriteWatchTracker::ProcessMemoryEntry(uint64_t tracker_key, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(tracker_key);

    if (entry != memory_info_.end())
    {
        auto memory_info = &entry->second;

        LoadActiveWriteStates(memory_info);

        if (memory_info->is_modified)
        {
            ProcessEntry(memory_info, handle_modified);
        }
    }
}

void WriteWatchTracker::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        auto memory_info = &entry->second;

        LoadActiveWriteStates(memory_info);

        if (memory_info->is_modified)
        {
            ProcessEntry(memory_info, handle_modified);
        }
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
