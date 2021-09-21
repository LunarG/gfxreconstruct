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

#include "custom_dx12_struct_ascii_consumers.h"
#include "format/dx12_subobject_types.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void WriteBOOLString(std::ostringstream& oss, const BOOL value, const char* indent, const bool output)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "&";
    }
    if (value == TRUE)
    {
        oss << indent << output_string << "true";
    }
    else
    {
        oss << indent << output_string << "false";
    }
}

void WriteStructString(std::ostringstream&                             oss,
                       const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* value,
                       const char*                                     indent,
                       const bool                                      prefix,
                       const bool                                      output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_PIPELINE_STATE_STREAM_DESC{\n";
    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    size_t   offset = 0;
    bool     first  = true;
    uint8_t* start  = reinterpret_cast<uint8_t*>(value->decoded_value->pPipelineStateSubobjectStream);

    while (offset < value->decoded_value->SizeInBytes)
    {
        auto                                current = start + offset;
        D3D12_PIPELINE_STATE_SUBOBJECT_TYPE type    = *reinterpret_cast<D3D12_PIPELINE_STATE_SUBOBJECT_TYPE*>(current);
        if (first)
        {
            oss << ",\n";
        }
        first = false;
        oss << indent2 << ConverttoText(D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE);
        oss << ",\n";

        switch (type)
        {
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE):
                WriteHandleId(oss, value->root_signature, indent2.c_str(), "ID3D12RootSignature_id");
                offset += sizeof(format::Dx12SignatureSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS):
                WriteStructString(oss, &value->vs_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS):
                WriteStructString(oss, &value->ps_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS):
                WriteStructString(oss, &value->ds_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS):
                WriteStructString(oss, &value->hs_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS):
                WriteStructString(oss, &value->gs_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS):
                WriteStructString(oss, &value->cs_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS):
                WriteStructString(oss, &value->as_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS):
                WriteStructString(oss, &value->ms_bytecode, indent2.c_str());
                offset += sizeof(format::Dx12ShaderBytecodeSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT):
                WriteStructString(oss, &value->stream_output, indent2.c_str());
                offset += sizeof(format::Dx12StreamOutputSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND):
                WriteStructString(oss, &value->blend, indent2.c_str());
                offset += sizeof(format::Dx12BlendSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK):
            {
                auto subobject = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                oss << indent2 << subobject->value;
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER):
                WriteStructString(oss, &value->rasterizer, indent2.c_str());
                offset += sizeof(format::Dx12RasterizerSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL):
                WriteStructString(oss, &value->depth_stencil, indent2.c_str());
                offset += sizeof(format::Dx12DepthStencilSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT):
                WriteStructString(oss, &value->input_layout, indent2.c_str());
                offset += sizeof(format::Dx12InputLayoutSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE):
            {
                auto subobject = reinterpret_cast<format::Dx12StripCutSubobject*>(current);
                oss << indent2 << ConverttoText(subobject->value);
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY):
            {
                auto subobject = reinterpret_cast<format::Dx12PrimitiveTopologySubobject*>(current);
                oss << indent2 << ConverttoText(subobject->value);
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS):
                WriteStructString(oss, &value->render_target_formats, indent2.c_str());
                offset += sizeof(format::Dx12RenderTargetFormatsSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT):
            {
                auto subobject = reinterpret_cast<format::Dx12FormatSubobject*>(current);
                oss << indent2 << ConverttoText(subobject->value);
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC):
                WriteStructString(oss, &value->sample_desc, indent2.c_str());
                offset += sizeof(format::Dx12SampleDescSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK):
            {
                auto subobject = reinterpret_cast<format::Dx12UIntSubobject*>(current);
                oss << indent2 << subobject->value;
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO):
                WriteStructString(oss, &value->cached_pso, indent2.c_str());
                offset += sizeof(format::Dx12CachedPsoSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS):
            {
                auto subobject = reinterpret_cast<format::Dx12TypeFlagsSubobject*>(current);
                oss << indent2 << ConverttoText(subobject->value);
                offset += sizeof(*subobject);
            }
            break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1):
                WriteStructString(oss, &value->depth_stencil1, indent2.c_str());
                offset += sizeof(format::Dx12DepthStencil1Subobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING):
                WriteStructString(oss, &value->view_instancing, indent2.c_str());
                offset += sizeof(format::Dx12ViewInstancingSubobject);
                break;
            case (D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MAX_VALID):
                break;
            default:
                break;
        }
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&              oss,
                       const Decoded_D3D12_CLEAR_VALUE* value,
                       const char*                      indent,
                       const bool                       prefix,
                       const bool                       output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_CLEAR_VALUE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->Color, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->Color, indent2.c_str());
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                   oss,
                       const Decoded_D3D12_RESOURCE_BARRIER* value,
                       const char*                           indent,
                       const bool                            prefix,
                       const bool                            output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_BARRIER{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    switch (value->decoded_value->Type)
    {
        case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            if (WriteCheckStructDecoderNull(oss, value->Transition, indent2.c_str()))
            {
                WriteStructString(oss, value->Transition, indent2.c_str());
            }
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            if (WriteCheckStructDecoderNull(oss, value->Aliasing, indent2.c_str()))
            {
                WriteStructString(oss, value->Aliasing, indent2.c_str());
            }
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            if (WriteCheckStructDecoderNull(oss, value->UAV, indent2.c_str()))
            {
                WriteStructString(oss, value->UAV, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                        oss,
                       const Decoded_D3D12_TEXTURE_COPY_LOCATION* value,
                       const char*                                indent,
                       const bool                                 prefix,
                       const bool                                 output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEXTURE_COPY_LOCATION{\n";
    oss << indent2 << value->pResource;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    switch (value->decoded_value->Type)
    {
        case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            oss << indent2 << value->decoded_value->SubresourceIndex;
            break;
        case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            if (WriteCheckStructDecoderNull(oss, value->PlacedFootprint, indent2.c_str()))
            {
                WriteStructString(oss, value->PlacedFootprint, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                            oss,
                       const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* value,
                       const char*                                    indent,
                       const bool                                     prefix,
                       const bool                                     output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SHADER_RESOURCE_VIEW_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ViewDimension);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Shader4ComponentMapping;
    oss << ",\n";

    switch (value->decoded_value->ViewDimension)
    {
        case D3D12_SRV_DIMENSION_BUFFER:
            if (WriteCheckStructDecoderNull(oss, value->Buffer, indent2.c_str()))
            {
                WriteStructString(oss, value->Buffer, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1D:
            if (WriteCheckStructDecoderNull(oss, value->Texture1D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1D, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture1DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1DArray, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2D:
            if (WriteCheckStructDecoderNull(oss, value->Texture2D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2D, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DArray, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMS, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMS, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMSArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMSArray, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURE3D:
            if (WriteCheckStructDecoderNull(oss, value->Texture3D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture3D, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBE:
            if (WriteCheckStructDecoderNull(oss, value->TextureCube, indent2.c_str()))
            {
                WriteStructString(oss, value->TextureCube, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            if (WriteCheckStructDecoderNull(oss, value->TextureCubeArray, indent2.c_str()))
            {
                WriteStructString(oss, value->TextureCubeArray, indent2.c_str());
            }
            break;
        case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            if (WriteCheckStructDecoderNull(oss, value->RaytracingAccelerationStructure, indent2.c_str()))
            {
                WriteStructString(oss, value->RaytracingAccelerationStructure, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                             oss,
                       const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* value,
                       const char*                                     indent,
                       const bool                                      prefix,
                       const bool                                      output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_UNORDERED_ACCESS_VIEW_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ViewDimension);
    oss << ",\n";

    switch (value->decoded_value->ViewDimension)
    {
        case D3D12_UAV_DIMENSION_BUFFER:
            if (WriteCheckStructDecoderNull(oss, value->Buffer, indent2.c_str()))
            {
                WriteStructString(oss, value->Buffer, indent2.c_str());
            }
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1D:
            if (WriteCheckStructDecoderNull(oss, value->Texture1D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1D, indent2.c_str());
            }
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture1DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1DArray, indent2.c_str());
            }
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2D:
            if (WriteCheckStructDecoderNull(oss, value->Texture2D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2D, indent2.c_str());
            }
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DArray, indent2.c_str());
            }
            break;
        case D3D12_UAV_DIMENSION_TEXTURE3D:
            if (WriteCheckStructDecoderNull(oss, value->Texture3D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture3D, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                          oss,
                       const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* value,
                       const char*                                  indent,
                       const bool                                   prefix,
                       const bool                                   output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_TARGET_VIEW_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ViewDimension);
    oss << ",\n";

    switch (value->decoded_value->ViewDimension)
    {
        case D3D12_RTV_DIMENSION_BUFFER:
            if (WriteCheckStructDecoderNull(oss, value->Buffer, indent2.c_str()))
            {
                WriteStructString(oss, value->Buffer, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1D:
            if (WriteCheckStructDecoderNull(oss, value->Texture1D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1D, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture1DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1DArray, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2D:
            if (WriteCheckStructDecoderNull(oss, value->Texture2D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2D, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DArray, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMS, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMS, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMSArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMSArray, indent2.c_str());
            }
            break;
        case D3D12_RTV_DIMENSION_TEXTURE3D:
            if (WriteCheckStructDecoderNull(oss, value->Texture3D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture3D, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                          oss,
                       const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* value,
                       const char*                                  indent,
                       const bool                                   prefix,
                       const bool                                   output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEPTH_STENCIL_VIEW_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ViewDimension);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    switch (value->decoded_value->ViewDimension)
    {
        case D3D12_DSV_DIMENSION_TEXTURE1D:
            if (WriteCheckStructDecoderNull(oss, value->Texture1D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1D, indent2.c_str());
            }
            break;
        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture1DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture1DArray, indent2.c_str());
            }
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2D:
            if (WriteCheckStructDecoderNull(oss, value->Texture2D, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2D, indent2.c_str());
            }
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DArray, indent2.c_str());
            }
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMS, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMS, indent2.c_str());
            }
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            if (WriteCheckStructDecoderNull(oss, value->Texture2DMSArray, indent2.c_str()))
            {
                WriteStructString(oss, value->Texture2DMSArray, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                 oss,
                       const Decoded_D3D12_ROOT_PARAMETER* value,
                       const char*                         indent,
                       const bool                          prefix,
                       const bool                          output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_PARAMETER{\n";
    oss << indent2 << ConverttoText(value->decoded_value->ParameterType);
    oss << ",\n";

    switch (value->decoded_value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            if (WriteCheckStructDecoderNull(oss, value->DescriptorTable, indent2.c_str()))
            {
                WriteStructString(oss, value->DescriptorTable, indent2.c_str());
            }
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            if (WriteCheckStructDecoderNull(oss, value->Constants, indent2.c_str()))
            {
                WriteStructString(oss, value->Constants, indent2.c_str());
            }
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            if (WriteCheckStructDecoderNull(oss, value->Descriptor, indent2.c_str()))
            {
                WriteStructString(oss, value->Descriptor, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                  oss,
                       const Decoded_D3D12_ROOT_PARAMETER1* value,
                       const char*                          indent,
                       const bool                           prefix,
                       const bool                           output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_PARAMETER1{\n";
    oss << indent2 << ConverttoText(value->decoded_value->ParameterType);
    oss << ",\n";

    switch (value->decoded_value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            if (WriteCheckStructDecoderNull(oss, value->DescriptorTable, indent2.c_str()))
            {
                WriteStructString(oss, value->DescriptorTable, indent2.c_str());
            }
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            if (WriteCheckStructDecoderNull(oss, value->Constants, indent2.c_str()))

            {
                WriteStructString(oss, value->Constants, indent2.c_str());
            }
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            if (WriteCheckStructDecoderNull(oss, value->Descriptor, indent2.c_str()))
            {
                WriteStructString(oss, value->Descriptor, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ShaderVisibility);
    oss << "}";
}

void WriteStructString(std::ostringstream&                                oss,
                       const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* value,
                       const char*                                        indent,
                       const bool                                         prefix,
                       const bool                                         output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VERSIONED_ROOT_SIGNATURE_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Version);
    oss << ",\n";

    switch (value->decoded_value->Version)
    {
        case D3D_ROOT_SIGNATURE_VERSION_1_0:
            if (WriteCheckStructDecoderNull(oss, value->Desc_1_0, indent2.c_str()))
            {
                WriteStructString(oss, value->Desc_1_0, indent2.c_str());
            }
            break;
        case D3D_ROOT_SIGNATURE_VERSION_1_1:
            if (WriteCheckStructDecoderNull(oss, value->Desc_1_1, indent2.c_str()))
            {
                WriteStructString(oss, value->Desc_1_1, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                        oss,
                       const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* value,
                       const char*                                indent,
                       const bool                                 prefix,
                       const bool                                 output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_CPU_DESCRIPTOR_HANDLE{\n";
    oss << indent2 << value->heap_id;
    oss << ",\n";

    oss << indent2 << value->index;
    oss << "}";
}

void WriteStructString(std::ostringstream&                        oss,
                       const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* value,
                       const char*                                indent,
                       const bool                                 prefix,
                       const bool                                 output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GPU_DESCRIPTOR_HANDLE{\n";
    oss << indent2 << value->heap_id;
    oss << ",\n";

    oss << indent2 << value->index;
    oss << "}";
}

void WriteStructString(std::ostringstream&                         oss,
                       const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* value,
                       const char*                                 indent,
                       const bool                                  prefix,
                       const bool                                  output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INDIRECT_ARGUMENT_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Constant.RootParameterIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Constant.DestOffsetIn32BitValues;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Constant.Num32BitValuesToSet;
    oss << "}";
}

void WriteStructString(std::ostringstream&                  oss,
                       const Decoded_D3D12_STATE_SUBOBJECT* value,
                       const char*                          indent,
                       const bool                           prefix,
                       const bool                           output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STATE_SUBOBJECT{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    switch (value->decoded_value->Type)
    {
        case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            if (WriteCheckPointerDecoderNull(oss, value->state_object_config, indent2.c_str()))
            {
                WriteStructString(oss, value->state_object_config->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            if (WriteCheckPointerDecoderNull(oss, value->global_root_signature, indent2.c_str()))
            {
                WriteStructString(oss, value->global_root_signature->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            if (WriteCheckPointerDecoderNull(oss, value->global_root_signature, indent2.c_str()))
            {
                WriteStructString(oss, value->local_root_signature->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            if (WriteCheckPointerDecoderNull(oss, value->node_mask, indent2.c_str()))
            {
                WriteStructString(oss, value->node_mask->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            if (WriteCheckPointerDecoderNull(oss, value->dxil_library_desc, indent2.c_str()))
            {
                WriteStructString(oss, value->dxil_library_desc->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            if (WriteCheckPointerDecoderNull(oss, value->existing_collection_desc, indent2.c_str()))
            {
                WriteStructString(oss, value->existing_collection_desc->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            if (WriteCheckPointerDecoderNull(oss, value->subobject_to_exports_association, indent2.c_str()))
            {
                WriteStructString(
                    oss, value->subobject_to_exports_association->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            if (WriteCheckPointerDecoderNull(oss, value->dxil_subobject_to_exports_association, indent2.c_str()))
            {
                WriteStructString(
                    oss, value->dxil_subobject_to_exports_association->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            if (WriteCheckPointerDecoderNull(oss, value->raytracing_shader_config, indent2.c_str()))
            {
                WriteStructString(oss, value->raytracing_shader_config->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            if (WriteCheckPointerDecoderNull(oss, value->raytracing_pipeline_config, indent2.c_str()))
            {
                WriteStructString(oss, value->raytracing_pipeline_config->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            if (WriteCheckPointerDecoderNull(oss, value->hit_group_desc, indent2.c_str()))
            {
                WriteStructString(oss, value->hit_group_desc->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            if (WriteCheckPointerDecoderNull(oss, value->raytracing_pipeline_config1, indent2.c_str()))
            {
                WriteStructString(oss, value->raytracing_pipeline_config1->GetMetaStructPointer(), indent2.c_str());
            }
            break;
        default:
            break;
    }

    oss << "}";
}

void WriteStructString(std::ostringstream&                                   oss,
                       const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value,
                       const char*                                           indent,
                       const bool                                            prefix,
                       const bool                                            output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION{\n";

    if (WriteCheckPointerDecoderNull(oss, value->pSubobjectToAssociate, indent2.c_str()))
    {
        WriteStructString(oss, value->pSubobjectToAssociate->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumExports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pExports, indent2.c_str()))
    {
        WriteArrayWStringsString(oss, &value->pExports, indent2.c_str());
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                    oss,
                       const Decoded_D3D12_STATE_OBJECT_DESC* value,
                       const char*                            indent,
                       const bool                             prefix,
                       const bool                             output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STATE_OBJECT_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumSubobjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->subobjects, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->subobjects, indent2.c_str());
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                           oss,
                       const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* value,
                       const char*                                   indent,
                       const bool                                    prefix,
                       const bool                                    output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_GEOMETRY_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    switch (value->decoded_value->Type)
    {
        case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            if (WriteCheckStructDecoderNull(oss, value->Triangles, indent2.c_str()))
            {
                WriteStructString(oss, value->Triangles, indent2.c_str());
            }
            break;
        case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            if (WriteCheckStructDecoderNull(oss, value->AABBs, indent2.c_str()))
            {
                WriteStructString(oss, value->AABBs, indent2.c_str());
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                                                 oss,
                       const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* value,
                       const char*                                                         indent,
                       const bool                                                          prefix,
                       const bool                                                          output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumDescs;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DescsLayout);
    oss << ",\n";

    switch (value->decoded_value->Type)
    {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            oss << indent2 << value->decoded_value->InstanceDescs;
            break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            switch (value->decoded_value->DescsLayout)
            {
                case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    if (WriteCheckPointerDecoderNull(oss, value->pGeometryDescs, indent2.c_str()))
                    {
                        WriteArrayStructsString(oss, value->pGeometryDescs, indent2.c_str());
                    }
                    break;
                case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    if (WriteCheckPointerDecoderNull(oss, value->ppGeometryDescs, indent2.c_str()))
                    {
                        WriteArrayStructsString(oss, value->ppGeometryDescs, indent2.c_str());
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    oss << "}";
}

void WriteStructString(std::ostringstream&                                         oss,
                       const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* value,
                       const char*                                                 indent,
                       const bool                                                  prefix,
                       const bool                                                  output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Version);
    oss << ",\n";

    switch (value->decoded_value->Version)
    {
        case D3D12_DRED_VERSION_1_0:
            if (WriteCheckStructDecoderNull(oss, value->Dred_1_0, indent2.c_str()))
            {
                WriteStructString(oss, value->Dred_1_0, indent2.c_str());
            }
            break;
        case D3D12_DRED_VERSION_1_1:
            if (WriteCheckStructDecoderNull(oss, value->Dred_1_1, indent2.c_str()))
            {
                WriteStructString(oss, value->Dred_1_1, indent2.c_str());
            }
            break;
        case D3D12_DRED_VERSION_1_2:
            if (WriteCheckStructDecoderNull(oss, value->Dred_1_2, indent2.c_str()))
            {
                WriteStructString(oss, value->Dred_1_2, indent2.c_str());
            }
            break;
        default:
            break;
    }

    oss << "}";
}

void WriteStructString(std::ostringstream&                               oss,
                       const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* value,
                       const char*                                       indent,
                       const bool                                        prefix,
                       const bool                                        output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_BEGINNING_ACCESS{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    WriteStructString(oss, value->Clear, indent2.c_str());
    oss << "}";
}

void WriteStructString(std::ostringstream&                            oss,
                       const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* value,
                       const char*                                    indent,
                       const bool                                     prefix,
                       const bool                                     output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_ENDING_ACCESS{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    WriteStructString(oss, value->Resolve, indent2.c_str());
    oss << "}";
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
