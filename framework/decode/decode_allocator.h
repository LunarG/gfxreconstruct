
/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DECODE_ALLOCATOR_H
#define GFXRECON_DECODE_DECODE_ALLOCATOR_H

#include "util/defines.h"
#include "util/monotonic_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DecodeAllocator
{
  public:
    // Begin must be called before any calls to Allocate (either initially or since End was called). This ensures
    // allocations are not made outside the intended scope. Also creates the allocator instance if it is nullptr.
    static void Begin();

    template <typename T>
    static T* Allocate(size_t count = 1, bool initialize = true)
    {
        assert((instance_ != nullptr) && instance_->can_allocate_);
        return instance_->can_allocate_ ? instance_->allocator_.Allocate<T>(count, initialize) : nullptr;
    }

    // End must be called to release any allocations made since last call to Begin. Currently allocated system memory
    // is re-used for future allocations.
    static void End();

    // Free system memory blocks. Must not be called between Begin and End
    static void FreeSystemMemory();

    // Destroy the allocator instance. This will also frees all allocated memory.
    static void DestroyInstance();

  private:
    DecodeAllocator() : allocator_(kAllocatorBlockSize), can_allocate_(false) {}

  private:
    static const size_t     kAllocatorBlockSize{ 64 * 1024 };
    static DecodeAllocator* instance_;

    util::MonotonicAllocator allocator_;
    bool                     can_allocate_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DECODE_ALLOCATOR_H
