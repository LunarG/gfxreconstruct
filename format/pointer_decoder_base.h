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

#ifndef BRIMSTONE_FORMAT_POINTER_DECODER_BASE_H
#define BRIMSTONE_FORMAT_POINTER_DECODER_BASE_H

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

    uint32_t GetAttributeMask() const { return attrib_; }

    uint64_t GetAddress() const { return address_; }

    size_t GetLength() const { return len_; }

protected:
    size_t DecodeAttributes(const uint8_t* buffer, size_t buffer_size)
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
        }

        return bytes_read;
    }

private:
    size_t                  len_;
    uint64_t                address_;
    uint32_t                attrib_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_POINTER_DECODER_BASE_H
