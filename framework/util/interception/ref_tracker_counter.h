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

#ifndef GFXRECON_INTERCEPTION_UTILS_REF_TRACKER_COUNTER_H
#define GFXRECON_INTERCEPTION_UTILS_REF_TRACKER_COUNTER_H

#include "util/defines.h"

#include <mutex>
#include <map>
#include <Windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

//-----------------------------------------------------------------------------
/// This class helps detect re-entrance problems.
//-----------------------------------------------------------------------------
class RefTrackerCounter
{
  public:
    RefTrackerCounter();
    ~RefTrackerCounter();

    RefTrackerCounter(std::mutex* pM);
    void UseExternalMutex(std::mutex* pM);

    void Increment();
    void Decrement();

    void operator++();
    void operator--();
    void operator++(int);
    void operator--(int);
    bool operator==(UINT32 v);
    bool operator>(UINT32 v);

    UINT32 GetRef();

  private:
    /// If using an external mutex (by using the constructor passing in a mutex or calling UseExternalMutex())
    bool is_using_external_mutex_;

    /// Pointer to a mutex to ensure the reference counter is only updated by one thread at a time
    std::mutex* mutex_;

    /// Map of reference count and thread ID.
    std::map<UINT32, int> map_inside_wrapper_;
};

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INTERCEPTION_UTILS_REF_TRACKER_COUNTER_H
