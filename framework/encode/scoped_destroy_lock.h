/*
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_SCOPED_DESTROY_LOCK_H
#define GFXRECON_ENCODE_SCOPED_DESTROY_LOCK_H

#include "util/defines.h"

#include <shared_mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/*
Regarding ScopedDestroyLock class and its related methods. These are used to address the
following race condition during capture:

Sometimes an app will destroy some Vulkan handles in one thread (A) and create same type of Vulkan handle in another
thread (B). There is a gap of time in between when the real handle is destroyed, and when its wrappers were deleted from
map in thread A. If during this time period, thread B was able to run, and creates same type of handles, and if any of
the newly-created handles had the same value of those destroyed by thread A, we crash.

For example, lets say an app's thread A calls vkFreeCommandBuffers, and in thread B it calls vkAllocateCommandBuffers.

GFXR's default API lock is AcquireSharedApiCallLock(), but if every API handling only request shared lock, that means
there is actually no lock for them. Therefore execution could switch from one thread to another thread. If thread A
calls vkFreeCommandBuffers to free command buffer group GC-X, those real Vulkan handles get destroyed by the driver, and
GFXR will proceed to delete wrapper objects of GC-X from the corresponding map. During this time, thread B was able to
run, and calls vkAllocateCommandBuffers to create a group of command buffers GC-Y. But because GC-X was already
destroyed, the driver may return some of the same former handle values of GC-X, but their wrapper still exists, and
GFXR's insertion of the new wrapper into its map will fail. And thread B will delete the wrapper later, so for any
following process, there would be no wrapper for the real handle which will eventually provoke a crash.

Note: destruction of other things could also potentially have this problem. For example, replace the above
vkFreeCommandBuffers with vkDestroyCommandPool. This call will free all command buffers of the command pool.

Regarding mutex_for_create_destroy_handle_ :

For any create wrapper operation, the operation which delete real Vulkan handle and its wrapper in map must be atomic.
This means a real handle and its wrapper must both exist, or both not exist, for any create wrapper operation.
*/

class ScopedDestroyLock
{
  public:
    ScopedDestroyLock(bool shared = false);

    ~ScopedDestroyLock();

    ScopedDestroyLock(const ScopedDestroyLock&) = delete;

    ScopedDestroyLock(ScopedDestroyLock&&) = delete;

    ScopedDestroyLock& operator=(const ScopedDestroyLock&) = delete;

    ScopedDestroyLock& operator=(ScopedDestroyLock&&) = delete;

  private:
    bool                     lock_shared_ = false;
    static std::shared_mutex mutex_for_create_destroy_handle_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_SCOPED_DESTROY_LOCK_H
