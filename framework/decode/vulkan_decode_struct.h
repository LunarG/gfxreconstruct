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

// The one DecodeStruct declaration: a function template over every decoded wrapper the schema describes, in place
// of one prototype per structure. The generated struct-decoders headers include this one, so a caller may include
// either.
//
// The definition is in decode/vulkan_decode_struct_impl.h, which is private to the one translation unit that
// instantiates it. See that header for why.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H

// Nothing in this file uses the custom forward header. A wrapper with a hand-written DecodeStruct is taken out of the
// template by overload resolution, which prefers the non-template overload only where it is declared; including the
// custom forward header here declares those overloads wherever the template is, so a caller of this header alone
// cannot get the template for such a wrapper. There is no list of such structures.
#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Wrapper>
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Wrapper* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
