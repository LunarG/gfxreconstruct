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

// This header declares the DecodeStruct template, one declaration for every schema-driven Decoded_ wrapper.
// generated/generated_vulkan_struct_decoders.h includes it, so a caller may include either.
//
// decode/vulkan_decode_struct_impl.h defines the template, and the explicit instantiations are in
// decode/vulkan_struct_decoders.cpp.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H

// NOTE: MUST NOT remove as unused -- nothing in this file uses it, but it declares the hand-written DecodeStruct
// overloads wherever the template is declared. Overload resolution prefers a non-template overload only where it is
// declared; without it, a call on a CUSTOM_DECODE wrapper picks the template, which has no instantiation for it, and
// fails to link.
#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "binding/decoded_type_of.h"
#include "util/defines.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <binding::DecodedWrapper Wrapper>
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Wrapper* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
