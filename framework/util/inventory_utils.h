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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// What a visitor invoked across an inventory can expand to, in one place: the row macros for the three binding
// specializations, and the three macros that build a TypeList out of a run of entries an #include produces, which
// no macro can wrap. The row macros spell the binding templates' names; they need those declared where they expand,
// not here.

#ifndef GFXRECON_UTIL_INVENTORY_UTILS_H
#define GFXRECON_UTIL_INVENTORY_UTILS_H

#include "util/type_list.h"

// One row: Native is the API's structure, Descriptor its API type descriptor.
#define GFXRECON_INVENTORY_DESCRIPTOR_FOR(Native, Descriptor) \
    template <>                                               \
    struct DescriptorFor<Native>                              \
    {                                                         \
        using type = Descriptor;                              \
    }

// One row: ApiElement is the structure or command descriptor, Decoded the type decode represents it with.
#define GFXRECON_INVENTORY_DECODED_TYPE(ApiElement, Decoded) \
    template <>                                              \
    struct DecodedType<ApiElement>                           \
    {                                                        \
        using type = Decoded;                                \
    }

// One row: Command is the command descriptor, Id its ApiCallId enumerator.
#define GFXRECON_INVENTORY_CALL_ID(Command, Id)        \
    template <>                                        \
    struct CallId<Command>                             \
    {                                                  \
        static constexpr format::ApiCallId value = Id; \
    }

// A TypeList named Name from the entries between BEGIN and END: the visitor expands each row to an ENTRY, the list
// opens on a placeholder, and END drops it, so a selection of nothing is an empty list.
// The three are one expression split across an #include, and the formatter reads the brackets as comparison
// operators.
// clang-format off
#define GFXRECON_INVENTORY_TYPE_LIST_BEGIN(Name) using Name = ::gfxrecon::util::TypeListPopFront<::gfxrecon::util::TypeList<void
#define GFXRECON_INVENTORY_TYPE_LIST_ENTRY(Type) , Type
#define GFXRECON_INVENTORY_TYPE_LIST_END >>;
// clang-format on

#endif // GFXRECON_UTIL_INVENTORY_UTILS_H
