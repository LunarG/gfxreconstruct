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

// The Vulkan catalog: the inventory read back into C++. The inventory carries back-end facts as row properties, so
// anything that reads it is binding, registry-derived lists included; the inventory's banner says which property
// is which. Each list and the trait is a visitor invoked across the inventory, so it is a property read back and
// cannot disagree with it. The checks file asserts each list's size against the generator's count.

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

// A list visitor: it yields one TypeList entry, a type, so this lives in a header.

// The structures and unions from which a handle is reachable through the fields: a handle member, an extension
// chain, which may carry anything, or a member that reaches one. The generator computes it from the member list,
// the same facts the Fields are generated from, and the MAY_REACH_HANDLES property is the only place it is stated.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_MAY_REACH_HANDLES
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(may_reach_handles_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// Every structure descriptor.
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// Every union descriptor.
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(unions)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures a pNext chain can hold: every descriptor with a structure_type. No union has one.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(extensible_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures a platform header defines and the registry only references: a descriptor and no Schema.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_EXTERNAL
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(external_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures whose encoder is hand-written.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_ENCODE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_encode_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures whose decoder is hand-written.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_DECODE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_decode_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures whose unwrap and map bodies are hand-written, or absent.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_CUSTOM_HANDLE_MAPPING
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(custom_handle_mapping_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures with a runtime-typed handle member: an integer whose sibling object type names the handle type.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_GENERIC_HANDLE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(generic_handle_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// The structures vulkan_struct_deep_copy does not handle: structures-deep-copy in the blacklists file.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_DEEP_COPY_EXCLUDED
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(deep_copy_exclusions)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

// What vulkan_struct_deep_copy_stype dispatches over: the extensible structures less the exclusions.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE
#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_DEEP_COPY_EXCLUDED
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) GFXRECON_INVENTORY_TYPE_LIST_ENTRY(schema::vulkan::api_types::Name)
GFXRECON_INVENTORY_TYPE_LIST_BEGIN(deep_copyable_structures)
#include "generated/generated_vulkan_inventory.h"
GFXRECON_INVENTORY_TYPE_LIST_END

GFXRECON_END_NAMESPACE(catalog)

// Membership, as a predicate on a descriptor: one base-class lookup each.
template <typename Descriptor>
inline constexpr bool MayReachHandles = util::TypeListContainsV<catalog::may_reach_handles_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool IsExternal = util::TypeListContainsV<catalog::external_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool IsCustomEncode = util::TypeListContainsV<catalog::custom_encode_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool IsCustomDecode = util::TypeListContainsV<catalog::custom_decode_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool IsCustomHandleMapping =
    util::TypeListContainsV<catalog::custom_handle_mapping_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool HasGenericHandle = util::TypeListContainsV<catalog::generic_handle_structures, Descriptor>;

template <typename Descriptor>
inline constexpr bool IsDeepCopyExcluded = util::TypeListContainsV<catalog::deep_copy_exclusions, Descriptor>;

GFXRECON_END_NAMESPACE(vulkan)
GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_VULKAN_CATALOG_H
