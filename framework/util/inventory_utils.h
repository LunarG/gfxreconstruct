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

// The macros an inventory visitor expands to; the visit protocol is in the banner of
// generated/generated_vulkan_inventory.h.
// NOTE: a specialization macro spells its template unqualified and does not include its header -- expand it inside the
// template's namespace, after the template's declaration.

#ifndef GFXRECON_UTIL_INVENTORY_UTILS_H
#define GFXRECON_UTIL_INVENTORY_UTILS_H

#include "util/type_list.h"

// Specializes ApiElementOf<ApiType> as Element: ApiType is the API's C type (a structure, union or enum) and Element
// its API element.
#define GFXRECON_INVENTORY_API_ELEMENT_FOR(ApiType, Element) \
    template <>                                              \
    struct ApiElementOf<ApiType>                             \
    {                                                        \
        using type = Element;                                \
    }

// Specializes DecodedTypeOf<ApiElement> as Decoded. ApiElement is a structure or command API element; Decoded is the
// type decode stores it in.
#define GFXRECON_INVENTORY_DECODED_TYPE(ApiElement, Decoded) \
    template <>                                              \
    struct DecodedTypeOf<ApiElement>                         \
    {                                                        \
        using type = Decoded;                                \
    }

// Specializes CallId<Command> as Id. Command is a command API element; Id is its format::ApiCallId enumerator.
#define GFXRECON_INVENTORY_CALL_ID(Command, Id)        \
    template <>                                        \
    struct CallId<Command>                             \
    {                                                  \
        static constexpr format::ApiCallId value = Id; \
    }

// These three declare a TypeList named Name from the entries between BEGIN and END. The visitor expands each inventory
// entry to an ENTRY. BEGIN opens the list on a void placeholder that TypeListPopFront_t drops, so an empty selection is
// an empty list. clang-format is off: the three are one expression split across an #include, and clang-format reads the
// brackets as comparison operators.
// clang-format off
#define GFXRECON_INVENTORY_TYPE_LIST_BEGIN(Name) using Name = ::gfxrecon::util::TypeListPopFront_t<::gfxrecon::util::TypeList<void
#define GFXRECON_INVENTORY_TYPE_LIST_ENTRY(Type) , Type
#define GFXRECON_INVENTORY_TYPE_LIST_END >>;
// clang-format on

#endif // GFXRECON_UTIL_INVENTORY_UTILS_H
