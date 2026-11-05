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

// The structure Encode Action. schema::WalkFields applies one Apply overload set to a schema's Fields over the API's
// own structure. Each Apply reads its shape from storage and hands the value, pointer or run to EncoderAdapter,
// which makes the one encoder call the field's category and shape select. The Action is the only party that touches
// storage; the adapter sees field contents and never the structure they came from.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_encode_capture_wrappers.h"
#include "binding/vulkan_wire_type.h"
#include "schema/field.h"

// This operation reads Vulkan's own structures. Keep the complete generated member-binding population beside the
// Action and private to the translation unit that owns the generic EncodeStruct instantiations.
#include "generated/generated_vulkan_schema_api_struct_members.h"

#include "util/defines.h"

#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Adapters from a Field to the ParameterEncoder and umbrella entry points. The concepts read the Field's category and
// shape; the entry points know nothing of Fields, and each operator() makes the one call the procedural bodies made
// for that combination. Nothing here reads storage, which is what lets a command Action reuse this table unchanged.
//
// Direction, not taken yet: the Action names this type directly. Taking it as a template parameter instead, the way a
// traits type is passed, would make the shape Apply set API-agnostic; the Vulkan facts would then live in this
// adapter and in the schema, and the same Action would serve another API given its adapter.
// Interim until plan 2.4 stage 3: the text attribute word is read from the interim text category; the revision makes
// it a binding on the API element.
template <schema::TextApiElement Element>
inline constexpr format::PointerAttributes TextAttributeOf_v =
    std::same_as<schema::CategoryOf_t<Element>, schema::category::WChar> ? format::PointerAttributes::kIsWString
                                                                         : format::PointerAttributes::kIsString;

struct EncoderAdapter
{
    // A platform typedef is its own API element, so a scalar member's DeclaredType is its API element type; an opaque
    // or funcpointer member is some pointer type, cast to the address.
    template <typename Field, typename DeclaredType>
    requires schema::GeneralScalarApiElement<typename Field::api_element> && schema::ValueField<Field>
    void operator()(Field, ParameterEncoder* encoder, const DeclaredType& value) const
    {
        static_assert(!schema::ScalarApiElement<typename Field::api_element> ||
                          std::is_same_v<DeclaredType, schema::ApiTypeOf_t<typename Field::api_element>>,
                      "A scalar member is declared as its API element type");
        encoder->EncodeAs<binding::WireTypeOf_t<typename Field::api_element>>(value);
    }

    // A pointer to one scalar.
    template <typename Field>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::PointerField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>* pointer) const
    {
        encoder->EncodePointerAs<binding::WireTypeOf_t<typename Field::api_element>>(pointer);
    }

    // A pointer to an opaque object, Pointer<ANativeWindow>, or to void, Pointer<Void>: what it points at is never
    // described, so the pointer's value is the record.
    template <typename Field, typename Pointee>
    requires(schema::OpaqueApiElement<typename Field::api_element> ||
             schema::VoidApiElement<typename Field::api_element>) &&
        schema::PointerField<Field> &&
        (!schema::PointerToPointerField<Field>)void operator()(Field, ParameterEncoder* encoder, Pointee* pointer) const
    {
        encoder->EncodeVoidPtr(pointer);
    }

    // A counted run of scalars.
    template <typename Field>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::AnyArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* array,
                    size_t                                                  count) const
    {
        encoder->EncodeArrayAs<binding::WireTypeOf_t<typename Field::api_element>>(array, count);
    }

    // A counted run of bytes the API declares as void: Array<Const<Void>, n>.
    template <typename Field>
    requires schema::VoidApiElement<typename Field::api_element> && schema::ArrayField<Field>
    void operator()(Field, ParameterEncoder* encoder, const void* bytes, size_t count) const
    {
        encoder->EncodeUInt8Array(bytes, count);
    }

    // Handle category: value, pointer, run. A handle is recorded as its capture wrapper's id, so each entry needs the
    // wrapper type CaptureWrapperOf maps its API element to, and requires ApiElementWithCaptureWrapper.
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
    requires schema::HandleApiElement<typename Field::api_element> && schema::PointerField<Field> &&
        ApiElementWithCaptureWrapper<typename Field::api_element>
    void operator()(Field,
                    ParameterEncoder*                                       encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* handle_pointer) const
    {
        using Wrapper = CaptureWrapperOf_t<typename Field::api_element>;
        // No structure field has this shape; the entry is here for the command Action's output parameters and has no
        // byte gate yet. TODO: determine a mechanism to pass omit_output_data when the adapter serves command
        // parameters: potentially a Field-level fact beside the Return Field, or the generated encoders' result-based
        // rule if it proves uniform enough to import.
        encoder->template EncodeVulkanHandlePtr<Wrapper>(handle_pointer /*, omit_output_data */);
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

    // Struct category: value, pointer, run. Each calls the EncodeStruct overload for the API element's type.
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

    // A run of pointers to structures. On the wire a pointer to one structure is a row of length one, so this is the
    // two-dimensional structure array with every row of length 1. The 1 is the encoder's spelling of the shape, not a
    // schema fact, which is why the API element carries no extent for it.
    template <typename Field>
    requires schema::StructApiElement<typename Field::api_element> && schema::PointerArrayField<Field>
    void operator()(Field,
                    ParameterEncoder*                                              encoder,
                    const schema::ApiTypeOf_t<typename Field::api_element>* const* rows,
                    size_t                                                         count) const
    {
        EncodeStructArray2D(encoder, rows, count, 1);
    }

    template <typename Field>
    requires schema::TextApiElement<typename Field::api_element> && schema::PointerField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::ApiTypeOf_t<typename Field::api_element>* text) const
    {
        encoder->EncodeStringAs<binding::WireTypeOf_t<typename Field::api_element>,
                                TextAttributeOf_v<typename Field::api_element>>(text);
    }

    // A text typedef held by value: the API element is the pointer type the header spells, LPCWSTR, and the value is
    // the null-terminated string it points at.
    template <typename Field>
    requires schema::TextApiElement<typename Field::api_element> && schema::ValueField<Field>
    void operator()(Field, ParameterEncoder* encoder, schema::ApiTypeOf_t<typename Field::api_element> text) const
    {
        encoder->EncodeStringAs<binding::WireTypeOf_t<typename Field::api_element>,
                                TextAttributeOf_v<typename Field::api_element>>(text);
    }

    template <typename Field>
    requires schema::TextApiElement<typename Field::api_element> && schema::FixedArrayField<Field>
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
    requires schema::TextApiElement<typename Field::api_element> && schema::PointerArrayField<Field>
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

    // A value-shaped field of any category the adapter encodes. Get references an ordinary member in place, or yields the
    // value of a non-addressable one (e.g. a bitfield), so one overload serves both.
    template <typename Field, typename Storage>
    requires schema::ValueField<Field> && schema::FieldStoreFor<Storage, Field>
    void Apply(Field field, const Storage& storage) { EncoderAdapter()(field, encoder_, schema::Get(storage, field)); }

    // A pointer to one element. The member holds the pointer, and the pointer is what the encoder needs, so it is
    // read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::PointerField<Field> && schema::FieldStoreFor<Storage, Field>
    void Apply(Field field, const Storage& storage) { EncoderAdapter()(field, encoder_, schema::Get(storage, field)); }

    // A counted run, with a sibling member that holds the count: a pointer to a run of elements (Array), or a run of
    // pointers each to one element (PointerArray). Either way the member holds a pointer, and the pointer is what the
    // encoder needs, so it is read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::AnyCountedField<Field> && schema::FieldStoreFor<Storage, Field> &&
        schema::FieldWithLength<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using Length = schema::LengthOf_t<Field>;

        const size_t count = GFXRECON_NARROWING_CAST(size_t, Length::Get(storage));
        EncoderAdapter()(field, encoder_, schema::Get(storage, field), count);
    }

    // A fixed-extent array of elements, of one or two dimensions. Every named fixed-array entry point, the 2DMatrix
    // family included, is one run over a flat pointer and a length, so a matrix is a run of the extent product and
    // the two ranks share a body. The extents are read from the API member's declared type, as they are on the decode
    // side; the Field records the same extents and the static_assert below holds the two to agree.
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
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A StaticArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        size_t count = std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            static_assert(!(schema::FieldWithLength<Storage, Field>),
                          "A multi-dimensional fixed-extent array with a count field is not yet schema enabled");
            EncoderAdapter()(field, encoder_, &array_ref[0][0], count);
        }
        else
        {
            if constexpr (schema::FieldWithLength<Storage, Field>)
            {
                using Length = schema::LengthOf_t<Field>;
                // The count member's value in its own type; the clamp bounds it by the capacity and reports.
                const auto count_value = Length::Get(storage);
                count = ParameterEncoder::ClampStaticArrayLength(count_value, count, Field::field_name.data());
            }
            EncoderAdapter()(field, encoder_, &array_ref[0], count);
        }
    }

    // The extension chain. The Field records the registry fact, whether anything is declared to chain onto the
    // owner, and this overload applies the capture policy the procedural bodies applied: a chain the registry
    // provides for is walked trusting the pointer, and a chain the registry has nothing for is probed first, since
    // the spec then usually says the pointer is null, driver-written memory may hold garbage there, and vendors
    // chain unregistered structures anyway. Both walks resolve each node's type at run time from its sType.
    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::FieldStoreFor<Storage, Field>
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

    // A true special case, general to no shape: a generic handle scalar, whose value is the handle plus its selector
    // sibling's object type. Both members are accessed by value.
    template <typename Field, typename Storage>
    requires schema::HandleValueField<Field> && schema::FieldStoreFor<Storage, Field> &&
        schema::FieldWithSelector<Storage, Field>
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
