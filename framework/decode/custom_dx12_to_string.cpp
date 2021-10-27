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

#include "custom_dx12_to_string.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "generated/generated_dx12_struct_to_string.h"

#include <algorithm>
#include <ios>
#include <sstream>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <>
std::string ToString<GUID>(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    GFXRECON_UNREFERENCED_PARAMETER(tabCount);
    GFXRECON_UNREFERENCED_PARAMETER(tabSize);
    std::stringstream strStrm;
    strStrm.width(8);
    strStrm << std::hex << obj.Data1 << '-';
    strStrm.width(4);
    strStrm << std::hex << obj.Data2 << '-';
    strStrm << std::hex << obj.Data3 << '-';
    strStrm.width(2);
    for (size_t i = 0; i < 8; ++i)
    {
        strStrm << std::hex << static_cast<unsigned short>(obj.Data4[i]);
        if (i == 1)
        {
            strStrm << '-';
        }
    }
    return '"' + strStrm.str() + '"';
}

template <>
std::string ToString<D3D12_CPU_DESCRIPTOR_HANDLE>(const D3D12_CPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize)
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

#if 0
template <>
std::string ToString<D3D12_GPU_DESCRIPTOR_HANDLE>(const D3D12_GPU_DESCRIPTOR_HANDLE& obj,
                                                  ToStringFlags                      toStringFlags,
                                                  uint32_t                           tabCount,
                                                  uint32_t                           tabSize)
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
#endif

template <>
std::string
ToString<LARGE_INTEGER>(const LARGE_INTEGER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "QuadPart", toStringFlags, tabCount, tabSize, ToString(obj.QuadPart, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_VERSIONED_ROOT_SIGNATURE_DESC>(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj,
    ToStringFlags                              toStringFlags,
    uint32_t                                   tabCount,
    uint32_t                                   tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Version", toStringFlags, tabCount, tabSize, ToString(obj.Version, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_TEXTURE_COPY_LOCATION>(const D3D12_TEXTURE_COPY_LOCATION& obj,
    ToStringFlags                      toStringFlags,
    uint32_t                           tabCount,
    uint32_t                           tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pResource", toStringFlags, tabCount, tabSize, HandleIdToString(obj.pResource));
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            switch (obj.Type) {
            case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            {
                FieldToString(strStrm, false, "PlacedFootprint", toStringFlags, tabCount, tabSize, ToString(obj.PlacedFootprint, toStringFlags, tabCount, tabSize));
            } break;
            case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            {
                FieldToString(strStrm, false, "SubresourceIndex", toStringFlags, tabCount, tabSize, ToString(obj.SubresourceIndex, toStringFlags, tabCount, tabSize));
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
std::string ToString<D3D12_SHADER_RESOURCE_VIEW_DESC>(const D3D12_SHADER_RESOURCE_VIEW_DESC& obj,
    ToStringFlags                          toStringFlags,
    uint32_t                               tabCount,
    uint32_t                               tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, ToString(obj.Format, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Shader4ComponentMapping", toStringFlags, tabCount, tabSize, ToString(obj.Shader4ComponentMapping, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_UNORDERED_ACCESS_VIEW_DESC>(const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj,
    ToStringFlags                           toStringFlags,
    uint32_t                                tabCount,
    uint32_t                                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, ToString(obj.Format, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_RENDER_TARGET_VIEW_DESC>(const D3D12_RENDER_TARGET_VIEW_DESC& obj,
    ToStringFlags                        toStringFlags,
    uint32_t                             tabCount,
    uint32_t                             tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, ToString(obj.Format, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_DEPTH_STENCIL_VIEW_DESC>(const D3D12_DEPTH_STENCIL_VIEW_DESC& obj,
    ToStringFlags                        toStringFlags,
    uint32_t                             tabCount,
    uint32_t                             tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, ToString(obj.Format, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ViewDimension", toStringFlags, tabCount, tabSize, ToString(obj.ViewDimension, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_CLEAR_VALUE>(const D3D12_CLEAR_VALUE& obj,
    ToStringFlags            toStringFlags,
    uint32_t                 tabCount,
    uint32_t                 tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Format", toStringFlags, tabCount, tabSize, ToString(obj.Format, toStringFlags, tabCount, tabSize));
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
                // TODO : 
                FieldToString(strStrm, false, "Color", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.Color, toStringFlags, tabCount, tabSize));
            } break;
            }
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_PIPELINE_STATE_STREAM_DESC>(const D3D12_PIPELINE_STATE_STREAM_DESC& obj,
    ToStringFlags                           toStringFlags,
    uint32_t                                tabCount,
    uint32_t                                tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "SizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.SizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelineStateSubobjectStream", toStringFlags, tabCount, tabSize, PtrToString(obj.pPipelineStateSubobjectStream));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_STATE_OBJECT_DESC>(const D3D12_STATE_OBJECT_DESC& obj,
    ToStringFlags                  toStringFlags,
    uint32_t                       tabCount,
    uint32_t                       tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : 
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumSubobjects", toStringFlags, tabCount, tabSize, ToString(obj.NumSubobjects, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubobjects", toStringFlags, tabCount, tabSize, ArrayToString(obj.NumSubobjects, obj.pSubobjects, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj,
    ToStringFlags                                               toStringFlags,
    uint32_t                                                    tabCount,
    uint32_t                                                    tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : 
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NumDescs", toStringFlags, tabCount, tabSize, ToString(obj.NumDescs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "DescsLayout", toStringFlags, tabCount, tabSize, ToString(obj.DescsLayout, toStringFlags, tabCount, tabSize));
            switch (obj.Type) {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            {
            } break;
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            {
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
std::string ToString<D3D12_RENDER_PASS_BEGINNING_ACCESS>(const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj,
    ToStringFlags                             toStringFlags,
    uint32_t                                  tabCount,
    uint32_t                                  tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS>(const D3D12_RENDER_PASS_ENDING_ACCESS& obj,
    ToStringFlags                          toStringFlags,
    uint32_t                               tabCount,
    uint32_t                               tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_ROOT_PARAMETER>(const D3D12_ROOT_PARAMETER& obj,
    ToStringFlags               toStringFlags,
    uint32_t                    tabCount,
    uint32_t                    tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ParameterType", toStringFlags, tabCount, tabSize, ToString(obj.ParameterType, toStringFlags, tabCount, tabSize));
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
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, ToString(obj.ShaderVisibility, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_ROOT_PARAMETER1>(const D3D12_ROOT_PARAMETER1& obj,
    ToStringFlags                toStringFlags,
    uint32_t                     tabCount,
    uint32_t                     tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "ParameterType", toStringFlags, tabCount, tabSize, ToString(obj.ParameterType, toStringFlags, tabCount, tabSize));
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
            FieldToString(strStrm, false, "ShaderVisibility", toStringFlags, tabCount, tabSize, ToString(obj.ShaderVisibility, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_INDIRECT_ARGUMENT_DESC>(const D3D12_INDIRECT_ARGUMENT_DESC& obj,
    ToStringFlags                       toStringFlags,
    uint32_t                            tabCount,
    uint32_t                            tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : 
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            switch (obj.Type) {
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
            {

            } break;
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
            {

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
std::string ToString<DXGI_DISPLAY_COLOR_SPACE>(const DXGI_DISPLAY_COLOR_SPACE& obj,
                                               ToStringFlags                   toStringFlags,
                                               uint32_t                        tabCount,
                                               uint32_t                        tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : 
            // FieldToString(strStrm, true, "PrimaryCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.PrimaryCoordinates, toStringFlags, tabCount, tabSize));
            // FieldToString(strStrm, false, "WhitePoints", toStringFlags, tabCount, tabSize, ToString(obj.WhitePoints, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_RAYTRACING_INSTANCE_DESC>(const D3D12_RAYTRACING_INSTANCE_DESC& obj,
                                                     ToStringFlags                         toStringFlags,
                                                     uint32_t                              tabCount,
                                                     uint32_t                              tabSize)
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
            FieldToString(strStrm, false, "InstanceID", toStringFlags, tabCount, tabSize, ToString(obj.InstanceID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InstanceMask", toStringFlags, tabCount, tabSize, ToString(obj.InstanceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "InstanceContributionToHitGroupIndex", toStringFlags, tabCount, tabSize, ToString(obj.InstanceContributionToHitGroupIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AccelerationStructure", toStringFlags, tabCount, tabSize, ToString(obj.AccelerationStructure, toStringFlags, tabCount, tabSize));
        }
    );
    // clang-format on
}

template <>
std::string
ToString<D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION>(const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj,
    ToStringFlags                                      toStringFlags,
    uint32_t                                           tabCount,
    uint32_t                                           tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            // TODO : 
            FieldToString(strStrm, true, "SubobjectToAssociate", toStringFlags, tabCount, tabSize, PtrToString(obj.SubobjectToAssociate));
            FieldToString(strStrm, false, "NumExports", toStringFlags, tabCount, tabSize, ToString(obj.NumExports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExports", toStringFlags, tabCount, tabSize, PtrToString(obj.pExports));
        }
    );
    // clang-format on
}

template <>
std::string ToString<D3D12_RESOURCE_BARRIER>(const D3D12_RESOURCE_BARRIER& obj,
    ToStringFlags                 toStringFlags,
    uint32_t                      tabCount,
    uint32_t                      tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, ToString(obj.Flags, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<D3D12_STATE_SUBOBJECT>(const D3D12_STATE_SUBOBJECT& obj,
    ToStringFlags                toStringFlags,
    uint32_t                     tabCount,
    uint32_t                     tabSize)
{
    // clang-format off
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "Type", toStringFlags, tabCount, tabSize, ToString(obj.Type, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, PtrToString(obj.pDesc));
        }
    );
    // clang-format on
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
