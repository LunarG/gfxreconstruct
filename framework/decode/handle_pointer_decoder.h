/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_HANDLE_POINTER_DECODER_H
#define GFXRECON_DECODE_HANDLE_POINTER_DECODER_H

#include "decode/decode_allocator.h"
#include "decode/pointer_decoder.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class HandlePointerDecoder
{
  public:
    using HandleType = T;

    HandlePointerDecoder() : handle_data_(nullptr), handle_data_len_(0), capacity_(0), is_memory_external_(false) {}

    ~HandlePointerDecoder() {}

    bool IsNull() const { return decoder_.IsNull(); }

    bool HasAddress() const { return decoder_.HasAddress(); }

    bool HasData() const { return decoder_.HasData(); }

    bool IsArray() const { return decoder_.IsArray(); }

    uint32_t GetAttributeMask() const { return decoder_.GetAttributeMask(); }

    uint64_t GetAddress() const { return decoder_.GetAddress(); }

    size_t GetLength() const { return decoder_.GetLength(); }

    const format::HandleId* GetPointer() const { return decoder_.GetPointer(); }

    void SetExternalMemory(T* data, size_t capacity)
    {
        assert(handle_data_ == nullptr);

        if ((data != nullptr) && (capacity > 0))
        {
            handle_data_        = data;
            capacity_           = capacity;
            is_memory_external_ = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("Handle pointer decoder's external memory was initialized with a NULL pointer");
        }
    }

    void SetHandleLength(size_t len)
    {
        handle_data_len_ = len;

        if (!is_memory_external_)
        {
            handle_data_ = decoder_.AllocateOutputData(len);
        }
    }

    size_t GetHandleLength() const { return handle_data_len_; }

    T* GetHandlePointer() { return handle_data_; }

    const T* GetHandlePointer() const { return handle_data_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size) { return decoder_.DecodeHandleId(buffer, buffer_size); }

    // The value returned is only guaranteed to be valid if the current consumer has called SetConsumerData.
    void* GetConsumerData(size_t index) const
    {
        void* consumer_data = nullptr;

        if ((consumer_data_ != nullptr) && (index < handle_data_len_))
        {
            consumer_data = consumer_data_[index];
        }

        return consumer_data;
    }

    void SetConsumerData(size_t index, void* consumer_data)
    {
        if (index < handle_data_len_)
        {
            if (consumer_data_ == nullptr)
            {
                consumer_data_ = DecodeAllocator::Allocate<void*>(handle_data_len_);
            }

            consumer_data_[index] = consumer_data;
        }
    }

  private:
    PointerDecoder<format::HandleId, T> decoder_;
    T*                                  handle_data_;
    size_t                              handle_data_len_;
    size_t                              capacity_;
    bool                                is_memory_external_;
    void**                              consumer_data_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_HANDLE_POINTER_DECODER_H
