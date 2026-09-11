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
#include "util/logging.h"

#include <cinttypes>
#include <optional>

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

    // Overrides the decoded array length reported by GetLength().  This does not resize or
    // otherwise touch the underlying data/output buffers; it is intended for callers (such as
    // the replay frame loop consumer) that need to temporarily restrict a decoded array to a
    // sub-range (e.g. a single element) for one call, and are responsible for restoring the
    // original value afterward if the array's backing storage is reused.
    void SetLength(size_t len) { len_ = len; }

    // For a fixed-extent array whose registry 'len' names a sibling count member (e.g.
    // VkPhysicalDeviceMemoryProperties::memoryTypes with memoryTypeCount), records the count decoded from the
    // enclosing struct so the decoded array length can be checked against it.  Captures written before the count
    // was honored hold the full capacity, which is also accepted; see CheckExpectedLength().
    void SetExpectedLength(size_t len) { expected_len_ = len; }

    static bool PeekAttributesAndType(const uint8_t* buffer,
                                      size_t         buffer_size,
                                      bool&          is_null,
                                      bool&          is_struct,
                                      bool&          has_length,
                                      size_t&        length,
                                      uint32_t&      structure_type)
    {
        bool     success    = true;
        size_t   bytes_read = 0;
        uint32_t attrib     = 0;
        uint64_t address;

        is_null    = true;
        is_struct  = false;
        has_length = false;

        bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

        if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
        {
            is_null = false;
            if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                // Not interested right now, but need to read it if it's present
                bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address);
            }

            has_length = true;
            if (((attrib & format::PointerAttributes::kIsArray) == format::PointerAttributes::kIsArray) ||
                ((attrib & format::PointerAttributes::kIsArray2D) == format::PointerAttributes::kIsArray2D) ||
                ((attrib & format::PointerAttributes::kIsString) == format::PointerAttributes::kIsString) ||
                ((attrib & format::PointerAttributes::kIsWString) == format::PointerAttributes::kIsWString))
            {
                bytes_read +=
                    ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &length);
            }
            else
            {
                length = 1;
            }

            if ((attrib & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct)
            {
                is_struct = true;
                bytes_read +=
                    ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &structure_type);
            }
        }

        return success;
    }

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

  public:
    // Reports a decoded array length for a fixed-extent array that matches neither the count member recorded with
    // SetExpectedLength() nor the array capacity.  Neither value is trusted over the other: the count comes from the
    // capture stream as well, and older captures legitimately hold the full capacity regardless of the count.
    // A length above the capacity is left to the owning decoder's truncation warning.
    // Public so that decoders composed of a PointerDecoder (HandlePointerDecoder) can apply it to their member.
    void CheckExpectedLength(const char* decoder_name, size_t capacity) const
    {
        if (expected_len_ && (len_ != *expected_len_) && (len_ < capacity))
        {
            GFXRECON_LOG_WARNING(
                "%s decoder received an array of %" PRIuPTR
                " elements for a fixed-extent array, which matches neither the associated count (%" PRIuPTR
                ") nor the array capacity (%" PRIuPTR ")",
                decoder_name,
                len_,
                *expected_len_,
                capacity);
        }
    }

  private:
    size_t   len_;
    uint64_t address_;
    uint32_t attrib_;

    // Count member associated with a fixed-extent array; see SetExpectedLength().
    std::optional<size_t> expected_len_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_POINTER_DECODER_BASE_H
