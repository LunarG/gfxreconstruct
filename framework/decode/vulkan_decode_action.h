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
// Five overloads cover the structures reached so far. A field whose shape or kind none of them accepts makes
// WalkFields fail to compile and name the field, which is how the Action's coverage is bounded.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_ACTION_H
#define GFXRECON_DECODE_VULKAN_DECODE_ACTION_H

#include "decode/decode_allocator.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "schema/field_model.h"
#include "schema/schema_util.h"
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

// One adapter for each logical scalar kind, each naming the ValueDecoder function that already exists for it. The
// kind is not an alias for the function name: SampleMask, DeviceSize, DeviceAddress and Address all decode through a
// differently named function, because ValueDecoder has no entry point of their own.

// clang-format off
template <typename T> size_t DecodeScalar(schema::field_kind::Enum,    const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeEnumValue(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Flags,   const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeFlagsValue(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Flags64, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeFlags64Value(b, n, v); }

template <typename T> size_t DecodeScalar(schema::field_kind::UInt8,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt8Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::UInt16, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt16Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::UInt32, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt32Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::UInt64, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt64Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Int8,   const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeInt8Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Int16,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeInt16Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Int32,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeInt32Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Int64,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeInt64Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Float,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeFloatValue(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Double, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeDoubleValue(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::SizeT,  const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeSizeTValue(b, n, v); }

template <typename T> size_t DecodeScalar(schema::field_kind::SampleMask,    const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt32Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::DeviceSize,    const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt64Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::DeviceAddress, const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt64Value(b, n, v); }
template <typename T> size_t DecodeScalar(schema::field_kind::Address,       const uint8_t* b, size_t n, T* v) { return ValueDecoder::DecodeUInt64Value(b, n, v); }
// clang-format on

// field_kind::Char and field_kind::WChar have no adapter here on purpose. Text is never a value-shaped scalar; it
// reaches decode through StringDecoder and its relatives, which the pointer shapes select.

// The same one-liner-per-kind treatment for a run of scalars. PointerDecoder names its entry point by type rather
// than taking one, so this is a second table over the same kinds rather than a reuse of the one above. The decoder
// reads its own length from the wire, so a scalar array consults no sibling count field.

// clang-format off
template <typename D> size_t DecodeScalarArray(schema::field_kind::Enum,    const uint8_t* b, size_t n, D& d) { return d.DecodeEnum(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Flags,   const uint8_t* b, size_t n, D& d) { return d.DecodeFlags(b, n); }

template <typename D> size_t DecodeScalarArray(schema::field_kind::UInt8,  const uint8_t* b, size_t n, D& d) { return d.DecodeUInt8(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::UInt16, const uint8_t* b, size_t n, D& d) { return d.DecodeUInt16(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::UInt32, const uint8_t* b, size_t n, D& d) { return d.DecodeUInt32(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::UInt64, const uint8_t* b, size_t n, D& d) { return d.DecodeUInt64(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Int8,   const uint8_t* b, size_t n, D& d) { return d.DecodeInt8(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Int16,  const uint8_t* b, size_t n, D& d) { return d.DecodeInt16(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Int32,  const uint8_t* b, size_t n, D& d) { return d.DecodeInt32(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Int64,  const uint8_t* b, size_t n, D& d) { return d.DecodeInt64(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Float,  const uint8_t* b, size_t n, D& d) { return d.DecodeFloat(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Double, const uint8_t* b, size_t n, D& d) { return d.DecodeDouble(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::SizeT,  const uint8_t* b, size_t n, D& d) { return d.DecodeSizeT(b, n); }

template <typename D> size_t DecodeScalarArray(schema::field_kind::SampleMask,    const uint8_t* b, size_t n, D& d) { return d.DecodeVkSampleMask(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::DeviceSize,    const uint8_t* b, size_t n, D& d) { return d.DecodeVkDeviceSize(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::DeviceAddress, const uint8_t* b, size_t n, D& d) { return d.DecodeVkDeviceAddress(b, n); }
template <typename D> size_t DecodeScalarArray(schema::field_kind::Address,       const uint8_t* b, size_t n, D& d) { return d.DecodeVoidPtr(b, n); }
// clang-format on

// field_kind::Flags64 has no adapter because PointerDecoder has no entry point for it and no Vulkan structure
// declares an array of 64-bit flags. If one appears, WalkFields names the field and this is where it goes.

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
        bytes_read_ += DecodeScalar(
            typename Field::api_type::kind{}, Cursor(), Remaining(), &schema::GetRef(DecodedValueRef(storage), field));
    }

    // A run of scalars decodes into the wrapper's PointerDecoder, and the native pointer follows it, exactly as the
    // extension chain's does. The sibling count field is decoded as its own scalar in its own position; the array
    // length travels with the array on the wire, so nothing here reads across fields.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::PointerArrayField<Field> &&
        schema::Addressable<Storage, Field> && schema::Addressable<typename Storage::struct_type, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& field_ref = schema::GetRef(storage, field);

        bytes_read_ += DecodeScalarArray(typename Field::api_type::kind{}, Cursor(), Remaining(), field_ref);

        schema::GetRef(DecodedValueRef(storage), field) = field_ref.GetPointer();
    }

    // A handle decodes as the capture-file identity, into the decoded wrapper. The handle in the decoded value
    // stays null until replay maps the identity to a handle from this run.
    template <typename Field, typename Storage>
    requires schema::HandleField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        bytes_read_ += ValueDecoder::DecodeHandleIdValue(Cursor(), Remaining(), &schema::GetRef(storage, field));
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
