/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_POINTER_DECODER_H
#define GFXRECON_DECODE_POINTER_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T, typename OutputT = T>
class PointerDecoder : public PointerDecoderBase
{
  public:
    using ValueType = T;
    PointerDecoder() : data_(nullptr), capacity_(0), is_memory_external_(false), output_len_(0) {}

    T* GetPointer() { return data_; }

    const T* GetPointer() const { return data_; }

    size_t GetOutputLength() const { return output_len_; }

    OutputT* GetOutputPointer() { return output_data_; }

    const OutputT* GetOutputPointer() const { return output_data_; }

    OutputT* AllocateOutputData(size_t len)
    {
        output_len_ = len;

        // Default initialize output_data_
        output_data_ = DecodeAllocator::Allocate<OutputT>(len);

        return output_data_;
    }

    OutputT* AllocateOutputData(size_t len, const OutputT& init)
    {
        output_len_  = len;
        output_data_ = DecodeAllocator::Allocate<OutputT>(len, false);

        for (size_t i = 0; i < len; ++i)
        {
            output_data_[i] = init;
        }

        return output_data_;
    }

    template <size_t N, size_t M>
    void SetExternalMemory(T (&data)[N][M], size_t n, size_t m)
    {
        assert((data_ == nullptr) && (N == n) && (M == m));

        size_t capacity = n * m;

        if ((data != nullptr) && (capacity > 0))
        {
            data_               = reinterpret_cast<T*>(data);
            capacity_           = capacity;
            is_memory_external_ = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("Pointer decoder's external memory was initialized with a NULL pointer");
        }
    }

    void SetExternalMemory(T* data, size_t capacity)
    {
        assert(data_ == nullptr);

        if ((data != nullptr) && (capacity > 0))
        {
            data_               = data;
            capacity_           = capacity;
            is_memory_external_ = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("Pointer decoder's external memory was initialized with a NULL pointer");
        }
    }

    // clang-format off
    size_t DecodeInt8(const uint8_t* buffer, size_t buffer_size)         { return DecodeFrom<int8_t>(buffer, buffer_size); }
    size_t DecodeInt16(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<int16_t>(buffer, buffer_size); }
    size_t DecodeUInt16(const uint8_t* buffer, size_t buffer_size)       { return DecodeFrom<uint16_t>(buffer, buffer_size); }
    size_t DecodeInt32(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<int32_t>(buffer, buffer_size); }
    size_t DecodeUInt32(const uint8_t* buffer, size_t buffer_size)       { return DecodeFrom<uint32_t>(buffer, buffer_size); }
    size_t DecodeInt64(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<int64_t>(buffer, buffer_size); }
    size_t DecodeUInt64(const uint8_t* buffer, size_t buffer_size)       { return DecodeFrom<uint64_t>(buffer, buffer_size); }
    size_t DecodeFloat(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<float>(buffer, buffer_size); }
    // Decode pointer to a void pointer, encoded with ParameterEncoder::EncodeVoidPtrPtr.
    size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size)      { return DecodeFrom<format::AddressEncodeType>(buffer, buffer_size); }

    // Decode for array of bytes.
    size_t DecodeUInt8(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<uint8_t>(buffer, buffer_size); }
    size_t DecodeVoid(const uint8_t* buffer, size_t buffer_size)         { return DecodeFrom<uint8_t>(buffer, buffer_size); }

    // Decode for special types that may require conversion.
    size_t DecodeEnum(const uint8_t* buffer, size_t buffer_size)            { return DecodeFrom<format::EnumEncodeType>(buffer, buffer_size); }
    size_t DecodeFlags(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<format::FlagsEncodeType>(buffer, buffer_size); }
    size_t DecodeVkSampleMask(const uint8_t* buffer, size_t buffer_size)    { return DecodeFrom<format::SampleMaskEncodeType>(buffer, buffer_size); }
    size_t DecodeHandleId(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<format::HandleEncodeType>(buffer, buffer_size); }
    size_t DecodeVkDeviceSize(const uint8_t* buffer, size_t buffer_size)    { return DecodeFrom<format::DeviceSizeEncodeType>(buffer, buffer_size); }
    size_t DecodeVkDeviceAddress(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<format::DeviceAddressEncodeType>(buffer, buffer_size); }
    size_t DecodeSizeT(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<format::SizeTEncodeType>(buffer, buffer_size); }
    size_t DecodeLARGE_INTEGER(const uint8_t* buffer, size_t buffer_size)   { return DecodeFrom<int64_t>(buffer, buffer_size); }
    size_t DecodeLUID(const uint8_t* buffer, size_t buffer_size)            { return DecodeFrom<int64_t>(buffer, buffer_size); }
    // clang-format on

  private:
    template <typename SrcT>
    size_t DecodeFrom(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should not be decoding string arrays or structs.
        assert((GetAttributeMask() & (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray)) !=
               (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray));
        assert((GetAttributeMask() & (format::PointerAttributes::kIsWString | format::PointerAttributes::kIsArray)) !=
               (format::PointerAttributes::kIsWString | format::PointerAttributes::kIsArray));
        assert((GetAttributeMask() & format::PointerAttributes::kIsStruct) != format::PointerAttributes::kIsStruct);

        if (!IsNull())
        {
            if (!is_memory_external_)
            {
                bytes_read += DecodeInternal<SrcT>((buffer + bytes_read), (buffer_size - bytes_read));
            }
            else
            {
                bytes_read += DecodeExternal<SrcT>((buffer + bytes_read), (buffer_size - bytes_read));
            }
        }

        return bytes_read;
    }

    template <typename SrcT>
    size_t DecodeInternal(const uint8_t* buffer, size_t buffer_size)
    {
        assert(data_ == nullptr);

        size_t bytes_read = 0;
        size_t len        = GetLength();

        if (HasData())
        {
            data_      = DecodeAllocator::Allocate<T>(len, false);
            bytes_read = ValueDecoder::DecodeArrayFrom<SrcT>(buffer, buffer_size, data_, len);
        }
        else
        {
            // Allocate and default initialize
            data_ = DecodeAllocator::Allocate<T>(len);
        }

        return bytes_read;
    }

    template <typename SrcT>
    size_t DecodeExternal(const uint8_t* buffer, size_t buffer_size)
    {
        assert(data_ != nullptr);

        size_t bytes_read = 0;

        if (HasData())
        {
            size_t len = GetLength();

            if (len <= capacity_)
            {
                ValueDecoder::DecodeArrayFrom<SrcT>(buffer, buffer_size, data_, len);
            }
            else
            {
                // The external memory cacpacity is not large enough to contain the full decoded array.
                ValueDecoder::DecodeArrayFrom<SrcT>(buffer, buffer_size, data_, capacity_);

                GFXRECON_LOG_WARNING("Pointer decoder's external memory capacity (%" PRIuPTR
                                     ") is smaller than the decoded array size (%" PRIuPTR "); data will be truncated",
                                     capacity_,
                                     len);
            }

            // We always need to advance the position within the buffer by the amount of data that was expected to
            // be decoded, not the actual amount of data decoded if capacity is too small to hold all of the data.
            bytes_read = sizeof(SrcT) * len;
        }

        return bytes_read;
    }

  private:
    /// Memory to hold decoded data. Points to an internal allocation when #is_memory_external_ is false and
    /// to an externally provided allocation when #is_memory_external_ is true.
    T*     data_;
    size_t capacity_; ///< Size of external memory allocation referenced by #data_ when #is_memory_external_ is true.
    bool   is_memory_external_; ///< Indicates that the memory referenced by #data_ is an external allocation.

    /// Optional memory allocated for output pramaters when retrieving data from a function call. Allows both the data
    /// read from the file and the data retrieved from an API call to exist simultaneously, allowing the values to be
    /// compared.
    OutputT* output_data_{ nullptr };
    size_t   output_len_; ///< Size of #output_data_.
};

template <typename T>
class PointerDecoder<T*> : public PointerDecoderBase
{
  public:
    PointerDecoder() : data_(nullptr), inner_lengths_(nullptr) {}

    T** GetPointer() { return data_; }

    const T* const* GetPointer() const { return data_; }

    size_t GetInnerLength(size_t i) const
    {
        return ((i < GetLength()) && (inner_lengths_ != nullptr)) ? inner_lengths_[i] : 0;
    }

    // clang-format off
    size_t DecodeInt32(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<int32_t>(buffer, buffer_size); }
    size_t DecodeUInt32(const uint8_t* buffer, size_t buffer_size)          { return DecodeFrom<uint32_t>(buffer, buffer_size); }
    size_t DecodeInt64(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<int64_t>(buffer, buffer_size); }
    size_t DecodeUInt64(const uint8_t* buffer, size_t buffer_size)          { return DecodeFrom<uint64_t>(buffer, buffer_size); }
    size_t DecodeFloat(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<float>(buffer, buffer_size); }

    // Decode pointer to a void pointer, encoded with ParameterEncoder::EncodeVoidPtrPtr.
    size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size)         { return DecodeFrom<format::AddressEncodeType>(buffer, buffer_size); }

    // Decode for array of bytes.
    size_t DecodeUInt8(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<uint8_t>(buffer, buffer_size); }
    size_t DecodeVoid(const uint8_t* buffer, size_t buffer_size)            { return DecodeFrom<uint8_t>(buffer, buffer_size); }

    // Decode for special types that may require conversion.
    size_t DecodeEnum(const uint8_t* buffer, size_t buffer_size)            { return DecodeFrom<format::EnumEncodeType>(buffer, buffer_size); }
    size_t DecodeFlags(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<format::FlagsEncodeType>(buffer, buffer_size); }
    size_t DecodeVkSampleMask(const uint8_t* buffer, size_t buffer_size)    { return DecodeFrom<format::SampleMaskEncodeType>(buffer, buffer_size); }
    size_t DecodeHandleId(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<format::HandleEncodeType>(buffer, buffer_size); }
    size_t DecodeVkDeviceSize(const uint8_t* buffer, size_t buffer_size)    { return DecodeFrom<format::DeviceSizeEncodeType>(buffer, buffer_size); }
    size_t DecodeVkDeviceAddress(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<format::DeviceAddressEncodeType>(buffer, buffer_size); }
    size_t DecodeSizeT(const uint8_t* buffer, size_t buffer_size)           { return DecodeFrom<format::SizeTEncodeType>(buffer, buffer_size); }
    // clang-format on

  private:
    template <typename SrcT>
    size_t DecodeFrom(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should not be decoding pointers, arrays, or structs.
        assert((GetAttributeMask() & format::PointerAttributes::kIsSingle) != format::PointerAttributes::kIsSingle);
        assert((GetAttributeMask() & format::PointerAttributes::kIsArray) != format::PointerAttributes::kIsArray);
        assert((GetAttributeMask() & format::PointerAttributes::kIsStruct) != format::PointerAttributes::kIsStruct);

        // We should only be decoding 2D arrays
        assert((GetAttributeMask() & format::PointerAttributes::kIsArray2D) == format::PointerAttributes::kIsArray2D);

        if (!IsNull() && HasData())
        {
            bytes_read += DecodeInternal<SrcT>((buffer + bytes_read), (buffer_size - bytes_read));
        }

        return bytes_read;
    }

    template <typename SrcT>
    size_t DecodeInternal(const uint8_t* buffer, size_t buffer_size)
    {
        assert(data_ == nullptr);

        size_t bytes_read = 0;
        size_t len        = GetLength();

        data_          = DecodeAllocator::Allocate<T*>(len, false);
        inner_lengths_ = DecodeAllocator::Allocate<size_t>(len);

        for (size_t i = 0; i < len; ++i)
        {
            uint32_t attrib = 0;
            bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

            if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
            {
                if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
                {
                    uint64_t address;
                    bytes_read +=
                        ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address);
                }

                // We should not be decoding string arrays or structs.
                assert((GetAttributeMask() &
                        (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray)) !=
                       (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray));
                assert((GetAttributeMask() &
                        (format::PointerAttributes::kIsWString | format::PointerAttributes::kIsArray)) !=
                       (format::PointerAttributes::kIsWString | format::PointerAttributes::kIsArray));
                assert((GetAttributeMask() & format::PointerAttributes::kIsStruct) !=
                       format::PointerAttributes::kIsStruct);

                size_t inner_len = 0;
                bytes_read +=
                    ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &inner_len);

                T* inner_data = DecodeAllocator::Allocate<T>(inner_len);
                bytes_read += ValueDecoder::DecodeArrayFrom<SrcT>(
                    (buffer + bytes_read), (buffer_size - bytes_read), inner_data, inner_len);

                data_[i]          = inner_data;
                inner_lengths_[i] = inner_len;
            }
            else
            {
                data_[i] = nullptr;
            }
        }

        return bytes_read;
    }

  private:
    T**     data_; ///< Memory to hold decoded data
    size_t* inner_lengths_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_POINTER_DECODER_H
