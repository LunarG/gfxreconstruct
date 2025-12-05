/*
** Copyright (c) 2025 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
**
* copy of this software and associated documentation files (the "Software"),
** to deal in the Software without
* restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute,
* sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do
* so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be
* included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
* WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
* FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "util/heap_buffer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Grow the capacity of the HeapBuffer without attempting to preserve the current contents
void HeapBuffer::ReserveDiscarding(size_t capacity)
{
    if (capacity && (capacity > capacity_))
    {
        store_    = Store(new DataType[capacity]);
        capacity_ = capacity;
    }
}

// Grow the capacity of the HeapBuffer while conserving the current contents
void HeapBuffer::ReservePreserving(size_t new_capacity)
{
    if (IsEmpty())
    {
        ReserveDiscarding(new_capacity);
    }
    else if (new_capacity > capacity_)
    {
        HeapBuffer destination(new_capacity);
        std::memcpy(destination.Get(), Get(), capacity_);
        *this = std::move(destination);
    }
}

void HeapBuffer::Reset()
{
    store_.reset();
    capacity_ = 0;
}

HeapBufferPool::Entry::~Entry() noexcept
{
    Reset();
}

void HeapBufferPool::Entry::Reset() noexcept
{
    // Return to pool_ if not reset
    if (pool_)
    {
        pool_->Release(std::move(*this));
    }
}

HeapBufferPool::Entry::Entry(Entry&& other) noexcept : Base(std::move(other))
{
    pool_       = other.pool_;
    other.pool_ = nullptr;
}

HeapBufferPool::Entry& HeapBufferPool::Entry::operator=(Entry&& other) noexcept
{
    if (this == &other)
        return *this;

    if (pool_)
    {
        pool_->Release(std::move(*this));
        GFXRECON_ASSERT(pool_ == nullptr);
    }

    Base::operator=(std::move(other));
    pool_       = other.pool_;
    other.pool_ = nullptr;

    return *this;
}

HeapBufferPool::Entry HeapBufferPool::Acquire(size_t size)
{
    if (!store_.empty())
    {
        Entry entry = std::move(store_.front());
        store_.pop_front();
        entry.ReserveDiscarding(size); // Realloc will only grow the buffer

        acquired_++;
        return entry;
    }
    acquired_++;
    return Entry(this, size);
}

void HeapBufferPool::Reset() noexcept
{
    // Doesn't remove any acquired buffers, just clears the pool
    // Disavow all entries in the pool so they don't try to return themselve to a pool that is being reset
    for (auto& entry : store_)
    {
        entry.DisavowPool();
    }
    store_.clear();
}

HeapBufferPool::~HeapBufferPool()
{
    if (acquired_ != 0)
    {
        GFXRECON_LOG_ERROR("Deleted HeapBufferPool without releasing all Acquired entries. Outstanding count = %zu.",
                           acquired_);
        GFXRECON_ASSERT(acquired_ == 0);
    }
    Reset();
}

void HeapBufferPool::Release(Entry&& entry) noexcept
{
    GFXRECON_ASSERT(acquired_ > 0);
    acquired_--;

    // No point in storing empty buffers
    if (!entry.IsEmpty() && (store_.size() < max_entries_))
    {
        // NOTE: Might not want to hang onto *giant* buffers... or add a full pow2 bucket set
        try
        {
            store_.push_back(std::move(entry));
        }
        catch (...)
        {
            // This is only from ~Entry so we don't have to worry about cleaning up entry
        }
    }
    else
    {
        // Mark the entry as released, even if we don't take its contents back into the pool
        entry.DisavowPool();
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
