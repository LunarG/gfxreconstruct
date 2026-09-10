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

// Every DecodeStruct declaration, in one header. The generated forward header declares the wrappers, the
// prototypes of the structures that keep a generated body, and the NonSchemaDrivenStructs list; this header includes
// it and adds the one declaration that serves every other structure, a constrained function template in place of one
// prototype per structure. Include this, not the generated header, to call DecodeStruct.
//
// The split is deliberate: the generated file carries the data, which is the list, and this file carries the
// logic that reads it, so that logic is C++ in a header rather than a Python string in a generator.
//
// The list names what the schema does NOT drive. It is stated as an exclusion because the forward header is
// included nearly everywhere and the concept expands the list at every use; naming the driven population instead
// would put a fold over every structure at every call site, to decide a question the exclusions answer in a step.
//
// The constraint is for diagnosis, not selection: the template would resolve correctly without it, since a
// non-template beats a template wherever a prototype still exists. What it buys is that a structure with a body of
// its own fails at the call naming its type, rather than at the link naming a mangled symbol.
//
// The definition is in decode/vulkan_decode_struct_impl.h, which is private to the one translation unit that
// instantiates it. See that header for why.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H

#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"
#include "util/type_list.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename Wrapper>
concept SchemaDriven = !util::TypeListContainsV<NonSchemaDrivenStructs, Wrapper>;

template <SchemaDriven Wrapper>
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Wrapper* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_STRUCT_H
