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
// store holds it. It declares no API element, no Field and no member trait -- those are generated
// content -- and no wire type, which is format's to state.

#ifndef GFXRECON_SCHEMA_FIELD_H
#define GFXRECON_SCHEMA_FIELD_H

#include "format/format.h"
#include "schema/api_element.h"
#include "util/defines.h"
#include "util/fixed_string.h"

#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// The logical categories an API element names live in format/format.h, on the category tags themselves, together with the wire
// type each is recorded as. This layer declares no category; it selects on them.

// Store values. A store value is a type with a static Get(store) that yields a value; an Array declaration names one
// as its length, and an Action evaluates it. The base marks the types that are one, so an operator can require it of
// its operands and a declaration can be constrained on it.
struct StoreValueBase
{};

template <typename T>
concept StoreValue = std::derived_from<T, StoreValueBase>;

// Declarations. A field's declaration is an API element, or one form over a declaration: Const, Pointer, Array or
// FixedArray. The forms nest as the C declarator nests, so `const T* const*` is Array<Const<Pointer<Const<T>>>, n>,
// and an element is the leaf. Each form derives from Declaration<D>, which names what it declares as element, and
// from its own tag, so a shape concept is one base check. The forms are the type chain DWARF records for a member,
// DW_TAG_const_type, DW_TAG_pointer_type and DW_TAG_array_type over a base or structure type, with the length a
// store value where DWARF has DW_AT_count.
struct DeclarationBase
{};

template <typename E>
struct Declaration : DeclarationBase
{
    using element = E;
};

template <typename T>
concept IsDeclaration = ApiElement<T> || std::is_base_of_v<DeclarationBase, T>;

struct ConstDeclaration
{};
struct PointerDeclaration
{};
struct ArrayDeclaration
{};
struct FixedArrayDeclaration
{};

// The tokens a length slot takes in place of a store value. UseLength says an Array's capacity is its length, the
// input-array case. UseCapacity says a FixedArray's length is its capacity, the plain static-array case. UnknownLength
// says the registry gives no length an Action can evaluate, so the field stays on the custom path by rule.
struct UseLength
{};
struct UseCapacity
{};
struct UnknownLength
{};

template <typename T>
concept LengthSlot = StoreValue<T> || std::same_as<T, UnknownLength>;

// const applied at this level of the declaration.
template <IsDeclaration D>
struct Const : Declaration<D>, ConstDeclaration
{};

// A pointer to one D.
template <IsDeclaration D>
struct Pointer : Declaration<D>, PointerDeclaration
{};

// A pointer to Length items of D, with room for Capacity items. Capacity differs from Length only for an output array,
// where the buffer holds more than the call fills.
template <IsDeclaration D, LengthSlot Length, typename Capacity = UseLength>
struct Array : Declaration<D>, ArrayDeclaration
{
    using length   = Length;
    using capacity = Capacity;
};

// An array of N items of D declared in the storage type itself, with Length of them valid: UseCapacity for all N,
// or a store value for a bounded array whose count is a sibling. The parameter order is <D, Length, Capacity> for
// both array forms, so a reader who knows one knows the other.
template <IsDeclaration D, typename Length, size_t N>
struct FixedArray : Declaration<D>, FixedArrayDeclaration
{
    static_assert(StoreValue<Length> || std::same_as<Length, UseCapacity>,
                  "A FixedArray's length is UseCapacity or a store value");
    using length                     = Length;
    static constexpr size_t capacity = N;
};

GFXRECON_BEGIN_NAMESPACE(detail)

// Const is transparent to shape: the classification reads the form under it.
template <typename D>
struct RemoveConst
{
    using type = D;
};

template <typename D>
struct RemoveConst<Const<D>>
{
    using type = typename RemoveConst<D>::type;
};

// The element at the leaf of a declaration, through every level.
template <typename D>
struct ElementOf
{
    using type = D;
};

template <typename D>
struct ElementOf<Const<D>> : ElementOf<D>
{};

template <typename D>
struct ElementOf<Pointer<D>> : ElementOf<D>
{};

template <typename D, typename L, typename C>
struct ElementOf<Array<D, L, C>> : ElementOf<D>
{};

template <typename D, typename L, size_t N>
struct ElementOf<FixedArray<D, L, N>> : ElementOf<D>
{};

// The declared C type a declaration spells, rebuilt from the element's element_type with the declarator applied:
// const at the level it was written, a star for Pointer and Array, an extent for FixedArray. add_const_t on an array
// type qualifies its elements, as C does.
template <typename D>
struct ApiTypeOf
{
    using type = typename D::element_type;
};

template <typename D>
struct ApiTypeOf<Const<D>>
{
    using type = std::add_const_t<typename ApiTypeOf<D>::type>;
};

template <typename D>
struct ApiTypeOf<Pointer<D>>
{
    using type = typename ApiTypeOf<D>::type*;
};

template <typename D, typename L, typename C>
struct ApiTypeOf<Array<D, L, C>>
{
    using type = typename ApiTypeOf<D>::type*;
};

template <typename D, typename L, size_t N>
struct ApiTypeOf<FixedArray<D, L, N>>
{
    using type = typename ApiTypeOf<D>::type[N];
};

GFXRECON_END_NAMESPACE(detail)

template <typename D>
using ElementOf = typename detail::ElementOf<D>::type;

template <typename D>
using ApiTypeOf = typename detail::ApiTypeOf<D>::type;

// A field. The generator emits one derived struct per field use, `struct pNext : Field<"pNext", Pointer<Const<
// ExtensionChain>>> {};`, in a namespace named for the owner, so each use is its own type for MemberPointer,
// per-use facts and diagnostics, while a generic Action entry that deduces Field<Name, Declaration> instantiates once
// per distinct declaration, since a derived argument deduces against its base, [temp.deduct.call]/4.3.
struct FieldBase
{};

template <util::FixedString Name, IsDeclaration D>
struct Field : FieldBase
{
    using declaration = D;
    using api_element = ElementOf<D>;

    static constexpr std::string_view field_name = Name.view();
};

template <typename T>
concept IsField = std::is_base_of_v<FieldBase, T>;

// The Field vocabulary. Every Field the schema generator emits is `struct name : Field<"name", Declaration> {...}`
// with the members below and no others. A Field states what one use site is, never what an operation does with it,
// so nothing here names an operation, a wire type or a storage type.
//
//   declaration       Every field, from the Field base. An API element, or Const, Pointer, Array or FixedArray over a
//                     declaration, as the C declarator nests. The form concepts below read it, ApiTypeOf rebuilds the
//                     declared C type from it, and an Array or FixedArray carries its length in it.
//   api_element       Every field, from the Field base: the element at the leaf of the declaration. Its category and
//                     element_type answer every type question, and the category concepts below select on it.
//   field_name        Every field, from the Field base: the registry's member or parameter name, for diagnostics.
//                     Not `name`, because Vulkan declares members called name and a member cannot share the name of
//                     its class.
//   is_return         A command's Return Field only, always true. Absent means false; schema.h's return predicate
//                     reads it that way so that no other Field has to state it.
//   length_expression An Array whose registry length no Action can evaluate: the registry text as written. Not read
//                     by any operation; a length no Action can evaluate is recorded here rather than dropped.
//   selector_field    A GenericHandle field only: the sibling Field whose value names the handle type the integer
//                     stands for, so an operation can dispatch on it.
//   selections        A union alternative the registry marks: the selector values that choose it.
//   has_extensions    The pNext field. Whether the registry declares the owning structure on either side of
//                     structextends: extended by some structure, or itself an extension of one. This is the
//                     registry's fact, not the spec's. The spec usually states the false case as "pNext must be
//                     NULL", but a registry entry can disagree with the spec's text: VkPipelineCreateInfoKHR
//                     requires a create-info node and declares none. The schema records the fact and nothing
//                     more; whether to trust, probe or ignore the pointer is the Action's policy, not the Field's.
//
// Storage facts, which member of which type holds a field, are MemberPointer specializations and never Field
// members. Type facts, category, element_type, capture_wrapper_type, are on the api_element and are not restated.

// The API's own C++ type for one element of a field that names this API element. It is not the declared type of any
// field: the shape supplies the packaging, so a pointer-array field naming this API element is declared as a pointer
// to this type.
template <typename ApiType>
using ElementType = typename ApiType::element_type;

template <typename Field>
using FieldElementType = ElementType<typename Field::api_element>;

// The logical category a Field's API type names. Every category concept below asks format.h a question about this type
// and never spells a category tag itself.
template <typename Field>
using FieldCategory = typename Field::api_element::category;

// The wire type a Field is recorded as. The join between a category and its width is on the category itself, in
// format/format.h, so a change to the capture format touches that header and no schema content.
template <typename Field>
using FieldEncodeType = format::EncodeTypeFor<FieldCategory<Field>>;

// The count expression for an Array, PointerArray or StaticArray Field, if any: a FieldValue whose Get reads the
// array's length from the owner's storage.
template <typename Field>
using FieldLength = typename detail::RemoveConst<typename Field::declaration>::type::length;

// The sibling Field whose value names a generic handle's object type.
template <typename Field>
using FieldSelectorField = typename Field::selector_field;

// Whether the extents a FixedArray Field declares equal the extents of an array type, in rank and in every
// dimension. An Action with the declared member type in hand asserts this where it reads the array, so a schema that
// drifts from the API header fails in every build and not only in the one that compiles the generated checks file.
template <typename ArrayType, typename Field, typename Indices = std::make_index_sequence<std::rank_v<ArrayType>>>
struct DeclaredExtentsMatch;

template <typename ArrayType, typename Field, size_t... I>
struct DeclaredExtentsMatch<ArrayType, Field, std::index_sequence<I...>>
{
    // The type the declaration spells, which std::rank_v and std::extent_v read as they read the member's.
    using Declared = ApiTypeOf<typename Field::declaration>;

    // The rank test guards the fold: a declaration shallower than the declared rank is a mismatch, not an
    // out-of-bounds read, because a constant && does not evaluate its right operand once the left is false.
    static constexpr bool rank_matches = std::rank_v<ArrayType> == std::rank_v<Declared>;
    static constexpr bool value = rank_matches && ((std::extent_v<ArrayType, I> == std::extent_v<Declared, I>)&&...);
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
concept HasFieldLength = requires(const Storage& storage)
{
    FieldLength<Field>::Get(storage);
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

// Get is the uniform const read, whatever the member's addressability. It yields a reference to the member where it
// is addressable, and the member's value where it is not: a non-addressable member is a bitfield, so the value is
// an integer read through the generated accessor. A caller that binds the result to a const reference is safe in
// both cases, and a caller that wants a copy takes one with auto.
template <typename Storage, typename Field>
requires HasMember<Storage, Field>
[[nodiscard]] decltype(auto) Get(const Storage& storage, Field field)
{
    if constexpr (Addressable<Storage, Field>)
    {
        return GetRef(storage, field);
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

// Form concepts. Each reads the field's declaration: the form under any Const, through RemoveConst, and for the
// fixed array the declared C type, through std::is_array_v on ApiTypeOf.
template <typename Field>
using FieldForm = typename detail::RemoveConst<typename Field::declaration>::type;

// The void return of a command: the Void element held by value. It has no runtime value, no storage member and no
// encoded bytes; every command schema carries exactly one return Field, which is what lets ReturnFields find it and
// ParameterFields drop it.
template <typename Field>
concept VoidReturnField =
    ApiElement<FieldForm<Field>> && std::same_as<typename FieldForm<Field>::category, format::category::Void>;

// A directly held value: the declaration is an element.
template <typename Field>
concept ValueField = ApiElement<FieldForm<Field>> && !VoidReturnField<Field>;

// The extension chain entry of an extensible structure: a pointer whose leaf is the chain element, whose concrete
// element types are selected at run time from the encoded structure type.
template <typename Field>
concept ExtensionChainField = std::is_base_of_v<PointerDeclaration, FieldForm<Field>> &&
    std::same_as<ElementOf<FieldForm<Field>>, ExtensionChain>;

// A pointer to one element.
template <typename Field>
concept PointerField = std::is_base_of_v<PointerDeclaration, FieldForm<Field>> && !ExtensionChainField<Field>;

// A pointer to a pointer: an output slot the callee fills with an address, void** ppData, AHardwareBuffer** pBuffer.
// No structure member is one; the command parameters are.
template <typename Field>
concept IndirectPointerField = PointerField<Field> &&
    std::is_base_of_v<PointerDeclaration, typename detail::RemoveConst<typename FieldForm<Field>::element>::type>;

// An array of pointers, each to one element, with a length: an Array whose item is a Pointer. The storage is count
// pointers and nothing more; what the wire makes of each pointee is the adapter's decision by category, a structure
// of one or a null-terminated string.
template <typename Field>
concept PointerArrayField = std::is_base_of_v<ArrayDeclaration, FieldForm<Field>> &&
    std::is_base_of_v<PointerDeclaration, typename detail::RemoveConst<typename FieldForm<Field>::element>::type>;

// A pointer to a run of elements, with a length.
template <typename Field>
concept ArrayField = std::is_base_of_v<ArrayDeclaration, FieldForm<Field>> && !PointerArrayField<Field>;

// A fixed-extent array declared in the storage type itself.
template <typename Field>
concept StaticArrayField = std::is_base_of_v<FixedArrayDeclaration, FieldForm<Field>>;

// Category concepts. A category concept reads the element at the leaf of a declaration, and a form concept reads
// the declaration, so the two are facts about two different things: OpaqueElement<F> && PointerField<F> is a pointer
// to an opaque object. A category concept takes the Field or the element itself.
GFXRECON_BEGIN_NAMESPACE(detail)

template <typename T>
struct ElementOfAny
{
    using type = T;
};

template <IsField T>
struct ElementOfAny<T>
{
    using type = typename T::api_element;
};

GFXRECON_END_NAMESPACE(detail)

template <typename T>
using CategoryOf = typename detail::ElementOfAny<T>::type::category;

template <typename T>
concept HandleElement = format::IsHandleCategory<CategoryOf<T>>;

template <typename Field>
concept HandleValueField = HandleElement<Field> && ValueField<Field>;

template <typename T>
concept ScalarElement = format::IsScalarCategory<CategoryOf<T>>;

template <typename Field>
concept ScalarValueField = ScalarElement<Field> && ValueField<Field>;

// Text, of either width. The two categories pick different decoder classes, and nothing else about them differs.
template <typename T>
concept TextElement = format::IsTextCategory<CategoryOf<T>>;

// The category alone, so it also matches a pointer-array or static-array of structures. An Action that wants those
// separately orders its overloads by subsumption, or constrains on the form as well.
template <typename T>
concept StructElement = format::IsStructCategory<CategoryOf<T>>;

// A type the API declares and never describes: a platform structure reached through a pointer, or a platform
// handle typedef held by value. Recorded as the address, never followed.
template <typename T>
concept OpaqueElement = format::IsOpaqueCategory<CategoryOf<T>>;

template <typename T>
concept CallbackElement = format::IsCallbackCategory<CategoryOf<T>>;

// void: a pointer to it is an address, a counted pointer to it is a run of bytes, and a value of it is a command's
// void return.
template <typename T>
concept VoidElement = std::same_as<CategoryOf<T>, format::category::Void>;

// Recorded as an identifier rather than the thing itself: a handle's capture-file id, or an address. Nothing decodes
// into the API's own member for any of them; the identifier goes to the wrapper and the member is nulled until replay
// resolves it.
template <typename T>
concept IdentifierElement = HandleElement<T> || OpaqueElement<T> || CallbackElement<T>;

// Recorded as the member's own bits, in the category's wire type: a scalar, or an opaque or callback element held
// by value. A handle is not one, since it records the wrapper's id.
template <typename T>
concept GeneralScalarElement = ScalarElement<T> || OpaqueElement<T> || CallbackElement<T>;

// Any pointer shape. A decoder that reads its own length and depth from the wire cannot tell them apart -- a pointer
// to one element is a run of one, and a run of pointers is one more level of the same -- so an operation whose body
// does not consult the length constrains on this rather than on the shapes separately.
template <typename Field>
concept AnyPointerField = PointerField<Field> || ArrayField<Field> || PointerArrayField<Field>;

// Either counted run: a pointer to a run of elements, or a run of pointers. Both read a sibling count and hand the
// member's pointer value to an operation with it.
template <typename Field>
concept AnyCountedField = ArrayField<Field> || PointerArrayField<Field>;

// A run of elements, counted or fixed. The adapter's array entries take either, since both hand over a pointer and a
// count; the Action reads them differently.
template <typename Field>
concept AnyArrayField = StaticArrayField<Field> || ArrayField<Field>;

// What a count operand may yield: an integer, or a C enum standing for one, as rasterizationSamples does. bool is an
// integer to the language and not a count.
template <typename T>
concept LengthValue = (std::integral<T> && !std::same_as<T, bool>) || std::is_enum_v<T>;

template <typename Operand, typename Store>
using OperandValue = decltype(Operand::Get(std::declval<const Store&>()));

// A value read from storage by Field. The one-argument form reads the Field's own value. The two-argument form reads
// Member from what the Field points to: Store holds Field, FieldStore is what Field's value points to, and is the
// Store that Member is read from.
template <typename Field, typename... Member>
struct FieldValue;

template <typename Field>
struct FieldValue<Field> : StoreValueBase
{
    template <typename Store>
    requires HasMember<Store, Field>
    [[nodiscard]] static auto Get(const Store& store) { return schema::Get(store, Field{}); }
};

template <typename Field, typename Member>
struct FieldValue<Field, Member> : StoreValueBase
{
    static_assert(PointerField<Field>,
                  "Pointer Field only. Struct Field: add a GetRef branch in Get and FieldStore.");

    template <typename Store>
    using FieldStore = std::remove_cvref_t<decltype(*FieldValue<Field>::Get(std::declval<const Store&>()))>;

    template <typename Store>
    requires HasMember<FieldStore<Store>, Member>
    [[nodiscard]] static auto Get(const Store& store) { return schema::Get(*FieldValue<Field>::Get(store), Member{}); }
};

// A number written into the schema, in the type the generator gave the literal. An API constant such as VK_UUID_SIZE
// is a macro, so the type carries its value and the generated header's NOTE line carries its name.
template <auto V>
struct Literal : StoreValueBase
{
    template <typename Store>
    [[nodiscard]] static constexpr auto Get(const Store&)
    {
        return V;
    }
};

// Arithmetic over two operands, in the operands' own types under the usual conversions, so an enum promotes and a
// literal beside an unsigned sibling is written unsigned. The Apply narrows the result once, as it does for a plain
// sibling. The registry's lengths use these three operators and no others.
template <StoreValue Left, StoreValue Right>
struct Sum : StoreValueBase
{
    template <typename Store>
    requires LengthValue<OperandValue<Left, Store>> && LengthValue<OperandValue<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) + Right::Get(store); }
};

template <StoreValue Left, StoreValue Right>
struct Product : StoreValueBase
{
    template <typename Store>
    requires LengthValue<OperandValue<Left, Store>> && LengthValue<OperandValue<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) * Right::Get(store); }
};

template <StoreValue Left, StoreValue Right>
struct Quotient : StoreValueBase
{
    template <typename Store>
    requires LengthValue<OperandValue<Left, Store>> && LengthValue<OperandValue<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) / Right::Get(store); }
};

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
