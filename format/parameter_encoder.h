/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_FORMAT_PARAMETER_ENCODER_H
#define BRIMSTONE_FORMAT_PARAMETER_ENCODER_H

#include <cstring>
#include <cwchar>
#include <memory>
#include <type_traits>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "util/output_stream.h"
#include "util/platform.h"
#include "format/format.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class ParameterEncoder
{
public:
    ParameterEncoder(util::OutputStream* stream) : output_stream_(stream) { }

    ~ParameterEncoder() { }

    void Reset() { output_stream_->Reset(); }

    // Values
    size_t EncodeUInt8Value(uint8_t value)                                                                               { return EncodeValue(value); }
    size_t EncodeUInt16Value(uint16_t value)                                                                             { return EncodeValue(value); }
    size_t EncodeInt32Value(int32_t value)                                                                               { return EncodeValue(value); }
    size_t EncodeUInt32Value(uint32_t value)                                                                             { return EncodeValue(value); }
    size_t EncodeInt64Value(int64_t value)                                                                               { return EncodeValue(value); }
    size_t EncodeUInt64Value(uint64_t value)                                                                             { return EncodeValue(value); }
    size_t EncodeFloatValue(float value)                                                                                 { return EncodeValue(value); }
    size_t EncodeVkBool32Value(VkBool32 value)                                                                           { return EncodeValue(value); }
    size_t EncodeVkSampleMaskValue(VkSampleMask value)                                                                   { return EncodeValue(static_cast<SampleMaskEncodeType>(value)); }
    size_t EncodeVkDeviceSizeValue(VkDeviceSize value)                                                                   { return EncodeValue(static_cast<DeviceSizeEncodeType>(value)); }
    size_t EncodeSizeTValue(size_t value)                                                                                { return EncodeValue(static_cast<SizeTEncodeType>(value)); }

    // Encode the address values for pointers to non-Vulkan objects to be used as object IDs.
    size_t EncodeAddress(const void* value)                                                                              { return EncodeValue(reinterpret_cast<AddressEncodeType>(value)); }
    size_t EncodeVoidPtr(const void* value)                                                                              { return EncodeAddress(value); }
    template<typename T>
    size_t EncodeFunctionPtr(T value)                                                                                    { return EncodeValue(reinterpret_cast<AddressEncodeType>(value)); }

    template<typename T>
    size_t EncodeHandleIdValue(T value)                                                                                  { return EncodeValue(TypeCast<HandleEncodeType>(value)); }
    template<typename T>
    size_t EncodeEnumValue(T value)                                                                                      { return EncodeValue(static_cast<EnumEncodeType>(value)); }
    template<typename T>
    size_t EncodeFlagsValue(T value)                                                                                     { return EncodeValue(static_cast<FlagsEncodeType>(value)); }

    // Pointers
    size_t EncodeInt32Ptr(const int32_t* ptr, bool omit_addr = false, bool omit_data = false)                            { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeUInt32Ptr(const uint32_t* ptr, bool omit_addr = false, bool omit_data = false)                          { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeInt64Ptr(const int64_t* ptr, bool omit_addr = false, bool omit_data = false)                            { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeUInt64Ptr(const uint64_t* ptr, bool omit_addr = false, bool omit_data = false)                          { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeFloatPtr(const float* ptr, bool omit_addr = false, bool omit_data = false)                              { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeVkBool32Ptr(const VkBool32* ptr, bool omit_addr = false, bool omit_data = false)                        { return EncodePointer(ptr, omit_addr, omit_data); }
    size_t EncodeVkSampleMaskPtr(const VkSampleMask* ptr, bool omit_addr = false, bool omit_data = false)                { return EncodePointerConverted<SampleMaskEncodeType>(ptr, omit_addr, omit_data); }
    size_t EncodeVkDeviceSizePtr(const VkDeviceSize* ptr, bool omit_addr = false, bool omit_data = false)                { return EncodePointerConverted<DeviceSizeEncodeType>(ptr, omit_addr, omit_data); }
    size_t EncodeSizeTPtr(const size_t* ptr, bool omit_addr = false, bool omit_data = false)                             { return EncodePointerConverted<SizeTEncodeType>(ptr, omit_addr, omit_data); }

    // Treat pointers to non-Vulkan objects as 64-bit object IDs.
    size_t EncodeVoidPtrPtr(const void* const* ptr, bool omit_addr = false, bool omit_data = false)                      { return EncodePointerConverted<AddressEncodeType>(ptr, omit_addr, omit_data); }

    template<typename T>
    size_t EncodeHandleIdPtr(const T* ptr, bool omit_addr = false, bool omit_data = false)                               { return EncodePointerConverted<HandleEncodeType>(ptr, omit_addr, omit_data); }
    template<typename T>
    size_t EncodeEnumPtr(const T* ptr, bool omit_addr = false, bool omit_data = false)                                   { return EncodePointerConverted<EnumEncodeType>(ptr, omit_addr, omit_data); }
    template<typename T>
    size_t EncodeFlagsPtr(const T* ptr, bool omit_addr = false, bool omit_data = false)                                  { return EncodePointerConverted<FlagsEncodeType>(ptr, omit_addr, omit_data); }

    // Arrays
    size_t EncodeInt32Array(const int32_t* arr, size_t len, bool omit_addr = false, bool omit_data = false)              { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeUInt32Array(const uint32_t* arr, size_t len, bool omit_addr = false, bool omit_data = false)            { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeInt64Array(const int64_t* arr, size_t len, bool omit_addr = false, bool omit_data = false)              { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeUInt64Array(const uint64_t* arr, size_t len, bool omit_addr = false, bool omit_data = false)            { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeFloatArray(const float* arr, size_t len, bool omit_addr = false, bool omit_data = false)                { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeVkBool32Array(const VkBool32* arr, size_t len, bool omit_addr = false, bool omit_data = false)          { return EncodeArray(arr, len, omit_addr, omit_data); }
    size_t EncodeVkSampleMaskArray(const VkSampleMask* arr, size_t len, bool omit_addr = false, bool omit_data = false)  { return EncodeArrayConverted<SampleMaskEncodeType>(arr, len, omit_addr, omit_data); }
    size_t EncodeVkDeviceSizeArray(const VkDeviceSize* arr, size_t len, bool omit_addr = false, bool omit_data = false)  { return EncodeArrayConverted<DeviceSizeEncodeType>(arr, len, omit_addr, omit_data); }
    size_t EncodeSizeTArray(const size_t* arr, size_t len, bool omit_addr = false, bool omit_data = false)               { return EncodeArrayConverted<SizeTEncodeType>(arr, len, omit_addr, omit_data); }

    // Array of bytes.
    size_t EncodeUInt8Array(const void* arr, size_t len, bool omit_addr = false, bool omit_data = false)                 { return EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_addr, omit_data); }
    size_t EncodeVoidArray(const void* arr, size_t len, bool omit_addr = false, bool omit_data = false)                  { return EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_addr, omit_data); }

    template<typename T>
    size_t EncodeHandleIdArray(const T* arr, size_t len, bool omit_addr = false, bool omit_data = false)                 { return EncodeArrayConverted<HandleEncodeType>(arr, len, omit_addr, omit_data); }
    template<typename T>
    size_t EncodeEnumArray(const T* arr, size_t len, bool omit_addr = false, bool omit_data = false)                     { return EncodeArrayConverted<EnumEncodeType>(arr, len, omit_addr, omit_data); }
    template<typename T>
    size_t EncodeFlagsArray(const T* arr, size_t len, bool omit_addr = false, bool omit_data = false)                    { return EncodeArrayConverted<FlagsEncodeType>(arr, len, omit_addr, omit_data); }

    size_t EncodeString(const char* str, bool omit_addr = false, bool omit_data = false)                                 { return EncodeBasicString<char, PointerAttributes::kIsString>(str, omit_addr, omit_data); }
    size_t EncodeWString(const wchar_t* str, bool omit_addr = false, bool omit_data = false)                             { return EncodeBasicString<wchar_t, PointerAttributes::kIsWString>(str, omit_addr, omit_data); }
    size_t EncodeStringArray(const char* const* str, size_t len, bool omit_addr = false, bool omit_data = false)         { return EncodeBasicStringArray<char, PointerAttributes::kIsString>(str, len, omit_addr, omit_data); }
    size_t EncodeWStringArray(const wchar_t* const* str, size_t len, bool omit_addr = false, bool omit_data = false)     { return EncodeBasicStringArray<wchar_t, PointerAttributes::kIsWString>(str, len, omit_addr, omit_data); }

    size_t EncodeStructPtrPreamble(const void* ptr, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsStruct | kIsSingle | GetPointerAttributeMask(ptr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if ((pointer_attrib & kHasAddress) == kHasAddress)
        {
            total += EncodeAddress(ptr);
        }

        return total;
    }

    size_t EncodeStructArrayPreamble(const void* arr, size_t len, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsStruct | kIsArray | GetPointerAttributeMask(arr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            total += EncodeSizeTValue(len);
        }

        return total;
    }

private:
    uint32_t GetPointerAttributeMask(const void* ptr, bool omit_addr, bool omit_data)
    {
        uint32_t pointer_attrib = 0;

        if (ptr == nullptr)
        {
            pointer_attrib |= kIsNull;
        }
        else
        {
            if (!omit_addr)
            {
                pointer_attrib |= kHasAddress;
            }

            if (!omit_data)
            {
                pointer_attrib |= kHasData;
            }
        }

        return pointer_attrib;
    }

    template<typename DstT, typename SrcT>
    typename std::enable_if<!std::is_pointer<SrcT>::value && !std::is_pointer<DstT>::value, DstT>::type TypeCast(SrcT value)
    {
        return static_cast<DstT>(value);
    }

    template<typename DstT, typename SrcT>
    typename std::enable_if<std::is_pointer<SrcT>::value || std::is_pointer<DstT>::value, DstT>::type TypeCast(SrcT value)
    {
        return reinterpret_cast<DstT>(value);
    }

    template<typename T>
    size_t EncodeValue(T value)
    {
        return output_stream_->Write(&value, sizeof(T));
    }

    template<typename T>
    size_t EncodePointer(const T* ptr, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsSingle | GetPointerAttributeMask(ptr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (ptr != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(ptr);
            }

            if ((pointer_attrib & kHasData) == kHasData)
            {
                total += output_stream_->Write(ptr, sizeof(T));
            }
        }

        return total;
    }

    template<typename DstT, typename SrcT>
    size_t EncodePointerConverted(const SrcT* ptr, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsSingle | GetPointerAttributeMask(ptr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (ptr != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(ptr);
            }

            if ((pointer_attrib & kHasData) == kHasData)
            {
                DstT converted = TypeCast<DstT>(*ptr);
                total += output_stream_->Write(&converted, sizeof(DstT));
            }
        }

        return total;
    }

    template<typename T>
    size_t EncodeArray(const T* arr, size_t len, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsArray | GetPointerAttributeMask(arr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            total += EncodeSizeTValue(len);

            if ((pointer_attrib & kHasData) == kHasData)
            {
                total += output_stream_->Write(arr, len * sizeof(T));
            }
        }

        return total;
    }

    // Perform a type conversion for array elements when the original type has a size that is not equal to the target type for conversion.
    template<typename DstT, typename SrcT>
    typename std::enable_if<sizeof(SrcT) != sizeof(DstT), size_t>::type EncodeArrayConverted(const SrcT* arr, size_t len, bool omit_addr = false, bool omit_data = false)
    {
        uint32_t pointer_attrib = kIsArray | GetPointerAttributeMask(arr, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(arr);
            }

            // Always write the array size when the pointer is not null.
            total += EncodeSizeTValue(len);

            if ((pointer_attrib & kHasData) == kHasData)
            {
                for (size_t i = 0; i < len; ++i)
                {
                    DstT converted = TypeCast<DstT>(arr[i]);
                    total += fwrite(&converted, sizeof(DstT), 1, stdout);
                }
            }
        }

        return total;
    }

    // Overload for the case where the original type and the conversion type have matching sizes, where we can skip the type conversion.
    template<typename DstT, typename SrcT>
    typename std::enable_if<sizeof(SrcT) == sizeof(DstT), size_t>::type EncodeArrayConverted(const SrcT* arr, size_t len, bool omit_addr = false, bool omit_data = false)
    {
        return EncodeArray(arr, len, omit_addr, omit_data);
    }

    template <typename CharT, PointerAttributes EncodeAttrib>
    size_t EncodeBasicString(const CharT* str, bool omit_addr, bool omit_data)
    {
        uint32_t pointer_attrib = EncodeAttrib | kIsSingle | GetPointerAttributeMask(str, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (str != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(str);
            }

            // Always write the string length.
            size_t len = util::platform::StringLength(str);

            total += EncodeSizeTValue(len);

            if ((pointer_attrib & kHasData) == kHasData)
            {
                total += output_stream_->Write(str, len);
            }
        }

        return total;
    }

    template <typename CharT, PointerAttributes EncodeAttrib>
    size_t EncodeBasicStringArray(const CharT* const* str, size_t len, bool omit_addr, bool omit_data)
    {
        uint32_t pointer_attrib = EncodeAttrib | kIsArray | GetPointerAttributeMask(str, omit_addr, omit_data);

        size_t total = output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (str != nullptr)
        {
            if ((pointer_attrib & kHasAddress) == kHasAddress)
            {
                total += EncodeAddress(str);
            }

            // Always write the array size.
            total += EncodeSizeTValue(len);

            if ((pointer_attrib & kHasData) == kHasData)
            {
                for (size_t i = 0; i < len; ++i)
                {
                    total += EncodeBasicString<CharT, EncodeAttrib>(str[i], omit_addr, omit_data);
                }
            }
        }

        return total;
    }

private:
    util::OutputStream*                 output_stream_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_PARAMETER_ENCODER_H
