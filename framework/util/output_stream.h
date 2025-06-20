/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_OUTPUT_STREAM_H
#define GFXRECON_UTIL_OUTPUT_STREAM_H

#include "util/defines.h"

#include <string_view>
#include <cstddef>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class OutputStream
{
  public:
    virtual ~OutputStream() {}

    virtual bool IsValid() { return false; }

    virtual bool Write(const void* data, size_t len) = 0;

    virtual void Flush() {}

    template <size_t N>
    void CombineAndWrite(const std::pair<const void*, size_t> (&buffers)[N], std::vector<uint8_t>& scratch_buffer)
    {
        static_assert(N != 1, "Use WriteToFile(void*, size) when writing a single buffer.");

        // Combine buffers for a single write.
        scratch_buffer.clear();
        for (size_t i = 0; i < N; ++i)
        {
            const uint8_t* const data = reinterpret_cast<const uint8_t*>(buffers[i].first);
            const size_t         size = buffers[i].second;
            scratch_buffer.insert(scratch_buffer.end(), data, data + size);
        }

        Write(scratch_buffer.data(), scratch_buffer.size());
    }
};

inline void Write(OutputStream& os, std::string_view sv)
{
    os.Write(sv.data(), sv.size());
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_OUTPUT_STREAM_H
