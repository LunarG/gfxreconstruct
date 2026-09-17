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

// The structure Encode Action: one Apply overload set, applied to a schema's Fields by schema::WalkFields over the
// API's own structure. Each overload reads a member and encodes it with the wire type its Field's logical kind
// selects; the Action names kinds and never widths.

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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    // A value-shaped scalar. Read through Get, which serves an ordinary member and a bitfield alike, so one overload
    // covers both.
    template <typename Field, typename Storage>
    requires schema::GeneralScalarKindField<Field> && schema::ValueShapedField<Field> &&
        schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        encoder_->template Encode<typename Field::api_type::kind>(schema::Get(storage, field));
    }

    // A fixed-extent array of scalars, of one or two dimensions. Every named fixed-array entry point, the 2DMatrix
    // family included, is one EncodeArray over a flat pointer and a length, so a matrix is a run of the extent
    // product and the two ranks share a body. The extents are read from the API member's declared type, as they are
    // on the decode side; the Field records the same extents and the static_assert below holds the two to agree.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const auto& array_ref = schema::GetRef(storage, field);
        using ArrayType       = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatchV<ArrayType, Field>,
                      "A StaticArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        constexpr size_t count =
            std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            encoder_->template EncodeArray<typename Field::api_type::kind>(&array_ref[0][0], count);
        }
        else
        {
            encoder_->template EncodeArray<typename Field::api_type::kind>(&array_ref[0], count);
        }
    }

    // The extension chain. The Field records the registry fact, whether anything is declared to chain onto the
    // owner, and this overload applies the capture policy the procedural bodies applied: a chain the registry
    // provides for is walked trusting the pointer, and a chain the registry has nothing for is probed first, since
    // the spec then usually says the pointer is null, driver-written memory may hold garbage there, and vendors
    // chain unregistered structures anyway. Both walks resolve each node's type at run time from its sType.
    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::HasMember<Storage, Field>
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

    // A pointer to one scalar. The member holds the pointer, and the pointer is what the encoder needs, so it is
    // read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::PointerField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        static_assert(Field::pointer_count == 1, "A pointer to one scalar has one level of indirection");

        encoder_->template EncodePointer<typename Field::api_type::kind>(schema::Get(storage, field));
    }

    // An array of scalars, with a sibling member that holds the count. The member holds the pointer, and the pointer is
    // what the encoder needs, so it is read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::PointerArrayField<Field> && schema::HasMember<Storage, Field> &&
        schema::HasCountField<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using CountField = schema::FieldCountField<Field>;
        using ArrayType  = schema::FieldElementType<Field>;

        auto             count = schema::Get(storage, CountField{});
        const ArrayType* array = static_cast<const ArrayType*>(schema::Get(storage, field));
        encoder_->template EncodeArray<typename Field::api_type::kind>(array, GFXRECON_NARROWING_CAST(size_t, count));
    }

    // A single wrapped handle.
    template <typename Field, typename Storage>
    requires schema::HandleKindField<Field> && schema::ValueShapedField<Field> && schema::HasMember<Storage, Field> &&
        HasCaptureWrapper<typename Field::api_type>
    void Apply(Field field, const Storage& storage)
    {
        using Wrapper = CaptureWrapperType<typename Field::api_type>;
        encoder_->template EncodeVulkanHandleValue<Wrapper>(schema::Get(storage, field));
    }

    // An array of handles, with a sibling member that holds the count. The member holds the pointer, and the pointer is
    // what the encoder needs, so it is read as a value like any other; nothing here takes the member's address.
    template <typename Field, typename Storage>
    requires schema::HandleKindField<Field> && schema::PointerArrayField<Field> && schema::HasMember<Storage, Field> &&
        schema::HasCountField<Storage, Field> && HasCaptureWrapper<typename Field::api_type>
    void Apply(Field field, const Storage& storage)
    {
        using CountField = schema::FieldCountField<Field>;
        using Wrapper    = CaptureWrapperType<typename Field::api_type>;

        auto count = schema::Get(storage, CountField{});
        encoder_->template EncodeVulkanHandleArray<Wrapper>(schema::Get(storage, field),
                                                            GFXRECON_NARROWING_CAST(size_t, count));
    }

    // A generic handle scalar, with a sibling member that holds the handle type. The field and selector members are
    // accessed by value.
    template <typename Field, typename Storage>
    requires schema::HandleField<Field> && schema::HasMember<Storage, Field> && schema::HasSelectorField<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        using SelectorField = schema::FieldSelectorField<Field>;
        encoder_->Encode<typename Field::api_type::kind>(
            vulkan_wrappers::GetWrappedId(schema::Get(storage, field), schema::Get(storage, SelectorField{})));
    }

    // Field is a String or WString, and the member holds a pointer to it. The encoder needs the pointer, so it is read
    // by value.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::PointerField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        static_assert(Field::pointer_count == 1, "A pointer to one string has one level of indirection");
        encoder_->template EncodeString<typename Field::api_type::kind>(schema::Get(storage, field));
    }

    // Field is a String or WString fixed length array. Must access field by reference. One-dimensional only.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field>
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
        encoder_->template EncodeString<typename Field::api_type::kind, capacity>(&string_ref[0]);
    }

  private:
    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
