/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H
#define GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H

#include "util/defines.h"
#include "util/output_stream.h"

#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class MemoryOutputStream : public OutputStream
{
  public:
    const size_t kDefaultBufferSize = 512;

  public:
    MemoryOutputStream();

    MemoryOutputStream(size_t initial_size);

    MemoryOutputStream(const void* initial_data, size_t initial_data_size);

    virtual ~MemoryOutputStream() override;

    virtual bool IsValid() override { return true; }

    virtual void Clear() { buffer_.clear(); };

    virtual size_t Write(const void* data, size_t len) override;

    virtual const uint8_t* GetData() const { return buffer_.data(); }

    virtual size_t GetDataSize() const { return buffer_.size(); }

  protected:
    std::vector<uint8_t>* GetBuffer() { return &buffer_; }

  private:
    std::vector<uint8_t> buffer_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_MEMORY_OUTPUT_STREAM_H
