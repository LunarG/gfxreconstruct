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

#ifndef BRIMSTONE_FORMAT_STRING_DECODER_H
#define BRIMSTONE_FORMAT_STRING_DECODER_H

#include <cassert>
#include <cwchar>

#include "util/defines.h"
#include "format/format.h"
#include "format/pointer_decoder_base.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

template <typename CharT, PointerAttributes DecodeAttrib>
class BasicStringDecoder : public PointerDecoderBase
{
public:
    BasicStringDecoder() : data_(nullptr), capacity_(0), is_memory_external_(false) {}

    ~BasicStringDecoder() { if ((data_ != nullptr) && !is_memory_external_) delete [] data_; }

    CharT* GetPointer() const { return data_; }

    void SetExternalMemory(CharT* data, size_t capacity)
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

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding individual strings.
        assert((GetAttributeMask() & DecodeAttrib) == DecodeAttrib);
        assert((GetAttributeMask() & PointerAttributes::kIsArray) != PointerAttributes::kIsArray);

        if (!IsNull() && HasData())
        {
            size_t string_len = GetLength();
            size_t alloc_len  = string_len + 1;

            if (!is_memory_external_)
            {
                assert(data_ == nullptr);

                data_     = new CharT[alloc_len];
                capacity_ = alloc_len;
                bytes_read +=
                    ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
            }
            else
            {
                assert(data_ != nullptr);

                // TODO: Report error if alloc_len > capacity_
                if (alloc_len > capacity_)
                {
                    ValueDecoder::DecodeVoidArray(
                        (buffer + bytes_read), (buffer_size - bytes_read), data_, (capacity_ - 1));
                    data_[capacity_] = '\0';
                }
                else
                {
                    ValueDecoder::DecodeVoidArray((buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
                    data_[string_len] = '\0';
                }

                // We always need to advance the position within the buffer by the amount of data that was expected to
                // be decoded, not the actual amount of data decoded if capacity is too small to hold all of the data.
                bytes_read += string_len;
            }
        }

        return bytes_read;
    }

  private:
    CharT*  data_;
    size_t  capacity_;
    bool    is_memory_external_;
};

typedef BasicStringDecoder<char, PointerAttributes::kIsString>     StringDecoder;
typedef BasicStringDecoder<wchar_t, PointerAttributes::kIsWString> WStringDecoder;

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_STRING_DECODER_H
