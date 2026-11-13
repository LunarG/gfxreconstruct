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

// The Vulkan catalog reads the API element inventory, generated/generated_vulkan_inventory.h, back into C++: in
// namespace catalog, a TypeList of API elements per inventory property. Each list is the property read back, so it
// cannot disagree with the inventory; the inventory's banner lists each property. Only structures and unions carry
// properties.
//
// To add a list, write a block like those below: define GFXRECON_INVENTORY_REQUIRE or GFXRECON_INVENTORY_FORBID as
// needed and the visit macros, then BEGIN, the #include, and END. The #include undefines the visit, REQUIRE and FORBID
// macros, so each block starts clean.

#ifndef GFXRECON_BINDING_VULKAN_CATALOG_H
#define GFXRECON_BINDING_VULKAN_CATALOG_H

#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"
#include "util/inventory_utils.h"
#include "util/type_list.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)
GFXRECON_BEGIN_NAMESPACE(vulkan)

GFXRECON_BEGIN_NAMESPACE(catalog)

#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(unions)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// extensible_structures lists every structure with a structure_type; no union has one.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(extensible_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// external_structures lists the structures a platform header defines and the registry only references: each has an
// API element and no Schema.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_EXTERNAL
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(external_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// custom_encode_structures lists the structures whose encoder is hand-written.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_ENCODE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_encode_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// custom_decode_structures lists the structures whose decoder is hand-written.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_DECODE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_decode_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// custom_handle_mapping_structures lists the structures whose unwrap and map bodies are hand-written, or absent.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_HANDLE_MAPPING
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_handle_mapping_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// generic_handle_structures lists the structures with a member the registry marks objecttype: an integer that holds a
// handle whose type a sibling member gives.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_GENERIC_HANDLE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(generic_handle_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// deep_copy_exclusions lists the structures vulkan_struct_deep_copy does not handle.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_DEEP_COPY_EXCLUDED
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(deep_copy_exclusions)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// deep_copyable_structures lists the extensible structures that are not deep-copy exclusions.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE
#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_DEEP_COPY_EXCLUDED
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_elements::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(deep_copyable_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

GFXRECON_END_NAMESPACE(catalog)

GFXRECON_END_NAMESPACE(vulkan)
GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_VULKAN_CATALOG_H
