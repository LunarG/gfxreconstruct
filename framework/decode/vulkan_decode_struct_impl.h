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

// This header defines DecodeStruct. Only a translation unit that instantiates it includes this header:
// decode/vulkan_struct_decoders.cpp, with the explicit instantiations, and test/test_vulkan_schema.cpp. A translation
// unit that only calls DecodeStruct includes decode/vulkan_decode_struct.h and links to those instantiations.
//
// NOTE: in a translation unit that sees only the declaration, a call on a wrapper missing from those instantiations is
// a link error (unresolved external), not a compile error.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H

#include "binding/vulkan_decoded_type.h"
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

template <binding::DecodedWrapper Wrapper>
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Wrapper* wrapper)
{
    static_assert(schema::HasSchemaFields<typename Wrapper::api_element>,
                  "A schema-driven wrapper's API element must have a schema");

    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    DecodeStructAction action(buffer, buffer_size);

    schema::WalkFields<typename Wrapper::api_element>(action, *wrapper);

    return action.BytesRead();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_IMPL_H
