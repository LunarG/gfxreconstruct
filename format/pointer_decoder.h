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
#include <limits>
#include <memory>

#include "util/defines.h"
#include "format/format.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class PointerDecoderBase
{
public:
    PointerDecoderBase() : len_(0), address_(0), attrib_(PointerAttributes::kIsNull) { }

    ~PointerDecoderBase() { }

    bool IsNull() const { return ((attrib_ & PointerAttributes::kIsNull) == PointerAttributes::kIsNull) ? true : false; }

    bool HasAddress() const { return ((attrib_ & PointerAttributes::kHasAddress) == PointerAttributes::kHasAddress) ? true : false; }

    bool HasData() const { return ((attrib_ & PointerAttributes::kHasData) == PointerAttributes::kHasData) ? true : false; }

    uint64_t GetAddress() const { return address_; }

    size_t GetLength() const { return len_; }

protected:
    size_t                  len_;
    uint64_t                address_;
    uint32_t                attrib_;
};

template<typename T>
class PointerDecoder : public PointerDecoderBase
{
public:
    PointerDecoder() : data_(nullptr) { }

    ~PointerDecoder() { DestroyData<T>(); }

    T* GetPointer() const { return data_.get(); }

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
        size_t bytes_read = 0;

        bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib_);

        if ((attrib_ & PointerAttributes::kIsNull) != PointerAttributes::kIsNull)
        {
            if ((attrib_ & PointerAttributes::kHasAddress) == PointerAttributes::kHasAddress)
            {
                bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address_);
            }

            if (((attrib_ & PointerAttributes::kIsArray) == PointerAttributes::kIsArray) ||
                ((attrib_ & PointerAttributes::kIsString) == PointerAttributes::kIsString))
            {
                bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &len_);
            }
            else
            {
                len_ = 1;
            }

            if (((attrib_ & PointerAttributes::kHasData) == PointerAttributes::kHasData))
            {
                data_ = std::make_unique<T[]>(len_);
                bytes_read += DecodeData<T, SrcT>((buffer + bytes_read), (buffer_size - bytes_read), &data_, len_);
            }
        }

        return bytes_read;
    }

    template <typename DstT, typename SrcT>
    size_t DecodeData(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<DstT[]>* data, size_t len)
    {
        assert(data != nullptr);
        assert((attrib_ & (PointerAttributes::kIsString | PointerAttributes::kIsArray)) != (PointerAttributes::kIsString | PointerAttributes::kIsArray));

        return ValueDecoder::DecodeArrayFrom<SrcT>(buffer, buffer_size, data->get(), len);
    }

    template <>
    size_t DecodeData<char*, char*>(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<char*[]>* data, size_t len)
    {
        assert(data != nullptr);
        assert((attrib_ & (PointerAttributes::kIsString | PointerAttributes::kIsArray)) == (PointerAttributes::kIsString | PointerAttributes::kIsArray));

        size_t bytes_read = 0;

        for (size_t i = 0; i < len; ++i)
        {
            bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib_);

            if ((attrib_ & PointerAttributes::kIsNull) != PointerAttributes::kIsNull)
            {
                if ((attrib_ & PointerAttributes::kHasAddress) == PointerAttributes::kHasAddress)
                {
                    // TODO: Store address for individual strings.
                    uint64_t address = 0;
                    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address);
                }

                assert((attrib_ & PointerAttributes::kIsString) == PointerAttributes::kIsString);

                size_t slen = 0;
                bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &slen);

                char* value = new char[slen + 1];

                if (((attrib_ & PointerAttributes::kHasData) == PointerAttributes::kHasData))
                {
                    bytes_read += ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), value, slen);
                    value[slen] = '\0';
                }
                else
                {
                    value[0] = '\0';
                }

                (*data)[i] = value;
            }
            else
            {
                (*data)[i] = nullptr;
            }
        }

        return bytes_read;
    }

    template<typename S>
    void DestroyData() { }

    template<>
    void DestroyData<char*>()
    {
        assert((attrib_ & (PointerAttributes::kIsString | PointerAttributes::kIsArray)) == (PointerAttributes::kIsString | PointerAttributes::kIsArray));

        if (data_ != nullptr)
        {
            // Must explicitly destroy the individual strings in the array.
            for (size_t i = 0; i < len_; ++i)
            {
                delete[] data_[i];
                data_[i] = nullptr;
            }
        }
    }

private:
    std::unique_ptr<T[]>    data_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_POINTER_DECODER_H
