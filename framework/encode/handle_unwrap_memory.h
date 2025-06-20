/*
** Copyright (c) 2019,2022 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_HANDLE_UNWRAP_MEMORY_H
#define GFXRECON_ENCODE_HANDLE_UNWRAP_MEMORY_H

#include "util/defines.h"

#include <iterator>
#include <cstddef>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

typedef std::vector<uint8_t> HandleUnwrapBuffer;

class HandleUnwrapMemory
{
  public:
    HandleUnwrapMemory() : current_buffer_(0) {}

    uint8_t* GetBuffer(size_t len)
    {
        HandleUnwrapBuffer* next_buffer = nullptr;
        size_t              next_index  = current_buffer_++;

        if (next_index < buffers_.size())
        {
            next_buffer = &buffers_[next_index];

            if (len > next_buffer->size())
            {
                next_buffer->resize(len);
            }
        }
        else
        {
            buffers_.emplace_back(len);
            next_buffer = &buffers_[next_index];
        }

        return next_buffer->data();
    }

    uint8_t* GetFilledBuffer(const uint8_t* data, size_t len)
    {
        HandleUnwrapBuffer* next_buffer = nullptr;
        size_t              next_index  = current_buffer_++;

        if (next_index < buffers_.size())
        {
            next_buffer = &buffers_[next_index];
            next_buffer->clear();
            std::copy(data, data + len, std::back_inserter(*next_buffer));
        }
        else
        {
            buffers_.emplace_back(data, data + len);
            next_buffer = &buffers_[next_index];
        }

        return next_buffer->data();
    }

    void Reset() { current_buffer_ = 0; }

  private:
    size_t                          current_buffer_;
    std::vector<HandleUnwrapBuffer> buffers_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_HANDLE_UNWRAP_MEMORY_H
