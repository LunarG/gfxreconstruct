/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_NEXT_TYPED_NODE_H
#define GFXRECON_DECODE_OPENXR_NEXT_TYPED_NODE_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class OpenXrNextTypedNode : public OpenXrNextNode
{
  public:
    OpenXrNextTypedNode() {}

    virtual ~OpenXrNextTypedNode() override {}

    virtual uint32_t GetAttributeMask() const override { return struct_pointer_.GetAttributeMask(); }

    virtual uint64_t GetAddress() const override { return struct_pointer_.GetAddress(); }

    virtual void* GetPointer() override { return struct_pointer_.GetPointer(); }

    virtual const void* GetPointer() const override { return struct_pointer_.GetPointer(); }

    virtual void* GetMetaStructPointer() override { return struct_pointer_.GetMetaStructPointer(); }

    virtual const void* GetMetaStructPointer() const override { return struct_pointer_.GetMetaStructPointer(); }

    virtual size_t Decode(const uint8_t* buffer, size_t buffer_size) override
    {
        return struct_pointer_.Decode(buffer, buffer_size);
    }

  private:
    StructPointerDecoder<T> struct_pointer_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_NEXT_TYPED_NODE_H
