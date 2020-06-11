/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_STRING_ARRAY_DECODER_H
#define GFXRECON_DECODE_STRING_ARRAY_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <cwchar>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename CharT, format::PointerAttributes DecodeAttrib>
class BasicStringArrayDecoder : public PointerDecoderBase
{
  public:
    BasicStringArrayDecoder() {}

    ~BasicStringArrayDecoder() { DestroyStrings(); }

    const uint32_t* GetStringAttributes() const { return string_attributes_.get(); }

    const uint64_t* GetStringAddresses() const { return string_addresses_.get(); }

    const size_t* GetStringLengths() const { return string_lengths_.get(); }

    const CharT* const* GetPointer() const { return strings_.get(); }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding string arrays.
        assert((GetAttributeMask() & (DecodeAttrib | format::PointerAttributes::kIsArray)) ==
               (DecodeAttrib | format::PointerAttributes::kIsArray));

        if (!IsNull() && HasData())
        {
            size_t len         = GetLength();
            strings_           = std::make_unique<char*[]>(len);
            string_attributes_ = std::make_unique<uint32_t[]>(len);
            string_addresses_  = std::make_unique<uint64_t[]>(len);
            string_lengths_    = std::make_unique<size_t[]>(len);

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

                    CharT* value = new CharT[slen + 1];

                    if (((attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData))
                    {
                        bytes_read += ValueDecoder::DecodeVoidArray(
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
    void DestroyStrings()
    {
        if (strings_ != nullptr)
        {
            // Must explicitly destroy the individual strings in the array.
            for (size_t i = 0; i < GetLength(); ++i)
            {
                delete[] strings_[i];
                strings_[i] = nullptr;
            }
        }
    }

  private:
    std::unique_ptr<CharT*[]>   strings_;
    std::unique_ptr<uint32_t[]> string_attributes_;
    std::unique_ptr<uint64_t[]> string_addresses_;
    std::unique_ptr<size_t[]>   string_lengths_;
};

typedef BasicStringArrayDecoder<char, format::PointerAttributes::kIsString>     StringArrayDecoder;
typedef BasicStringArrayDecoder<wchar_t, format::PointerAttributes::kIsWString> WStringArrayDecoder;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRING_ARRAY_DECODER_H
