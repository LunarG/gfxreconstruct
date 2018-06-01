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

#ifndef BRIMSTONE_FORMAT_VALUE_DECODER_H
#define BRIMSTONE_FORMAT_VALUE_DECODER_H

#include <cassert>
#include <type_traits>
#include <memory.h>

#include "vulkan/vulkan.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class ValueDecoder
{
public:
    // Values
    static size_t DecodeInt32Value(const uint8_t* buffer, size_t buffer_size, int32_t* value) { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt32Value(const uint8_t* buffer, size_t buffer_size, uint32_t* value) { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeInt64Value(const uint8_t* buffer, size_t buffer_size, int64_t* value) { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt64Value(const uint8_t* buffer, size_t buffer_size, uint64_t* value) { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeFloatValue(const uint8_t* buffer, size_t buffer_size, float* value) { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeVkBool32Value(const uint8_t* buffer, size_t buffer_size, VkBool32* value) { return DecodeValue(buffer, buffer_size, value); }

    static size_t DecodeVkSampleMaskValue(const uint8_t* buffer, size_t buffer_size, VkSampleMask* value) { return DecodeValueFrom<SampleMaskEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeVkDeviceSizeValue(const uint8_t* buffer, size_t buffer_size, VkDeviceSize* value) { return DecodeValueFrom<DeviceSizeEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeSizeTValue(const uint8_t* buffer, size_t buffer_size, size_t* value) { return DecodeValueFrom<SizeTEncodeType>(buffer, buffer_size, value); }

    // Treat pointers to non-Vulkan objects as 64-bit object IDs.
    static size_t DecodeAddress(const uint8_t* buffer, size_t buffer_size, uint64_t* value) { return DecodeValueFrom<AddressEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size, uint64_t* value) { return DecodeAddress(buffer, buffer_size, value); }
    static size_t DecodeFunctionPtr(const uint8_t* buffer, size_t buffer_size, uint64_t* value) { return DecodeAddress(buffer, buffer_size, value); }

    template<typename T>
    static size_t DecodeHandleValue(const uint8_t* buffer, size_t buffer_size, T* value) { return DecodeValueFrom<HandleEncodeType>(buffer, buffer_size, value); }
    template<typename T>
    static size_t DecodeEnumValue(const uint8_t* buffer, size_t buffer_size, T* value) { return DecodeValueFrom<EnumEncodeType>(buffer, buffer_size, value); }
    template<typename T>
    static size_t DecodeFlagsValue(const uint8_t* buffer, size_t buffer_size, T* value) { return DecodeValueFrom<FlagsEncodeType>(buffer, buffer_size, value); }

    // Arrays
    static size_t DecodeInt32Array(const uint8_t* buffer, size_t buffer_size, int32_t* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeUInt32Array(const uint8_t* buffer, size_t buffer_size, uint32_t* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeInt64Array(const uint8_t* buffer, size_t buffer_size, int64_t* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeUInt64Array(const uint8_t* buffer, size_t buffer_size, uint64_t* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeFloatArray(const uint8_t* buffer, size_t buffer_size, float* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeVkBool32Array(const uint8_t* buffer, size_t buffer_size, VkBool32* arr, size_t len) { return DecodeArray(buffer, buffer_size, arr, len); }

    static size_t DecodeVkSampleMaskArray(const uint8_t* buffer, size_t buffer_size, VkSampleMask* arr, size_t len) { return DecodeArrayFrom<SampleMaskEncodeType>(buffer, buffer_size, arr, len); }
    static size_t DecodeVkDeviceSizeArray(const uint8_t* buffer, size_t buffer_size, VkDeviceSize* arr, size_t len) { return DecodeArrayFrom<DeviceSizeEncodeType>(buffer, buffer_size, arr, len); }
    static size_t DecodeSizeTArray(const uint8_t* buffer, size_t buffer_size, size_t* arr, size_t len) { return DecodeArrayFrom<SizeTEncodeType>(buffer, buffer_size, arr, len); }

    static size_t DecodeUInt8Array(const uint8_t* buffer, size_t buffer_size, void* arr, size_t len) { return DecodeArray(buffer, buffer_size, reinterpret_cast<uint8_t*>(arr), len); }
    static size_t DecodeVoidArray(const uint8_t* buffer, size_t buffer_size, void* arr, size_t len) { return DecodeArray(buffer, buffer_size, reinterpret_cast<uint8_t*>(arr), len); }

    template<typename T>
    static size_t DecodeHandleArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len) { return DecodeArrayFrom<HandleEncodeType>(buffer, buffer_size, arr, len); }
    template<typename T>
    static size_t DecodeEnumArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len) { return DecodeArrayFrom<EnumEncodeType>(buffer, buffer_size, arr, len); }
    template<typename T>
    static size_t DecodeFlagsArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len) { return DecodeArrayFrom<FlagsEncodeType>(buffer, buffer_size, arr, len); }

    // Perform a type conversion for array elements when the original type has a size that is not equal to the target type for conversion.
    template<typename SrcT, typename DstT>
    static typename std::enable_if<sizeof(SrcT) != sizeof(DstT), size_t>::type DecodeArrayFrom(const uint8_t* buffer, size_t buffer_size, DstT* arr, size_t len)
    {
        assert(arr != nullptr);

        size_t bytes_read = 0;
        size_t data_size = len * sizeof(SrcT);

        if (buffer_size >= data_size)
        {
            for (size_t i = 0; i < len; ++i)
            {
                SrcT from_value = 0;
                bytes_read += DecodeValue((buffer + bytes_read), (buffer_size - bytes_read), &from_value);
                arr[i] = TypeCast<DstT>(from_value);
            }
        }

        return bytes_read;
    }

    // Overload for the case where the original type and the conversion type have matching sizes, where we can skip the type conversion.
    template<typename SrcT, typename DstT>
    static typename std::enable_if<sizeof(SrcT) == sizeof(DstT), size_t>::type DecodeArrayFrom(const uint8_t* buffer, size_t buffer_size, DstT* arr, size_t len)
    {
        return DecodeArray(buffer, buffer_size, arr, len);
    }

private:
    template<typename DstT, typename SrcT>
    static typename std::enable_if<std::is_arithmetic<SrcT>::value && std::is_arithmetic<DstT>::value, DstT>::type TypeCast(SrcT value)
    {
        return static_cast<DstT>(value);
    }

    template<typename DstT, typename SrcT>
    static typename std::enable_if<!std::is_arithmetic<SrcT>::value || !std::is_arithmetic<DstT>::value, DstT>::type TypeCast(SrcT value)
    {
        return reinterpret_cast<DstT>(value);
    }

    template<typename T>
    static size_t DecodeValue(const uint8_t* buffer, size_t buffer_size, T* value)
    {
        assert(value != nullptr);

        size_t bytes_read = 0;
        size_t data_size = sizeof(T);

        if (buffer_size >= data_size)
        {
            bytes_read = data_size;
            memcpy(value, buffer, data_size);
        }

        return bytes_read;
    }

    template<typename SrcT, typename DstT>
    static size_t DecodeValueFrom(const uint8_t* buffer, size_t buffer_size, DstT* value)
    {
        assert(value != nullptr);

        size_t bytes_read = 0;
        size_t data_size = sizeof(SrcT);

        if (buffer_size >= data_size)
        {
            SrcT from_type = 0;
            bytes_read = data_size;
            memcpy(&from_type, buffer, data_size);
            (*value) = TypeCast<DstT>(from_type);
        }

        return bytes_read;
    }

    template<typename T>
    static size_t DecodeArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len)
    {
        assert(arr != nullptr);

        size_t bytes_read = 0;
        size_t data_size = len * sizeof(T);

        if (buffer_size >= data_size)
        {
            bytes_read = data_size;
            memcpy(arr, buffer, data_size);
        }

        return bytes_read;
    }
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_VALUE_DECODER_H
