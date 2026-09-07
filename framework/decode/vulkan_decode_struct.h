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

// DecodeStruct for every structure whose decoder is a schema field walk -- the declaration.
//
// Callers include this and get a declaration, a small typelist of the structures the walk owns, and nothing else.
// The definition, the schema, the Action and the member-trait partitions live in vulkan_decode_struct_impl.h,
// which exactly one translation unit compiles.
//
// That division is the point. Before it, every translation unit that decoded a Vulkan structure parsed about
// 50,000 lines of schema and member traits, and after full migration that would have been nine of them, four being
// consumers with no business seeing member pointers. It also sets the cost of the next operation family: one
// translation unit rather than one per caller.
//
// A structure the generator has not moved still has its own non-template DecodeStruct prototype and definition. A
// non-template beats a template in overload resolution, so a caller reaches the procedural decoder for those and
// this template for the rest.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H

#include "generated/generated_vulkan_decode_walked_structs.h"
#include "util/defines.h"
#include "util/type_list.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// A wrapper the walk owns, tested against the generated list rather than against the schema. Constraining on the
// schema would mean reaching it, which is what this header exists to avoid; the list says the same thing and costs
// forward declarations the caller already has.
//
// The constraint is for diagnosis, not selection: an unconstrained template would resolve correctly anyway, since
// the non-template overloads win wherever they exist. What it buys is that a wrapper with no instantiation fails
// at the call naming its type, rather than at the link naming a mangled symbol.
template <typename Wrapper>
concept WalkedWrapper = util::TypeListContainsV<WalkedStructs, Wrapper>;

template <WalkedWrapper Wrapper>
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Wrapper* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
