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

#ifndef GFXRECON_ENCODE_PARAMETER_ENCODER_H
#define GFXRECON_ENCODE_PARAMETER_ENCODER_H

#if ENABLE_OPENXR_SUPPORT
#include "encode/openxr_handle_wrapper_util.h"
#endif
#include "encode/vulkan_handle_wrapper_util.h"
#if ENABLE_OPENXR_SUPPORT
#include "encode/openxr_handle_wrapper_util.h"
#endif // ENABLE_OPENXR_SUPPORT
#if defined(WIN32)
#include "encode/dx12_object_wrapper_util.h"
#endif

#include "format/format.h"
#include "util/defines.h"
#include "util/output_stream.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"
#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif

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

    // clang-format off

    // Values
    void EncodeInt8Value(int8_t value)                                                                                { EncodeValue(value); }
    void EncodeUInt8Value(uint8_t value)                                                                              { EncodeValue(value); }
    void EncodeInt16Value(int16_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt16Value(uint16_t value)                                                                            { EncodeValue(value); }
    void EncodeInt32Value(int32_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt32Value(uint32_t value)                                                                            { EncodeValue(value); }
    void EncodeInt64Value(int64_t value)                                                                              { EncodeValue(value); }
    void EncodeUInt64Value(uint64_t value)                                                                            { EncodeValue(value); }
    void EncodeFloatValue(float value)                                                                                { EncodeValue(value); }
    void EncodeDoubleValue(double value)                                                                              { EncodeValue(value); }
    void EncodeSizeTValue(size_t value)                                                                               { EncodeValue(static_cast<format::SizeTEncodeType>(value)); }
    void EncodeHandleIdValue(format::HandleId value)                                                                  { EncodeValue(static_cast<format::HandleEncodeType>(value)); }
#if ENABLE_OPENXR_SUPPORT
    void EncodeD3D_FEATURE_LEVELValue(D3D_FEATURE_LEVEL value)                                                        { EncodeValue(value); }
#endif // ENABLE_OPENXR_SUPPORT

    // Encode the address values for pointers to non-Vulkan objects to be used as object IDs.
    void EncodeAddress(const void* value)                                                                             { EncodeValue(reinterpret_cast<format::AddressEncodeType>(value)); }
    void EncodeVoidPtr(const void* value)                                                                             { EncodeAddress(value); }
    template<typename T>
    void EncodeFunctionPtr(T value)                                                                                   { EncodeValue(reinterpret_cast<format::AddressEncodeType>(value)); }

    template<typename Wrapper>
    void EncodeVulkanHandleValue(typename Wrapper::HandleType value)                                                  { EncodeHandleIdValue(vulkan_wrappers::GetWrappedId<Wrapper>(value)); }
#if ENABLE_OPENXR_SUPPORT
    template<typename Wrapper>
    void EncodeOpenXrHandleValue(typename Wrapper::HandleType value)                                                  { EncodeHandleIdValue(openxr_wrappers::GetWrappedId<Wrapper>(value)); }
    template<typename Wrapper>
    void EncodeOpenXrAtomValue(typename Wrapper::HandleType value)                                                    { EncodeHandleIdValue(openxr_wrappers::GetAtomWrappedId<Wrapper>(value)); }
#endif // ENABLE_OPENXR_SUPPORT
    template<typename T>
    void EncodeEnumValue(T value)                                                                                     { EncodeValue(static_cast<format::EnumEncodeType>(value)); }
    template<typename T>
    void EncodeFlagsValue(T value)                                                                                    { EncodeValue(static_cast<format::FlagsEncodeType>(value)); }
    template<typename T>
    void EncodeFlags64Value(T value)                                                                                  { EncodeValue(static_cast<format::Flags64EncodeType>(value)); }

    // Pointers
    void EncodeUInt8Ptr(const uint8_t* ptr, bool omit_data = false, bool omit_addr = false)                           { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeUInt16Ptr(const uint16_t* ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeInt32Ptr(const int32_t* ptr, bool omit_data = false, bool omit_addr = false)                           { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeUInt32Ptr(const uint32_t* ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointer(ptr, omit_data, omit_addr); }

#if defined(WIN32)
    // Oveload for WIN32 DWORD type.  Pointers from the DWORD typedef of unsigned long are not compatible with uint32_t pointers.
    void EncodeUInt32Ptr(const unsigned long* ptr, bool omit_data = false, bool omit_addr = false)                    { EncodePointer(ptr, omit_data, omit_addr); }
    // Oveload for WIN32 SIZE_T type.  Pointers from the SIZE_T typedef of unsigned long are not compatible with size_t pointers.
    void EncodeSizeTPtr(const unsigned long* ptr, bool omit_data = false, bool omit_addr = false)                     { EncodePointer(ptr, omit_data, omit_addr); }
#endif

    void EncodeInt64Ptr(const int64_t* ptr, bool omit_data = false, bool omit_addr = false)                           { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeUInt64Ptr(const uint64_t* ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeFloatPtr(const float* ptr, bool omit_data = false, bool omit_addr = false)                             { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeSizeTPtr(const size_t* ptr, bool omit_data = false, bool omit_addr = false)                            { EncodePointerConverted<format::SizeTEncodeType>(ptr, omit_data, omit_addr); }
    void EncodeHandleIdPtr(const format::HandleId* ptr, bool omit_data = false, bool omit_addr = false)               { EncodePointerConverted<format::HandleEncodeType>(ptr, omit_data, omit_addr); }

    // Treat pointers to non-Vulkan objects as 64-bit object IDs.
    template<typename T>
    void EncodeVoidPtrPtr(const T* const* ptr, bool omit_data = false, bool omit_addr = false)                        { EncodePointerConverted<format::AddressEncodeType>(ptr, omit_data, omit_addr); }
#if ENABLE_OPENXR_SUPPORT
    void EncodeIUnknownPtr(IUnknown* ptr, bool omit_data = false, bool omit_addr = false)                             { EncodePointer(ptr, omit_data, omit_addr); }
    void EncodeIUnknownPtrPtr(IUnknown** ptr, bool omit_data = false, bool omit_addr = false)                         { EncodePointerConverted<format::AddressEncodeType>(ptr, omit_data, omit_addr); }
#endif // ENABLE_OPENXR_SUPPORT

    template<typename Wrapper>
    void EncodeVulkanHandlePtr(const typename Wrapper::HandleType* ptr, bool omit_data = false, bool omit_addr = false)     { EncodeWrappedVulkanHandlePointer<Wrapper>(ptr, omit_data, omit_addr); }
#if ENABLE_OPENXR_SUPPORT
    template<typename Wrapper>
    void EncodeOpenXrHandlePtr(const typename Wrapper::HandleType* ptr, bool omit_data = false, bool omit_addr = false)     { EncodeWrappedOpenXrHandlePointer<Wrapper>(ptr, omit_data, omit_addr); }
    template<typename Wrapper>
    void EncodeOpenXrAtomPtr(const typename Wrapper::HandleType* ptr, bool omit_data = false, bool omit_addr = false)       { EncodeWrappedOpenXrAtomPointer<Wrapper>(ptr, omit_data, omit_addr); }
#endif // ENABLE_OPENXR_SUPPORT
    template<typename T>
    void EncodeEnumPtr(const T* ptr, bool omit_data = false, bool omit_addr = false)                                  { EncodePointerConverted<format::EnumEncodeType>(ptr, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlagsPtr(const T* ptr, bool omit_data = false, bool omit_addr = false)                                 { EncodePointerConverted<format::FlagsEncodeType>(ptr, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlags64Ptr(const T* ptr, bool omit_data = false, bool omit_addr = false)                               { EncodePointerConverted<format::Flags64EncodeType>(ptr, omit_data, omit_addr); }

    // Arrays
    void EncodeInt8Array(const int8_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)               { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeInt16Array(const int16_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)             { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeUInt16Array(const uint16_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)           { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeInt32Array(const int32_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)             { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeUInt32Array(const uint32_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)           { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeInt64Array(const int64_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)             { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeUInt64Array(const uint64_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)           { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeFloatArray(const float* arr, size_t len, bool omit_data = false, bool omit_addr = false)               { EncodeArray(arr, len, omit_data, omit_addr); }
    void EncodeSizeTArray(const size_t* arr, size_t len, bool omit_data = false, bool omit_addr = false)              { EncodeArrayConverted<format::SizeTEncodeType>(arr, len, omit_data, omit_addr); }
    void EncodeHandleIdArray(const format::HandleId* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeArrayConverted<format::HandleEncodeType>(arr, len, omit_data, omit_addr); }
    void EncodeVkFormatArray(const VkFormat* arr, size_t len, bool omit_data = false, bool omit_addr = false)         { EncodeArrayConverted<format::FormatEncodeType>(arr, len, omit_data, omit_addr); }
#if ENABLE_OPENXR_SUPPORT
    void EncodeXrBool32Array(const XrBool32* arr, size_t len, bool omit_data = false, bool omit_addr = false)         { EncodeArray(arr, len, omit_data, omit_addr); }
#endif // ENABLE_OPENXR_SUPPORT

    // Array of bytes.
    void EncodeUInt8Array(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)                { EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_data, omit_addr); }
    void EncodeVoidArray(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)                 { EncodeArray(reinterpret_cast<const uint8_t*>(arr), len, omit_data, omit_addr); }

    template<typename Wrapper>
    void EncodeVulkanHandleArray(const typename Wrapper::HandleType* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeWrappedVulkanHandleArray<Wrapper>(arr, len, omit_data, omit_addr); }
#if ENABLE_OPENXR_SUPPORT
    template<typename Wrapper>
    void EncodeOpenXrHandleArray(const typename Wrapper::HandleType* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeWrappedOpenXrHandleArray<Wrapper>(arr, len, omit_data, omit_addr); }
    template<typename Wrapper>
    void EncodeOpenXrAtomArray(const typename Wrapper::HandleType* arr, size_t len, bool omit_data = false, bool omit_addr = false) { EncodeWrappedOpenXrAtomArray<Wrapper>(arr, len, omit_data, omit_addr); }
#endif // ENABLE_OPENXR_SUPPORT
    template<typename T>
    void EncodeEnumArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                    { EncodeArrayConverted<format::EnumEncodeType>(arr, len, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlagsArray(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                   { EncodeArrayConverted<format::FlagsEncodeType>(arr, len, omit_data, omit_addr); }
    template<typename T>
    void EncodeFlags64Array(const T* arr, size_t len, bool omit_data = false, bool omit_addr = false)                 { EncodeArrayConverted<format::Flags64EncodeType>(arr, len, omit_data, omit_addr); }

    void EncodeString(const char* str, bool omit_data = false, bool omit_addr = false)                                { EncodeBasicString<char, format::CharEncodeType, format::PointerAttributes::kIsString>(str, omit_data, omit_addr); }
    void EncodeWString(const wchar_t* str, bool omit_data = false, bool omit_addr = false)                            { EncodeBasicString<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString>(str, omit_data, omit_addr); }
    void EncodeStringArray(const char* const* str, size_t len, bool omit_data = false, bool omit_addr = false)        { EncodeBasicStringArray<char, format::CharEncodeType, format::PointerAttributes::kIsString>(str, len, omit_data, omit_addr); }
    void EncodeWStringArray(const wchar_t* const* str, size_t len, bool omit_data = false, bool omit_addr = false)    { EncodeBasicStringArray<wchar_t, format::WCharEncodeType, format::PointerAttributes::kIsWString>(str, len, omit_data, omit_addr); }

    // 2D Arrays
    template<typename SizeT>
    void EncodeUInt32Array2D(const uint32_t* const* arr, SizeT size_2d, bool omit_data = false, bool omit_addr = false) { EncodeArray2D(arr, size_2d, omit_data, omit_addr); }
    template<typename T, typename SizeT>
    void EncodeEnumArray2D(const T* const* arr, SizeT size_2d, bool omit_data = false, bool omit_addr = false) { EncodeArray2DConverted<format::EnumEncodeType>(arr, size_2d, omit_data, omit_addr); }

    template <size_t N, size_t M>
    void EncodeFloat2DMatrix(const float (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const float*>(arr), n * m, omit_data, omit_addr); }
    template <size_t N, size_t M>
    void EncodeUInt82DMatrix(const uint8_t (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const uint8_t*>(arr), n * m, omit_data, omit_addr); }
    template <size_t N, size_t M>
    void EncodeInt82DMatrix(const int8_t (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const int8_t*>(arr), n * m, omit_data, omit_addr); }
    template <size_t N, size_t M>
    void EncodeInt162DMatrix(const int16_t (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const int16_t*>(arr), n * m, omit_data, omit_addr); }
    template <size_t N, size_t M>
    void EncodeUInt162DMatrix(const uint16_t (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const uint16_t*>(arr), n * m, omit_data, omit_addr); }
    template <size_t N, size_t M>
    void EncodeInt322DMatrix(const int32_t (&arr)[N][M], size_t n, size_t m, bool omit_data = false, bool omit_addr = false) { assert((N == n) && (M == m)); EncodeArray(reinterpret_cast<const int32_t*>(arr), n * m, omit_data, omit_addr); }

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

    void EncodeStructArray2DPreamble(const void* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        uint32_t pointer_attrib = format::PointerAttributes::kIsStruct | format::PointerAttributes::kIsArray2D |
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

#if defined(WIN32)
    template <typename T>
    void EncodeObjectValue(const T* value)
    {
        EncodeHandleIdValue(GetDx12WrappedId<T>(value));
    }

    template <typename T>
    void EncodeObjectPtr(const T* const* value, bool omit_data = false, bool omit_addr = false)
    {
        EncodeWrappedObjectPointer(value, omit_data, omit_addr);
    }

    void EncodeObjectPtr(const void* const* value, bool omit_data = false, bool omit_addr = false)
    {
        EncodeWrappedObjectPointer(reinterpret_cast<const IUnknown* const*>(value), omit_data, omit_addr);
    }

    template <typename T>
    void EncodeWrappedObjectPointer(const T* const* ptr, bool omit_data = false, bool omit_addr = false)
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
                EncodeObjectValue<T>(*ptr);
            }
        }
    }

    template <typename T>
    void EncodeObjectArray(T* const* arr, size_t len, bool omit_data = false, bool omit_addr = false)
    {
        EncodeWrappedObjectArray<T>(arr, len, omit_data, omit_addr);
    }

    template <typename T>
    void EncodeWrappedObjectArray(T* const* arr, size_t len, bool omit_data = false, bool omit_addr = false)
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
                    EncodeObjectValue<T>(arr[i]);
                }
            }
        }
    }
#endif

    void EncodeRawBytes(const void* bytes, size_t num_bytes)
    {
        output_stream_->Write(bytes, num_bytes);
    }

#if ENABLE_OPENXR_SUPPORT

    void EncodeMLCoordinateFrameUIDValue(MLCoordinateFrameUID value)
    {
        EncodeValue(value.data[0]);
        EncodeValue(value.data[1]);
    }

#endif // ENABLE_OPENXR_SUPPORT

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

    template <typename Wrapper>
    void EncodeWrappedVulkanHandlePointer(const typename Wrapper::HandleType* ptr,
                                          bool                                omit_data = false,
                                          bool                                omit_addr = false)
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
                EncodeVulkanHandleValue<Wrapper>(*ptr);
            }
        }
    }

#if ENABLE_OPENXR_SUPPORT
    template <typename Wrapper>
    void EncodeWrappedOpenXrHandlePointer(const typename Wrapper::HandleType* ptr,
                                          bool                                omit_data = false,
                                          bool                                omit_addr = false)
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
                EncodeOpenXrHandleValue<Wrapper>(*ptr);
            }
        }
    }

    template <typename Wrapper>
    void EncodeWrappedOpenXrAtomPointer(const typename Wrapper::HandleType* ptr,
                                        bool                                omit_data = false,
                                        bool                                omit_addr = false)
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
                EncodeOpenXrAtomValue<Wrapper>(*ptr);
            }
        }
    }

#endif // ENABLE_OPENXR_SUPPORT

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

    template <typename Wrapper>
    void EncodeWrappedVulkanHandleArray(const typename Wrapper::HandleType* arr,
                                        size_t                              len,
                                        bool                                omit_data = false,
                                        bool                                omit_addr = false)
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
                    EncodeVulkanHandleValue<Wrapper>(arr[i]);
                }
            }
        }
    }

#if ENABLE_OPENXR_SUPPORT
    template <typename Wrapper>
    void EncodeWrappedOpenXrHandleArray(const typename Wrapper::HandleType* arr,
                                        size_t                              len,
                                        bool                                omit_data = false,
                                        bool                                omit_addr = false)
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
                    EncodeOpenXrHandleValue<Wrapper>(arr[i]);
                }
            }
        }
    }

    template <typename Wrapper>
    void EncodeWrappedOpenXrAtomArray(const typename Wrapper::HandleType* arr,
                                      size_t                              len,
                                      bool                                omit_data = false,
                                      bool                                omit_addr = false)
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
                    EncodeOpenXrAtomValue<Wrapper>(arr[i]);
                }
            }
        }
    }
#endif // ENABLE_OPENXR_SUPPORT

    template <typename T, typename SizeT>
    typename std::enable_if<!std::is_integral<SizeT>::value>::type
    EncodeArray2D(const T* const* arr, SizeT size_2d, bool omit_data = false, bool omit_addr = false)
    {
        // Outer pointer attributes
        uint32_t pointer_attrib =
            format::PointerAttributes::kIsArray2D | GetPointerAttributeMask(arr, omit_data, omit_addr);
        output_stream_->Write(&pointer_attrib, sizeof(pointer_attrib));

        if (arr != nullptr)
        {
            // Outer array address
            if ((pointer_attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                EncodeAddress(arr);
            }

            // Outer array size
            EncodeSizeTValue(size_2d.size());

            // Treat all inner array infomation as data
            if ((pointer_attrib & format::PointerAttributes::kHasData) == format::PointerAttributes::kHasData)
            {
                for (size_t i = 0; i < size_2d.size(); ++i)
                {
                    // Inner pointer attributes
                    uint32_t inner_pointer_attrib =
                        format::PointerAttributes::kIsArray | GetPointerAttributeMask(arr[i], omit_data, omit_addr);
                    output_stream_->Write(&inner_pointer_attrib, sizeof(inner_pointer_attrib));

                    // Inner array address
                    if ((inner_pointer_attrib & format::PointerAttributes::kHasAddress) ==
                        format::PointerAttributes::kHasAddress)
                    {
                        EncodeAddress(arr[i]);
                    }

                    // Inner array size
                    EncodeSizeTValue(size_2d[i]);

                    // Inner array data
                    if ((inner_pointer_attrib & format::PointerAttributes::kHasData) ==
                        format::PointerAttributes::kHasData)
                    {
                        output_stream_->Write(arr[i], size_2d[i] * sizeof(T));
                    }
                }
            }
        }
    }

    template <typename DstT, typename SrcT, typename SizeT>
    typename std::enable_if<sizeof(SrcT) != sizeof(DstT), void>::type
    EncodeArray2DConverted(const SrcT* const* arr, SizeT size_2d, bool omit_data = false, bool omit_addr = false)
    {
        static_assert(sizeof(SrcT) == sizeof(DstT),
                      "Encoding 2D arrays that require type conversion is not implemented.");
    }

    // Overload for the case where the original type and the conversion type have matching sizes, where we can skip the
    // type conversion.
    template <typename DstT, typename SrcT, typename SizeT>
    typename std::enable_if<sizeof(SrcT) == sizeof(DstT), void>::type
    EncodeArray2DConverted(const SrcT* const* arr, SizeT size_2d, bool omit_data = false, bool omit_addr = false)
    {
        EncodeArray2D(arr, size_2d, omit_data, omit_addr);
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
