/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_PNEXT_NODE_H
#define GFXRECON_DECODE_PNEXT_NODE_H

#include "generated/generated_vulkan_stype_util.h"
#include "util/defines.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PNextNode
{
  public:
    PNextNode() {}

    virtual ~PNextNode() {}

    virtual uint32_t GetAttributeMask() const = 0;

    virtual uint64_t GetAddress() const = 0;

    virtual void* GetPointer() = 0;

    virtual const void* GetPointer() const = 0;

    virtual void* GetMetaStructPointer() = 0;

    virtual const void* GetMetaStructPointer() const = 0;

    virtual size_t Decode(const uint8_t* buffer, size_t buffer_size) = 0;
};

//  NOTE:
// This functions as if it were a base class to all DecodedStruct_<SomeStruct>
// As all DecodedStruct_<SomeStruct> are of the form SomeStruct *decoded_value; PNextNode *pNext;
// And since the first element of SomeStruct *must* be the sType, the decoded_value pointer
// can also be treated as a pointer to VkStructureType
struct VulkanMetaStructHeader
{
    VkStructureType* sType;
    PNextNode*       pNext;
};

template <typename T>
const T* GetPNextMetaStruct(const PNextNode* pnext)
{
    while (pnext != nullptr)
    {
        const auto* header = reinterpret_cast<const VulkanMetaStructHeader*>(pnext->GetMetaStructPointer());
        if (*header->sType == gfxrecon::util::GetSType<typename T::struct_type>())
        {
            return reinterpret_cast<const T*>(header);
        }
        pnext = header->pNext;
    }
    return nullptr;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_PNEXT_NODE_H
