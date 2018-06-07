/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_FORMAT_PNEXT_TYPED_NODE_H
#define BRIMSTONE_FORMAT_PNEXT_TYPED_NODE_H

#include <cassert>
#include <memory>

#include "util/defines.h"
#include "format/format.h"
#include "format/struct_pointer_decoder.h"

// TODO: Need to generate a header with the 'decode_struct' function declarations to include here.

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

template <typename T>
class PNextTypedNode : public PNextNode
{
public:
    PNextTypedNode() { }

    ~PNextTypedNode() { }

    virtual uint32_t GetAttributeMask() const override { return struct_pointer_.GetAttributeMask(); }

    virtual uint64_t GetAddress() const override { return struct_pointer_.GetAddress(); }

    virtual void* GetPointer() const override { return struct_pointer_.GetPointer(); }

    virtual size_t Decode(const uint8_t* buffer, size_t buffer_size) override { return struct_pointer_.Decode<decode_struct>(buffer, buffer_size); }

private:
    StructPointerDecoder<T> struct_pointer_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_PNEXT_TYPED_NODE_H
