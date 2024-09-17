/*
** Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2015-2023 Valve Corporation
** Copyright (c) 2015-2023 LunarG, Inc.
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

#include "util/page_guard_manager.h"

#include "util/logging.h"
#include "util/page_status_tracker.h"
#include "util/platform.h"

#include <cassert>
#include <csetjmp>
#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(WIN32)
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

const uint32_t kGuardReadWriteProtect = PAGE_READWRITE | PAGE_GUARD;
const uint32_t kGuardReadOnlyProtect  = PAGE_READONLY;
const uint32_t kGuardNoProtect        = PAGE_READWRITE;

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
                void* address  = reinterpret_cast<void*>(record->ExceptionInformation[1]);
                bool  is_write = true;

                if (manager->UseSeparateRead() && (record->ExceptionInformation[0] == 0))
                {
                    is_write = false;
                }

                // The PAGE_GUARD settings was automatically removed when the exception was raised, and does not need to
                // be removed by the handler.
                if (manager->HandleGuardPageViolation(address, is_write, false))
                {
                    result_code = EXCEPTION_CONTINUE_EXECUTION;
                }
            }
            else if (record->ExceptionCode == STATUS_ACCESS_VIOLATION)
            {
                // ExceptionInformation[0] indicates a read operation if 0 and write if 1.
                // ExceptionInformation[1] is the address of the inaccessible data.
                void* address  = reinterpret_cast<void*>(record->ExceptionInformation[1]);
                bool  is_write = true;

                if (manager->UseSeparateRead() && (record->ExceptionInformation[0] == 0))
                {
                    is_write = false;
                }

                // The read-only memory protection was not automatically removed when the exception was raised, and must
                // be removed by the handler.
                if (manager->HandleGuardPageViolation(address, is_write, true))
                {
                    result_code = EXCEPTION_CONTINUE_EXECUTION;
                }
            }
        }
    }

    return result_code;
}
#else
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#ifdef __APPLE__
static constexpr uint32_t MEMPROT_SIGNAL = SIGBUS;
#else
static constexpr uint32_t MEMPROT_SIGNAL = SIGSEGV;
#endif

const uint32_t kGuardReadWriteProtect = PROT_NONE;
const uint32_t kGuardReadOnlyProtect  = PROT_READ;
const uint32_t kGuardNoProtect        = PROT_READ | PROT_WRITE;

static struct sigaction s_old_sigaction = {};
static stack_t          s_old_stack     = {};

static uint8_t* s_alt_stack      = nullptr;
static size_t   s_alt_stack_size = 0;

static bool TryHandlePageGuardException(int id, siginfo_t* info, void* data)
{
    bool              handled = false;
    PageGuardManager* manager = PageGuardManager::Get();
    if ((id == MEMPROT_SIGNAL) && (info->si_addr != nullptr) && (manager != nullptr))
    {
        bool is_write = true;
#if defined(PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION)
        if (manager->UseSeparateRead() && (data != nullptr))
        {
            // This is a machine-specific method for detecting read vs. write access, and is not portable.
            auto ucontext = reinterpret_cast<const ucontext_t*>(data);
#if (defined(__x86_64__) || defined(__i386__))
#ifdef __APPLE__
            if ((ucontext->uc_mcontext->__es.__err & 0x2) == 0)
#else
            if ((ucontext->uc_mcontext.gregs[REG_ERR] & 0x2) == 0)
#endif
            {
                is_write = false;
            }
#elif defined(__arm__)
            // Check WnR bit of the ESR register, which indicates write when 1 and read when 0.
            static const unsigned long kEsrWnRBit = 1ul << 11;
            if ((ucontext->uc_mcontext.error_code & kEsrWnRBit) == 0)
            {
                is_write = false;
            }
#elif defined(__aarch64__)
            // Check WnR bit of the ESR_EL1 register, which indicates write when 1 and read when 0.
            static const uint32_t kEsrElxWnRBit = 1u << 6;
#ifdef __APPLE__
            if ((ucontext->uc_mcontext->__es.__esr & kEsrElxWnRBit) == 0)
            {
                is_write = false;
            }
#else
            const uint8_t* reserved = ucontext->uc_mcontext.__reserved;
            auto           ctx      = reinterpret_cast<const _aarch64_ctx*>(reserved);

            while (ctx->magic != 0)
            {
                if (ctx->magic == ESR_MAGIC)
                {
                    auto esr_ctx = reinterpret_cast<const esr_context*>(ctx);
                    if ((esr_ctx->esr & kEsrElxWnRBit) == 0)
                    {
                        is_write = false;
                    }
                    break;
                }
                else
                {
                    reserved += ctx->size;
                    ctx = reinterpret_cast<const _aarch64_ctx*>(reserved);
                }
            }
#endif
#endif
        }
#endif
        handled = manager->HandleGuardPageViolation(info->si_addr, is_write, true);
    }
    return handled;
}

static void PageGuardExceptionHandler(int id, siginfo_t* info, void* data)
{
    if (!TryHandlePageGuardException(id, info, data))
    {
        // This was not a SIGSEGV signal for an address that was protected with mprotect().
        // Raise the original signal handler for this case.
        if (((s_old_sigaction.sa_flags & SA_SIGINFO) == SA_SIGINFO) && (s_old_sigaction.sa_sigaction != nullptr))
        {
            s_old_sigaction.sa_sigaction(id, info, data);
        }
        else if (((s_old_sigaction.sa_flags & SA_SIGINFO) != SA_SIGINFO) && (s_old_sigaction.sa_handler != nullptr))
        {
            s_old_sigaction.sa_handler(id);
        }
        else
        {
            abort();
        }
    }
}
#endif

PageGuardManager* PageGuardManager::instance_ = nullptr;

void PageGuardManager::InitializeSystemExceptionContext(void)
{
#if defined(__linux__)
    if (s_alt_stack == nullptr)
    {
        s_alt_stack_size = SIGSTKSZ;
        s_alt_stack      = new uint8_t[s_alt_stack_size];
    }
#endif
#if defined(__ANDROID__)
    AddSpecialSignalHandlerFn =
        reinterpret_cast<PFN_AddSpecialSignalHandlerFn>(dlsym(RTLD_DEFAULT, "AddSpecialSignalHandlerFn"));
    RemoveSpecialSignalHandlerFn =
        reinterpret_cast<PFN_RemoveSpecialSignalHandlerFn>(dlsym(RTLD_DEFAULT, "RemoveSpecialSignalHandlerFn"));
    if (!AddSpecialSignalHandlerFn || !RemoveSpecialSignalHandlerFn)
    {
        AddSpecialSignalHandlerFn    = nullptr;
        RemoveSpecialSignalHandlerFn = nullptr;
        GFXRECON_LOG_WARNING("PageGuardManager could not find libsigchain symbols. Falling back to sigaction.")
    }
#endif
}

PageGuardManager::PageGuardManager() :
    PageGuardManager(kDefaultEnableCopyOnMap,
                     kDefaultEnableSeparateRead,
                     kDefaultUnblockSIGSEGV,
                     kDefaultEnableSignalHandlerWatcher,
                     kDefaultSignalHandlerWatcherMaxRestores,
                     kDefaultEnableReadWriteSamePage,
                     kDefaultMemoryProtMode)
{}

PageGuardManager::PageGuardManager(bool                 enable_copy_on_map,
                                   bool                 enable_separate_read,
                                   bool                 expect_read_write_same_page,
                                   bool                 unblock_SIGSEGV,
                                   bool                 enable_signal_handler_watcher,
                                   int                  signal_handler_watcher_max_restores,
                                   MemoryProtectionMode protection_mode) :
    exception_handler_(nullptr),
    exception_handler_count_(0), system_page_size_(util::platform::GetSystemPageSize()),
    system_page_pot_shift_(GetSystemPagePotShift()), enable_copy_on_map_(enable_copy_on_map),
    enable_separate_read_(enable_separate_read), unblock_sigsegv_(unblock_SIGSEGV),
    enable_signal_handler_watcher_(enable_signal_handler_watcher),
    signal_handler_watcher_max_restores_(signal_handler_watcher_max_restores),
    enable_read_write_same_page_(expect_read_write_same_page), protection_mode_(protection_mode), uffd_is_init_(false)
{
    if (kUserFaultFdMode == protection_mode_ && !USERFAULTFD_SUPPORTED)
    {
        GFXRECON_LOG_WARNING("Kernel does not support all features for userfaultfd memory tracking mode. Falling back "
                             "to mprotect mode.");

        protection_mode_ = kMProtectMode;
    }

    if (kMProtectMode == protection_mode_)
    {
        InitializeSystemExceptionContext();
    }
    else
    {
        if (!InitializeUserFaultFd())
        {
            GFXRECON_LOG_ERROR("Userfaultfd initialization failed. Falling back to mprotect memory tracking mode.");

            protection_mode_ = kMProtectMode;
            InitializeSystemExceptionContext();
        }
    }
}

PageGuardManager::~PageGuardManager()
{
    if (kMProtectMode == protection_mode_)
    {
        if (exception_handler_ != nullptr)
        {
            ClearExceptionHandler(exception_handler_);
        }
    }
    else
    {
        UffdTerminate();
    }
}

#if !defined(WIN32)
uint32_t PageGuardManager::signal_handler_watcher_restores_ = 0;

void PageGuardManager::MarkAllTrackedMemoryAsDirty()
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto& entry : memory_info_)
    {
        auto memory_info = &entry.second;

        memory_info->is_modified = true;
        memory_info->status_tracker.SetAllBlocksActiveWrite();
        SetMemoryProtection(memory_info->shadow_memory, memory_info->shadow_range, kGuardNoProtect);
    }
}

bool PageGuardManager::CheckSignalHandler()
{
    assert(instance_);

    instance_->signal_handler_lock_.lock();

    if (instance_->exception_handler_)
    {
        assert(instance_->exception_handler_count_);

        struct sigaction current_handler;
        int              result = sigaction(MEMPROT_SIGNAL, nullptr, &current_handler);

        if (result != -1)
        {
            if (current_handler.sa_sigaction != PageGuardExceptionHandler)
            {
                GFXRECON_LOG_WARNING("PageGuardManager: Signal handler has been removed. Re-installing.")

                instance_->exception_handler_       = nullptr;
                instance_->exception_handler_count_ = 0;
                instance_->signal_handler_lock_.unlock();

                instance_->AddExceptionHandler();

                // Potentially we lost information. Assume everything is dirty
                instance_->MarkAllTrackedMemoryAsDirty();

                return true;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("sigaction failed (%s)", strerror(errno));
        }
    }

    instance_->signal_handler_lock_.unlock();

    return false;
}

void* PageGuardManager::SignalHandlerWatcher(void* args)
{
    while (instance_->enable_signal_handler_watcher_ &&
#if defined(__ANDROID__)
           !instance_->libsigchain_active_ &&
#endif
           (instance_->signal_handler_watcher_max_restores_ < 0 ||
            signal_handler_watcher_restores_ < static_cast<uint32_t>(instance_->signal_handler_watcher_max_restores_)))
    {
        if (CheckSignalHandler())
        {
            ++signal_handler_watcher_restores_;
        }
    }

    return NULL;
}
#endif // !defined(WIN32)

void PageGuardManager::Create(bool                 enable_copy_on_map,
                              bool                 enable_separate_read,
                              bool                 expect_read_write_same_page,
                              bool                 unblock_SIGSEGV,
                              bool                 enable_signal_handler_watcher,
                              int                  signal_handler_watcher_max_restores,
                              MemoryProtectionMode protection_mode)
{
    if (instance_ == nullptr)
    {
        instance_ = new PageGuardManager(enable_copy_on_map,
                                         enable_separate_read,
                                         expect_read_write_same_page,
                                         unblock_SIGSEGV,
                                         enable_signal_handler_watcher,
                                         signal_handler_watcher_max_restores,
                                         protection_mode);

#if !defined(WIN32)
        if (enable_signal_handler_watcher &&
            (signal_handler_watcher_max_restores < 0 ||
             signal_handler_watcher_restores_ < static_cast<uint32_t>(signal_handler_watcher_max_restores)))
        {
            int ret =
                pthread_create(&instance_->signal_handler_watcher_thread_, nullptr, SignalHandlerWatcher, nullptr);
            if (ret)
            {
                GFXRECON_LOG_ERROR("Page guard manager failed spawning thread (%s)", strerror(ret));
            }
        }
#endif
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
#if !defined(WIN32)
        if (instance_->enable_signal_handler_watcher_)
        {
            instance_->enable_signal_handler_watcher_ = false;

            int ret = pthread_join(instance_->signal_handler_watcher_thread_, nullptr);
            if (ret)
            {
                GFXRECON_LOG_ERROR("Page guard signal watcher thread failed terminating (%s)", strerror(ret));
            }
        }
#endif
        delete instance_;
        instance_ = nullptr;
    }
}

size_t PageGuardManager::GetSystemPagePotShift() const
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

size_t PageGuardManager::GetAlignedSize(size_t size) const
{
    return util::platform::GetAlignedSize(size, system_page_size_);
}

void* PageGuardManager::AllocateMemory(size_t aligned_size, bool use_write_watch)
{
    assert(aligned_size > 0);

    if (aligned_size > 0)
    {
#ifndef WIN32
        if (use_write_watch)
        {
            GFXRECON_LOG_ERROR("PageGuardManager::AllocateMemory() ignored use_write_watch=true due to lack of support "
                               "from the current platform.");
        }
#endif
        void* memory = util::platform::AllocateRawMemory(aligned_size, use_write_watch);

        if (memory == nullptr)
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to allocate memory with size = %" PRIuPTR
                               " with error code: %u",
                               aligned_size,
                               util::platform::GetSystemLastErrorCode());
        }

        return memory;
    }
    else
    {
        GFXRECON_LOG_ERROR("PageGuardManager::AllocateMemory(): aligned_size must be greater than 0.");

        return nullptr;
    }
}

void PageGuardManager::FreeMemory(void* memory, size_t aligned_size)
{
    assert(memory != nullptr);

    util::platform::FreeRawMemory(memory, aligned_size);
}

void PageGuardManager::AddExceptionHandler()
{
    if (enable_signal_handler_watcher_)
        signal_handler_lock_.lock();

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
#if defined(__ANDROID__)
        if (!libsigchain_active_ && AddSpecialSignalHandlerFn)
        {
            static std::jmp_buf abort_env;

            struct sigaction orig_abort_sa = {};

            struct sigaction abort_sa = {};
            abort_sa.sa_flags         = SA_SIGINFO;
            sigemptyset(&abort_sa.sa_mask);
            abort_sa.sa_sigaction = [](int id, siginfo_t* info, void* data) { std::longjmp(abort_env, 0); };

            // Install temporary handler for SIGABRT to catch failure in AddSpecialSignalHandlerFn
            sigaction(SIGABRT, &abort_sa, &orig_abort_sa);
            if (setjmp(abort_env) == 0)
            {
                // Install special signal handler with libsigchain
                SigchainAction sc = {};
                sc.sc_sigaction   = TryHandlePageGuardException;
                sigemptyset(&sc.sc_mask);
                AddSpecialSignalHandlerFn(MEMPROT_SIGNAL, &sc);

                // If we got this far then it was successful
                libsigchain_active_      = true;
                exception_handler_       = reinterpret_cast<void*>(TryHandlePageGuardException);
                exception_handler_count_ = 1;
            }
            else
            {
                GFXRECON_LOG_WARNING(
                    "PageGuardManager libsigchain AddSpecialSignalHandlerFn failed, falling back to sigaction");
            }

            // Restore original SIGABRT handler
            sigaction(SIGABRT, &orig_abort_sa, nullptr);
        }
        if (!libsigchain_active_)
#endif
        {
            // Retrieve the current SIGSEGV handler info before replacing the current signal handler to determine if our
            // replacement signal handler should use an alternate signal stack.
            int result = sigaction(MEMPROT_SIGNAL, nullptr, &s_old_sigaction);

            if (result != -1)
            {
                struct sigaction sa = {};

                sa.sa_flags = SA_SIGINFO;
                sigemptyset(&sa.sa_mask);
                sa.sa_sigaction = PageGuardExceptionHandler;

                if ((s_old_sigaction.sa_flags & SA_ONSTACK) == SA_ONSTACK)
                {
                    // Replace the current alternate signal stack with one that is guaranteed to be valid for the page
                    // guard signal handler.
                    stack_t new_stack;
                    new_stack.ss_sp    = s_alt_stack;
                    new_stack.ss_flags = 0;
                    new_stack.ss_size  = s_alt_stack_size;

                    sigaltstack(&new_stack, &s_old_stack);

                    sa.sa_flags |= SA_ONSTACK;
                }

                result = sigaction(MEMPROT_SIGNAL, &sa, nullptr);
            }

            if (result != -1)
            {
                exception_handler_       = reinterpret_cast<void*>(PageGuardExceptionHandler);
                exception_handler_count_ = 1;
            }
            else
            {
                GFXRECON_LOG_ERROR("PageGuardManager failed to register exception handler (errno = %d)", errno);
            }
        }
#endif
    }
    else
    {
        ++exception_handler_count_;
    }

    if (enable_signal_handler_watcher_)
        signal_handler_lock_.unlock();
}

void PageGuardManager::RemoveExceptionHandler()
{
    if (enable_signal_handler_watcher_)
        signal_handler_lock_.lock();

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

    if (enable_signal_handler_watcher_)
        signal_handler_lock_.unlock();
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
#if defined(__ANDROID__)
    if (libsigchain_active_)
    {
        RemoveSpecialSignalHandlerFn(MEMPROT_SIGNAL,
                                     reinterpret_cast<decltype(SigchainAction::sc_sigaction)>(exception_handler));
        libsigchain_active_ = false;
    }
    else
#endif
    {
        if ((s_old_sigaction.sa_flags & SA_ONSTACK) == SA_ONSTACK)
        {
            // Restore the alternate signal stack.
            sigaltstack(&s_old_stack, nullptr);
        }

        // Restore the old signal handler.
        if (sigaction(MEMPROT_SIGNAL, &s_old_sigaction, nullptr) == -1)
        {
            GFXRECON_LOG_ERROR("PageGuardManager failed to remove exception handler (errno= %d)", errno);
        }
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
    util::platform::MemoryCopy(destination, size, source, size);
}

bool PageGuardManager::FindMemory(void* address, MemoryInfo** watched_memory_info)
{
    assert((address != nullptr) && (watched_memory_info != nullptr));

    bool found = false;
    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        MemoryInfo* memory_info = &(entry->second);

        if ((address >= memory_info->start_address) && (address < memory_info->end_address))
        {
            found                  = true;
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
            "PageGuardManager failed to enable page guard for memory region [start address = %p, size = %" PRIuPTR
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
            "PageGuardManager failed to enable page guard for memory region [start address = %p, size = %" PRIuPTR
            "] (mprotect() produced error code %d)",
            protect_address,
            protect_size,
            errno);
    }

    if (protect_mask ^ kGuardNoProtect)
    {
        sigset_t x;
        sigemptyset(&x);
        sigprocmask(SIG_SETMASK, nullptr, &x);

        // Check if SIGSEGV is blocked
        int ret = sigismember(&x, MEMPROT_SIGNAL);
        if (ret == 1)
        {
            if (!unblock_sigsegv_)
            {
                GFXRECON_LOG_WARNING("SIGSEGV is blocked while page_guard mechanism expects the signal to be handled. "
                                     "Things might fail and/or crash with segmentation fault. To force-enable SIGSEGV "
                                     "try setting GFXRECON_PAGE_GUARD_UNBLOCK_SIGSEGV environment variable to 1.\n");
            }
            else
            {
                // Unblock SIGSEGV
                sigemptyset(&x);
                sigaddset(&x, MEMPROT_SIGNAL);
                if (sigprocmask(SIG_UNBLOCK, &x, nullptr))
                {
                    GFXRECON_LOG_ERROR("sigprocmask failed to unblock SIGSEGV on thread %lld (errno: %d)",
                                       platform::GetCurrentThreadId(),
                                       errno);
                }
            }
        }
        else if (ret == -1)
        {
            GFXRECON_LOG_ERROR("sigismember() failed (errno: %d)\n", errno);
        }
    }
#endif
    return success;
}

void PageGuardManager::LoadActiveWriteStates(MemoryInfo* memory_info)
{
    assert((memory_info != nullptr) && (memory_info->shadow_memory == nullptr));

#if defined(WIN32)
    auto      modified_addresses = memory_info->modified_addresses.get();
    ULONG_PTR modified_count     = memory_info->total_pages;
    DWORD     granularity        = 0;

    if (GetWriteWatch(WRITE_WATCH_FLAG_RESET,
                      memory_info->aligned_address,
                      memory_info->mapped_range + memory_info->aligned_offset,
                      modified_addresses,
                      &modified_count,
                      &granularity) == 0)
    {
        if (modified_count > 0)
        {
            memory_info->is_modified = true;

            for (ULONG_PTR i = 0; i < modified_count; ++i)
            {
                // Get offset from the page-aligned start address of the mapped memory to the address of the modified
                // page.
                size_t start_offset =
                    static_cast<uint8_t*>(modified_addresses[i]) - static_cast<uint8_t*>(memory_info->aligned_address);
                size_t page_index = start_offset >> system_page_pot_shift_;

                memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("PageGuardManager failed to retrieve write-modified pages for memory region [start address "
                           "= %p, size = %" PRIuPTR "] (GetWriteWatch() produced error code %u)",
                           memory_info->mapped_memory,
                           memory_info->mapped_range,
                           GetLastError());
    }
#endif
}

void PageGuardManager::ProcessEntry(uint64_t                  memory_id,
                                    MemoryInfo*               memory_info,
                                    const ModifiedMemoryFunc& handle_modified)
{
    assert(memory_info != nullptr);
    assert(memory_info->is_modified);

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
            // If there was no write operation on the current page, check to see if there was a read operation.
            // If a read operation triggered the page guard handler, it needs to be reset.
            // Note that it is only possible to reach this state when enable_shadow_memory_ is true and
            // enable_read_write_same_page_ is false.
            if (memory_info->status_tracker.IsActiveReadBlock(i))
            {
                memory_info->status_tracker.SetActiveReadBlock(i, false);

                if (protection_mode_ == kMProtectMode)
                {
                    assert(memory_info->shadow_memory != nullptr);

                    void* page_address =
                        static_cast<uint8_t*>(memory_info->aligned_address) + (i << system_page_pot_shift_);
                    size_t segment_size = GetMemorySegmentSize(memory_info, i);

                    SetMemoryProtection(page_address, segment_size, kGuardReadWriteProtect);
                }
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

void PageGuardManager::ProcessActiveRange(uint64_t                  memory_id,
                                          MemoryInfo*               memory_info,
                                          size_t                    start_index,
                                          size_t                    end_index,
                                          const ModifiedMemoryFunc& handle_modified)
{
    assert((memory_info != nullptr) && (memory_info->aligned_address != nullptr));
    assert(end_index > start_index);

    size_t page_count  = end_index - start_index;
    size_t page_offset = start_index << system_page_pot_shift_;
    size_t page_range  = page_count << system_page_pot_shift_;

    if (end_index == memory_info->total_pages)
    {
        // Adjust range for memory ranges that end with a partial page.
        page_range -= system_page_size_ - memory_info->last_segment_size;
    }

    if (memory_info->shadow_memory != nullptr)
    {
        void*  guard_address = static_cast<uint8_t*>(memory_info->aligned_address) + page_offset;
        size_t guard_range   = page_range;

        // Page guard was disabled when these pages were accessed.  We enable it now for write, to
        // trap any writes made to the memory while we are performing the copy from shadow memory
        // to mapped memory.
        if (kMProtectMode == protection_mode_)
        {
            SetMemoryProtection(guard_address, guard_range, kGuardReadOnlyProtect);
        }
        else if (kUserFaultFdMode == protection_mode_)
        {
            assert(memory_info->aligned_address == memory_info->shadow_memory);
            // uffd requires page aligned addresses and sizes.
            UffdUnregisterMemory(guard_address, page_count << system_page_pot_shift_);
        }

        // Copy from shadow memory to the original mapped memory.
        if (start_index == 0)
        {
            page_range -= memory_info->aligned_offset;
        }
        else
        {
            page_offset -= memory_info->aligned_offset;
        }

        void* source_address      = static_cast<uint8_t*>(memory_info->shadow_memory) + page_offset;
        void* destination_address = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
        MemoryCopy(destination_address, source_address, page_range);

        // The shadow memory address, page offset, and range values to be provided to the callback, which will process
        // the memory range.
        handle_modified(memory_id, memory_info->shadow_memory, page_offset, page_range);

        if (kMProtectMode == protection_mode_)
        {
            // Reset page guard to detect both read and write accesses when using shadow memory.
            SetMemoryProtection(guard_address, guard_range, kGuardReadWriteProtect);
        }
        else if (kUserFaultFdMode == protection_mode_)
        {
            UffdResetRegion(guard_address, page_range);
        }
    }
    else
    {
        if (!memory_info->use_write_watch)
        {
            void* guard_address = static_cast<uint8_t*>(memory_info->aligned_address) + page_offset;

            if (kMProtectMode == protection_mode_)
            {
                // Reset page guard to detect only write accesses when not using shadow memory.
                SetMemoryProtection(guard_address, page_range, kGuardReadOnlyProtect);
            }
        }

        // Copy directly from the mapped memory.
        if (start_index == 0)
        {
            // If the watch pointer was aligned to the start of a page, the alignment offset needs to be
            // deducted from the page range.
            page_range -= memory_info->aligned_offset;
        }
        else
        {
            // If the start address was aligned to the start of a page, the alignment offset needs to be deducted from
            // the start offset.
            page_offset -= memory_info->aligned_offset;
        }

        // The mapped memory address, page offset, and range values to be provided to the callback, which will process
        // the memory range.
        handle_modified(memory_id, memory_info->mapped_memory, page_offset, page_range);
    }
}

bool PageGuardManager::GetTrackedMemory(uint64_t memory_id, void** memory)
{
    assert(memory != nullptr);

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
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

void* PageGuardManager::AddTrackedMemory(uint64_t  memory_id,
                                         void*     mapped_memory,
                                         size_t    mapped_offset,
                                         size_t    mapped_range,
                                         uintptr_t shadow_memory_handle,
                                         bool      use_shadow_memory,
                                         bool      use_write_watch)
{
    void*  aligned_address = nullptr;
    void*  shadow_memory   = nullptr;
    size_t shadow_size     = 0;
    size_t aligned_offset  = 0;

    ShadowMemoryInfo* shadow_memory_info = nullptr;

    if (use_shadow_memory)
    {
        if (use_write_watch)
        {
            // Although it would be possible to track writes to shadow memory with write watch, it is not possible to
            // track reads, which can require a copy from driver memory to shadow memory.
            use_write_watch = false;
            GFXRECON_LOG_WARNING(
                "PageGuardManager::AddTrackedMemory() ignored use_write_watch=true for mapped memory tracking "
                "with shadow memory")
        }

        if (shadow_memory_handle == kNullShadowHandle)
        {
            shadow_size   = GetAlignedSize(mapped_range);
            shadow_memory = AllocateMemory(shadow_size, false);

            if (shadow_memory != nullptr)
            {
                aligned_address = shadow_memory;

                if (enable_copy_on_map_ && kUserFaultFdMode != protection_mode_)
                {
                    MemoryCopy(shadow_memory, mapped_memory, mapped_range);
                }
            }
        }
        else
        {
            shadow_memory_info = reinterpret_cast<ShadowMemoryInfo*>(shadow_memory_handle);

            assert(shadow_memory_info->memory != nullptr);

            // Set the shadow memory pointer to the start of the mapped range.
            shadow_memory = static_cast<uint8_t*>(shadow_memory_info->memory) + mapped_offset;
            shadow_size   = mapped_range;

            aligned_address = AlignToPageStart(shadow_memory);
            aligned_offset  = GetOffsetFromPageStart(shadow_memory);
        }
    }
    else
    {
#if !defined(WIN32)
        if (use_write_watch)
        {
            // Only supported on Windows.
            use_write_watch = false;
            GFXRECON_LOG_WARNING("PageGuardManager::AddTrackedMemory() disabled write watch for mapped memory tracking "
                                 "due to lack of support from the current platform")
        }
#endif

        // Align the mapped memory pointer to the start of its page.
        aligned_address = AlignToPageStart(mapped_memory);
        aligned_offset  = GetOffsetFromPageStart(mapped_memory);
    }

    if (aligned_address != nullptr)
    {
        size_t guard_range = mapped_range + aligned_offset;

        // Userfaultfd requires the registered region to be multiples of the page size
        if (kUserFaultFdMode == protection_mode_ && guard_range != GetAlignedSize(guard_range))
        {
            if (!use_shadow_memory)
            {
                assert(shadow_memory == nullptr);
                GFXRECON_LOG_WARNING("Registering an externally allocated memory region to uffd using a range (%zu) "
                                     "greater than the requested/original size (%zu).",
                                     GetAlignedSize(guard_range),
                                     guard_range);
            }

            guard_range = GetAlignedSize(guard_range);
        }

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

        // When using persistent shadow allocations, copy the mapped range from the driver memory to shadow memory on
        // the first map.  Copied pages are marked dirty, and are not copied if mapped again.
        if (shadow_memory_info != nullptr)
        {
            size_t         first_page = (mapped_offset - aligned_offset) >> system_page_pot_shift_;
            uint8_t*       dst_page   = static_cast<uint8_t*>(shadow_memory);
            const uint8_t* src_page   = static_cast<const uint8_t*>(mapped_memory);

            for (size_t i = 0; i < total_pages; ++i)
            {
                size_t page_index = first_page + i;

                if (!shadow_memory_info->page_loaded[page_index])
                {
                    size_t copy_size = system_page_size_;

                    if ((page_index + 1) == shadow_memory_info->total_pages)
                    {
                        copy_size = shadow_memory_info->last_segment_size;
                    }

                    if (i == 0)
                    {
                        copy_size -= aligned_offset;
                    }

                    if (copy_size == system_page_size_)
                    {
                        // Only mark the block as loaded when there was a full copy.
                        shadow_memory_info->page_loaded[page_index] = true;
                    }

                    MemoryCopy(dst_page, src_page, copy_size);

                    dst_page += copy_size;
                    src_page += copy_size;
                }
            }
        }

        bool        success       = true;
        const void* start_address = mapped_memory;

        if (use_shadow_memory)
        {
            start_address = shadow_memory;
        }

        if (!use_write_watch)
        {
            if (kMProtectMode == protection_mode_)
            {
                AddExceptionHandler();

                // When using shadow memory, enable page guard for read and write operations so that shadow memory can
                // be synchronized with the mapped memory on both read and write access.  When not using shadow memory,
                // only detect write access.
                if (use_shadow_memory)
                {
                    success = SetMemoryProtection(aligned_address, guard_range, kGuardReadWriteProtect);
                }
                else
                {
                    success = SetMemoryProtection(aligned_address, guard_range, kGuardReadOnlyProtect);
                }
            }
            else
            {
                success = UffdRegisterMemory(aligned_address, guard_range);
            }
        }

        std::lock_guard<std::mutex> lock(tracked_memory_lock_);

        if (success)
        {
            assert(memory_info_.find(memory_id) == memory_info_.end());

            auto entry =
                memory_info_.emplace(std::piecewise_construct,
                                     std::forward_as_tuple(memory_id),
                                     std::forward_as_tuple(mapped_memory,
                                                           mapped_range,
                                                           shadow_memory,
                                                           shadow_size,
                                                           aligned_address,
                                                           aligned_offset,
                                                           total_pages,
                                                           last_segment_size,
                                                           start_address,
                                                           static_cast<const uint8_t*>(start_address) + mapped_range,
                                                           use_write_watch,
                                                           shadow_memory_handle == kNullShadowHandle));

            if (!entry.second)
            {
                if (!use_write_watch)
                {
                    if (kMProtectMode == protection_mode_)
                    {
                        RemoveExceptionHandler();
                        SetMemoryProtection(aligned_address, guard_range, kGuardNoProtect);
                    }
                    else
                    {
                        UffdUnregisterMemory(aligned_address, guard_range);
                    }
                }

                if (shadow_memory != nullptr)
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
        }
    }

    return (shadow_memory != nullptr) ? shadow_memory : mapped_memory;
}

void PageGuardManager::ReleaseTrackedMemory(const MemoryInfo* memory_info)
{
    if (!memory_info->use_write_watch)
    {
        if (kMProtectMode == protection_mode_)
        {
            RemoveExceptionHandler();
            SetMemoryProtection(
                memory_info->aligned_address, memory_info->mapped_range + memory_info->aligned_offset, kGuardNoProtect);
        }
        else
        {
            UffdUnregisterMemory(memory_info->shadow_memory, memory_info->shadow_range);
        }
    }
    if ((memory_info->shadow_memory != nullptr) && memory_info->own_shadow_memory)
    {
        FreeMemory(memory_info->shadow_memory, memory_info->shadow_range);
    }
}

void PageGuardManager::RemoveTrackedMemory(uint64_t memory_id)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);
    if (entry != memory_info_.end())
    {
        ReleaseTrackedMemory(&entry->second);

        memory_info_.erase(entry);
    }
}

uintptr_t PageGuardManager::AllocatePersistentShadowMemory(size_t size)
{
    ShadowMemoryInfo* info          = nullptr;
    size_t            shadow_size   = GetAlignedSize(size);
    void*             shadow_memory = AllocateMemory(shadow_size, false);

    if (shadow_memory != nullptr)
    {
        size_t total_shadow_pages       = shadow_size >> system_page_pot_shift_;
        size_t last_shadow_segment_size = size & (system_page_size_ - 1); // allocation_size % system_page_size_

        info = new ShadowMemoryInfo(shadow_memory, shadow_size, total_shadow_pages, last_shadow_segment_size);
    }

    return reinterpret_cast<uintptr_t>(info);
}

void PageGuardManager::FreePersistentShadowMemory(uintptr_t shadow_memory_handle)
{
    auto info = reinterpret_cast<ShadowMemoryInfo*>(shadow_memory_handle);

    if (info != nullptr)
    {
        FreeMemory(info->memory, info->size);
        delete info;
    }
}

void PageGuardManager::ProcessMemoryEntry(uint64_t memory_id, const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    auto entry = memory_info_.find(memory_id);

    uint32_t n_threads_to_wait = 0;
    if (protection_mode_ == kUserFaultFdMode)
    {
        n_threads_to_wait = UffdBlockFaultingThreads();
    }

    if (entry != memory_info_.end())
    {
        auto memory_info = &entry->second;

        if (memory_info->use_write_watch)
        {
            // Active memory tracking with VirtualProtect()/mprotect() is only applied to shadow memory.
            // When not using shadow memory, we need to query for active write status.
            LoadActiveWriteStates(memory_info);
        }

        if (memory_info->is_modified)
        {
            ProcessEntry(entry->first, memory_info, handle_modified);
        }
    }

    // Unblock threads
    if (protection_mode_ == kUserFaultFdMode)
    {
        UffdUnblockFaultingThreads(n_threads_to_wait);
    }
}

void PageGuardManager::ProcessMemoryEntries(const ModifiedMemoryFunc& handle_modified)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    uint32_t n_threads_to_wait = 0;
    if (protection_mode_ == kUserFaultFdMode)
    {
        n_threads_to_wait = UffdBlockFaultingThreads();
    }

    for (auto entry = memory_info_.begin(); entry != memory_info_.end(); ++entry)
    {
        auto memory_info = &entry->second;

        if (memory_info->use_write_watch)
        {
            // Active memory tracking with VirtualProtect()/mprotect() is only applied to shadow memory.
            // When not using shadow memory, we need to query for active write status.
            LoadActiveWriteStates(memory_info);
        }

        if (memory_info->is_modified)
        {
            ProcessEntry(entry->first, memory_info, handle_modified);
        }
    }

    // Unblock threads
    if (protection_mode_ == kUserFaultFdMode)
    {
        UffdUnblockFaultingThreads(n_threads_to_wait);
    }
}

bool PageGuardManager::HandleGuardPageViolation(void* address, bool is_write, bool clear_guard)
{
    assert(protection_mode_ == kMProtectMode);

    MemoryInfo* memory_info = nullptr;

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    bool found = FindMemory(address, &memory_info);
    if (found)
    {
        assert((memory_info != nullptr) && (memory_info->aligned_address != nullptr));
        assert(reinterpret_cast<uintptr_t>(address) >= reinterpret_cast<uintptr_t>(memory_info->aligned_address));

        memory_info->is_modified = true;

        // Get the offset from the start of the first protected memory page to the current address.
        size_t start_offset = static_cast<uint8_t*>(address) - static_cast<uint8_t*>(memory_info->aligned_address);

        size_t page_index   = start_offset >> system_page_pot_shift_;
        size_t page_offset  = page_index << system_page_pot_shift_;
        void*  page_address = static_cast<uint8_t*>(memory_info->aligned_address) + page_offset;
        size_t segment_size = GetMemorySegmentSize(memory_info, page_index);

        // Remove protection from page before accessing memory, if required by current guard type (required for all
        // types except WIN32 PAGE_GUARD).
        if (clear_guard)
        {
            SetMemoryProtection(page_address, segment_size, kGuardNoProtect);
        }

        // For POSIX systems, when compiled without PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION, is_write is always
        // true because we are not notified if the exception was raised by a read or write operation.
        if (is_write)
        {
            memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
        }
        else
        {
            // We should only receive a signal/exception for a read when shadow memory is enabled.
            assert(memory_info->shadow_memory != nullptr);

            // Copy from the mapped memory to the shadow memory.
            if (page_index == 0)
            {
                segment_size -= memory_info->aligned_offset;
            }
            else
            {
                page_offset -= memory_info->aligned_offset;
            }

            uint8_t* source_address      = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
            uint8_t* destination_address = static_cast<uint8_t*>(memory_info->shadow_memory) + page_offset;
            MemoryCopy(destination_address, source_address, segment_size);

            memory_info->status_tracker.SetActiveReadBlock(page_index, true);

            if (enable_read_write_same_page_)
            {
                // The page guard has been removed from this page.  If we expect both reads and writes to the page,
                // it needs to be marked for active write.
                memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
            }
        }
    }

    return found;
}

const void* PageGuardManager::GetMappedMemory(uint64_t memory_id) const
{
    const auto& mem_info = memory_info_.find(memory_id);
    if (mem_info != memory_info_.end())
    {
        return mem_info->second.mapped_memory;
    }

    return nullptr;
}

void PageGuardManager::GetDirtyMemoryRegions(uint64_t                                         memory_id,
                                             std::unordered_map<uint64_t, const MemoryInfo&>& memories_page_status)
{
    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    if (memory_id == 0)
    {
        for (auto& entry : memory_info_)
        {
            if (entry.second.is_modified)
            {
                memories_page_status.emplace(entry.first, entry.second);
            }
        }
    }
    else
    {
        const auto entry = memory_info_.find(memory_id);
        if (entry != memory_info_.end() && entry->second.is_modified)
        {
            memories_page_status.emplace(entry->first, entry->second);
        }
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
