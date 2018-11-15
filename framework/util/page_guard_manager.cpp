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

#include "util/page_guard_manager.h"

#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(WIN32)
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static uint32_t kGuardReadWriteProtect = PAGE_READWRITE | PAGE_GUARD;
static uint32_t kGuardReadOnlyProtect  = PAGE_READONLY;
static uint32_t kGuardNoProtect        = PAGE_READWRITE;

static LONG WINAPI PageGuardExceptionHandler(PEXCEPTION_POINTERS exception_pointers)
{
    LONG result_code = EXCEPTION_CONTINUE_SEARCH;

    if ((exception_pointers != nullptr) && (exception_pointers->ExceptionRecord != nullptr))
    {
        PEXCEPTION_RECORD record  = exception_pointers->ExceptionRecord;
        PageGuardManager* manager = PageGuardManager::Get();
        if ((manager != nullptr) && (record->ExceptionInformation[1] != 0))
        {

            if (record->ExceptionCode == STATUS_GUARD_PAGE_VIOLATION)
            {
                // ExceptionInformation[0] indicates a read operation if 0 and write if 1.
                // ExceptionInformation[1] is the address of the inaccessible data.
                bool  is_write = (record->ExceptionInformation[0] == 0) ? false : true;
                void* address  = reinterpret_cast<void*>(record->ExceptionInformation[1]);
                if (manager->HandleGuardPageViolation(address, is_write, false))
                {
                    result_code = EXCEPTION_CONTINUE_EXECUTION;
                }
            }
#if !defined(PAGE_GUARD_ENABLE_WRITE_WATCH)
            else if (record->ExceptionCode == STATUS_ACCESS_VIOLATION)
            {
                // ExceptionInformation[0] indicates a read operation if 0 and write if 1.
                // ExceptionInformation[1] is the address of the inaccessible data.
                bool  is_write = (record->ExceptionInformation[0] == 0) ? false : true;
                void* address  = reinterpret_cast<void*>(record->ExceptionInformation[1]);
                if (manager->HandleGuardPageViolation(address, is_write, true))
                {
                    result_code = EXCEPTION_CONTINUE_EXECUTION;
                }
            }
#endif
        }
    }

    return result_code;
}
#else
#include <errno.h>
#include <signal.h>
#include <sys/mman.h>
#include <unistd.h>

static uint32_t kGuardReadWriteProtect = PROT_NONE;
static uint32_t kGuardReadOnlyProtect  = PROT_READ;
static uint32_t kGuardNoProtect        = PROT_READ | PROT_WRITE;

static struct sigaction s_old_sigaction;

static void PageGuardExceptionHandler(int id, siginfo_t* info, void*)
{
    PageGuardManager* manager = PageGuardManager::Get();
    if ((id == SIGSEGV) && (info->si_addr != nullptr) && (manager != nullptr))
    {
        bool is_write = true;
#if defined(PAGE_GUARD_ENABLE_X86_64_UCONTEXT)
#if defined(__x86_64__) || defined(__i386__)
        if (data != nullptr)
        {
            // This is a machine-specific method for detecting read vs. write access, and is not portable.
            // So far, it does appear to work with both 32-bit and 64-bit builds running on x86-64 Linux systems.
            ucontext_t* ucontext = reinterpret_cast<ucontext_t*>(data);
            is_write             = (ucontext->uc_mcontext.gregs[REG_ERR] & 0x2) ? true : false;
            printf("gregs = %" PRIx64 "\n", ucontext->uc_mcontext.gregs[REG_ERR]);
        }
#endif
#endif
        manager->HandleGuardPageViolation(info->si_addr, is_write, true);
    }
}
#endif

PageGuardManager* PageGuardManager::instance_ = nullptr;

PageGuardManager::PageGuardManager() :
    exception_handler_(nullptr), exception_handler_count_(0), system_page_size_(GetSystemPageSize()),
    enable_shadow_cached_memory_(kDefaultEnableShadowCachedMemory), enable_uncached_read_(kDefaultEnableUncachedRead),
    enable_copy_on_map_(kDefaultEnableCopyOnMap), enable_lazy_copy_(kDefaultEnableLazyCopy),
    enable_separate_read_tracking_(kDefaultEnableSeparateReadTracking),
    enable_read_write_same_page_(kDefaultEnableReadWriteSamePage)
{
}

PageGuardManager::PageGuardManager(bool enable_shadow_cached_memory,
                                   bool enable_uncached_read,
                                   bool enable_copy_on_map,
                                   bool enable_lazy_copy,
                                   bool enable_separate_read_tracking,
                                   bool expect_read_write_same_page) :
    exception_handler_(nullptr),
    exception_handler_count_(0), system_page_size_(GetSystemPageSize()),
    enable_shadow_cached_memory_(enable_shadow_cached_memory), enable_uncached_read_(enable_uncached_read),
    enable_copy_on_map_(enable_copy_on_map), enable_lazy_copy_(enable_lazy_copy),
    enable_separate_read_tracking_(enable_separate_read_tracking),
    enable_read_write_same_page_(expect_read_write_same_page)
{
}

PageGuardManager::~PageGuardManager()
{
    if (exception_handler_ != nullptr)
    {
        ClearExceptionHandler(exception_handler_);
    }

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        const auto& memory_info = entry->second;
        if (memory_info.shadow_memory)
        {
            FreeShadowMemory(memory_info.shadow_memory, memory_info.shadow_range);
        }
        else
        {
            // Disable page guard.
            size_t guard_range = memory_info.mapped_range + memory_info.aligned_offset;
            SetMemoryProtection(memory_info.aligned_address, guard_range, kGuardNoProtect);
        }
    }
}

void PageGuardManager::Create(bool enable_shadow_cached_memory,
                              bool enable_uncached_read,
                              bool enable_copy_on_map,
                              bool enable_lazy_copy,
                              bool enable_separate_read_tracking,
                              bool expect_read_write_same_page)
{
    if (instance_ == nullptr)
    {
        instance_ = new PageGuardManager(enable_shadow_cached_memory,
                                         enable_uncached_read,
                                         enable_copy_on_map,
                                         enable_lazy_copy,
                                         enable_separate_read_tracking,
                                         expect_read_write_same_page);
    }
    else
    {
        GFXRECON_LOG_WARNING("PageGuardManager creation was attempted more than once");
    }
}

void PageGuardManager::Destroy()
{
    if (instance_ != nullptr)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

size_t PageGuardManager::GetSystemPageSize() const
{
#if defined(WIN32)
    SYSTEM_INFO sSysInfo;
    GetSystemInfo(&sSysInfo);
    return sSysInfo.dwPageSize;
#else
    return getpagesize();
#endif
}

size_t PageGuardManager::GetAdjustedSize(size_t size) const
{
    size_t extra = size % system_page_size_;
    if (extra != 0)
    {
        // Adjust the size to be a multiple of the system page size.
        size = size - extra + system_page_size_;
    }

    return size;
}

void* PageGuardManager::AllocateShadowMemory(size_t size)
{
    assert(size > 0);

    void* memory = nullptr;

    if (size > 0)
    {
#if defined(WIN32)
        DWORD flags = MEM_RESERVE | MEM_COMMIT;
#if defined(PAGE_GUARD_ENABLE_WRITE_WATCH)
        flags |= MEM_WRITE_WATCH;
#endif
        memory = VirtualAlloc(nullptr, size, flags, PAGE_READWRITE);
#else
        memory = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
#endif
    }

    if (memory == nullptr)
    {
        GFXRECON_LOG_ERROR("PageGuardManager failed to allocate shadow memory with size = %" PRIuPTR, size);
    }

    return memory;
}

void PageGuardManager::FreeShadowMemory(void* memory, size_t size)
{
    assert(memory != nullptr);

    if (memory != nullptr)
    {
#if defined(WIN32)
        GFXRECON_UNREFERENCED_PARAMETER(size);
        VirtualFree(memory, 0, MEM_RELEASE);
#else
        munmap(memory, size);
#endif
    }
}

void PageGuardManager::AddExceptionHandler()
{
    if (exception_handler_ == nullptr)
    {
        assert(exception_handler_count_ == 0);

#if defined(WIN32)
        exception_handler_ = AddVectoredExceptionHandler(1, PageGuardExceptionHandler);
        if (exception_handler_ == nullptr)
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to register exception handler (GetLastError() returned %d)",
                               GetLastError());
        }
        else
        {
            exception_handler_count_ = 1;
        }
#else
        struct sigaction sa;
        sa.sa_flags = SA_SIGINFO;
        sigemptyset(&sa.sa_mask);
        sa.sa_sigaction = PageGuardExceptionHandler;
        if (sigaction(SIGSEGV, &sa, &s_old_sigaction) == -1)
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to register exception handler (errno = %d)", errno);
        }
        else
        {
            exception_handler_       = reinterpret_cast<void*>(PageGuardExceptionHandler);
            exception_handler_count_ = 1;
        }
#endif
    }
    else
    {
        ++exception_handler_count_;
    }
}

void PageGuardManager::RemoveExceptionHandler()
{
    if (exception_handler_ != nullptr)
    {
        assert(exception_handler_count_ > 0);

        --exception_handler_count_;

        if (exception_handler_count_ == 0)
        {
            ClearExceptionHandler(exception_handler_);
            exception_handler_ = nullptr;
        }
    }
}

void PageGuardManager::ClearExceptionHandler(void* exception_handler)
{
#if defined(WIN32)
    if (RemoveVectoredExceptionHandler(exception_handler) == 0)
    {
        GFXRECON_LOG_ERROR("PageGuardManager failed to remove exception handler (GetLastError() returned %d)",
                           GetLastError());
    }
#else
    struct sigaction current_sa;
    if (sigaction(SIGSEGV, &s_old_sigaction, &current_sa) == -1)
    {
        GFXRECON_LOG_ERROR("PageGuardManager failed to remove exception handler (errno= %d)", errno);
    }
#endif
}

size_t PageGuardManager::GetMemorySegmentSize(const MemoryInfo* memory_info, size_t page_index) const
{
    assert(memory_info != nullptr);
    assert(page_index < memory_info->total_pages);

    // If this is the last segment of the tracked memory, we want to know if it is a full page or a partial page.
    return ((page_index + 1) < memory_info->total_pages) ? system_page_size_ : memory_info->last_segment_size;
}

void PageGuardManager::MemoryCopy(void* destination, const void* source, size_t size)
{
    // TODO: parallel copy? (vktrace has options for this).
    util::platform::MemoryCopy(destination, size, source, size);
}

bool PageGuardManager::FindMemory(void* address, void** watched_memory, MemoryInfo** watched_memory_info)
{
    assert((address != nullptr) && (watched_memory != nullptr) && (watched_memory_info != nullptr));

    bool found = false;
    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        MemoryInfo* memory_info = &(entry->second);

        void* start = (memory_info->shadow_memory) ? memory_info->shadow_memory : memory_info->mapped_memory;
        void* end   = static_cast<uint8_t*>(start) + memory_info->mapped_range;

        if ((address >= start) && (address < end))
        {
            found                  = true;
            (*watched_memory)      = start;
            (*watched_memory_info) = memory_info;
            break;
        }
    }

    return found;
}

bool PageGuardManager::SetMemoryProtection(void* protect_address, size_t protect_size, uint32_t protect_mask)
{
    bool success = true;

#if defined(WIN32)
    DWORD old_setting = 0;
    if (VirtualProtect(protect_address, protect_size, protect_mask, &old_setting) == FALSE)
    {
        success = false;

        GFXRECON_LOG_ERROR(
            "PageGuardManager failed to enable page guard for memory region [start address = %p, size = %" PRIu64
            "] (VirtualProtect() produced error code %u)",
            protect_address,
            protect_size,
            GetLastError());
    }
#else
    if (mprotect(protect_address, protect_size, protect_mask) == -1)
    {
        success = false;

        GFXRECON_LOG_ERROR(
            "PageGuardManager failed to enable page guard for memory region [start address = %p, size = %" PRIu64
            "] (mprotect() produced error code %d)",
            protect_address,
            protect_size,
            errno);
    }
#endif

    return success;
}

void PageGuardManager::ProcessEntry(uint64_t memory_id, MemoryInfo* memory_info, ModifiedMemoryFunc handle_modified)
{
    assert(memory_info != nullptr);

    bool   active_range = false;
    size_t start_index  = 0;

    memory_info->is_modified = false;

    for (size_t i = 0; i < memory_info->total_pages; ++i)
    {
        // Concatenate dirty pages to handle as large a range as possible with a single modified memory handler
        // invokation.
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
            // If there was no write operation on the current page, check to see if there was a read operation.
            // If a read operation triggered the page guard handler, it needs to be reset.
            // Note that it is only possible to reach this state when enable_separate_read_tracking_ is true and
            // enable_read_write_same_page_ is false (eg. no writes are expected to be performed to pages that are
            // read).
            if (memory_info->status_tracker.IsActiveReadBlock(i))
            {

                void*  page_address = static_cast<uint8_t*>(memory_info->aligned_address) + (i * system_page_size_);
                size_t segment_size = GetMemorySegmentSize(memory_info, i);

                memory_info->status_tracker.SetActiveReadBlock(i, false);
                SetMemoryProtection(page_address, segment_size, kGuardReadWriteProtect);
            }

            // If the previous pages were modified by a write operation, process the modified range now.
            if (active_range)
            {
                active_range = false;

                ProcessActiveRange(memory_id, memory_info, start_index, i, handle_modified);
            }
        }
    }

    if (active_range)
    {
        ProcessActiveRange(memory_id, memory_info, start_index, memory_info->total_pages, handle_modified);
    }
}

void PageGuardManager::ProcessActiveRange(uint64_t           memory_id,
                                          MemoryInfo*        memory_info,
                                          size_t             start_index,
                                          size_t             end_index,
                                          ModifiedMemoryFunc handle_modified)
{
    assert(memory_info != nullptr);
    assert(end_index > start_index);

    size_t page_count    = end_index - start_index;
    size_t page_offset   = start_index * system_page_size_;
    size_t page_range    = page_count * system_page_size_;
    void*  start_address = static_cast<uint8_t*>(memory_info->aligned_address) + page_offset;

    if (end_index == memory_info->total_pages)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= system_page_size_ - memory_info->last_segment_size;
    }

#if defined(WIN32) && defined(PAGE_GUARD_ENABLE_WRITE_WATCH)
    // Page guard was disabled when these pages were accessed.  We can't enable it now without
    // triggering an exception for the read operation we are about to perform, so we enable a write
    // watch on these pages to determine if they were modified by another thread between the point where
    // we copy the modified pages and re-enable the page guard.
    if (ResetWriteWatch(start_address, page_range) != 0)
    {
        GFXRECON_LOG_ERROR(
            "PageGuardManager failed to reset write watch for memory region [start address = %p, size = %" PRIu64
            "] (ResetWriteWatch() produced error code %u)",
            start_address,
            page_range,
            GetLastError());
    }
#else
    // Page guard was disabled when these pages were accessed.  We enable it now for write, to
    // trap any writes made to the memory while we are performing the copy from shadow memory
    // to mapped memory.
    SetMemoryProtection(start_address, page_range, kGuardReadOnlyProtect);
#endif

    // Source address, offset, and range values to be provided to the callback.
    // For shadow memory, they are the shadow memory pointer with the actual page offset and page range.
    // For non-shadow memory, the page offset and range need to be adjusted when the source address is not aligned to
    // the start of a page.
    void*  source_address = nullptr;
    size_t source_offset  = page_offset;
    size_t source_range   = page_range;

    if (memory_info->shadow_memory != nullptr)
    {
        // Copy from shadow memory to the original mapped memory
        void* destination_address = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
        MemoryCopy(destination_address, start_address, page_range);

        source_address = static_cast<uint8_t*>(memory_info->shadow_memory);
    }
    else
    {
        source_address = static_cast<uint8_t*>(memory_info->mapped_memory);

        if (start_index == 0)
        {
            // If the watch pointer was aligned to the start of a page, the alignment offset needs to be
            // deducted from the page size.
            source_range -= memory_info->aligned_offset;
        }
        else
        {
            // If the watch pointer was aligned to the start of a page, the alignment offset needs to be
            // deducted from the start offset.
            source_offset -= memory_info->aligned_offset;
        }
    }

    handle_modified(memory_id, source_address, source_offset, source_range);

    // Reset page guard.
    SetMemoryProtection(start_address, page_range, kGuardReadWriteProtect);

#if defined(WIN32) && defined(PAGE_GUARD_ENABLE_WRITE_WATCH)
    // Check for writes that occured during copy and update the write tracking state.
    for (size_t i = start_index; i < end_index; ++i)
    {
        void*  page_address = static_cast<uint8_t*>(memory_info->aligned_address) + (i * system_page_size_);
        size_t segment_size = GetMemorySegmentSize(memory_info, i);

        void*     addresses     = nullptr;
        ULONG_PTR address_count = 1;
        ULONG     granularity   = 0;

        if (GetWriteWatch(0, page_address, segment_size, &addresses, &address_count, &granularity) == 0)
        {
            if (address_count == 1)
            {
                memory_info->status_tracker.SetActiveWriteBlock(i, true);
                SetMemoryProtection(page_address, segment_size, kGuardNoProtect);
                memory_info->is_modified = true;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to retrieve write watch count for page %p"
                               " (GetWriteWatch() produced error code %u)",
                               page_address,
                               GetLastError());
        }
    }
#endif
}

void* PageGuardManager::AddMemory(uint64_t memory_id, void* mapped_memory, size_t size, bool is_cached, bool shadow)
{
    bool success = true;

    void*  aligned_address   = nullptr;
    void*  shadow_memory     = nullptr;
    size_t shadow_size       = 0;
    size_t aligned_offset    = 0;
    size_t guard_range       = size;
    size_t total_pages       = size / system_page_size_;
    size_t last_segment_size = size % system_page_size_;

    if (last_segment_size != 0)
    {
        ++total_pages;
    }
    else
    {
        last_segment_size = system_page_size_;
    }

    if (shadow)
    {
        shadow_size   = GetAdjustedSize(size);
        shadow_memory = AllocateShadowMemory(shadow_size);

        if (shadow_memory != nullptr)
        {
            if (enable_copy_on_map_ && !enable_lazy_copy_)
            {
                MemoryCopy(shadow_memory, mapped_memory, size);
            }

            aligned_address = shadow_memory;
        }
        else
        {
            success = false;
        }
    }
    else
    {
        // Align the mapped memory pointer to the start of its page.
        aligned_offset  = GetOffsetFromPageStart(mapped_memory);
        aligned_address = AlignToPageStart(mapped_memory);
        guard_range += aligned_offset;
    }

    if (success)
    {
        std::lock_guard<std::mutex> lock(tracked_memory_lock_);

        AddExceptionHandler();

        // Enable page guard for read and write operations.
        if (SetMemoryProtection(aligned_address, guard_range, kGuardReadWriteProtect))
        {
            assert(memory_info_.find(memory_id) == memory_info_.end());

            auto entry = memory_info_.emplace(std::piecewise_construct,
                                              std::forward_as_tuple(memory_id),
                                              std::forward_as_tuple(mapped_memory,
                                                                    size,
                                                                    shadow_memory,
                                                                    shadow_size,
                                                                    aligned_address,
                                                                    aligned_offset,
                                                                    total_pages,
                                                                    last_segment_size,
                                                                    is_cached));

            if (!entry.second)
            {
                success = false;
            }
        }
    }

    if (!success)
    {
        if (shadow_memory)
        {
            FreeShadowMemory(shadow_memory, shadow_size);
            shadow_memory = nullptr;
        }
        else
        {
            SetMemoryProtection(aligned_address, guard_range, kGuardNoProtect);
        }
    }

    return (shadow_memory != nullptr) ? shadow_memory : mapped_memory;
}

void PageGuardManager::RemoveMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    RemoveExceptionHandler();

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        bool              success     = true;
        const MemoryInfo& memory_info = entry->second;

        if (memory_info.shadow_memory)
        {
            FreeShadowMemory(memory_info.shadow_memory, memory_info.shadow_range);
        }
        else
        {
            // Disable page guard.
            size_t guard_range = memory_info.mapped_range + memory_info.aligned_offset;
            SetMemoryProtection(memory_info.aligned_address, guard_range, kGuardNoProtect);
        }

        memory_info_.erase(entry);
    }
}

bool PageGuardManager::ProcessMemoryEntry(uint64_t memory_id, ModifiedMemoryFunc handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    bool found = false;
    auto entry = memory_info_.find(memory_id);

    if ((entry != memory_info_.end()) && (entry->second.is_modified))
    {
        found = true;
        ProcessEntry(entry->first, &entry->second, handle_modified);
    }

    return found;
}

void PageGuardManager::ProcessMemoryEntries(ModifiedMemoryFunc handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        if (entry->second.is_modified)
        {
            ProcessEntry(entry->first, &entry->second, handle_modified);
        }
    }
}

bool PageGuardManager::HandleGuardPageViolation(void* address, bool is_write, bool clear_guard)
{
    void*       start_address = nullptr;
    MemoryInfo* memory_info   = nullptr;

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    bool found = FindMemory(address, &start_address, &memory_info);
    if (found)
    {
        assert((start_address != nullptr) && (memory_info != nullptr) && (memory_info->aligned_address != nullptr));
        assert(reinterpret_cast<uintptr_t>(address) >= reinterpret_cast<uintptr_t>(memory_info->aligned_address));

        memory_info->is_modified = true;

        // Get the offset from the start of the first protected memory page to the current address.
        size_t start_offset = static_cast<uint8_t*>(address) - static_cast<uint8_t*>(memory_info->aligned_address);

        size_t page_index   = start_offset / system_page_size_;
        size_t page_offset  = GetOffsetFromPageStart(address);
        void*  page_address = AlignToPageStart(address);

#if !defined(WIN32) || !defined(PAGE_GUARD_ENABLE_WRITE_WATCH)
        // Remove protection from page before accessing memory.  Not necessary for Windows, which does this
        // automatically.
        if (clear_guard)
        {
            SetMemoryProtection(page_address, GetMemorySegmentSize(memory_info, page_index), kGuardNoProtect);
        }
#endif

        // For POSIX systems, excluding Linux when compiled with PAGE_GUARD_ENABLE_X86_64_UCONTEXT, is_write is always
        // true because we are not notified if the exception was raised by a read or write operation.
        if (is_write || !enable_separate_read_tracking_)
        {
            // When shadow memory is used, the content of the mapped memory needs to be copied to the shadow memory if
            // the application is expected to read from that memory or if the applicationis mapping and unmapping memory
            // to perform small, incremental updates.  As an optimization, the copy can be performed for individual page
            // blocks at first access instead of being performed for the entire memory range at shadow memory
            // allocation.  Multiple factors can affect the need to perform the copy:
            //   If there is no shadow memory, the copy is unnecessary.
            //   If the optimization is not enabled, the copy is unnecessary.
            //   If the optimization is not enabled, but we expect the memory to be read from, the copy is necessary.
            //   If the optimization is enabled, but this is not the first access to the block since it was mapped, the
            //   copy is unnecessary.
            if ((memory_info->shadow_memory != nullptr) &&
                (memory_info->is_cached || enable_uncached_read_ ||
                 (enable_copy_on_map_ && enable_lazy_copy_ && !memory_info->status_tracker.IsBlockLoaded(page_index))))
            {
                // Advance the mapped memory pointer by the offset from the start of the shadow memory to the start of
                // the modified page.
                size_t modified_page_start = start_offset - page_offset;
                assert(modified_page_start == (page_index * system_page_size_));
                void* source_address = static_cast<uint8_t*>(memory_info->mapped_memory) + modified_page_start;

                MemoryCopy(page_address, source_address, GetMemorySegmentSize(memory_info, page_index));
                memory_info->status_tracker.SetBlockLoaded(page_index, true);
            }

            memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
        }
        else
        {
            if (memory_info->shadow_memory != nullptr)
            {
                // This is a read from shadow memory with separate read tracking enabled.
                if (enable_copy_on_map_ && enable_lazy_copy_)
                {
                    // Mark the page as loaded for lazy copy on map.
                    memory_info->status_tracker.SetBlockLoaded(page_index, true);
                }

                // Advance the mapped memory pointer by the offset from the start of the shadow memory to the start of
                // the modified page.
                size_t modified_page_start = start_offset - page_offset;
                assert(modified_page_start == (page_index * system_page_size_));
                void* source_address = reinterpret_cast<uint8_t*>(memory_info->mapped_memory) + modified_page_start;
                MemoryCopy(page_address, source_address, GetMemorySegmentSize(memory_info, page_index));
            }

            memory_info->status_tracker.SetActiveReadBlock(page_index, true);

            if (enable_read_write_same_page_)
            {
                // The page guard has been removed from this page.  If we expect reads and writes to the page,
                // it needs to be marked for active write.
                memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
            }
        }
    }

    return found;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
