/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_THREADPOOL_H
#define GFXRECON_UTIL_THREADPOOL_H

#include "util/defines.h"
#include <deque>
#include <functional>
#include <future>
#include <mutex>
#include <thread>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class ThreadPool
{
  public:
    enum class Priority : uint32_t
    {
        High = 0,
        Default,
        NumPriorities
    };

    ThreadPool() = default;

    explicit ThreadPool(size_t num_threads) { start(num_threads); }

    ThreadPool(ThreadPool&& other) noexcept : ThreadPool() { swap(*this, other); }

    ThreadPool(const ThreadPool& other) = delete;

    ~ThreadPool() { join_all(); }

    ThreadPool& operator=(ThreadPool other)
    {
        swap(*this, other);
        return *this;
    }

    /**
     * @brief   Set the number of worker-threads
     * @param   num     the desired number of threads
     */
    void set_num_threads(size_t num)
    {
        join_all();
        start(num);
    }

    /**
     * @return  the number of worker-threads
     */
    [[nodiscard]] size_t numthreads() const { return threads_.size(); }

    /**
     * @brief   post work to be processed by the ThreadPool
     *
     * @tparam  Func    function template parameter
     * @tparam  Args    template params for optional arguments
     * @param   f       the function object to execute
     * @param   args    optional params to bind to the function object
     * @return  a std::future holding the return value.
     */
    template <Priority prio = Priority::Default, typename Func, typename... Args>
    std::future<typename std::invoke_result<Func, Args...>::type> post(Func&& f, Args&&... args)
    {
        using result_t        = typename std::invoke_result<Func, Args...>::type;
        using packaged_task_t = std::packaged_task<result_t()>;
        auto packed_task =
            std::make_shared<packaged_task_t>(std::bind(std::forward<Func>(f), std::forward<Args>(args)...));
        auto future = packed_task->get_future();

        {
            std::unique_lock<std::mutex> lock(mutex_);
            constexpr uint32_t           queue_index =
                std::min(static_cast<uint32_t>(prio), static_cast<uint32_t>(Priority::Default));
            queues_[queue_index].push_back(std::bind(&packaged_task_t::operator(), packed_task));
        }
        condition_.notify_one();
        return future;
    }

    /**
     * @brief   Manually poll all queued tasks.
     *          useful when this ThreadPool has no threads
     *
     * @return  number of tasks processed.
     */
    std::size_t poll()
    {
        if (!running_ && threads_.empty())
        {
            std::unique_lock<std::mutex> lock(mutex_);
            size_t                       ret = 0;

            for (auto& queue : queues_)
            {
                ret += queue.size();
                while (!queue.empty())
                {
                    auto task = std::move(queue.front());
                    queue.pop_front();
                    if (task)
                    {
                        task();
                    }
                }
            }
            return ret;
        }
        return 0;
    }

    /**
     * @brief   Stop execution and join all threads.
     */
    void join_all()
    {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            running_ = false;
            for (auto& queue : queues_)
            {
                queue.clear();
            }
        }
        condition_.notify_all();

        for (auto& thread : threads_)
        {
            if (thread.joinable())
            {
                thread.join();
            }
        }
        threads_.clear();
    }

    friend void swap(ThreadPool& lhs, ThreadPool& rhs) noexcept
    {
        std::lock(lhs.mutex_, rhs.mutex_);
        std::unique_lock<std::mutex> lock_lhs(lhs.mutex_, std::adopt_lock);
        std::unique_lock<std::mutex> lock_rhs(rhs.mutex_, std::adopt_lock);

        std::swap(lhs.running_, rhs.running_);
        std::swap(lhs.threads_, rhs.threads_);

        for (uint32_t i = 0; i < static_cast<uint32_t>(Priority::NumPriorities); ++i)
        {
            std::swap(lhs.queues_[i], rhs.queues_[i]);
        }
    }

  private:
    using task_t = std::function<void()>;

    void start(size_t num_threads)
    {
        if (num_threads == 0)
        {
            return;
        }

        running_ = true;
        threads_.resize(num_threads);

        auto worker_fn = [this]() noexcept {
            task_t task;

            for (;;)
            {
                {
                    std::unique_lock<std::mutex> lock(mutex_);
                    bool                         all_queues_empty = true;

                    // wait for next task
                    condition_.wait(lock, [this, &all_queues_empty] {
                        for (const auto& queue : queues_)
                        {
                            if (!queue.empty())
                            {
                                all_queues_empty = false;
                                break;
                            }
                        }
                        return !running_ || !all_queues_empty;
                    });

                    // exit worker if requested and nothing is left in queue
                    if (!running_ && all_queues_empty)
                    {
                        return;
                    }

                    // grab task from highest prio, non-empty queue
                    for (auto& queue : queues_)
                    {
                        if (!queue.empty())
                        {
                            task = std::move(queue.front());
                            queue.pop_front();
                            break;
                        }
                    }
                }

                // run task
                if (task)
                {
                    task();
                }
            }
        };
        for (auto& thread : threads_)
        {
            thread = std::thread(worker_fn);
        }
    }

    bool                     running_ = false;
    std::vector<std::thread> threads_;

    std::mutex              mutex_;
    std::condition_variable condition_;
    std::deque<task_t>      queues_[static_cast<uint32_t>(Priority::NumPriorities)];
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_THREADPOOL_H
