/*
** Copyright (c) 2026 LunarG, Inc.
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

// The pNext chain encoder: one entry point over the schema's structure list, in place of a generated switch with a
// case per structure. A node is found by its sType in the StructureTypeIndex and encoded through the EncodeStructPtr
// its descriptor names; an unrecognized node is reported and skipped, and the hop past it is probed (DF-2).

#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "generated/generated_vulkan_schema_types.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "schema/schema.h"
#include "schema/structure_type_index.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/type_list.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

namespace
{

using Index = schema::StructureTypeIndex<schema::vulkan::catalog::extensible_structures>;

// Encodes the node as the structure its descriptor names, the way the generated case for that structure did.
struct EncodeNode
{
    template <schema::HasStructureType Descriptor>
    void operator()(ParameterEncoder* encoder, const VkBaseInStructure* base) const
    {
        EncodeStructPtr(encoder, reinterpret_cast<const typename Descriptor::element_type*>(base));
    }
};

} // namespace

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pNext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = base->pNext;
    }

    if (base == nullptr)
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
        return;
    }

    if (const auto position = Index::Find(base->sType); position != Index::End())
    {
        util::Visit(position, EncodeNode{}, encoder, base);
        return;
    }

    // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see
    // if it points to a recognized value.
    int32_t                 message_size = std::snprintf(nullptr,
                                         0,
                                         "A pNext value with unrecognized VkStructureType = %d was omitted from the "
                                                         "capture file, which may cause replay to fail.",
                                         base->sType);
    std::unique_ptr<char[]> message      = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
    std::snprintf(message.get(),
                  (message_size + 1),
                  "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may "
                  "cause replay to fail.",
                  base->sType);
    VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
    GFXRECON_LOG_WARNING("%s", message.get());
    EncodePNextStructIfValid(encoder, base->pNext);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
