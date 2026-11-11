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

// This header declares the explicit specializations of util/to_string.h's ToString primaries for every Vulkan enum,
// plus a VkFlags form per flag-bits enum, as an inventory visitor. They are defined over the enumerant tables in
// generated/generated_vulkan_enum_to_string.cpp. Specializations, not overloads: a specialization is found wherever
// the primary is, by the generic formatters in util/to_string.h too, and an overload would not be. Callers include
// only this header; the tables stay in the .cpp.

#ifndef GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H
#define GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H

#include "format/platform_types.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// The two templates below are keyed on the API element, for the 64-bit flag-bits and mask types: C spells them
// VkFlags64, which cannot key an explicit specialization. They are explicitly instantiated in
// generated/generated_vulkan_enum_to_string.cpp. A call for an API element missing from that instantiation list is a
// link error (unresolved external), not a compile error.

// Returns the name of one enumerant of Element.
template <schema::EnumApiElement Element>
std::string ToString(typename Element::element_type value,
                     ToStringFlags                  toStringFlags = kToString_Default,
                     uint32_t                       tabCount      = kToStringDefaultTabCount,
                     uint32_t                       tabSize       = kToStringDefaultTabSize);

// Returns the set bits of a mask of Element, by name.
template <schema::BitmaskApiElement Element>
std::string ToString(VkFlags64     flags,
                     ToStringFlags toStringFlags = kToString_Default,
                     uint32_t      tabCount      = kToStringDefaultTabCount,
                     uint32_t      tabSize       = kToStringDefaultTabSize);

#define GFXRECON_INVENTORY_VISIT_ENUM(Enum) \
    template <>                             \
    std::string ToString<Enum>(const Enum& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
#define GFXRECON_INVENTORY_VISIT_FLAG_BITS(Enum) \
    GFXRECON_INVENTORY_VISIT_ENUM(Enum)          \
    template <>                                  \
    std::string ToString<Enum>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
#include "generated/generated_vulkan_inventory.h"

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_VULKAN_ENUM_TO_STRING_H
