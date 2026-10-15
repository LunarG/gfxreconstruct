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

// Explicit specializations of util/to_string.h's primaries, one per native enum and one more per flag-bits enum,
// a visitor invoked across the inventory, defined in generated_vulkan_enum_to_string.cpp over the enumerant tables. A
// specialization is found wherever the primary is, by the generic formatters too, which an overload would not be.
// Callers include only this; the tables stay in the .cpp.

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

// Keyed on the API type descriptor, for the types spelled as a bare integer in C: the 64-bit flag-bits types,
// instantiated in generated_vulkan_enum_to_string.cpp.

// Requires a descriptor with an enumerant table: one enumerant to its name.
template <schema::HasEnumerants Descriptor>
std::string ToString(typename Descriptor::element_type value,
                     ToStringFlags                     toStringFlags = kToString_Default,
                     uint32_t                          tabCount      = kToStringDefaultTabCount,
                     uint32_t                          tabSize       = kToStringDefaultTabSize);

// Requires a mask typedef's descriptor: the set bits of a mask, by name.
template <schema::HasBitvalues Descriptor>
std::string ToString(VkFlags64     flags,
                     ToStringFlags toStringFlags = kToString_Default,
                     uint32_t      tabCount      = kToStringDefaultTabCount,
                     uint32_t      tabSize       = kToStringDefaultTabSize);

// A declaration visitor: it yields a declaration, so this lives in a header; the definitions are in the .cpp.
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
