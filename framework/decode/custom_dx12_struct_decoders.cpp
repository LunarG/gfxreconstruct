/*
** Copyright (c) 2021 LunarG, Inc.
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
#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "custom_dx12_struct_decoders.h"

#include "format/dx12_subobject_types.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
size_t DecodeDescriptorStruct(const uint8_t* buffer, size_t buffer_size, T* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    typename T::struct_type* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->heap_id));
    value->ptr = 0;

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->index));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* wrapper)
{
    return DecodeDescriptorStruct(buffer, buffer_size, wrapper);
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CLEAR_VALUE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t             bytes_read = 0;
    D3D12_CLEAR_VALUE* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));

    wrapper->Color.SetExternalMemory(value->Color, 4);
    bytes_read += wrapper->Color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                  bytes_read = 0;
    D3D12_RESOURCE_BARRIER* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->Type)
    {
        case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            wrapper->Transition                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>();
            wrapper->Transition->decoded_value = &(value->Transition);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Transition);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            wrapper->Aliasing                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>();
            wrapper->Aliasing->decoded_value = &(value->Aliasing);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Aliasing);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            wrapper->UAV                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_UAV_BARRIER>();
            wrapper->UAV->decoded_value = &(value->UAV);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->UAV);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXTURE_COPY_LOCATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                       bytes_read = 0;
    D3D12_TEXTURE_COPY_LOCATION* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pResource));
    value->pResource = nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    switch (value->Type)
    {
        case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            bytes_read += ValueDecoder::DecodeUInt32Value(
                (buffer + bytes_read), (buffer_size - bytes_read), &(value->SubresourceIndex));
            break;
        case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            wrapper->PlacedFootprint = DecodeAllocator::Allocate<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>();
            wrapper->PlacedFootprint->decoded_value = &(value->PlacedFootprint);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PlacedFootprint);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                           bytes_read = 0;
    D3D12_SHADER_RESOURCE_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Shader4ComponentMapping));

    switch (value->ViewDimension)
    {
        case D3D12_SRV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_SRV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_SRV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_SRV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_SRV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_SRV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_SRV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_SRV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_SRV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBE:
            wrapper->TextureCube                = DecodeAllocator::Allocate<Decoded_D3D12_TEXCUBE_SRV>();
            wrapper->TextureCube->decoded_value = &(value->TextureCube);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->TextureCube);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            wrapper->TextureCubeArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEXCUBE_ARRAY_SRV>();
            wrapper->TextureCubeArray->decoded_value = &(value->TextureCubeArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->TextureCubeArray);
            break;
        case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            wrapper->RaytracingAccelerationStructure =
                DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV>();
            wrapper->RaytracingAccelerationStructure->decoded_value = &(value->RaytracingAccelerationStructure);
            bytes_read += DecodeStruct(
                (buffer + bytes_read), (buffer_size - bytes_read), wrapper->RaytracingAccelerationStructure);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                            bytes_read = 0;
    D3D12_UNORDERED_ACCESS_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));

    switch (value->ViewDimension)
    {
        case D3D12_UAV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_UAV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_UAV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_UAV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_UAV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_UAV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_UAV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_UAV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_UAV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_TARGET_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    D3D12_RENDER_TARGET_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));

    switch (value->ViewDimension)
    {
        case D3D12_RTV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_RTV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_RTV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_RTV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_RTV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_RTV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_RTV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_RTV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_RTV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    D3D12_DEPTH_STENCIL_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->ViewDimension)
    {
        case D3D12_DSV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_DSV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_DSV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_DSV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_DSV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_DSV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_DSV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                bytes_read = 0;
    D3D12_ROOT_PARAMETER* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ParameterType));

    switch (value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            wrapper->DescriptorTable                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR_TABLE>();
            wrapper->DescriptorTable->decoded_value = &(value->DescriptorTable);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            wrapper->Constants                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_CONSTANTS>();
            wrapper->Constants->decoded_value = &(value->Constants);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            wrapper->Descriptor                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR>();
            wrapper->Descriptor->decoded_value = &(value->Descriptor);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Descriptor);
            break;
    }

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                 bytes_read = 0;
    D3D12_ROOT_PARAMETER1* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ParameterType));

    switch (value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            wrapper->DescriptorTable                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1>();
            wrapper->DescriptorTable->decoded_value = &(value->DescriptorTable);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            wrapper->Constants                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_CONSTANTS>();
            wrapper->Constants->decoded_value = &(value->Constants);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            wrapper->Descriptor                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR1>();
            wrapper->Descriptor->decoded_value = &(value->Descriptor);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Descriptor);
            break;
    }

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                               bytes_read = 0;
    D3D12_VERSIONED_ROOT_SIGNATURE_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Version));

    switch (value->Version)
    {
        case D3D_ROOT_SIGNATURE_VERSION_1_0:
            wrapper->Desc_1_0                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_SIGNATURE_DESC>();
            wrapper->Desc_1_0->decoded_value = &(value->Desc_1_0);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Desc_1_0);
            break;
        case D3D_ROOT_SIGNATURE_VERSION_1_1:
            wrapper->Desc_1_1                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_SIGNATURE_DESC1>();
            wrapper->Desc_1_1->decoded_value = &(value->Desc_1_1);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Desc_1_1);
            break;
        case D3D_ROOT_SIGNATURE_VERSION_1_2:
            wrapper->Desc_1_2                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_SIGNATURE_DESC2>();
            wrapper->Desc_1_2->decoded_value = &(value->Desc_1_2);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Desc_1_2);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INDIRECT_ARGUMENT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                        bytes_read = 0;
    D3D12_INDIRECT_ARGUMENT_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.RootParameterIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.DestOffsetIn32BitValues));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.Num32BitValuesToSet));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                          bytes_read = 0;
    D3D12_RAYTRACING_GEOMETRY_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->Type)
    {
        case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            wrapper->Triangles = DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC>();
            wrapper->Triangles->decoded_value = &(value->Triangles);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Triangles);
            break;
        case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            wrapper->AABBs                = DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC>();
            wrapper->AABBs->decoded_value = &(value->AABBs);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AABBs);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t*                                                buffer,
                    size_t                                                        buffer_size,
                    Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                                bytes_read = 0;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescs));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DescsLayout));

    switch (value->Type)
    {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            bytes_read += ValueDecoder::DecodeUInt64Value(
                (buffer + bytes_read), (buffer_size - bytes_read), &(value->InstanceDescs));
            break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            switch (value->DescsLayout)
            {
                case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    wrapper->pGeometryDescs =
                        DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC>>();
                    bytes_read += wrapper->pGeometryDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
                    value->pGeometryDescs = wrapper->pGeometryDescs->GetPointer();
                    break;
                case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    wrapper->ppGeometryDescs =
                        DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC*>>();
                    bytes_read += wrapper->ppGeometryDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
                    value->ppGeometryDescs = wrapper->ppGeometryDescs->GetPointer();
                    break;
            }
            break;
    }

    return bytes_read;
}

size_t
DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                        bytes_read = 0;
    D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Version));

    switch (value->Version)
    {
        case D3D12_DRED_VERSION_1_0:
            wrapper->Dred_1_0                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>();
            wrapper->Dred_1_0->decoded_value = &(value->Dred_1_0);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_0);
            break;
        case D3D12_DRED_VERSION_1_1:
            wrapper->Dred_1_1                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1>();
            wrapper->Dred_1_1->decoded_value = &(value->Dred_1_1);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_1);
            break;
        case D3D12_DRED_VERSION_1_2:
            wrapper->Dred_1_2                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2>();
            wrapper->Dred_1_2->decoded_value = &(value->Dred_1_2);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_2);
            break;
        case D3D12_DRED_VERSION_1_3:
            wrapper->Dred_1_3                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3>();
            wrapper->Dred_1_3->decoded_value = &(value->Dred_1_3);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_3);
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                              bytes_read = 0;
    D3D12_RENDER_PASS_BEGINNING_ACCESS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    wrapper->Clear = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS>();
    wrapper->Clear->decoded_value = &(value->Clear);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Clear);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                           bytes_read = 0;
    D3D12_RENDER_PASS_ENDING_ACCESS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    wrapper->Resolve = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>();
    wrapper->Resolve->decoded_value = &(value->Resolve);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Resolve);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_LARGE_INTEGER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t         bytes_read = 0;
    LARGE_INTEGER* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->QuadPart));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                            bytes_read = 0;
    D3D12_PIPELINE_STATE_STREAM_DESC* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->SizeInBytes));

    size_t   offset = 0;
    uint8_t* start  = DecodeAllocator::Allocate<uint8_t>(value->SizeInBytes, false);

    value->pPipelineStateSubobjectStream = start;

    while (offset < value->SizeInBytes)
    {
        D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type{};
        auto                                current = start + offset;

        bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &type);

        switch (type)
        {
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE:
            {
                auto subobject   = reinterpret_cast<format::Dx12SignatureSubobject*>(current);
                subobject->type  = type;
                subobject->value = nullptr;

                // Store the pointer to the root signature object in the wrapper to simplify the handle mapping process.
                wrapper->root_signature_ptr = &subobject->value;

                bytes_read += ValueDecoder::DecodeHandleIdValue(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->root_signature));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->vs_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->vs_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->ps_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->ps_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->ds_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->ds_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->hs_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->hs_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->gs_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->gs_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->cs_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->cs_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->as_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->as_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS:
            {
                auto subobject                     = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                subobject->type                    = type;
                wrapper->ms_bytecode.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->ms_bytecode));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
            {
                auto subobject                       = reinterpret_cast<format::Dx12StreamOutputSubobject*>(current);
                subobject->type                      = type;
                wrapper->stream_output.decoded_value = &subobject->value;

                bytes_read +=
                    DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->stream_output));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND:
            {
                auto subobject               = reinterpret_cast<format::Dx12BlendSubobject*>(current);
                subobject->type              = type;
                wrapper->blend.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->blend));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
            {
                auto subobject  = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeUInt32Value(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER:
            {
                auto subobject                    = reinterpret_cast<format::Dx12RasterizerSubobject*>(current);
                subobject->type                   = type;
                wrapper->rasterizer.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->rasterizer));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
            {
                auto subobject                       = reinterpret_cast<format::Dx12DepthStencilSubobject*>(current);
                subobject->type                      = type;
                wrapper->depth_stencil.decoded_value = &subobject->value;

                bytes_read +=
                    DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->depth_stencil));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
            {
                auto subobject                      = reinterpret_cast<format::Dx12InputLayoutSubobject*>(current);
                subobject->type                     = type;
                wrapper->input_layout.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->input_layout));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
            {
                auto subobject  = reinterpret_cast<format::Dx12StripCutSubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeEnumValue(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
            {
                auto subobject  = reinterpret_cast<format::Dx12PrimitiveTopologySubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeEnumValue(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
            {
                auto subobject  = reinterpret_cast<format::Dx12RenderTargetFormatsSubobject*>(current);
                subobject->type = type;
                wrapper->render_target_formats.decoded_value = &subobject->value;

                bytes_read +=
                    DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->render_target_formats));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
            {
                auto subobject  = reinterpret_cast<format::Dx12FormatSubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeEnumValue(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
            {
                auto subobject                     = reinterpret_cast<format::Dx12SampleDescSubobject*>(current);
                subobject->type                    = type;
                wrapper->sample_desc.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sample_desc));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK:
            {
                auto subobject  = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeUInt32Value(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO:
            {
                auto subobject                    = reinterpret_cast<format::Dx12CachedPsoSubobject*>(current);
                subobject->type                   = type;
                wrapper->cached_pso.decoded_value = &subobject->value;

                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->cached_pso));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS:
            {
                auto subobject  = reinterpret_cast<format::Dx12TypeFlagsSubobject*>(current);
                subobject->type = type;

                bytes_read += ValueDecoder::DecodeEnumValue(
                    (buffer + bytes_read), (buffer_size - bytes_read), &(subobject->value));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
            {
                auto subobject                        = reinterpret_cast<format::Dx12DepthStencil1Subobject*>(current);
                subobject->type                       = type;
                wrapper->depth_stencil1.decoded_value = &subobject->value;

                bytes_read +=
                    DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->depth_stencil1));

                offset += sizeof(*subobject);
                break;
            }
            case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
            {
                auto subobject  = reinterpret_cast<format::Dx12ViewInstancingSubobject*>(current);
                subobject->type = type;
                wrapper->view_instancing.decoded_value = &subobject->value;

                bytes_read +=
                    DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->view_instancing));

                offset += sizeof(*subobject);
                break;
            }
            default:
                // Type is unrecognized.  Check for an invalid type value to determine if capture did not recogize the
                // type and log a warning.
                offset = value->SizeInBytes;

                if (type == format::kInvalidSubobjectType)
                {
                    GFXRECON_LOG_FATAL(
                        "A pipeline state subobject encoding indicates that the stream contained an unrecognized "
                        "subobject type during capture and the captured data is incomplete, which may cause replay to "
                        "fail.");
                }
                else
                {
                    GFXRECON_LOG_FATAL("Pipeline state subobject decoding encountered unrecognized subobject type "
                                       "D3D12_PIPELINE_STATE_SUBOBJECT_TYPE = %d, which may cause replay to fail.",
                                       type);
                }

                break;
        }
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATE_OBJECT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    D3D12_STATE_OBJECT_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumSubobjects));

    // Decode the D3D12_STATE_SUBOBJECT array stride value, which is added by the capture encoder.
    bytes_read +=
        ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->subobject_stride));

    wrapper->pSubobjects = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>>();
    bytes_read += wrapper->pSubobjects->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubobjects = wrapper->pSubobjects->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_STATE_SUBOBJECT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                 bytes_read = 0;
    D3D12_STATE_SUBOBJECT* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    auto buffer2      = buffer + bytes_read;
    auto buffer_size2 = buffer_size - bytes_read;
    switch (value->Type)
    {
        case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            wrapper->state_object_config =
                +DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_CONFIG>>();
            bytes_read += wrapper->state_object_config->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->state_object_config->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            wrapper->global_root_signature =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_GLOBAL_ROOT_SIGNATURE>>();
            bytes_read += wrapper->global_root_signature->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->global_root_signature->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            wrapper->local_root_signature =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_LOCAL_ROOT_SIGNATURE>>();
            bytes_read += wrapper->local_root_signature->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->local_root_signature->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            wrapper->node_mask = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_NODE_MASK>>();
            bytes_read += wrapper->node_mask->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->node_mask->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            wrapper->dxil_library_desc =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DXIL_LIBRARY_DESC>>();
            bytes_read += wrapper->dxil_library_desc->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->dxil_library_desc->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            wrapper->existing_collection_desc =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_EXISTING_COLLECTION_DESC>>();
            bytes_read += wrapper->existing_collection_desc->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->existing_collection_desc->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            wrapper->subobject_to_exports_association =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION>>();
            bytes_read += wrapper->subobject_to_exports_association->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->subobject_to_exports_association->GetPointer();
            break;
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            wrapper->dxil_subobject_to_exports_association =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION>>();
            bytes_read += wrapper->dxil_subobject_to_exports_association->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->dxil_subobject_to_exports_association->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            wrapper->raytracing_shader_config =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_SHADER_CONFIG>>();
            bytes_read += wrapper->raytracing_shader_config->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->raytracing_shader_config->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            wrapper->raytracing_pipeline_config =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG>>();
            bytes_read += wrapper->raytracing_pipeline_config->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->raytracing_pipeline_config->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            wrapper->hit_group_desc = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_HIT_GROUP_DESC>>();
            bytes_read += wrapper->hit_group_desc->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->hit_group_desc->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            wrapper->raytracing_pipeline_config1 =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1>>();
            bytes_read += wrapper->raytracing_pipeline_config1->Decode(buffer2, buffer_size2);
            value->pDesc = wrapper->raytracing_pipeline_config1->GetPointer();
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                  bytes_read = 0;
    D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value      = wrapper->decoded_value;

    wrapper->pSubobjectToAssociate = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_STATE_SUBOBJECT>>();
    bytes_read += wrapper->pSubobjectToAssociate->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSubobjectToAssociate = wrapper->pSubobjectToAssociate->GetPointer();
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumExports));
    bytes_read += wrapper->pExports.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pExports = const_cast<LPCWSTR*>(wrapper->pExports.GetPointer());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BARRIER_GROUP* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    D3D12_BARRIER_GROUP* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumBarriers));

    switch (value->Type)
    {
        case D3D12_BARRIER_TYPE_GLOBAL:
            wrapper->global_barriers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_GLOBAL_BARRIER>>();
            bytes_read += wrapper->global_barriers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->pGlobalBarriers = wrapper->global_barriers->GetPointer();
            break;
        case D3D12_BARRIER_TYPE_TEXTURE:
            wrapper->texture_barriers =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_TEXTURE_BARRIER>>();
            bytes_read += wrapper->texture_barriers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->pTextureBarriers = wrapper->texture_barriers->GetPointer();
            break;
        case D3D12_BARRIER_TYPE_BUFFER:
            wrapper->buffer_barriers = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_BUFFER_BARRIER>>();
            bytes_read += wrapper->buffer_barriers->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->pBufferBarriers = wrapper->buffer_barriers->GetPointer();
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SAMPLER_DESC2* wrapper)
{
    size_t               bytes_read = 0;
    D3D12_SAMPLER_DESC2* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Filter));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressU));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressV));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->AddressW));
    bytes_read +=
        ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MipLODBias));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxAnisotropy));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ComparisonFunc));

    wrapper->FloatBorderColor.SetExternalMemory(value->FloatBorderColor, 4);
    bytes_read += wrapper->FloatBorderColor.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MinLOD));
    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->MaxLOD));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
