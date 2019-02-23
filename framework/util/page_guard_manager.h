/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2015-2018 Valve Corporation
** Copyright (c) 2015-2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_UTIL_PAGE_GUARD_MANAGER_H
#define GFXRECON_UTIL_PAGE_GUARD_MANAGER_H

#include "util/defines.h"
#include "util/page_status_tracker.h"

#include <cstdint>
#include <functional>
#include <mutex>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class PageGuardManager
{
  public:
    static const bool kDefaultEnableShadowCachedMemory   = false;
    static const bool kDefaultEnableUncachedRead         = false;
    static const bool kDefaultEnableCopyOnMap            = true;
    static const bool kDefaultEnableLazyCopy             = true;
    static const bool kDefaultEnableSeparateReadTracking = true;
    static const bool kDefaultEnableReadWriteSamePage    = true;

  public:
    // Callback for processing modified memory.  The function parameters are the ID of the modified memory object,
    // a pointer to the start of the modified memory range, the offset from the initial mapped memory pointer to
    // the modified range pointer, and the size of the modified range.
    typedef std::function<void(uint64_t, void*, size_t, size_t)> ModifiedMemoryFunc;

  public:
    static void Create(bool enable_shadow_cached_memory,
                       bool enable_uncached_read,
                       bool enable_copy_on_map,
                       bool enable_lazy_copy,
                       bool enable_separate_read_tracking,
                       bool expect_read_write_same_page);

    static void Destroy();

    static PageGuardManager* Get() { return instance_; }

    void* AddMemory(uint64_t memory_id, void* mapped_memory, size_t size, bool is_cached);

    void RemoveMemory(uint64_t memory_id);

    bool ProcessMemoryEntry(uint64_t memory_id, ModifiedMemoryFunc handle_modified);

    void ProcessMemoryEntries(ModifiedMemoryFunc handle_modified);

    bool HandleGuardPageViolation(void* address, bool is_write, bool clear_guard);

  protected:
    PageGuardManager();

    PageGuardManager(bool enable_shadow_cached_memory,
                     bool enable_uncached_read,
                     bool enable_copy_on_map,
                     bool enable_lazy_copy,
                     bool enable_separate_read_tracking,
                     bool expect_read_write_same_page);

    ~PageGuardManager();

  private:
    struct MemoryInfo
    {
        MemoryInfo(void* mm, size_t mr, void* sm, size_t sr, size_t tp, size_t lss, bool ic) :
            status_tracker(tp), mapped_memory(mm), mapped_range(mr), shadow_memory(sm), shadow_range(sr),
            total_pages(tp), last_segment_size(lss), is_cached(ic), is_modified(false)
        {}

        PageStatusTracker status_tracker;

        void*  mapped_memory;  // Pointer to mapped memory to be tracked.
        size_t mapped_range;   // Size of the mapped memory range.
        void*  shadow_memory;  // Shadow memory for mapped memory types that cannot be tracked by guard pages.
        size_t shadow_range;   // Size of the shadow memory allocation, which is the mapped memory size adjusted to be a
                               // multiple of system page size.
        size_t total_pages;    // Total number of pages contained by the mapped memory.
        size_t last_segment_size; // Size of the last segment of the mapped memory, which may not be a full page.
        bool   is_cached;
        bool   is_modified;
    };

    typedef std::unordered_map<uint64_t, MemoryInfo> MemoryInfoMap;

  private:
    size_t GetSystemPageSize() const;
    size_t GetAdjustedSize(size_t size) const;

    void* AllocateShadowMemory(size_t size);
    void  FreeShadowMemory(void* pMemory, size_t size);

    void AddExceptionHandler();
    void RemoveExceptionHandler();
    void ClearExceptionHandler(void* exception_handler);

    size_t GetMemorySegmentSize(const MemoryInfo* memory_info, size_t page_index) const;
    void   MemoryCopy(void* destination, const void* source, size_t size);
    bool   FindMemory(void* address, void** watched_memory, MemoryInfo** watched_memory_info);
    bool   SetMemoryProtection(void* protect_address, size_t protect_size, uint32_t protect_mask);
    void   ProcessEntry(uint64_t memory_id, MemoryInfo* memory_info, ModifiedMemoryFunc handle_modified);
    void   ProcessActiveRange(uint64_t           memory_id,
                              MemoryInfo*        memory_info,
                              size_t             start_index,
                              size_t             end_index,
                              ModifiedMemoryFunc handle_modified);

    size_t GetOffsetFromPageStart(void* address) const
    {
        return reinterpret_cast<uintptr_t>(address) % system_page_size_;
    }

    void* AlignToPageStart(void* address) const
    {
        return static_cast<uint8_t*>(address) - GetOffsetFromPageStart(address);
    }

  private:
    static PageGuardManager* instance_;
    MemoryInfoMap            memory_info_;
    std::mutex               tracked_memory_lock_;
    void*                    exception_handler_;
    uint32_t                 exception_handler_count_;
    const size_t             system_page_size_;
    bool                     enable_shadow_cached_memory_;
    bool                     enable_uncached_read_;
    bool                     enable_copy_on_map_;
    bool                     enable_lazy_copy_;

    // These options only apply to WIN32 builds, or to Linux builds generated with the PAGE_GUARD_ENABLE_X86_64_UCONTEXT
    // pre-processor directive.
    bool enable_separate_read_tracking_;
    bool enable_read_write_same_page_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PAGE_GUARD_MANAGER_H
