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
#include "util/type_list.h"

#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// An expression value derives from ExpressionValueBase and has a static Get(const Storage&) that yields a value. An
// Array or FixedArray takes one as its length, and an Action evaluates it on the storage that holds the Field.
struct ExpressionValueBase
{};

template <typename T>
concept ExpressionValue = std::derived_from<T, ExpressionValueBase>;

// A Field's declaration is an API element, or a form over a declaration. The forms nest as the C declarator nests:
// `const T* const*` with length n is Array<Const<Pointer<Const<T>>>, n>, and the API element is the leaf. Pointer,
// Array and FixedArray derive from Declaration<D>, whose type is D, the declaration inside the form. Const has no such
// member. Each form also derives from its tag type below, which the form concepts test.
struct DeclarationBase
{};

template <typename D>
struct Declaration : DeclarationBase
{
    using type = D;
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

// UseCapacity, NullTerminated and UnknownLength are the length tokens, used in place of an expression value.
// UseCapacity: a FixedArray's length is all N items. NullTerminated: the run ends at its first zero item (Vulkan: the
// registry's len="null-terminated"); a run of char or wchar_t with it is a string. UnknownLength: the API description
// gives a length that maps to no expression value (Vulkan: a registry len attribute), and the Field carries its text
// as source_length_expression. A token is not an expression value, so FieldWithLength is false for its Field, and a
// token has no Get.
struct UseCapacity
{};
struct NullTerminated
{};
struct UnknownLength
{};

template <typename T>
concept LengthDescriptor = ExpressionValue<T> || std::same_as<T, UnknownLength> || std::same_as<T, NullTerminated>;

// Const applies const at this level of the declaration.
template <typename D>
requires IsDeclaration_v<D>
struct Const : DeclarationBase, ConstDeclaration
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
// N, NullTerminated for a string, or the expression value of a sibling count member.
template <typename D, typename Length, size_t N>
requires IsDeclaration_v<D>
struct FixedArray : Declaration<D>, FixedArrayDeclaration
{
    static_assert(ExpressionValue<Length> || std::same_as<Length, UseCapacity> || std::same_as<Length, NullTerminated>,
                  "A FixedArray's length is UseCapacity, NullTerminated or an expression value");
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

GFXRECON_BEGIN_NAMESPACE(detail)

// InnerType_t is the declaration inside a Pointer, Array or FixedArray Field, without Const: for
// Array<Const<Pointer<T>>, n> it is Pointer<T>.
template <typename Field>
using InnerType_t = RemoveConst_t<typename RemoveConst_t<typename Field::declaration>::type>;

GFXRECON_END_NAMESPACE(detail)

// A semantic token states a fact about a Field that its declaration cannot. On a pointer to Void it states what the
// pointer holds. A Field lists its tokens in semantics.
GFXRECON_BEGIN_NAMESPACE(semantic)

// ExtensionChain: the pointer holds a chain of structures, and the type of each is selected at run time by the
// structure type it starts with.
struct ExtensionChain
{};

// ValidExtensions: the API description lists structures that can follow this structure in its extension chain, as
// the structure extended or as one that extends another (Vulkan: the registry's structextends attribute).
struct ValidExtensions
{};

GFXRECON_END_NAMESPACE(semantic)

// FieldBase is the base of every Field. A Field is one struct per use, in a namespace named for the owner, e.g.
// `struct buffer : Field<"buffer", api_elements::VkBuffer> { ... };`, so each use is its own type: for its accessor,
// for the per-use members below, and in diagnostics.
struct FieldBase
{};

template <util::FixedString Name, typename D>
requires IsDeclaration_v<D>
struct Field : FieldBase
{
    using declaration = D;
    using api_element = RemoveDeclarators_t<D>;
    using semantics   = util::TypeList<>;

    static constexpr std::string_view field_name = Name.view();
};

template <typename T>
inline constexpr bool IsField_v = std::is_base_of_v<FieldBase, T>;

// A Field has only the members below. A Field states what one use is. category and element_type are read from
// api_element, never restated on the Field.
//
//   declaration       Every Field, from the Field base: the API element, or a form over it as C declares it.
//   api_element       Every Field, from the Field base: the API element at the leaf of declaration.
//   field_name        Every Field, from the Field base: the member or parameter name in the API description, for
//                     diagnostics. Not `name`: an API can declare a member called name (Vulkan does), and a member
//                     cannot share the name of its class.
//   semantics         Every Field: the TypeList of its semantic tokens, empty from the Field base.
//   GetRef            Every Field but a bitfield and a void return: returns a reference to the member of this name
//                     in any storage type that has one. A storage type without the member is a substitution failure,
//                     so StorageFor is false and not a hard error.
//   bit_width         A bitfield only: std::integral_constant holding the bit count in the API description (Vulkan:
//                     the registry's `: N`).
//   Get, Set          A bitfield only, in place of GetRef: a bitfield has no address ([class.bit]/3).
//   is_return         A command's return Field only, always true. Absent means false: kIsReturnField in schema.h
//                     reads it that way, so no other Field states it.
//   source_length_expression
//                     An Array whose length is UnknownLength: the length text as the API description writes it
//                     (Vulkan: the registry's len attribute), kept so it is not lost.
//   selector_field    A union-typed member only: the sibling Field whose value selects the union alternative, from
//                     the API description (Vulkan: the registry's selector attribute).
//   objecttype_field  An integer member that holds a handle only: the sibling Field that holds the handle's object
//                     type, from the API description (Vulkan: the registry's objecttype attribute).
//   selections        A union alternative the API description marks: the selector values that choose it (Vulkan: the
//                     registry's selection attribute).

template <ApiElement E>
using CategoryOf_t = typename E::category;

// LengthOf_t is the length of an Array or FixedArray Field: an expression value (FieldValue, Literal, Sum, Product,
// Quotient), UseCapacity, NullTerminated, or UnknownLength.
template <typename Field>
using LengthOf_t = typename RemoveConst_t<typename Field::declaration>::length;

// DeclaredExtentsMatch is true when ArrayType, the type storage declares the member as, has the rank and extents of
// the Field's declaration.
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

// FieldWithBitWidth matches a bitfield Field: it carries bit_width, and Get and Set in place of GetRef.
template <typename Field>
concept FieldWithBitWidth = requires
{
    typename Field::bit_width;
};

// StorageFor is true when Storage has the member Field reads: the Field's accessor accepts it. The API structure, its
// Decoded_ wrapper and a command's decode::args structure spell a member the same way, so one accessor serves all.
template <typename Storage, typename Field>
concept StorageFor = requires(Storage& storage)
{
    Field::GetRef(storage);
}
|| requires(const Storage& storage)
{
    Field::Get(storage);
};

// FieldWithObjectType matches a Field that carries objecttype_field: an integer that holds a handle. It tests the
// Field alone. StorageWithObjectType adds that Storage holds the object type sibling, for a body that reads the
// sibling's value.
template <typename Field>
concept FieldWithObjectType = requires
{
    typename Field::objecttype_field;
};

template <typename Storage, typename Field>
concept StorageWithObjectType = FieldWithObjectType<Field> && StorageFor<Storage, typename Field::objecttype_field>;

// FieldWithLength matches a Field whose declared length is an expression value, a count member or an expression over
// members, and not a length token. It tests the Field alone. StorageWithLength adds that Storage can evaluate
// that length, for a body that reads the count.
template <typename Field>
concept FieldWithLength = requires
{
    requires ExpressionValue<LengthOf_t<Field>>;
};

template <typename Storage, typename Field>
concept StorageWithLength = FieldWithLength<Field> && requires(const Storage& storage)
{
    LengthOf_t<Field>::Get(storage);
};

// Returns a const reference to the member, or a bitfield member's value through the Field's Get. Binding the result
// to const auto& is safe in both cases; take a copy with auto. Get and Set are the only accessors that serve a
// bitfield; every other read or write calls Field::GetRef(storage).
template <typename Storage, typename Field>
requires StorageFor<Storage, Field>
[[nodiscard]] decltype(auto) Get(const Storage& storage, Field)
{
    if constexpr (FieldWithBitWidth<Field>)
    {
        return Field::Get(storage);
    }
    else
    {
        return Field::GetRef(storage);
    }
}

// Writes value to the member: through the Field's Set for a bitfield, else through Field::GetRef.
template <typename Storage, typename Field, typename ValueType>
requires StorageFor<Storage, Field>
void Set(Storage& storage, Field, ValueType&& value)
{
    if constexpr (FieldWithBitWidth<Field>)
    {
        Field::Set(storage, value);
    }
    else
    {
        Field::GetRef(storage) = std::forward<ValueType>(value);
    }
}

// StoredTypeOf_t is the type Storage declares Field's member as, without reference or cv-qualifiers.
template <typename Storage, typename Field>
requires StorageFor<Storage, Field>
using StoredTypeOf_t =
    std::remove_cvref_t<decltype(schema::Get(std::declval<const Storage&>(), std::declval<Field>()))>;

// The form concepts below each take a Field and test its declaration under any outer Const (RemoveConst_t).

// VoidReturnField matches a void command's return Field: Void by value, with no runtime value and no storage member.
// Every command has exactly one is_return Field, Void for a void command, so ReturnFields_t finds exactly one and
// ParameterFields_t drops it.
template <typename Field>
concept VoidReturnField = ApiElement<RemoveConst_t<typename Field::declaration>> &&
    std::same_as<typename RemoveConst_t<typename Field::declaration>::category, category::Void>;

// ValueField matches a directly held value: the declaration is an API element. A void return has no value and is not
// a ValueField.
template <typename Field>
concept ValueField = ApiElement<RemoveConst_t<typename Field::declaration>> && !VoidReturnField<Field>;

// PointerField matches a pointer to one item.
template <typename Field>
concept PointerField = std::is_base_of_v<PointerDeclaration, RemoveConst_t<typename Field::declaration>>;

// ExtensionChainField matches a structure's pNext Field: a PointerField whose Field carries the ExtensionChain token.
template <typename Field>
concept ExtensionChainField =
    PointerField<Field> && util::TypeListContains_v<typename Field::semantics, semantic::ExtensionChain>;

// PointerToPointerField matches a pointer to a pointer: an output slot the callee fills with an address (void** ppData,
// AHardwareBuffer** pBuffer). Only command parameters have this form; no structure member does.
template <typename Field>
concept PointerToPointerField =
    PointerField<Field> && std::is_base_of_v<PointerDeclaration, detail::InnerType_t<Field>>;

// ArrayField matches a pointer to a run of items, with a length.
template <typename Field>
concept ArrayField = std::is_base_of_v<ArrayDeclaration, RemoveConst_t<typename Field::declaration>>;

// PointerArrayField matches an ArrayField whose item is a Pointer: count pointers, each to one item, and nothing more.
template <typename Field>
concept PointerArrayField = ArrayField<Field> && std::is_base_of_v<PointerDeclaration, detail::InnerType_t<Field>>;

// FixedArrayField matches a fixed-extent array declared in the storage type itself.
template <typename Field>
concept FixedArrayField = std::is_base_of_v<FixedArrayDeclaration, RemoveConst_t<typename Field::declaration>>;

GFXRECON_BEGIN_NAMESPACE(detail)

template <typename T>
concept CharacterType = std::same_as<T, char> || std::same_as<T, wchar_t>;

// StringDeclaration matches the declaration of a string: an Array or FixedArray of char or wchar_t whose length is
// NullTerminated.
template <typename D>
concept StringDeclaration =
    std::same_as<typename D::length, NullTerminated> && CharacterType<ApiTypeOf_t<RemoveConst_t<typename D::type>>>;

GFXRECON_END_NAMESPACE(detail)

// StringField matches a Field whose declaration is a string.
// StringArrayField matches a counted run of strings, const char* const*: an ArrayField whose inner type is a string.
template <typename Field>
concept StringField = detail::StringDeclaration<RemoveConst_t<typename Field::declaration>>;

template <typename Field>
concept StringArrayField = ArrayField<Field> && detail::StringDeclaration<detail::InnerType_t<Field>>;

// Category concepts take an API element, a Field's api_element; form concepts take the Field. Combine them:
// VoidApiElement<typename F::api_element> && PointerField<F> is a pointer to void.
template <typename E>
concept HandleApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Handle>;

// SimpleApiElement matches scalar, enum and bitmask API elements; both Actions read or write them as WireTypeOf_t.
template <typename E>
concept SimpleApiElement = ApiElement<E> &&
    (std::same_as<CategoryOf_t<E>, category::Scalar> || std::same_as<CategoryOf_t<E>, category::Enum> ||
     std::same_as<CategoryOf_t<E>, category::Bitmask>);

// StructOrUnionApiElement matches structures and unions.
template <typename E>
concept StructOrUnionApiElement = ApiElement<E> &&
    (std::same_as<CategoryOf_t<E>, category::Struct> || std::same_as<CategoryOf_t<E>, category::Union>);

// UnionApiElement matches a union. Its Schema lists Alternatives, not Fields; see schema/schema.h.
template <typename E>
concept UnionApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Union>;

template <typename E>
concept EnumApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Enum>;

template <typename E>
concept BitmaskApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Bitmask>;

template <typename E>
concept FuncpointerApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Funcpointer>;

// VoidApiElement matches void and the platform types with no C definition in the API headers (ANativeWindow,
// deref_HWND). A Pointer to it is recorded as an address, an Array of it as a run of bytes, and a value of it is a
// command's void return.
template <typename E>
concept VoidApiElement = ApiElement<E> && std::same_as<CategoryOf_t<E>, category::Void>;

// IdentifierApiElement matches a handle or a function pointer: a value that has meaning only in the process that
// created it.
template <typename E>
concept IdentifierApiElement = HandleApiElement<E> || FuncpointerApiElement<E>;

GFXRECON_BEGIN_NAMESPACE(detail)

// Integer matches an operand of Sum, Product and Quotient: an integer other than bool, which is an integer to the
// language and not a count. IntegerOrEnum matches a Literal's value: an integer or an enumerator.
template <typename T>
concept Integer = std::integral<T> && !std::same_as<T, bool>;

template <typename T>
concept IntegerOrEnum = Integer<T> || std::is_enum_v<T>;

GFXRECON_END_NAMESPACE(detail)

template <typename Operand, typename Storage>
using OperandValue_t = decltype(Operand::Get(std::declval<const Storage&>()));

// FieldValue<F> reads F's member from storage.
template <typename Field>
struct FieldValue : ExpressionValueBase
{
    template <typename Storage>
    requires StorageFor<Storage, Field>
    [[nodiscard]] static auto Get(const Storage& storage) { return schema::Get(storage, Field{}); }
};

// Deref<Operand> yields what the pointer Operand yields points at, as a reference.
// NOTE: MUST NOT be evaluated on a null pointer; Get does not test it.
template <ExpressionValue Operand>
struct Deref : ExpressionValueBase
{
    template <typename Storage>
    requires std::is_pointer_v<std::remove_cvref_t<OperandValue_t<Operand, Storage>>>
    [[nodiscard]] static decltype(auto) Get(const Storage& storage) { return *Operand::Get(storage); }
};

// StorageValue<Base, F> reads F's member from the storage Base yields, so the spelling follows the source:
// StorageValue<Deref<FieldValue<pAllocateInfo>>, fields::VkCommandBufferAllocateInfo::commandBufferCount> is
// pAllocateInfo->commandBufferCount.
template <ExpressionValue Base, typename Field>
struct StorageValue : ExpressionValueBase
{
    template <typename Storage>
    requires StorageFor<std::remove_cvref_t<OperandValue_t<Base, Storage>>, Field>
    [[nodiscard]] static auto Get(const Storage& storage) { return schema::Get(Base::Get(storage), Field{}); }
};

// Literal<V> yields V as declared, an integer or an enumerator. An API constant such as VK_UUID_SIZE is a macro, so
// V carries its value and the NOTE comment above the generated Field carries its name.
template <detail::IntegerOrEnum auto V>
struct Literal : ExpressionValueBase
{
    using value_type = decltype(V);

    template <typename Storage>
    [[nodiscard]] static constexpr value_type Get(const Storage&)
    {
        return V;
    }
};

// AsInteger<Operand> yields an enum-valued Operand as its underlying integer type, so that an operator can take it.
// For a C enum the underlying type is the compiler's choice, so the result's signedness is not portable; its value is.
template <ExpressionValue Operand>
struct AsInteger : ExpressionValueBase
{
    template <typename Storage>
    requires std::is_enum_v<OperandValue_t<Operand, Storage>>
    [[nodiscard]] static constexpr auto Get(const Storage& storage)
    {
        using value_type = std::underlying_type_t<OperandValue_t<Operand, Storage>>;
        return static_cast<value_type>(Operand::Get(storage));
    }
};

// Sum, Product and Quotient compute in their operands' own types under the usual arithmetic conversions.
template <ExpressionValue Left, ExpressionValue Right>
struct Sum : ExpressionValueBase
{
    template <typename Storage>
    requires detail::Integer<OperandValue_t<Left, Storage>> && detail::Integer<OperandValue_t<Right, Storage>>
    [[nodiscard]] static constexpr auto Get(const Storage& storage) { return Left::Get(storage) + Right::Get(storage); }
};

template <ExpressionValue Left, ExpressionValue Right>
struct Product : ExpressionValueBase
{
    template <typename Storage>
    requires detail::Integer<OperandValue_t<Left, Storage>> && detail::Integer<OperandValue_t<Right, Storage>>
    [[nodiscard]] static constexpr auto Get(const Storage& storage) { return Left::Get(storage) * Right::Get(storage); }
};

template <ExpressionValue Left, ExpressionValue Right>
struct Quotient : ExpressionValueBase
{
    template <typename Storage>
    requires detail::Integer<OperandValue_t<Left, Storage>> && detail::Integer<OperandValue_t<Right, Storage>>
    [[nodiscard]] static constexpr auto Get(const Storage& storage) { return Left::Get(storage) / Right::Get(storage); }
};

template <typename Storage, typename Field, typename ValueType>
concept StoresFieldAs = StorageFor<Storage, Field> && std::same_as<StoredTypeOf_t<Storage, Field>, ValueType>;

template <typename Storage, typename Field>
concept StoresElementField = StoresFieldAs<Storage, Field, ApiTypeOf_t<typename Field::api_element>>;

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_FIELD_H
