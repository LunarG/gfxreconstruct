/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

    bool IsArray() const
    {
        return ((attrib_ & format::PointerAttributes::kIsArray) == format::PointerAttributes::kIsArray) ? true : false;
    }

    bool IsArray2D() const
    {
        return ((attrib_ & format::PointerAttributes::kIsArray2D) == format::PointerAttributes::kIsArray2D) ? true
                                                                                                            : false;
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
                ((attrib_ & format::PointerAttributes::kIsArray2D) == format::PointerAttributes::kIsArray2D) ||
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
