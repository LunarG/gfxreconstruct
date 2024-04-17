/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VALUE_DECODER_H
#define GFXRECON_DECODE_VALUE_DECODER_H

#include "format/platform_types.h"
#include "format/format.h"
#include "util/defines.h"

#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif
#include "vulkan/vulkan.h"

#include <cassert>
#include <type_traits>
#include <memory.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class ValueDecoder
{
  public:
    // clang-format off

    // Values
    static size_t DecodeInt8Value(const uint8_t* buffer, size_t buffer_size, int8_t* value)                         { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt8Value(const uint8_t* buffer, size_t buffer_size, uint8_t* value)                       { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeInt16Value(const uint8_t* buffer, size_t buffer_size, int16_t* value)                       { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt16Value(const uint8_t* buffer, size_t buffer_size, uint16_t* value)                     { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeInt32Value(const uint8_t* buffer, size_t buffer_size, int32_t* value)                       { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt32Value(const uint8_t* buffer, size_t buffer_size, uint32_t* value)                     { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt32BitFieldValue(const uint8_t* buffer, size_t buffer_size, const uint32_t& value)       { return 0; }

#if defined(WIN32)
    // Oveload for WIN32 LONG type.  Pointers from the LONG typedef of unsigned long are not compatible with int32_t pointers.
    static size_t DecodeInt32Value(const uint8_t* buffer, size_t buffer_size, long* value)                          { return DecodeValue(buffer, buffer_size, value); }
    // Oveload for WIN32 DWORD type.  Pointers from the DWORD typedef of unsigned long are not compatible with uint32_t pointers.
    static size_t DecodeUInt32Value(const uint8_t* buffer, size_t buffer_size, unsigned long* value)                { return DecodeValue(buffer, buffer_size, value); }
#endif

    static size_t DecodeInt64Value(const uint8_t* buffer, size_t buffer_size, int64_t* value)                       { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeUInt64Value(const uint8_t* buffer, size_t buffer_size, uint64_t* value)                     { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeFloatValue(const uint8_t* buffer, size_t buffer_size, float* value)                         { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeDoubleValue(const uint8_t* buffer, size_t buffer_size, double* value)                       { return DecodeValue(buffer, buffer_size, value); }
    static size_t DecodeVkBool32Value(const uint8_t* buffer, size_t buffer_size, VkBool32* value)                   { return DecodeValue(buffer, buffer_size, value); }
#if ENABLE_OPENXR_SUPPORT
    static size_t DecodeXrBool32Value(const uint8_t* buffer, size_t buffer_size, XrBool32* value)                   { return DecodeValue(buffer, buffer_size, value); }
#endif

    static size_t DecodeVkSampleMaskValue(const uint8_t* buffer, size_t buffer_size, VkSampleMask* value)           { return DecodeValueFrom<format::SampleMaskEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeVkDeviceSizeValue(const uint8_t* buffer, size_t buffer_size, VkDeviceSize* value)           { return DecodeValueFrom<format::DeviceSizeEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeVkDeviceAddressValue(const uint8_t* buffer, size_t buffer_size, VkDeviceAddress* value)     { return DecodeValueFrom<format::DeviceAddressEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeSizeTValue(const uint8_t* buffer, size_t buffer_size, size_t* value)                        { return DecodeValueFrom<format::SizeTEncodeType>(buffer, buffer_size, value); }
#if (defined(VK_USE_PLATFORM_XLIB_KHR) || defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)) && !defined(GFXRECON_ARCH64)
    // Oveload for the 32-bit XID type.  Pointers from the 32-bit XID typedef of unsigned long are not compatible with size_t pointers.
    static size_t DecodeSizeTValue(const uint8_t* buffer, size_t buffer_size, unsigned long* value)                 { return DecodeValueFrom<format::SizeTEncodeType>(buffer, buffer_size, value); }
#elif defined(WIN32)
#if !defined(GFXRECON_ARCH64)
    // Oveload for 32-bit WIN32 SIZE_T type.  Pointers from the unsigned long typedef of are not compatible with size_t pointers.
    static size_t DecodeSizeTValue(const uint8_t* buffer, size_t buffer_size, SIZE_T* value)                        { return DecodeValueFrom<format::SizeTEncodeType>(buffer, buffer_size, value); }
#endif
    // Oveload for WIN32 LONG_PTR type.  Pointers from the LONG_PTR typedef of __int64 / long are not compatible with size_t pointers.
    static size_t DecodeSizeTValue(const uint8_t* buffer, size_t buffer_size, LONG_PTR* value)                      { return DecodeValueFrom<format::SizeTEncodeType>(buffer, buffer_size, value); }
#endif

#if ENABLE_OPENXR_SUPPORT
    static size_t DecodeD3D_FEATURE_LEVELValue(const uint8_t* buffer, size_t buffer_size, D3D_FEATURE_LEVEL* value) { return DecodeValueFrom<format::D3D_FEATURE_LEVELEncodeType>(buffer, buffer_size, value); }

    static size_t DecodeMLCoordinateFrameUIDValue(const uint8_t* buffer, size_t buffer_size, MLCoordinateFrameUID* value)
    {
        return DecodeUInt64Array(buffer,buffer_size, value->data, 2);
    }

#endif // ENABLE_OPENXR_SUPPORT

    // Treat pointers to non-Vulkan objects as 64-bit object IDs.
    static size_t DecodeAddress(const uint8_t* buffer, size_t buffer_size, uint64_t* value)                         { return DecodeValueFrom<format::AddressEncodeType>(buffer, buffer_size, value); }
    static size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size, uint64_t* value)                         { return DecodeAddress(buffer, buffer_size, value); }

    static size_t DecodeHandleIdValue(const uint8_t* buffer, size_t buffer_size, format::HandleId* value)           { return DecodeValueFrom<format::HandleEncodeType>(buffer, buffer_size, value); }
    template<typename T>
    static size_t DecodeEnumValue(const uint8_t* buffer, size_t buffer_size, T* value)                              { return DecodeValueFrom<format::EnumEncodeType>(buffer, buffer_size, value); }
    template<typename T>
    static size_t DecodeFlagsValue(const uint8_t* buffer, size_t buffer_size, T* value)                             { return DecodeValueFrom<format::FlagsEncodeType>(buffer, buffer_size, value); }
    template<typename T>
    static size_t DecodeFlags64Value(const uint8_t* buffer, size_t buffer_size, T* value)                           { return DecodeValueFrom<format::Flags64EncodeType>(buffer, buffer_size, value); }

    // Arrays
    static size_t DecodeCharArray(const uint8_t* buffer, size_t buffer_size, char* arr, size_t len)                 { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeInt32Array(const uint8_t* buffer, size_t buffer_size, int32_t* arr, size_t len)             { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeUInt32Array(const uint8_t* buffer, size_t buffer_size, uint32_t* arr, size_t len)           { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeInt64Array(const uint8_t* buffer, size_t buffer_size, int64_t* arr, size_t len)             { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeUInt64Array(const uint8_t* buffer, size_t buffer_size, uint64_t* arr, size_t len)           { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeFloatArray(const uint8_t* buffer, size_t buffer_size, float* arr, size_t len)               { return DecodeArray(buffer, buffer_size, arr, len); }
    static size_t DecodeVkBool32Array(const uint8_t* buffer, size_t buffer_size, VkBool32* arr, size_t len)         { return DecodeArray(buffer, buffer_size, arr, len); }
#if ENABLE_OPENXR_SUPPORT
    static size_t DecodeXrBool32Array(const uint8_t* buffer, size_t buffer_size, XrBool32* arr, size_t len)         { return DecodeArray(buffer, buffer_size, arr, len); }
#endif

    static size_t DecodeVkSampleMaskArray(const uint8_t* buffer, size_t buffer_size, VkSampleMask* arr, size_t len) { return DecodeArrayFrom<format::SampleMaskEncodeType>(buffer, buffer_size, arr, len); }
    static size_t DecodeVkDeviceSizeArray(const uint8_t* buffer, size_t buffer_size, VkDeviceSize* arr, size_t len) { return DecodeArrayFrom<format::DeviceSizeEncodeType>(buffer, buffer_size, arr, len); }
    static size_t DecodeVkDeviceAddressArray(const uint8_t* buffer, size_t buffer_size, VkDeviceAddress* arr, size_t len) { return DecodeArrayFrom<format::DeviceAddressEncodeType>(buffer, buffer_size, arr, len); }
    static size_t DecodeSizeTArray(const uint8_t* buffer, size_t buffer_size, size_t* arr, size_t len)              { return DecodeArrayFrom<format::SizeTEncodeType>(buffer, buffer_size, arr, len); }

    static size_t DecodeUInt8Array(const uint8_t* buffer, size_t buffer_size, void* arr, size_t len)                { return DecodeArray(buffer, buffer_size, reinterpret_cast<uint8_t*>(arr), len); }
    static size_t DecodeVoidArray(const uint8_t* buffer, size_t buffer_size, void* arr, size_t len)                 { return DecodeArray(buffer, buffer_size, reinterpret_cast<uint8_t*>(arr), len); }

    static size_t DecodeHandleIdArray(const uint8_t* buffer, size_t buffer_size, format::HandleId* arr, size_t len) { return DecodeArrayFrom<format::HandleEncodeType>(buffer, buffer_size, arr, len); }
    template<typename T>
    static size_t DecodeEnumArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len)                    { return DecodeArrayFrom<format::EnumEncodeType>(buffer, buffer_size, arr, len); }
    template<typename T>
    static size_t DecodeFlagsArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len)                   { return DecodeArrayFrom<format::FlagsEncodeType>(buffer, buffer_size, arr, len); }
    template<typename T>
    static size_t DecodeFlags64Array(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len)                 { return DecodeArrayFrom<format::Flags64EncodeType>(buffer, buffer_size, arr, len); }

    // clang-format on

    // Perform a type conversion for array elements when the original type has a size that is not equal to the target
    // type for conversion.
    template <typename SrcT, typename DstT>
    static typename std::enable_if<sizeof(SrcT) != sizeof(DstT), size_t>::type
    DecodeArrayFrom(const uint8_t* buffer, size_t buffer_size, DstT* arr, size_t len)
    {
        assert(arr != nullptr);

        size_t bytes_read = 0;
        size_t data_size  = len * sizeof(SrcT);

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

    // Overload for the case where the original type and the conversion type have matching sizes, where we can skip the
    // type conversion.
    template <typename SrcT, typename DstT>
    static typename std::enable_if<sizeof(SrcT) == sizeof(DstT), size_t>::type
    DecodeArrayFrom(const uint8_t* buffer, size_t buffer_size, DstT* arr, size_t len)
    {
        return DecodeArray(buffer, buffer_size, arr, len);
    }

  private:
    template <typename DstT, typename SrcT>
    static typename std::enable_if<!std::is_pointer<SrcT>::value && !std::is_pointer<DstT>::value, DstT>::type
    TypeCast(SrcT value)
    {
        return static_cast<DstT>(value);
    }

    template <typename DstT, typename SrcT>
    static typename std::enable_if<std::is_pointer<SrcT>::value || std::is_pointer<DstT>::value, DstT>::type
    TypeCast(SrcT value)
    {
        return reinterpret_cast<DstT>(value);
    }

    template <typename T>
    static size_t DecodeValue(const uint8_t* buffer, size_t buffer_size, T* value)
    {
        assert(value != nullptr);

        size_t bytes_read = 0;
        size_t data_size  = sizeof(T);

        if (buffer_size >= data_size)
        {
            bytes_read = data_size;
            memcpy(value, buffer, data_size);
        }

        return bytes_read;
    }

    template <typename SrcT, typename DstT>
    static size_t DecodeValueFrom(const uint8_t* buffer, size_t buffer_size, DstT* value)
    {
        assert(value != nullptr);

        size_t bytes_read = 0;
        size_t data_size  = sizeof(SrcT);

        if (buffer_size >= data_size)
        {
            SrcT from_type = 0;
            bytes_read     = data_size;
            memcpy(&from_type, buffer, data_size);
            (*value) = TypeCast<DstT>(from_type);
        }

        return bytes_read;
    }

    template <typename T>
    static size_t DecodeArray(const uint8_t* buffer, size_t buffer_size, T* arr, size_t len)
    {
        assert(arr != nullptr);

        size_t bytes_read = 0;
        size_t data_size  = len * sizeof(T);

        if (buffer_size >= data_size)
        {
            bytes_read = data_size;
            memcpy(arr, buffer, data_size);
        }

        return bytes_read;
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VALUE_DECODER_H
