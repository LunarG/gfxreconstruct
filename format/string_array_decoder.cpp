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

#include "format/format.h"
#include "format/value_decoder.h"
#include "format/string_array_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t StringArrayDecoder::Decode(const uint8_t* buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib_);

    assert((attrib_ & (PointerAttributes::kIsString | PointerAttributes::kIsArray)) == (PointerAttributes::kIsString | PointerAttributes::kIsArray));

    if ((attrib_ & PointerAttributes::kIsNull) != PointerAttributes::kIsNull)
    {
        if ((attrib_ & PointerAttributes::kHasAddress) == PointerAttributes::kHasAddress)
        {
            bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address_);
        }

        bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &len_);

        if (((attrib_ & PointerAttributes::kHasData) == PointerAttributes::kHasData))
        {
            strings_ = std::make_unique<char*[]>(len_);
            string_addresses_ = std::make_unique<uint64_t[]>(len_);
            string_lengths_ = std::make_unique<size_t[]>(len_);

            for (size_t i = 0; i < len_; ++i)
            {
                bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib_);

                if ((attrib_ & PointerAttributes::kIsNull) != PointerAttributes::kIsNull)
                {
                    if ((attrib_ & PointerAttributes::kHasAddress) == PointerAttributes::kHasAddress)
                    {
                        bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &string_addresses_[i]);
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

                    strings_[i] = value;
                    string_lengths_[i] = slen;
                }
                else
                {
                    strings_[i] = nullptr;
                    string_addresses_[i] = 0;
                    string_lengths_[i] = 0;
                }
            }
        }
    }

    return bytes_read;
}

void StringArrayDecoder::DestroyStrings()
{
    if (strings_ != nullptr)
    {
        // Must explicitly destroy the individual strings in the array.
        for (size_t i = 0; i < len_; ++i)
        {
            delete [] strings_[i];
            strings_[i] = nullptr;
        }
    }
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
