/*
** Copyright (c) 2021-2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

/*
** This file is generated from dx12_struct_decoders_body_generator.py.
**
*/

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "generated_dx12_struct_decoders.h"

#include "decode/custom_dx12_struct_decoders.h"
#include "decode/decode_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_FRAME_STATISTICS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_FRAME_STATISTICS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PresentCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PresentRefreshCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncRefreshCount));
    wrapper->SyncQPCTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->SyncQPCTime->decoded_value = &(value->SyncQPCTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SyncQPCTime);
    wrapper->SyncGPUTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->SyncGPUTime->decoded_value = &(value->SyncGPUTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SyncGPUTime);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_MAPPED_RECT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_MAPPED_RECT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Pitch));
    bytes_read += wrapper->pBits.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBits = wrapper->pBits.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_LUID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    LUID* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->LowPart));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->HighPart));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_ADAPTER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_ADAPTER_DESC* value = wrapper->decoded_value;

    wrapper->Description.SetExternalMemory(value->Description, 128);
    bytes_read += wrapper->Description.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VendorId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SubSysId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedVideoMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedSystemMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedSystemMemory));
    wrapper->AdapterLuid = DecodeAllocator::Allocate<Decoded_LUID>();
    wrapper->AdapterLuid->decoded_value = &(value->AdapterLuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AdapterLuid);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTPUT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTPUT_DESC* value = wrapper->decoded_value;

    wrapper->DeviceName.SetExternalMemory(value->DeviceName, 32);
    bytes_read += wrapper->DeviceName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->DesktopCoordinates = DecodeAllocator::Allocate<Decoded_tagRECT>();
    wrapper->DesktopCoordinates->decoded_value = &(value->DesktopCoordinates);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DesktopCoordinates);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AttachedToDesktop));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Rotation));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->Monitor));
    value->Monitor = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SHARED_RESOURCE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SHARED_RESOURCE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->Handle));
    value->Handle = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SURFACE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SURFACE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SWAP_CHAIN_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SWAP_CHAIN_DESC* value = wrapper->decoded_value;

    wrapper->BufferDesc = DecodeAllocator::Allocate<Decoded_DXGI_MODE_DESC>();
    wrapper->BufferDesc->decoded_value = &(value->BufferDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BufferDesc);
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferUsage));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferCount));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->OutputWindow));
    value->OutputWindow = nullptr;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Windowed));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SwapEffect));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_ADAPTER_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_ADAPTER_DESC1* value = wrapper->decoded_value;

    wrapper->Description.SetExternalMemory(value->Description, 128);
    bytes_read += wrapper->Description.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VendorId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SubSysId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedVideoMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedSystemMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedSystemMemory));
    wrapper->AdapterLuid = DecodeAllocator::Allocate<Decoded_LUID>();
    wrapper->AdapterLuid->decoded_value = &(value->AdapterLuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AdapterLuid);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_DISPLAY_COLOR_SPACE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_DISPLAY_COLOR_SPACE* value = wrapper->decoded_value;

    wrapper->PrimaryCoordinates.SetExternalMemory(*value->PrimaryCoordinates, 16);
    bytes_read += wrapper->PrimaryCoordinates.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->WhitePoints.SetExternalMemory(*value->WhitePoints, 32);
    bytes_read += wrapper->WhitePoints.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTDUPL_MOVE_RECT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTDUPL_MOVE_RECT* value = wrapper->decoded_value;

    wrapper->SourcePoint = DecodeAllocator::Allocate<Decoded_tagPOINT>();
    wrapper->SourcePoint->decoded_value = &(value->SourcePoint);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SourcePoint);
    wrapper->DestinationRect = DecodeAllocator::Allocate<Decoded_tagRECT>();
    wrapper->DestinationRect->decoded_value = &(value->DestinationRect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DestinationRect);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTDUPL_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTDUPL_DESC* value = wrapper->decoded_value;

    wrapper->ModeDesc = DecodeAllocator::Allocate<Decoded_DXGI_MODE_DESC>();
    wrapper->ModeDesc->decoded_value = &(value->ModeDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->ModeDesc);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Rotation));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DesktopImageInSystemMemory));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTDUPL_POINTER_POSITION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTDUPL_POINTER_POSITION* value = wrapper->decoded_value;

    wrapper->Position = DecodeAllocator::Allocate<Decoded_tagPOINT>();
    wrapper->Position->decoded_value = &(value->Position);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Position);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Visible));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Pitch));
    wrapper->HotSpot = DecodeAllocator::Allocate<Decoded_tagPOINT>();
    wrapper->HotSpot->decoded_value = &(value->HotSpot);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->HotSpot);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTDUPL_FRAME_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTDUPL_FRAME_INFO* value = wrapper->decoded_value;

    wrapper->LastPresentTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->LastPresentTime->decoded_value = &(value->LastPresentTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->LastPresentTime);
    wrapper->LastMouseUpdateTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->LastMouseUpdateTime->decoded_value = &(value->LastMouseUpdateTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->LastMouseUpdateTime);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccumulatedFrames));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RectsCoalesced));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ProtectedContentMaskedOut));
    wrapper->PointerPosition = DecodeAllocator::Allocate<Decoded_DXGI_OUTDUPL_POINTER_POSITION>();
    wrapper->PointerPosition->decoded_value = &(value->PointerPosition);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PointerPosition);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TotalMetadataBufferSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PointerShapeBufferSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_MODE_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_MODE_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    wrapper->RefreshRate = DecodeAllocator::Allocate<Decoded_DXGI_RATIONAL>();
    wrapper->RefreshRate->decoded_value = &(value->RefreshRate);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->RefreshRate);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScanlineOrdering));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Scaling));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Stereo));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SWAP_CHAIN_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SWAP_CHAIN_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Stereo));
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferUsage));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Scaling));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SwapEffect));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AlphaMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value = wrapper->decoded_value;

    wrapper->RefreshRate = DecodeAllocator::Allocate<Decoded_DXGI_RATIONAL>();
    wrapper->RefreshRate->decoded_value = &(value->RefreshRate);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->RefreshRate);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScanlineOrdering));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Scaling));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Windowed));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_PRESENT_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_PRESENT_PARAMETERS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DirtyRectsCount));
    wrapper->pDirtyRects = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_tagRECT>>();
    bytes_read += wrapper->pDirtyRects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDirtyRects = wrapper->pDirtyRects->GetPointer();
    wrapper->pScrollRect = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_tagRECT>>();
    bytes_read += wrapper->pScrollRect->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pScrollRect = wrapper->pScrollRect->GetPointer();
    wrapper->pScrollOffset = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_tagPOINT>>();
    bytes_read += wrapper->pScrollOffset->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pScrollOffset = wrapper->pScrollOffset->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_ADAPTER_DESC2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_ADAPTER_DESC2* value = wrapper->decoded_value;

    wrapper->Description.SetExternalMemory(value->Description, 128);
    bytes_read += wrapper->Description.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VendorId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SubSysId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedVideoMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedSystemMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedSystemMemory));
    wrapper->AdapterLuid = DecodeAllocator::Allocate<Decoded_LUID>();
    wrapper->AdapterLuid->decoded_value = &(value->AdapterLuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AdapterLuid);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->GraphicsPreemptionGranularity));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComputePreemptionGranularity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_MATRIX_3X2_F* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_MATRIX_3X2_F* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_11));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_12));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_21));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_22));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_31));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->_32));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_DECODE_SWAP_CHAIN_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_FRAME_STATISTICS_MEDIA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_FRAME_STATISTICS_MEDIA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PresentCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PresentRefreshCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncRefreshCount));
    wrapper->SyncQPCTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->SyncQPCTime->decoded_value = &(value->SyncQPCTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SyncQPCTime);
    wrapper->SyncGPUTime = DecodeAllocator::Allocate<Decoded_LARGE_INTEGER>();
    wrapper->SyncGPUTime->decoded_value = &(value->SyncGPUTime);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SyncGPUTime);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CompositionMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ApprovedPresentDuration));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_QUERY_VIDEO_MEMORY_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Budget));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CurrentUsage));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AvailableForReservation));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CurrentReservation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_HDR_METADATA_HDR10* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_HDR_METADATA_HDR10* value = wrapper->decoded_value;

    wrapper->RedPrimary.SetExternalMemory(value->RedPrimary, 2);
    bytes_read += wrapper->RedPrimary.DecodeUInt16((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->GreenPrimary.SetExternalMemory(value->GreenPrimary, 2);
    bytes_read += wrapper->GreenPrimary.DecodeUInt16((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->BluePrimary.SetExternalMemory(value->BluePrimary, 2);
    bytes_read += wrapper->BluePrimary.DecodeUInt16((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->WhitePoint.SetExternalMemory(value->WhitePoint, 2);
    bytes_read += wrapper->WhitePoint.DecodeUInt16((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxMasteringLuminance));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinMasteringLuminance));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxContentLightLevel));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxFrameAverageLightLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_HDR_METADATA_HDR10PLUS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_HDR_METADATA_HDR10PLUS* value = wrapper->decoded_value;

    wrapper->Data.SetExternalMemory(value->Data, 72);
    bytes_read += wrapper->Data.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_ADAPTER_DESC3* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_ADAPTER_DESC3* value = wrapper->decoded_value;

    wrapper->Description.SetExternalMemory(value->Description, 128);
    bytes_read += wrapper->Description.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VendorId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SubSysId));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedVideoMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DedicatedSystemMemory));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedSystemMemory));
    wrapper->AdapterLuid = DecodeAllocator::Allocate<Decoded_LUID>();
    wrapper->AdapterLuid->decoded_value = &(value->AdapterLuid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AdapterLuid);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->GraphicsPreemptionGranularity));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComputePreemptionGranularity));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_OUTPUT_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_OUTPUT_DESC1* value = wrapper->decoded_value;

    wrapper->DeviceName.SetExternalMemory(value->DeviceName, 32);
    bytes_read += wrapper->DeviceName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->DesktopCoordinates = DecodeAllocator::Allocate<Decoded_tagRECT>();
    wrapper->DesktopCoordinates->decoded_value = &(value->DesktopCoordinates);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DesktopCoordinates);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AttachedToDesktop));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Rotation));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->Monitor));
    value->Monitor = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BitsPerColor));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ColorSpace));
    wrapper->RedPrimary.SetExternalMemory(value->RedPrimary, 2);
    bytes_read += wrapper->RedPrimary.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->GreenPrimary.SetExternalMemory(value->GreenPrimary, 2);
    bytes_read += wrapper->GreenPrimary.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->BluePrimary.SetExternalMemory(value->BluePrimary, 2);
    bytes_read += wrapper->BluePrimary.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->WhitePoint.SetExternalMemory(value->WhitePoint, 2);
    bytes_read += wrapper->WhitePoint.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxLuminance));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxFullFrameLuminance));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_RATIONAL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_RATIONAL* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Numerator));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Denominator));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_SAMPLE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_SAMPLE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Count));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Quality));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_RGB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_RGB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Red));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Green));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Blue));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3DCOLORVALUE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3DCOLORVALUE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->r));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->g));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->b));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->a));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_GAMMA_CONTROL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_GAMMA_CONTROL* value = wrapper->decoded_value;

    wrapper->Scale = DecodeAllocator::Allocate<Decoded_DXGI_RGB>();
    wrapper->Scale->decoded_value = &(value->Scale);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Scale);
    wrapper->Offset = DecodeAllocator::Allocate<Decoded_DXGI_RGB>();
    wrapper->Offset->decoded_value = &(value->Offset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Offset);
    wrapper->GammaCurve = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_DXGI_RGB>>();
    wrapper->GammaCurve->SetExternalMemory(value->GammaCurve, 1025);
    bytes_read += wrapper->GammaCurve->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_GAMMA_CONTROL_CAPABILITIES* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScaleAndOffsetSupported));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxConvertedValue));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinConvertedValue));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumGammaControlPoints));
    wrapper->ControlPointPositions.SetExternalMemory(value->ControlPointPositions, 1025);
    bytes_read += wrapper->ControlPointPositions.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_MODE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_MODE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    wrapper->RefreshRate = DecodeAllocator::Allocate<Decoded_DXGI_RATIONAL>();
    wrapper->RefreshRate->decoded_value = &(value->RefreshRate);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->RefreshRate);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScanlineOrdering));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Scaling));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_JPEG_DC_HUFFMAN_TABLE* value = wrapper->decoded_value;

    wrapper->CodeCounts.SetExternalMemory(value->CodeCounts, 12);
    bytes_read += wrapper->CodeCounts.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->CodeValues.SetExternalMemory(value->CodeValues, 12);
    bytes_read += wrapper->CodeValues.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_JPEG_AC_HUFFMAN_TABLE* value = wrapper->decoded_value;

    wrapper->CodeCounts.SetExternalMemory(value->CodeCounts, 16);
    bytes_read += wrapper->CodeCounts.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->CodeValues.SetExternalMemory(value->CodeValues, 162);
    bytes_read += wrapper->CodeValues.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_DXGI_JPEG_QUANTIZATION_TABLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    DXGI_JPEG_QUANTIZATION_TABLE* value = wrapper->decoded_value;

    wrapper->Elements.SetExternalMemory(value->Elements, 64);
    bytes_read += wrapper->Elements.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_COMMAND_QUEUE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_COMMAND_QUEUE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Priority));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INPUT_ELEMENT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_INPUT_ELEMENT_DESC* value = wrapper->decoded_value;

    bytes_read += wrapper->SemanticName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->SemanticName = wrapper->SemanticName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SemanticIndex));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InputSlot));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AlignedByteOffset));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->InputSlotClass));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InstanceDataStepRate));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SO_DECLARATION_ENTRY* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SO_DECLARATION_ENTRY* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Stream));
    bytes_read += wrapper->SemanticName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->SemanticName = wrapper->SemanticName.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SemanticIndex));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartComponent));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComponentCount));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->OutputSlot));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VIEWPORT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_VIEWPORT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->TopLeftX));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->TopLeftY));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinDepth));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxDepth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BOX* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BOX* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->left));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->top));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->front));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->right));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bottom));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->back));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCILOP_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCILOP_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilFailOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilDepthFailOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilPassOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilFunc));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCIL_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthWriteMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthFunc));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilEnable));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilReadMask));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilWriteMask));
    wrapper->FrontFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC>();
    wrapper->FrontFace->decoded_value = &(value->FrontFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->FrontFace);
    wrapper->BackFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC>();
    wrapper->BackFace->decoded_value = &(value->BackFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BackFace);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCIL_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthWriteMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthFunc));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilEnable));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilReadMask));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilWriteMask));
    wrapper->FrontFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC>();
    wrapper->FrontFace->decoded_value = &(value->FrontFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->FrontFace);
    wrapper->BackFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC>();
    wrapper->BackFace->decoded_value = &(value->BackFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BackFace);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBoundsTestEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCILOP_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCILOP_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilFailOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilDepthFailOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilPassOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilFunc));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilReadMask));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilWriteMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_DESC2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCIL_DESC2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthWriteMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthFunc));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StencilEnable));
    wrapper->FrontFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC1>();
    wrapper->FrontFace->decoded_value = &(value->FrontFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->FrontFace);
    wrapper->BackFace = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCILOP_DESC1>();
    wrapper->BackFace->decoded_value = &(value->BackFace);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BackFace);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBoundsTestEnable));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_TARGET_BLEND_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_TARGET_BLEND_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BlendEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->LogicOpEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SrcBlend));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DestBlend));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BlendOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SrcBlendAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DestBlendAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BlendOpAlpha));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->LogicOp));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RenderTargetWriteMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BLEND_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BLEND_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AlphaToCoverageEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndependentBlendEnable));
    wrapper->RenderTarget = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_BLEND_DESC>>();
    wrapper->RenderTarget->SetExternalMemory(value->RenderTarget, 8);
    bytes_read += wrapper->RenderTarget->Decode((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RASTERIZER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RASTERIZER_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->FillMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CullMode));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FrontCounterClockwise));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBias));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBiasClamp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlopeScaledDepthBias));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthClipEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MultisampleEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AntialiasedLineEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ForcedSampleCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ConservativeRaster));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RASTERIZER_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RASTERIZER_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->FillMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CullMode));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FrontCounterClockwise));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBias));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBiasClamp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlopeScaledDepthBias));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthClipEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MultisampleEnable));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AntialiasedLineEnable));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ForcedSampleCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ConservativeRaster));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RASTERIZER_DESC2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RASTERIZER_DESC2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->FillMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CullMode));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FrontCounterClockwise));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBias));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBiasClamp));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlopeScaledDepthBias));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthClipEnable));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->LineRasterizationMode));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ForcedSampleCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ConservativeRaster));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SHADER_BYTECODE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SHADER_BYTECODE* value = wrapper->decoded_value;

    bytes_read += wrapper->pShaderBytecode.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pShaderBytecode = wrapper->pShaderBytecode.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BytecodeLength));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STREAM_OUTPUT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_STREAM_OUTPUT_DESC* value = wrapper->decoded_value;

    wrapper->pSODeclaration = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_SO_DECLARATION_ENTRY>>();
    bytes_read += wrapper->pSODeclaration->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSODeclaration = wrapper->pSODeclaration->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumEntries));
    bytes_read += wrapper->pBufferStrides.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferStrides = wrapper->pBufferStrides.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumStrides));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RasterizedStream));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INPUT_LAYOUT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_INPUT_LAYOUT_DESC* value = wrapper->decoded_value;

    wrapper->pInputElementDescs = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_INPUT_ELEMENT_DESC>>();
    bytes_read += wrapper->pInputElementDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pInputElementDescs = wrapper->pInputElementDescs->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumElements));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CACHED_PIPELINE_STATE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_CACHED_PIPELINE_STATE* value = wrapper->decoded_value;

    bytes_read += wrapper->pCachedBlob.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCachedBlob = wrapper->pCachedBlob.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CachedBlobSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GRAPHICS_PIPELINE_STATE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pRootSignature));
    value->pRootSignature = nullptr;
    wrapper->VS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->VS->decoded_value = &(value->VS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->VS);
    wrapper->PS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->PS->decoded_value = &(value->PS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PS);
    wrapper->DS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->DS->decoded_value = &(value->DS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DS);
    wrapper->HS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->HS->decoded_value = &(value->HS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->HS);
    wrapper->GS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->GS->decoded_value = &(value->GS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->GS);
    wrapper->StreamOutput = DecodeAllocator::Allocate<Decoded_D3D12_STREAM_OUTPUT_DESC>();
    wrapper->StreamOutput->decoded_value = &(value->StreamOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->StreamOutput);
    wrapper->BlendState = DecodeAllocator::Allocate<Decoded_D3D12_BLEND_DESC>();
    wrapper->BlendState->decoded_value = &(value->BlendState);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BlendState);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SampleMask));
    wrapper->RasterizerState = DecodeAllocator::Allocate<Decoded_D3D12_RASTERIZER_DESC>();
    wrapper->RasterizerState->decoded_value = &(value->RasterizerState);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->RasterizerState);
    wrapper->DepthStencilState = DecodeAllocator::Allocate<Decoded_D3D12_DEPTH_STENCIL_DESC>();
    wrapper->DepthStencilState->decoded_value = &(value->DepthStencilState);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DepthStencilState);
    wrapper->InputLayout = DecodeAllocator::Allocate<Decoded_D3D12_INPUT_LAYOUT_DESC>();
    wrapper->InputLayout->decoded_value = &(value->InputLayout);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->InputLayout);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->IBStripCutValue));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->PrimitiveTopologyType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumRenderTargets));
    wrapper->RTVFormats.SetExternalMemory(value->RTVFormats, 8);
    bytes_read += wrapper->RTVFormats.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DSVFormat));
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));
    wrapper->CachedPSO = DecodeAllocator::Allocate<Decoded_D3D12_CACHED_PIPELINE_STATE>();
    wrapper->CachedPSO->decoded_value = &(value->CachedPSO);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->CachedPSO);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_COMPUTE_PIPELINE_STATE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pRootSignature));
    value->pRootSignature = nullptr;
    wrapper->CS = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->CS->decoded_value = &(value->CS);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->CS);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));
    wrapper->CachedPSO = DecodeAllocator::Allocate<Decoded_D3D12_CACHED_PIPELINE_STATE>();
    wrapper->CachedPSO->decoded_value = &(value->CachedPSO);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->CachedPSO);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RT_FORMAT_ARRAY* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RT_FORMAT_ARRAY* value = wrapper->decoded_value;

    wrapper->RTFormats.SetExternalMemory(value->RTFormats, 8);
    bytes_read += wrapper->RTFormats.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumRenderTargets));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DoublePrecisionFloatShaderOps));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->OutputMergerLogicOp));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinPrecisionSupport));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->TiledResourcesTier));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceBindingTier));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PSSpecifiedStencilRefSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TypedUAVLoadAdditionalFormats));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ROVsSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ConservativeRasterizationTier));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxGPUVirtualAddressBitsPerResource));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StandardSwizzle64KBSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CrossNodeSharingTier));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CrossAdapterRowMajorTextureSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceHeapTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WaveOps));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WaveLaneCountMin));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WaveLaneCountMax));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TotalLaneCount));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ExpandedComputeResourceStates));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Int64ShaderOps));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthBoundsTestSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ProgrammableSamplePositionsTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_ROOT_SIGNATURE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->HighestVersion));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_ARCHITECTURE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TileBasedRenderer));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UMA));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CacheCoherentUMA));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_ARCHITECTURE1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TileBasedRenderer));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UMA));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CacheCoherentUMA));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IsolatedMMU));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_FEATURE_LEVELS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumFeatureLevels));
    bytes_read += wrapper->pFeatureLevelsRequested.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pFeatureLevelsRequested = wrapper->pFeatureLevelsRequested.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxSupportedFeatureLevel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_SHADER_MODEL* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->HighestShaderModel));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_FORMAT_SUPPORT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Support1));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Support2));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SampleCount));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumQualityLevels));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_FORMAT_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneCount));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxGPUVirtualAddressBitsPerResource));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxGPUVirtualAddressBitsPerProcess));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_SHADER_CACHE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SupportFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CommandListType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Priority));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PriorityForTypeIsSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS3* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CopyQueueTimestampQueriesSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CastingFullyTypedFormatSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->WriteBufferImmediateSupportFlags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewInstancingTier));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BarycentricsSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_EXISTING_HEAPS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Supported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_DISPLAYABLE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DisplayableTexture));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedResourceCompatibilityTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS4* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MSAA64KBAlignedTextureSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharedResourceCompatibilityTier));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Native16BitShaderOpsSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_SERIALIZATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_SERIALIZATION* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->HeapSerializationTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_CROSS_NODE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_CROSS_NODE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SharingTier));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AtomicShaderInstructions));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS5* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SRVOnlyTiledResourceTier3));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RenderPassesTier));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RaytracingTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS6* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdditionalShadingRatesSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PerPrimitiveShadingRateSupportedWithViewportIndexing));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->VariableShadingRateTier));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShadingRateImageTileSize));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BackgroundProcessingSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS7* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MeshShaderTier));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SamplerFeedbackTier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_QUERY_META_COMMAND* value = wrapper->decoded_value;

    wrapper->CommandId = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->CommandId->decoded_value = &(value->CommandId);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->CommandId);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));
    bytes_read += wrapper->pQueryInputData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueryInputData = wrapper->pQueryInputData.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->QueryInputDataSizeInBytes));
    bytes_read += wrapper->pQueryOutputData.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pQueryOutputData = wrapper->pQueryOutputData.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->QueryOutputDataSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS8* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnalignedBlockTexturesSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS9* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MeshShaderPipelineStatsSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MeshShaderSupportsFullRangeRenderTargetArrayIndex));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AtomicInt64OnTypedResourceSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AtomicInt64OnGroupSharedSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DerivativesInMeshAndAmplificationShadersSupported));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->WaveMMATier));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS10* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VariableRateShadingSumCombinerSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MeshShaderPerPrimitiveShadingRateSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS11* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AtomicInt64OnDescriptorHeapResourceSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS12* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MSPrimitivesPipelineStatisticIncludesCulledPrimitives));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->EnhancedBarriersSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RelaxedFormatCastingSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS13* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnrestrictedBufferTextureCopyPitchSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnrestrictedVertexElementAlignmentSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InvertedViewportHeightFlipsYSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InvertedViewportDepthFlipsZSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TextureCopyBetweenDimensionsSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AlphaBlendFactorSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS14* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdvancedTextureOpsSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WriteableMSAATexturesSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndependentFrontAndBackStencilRefMaskSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS15* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->TriangleFanSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DynamicIndexBufferStripCutSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS16* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DynamicDepthBiasSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GPUUploadHeapSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS17* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NonNormalizedCoordinateSamplersSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ManualWriteTrackingResourceSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS18* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RenderPassesValid));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_D3D12_OPTIONS19* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MismatchingOutputDimensionsSupported));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SupportedSampleCountsWithNoOutputs));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PointSamplingAddressesNeverRoundUp));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RasterizerDesc2Supported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NarrowQuadrilateralLinesSupported));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AnisoFilterWithPointMipSupported));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxSamplerDescriptorHeapSize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxSamplerDescriptorHeapSizeWithStaticSamplers));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxViewDescriptorHeapSize));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComputeOnlyCustomHeapSupported));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_ALLOCATION_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_ALLOCATION_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Alignment));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_ALLOCATION_INFO1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Offset));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Alignment));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_HEAP_PROPERTIES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_HEAP_PROPERTIES* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->CPUPageProperty));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MemoryPoolPreference));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CreationNodeMask));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VisibleNodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_HEAP_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_HEAP_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    wrapper->Properties = DecodeAllocator::Allocate<Decoded_D3D12_HEAP_PROPERTIES>();
    wrapper->Properties->decoded_value = &(value->Properties);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Properties);
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Alignment));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_MIP_REGION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_MIP_REGION* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Dimension));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Alignment));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthOrArraySize));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Layout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Dimension));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Alignment));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthOrArraySize));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    wrapper->SampleDesc = DecodeAllocator::Allocate<Decoded_DXGI_SAMPLE_DESC>();
    wrapper->SampleDesc->decoded_value = &(value->SampleDesc);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SampleDesc);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Layout));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    wrapper->SamplerFeedbackMipRegion = DecodeAllocator::Allocate<Decoded_D3D12_MIP_REGION>();
    wrapper->SamplerFeedbackMipRegion->decoded_value = &(value->SamplerFeedbackMipRegion);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SamplerFeedbackMipRegion);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_VALUE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEPTH_STENCIL_VALUE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Depth));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Stencil));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RANGE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RANGE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Begin));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->End));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RANGE_UINT64* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RANGE_UINT64* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Begin));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->End));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SUBRESOURCE_RANGE_UINT64* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Subresource));
    wrapper->Range = DecodeAllocator::Allocate<Decoded_D3D12_RANGE_UINT64>();
    wrapper->Range->decoded_value = &(value->Range);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Range);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBRESOURCE_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SUBRESOURCE_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Offset));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RowPitch));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthPitch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TILED_RESOURCE_COORDINATE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TILED_RESOURCE_COORDINATE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->X));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Y));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Z));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Subresource));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TILE_REGION_SIZE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TILE_REGION_SIZE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumTiles));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UseBox));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBRESOURCE_TILING* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SUBRESOURCE_TILING* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WidthInTiles));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->HeightInTiles));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthInTiles));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartTileIndexInOverallResource));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TILE_SHAPE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TILE_SHAPE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WidthInTexels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->HeightInTexels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DepthInTexels));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PACKED_MIP_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_PACKED_MIP_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumStandardMips));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumPackedMips));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumTilesForPackedMips));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartTileIndexInOverallResource));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_TRANSITION_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResource));
    value->pResource = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Subresource));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StateBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->StateAfter));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_ALIASING_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_ALIASING_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResourceBefore));
    value->pResourceBefore = nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResourceAfter));
    value->pResourceAfter = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_UAV_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RESOURCE_UAV_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResource));
    value->pResource = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBRESOURCE_FOOTPRINT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SUBRESOURCE_FOOTPRINT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Depth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RowPitch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Offset));
    wrapper->Footprint = DecodeAllocator::Allocate<Decoded_D3D12_SUBRESOURCE_FOOTPRINT>();
    wrapper->Footprint->decoded_value = &(value->Footprint);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Footprint);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SAMPLE_POSITION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SAMPLE_POSITION* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->X));
    bytes_read += ValueDecoder::DecodeInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VIEW_INSTANCE_LOCATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_VIEW_INSTANCE_LOCATION* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewportArrayIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RenderTargetArrayIndex));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VIEW_INSTANCING_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_VIEW_INSTANCING_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewInstanceCount));
    wrapper->pViewInstanceLocations = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_VIEW_INSTANCE_LOCATION>>();
    bytes_read += wrapper->pViewInstanceLocations->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pViewInstanceLocations = wrapper->pViewInstanceLocations->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUFFER_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUFFER_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumElements));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StructureByteStride));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_ARRAY_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_ARRAY_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_ARRAY_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_ARRAY_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX3D_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX3D_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXCUBE_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEXCUBE_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXCUBE_ARRAY_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEXCUBE_ARRAY_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MostDetailedMip));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->First2DArrayFace));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumCubes));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResourceMinLODClamp));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnusedField_NothingToDefine));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_ARRAY_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_ARRAY_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Location));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_CONSTANT_BUFFER_VIEW_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferLocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SAMPLER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SAMPLER_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Filter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressU));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressV));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressW));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLODBias));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxAnisotropy));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComparisonFunc));
    wrapper->BorderColor.SetExternalMemory(value->BorderColor, 4);
    bytes_read += wrapper->BorderColor.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinLOD));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxLOD));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUFFER_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUFFER_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumElements));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StructureByteStride));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CounterOffsetInBytes));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_ARRAY_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_ARRAY_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_ARRAY_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_ARRAY_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnusedField_NothingToDefine));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_ARRAY_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_ARRAY_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX3D_UAV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX3D_UAV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstWSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUFFER_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUFFER_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstElement));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumElements));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_ARRAY_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_ARRAY_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnusedField_NothingToDefine));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_ARRAY_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_ARRAY_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PlaneSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_ARRAY_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_ARRAY_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX3D_RTV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX3D_RTV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstWSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->WSize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX1D_ARRAY_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX1D_ARRAY_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2D_ARRAY_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2D_ARRAY_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipSlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UnusedField_NothingToDefine));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEX2DMS_ARRAY_DSV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEX2DMS_ARRAY_DSV* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ArraySize));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DESCRIPTOR_HEAP_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DESCRIPTOR_HEAP_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescriptors));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DESCRIPTOR_RANGE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DESCRIPTOR_RANGE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RangeType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescriptors));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BaseShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->OffsetInDescriptorsFromTableStart));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_DESCRIPTOR_TABLE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescriptorRanges));
    wrapper->pDescriptorRanges = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_RANGE>>();
    bytes_read += wrapper->pDescriptorRanges->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorRanges = wrapper->pDescriptorRanges->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_CONSTANTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_CONSTANTS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Num32BitValues));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_DESCRIPTOR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_DESCRIPTOR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATIC_SAMPLER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_STATIC_SAMPLER_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Filter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressU));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressV));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressW));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLODBias));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxAnisotropy));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComparisonFunc));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BorderColor));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinLOD));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxLOD));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATIC_SAMPLER_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_STATIC_SAMPLER_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Filter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressU));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressV));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressW));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLODBias));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxAnisotropy));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComparisonFunc));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->BorderColor));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinLOD));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxLOD));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_SIGNATURE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_SIGNATURE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumParameters));
    wrapper->pParameters = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER>>();
    bytes_read += wrapper->pParameters->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pParameters = wrapper->pParameters->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumStaticSamplers));
    wrapper->pStaticSamplers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC>>();
    bytes_read += wrapper->pStaticSamplers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStaticSamplers = wrapper->pStaticSamplers->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DESCRIPTOR_RANGE1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DESCRIPTOR_RANGE1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RangeType));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescriptors));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BaseShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->OffsetInDescriptorsFromTableStart));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_DESCRIPTOR_TABLE1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescriptorRanges));
    wrapper->pDescriptorRanges = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_RANGE1>>();
    bytes_read += wrapper->pDescriptorRanges->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescriptorRanges = wrapper->pDescriptorRanges->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_DESCRIPTOR1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_DESCRIPTOR1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderRegister));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->RegisterSpace));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_SIGNATURE_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_SIGNATURE_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumParameters));
    wrapper->pParameters = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER1>>();
    bytes_read += wrapper->pParameters->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pParameters = wrapper->pParameters->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumStaticSamplers));
    wrapper->pStaticSamplers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC>>();
    bytes_read += wrapper->pStaticSamplers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStaticSamplers = wrapper->pStaticSamplers->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_SIGNATURE_DESC2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_ROOT_SIGNATURE_DESC2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumParameters));
    wrapper->pParameters = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER1>>();
    bytes_read += wrapper->pParameters->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pParameters = wrapper->pParameters->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumStaticSamplers));
    wrapper->pStaticSamplers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC1>>();
    bytes_read += wrapper->pStaticSamplers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pStaticSamplers = wrapper->pStaticSamplers->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GPU_DESCRIPTOR_HANDLE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ptr));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DISCARD_REGION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DISCARD_REGION* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumRects));
    wrapper->pRects = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_tagRECT>>();
    bytes_read += wrapper->pRects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRects = wrapper->pRects->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstSubresource));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumSubresources));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_QUERY_HEAP_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_QUERY_HEAP_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Count));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_QUERY_DATA_PIPELINE_STATISTICS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IAVertices));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IAPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GSPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->HSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CSInvocations));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_QUERY_DATA_PIPELINE_STATISTICS1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IAVertices));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IAPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GSPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CPrimitives));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->HSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ASInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MSInvocations));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MSPrimitives));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_QUERY_DATA_SO_STATISTICS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_QUERY_DATA_SO_STATISTICS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumPrimitivesWritten));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PrimitivesStorageNeeded));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_STREAM_OUTPUT_BUFFER_VIEW* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferLocation));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferFilledSizeLocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRAW_ARGUMENTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRAW_ARGUMENTS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VertexCountPerInstance));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InstanceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartVertexLocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartInstanceLocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRAW_INDEXED_ARGUMENTS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndexCountPerInstance));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->InstanceCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartIndexLocation));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BaseVertexLocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartInstanceLocation));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DISPATCH_ARGUMENTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DISPATCH_ARGUMENTS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountX));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountY));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERTEX_BUFFER_VIEW* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_VERTEX_BUFFER_VIEW* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferLocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StrideInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INDEX_BUFFER_VIEW* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_INDEX_BUFFER_VIEW* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BufferLocation));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_COMMAND_SIGNATURE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_COMMAND_SIGNATURE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ByteStride));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumArgumentDescs));
    wrapper->pArgumentDescs = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_INDIRECT_ARGUMENT_DESC>>();
    bytes_read += wrapper->pArgumentDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pArgumentDescs = wrapper->pArgumentDescs->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Dest));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Value));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Support));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_PROTECTED_RESOURCE_SESSION_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_META_COMMAND_PARAMETER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_META_COMMAND_PARAMETER_DESC* value = wrapper->decoded_value;

    bytes_read += wrapper->Name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Name = wrapper->Name.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RequiredResourceState));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StructureOffset));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_META_COMMAND_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_META_COMMAND_DESC* value = wrapper->decoded_value;

    wrapper->Id = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->Id->decoded_value = &(value->Id);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Id);
    bytes_read += wrapper->Name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Name = wrapper->Name.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->InitializationDirtyState));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ExecutionDirtyState));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATE_OBJECT_CONFIG* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_STATE_OBJECT_CONFIG* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GLOBAL_ROOT_SIGNATURE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pGlobalRootSignature));
    value->pGlobalRootSignature = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_LOCAL_ROOT_SIGNATURE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_LOCAL_ROOT_SIGNATURE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pLocalRootSignature));
    value->pLocalRootSignature = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_NODE_MASK* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_NODE_MASK* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_EXPORT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_EXPORT_DESC* value = wrapper->decoded_value;

    bytes_read += wrapper->Name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Name = wrapper->Name.GetPointer();
    bytes_read += wrapper->ExportToRename.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ExportToRename = wrapper->ExportToRename.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DXIL_LIBRARY_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DXIL_LIBRARY_DESC* value = wrapper->decoded_value;

    wrapper->DXILLibrary = DecodeAllocator::Allocate<Decoded_D3D12_SHADER_BYTECODE>();
    wrapper->DXILLibrary->decoded_value = &(value->DXILLibrary);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DXILLibrary);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumExports));
    wrapper->pExports = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_EXPORT_DESC>>();
    bytes_read += wrapper->pExports->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pExports = wrapper->pExports->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_EXISTING_COLLECTION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_EXISTING_COLLECTION_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pExistingCollection));
    value->pExistingCollection = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumExports));
    wrapper->pExports = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_EXPORT_DESC>>();
    bytes_read += wrapper->pExports->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pExports = wrapper->pExports->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value = wrapper->decoded_value;

    bytes_read += wrapper->SubobjectToAssociate.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->SubobjectToAssociate = wrapper->SubobjectToAssociate.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumExports));
    bytes_read += wrapper->pExports.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pExports = const_cast<LPCWSTR*>(wrapper->pExports.GetPointer());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_HIT_GROUP_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_HIT_GROUP_DESC* value = wrapper->decoded_value;

    bytes_read += wrapper->HitGroupExport.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->HitGroupExport = wrapper->HitGroupExport.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += wrapper->AnyHitShaderImport.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->AnyHitShaderImport = wrapper->AnyHitShaderImport.GetPointer();
    bytes_read += wrapper->ClosestHitShaderImport.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ClosestHitShaderImport = wrapper->ClosestHitShaderImport.GetPointer();
    bytes_read += wrapper->IntersectionShaderImport.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->IntersectionShaderImport = wrapper->IntersectionShaderImport.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_SHADER_CONFIG* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_SHADER_CONFIG* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxPayloadSizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxAttributeSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_PIPELINE_CONFIG* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxTraceRecursionDepth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_PIPELINE_CONFIG1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxTraceRecursionDepth));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartAddress));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StrideInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartAddress));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StartAddress));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->StrideInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Transform3x4));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndexFormat));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->VertexFormat));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndexCount));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->VertexCount));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndexBuffer));
    wrapper->VertexBuffer = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE>();
    wrapper->VertexBuffer->decoded_value = &(value->VertexBuffer);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->VertexBuffer);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_AABB* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_AABB* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinX));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinY));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinZ));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxX));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxY));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AABBCount));
    wrapper->AABBs = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE>();
    wrapper->AABBs->decoded_value = &(value->AABBs);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AABBs);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DestBuffer));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->InfoType));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CompactedSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DecodedSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescs));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SerializedSizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumBottomLevelAccelerationStructurePointers));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* value = wrapper->decoded_value;

    wrapper->DriverOpaqueGUID = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->DriverOpaqueGUID->decoded_value = &(value->DriverOpaqueGUID);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DriverOpaqueGUID);
    wrapper->DriverOpaqueVersioningData.SetExternalMemory(value->DriverOpaqueVersioningData, 16);
    bytes_read += wrapper->DriverOpaqueVersioningData.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* value = wrapper->decoded_value;

    wrapper->DriverMatchingIdentifier = DecodeAllocator::Allocate<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>();
    wrapper->DriverMatchingIdentifier->decoded_value = &(value->DriverMatchingIdentifier);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DriverMatchingIdentifier);
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SerializedSizeInBytesIncludingHeader));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeserializedSizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumBottomLevelAccelerationStructurePointersAfterHeader));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->CurrentSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_INSTANCE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_INSTANCE_DESC* value = wrapper->decoded_value;

    wrapper->Transform.SetExternalMemory(*value->Transform, 12);
    bytes_read += wrapper->Transform.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));
    UINT temp_InstanceID;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &temp_InstanceID);
    value->InstanceID = temp_InstanceID;
    UINT temp_InstanceMask;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &temp_InstanceMask);
    value->InstanceMask = temp_InstanceMask;
    UINT temp_InstanceContributionToHitGroupIndex;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &temp_InstanceContributionToHitGroupIndex);
    value->InstanceContributionToHitGroupIndex = temp_InstanceContributionToHitGroupIndex;
    UINT temp_Flags;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &temp_Flags);
    value->Flags = temp_Flags;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccelerationStructure));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DestAccelerationStructureData));
    wrapper->Inputs = DecodeAllocator::Allocate<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>();
    wrapper->Inputs->decoded_value = &(value->Inputs);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Inputs);
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SourceAccelerationStructureData));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScratchAccelerationStructureData));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResultDataMaxSizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ScratchDataSizeInBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->UpdateScratchDataSizeInBytes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_AUTO_BREADCRUMB_NODE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_AUTO_BREADCRUMB_NODE* value = wrapper->decoded_value;

    bytes_read += wrapper->pCommandListDebugNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandListDebugNameA = wrapper->pCommandListDebugNameA.GetPointer();
    bytes_read += wrapper->pCommandListDebugNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandListDebugNameW = wrapper->pCommandListDebugNameW.GetPointer();
    bytes_read += wrapper->pCommandQueueDebugNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandQueueDebugNameA = wrapper->pCommandQueueDebugNameA.GetPointer();
    bytes_read += wrapper->pCommandQueueDebugNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandQueueDebugNameW = wrapper->pCommandQueueDebugNameW.GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pCommandList));
    value->pCommandList = nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pCommandQueue));
    value->pCommandQueue = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BreadcrumbCount));
    bytes_read += wrapper->pLastBreadcrumbValue.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pLastBreadcrumbValue = wrapper->pLastBreadcrumbValue.GetPointer();
    bytes_read += wrapper->pCommandHistory.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandHistory = wrapper->pCommandHistory.GetPointer();
    wrapper->pNext = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>>();
    bytes_read += wrapper->pNext->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pNext = wrapper->pNext->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_BREADCRUMB_CONTEXT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BreadcrumbIndex));
    bytes_read += wrapper->pContextString.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pContextString = wrapper->pContextString.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_AUTO_BREADCRUMB_NODE1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_AUTO_BREADCRUMB_NODE1* value = wrapper->decoded_value;

    bytes_read += wrapper->pCommandListDebugNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandListDebugNameA = wrapper->pCommandListDebugNameA.GetPointer();
    bytes_read += wrapper->pCommandListDebugNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandListDebugNameW = wrapper->pCommandListDebugNameW.GetPointer();
    bytes_read += wrapper->pCommandQueueDebugNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandQueueDebugNameA = wrapper->pCommandQueueDebugNameA.GetPointer();
    bytes_read += wrapper->pCommandQueueDebugNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandQueueDebugNameW = wrapper->pCommandQueueDebugNameW.GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pCommandList));
    value->pCommandList = nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pCommandQueue));
    value->pCommandQueue = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BreadcrumbCount));
    bytes_read += wrapper->pLastBreadcrumbValue.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));
    value->pLastBreadcrumbValue = wrapper->pLastBreadcrumbValue.GetPointer();
    bytes_read += wrapper->pCommandHistory.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCommandHistory = wrapper->pCommandHistory.GetPointer();
    wrapper->pNext = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>>();
    bytes_read += wrapper->pNext->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->BreadcrumbContextsCount));
    wrapper->pBreadcrumbContexts = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_BREADCRUMB_CONTEXT>>();
    bytes_read += wrapper->pBreadcrumbContexts->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBreadcrumbContexts = wrapper->pBreadcrumbContexts->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEVICE_REMOVED_EXTENDED_DATA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    wrapper->pHeadAutoBreadcrumbNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>>();
    bytes_read += wrapper->pHeadAutoBreadcrumbNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadAutoBreadcrumbNode = wrapper->pHeadAutoBreadcrumbNode->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_ALLOCATION_NODE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_ALLOCATION_NODE* value = wrapper->decoded_value;

    bytes_read += wrapper->ObjectNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ObjectNameA = wrapper->ObjectNameA.GetPointer();
    bytes_read += wrapper->ObjectNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ObjectNameW = wrapper->ObjectNameW.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AllocationType));
    wrapper->pNext = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>>();
    bytes_read += wrapper->pNext->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pNext = wrapper->pNext->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_ALLOCATION_NODE1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_ALLOCATION_NODE1* value = wrapper->decoded_value;

    bytes_read += wrapper->ObjectNameA.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ObjectNameA = wrapper->ObjectNameA.GetPointer();
    bytes_read += wrapper->ObjectNameW.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->ObjectNameW = wrapper->ObjectNameW.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AllocationType));
    wrapper->pNext = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>>();
    bytes_read += wrapper->pNext->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pNext = wrapper->pNext->GetPointer();
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pObject));
    value->pObject = nullptr;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* value = wrapper->decoded_value;

    wrapper->pHeadAutoBreadcrumbNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>>();
    bytes_read += wrapper->pHeadAutoBreadcrumbNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadAutoBreadcrumbNode = wrapper->pHeadAutoBreadcrumbNode->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* value = wrapper->decoded_value;

    wrapper->pHeadAutoBreadcrumbNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>>();
    bytes_read += wrapper->pHeadAutoBreadcrumbNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadAutoBreadcrumbNode = wrapper->pHeadAutoBreadcrumbNode->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_PAGE_FAULT_OUTPUT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PageFaultVA));
    wrapper->pHeadExistingAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>>();
    bytes_read += wrapper->pHeadExistingAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadExistingAllocationNode = wrapper->pHeadExistingAllocationNode->GetPointer();
    wrapper->pHeadRecentFreedAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>>();
    bytes_read += wrapper->pHeadRecentFreedAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadRecentFreedAllocationNode = wrapper->pHeadRecentFreedAllocationNode->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_PAGE_FAULT_OUTPUT1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PageFaultVA));
    wrapper->pHeadExistingAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>>();
    bytes_read += wrapper->pHeadExistingAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadExistingAllocationNode = wrapper->pHeadExistingAllocationNode->GetPointer();
    wrapper->pHeadRecentFreedAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>>();
    bytes_read += wrapper->pHeadRecentFreedAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadRecentFreedAllocationNode = wrapper->pHeadRecentFreedAllocationNode->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DRED_PAGE_FAULT_OUTPUT2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PageFaultVA));
    wrapper->pHeadExistingAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>>();
    bytes_read += wrapper->pHeadExistingAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadExistingAllocationNode = wrapper->pHeadExistingAllocationNode->GetPointer();
    wrapper->pHeadRecentFreedAllocationNode = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>>();
    bytes_read += wrapper->pHeadRecentFreedAllocationNode->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHeadRecentFreedAllocationNode = wrapper->pHeadRecentFreedAllocationNode->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->PageFaultFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEVICE_REMOVED_EXTENDED_DATA1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceRemovedReason));
    wrapper->AutoBreadcrumbsOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>();
    wrapper->AutoBreadcrumbsOutput->decoded_value = &(value->AutoBreadcrumbsOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AutoBreadcrumbsOutput);
    wrapper->PageFaultOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>();
    wrapper->PageFaultOutput->decoded_value = &(value->PageFaultOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PageFaultOutput);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEVICE_REMOVED_EXTENDED_DATA2* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceRemovedReason));
    wrapper->AutoBreadcrumbsOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>();
    wrapper->AutoBreadcrumbsOutput->decoded_value = &(value->AutoBreadcrumbsOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AutoBreadcrumbsOutput);
    wrapper->PageFaultOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>();
    wrapper->PageFaultOutput->decoded_value = &(value->PageFaultOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PageFaultOutput);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEVICE_REMOVED_EXTENDED_DATA3* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceRemovedReason));
    wrapper->AutoBreadcrumbsOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>();
    wrapper->AutoBreadcrumbsOutput->decoded_value = &(value->AutoBreadcrumbsOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AutoBreadcrumbsOutput);
    wrapper->PageFaultOutput = DecodeAllocator::Allocate<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>();
    wrapper->PageFaultOutput->decoded_value = &(value->PageFaultOutput);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PageFaultOutput);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DeviceState));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Count));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Count));
    wrapper->pTypes = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_GUID>>();
    bytes_read += wrapper->pTypes->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTypes = wrapper->pTypes->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NodeMask));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    wrapper->ProtectionType = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->ProtectionType->decoded_value = &(value->ProtectionType);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->ProtectionType);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* value = wrapper->decoded_value;

    wrapper->ClearValue = DecodeAllocator::Allocate<Decoded_D3D12_CLEAR_VALUE>();
    wrapper->ClearValue->decoded_value = &(value->ClearValue);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->ClearValue);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdditionalWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdditionalHeight));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SrcSubresource));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DstSubresource));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DstX));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->DstY));
    wrapper->SrcRect = DecodeAllocator::Allocate<Decoded_tagRECT>();
    wrapper->SrcRect->decoded_value = &(value->SrcRect);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->SrcRect);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pSrcResource));
    value->pSrcResource = nullptr;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pDstResource));
    value->pDstResource = nullptr;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SubresourceCount));
    wrapper->pSubresourceParameters = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS>>();
    bytes_read += wrapper->pSubresourceParameters->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubresourceParameters = wrapper->pSubresourceParameters->GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ResolveMode));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->PreserveResolveSource));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdditionalWidth));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AdditionalHeight));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_RENDER_TARGET_DESC* value = wrapper->decoded_value;

    wrapper->cpuDescriptor = DecodeAllocator::Allocate<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>();
    wrapper->cpuDescriptor->decoded_value = &(value->cpuDescriptor);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->cpuDescriptor);
    wrapper->BeginningAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS>();
    wrapper->BeginningAccess->decoded_value = &(value->BeginningAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->BeginningAccess);
    wrapper->EndingAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS>();
    wrapper->EndingAccess->decoded_value = &(value->EndingAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->EndingAccess);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* value = wrapper->decoded_value;

    wrapper->cpuDescriptor = DecodeAllocator::Allocate<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>();
    wrapper->cpuDescriptor->decoded_value = &(value->cpuDescriptor);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->cpuDescriptor);
    wrapper->DepthBeginningAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS>();
    wrapper->DepthBeginningAccess->decoded_value = &(value->DepthBeginningAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DepthBeginningAccess);
    wrapper->StencilBeginningAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS>();
    wrapper->StencilBeginningAccess->decoded_value = &(value->StencilBeginningAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->StencilBeginningAccess);
    wrapper->DepthEndingAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS>();
    wrapper->DepthEndingAccess->decoded_value = &(value->DepthEndingAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DepthEndingAccess);
    wrapper->StencilEndingAccess = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS>();
    wrapper->StencilEndingAccess->decoded_value = &(value->StencilEndingAccess);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->StencilEndingAccess);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DISPATCH_RAYS_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DISPATCH_RAYS_DESC* value = wrapper->decoded_value;

    wrapper->RayGenerationShaderRecord = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE>();
    wrapper->RayGenerationShaderRecord->decoded_value = &(value->RayGenerationShaderRecord);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->RayGenerationShaderRecord);
    wrapper->MissShaderTable = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>();
    wrapper->MissShaderTable->decoded_value = &(value->MissShaderTable);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->MissShaderTable);
    wrapper->HitGroupTable = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>();
    wrapper->HitGroupTable->decoded_value = &(value->HitGroupTable);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->HitGroupTable);
    wrapper->CallableShaderTable = DecodeAllocator::Allocate<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>();
    wrapper->CallableShaderTable->decoded_value = &(value->CallableShaderTable);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->CallableShaderTable);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Width));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Height));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Depth));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SHADER_CACHE_SESSION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SHADER_CACHE_SESSION_DESC* value = wrapper->decoded_value;

    wrapper->Identifier = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->Identifier->decoded_value = &(value->Identifier);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Identifier);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Mode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaximumInMemoryCacheSizeBytes));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaximumInMemoryCacheEntries));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaximumValueFileSizeBytes));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Version));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BARRIER_SUBRESOURCE_RANGE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->IndexOrFirstMipLevel));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumMipLevels));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstArraySlice));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumArraySlices));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->FirstPlane));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumPlanes));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_GLOBAL_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_GLOBAL_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncAfter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessAfter));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXTURE_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_TEXTURE_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncAfter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessAfter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->LayoutBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->LayoutAfter));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResource));
    value->pResource = nullptr;
    wrapper->Subresources = DecodeAllocator::Allocate<Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE>();
    wrapper->Subresources->decoded_value = &(value->Subresources);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Subresources);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUFFER_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_BUFFER_BARRIER* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SyncAfter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessBefore));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AccessAfter));
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResource));
    value->pResource = nullptr;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Offset));
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Size));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBRESOURCE_DATA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_SUBRESOURCE_DATA* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pData));
    value->pData = nullptr;
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RowPitch));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlicePitch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_MEMCPY_DEST* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_MEMCPY_DEST* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pData));
    value->pData = nullptr;
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->RowPitch));
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlicePitch));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEVICE_CONFIGURATION_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEVICE_CONFIGURATION_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->GpuBasedValidationFlags));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->SDKVersion));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumEnabledExperimentalFeatures));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DISPATCH_MESH_ARGUMENTS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountX));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountY));
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->ThreadGroupCountZ));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D_SHADER_MACRO* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D_SHADER_MACRO* value = wrapper->decoded_value;

    bytes_read += wrapper->Name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Name = wrapper->Name.GetPointer();
    bytes_read += wrapper->Definition.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Definition = wrapper->Definition.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxMessagesPerCommandList));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DefaultShaderPatchMode));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->PipelineStateCreateFlags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SlowdownFactor));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderPatchMode));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_MESSAGE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_MESSAGE* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Category));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Severity));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ID));
    bytes_read += wrapper->pDescription.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pDescription = wrapper->pDescription.GetPointer();
    bytes_read += ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DescriptionByteLength));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INFO_QUEUE_FILTER_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_INFO_QUEUE_FILTER_DESC* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumCategories));
    bytes_read += wrapper->pCategoryList.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pCategoryList = wrapper->pCategoryList.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumSeverities));
    bytes_read += wrapper->pSeverityList.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSeverityList = wrapper->pSeverityList.GetPointer();
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumIDs));
    bytes_read += wrapper->pIDList.DecodeEnum((buffer + bytes_read), (buffer_size - bytes_read));
    value->pIDList = wrapper->pIDList.GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INFO_QUEUE_FILTER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    D3D12_INFO_QUEUE_FILTER* value = wrapper->decoded_value;

    wrapper->AllowList = DecodeAllocator::Allocate<Decoded_D3D12_INFO_QUEUE_FILTER_DESC>();
    wrapper->AllowList->decoded_value = &(value->AllowList);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AllowList);
    wrapper->DenyList = DecodeAllocator::Allocate<Decoded_D3D12_INFO_QUEUE_FILTER_DESC>();
    wrapper->DenyList->decoded_value = &(value->DenyList);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DenyList);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_GUID* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    GUID* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Data1));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Data2));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Data3));
    wrapper->Data4.SetExternalMemory(value->Data4, 8);
    bytes_read += wrapper->Data4.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_tagRECT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    tagRECT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->left));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->top));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->right));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bottom));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_tagPOINT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    tagPOINT* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->x));
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->y));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded__SECURITY_ATTRIBUTES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    _SECURITY_ATTRIBUTES* value = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->nLength));
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->lpSecurityDescriptor));
    value->lpSecurityDescriptor = nullptr;
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bInheritHandle));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
