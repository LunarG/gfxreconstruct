/*
** Copyright (c) 2019 Valve Corporation
** Copyright (c) 2019 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_HANDLE_POINTER_DECODER_H
#define GFXRECON_DECODE_HANDLE_POINTER_DECODER_H

#include "decode/pointer_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class HandlePointerDecoder
{
  public:
    HandlePointerDecoder() : handle_data_(nullptr), capacity_(0), is_memory_external_(false) {}

    ~HandlePointerDecoder()
    {
        if ((handle_data_ != nullptr) && !is_memory_external_)
        {
            delete[] handle_data_;
        }
    }

    bool IsNull() const { return decoder_.IsNull(); }

    bool HasAddress() const { return decoder_.HasAddress(); }

    bool HasData() const { return decoder_.HasData(); }

    uint32_t GetAttributeMask() const { return decoder_.GetAttributeMask(); }

    uint64_t GetAddress() const { return decoder_.GetAddress(); }

    size_t GetLength() const { return decoder_.GetLength(); }

    format::HandleId* GetPointer() const { return decoder_.GetPointer(); }

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

    T* GetHandlePointer() const { return handle_data_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t result = decoder_.DecodeHandleId(buffer, buffer_size);

        if (!IsNull() && HasData() && !is_memory_external_)
        {
            assert(handle_data_ == nullptr);

            size_t len   = GetLength();
            handle_data_ = new T[len];
        }

        return result;
    }

  private:
    PointerDecoder<format::HandleId> decoder_;
    T*                               handle_data_;
    size_t                           capacity_;
    bool                             is_memory_external_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_HANDLE_POINTER_DECODER_H
