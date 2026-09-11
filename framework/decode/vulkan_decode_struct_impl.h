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

// DecodeStruct for every structure the schema drives -- the definition.
//
// PRIVATE. One translation unit includes this: generated_vulkan_struct_decoders.cpp, where the procedural bodies
// it replaces already live. Everything else sees the declaration in generated_vulkan_struct_decoders_forward.h and
// links against the instantiations that unit emits, reaching no schema. A caller parses 3,173 lines instead of
// 91,619, and the next operation family costs one translation unit rather than one per caller.
//
// It is a header only because that .cpp is generated. This is the one piece of the arrangement that must stay
// hand-written -- it names no structure and no field, which is the property the whole thing exists to have -- and
// hand-written logic inside a generated file means a Python string, which is what write_base_out_struct_decoder
// looks like. Were the .cpp hand-written, this would be a function in it and this header would not exist.
//
// Everything generated that the body touches is a dependent name -- the descriptors, the Schema specializations,
// the ApiElementFor specializations and both member-trait partitions are needed to instantiate, not to parse. So
// this header could be light. It is not, because two headers it includes deliberately carry their generated
// content: api_element_traits.h pulls the specializations so its concepts cannot silently answer no, and
// vulkan_decode_action.h pulls the member partitions so its overloads cannot re-resolve on a partial set. Both
// guards exist for other includers, not for this one.
//
// That costs nothing here, since the only translation unit that includes this is the one that instantiates, and
// instantiation needs the content regardless. It would matter if the definition ever had to parse without the
// generated schema -- compiling the walk against a stub, say -- and at that point splitting each facade into
// primaries and specializations is two lines rather than a redesign.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H

#include "decode/api_element_traits.h"
#include "decode/vulkan_decode_action.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "generated/generated_vulkan_schema.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// The declaration constrains on the generated list; this asserts the list agrees with the schema. A structure named
// there whose element has no schema fails here rather than inside WalkFields.
template <SchemaDriven Wrapper>
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Wrapper* wrapper)
{
    static_assert(HasApiElement<Wrapper>, "A schema-driven wrapper must name an API element");
    static_assert(schema::HasSchema<typename ApiElementFor<Wrapper>::type>,
                  "A schema-driven wrapper's API element must have a schema");

    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    DecodeStructAction action(buffer, buffer_size);

    schema::WalkFields<typename ApiElementFor<Wrapper>::type>(action, *wrapper);

    return action.BytesRead();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
