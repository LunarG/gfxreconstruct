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

// DecodeStruct for every structure whose decoder is a schema field walk.
//
// One hand-written definition, not one generated function for each structure. Nothing here names a structure or a
// field: the schema supplies the field order and the Action decides what each field means.
//
// A structure the generator has not moved still has its own non-template DecodeStruct prototype and definition. A
// non-template beats a template in overload resolution, so a caller reaches the procedural decoder for those and
// this template for the rest, with no list of migrated structures anywhere in C++. Which structures have moved is
// decided entirely by which ones the generators skip.
//
// This header is target-private. It is included by the translation units that decode Vulkan structures and by
// nothing else, which is what keeps the member-trait partitions out of every other decode translation unit. The
// partitions themselves are included by vulkan_decode_action.h, where the overloads they constrain are declared.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H

#include "decode/api_element_traits.h"
#include "decode/vulkan_decode_action.h"
#include "generated/generated_vulkan_schema.h"
#include "schema/schema_util.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// A decoded wrapper this operation can walk: one that names an API element, where that element has a schema.
//
// The Action's own coverage is deliberately not part of this. A structure whose fields the Action cannot handle
// fails inside WalkFields with a static_assert naming the field, which is a better diagnostic than an unsatisfied
// constraint that only says the overload was not viable.
template <typename Wrapper>
concept WalkableWrapper = HasApiElement<Wrapper> && schema::HasSchema<typename ApiElementFor<Wrapper>::type>;

template <typename Wrapper>
requires WalkableWrapper<Wrapper> size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Wrapper* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    DecodeStructAction action(buffer, buffer_size);

    schema::WalkFields<typename ApiElementFor<Wrapper>::type>(action, *wrapper);

    return action.BytesRead();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
