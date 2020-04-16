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

#ifndef GFXRECON_DECODE_STRUCT_POINTER_DECODER_H
#define GFXRECON_DECODE_STRUCT_POINTER_DECODER_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/pointer_decoder_base.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
class StructPointerDecoder : public PointerDecoderBase
{
  public:
    StructPointerDecoder() :
        decoded_structs_(nullptr), struct_memory_(nullptr), capacity_(0), is_memory_external_(false)
    {}

    virtual ~StructPointerDecoder() override
    {
        if ((struct_memory_ != nullptr) && !is_memory_external_)
        {
            delete[] struct_memory_;
        }

        if (decoded_structs_ != nullptr)
        {
            delete[] decoded_structs_;
        }
    }

    T* GetMetaStructPointer() { return decoded_structs_; }

    const T* GetMetaStructPointer() const { return decoded_structs_; }

    typename T::struct_type* GetPointer() { return struct_memory_; }

    const typename T::struct_type* GetPointer() const { return struct_memory_; }

    size_t GetOutputLength() const { return output_len_; }

    typename T::struct_type* GetOutputPointer() { return output_data_.get(); }

    const typename T::struct_type* GetOutputPointer() const { return output_data_.get(); }

    typename T::struct_type* AllocateOutputData(size_t len)
    {
        output_len_  = len;
        output_data_ = std::make_unique<typename T::struct_type[]>(len);
        return output_data_.get();
    }

    typename T::struct_type* AllocateOutputData(size_t len, const typename T::struct_type& init)
    {
        output_len_  = len;
        output_data_ = std::make_unique<typename T::struct_type[]>(len);

        for (size_t i = 0; i < len; ++i)
        {
            output_data_[i] = init;
        }

        return output_data_.get();
    }

    void SetExternalMemory(typename T::struct_type* data, size_t capacity)
    {
        if ((data != nullptr) && (capacity > 0))
        {
            struct_memory_      = data;
            capacity_           = capacity;
            is_memory_external_ = true;
        }
        else
        {
            GFXRECON_LOG_WARNING("Struct pointer decoder's external memory was initialized with a NULL pointer");
        }
    }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding structs.
        assert((GetAttributeMask() & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct);

        if (!IsNull())
        {
            size_t len = GetLength();

            if (!is_memory_external_)
            {
                assert(struct_memory_ == nullptr);

                struct_memory_ = new typename T::struct_type[len];
                capacity_      = len;
            }
            else
            {
                assert(struct_memory_ != nullptr);
                assert(len <= capacity_);

                if ((struct_memory_ == nullptr) || (len > capacity_))
                {
                    GFXRECON_LOG_WARNING("Struct pointer decoder's external memory capacity (%" PRIuPTR
                                         ") is smaller than the decoded array size (%" PRIuPTR
                                         "); an internal memory allocation will be used instead",
                                         capacity_,
                                         len);

                    is_memory_external_ = false;
                    struct_memory_      = new typename T::struct_type[len];
                    capacity_           = len;
                }
            }

            decoded_structs_ = new T[len];

            if (HasData())
            {
                for (size_t i = 0; i < len; ++i)
                {
                    decoded_structs_[i].decoded_value = &struct_memory_[i];

                    // Note: We only expect this class to be used with structs that have a decode_struct function.
                    //       If an error is encoutered here due to a new struct type, the struct decoders need to be
                    //       updated to support the new type.
                    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &decoded_structs_[i]);
                }
            }
        }

        return bytes_read;
    }

  private:
    /// Memory to hold decoded data. Points to an internal allocation when #is_memory_external_ is false and
    /// to an externally provided allocation when #is_memory_external_ is true.
    T*                       decoded_structs_;
    typename T::struct_type* struct_memory_; ///< Decoded Vulkan structures.
    size_t capacity_; ///< Size of external memory allocation referenced by #data_ when #is_memory_external_ is true.
    bool   is_memory_external_; ///< Indicates that the memory referenced by #data_ is an external allocation.

    /// Optional memory allocated for output pramaters when retrieving data from a function call. Allows both the data
    /// read from the file and the data retrieved from an API call to exist simultaneously, allowing the values to be
    /// compared.
    std::unique_ptr<typename T::struct_type[]> output_data_;
    size_t                                     output_len_; ///< Size of #output_data_.
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRUCT_POINTER_DECODER_H
