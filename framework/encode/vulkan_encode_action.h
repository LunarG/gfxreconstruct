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
// which makes the one encoder call the field's kind and shape select. The Action is the only party that touches
// storage; the adapter sees field contents and never the structure they came from.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_encode_capture_wrappers.h"
#include "schema/field.h"

// This operation reads native Vulkan structures. Keep the complete generated member-binding population beside the
// Action and private to the translation unit that owns the generic EncodeStruct instantiations.
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include "util/defines.h"

#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Adapters from a Field to the ParameterEncoder and umbrella entry points. The concepts read the Field's kind and
// shape; the entry points know nothing of Fields, and each operator() makes the one call the procedural bodies made
// for that combination. Nothing here reads storage, which is what lets a command Action reuse this table unchanged.
//
// Direction, not taken yet: the Action names this type directly. Taking it as a template parameter instead, the way a
// traits type is passed, would make the shape Apply set API-agnostic; the Vulkan facts would then live in this
// adapter and in the schema, and the same Action would serve another API given its adapter.
struct EncoderAdapter
{
    // Scalar and address kinds: value, pointer, run. GeneralScalarKindField admits the address kind because its bits
    // are the value recorded, and Encode converts a pointer with the cast it needs.
    template <typename Field>
    requires schema::GeneralScalarKindField<Field> && schema::ValueShapeField<Field>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>& value) const
    {
        encoder->Encode(schema::FieldKind<Field>{}, value);
    }

    template <typename Field>
    requires schema::GeneralScalarKindField<Field> && schema::PointerShapeField<Field>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* pointer) const
    {
        encoder->EncodePointer(schema::FieldKind<Field>{}, pointer);
    }

    template <typename Field, typename SizeType>
    requires schema::GeneralScalarKindField<Field> && schema::AnyArrayShapeField<Field>
    void
    operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* array, SizeType count) const
    {
        encoder->EncodeArray(schema::FieldKind<Field>{}, array, GFXRECON_NARROWING_CAST(size_t, count));
    }

    // Handle kind: value, pointer, run. A handle is recorded as its capture wrapper's id, so each entry needs the
    // wrapper type CaptureWrapperFor maps its descriptor to, and requires HasCaptureWrapper.
    template <typename Field>
    requires schema::HandleKindField<Field> && schema::ValueShapeField<Field> &&
        HasCaptureWrapper<typename Field::api_type>
    void operator()(Field field, ParameterEncoder* encoder, const schema::FieldElementType<Field>& handle) const
    {
        using Wrapper = CaptureWrapperType<typename Field::api_type>;
        encoder->template EncodeVulkanHandleValue<Wrapper>(handle);
    }

    template <typename Field>
    requires schema::HandleKindField<Field> && schema::PointerShapeField<Field> &&
        HasCaptureWrapper<typename Field::api_type>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* handle_pointer) const
    {
        using Wrapper = CaptureWrapperType<typename Field::api_type>;
        // No structure field has this shape; the entry is here for the command Action's output parameters and has no
        // byte gate yet. TODO: determine a mechanism to pass omit_output_data when the adapter serves command
        // parameters: potentially a Field-level fact beside the Return Field, or the generated encoders' result-based
        // rule if it proves uniform enough to import.
        encoder->template EncodeVulkanHandlePtr<Wrapper>(handle_pointer /*, omit_output_data */);
    }

    template <typename Field>
    requires schema::HandleKindField<Field> && schema::AnyArrayShapeField<Field> &&
        HasCaptureWrapper<typename Field::api_type>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* array, size_t count) const
    {
        using Wrapper = CaptureWrapperType<typename Field::api_type>;
        encoder->template EncodeVulkanHandleArray<Wrapper>(array, count);
    }

    // Struct kind: value, pointer, run. Each calls the EncodeStruct overload for the element's type.
    template <typename Field>
    requires schema::StructKindField<Field> && schema::ValueShapeField<Field>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>& value) const
    {
        EncodeStruct(encoder, value);
    }

    template <typename Field>
    requires schema::StructKindField<Field> && schema::PointerShapeField<Field>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* pointer) const
    {
        EncodeStructPtr(encoder, pointer);
    }

    template <typename Field>
    requires schema::StructKindField<Field> && schema::AnyArrayShapeField<Field>
    void operator()(Field, ParameterEncoder* encoder, const schema::FieldElementType<Field>* array, size_t count) const
    {
        EncodeStructArray(encoder, array, count);
    }
};

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    // A value-shaped field of any kind the adapter encodes. Getter references an ordinary member in place, or an
    // internal copy of a non-addressable one (e.g. a bitfield), so one overload serves both.
    template <typename Field, typename Storage>
    requires schema::ValueShapeField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        EncoderAdapter()(field, encoder_, *schema::Getter(storage, field));
    }

    // A pointer to one element. The member holds the pointer, and the pointer is what the encoder needs, so it is
    // read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::PointerShapeField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        static_assert(Field::pointer_count == 1, "A pointer to one element has one level of indirection");
        EncoderAdapter()(field, encoder_, schema::Get(storage, field));
    }

    // An array of elements, with a sibling member that holds the count. The member holds the pointer, and the pointer
    // is what the encoder needs, so it is read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::ArrayShapeField<Field> && schema::HasMember<Storage, Field> &&
        schema::HasCountField<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using CountField = schema::FieldCountField<Field>;
        using ArrayType  = schema::FieldElementType<Field>;

        auto count = schema::Get(storage, CountField{});

        // We encode schema's element type, not the member's declared type. This is to support
        // api_type::vulkan::OpaqueBytes, which are void* members with a count, and the api_type descriptor makes it
        // a run of uint8_t. For every other api_type run the cast is the identity.
        const ArrayType* array = static_cast<const ArrayType*>(schema::Get(storage, field));
        EncoderAdapter()(field, encoder_, array, GFXRECON_NARROWING_CAST(size_t, count));
    }

    // A fixed-extent array of elements, of one or two dimensions. Every named fixed-array entry point, the 2DMatrix
    // family included, is one run over a flat pointer and a length, so a matrix is a run of the extent product and
    // the two ranks share a body. The extents are read from the API member's declared type, as they are on the decode
    // side; the Field records the same extents and the static_assert below holds the two to agree.
    //
    // If a count field is present the static extent is treated as the capacity, and count elements up to capacity are
    // written.
    template <typename Field, typename Storage>
    requires schema::StaticArrayShapeField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const auto& array_ref = schema::GetRef(storage, field);
        using ArrayType       = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatchV<ArrayType, Field>,
                      "A StaticArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        size_t count = std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            static_assert(!(schema::HasCountField<Storage, Field>),
                          "A multi-dimensional fixed-extent array with a count field is not yet schema enabled");
            EncoderAdapter()(field, encoder_, &array_ref[0][0], count);
        }
        else
        {
            if constexpr (schema::HasCountField<Storage, Field>)
            {
                using CountField = schema::FieldCountField<Field>;
                // We don't need a NARROWING_CAST here because the count is a size_t, count_value is either less or
                // ignored.
                const auto count_value = *schema::Getter(storage, CountField{});
                count                  = std::cmp_less(count_value, count) ? static_cast<size_t>(count_value) : count;
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
    requires schema::ExtensionChainShapeField<Field> && schema::HasMember<Storage, Field>
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
    requires schema::HandleValueField<Field> && schema::HasMember<Storage, Field> &&
        schema::HasSelectorField<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using SelectorField = schema::FieldSelectorField<Field>;
        encoder_->Encode(
            schema::FieldKind<Field>{},
            vulkan_wrappers::GetWrappedId(schema::Get(storage, field), schema::Get(storage, SelectorField{})));
    }

    // A pointer to one string, of either width. The member holds the pointer, and the pointer is what the encoder
    // needs, so it is read as a value like any other.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::PointerShapeField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        static_assert(Field::pointer_count == 1, "A pointer to one string has one level of indirection");
        encoder_->EncodeString(schema::FieldKind<Field>{}, schema::Get(storage, field));
    }

    // Field is a String or WString fixed length array. Must access field by reference. One-dimensional only.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::StaticArrayShapeField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const auto& string_ref = schema::GetRef(storage, field);
        using ArrayType        = std::remove_cvref_t<decltype(string_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatchV<ArrayType, Field>,
                      "A StaticArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> == 1, "String arrays must be one-dimensional only");

        constexpr size_t capacity = std::extent_v<ArrayType, 0>;
        encoder_->EncodeString(schema::FieldKind<Field>{}, &string_ref[0], capacity);
    }

  private:
    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
