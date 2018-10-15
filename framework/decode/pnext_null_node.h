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

#ifndef BRIMSTONE_DECODE_PNEXT_NULL_NODE_H
#define BRIMSTONE_DECODE_PNEXT_NULL_NODE_H

#include <cassert>
#include <memory>

#include "util/defines.h"
#include "format/format.h"
#include "decode/pnext_node.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

class PNextNullNode : public PNextNode
{
  public:
    PNextNullNode() {}

    virtual ~PNextNullNode() {}

    virtual uint32_t GetAttributeMask() const
    {
        return (format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsSingle |
                format::PointerAttributes::kIsNull);
    }

    virtual uint64_t GetAddress() const { return 0; }

    virtual void* GetPointer() const { return nullptr; }

    virtual size_t Decode(const uint8_t*, size_t) { return 0; };
};

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_PNEXT_NULL_NODE_H
