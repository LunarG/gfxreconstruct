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
#include "util/alignment_utils.h"

#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Grow the capacity of the HeapBuffer without attempting to preserve the current contents
void HeapBuffer::ReserveDiscarding(size_t capacity)
{
    if (capacity && (capacity > capacity_))
    {
        capacity  = util::next_pow_2(capacity);
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

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
