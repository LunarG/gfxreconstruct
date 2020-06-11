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

#ifndef GFXRECON_ENCODE_PARAMETER_ENCODER_H
#define GFXRECON_ENCODE_PARAMETER_ENCODER_H

#include "encode/vulkan_handle_wrapper_util.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/output_stream.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"

#include <cstring>
#include <cwchar>
#include <memory>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ParameterEncoder
{
  public:
    ParameterEncoder(util::OutputStream* stream) : output_stream_(stream) {}

    ~ParameterEncoder() {}

    void Reset() { output_stream_->Reset(); }

    // clang-format off

    // Values
    void EncodeUInt8Value(uint8_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt16Value(uint16_t value)                                                                            { EncodeValue(value); }
    void EncodeInt32Value(int32_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt32Value(uint32_t value)                                                                            { EncodeValue(value); }
    void EncodeInt64Value(int64_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt64Value(uint64_t value)                                                                            { EncodeValue(value); }
    void EncodeFloatValue(float value)                                                                                { EncodeValue(value); }
    void EncodeVkBool32Value(VkBool32 value)                                                                          { EncodeValue(value); }
    void EncodeVkSampleMaskValue(VkSampleMask value)                                                                  { EncodeValue(static_cast<format::SampleMaskEncodeType>(value)); }
    void EncodeVkDeviceSizeValue(VkDeviceSize value)                                                                  { EncodeValue(static_cast<format::DeviceSizeEncodeType>(value)); }
    void EncodeVkDeviceAddressValue(VkDeviceAddress value)                                                            { EncodeValue(static_cast<format::DeviceSizeEncodeType>(value)); }
    void EncodeSizeTValue(size_t value)                                                                               { EncodeValue(static_cast<format::SizeTEncodeType>(value)); }
    void EncodeHandleIdValue(format::HandleId value)                                                                  { EncodeValue(static_cast<format::HandleEncodeType>(value)); }

    // Encode the address values for pointers to non-Vulkan objects to be used as object IDs.
    void EncodeAddress(const void* value)                                                                             { EncodeValue(reinterpret_cast<format::AddressEncodeType>(value)); }
    void EncodeVoidPtr(const void* value)                                                                             { EncodeAddress(value); }
    template<typename T>
    void EncodeFunctionPtr(T value)                                                                                   { EncodeValue(reinterpret_cast<format::AddressEncodeType>(value)); }

    template<typename T>
    void EncodeHandleValue(T value)                                                                                   { EncodeHandleIdValue(GetWrappedId(value)); }
    template<typename T>
    void EncodeEnumValue(T value)                                                                                     { EncodeValue(static_cast<format::EnumEncodeType>(value)); }
    template<typename T>
    void EncodeFlagsValue(T value)                                                                                    { EncodeValue(static_cast<format::FlagsEncodeType>(value)); }

    // Pointers
    void EncodeInt32Ptr(const int32_t* ptr, bool omit_data = false, bool omit_addr = false)                           { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeUInt32Ptr(const uint32_t* ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeInt64Ptr(const int64_t* ptr, bool omit_data = false, bool omit_addr = false)                           { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeUInt64Ptr(const uint64_t* ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeFloatPtr(const float* ptr, bool omit_data = false, bool omit_addr = false)                             { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeVkBool32Ptr(const VkBool32* ptr, bool omit_data = false, bool omit_addr = false)                       { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeVkSampleMaskPtr(const VkSampleMask* ptr, bool omit_data = false, bool omit_addr = false)               { EncodePointerConverted<format::SampleMaskEncodeType>(ptr, omit_data, omit_addr); }
    void EncodeVkDeviceSizePtr(const VkDeviceSize* ptr, bool omit_data = false, bool omit_addr = false)               { EncodePointerConverted<format::DeviceSizeEncodeType>(ptr, omit_data, omit_addr); }
    void EncodeSizeTPtr(const size_t* ptr, bool omit_data = false, bool omit_addr = false)                            { EncodePointerConverted<format::SizeTEncodeType>(ptr, omit_data, omit_addr); }
    void EncodeHandleIdPtr(const format::HandleId* ptr, bool omit_data = false, bool omit_addr = false)               { EncodePointerConverted<format::HandleEncodeType>(ptr, omit_data, omit_addr); }

    // Treat pointers to non-Vulkan objects as 64-bit object IDs.
    template<typename T>
    void EncodeVoidPtrPtr(const T* const* ptr, bool omit_data = false, bool omit_addr = false)                        { EncodePointerConverted<format::AddressEncodeType>(ptr, omit_data, omit_addr); }

    template<typename T>
    void EncodeHandlePtr(const T* ptr, bool omit_data = false, bool omit_addr = false)                                { EncodeWrappedHandlePointer(ptr, omit_data, omit_addr); }
    template<typename T>
    void EncodeEnumPtr(const T* ptr, bool omit_data = false, bool omit_addr = false)                                  { EncodePointerConverted<format::EnumEncodeType>(ptr, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlagsPtr(const T* ptr, bool omit_data = false, bool omit_addr = false)                                 { EncodePointerConverted<format::FlagsEncodeType>(ptr, omit_data, omit_addr); }

    // Arrays
    void EncodeInt32Array(const int32_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)             { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeUInt32Array(const uint32_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)           { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeInt64Array(const int64_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)             { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeUInt64Array(const uint64_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)           { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeFloatArray(const float* arr, size_t len, bool omit_data = false, bool omit_addr = false)               { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeVkBool32Array(const VkBool32* arr, size_t len, bool omit_data = false, bool omit_addr = false)         { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeVkSampleMaskArray(const VkSampleMask* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeArrayConverted<format::SampleMaskEncodeType>(arr, len, omit_data, omit_addr); }
    void EncodeVkDeviceSizeArray(const VkDeviceSize* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeArrayConverted<format::DeviceSizeEncodeType>(arr, len, omit_data, omit_addr); }
    void EncodeSizeTArray(const size_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)              { EncodeArrayConverted<format::SizeTEncodeType>(arr, len, omit_data, omit_addr); }
    void EncodeHandleIdArray(const format::HandleId* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeArrayConverted<format::HandleEncodeType>(arr, len, omit_data, omit_addr); }

    // Array of bytes.
    void EncodeUInt8Array(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)                { EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_data, omit_addr); }
    void EncodeVoidArray(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)                 { EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_data, omit_addr); }

    template<typename T>
    void EncodeHandleArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                  { EncodeWrappedHandleArray(arr, len, omit_data, omit_addr); }
    template<typename T>
    void EncodeEnumArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                    { EncodeArrayConverted<format::EnumEncodeType>(arr, len, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlagsArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                   { EncodeArrayConverted<format::FlagsEncodeType>(arr, len, omit_data, omit_addr); }

    void EncodeString(const char* str, bool omit_data = false, bool omit_addr = false)                                { EncodeBasicString<char, format::CharEncodeType, format::PointerAttributes::kIsString>(str, omit_data, omit_addr); }
    void EncodeWString(const wchar_t* str, bool omit_data = false, bool omit_addr = false)                            { EncodeBasicString<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString>(str, omit_data, omit_addr); }
    void EncodeStringArray(const char* const* str, size_t len, bool omit_data = false, bool omit_addr = false)        { EncodeBasicStringArray<char, format::CharEncodeType, format::PointerAttributes::kIsString>(str, len, omit_data, omit_addr); }
    void EncodeWStringArray(const wchar_t* const* str, size_t len, bool omit_data = false, bool omit_addr = false)    { EncodeBasicStringArray<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString>(str, len, omit_data, omit_addr); }

    template <size_t N, size_t M>
    void EncodeFloat2DMatrix(const float (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const float*>(arr), n * m, omit_data, omit_addr); }

    // clang-format on

    void EncodeStructPtrPreamble(const void* ptr, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib = format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsSingle |
                                  GetPointerAttributeMask(ptr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
        {
            EncodeAddress(ptr);
        }
    }

    void EncodeStructArrayPreamble(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib = format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray |
                                  GetPointerAttributeMask(arr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            EncodeSizeTValue(len);
        }
    }

  private:
    uint32_t GetPointerAttributeMask(const void* ptr, bool omit_data, bool omit_addr)
    {
        uint32_t pointer_attrib = 0;

        if (ptr == nullptr)
        {
            pointer_attrib |= format::PointerAttributes::kIsNull;
        }
        else
        {
            if (!omit_addr)
            {
                pointer_attrib |= format::PointerAttributes::kHasAddress;
            }

            if (!omit_data)
            {
                pointer_attrib |= format::PointerAttributes::kHasData;
            }
        }

        return pointer_attrib;
    }

    template <typename DstT, typename SrcT>
    typename std::enable_if<!std::is_pointer<SrcT>::value && !std::is_pointer<DstT>::value, DstT>::type
    TypeCast(SrcT value)
    {
        return static_cast<DstT>(value);
    }

    template <typename DstT, typename SrcT>
    typename std::enable_if<std::is_pointer<SrcT>::value || std::is_pointer<DstT>::value, DstT>::type
    TypeCast(SrcT value)
    {
        return reinterpret_cast<DstT>(value);
    }

    template <typename T>
    void EncodeValue(T value)
    {
        output_stream_->Write(&value, sizeof(T));
    }

    template <typename T>
    void EncodePointer(const T* ptr, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsSingle | GetPointerAttributeMask(ptr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (ptr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(ptr);
            }

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                output_stream_->Write(ptr, sizeof(T));
            }
        }
    }

    template <typename DstT, typename SrcT>
    void EncodePointerConverted(const SrcT* ptr, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsSingle | GetPointerAttributeMask(ptr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (ptr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(ptr);
            }

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                DstT converted = TypeCast<DstT>(*ptr);
                output_stream_->Write(&converted, sizeof(DstT));
            }
        }
    }

    template <typename SrcT>
    void EncodeWrappedHandlePointer(const SrcT* ptr, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsSingle | GetPointerAttributeMask(ptr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (ptr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(ptr);
            }

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                EncodeHandleValue(*ptr);
            }
        }
    }

    template <typename T>
    void EncodeArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsArray | GetPointerAttributeMask(arr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            EncodeSizeTValue(len);

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                output_stream_->Write(arr, len * sizeof(T));
            }
        }
    }

    // Perform a type conversion for array elements when the original type has a size that is not equal to the target
    // type for conversion.
    template <typename DstT, typename SrcT>
    typename std::enable_if<sizeof(SrcT) != sizeof(DstT), void>::type
    EncodeArrayConverted(const SrcT* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsArray | GetPointerAttributeMask(arr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            EncodeSizeTValue(len);

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                for (size_t i = 0; i < len; ++i)
                {
                    DstT converted = TypeCast<DstT>(arr[i]);
                    output_stream_->Write(&converted, sizeof(DstT));
                }
            }
        }
    }

    // Overload for the case where the original type and the conversion type have matching sizes, where we can skip the
    // type conversion.
    template <typename DstT, typename SrcT>
    typename std::enable_if<sizeof(SrcT) == sizeof(DstT), void>::type
    EncodeArrayConverted(const SrcT* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        EncodeArray(arr, len, omit_data, omit_addr);
    }

    template <typename SrcT>
    void EncodeWrappedHandleArray(const SrcT* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsArray | GetPointerAttributeMask(arr, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            EncodeSizeTValue(len);

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                for (size_t i = 0; i < len; ++i)
                {
                    EncodeHandleValue(arr[i]);
                }
            }
        }
    }

    template <typename CharT, typename EncodeT>
    typename std::enable_if<sizeof(CharT) == sizeof(EncodeT), void>::type EncodeBasicStringConverted(const CharT* str,
                                                                                                     size_t       len)
    {
        output_stream_->Write(str, len * sizeof(CharT));
    }

    template <typename CharT, typename EncodeT>
    typename std::enable_if<sizeof(CharT) != sizeof(EncodeT), void>::type EncodeBasicStringConverted(const CharT* str,
                                                                                                     size_t       len)
    {
        for (size_t i = 0; i < len; ++i)
        {
            EncodeT converted = TypeCast<EncodeT>(str[i]);
            output_stream_->Write(&converted, sizeof(EncodeT));
        }
    }

    template <typename CharT, typename EncodeT, format::PointerAttributes EncodeAttrib>
    void EncodeBasicString(const CharT* str, bool omit_data, bool omit_addr)
    {
        uint32_t pointer_attrib =
            EncodeAttrib | format::PointerAttributes::kIsSingle | GetPointerAttributeMask(str, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (str != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(str);
            }

            // Always write the string length.
            size_t len = util::platform::StringLength(str);

            EncodeSizeTValue(len);

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                EncodeBasicStringConverted<CharT, EncodeT>(str, len);
            }
        }
    }

    template <typename CharT, typename EncodeT, format::PointerAttributes EncodeAttrib>
    void EncodeBasicStringArray(const CharT* const* str, size_t len, bool omit_data, bool omit_addr)
    {
        uint32_t pointer_attrib =
            EncodeAttrib | format::PointerAttributes::kIsArray | GetPointerAttributeMask(str, omit_data, omit_addr);

        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (str != nullptr)
        {
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(str);
            }

            // Always write the array size.
            EncodeSizeTValue(len);

            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                for (size_t i = 0; i < len; ++i)
                {
                    EncodeBasicString<CharT, EncodeT, EncodeAttrib>(str[i], omit_data, omit_addr);
                }
            }
        }
    }

  private:
    util::OutputStream* output_stream_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_PARAMETER_ENCODER_H
