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

#ifndef GFXRECON_DECODE_STRING_DECODER_H
#define GFXRECON_DECODE_STRING_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <cwchar>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename CharT, typename EncodeT, format::PointerAttributes DecodeAttrib>
class BasicStringDecoder : public PointerDecoderBase
{
  public:
    BasicStringDecoder() : data_(nullptr), capacity_(0), is_memory_external_(false) {}

    ~BasicStringDecoder()
    {
        if ((data_ != nullptr) && !is_memory_external_)
        {
            delete[] data_;
        }
    }

    const CharT* GetPointer() const { return data_; }

    void SetExternalMemory(CharT* data, size_t capacity)
    {
        if ((data != nullptr) && (capacity > 0))
        {
            data_               = data;
            capacity_           = capacity;
            is_memory_external_ = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("String decoder's external memory was initialized with a NULL pointer");
        }
    }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding individual strings.
        assert((GetAttributeMask() & DecodeAttrib) == DecodeAttrib);
        assert((GetAttributeMask() & format::PointerAttributes::kIsArray) != format::PointerAttributes::kIsArray);

        if (!IsNull() && HasData())
        {
            size_t string_len = GetLength();
            size_t alloc_len  = string_len + 1;

            if (!is_memory_external_)
            {
                assert(data_ == nullptr);

                data_     = new CharT[alloc_len];
                capacity_ = alloc_len;
                bytes_read += ValueDecoder::DecodeArrayFrom<EncodeT>(
                    (buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
                data_[string_len] = '\0';
            }
            else
            {
                assert(data_ != nullptr);

                if (alloc_len <= capacity_)
                {
                    ValueDecoder::DecodeArrayFrom<EncodeT>(
                        (buffer + bytes_read), (buffer_size - bytes_read), data_, string_len);
                    data_[string_len] = '\0';
                }
                else
                {
                    size_t truncate_len = capacity_ - 1;
                    ValueDecoder::DecodeArrayFrom<EncodeT>(
                        (buffer + bytes_read), (buffer_size - bytes_read), data_, truncate_len);
                    data_[truncate_len] = '\0';

                    GFXRECON_LOG_WARNING("String decoder's external memory capacity (%" PRIuPTR
                                         ") is smaller than the decoded string size (%" PRIuPTR
                                         "); data will be truncated",
                                         capacity_,
                                         alloc_len);
                }

                // We always need to advance the position within the buffer by the amount of data that was expected to
                // be decoded, not the actual amount of data decoded if capacity is too small to hold all of the data.
                bytes_read += string_len * sizeof(EncodeT);
            }
        }

        return bytes_read;
    }

  private:
    CharT* data_;
    size_t capacity_;
    bool   is_memory_external_;
};

typedef BasicStringDecoder<char, format::CharEncodeType, format::PointerAttributes::kIsString>      StringDecoder;
typedef BasicStringDecoder<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString> WStringDecoder;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRING_DECODER_H
