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

// The type an API element is encoded as, e.g. format::DeviceSizeEncodeType for VkDeviceSize. The scalar and enum
// specializations of an API are generated into generated/generated_<api>_wire_types.h, which
// binding/<api>_wire_type.h includes; the partial specializations below cover bitmask, handle, funcpointer and opaque.

#ifndef GFXRECON_BINDING_WIRE_TYPE_OF_H
#define GFXRECON_BINDING_WIRE_TYPE_OF_H

#include "format/format.h"
#include "schema/field.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// Declared and not defined: an API element without a specialization is an incomplete type where it is read.
template <schema::ApiElement Element>
requires schema::ScalarApiElement<Element> || schema::TextApiElement<Element> || schema::IdentifierApiElement<Element>
struct WireTypeOf;

template <schema::ApiElement Element>
using WireTypeOf_t = typename WireTypeOf<Element>::type;

template <schema::ApiElement Element>
requires schema::BitmaskApiElement<Element>
struct WireTypeOf<Element>
{
    using type = WireTypeOf_t<typename Element::flags_type>;
};

template <schema::ApiElement Element>
requires schema::HandleApiElement<Element>
struct WireTypeOf<Element>
{
    using type = format::HandleEncodeType;
};

template <schema::ApiElement Element>
requires schema::FuncpointerApiElement<Element> || schema::OpaqueApiElement<Element>
struct WireTypeOf<Element>
{
    using type = format::AddressEncodeType;
};

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_WIRE_TYPE_OF_H
