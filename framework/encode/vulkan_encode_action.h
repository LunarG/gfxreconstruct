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

// EncodeStructAction is the Apply overload set schema::WalkFields applies to an API structure's schema. If no Apply
// accepts a Field, a static_assert in WalkFields stops the compile and shows the Field.
//
// Each Apply reads its Field's member with schema::Get, and for a run its count from LengthOf_t<Field>, and passes
// what it read to EncoderAdapter, which selects the encoder call by the category of the Field's API element and reads
// no storage. The extension-chain and generic-handle overloads call the encoder directly.
//
// Limitations:
//   - A Field that an Apply accepts but no EncoderAdapter overload does fails to compile inside that Apply, as a call
//     with no matching EncoderAdapter overload, not at the WalkFields static_assert. No adapter overload takes a
//     pointer to a pointer, a Pointer to a handle, a PointerArray of scalars or handles, or a run of function-pointer
//     API elements.
//   - A FixedArray above two dimensions, or of two dimensions with a count member, fails a static_assert in its Apply.
//
// Lifetime: the Action holds the ParameterEncoder pointer without owning it and keeps no other state, so one instance
// may walk any number of structures.
//
// Typical pattern (encode/vulkan_encode_struct_impl.h), after EncodeStructAction action(encoder):
//   schema::WalkFields<ApiElement>(action, value);
//
// Future work, for the Apply set to serve another API:
//   1. EncodeStructAction takes its adapter as a template parameter instead of spelling EncoderAdapter.
//   2. The Vulkan facts in the Apply set, vulkan_wrappers::GetWrappedId in the generic-handle overload, move into the
//      adapter or the schema.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_encode_capture_wrappers.h"
#include "binding/vulkan_wire_type.h"
#include "schema/field.h"

// Required by the StorageFor and Addressable constraints below.
#include "generated/generated_vulkan_schema_api_struct_members.h"

#include "util/defines.h"

#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// TextAttributeOf_v is the attribute word a string is written under: kIsWString for a wchar_t element, kIsString for
// char.
template <schema::ScalarApiElement Element>
inline constexpr format::PointerAttributes TextAttributeOf_v =
    std::same_as<typename Element::element_type, wchar_t> ? format::PointerAttributes::kIsWString
                                                          : format::PointerAttributes::kIsString;

// Each operator() makes one encoder call for one category and shape of the Field's API element.
struct EncoderAdapter
{
    // Encodes a scalar or function-pointer value as its WireTypeOf. A scalar member is declared as its API element
    // type, since a platform typedef is its own API element; a function-pointer member is a pointer type, which
    // EncodeAs reinterpret_casts to the address.
    template <typename Field, typename DeclaredType>
    requires(schema::ScalarApiElement<typename Field::api_element> ||
             schema::FuncpointerApiElement<typename Field::api_element>) &&
        schema::ValueField<Field> void operator()(Field, ParameterEncoder* encoder, const DeclaredType& value) const
    {
        static_assert(!schema::ScalarApiElement<typename Field::api_element> ||
                          std::is_same_v<DeclaredType, schema::ApiTypeOf_t<typename Field::api_element>>,
                      "A scalar member is declared as its API element type");
        encoder->EncodeAs<binding::WireTypeOf_t<typename Field::api_element>>(value);
    }

    template <typename Field>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::PointerField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>* pointer) const
    {
        encoder->EncodePointerAs<binding::WireTypeOf_t<typename Field::api_element>>(pointer);
    }

    // Records the pointer's address only: what a void pointer points at is never described. Pointer<Void> and the
    // platform types curation leaves undefined, Pointer<ANativeWindow>, Pointer<deref_HWND>, take this overload.
    template <typename Field, typename T>
    requires schema::VoidApiElement<typename Field::api_element> && schema::PointerField<Field> &&
        (!schema::PointerToPointerField<Field>)void
        operator()(Field, ParameterEncoder* encoder, T* pointer) const
    {
        encoder->EncodeVoidPtr(pointer);
    }

    template <typename Field>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::AnyArrayField<Field> &&
        (!schema::NullTerminatedField<Field>)void
        operator()(Field,
                   ParameterEncoder*                                       encoder,
                   const schema::ApiTypeOf_t<typename Field::api_element>* array,
                   size_t                                                  count) const
    {
        encoder->EncodeArrayAs<binding::WireTypeOf_t<typename Field::api_element>>(array, count);
    }

    template <typename Field>
    requires schema::VoidApiElement<typename Field::api_element> && schema::ArrayField<Field>
    void operator()(Field, ParameterEncoder* encoder, const void* bytes, size_t count) const
    {
        encoder->EncodeUInt8Array(bytes, count);
    }

    // Encodes a handle, by value or in a run, as its capture wrapper's id. CaptureWrapperOf gives the wrapper type; a
    // handle API element without a CaptureWrapperOf specialization matches neither overload.
    template <typename Field>
    requires schema::HandleApiElement<typename Field::api_element> && schema::ValueField<Field> &&
        ApiElementWithCaptureWrapper<typename Field::api_element>
    void operator()(Field                                                   field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>& handle) const
    {
        using Wrapper = CaptureWrapperOf_t<typename Field::api_element>;
        encoder->template EncodeVulkanHandleValue<Wrapper>(handle);
    }

    template <typename Field>
    requires schema::HandleApiElement<typename Field::api_element> && schema::AnyArrayField<Field> &&
        ApiElementWithCaptureWrapper<typename Field::api_element>
    void operator()(Field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* array,
                    size_t                                                  count) const
    {
        using Wrapper = CaptureWrapperOf_t<typename Field::api_element>;
        encoder->template EncodeVulkanHandleArray<Wrapper>(array, count);
    }

    // Encodes a structure by value, by pointer or in a run through EncodeStruct; EncodeStructPtr and EncodeStructArray
    // call it per element. A union or a CUSTOM_ENCODE structure reaches its hand-written overload.
    template <typename Field>
    requires schema::StructApiElement<typename Field::api_element> && schema::ValueField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>& value) const
    {
        EncodeStruct(encoder, value);
    }

    template <typename Field>
    requires schema::StructApiElement<typename Field::api_element> && schema::PointerField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>* pointer) const
    {
        EncodeStructPtr(encoder, pointer);
    }

    template <typename Field>
    requires schema::StructApiElement<typename Field::api_element> && schema::AnyArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* array,
                    size_t                                                  count) const
    {
        EncodeStructArray(encoder, array, count);
    }

    // Encodes a run of pointers, each to one structure, as EncodeStructArray2D with every inner length 1. The 1 is the
    // Pointer shape, not an extent, so the schema records none.
    template <typename Field>
    requires schema::StructApiElement<typename Field::api_element> && schema::PointerArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                              encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* const* rows,
                    size_t                                                         count) const
    {
        EncodeStructArray2D(encoder, rows, count, 1);
    }

    // Encodes a string, Array<Const<Char>, NullTerminated>: the run ends at its terminator, so no count is passed.
    template <typename Field>
    requires schema::NullTerminatedField<Field> && schema::ArrayField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>* text) const
    {
        encoder->EncodeStringAs<binding::WireTypeOf_t<typename Field::api_element>,
                                TextAttributeOf_v<typename Field::api_element>>(text);
    }

    template <typename Field>
    requires schema::NullTerminatedField<Field> && schema::FixedArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* text,
                    size_t                                                  capacity) const
    {
        static_assert(std::rank_v<schema::ApiTypeOf_t<typename Field::declaration>> == 1,
                      "A fixed-extent string has one dimension");
        encoder->EncodeStringAs<binding::WireTypeOf_t<typename Field::api_element>,
                                TextAttributeOf_v<typename Field::api_element>>(text, capacity);
    }

    template <typename Field>
    requires schema::NullTerminatedArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                              encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* const* strings,
                    size_t                                                         count) const
    {
        encoder->EncodeStringArrayAs<binding::WireTypeOf_t<typename Field::api_element>,
                                     TextAttributeOf_v<typename Field::api_element>>(strings, count);
    }
};

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    // Encodes a value of any category EncoderAdapter takes. schema::Get references an ordinary member in place, or
    // reads a bitfield through its generated accessor, so one overload serves both.
    template <typename Field, typename Storage>
    requires schema::ValueField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Field field, const Storage& storage) { EncoderAdapter()(field, encoder_, schema::Get(storage, field)); }

    template <typename Field, typename Storage>
    requires schema::PointerField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Field field, const Storage& storage) { EncoderAdapter()(field, encoder_, schema::Get(storage, field)); }

    // Encodes a string, Array<Const<Char>, NullTerminated>: the terminator is the length, so no count member is read.
    template <typename Field, typename Storage>
    requires schema::NullTerminatedField<Field> && schema::ArrayField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Field field, const Storage& storage) { EncoderAdapter()(field, encoder_, schema::Get(storage, field)); }

    // Encodes an Array, a pointer to a run, or a PointerArray, a run of pointers each to one item, with its count:
    // LengthOf_t<Field> evaluated on the structure, a member or an expression over members (e.g. pCode's codeSize / 4).
    template <typename Field, typename Storage>
    requires schema::AnyCountedField<Field> && schema::StorageFor<Storage, Field> &&
        schema::StorageWithLength<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using Length = schema::LengthOf_t<Field>;

        const size_t count = GFXRECON_NARROWING_CAST(size_t, Length::Get(storage));
        EncoderAdapter()(field, encoder_, schema::Get(storage, field), count);
    }

    // Encodes a fixed-extent array of one or two dimensions as one run from the first element: a two-dimensional array
    // is a run of the extent product, as the 2DMatrix entry points do. The extents come from the API member's declared
    // type; the static_asserts hold the Field's recorded extents equal to them.
    //
    // If a count field is present the static extent is treated as the capacity, and count elements up to capacity are
    // written.
    template <typename Field, typename Storage>
    requires schema::FixedArrayField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const auto& array_ref = schema::GetRef(storage, field);
        using ArrayType       = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        size_t count = std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            static_assert(!(schema::StorageWithLength<Storage, Field>),
                          "A multi-dimensional fixed-extent array with a count field is not yet schema enabled");
            EncoderAdapter()(field, encoder_, &array_ref[0][0], count);
        }
        else
        {
            if constexpr (schema::StorageWithLength<Storage, Field>)
            {
                using Length = schema::LengthOf_t<Field>;
                // Read in the count member's own type, not narrowed to size_t: ClampStaticArrayLength compares in
                // that type and logs, so a negative count encodes nothing and one above the extent is clamped.
                const auto count_value = Length::Get(storage);
                count = ParameterEncoder::ClampStaticArrayLength(count_value, count, Field::field_name.data());
            }
            EncoderAdapter()(field, encoder_, &array_ref[0], count);
        }
    }

    // Encodes the extension chain. Field::has_extensions is true when the registry lists this structure on either side
    // of structextends: EncodePNextStruct then walks the chain trusting the pointer. Otherwise EncodePNextStructIfValid
    // probes the pointer first, since the spec then usually requires NULL, driver-written memory may hold garbage
    // there, and vendors chain unregistered structures anyway. Both walks find each node's type by its sType.
    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const void* chain = schema::Get(storage, field);

        if constexpr (Field::has_extensions)
        {
            EncodePNextStruct(encoder_, chain);
        }
        else
        {
            EncodePNextStructIfValid(encoder_, chain);
        }
    }

    // Encodes a generic handle, a uint64_t member the registry marks objecttype: GetWrappedId maps it to its capture
    // id using the object type in the selector Field. EncoderAdapter reads no storage, so this overload reads the
    // selector.
    template <typename Field, typename Storage>
    requires schema::ScalarValueField<Field> && schema::StorageFor<Storage, Field> &&
        schema::StorageWithSelector<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using SelectorField = typename Field::selector_field;
        encoder_->EncodeAs<binding::WireTypeOf_t<typename Field::api_element>>(
            vulkan_wrappers::GetWrappedId(schema::Get(storage, field), schema::Get(storage, SelectorField{})));
    }

  private:
    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
