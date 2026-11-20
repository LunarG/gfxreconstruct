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

// EncodeStructAction: the schema::WalkFields Action that encodes an API structure. Caller: EncodeStruct.
//
// One Apply per declaration shape: value, pointer, array, fixed array. Each Apply holds the framing for its shape, the
// count and the clamp, and branches once on the category of the Field's API element to select the encoder call. A
// scalar, enum or bitmask is written as binding::WireTypeOf of its API element.
//
// Limitations:
//   - A category an Apply has no encoder call for fails a static_assert in that Apply. No call takes a pointer to a
//     pointer, a Pointer to a handle, an Array of pointers to scalars or handles, or a run of function-pointer API
//     elements.
//   - A FixedArray above two dimensions, or of two dimensions with a count member, fails a static_assert in its Apply.
//
// Lifetime: the Action holds the ParameterEncoder pointer without owning it and keeps no other state, so one instance
// may walk any number of structures.
//
// Future work, for the Apply set to serve another API: the Vulkan facts in it, vulkan_wrappers::GetWrappedId,
// CaptureWrapperOf and the pNext entry points, move into a binding or the schema.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "binding/vulkan_wire_type.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "generated/generated_vulkan_capture_wrapper_of.h"
#include "schema/field.h"

#include "util/defines.h"
#include "util/type_list.h"

#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// TextAttributeOf_v is the attribute word a string is written under: kIsWString for a wchar_t element, kIsString for
// char.
template <schema::SimpleApiElement Element>
inline constexpr format::PointerAttributes TextAttributeOf_v =
    std::same_as<typename Element::element_type, wchar_t> ? format::PointerAttributes::kIsWString
                                                          : format::PointerAttributes::kIsString;

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    // Encodes a value. schema::Get references an ordinary member in place, or reads a bitfield through the Field's
    // Get, so one overload serves both.
    template <typename Storage, typename Field>
    requires schema::ValueField<Field> && schema::StorageFor<Storage, Field>
    void Apply(const Storage& storage, Field field)
    {
        using Element = typename Field::api_element;

        if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            // A union, or a structure with a hand-written encoder, reaches its hand-written EncodeStruct overload.
            EncodeStruct(encoder_, schema::Get(storage, field));
        }
        else if constexpr (schema::HandleApiElement<Element>)
        {
            // A handle is written as its capture wrapper's id.
            static_assert(ApiElementWithCaptureWrapper<Element>, "The handle API element has no CaptureWrapperOf");
            encoder_->template EncodeVulkanHandleValue<CaptureWrapperOf_t<Element>>(schema::Get(storage, field));
        }
        else if constexpr (schema::FieldWithObjectType<Field>)
        {
            // A generic handle, a uint64_t member the registry marks objecttype: GetWrappedId maps it to its capture
            // id using the object type its objecttype_field holds.
            static_assert(schema::StorageWithObjectType<Storage, Field>, "The storage must hold the object type Field");
            using ObjectTypeField = typename Field::objecttype_field;
            encoder_->EncodeAs<binding::WireTypeOf_t<Element>>(
                vulkan_wrappers::GetWrappedId(schema::Get(storage, field), schema::Get(storage, ObjectTypeField{})));
        }
        else
        {
            // A scalar member is declared as its API element type, since a platform typedef is its own API element;
            // a function-pointer member is a pointer type, which EncodeAs reinterpret_casts to the address.
            static_assert(schema::SimpleApiElement<Element> || schema::FuncpointerApiElement<Element>,
                          "No encoder call for a value of this category");
            static_assert(!schema::SimpleApiElement<Element> ||
                              std::is_same_v<schema::StoredTypeOf_t<Storage, Field>, schema::ApiTypeOf_t<Element>>,
                          "A scalar member is declared as its API element type");
            encoder_->EncodeAs<binding::WireTypeOf_t<Element>>(schema::Get(storage, field));
        }
    }

    // Encodes a pointer to one item, or an extension chain.
    template <typename Storage, typename Field>
    requires schema::PointerField<Field> && schema::StorageFor<Storage, Field>
    void Apply(const Storage& storage, Field)
    {
        using Element = typename Field::api_element;

        if constexpr (schema::ExtensionChainField<Field>)
        {
            // The extension chain. NOTE: MUST be tested before the Void branch: pNext is declared
            // Pointer<Const<Void>>, and the Void branch would record its address only.
            //
            // With the ValidExtensions token EncodePNextStruct walks the chain trusting the pointer. Without it
            // EncodePNextStructIfValid checks that the pointer can be read first, since the spec then usually
            // requires NULL, driver-written memory may hold garbage there, and vendors chain unregistered structures
            // anyway. Both walks find each node's type by its sType.
            const void* pnext = Field::GetRef(storage);

            if constexpr (util::TypeListContains_v<typename Field::semantics, schema::semantic::ValidExtensions>)
            {
                EncodePNextStruct(encoder_, pnext);
            }
            else
            {
                EncodePNextStructIfValid(encoder_, pnext);
            }
        }
        else if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            EncodeStructPtr(encoder_, Field::GetRef(storage));
        }
        else if constexpr (schema::VoidApiElement<Element>)
        {
            // Records the pointer's address only: what a void pointer points at is never described. Pointer<Void>
            // and the platform types curation leaves undefined, Pointer<ANativeWindow>, Pointer<deref_HWND>.
            static_assert(!schema::PointerToPointerField<Field>, "No encoder call for a pointer to a pointer");
            encoder_->EncodeVoidPtr(Field::GetRef(storage));
        }
        else
        {
            static_assert(schema::SimpleApiElement<Element> && !schema::PointerToPointerField<Field>,
                          "No encoder call for a pointer to this category");
            encoder_->EncodePointerAs<binding::WireTypeOf_t<Element>>(Field::GetRef(storage));
        }
    }

    // Encodes an Array: a pointer to a run of items, or a run of pointers each to one item. A string,
    // Array<Const<Char>, NullTerminated>, ends at its terminator and reads no count; every other run takes its count
    // from LengthOf_t<Field> evaluated on the structure, a member or an expression over members (e.g. pCode's
    // codeSize / 4).
    template <typename Storage, typename Field>
    requires schema::ArrayField<Field> && schema::StorageFor<Storage, Field>
    void Apply(const Storage& storage, Field)
    {
        using Element = typename Field::api_element;

        if constexpr (schema::StringField<Field>)
        {
            encoder_->EncodeStringAs<binding::WireTypeOf_t<Element>, TextAttributeOf_v<Element>>(
                Field::GetRef(storage));
        }
        else
        {
            static_assert(schema::StorageWithLength<Storage, Field>,
                          "An Array's length must be an expression value the storage can evaluate");

            const size_t count = GFXRECON_NARROWING_CAST(size_t, schema::LengthOf_t<Field>::Get(storage));

            if constexpr (schema::StringArrayField<Field>)
            {
                encoder_->EncodeStringArrayAs<binding::WireTypeOf_t<Element>, TextAttributeOf_v<Element>>(
                    Field::GetRef(storage), count);
            }
            else if constexpr (schema::PointerArrayField<Field>)
            {
                // A run of pointers, each to one structure, is EncodeStructArray2D with every inner length 1. The 1
                // is the Pointer shape, not an extent, so the schema records none.
                static_assert(schema::StructOrUnionApiElement<Element>,
                              "No encoder call for an Array of pointers to this category");
                EncodeStructArray2D(encoder_, Field::GetRef(storage), count, 1);
            }
            else if constexpr (schema::VoidApiElement<Element>)
            {
                // An Array of Void is a run of bytes; its length is the byte count.
                encoder_->EncodeUInt8Array(Field::GetRef(storage), count);
            }
            else
            {
                EncodeRun<Element>(Field::GetRef(storage), count);
            }
        }
    }

    // Encodes a fixed-extent array of one or two dimensions as one run from the first element: a two-dimensional array
    // is a run of the extent product, as the 2DMatrix entry points do. The extents come from the API member's declared
    // type; the static_asserts hold the Field's recorded extents equal to them.
    //
    // If a count field is present the static extent is treated as the capacity, and count elements up to capacity are
    // written.
    template <typename Storage, typename Field>
    requires schema::FixedArrayField<Field> && schema::StorageFor<Storage, Field>
    void Apply(const Storage& storage, Field)
    {
        using Element   = typename Field::api_element;
        using ArrayType = schema::StoredTypeOf_t<Storage, Field>;

        const ArrayType& array_ref = Field::GetRef(storage);

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        size_t count = std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (schema::StringField<Field>)
        {
            // A string in a fixed extent: the extent bounds the search for the terminator.
            static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent string has one dimension");
            encoder_->EncodeStringAs<binding::WireTypeOf_t<Element>, TextAttributeOf_v<Element>>(&array_ref[0], count);
        }
        else if constexpr (std::rank_v<ArrayType> == 2)
        {
            static_assert(!(schema::StorageWithLength<Storage, Field>),
                          "A multi-dimensional fixed-extent array with a count field is not yet schema enabled");
            EncodeRun<Element>(&array_ref[0][0], count);
        }
        else
        {
            if constexpr (schema::StorageWithLength<Storage, Field>)
            {
                // Read in the count member's own type, not narrowed to size_t: ClampStaticArrayLength compares in
                // that type and logs, so a negative count encodes nothing and one above the extent is clamped.
                const auto count_value = schema::LengthOf_t<Field>::Get(storage);
                count = ParameterEncoder::ClampStaticArrayLength(count_value, count, Field::field_name.data());
            }
            EncodeRun<Element>(&array_ref[0], count);
        }
    }

  private:
    // Encodes count items from array, the leaf of the Array and FixedArray overloads: structures through EncodeStruct,
    // handles as their capture wrappers' ids, scalars as their WireTypeOf.
    template <typename Element>
    void EncodeRun(const schema::ApiTypeOf_t<Element>* array, size_t count)
    {
        if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            EncodeStructArray(encoder_, array, count);
        }
        else if constexpr (schema::HandleApiElement<Element>)
        {
            static_assert(ApiElementWithCaptureWrapper<Element>, "The handle API element has no CaptureWrapperOf");
            encoder_->template EncodeVulkanHandleArray<CaptureWrapperOf_t<Element>>(array, count);
        }
        else
        {
            static_assert(schema::SimpleApiElement<Element>, "No encoder call for a run of this category");
            encoder_->EncodeArrayAs<binding::WireTypeOf_t<Element>>(array, count);
        }
    }

    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
