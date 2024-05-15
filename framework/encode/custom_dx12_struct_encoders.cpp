/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/dx12_object_wrapper_info.h"
#include "encode/dx12_object_wrapper_util.h"
#include "encode/struct_pointer_encoder.h"
#include "format/dx12_subobject_types.h"
#include "format/format.h"
#include "generated/generated_dx12_api_call_encoders.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
void EncodeDescriptorStruct(ParameterEncoder* encoder, const T& value)
{
    format::HandleId heap_id = format::kNullHandleId;
    uint32_t         index   = 0;

    if (value.ptr != 0)
    {
        void*             descriptor_memory = reinterpret_cast<void*>(value.ptr);
        DxDescriptorInfo* descriptor_info   = nullptr;

        util::platform::MemoryCopy(
            &descriptor_info, sizeof(descriptor_info), descriptor_memory, sizeof(descriptor_info));

        heap_id = descriptor_info->heap_id;
        index   = descriptor_info->index;
    }

    encoder->EncodeHandleIdValue(heap_id);
    encoder->EncodeUInt32Value(index);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CPU_DESCRIPTOR_HANDLE& value)
{
    EncodeDescriptorStruct(encoder, value);
}

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
    encoder->EncodeObjectValue(value.pResource);
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
        case D3D_ROOT_SIGNATURE_VERSION_1_2:
            EncodeStruct(encoder, value.Desc_1_2);
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
                    EncodeStructArray2D(encoder, value.ppGeometryDescs, value.NumDescs, 1);
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

void EncodeStruct(ParameterEncoder* encoder, const LARGE_INTEGER& value)
{
    encoder->EncodeInt64Value(value.QuadPart);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PIPELINE_STATE_STREAM_DESC& value)
{
    encoder->EncodeSizeTValue(value.SizeInBytes);

    if ((value.SizeInBytes > 0) && (value.pPipelineStateSubobjectStream != nullptr))
    {
        size_t   offset = 0;
        uint8_t* start  = reinterpret_cast<uint8_t*>(value.pPipelineStateSubobjectStream);

        while (offset < value.SizeInBytes)
        {
            auto current = start + offset;
            auto type    = *reinterpret_cast<D3D12_PIPELINE_STATE_SUBOBJECT_TYPE*>(current);

            switch (type)
            {
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE:
                {
                    auto subobject = reinterpret_cast<format::Dx12SignatureSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeObjectValue(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS:
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS:
                {
                    // These subobject types can share the same encoding code for the D3D12_SHADER_BYTECODE type.
                    auto subobject = reinterpret_cast<format::Dx12ShaderBytecodeSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT:
                {
                    auto subobject = reinterpret_cast<format::Dx12StreamOutputSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND:
                {
                    auto subobject = reinterpret_cast<format::Dx12BlendSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK:
                {
                    auto subobject = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeUInt32Value(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER:
                {
                    auto subobject = reinterpret_cast<format::Dx12RasterizerSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL:
                {
                    auto subobject = reinterpret_cast<format::Dx12DepthStencilSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT:
                {
                    auto subobject = reinterpret_cast<format::Dx12InputLayoutSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE:
                {
                    auto subobject = reinterpret_cast<format::Dx12StripCutSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeEnumValue(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY:
                {
                    auto subobject = reinterpret_cast<format::Dx12PrimitiveTopologySubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeEnumValue(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS:
                {
                    auto subobject = reinterpret_cast<format::Dx12RenderTargetFormatsSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT:
                {
                    auto subobject = reinterpret_cast<format::Dx12FormatSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeEnumValue(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC:
                {
                    auto subobject = reinterpret_cast<format::Dx12SampleDescSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK:
                {
                    auto subobject = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeUInt32Value(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO:
                {
                    auto subobject = reinterpret_cast<format::Dx12CachedPsoSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS:
                {
                    auto subobject = reinterpret_cast<format::Dx12TypeFlagsSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    encoder->EncodeEnumValue(subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1:
                {
                    auto subobject = reinterpret_cast<format::Dx12DepthStencil1Subobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                case D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING:
                {
                    auto subobject = reinterpret_cast<format::Dx12ViewInstancingSubobject*>(current);
                    encoder->EncodeEnumValue(type);
                    EncodeStruct(encoder, subobject->value);
                    offset += sizeof(*subobject);
                    break;
                }
                default:
                    // Type is unrecognized.  Write an invalid enum value so the decoder know the data is incomplete,
                    // and log a warning.
                    encoder->EncodeUInt32Value(format::kInvalidSubobjectType);
                    offset = value.SizeInBytes;

                    GFXRECON_LOG_WARNING(
                        "A pipeline state subobject with unrecognized D3D12_PIPELINE_STATE_SUBOBJECT_TYPE = %d was "
                        "omitted from the capture file, which may cause replay to fail.",
                        type);

                    break;
            }
        }
    }
}

void EncodeD3D12FeatureStruct(ParameterEncoder* encoder, void* feature_data, D3D12_FEATURE feature)
{
    switch (feature)
    {
        case D3D12_FEATURE_D3D12_OPTIONS:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS*>(feature_data));
            break;
        case D3D12_FEATURE_ARCHITECTURE:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_ARCHITECTURE*>(feature_data));
            break;
        case D3D12_FEATURE_FEATURE_LEVELS:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_FEATURE_LEVELS*>(feature_data));
            break;
        case D3D12_FEATURE_FORMAT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_FORMAT_SUPPORT*>(feature_data));
            break;
        case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS*>(feature_data));
            break;
        case D3D12_FEATURE_FORMAT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_FORMAT_INFO*>(feature_data));
            break;
        case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(feature_data));
            break;
        case D3D12_FEATURE_SHADER_MODEL:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_SHADER_MODEL*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS1:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS1*>(feature_data));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
            EncodeStructPtr(encoder,
                            reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT*>(feature_data));
            break;
        case D3D12_FEATURE_ROOT_SIGNATURE:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_ROOT_SIGNATURE*>(feature_data));
            break;
        case D3D12_FEATURE_ARCHITECTURE1:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_ARCHITECTURE1*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS2:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS2*>(feature_data));
            break;
        case D3D12_FEATURE_SHADER_CACHE:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_SHADER_CACHE*>(feature_data));
            break;
        case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS3:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS3*>(feature_data));
            break;
        case D3D12_FEATURE_EXISTING_HEAPS:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_EXISTING_HEAPS*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS4:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS4*>(feature_data));
            break;
        case D3D12_FEATURE_SERIALIZATION:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_SERIALIZATION*>(feature_data));
            break;
        case D3D12_FEATURE_CROSS_NODE:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_CROSS_NODE*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS5:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(feature_data));
            break;
        case D3D12_FEATURE_DISPLAYABLE:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_DISPLAYABLE*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS6:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS6*>(feature_data));
            break;
        case D3D12_FEATURE_QUERY_META_COMMAND:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_QUERY_META_COMMAND*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS7:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS7*>(feature_data));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
            EncodeStructPtr(encoder,
                            reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT*>(feature_data));
            break;
        case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
            EncodeStructPtr(encoder,
                            reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS8:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS8*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS9:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS9*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS10:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS10*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS11:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS11*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS12:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS12*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS13:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS13*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS14:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS14*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS15:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS15*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS16:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS16*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS17:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS17*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS18:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS18*>(feature_data));
            break;
        case D3D12_FEATURE_D3D12_OPTIONS19:
            EncodeStructPtr(encoder, reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS19*>(feature_data));
            break;
        default:
            GFXRECON_LOG_WARNING("Failed to encode ID3D12Device::CheckFeatureSupport pFeatureData parameter with "
                                 "unrecognized D3D12_FEATURE type %d",
                                 feature);
            break;
    }
}

void EncodeDXGIFeatureStruct(ParameterEncoder* encoder, void* feature_data, DXGI_FEATURE feature)
{
    switch (feature)
    {
        case DXGI_FEATURE_PRESENT_ALLOW_TEARING:
            encoder->EncodeInt32Value(*reinterpret_cast<int32_t*>(feature_data));
            break;
        default:
            GFXRECON_LOG_FATAL("Failed to encode IDXGIFactory5::CheckFeatureSupport pFeatureData parameter with "
                               "unrecognized DXGI_FEATURE type %d",
                               feature);
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.NumSubobjects);

    // Encode the size of the D3D12_STATE_SUBOBJECT struct to use when computing the start address for each element in
    // the array when searching for a match to D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION::pSubobjectToAssociate.
    encoder->EncodeSizeTValue(sizeof(value.pSubobjects[0]));

    EncodeStructArray(encoder, value.pSubobjects, value.NumSubobjects);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_SUBOBJECT& value)
{
    encoder->EncodeEnumValue(value.Type);
    if (value.pDesc)
    {
        switch (value.Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_STATE_OBJECT_CONFIG*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_GLOBAL_ROOT_SIGNATURE*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_LOCAL_ROOT_SIGNATURE*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_NODE_MASK*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_DXIL_LIBRARY_DESC*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_EXISTING_COLLECTION_DESC*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                EncodeStructPtr(encoder,
                                reinterpret_cast<const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_RAYTRACING_SHADER_CONFIG*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_RAYTRACING_PIPELINE_CONFIG*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_HIT_GROUP_DESC*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
                EncodeStructPtr(encoder, reinterpret_cast<const D3D12_RAYTRACING_PIPELINE_CONFIG1*>(value.pDesc));
                break;
            case D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID:
                break;
            default:
                break;
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value)
{
    EncodeStructPtr(encoder, value.pSubobjectToAssociate);
    encoder->EncodeUInt32Value(value.NumExports);
    encoder->EncodeWStringArray(value.pExports, value.NumExports);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BARRIER_GROUP& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.NumBarriers);

    switch (value.Type)
    {
        case D3D12_BARRIER_TYPE_GLOBAL:
            EncodeStructArray(encoder, value.pGlobalBarriers, value.NumBarriers);
            break;
        case D3D12_BARRIER_TYPE_TEXTURE:
            EncodeStructArray(encoder, value.pTextureBarriers, value.NumBarriers);
            break;
        case D3D12_BARRIER_TYPE_BUFFER:
            EncodeStructArray(encoder, value.pBufferBarriers, value.NumBarriers);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLER_DESC2& value)
{
    encoder->EncodeEnumValue(value.Filter);
    encoder->EncodeEnumValue(value.AddressU);
    encoder->EncodeEnumValue(value.AddressV);
    encoder->EncodeEnumValue(value.AddressW);
    encoder->EncodeFloatValue(value.MipLODBias);
    encoder->EncodeUInt32Value(value.MaxAnisotropy);
    encoder->EncodeEnumValue(value.ComparisonFunc);
    encoder->EncodeFloatArray(value.FloatBorderColor, 4);
    encoder->EncodeFloatValue(value.MinLOD);
    encoder->EncodeFloatValue(value.MaxLOD);
    encoder->EncodeEnumValue(value.Flags);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
