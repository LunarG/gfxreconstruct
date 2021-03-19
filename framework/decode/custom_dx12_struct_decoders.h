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

#ifndef GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_H

#include "generated/generated_dx12_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Unions.
struct Decoded_D3D12_CLEAR_VALUE
{
    using struct_type = D3D12_CLEAR_VALUE;
    D3D12_CLEAR_VALUE*    decoded_value{ nullptr };
    PointerDecoder<float> Color;
};

struct Decoded_D3D12_RESOURCE_BARRIER
{
    using struct_type = D3D12_RESOURCE_BARRIER;
    D3D12_RESOURCE_BARRIER*                    decoded_value{ nullptr };
    Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* Transition{ nullptr };
    Decoded_D3D12_RESOURCE_ALIASING_BARRIER*   Aliasing{ nullptr };
    Decoded_D3D12_RESOURCE_UAV_BARRIER*        UAV{ nullptr };
};

struct Decoded_D3D12_TEXTURE_COPY_LOCATION
{
    using struct_type = D3D12_TEXTURE_COPY_LOCATION;
    D3D12_TEXTURE_COPY_LOCATION*                decoded_value{ nullptr };
    format::HandleId                            pResource;
    Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* PlacedFootprint{ nullptr };
};

struct Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC
{
    using struct_type = D3D12_SHADER_RESOURCE_VIEW_DESC;
    D3D12_SHADER_RESOURCE_VIEW_DESC*                     decoded_value{ nullptr };
    Decoded_D3D12_BUFFER_SRV*                            Buffer{ nullptr };
    Decoded_D3D12_TEX1D_SRV*                             Texture1D{ nullptr };
    Decoded_D3D12_TEX1D_ARRAY_SRV*                       Texture1DArray{ nullptr };
    Decoded_D3D12_TEX2D_SRV*                             Texture2D{ nullptr };
    Decoded_D3D12_TEX2D_ARRAY_SRV*                       Texture2DArray{ nullptr };
    Decoded_D3D12_TEX2DMS_SRV*                           Texture2DMS{ nullptr };
    Decoded_D3D12_TEX2DMS_ARRAY_SRV*                     Texture2DMSArray{ nullptr };
    Decoded_D3D12_TEX3D_SRV*                             Texture3D{ nullptr };
    Decoded_D3D12_TEXCUBE_SRV*                           TextureCube{ nullptr };
    Decoded_D3D12_TEXCUBE_ARRAY_SRV*                     TextureCubeArray{ nullptr };
    Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* RaytracingAccelerationStructure{ nullptr };
};

struct Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC
{
    using struct_type = D3D12_UNORDERED_ACCESS_VIEW_DESC;
    D3D12_UNORDERED_ACCESS_VIEW_DESC* decoded_value{ nullptr };
    Decoded_D3D12_BUFFER_UAV*         Buffer{ nullptr };
    Decoded_D3D12_TEX1D_UAV*          Texture1D{ nullptr };
    Decoded_D3D12_TEX1D_ARRAY_UAV*    Texture1DArray{ nullptr };
    Decoded_D3D12_TEX2D_UAV*          Texture2D{ nullptr };
    Decoded_D3D12_TEX2D_ARRAY_UAV*    Texture2DArray{ nullptr };
    Decoded_D3D12_TEX3D_UAV*          Texture3D{ nullptr };
};

struct Decoded_D3D12_RENDER_TARGET_VIEW_DESC
{
    using struct_type = D3D12_RENDER_TARGET_VIEW_DESC;
    D3D12_RENDER_TARGET_VIEW_DESC*   decoded_value{ nullptr };
    Decoded_D3D12_BUFFER_RTV*        Buffer{ nullptr };
    Decoded_D3D12_TEX1D_RTV*         Texture1D{ nullptr };
    Decoded_D3D12_TEX1D_ARRAY_RTV*   Texture1DArray{ nullptr };
    Decoded_D3D12_TEX2D_RTV*         Texture2D{ nullptr };
    Decoded_D3D12_TEX2D_ARRAY_RTV*   Texture2DArray{ nullptr };
    Decoded_D3D12_TEX2DMS_RTV*       Texture2DMS{ nullptr };
    Decoded_D3D12_TEX2DMS_ARRAY_RTV* Texture2DMSArray{ nullptr };
    Decoded_D3D12_TEX3D_RTV*         Texture3D{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC
{
    using struct_type = D3D12_DEPTH_STENCIL_VIEW_DESC;
    D3D12_DEPTH_STENCIL_VIEW_DESC*   decoded_value{ nullptr };
    Decoded_D3D12_TEX1D_DSV*         Texture1D{ nullptr };
    Decoded_D3D12_TEX1D_ARRAY_DSV*   Texture1DArray{ nullptr };
    Decoded_D3D12_TEX2D_DSV*         Texture2D{ nullptr };
    Decoded_D3D12_TEX2D_ARRAY_DSV*   Texture2DArray{ nullptr };
    Decoded_D3D12_TEX2DMS_DSV*       Texture2DMS{ nullptr };
    Decoded_D3D12_TEX2DMS_ARRAY_DSV* Texture2DMSArray{ nullptr };
};

struct Decoded_D3D12_ROOT_PARAMETER
{
    using struct_type = D3D12_ROOT_PARAMETER;
    D3D12_ROOT_PARAMETER*                decoded_value{ nullptr };
    Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* DescriptorTable{ nullptr };
    Decoded_D3D12_ROOT_CONSTANTS*        Constants{ nullptr };
    Decoded_D3D12_ROOT_DESCRIPTOR*       Descriptor{ nullptr };
};

struct Decoded_D3D12_ROOT_PARAMETER1
{
    using struct_type = D3D12_ROOT_PARAMETER1;
    D3D12_ROOT_PARAMETER1*                decoded_value{ nullptr };
    Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* DescriptorTable{ nullptr };
    Decoded_D3D12_ROOT_CONSTANTS*         Constants{ nullptr };
    Decoded_D3D12_ROOT_DESCRIPTOR1*       Descriptor{ nullptr };
};

struct Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC
{
    using struct_type = D3D12_VERSIONED_ROOT_SIGNATURE_DESC;
    D3D12_VERSIONED_ROOT_SIGNATURE_DESC* decoded_value{ nullptr };
    Decoded_D3D12_ROOT_SIGNATURE_DESC*   Desc_1_0{ nullptr };
    Decoded_D3D12_ROOT_SIGNATURE_DESC1*  Desc_1_1{ nullptr };
};

struct Decoded_D3D12_INDIRECT_ARGUMENT_DESC
{
    using struct_type = D3D12_INDIRECT_ARGUMENT_DESC;
    D3D12_INDIRECT_ARGUMENT_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_GEOMETRY_DESC
{
    using struct_type = D3D12_RAYTRACING_GEOMETRY_DESC;
    D3D12_RAYTRACING_GEOMETRY_DESC*                   decoded_value{ nullptr };
    Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* Triangles{ nullptr };
    Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC*     AABBs{ nullptr };
};

struct Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS
{
    using struct_type = D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS*          decoded_value{ nullptr };
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC>*  pGeometryDescs{ nullptr };
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC*>* ppGeometryDescs{ nullptr };
};

struct Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA
{
    using struct_type = D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA;
    D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* decoded_value{ nullptr };
    Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA*   Dred_1_0{ nullptr };
    Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1*  Dred_1_1{ nullptr };
    Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2*  Dred_1_2{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS
{
    using struct_type = D3D12_RENDER_PASS_BEGINNING_ACCESS;
    D3D12_RENDER_PASS_BEGINNING_ACCESS*                          decoded_value{ nullptr };
    Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* Clear{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_ENDING_ACCESS
{
    using struct_type = D3D12_RENDER_PASS_ENDING_ACCESS;
    D3D12_RENDER_PASS_ENDING_ACCESS*                            decoded_value{ nullptr };
    Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* Resolve{ nullptr };
};

struct Decoded_LARGE_INTEGER
{
    using struct_type = LARGE_INTEGER;
    LARGE_INTEGER* decoded_value{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_DX12_STRUCT_DECODERS_H
