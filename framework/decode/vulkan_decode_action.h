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

// DecodeStructAction: the Apply overload set schema::WalkFields applies to a Decoded_ wrapper's schema. If no overload
// accepts a Field, a static_assert in WalkFields stops the compile and shows the Field.
//
// A scalar or identifier decodes as binding::WireTypeOf of its API element, so a new width is a WireTypeOf
// specialization, not a new Decode method.
//
// Limitations: a pointer to a pointer, a Pointer or PointerArray of handles, and a run of opaque or function-pointer
// API elements have no overload.
//
// Lifetime: one instance walks one structure; it carries the read cursor, and BytesRead() returns the bytes consumed.
// The decoders and nested wrappers it allocates come from DecodeAllocator, so the walk must run between
// DecodeAllocator::Begin() and End().
//
// Typical pattern (decode/vulkan_decode_struct_impl.h), after DecodeStructAction action(buffer, buffer_size):
//   schema::WalkFields<typename Wrapper::api_element>(action, *wrapper);

#ifndef GFXRECON_DECODE_VULKAN_DECODE_ACTION_H
#define GFXRECON_DECODE_VULKAN_DECODE_ACTION_H

#include "decode/decode_allocator.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "binding/vulkan_wire_type.h"
#include "schema/field.h"
#include "schema/schema.h"
#include "util/defines.h"

// Required by the Addressable and FieldStoreFor constraints below.
#include "generated/generated_vulkan_schema_api_struct_members.h"
#include "generated/generated_vulkan_schema_decoded_struct_members.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DecodeStructAction
{
  public:
    DecodeStructAction(const uint8_t* buffer, size_t buffer_size) : buffer_(buffer), buffer_size_(buffer_size) {}

    size_t BytesRead() const { return bytes_read_; }

    // Decodes a scalar value into a local and writes it through schema::Set, not in place: a bitfield member has no
    // address ([class.bit]/3), and Set reaches its generated accessor. A bitfield is recorded as a whole value of its
    // API element's type -- a one-bit flag is four bytes -- and narrowed on the write.
    template <typename Field, typename Storage>
    requires schema::ScalarValueField<Field> && schema::FieldStoreFor<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        schema::ApiTypeOf_t<typename Field::api_element> value{};

        bytes_read_ +=
            ValueDecoder::DecodeAs<binding::WireTypeOf_t<typename Field::api_element>>(Cursor(), Remaining(), &value);

        schema::Set(DecodedValueRef(storage), field, value);
    }

    // Decodes a Pointer, Array or PointerArray of scalars into the wrapper's PointerDecoder, and points the decoded
    // value's member at its storage. The decoder reads the length from the wire, so one element is a run of one; the
    // count member decodes as its own Field, and nothing here reads across Fields.
    template <typename Field, typename Storage>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::AnyPointerField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ +=
            field_ref.template DecodeAs<binding::WireTypeOf_t<typename Field::api_element>>(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref.GetPointer());
    }

    // Decodes an identifier held by value -- a handle, an opaque API element, a function pointer -- into the wrapper
    // member, and sets the decoded value's member to Member{}, the null of its declared type: VK_NULL_HANDLE for a
    // handle, pointer or integer by build; 0 for a GenericHandle; nullptr for a function pointer or a platform handle
    // typedef such as HMONITOR. Replay maps a handle member through MapStructHandles; nothing restores an address.
    template <typename Field, typename Storage>
    requires schema::IdentifierApiElement<typename Field::api_element> && schema::ValueField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        using Member = std::remove_cvref_t<decltype(schema::GetRef(DecodedValueRef(storage), field))>;

        bytes_read_ += ValueDecoder::DecodeAs<binding::WireTypeOf_t<typename Field::api_element>>(
            Cursor(), Remaining(), &schema::GetRef(storage, field));

        schema::Set(DecodedValueRef(storage), field, Member{});
    }

    // Reads a pointer to an opaque object, Pointer<ANativeWindow>, or to void, Pointer<Void>, as its address into the
    // wrapper's uint64_t member, and sets the decoded value's pointer to null, Member{}.
    template <typename Field, typename Storage>
    requires(schema::OpaqueApiElement<typename Field::api_element> ||
             schema::VoidApiElement<typename Field::api_element>) &&
        schema::PointerField<Field> &&
        (!schema::PointerToPointerField<Field>)&&schema::Addressable<Storage, Field>&& schema::
            Addressable<typename Storage::struct_type, Field> void Apply(Field field, Storage& storage)
    {
        using Member = std::remove_cvref_t<decltype(schema::GetRef(DecodedValueRef(storage), field))>;

        bytes_read_ += ValueDecoder::DecodeAddress(Cursor(), Remaining(), &schema::GetRef(storage, field));

        schema::Set(DecodedValueRef(storage), field, Member{});
    }

    template <typename Field, typename Storage>
    requires schema::VoidApiElement<typename Field::api_element> && schema::ArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += field_ref.DecodeUInt8(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref.GetPointer());
    }

    // Decodes a run of handles into the wrapper's HandlePointerDecoder and sets the decoded value's pointer to null:
    // the decoder holds capture ids, and replay's MapStructHandles points the member at the handles it maps them to.
    // HandlePointerDecoder::Decode always reads format::HandleEncodeType, so no wire type is passed.
    template <typename Field, typename Storage>
    requires schema::HandleApiElement<typename Field::api_element> && schema::ArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        bytes_read_ += schema::GetRef(storage, field).Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, nullptr);
    }

    // Decodes one string, a run of strings, or a text typedef held by value such as LPCWSTR into the wrapper's
    // StringDecoder, WStringDecoder or StringArrayDecoder, and points the decoded value's member at its storage. Each
    // decoder reads its own length and fixes its encode type by template argument, so no wire type is passed.
    template <typename Field, typename Storage>
    requires schema::TextApiElement<typename Field::api_element> &&
        (schema::AnyPointerField<Field> || schema::ValueField<Field>)&&schema::Addressable<Storage, Field>&& schema::
            Addressable<typename Storage::struct_type, Field> void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref.GetPointer());
    }

    // Decodes a fixed-extent string in place: SetExternalMemory points the decoder at the decoded value's array, so
    // nothing is assigned afterwards.
    template <typename Field, typename Storage>
    requires schema::TextApiElement<typename Field::api_element> && schema::FixedArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent string is one dimensional");

        field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());
    }

    // Decodes an embedded structure: allocates the Decoded_ wrapper the member points at, links its decoded_value to
    // the decoded value's inline member, and calls DecodeStruct. A schema-driven type reaches the DecodeStruct template
    // and walks its own Fields; a union or a CUSTOM_DECODE type reaches its hand-written overload. The wrapper type is
    // the member's declared type, so no decoded-type binding is read.
    template <typename Field, typename Storage>
    requires schema::StructApiElement<typename Field::api_element> && schema::ValueField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        using Nested    = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;

        field_ref                = DecodeAllocator::Allocate<Nested>();
        field_ref->decoded_value = &schema::GetRef(DecodedValueRef(storage), field);

        bytes_read_ += DecodeStruct(Cursor(), Remaining(), field_ref);
    }

    // Decodes a fixed-extent scalar array in place: SetExternalMemory points the decoder at the decoded value's array,
    // so nothing is assigned afterwards. The extents come from the API member's declared type, the one the compiler
    // laid the storage out from; the static_asserts hold the Field's recorded extents equal to them.
    template <typename Field, typename Storage>
    requires schema::ScalarApiElement<typename Field::api_element> && schema::FixedArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");

        // The bound is PointerDecoder's, not the registry's: SetExternalMemory has one- and two-dimension overloads
        // only. A higher rank fails here, with this message, instead of as an unviable call.
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

        bytes_read_ +=
            field_ref.template DecodeAs<binding::WireTypeOf_t<typename Field::api_element>>(Cursor(), Remaining());
    }

    // Decodes a Pointer, Array or PointerArray of structures: allocates the wrapper's StructPointerDecoder, which reads
    // its own length from the wire (one element is a run of one) and decodes each element with DecodeStruct, and
    // points the decoded value's member at its storage. The wrapper declares every StructPointerDecoder member as a
    // pointer and every other decoder member by value, so the shape and category settle which form this writes; a
    // wrapper that broke that rule would fail to compile here.
    template <typename Field, typename Storage>
    requires schema::StructApiElement<typename Field::api_element> && schema::AnyPointerField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        using Decoder   = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;

        field_ref = DecodeAllocator::Allocate<Decoder>();

        bytes_read_ += field_ref->Decode(Cursor(), Remaining());

        schema::Set(DecodedValueRef(storage), field, field_ref->GetPointer());
    }

    // Decodes a fixed-extent array of structures in place: allocates the StructPointerDecoder as for any run of
    // structures, then SetExternalMemory points it at the decoded value's array, so nothing is assigned afterwards.
    template <typename Field, typename Storage>
    requires schema::StructApiElement<typename Field::api_element> && schema::FixedArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using Decoder   = std::remove_pointer_t<std::remove_cvref_t<decltype(field_ref)>>;
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent array of structures is one dimensional");

        field_ref = DecodeAllocator::Allocate<Decoder>();
        field_ref->SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref->Decode(Cursor(), Remaining());
    }

    // Decodes a fixed-extent array of handles. The two calls do unrelated things: Decode reads the capture ids into
    // the decoder's own storage, and SetExternalMemory does not redirect that; it makes the decoded value's array the
    // destination for the handles replay maps those ids to. Nothing is written to the decoded value here.
    // VkPhysicalDeviceGroupProperties::physicalDevices is the only field of this shape.
    template <typename Field, typename Storage>
    requires schema::HandleApiElement<typename Field::api_element> && schema::FixedArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);
        auto& array_ref = schema::GetRef(DecodedValueRef(storage), field);
        using ArrayType = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");
        static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent array of handles is one dimensional");

        field_ref.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);

        bytes_read_ += field_ref.Decode(Cursor(), Remaining());
    }

    // Decodes the extension chain with DecodePNextStruct, which selects each node's type by its sType at run time.
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
