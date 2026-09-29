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

// The one EncodeStruct declaration: a function template over every Vulkan structure the schema describes, in
// place of one prototype per structure. The generated struct-encoders header includes this one, so a caller may
// include either.
//
// The definition is in encode/vulkan_encode_struct_impl.h, which is private to the one translation unit that
// instantiates it.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_H

// Nothing in this file uses the custom header. A structure with a hand-written EncodeStruct is taken out of the
// template by overload resolution, which prefers the non-template overload only where it is declared; including the
// custom header here declares those overloads wherever the template is, so a caller of this header alone cannot get
// the template for such a structure. There is no list of such structures.
#include "encode/custom_vulkan_struct_encoders.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ParameterEncoder;

template <typename Struct>
void EncodeStruct(ParameterEncoder* encoder, const Struct& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_H
