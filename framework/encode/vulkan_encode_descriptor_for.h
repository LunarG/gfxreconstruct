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

// The native structure to its API type descriptor. Encode's storage is the API's own structure, which cannot carry
// an api_element alias the way a decoded wrapper does, so the inverse of the descriptor's element_type is a trait.
// The rows are generated, one per described structure, in generated/generated_vulkan_encode_descriptor_for.h;
// this header carries the primary template and the row macro.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_DESCRIPTOR_FOR_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_DESCRIPTOR_FOR_H

#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename Struct>
struct DescriptorFor;

template <typename Struct>
concept HasDescriptor = requires
{
    typename DescriptorFor<Struct>::type;
};

#define GFXRECON_VULKAN_DESCRIPTOR_FOR(Struct)          \
    template <>                                         \
    struct DescriptorFor<Struct>                        \
    {                                                   \
        using type = schema::vulkan::api_types::Struct; \
    }

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_DESCRIPTOR_FOR_H
