/*
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

#ifndef BRIMSTONE_FORMAT_POINTER_DECODER_H
#define BRIMSTONE_FORMAT_POINTER_DECODER_H

#include <cassert>

#include "util/defines.h"
#include "format/format.h"
#include "format/pointer_decoder_base.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

template<typename T>
class PointerDecoder : public PointerDecoderBase
{
public:
    PointerDecoder() : data_(nullptr), capacity_(0), is_memory_external_(false) { }

    ~PointerDecoder() { if ((data_ != nullptr) && !is_memory_external_) delete [] data_; }

    T* GetPointer() const { return data_; }

    void SetExternalMemory(T* data, size_t capacity)
    {
        if ((data != nullptr) && (capacity > 0))
        {
            data_ = data;
            capacity_ = capacity;
            is_memory_external_ = true;
        }
        else
        {
            // TODO: Log an error message
        }
    }

    size_t Decode(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<T>(buffer, buffer_size); }

    // Decode for special types that may require conversion.
    size_t DecodeEnum(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<EnumEncodeType>(buffer, buffer_size); }
    size_t DecodeFlags(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<FlagsEncodeType>(buffer, buffer_size); }
    size_t DecodeSampleMask(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<SampleMaskEncodeType>(buffer, buffer_size); }
    size_t DecodeHandle(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<HandleEncodeType>(buffer, buffer_size); }
    size_t DecodeDeviceSize(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<DeviceSizeEncodeType>(buffer, buffer_size); }
    size_t DecodeSizeT(const uint8_t* buffer, size_t buffer_size) { return DecodeFrom<SizeTEncodeType>(buffer, buffer_size); }

private:
    template <typename SrcT>
    size_t DecodeFrom(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should not be decoding string arrays or structs.
        assert((GetAttributeMask() & (PointerAttributes::kIsString | PointerAttributes::kIsArray)) != (PointerAttributes::kIsString | PointerAttributes::kIsArray));
        assert((GetAttributeMask() & PointerAttributes::kIsStruct) != PointerAttributes::kIsStruct);

        if (!IsNull() && HasData())
        {
            size_t len = GetLength();

            if (!is_memory_external_)
            {
                assert(data_ == nullptr);

                data_ = new T[len];
                capacity_ = len;
                bytes_read += ValueDecoder::DecodeArrayFrom<SrcT>((buffer + bytes_read), (buffer_size - bytes_read), data_, len);
            }
            else
            {
                assert(data_ != nullptr);

                // TODO: Report error if len > capacity_
                ValueDecoder::DecodeArrayFrom<SrcT>((buffer + bytes_read), (buffer_size - bytes_read), data_, (len > capacity_) ? capacity_ : len);

                // We always need to advance the position within the buffer by the amount of data that was expected to be decoded, not
                // the actual amount of data decoded if capacity is too small to hold all of the data.
                bytes_read += sizeof(SrcT) * len;
            }
        }

        return bytes_read;
    }

private:
    T*      data_;
    size_t  capacity_;
    bool    is_memory_external_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_POINTER_DECODER_H
