/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_STRING_ARRAY_DECODER_H
#define GFXRECON_DECODE_STRING_ARRAY_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <cwchar>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename CharT, typename EncodeT, format::PointerAttributes DecodeAttrib>
class BasicStringArrayDecoder : public PointerDecoderBase
{
  public:
    BasicStringArrayDecoder() {}

    const uint32_t* GetStringAttributes() const { return string_attributes_; }

    const uint64_t* GetStringAddresses() const { return string_addresses_; }

    const size_t* GetStringLengths() const { return string_lengths_; }

    const CharT* const* GetPointer() const { return strings_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding string arrays.
        assert((GetAttributeMask() & (DecodeAttrib | format::PointerAttributes::kIsArray)) ==
               (DecodeAttrib | format::PointerAttributes::kIsArray));

        if (!IsNull() && HasData())
        {
            size_t len         = GetLength();
            strings_           = DecodeAllocator::Allocate<CharT*>(len);
            string_attributes_ = DecodeAllocator::Allocate<uint32_t>(len);
            string_addresses_  = DecodeAllocator::Allocate<uint64_t>(len);
            string_lengths_    = DecodeAllocator::Allocate<size_t>(len);

            for (size_t i = 0; i < len; ++i)
            {
                uint32_t attrib = 0;
                bytes_read +=
                    ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

                if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
                {
                    if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
                    {
                        bytes_read += ValueDecoder::DecodeAddress(
                            (buffer + bytes_read), (buffer_size - bytes_read), &string_addresses_[i]);
                    }

                    assert((attrib & DecodeAttrib) == DecodeAttrib);

                    size_t slen = 0;
                    bytes_read +=
                        ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &slen);

                    CharT* value = DecodeAllocator::Allocate<CharT>(slen + 1, false);

                    if (((attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData))
                    {
                        bytes_read += ValueDecoder::DecodeArrayFrom<EncodeT>(
                            (buffer + bytes_read), (buffer_size - bytes_read), value, slen);
                        value[slen] = '\0';
                    }
                    else
                    {
                        value[0] = '\0';
                    }

                    strings_[i]        = value;
                    string_lengths_[i] = slen;
                }
                else
                {
                    strings_[i]          = nullptr;
                    string_addresses_[i] = 0;
                    string_lengths_[i]   = 0;
                }

                string_attributes_[i] = attrib;
            }
        }

        return bytes_read;
    }

  private:
    CharT**   strings_{ nullptr };
    uint32_t* string_attributes_{ nullptr };
    uint64_t* string_addresses_{ nullptr };
    size_t*   string_lengths_{ nullptr };
};

typedef BasicStringArrayDecoder<char, format::CharEncodeType, format::PointerAttributes::kIsString> StringArrayDecoder;
typedef BasicStringArrayDecoder<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString>
    WStringArrayDecoder;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRING_ARRAY_DECODER_H
