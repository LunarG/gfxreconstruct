/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

#include "generated/generated_vulkan_schema_catalog.h"
#include "graphics/vulkan_struct_deep_copy.h"
#include "schema/structure_type_index.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

inline uint8_t* offset_ptr(uint8_t* ptr, uint64_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

size_t vulkan_struct_deep_copy_stype(const void* pNext, uint8_t* out_data)
{

    uint64_t offset = 0;
    GFXRECON_ASSERT(pNext != nullptr);
    auto     base    = reinterpret_cast<const VkBaseInStructure*>(pNext);
    uint8_t* out_ptr = offset_ptr(out_data, offset);

    using DeepCopyIndex = schema::StructureTypeIndex<schema::vulkan::catalog::deep_copyable_structures>;
    if (const auto position = DeepCopyIndex::Find(base->sType); position != DeepCopyIndex::End())
    {
        auto visitor = [&offset, pNext, out_ptr]<schema::HasStructureType Descriptor>() {
            offset +=
                vulkan_struct_deep_copy(reinterpret_cast<const typename Descriptor::element_type*>(pNext), 1, out_ptr);
        };
        util::Visit(position, visitor);
    }
    else
    {
        GFXRECON_LOG_WARNING("vulkan_struct_deep_copy_stype: unknown struct-type: %d", base->sType);
    }
    return offset;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
