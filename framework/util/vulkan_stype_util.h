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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// The VkStructureType of a Vulkan structure, read from its API type descriptor through the descriptor binding. A
// structure the registry gives no structure type, or one with no descriptor, does not satisfy the constraint.

#ifndef GFXRECON_UTIL_VULKAN_STYPE_UTIL_H
#define GFXRECON_UTIL_VULKAN_STYPE_UTIL_H

#include "generated/generated_vulkan_schema_binding_descriptor_for.h"
#include "schema/binding/descriptor_for.h"
#include "schema/schema.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <schema::binding::HasDescriptor Struct>
requires schema::HasStructureType<typename schema::binding::DescriptorFor<Struct>::type>
constexpr VkStructureType GetSType()
{
    return schema::binding::DescriptorFor<Struct>::type::structure_type;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_VULKAN_STYPE_UTIL_H
