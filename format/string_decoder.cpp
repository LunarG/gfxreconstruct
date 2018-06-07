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
#include "format/string_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t StringDecoder::Decode(const uint8_t* buffer, size_t buffer_size)
{
    size_t bytes_read = DecodeAttributes(buffer, buffer_size);

    // We should only be decoding individual strings.
    assert((GetAttributeMask() & PointerAttributes::kIsString) == PointerAttributes::kIsString);
    assert((GetAttributeMask() & PointerAttributes::kIsArray) != PointerAttributes::kIsArray);

    if (!IsNull() && HasData())
    {
        size_t string_len = GetLength();
        size_t alloc_len = string_len + 1;

        if (!is_memory_external_)
        {
            assert(data_ == nullptr);

            data_ = new char[alloc_len];
            capacity_ = alloc_len;
            bytes_read += ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
        }
        else
        {
            assert(data_ != nullptr);

            // TODO: Report error if alloc_len > capacity_
            if (alloc_len > capacity_)
            {
                ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), data_, (capacity_ - 1));
                data_[capacity_] = '\0';
            }
            else
            {
                ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
                data_[string_len] = '\0';
            }

            // We always need to advance the position within the buffer by the amount of data that was expected to be decoded, not
            // the actual amount of data decoded if capacity is too small to hold all of the data.
            bytes_read += string_len;
        }
    }

    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
