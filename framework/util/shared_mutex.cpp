
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

thread_local std::atomic_bool SharedMutex::has_read_lock_{ false };

void SharedMutex::lock()
{
    writer_mutex.lock();

    // Indicate to readers the writer is waiting.
    wait_for_writer_.store(true);

    // Wait for readers.
    while (reader_count_.load() > (has_read_lock_.load() ? 1u : 0u))
    {
    }
}

void SharedMutex::unlock()
{
    writer_mutex.unlock();
    wait_for_writer_.store(false);
}

void SharedMutex::lock_shared()
{
    reader_count_.fetch_add(1);
    has_read_lock_.store(true);

    if (wait_for_writer_.load())
    {
        has_read_lock_.store(false);
        reader_count_.fetch_sub(1);

        writer_mutex.lock();

        reader_count_.fetch_add(1);
        has_read_lock_.store(true);

        writer_mutex.unlock();
    }
}

void SharedMutex::unlock_shared()
{
    reader_count_.fetch_sub(1);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
