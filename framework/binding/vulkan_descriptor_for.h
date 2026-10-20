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

// The Vulkan DescriptorFor rows, a visitor invoked across the inventory: every structure, every union and every native
// enum to its API type descriptor. A 64-bit flag-bits type is spelled VkFlags64, so it has no row; one would bind the
// bare integer type.

#ifndef GFXRECON_BINDING_VULKAN_DESCRIPTOR_FOR_H
#define GFXRECON_BINDING_VULKAN_DESCRIPTOR_FOR_H

#include "binding/descriptor_for.h"
#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"
#include "util/inventory_utils.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// A struct visitor: it yields a specialization, a type, so this lives in a header.
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) \
    GFXRECON_INVENTORY_DESCRIPTOR_FOR(::Name, schema::vulkan::api_types::Name);
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
#define GFXRECON_INVENTORY_VISIT_ENUM(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
#define GFXRECON_INVENTORY_VISIT_FLAG_BITS(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
#include "generated/generated_vulkan_inventory.h"

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_VULKAN_DESCRIPTOR_FOR_H
