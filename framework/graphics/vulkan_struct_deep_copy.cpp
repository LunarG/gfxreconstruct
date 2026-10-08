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

#include "binding/structure_type.h"
#include "generated/generated_vulkan_binding_descriptor_for.h"
#include "generated/generated_vulkan_schema_catalog.h"
#include "graphics/vulkan_struct_deep_copy.h"
#include "schema/structure_type_index.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

size_t vulkan_struct_deep_copy_stype(const void* pNext, uint8_t* out_data)
{
    GFXRECON_ASSERT(pNext != nullptr);
    const auto s_type = reinterpret_cast<const VkBaseInStructure*>(pNext)->sType;

    auto on_find = [pNext, out_data]<schema::HasStructureType Descriptor>() {
        return vulkan_struct_deep_copy(binding::StructureTypeCast<Descriptor>(pNext), 1, out_data);
    };
    auto on_miss = [s_type]() {
        GFXRECON_LOG_WARNING("vulkan_struct_deep_copy_stype: unknown struct-type: %d", s_type);
        return size_t(0);
    };
    using List = schema::vulkan::catalog::deep_copyable_structures;
    return schema::StructureTypeVisit<List>(s_type, on_find, on_miss);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
