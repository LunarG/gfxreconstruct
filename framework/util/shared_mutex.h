
/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_SHARED_MUTEX_H
#define GFXRECON_UTIL_SHARED_MUTEX_H

#include "util/defines.h"

#include <atomic>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// A shared (reader/writer) mutex implementation using std::mutex and std::atomic.
class SharedMutex
{
  public:
    SharedMutex() : reader_count_(0), wait_for_writer_(false) {}

    // Exclusive lock which waits for current readers in a spin lock then acquires the mutex. A thread's read lock can
    // be promoted to a write lock.
    void lock();
    void unlock();

    void lock_shared();
    void unlock_shared();

  private:
    // Not copyable or movable
    SharedMutex(const SharedMutex&) = delete;
    SharedMutex& operator=(const SharedMutex&) = delete;

  private:
    static thread_local std::atomic_bool has_read_lock_;

  private:
    std::mutex         writer_mutex;
    std::atomic_size_t reader_count_;
    std::atomic_bool   wait_for_writer_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_SHARED_MUTEX_H
