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
// A scalar kind derives from format::kind::Scalar so that one concept selects the shared scalar access pattern while
// the exact kind still selects the operation.
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

// The API's own C++ type for one element of a field that names this descriptor. It is not the declared type of any
// field: the shape supplies the packaging, so a pointer-array field naming this descriptor is declared as a pointer
// to this type.
template <typename ApiType>
using ElementType = typename ApiType::element_type;

template <typename Field>
using FieldElementType = ElementType<typename Field::api_type>;

// The wire type a Field is recorded as. The join between a kind and its width is on the kind itself, in
// format/format.h, so a change to the capture format touches that header and no schema content.
template <typename Field>
using FieldEncodeType = format::EncodeTypeFor<typename Field::api_type::kind>;

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
// A field whose API type alone cannot say what it is: the API declares a plain integer, and a sibling field names
// the handle type at run time. The schema records that sibling, so an operation can tell these from handles whose
// type is in their declaration.
template <typename Field>
concept HasSelectorField = requires
{
    typename Field::selector_field;
};

template <typename Field>
concept HandleKindField = std::same_as<typename Field::api_type::kind, format::kind::Handle>;

template <typename Field>
concept HandleField = HandleKindField<Field> && std::same_as<typename Field::shape, field_shape::Value>;

// The kind alone, so a shape other than Value can select on it. ScalarField is the value-shaped case.
template <typename Field>
concept ScalarKindField = std::derived_from<typename Field::api_type::kind, format::kind::Scalar>;

template <typename Field>
concept ScalarField = ScalarKindField<Field> && std::same_as<typename Field::shape, field_shape::Value>;

// StructField constrains on logical kind alone, so it also matches a pointer-array or static-array of structures.
// An Action that wants those separately must order its overloads by subsumption, or constrain on shape as well.
// Text, of either width. The two kinds pick different decoder classes, and nothing else about them differs.
template <typename Field>
concept TextKindField = std::same_as<typename Field::api_type::kind, format::kind::Char> ||
    std::same_as<typename Field::api_type::kind, format::kind::WChar>;

template <typename Field>
concept StructField = std::same_as<typename Field::api_type::kind, format::kind::Struct>;

// An opaque address: recorded as the value the capture saw rather than followed, so nothing is at the other end
// to decode and the field is value-shaped whether or not the declaration writes a star.
template <typename Field>
concept AddressField = std::same_as<typename Field::api_type::kind, format::kind::Address>;

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
concept NoValueField = std::same_as<typename Field::shape, field_shape::VoidReturn>;

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
