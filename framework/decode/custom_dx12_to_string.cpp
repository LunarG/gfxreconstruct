/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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

#include "custom_dx12_to_string.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "generated/generated_dx12_struct_to_string.h"

#include <algorithm>
#include <ios>
#include <sstream>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string
ToString(const D3D12_CPU_DESCRIPTOR_HANDLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ptr", toStringFlags, tabCount, tabSize, ToString(obj.ptr, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_GPU_DESCRIPTOR_HANDLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ptr", toStringFlags, tabCount, tabSize, ToString(obj.ptr, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

std::string ToString(const LARGE_INTEGER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "QuadPart", toStringFlags, tabCount, tabSize, ToString(obj.QuadPart));
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj,
                     ToStringFlags                              toStringFlags,
                     uint32_t                                   tabCount,
                     uint32_t                                   tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Version", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Version)));
            switch (obj.Version) {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
            {
                FieldToString(strStrm, false, "Desc_1_0", toStringFlags, tabCount, tabSize, ToString(obj.Desc_1_0, toStringFlags, tabCount, tabSize));
            } break;
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
            {
                FieldToString(strStrm, false, "Desc_1_1", toStringFlags, tabCount, tabSize, ToString(obj.Desc_1_1, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_TEXTURE_COPY_LOCATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            switch (obj.Type) {
            case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            {
                FieldToString(strStrm, false, "PlacedFootprint", toStringFlags, tabCount, tabSize, ToString(obj.PlacedFootprint, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            {
                FieldToString(strStrm, false, "SubresourceIndex", toStringFlags, tabCount, tabSize, ToString(obj.SubresourceIndex));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_SHADER_RESOURCE_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ViewDimension)));
            FieldToString(strStrm, false, "Shader4ComponentMapping", toStringFlags, tabCount, tabSize, ToString(obj.Shader4ComponentMapping));
            switch (obj.ViewDimension) {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DMSArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToString(strStrm, false, "TextureCube", toStringFlags, tabCount, tabSize, ToString(obj.TextureCube, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToString(strStrm, false, "TextureCubeArray", toStringFlags, tabCount, tabSize, ToString(obj.TextureCubeArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            {
                FieldToString(strStrm, false, "RaytracingAccelerationStructure", toStringFlags, tabCount, tabSize, ToString(obj.RaytracingAccelerationStructure, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ViewDimension)));
            switch (obj.ViewDimension) {
            case D3D12_UAV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_RENDER_TARGET_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ViewDimension)));
            switch (obj.ViewDimension) {
            case D3D12_RTV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_DEPTH_STENCIL_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ViewDimension)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            switch (obj.ViewDimension) {
            case D3D12_DSV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_DSV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_CLEAR_VALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Format)));
            switch (obj.Format) {
            case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
            case DXGI_FORMAT_D32_FLOAT:
            case DXGI_FORMAT_D24_UNORM_S8_UINT:
            case DXGI_FORMAT_D16_UNORM:
            {
                FieldToString(strStrm, false, "DepthStencil", toStringFlags, tabCount, tabSize, ToString(obj.DepthStencil, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
                FieldToString(strStrm, false, "Color", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.Color, toStringFlags, tabCount, tabSize));
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_PIPELINE_STATE_STREAM_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes));
            FieldToString(strStrm, false, "pPipelineStateSubobjectStream", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pPipelineStateSubobjectStream)));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_STATE_OBJECT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "NumSubobjects", toStringFlags, tabCount, tabSize, ToString(obj.NumSubobjects));
            FieldToString(strStrm, false, "pSubobjects", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumSubobjects, obj.pSubobjects, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj,
                     ToStringFlags                                               toStringFlags,
                     uint32_t                                                    tabCount,
                     uint32_t                                                    tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "NumDescs", toStringFlags, tabCount, tabSize, ToString(obj.NumDescs));
            FieldToString(strStrm, false, "DescsLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DescsLayout)));
            switch (obj.Type) {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            {
                FieldToString(strStrm, false, "InstanceDescs", toStringFlags, tabCount, tabSize, ToString(obj.InstanceDescs, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            {
                switch (obj.DescsLayout)
                {
                case D3D12_ELEMENTS_LAYOUT_ARRAY:
                {
                    FieldToString(strStrm, false, "InstanceDescs", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumDescs, obj.pGeometryDescs, toStringFlags, tabCount, tabSize));
                } break;
                case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                {
                    // TODO : Generic 2D array handler...
                    FieldToString(strStrm, false, "InstanceDescs", toStringFlags, tabCount, tabSize,  PtrToString(obj.ppGeometryDescs));
                } break;
                }
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj,
                     ToStringFlags                             toStringFlags,
                     uint32_t                                  tabCount,
                     uint32_t                                  tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            switch (obj.Type) {
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR:
            {
                FieldToString(strStrm, false, "Clear", toStringFlags, tabCount, tabSize, ToString(obj.Clear, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_RENDER_PASS_ENDING_ACCESS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            switch (obj.Type) {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
            {
                FieldToString(strStrm, false, "Resolve", toStringFlags, tabCount, tabSize, ToString(obj.Resolve, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_ROOT_PARAMETER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ParameterType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ParameterType)));
            switch (obj.ParameterType) {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToString(strStrm, false, "DescriptorTable", toStringFlags, tabCount, tabSize, ToString(obj.DescriptorTable, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToString(strStrm, false, "Constants", toStringFlags, tabCount, tabSize, ToString(obj.Constants, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            default:
            {
                FieldToString(strStrm, false, "Descriptor", toStringFlags, tabCount, tabSize, ToString(obj.Descriptor, toStringFlags, tabCount, tabSize));
            } break;
            }
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ShaderVisibility)));
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_ROOT_PARAMETER1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ParameterType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ParameterType)));
            switch (obj.ParameterType) {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToString(strStrm, false, "DescriptorTable", toStringFlags, tabCount, tabSize, ToString(obj.DescriptorTable, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToString(strStrm, false, "Constants", toStringFlags, tabCount, tabSize, ToString(obj.Constants, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            default:
            {
                FieldToString(strStrm, false, "Descriptor", toStringFlags, tabCount, tabSize, ToString(obj.Descriptor, toStringFlags, tabCount, tabSize));
            } break;
            }
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ShaderVisibility)));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_INDIRECT_ARGUMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            switch (obj.Type) {
            case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
            {
                FieldToString(strStrm, false, "VertexBuffer.Slot", toStringFlags, tabCount, tabSize, ToString(obj.VertexBuffer.Slot));
            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
            {
                FieldToString(strStrm, false, "Constant.RootParameterIndex", toStringFlags, tabCount, tabSize, ToString(obj.Constant.RootParameterIndex));
                FieldToString(strStrm, false, "Constant.DestOffsetIn32BitValues", toStringFlags, tabCount, tabSize, ToString(obj.Constant.DestOffsetIn32BitValues));
                FieldToString(strStrm, false, "Constant.Num32BitValuesToSet", toStringFlags, tabCount, tabSize, ToString(obj.Constant.Num32BitValuesToSet));
            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            {
                FieldToString(strStrm, false, "ConstantBufferView.RootParameterIndex", toStringFlags, tabCount, tabSize, ToString(obj.ConstantBufferView.RootParameterIndex));
            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            {
                FieldToString(strStrm, false, "ShaderResourceView.RootParameterIndex", toStringFlags, tabCount, tabSize, ToString(obj.ShaderResourceView.RootParameterIndex));
            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
            {
                FieldToString(strStrm, false, "UnorderedAccessView.RootParameterIndex", toStringFlags, tabCount, tabSize, ToString(obj.UnorderedAccessView.RootParameterIndex));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string
ToString(const DXGI_DISPLAY_COLOR_SPACE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : Generic 2D array handler...
            FieldToString(strStrm, true, "PrimaryCoordinates", toStringFlags, tabCount, tabSize, ArrayToString(0, obj.PrimaryCoordinates[0], toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "WhitePoints", toStringFlags, tabCount, tabSize, ArrayToString(0, obj.WhitePoints[0], toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_RAYTRACING_INSTANCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            std::string strs[3][4];
            size_t maxStrLength = 0;
            for (size_t y = 0; y < 3; ++y)
            {
                for (size_t x = 0; x < 4; ++x)
                {
                    strs[y][x] = std::to_string(obj.Transform[y][x]);
                    maxStrLength = std::max(maxStrLength, strs[y][x].size());
                }
            }
            FieldToString(strStrm, true, "Transform", toStringFlags, tabCount, tabSize,
                ArrayToString(3, obj.Transform, toStringFlags, tabCount, tabSize,
                    [&]()
                    {
                        return true;
                    },
                    [&](size_t y)
                    {
                        std::stringstream rowStrStrm;
                        rowStrStrm << '[' << GetWhitespaceString(toStringFlags);
                        for (size_t x = 0; x < 4; ++x)
                        {
                            if (x)
                            {
                                rowStrStrm << ',' << GetWhitespaceString(toStringFlags);
                            }
                            if (strs[y][x].size() < maxStrLength)
                            {
                                strs[y][x].insert(0, maxStrLength - strs[y][x].size(), ' ');
                            }
                            rowStrStrm << strs[y][x];
                        }
                        rowStrStrm << GetWhitespaceString(toStringFlags) << ']';
                        return rowStrStrm.str();
                    }
                )
            );
            FieldToString(strStrm, false, "InstanceID", toStringFlags, tabCount, tabSize, ToString(obj.InstanceID));
            FieldToString(strStrm, false, "InstanceMask", toStringFlags, tabCount, tabSize, ToString(obj.InstanceMask)); ///< @todo Do something better with masks like this.
            FieldToString(strStrm, false, "InstanceContributionToHitGroupIndex", toStringFlags, tabCount, tabSize, ToString(obj.InstanceContributionToHitGroupIndex));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            FieldToString(strStrm, false, "AccelerationStructure", toStringFlags, tabCount, tabSize, ToString(obj.AccelerationStructure)); ///< @todo Represent virtual addresses as hex.
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj,
                     ToStringFlags                                      toStringFlags,
                     uint32_t                                           tabCount,
                     uint32_t                                           tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SubobjectToAssociate", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.SubobjectToAssociate)));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, ToString(obj.NumExports));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pExports)));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_RESOURCE_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Flags)));
            switch (obj.Type) {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            {
                FieldToString(strStrm, false, "Transition", toStringFlags, tabCount, tabSize, ToString(obj.Transition, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            {
                FieldToString(strStrm, false, "Aliasing", toStringFlags, tabCount, tabSize, ToString(obj.Aliasing, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            {
                FieldToString(strStrm, false, "UAV", toStringFlags, tabCount, tabSize, ToString(obj.UAV, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

std::string ToString(const D3D12_STATE_SUBOBJECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pDesc)));
        }
    );
    // clang-format on
}

std::string
ToString(const D3D12_RAYTRACING_GEOMETRY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.Type)));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.Flags)));
            switch (obj.Type)
            {
                case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
                {
                    FieldToString(strStrm, false, "Triangles", toStringFlags, tabCount, tabSize, ToString(obj.Triangles, toStringFlags, tabCount, tabSize));
                } break;
                case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
                {
                    FieldToString(strStrm, false, "AABBs", toStringFlags, tabCount, tabSize, ToString(obj.AABBs, toStringFlags, tabCount, tabSize));
                } break;
                default:
                {
                } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_SUBRESOURCE_DATA>(const D3D11_SUBRESOURCE_DATA& obj,
                                             ToStringFlags                 toStringFlags,
                                             uint32_t                      tabCount,
                                             uint32_t                      tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pSysMem", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.pSysMem) + '"');
            FieldToString(strStrm, false, "SysMemPitch", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SysMemPitch, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "SysMemSlicePitch", toStringFlags, tabCount, tabSize, '"' + ToString(obj.SysMemSlicePitch, toStringFlags, tabCount, tabSize) + '"');
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_BUFFER_SRV>(const D3D11_BUFFER_SRV& obj,
                                       ToStringFlags           toStringFlags,
                                       uint32_t                tabCount,
                                       uint32_t                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, '"' + ToString(obj.FirstElement, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, '"' + ToString(obj.NumElements, toStringFlags, tabCount, tabSize) + '"');
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_SHADER_RESOURCE_VIEW_DESC>(const D3D11_SHADER_RESOURCE_VIEW_DESC& obj,
                                                      ToStringFlags                          toStringFlags,
                                                      uint32_t                               tabCount,
                                                      uint32_t                               tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_SRV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DMSArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToString(strStrm, false, "TextureCube", toStringFlags, tabCount, tabSize, ToString(obj.TextureCube, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToString(strStrm, false, "TextureCubeArray", toStringFlags, tabCount, tabSize, ToString(obj.TextureCubeArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_BUFFEREX:
            {
                FieldToString(strStrm, false, "BufferEx", toStringFlags, tabCount, tabSize, ToString(obj.BufferEx, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_BUFFER_RTV>(const D3D11_BUFFER_RTV& obj,
                                       ToStringFlags           toStringFlags,
                                       uint32_t                tabCount,
                                       uint32_t                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "FirstElement", toStringFlags, tabCount, tabSize, '"' + ToString(obj.FirstElement, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "NumElements", toStringFlags, tabCount, tabSize, '"' + ToString(obj.NumElements, toStringFlags, tabCount, tabSize) + '"');
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_UNORDERED_ACCESS_VIEW_DESC>(const D3D11_UNORDERED_ACCESS_VIEW_DESC& obj,
                                                       ToStringFlags                           toStringFlags,
                                                       uint32_t                                tabCount,
                                                       uint32_t                                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_UAV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_RENDER_TARGET_VIEW_DESC>(const D3D11_RENDER_TARGET_VIEW_DESC& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_RTV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_DEPTH_STENCIL_VIEW_DESC>(const D3D11_DEPTH_STENCIL_VIEW_DESC& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Flags, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_DSV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_DSV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_DSV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_DSV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_DSV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_SHADER_RESOURCE_VIEW_DESC1>(const D3D11_SHADER_RESOURCE_VIEW_DESC1& obj,
                                                       ToStringFlags                           toStringFlags,
                                                       uint32_t                                tabCount,
                                                       uint32_t                                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_SRV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DMSArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToString(strStrm, false, "TextureCube", toStringFlags, tabCount, tabSize, ToString(obj.TextureCube, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToString(strStrm, false, "TextureCubeArray", toStringFlags, tabCount, tabSize, ToString(obj.TextureCubeArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_SRV_DIMENSION_BUFFEREX:
            {
                FieldToString(strStrm, false, "BufferEx", toStringFlags, tabCount, tabSize, ToString(obj.BufferEx, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_UNORDERED_ACCESS_VIEW_DESC1>(const D3D11_UNORDERED_ACCESS_VIEW_DESC1& obj,
                                                        ToStringFlags                            toStringFlags,
                                                        uint32_t                                 tabCount,
                                                        uint32_t                                 tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_UAV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_RENDER_TARGET_VIEW_DESC1>(const D3D11_RENDER_TARGET_VIEW_DESC1& obj,
                                                     ToStringFlags                         toStringFlags,
                                                     uint32_t                              tabCount,
                                                     uint32_t                              tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_RTV_DIMENSION_BUFFER:
            {
                FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, ToString(obj.Buffer, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToString(strStrm, false, "Texture1D", toStringFlags, tabCount, tabSize, ToString(obj.Texture1D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToString(strStrm, false, "Texture1DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture1DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToString(strStrm, false, "Texture2DMS", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMS, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DMSArray, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToString(strStrm, false, "Texture3D", toStringFlags, tabCount, tabSize, ToString(obj.Texture3D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_VIDEO_COLOR>(const D3D11_VIDEO_COLOR& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "RGBA", toStringFlags, tabCount, tabSize, '"' + ToString(obj.RGBA, toStringFlags, tabCount, tabSize) + '"');
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_AUTHENTICATED_PROTECTION_FLAGS>(const D3D11_AUTHENTICATED_PROTECTION_FLAGS& obj,
                                                           ToStringFlags                               toStringFlags,
                                                           uint32_t                                    tabCount,
                                                           uint32_t                                    tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // This is a union of a bitfield and unsigned integer, generate string using the bitfield Flags name and the unsigned integer Value.
            FieldToString(strStrm, true, "Flags", toStringFlags, tabCount, tabSize, '"' + ToString(obj.Value, toStringFlags, tabCount, tabSize) + '"');
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC>(const D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC& obj,
                                                           ToStringFlags                               toStringFlags,
                                                           uint32_t                                    tabCount,
                                                           uint32_t                                    tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // This is a union of a bitfield and unsigned integer, generate string using the bitfield Flags name and the unsigned integer Value.
            FieldToString(strStrm, true, "DecodeProfile", toStringFlags, tabCount, tabSize, '"' + ToString(obj.DecodeProfile, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_VDOV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC>(const D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC& obj,
                                                            ToStringFlags                                toStringFlags,
                                                            uint32_t                                     tabCount,
                                                            uint32_t                                     tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // This is a union of a bitfield and unsigned integer, generate string using the bitfield Flags name and the unsigned integer Value.
            FieldToString(strStrm, true, "FourCC", toStringFlags, tabCount, tabSize, '"' + ToString(obj.FourCC, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_VPIV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC>(const D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC& obj,
                                                             ToStringFlags toStringFlags,
                                                             uint32_t      tabCount,
                                                             uint32_t      tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // This is a union of a bitfield and unsigned integer, generate string using the bitfield Flags name and the unsigned integer Value.
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, '"' + ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize) + '"');
            switch (obj.ViewDimension) {
            case D3D11_VPOV_DIMENSION_TEXTURE2D:
            {
                FieldToString(strStrm, false, "Texture2D", toStringFlags, tabCount, tabSize, ToString(obj.Texture2D, toStringFlags, tabCount, tabSize));
            } break;
            case D3D11_VPOV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToString(strStrm, false, "Texture2DArray", toStringFlags, tabCount, tabSize, ToString(obj.Texture2DArray, toStringFlags, tabCount, tabSize));
            } break;
            default:
            {
            } break;
            }
        }
    );
    // clang-format on
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
