/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2015-2020 Valve Corporation
** Copyright (c) 2015-2020 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_PAGE_GUARD_MANAGER_H
#define GFXRECON_UTIL_PAGE_GUARD_MANAGER_H

#include "util/defines.h"
#include "util/page_status_tracker.h"
#include "util/platform.h"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <atomic>

#if !defined(WIN32)
#include <pthread.h>
#endif

#if defined(WIN32) || defined(__APPLE__)
#define USERFAULTFD_SUPPORTED 0
#else
#include <linux/userfaultfd.h>
// Older kernels might not support all features we need from userfaultfd. Check what is available.
#if defined(UFFD_USER_MODE_ONLY) && defined(UFFDIO_WRITEPROTECT) && defined(UFFDIO_WRITEPROTECT_MODE_WP)
#define USERFAULTFD_SUPPORTED 1
#else
#define USERFAULTFD_SUPPORTED 0
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class PageGuardManager
{
  public:
    enum MemoryProtectionMode
    {
        kMProtectMode,
        kUserFaultFdMode
    };

    static const bool                 kDefaultEnableCopyOnMap                 = true;
    static const bool                 kDefaultEnableSeparateRead              = true;
    static const bool                 kDefaultEnableReadWriteSamePage         = true;
    static const bool                 kDefaultUnblockSIGSEGV                  = false;
    static const bool                 kDefaultEnableSignalHandlerWatcher      = false;
    static const int                  kDefaultSignalHandlerWatcherMaxRestores = 1;
    static const MemoryProtectionMode kDefaultMemoryProtMode                  = kMProtectMode;

    static const uintptr_t kNullShadowHandle = 0;

  public:
    // Callback for processing modified memory.  The function parameters are the ID of the modified memory object,
    // a pointer to the start of the modified memory range, the offset from the initial mapped memory pointer to
    // the modified range pointer, and the size of the modified range.
    typedef std::function<void(uint64_t, void*, size_t, size_t)> ModifiedMemoryFunc;

  public:
    static void Create(bool                 enable_copy_on_map,
                       bool                 enable_separate_read,
                       bool                 expect_read_write_same_page,
                       bool                 unblock_SIGSEGV,
                       bool                 enable_signal_handler_watcher,
                       int                  signal_handler_watcher_max_restores,
                       MemoryProtectionMode protection_mode);

    static void Destroy();

    static PageGuardManager* Get() { return instance_; }

    bool UseSeparateRead() const { return enable_separate_read_; }

    bool GetTrackedMemory(uint64_t memory_id, void** memory);

    // The use_write_watch parameter is ignored on all platforms except Windows, and is ignored on Windows if
    // shadow_memory is true.
    //
    // The shadow_memory_handle parameter is an option value that allows the lifetime of the shadow memory allocation to
    // be managed externally.  Unless opy-on-map is disabled, copies from the mapped_range portion of mapped_memory to
    // the shadow memory are performed once, the first time that the shadow memory is added for tracking.  Copies will
    // not be performed if the mapped range is removed from tracking and then added again.
    //
    // When use_shadow_memory is true and shadow_memory_handle is kNullShadowHandle, an internally managed shadow
    // allocation will be created.  Unless copy-on-map is disabled, the content of the mapped_range portion of
    // mapped_memory will be copied to the shadow allocation.  The shadow allocation will be freed by
    // RemoveTrackedMemory.
    void* AddTrackedMemory(uint64_t  memory_id,
                           void*     mapped_memory,
                           size_t    mapped_offset,
                           size_t    mapped_range,
                           uintptr_t shadow_memory_handle,
                           bool      use_shadow_memory,
                           bool      use_write_watch);

    void RemoveTrackedMemory(uint64_t memory_id);

    void ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified);

    void ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified);

    bool HandleGuardPageViolation(void* address, bool is_write, bool clear_guard);

    size_t GetAlignedSize(size_t size) const;

    // The use_write_watch parameter is ignored on all platforms except Windows.
    void* AllocateMemory(size_t aligned_size, bool use_write_watch);

    void FreeMemory(void* pMemory, size_t aligned_size);

    uintptr_t AllocatePersistentShadowMemory(size_t size);

    void FreePersistentShadowMemory(uintptr_t shadow_memory_handle);

    const void* GetMappedMemory(uint64_t memory_id) const;

    void UffdBlockRtSignal();

    void UffdUnblockRtSignal();

  protected:
    PageGuardManager();

    PageGuardManager(bool                 enable_copy_on_map,
                     bool                 enable_separate_read,
                     bool                 expect_read_write_same_page,
                     bool                 unblock_SIGSEGV,
                     bool                 enable_signal_handler_watcher,
                     int                  signal_handler_watcher_max_restores,
                     MemoryProtectionMode protection_mode);

    ~PageGuardManager();

  private:
    struct MemoryInfo
    {
        MemoryInfo(void*       mm,
                   size_t      mr,
                   void*       sm,
                   size_t      sr,
                   void*       aa,
                   size_t      ao,
                   size_t      tp,
                   size_t      lss,
                   const void* sa,
                   const void* ea,
                   bool        ww,
                   bool        os) :
            status_tracker(tp),
            mapped_memory(mm), mapped_range(mr), shadow_memory(sm), shadow_range(sr), aligned_address(aa),
            aligned_offset(ao), total_pages(tp), last_segment_size(lss), start_address(sa), end_address(ea),
            use_write_watch(ww), is_modified(false), own_shadow_memory(os)
        {
#if defined(WIN32)
            if (shadow_memory == nullptr)
            {
                modified_addresses = std::make_unique<void*[]>(total_pages);
            }
#endif
        }

        PageStatusTracker status_tracker;

        void*  mapped_memory;  // Pointer to mapped memory to be tracked.
        size_t mapped_range;   // Size of the mapped memory range.
        void*  shadow_memory;  // Shadow memory for mapped memory types that cannot be tracked by guard pages.
        size_t shadow_range;   // Size of the shadow memory allocation, which is the mapped memory size adjusted to be a
                               // multiple of system page size.
        void* aligned_address; // Mapped memory pointer aligned to start of page when shadow memory is disabled, or
                               // shadow memory pointer when enabled.
        size_t      aligned_offset;    // Difference between #aligned_address and #mapped_memory.
        size_t      total_pages;       // Total number of pages contained by the mapped memory.
        size_t      last_segment_size; // Size of the last segment of the mapped memory, which may not be a full page.
        const void* start_address;     // Start address for the protected memory region.
        const void* end_address;       // Address immediately after the end of the protected memory region.
        bool        use_write_watch;
        bool        is_modified;
        bool        own_shadow_memory;

#if defined(WIN32)
        // Memory for retrieving modified pages with GetWriteWatch.
        std::unique_ptr<void*[]> modified_addresses;
#endif
    };

    struct ShadowMemoryInfo
    {
        ShadowMemoryInfo(void* sm, size_t ss, size_t tp, size_t lss) :
            memory(sm), size(ss), total_pages(tp), last_segment_size(lss), page_loaded(tp, false)
        {}

        void*             memory;            // Pointer to the shadow memory.
        size_t            size;              // Page-aligned size of the shadow memory.
        size_t            total_pages;       // Total number of pages in the shadow memory.
        size_t            last_segment_size; // Size of the last segment of the mapped memory.
        std::vector<bool> page_loaded;       // Tracks which pages have been loaded.
    };

    typedef std::unordered_map<uint64_t, MemoryInfo> MemoryInfoMap;

  private:
    size_t GetSystemPagePotShift() const;
    void   InitializeSystemExceptionContext();
    void   ReleaseTrackedMemory(const MemoryInfo* memory_info);

    void AddExceptionHandler();
    void RemoveExceptionHandler();
    void ClearExceptionHandler(void* exception_handler);

    size_t GetMemorySegmentSize(const MemoryInfo* memory_info, size_t page_index) const;
    void   MemoryCopy(void* destination, const void* source, size_t size);
    bool   FindMemory(void* address, MemoryInfo** watched_memory_info);
    bool   SetMemoryProtection(void* protect_address, size_t protect_size, uint32_t protect_mask);
    void   LoadActiveWriteStates(MemoryInfo* memory_info);
    void   ProcessEntry(uint64_t memory_id, MemoryInfo* memory_info, const ModifiedMemoryFunc& handle_modified);
    void   ProcessActiveRange(uint64_t                  memory_id,
                              MemoryInfo*               memory_info,
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
    static PageGuardManager* instance_;
    MemoryInfoMap            memory_info_;
    std::mutex               tracked_memory_lock_;
    std::mutex               signal_handler_lock_;
    void*                    exception_handler_;
    uint32_t                 exception_handler_count_;
    const size_t             system_page_size_;
    const size_t             system_page_pot_shift_;
    const bool               enable_copy_on_map_;
    const bool               enable_separate_read_;
    const bool               unblock_sigsegv_;
    bool                     enable_signal_handler_watcher_;
    int                      signal_handler_watcher_max_restores_;

    // Only applies to WIN32 builds and Linux/Android builds with PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION defined.
    const bool enable_read_write_same_page_;

#if !defined(WIN32)
    pthread_t       signal_handler_watcher_thread_;
    static uint32_t signal_handler_watcher_restores_;

    static void* SignalHandlerWatcher(void*);
    static bool  CheckSignalHandler();
    void         MarkAllTrackedMemoryAsDirty();
#endif

    MemoryProtectionMode protection_mode_;
    bool                 uffd_is_init_;

#if USERFAULTFD_SUPPORTED == 1
    int                          uffd_rt_signal_used_;
    sigset_t                     uffd_signal_set_;
    int                          uffd_fd_;
    pthread_t                    uffd_handler_thread_;
    static std::atomic<bool>     is_uffd_handler_thread_running_;
    static std::atomic<bool>     stop_uffd_handler_thread_;
    std::unique_ptr<uint8_t[]>   uffd_page_size_tmp_buff_;
    std::unordered_set<uint64_t> uffd_fault_causing_threads_;
    std::mutex                   thread_set_mutex_;
#endif

    bool     InitializeUserFaultFd();
    void     UffdTerminate();
    uint32_t UffdBlockFaultingThreads();
    void     UffdUnblockFaultingThreads(uint32_t n_threads_to_wait);
    bool     UffdRegisterMemory(const void* address, size_t length);
    void     UffdUnregisterMemory(const void* address, size_t length);
    bool     UffdResetRegion(void* guard_address, size_t guard_range);

#if USERFAULTFD_SUPPORTED == 1
    bool         UffdInit();
    bool         UffdSetSignalHandler();
    void         UffdRemoveSignalHandler();
    bool         UffdStartHandlerThread();
    bool         UffdHandleFault(MemoryInfo* memory_info, uint64_t address, uint64_t flags, bool wake_thread);
    bool         UffdWakeFaultingThread(uint64_t address);
    void         UffdSignalHandler(int sig);
    void*        UffdHandlerThread(void* args);
    static void* UffdHandlerThreadHelper(void* this_);
    static void  UffdStaticSignalHandler(int sig);
#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_PAGE_GUARD_MANAGER_H
