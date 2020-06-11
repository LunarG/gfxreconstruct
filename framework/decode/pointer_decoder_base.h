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

#ifndef GFXRECON_DECODE_POINTER_DECODER_BASE_H
#define GFXRECON_DECODE_POINTER_DECODER_BASE_H

#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class PointerDecoderBase
{
  public:
    PointerDecoderBase() : len_(0), address_(0), attrib_(format::PointerAttributes::kIsNull) {}

    virtual ~PointerDecoderBase() {}

    bool IsNull() const
    {
        return ((attrib_ & format::PointerAttributes::kIsNull) == format::PointerAttributes::kIsNull) ? true : false;
    }

    bool HasAddress() const
    {
        return ((attrib_ & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress) ? true
                                                                                                              : false;
    }

    bool HasData() const
    {
        return ((attrib_ & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData) ? true : false;
    }

    uint32_t GetAttributeMask() const { return attrib_; }

    uint64_t GetAddress() const { return address_; }

    size_t GetLength() const { return len_; }

  protected:
    size_t DecodeAttributes(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = 0;

        bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib_);

        if ((attrib_ & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
        {
            if ((attrib_ & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address_);
            }

            if (((attrib_ & format::PointerAttributes::kIsArray) == format::PointerAttributes::kIsArray) ||
                ((attrib_ & format::PointerAttributes::kIsString) == format::PointerAttributes::kIsString) ||
                ((attrib_ & format::PointerAttributes::kIsWString) == format::PointerAttributes::kIsWString))
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
    size_t   len_;
    uint64_t address_;
    uint32_t attrib_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_POINTER_DECODER_BASE_H
