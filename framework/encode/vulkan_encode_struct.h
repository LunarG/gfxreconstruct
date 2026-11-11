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

// This header declares the EncodeStruct template, one declaration for every schema-driven Vulkan structure.
// generated/generated_vulkan_struct_encoders.h includes it, so a caller may include either.
//
// encode/vulkan_encode_struct_impl.h defines the template; only encode/vulkan_struct_encoders.cpp, which holds the
// explicit instantiations, includes it.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_STRUCT_H

// NOTE: MUST NOT remove as unused -- nothing in this file uses it, but it declares the hand-written EncodeStruct
// overloads wherever the template is declared. A call inside a template sees only the overloads declared before the
// template's definition ([temp.dep.candidate]); argument-dependent lookup adds none for a global C structure
// ([basic.lookup.argdep]). Without it, a call on a CUSTOM_ENCODE structure picks the template, which has no
// instantiation for it, and fails to link.
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
