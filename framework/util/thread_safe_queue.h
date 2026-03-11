
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

#include <concepts>
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <mutex>
#include <new>
#include <optional>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Lots of details not to pollute the util namespace with so
GFXRECON_BEGIN_NAMESPACE(thread_safe_queue_detail)
// Queue implmentation base class
//
// There is no producer side throttling or queue size limitation.
// A `size() method is intentionally non supported as it will either be inacurate or non performant
//
// Further details in each derived Queue below.
template <typename T>
class QueueBase
{
  public:
    using value_type = T;
    using pop_type   = std::optional<value_type>;

    bool live() const
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
            mp_queue_.emplace_back(std::forward<Args>(args)...);
        }
        cv_.notify_one();
        return true;
    }

  protected:
    using QueueStore = std::deque<value_type>;
    static pop_type pop_queue(QueueStore& queue)
    {
        if (queue.empty())
        {
            return std::nullopt;
        }

        value_type value = std::move(queue.front());
        queue.pop_front();
        return value;
    }

    // Align these access control elements together to assure only a single
    // Cacheline invalidation on locked operations
    alignas(kConstructiveAlign) mutable std::mutex mutex_;
    std::condition_variable cv_;
    QueueStore              mp_queue_;     // Only accessed under the mutex
    bool                    live_{ true }; // Only accessed under the mutex
};

// The is a multi-producer/multi-consumer safe queue.
//
// Any number of threads may read or write safely.
// empty() likely not high performing as it is locking
// For non blocking access, use `try_pop()`
// NOTE: Using `if !empty then pop`, is slower, and may still block with multiple consumers.
template <typename T>
class QueueMPMC : public QueueBase<T>
{
  public:
    using Base     = QueueBase<T>;
    using pop_type = typename Base::pop_type;

    bool empty()
    {
        std::lock_guard<std::mutex> lock(this->mutex_);
        return this->mp_queue_.empty();
    }

    pop_type pop()
    {
        std::unique_lock<std::mutex> lock(this->mutex_);
        this->cv_.wait(lock, [this] { return !this->mp_queue_.empty() || !this->live_; });

        // After waiting, we hold the mutex, and either the queue is not empty, or the queue is not live.
        // Note: Must only be called on mp_queue_ while holding mutex_
        return Base::pop_queue(this->mp_queue_);
    }

    // Returns std::nullopt if the queue is empty, otherwise pops and returns the front value. Does not block.
    pop_type try_pop()
    {
        std::lock_guard<std::mutex> lock(this->mutex_);
        // Note: Must only be called on mp_queue_ while holding mutex_
        return Base::pop_queue(this->mp_queue_);
    }
};

// This is a *single-consumer*, double-buffer queue.
//
// NOTE: If more than one consumer is used, external synchronization is required.
//
// The queue adds a non-locked, single-consumer queue (`sc_queue_`) that is accessible only by the
// consumer thread. When `sc_queue_` is empty, it is swapped with the producer's queue under a lock.
// During blocking operations (such as `pop()`) the swap operation will wait until the producer queue
// (`mp_queue_`) is non-empty or the queue is closed.
//
// `empty()` is performant when there is content in `sc_queue_` and implicitly swaps (non-waiting) with
// the producer queue if empty.
template <typename T>
class QueueMPSC : public QueueBase<T>
{
  public:
    using Base     = QueueBase<T>;
    using pop_type = typename Base::pop_type;

    struct WaitingOperation
    {};
    struct NonWaitingOperation
    {};

    pop_type pop() { return common_pop<WaitingOperation>(); }

    // Returns std::nullopt if the queue is empty, otherwise pops and returns the front value. Does not block.
    pop_type try_pop() { return common_pop<NonWaitingOperation>(); }

    bool empty()
    {
        if (!sc_queue_.empty())
        {
            return false;
        }
        swap_queues<NonWaitingOperation>();
        return sc_queue_.empty();
    }

  private:
    template <typename WaitingTrait>
    pop_type common_pop()
    {
        if (sc_queue_.empty())
        {
            swap_queues<WaitingTrait>();
        }
        return Base::pop_queue(sc_queue_);
    }

    template <typename WaitingTrait>
    void swap_queues()
    {
        GFXRECON_ASSERT(sc_queue_.empty());
        std::unique_lock<std::mutex> lock(this->mutex_);
        if constexpr (std::is_same_v<WaitingTrait, WaitingOperation>)
        {
            if (this->mp_queue_.empty())
            {
                this->cv_.wait(lock, [this] { return !this->mp_queue_.empty() || !this->live_; });
            }
            std::swap(this->mp_queue_, sc_queue_);
        }
        else if (!this->mp_queue_.empty())
        {
            std::swap(this->mp_queue_, sc_queue_);
        }
    }

    // Align the consumer side store to not share a cacheline with producer side
    // mutex controlled elements in Base
    alignas(util::kDestructiveAlign) typename Base::QueueStore sc_queue_;
};

GFXRECON_END_NAMESPACE(thread_safe_queue_detail)

// A thread safe queue with blocking and non-blocking pop operations. The queue is unbounded
template <typename T, bool SingleConsumer>
class ThreadSafeQueue
{
  public:
    ThreadSafeQueue()                                  = default;
    ThreadSafeQueue(const ThreadSafeQueue&)            = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    constexpr static bool kSingleConsumer = SingleConsumer;

    using Queue = std::
        conditional_t<kSingleConsumer, thread_safe_queue_detail::QueueMPSC<T>, thread_safe_queue_detail::QueueMPMC<T>>;
    using value_type = typename Queue::value_type;
    using pop_type   = typename Queue::pop_type;

    bool empty() { return queue_.empty(); }
    bool live() const { return queue_.live(); }
    void close() { queue_.close(); }

    template <typename... Args>
    requires std::constructible_from<value_type, Args&&...>
    bool emplace(Args&&... args) { return queue_.emplace(std::forward<Args>(args)...); }

    template <typename U>
    requires std::constructible_from<value_type, U&&>
    bool push(U&& value) { return queue_.emplace(std::forward<U>(value)); }

    pop_type pop() { return queue_.pop(); }

    // Returns std::nullopt if the queue is empty, otherwise pops and returns the front value. Does not block.
    pop_type try_pop() { return queue_.try_pop(); }

  private:
    Queue queue_; // Hides the details of MPMC and MPSC implemenations
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif /* GFXRECON_UTIL_THREAD_SAFE_QUEUE_H */
