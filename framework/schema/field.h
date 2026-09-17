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

// What a Field is, and how to reach the value it names in a store.
//
// gfxrecon::format defines the primitives a capture can represent and how each is encoded. This layer defines their
// arrangement: which API type a Field names, how that type is packaged at the use site, and which member of which
// store holds it. It declares no API type descriptor, no Field descriptor and no member trait -- those are generated
// content -- and no wire type, which is format's to state.

#ifndef GFXRECON_SCHEMA_FIELD_H
#define GFXRECON_SCHEMA_FIELD_H

#include "format/format.h"
#include "util/defines.h"

#include <concepts>
#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// The logical kinds a descriptor names live in format/format.h, on the kind tags themselves, together with the wire
// type each is recorded as. This layer declares no kind; it selects on them.

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

// The return Field of a command that returns void. It has no runtime value, no storage member and no encoded
// bytes; it exists so that every command schema carries exactly one return Field, which is what lets ReturnMatches
// find it and ParameterFields drop it. All 443 uses are a command's result, and there are no others.
//
// Not NoValue, which is the obvious name: X11's Xutil.h defines that as a macro, and vulkan.h reaches Xutil.h
// through Xrandr.h whenever VK_USE_PLATFORM_XLIB_XRANDR_EXT is set, so every Linux build broke on it. Of the
// thirty-six names this vocabulary declares, it was the only collision.
struct VoidReturn
{};

GFXRECON_END_NAMESPACE(field_shape)

// The Field descriptor vocabulary. Every Field descriptor the schema generator emits is a struct of the members below
// and no others; the members present depend on the field's shape and kind. A descriptor states what one use site
// is, never what an operation does with it, so nothing here names an operation, a wire type or a storage type.
//
//   api_type          Every field. The API type descriptor; its kind and element_type answer every type question, and
//                     the kind concepts below select on it.
//   shape             Every field. One of the field_shape tags above; the shape concepts below select on it.
//   field_name        Every field. The registry's member or parameter name, for diagnostics. It is not `name`,
//                     because Vulkan declares members called name and a member cannot share the name of its class.
//   is_return         A command's Return Field only, always true. Absent means false; schema.h's return predicate
//                     reads it that way so that no other descriptor has to state it.
//   pointer_count     Pointer and PointerArray. The declared star count, one or two.
//   count_field       PointerArray or StaticArray whose registry length is exactly one sibling member: that sibling's
//                     Field descriptor, so a cross-field read can be constrained on it.
//   length_expression PointerArray or StaticArray whose registry length is anything else: the registry text as
//                     written, for example a computed length or the comma-joined extents of a matrix. Not read by
//                     any operation; a length no Action can evaluate is recorded here rather than dropped.
//   extents           StaticArray. The declared extents in declaration order, so extents[i] is
//                     std::extent_v<Member, i> and the rank is the array's length. The schema states them so a
//                     field is fully described without a storage type; an Action with storage in hand may read the
//                     declared type instead, and asserts the two agree with DeclaredExtentsMatch below.
//   selector_field    A GenericHandle field only: the sibling Field whose value names the handle type the integer
//                     stands for, so an operation can dispatch on it.
//   has_extensions    ExtensionChain. Whether the registry declares the owning structure on either side of
//                     structextends: extended by some structure, or itself an extension of one. This is the
//                     registry's fact, not the spec's. The spec usually states the false case as "pNext must be
//                     NULL", but a registry entry can disagree with the spec's text: VkPipelineCreateInfoKHR
//                     requires a create-info node and declares none. The schema records the fact and nothing
//                     more; whether to trust, probe or ignore the pointer is the Action's policy, not the Field's.
//
// Storage facts, which member of which type holds a field, are MemberPointer specializations and never descriptor
// members. Type facts, kind, element_type, capture_wrapper_type, are on the api_type and are not restated.

// The API's own C++ type for one element of a field that names this descriptor. It is not the declared type of any
// field: the shape supplies the packaging, so a pointer-array field naming this descriptor is declared as a pointer
// to this type.
template <typename ApiType>
using ElementType = typename ApiType::element_type;

template <typename Field>
using FieldElementType = ElementType<typename Field::api_type>;

// The logical kind a Field's API type names. Every kind concept below asks format.h a question about this type
// and never spells a kind tag itself.
template <typename Field>
using FieldKind = typename Field::api_type::kind;

// The wire type a Field is recorded as. The join between a kind and its width is on the kind itself, in
// format/format.h, so a change to the capture format touches that header and no schema content.
template <typename Field>
using FieldEncodeType = format::EncodeTypeFor<FieldKind<Field>>;

// The count field for a PointerArray or StaticArray Field, if any. The sibling Field whose value names the array's
// length
template <typename Field>
using FieldCountField = typename Field::count_field;

// The generic handle object types selector field which names the actual handle type.
template <typename Field>
using FieldSelectorField = typename Field::selector_field;

// Whether the extents a StaticArray Field records equal the extents of an array type, in rank and in every
// dimension. An Action with the declared member type in hand asserts this where it reads the array, so a schema that
// drifts from the API header fails in every build and not only in the one that compiles the generated checks file.
template <typename ArrayType, typename Field, typename Indices = std::make_index_sequence<std::rank_v<ArrayType>>>
struct DeclaredExtentsMatch;

template <typename ArrayType, typename Field, size_t... I>
struct DeclaredExtentsMatch<ArrayType, Field, std::index_sequence<I...>>
{
    // The rank test guards the fold: a recorded list shorter than the declared rank is a mismatch, not an
    // out-of-bounds read, because a constant && does not evaluate its right operand once the left is false.
    static constexpr bool rank_matches = std::rank_v<ArrayType> == std::extent_v<decltype(Field::extents)>;
    static constexpr bool value        = rank_matches && ((std::extent_v<ArrayType, I> == Field::extents[I]) && ...);
};

template <typename ArrayType, typename Field>
inline constexpr bool DeclaredExtentsMatchV = DeclaredExtentsMatch<ArrayType, Field>::value;

// Member traits. The primary template stays undefined, so an absent specialization makes the access concepts fail
// rather than producing a hard error.
template <typename Storage, typename Field>
struct MemberPointer;

// Sentinel for a member that has no pointer-to-member. The address-of operator may not be applied to a bitfield and
// a non-const reference may not be bound to one, so &Storage::member does not exist for such a member and GetRef
// cannot serve it; the mapping supplies generated Get and Set accessors instead. That rule is C++ [class.bit]/3 --
// a stable name, resolvable at https://eel.is/c++draft/class.bit.
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
concept HasSelectorField = HasMember<Storage, FieldSelectorField<Field>>;

template <typename Storage, typename Field>
concept HasCountField = HasMember<Storage, FieldCountField<Field>>;

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
concept HandleKindField = format::IsHandleKind<FieldKind<Field>>;

template <typename Field>
concept HandleField = HandleKindField<Field> && std::same_as<typename Field::shape, field_shape::Value>;

// The kind alone, so a shape other than Value can select on it. ScalarField is the value-shaped case.
template <typename Field>
concept ScalarKindField = format::IsScalarKind<FieldKind<Field>>;

template <typename Field>
concept ScalarField = ScalarKindField<Field> && std::same_as<typename Field::shape, field_shape::Value>;

// Text, of either width. The two kinds pick different decoder classes, and nothing else about them differs.
template <typename Field>
concept TextKindField = format::IsTextKind<FieldKind<Field>>;

// StructKindField constrains on logical kind alone, so it also matches a pointer-array or static-array of structures.
// An Action that wants those separately must order its overloads by subsumption, or constrain on shape as well.
template <typename Field>
concept StructKindField = format::IsStructKind<FieldKind<Field>>;

// An opaque address: recorded as the value the capture saw rather than followed, so nothing is at the other end
// to decode and the field is value-shaped whether or not the declaration writes a star.
template <typename Field>
concept AddressKindField = format::IsAddressKind<FieldKind<Field>>;

// A kind that records an identifier rather than the thing itself: a handle's capture-file id, or the address the
// capture saw. Nothing decodes into the API's own member for either; the identifier goes to the wrapper and the
// member is nulled until replay resolves it. The two kinds share that pattern and nothing else, so one concept
// names the pair.
template <typename Field>
concept IdentifierKindField = HandleKindField<Field> || AddressKindField<Field>;

// A scalar in the general sense that the member's own bits are the value recorded, in the kind's wire type. That
// is the scalar family and the address kind, which format.h keeps off that family because the decoder treats an
// address as an identifier; for encode the distinction does not arise. A handle is not one, since it records the
// wrapper's id.
template <typename Field>
concept GeneralScalarKindField = ScalarKindField<Field> || AddressKindField<Field>;

template <typename Field>
concept ValueShapedField = std::same_as<typename Field::shape, field_shape::Value>;

template <typename Field>
concept PointerField = std::same_as<typename Field::shape, field_shape::Pointer>;

template <typename Field>
concept PointerArrayField = std::same_as<typename Field::shape, field_shape::PointerArray>;

// Either pointer shape. A decoder that reads its own length from the wire cannot tell them apart -- a pointer to
// one element is a run of one -- so an operation whose body does not consult the length constrains on this rather
// than on the two shapes separately.
template <typename Field>
concept PointerShapedField = PointerField<Field> || PointerArrayField<Field>;

template <typename Field>
concept StaticArrayField = std::same_as<typename Field::shape, field_shape::StaticArray>;

template <typename Field>
concept ExtensionChainField = std::same_as<typename Field::shape, field_shape::ExtensionChain>;

template <typename Field>
concept VoidReturnField = std::same_as<typename Field::shape, field_shape::VoidReturn>;

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

#endif // GFXRECON_SCHEMA_FIELD_H
