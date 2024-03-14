/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_PARAMETER_BUFFER_H
#define GFXRECON_ENCODE_PARAMETER_BUFFER_H

#include "util/defines.h"
#include "util/memory_output_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ParameterBuffer : public util::MemoryOutputStream
{
  public:
    ParameterBuffer() : header_size_(0) {}

    virtual ~ParameterBuffer() {}

    // Reset buffer, reserving space for a header at the start of the buffer.
    void ClearWithHeader(size_t header_size)
    {
        MemoryOutputStream::Clear();
        header_size_ = header_size;
        GetBuffer()->resize(header_size_);
    }

    virtual void Clear() override
    {
        MemoryOutputStream::Clear();
        header_size_ = 0;
    }

    // Returns a pointer to the header data or nullptr if no header data was reserved.
    uint8_t* GetHeaderData() { return (header_size_ > 0) ? GetBuffer()->data() : nullptr; };

    // Returns the number of bytes reserved for the header at the start of the buffer.
    size_t GetHeaderDataSize() const { return header_size_; }

    virtual const uint8_t* GetData() const override { return MemoryOutputStream::GetData() + header_size_; }

    virtual size_t GetDataSize() const override { return MemoryOutputStream::GetDataSize() - header_size_; }

  private:
    size_t header_size_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_PARAMETER_BUFFER_H
