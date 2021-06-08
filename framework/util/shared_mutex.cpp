
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

#include "util/shared_mutex.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

thread_local std::atomic_size_t SharedMutex::read_lock_depth_{ 0 };

void SharedMutex::lock()
{
    // Acquire writer mutex and indicate to readers the writer is waiting.
    // If wait_for_writer_ is true, the writer thread must own the lock on the writer_mutex, so lock the mutex before
    // setting wait_for_writer_.
    assert(wait_for_writer_.load() == false);
    writer_mutex.lock();
    wait_for_writer_.store(true);

    // Wait for reader locks to be released. reader_count_ is the sum of all read_lock_depth_ values of all threads. To
    // allow this thread to be promoted to a writer lock, wait until reader_count_ equals this thread's
    // read_lock_depth_.
    while (reader_count_.load() != read_lock_depth_.load())
    {
    }
}

void SharedMutex::unlock()
{
    // If wait_for_writer_ is true, the writer thread must own the lock on the writer_mutex, so unlock the mutex first.
    assert(wait_for_writer_.load() == true);
    writer_mutex.unlock();
    wait_for_writer_.store(false);
}

void SharedMutex::lock_shared()
{
    size_t previous_read_lock_depth = IncrementReadCount();

    // If the read lock is being acquired for the first time in this thread's call stack, check if a writer is waiting.
    if ((previous_read_lock_depth == 0) && wait_for_writer_.load())
    {
        DecrementReadCount();

        writer_mutex.lock();

        IncrementReadCount();

        writer_mutex.unlock();
    }
}

void SharedMutex::unlock_shared()
{
    DecrementReadCount();
}

size_t SharedMutex::IncrementReadCount()
{
    // Ensure reader_count_ is always >= read_lock_depth_, so increment reader_count_ before read_lock_depth_.
    size_t rc  = reader_count_.fetch_add(1);
    size_t rld = read_lock_depth_.fetch_add(1);
    assert(rc >= rld);
    return rld;
}

void SharedMutex::DecrementReadCount()
{
    // Ensure reader_count_ is always >= read_lock_depth_, so decrement read_lock_depth_ before reader_count_.
    size_t rld = read_lock_depth_.fetch_sub(1);
    size_t rc  = reader_count_.fetch_sub(1);
    assert(rc >= rld);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
