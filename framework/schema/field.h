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

// A Field is one structure member or command parameter: its name and its declaration, an API element under the forms
// Const, Pointer, Array and FixedArray, with a length expression for a run.

#ifndef GFXRECON_SCHEMA_FIELD_H
#define GFXRECON_SCHEMA_FIELD_H

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

// A store value derives from StoreValueBase and has a static Get(const Store&) that yields a value. An Array or
// FixedArray takes one as its length, and an Action evaluates it on the storage that holds the Field.
struct StoreValueBase
{};

template <typename T>
concept StoreValue = std::derived_from<T, StoreValueBase>;

// A Field's declaration is an API element, or a form over a declaration. The forms nest as the C declarator nests:
// `const T* const*` with length n is Array<Const<Pointer<Const<T>>>, n>, and the API element is the leaf. Each form
// derives from Declaration<D>, whose element is D, and from its tag type below, which the form concepts test.
struct DeclarationBase
{};

template <typename E>
struct Declaration : DeclarationBase
{
    using element = E;
};

template <typename T>
inline constexpr bool IsDeclaration_v = ApiElement<T> || std::is_base_of_v<DeclarationBase, T>;

struct ConstDeclaration
{};
struct PointerDeclaration
{};
struct ArrayDeclaration
{};
struct FixedArrayDeclaration
{};

// UseCapacity and UnknownLength are the length tokens, used in place of a store value. UseCapacity: a FixedArray's
// length is all N items. UnknownLength: the generator could not map the registry len attribute to a store value, and
// the Field carries the text as length_expression. A token has no Get, so FieldWithLength is false for its Field.
struct UseCapacity
{};
struct UnknownLength
{};

template <typename T>
concept LengthDescriptor = StoreValue<T> || std::same_as<T, UnknownLength>;

// Const applies const at this level of the declaration.
template <typename D>
requires IsDeclaration_v<D>
struct Const : Declaration<D>, ConstDeclaration
{};

// Pointer declares a pointer to one D.
template <typename D>
requires IsDeclaration_v<D>
struct Pointer : Declaration<D>, PointerDeclaration
{};

// Array declares a pointer to Length items of D.
template <typename D, LengthDescriptor Length>
requires IsDeclaration_v<D>
struct Array : Declaration<D>, ArrayDeclaration
{
    using length = Length;
};

// FixedArray declares an array of N items of D inside the storage type, with Length of them valid: UseCapacity for all
// N, or the store value of a sibling count member, which the encode Action clamps to N.
template <typename D, typename Length, size_t N>
requires IsDeclaration_v<D>
struct FixedArray : Declaration<D>, FixedArrayDeclaration
{
    static_assert(StoreValue<Length> || std::same_as<Length, UseCapacity>,
                  "A FixedArray's length is UseCapacity or a store value");
    using length                     = Length;
    static constexpr size_t capacity = N;
};

GFXRECON_BEGIN_NAMESPACE(detail)

// RemoveConst strips outer Const levels. Const is transparent to shape: the form concepts read the form under it.
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

// RemoveDeclarators yields the declaration with every declarator removed: the API element at its leaf.
template <typename D>
struct RemoveDeclarators
{
    using type = D;
};

template <typename D>
struct RemoveDeclarators<Const<D>> : RemoveDeclarators<D>
{};

template <typename D>
struct RemoveDeclarators<Pointer<D>> : RemoveDeclarators<D>
{};

template <typename D, typename L>
struct RemoveDeclarators<Array<D, L>> : RemoveDeclarators<D>
{};

template <typename D, typename L, size_t N>
struct RemoveDeclarators<FixedArray<D, L, N>> : RemoveDeclarators<D>
{};

// ApiTypeOf rebuilds the C type a declaration spells from the API element's element_type: const at the level it was
// written, a star for Pointer and Array, an extent for FixedArray. add_const_t on an array type qualifies its items, as
// C does. generated/generated_<api>_schema_checks.cpp static_asserts the result against each member's decltype.
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

template <typename D, typename L>
struct ApiTypeOf<Array<D, L>>
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
using RemoveDeclarators_t = typename detail::RemoveDeclarators<D>::type;

template <typename D>
using ApiTypeOf_t = typename detail::ApiTypeOf<D>::type;

template <typename D>
using RemoveConst_t = typename detail::RemoveConst<D>::type;

// FieldBase is the base of every Field. The generator emits one struct per use, in a namespace named for the owner,
// e.g. `struct pNext : Field<"pNext", Pointer<Const<ExtensionChain>>> {};`, so each use is its own type: for
// MemberPointer, for the per-use members below, and in diagnostics.
struct FieldBase
{};

template <util::FixedString Name, typename D>
requires IsDeclaration_v<D>
struct Field : FieldBase
{
    using declaration = D;
    using api_element = RemoveDeclarators_t<D>;

    static constexpr std::string_view field_name = Name.view();
};

template <typename T>
inline constexpr bool IsField_v = std::is_base_of_v<FieldBase, T>;

// A generated Field has only the members below; vulkan_schema_generator.py emits no others. A Field states what one
// use is. A wire type is a WireTypeOf specialization and a storage member a MemberPointer specialization, never a Field
// member; category and element_type are read from api_element, never restated on the Field.
//
//   declaration       Every Field, from the Field base: the API element, or a form over it as C declares it.
//   api_element       Every Field, from the Field base: the API element at the leaf of declaration.
//   field_name        Every Field, from the Field base: the registry's member or parameter name, for diagnostics. Not
//                     `name`: Vulkan declares members called name, and a member cannot share the name of its class.
//   is_return         A command's return Field only, always true. Absent means false: kIsReturnField in schema.h
//                     reads it that way, so no other Field states it.
//   length_expression An Array whose length is UnknownLength: the registry len text as written, kept so it is not lost.
//                     Nothing reads it.
//   selector_field    The sibling Field whose value selects this Field's meaning: the registry's selector attribute
//                     on a union member, or the object type member of a GenericHandle member (GENERIC_HANDLE_STRUCTS
//                     and GENERIC_HANDLE_APICALLS in vulkan_base_generator.py). The encode Action passes a
//                     GenericHandle's selector to GetWrappedId.
//   selections        A union alternative the registry marks: the selector values that choose it, from the
//                     registry's selection attribute.
//   has_extensions    The pNext Field only: true when the registry lists the owner on either side of structextends.
//                     This is the registry's fact, not the spec's: VkPipelineCreateInfoKHR requires a pNext node and
//                     gets false. The encode Action trusts the pointer when true and probes it when false.

template <ApiElement E>
using CategoryOf_t = typename E::category;

// LengthOf_t is the length of an Array or FixedArray Field: a store value (FieldValue, Literal, Sum, Product,
// Quotient), UseCapacity, or UnknownLength.
template <typename Field>
using LengthOf_t = typename RemoveConst_t<typename Field::declaration>::length;

// DeclaredExtentsMatch is true when a FixedArray Field's declared extents equal ArrayType's, in rank and in every
// dimension. The decode and encode Actions static_assert it on the member's type where they read the array. A schema
// that disagrees with the API header then fails to compile wherever an Action is instantiated, not only in
// generated/generated_<api>_schema_checks.cpp, which asserts each member's declared type.
template <typename ArrayType, typename Field, typename Indices = std::make_index_sequence<std::rank_v<ArrayType>>>
struct DeclaredExtentsMatch;

template <typename ArrayType, typename Field, size_t... I>
struct DeclaredExtentsMatch<ArrayType, Field, std::index_sequence<I...>>
{
    using Declared = ApiTypeOf_t<typename Field::declaration>;

    // rank_matches catches a declaration with more dimensions than ArrayType; the fold compares ArrayType's only.
    static constexpr bool rank_matches = std::rank_v<ArrayType> == std::rank_v<Declared>;
    static constexpr bool value = rank_matches && ((std::extent_v<ArrayType, I> == std::extent_v<Declared, I>)&&...);
};

template <typename ArrayType, typename Field>
inline constexpr bool DeclaredExtentsMatch_v = DeclaredExtentsMatch<ArrayType, Field>::value;

// MemberPointer<Storage, Field>::value points at the member of Storage that holds Field. The generator specializes it
// for the API structures, the Decoded_ wrappers and the decode::args command storage. The primary template is
// undefined: without a specialization FieldStoreFor and Addressable are false, not a hard error.
template <typename Storage, typename Field>
struct MemberPointer;

// NotAddressable is the MemberPointer value for a bitfield member: &Storage::member does not exist for a bitfield
// ([class.bit]/3), so GetRef cannot serve it. Its generated MemberPointer specialization derives from
// NonAddressableMember and supplies static Get and Set accessors instead.
struct NotAddressable
{};

struct NonAddressableMember
{
    static constexpr NotAddressable value{};
};

template <typename Storage, typename Field>
concept FieldStoreFor = requires
{
    MemberPointer<std::remove_cv_t<Storage>, Field>::value;
};

template <typename Storage, typename Field>
concept FieldWithSelector = FieldStoreFor<Storage, typename Field::selector_field>;

template <typename Storage, typename Field>
concept FieldWithLength = requires(const Storage& storage)
{
    LengthOf_t<Field>::Get(storage);
};

template <typename Storage, typename Field>
concept Addressable = requires
{
    requires std::is_member_object_pointer_v<decltype(MemberPointer<std::remove_cv_t<Storage>, Field>::value)>;
};

template <typename Storage, typename Field>
concept NonAddressable = FieldStoreFor<Storage, Field> &&(!Addressable<Storage, Field>);

// Returns a reference to an addressable member. The constraint removes it from the overload set for a bitfield member,
// which Get and Set serve instead.
template <typename Storage, typename Field>
requires Addressable<Storage, Field>
[[nodiscard]] decltype(auto) GetRef(Storage& storage, Field)
{
    return (storage.*MemberPointer<std::remove_cv_t<Storage>, Field>::value);
}

// Returns a const reference to an addressable member, or a bitfield member's value through the generated Get. Binding
// the result to const auto& is safe in both cases; take a copy with auto.
template <typename Storage, typename Field>
requires FieldStoreFor<Storage, Field>
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

// Writes value to the member: through GetRef when addressable, through the generated Set for a bitfield member. It is
// the only write available for a bitfield member.
template <typename Storage, typename Field, typename ValueType>
requires FieldStoreFor<Storage, Field>
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

// The form concepts below each take a Field and test its declaration under any outer Const (RemoveConst_t).

// VoidReturnField matches a void command's return Field: Void by value, with no runtime value, no storage member and
// no encoded bytes. The generator emits one is_return Field for every command, Void for a void command, so
// ReturnFields_t finds exactly one and ParameterFields_t drops it.
template <typename Field>
concept VoidReturnField = ApiElement<RemoveConst_t<typename Field::declaration>> &&
    std::same_as<typename RemoveConst_t<typename Field::declaration>::category, category::Void>;

// ValueField matches a directly held value: the declaration is an API element.
template <typename Field>
concept ValueField = ApiElement<RemoveConst_t<typename Field::declaration>> && !VoidReturnField<Field>;

// ExtensionChainField matches a structure's pNext Field: a Pointer whose leaf is ExtensionChain. The type of each node
// in the chain is selected at run time from its encoded sType.
template <typename Field>
concept ExtensionChainField = std::is_base_of_v<PointerDeclaration, RemoveConst_t<typename Field::declaration>> &&
    std::same_as<typename Field::api_element, ExtensionChain>;

// PointerField matches a pointer to one item. A pNext Field is an ExtensionChainField, not a PointerField.
template <typename Field>
concept PointerField =
    std::is_base_of_v<PointerDeclaration, RemoveConst_t<typename Field::declaration>> && !ExtensionChainField<Field>;

// PointerToPointerField matches a pointer to a pointer: an output slot the callee fills with an address (void** ppData,
// AHardwareBuffer** pBuffer). Only command parameters have this form; no structure member does.
template <typename Field>
concept PointerToPointerField = PointerField<Field> &&
    std::is_base_of_v<PointerDeclaration, RemoveConst_t<typename RemoveConst_t<typename Field::declaration>::element>>;

// PointerArrayField matches an Array whose item is a Pointer: count pointers, each to one item, and nothing more.
// EncoderAdapter encodes what each pointer points at by category: one structure, or a null-terminated string.
template <typename Field>
concept PointerArrayField = std::is_base_of_v<ArrayDeclaration, RemoveConst_t<typename Field::declaration>> &&
    std::is_base_of_v<PointerDeclaration, RemoveConst_t<typename RemoveConst_t<typename Field::declaration>::element>>;

// ArrayField matches a pointer to a run of items, with a length. An Array of pointers is a PointerArrayField instead.
template <typename Field>
concept ArrayField =
    std::is_base_of_v<ArrayDeclaration, RemoveConst_t<typename Field::declaration>> && !PointerArrayField<Field>;

// FixedArrayField matches a fixed-extent array declared in the storage type itself.
template <typename Field>
concept FixedArrayField = std::is_base_of_v<FixedArrayDeclaration, RemoveConst_t<typename Field::declaration>>;

// Category concepts take an API element, a Field's api_element; form concepts take the Field. Combine them:
// OpaqueApiElement<typename F::api_element> && PointerField<F> is a pointer to an opaque object.
template <typename E>
concept HandleApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Handle>;

template <typename Field>
concept HandleValueField = HandleApiElement<typename Field::api_element> && ValueField<Field>;

// ScalarApiElement matches scalar, enum and bitmask API elements; both Actions read or write them as WireTypeOf_t.
template <typename E>
concept ScalarApiElement = ApiElement<E> &&
    (std::same_as<CategoryOf_t<E>, category::Scalar> || std::same_as<CategoryOf_t<E>, category::Enum> ||
     std::same_as<CategoryOf_t<E>, category::Bitmask>);

template <typename Field>
concept ScalarValueField = ScalarApiElement<typename Field::api_element> && ValueField<Field>;

// TextApiElement matches the text categories, Char and WChar.
// Interim until stage 3: text becomes a Char or WChar scalar with a length token on the Field.
template <typename E>
concept TextApiElement = ApiElement<E> && std::derived_from<CategoryOf_t<E>, category::Text>;

// StructApiElement matches structures and unions. A union Field takes the structure Apply;
// decode/custom_vulkan_struct_decoders.cpp and encode/custom_vulkan_struct_encoders.cpp hold the hand-written
// DecodeStruct and EncodeStruct union overloads it reaches.
template <typename E>
concept StructApiElement = ApiElement<E> &&
    (std::same_as<CategoryOf_t<E>, category::Struct> || std::same_as<CategoryOf_t<E>, category::Union>);

// UnionApiElement matches a union. Its Schema lists Alternatives, not Fields; see schema/schema.h.
template <typename E>
concept UnionApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Union>;

template <typename E>
concept EnumApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Enum>;

template <typename E>
concept BitmaskApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Bitmask>;

// OpaqueApiElement matches a type the API declares and never describes: a platform structure reached through a pointer
// (ANativeWindow), or a platform handle typedef held by value (HWND). It is recorded as the address, never followed.
template <typename E>
concept OpaqueApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Opaque>;

template <typename E>
concept FuncpointerApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Funcpointer>;

// VoidApiElement matches void. A Pointer to it is recorded as an address, an Array of it as a run of bytes, and a
// value of it is a command's void return.
template <typename E>
concept VoidApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Void>;

// IdentifierApiElement matches the API elements recorded as an identifier rather than the thing itself: a handle's
// capture id, or the address of an opaque object or function. The decode Action writes the identifier to the Decoded_
// wrapper member and nulls the API structure's member; replay maps handle members through MapStructHandles.
template <typename E>
concept IdentifierApiElement = HandleApiElement<E> || OpaqueApiElement<E> || FuncpointerApiElement<E>;

// GeneralScalarApiElement matches the API elements encoded from the member's own bits: scalar, enum, bitmask, opaque
// and funcpointer. Handle is excluded: a handle value is encoded as its capture id.
template <typename E>
concept GeneralScalarApiElement = ScalarApiElement<E> || OpaqueApiElement<E> || FuncpointerApiElement<E>;

// AnyPointerField matches any pointer form. Constrain on it where the body ignores the length: a PointerDecoder reads
// length and depth from the capture, so a pointer to one item is a run of one and a run of pointers is one more level.
template <typename Field>
concept AnyPointerField = PointerField<Field> || ArrayField<Field> || PointerArrayField<Field>;

template <typename Field>
concept AnyCountedField = ArrayField<Field> || PointerArrayField<Field>;

// AnyArrayField matches a counted or fixed run of items. EncoderAdapter's array entries take either, since both pass a
// pointer and a count; the encode Action computes the count differently for each.
template <typename Field>
concept AnyArrayField = FixedArrayField<Field> || ArrayField<Field>;

// IntegralLength matches what a count operand may yield: an integer, or a C enum standing for one, as
// rasterizationSamples does. bool is excluded: it is an integer to the language, not a count.
template <typename T>
concept IntegralLength = (std::integral<T> && !std::same_as<T, bool>) || std::is_enum_v<T>;

template <typename Operand, typename Store>
using OperandValue_t = decltype(Operand::Get(std::declval<const Store&>()));

// FieldValue reads a length from storage. FieldValue<F> reads F's member. FieldValue<F, Member> reads Member from the
// structure F points at, e.g. FieldValue<pAllocateInfo, fields::VkCommandBufferAllocateInfo::commandBufferCount>.
template <typename Field, typename... Member>
struct FieldValue;

template <typename Field>
struct FieldValue<Field> : StoreValueBase
{
    template <typename Store>
    requires FieldStoreFor<Store, Field>
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
    requires FieldStoreFor<FieldStore<Store>, Member>
    [[nodiscard]] static auto Get(const Store& store) { return schema::Get(*FieldValue<Field>::Get(store), Member{}); }
};

// Literal<V> yields V, in the type the generator gave the literal. An API constant such as VK_UUID_SIZE is a macro, so
// V carries its value and the NOTE comment above the generated Field carries its name.
template <auto V>
struct Literal : StoreValueBase
{
    template <typename Store>
    [[nodiscard]] static constexpr auto Get(const Store&)
    {
        return V;
    }
};

// Sum, Product and Quotient compute in their operands' own types under the usual arithmetic conversions. The generator
// writes a literal unsigned (Literal<4u>) unless an enum operand takes part, so no sign conversion occurs. The encode
// Action narrows the result to size_t once. Registry len attributes use these three operators only; a new one is a
// StoreValue here and a case in parse_count_expression (vulkan_schema_generator.py).
template <StoreValue Left, StoreValue Right>
struct Sum : StoreValueBase
{
    template <typename Store>
    requires IntegralLength<OperandValue_t<Left, Store>> && IntegralLength<OperandValue_t<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) + Right::Get(store); }
};

template <StoreValue Left, StoreValue Right>
struct Product : StoreValueBase
{
    template <typename Store>
    requires IntegralLength<OperandValue_t<Left, Store>> && IntegralLength<OperandValue_t<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) * Right::Get(store); }
};

template <StoreValue Left, StoreValue Right>
struct Quotient : StoreValueBase
{
    template <typename Store>
    requires IntegralLength<OperandValue_t<Left, Store>> && IntegralLength<OperandValue_t<Right, Store>>
    [[nodiscard]] static constexpr auto Get(const Store& store) { return Left::Get(store) / Right::Get(store); }
};

template <typename Storage, typename Field, typename ValueType>
concept StoresFieldAs = Addressable<Storage, Field> && requires(Storage& storage, Field field)
{
    requires std::same_as<std::remove_cvref_t<decltype(GetRef(storage, field))>, ValueType>;
};

template <typename Storage, typename Field>
concept StoresElementField = StoresFieldAs<Storage, Field, ApiTypeOf_t<typename Field::api_element>>;

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_FIELD_H
