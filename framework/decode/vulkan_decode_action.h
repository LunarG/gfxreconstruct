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
// Twelve overloads cover every structure the schema drives. A field whose shape or kind none of them accepts makes
// WalkFields fail to compile and name the field, which is how the Action's coverage is bounded.
//
// Two access primitives, by one rule. schema::Set writes a value to the decoded member, and is what every overload
// uses to store a result: it is the same assignment where the member is addressable and the only write that exists
// where it is not, so the Action never asks which. schema::GetRef appears only where a decoder needs the member's
// address -- the fixed-extent arrays decoded in place, and the embedded structure whose wrapper links to it -- and
// once unevaluated, to name a member's declared type.

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

    // A value-shaped scalar decodes a whole value of the field's element type and writes it to the decoded value,
    // which is where the API expects to read it.
    //
    // It is not decoded in place, because not every member has a place. A bitfield cannot be decoded into: the
    // address-of operator may not be applied to one and a non-const reference may not be bound to one, so there is
    // no &member for the trait to hold and no reference for GetRef to return. That rule is C++ [class.bit]/3, a
    // stable name resolvable at https://eel.is/c++draft/class.bit. Writing through Set serves both: it is the same
    // assignment for an ordinary member, and for a bitfield it reaches the accessor the member trait supplies.
    //
    // Each bitfield is recorded as a whole value on the wire too -- a one-bit flag costs four bytes -- and the
    // narrowing happens on the write, exactly as the procedural decoder did it.
    template <typename Field, typename Storage>
    requires schema::ScalarField<Field> && schema::HasMember<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        schema::FieldElementType<Field> value{};

        bytes_read_ += ValueDecoder::Decode<typename Field::api_type::kind>(Cursor(), Remaining(), &value);

        schema::Set(DecodedValueRef(storage), field, value);
    }

    // A pointer to one scalar, or to a run of them. Both decode into the wrapper's PointerDecoder and the decoded
    // value's pointer follows, as the extension chain's does: the decoder reads its own length from the wire, so
    // one element is a run of one and the shape does not change the body.
    //
    // The sibling count field is decoded as its own scalar in its own position, and the array's length travels
    // with the array, so nothing here reads across fields.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::PointerShapedField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += field_ref.template Decode<typename Field::api_type::kind>(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref.GetPointer());
    }

    // A value-shaped identifier -- a handle, or an opaque address -- decodes as what the capture recorded, into the
    // decoded wrapper. The decoded value's member is nulled, and stays null until replay resolves the identifier:
    // a handle through the mapping to a handle from this run, an address through PreProcessExternalObject for the
    // fields the ExternalObject descriptor names. Both halves are the invariant: the wrapper carries the captured
    // identifier, the decoded value carries nothing from another run.
    //
    // The null is written as a value-initialized member -- the decoded value's own declared type -- rather than as
    // VK_NULL_HANDLE, nullptr, or the field's element type, so that one body serves every spelling. VK_NULL_HANDLE
    // follows the build's handle representation -- a null pointer where handles are pointers, 0 where they are
    // integers -- so for a member declared as a handle type this writes exactly what that macro would. A handle the
    // API declares as a plain integer, with a sibling field naming its type at run time, is uint64_t in either
    // build, and gets the 0 its generated body wrote; VK_NULL_HANDLE is a null pointer in the builds where handles
    // are pointers, and would not convert there. A function pointer or a pointer to something outside the API
    // value-initializes to nullptr, which is what its generated body wrote. The element type would not do for the
    // last of those: every address outside the API names the one ExternalObject descriptor, whose element type is
    // void*, while the member itself may be a typed platform pointer such as HMONITOR, to which a null void* does
    // not convert.
    //
    // The address case reaches this whether or not the declaration writes a star: the schema shapes it as a value,
    // because that is what the capture recorded.
    template <typename Field, typename Storage>
    requires schema::IdentifierKindField<Field> && schema::ValueShapedField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        using Member = std::remove_cvref_t<decltype(schema::GetRef(DecodedValueRef(storage), field))>;

        bytes_read_ += ValueDecoder::Decode<typename Field::api_type::kind>(
            Cursor(), Remaining(), &schema::GetRef(storage, field));

        schema::Set(DecodedValueRef(storage), field, Member{});
    }

    // A run of handles decodes into the wrapper's HandlePointerDecoder, and the decoded value's pointer is nulled
    // rather than pointed at it -- the same division a single handle gets, for the same reason: the wrapper holds
    // capture-file identities and replay maps them to handles of its own.
    //
    // HandlePointerDecoder names no kind on its Decode, because the class is the kind: it is instantiated on the
    // handle type and reads HandleEncodeType by construction.
    template <typename Field, typename Storage>
    requires schema::HandleKindField<Field> && schema::PointerArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        bytes_read_ += schema::GetRef(storage, field).Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, nullptr);
    }

    // Text: one string, or a run of them. Both decode the same way and differ only in the decoder class the
    // wrapper declares -- StringDecoder or WStringDecoder for one, StringArrayDecoder for a run -- and all three
    // read their own length from the wire and hand back storage the decoded value can point at.
    //
    // Unlike a scalar run, no kind is passed: each of those classes is instantiated on its character type and
    // reads the matching encode type by construction, so the kind selects the member rather than the call.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::PointerShapedField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref.GetPointer());
    }

    // A fixed-extent string decodes in place, like any fixed-extent array: the decoder is pointed at the decoded
    // value's own storage and writes straight into it, so nothing is assigned afterwards. The extent comes from
    // the API member's declared type, for the reason the scalar case gives.
    template <typename Field, typename Storage>
    requires schema::TextKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent string is one dimensional");

        field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());
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
    requires schema::StructField<Field> && schema::PointerShapedField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        using Decoder   = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;

        field_ref = DecodeAllocator::Allocate<Decoder>();

        bytes_read_ += field_ref->Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref->GetPointer());
    }

    // A fixed-extent array of structures. The decoder is still allocated, as it is for any run of structures, but
    // it is then pointed at the decoded value's own array and decodes into that, so nothing is assigned
    // afterwards -- the fixed-extent half of the pattern, on the structure decoder rather than a scalar one.
    //
    // Each element still descends through DecodeStruct, so this is legacy descent once per element.
    template <typename Field, typename Storage>
    requires schema::StructField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using Decoder   = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent array of structures is one dimensional");

        field_ref = DecodeAllocator::Allocate<Decoder>();
        field_ref->SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref->Decode(Cursor(), Remaining());
    }

    // A fixed-extent array of handles. The two calls do unrelated things, despite reading like a sequence.
    //
    // Decode reads the captured identities into the decoder's own storage, as every handle shape does.
    // SetExternalMemory does not redirect that: it hands the decoder the decoded value's array to use as the
    // destination for the native handles replay maps those identities to, later. So nothing is written into the
    // decoded value here, which is why this shape has no null to write -- the array is an output buffer waiting
    // on the mapping step, not storage the decode fills. The invariant holds for that reason rather than by
    // assignment: the identities are in the decoder, and no handle from another run is in the decoded value.
    //
    // VkPhysicalDeviceGroupProperties::physicalDevices is the only field in the registry with this shape, and it
    // is the one the inversion found -- coverage measured by script had counted it as a scalar array, because a
    // handle is not a scalar kind and the script did not model that. The extent below is VK_MAX_DEVICE_GROUP_SIZE,
    // which is the capacity the generated body passed.
    template <typename Field, typename Storage>
    requires schema::HandleKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field> &&
        schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent array of handles is one dimensional");

        field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());
    }

    // The extension chain keeps runtime sType dispatch, and the decoded value's pointer follows the decoded node.
    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += DecodePNextStruct(Cursor(), Remaining(), &field_ref);

        schema::Set(DecodedValueRef(storage), field, field_ref ? field_ref->GetPointer() : nullptr);
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
