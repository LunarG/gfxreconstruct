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

// Generic EncodeStruct definition. PRIVATE: generated_vulkan_struct_encoders.cpp is the one translation unit that
// includes it and instantiates the walk. Callers see the declaration in encode/vulkan_encode_struct.h, beside the
// prototypes of the structures that keep a generated body, and a call by structure type resolves as it always did.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H

#include "encode/vulkan_encode_action.h"
#include "encode/vulkan_encode_struct.h"
#include "generated/generated_vulkan_encode_capture_wrappers.h"
#include "generated/generated_vulkan_schema.h"
#include "generated/generated_vulkan_schema_binding_descriptor_for.h"
#include "schema/binding/descriptor_for.h"
#include "schema/schema.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// The assertion is the only gate: a structure with no descriptor fails here, naming the structure, rather than inside
// WalkFields.
template <typename Struct>
void EncodeStruct(ParameterEncoder* encoder, const Struct& value)
{
    static_assert(schema::binding::HasDescriptor<Struct>,
                  "A schema-driven structure must name its API type descriptor");
    using ApiElement = typename schema::binding::DescriptorFor<Struct>::type;
    static_assert(schema::HasSchema<ApiElement>, "A schema-driven structure's API element must have a schema");

    EncodeStructAction action(encoder);
    schema::WalkFields<ApiElement>(action, value);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_IMPL_H
