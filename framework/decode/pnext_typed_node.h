/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_PNEXT_TYPED_NODE_H
#define GFXRECON_DECODE_PNEXT_TYPED_NODE_H

#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class PNextTypedNode : public PNextNode
{
  public:
    PNextTypedNode() {}

    virtual ~PNextTypedNode() override {}

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

#endif // GFXRECON_DECODE_PNEXT_TYPED_NODE_H
