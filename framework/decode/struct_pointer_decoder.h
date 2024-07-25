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

#ifndef GFXRECON_DECODE_STRUCT_POINTER_DECODER_H
#define GFXRECON_DECODE_STRUCT_POINTER_DECODER_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/pointer_decoder_base.h"
#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#if defined(WIN32)
#include "decode/custom_dx12_struct_decoders_forward.h"
#include "generated/generated_dx12_struct_decoders_forward.h"
#endif

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

    T* GetMetaStructPointer() { return decoded_structs_; }

    const T* GetMetaStructPointer() const { return decoded_structs_; }

    typename T::struct_type* GetPointer() { return struct_memory_; }

    const typename T::struct_type* GetPointer() const { return struct_memory_; }

    size_t GetOutputLength() const { return output_len_; }

    typename T::struct_type* GetOutputPointer() { return output_data_; }

    const typename T::struct_type* GetOutputPointer() const { return output_data_; }

    typename T::struct_type* AllocateOutputData(size_t len)
    {
        output_len_  = len;
        output_data_ = DecodeAllocator::Allocate<typename T::struct_type>(len);
        return output_data_;
    }

    typename T::struct_type* AllocateOutputData(size_t len, const typename T::struct_type& init)
    {
        output_len_  = len;
        output_data_ = DecodeAllocator::Allocate<typename T::struct_type>(len);

        for (size_t i = 0; i < len; ++i)
        {
            output_data_[i] = init;
        }

        return output_data_;
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

                struct_memory_ = DecodeAllocator::Allocate<typename T::struct_type>(len);
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
                    struct_memory_      = DecodeAllocator::Allocate<typename T::struct_type>(len);
                    capacity_           = len;
                }
            }

            decoded_structs_ = DecodeAllocator::Allocate<T>(len);

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

    size_t DecodeBaseHeader(const uint8_t* buffer, size_t buffer_size)
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

                struct_memory_ = reinterpret_cast<typename T::struct_type*>(
                    DecodeAllocator::Allocate<typename T::union_size_type>(len));
                capacity_ = len;
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
                    struct_memory_      = reinterpret_cast<typename T::struct_type*>(
                        DecodeAllocator::Allocate<typename T::union_size_type>(len));
                    capacity_ = len;
                }
            }

            decoded_structs_ = T::AllocateAppropriate((buffer + bytes_read), (buffer_size - bytes_read), len);

            if (HasData())
            {
                for (size_t i = 0; i < len; ++i)
                {
                    decoded_structs_[i].decoded_value = &struct_memory_[i];

                    // Note: We only expect this class to be used with structs that have a decode_struct function.
                    //       If an error is encoutered here due to a new struct type, the struct decoders need to be
                    //       updated to support the new type.
                    bytes_read +=
                        T::DecodeAppropriate((buffer + bytes_read), (buffer_size - bytes_read), &decoded_structs_[i]);
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
    typename T::struct_type* output_data_{ nullptr };
    size_t                   output_len_; ///< Size of #output_data_.
};

template <typename T>
class StructPointerDecoder<T*> : public PointerDecoderBase
{
  public:
    StructPointerDecoder() : decoded_structs_(nullptr), struct_memory_(nullptr) {}

    T** GetMetaStructPointer() { return decoded_structs_; }

    const T* const* GetMetaStructPointer() const { return decoded_structs_; }

    typename T::struct_type** GetPointer() { return struct_memory_; }

    const typename T::struct_type** GetPointer() const { return struct_memory_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding 2D struct arrays.
        assert((GetAttributeMask() & (format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray2D)) ==
               (format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray2D));

        if (!IsNull() && HasData())
        {
            assert(struct_memory_ == nullptr);

            size_t len       = GetLength();
            struct_memory_   = DecodeAllocator::Allocate<typename T::struct_type*>(len, false);
            decoded_structs_ = DecodeAllocator::Allocate<T*>(len, false);

            for (size_t i = 0; i < len; ++i)
            {
                uint32_t attrib = 0;
                bytes_read +=
                    ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

                if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
                {
                    if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
                    {
                        uint64_t address;
                        bytes_read +=
                            ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address);
                    }

                    assert((attrib & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct);

                    size_t inner_len = 0;
                    bytes_read +=
                        ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &inner_len);

                    typename T::struct_type* inner_struct_memory =
                        DecodeAllocator::Allocate<typename T::struct_type>(inner_len);
                    T* inner_decoded_structs = DecodeAllocator::Allocate<T>(inner_len);

                    for (size_t j = 0; j < inner_len; ++j)
                    {
                        inner_decoded_structs[j].decoded_value = &inner_struct_memory[j];
                        // Note: We only expect this class to be used with structs that have a decode_struct function.
                        //       If an error is encoutered here due to a new struct type, the struct decoders need to be
                        //       updated to support the new type.
                        bytes_read +=
                            DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &inner_decoded_structs[j]);
                    }

                    struct_memory_[i]   = inner_struct_memory;
                    decoded_structs_[i] = inner_decoded_structs;
                }
                else
                {
                    struct_memory_[i]   = nullptr;
                    decoded_structs_[i] = nullptr;
                }
            }
        }

        return bytes_read;
    }

    size_t DecodeBaseHeader(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding 2D struct arrays.
        assert((GetAttributeMask() & (format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray2D)) ==
               (format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray2D));

        if (!IsNull() && HasData())
        {
            assert(struct_memory_ == nullptr);

            size_t len       = GetLength();
            struct_memory_   = DecodeAllocator::Allocate<typename T::struct_type*>(len, false);
            decoded_structs_ = DecodeAllocator::Allocate<T*>(len, false);

            for (size_t i = 0; i < len; ++i)
            {
                uint32_t attrib = 0;
                bytes_read +=
                    ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

                if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
                {
                    if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
                    {
                        uint64_t address;
                        bytes_read +=
                            ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &address);
                    }

                    assert((attrib & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct);

                    size_t inner_len = 0;
                    bytes_read +=
                        ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &inner_len);

                    typename T::struct_type* inner_struct_memory = reinterpret_cast<typename T::struct_type*>(
                        DecodeAllocator::Allocate<typename T::union_size_type>(inner_len));
                    T* inner_decoded_structs =
                        T::AllocateAppropriate((buffer + bytes_read), (buffer_size - bytes_read), len);

                    for (size_t j = 0; j < inner_len; ++j)
                    {
                        inner_decoded_structs[j].decoded_value = &inner_struct_memory[j];
                        // Note: We only expect this class to be used with structs that have a decode_struct function.
                        //       If an error is encoutered here due to a new struct type, the struct decoders need to be
                        //       updated to support the new type.
                        bytes_read += T::DecodeAppropriate(
                            (buffer + bytes_read), (buffer_size - bytes_read), &inner_decoded_structs[i]);
                    }

                    struct_memory_[i]   = inner_struct_memory;
                    decoded_structs_[i] = inner_decoded_structs;
                }
                else
                {
                    struct_memory_[i]   = nullptr;
                    decoded_structs_[i] = nullptr;
                }
            }
        }

        return bytes_read;
    }

  private:
    T**                       decoded_structs_; ///< Memory to hold decoded data.
    typename T::struct_type** struct_memory_;   ///< Decoded Vulkan structures.
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRUCT_POINTER_DECODER_H
