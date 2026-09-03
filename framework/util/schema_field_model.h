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
// This header carries no API type descriptor, no Field descriptor, and no
// member-trait specialization. Those are generated content.
//
// The logical kinds here are the fixed part of the vocabulary. The generator
// emits the leaf scalar kinds actually used by the supported APIs, because
// that set follows the registry rather than this header.

#ifndef GFXRECON_UTIL_SCHEMA_FIELD_MODEL_H
#define GFXRECON_UTIL_SCHEMA_FIELD_MODEL_H

#include "util/defines.h"

#include <concepts>
#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// Logical kinds. A scalar kind derives from field_kind::Scalar so that one concept selects the shared scalar access
// pattern while the exact kind still selects the named Encode or Decode operation. Handle, structure, and void kinds
// do not derive from Scalar, because their access patterns differ.
GFXRECON_BEGIN_NAMESPACE(field_kind)

struct Scalar
{};

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

// Optional capability of an API type descriptor. Capture-side wrapper state and decoded representation are not two
// halves of one descriptor, so an action is constrained on the capability it names.
template <typename ApiType>
concept HasCaptureWrapper = requires { typename ApiType::capture_wrapper_type; };

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
concept HasMember = requires { MemberPointer<std::remove_cv_t<Storage>, Field>::value; };

template <typename Storage, typename Field>
concept Addressable = requires {
    requires std::is_member_object_pointer_v<decltype(MemberPointer<std::remove_cv_t<Storage>, Field>::value)>;
};

template <typename Storage, typename Field>
concept NonAddressable = HasMember<Storage, Field> && (!Addressable<Storage, Field>);

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

// Shape concepts. Every one of these selects on exactly two facts, the API type's logical kind and the field use's
// shape.
template <typename Field>
concept HandleField = std::same_as<typename Field::api_type::kind, field_kind::Handle> &&
                      std::same_as<typename Field::shape, field_shape::Value>;

template <typename Field>
concept StructField = std::same_as<typename Field::api_type::kind, field_kind::Struct>;

template <typename Field>
concept ScalarField = std::derived_from<typename Field::api_type::kind, field_kind::Scalar> &&
                      std::same_as<typename Field::shape, field_shape::Value>;

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

// Storage concepts. These describe what a store holds for a Field, and stay independent of any one operation family.
template <typename FieldStore, typename Field, typename ValueType>
concept StoresFieldAs = Addressable<FieldStore, Field> && requires(FieldStore& store, Field field) {
    requires std::same_as<std::remove_cvref_t<decltype(GetRef(store, field))>, ValueType>;
};

template <typename FieldStore, typename Field>
concept StoresNativeField = StoresFieldAs<FieldStore, Field, typename Field::api_type::native_type>;

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_SCHEMA_FIELD_MODEL_H
