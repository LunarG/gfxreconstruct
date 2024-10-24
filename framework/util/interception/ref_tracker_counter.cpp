/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "ref_tracker_counter.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

RefTrackerCounter::RefTrackerCounter()
{
    is_using_external_mutex_ = false;
    mutex_                   = new std::mutex();
}

RefTrackerCounter::~RefTrackerCounter()
{
    if (is_using_external_mutex_ == false)
    {
        GFXRECON_SAFE_DELETE(mutex_);
    }
}

RefTrackerCounter::RefTrackerCounter(std::mutex* pM)
{
    is_using_external_mutex_ = true;

    mutex_ = pM;
}

void RefTrackerCounter::UseExternalMutex(std::mutex* pM)
{
    if (is_using_external_mutex_ == false)
    {
        GFXRECON_SAFE_DELETE(mutex_);
    }

    is_using_external_mutex_ = true;

    mutex_ = pM;
}

void RefTrackerCounter::operator++()
{
    Increment();
}

void RefTrackerCounter::operator--()
{
    Decrement();
}

void RefTrackerCounter::operator++(int)
{
    Increment();
}

void RefTrackerCounter::operator--(int)
{
    Decrement();
}

bool RefTrackerCounter::operator==(UINT32 v)
{
    std::lock_guard<std::mutex> guard(*mutex_);

    UINT32                          thread_id = ::GetCurrentThreadId();
    std::map<UINT32, int>::iterator it        = map_inside_wrapper_.find(thread_id);

    if (it != map_inside_wrapper_.end())
    {
        return it->second == (int)v;
    }

    // not found? then its value is zero
    return (v == 0);
}

bool RefTrackerCounter::operator>(UINT32 v)
{
    std::lock_guard<std::mutex> guard(*mutex_);

    UINT32                          thread_id = ::GetCurrentThreadId();
    std::map<UINT32, int>::iterator it        = map_inside_wrapper_.find(thread_id);

    if (it != map_inside_wrapper_.end())
    {
        return (UINT32)it->second > v;
    }

    return false;
}

UINT32 RefTrackerCounter::GetRef()
{
    std::lock_guard<std::mutex> guard(*mutex_);

    UINT32                          thread_id = ::GetCurrentThreadId();
    std::map<UINT32, int>::iterator it        = map_inside_wrapper_.find(thread_id);

    if (it != map_inside_wrapper_.end())
    {
        return it->second;
    }

    return 0;
}

void RefTrackerCounter::Increment()
{
    std::lock_guard<std::mutex> guard(*mutex_);

    UINT32                          thread_id = ::GetCurrentThreadId();
    std::map<UINT32, int>::iterator it        = map_inside_wrapper_.find(thread_id);

    if (it != map_inside_wrapper_.end())
    {
        it->second++;
    }
    else
    {
        map_inside_wrapper_[thread_id] = 1;
    }
}

void RefTrackerCounter::Decrement()
{
    std::lock_guard<std::mutex> guard(*mutex_);

    UINT32                          thread_id = ::GetCurrentThreadId();
    std::map<UINT32, int>::iterator it        = map_inside_wrapper_.find(thread_id);

    if (it != map_inside_wrapper_.end())
    {
        it->second--;
    }
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
