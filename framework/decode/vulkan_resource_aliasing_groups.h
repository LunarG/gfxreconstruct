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

#ifndef GFXRECON_DECODE_VULKAN_RESOURCE_ALIASING_GROUPS_H
#define GFXRECON_DECODE_VULKAN_RESOURCE_ALIASING_GROUPS_H

#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"

#include <iterator>
#include <variant>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief   The create-info of one aliasing group member, decoded.
 *
 * The alternative held is the member's resource type, so the two cannot disagree.
 */
using ResourceAliasingCreateInfo = std::variant<StructPointerDecoder<Decoded_VkBufferCreateInfo>,
                                                StructPointerDecoder<Decoded_VkImageCreateInfo>,
                                                StructPointerDecoder<Decoded_VkTensorCreateInfoARM>>;

/// The resource type of each ResourceAliasingCreateInfo alternative, in alternative order.
inline constexpr format::ResourceAliasingResourceType kResourceAliasingAlternativeTypes[]{
    format::ResourceAliasingResourceType::kBuffer,
    format::ResourceAliasingResourceType::kImage,
    format::ResourceAliasingResourceType::kTensor,
};

static_assert(std::variant_size_v<ResourceAliasingCreateInfo> == std::size(kResourceAliasingAlternativeTypes),
              "every ResourceAliasingCreateInfo alternative needs a resource type");

/**
 * @brief   The name of a resource type, for human-readable output.
 *
 * @param   type  the resource type to name.
 * @return  the name, or "unknown" for a type this build does not know.
 */
inline const char* ResourceAliasingResourceTypeToString(format::ResourceAliasingResourceType type)
{
    switch (type)
    {
        case format::ResourceAliasingResourceType::kBuffer:
            return "buffer";
        case format::ResourceAliasingResourceType::kImage:
            return "image";
        case format::ResourceAliasingResourceType::kTensor:
            return "tensor";
        default:
            return "unknown";
    }
}

/**
 * @brief   One resource of an aliasing group, as read from a resource aliasing groups meta-data block.
 */
struct ResourceAliasingMember
{
    format::HandleId           resource_id{ format::kNullHandleId };
    uint64_t                   bind_offset{ 0 };
    ResourceAliasingCreateInfo create_info;

    format::ResourceAliasingResourceType GetResourceType() const
    {
        return kResourceAliasingAlternativeTypes[create_info.index()];
    }
};

/**
 * @brief   A set of resources that alias one another inside one device memory object.
 */
struct ResourceAliasingGroup
{
    format::HandleId                    memory_id{ format::kNullHandleId };
    uint32_t                            group_id{ 0 };
    std::vector<ResourceAliasingMember> members;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_ALIASING_GROUPS_H
