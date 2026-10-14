/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_FORMAT_API_CALL_LOG_H
#define GFXRECON_FORMAT_API_CALL_LOG_H

#include "format/api_call_id.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstdint>
#include <cstring>
#include <type_traits>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(format)

/// Default entry metadata: entries carry nothing beyond the call id and parameter buffer.
struct ApiCallLogNoMeta
{};

/// An append-only, in-memory log of encoded API calls.
/// Each entry holds:
/// - a call id
/// - a trivially-copyable metadata value (optional)
/// - a copy of the call's encoded parameter buffer
///
/// Entries are packed into a single contiguous byte buffer and can only be visited in append
/// order or cleared wholesale. The layout is process-local and never reaches a capture file.
template <typename EntryMetaT = ApiCallLogNoMeta>
class ApiCallLog
{
    static_assert(std::is_trivially_copyable_v<EntryMetaT>, "ApiCallLog entry metadata must be trivially copyable");

  public:
    void Append(ApiCallId call_id, const EntryMetaT& meta, const uint8_t* parameter_data, size_t parameter_size)
    {
        WriteBytes(&parameter_size, sizeof(parameter_size));
        WriteBytes(&call_id, sizeof(call_id));
        if constexpr (!std::is_empty_v<EntryMetaT>)
        {
            WriteBytes(&meta, sizeof(meta));
        }
        WriteBytes(parameter_data, parameter_size);
    }

    template <typename T = EntryMetaT, typename = std::enable_if_t<std::is_empty_v<T>>>
    void Append(ApiCallId call_id, const uint8_t* parameter_data, size_t parameter_size)
    {
        Append(call_id, EntryMetaT{}, parameter_data, parameter_size);
    }

    /// Invoke visitor on each entry in append order. The visitor signature is
    /// (ApiCallId, const uint8_t* parameter_data, size_t parameter_size) when EntryMetaT is empty,
    /// (ApiCallId, const EntryMetaT&, const uint8_t* parameter_data, size_t parameter_size) otherwise.
    template <typename Visitor>
    void ForEach(Visitor&& visitor) const
    {
        size_t offset = 0;
        while (offset < data_.size())
        {
            size_t    parameter_size = 0;
            ApiCallId call_id{};
            ReadBytes(&parameter_size, sizeof(parameter_size), offset);
            ReadBytes(&call_id, sizeof(call_id), offset);

            if constexpr (std::is_empty_v<EntryMetaT>)
            {
                GFXRECON_ASSERT((offset + parameter_size) <= data_.size());
                visitor(call_id, data_.data() + offset, parameter_size);
            }
            else
            {
                EntryMetaT meta{};
                ReadBytes(&meta, sizeof(meta), offset);
                GFXRECON_ASSERT((offset + parameter_size) <= data_.size());
                visitor(call_id, meta, data_.data() + offset, parameter_size);
            }

            offset += parameter_size;
        }
        GFXRECON_ASSERT(offset == data_.size());
    }

    void Clear() { data_.clear(); }

    bool IsEmpty() const { return data_.empty(); }

  private:
    void WriteBytes(const void* data, size_t size)
    {
        const auto* bytes = static_cast<const uint8_t*>(data);
        data_.insert(data_.end(), bytes, bytes + size);
    }

    // memcpy keeps header-field reads aligned regardless of their offset in the byte buffer
    void ReadBytes(void* dst, size_t size, size_t& offset) const
    {
        GFXRECON_ASSERT((offset + size) <= data_.size());
        std::memcpy(dst, data_.data() + offset, size);
        offset += size;
    }

    std::vector<uint8_t> data_;
};

GFXRECON_END_NAMESPACE(format)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_FORMAT_API_CALL_LOG_H
