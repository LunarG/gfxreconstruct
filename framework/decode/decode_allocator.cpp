
/*
** Copyright (c) 2022 LunarG, Inc.
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

#include "decode/decode_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DecodeAllocator* DecodeAllocator::instance_{ nullptr };

void DecodeAllocator::Begin()
{
    if (instance_ == nullptr)
    {
        instance_ = new DecodeAllocator();
    }
    assert(!instance_->can_allocate_);
    instance_->can_allocate_ = true;
}

void DecodeAllocator::End()
{
    assert((instance_ != nullptr) && instance_->can_allocate_);
    if (instance_->end_can_clear_)
    {
        instance_->allocator_.Clear(false);
    }
    instance_->can_allocate_ = false;
}

void DecodeAllocator::TurnOnEndCanClear()
{
    instance_->end_can_clear_ = true;
}

void DecodeAllocator::TurnOffEndCanClear()
{
    instance_->end_can_clear_ = false;
}

void DecodeAllocator::FreeSystemMemory()
{
    assert((instance_ != nullptr) && !instance_->can_allocate_);
    instance_->allocator_.Clear(true);
}

void DecodeAllocator::DestroyInstance()
{
    delete instance_;
    instance_ = nullptr;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
