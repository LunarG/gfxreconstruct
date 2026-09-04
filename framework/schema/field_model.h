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

// Field-model vocabulary for the generic field schema and action model.
//
// This header carries no API type descriptor, no Field descriptor, and no member-trait specialization. Those are
// generated content.
//
// It also names no wire representation type. schema/encoding.h joins a kind to its wire type, and only the Encode
// and Decode adapters include it, so a header that needs field identity reaches no format type.

#ifndef GFXRECON_SCHEMA_FIELD_MODEL_H
#define GFXRECON_SCHEMA_FIELD_MODEL_H

#include "util/defines.h"

#include <concepts>
#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// Logical kinds. A kind is a plain empty tag that names one logical Encode and Decode operation, so an operation is
// written as one flat overload for each kind, each naming the ParameterEncoder or ValueDecoder function that already
// exists for it. That keeps every operation a list of one-liners over an API surface that is itself a flat list.
//
// A kind therefore duplicates part of what the descriptor's element_type says: DeviceSize and UInt64 are both 64 bits
// wide, and Flags and Flags64 differ only by width. That duplication is deliberate. It can only go wrong in the
// generator's own type-resolution loop, which assigns kind and element type together for a whole class of types at
// once, so a mistake shows up across hundreds of descriptors and fails the round trip rather than hiding in one.
// The generator checks the agreement at generation time, where the risk actually lives.
//
// A scalar kind derives from field_kind::Scalar so that one concept selects the shared scalar access pattern while
// the exact kind still selects the operation.
GFXRECON_BEGIN_NAMESPACE(field_kind)

struct Scalar
{};

// Recorded as the element type itself. These exist so that an operation has one overload for each named
// ParameterEncoder and ValueDecoder function, not because anything is converted.
struct UInt8 : Scalar
{};

struct UInt16 : Scalar
{};

struct UInt32 : Scalar
{};

struct UInt64 : Scalar
{};

struct Int8 : Scalar
{};

struct Int16 : Scalar
{};

struct Int32 : Scalar
{};

struct Int64 : Scalar
{};

struct Float : Scalar
{};

struct Double : Scalar
{};

// Recorded through a wire type that gfxrecon::format names in its own right, so the capture format can change it
// without touching any descriptor. schema/encoding.h holds the mapping. The wire type need not differ from the
// element type today: SampleMaskEncodeType and VkSampleMask are both 32 bits, but reserving the name is what keeps
// them free to diverge.
struct Char : Scalar
{};

struct WChar : Scalar
{};

struct SizeT : Scalar
{};

struct Enum : Scalar
{};

struct Flags : Scalar
{};

struct Flags64 : Scalar
{};

struct SampleMask : Scalar
{};

struct DeviceSize : Scalar
{};

struct DeviceAddress : Scalar
{};

// An opaque address recorded as a 64-bit value: a function pointer, or a pointer to a non-API object.
struct Address : Scalar
{};

// Handle, structure and void access patterns differ from the scalar pattern, so they do not derive from Scalar.
// Handle has a wire type of its own; a structure is expanded field by field and void has no wire representation, so
// neither has a row in schema/encoding.h.
struct Handle
{};

struct Struct
{};

struct Void
{};

GFXRECON_END_NAMESPACE(field_kind)

// How one field use packages its API type. Shape is a property of the use site, not of the type.
GFXRECON_BEGIN_NAMESPACE(field_shape)

// A directly held value.
struct Value
{};

// A pointer to one element.
struct Pointer
{};

// A pointer to a run of elements, with a sibling count field.
struct PointerArray
{};

// A fixed-extent array declared in the storage type itself.
struct StaticArray
{};

// The extension chain entry of an extensible structure. Its concrete element types are selected at run time from the
// encoded structure type, so it is not a plain pointer use site.
struct ExtensionChain
{};

// A field with no runtime value, storage member, or encoded bytes. The void return Field is the only current use.
struct NoValue
{};

GFXRECON_END_NAMESPACE(field_shape)

// The API's own C++ type for one element of a field that names this descriptor. It is not the declared type of any
// field: the shape supplies the packaging, so a pointer-array field naming this descriptor is declared as a pointer
// to this type.
template <typename ApiType>
using ElementType = typename ApiType::element_type;

template <typename Field>
using FieldElementType = ElementType<typename Field::api_type>;

// Optional capability of an API type descriptor. Capture-side wrapper state and decoded representation are not two
// halves of one descriptor, so an action is constrained on the capability it names.
template <typename ApiType>
concept HasCaptureWrapper = requires
{
    typename ApiType::capture_wrapper_type;
};

// Member traits. The primary template stays undefined, so an absent specialization makes the access concepts fail
// rather than producing a hard error.
template <typename Storage, typename Field>
struct MemberPointer;

// Sentinel for a member that has no pointer-to-member. [class.bit]/3 does not permit the address-of operator on a
// bitfield, so such a mapping supplies generated accessors instead.
struct NotAddressable
{};

struct NonAddressableMember
{
    static constexpr NotAddressable value{};
};

template <typename Storage, typename Field>
concept HasMember = requires
{
    MemberPointer<std::remove_cv_t<Storage>, Field>::value;
};

template <typename Storage, typename Field>
concept Addressable = requires
{
    requires std::is_member_object_pointer_v<decltype(MemberPointer<std::remove_cv_t<Storage>, Field>::value)>;
};

template <typename Storage, typename Field>
concept NonAddressable = HasMember<Storage, Field> &&(!Addressable<Storage, Field>);

// GetRef is the normal primitive for an addressable member. The constraint removes it from the overload set for a
// non-addressable member, so another action overload wins by overload resolution.
template <typename Storage, typename Field>
requires Addressable<Storage, Field>
[[nodiscard]] decltype(auto) GetRef(Storage& storage, Field)
{
    return (storage.*MemberPointer<std::remove_cv_t<Storage>, Field>::value);
}

// Get expresses a read by value, and is the only read available for a non-addressable member.
template <typename Storage, typename Field>
requires HasMember<Storage, Field>
[[nodiscard]] auto Get(const Storage& storage, Field field)
{
    if constexpr (Addressable<Storage, Field>)
    {
        using Value = std::remove_cvref_t<decltype(GetRef(storage, field))>;
        return Value(GetRef(storage, field));
    }
    else
    {
        return MemberPointer<std::remove_cv_t<Storage>, Field>::Get(storage);
    }
}

// Set expresses a write, and is the only write available for a non-addressable member.
template <typename Storage, typename Field, typename ValueType>
requires HasMember<Storage, Field>
void Set(Storage& storage, Field field, ValueType&& value)
{
    if constexpr (Addressable<Storage, Field>)
    {
        GetRef(storage, field) = std::forward<ValueType>(value);
    }
    else
    {
        MemberPointer<std::remove_cv_t<Storage>, Field>::Set(storage, value);
    }
}

// Shape concepts select action overloads from the API type's logical kind and the field use's shape.
template <typename Field>
concept HandleField = std::same_as<typename Field::api_type::kind, field_kind::Handle> &&
    std::same_as<typename Field::shape, field_shape::Value>;

// The kind alone, so a shape other than Value can select on it. ScalarField is the value-shaped case.
template <typename Field>
concept ScalarKindField = std::derived_from<typename Field::api_type::kind, field_kind::Scalar>;

template <typename Field>
concept ScalarField = ScalarKindField<Field> && std::same_as<typename Field::shape, field_shape::Value>;

// StructField constrains on logical kind alone, so it also matches a pointer-array or static-array of structures.
// An Action that wants those separately must order its overloads by subsumption, or constrain on shape as well.
template <typename Field>
concept StructField = std::same_as<typename Field::api_type::kind, field_kind::Struct>;

template <typename Field>
concept ValueShapedField = std::same_as<typename Field::shape, field_shape::Value>;

template <typename Field>
concept PointerField = std::same_as<typename Field::shape, field_shape::Pointer>;

template <typename Field>
concept PointerArrayField = std::same_as<typename Field::shape, field_shape::PointerArray>;

template <typename Field>
concept StaticArrayField = std::same_as<typename Field::shape, field_shape::StaticArray>;

template <typename Field>
concept ExtensionChainField = std::same_as<typename Field::shape, field_shape::ExtensionChain>;

template <typename Field>
concept NoValueField = std::same_as<typename Field::shape, field_shape::NoValue>;

// Storage concepts. These describe what a storage type holds for a Field, and stay independent of any one operation
// family.
template <typename Storage, typename Field, typename ValueType>
concept StoresFieldAs = Addressable<Storage, Field> && requires(Storage& storage, Field field)
{
    requires std::same_as<std::remove_cvref_t<decltype(GetRef(storage, field))>, ValueType>;
};

template <typename Storage, typename Field>
concept StoresElementField = StoresFieldAs<Storage, Field, FieldElementType<Field>>;

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_FIELD_MODEL_H
