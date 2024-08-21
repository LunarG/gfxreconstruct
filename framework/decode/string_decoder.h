/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_STRING_DECODER_H
#define GFXRECON_DECODE_STRING_DECODER_H

#include "decode/pointer_decoder_base.h"
#include "decode/decode_allocator.h"
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

    CharT* GetPointer() { return data_; }

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

                data_     = DecodeAllocator::Allocate<CharT>(alloc_len, false);
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
