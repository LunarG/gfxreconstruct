/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_POINTER_DECODER_H
#define GFXRECON_DECODE_POINTER_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class PointerDecoder : public PointerDecoderBase
{
  public:
    PointerDecoder() : data_(nullptr), capacity_(0), is_memory_external_(false) {}

    virtual ~PointerDecoder() override
    {
        if ((data_ != nullptr) && !is_memory_external_)
            delete[] data_;
    }

    T* GetPointer() const { return data_; }

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
    size_t DecodeInt32(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<int32_t>(buffer, buffer_size); }
    size_t DecodeUInt32(const uint8_t* buffer, size_t buffer_size)       { return DecodeFrom<uint32_t>(buffer, buffer_size); }
    size_t DecodeInt64(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<int64_t>(buffer, buffer_size); }
    size_t DecodeUInt64(const uint8_t* buffer, size_t buffer_size)       { return DecodeFrom<uint64_t>(buffer, buffer_size); }
    size_t DecodeFloat(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<float>(buffer, buffer_size); }
    size_t DecodeVkBool32(const uint8_t* buffer, size_t buffer_size)     { return DecodeFrom<VkBool32>(buffer, buffer_size); }

    // Decode pointer to a void pointer, encoded with ParameterEncoder::EncodeVoidPtrPtr.
    size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size)      { return DecodeFrom<format::AddressEncodeType>(buffer, buffer_size); }

    // Decode for array of bytes.
    size_t DecodeUInt8(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<uint8_t>(buffer, buffer_size); }
    size_t DecodeVoid(const uint8_t* buffer, size_t buffer_size)         { return DecodeFrom<uint8_t>(buffer, buffer_size); }

    // Decode for special types that may require conversion.
    size_t DecodeEnum(const uint8_t* buffer, size_t buffer_size)         { return DecodeFrom<format::EnumEncodeType>(buffer, buffer_size); }
    size_t DecodeFlags(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<format::FlagsEncodeType>(buffer, buffer_size); }
    size_t DecodeVkSampleMask(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<format::SampleMaskEncodeType>(buffer, buffer_size); }
    size_t DecodeHandleId(const uint8_t* buffer, size_t buffer_size)     { return DecodeFrom<format::HandleEncodeType>(buffer, buffer_size); }
    size_t DecodeVkDeviceSize(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<format::DeviceSizeEncodeType>(buffer, buffer_size); }
    size_t DecodeSizeT(const uint8_t* buffer, size_t buffer_size)        { return DecodeFrom<format::SizeTEncodeType>(buffer, buffer_size); }
    // clang-format on

  private:
    template <typename SrcT>
    size_t DecodeFrom(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should not be decoding string arrays or structs.
        assert((GetAttributeMask() & (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray)) !=
               (format::PointerAttributes::kIsString | format::PointerAttributes::kIsArray));
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

        data_     = new T[len];
        capacity_ = len;

        if (HasData())
        {
            bytes_read = ValueDecoder::DecodeArrayFrom<SrcT>(buffer, buffer_size, data_, len);
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
    T*     data_;
    size_t capacity_;
    bool   is_memory_external_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_POINTER_DECODER_H
