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

static pthread_mutex_t reset_regions_mutex    = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  reset_regions_cond     = PTHREAD_COND_INITIALIZER;
static bool            block_accessor_threads = false;

static pthread_mutex_t wait_for_threads_mutex      = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  wait_for_threads_cond       = PTHREAD_COND_INITIALIZER;
static uint32_t        accessor_threads_in_handler = 0;

std::atomic<bool> PageGuardManager::is_uffd_handler_thread_running_ = { false };
std::atomic<bool> PageGuardManager::stop_uffd_handler_thread_       = { false };

void PageGuardManager::UffdStaticSignalHandler(int sig)
{
    assert(instance_);

    instance_->UffdSignalHandler(sig);
}

void PageGuardManager::UffdSignalHandler(int sig)
{
    assert(sig == uffd_rt_signal_used_);
    assert(uffd_rt_signal_used_ != -1);

    if (sig == uffd_rt_signal_used_)
    {
        // Signal reset regions
        {
            pthread_mutex_lock(&wait_for_threads_mutex);
            ++accessor_threads_in_handler;
            pthread_cond_signal(&wait_for_threads_cond);
            pthread_mutex_unlock(&wait_for_threads_mutex);
        }

        // Wait for reset regions to finish
        {
            pthread_mutex_lock(&reset_regions_mutex);
            while (block_accessor_threads)
            {
                pthread_cond_wait(&reset_regions_cond, &reset_regions_mutex);
            }
            pthread_mutex_unlock(&reset_regions_mutex);
        }

        // Decrement counter
        {
            pthread_mutex_lock(&wait_for_threads_mutex);
            --accessor_threads_in_handler;
            pthread_cond_signal(&wait_for_threads_cond);
            pthread_mutex_unlock(&wait_for_threads_mutex);
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
    struct sigaction sa = {};
    sa.sa_flags         = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = UffdStaticSignalHandler;

    if (sigaction(uffd_rt_signal_used_, &sa, NULL))
    {
        GFXRECON_LOG_ERROR("sigaction failed: %s", strerror(errno));
        uffd_rt_signal_used_ = -1;
        return false;
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
        stop_uffd_handler_thread_ = true;
        if (pthread_join(uffd_handler_thread_, nullptr))
        {
            GFXRECON_LOG_ERROR("%s() pthread_join failed: %s", __func__, strerror(errno));
        }
    }

    std::lock_guard<std::mutex> lock(tracked_memory_lock_);

    for (auto& entry : memory_info_)
    {
        ReleaseTrackedMemory(&entry.second);
    }

    if (uffd_fd_ != -1 && close(uffd_fd_))
    {
        GFXRECON_LOG_ERROR("Error closing uffd_fd: %s", strerror(errno));
    }

    if (uffd_rt_signal_used_ != -1)
    {
        UffdRemoveSignalHandler();
    }

    uffd_is_init_ = false;
    uffd_fd_      = -1;
}

bool PageGuardManager::UffdInit()
{
    if (uffd_fd_ == -1)
    {
        // open the userfault fd
        uffd_fd_ = syscall(SYS_userfaultfd, UFFD_USER_MODE_ONLY | O_CLOEXEC | O_NONBLOCK);
        if (uffd_fd_ == -1)
        {
            GFXRECON_LOG_ERROR("syscall/userfaultfd: %s", strerror(errno));
            return false;
        }

        // enable for api version and check features
        struct uffdio_api uffdio_api;
        uffdio_api.api      = UFFD_API;
        uffdio_api.features = UFFD_FEATURE_PAGEFAULT_FLAG_WP | UFFD_FEATURE_THREAD_ID;
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

        const uint64_t required_features[] = { UFFD_FEATURE_PAGEFAULT_FLAG_WP, UFFD_FEATURE_THREAD_ID };
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
    }

    return true;
}

bool PageGuardManager::UffdHandleFault(uint64_t address, uint64_t flags, bool wake_thread, uint64_t tid)
{
    assert(protection_mode_ == kUserFaultFdMode);

    MemoryInfo* memory_info;
    bool        found = FindMemory(reinterpret_cast<void*>(address), &memory_info);

    if (found)
    {
        // Pages are not touched before they are registed so only missing page faults are expected to happen
        assert((flags & UFFD_PAGEFAULT_FLAG_WP) != UFFD_PAGEFAULT_FLAG_WP);

        memory_info->uffd_fault_causing_threads.insert(tid);

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
            if (errno == EEXIST)
            {
                // EEXIST is ok and can happen when for example 2 threads try to access the same page
                // simultaneously. The first one will allocate the page when served, so the second one
                // will generate EEXIST.
                return true;
            }
            else
            {
                GFXRECON_LOG_ERROR("ioctl/uffdio_copy errno: %d: %s", errno, strerror(errno));
                GFXRECON_LOG_ERROR("  is_write: %d", is_write);
                GFXRECON_LOG_ERROR("  flags: 0x%" PRIx64, flags);
                GFXRECON_LOG_ERROR("  destination_address: %p", destination_address);
                GFXRECON_LOG_ERROR("  source_address: %p", source_address);
                GFXRECON_LOG_ERROR("  copy.dst: 0x%" PRIx64, copy.dst);
                GFXRECON_LOG_ERROR("  copy.src: 0x%" PRIx64, copy.src);
                GFXRECON_LOG_ERROR("  copy.len: %" PRIu64, system_page_size_);

                return false;
            }
        }

        if (copy.copy != system_page_size_)
        {
            GFXRECON_LOG_ERROR("Unexpected copy.copy (%" PRId64 " != %zu)", copy.copy, system_page_size_);
            return false;
        }

        return true;
    }
    else
    {
        GFXRECON_LOG_ERROR("Could not find memory entry containing 0x%" PRIx64);

        return false;
    }
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

    is_uffd_handler_thread_running_ = true;

    while (true)
    {
        struct pollfd pollfd[1];
        pollfd[0].fd     = uffd_fd_;
        pollfd[0].events = POLLIN;

        int pollres = poll(pollfd, 1, 200);

        if (stop_uffd_handler_thread_)
        {
            goto exit;
        }

        switch (pollres)
        {
            case -1:
                GFXRECON_LOG_ERROR("%s() poll error: %s", __func__, strerror(errno));
                continue;
                break;
            case 0:
                continue;
                break;
            case 1:
                break;
            default:
                GFXRECON_LOG_ERROR("%s() poll error: got %d fds instead of 1\n", pollres);
                goto exit;
        }

        if (pollfd[0].revents & POLLERR)
        {
            GFXRECON_LOG_ERROR("Poll got POLLERR");
            goto exit;
        }

        if (!(pollfd[0].revents & POLLIN))
        {
            continue;
        }

        int64_t         readres;
        struct uffd_msg msg[16];
        while ((readres = read(uffd_fd_, &msg, sizeof(msg))) < 0)
        {
            if (errno == EAGAIN)
            {
                // Try again
                continue;
            }
            else
            {
                GFXRECON_LOG_ERROR("read/userfaultfd: %s", strerror(errno));
                goto exit;
            }
        }

        if (readres % sizeof(uffd_msg))
        {
            GFXRECON_LOG_ERROR("Unexpected read size\n");
            goto exit;
        }

        if (readres == sizeof(msg))
        {
            GFXRECON_LOG_ERROR("Messages might have been lost");
        }

        // Lock here instead of inside UffdHandleFault() in order to avoid multiple locks + unlocks
        // in case of multiple messages.
        tracked_memory_lock_.lock();

        const unsigned int n_messages = readres / sizeof(struct uffd_msg);
        for (unsigned int i = 0; i < n_messages; ++i)
        {
            if (msg[i].event == UFFD_EVENT_PAGEFAULT)
            {
                UffdHandleFault(msg[i].arg.pagefault.address,
                                msg[i].arg.pagefault.flags,
                                n_messages == 1,
                                static_cast<uint64_t>(msg[i].arg.pagefault.feat.ptid));
            }
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

    is_uffd_handler_thread_running_ = false;

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
        return false;
    }

    stop_uffd_handler_thread_ = false;

    return true;
}

bool PageGuardManager::InitializeUserFaultFd()
{
    assert(!uffd_is_init_);

    uffd_is_init_            = false;
    uffd_rt_signal_used_     = -1;
    uffd_fd_                 = -1;
    uffd_page_size_tmp_buff_ = std::make_unique<uint8_t[]>(util::platform::GetSystemPageSize());

    if (!UffdInit())
    {
        goto init_failed;
    }

    if (!UffdStartHandlerThread())
    {
        goto init_failed;
    }

    if (!UffdSetSignalHandler())
    {
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

    struct uffdio_register uffdio_register;
    uffdio_register.range.start = GFXRECON_PTR_TO_UINT64(address);
    uffdio_register.range.len   = length;
    uffdio_register.mode        = UFFDIO_REGISTER_MODE_WP | UFFDIO_REGISTER_MODE_MISSING;
    if (ioctl(uffd_fd_, UFFDIO_REGISTER, &uffdio_register) == -1)
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_register: %s", strerror(errno));
        return false;
    }

    const uint64_t zero_page_ioctl = (uint64_t)0x1 << _UFFDIO_ZEROPAGE;
    const uint64_t copy_ioctl      = (uint64_t)0x1 << _UFFDIO_COPY;
    const uint64_t expected_ioctls = zero_page_ioctl | copy_ioctl;
    if ((uffdio_register.ioctls & expected_ioctls) != expected_ioctls)
    {
        GFXRECON_LOG_ERROR("Unexpected userfaultfd ioctl set (expected: 0x%llx got: 0x%llx)\n",
                           expected_ioctls,
                           uffdio_register.ioctls);
        return false;
    }

    struct uffdio_writeprotect prot_p;
    prot_p.range.start = GFXRECON_PTR_TO_UINT64(address);
    prot_p.range.len   = length;
    prot_p.mode        = UFFDIO_WRITEPROTECT_MODE_WP;
    if (ioctl(uffd_fd_, UFFDIO_WRITEPROTECT, &prot_p))
    {
        GFXRECON_LOG_ERROR("ioctl/uffdio_writeprotect: %s\n", strerror(errno));

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

uint32_t PageGuardManager::UffdBlockFaultingThreads(const MemoryInfo* memory_info)
{
    assert(!accessor_threads_in_handler);

    // Set to one before sending the signal to the threads
    block_accessor_threads = true;

    uint32_t       n_threads_to_wait = 0;
    const uint64_t this_tid          = util::platform::GetCurrentThreadId();
    for (const auto& entry : memory_info->uffd_fault_causing_threads)
    {
        // Don't send the signal to this thread.
        // Threads that do not exist any more do not count. In this case SendSignalToThread()
        // will return an error
        if (this_tid != entry && util::platform::SendSignalToThread(entry, uffd_rt_signal_used_) == 0)
        {
            ++n_threads_to_wait;
        }
    }

    // If the signal was sent to any threads wait to make sure all of them have entered the signal handler
    if (n_threads_to_wait)
    {
        pthread_mutex_lock(&wait_for_threads_mutex);
        while (accessor_threads_in_handler < n_threads_to_wait)
        {
            pthread_cond_wait(&wait_for_threads_cond, &wait_for_threads_mutex);
        }
        pthread_mutex_unlock(&wait_for_threads_mutex);
    }

    return n_threads_to_wait;
}

void PageGuardManager::UffdUnblockFaultingThreads(MemoryInfo* memory_info, uint32_t n_threads_to_wait)
{
    if (n_threads_to_wait)
    {
        pthread_mutex_lock(&reset_regions_mutex);
        block_accessor_threads = false;
        pthread_cond_broadcast(&reset_regions_cond);
        pthread_mutex_unlock(&reset_regions_mutex);

        // Wait for all threads to exit the signal handler. Otherwise there's race condition if we try to
        // send another batch of threads into the signal handler and the previous one haven't exited yet.
        pthread_mutex_lock(&wait_for_threads_mutex);
        while (accessor_threads_in_handler)
        {
            pthread_cond_wait(&wait_for_threads_cond, &wait_for_threads_mutex);
        }
        pthread_mutex_unlock(&wait_for_threads_mutex);
    }
    else
    {
        // No reason to synch. Just set it to false.
        block_accessor_threads = false;
    }

    // Reset this, otherwise threads might start accumulate and we will have to sent too many signals
    memory_info->uffd_fault_causing_threads.clear();
}

void PageGuardManager::UffdBlockRtSignal()
{
    if (uffd_rt_signal_used_ != -1)
    {
        sigprocmask(SIG_BLOCK, &uffd_signal_set_, NULL);
    }
}

void PageGuardManager::UffdUnblockRtSignal()
{
    if (uffd_rt_signal_used_ != -1)
    {
        sigprocmask(SIG_UNBLOCK, &uffd_signal_set_, NULL);
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

uint32_t PageGuardManager::UffdBlockFaultingThreads(const MemoryInfo* memory_info)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_info);
    return 0;
}

void PageGuardManager::UffdUnblockFaultingThreads(MemoryInfo* memory_info, uint32_t n_threads_to_wait)
{
    GFXRECON_UNREFERENCED_PARAMETER(memory_info);
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
