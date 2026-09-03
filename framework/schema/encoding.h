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

// The join between a logical kind and its wire representation.
//
// One row for each kind, and nothing computed. Both the Encode and the Decode adapter read it, so capture and replay
// cannot disagree about a field's wire representation. Before this trait existed the association was a generator-side
// table from C++ type to operation name, joined to gfxrecon::format only by the naming convention of the generated
// call site, which nothing checked.
//
// The primary template is left undefined, so a kind with no row here fails at the point of use and names itself.
// field_kind::Struct and field_kind::Void have no row on purpose: a structure is expanded field by field, and void
// has no wire representation at all.
//
// Only the Encode and Decode adapters include this header. Field identity does not, so a header that needs only
// descriptors and Fields reaches no wire representation type.

#ifndef GFXRECON_SCHEMA_ENCODING_H
#define GFXRECON_SCHEMA_ENCODING_H

#include "format/format.h"
#include "schema/field_model.h"
#include "util/defines.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

template <typename Kind, typename ElementType>
struct EncodedType;

// clang-format off

// A width the registry names directly is recorded as itself.
template <typename E> struct EncodedType<field_kind::UInt8,  E> { using type = E; };
template <typename E> struct EncodedType<field_kind::UInt16, E> { using type = E; };
template <typename E> struct EncodedType<field_kind::UInt32, E> { using type = E; };
template <typename E> struct EncodedType<field_kind::UInt64, E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Int8,   E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Int16,  E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Int32,  E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Int64,  E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Float,  E> { using type = E; };
template <typename E> struct EncodedType<field_kind::Double, E> { using type = E; };

// A kind whose wire representation is pinned independently of the element type.
template <typename E> struct EncodedType<field_kind::Char,          E> { using type = format::CharEncodeType; };
template <typename E> struct EncodedType<field_kind::WChar,         E> { using type = format::WCharEncodeType; };
template <typename E> struct EncodedType<field_kind::SizeT,         E> { using type = format::SizeTEncodeType; };
template <typename E> struct EncodedType<field_kind::Enum,          E> { using type = format::EnumEncodeType; };
template <typename E> struct EncodedType<field_kind::Flags,         E> { using type = format::FlagsEncodeType; };
template <typename E> struct EncodedType<field_kind::Flags64,       E> { using type = format::Flags64EncodeType; };
template <typename E> struct EncodedType<field_kind::SampleMask,    E> { using type = format::SampleMaskEncodeType; };
template <typename E> struct EncodedType<field_kind::DeviceSize,    E> { using type = format::DeviceSizeEncodeType; };
template <typename E> struct EncodedType<field_kind::DeviceAddress, E> { using type = format::DeviceAddressEncodeType; };
template <typename E> struct EncodedType<field_kind::Address,       E> { using type = format::AddressEncodeType; };
template <typename E> struct EncodedType<field_kind::Handle,        E> { using type = format::HandleEncodeType; };

// clang-format on

// The wire representation for one Field. This is the expression an adapter writes, so a change to the capture format
// touches this header and no schema content.
template <typename Field>
using EncodedTypeFor =
    typename EncodedType<typename Field::api_type::kind, typename Field::api_type::element_type>::type;

// Recorded wire widths. A change to the capture format has to move one of these deliberately rather than silently.
static_assert(sizeof(format::EnumEncodeType) == 4);
static_assert(sizeof(format::FlagsEncodeType) == 4);
static_assert(sizeof(format::Flags64EncodeType) == 8);
static_assert(sizeof(format::SampleMaskEncodeType) == 4);
static_assert(sizeof(format::SizeTEncodeType) == 8);
static_assert(sizeof(format::DeviceSizeEncodeType) == 8);
static_assert(sizeof(format::DeviceAddressEncodeType) == 8);
static_assert(sizeof(format::AddressEncodeType) == 8);
static_assert(sizeof(format::CharEncodeType) == 1);
static_assert(sizeof(format::WCharEncodeType) == 2);
static_assert(sizeof(format::HandleEncodeType) == 8);

// A handle ID is the capture-file identity of an API handle. It is currently a typedef of the handle wire type, so a
// change to that type silently changes what every handle ID means. This assertion records the coupling rather than
// endorsing it.
static_assert(std::is_same_v<format::HandleId, format::HandleEncodeType>);

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_ENCODING_H
