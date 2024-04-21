/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#if USERFAULTFD_SUPPORTED == 1
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cinttypes>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static pthread_mutex_t reset_regions_mutex    = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;
static pthread_cond_t  reset_regions_cond     = PTHREAD_COND_INITIALIZER;
static bool            block_accessor_threads = false;

static pthread_mutex_t wait_for_threads_mutex = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;
static pthread_cond_t  wait_for_threads_cond  = PTHREAD_COND_INITIALIZER;
static uint32_t        blocked_threads        = 0;
static uint32_t        threads_to_block       = 0;

std::atomic<bool> PageGuardManager::is_uffd_handler_thread_running_ = { false };

void PageGuardManager::UffdStaticSignalHandler(int sig)
{
    assert(instance_);

    instance_->UffdSignalHandler(sig);
}

static void internal_thread_termination_handler(int sig)
{
    // The purpose of this handler is to gracefully terminate the uffd handler thread
    pthread_exit(nullptr);
}

#define LOG_THREAD_SYNCHRONIZATION_ERROR(_tid, _func_name, _error)  \
    GFXRECON_LOG_ERROR("[%" PRIu64 "] %s: %u %s() failed %d (%s) ", \
                       (_tid),                                      \
                       __func__,                                    \
                       __LINE__,                                    \
                       (_func_name),                                \
                       (_error),                                    \
                       strerror((_error)))

void PageGuardManager::UffdSignalHandler(int sig)
{
    assert(sig == uffd_rt_signal_used_);
    assert(uffd_rt_signal_used_ != -1);

    if (sig == uffd_rt_signal_used_)
    {
        const uint64_t tid = util::platform::GetCurrentThreadId();

        // Signal reset regions
        {
            int ret = pthread_mutex_lock(&wait_for_threads_mutex);
            if (ret == 0)
            {
                ++blocked_threads;
                if (blocked_threads == threads_to_block)
                {
                    ret = pthread_cond_signal(&wait_for_threads_cond);
                    if (ret)
                    {
                        LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_cond_signal()", ret);
                        assert(0);
                    }
                }

                ret = pthread_mutex_unlock(&wait_for_threads_mutex);
                if (ret)
                {
                    LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_unlock()", ret);
                    assert(0);
                }
            }
            else
            {
                LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_lock()", ret);
                assert(0);
            }
        }

        // Wait for reset regions to finish
        {
            int ret = pthread_mutex_lock(&reset_regions_mutex);
            if (ret == 0)
            {
                while (block_accessor_threads)
                {
                    ret = pthread_cond_wait(&reset_regions_cond, &reset_regions_mutex);
                    if (ret)
                    {
                        LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_cond_wait()", ret);
                        assert(0);
                    }
                }

                ret = pthread_mutex_unlock(&reset_regions_mutex);
                if (ret)
                {
                    LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_unlock()", ret);
                    assert(0);
                }
            }
            else
            {
                LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_lock()", ret);
                assert(0);
            }
        }

        // Decrement counter
        {
            int ret = pthread_mutex_lock(&wait_for_threads_mutex);
            if (ret == 0)
            {
                --blocked_threads;
                if (!blocked_threads)
                {
                    ret = pthread_cond_signal(&wait_for_threads_cond);
                    if (ret)
                    {
                        LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_cond_signal()", ret);
                        assert(0);
                    }
                }

                // GFXRECON_WRITE_CONSOLE("[%" PRIu64 "] CU", tid)
                ret = pthread_mutex_unlock(&wait_for_threads_mutex);
                if (ret)
                {
                    LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_unlock()", ret);
                    assert(0);
                }
            }
            else
            {
                LOG_THREAD_SYNCHRONIZATION_ERROR(tid, "pthread_mutex_lock()", ret);
                assert(0);
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("%s() received signal %d instead of %d", __func__, sig, uffd_rt_signal_used_);
    }
}

bool PageGuardManager::UffdSetSignalHandler()
{
    // Search for a free RT signal
    for (int sig = SIGRTMIN; sig < SIGRTMAX + 1; ++sig)
    {
        struct sigaction current_handler = {};
        if (sigaction(sig, nullptr, &current_handler))
        {
            GFXRECON_LOG_ERROR("%s(): sigaction query failed: %s", __func__, strerror(errno));
            continue;
        }

        if (current_handler.sa_handler == nullptr && current_handler.sa_sigaction == nullptr)
        {
            uffd_rt_signal_used_ = sig;
            break;
        }
    }

    if (uffd_rt_signal_used_ == -1)
    {
        GFXRECON_LOG_ERROR(
            "Searched through all RT signals [%d,  %d] and no free signal was found", SIGRTMIN, SIGRTMAX);
        return false;
    }

    // Install signal handler for the RT signal
    {
        struct sigaction sa = {};
        sa.sa_flags         = SA_SIGINFO;
        sigemptyset(&sa.sa_mask);
        sa.sa_handler = UffdStaticSignalHandler;

        if (sigaction(uffd_rt_signal_used_, &sa, NULL))
        {
            GFXRECON_LOG_ERROR("sigaction failed to register signal %d (%s)", uffd_rt_signal_used_, strerror(errno));
            uffd_rt_signal_used_ = -1;
            return false;
        }
    }

    // Register a handler for SIGINT. We will use this signal to terminate the uffd handler thread
    {
        struct sigaction sa = {};
        sa.sa_flags         = SA_SIGINFO;
        sigemptyset(&sa.sa_mask);
        sa.sa_handler = internal_thread_termination_handler;

        if (sigaction(SIGINT, &sa, NULL))
        {
            GFXRECON_LOG_ERROR("sigaction failed to register SIGINT (%s)", uffd_rt_signal_used_, strerror(errno));
            return false;
        }
    }

    // Have uffd_signal_set_ prepared for when we need to block/unblock the signal
    sigemptyset(&uffd_signal_set_);
    sigaddset(&uffd_signal_set_, uffd_rt_signal_used_);

    return true;
}

void PageGuardManager::UffdRemoveSignalHandler()
{
    assert(uffd_rt_signal_used_ != -1);

    struct sigaction sa = {};
    sa.sa_flags         = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = nullptr;

    if (sigaction(uffd_rt_signal_used_, &sa, NULL))
    {
        GFXRECON_LOG_ERROR("%s() sigaction failed: %s", __func__, strerror(errno));
    }

    uffd_rt_signal_used_ = -1;
}

void PageGuardManager::UffdTerminate()
{
    if (is_uffd_handler_thread_running_)
    {
        // Terminate handler thread
        if (!pthread_kill(uffd_handler_thread_, SIGINT))
        {
            if (pthread_join(uffd_handler_thread_, nullptr))
            {
                GFXRECON_LOG_ERROR("%s() pthread_join failed: %s", __func__, strerror(errno));
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("pthread_kill failed to send signal to handler thread. Terminating anyway")
        }

        is_uffd_handler_thread_running_ = false;
    }

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto& entry : memory_info_)
    {
        ReleaseTrackedMemory(&entry.second);
    }

    if (uffd_fd_ != -1 && close(uffd_fd_))
    {
        GFXRECON_LOG_ERROR("Error closing uffd_fd: %s", strerror(errno));
        uffd_fd_ = -1;
    }

    if (uffd_rt_signal_used_ != -1)
    {
        UffdRemoveSignalHandler();
        uffd_rt_signal_used_ = -1;
    }

    uffd_is_init_ = false;
}

bool PageGuardManager::UffdHandleFault(MemoryInfo* memory_info, uint64_t address, uint64_t flags, bool wake_thread)
{
    assert(protection_mode_ == kUserFaultFdMode);

    // Pages are not touched before they are registed so only missing page faults are expected to happen
    assert((flags & UFFD_PAGEFAULT_FLAG_WP) != UFFD_PAGEFAULT_FLAG_WP);

    memory_info->is_modified = true;

    assert((memory_info != nullptr) && (memory_info->aligned_address != nullptr));
    assert(static_cast<uintptr_t>(address) >= reinterpret_cast<uintptr_t>(memory_info->aligned_address));

    // Get the offset from the start of the first protected memory page to the current address.
    const size_t start_offset =
        reinterpret_cast<uint8_t*>(address) - static_cast<uint8_t*>(memory_info->aligned_address);
    const size_t page_index  = start_offset >> system_page_pot_shift_;
    const size_t page_offset = page_index << system_page_pot_shift_;
    assert(start_offset == page_offset);
    const size_t segment_size = GetMemorySegmentSize(memory_info, page_index);
    assert(segment_size <= system_page_size_);

    assert(!(GFXRECON_PTR_TO_UINT64(memory_info->aligned_address) % system_page_size_));
    assert(memory_info->aligned_offset == 0);

    const bool is_write = (flags & UFFD_PAGEFAULT_FLAG_WRITE) == UFFD_PAGEFAULT_FLAG_WRITE;
    if (is_write)
    {
        memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
    }
    else
    {
        memory_info->status_tracker.SetActiveReadBlock(page_index, true);

        if (enable_read_write_same_page_)
        {
            // The page guard has been removed from this page.  If we expect both reads and writes to the page,
            // it needs to be marked for active write.
            memory_info->status_tracker.SetActiveWriteBlock(page_index, true);
        }
    }

    // Copy from the mapped memory to the shadow memory.
    uint8_t* source_address;
    if (segment_size < system_page_size_)
    {
        assert(0);
        // This shouldn't happen, at least not often, as we should warn if mapped memory (and therefore shadow
        // memory too) is not page aligned.
        util::platform::MemoryCopy(uffd_page_size_tmp_buff_.get(),
                                   segment_size,
                                   static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset,
                                   segment_size);

        source_address = uffd_page_size_tmp_buff_.get();
    }
    else
    {
        assert(memory_info->aligned_offset == 0);
        source_address = static_cast<uint8_t*>(memory_info->mapped_memory) + page_offset;
    }

    uint8_t* destination_address = static_cast<uint8_t*>(memory_info->shadow_memory) + page_offset;

    // Pointers need to be properly casted to uint64_t to avoid sign extension in case it is a 32bit build
    struct uffdio_copy copy;
    copy.dst  = GFXRECON_PTR_TO_UINT64(destination_address);
    copy.src  = GFXRECON_PTR_TO_UINT64(source_address);
    copy.len  = system_page_size_;
    copy.mode = wake_thread ? 0 : UFFDIO_COPY_MODE_DONTWAKE;

    if (ioctl(uffd_fd_, UFFDIO_COPY, &copy))
    {
        if (errno != EEXIST)
        {
            GFXRECON_LOG_ERROR("ioctl/uffdio_copy errno: %d: %s", errno, strerror(errno));
            GFXRECON_LOG_ERROR("  is_write: %d", is_write);
            GFXRECON_LOG_ERROR("  flags: 0x%" PRIx64, flags);
            GFXRECON_LOG_ERROR("  destination_address: %p", destination_address);
            GFXRECON_LOG_ERROR("  source_address: %p", source_address);
            GFXRECON_LOG_ERROR("  copy.dst: 0x%" PRIx64, copy.dst);
            GFXRECON_LOG_ERROR("  copy.src: 0x%" PRIx64, copy.src);
            GFXRECON_LOG_ERROR("  copy.len: %" PRIu64, copy.len);
        }

        return false;
    }

    if (copy.copy != system_page_size_)
    {
        GFXRECON_LOG_ERROR("Unexpected copy.copy (%" PRId64 " != %zu)", copy.copy, system_page_size_);
        return false;
    }

    return true;
}

bool PageGuardManager::UffdWakeFaultingThread(uint64_t address)
{
    struct uffdio_range uffdio_wake;
    uffdio_wake.start = address;
    uffdio_wake.len   = static_cast<uint64_t>(system_page_size_);
    if (ioctl(uffd_fd_, UFFDIO_WAKE, &uffdio_wake) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_wake: %s", strerror(errno));
        return false;
    }

    return true;
}

void* PageGuardManager::UffdHandlerThread(void* args)
{
    GFXRECON_UNREFERENCED_PARAMETER(args);
    assert(uffd_fd_ != -1);

    while (true)
    {
        struct uffd_msg msg[16];
        const int64_t   readres = read(uffd_fd_, &msg, sizeof(msg));

        tracked_memory_lock_.lock();

        if (readres <= 0)
        {
            if (errno == EAGAIN)
            {
                // Try again
                tracked_memory_lock_.unlock();
                continue;
            }
            else
            {
                GFXRECON_LOG_ERROR("read/userfaultfd: %s", strerror(errno));
                goto exit;
            }
        }

        if (readres == sizeof(msg))
        {
            GFXRECON_LOG_ERROR("Messages might have been lost");
        }

        const unsigned int n_messages = readres / sizeof(struct uffd_msg);
        for (unsigned int i = 0; i < n_messages; ++i)
        {
            assert(msg[i].event == UFFD_EVENT_PAGEFAULT);

            const uint64_t address = msg[i].arg.pagefault.address;
            MemoryInfo*    memory_info;
            bool           found = FindMemory(reinterpret_cast<void*>(address), &memory_info);
            if (!found)
            {
                GFXRECON_LOG_ERROR("Could not find memory entry containing 0x%" PRIx64, address);
                continue;
            }

            uffd_fault_causing_threads.insert(static_cast<uint64_t>(msg[i].arg.pagefault.feat.ptid));

            // Skip repeating faults on the same page
            if (i && (msg[i].arg.pagefault.address % system_page_size_) ==
                         (msg[i - 1].arg.pagefault.address % system_page_size_))
            {
                continue;
            }

            UffdHandleFault(memory_info, msg[i].arg.pagefault.address, msg[i].arg.pagefault.flags, n_messages == 1);
        }

        // When there are multiple messages from multiple threads deferre waking
        // them up to avoid race conditions
        if (n_messages > 1)
        {
            for (unsigned int i = 0; i < n_messages; ++i)
            {
                if (msg[i].event == UFFD_EVENT_PAGEFAULT)
                {
                    UffdWakeFaultingThread(msg[i].arg.pagefault.address);
                }
            }
        }

        tracked_memory_lock_.unlock();
    }
exit:

    tracked_memory_lock_.unlock();

    return nullptr;
}

void* PageGuardManager::UffdHandlerThreadHelper(void* this_)
{
    assert(this_);

    return reinterpret_cast<PageGuardManager*>(this_)->UffdHandlerThread(nullptr);
}

bool PageGuardManager::UffdStartHandlerThread()
{
    assert(uffd_fd_ != -1);

    if (pthread_create(&uffd_handler_thread_, nullptr, UffdHandlerThreadHelper, this))
    {
        GFXRECON_LOG_ERROR("%s() pthread_create: %s", __func__, strerror(errno));
        assert(0);
        return false;
    }

    sleep(1);

    is_uffd_handler_thread_running_ = true;

    return true;
}

bool PageGuardManager::UffdInit()
{
    assert(uffd_fd_ == -1);

    // open the userfault fd
    uffd_fd_ = syscall(SYS_userfaultfd, UFFD_USER_MODE_ONLY | O_CLOEXEC);
    if (uffd_fd_ == -1)
    {
        GFXRECON_LOG_ERROR("syscall/userfaultfd: %s", strerror(errno));
        return false;
    }

    // enable for api version and check features
    struct uffdio_api uffdio_api;
    uffdio_api.api      = UFFD_API;
    uffdio_api.features = UFFD_FEATURE_THREAD_ID;
    if (ioctl(uffd_fd_, UFFDIO_API, &uffdio_api) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_api: %s", strerror(errno));

        return false;
    }

    if (uffdio_api.api != UFFD_API)
    {
        GFXRECON_LOG_ERROR("Unsupported userfaultfd api");

        return false;
    }

    const uint64_t required_features[] = { UFFD_FEATURE_THREAD_ID };
    for (size_t i = 0; i < sizeof(required_features) / sizeof(required_features[0]); ++i)
    {
        if ((uffdio_api.features & required_features[i]) != required_features[i])
        {
            GFXRECON_LOG_ERROR("Unsupported userfaultfd feature: 0x%" PRIx64 "\n", required_features[i]);

            return false;
        }
    }

    const uint64_t requested_ioctls[] = { 0x1 << _UFFDIO_REGISTER };
    for (size_t i = 0; i < sizeof(requested_ioctls) / sizeof(requested_ioctls[0]); ++i)
    {
        if ((uffdio_api.ioctls & requested_ioctls[i]) != requested_ioctls[i])
        {
            GFXRECON_LOG_ERROR("Unsupported userfaultfd ioctl: 0x%" PRIx64 "\n", requested_ioctls[i]);

            return false;
        }
    }

    return true;
}

bool PageGuardManager::InitializeUserFaultFd()
{
    assert(!uffd_is_init_);

    uffd_rt_signal_used_     = -1;
    uffd_fd_                 = -1;
    uffd_page_size_tmp_buff_ = std::make_unique<uint8_t[]>(util::platform::GetSystemPageSize());

    if (!UffdInit())
    {
        assert(0);
        goto init_failed;
    }

    if (!UffdStartHandlerThread())
    {
        assert(0);
        goto init_failed;
    }

    if (!UffdSetSignalHandler())
    {
        assert(0);
        goto init_failed;
    }

    uffd_is_init_ = true;

    return true;

init_failed:
    UffdTerminate();
    return false;
}

bool PageGuardManager::UffdRegisterMemory(const void* address, size_t length)
{
    assert(uffd_fd_ != -1);

    if (!length || (length % system_page_size_))
    {
        GFXRECON_LOG_ERROR(
            "Attempting to register a memory region with a non page aligned length (%zu) (system's page size %zu).",
            length,
            system_page_size_);
    }

    if (!util::platform::IsAddressAligned(address, system_page_size_))
    {
        GFXRECON_LOG_ERROR("Attempting to register a memory region with non page aligned base address (%zu) (system's "
                           "page size: %zu).",
                           address,
                           system_page_size_);
    }

    struct uffdio_register uffdio_register;
    uffdio_register.range.start = GFXRECON_PTR_TO_UINT64(address);
    uffdio_register.range.len   = length;
    uffdio_register.mode        = UFFDIO_REGISTER_MODE_MISSING;
    if (ioctl(uffd_fd_, UFFDIO_REGISTER, &uffdio_register) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_register: %s", strerror(errno));
        GFXRECON_LOG_ERROR("uffdio_register.range.start: 0x%" PRIx64, uffdio_register.range.start);
        GFXRECON_LOG_ERROR("uffdio_register.range.len: %" PRId64, uffdio_register.range.len);
        return false;
    }

    const uint64_t expected_ioctls = (uint64_t)0x1 << _UFFDIO_COPY;
    if ((uffdio_register.ioctls & expected_ioctls) != expected_ioctls)
    {
        GFXRECON_LOG_ERROR("Unexpected userfaultfd ioctl set (expected: 0x%llx got: 0x%llx)\n",
                           expected_ioctls,
                           uffdio_register.ioctls);
        return false;
    }

    return true;
}

void PageGuardManager::UffdUnregisterMemory(const void* address, size_t length)
{
    assert(uffd_fd_ != -1);

    struct uffdio_range uffdio_unregister;
    uffdio_unregister.start = GFXRECON_PTR_TO_UINT64(address);
    uffdio_unregister.len   = static_cast<uint64_t>(length);
    if (ioctl(uffd_fd_, UFFDIO_UNREGISTER, &uffdio_unregister) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_unregister: %s", strerror(errno));
        GFXRECON_LOG_ERROR("uffdio_unregister.start: 0x%" PRIx64, uffdio_unregister.start);
        GFXRECON_LOG_ERROR("uffdio_unregister.len: %" PRId64, uffdio_unregister.len);
    }
}

bool PageGuardManager::UffdResetRegion(void* guard_address, size_t guard_range)
{
    // Release pages and allocate fresh ones
    madvise(guard_address, guard_range, MADV_DONTNEED);
    void* shadow_memory = guard_address;
    guard_address       = util::platform::AllocateRawMemory(guard_range, false, guard_address);
    if (!guard_address)
    {
        GFXRECON_LOG_ERROR("mmap error: %s", strerror(errno));

        return false;
    }
    else if (guard_address != shadow_memory)
    {
        GFXRECON_LOG_ERROR("MAP_FIXED was not honored when remapping memory");

        return false;
    }

    return UffdRegisterMemory(guard_address, guard_range);
}

uint32_t PageGuardManager::UffdBlockFaultingThreads()
{
    assert(!blocked_threads);

    const uint64_t this_tid = util::platform::GetCurrentThreadId();

    int ret = pthread_mutex_lock(&wait_for_threads_mutex);
    if (ret)
    {
        LOG_THREAD_SYNCHRONIZATION_ERROR(this_tid, "pthread_mutex_lock()", ret);
        assert(0);
    }

    // Set to one before sending the signal to the threads
    block_accessor_threads = true;

    threads_to_block = 0;
    for (const auto& entry : uffd_fault_causing_threads)
    {
        // Don't send the signal to this thread.
        if (this_tid == entry)
        {
            continue;
        }

        // Threads that do not exist any more do not count. In this case SendSignalToThread()
        // will return an error
        ret = util::platform::SendSignalToThread(entry, uffd_rt_signal_used_);
        if (ret == 0)
        {
            ++threads_to_block;
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Sending signal to thread %" PRIu64 " failed %d (%s - %s)", entry, ret, strerror(ret), strerror(errno));
        }
    }

    // If the signal was sent to any threads wait to make sure all of them have entered the signal handler
    if (threads_to_block)
    {
        while (blocked_threads < threads_to_block)
        {
            ret = pthread_cond_wait(&wait_for_threads_cond, &wait_for_threads_mutex);
            if (ret)
            {
                LOG_THREAD_SYNCHRONIZATION_ERROR(this_tid, "pthread_cond_wait()", ret);
                assert(0);
            }
        }
        ret = pthread_mutex_unlock(&wait_for_threads_mutex);
        if (ret)
        {
            LOG_THREAD_SYNCHRONIZATION_ERROR(this_tid, "pthread_mutex_unlock()", ret);
            assert(0);
        }
    }
    else
    {
        ret = pthread_mutex_unlock(&wait_for_threads_mutex);
        if (ret)
        {
            LOG_THREAD_SYNCHRONIZATION_ERROR(this_tid, "pthread_mutex_unlock()", ret);
            assert(0);
        }
    }

    return threads_to_block;
}

void PageGuardManager::UffdUnblockFaultingThreads(uint32_t n_threads_to_wait)
{
    if (n_threads_to_wait)
    {
        int ret = pthread_mutex_lock(&reset_regions_mutex);
        if (ret == 0)
        {
            // GFXRECON_WRITE_CONSOLE("rst")
            block_accessor_threads = false;
            ret                    = pthread_cond_broadcast(&reset_regions_cond);
            if (ret)
            {
                GFXRECON_WRITE_CONSOLE("%s() broadcast failed %d %s", __func__, ret, strerror(ret));
                assert(0);
            }

            ret = pthread_mutex_unlock(&reset_regions_mutex);
            if (ret)
            {
                GFXRECON_WRITE_CONSOLE("%s() 1 unlock failed %d %s", __func__, ret, strerror(ret));
                assert(0);
            }
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("%s() 1 lock failed %d %s", __func__, ret, strerror(ret));
            assert(0);
        }

        // Wait for all threads to exit the signal handler. Otherwise there's race condition if we try to
        // send another batch of threads into the signal handler and the previous one haven't exited yet.
        assert(n_threads_to_wait == threads_to_block);
        ret = pthread_mutex_lock(&wait_for_threads_mutex);
        if (ret == 0)
        {
            // GFXRECON_WRITE_CONSOLE("wait: %u", n_threads_to_wait)
            while (blocked_threads)
            {
                ret = pthread_cond_wait(&wait_for_threads_cond, &wait_for_threads_mutex);
                if (ret)
                {
                    GFXRECON_WRITE_CONSOLE("%s() wait failed %d %s", __func__, ret, strerror(ret));
                    assert(0);
                }
            }

            ret = pthread_mutex_unlock(&wait_for_threads_mutex);
            if (ret)
            {
                GFXRECON_WRITE_CONSOLE("%s() 2 unlock failed %d %s", __func__, ret, strerror(ret));
                assert(0);
            }
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("%s() 2 lock failed %d %s", __func__, ret, strerror(ret));
        }
    }
    else
    {
        // No reason to synch. Just set it to false.
        block_accessor_threads = false;
    }
}

void PageGuardManager::UffdBlockRtSignal()
{
    if (uffd_rt_signal_used_ != -1)
    {
        int ret = sigprocmask(SIG_BLOCK, &uffd_signal_set_, NULL);
        if (ret)
        {
            GFXRECON_LOG_ERROR("%s sigprocmask failed with: %s", __func__, strerror(errno))
        }
    }
}

void PageGuardManager::UffdUnblockRtSignal()
{
    if (uffd_rt_signal_used_ != -1)
    {
        int ret = sigprocmask(SIG_UNBLOCK, &uffd_signal_set_, NULL);
        if (ret)
        {
            GFXRECON_LOG_ERROR("%s sigprocmask failed with: %s", __func__, strerror(errno))
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#else

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool PageGuardManager::InitializeUserFaultFd()
{
    return false;
}

void PageGuardManager::UffdTerminate() {}

bool PageGuardManager::UffdRegisterMemory(const void* address, size_t length)
{
    GFXRECON_UNREFERENCED_PARAMETER(address);
    GFXRECON_UNREFERENCED_PARAMETER(length);

    return false;
}

void PageGuardManager::UffdUnregisterMemory(const void* address, size_t length)
{
    GFXRECON_UNREFERENCED_PARAMETER(address);
    GFXRECON_UNREFERENCED_PARAMETER(length);
}

uint32_t PageGuardManager::UffdBlockFaultingThreads()
{
    return 0;
}

void PageGuardManager::UffdUnblockFaultingThreads(uint32_t n_threads_to_wait)
{
    GFXRECON_UNREFERENCED_PARAMETER(n_threads_to_wait);
}

bool PageGuardManager::UffdResetRegion(void* guard_address, size_t guard_range)
{
    GFXRECON_UNREFERENCED_PARAMETER(guard_address);
    GFXRECON_UNREFERENCED_PARAMETER(guard_range);

    return true;
}

void PageGuardManager::UffdBlockRtSignal() {}

void PageGuardManager::UffdUnblockRtSignal() {}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#endif // USERFAULTFD_SUPPORTED == 1
