/*
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#ifndef GFXRECON_DECODE_DX_FEATURE_DATA_DECODER_H
#define GFXRECON_DECODE_DX_FEATURE_DATA_DECODER_H

#include "decode/pointer_decoder.h"
#include "decode/pointer_decoder_base.h"
#include "decode/struct_pointer_decoder.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DxFeatureDataDecoder
{
  public:
    virtual ~DxFeatureDataDecoder() {}

    virtual bool IsNull() const = 0;

    virtual bool HasAddress() const = 0;

    virtual bool HasData() const = 0;

    virtual bool IsArray() const = 0;

    virtual uint32_t GetAttributeMask() const = 0;

    virtual uint64_t GetAddress() const = 0;

    virtual size_t GetLength() const = 0;

    virtual void* GetPointer() = 0;

    virtual const void* GetPointer() const = 0;

    virtual size_t GetOutputLength() const = 0;

    virtual void* GetOutputPointer() = 0;

    virtual const void* GetOutputPointer() const = 0;

    virtual void* AllocateOutputData(size_t len) = 0;

    template <typename T, typename OutputT = T>
    PointerDecoder<T, OutputT>* GetPointerDecoder()
    {
        return reinterpret_cast<PointerDecoder<T, OutputT>*>(GetPointerDecoderBase());
    }

    template <typename T, typename OutputT = T>
    const PointerDecoder<T, OutputT>* GetPointerDecoder() const
    {
        return reinterpret_cast<PointerDecoder<T, OutputT>*>(GetPointerDecoderBase());
    }

    template <typename T>
    StructPointerDecoder<T>* GetStructPointerDecoder()
    {
        return reinterpret_cast<StructPointerDecoder<T>*>(GetStructPointerDecoderBase());
    }

    template <typename T>
    const StructPointerDecoder<T>* GetStructPointerDecoder() const
    {
        return reinterpret_cast<StructPointerDecoder<T>*>(GetStructPointerDecoderBase());
    }

  protected:
    virtual PointerDecoderBase* GetPointerDecoderBase()
    {
        GFXRECON_LOG_FATAL("Invalid DxFeatureDataDecoder type conversion");
        return nullptr;
    }

    virtual const PointerDecoderBase* GetPointerDecoderBase() const
    {
        GFXRECON_LOG_FATAL("Invalid DxFeatureDataDecoder type conversion");
        return nullptr;
    }

    virtual PointerDecoderBase* GetStructPointerDecoderBase()
    {
        GFXRECON_LOG_FATAL("Invalid DxFeatureDataDecoder type conversion");
        return nullptr;
    }

    virtual const PointerDecoderBase* GetStructPointerDecoderBase() const
    {
        GFXRECON_LOG_FATAL("Invalid DxFeatureDataDecoder type conversion");
        return nullptr;
    }
};

template <typename T, typename OutputT = T>
class DxFeatureDataPointerDecoder : public DxFeatureDataDecoder
{
  public:
    // Generic override methods.
    bool IsNull() const override { return decoder_.IsNull(); }

    bool HasAddress() const override { return decoder_.HasAddress(); }

    bool HasData() const override { return decoder_.HasData(); }

    bool IsArray() const override { return decoder_.IsArray(); }

    uint32_t GetAttributeMask() const override { return decoder_.GetAttributeMask(); }

    uint64_t GetAddress() const override { return decoder_.GetAddress(); }

    size_t GetLength() const override { return decoder_.GetLength(); }

    void* GetPointer() override { return GetPointerT(); }

    const void* GetPointer() const override { return GetPointerT(); }

    size_t GetOutputLength() const override { return decoder_.GetOutputLength(); }

    void* GetOutputPointer() override { return GetOutputPointerT(); }

    const void* GetOutputPointer() const override { return GetOutputPointerT(); }

    void* AllocateOutputData(size_t len) override { return AllocateOutputDataT(len); }

    // Type specific methods.
    T* GetPointerT() { return decoder_.GetPointer(); }

    const T* GetPointerT() const { return decoder_.GetPointer(); }

    OutputT* GetOutputPointerT() { return decoder_.GetOutputPointer(); }

    const OutputT* GetOutputPointerT() const { return decoder_.GetOutputPointer(); }

    T* AllocateOutputDataT(size_t len)
    {
        if (!IsNull())
        {
            const auto value = GetPointerT();
            GFXRECON_ASSERT(value != nullptr);
            return decoder_.AllocateOutputData(len, *value);
        }

        return decoder_.AllocateOutputData(len);
    }

    // clang-format off
    size_t DecodeInt8(const uint8_t* buffer, size_t buffer_size)     { return decoder_.DecodeInt8(buffer, buffer_size); }
    size_t DecodeUInt16(const uint8_t* buffer, size_t buffer_size)   { return decoder_.DecodeUInt16(buffer, buffer_size); }
    size_t DecodeInt32(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeInt32(buffer, buffer_size); }
    size_t DecodeUInt32(const uint8_t* buffer, size_t buffer_size)   { return decoder_.DecodeUInt32(buffer, buffer_size); }
    size_t DecodeInt64(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeInt64(buffer, buffer_size); }
    size_t DecodeUInt64(const uint8_t* buffer, size_t buffer_size)   { return decoder_.DecodeUInt64(buffer, buffer_size); }
    size_t DecodeFloat(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeFloat(buffer, buffer_size); }
    size_t DecodeVoidPtr(const uint8_t* buffer, size_t buffer_size)  { return decoder_.DecodeVoidPtr(buffer, buffer_size); }
    size_t DecodeUInt8(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeUInt8(buffer, buffer_size); }
    size_t DecodeVoid(const uint8_t* buffer, size_t buffer_size)     { return decoder_.DecodeVoid(buffer, buffer_size); }
    size_t DecodeEnum(const uint8_t* buffer, size_t buffer_size)     { return decoder_.DecodeEnum(buffer, buffer_size); }
    size_t DecodeFlags(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeFlags>(buffer, buffer_size); }
    size_t DecodeHandleId(const uint8_t* buffer, size_t buffer_size) { return decoder_.DecodeHandleId(buffer, buffer_size); }
    size_t DecodeSizeT(const uint8_t* buffer, size_t buffer_size)    { return decoder_.DecodeSizeT(buffer, buffer_size); }
    // clang-format on

  protected:
    PointerDecoderBase* GetPointerDecoderBase() override { return &decoder_; }

    const PointerDecoderBase* GetPointerDecoderBase() const override { return &decoder_; }

  private:
    PointerDecoder<T, OutputT> decoder_;
};

template <typename T>
class DxFeatureDataStructPointerDecoder : public DxFeatureDataDecoder
{
  public:
    // Generic override methods.
    bool IsNull() const override { return decoder_.IsNull(); }

    bool HasAddress() const override { return decoder_.HasAddress(); }

    bool HasData() const override { return decoder_.HasData(); }

    bool IsArray() const override { return decoder_.IsArray(); }

    uint32_t GetAttributeMask() const override { return decoder_.GetAttributeMask(); }

    uint64_t GetAddress() const override { return decoder_.GetAddress(); }

    size_t GetLength() const override { return decoder_.GetLength(); }

    void* GetPointer() override { return GetPointerT(); }

    const void* GetPointer() const override { return GetPointerT(); }

    size_t GetOutputLength() const override { return decoder_.GetOutputLength(); }

    void* GetOutputPointer() override { return GetOutputPointerT(); }

    const void* GetOutputPointer() const override { return GetOutputPointerT(); }

    void* AllocateOutputData(size_t len) override { return AllocateOutputDataT(len); }

    // Type specific methods.
    T* GetMetaStructPointerT() { return decoder_.GetMetaStructPointer(); }

    const T* GetMetaStructPointerT() const { return decoder_.GetMetaStructPointer(); }

    typename T::struct_type* GetPointerT() { return decoder_.GetPointer(); }

    const typename T::struct_type* GetPointerT() const { return decoder_.GetPointer(); }

    typename T::struct_type* GetOutputPointerT() { return decoder_.GetOutputPointer(); }

    const typename T::struct_type* GetOutputPointerT() const { return decoder_.GetOutputPointer(); }

    typename T::struct_type* AllocateOutputDataT(size_t len)
    {
        if (!IsNull())
        {
            // Some feature data values are inout parameters, requiring the memory allocated for output data to be
            // initialized with the decoded value to ensure that it contains the expected in parameter values.
            const auto value = GetPointerT();
            GFXRECON_ASSERT(value != nullptr);
            return decoder_.AllocateOutputData(len, *value);
        }

        return decoder_.AllocateOutputData(len);
    }

    size_t Decode(const uint8_t* buffer, size_t buffer_size) { return decoder_.Decode(buffer, buffer_size); }

  protected:
    PointerDecoderBase* GetStructPointerDecoderBase() override { return &decoder_; }

    const PointerDecoderBase* GetStructPointerDecoderBase() const override { return &decoder_; }

  private:
    StructPointerDecoder<T> decoder_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX_FEATURE_DATA_DECODER_H
