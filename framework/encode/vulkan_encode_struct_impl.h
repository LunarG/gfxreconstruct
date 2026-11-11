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

// This header defines EncodeStruct. Only a translation unit that instantiates it includes this header:
// encode/vulkan_struct_encoders.cpp, with the explicit instantiations. A translation unit that only calls EncodeStruct
// includes encode/vulkan_encode_struct.h and links to those instantiations.
//
// NOTE: in a translation unit that sees only the declaration, a call on a structure missing from those instantiations
// is a link error (unresolved external), not a compile error.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H

#include "encode/vulkan_encode_action.h"
#include "encode/vulkan_encode_struct.h"
#include "encode/vulkan_encode_capture_wrappers.h"
#include "generated/generated_vulkan_schema.h"
#include "binding/vulkan_api_element_of.h"
#include "schema/schema.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename Struct>
void EncodeStruct(ParameterEncoder* encoder, const Struct& value)
{
    static_assert(binding::ApiTypeWithApiElement<Struct>, "A schema-driven structure must declare api_element");
    using ApiElement = typename binding::ApiElementOf<Struct>::type;
    static_assert(schema::HasSchemaFields<ApiElement>, "A schema-driven structure's API element must have a schema");

    EncodeStructAction action(encoder);
    schema::WalkFields<ApiElement>(action, value);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
