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

// ToString for Vulkan's enumerated types, from their enumerant tables. These overloads are more constrained than the
// primary templates in util/to_string.h, so they are chosen for every Vulkan enum this header binds; OpenXR and other
// APIs keep their own specializations of the primaries.
#ifndef GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H
#define GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H

#include "generated/generated_vulkan_schema_binding_descriptor_for.h"
#include "generated/generated_vulkan_schema_enumerants.h"
#include "generated/generated_vulkan_schema_types.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/enumerants.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <string>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(detail)

template <typename Table>
std::string EnumerantToString(typename EnumerantDescriptorOf<Table>::element_type value)
{
    const std::string_view name = NameIn<Table>(value);
    return name.empty() ? "Unhandled " + std::string(EnumerantDescriptorOf<Table>::name) : std::string(name);
}

// Each set bit by name, in bit order, joined with '|'; zero by the table's name for zero.
template <typename Table, typename Flags>
std::string EnumerantMaskToString(Flags flags)
{
    using Bit = typename EnumerantDescriptorOf<Table>::element_type;
    return BitmaskToString<Bit>(flags, [](Bit bit) { return EnumerantToString<Table>(bit); });
}

GFXRECON_END_NAMESPACE(detail)

// An enum value.
template <HasEnumerantTable Enum>
std::string ToString(const Enum& value,
                     ToStringFlags = kToString_Default,
                     uint32_t      = kToStringDefaultTabCount,
                     uint32_t      = kToStringDefaultTabSize)
{
    return detail::EnumerantToString<EnumerantTableOf<Enum>>(value);
}

// A 32-bit mask. VkFlags carries no type, so the caller names the flag-bits enum:
// ToString<VkImageUsageFlagBits>(usage).
template <HasMaskTable FlagBits>
std::string ToString(VkFlags flags,
                     ToStringFlags = kToString_Default,
                     uint32_t      = kToStringDefaultTabCount,
                     uint32_t      = kToStringDefaultTabSize)
{
    return detail::EnumerantMaskToString<EnumerantTableOf<FlagBits>>(flags);
}

// Keyed on the API type descriptor, for the types spelled as a bare integer in C, which no native type can select:
// the 64-bit flag-bits. One bit or enumerant by its flag-bits descriptor,
// ToString<schema::vulkan::api_types::VkPipelineStageFlagBits2>(stage), and a mask by its flags descriptor,
// ToString<schema::vulkan::api_types::VkPipelineStageFlags2>(stages).
template <schema::HasEnumerants Descriptor>
std::string ToString(typename Descriptor::element_type value,
                     ToStringFlags = kToString_Default,
                     uint32_t      = kToStringDefaultTabCount,
                     uint32_t      = kToStringDefaultTabSize)
{
    return detail::EnumerantToString<typename Descriptor::enumerants>(value);
}

template <schema::HasFlagBits Descriptor>
std::string ToString(VkFlags64 flags,
                     ToStringFlags = kToString_Default,
                     uint32_t      = kToStringDefaultTabCount,
                     uint32_t      = kToStringDefaultTabSize)
{
    return detail::EnumerantMaskToString<typename Descriptor::flag_bits::enumerants>(flags);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H
