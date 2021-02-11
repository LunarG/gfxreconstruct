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

#include "encode/custom_dx12_struct_encoders.h"
#include "generated/generated_dx12_api_call_encoders.h"
#include "encode/struct_pointer_encoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CLEAR_VALUE& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeFloatArray(value.Color, 4);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_BARRIER& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);

    switch (value.Type)
    {
        case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            EncodeStruct(encoder, value.Transition);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            EncodeStruct(encoder, value.Aliasing);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            EncodeStruct(encoder, value.UAV);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXTURE_COPY_LOCATION& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_TEXTURE_COPY_LOCATION*>(&value)->pResource));
    encoder->EncodeEnumValue(value.Type);

    switch (value.Type)
    {
        case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            encoder->EncodeUInt32Value(value.SubresourceIndex);
            break;
        case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            EncodeStruct(encoder, value.PlacedFootprint);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_RESOURCE_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    encoder->EncodeUInt32Value(value.Shader4ComponentMapping);

    switch (value.ViewDimension)
    {
        case D3D12_SRV_DIMENSION_BUFFER:
            EncodeStruct(encoder, value.Buffer);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1D:
            EncodeStruct(encoder, value.Texture1D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            EncodeStruct(encoder, value.Texture1DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2D:
            EncodeStruct(encoder, value.Texture2D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            EncodeStruct(encoder, value.Texture2DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            EncodeStruct(encoder, value.Texture2DMS);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            EncodeStruct(encoder, value.Texture2DMSArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE3D:
            EncodeStruct(encoder, value.Texture3D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBE:
            EncodeStruct(encoder, value.TextureCube);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            EncodeStruct(encoder, value.TextureCubeArray);
            break;
        case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            EncodeStruct(encoder, value.RaytracingAccelerationStructure);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_UNORDERED_ACCESS_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);

    switch (value.ViewDimension)
    {
        case D3D12_UAV_DIMENSION_BUFFER:
            EncodeStruct(encoder, value.Buffer);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1D:
            EncodeStruct(encoder, value.Texture1D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            EncodeStruct(encoder, value.Texture1DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2D:
            EncodeStruct(encoder, value.Texture2D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            EncodeStruct(encoder, value.Texture2DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE3D:
            EncodeStruct(encoder, value.Texture3D);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);

    switch (value.ViewDimension)
    {
        case D3D12_RTV_DIMENSION_BUFFER:
            EncodeStruct(encoder, value.Buffer);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1D:
            EncodeStruct(encoder, value.Texture1D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            EncodeStruct(encoder, value.Texture1DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2D:
            EncodeStruct(encoder, value.Texture2D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            EncodeStruct(encoder, value.Texture2DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            EncodeStruct(encoder, value.Texture2DMS);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            EncodeStruct(encoder, value.Texture2DMSArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE3D:
            EncodeStruct(encoder, value.Texture3D);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    encoder->EncodeEnumValue(value.Flags);

    switch (value.ViewDimension)
    {
        case D3D12_DSV_DIMENSION_TEXTURE1D:
            EncodeStruct(encoder, value.Texture1D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            EncodeStruct(encoder, value.Texture1DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2D:
            EncodeStruct(encoder, value.Texture2D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            EncodeStruct(encoder, value.Texture2DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            EncodeStruct(encoder, value.Texture2DMS);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            EncodeStruct(encoder, value.Texture2DMSArray);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER& value)
{
    encoder->EncodeEnumValue(value.ParameterType);

    switch (value.ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            EncodeStruct(encoder, value.DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            EncodeStruct(encoder, value.Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            EncodeStruct(encoder, value.Descriptor);
            break;
        default:
            break;
    }

    encoder->EncodeEnumValue(value.ShaderVisibility);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER1& value)
{
    encoder->EncodeEnumValue(value.ParameterType);

    switch (value.ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            EncodeStruct(encoder, value.DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            EncodeStruct(encoder, value.Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            EncodeStruct(encoder, value.Descriptor);
            break;
        default:
            break;
    }

    encoder->EncodeEnumValue(value.ShaderVisibility);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& value)
{
    encoder->EncodeEnumValue(value.Version);

    switch (value.Version)
    {
        case D3D_ROOT_SIGNATURE_VERSION_1_0:
            EncodeStruct(encoder, value.Desc_1_0);
            break;
        case D3D_ROOT_SIGNATURE_VERSION_1_1:
            EncodeStruct(encoder, value.Desc_1_1);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDIRECT_ARGUMENT_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.Constant.RootParameterIndex);
    encoder->EncodeUInt32Value(value.Constant.DestOffsetIn32BitValues);
    encoder->EncodeUInt32Value(value.Constant.Num32BitValuesToSet);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);

    switch (value.Type)
    {
        case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            EncodeStruct(encoder, value.Triangles);
            break;
        case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            EncodeStruct(encoder, value.AABBs);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NumDescs);
    encoder->EncodeEnumValue(value.DescsLayout);

    switch (value.Type)
    {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            encoder->EncodeUInt64Value(value.InstanceDescs);
            break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            switch (value.DescsLayout)
            {
                case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    EncodeStructArray(encoder, value.pGeometryDescs, value.NumDescs);
                    break;
                case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    EncodeStructArrayPtr(encoder, value.ppGeometryDescs, value.NumDescs);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& value)
{
    encoder->EncodeEnumValue(value.Version);

    switch (value.Version)
    {
        case D3D12_DRED_VERSION_1_0:
            EncodeStruct(encoder, value.Dred_1_0);
            break;
        case D3D12_DRED_VERSION_1_1:
            EncodeStruct(encoder, value.Dred_1_1);
            break;
        case D3D12_DRED_VERSION_1_2:
            EncodeStruct(encoder, value.Dred_1_2);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS& value)
{
    encoder->EncodeEnumValue(value.Type);
    EncodeStruct(encoder, value.Clear);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS& value)
{
    encoder->EncodeEnumValue(value.Type);
    EncodeStruct(encoder, value.Resolve);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
