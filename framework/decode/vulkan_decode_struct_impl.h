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

// DecodeStruct for every structure whose decoder is a schema field walk -- the definition.
//
// TARGET-PRIVATE, and more strictly than the member-trait partitions it pulls in: exactly one translation unit
// includes this, the generated instantiation unit. Everything else includes vulkan_decode_struct.h and links
// against what that unit emits.
//
// One hand-written definition, not one generated function for each structure. Nothing here names a structure or a
// field: the schema supplies the field order and the Action decides what each field means.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H

#include "decode/api_element_traits.h"
#include "decode/vulkan_decode_action.h"
#include "decode/vulkan_decode_struct.h"
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
template <WalkedWrapper Wrapper>
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Wrapper* wrapper)
{
    static_assert(HasApiElement<Wrapper>, "A walked wrapper must name an API element");
    static_assert(schema::HasSchema<typename ApiElementFor<Wrapper>::type>,
                  "A walked wrapper's API element must have a schema");

    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    DecodeStructAction action(buffer, buffer_size);

    schema::WalkFields<typename ApiElementFor<Wrapper>::type>(action, *wrapper);

    return action.BytesRead();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
