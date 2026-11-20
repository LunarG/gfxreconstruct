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

// DecodeStructAction: the schema::WalkFields Action that decodes a Decoded_ wrapper. Caller: DecodeStruct.
//
// One Apply per declaration shape: value, pointer, array, fixed array. Each Apply branches once on the category of the
// Field's API element. A scalar, enum, bitmask or identifier decodes as binding::WireTypeOf of its API element, so a
// new width is a WireTypeOf specialization, not a new Decode method.
//
// Limitations: a pointer to a pointer, a Pointer or an Array of pointers to handles, and a run of function-pointer
// API elements fail a static_assert in their Apply.
//
// Lifetime: one instance walks one structure; it carries the read cursor, and BytesRead() returns the bytes consumed.
// The decoders and nested wrappers it allocates come from DecodeAllocator, so the walk must run between
// DecodeAllocator::Begin() and End().

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

// The Decoded_ wrappers the Apply set reads members of.
#include "generated/generated_vulkan_struct_decoders.h"

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

    // Decodes a value. Storage is the Decoded_ wrapper: it holds a member for a structure or an identifier, and the
    // API structure it wraps, the decoded value, holds every member.
    template <typename Storage, typename Field>
    requires schema::ValueField<Field> && schema::StorageFor<typename Storage::struct_type, Field>
    void Apply(Storage& storage, Field field)
    {
        using Element = typename Field::api_element;

        if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            // An embedded structure: allocates the Decoded_ wrapper the member points at, links its decoded_value to
            // the decoded value's inline member, and calls DecodeStruct. A schema-driven type reaches the DecodeStruct
            // template and walks its own Fields; a union, or a structure with a hand-written decoder, reaches its
            // hand-written DecodeStruct overload. The wrapper type is the member's declared type, so no decoded-type
            // binding is read.
            using DecodeWrapper     = std::remove_pointer_t<schema::StoredTypeOf_t<Storage, Field>>;
            DecodeWrapper*& wrapper = Field::GetRef(storage);

            wrapper                = DecodeAllocator::Allocate<DecodeWrapper>();
            wrapper->decoded_value = &Field::GetRef(DecodedValueRef(storage));

            bytes_read_ += DecodeStruct(Cursor(), Remaining(), wrapper);
        }
        else if constexpr (schema::IdentifierApiElement<Element> || schema::FieldWithObjectType<Field>)
        {
            // An identifier: a handle, a function pointer, or a generic handle, a uint64_t member the registry marks
            // objecttype. Its capture id or address goes to the wrapper member, and the decoded value's member is set
            // to ValueType{}, the null of its declared type: VK_NULL_HANDLE for a handle, pointer or integer by build;
            // nullptr for a function pointer; 0 for a generic handle. Replay maps a handle member through
            // MapStructHandles, a generic handle by the object type its objecttype_field holds; nothing restores an
            // address.
            using ValueType = schema::StoredTypeOf_t<typename Storage::struct_type, Field>;

            bytes_read_ +=
                ValueDecoder::DecodeAs<binding::WireTypeOf_t<Element>>(Cursor(), Remaining(), &Field::GetRef(storage));

            Field::GetRef(DecodedValueRef(storage)) = ValueType{};
        }
        else
        {
            // A scalar decodes into a local and is written through schema::Set, not in place: a bitfield member has no
            // address ([class.bit]/3), and Set reaches the Field's Set. A bitfield is recorded as a whole value of its
            // API element's type -- a one-bit flag is four bytes -- and narrowed on the write.
            static_assert(schema::SimpleApiElement<Element>, "No decoder call for a value of this category");
            schema::ApiTypeOf_t<Element> value{};

            bytes_read_ += ValueDecoder::DecodeAs<binding::WireTypeOf_t<Element>>(Cursor(), Remaining(), &value);

            schema::Set(DecodedValueRef(storage), field, value);
        }
    }

    // Decodes a pointer to one item, or an extension chain, into the wrapper's member, and settles the decoded
    // value's member. A decoder reads the length from the capture, so one item is a run of one.
    template <typename Storage, typename Field>
    requires schema::PointerField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Storage& storage, Field)
    {
        using Element   = typename Field::api_element;
        auto& value_ref = Field::GetRef(DecodedValueRef(storage));

        if constexpr (schema::ExtensionChainField<Field>)
        {
            // The extension chain. NOTE: MUST be tested before the Void branch: pNext is declared
            // Pointer<Const<Void>>, and the Void branch would read it as an address. DecodePNextStruct selects each
            // node's type by its sType at run time.
            PNextNode*& pnext = Field::GetRef(storage);

            bytes_read_ += DecodePNextStruct(Cursor(), Remaining(), &pnext);

            value_ref = pnext ? pnext->GetPointer() : nullptr;
        }
        else if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            // Allocates the wrapper's StructPointerDecoder, which decodes the structure with DecodeStruct. The wrapper
            // declares every StructPointerDecoder member as a pointer and every other decoder member by value; a
            // wrapper that broke that rule would fail to compile here.
            using StructDecoder     = std::remove_pointer_t<schema::StoredTypeOf_t<Storage, Field>>;
            StructDecoder*& decoder = Field::GetRef(storage);

            decoder = DecodeAllocator::Allocate<StructDecoder>();

            bytes_read_ += decoder->Decode(Cursor(), Remaining());

            value_ref = decoder->GetPointer();
        }
        else if constexpr (schema::VoidApiElement<Element>)
        {
            // A pointer to void, Pointer<Void>, or to a platform type curation leaves undefined,
            // Pointer<ANativeWindow>, Pointer<deref_HWND>: its address goes to the wrapper's uint64_t member, and the
            // decoded value's pointer is null.
            static_assert(!schema::PointerToPointerField<Field>, "No decoder call for a pointer to a pointer");

            uint64_t& address = Field::GetRef(storage);

            bytes_read_ += ValueDecoder::DecodeAddress(Cursor(), Remaining(), &address);

            value_ref = nullptr;
        }
        else
        {
            static_assert(schema::SimpleApiElement<Element>, "No decoder call for a pointer to this category");

            auto& decoder = Field::GetRef(storage);

            bytes_read_ += decoder.template DecodeAs<binding::WireTypeOf_t<Element>>(Cursor(), Remaining());

            value_ref = decoder.GetPointer();
        }
    }

    // Decodes an Array into the wrapper's decoder member, and settles the decoded value's member. The decoder reads
    // the length from the capture; the count member decodes as its own Field, and nothing here reads across Fields.
    template <typename Storage, typename Field>
    requires schema::ArrayField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Storage& storage, Field)
    {
        using Element   = typename Field::api_element;
        auto& value_ref = Field::GetRef(DecodedValueRef(storage));

        if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            // Allocates the wrapper's StructPointerDecoder, which decodes each element with DecodeStruct. The wrapper
            // declares every StructPointerDecoder member as a pointer and every other decoder member by value; a
            // wrapper that broke that rule would fail to compile here.
            using StructDecoder     = std::remove_pointer_t<schema::StoredTypeOf_t<Storage, Field>>;
            StructDecoder*& decoder = Field::GetRef(storage);

            decoder = DecodeAllocator::Allocate<StructDecoder>();

            bytes_read_ += decoder->Decode(Cursor(), Remaining());

            value_ref = decoder->GetPointer();
        }
        else if constexpr (schema::HandleApiElement<Element>)
        {
            // A run of handles: the HandlePointerDecoder holds capture ids, and replay's MapStructHandles points the
            // member at the handles it maps them to. HandlePointerDecoder::Decode always reads
            // format::HandleEncodeType, so no wire type is passed.
            static_assert(!schema::PointerArrayField<Field>, "No decoder call for an Array of pointers to handles");

            auto& decoder = Field::GetRef(storage);

            bytes_read_ += decoder.Decode(Cursor(), Remaining());

            value_ref = nullptr;
        }
        else if constexpr (schema::VoidApiElement<Element>)
        {
            // An Array of Void is a run of bytes; its length is the byte count.
            static_assert(!schema::PointerArrayField<Field>, "No decoder call for an Array of pointers to void");

            auto& decoder = Field::GetRef(storage);

            bytes_read_ += decoder.DecodeUInt8(Cursor(), Remaining());

            value_ref = decoder.GetPointer();
        }
        else if constexpr (schema::StringField<Field> || schema::StringArrayField<Field>)
        {
            // One string, Array<Const<Char>, NullTerminated>, or a run of strings: the wrapper's StringDecoder,
            // WStringDecoder or StringArrayDecoder reads its own length and fixes its encode type by template
            // argument, so no wire type is passed.
            auto& decoder = Field::GetRef(storage);

            bytes_read_ += decoder.Decode(Cursor(), Remaining());

            value_ref = decoder.GetPointer();
        }
        else
        {
            static_assert(schema::SimpleApiElement<Element>, "No decoder call for an Array of this category");

            auto& decoder = Field::GetRef(storage);

            bytes_read_ += decoder.template DecodeAs<binding::WireTypeOf_t<Element>>(Cursor(), Remaining());

            value_ref = decoder.GetPointer();
        }
    }

    // Decodes a fixed-extent array in place: SetExternalMemory points the decoder at the decoded value's array, so
    // nothing is assigned afterwards. The extents come from the API member's declared type, the one the compiler laid
    // the storage out from; the static_asserts hold the Field's recorded extents equal to them. A count member
    // decodes before its array, and SetExpectedLength gives it to the decoder, which checks the encoded length
    // against it.
    template <typename Storage, typename Field>
    requires schema::FixedArrayField<Field> && schema::StorageFor<Storage, Field>
    void Apply(Storage& storage, Field)
    {
        using Element   = typename Field::api_element;
        using ArrayType = schema::StoredTypeOf_t<typename Storage::struct_type, Field>;

        ArrayType& array_ref = Field::GetRef(DecodedValueRef(storage));

        static_assert(std::is_array_v<ArrayType>,
                      "A FixedArray field must be declared as an array in the API type it belongs to");
        static_assert(schema::DeclaredExtentsMatch_v<ArrayType, Field>,
                      "A FixedArray field's recorded extents must equal the extents the API type declares");

        if constexpr (schema::StructOrUnionApiElement<Element>)
        {
            // Allocates the StructPointerDecoder as for any run of structures.
            static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent array of structures is one dimensional");
            using StructDecoder     = std::remove_pointer_t<schema::StoredTypeOf_t<Storage, Field>>;
            StructDecoder*& decoder = Field::GetRef(storage);

            decoder = DecodeAllocator::Allocate<StructDecoder>();
            decoder->SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);
            SetExpectedLength<Field>(storage, *decoder);

            bytes_read_ += decoder->Decode(Cursor(), Remaining());
        }
        else if constexpr (schema::HandleApiElement<Element> || schema::StringField<Field>)
        {
            // A string decodes in place. For handles the two calls do unrelated things: Decode reads the capture ids
            // into the decoder's own storage, and SetExternalMemory does not redirect that; it makes the decoded
            // value's array the destination for the handles replay maps those ids to.
            // VkPhysicalDeviceGroupProperties::physicalDevices is the only handle field of this shape.
            static_assert(std::rank_v<ArrayType> == 1, "A fixed-extent string or array of handles is one dimensional");

            auto& decoder = Field::GetRef(storage);

            decoder.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);
            SetExpectedLength<Field>(storage, decoder);

            bytes_read_ += decoder.Decode(Cursor(), Remaining());
        }
        else
        {
            static_assert(schema::SimpleApiElement<Element>, "No decoder call for a fixed array of this category");

            // The bound is PointerDecoder's, not the registry's: SetExternalMemory has one- and two-dimension
            // overloads only. A higher rank fails here, with this message, instead of as an unviable call.
            static_assert(std::rank_v<ArrayType> <= 2,
                          "PointerDecoder::SetExternalMemory covers one and two dimensions only");

            auto& decoder = Field::GetRef(storage);

            if constexpr (std::rank_v<ArrayType> == 2)
            {
                decoder.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>, std::extent_v<ArrayType, 1>);
            }
            else
            {
                decoder.SetExternalMemory(array_ref, std::extent_v<ArrayType, 0>);
                SetExpectedLength<Field>(storage, decoder);
            }

            bytes_read_ += decoder.template DecodeAs<binding::WireTypeOf_t<Element>>(Cursor(), Remaining());
        }
    }

  private:
    const uint8_t* Cursor() const { return buffer_ + bytes_read_; }

    size_t Remaining() const { return buffer_size_ - bytes_read_; }

    template <typename Storage>
    static typename Storage::struct_type& DecodedValueRef(Storage& storage)
    {
        return *storage.decoded_value;
    }

    // Gives decoder the value of a fixed array's count member, which the walk decoded before the array. Does nothing
    // for an array with no count member.
    template <typename Field, typename Storage, typename Decoder>
    static void SetExpectedLength(Storage& storage, Decoder& decoder)
    {
        if constexpr (schema::StorageWithLength<typename Storage::struct_type, Field>)
        {
            decoder.SetExpectedLength(static_cast<size_t>(schema::LengthOf_t<Field>::Get(DecodedValueRef(storage))));
        }
    }

    const uint8_t* buffer_{ nullptr };
    size_t         buffer_size_{ 0 };
    size_t         bytes_read_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_ACTION_H
