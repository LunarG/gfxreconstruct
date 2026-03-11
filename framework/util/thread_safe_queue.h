
/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_THREAD_SAFE_QUEUE_H
#define GFXRECON_UTIL_THREAD_SAFE_QUEUE_H

#include "util/defines.h"

#include <atomic>
#include <concepts>
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <mutex>
#include <optional>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// A thread safe queue with blocking and non-blocking pop operations. The queue is unbounded
template <typename T>
class ThreadSafeQueue
{
  public:
    using value_type                                   = T;
    ThreadSafeQueue()                                  = default;
    ThreadSafeQueue(const ThreadSafeQueue&)            = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    // size() and empty() are not guaranteed to be accurate if other threads are modifying the queue,
    // and should be used for informational/heuristic purposes only. Don't use for synchronization control.
    //
    // pop() and try_pop() operations are always accurate and thread-safe.
    std::size_t size() const { return size_.load(std::memory_order_relaxed); }
    bool        empty() const { return size() == 0; }

    bool live()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return live_;
    }

    // Closes the queue
    //
    // After close() returns:
    // * push and emplace operations will fail and return false. (Asserts in debug builds, invalid to push to a closed
    // queue)
    // * unblock any pop operations waiting on empty queue_.
    // * Pop operations will return previously pushed values, or std::nullopt once queue_ is empty, without blocking.
    //
    // Note: The caller must ensure that no threads access the queue after it is destroyed. (typically by stop or join
    // operations)
    //
    void close()
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            live_ = false;
        }
        cv_.notify_all();
    }

    template <typename... Args>
    requires std::constructible_from<value_type, Args&&...>
    bool emplace(Args&&... args)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (!live_)
            {
                GFXRECON_ASSERT(false && "Attempting to push to a closed ThreadSafeQueue");
                return false;
            }

            queue_.emplace_back(std::forward<Args>(args)...);
            size_.fetch_add(1, std::memory_order_relaxed);
        }
        cv_.notify_one();
        return true;
    }

    template <typename U>
    requires std::constructible_from<value_type, U&&>
    bool push(U&& value) { return emplace(std::forward<U>(value)); }

    std::optional<value_type> pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !queue_.empty() || !live_; });

        // After waiting, we hold the mutex, and either the queue is not empty, or the queue is not live.
        return try_pop_locked();
    }

    // Returns std::nullopt if the queue is empty, otherwise pops and returns the front value. Does not block.
    std::optional<value_type> try_pop()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return try_pop_locked();
    }

  private:
    // Note: Must only be called while holding mutex_
    std::optional<value_type> try_pop_locked()
    {
        if (queue_.empty())
        {
            return std::nullopt;
        }

        value_type value = std::move(queue_.front());
        queue_.pop_front();
        size_.fetch_sub(1, std::memory_order_relaxed);
        return value;
    }

    mutable std::mutex       mutex_;
    std::condition_variable  cv_;
    std::deque<value_type>   queue_;        // Only accessed under the mutex
    bool                     live_{ true }; // Only accessed under the mutex
    std::atomic<std::size_t> size_{ 0 };    // Snapshot counter -- allows size() calls without holding the mutex.
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_UTIL_THREAD_SAFE_QUEUE_H */
