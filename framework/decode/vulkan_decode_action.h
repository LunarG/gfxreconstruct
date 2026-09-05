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

// The decode Action: one Apply overload set, applied to a schema's Fields by schema::WalkFields.
//
// This is hand-written. The generator emits the schema and the per-structure entry point that drives the walk; it
// does not emit the operation. That is the whole point of the arrangement, so adding an operation family costs one
// Action rather than one generated function for every structure.
//
// Nine overloads cover the structures reached so far. A field whose shape or kind none of them accepts makes
// WalkFields fail to compile and name the field, which is how the Action's coverage is bounded.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_ACTION_H
#define GFXRECON_DECODE_VULKAN_DECODE_ACTION_H

#include "decode/decode_allocator.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "schema/field.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

// The member-trait partitions this operation reads. They belong here, with the constrained overloads below, rather
// than with the entry point that drives the walk: the overloads are what a partial set would silently re-resolve, so
// the set travels with them.
#include "generated/generated_vulkan_schema_native_struct_members.h"
#include "generated/generated_vulkan_schema_decoded_struct_members.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Declared the way the generated struct decoders declare it; there is no header that publishes it.
size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, PNextNode** pNext);

// There is no table here joining a logical kind to a wire type, and no wire type is named. ValueDecoder and
// PointerDecoder each take a kind, and format/format.h carries the width on the kind itself, so this operation says
// only what a field's kind is -- which the schema already told it.
//
// Their named entry points -- DecodeVkDeviceSize, DecodeFlags and the rest -- each hardcode one wire type, which is
// the same fact stated a second time. Going through the kind keeps one statement of it, and reaches the kinds no
// named entry point covers: PointerDecoder has no DecodeFlags64, and Decode<format::kind::Flags64> needs none.

// The decode Action. It carries the read cursor, so one instance walks one structure.
class DecodeStructAction
{
  public:
    DecodeStructAction(const uint8_t* buffer, size_t buffer_size) : buffer_(buffer), buffer_size_(buffer_size) {}

    size_t BytesRead() const { return bytes_read_; }

    // A value-shaped scalar decodes straight into the decoded value, which is where the API expects to read it.
    template <typename Field, typename Storage>
    requires schema::ScalarField<Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        bytes_read_ += ValueDecoder::Decode<typename Field::api_type::kind>(
            Cursor(), Remaining(), &schema::GetRef(DecodedValueRef(storage), field));
    }

    // A bitfield cannot be decoded into. The address-of operator may not be applied to one and a non-const
    // reference may not be bound to one, so there is no &member for the trait to hold and no reference for GetRef
    // to return; the member trait supplies Set instead. That rule is C++ [class.bit]/3, a stable name resolvable at
    // https://eel.is/c++draft/class.bit.
    //
    // So this decodes a whole value of the field's element type and writes it through. Each bitfield is recorded
    // that way on the wire too -- a one-bit flag costs four bytes -- and the narrowing happens on the write,
    // exactly as the procedural decoder does it.
    //
    // Disjoint from the value-shaped scalar overload by Addressable against NonAddressable, which cannot both hold.
    template <typename Field, typename Storage>
    requires schema::ScalarField<Field> && schema::NonAddressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        schema::FieldElementType<Field> value{};

        bytes_read_ += ValueDecoder::Decode<typename Field::api_type::kind>(Cursor(), Remaining(), &value);

        schema::Set(DecodedValueRef(storage), field, value);
    }

    // A run of scalars decodes into the wrapper's PointerDecoder, and the decoded value's pointer follows it, as the
    // extension chain's does. The sibling count field is decoded as its own scalar in its own position; the array
    // length travels with the array on the wire, so nothing here reads across fields.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::PointerArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += field_ref.template Decode<typename Field::api_type::kind>(Cursor(), Remaining());

        schema::GetRef(DecodedValueRef(storage), field) = field_ref.GetPointer();
    }

    // A handle decodes as the capture-file identity, into the decoded wrapper. The handle in the decoded value
    // stays null until replay maps the identity to a handle from this run.
    template <typename Field, typename Storage>
    requires schema::HandleField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        bytes_read_ += ValueDecoder::Decode<typename Field::api_type::kind>(
            Cursor(), Remaining(), &schema::GetRef(storage, field));
        schema::GetRef(DecodedValueRef(storage), field) = VK_NULL_HANDLE;
    }

    // An embedded structure allocates its decoded wrapper, links that wrapper to the inline decoded value member, and
    // descends through the operation family's existing entry point. This is legacy descent, not a nested walk:
    // whether the nested DecodeStruct is itself a field walk is that structure's business, not this one's.
    //
    // The decoded type comes from the storage rather than from ApiElementTraits, because the wrapper's own member
    // already declares it. That keeps this header free of any generated include; the call resolves at instantiation.
    template <typename Field, typename Storage>
    requires schema::StructField<Field> && schema::ValueShapedField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        using Nested    = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;

        field_ref                = DecodeAllocator::Allocate<Nested>();
        field_ref->decoded_value = &schema::GetRef(DecodedValueRef(storage), field);

        bytes_read_ += DecodeStruct(Cursor(), Remaining(), field_ref);
    }

    // A fixed-extent array decodes in place. The decoder is pointed at the decoded value's own storage and writes
    // straight into it, so unlike every other overload nothing is assigned to the decoded value afterwards: it is
    // already the target.
    //
    // The extents come from the API member's declared type, not from the schema. The schema records a usable
    // extent only for a one-dimensional array; for a multidimensional one it records the dimension count and a
    // joined length expression, which is a string. std::extent_v recovers both dimensions from the C++
    // declaration the member trait already names, so the two cases need no separate treatment here and the
    // schema needs no extent at all for this.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");

        // The bound is PointerDecoder's, not the registry's. It supplies SetExternalMemory for one and two
        // dimensions and no more, so a rank the registry might one day add would otherwise fail as an unviable
        // overload rather than as a statement of the limit.
        static_assert(std::rank_v<ArrayType> <= 2,
                      "PointerDecoder::SetExternalMemory covers one and two dimensions only");

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>, std::extent_v<ArrayType, 1>);
        }
        else
        {
            field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);
        }

        bytes_read_ += field_ref.template Decode<typename Field::api_type::kind>(Cursor(), Remaining());
    }

    // A pointer to a structure, or to a run of them. Both decode identically: StructPointerDecoder reads its own
    // length from the wire, so one element is a run of one and the shape does not change the body. Every
    // StructPointerDecoder member is an allocated pointer and every other decoder member is held by value, so the
    // shape and kind that select this overload also settle which form to write; nothing here tests for it. If that
    // ever stops holding, this body fails to compile and names the field.
    //
    // The decoder descends into each element through DecodeStruct, so this is legacy descent like the embedded
    // structure case, once per element. Whether an element type is itself a field walk is that structure's
    // business.
    template <typename Field, typename Storage>
    requires schema::StructField<Field> &&
        (schema::PointerField<Field> ||
         schema::PointerArrayField<Field>)&&schema::Addressable<Storage, Field>&& schema::
            Addressable<typename Storage::struct_type, Field> void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        using Decoder   = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;

        field_ref = DecodeAllocator::Allocate<Decoder>();

        bytes_read_ += field_ref->Decode(Cursor(), Remaining());

        schema::GetRef(DecodedValueRef(storage), field) = field_ref->GetPointer();
    }

    // The extension chain keeps runtime sType dispatch, and the decoded value's pointer follows the decoded node.
    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += DecodePNextStruct(Cursor(), Remaining(), &field_ref);

        schema::GetRef(DecodedValueRef(storage), field) = field_ref ? field_ref->GetPointer() : nullptr;
    }

  private:
    const uint8_t* Cursor() const { return buffer_ + bytes_read_; }

    size_t Remaining() const { return buffer_size_ - bytes_read_; }

    // Named for the wrapper member it returns: every decoded wrapper calls this pointer decoded_value, and the
    // trait that would name its type calls it decoded_value_type. Ref for what GetRef means by it, and because the
    // plain name is taken by the DecodedValue alias in this namespace.
    template <typename Storage>
    static typename Storage::struct_type& DecodedValueRef(Storage& storage)
    {
        return *storage.decoded_value;
    }

    const uint8_t* buffer_{ nullptr };
    size_t         buffer_size_{ 0 };
    size_t         bytes_read_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_ACTION_H
