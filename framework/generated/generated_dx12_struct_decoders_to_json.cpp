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
** This file is generated from dx12_struct_decoders_to_json_body_generator.py.
**
*/

#if defined(D3D12_SUPPORT)

#include "generated_dx12_struct_decoders_to_json.h"
#include "generated_dx12_enum_to_json.h"
#include "decode/custom_dx12_struct_decoders.h"
#include "decode/decode_json_util.h"
#include "graphics/dx12_util.h"
#include "util/json_util.h"
#include "format/format_json.h"

/// @file Implementations of functions for converting decoded D3D12 structs to JSON.

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::FieldToJson;
using util::Bool32ToJson;
using util::RepresentBinaryFile;

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup ManualD3D12StructFieldToJsons Manual functions to convert raw structs.
/** @{ */
static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data)
{
    jdata["AdditionalWidth"] = data.AdditionalWidth;
    jdata["AdditionalHeight"] = data.AdditionalHeight;
}

static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data)
{
    jdata["AdditionalWidth"] = data.AdditionalWidth;
    jdata["AdditionalHeight"] = data.AdditionalHeight;
}

/// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj)
{
    FieldToJson(jdata["Depth"], obj.Depth);
    jdata["Stencil"] = obj.Stencil;
}
/** @} */

inline bool RepresentBinaryFile(nlohmann::ordered_json& jdata, std::string_view filename_base, const uint64_t instance_counter, const PointerDecoder<uint8_t>& data)
{
    return RepresentBinaryFile(jdata, filename_base, instance_counter, data.GetLength(), data.GetPointer());
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_QUEUE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_QUEUE_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Priority"] = decoded_value.Priority;
        jdata["Flags"] = D3D12_COMMAND_QUEUE_FLAGS_t{ decoded_value.Flags };
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_ELEMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_ELEMENT_DESC& meta_struct = *data;
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName);
        jdata["SemanticIndex"] = decoded_value.SemanticIndex;
        jdata["Format"] = decoded_value.Format;
        jdata["InputSlot"] = decoded_value.InputSlot;
        jdata["AlignedByteOffset"] = decoded_value.AlignedByteOffset;
        jdata["InputSlotClass"] = decoded_value.InputSlotClass;
        jdata["InstanceDataStepRate"] = decoded_value.InstanceDataStepRate;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SO_DECLARATION_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SO_DECLARATION_ENTRY& meta_struct = *data;
        jdata["Stream"] = decoded_value.Stream;
        FieldToJson(jdata["SemanticName"], meta_struct.SemanticName);
        jdata["SemanticIndex"] = decoded_value.SemanticIndex;
        jdata["StartComponent"] = decoded_value.StartComponent;
        jdata["ComponentCount"] = decoded_value.ComponentCount;
        jdata["OutputSlot"] = decoded_value.OutputSlot;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEWPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEWPORT& meta_struct = *data;
        FieldToJson(jdata["TopLeftX"], decoded_value.TopLeftX);
        FieldToJson(jdata["TopLeftY"], decoded_value.TopLeftY);
        FieldToJson(jdata["Width"], decoded_value.Width);
        FieldToJson(jdata["Height"], decoded_value.Height);
        FieldToJson(jdata["MinDepth"], decoded_value.MinDepth);
        FieldToJson(jdata["MaxDepth"], decoded_value.MaxDepth);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BOX& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BOX& meta_struct = *data;
        jdata["left"] = decoded_value.left;
        jdata["top"] = decoded_value.top;
        jdata["front"] = decoded_value.front;
        jdata["right"] = decoded_value.right;
        jdata["bottom"] = decoded_value.bottom;
        jdata["back"] = decoded_value.back;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const LUID& decoded_value = *data->decoded_value;
        const Decoded_LUID& meta_struct = *data;
        jdata["LowPart"] = decoded_value.LowPart;
        jdata["HighPart"] = decoded_value.HighPart;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC& meta_struct = *data;
        jdata["StencilFailOp"] = decoded_value.StencilFailOp;
        jdata["StencilDepthFailOp"] = decoded_value.StencilDepthFailOp;
        jdata["StencilPassOp"] = decoded_value.StencilPassOp;
        jdata["StencilFunc"] = decoded_value.StencilFunc;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable);
        jdata["DepthWriteMask"] = decoded_value.DepthWriteMask;
        jdata["DepthFunc"] = decoded_value.DepthFunc;
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC1& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable);
        jdata["DepthWriteMask"] = decoded_value.DepthWriteMask;
        jdata["DepthFunc"] = decoded_value.DepthFunc;
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCILOP_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCILOP_DESC1& meta_struct = *data;
        jdata["StencilFailOp"] = decoded_value.StencilFailOp;
        jdata["StencilDepthFailOp"] = decoded_value.StencilDepthFailOp;
        jdata["StencilPassOp"] = decoded_value.StencilPassOp;
        jdata["StencilFunc"] = decoded_value.StencilFunc;
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], decoded_value.StencilReadMask);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], decoded_value.StencilWriteMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_DESC2& meta_struct = *data;
        Bool32ToJson(jdata["DepthEnable"], decoded_value.DepthEnable);
        jdata["DepthWriteMask"] = decoded_value.DepthWriteMask;
        jdata["DepthFunc"] = decoded_value.DepthFunc;
        Bool32ToJson(jdata["StencilEnable"], decoded_value.StencilEnable);
        FieldToJson(jdata["FrontFace"], meta_struct.FrontFace);
        FieldToJson(jdata["BackFace"], meta_struct.BackFace);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], decoded_value.DepthBoundsTestEnable);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["BlendEnable"], decoded_value.BlendEnable);
        Bool32ToJson(jdata["LogicOpEnable"], decoded_value.LogicOpEnable);
        jdata["SrcBlend"] = decoded_value.SrcBlend;
        jdata["DestBlend"] = decoded_value.DestBlend;
        jdata["BlendOp"] = decoded_value.BlendOp;
        jdata["SrcBlendAlpha"] = decoded_value.SrcBlendAlpha;
        jdata["DestBlendAlpha"] = decoded_value.DestBlendAlpha;
        jdata["BlendOpAlpha"] = decoded_value.BlendOpAlpha;
        jdata["LogicOp"] = decoded_value.LogicOp;
        FieldToJsonAsFixedWidthBinary(jdata["RenderTargetWriteMask"], decoded_value.RenderTargetWriteMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BLEND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BLEND_DESC& meta_struct = *data;
        Bool32ToJson(jdata["AlphaToCoverageEnable"], decoded_value.AlphaToCoverageEnable);
        Bool32ToJson(jdata["IndependentBlendEnable"], decoded_value.IndependentBlendEnable);
        FieldToJson(jdata["RenderTarget"], meta_struct.RenderTarget);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC& meta_struct = *data;
        jdata["FillMode"] = decoded_value.FillMode;
        jdata["CullMode"] = decoded_value.CullMode;
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise);
        jdata["DepthBias"] = decoded_value.DepthBias;
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable);
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable);
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable);
        jdata["ForcedSampleCount"] = decoded_value.ForcedSampleCount;
        jdata["ConservativeRaster"] = decoded_value.ConservativeRaster;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC1& meta_struct = *data;
        jdata["FillMode"] = decoded_value.FillMode;
        jdata["CullMode"] = decoded_value.CullMode;
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise);
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias);
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable);
        Bool32ToJson(jdata["MultisampleEnable"], decoded_value.MultisampleEnable);
        Bool32ToJson(jdata["AntialiasedLineEnable"], decoded_value.AntialiasedLineEnable);
        jdata["ForcedSampleCount"] = decoded_value.ForcedSampleCount;
        jdata["ConservativeRaster"] = decoded_value.ConservativeRaster;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RASTERIZER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RASTERIZER_DESC2& meta_struct = *data;
        jdata["FillMode"] = decoded_value.FillMode;
        jdata["CullMode"] = decoded_value.CullMode;
        Bool32ToJson(jdata["FrontCounterClockwise"], decoded_value.FrontCounterClockwise);
        FieldToJson(jdata["DepthBias"], decoded_value.DepthBias);
        FieldToJson(jdata["DepthBiasClamp"], decoded_value.DepthBiasClamp);
        FieldToJson(jdata["SlopeScaledDepthBias"], decoded_value.SlopeScaledDepthBias);
        Bool32ToJson(jdata["DepthClipEnable"], decoded_value.DepthClipEnable);
        jdata["LineRasterizationMode"] = decoded_value.LineRasterizationMode;
        jdata["ForcedSampleCount"] = decoded_value.ForcedSampleCount;
        jdata["ConservativeRaster"] = decoded_value.ConservativeRaster;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_BYTECODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_BYTECODE& meta_struct = *data;
        static thread_local uint64_t D3D12_SHADER_BYTECODE_pShaderBytecode_counter{ 0 };
        const bool written = RepresentBinaryFile(jdata["pShaderBytecode"], "D3D12_SHADER_BYTECODE.pShaderBytecode", D3D12_SHADER_BYTECODE_pShaderBytecode_counter, meta_struct.pShaderBytecode);
        D3D12_SHADER_BYTECODE_pShaderBytecode_counter += written;

        jdata["BytecodeLength"] = decoded_value.BytecodeLength;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pSODeclaration"], meta_struct.pSODeclaration);
        jdata["NumEntries"] = decoded_value.NumEntries;
        FieldToJson(jdata["pBufferStrides"], meta_struct.pBufferStrides);
        jdata["NumStrides"] = decoded_value.NumStrides;
        jdata["RasterizedStream"] = decoded_value.RasterizedStream;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INPUT_LAYOUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INPUT_LAYOUT_DESC& meta_struct = *data;
        FieldToJson(jdata["pInputElementDescs"], meta_struct.pInputElementDescs);
        jdata["NumElements"] = decoded_value.NumElements;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CACHED_PIPELINE_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CACHED_PIPELINE_STATE& meta_struct = *data;
        FieldToJson(jdata["pCachedBlob"], meta_struct.pCachedBlob);
        jdata["CachedBlobSizeInBytes"] = decoded_value.CachedBlobSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& meta_struct = *data;
        HandleToJson(jdata["pRootSignature"], meta_struct.pRootSignature);
        FieldToJson(jdata["VS"], meta_struct.VS);
        FieldToJson(jdata["PS"], meta_struct.PS);
        FieldToJson(jdata["DS"], meta_struct.DS);
        FieldToJson(jdata["HS"], meta_struct.HS);
        FieldToJson(jdata["GS"], meta_struct.GS);
        FieldToJson(jdata["StreamOutput"], meta_struct.StreamOutput);
        FieldToJson(jdata["BlendState"], meta_struct.BlendState);
        FieldToJsonAsFixedWidthBinary(jdata["SampleMask"], decoded_value.SampleMask);
        FieldToJson(jdata["RasterizerState"], meta_struct.RasterizerState);
        FieldToJson(jdata["DepthStencilState"], meta_struct.DepthStencilState);
        FieldToJson(jdata["InputLayout"], meta_struct.InputLayout);
        jdata["IBStripCutValue"] = decoded_value.IBStripCutValue;
        jdata["PrimitiveTopologyType"] = decoded_value.PrimitiveTopologyType;
        jdata["NumRenderTargets"] = decoded_value.NumRenderTargets;
        FieldToJson(jdata["RTVFormats"], meta_struct.RTVFormats);
        jdata["DSVFormat"] = decoded_value.DSVFormat;
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO);
        jdata["Flags"] = D3D12_PIPELINE_STATE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMPUTE_PIPELINE_STATE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& meta_struct = *data;
        HandleToJson(jdata["pRootSignature"], meta_struct.pRootSignature);
        FieldToJson(jdata["CS"], meta_struct.CS);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
        FieldToJson(jdata["CachedPSO"], meta_struct.CachedPSO);
        jdata["Flags"] = D3D12_PIPELINE_STATE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_ROOT_SIGNATURE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_ROOT_SIGNATURE_DESC& meta_struct = *data;
        FieldToJson(jdata["pSerializedBlob"], meta_struct.pSerializedBlob);
        jdata["SerializedBlobSizeInBytes"] = decoded_value.SerializedBlobSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_SERIALIZED_ROOT_SIGNATURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_SERIALIZED_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_SERIALIZED_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["Desc"], meta_struct.Desc);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_SERIALIZED_ROOT_SIGNATURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_SERIALIZED_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_SERIALIZED_ROOT_SIGNATURE& meta_struct = *data;
        FieldToJson(jdata["Desc"], meta_struct.Desc);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RT_FORMAT_ARRAY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RT_FORMAT_ARRAY& meta_struct = *data;
        FieldToJson(jdata["RTFormats"], meta_struct.RTFormats);
        jdata["NumRenderTargets"] = decoded_value.NumRenderTargets;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& meta_struct = *data;
        Bool32ToJson(jdata["DoublePrecisionFloatShaderOps"], decoded_value.DoublePrecisionFloatShaderOps);
        Bool32ToJson(jdata["OutputMergerLogicOp"], decoded_value.OutputMergerLogicOp);
        jdata["MinPrecisionSupport"] = D3D12_SHADER_MIN_PRECISION_SUPPORT_t{ decoded_value.MinPrecisionSupport };
        jdata["TiledResourcesTier"] = decoded_value.TiledResourcesTier;
        jdata["ResourceBindingTier"] = decoded_value.ResourceBindingTier;
        Bool32ToJson(jdata["PSSpecifiedStencilRefSupported"], decoded_value.PSSpecifiedStencilRefSupported);
        Bool32ToJson(jdata["TypedUAVLoadAdditionalFormats"], decoded_value.TypedUAVLoadAdditionalFormats);
        Bool32ToJson(jdata["ROVsSupported"], decoded_value.ROVsSupported);
        jdata["ConservativeRasterizationTier"] = decoded_value.ConservativeRasterizationTier;
        jdata["MaxGPUVirtualAddressBitsPerResource"] = decoded_value.MaxGPUVirtualAddressBitsPerResource;
        Bool32ToJson(jdata["StandardSwizzle64KBSupported"], decoded_value.StandardSwizzle64KBSupported);
        jdata["CrossNodeSharingTier"] = decoded_value.CrossNodeSharingTier;
        Bool32ToJson(jdata["CrossAdapterRowMajorTextureSupported"], decoded_value.CrossAdapterRowMajorTextureSupported);
        Bool32ToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], decoded_value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation);
        jdata["ResourceHeapTier"] = decoded_value.ResourceHeapTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& meta_struct = *data;
        Bool32ToJson(jdata["WaveOps"], decoded_value.WaveOps);
        jdata["WaveLaneCountMin"] = decoded_value.WaveLaneCountMin;
        jdata["WaveLaneCountMax"] = decoded_value.WaveLaneCountMax;
        jdata["TotalLaneCount"] = decoded_value.TotalLaneCount;
        Bool32ToJson(jdata["ExpandedComputeResourceStates"], decoded_value.ExpandedComputeResourceStates);
        Bool32ToJson(jdata["Int64ShaderOps"], decoded_value.Int64ShaderOps);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& meta_struct = *data;
        Bool32ToJson(jdata["DepthBoundsTestSupported"], decoded_value.DepthBoundsTestSupported);
        jdata["ProgrammableSamplePositionsTier"] = decoded_value.ProgrammableSamplePositionsTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& meta_struct = *data;
        jdata["HighestVersion"] = decoded_value.HighestVersion;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer);
        Bool32ToJson(jdata["UMA"], decoded_value.UMA);
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_ARCHITECTURE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        Bool32ToJson(jdata["TileBasedRenderer"], decoded_value.TileBasedRenderer);
        Bool32ToJson(jdata["UMA"], decoded_value.UMA);
        Bool32ToJson(jdata["CacheCoherentUMA"], decoded_value.CacheCoherentUMA);
        Bool32ToJson(jdata["IsolatedMMU"], decoded_value.IsolatedMMU);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FEATURE_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& meta_struct = *data;
        jdata["NumFeatureLevels"] = decoded_value.NumFeatureLevels;
        FieldToJson(jdata["pFeatureLevelsRequested"], meta_struct.pFeatureLevelsRequested);
        jdata["MaxSupportedFeatureLevel"] = decoded_value.MaxSupportedFeatureLevel;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_MODEL& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& meta_struct = *data;
        jdata["HighestShaderModel"] = decoded_value.HighestShaderModel;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["Support1"] = D3D12_FORMAT_SUPPORT1_t{ decoded_value.Support1 };
        jdata["Support2"] = D3D12_FORMAT_SUPPORT2_t{ decoded_value.Support2 };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["SampleCount"] = decoded_value.SampleCount;
        jdata["Flags"] = D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS_t{ decoded_value.Flags };
        jdata["NumQualityLevels"] = decoded_value.NumQualityLevels;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_FORMAT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["PlaneCount"] = decoded_value.PlaneCount;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& meta_struct = *data;
        jdata["MaxGPUVirtualAddressBitsPerResource"] = decoded_value.MaxGPUVirtualAddressBitsPerResource;
        jdata["MaxGPUVirtualAddressBitsPerProcess"] = decoded_value.MaxGPUVirtualAddressBitsPerProcess;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADER_CACHE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& meta_struct = *data;
        jdata["SupportFlags"] = D3D12_SHADER_CACHE_SUPPORT_FLAGS_t{ decoded_value.SupportFlags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& meta_struct = *data;
        jdata["CommandListType"] = decoded_value.CommandListType;
        jdata["Priority"] = decoded_value.Priority;
        Bool32ToJson(jdata["PriorityForTypeIsSupported"], decoded_value.PriorityForTypeIsSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& meta_struct = *data;
        Bool32ToJson(jdata["CopyQueueTimestampQueriesSupported"], decoded_value.CopyQueueTimestampQueriesSupported);
        Bool32ToJson(jdata["CastingFullyTypedFormatSupported"], decoded_value.CastingFullyTypedFormatSupported);
        jdata["WriteBufferImmediateSupportFlags"] = D3D12_COMMAND_LIST_SUPPORT_FLAGS_t{ decoded_value.WriteBufferImmediateSupportFlags };
        jdata["ViewInstancingTier"] = decoded_value.ViewInstancingTier;
        Bool32ToJson(jdata["BarycentricsSupported"], decoded_value.BarycentricsSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_EXISTING_HEAPS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_DISPLAYABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& meta_struct = *data;
        Bool32ToJson(jdata["DisplayableTexture"], decoded_value.DisplayableTexture);
        jdata["SharedResourceCompatibilityTier"] = decoded_value.SharedResourceCompatibilityTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS4& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& meta_struct = *data;
        Bool32ToJson(jdata["MSAA64KBAlignedTextureSupported"], decoded_value.MSAA64KBAlignedTextureSupported);
        jdata["SharedResourceCompatibilityTier"] = decoded_value.SharedResourceCompatibilityTier;
        Bool32ToJson(jdata["Native16BitShaderOpsSupported"], decoded_value.Native16BitShaderOpsSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SERIALIZATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        jdata["HeapSerializationTier"] = decoded_value.HeapSerializationTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_CROSS_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& meta_struct = *data;
        jdata["SharingTier"] = decoded_value.SharingTier;
        Bool32ToJson(jdata["AtomicShaderInstructions"], decoded_value.AtomicShaderInstructions);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS5& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& meta_struct = *data;
        Bool32ToJson(jdata["SRVOnlyTiledResourceTier3"], decoded_value.SRVOnlyTiledResourceTier3);
        jdata["RenderPassesTier"] = decoded_value.RenderPassesTier;
        jdata["RaytracingTier"] = decoded_value.RaytracingTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS6& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& meta_struct = *data;
        Bool32ToJson(jdata["AdditionalShadingRatesSupported"], decoded_value.AdditionalShadingRatesSupported);
        Bool32ToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], decoded_value.PerPrimitiveShadingRateSupportedWithViewportIndexing);
        jdata["VariableShadingRateTier"] = decoded_value.VariableShadingRateTier;
        jdata["ShadingRateImageTileSize"] = decoded_value.ShadingRateImageTileSize;
        Bool32ToJson(jdata["BackgroundProcessingSupported"], decoded_value.BackgroundProcessingSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS7& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& meta_struct = *data;
        jdata["MeshShaderTier"] = decoded_value.MeshShaderTier;
        jdata["SamplerFeedbackTier"] = decoded_value.SamplerFeedbackTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_QUERY_META_COMMAND& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& meta_struct = *data;
        FieldToJson(jdata["CommandId"], meta_struct.CommandId);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
        FieldToJson(jdata["pQueryInputData"], meta_struct.pQueryInputData);
        jdata["QueryInputDataSizeInBytes"] = decoded_value.QueryInputDataSizeInBytes;
        FieldToJson(jdata["pQueryOutputData"], meta_struct.pQueryOutputData);
        jdata["QueryOutputDataSizeInBytes"] = decoded_value.QueryOutputDataSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS8& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& meta_struct = *data;
        Bool32ToJson(jdata["UnalignedBlockTexturesSupported"], decoded_value.UnalignedBlockTexturesSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS9& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& meta_struct = *data;
        Bool32ToJson(jdata["MeshShaderPipelineStatsSupported"], decoded_value.MeshShaderPipelineStatsSupported);
        Bool32ToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], decoded_value.MeshShaderSupportsFullRangeRenderTargetArrayIndex);
        Bool32ToJson(jdata["AtomicInt64OnTypedResourceSupported"], decoded_value.AtomicInt64OnTypedResourceSupported);
        Bool32ToJson(jdata["AtomicInt64OnGroupSharedSupported"], decoded_value.AtomicInt64OnGroupSharedSupported);
        Bool32ToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], decoded_value.DerivativesInMeshAndAmplificationShadersSupported);
        jdata["WaveMMATier"] = decoded_value.WaveMMATier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS10& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& meta_struct = *data;
        Bool32ToJson(jdata["VariableRateShadingSumCombinerSupported"], decoded_value.VariableRateShadingSumCombinerSupported);
        Bool32ToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], decoded_value.MeshShaderPerPrimitiveShadingRateSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS11& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& meta_struct = *data;
        Bool32ToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], decoded_value.AtomicInt64OnDescriptorHeapResourceSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS12& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& meta_struct = *data;
        jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"] = decoded_value.MSPrimitivesPipelineStatisticIncludesCulledPrimitives;
        Bool32ToJson(jdata["EnhancedBarriersSupported"], decoded_value.EnhancedBarriersSupported);
        Bool32ToJson(jdata["RelaxedFormatCastingSupported"], decoded_value.RelaxedFormatCastingSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS13& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& meta_struct = *data;
        Bool32ToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], decoded_value.UnrestrictedBufferTextureCopyPitchSupported);
        Bool32ToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], decoded_value.UnrestrictedVertexElementAlignmentSupported);
        Bool32ToJson(jdata["InvertedViewportHeightFlipsYSupported"], decoded_value.InvertedViewportHeightFlipsYSupported);
        Bool32ToJson(jdata["InvertedViewportDepthFlipsZSupported"], decoded_value.InvertedViewportDepthFlipsZSupported);
        Bool32ToJson(jdata["TextureCopyBetweenDimensionsSupported"], decoded_value.TextureCopyBetweenDimensionsSupported);
        Bool32ToJson(jdata["AlphaBlendFactorSupported"], decoded_value.AlphaBlendFactorSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS14& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& meta_struct = *data;
        Bool32ToJson(jdata["AdvancedTextureOpsSupported"], decoded_value.AdvancedTextureOpsSupported);
        Bool32ToJson(jdata["WriteableMSAATexturesSupported"], decoded_value.WriteableMSAATexturesSupported);
        Bool32ToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], decoded_value.IndependentFrontAndBackStencilRefMaskSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS15& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& meta_struct = *data;
        Bool32ToJson(jdata["TriangleFanSupported"], decoded_value.TriangleFanSupported);
        Bool32ToJson(jdata["DynamicIndexBufferStripCutSupported"], decoded_value.DynamicIndexBufferStripCutSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS16& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& meta_struct = *data;
        Bool32ToJson(jdata["DynamicDepthBiasSupported"], decoded_value.DynamicDepthBiasSupported);
        Bool32ToJson(jdata["GPUUploadHeapSupported"], decoded_value.GPUUploadHeapSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS17& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& meta_struct = *data;
        Bool32ToJson(jdata["NonNormalizedCoordinateSamplersSupported"], decoded_value.NonNormalizedCoordinateSamplersSupported);
        Bool32ToJson(jdata["ManualWriteTrackingResourceSupported"], decoded_value.ManualWriteTrackingResourceSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS18& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& meta_struct = *data;
        Bool32ToJson(jdata["RenderPassesValid"], decoded_value.RenderPassesValid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS19& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& meta_struct = *data;
        Bool32ToJson(jdata["MismatchingOutputDimensionsSupported"], decoded_value.MismatchingOutputDimensionsSupported);
        jdata["SupportedSampleCountsWithNoOutputs"] = decoded_value.SupportedSampleCountsWithNoOutputs;
        Bool32ToJson(jdata["PointSamplingAddressesNeverRoundUp"], decoded_value.PointSamplingAddressesNeverRoundUp);
        Bool32ToJson(jdata["RasterizerDesc2Supported"], decoded_value.RasterizerDesc2Supported);
        Bool32ToJson(jdata["NarrowQuadrilateralLinesSupported"], decoded_value.NarrowQuadrilateralLinesSupported);
        Bool32ToJson(jdata["AnisoFilterWithPointMipSupported"], decoded_value.AnisoFilterWithPointMipSupported);
        jdata["MaxSamplerDescriptorHeapSize"] = decoded_value.MaxSamplerDescriptorHeapSize;
        jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"] = decoded_value.MaxSamplerDescriptorHeapSizeWithStaticSamplers;
        jdata["MaxViewDescriptorHeapSize"] = decoded_value.MaxViewDescriptorHeapSize;
        Bool32ToJson(jdata["ComputeOnlyCustomHeapSupported"], decoded_value.ComputeOnlyCustomHeapSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS20& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20& meta_struct = *data;
        Bool32ToJson(jdata["ComputeOnlyWriteWatchSupported"], decoded_value.ComputeOnlyWriteWatchSupported);
        jdata["RecreateAtTier"] = decoded_value.RecreateAtTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_D3D12_OPTIONS21& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21& meta_struct = *data;
        jdata["WorkGraphsTier"] = decoded_value.WorkGraphsTier;
        jdata["ExecuteIndirectTier"] = decoded_value.ExecuteIndirectTier;
        Bool32ToJson(jdata["SampleCmpGradientAndBiasSupported"], decoded_value.SampleCmpGradientAndBiasSupported);
        Bool32ToJson(jdata["ExtendedCommandInfoSupported"], decoded_value.ExtendedCommandInfoSupported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_TIGHT_ALIGNMENT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_TIGHT_ALIGNMENT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_TIGHT_ALIGNMENT& meta_struct = *data;
        jdata["SupportTier"] = decoded_value.SupportTier;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PREDICATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PREDICATION& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_HARDWARE_COPY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED& meta_struct = *data;
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& meta_struct = *data;
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        jdata["Alignment"] = decoded_value.Alignment;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALLOCATION_INFO1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& meta_struct = *data;
        jdata["Offset"] = decoded_value.Offset;
        jdata["Alignment"] = decoded_value.Alignment;
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_PROPERTIES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_PROPERTIES& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["CPUPageProperty"] = decoded_value.CPUPageProperty;
        jdata["MemoryPoolPreference"] = decoded_value.MemoryPoolPreference;
        FieldToJsonAsFixedWidthBinary(jdata["CreationNodeMask"], decoded_value.CreationNodeMask);
        FieldToJsonAsFixedWidthBinary(jdata["VisibleNodeMask"], decoded_value.VisibleNodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HEAP_DESC& meta_struct = *data;
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        FieldToJson(jdata["Properties"], meta_struct.Properties);
        jdata["Alignment"] = decoded_value.Alignment;
        jdata["Flags"] = D3D12_HEAP_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["Dimension"] = decoded_value.Dimension;
        FieldToJson(jdata["DestHeapProperties"], meta_struct.DestHeapProperties);
        Bool32ToJson(jdata["Supported"], decoded_value.Supported);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MIP_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MIP_REGION& meta_struct = *data;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Depth"] = decoded_value.Depth;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC& meta_struct = *data;
        jdata["Dimension"] = decoded_value.Dimension;
        jdata["Alignment"] = decoded_value.Alignment;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["DepthOrArraySize"] = decoded_value.DepthOrArraySize;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["Format"] = decoded_value.Format;
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
        jdata["Layout"] = decoded_value.Layout;
        jdata["Flags"] = D3D12_RESOURCE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_DESC1& meta_struct = *data;
        jdata["Dimension"] = decoded_value.Dimension;
        jdata["Alignment"] = decoded_value.Alignment;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["DepthOrArraySize"] = decoded_value.DepthOrArraySize;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["Format"] = decoded_value.Format;
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
        jdata["Layout"] = decoded_value.Layout;
        jdata["Flags"] = D3D12_RESOURCE_FLAGS_t{ decoded_value.Flags };
        FieldToJson(jdata["SamplerFeedbackMipRegion"], meta_struct.SamplerFeedbackMipRegion);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VALUE& meta_struct = *data;
        FieldToJson(jdata["Depth"], decoded_value.Depth);
        jdata["Stencil"] = decoded_value.Stencil;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CLEAR_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CLEAR_VALUE& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        if(graphics::dx12::IsDepthStencilFormat(decoded_value.Format))
        {
            FieldToJson(jdata["DepthStencil"], decoded_value.DepthStencil);
        }
        else
        {
            FieldToJson(jdata["Color"], decoded_value.Color);
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE& meta_struct = *data;
        jdata["Begin"] = decoded_value.Begin;
        jdata["End"] = decoded_value.End;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RANGE_UINT64& meta_struct = *data;
        jdata["Begin"] = decoded_value.Begin;
        jdata["End"] = decoded_value.End;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_RANGE_UINT64& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& meta_struct = *data;
        jdata["Subresource"] = decoded_value.Subresource;
        FieldToJson(jdata["Range"], meta_struct.Range);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_INFO& meta_struct = *data;
        jdata["Offset"] = decoded_value.Offset;
        jdata["RowPitch"] = decoded_value.RowPitch;
        jdata["DepthPitch"] = decoded_value.DepthPitch;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILED_RESOURCE_COORDINATE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILED_RESOURCE_COORDINATE& meta_struct = *data;
        jdata["X"] = decoded_value.X;
        jdata["Y"] = decoded_value.Y;
        jdata["Z"] = decoded_value.Z;
        jdata["Subresource"] = decoded_value.Subresource;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_REGION_SIZE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_REGION_SIZE& meta_struct = *data;
        jdata["NumTiles"] = decoded_value.NumTiles;
        Bool32ToJson(jdata["UseBox"], decoded_value.UseBox);
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Depth"] = decoded_value.Depth;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_TILING& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_TILING& meta_struct = *data;
        jdata["WidthInTiles"] = decoded_value.WidthInTiles;
        jdata["HeightInTiles"] = decoded_value.HeightInTiles;
        jdata["DepthInTiles"] = decoded_value.DepthInTiles;
        jdata["StartTileIndexInOverallResource"] = decoded_value.StartTileIndexInOverallResource;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TILE_SHAPE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TILE_SHAPE& meta_struct = *data;
        jdata["WidthInTexels"] = decoded_value.WidthInTexels;
        jdata["HeightInTexels"] = decoded_value.HeightInTexels;
        jdata["DepthInTexels"] = decoded_value.DepthInTexels;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PACKED_MIP_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PACKED_MIP_INFO& meta_struct = *data;
        jdata["NumStandardMips"] = decoded_value.NumStandardMips;
        jdata["NumPackedMips"] = decoded_value.NumPackedMips;
        jdata["NumTilesForPackedMips"] = decoded_value.NumTilesForPackedMips;
        jdata["StartTileIndexInOverallResource"] = decoded_value.StartTileIndexInOverallResource;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_TRANSITION_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& meta_struct = *data;
        HandleToJson(jdata["pResource"], meta_struct.pResource);
        jdata["Subresource"] = decoded_value.Subresource;
        jdata["StateBefore"] = D3D12_RESOURCE_STATES_t{ decoded_value.StateBefore };
        jdata["StateAfter"] = D3D12_RESOURCE_STATES_t{ decoded_value.StateAfter };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_ALIASING_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& meta_struct = *data;
        HandleToJson(jdata["pResourceBefore"], meta_struct.pResourceBefore);
        HandleToJson(jdata["pResourceAfter"], meta_struct.pResourceAfter);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_UAV_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_UAV_BARRIER& meta_struct = *data;
        HandleToJson(jdata["pResource"], meta_struct.pResource);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RESOURCE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RESOURCE_BARRIER& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Flags"] = D3D12_RESOURCE_BARRIER_FLAGS_t{ decoded_value.Flags };
        switch(decoded_value.Type)
        {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            {
                FieldToJson(jdata["Transition"], meta_struct.Transition);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            {
                FieldToJson(jdata["Aliasing"], meta_struct.Aliasing);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            {
                FieldToJson(jdata["UAV"], meta_struct.UAV);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RESOURCE_BARRIER_TYPE in D3D12_RESOURCE_BARRIER.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Depth"] = decoded_value.Depth;
        jdata["RowPitch"] = decoded_value.RowPitch;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& meta_struct = *data;
        jdata["Offset"] = decoded_value.Offset;
        FieldToJson(jdata["Footprint"], meta_struct.Footprint);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_COPY_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_COPY_LOCATION& meta_struct = *data;
        HandleToJson(jdata["pResource"], meta_struct.pResource);
        jdata["Type"] = decoded_value.Type;
        switch(decoded_value.Type)
        {
            case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            {
                jdata["SubresourceIndex"] = decoded_value.SubresourceIndex;
                break;
            }
            case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            {
                FieldToJson(jdata["PlacedFootprint"], meta_struct.PlacedFootprint);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_TEXTURE_COPY_TYPE in D3D12_TEXTURE_COPY_LOCATION.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_POSITION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_POSITION& meta_struct = *data;
        jdata["X"] = decoded_value.X;
        jdata["Y"] = decoded_value.Y;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCE_LOCATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCE_LOCATION& meta_struct = *data;
        jdata["ViewportArrayIndex"] = decoded_value.ViewportArrayIndex;
        jdata["RenderTargetArrayIndex"] = decoded_value.RenderTargetArrayIndex;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VIEW_INSTANCING_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VIEW_INSTANCING_DESC& meta_struct = *data;
        jdata["ViewInstanceCount"] = decoded_value.ViewInstanceCount;
        FieldToJson(jdata["pViewInstanceLocations"], meta_struct.pViewInstanceLocations);
        jdata["Flags"] = D3D12_VIEW_INSTANCING_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_SRV& meta_struct = *data;
        jdata["FirstElement"] = decoded_value.FirstElement;
        jdata["NumElements"] = decoded_value.NumElements;
        jdata["StructureByteStride"] = decoded_value.StructureByteStride;
        jdata["Flags"] = D3D12_BUFFER_SRV_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXCUBE_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXCUBE_ARRAY_SRV& meta_struct = *data;
        jdata["MostDetailedMip"] = decoded_value.MostDetailedMip;
        jdata["MipLevels"] = decoded_value.MipLevels;
        jdata["First2DArrayFace"] = decoded_value.First2DArrayFace;
        jdata["NumCubes"] = decoded_value.NumCubes;
        FieldToJson(jdata["ResourceMinLODClamp"], decoded_value.ResourceMinLODClamp);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_SRV& meta_struct = *data;
        jdata["UnusedField_NothingToDefine"] = decoded_value.UnusedField_NothingToDefine;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_SRV& meta_struct = *data;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& meta_struct = *data;
        FieldToJsonAsHex(jdata["Location"], decoded_value.Location);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_RESOURCE_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["ViewDimension"] = decoded_value.ViewDimension;
        jdata["Shader4ComponentMapping"] = decoded_value.Shader4ComponentMapping;
        switch(decoded_value.ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToJson(jdata["TextureCube"], meta_struct.TextureCube);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToJson(jdata["TextureCubeArray"], meta_struct.TextureCubeArray);
                break;
            }
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            {
                FieldToJson(jdata["RaytracingAccelerationStructure"], meta_struct.RaytracingAccelerationStructure);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_CONSTANT_BUFFER_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC& meta_struct = *data;
        jdata["Filter"] = decoded_value.Filter;
        jdata["AddressU"] = decoded_value.AddressU;
        jdata["AddressV"] = decoded_value.AddressV;
        jdata["AddressW"] = decoded_value.AddressW;
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias);
        jdata["MaxAnisotropy"] = decoded_value.MaxAnisotropy;
        jdata["ComparisonFunc"] = decoded_value.ComparisonFunc;
        FieldToJson(jdata["BorderColor"], meta_struct.BorderColor);
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLER_DESC2& meta_struct = *data;
        jdata["Filter"] = decoded_value.Filter;
        jdata["AddressU"] = decoded_value.AddressU;
        jdata["AddressV"] = decoded_value.AddressV;
        jdata["AddressW"] = decoded_value.AddressW;
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias);
        jdata["MaxAnisotropy"] = decoded_value.MaxAnisotropy;
        jdata["ComparisonFunc"] = decoded_value.ComparisonFunc;
        if(decoded_value.Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
        {
            jdata["UintBorderColor"] = decoded_value.UintBorderColor;
        }
        else
        {
            FieldToJson(jdata["FloatBorderColor"], decoded_value.FloatBorderColor);
        }
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD);
        jdata["Flags"] = D3D12_SAMPLER_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_UAV& meta_struct = *data;
        jdata["FirstElement"] = decoded_value.FirstElement;
        jdata["NumElements"] = decoded_value.NumElements;
        jdata["StructureByteStride"] = decoded_value.StructureByteStride;
        jdata["CounterOffsetInBytes"] = decoded_value.CounterOffsetInBytes;
        jdata["Flags"] = D3D12_BUFFER_UAV_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_UAV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_UAV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_UAV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_UAV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_UAV& meta_struct = *data;
        jdata["UnusedField_NothingToDefine"] = decoded_value.UnusedField_NothingToDefine;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_UAV& meta_struct = *data;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_UAV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_UAV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstWSlice"] = decoded_value.FirstWSlice;
        jdata["WSize"] = decoded_value.WSize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_UNORDERED_ACCESS_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["ViewDimension"] = decoded_value.ViewDimension;
        switch(decoded_value.ViewDimension)
        {
            case D3D12_UAV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero-valued ViewDimension is meaningless. Is struct corrupted?");
                break;
            }
            case D3D12_UAV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "ViewDimension with unknown value. Is struct corrupted?");
                jdata["Unknown value"] = uint32_t(decoded_value.ViewDimension);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_RTV& meta_struct = *data;
        jdata["FirstElement"] = decoded_value.FirstElement;
        jdata["NumElements"] = decoded_value.NumElements;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_RTV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_RTV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_RTV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_RTV& meta_struct = *data;
        jdata["UnusedField_NothingToDefine"] = decoded_value.UnusedField_NothingToDefine;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_RTV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
        jdata["PlaneSlice"] = decoded_value.PlaneSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_RTV& meta_struct = *data;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX3D_RTV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX3D_RTV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstWSlice"] = decoded_value.FirstWSlice;
        jdata["WSize"] = decoded_value.WSize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_TARGET_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["ViewDimension"] = decoded_value.ViewDimension;
        switch(decoded_value.ViewDimension)
        {
            case D3D12_RTV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC.");
                break;
            }
            case D3D12_RTV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], meta_struct.Buffer);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], meta_struct.Texture3D);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Corrupt struct?");
                jdata["Unknown value"] = uint32_t(decoded_value.ViewDimension);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_DSV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX1D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX1D_ARRAY_DSV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_DSV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2D_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2D_ARRAY_DSV& meta_struct = *data;
        jdata["MipSlice"] = decoded_value.MipSlice;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_DSV& meta_struct = *data;
        jdata["UnusedField_NothingToDefine"] = decoded_value.UnusedField_NothingToDefine;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEX2DMS_ARRAY_DSV& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEX2DMS_ARRAY_DSV& meta_struct = *data;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["ArraySize"] = decoded_value.ArraySize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_VIEW_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& meta_struct = *data;
        jdata["Format"] = decoded_value.Format;
        jdata["ViewDimension"] = decoded_value.ViewDimension;
        jdata["Flags"] = D3D12_DSV_FLAGS_t{ decoded_value.Flags };
        switch(decoded_value.ViewDimension)
        {
            case D3D12_DSV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC.");
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], meta_struct.Texture1D);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], meta_struct.Texture2D);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC. Corrupt struct?");
                jdata["Unknown value"] = uint32_t(decoded_value.ViewDimension);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["NumDescriptors"] = decoded_value.NumDescriptors;
        jdata["Flags"] = D3D12_DESCRIPTOR_HEAP_FLAGS_t{ decoded_value.Flags };
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE& meta_struct = *data;
        jdata["RangeType"] = decoded_value.RangeType;
        jdata["NumDescriptors"] = decoded_value.NumDescriptors;
        jdata["BaseShaderRegister"] = decoded_value.BaseShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["OffsetInDescriptorsFromTableStart"] = decoded_value.OffsetInDescriptorsFromTableStart;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& meta_struct = *data;
        jdata["NumDescriptorRanges"] = decoded_value.NumDescriptorRanges;
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_CONSTANTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_CONSTANTS& meta_struct = *data;
        jdata["ShaderRegister"] = decoded_value.ShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["Num32BitValues"] = decoded_value.Num32BitValues;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR& meta_struct = *data;
        jdata["ShaderRegister"] = decoded_value.ShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER& meta_struct = *data;
        jdata["ParameterType"] = decoded_value.ParameterType;
        switch(decoded_value.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], meta_struct.Constants);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], meta_struct.Descriptor);
                break;
            }
        }
        jdata["ShaderVisibility"] = decoded_value.ShaderVisibility;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC& meta_struct = *data;
        jdata["Filter"] = decoded_value.Filter;
        jdata["AddressU"] = decoded_value.AddressU;
        jdata["AddressV"] = decoded_value.AddressV;
        jdata["AddressW"] = decoded_value.AddressW;
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias);
        jdata["MaxAnisotropy"] = decoded_value.MaxAnisotropy;
        jdata["ComparisonFunc"] = decoded_value.ComparisonFunc;
        jdata["BorderColor"] = decoded_value.BorderColor;
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD);
        jdata["ShaderRegister"] = decoded_value.ShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["ShaderVisibility"] = decoded_value.ShaderVisibility;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATIC_SAMPLER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATIC_SAMPLER_DESC1& meta_struct = *data;
        jdata["Filter"] = decoded_value.Filter;
        jdata["AddressU"] = decoded_value.AddressU;
        jdata["AddressV"] = decoded_value.AddressV;
        jdata["AddressW"] = decoded_value.AddressW;
        FieldToJson(jdata["MipLODBias"], decoded_value.MipLODBias);
        jdata["MaxAnisotropy"] = decoded_value.MaxAnisotropy;
        jdata["ComparisonFunc"] = decoded_value.ComparisonFunc;
        jdata["BorderColor"] = decoded_value.BorderColor;
        FieldToJson(jdata["MinLOD"], decoded_value.MinLOD);
        FieldToJson(jdata["MaxLOD"], decoded_value.MaxLOD);
        jdata["ShaderRegister"] = decoded_value.ShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["ShaderVisibility"] = decoded_value.ShaderVisibility;
        jdata["Flags"] = D3D12_SAMPLER_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC& meta_struct = *data;
        jdata["NumParameters"] = decoded_value.NumParameters;
        FieldToJson(jdata["pParameters"], meta_struct.pParameters);
        jdata["NumStaticSamplers"] = decoded_value.NumStaticSamplers;
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers);
        jdata["Flags"] = D3D12_ROOT_SIGNATURE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DESCRIPTOR_RANGE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DESCRIPTOR_RANGE1& meta_struct = *data;
        jdata["RangeType"] = decoded_value.RangeType;
        jdata["NumDescriptors"] = decoded_value.NumDescriptors;
        jdata["BaseShaderRegister"] = decoded_value.BaseShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["Flags"] = D3D12_DESCRIPTOR_RANGE_FLAGS_t{ decoded_value.Flags };
        jdata["OffsetInDescriptorsFromTableStart"] = decoded_value.OffsetInDescriptorsFromTableStart;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR_TABLE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& meta_struct = *data;
        jdata["NumDescriptorRanges"] = decoded_value.NumDescriptorRanges;
        FieldToJson(jdata["pDescriptorRanges"], meta_struct.pDescriptorRanges);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_DESCRIPTOR1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_DESCRIPTOR1& meta_struct = *data;
        jdata["ShaderRegister"] = decoded_value.ShaderRegister;
        jdata["RegisterSpace"] = decoded_value.RegisterSpace;
        jdata["Flags"] = D3D12_ROOT_DESCRIPTOR_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_PARAMETER1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_PARAMETER1& meta_struct = *data;
        jdata["ParameterType"] = decoded_value.ParameterType;
        switch (decoded_value.ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], meta_struct.Constants);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], meta_struct.Descriptor);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1.");
                jdata["Unknown value"] = uint32_t(decoded_value.ParameterType);
                break;
            }
        }
        jdata["ShaderVisibility"] = decoded_value.ShaderVisibility;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC1& meta_struct = *data;
        jdata["NumParameters"] = decoded_value.NumParameters;
        FieldToJson(jdata["pParameters"], meta_struct.pParameters);
        jdata["NumStaticSamplers"] = decoded_value.NumStaticSamplers;
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers);
        jdata["Flags"] = D3D12_ROOT_SIGNATURE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_ROOT_SIGNATURE_DESC2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_ROOT_SIGNATURE_DESC2& meta_struct = *data;
        jdata["NumParameters"] = decoded_value.NumParameters;
        FieldToJson(jdata["pParameters"], meta_struct.pParameters);
        jdata["NumStaticSamplers"] = decoded_value.NumStaticSamplers;
        FieldToJson(jdata["pStaticSamplers"], meta_struct.pStaticSamplers);
        jdata["Flags"] = D3D12_ROOT_SIGNATURE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& meta_struct = *data;
        jdata["Version"] = decoded_value.Version;
        switch (decoded_value.Version)
        {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
            {
                FieldToJson(jdata["Desc_1_0"], meta_struct.Desc_1_0);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
            {
                FieldToJson(jdata["Desc_1_1"], meta_struct.Desc_1_1);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_2:
            {
                FieldToJson(jdata["Desc_1_2"], meta_struct.Desc_1_2);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                jdata["Unknown value"] = uint32_t(decoded_value.Version);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        jdata["ptr"] = decoded_value.ptr;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISCARD_REGION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISCARD_REGION& meta_struct = *data;
        jdata["NumRects"] = decoded_value.NumRects;
        FieldToJson(jdata["pRects"], meta_struct.pRects);
        jdata["FirstSubresource"] = decoded_value.FirstSubresource;
        jdata["NumSubresources"] = decoded_value.NumSubresources;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_HEAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_HEAP_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Count"] = decoded_value.Count;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& meta_struct = *data;
        jdata["IAVertices"] = decoded_value.IAVertices;
        jdata["IAPrimitives"] = decoded_value.IAPrimitives;
        jdata["VSInvocations"] = decoded_value.VSInvocations;
        jdata["GSInvocations"] = decoded_value.GSInvocations;
        jdata["GSPrimitives"] = decoded_value.GSPrimitives;
        jdata["CInvocations"] = decoded_value.CInvocations;
        jdata["CPrimitives"] = decoded_value.CPrimitives;
        jdata["PSInvocations"] = decoded_value.PSInvocations;
        jdata["HSInvocations"] = decoded_value.HSInvocations;
        jdata["DSInvocations"] = decoded_value.DSInvocations;
        jdata["CSInvocations"] = decoded_value.CSInvocations;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& meta_struct = *data;
        jdata["IAVertices"] = decoded_value.IAVertices;
        jdata["IAPrimitives"] = decoded_value.IAPrimitives;
        jdata["VSInvocations"] = decoded_value.VSInvocations;
        jdata["GSInvocations"] = decoded_value.GSInvocations;
        jdata["GSPrimitives"] = decoded_value.GSPrimitives;
        jdata["CInvocations"] = decoded_value.CInvocations;
        jdata["CPrimitives"] = decoded_value.CPrimitives;
        jdata["PSInvocations"] = decoded_value.PSInvocations;
        jdata["HSInvocations"] = decoded_value.HSInvocations;
        jdata["DSInvocations"] = decoded_value.DSInvocations;
        jdata["CSInvocations"] = decoded_value.CSInvocations;
        jdata["ASInvocations"] = decoded_value.ASInvocations;
        jdata["MSInvocations"] = decoded_value.MSInvocations;
        jdata["MSPrimitives"] = decoded_value.MSPrimitives;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_QUERY_DATA_SO_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& meta_struct = *data;
        jdata["NumPrimitivesWritten"] = decoded_value.NumPrimitivesWritten;
        jdata["PrimitivesStorageNeeded"] = decoded_value.PrimitivesStorageNeeded;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        FieldToJsonAsHex(jdata["BufferFilledSizeLocation"], decoded_value.BufferFilledSizeLocation);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_ARGUMENTS& meta_struct = *data;
        jdata["VertexCountPerInstance"] = decoded_value.VertexCountPerInstance;
        jdata["InstanceCount"] = decoded_value.InstanceCount;
        jdata["StartVertexLocation"] = decoded_value.StartVertexLocation;
        jdata["StartInstanceLocation"] = decoded_value.StartInstanceLocation;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRAW_INDEXED_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& meta_struct = *data;
        jdata["IndexCountPerInstance"] = decoded_value.IndexCountPerInstance;
        jdata["InstanceCount"] = decoded_value.InstanceCount;
        jdata["StartIndexLocation"] = decoded_value.StartIndexLocation;
        jdata["BaseVertexLocation"] = decoded_value.BaseVertexLocation;
        jdata["StartInstanceLocation"] = decoded_value.StartInstanceLocation;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_ARGUMENTS& meta_struct = *data;
        jdata["ThreadGroupCountX"] = decoded_value.ThreadGroupCountX;
        jdata["ThreadGroupCountY"] = decoded_value.ThreadGroupCountY;
        jdata["ThreadGroupCountZ"] = decoded_value.ThreadGroupCountZ;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERTEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERTEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        jdata["StrideInBytes"] = decoded_value.StrideInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDEX_BUFFER_VIEW& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDEX_BUFFER_VIEW& meta_struct = *data;
        FieldToJsonAsHex(jdata["BufferLocation"], decoded_value.BufferLocation);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        jdata["Format"] = decoded_value.Format;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INDIRECT_ARGUMENT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        switch (decoded_value.Type)
        {
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
            {
                // No data to output for draws and dispatches, they are parameterless tags.
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
            {
                auto& vb = jdata["VertexBuffer"];
                vb["Slot"] = decoded_value.VertexBuffer.Slot;
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
            {
                // No parameters to output.
                FieldToJson(jdata["comment"], "There must be a D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED in the same sequence.");
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
            {
                auto& c = jdata["Constant"];
                c["RootParameterIndex"] = decoded_value.Constant.RootParameterIndex;
                c["DestOffsetIn32BitValues"] = decoded_value.Constant.DestOffsetIn32BitValues;
                c["Num32BitValuesToSet"] = decoded_value.Constant.Num32BitValuesToSet;
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            {
                auto& cbv = jdata["ConstantBufferView"];
                cbv["RootParameterIndex"] = decoded_value.ConstantBufferView.RootParameterIndex;
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            {
                auto& srv = jdata["ShaderResourceView"];
                srv["RootParameterIndex"] = decoded_value.ShaderResourceView.RootParameterIndex;
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
            {
                auto& uav = jdata["UnorderedAccessView"];
                uav["RootParameterIndex"] = decoded_value.UnorderedAccessView.RootParameterIndex;
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
            case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
            {
                // No data to output for draws and dispatches, they are parameterless tags.
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMAND_SIGNATURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMAND_SIGNATURE_DESC& meta_struct = *data;
        jdata["ByteStride"] = decoded_value.ByteStride;
        jdata["NumArgumentDescs"] = decoded_value.NumArgumentDescs;
        FieldToJson(jdata["pArgumentDescs"], meta_struct.pArgumentDescs);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& meta_struct = *data;
        FieldToJsonAsHex(jdata["Dest"], decoded_value.Dest);
        jdata["Value"] = decoded_value.Value;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_SCHEDULING_QUEUE_GROUPINGS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_HARDWARE_SCHEDULING_QUEUE_GROUPINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_HARDWARE_SCHEDULING_QUEUE_GROUPINGS& meta_struct = *data;
        jdata["ComputeQueuesPer3DQueue"] = decoded_value.ComputeQueuesPer3DQueue;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        jdata["Support"] = D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS_t{ decoded_value.Support };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
        jdata["Flags"] = D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_PARAMETER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name);
        jdata["Type"] = decoded_value.Type;
        jdata["Flags"] = D3D12_META_COMMAND_PARAMETER_FLAGS_t{ decoded_value.Flags };
        jdata["RequiredResourceState"] = D3D12_RESOURCE_STATES_t{ decoded_value.RequiredResourceState };
        jdata["StructureOffset"] = decoded_value.StructureOffset;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_META_COMMAND_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_META_COMMAND_DESC& meta_struct = *data;
        FieldToJson(jdata["Id"], meta_struct.Id);
        FieldToJson(jdata["Name"], meta_struct.Name);
        jdata["InitializationDirtyState"] = D3D12_GRAPHICS_STATES_t{ decoded_value.InitializationDirtyState };
        jdata["ExecutionDirtyState"] = D3D12_GRAPHICS_STATES_t{ decoded_value.ExecutionDirtyState };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROGRAM_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROGRAM_IDENTIFIER& meta_struct = *data;
        FieldToJson(jdata["OpaqueData"], meta_struct.OpaqueData);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_ID& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_ID& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name);
        jdata["ArrayIndex"] = decoded_value.ArrayIndex;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS& meta_struct = *data;
        jdata["MinSizeInBytes"] = decoded_value.MinSizeInBytes;
        jdata["MaxSizeInBytes"] = decoded_value.MaxSizeInBytes;
        jdata["SizeGranularityInBytes"] = decoded_value.SizeGranularityInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_CONFIG& meta_struct = *data;
        jdata["Flags"] = D3D12_STATE_OBJECT_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& meta_struct = *data;
        HandleToJson(jdata["pGlobalRootSignature"], meta_struct.pGlobalRootSignature);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_LOCAL_ROOT_SIGNATURE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& meta_struct = *data;
        HandleToJson(jdata["pLocalRootSignature"], meta_struct.pLocalRootSignature);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_MASK& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SAMPLE_MASK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SAMPLE_MASK& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["SampleMask"], decoded_value.SampleMask);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_IB_STRIP_CUT_VALUE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_IB_STRIP_CUT_VALUE& meta_struct = *data;
        jdata["IndexBufferStripCutValue"] = decoded_value.IndexBufferStripCutValue;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PRIMITIVE_TOPOLOGY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC& meta_struct = *data;
        jdata["PrimitiveTopology"] = decoded_value.PrimitiveTopology;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEPTH_STENCIL_FORMAT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEPTH_STENCIL_FORMAT& meta_struct = *data;
        jdata["DepthStencilFormat"] = decoded_value.DepthStencilFormat;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXPORT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXPORT_DESC& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name);
        FieldToJson(jdata["ExportToRename"], meta_struct.ExportToRename);
        jdata["Flags"] = D3D12_EXPORT_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_LIBRARY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_LIBRARY_DESC& meta_struct = *data;
        FieldToJson(jdata["DXILLibrary"], meta_struct.DXILLibrary);
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_DESC& meta_struct = *data;
        HandleToJson(jdata["pExistingCollection"], meta_struct.pExistingCollection);
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["pSubobjectToAssociate"], meta_struct.pSubobjectToAssociate);
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& meta_struct = *data;
        FieldToJson(jdata["SubobjectToAssociate"], meta_struct.SubobjectToAssociate);
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_HIT_GROUP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_HIT_GROUP_DESC& meta_struct = *data;
        FieldToJson(jdata["HitGroupExport"], meta_struct.HitGroupExport);
        jdata["Type"] = decoded_value.Type;
        FieldToJson(jdata["AnyHitShaderImport"], meta_struct.AnyHitShaderImport);
        FieldToJson(jdata["ClosestHitShaderImport"], meta_struct.ClosestHitShaderImport);
        FieldToJson(jdata["IntersectionShaderImport"], meta_struct.IntersectionShaderImport);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SHADER_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& meta_struct = *data;
        jdata["MaxPayloadSizeInBytes"] = decoded_value.MaxPayloadSizeInBytes;
        jdata["MaxAttributeSizeInBytes"] = decoded_value.MaxAttributeSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& meta_struct = *data;
        jdata["MaxTraceRecursionDepth"] = decoded_value.MaxTraceRecursionDepth;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_PIPELINE_CONFIG1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& meta_struct = *data;
        jdata["MaxTraceRecursionDepth"] = decoded_value.MaxTraceRecursionDepth;
        jdata["Flags"] = D3D12_RAYTRACING_PIPELINE_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_OUTPUT_OVERRIDES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_OUTPUT_OVERRIDES& meta_struct = *data;
        jdata["OutputIndex"] = decoded_value.OutputIndex;
        FieldToJson(jdata["pNewName"], meta_struct.pNewName);
        Bool32ToJson(jdata["pAllowSparseNodes"], meta_struct.pAllowSparseNodes);
        FieldToJson(jdata["pMaxRecords"], meta_struct.pMaxRecords);
        FieldToJson(jdata["pMaxRecordsSharedWithOutputIndex"], meta_struct.pMaxRecordsSharedWithOutputIndex);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BROADCASTING_LAUNCH_OVERRIDES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES& meta_struct = *data;
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], meta_struct.pLocalRootArgumentsTableIndex);
        Bool32ToJson(jdata["pProgramEntry"], meta_struct.pProgramEntry);
        FieldToJson(jdata["pNewName"], meta_struct.pNewName);
        FieldToJson(jdata["pShareInputOf"], meta_struct.pShareInputOf);
        FieldToJson(jdata["pDispatchGrid"], meta_struct.pDispatchGrid);
        FieldToJson(jdata["pMaxDispatchGrid"], meta_struct.pMaxDispatchGrid);
        jdata["NumOutputOverrides"] = decoded_value.NumOutputOverrides;
        FieldToJson(jdata["pOutputOverrides"], meta_struct.pOutputOverrides);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COALESCING_LAUNCH_OVERRIDES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES& meta_struct = *data;
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], meta_struct.pLocalRootArgumentsTableIndex);
        Bool32ToJson(jdata["pProgramEntry"], meta_struct.pProgramEntry);
        FieldToJson(jdata["pNewName"], meta_struct.pNewName);
        FieldToJson(jdata["pShareInputOf"], meta_struct.pShareInputOf);
        jdata["NumOutputOverrides"] = decoded_value.NumOutputOverrides;
        FieldToJson(jdata["pOutputOverrides"], meta_struct.pOutputOverrides);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_THREAD_LAUNCH_OVERRIDES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES& meta_struct = *data;
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], meta_struct.pLocalRootArgumentsTableIndex);
        Bool32ToJson(jdata["pProgramEntry"], meta_struct.pProgramEntry);
        FieldToJson(jdata["pNewName"], meta_struct.pNewName);
        FieldToJson(jdata["pShareInputOf"], meta_struct.pShareInputOf);
        jdata["NumOutputOverrides"] = decoded_value.NumOutputOverrides;
        FieldToJson(jdata["pOutputOverrides"], meta_struct.pOutputOverrides);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_COMMON_COMPUTE_NODE_OVERRIDES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES& meta_struct = *data;
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], meta_struct.pLocalRootArgumentsTableIndex);
        Bool32ToJson(jdata["pProgramEntry"], meta_struct.pProgramEntry);
        FieldToJson(jdata["pNewName"], meta_struct.pNewName);
        FieldToJson(jdata["pShareInputOf"], meta_struct.pShareInputOf);
        jdata["NumOutputOverrides"] = decoded_value.NumOutputOverrides;
        FieldToJson(jdata["pOutputOverrides"], meta_struct.pOutputOverrides);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_NODE& meta_struct = *data;
        FieldToJson(jdata["Shader"], meta_struct.Shader);
        jdata["OverridesType"] = decoded_value.OverridesType;
        switch(decoded_value.OverridesType)
        {
            case D3D12_NODE_OVERRIDES_TYPE_BROADCASTING_LAUNCH:
            {
                FieldToJson(jdata["pBroadcastingLaunchOverrides"], meta_struct.broadcasting_launch_overrides);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_COALESCING_LAUNCH:
            {
                FieldToJson(jdata["pCoalescingLaunchOverrides"], meta_struct.coalescing_launch_overrides);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_THREAD_LAUNCH:
            {
                FieldToJson(jdata["pThreadLaunchOverrides"], meta_struct.thread_launch_overrides);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_COMMON_COMPUTE:
            {
                FieldToJson(jdata["pCommonComputeNodeOverrides"], meta_struct.common_compute_node_overrides);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_NODE_OVERRIDES_TYPE in D3D12_SHADER_NODE.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE& meta_struct = *data;
        jdata["NodeType"] = decoded_value.NodeType;
        switch(decoded_value.NodeType)
        {
            case D3D12_NODE_TYPE_SHADER:
            {
                FieldToJson(jdata["Shader"], meta_struct.shader);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_NODE_TYPE in D3D12_NODE.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_WORK_GRAPH_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_WORK_GRAPH_DESC& meta_struct = *data;
        FieldToJson(jdata["ProgramName"], meta_struct.ProgramName);
        jdata["Flags"] = D3D12_WORK_GRAPH_FLAGS_t{ decoded_value.Flags };
        jdata["NumEntrypoints"] = decoded_value.NumEntrypoints;
        FieldToJson(jdata["pEntrypoints"], meta_struct.pEntrypoints);
        jdata["NumExplicitlyDefinedNodes"] = decoded_value.NumExplicitlyDefinedNodes;
        FieldToJson(jdata["pExplicitlyDefinedNodes"], meta_struct.pExplicitlyDefinedNodes);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GENERIC_PROGRAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GENERIC_PROGRAM_DESC& meta_struct = *data;
        FieldToJson(jdata["ProgramName"], meta_struct.ProgramName);
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
        jdata["NumSubobjects"] = decoded_value.NumSubobjects;
        FieldToJson(jdata["ppSubobjects"], meta_struct.ppSubobjects);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_OBJECT_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_OBJECT_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["NumSubobjects"] = decoded_value.NumSubobjects;
        FieldToJson(jdata["pSubobjects"], meta_struct.pSubobjects);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress);
        jdata["StrideInBytes"] = decoded_value.StrideInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& meta_struct = *data;
        FieldToJsonAsHex(jdata["StartAddress"], decoded_value.StartAddress);
        jdata["SizeInBytes"] = decoded_value.SizeInBytes;
        jdata["StrideInBytes"] = decoded_value.StrideInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["Transform3x4"], decoded_value.Transform3x4);
        jdata["IndexFormat"] = decoded_value.IndexFormat;
        jdata["VertexFormat"] = decoded_value.VertexFormat;
        jdata["IndexCount"] = decoded_value.IndexCount;
        jdata["VertexCount"] = decoded_value.VertexCount;
        FieldToJsonAsHex(jdata["IndexBuffer"], decoded_value.IndexBuffer);
        FieldToJson(jdata["VertexBuffer"], meta_struct.VertexBuffer);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_AABB& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_AABB& meta_struct = *data;
        FieldToJson(jdata["MinX"], decoded_value.MinX);
        FieldToJson(jdata["MinY"], decoded_value.MinY);
        FieldToJson(jdata["MinZ"], decoded_value.MinZ);
        FieldToJson(jdata["MaxX"], decoded_value.MaxX);
        FieldToJson(jdata["MaxY"], decoded_value.MaxY);
        FieldToJson(jdata["MaxZ"], decoded_value.MaxZ);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& meta_struct = *data;
        jdata["AABBCount"] = decoded_value.AABBCount;
        FieldToJson(jdata["AABBs"], meta_struct.AABBs);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC& meta_struct = *data;
        jdata["ByteOffset"] = decoded_value.ByteOffset;
        jdata["SubdivisionLevel"] = decoded_value.SubdivisionLevel;
        jdata["Format"] = decoded_value.Format;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC& meta_struct = *data;
        FieldToJson(jdata["OpacityMicromapIndexBuffer"], meta_struct.OpacityMicromapIndexBuffer);
        jdata["OpacityMicromapIndexFormat"] = decoded_value.OpacityMicromapIndexFormat;
        jdata["OpacityMicromapBaseLocation"] = decoded_value.OpacityMicromapBaseLocation;
        FieldToJsonAsHex(jdata["OpacityMicromapArray"], decoded_value.OpacityMicromapArray);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC& meta_struct = *data;
        FieldToJson(jdata["pTriangles"], meta_struct.pTriangles);
        FieldToJson(jdata["pOmmLinkage"], meta_struct.pOmmLinkage);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["DestBuffer"], decoded_value.DestBuffer);
        jdata["InfoType"] = decoded_value.InfoType;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& meta_struct = *data;
        jdata["CompactedSizeInBytes"] = decoded_value.CompactedSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        jdata["DecodedSizeInBytes"] = decoded_value.DecodedSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["NumDescs"] = decoded_value.NumDescs;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& meta_struct = *data;
        jdata["SerializedSizeInBytes"] = decoded_value.SerializedSizeInBytes;
        jdata["NumBottomLevelAccelerationStructurePointers"] = decoded_value.NumBottomLevelAccelerationStructurePointers;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& meta_struct = *data;
        FieldToJson(jdata["DriverOpaqueGUID"], meta_struct.DriverOpaqueGUID);
        FieldToJson(jdata["DriverOpaqueVersioningData"], meta_struct.DriverOpaqueVersioningData);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& meta_struct = *data;
        FieldToJson(jdata["DriverMatchingIdentifier"], meta_struct.DriverMatchingIdentifier);
        jdata["SerializedSizeInBytesIncludingHeader"] = decoded_value.SerializedSizeInBytesIncludingHeader;
        jdata["DeserializedSizeInBytes"] = decoded_value.DeserializedSizeInBytes;
        jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"] = decoded_value.NumBottomLevelAccelerationStructurePointersAfterHeader;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1& meta_struct = *data;
        FieldToJson(jdata["DriverMatchingIdentifier"], meta_struct.DriverMatchingIdentifier);
        jdata["SerializedSizeInBytesIncludingHeader"] = decoded_value.SerializedSizeInBytesIncludingHeader;
        jdata["DeserializedSizeInBytes"] = decoded_value.DeserializedSizeInBytes;
        jdata["NumBlocks"] = decoded_value.NumBlocks;
        jdata["HeaderPostambleType"] = decoded_value.HeaderPostambleType;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SERIALIZED_BLOCK* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_SERIALIZED_BLOCK& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_SERIALIZED_BLOCK& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["NumBlockPointersAfterHeader"] = decoded_value.NumBlockPointersAfterHeader;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        jdata["CurrentSizeInBytes"] = decoded_value.CurrentSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_INSTANCE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& meta_struct = *data;
        FieldToJson(jdata["Transform"], meta_struct.Transform);
        jdata["InstanceID"] = decoded_value.InstanceID;
        FieldToJsonAsFixedWidthBinary(jdata["InstanceMask"], decoded_value.InstanceMask);
        jdata["InstanceContributionToHitGroupIndex"] = decoded_value.InstanceContributionToHitGroupIndex;
        jdata["Flags"] = decoded_value.Flags;
        FieldToJsonAsHex(jdata["AccelerationStructure"], decoded_value.AccelerationStructure);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_GEOMETRY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Flags"] = D3D12_RAYTRACING_GEOMETRY_FLAGS_t{ decoded_value.Flags };
        switch(decoded_value.Type)
        {
            case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            {
                FieldToJson(jdata["Triangles"], meta_struct.Triangles);
                break;
            }
            case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            {
                FieldToJson(jdata["AABBs"], meta_struct.AABBs);
                break;
            }
            case D3D12_RAYTRACING_GEOMETRY_TYPE_OMM_TRIANGLES:
            {
                FieldToJson(jdata["OmmTriangles"], meta_struct.OmmTriangles);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_GEOMETRY_TYPE in D3D12_RAYTRACING_GEOMETRY_DESC.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY& meta_struct = *data;
        jdata["Count"] = decoded_value.Count;
        jdata["SubdivisionLevel"] = decoded_value.SubdivisionLevel;
        jdata["Format"] = decoded_value.Format;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC& meta_struct = *data;
        jdata["NumOmmHistogramEntries"] = decoded_value.NumOmmHistogramEntries;
        FieldToJson(jdata["pOmmHistogram"], meta_struct.pOmmHistogram);
        FieldToJsonAsHex(jdata["InputBuffer"], decoded_value.InputBuffer);
        FieldToJson(jdata["PerOmmDescs"], meta_struct.PerOmmDescs);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Flags"] = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t{ decoded_value.Flags };
        jdata["NumDescs"] = decoded_value.NumDescs;
        jdata["DescsLayout"] = decoded_value.DescsLayout;
        switch(decoded_value.Type)
        {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            {
                FieldToJsonAsHex(jdata["InstanceDescs"], decoded_value.InstanceDescs);
                break;
            }
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            {
                switch(decoded_value.DescsLayout)
                {
                    case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    {
                        FieldToJson(jdata["pGeometryDescs"], meta_struct.pGeometryDescs);
                        break;
                    }
                    case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    {
                        FieldToJson(jdata["ppGeometryDescs"], meta_struct.ppGeometryDescs);
                        break;
                    }
                }
                break;
            }
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_OPACITY_MICROMAP_ARRAY:
            {
                FieldToJson(jdata["pOpacityMicromapArrayDesc"], meta_struct.pOpacityMicromapArrayDesc);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE in D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["DestAccelerationStructureData"], decoded_value.DestAccelerationStructureData);
        FieldToJson(jdata["Inputs"], meta_struct.Inputs);
        FieldToJsonAsHex(jdata["SourceAccelerationStructureData"], decoded_value.SourceAccelerationStructureData);
        FieldToJsonAsHex(jdata["ScratchAccelerationStructureData"], decoded_value.ScratchAccelerationStructureData);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& meta_struct = *data;
        jdata["ResultDataMaxSizeInBytes"] = decoded_value.ResultDataMaxSizeInBytes;
        jdata["ScratchDataSizeInBytes"] = decoded_value.ScratchDataSizeInBytes;
        jdata["UpdateScratchDataSizeInBytes"] = decoded_value.UpdateScratchDataSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC& meta_struct = *data;
        FieldToJsonAsHex(jdata["DestBuffer"], decoded_value.DestBuffer);
        jdata["InfoType"] = decoded_value.InfoType;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC& meta_struct = *data;
        jdata["CurrentSizeInBytes"] = decoded_value.CurrentSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& meta_struct = *data;
        jdata["DecodedSizeInBytes"] = decoded_value.DecodedSizeInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA);
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW);
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA);
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW);
        HandleToJson(jdata["pCommandList"], meta_struct.pCommandList);
        HandleToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue);
        jdata["BreadcrumbCount"] = decoded_value.BreadcrumbCount;
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue);
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_BREADCRUMB_CONTEXT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& meta_struct = *data;
        jdata["BreadcrumbIndex"] = decoded_value.BreadcrumbIndex;
        FieldToJson(jdata["pContextString"], meta_struct.pContextString);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_AUTO_BREADCRUMB_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& meta_struct = *data;
        FieldToJson(jdata["pCommandListDebugNameA"], meta_struct.pCommandListDebugNameA);
        FieldToJson(jdata["pCommandListDebugNameW"], meta_struct.pCommandListDebugNameW);
        FieldToJson(jdata["pCommandQueueDebugNameA"], meta_struct.pCommandQueueDebugNameA);
        FieldToJson(jdata["pCommandQueueDebugNameW"], meta_struct.pCommandQueueDebugNameW);
        HandleToJson(jdata["pCommandList"], meta_struct.pCommandList);
        HandleToJson(jdata["pCommandQueue"], meta_struct.pCommandQueue);
        jdata["BreadcrumbCount"] = decoded_value.BreadcrumbCount;
        FieldToJson(jdata["pLastBreadcrumbValue"], meta_struct.pLastBreadcrumbValue);
        FieldToJson(jdata["pCommandHistory"], meta_struct.pCommandHistory);
        FieldToJson(jdata["pNext"], meta_struct.pNext);
        jdata["BreadcrumbContextsCount"] = decoded_value.BreadcrumbContextsCount;
        FieldToJson(jdata["pBreadcrumbContexts"], meta_struct.pBreadcrumbContexts);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        jdata["Flags"] = D3D12_DRED_FLAGS_t{ decoded_value.Flags };
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA);
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW);
        jdata["AllocationType"] = decoded_value.AllocationType;
        FieldToJson(jdata["pNext"], meta_struct.pNext);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_ALLOCATION_NODE1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_ALLOCATION_NODE1& meta_struct = *data;
        FieldToJson(jdata["ObjectNameA"], meta_struct.ObjectNameA);
        FieldToJson(jdata["ObjectNameW"], meta_struct.ObjectNameW);
        jdata["AllocationType"] = decoded_value.AllocationType;
        FieldToJson(jdata["pNext"], meta_struct.pNext);
        HandleToJson(jdata["pObject"], meta_struct.pObject);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& meta_struct = *data;
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], meta_struct.pHeadAutoBreadcrumbNode);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DRED_PAGE_FAULT_OUTPUT2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& meta_struct = *data;
        FieldToJsonAsHex(jdata["PageFaultVA"], decoded_value.PageFaultVA);
        FieldToJson(jdata["pHeadExistingAllocationNode"], meta_struct.pHeadExistingAllocationNode);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], meta_struct.pHeadRecentFreedAllocationNode);
        jdata["PageFaultFlags"] = D3D12_DRED_PAGE_FAULT_FLAGS_t{ decoded_value.PageFaultFlags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& meta_struct = *data;
        HresultToJson(jdata["DeviceRemovedReason"], decoded_value.DeviceRemovedReason);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], meta_struct.AutoBreadcrumbsOutput);
        FieldToJson(jdata["PageFaultOutput"], meta_struct.PageFaultOutput);
        jdata["DeviceState"] = decoded_value.DeviceState;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& meta_struct = *data;
        jdata["Version"] = decoded_value.Version;
        switch(decoded_value.Version)
        {
            case D3D12_DRED_VERSION_1_0:
            {
                FieldToJson(jdata["Dred_1_0"], meta_struct.Dred_1_0);
                break;
            }
            case D3D12_DRED_VERSION_1_1:
            {
                FieldToJson(jdata["Dred_1_1"], meta_struct.Dred_1_1);
                break;
            }
            case D3D12_DRED_VERSION_1_2:
            {
                FieldToJson(jdata["Dred_1_2"], meta_struct.Dred_1_2);
                break;
            }
            case D3D12_DRED_VERSION_1_3:
            {
                FieldToJson(jdata["Dred_1_3"], meta_struct.Dred_1_3);
                FieldToJson(jdata[format::kNameWarning], "Dred_1_3 is not supported by GFXR at this time. Please file an issue quoting this text if this is a blocker for you.");
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DRED_VERSION in D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        jdata["Count"] = decoded_value.Count;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& meta_struct = *data;
        jdata["NodeIndex"] = decoded_value.NodeIndex;
        jdata["Count"] = decoded_value.Count;
        FieldToJson(jdata["pTypes"], meta_struct.pTypes);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& meta_struct = *data;
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], decoded_value.NodeMask);
        jdata["Flags"] = D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t{ decoded_value.Flags };
        FieldToJson(jdata["ProtectionType"], meta_struct.ProtectionType);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& meta_struct = *data;
        FieldToJson(jdata["ClearValue"], meta_struct.ClearValue);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        jdata["AdditionalWidth"] = decoded_value.AdditionalWidth;
        jdata["AdditionalHeight"] = decoded_value.AdditionalHeight;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_BEGINNING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        switch(decoded_value.Type)
        {
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR:
            {
                FieldToJson(jdata["Clear"], meta_struct.Clear);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            if(decoded_value.PreserveLocal.AdditionalWidth != 0U || decoded_value.PreserveLocal.AdditionalHeight != 0U)
            {
                FieldToJson(jdata[format::kNameWarning], "Additional width and height should be zero (see DirectX Specs).");
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE in D3D12_RENDER_PASS_BEGINNING_ACCESS.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& meta_struct = *data;
        jdata["SrcSubresource"] = decoded_value.SrcSubresource;
        jdata["DstSubresource"] = decoded_value.DstSubresource;
        jdata["DstX"] = decoded_value.DstX;
        jdata["DstY"] = decoded_value.DstY;
        FieldToJson(jdata["SrcRect"], meta_struct.SrcRect);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& meta_struct = *data;
        HandleToJson(jdata["pSrcResource"], meta_struct.pSrcResource);
        HandleToJson(jdata["pDstResource"], meta_struct.pDstResource);
        jdata["SubresourceCount"] = decoded_value.SubresourceCount;
        FieldToJson(jdata["pSubresourceParameters"], meta_struct.pSubresourceParameters);
        jdata["Format"] = decoded_value.Format;
        jdata["ResolveMode"] = decoded_value.ResolveMode;
        Bool32ToJson(jdata["PreserveResolveSource"], decoded_value.PreserveResolveSource);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& meta_struct = *data;
        jdata["AdditionalWidth"] = decoded_value.AdditionalWidth;
        jdata["AdditionalHeight"] = decoded_value.AdditionalHeight;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_ENDING_ACCESS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        switch(decoded_value.Type)
        {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
            {
                FieldToJson(jdata["Resolve"], meta_struct.Resolve);
                break;
            }
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal);
                break;
            }

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_ENDING_ACCESS_TYPE in D3D12_RENDER_PASS_ENDING_ACCESS.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& meta_struct = *data;
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor);
        FieldToJson(jdata["BeginningAccess"], meta_struct.BeginningAccess);
        FieldToJson(jdata["EndingAccess"], meta_struct.EndingAccess);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& meta_struct = *data;
        FieldToJson(jdata["cpuDescriptor"], meta_struct.cpuDescriptor);
        FieldToJson(jdata["DepthBeginningAccess"], meta_struct.DepthBeginningAccess);
        FieldToJson(jdata["StencilBeginningAccess"], meta_struct.StencilBeginningAccess);
        FieldToJson(jdata["DepthEndingAccess"], meta_struct.DepthEndingAccess);
        FieldToJson(jdata["StencilEndingAccess"], meta_struct.StencilEndingAccess);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_RAYS_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_RAYS_DESC& meta_struct = *data;
        FieldToJson(jdata["RayGenerationShaderRecord"], meta_struct.RayGenerationShaderRecord);
        FieldToJson(jdata["MissShaderTable"], meta_struct.MissShaderTable);
        FieldToJson(jdata["HitGroupTable"], meta_struct.HitGroupTable);
        FieldToJson(jdata["CallableShaderTable"], meta_struct.CallableShaderTable);
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Depth"] = decoded_value.Depth;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SET_WORK_GRAPH_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SET_WORK_GRAPH_DESC& meta_struct = *data;
        FieldToJson(jdata["ProgramIdentifier"], meta_struct.ProgramIdentifier);
        jdata["Flags"] = D3D12_SET_WORK_GRAPH_FLAGS_t{ decoded_value.Flags };
        FieldToJson(jdata["BackingMemory"], meta_struct.BackingMemory);
        FieldToJson(jdata["NodeLocalRootArgumentsTable"], meta_struct.NodeLocalRootArgumentsTable);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SET_RAYTRACING_PIPELINE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC& meta_struct = *data;
        FieldToJson(jdata["ProgramIdentifier"], meta_struct.ProgramIdentifier);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SET_GENERIC_PIPELINE_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC& meta_struct = *data;
        FieldToJson(jdata["ProgramIdentifier"], meta_struct.ProgramIdentifier);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SET_PROGRAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SET_PROGRAM_DESC& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        switch(decoded_value.Type)
        {
            case D3D12_PROGRAM_TYPE_GENERIC_PIPELINE:
            {
                FieldToJson(jdata["GenericPipeline"], meta_struct.generic_pipeline);
                break;
            }
            case D3D12_PROGRAM_TYPE_RAYTRACING_PIPELINE:
            {
                FieldToJson(jdata["RaytracingPipeline"], meta_struct.raytracing_pipeline);
                break;
            }
            case D3D12_PROGRAM_TYPE_WORK_GRAPH:
            {
                FieldToJson(jdata["WorkGraph"], meta_struct.work_graph);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_PROGRAM_TYPE in D3D12_SET_PROGRAM_DESC.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_CPU_INPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_CPU_INPUT& meta_struct = *data;
        jdata["EntrypointIndex"] = decoded_value.EntrypointIndex;
        jdata["NumRecords"] = decoded_value.NumRecords;
        jdata["pRecords"] = meta_struct.pRecords;
        jdata["RecordStrideInBytes"] = decoded_value.RecordStrideInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_NODE_GPU_INPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_NODE_GPU_INPUT& meta_struct = *data;
        jdata["EntrypointIndex"] = decoded_value.EntrypointIndex;
        jdata["NumRecords"] = decoded_value.NumRecords;
        FieldToJson(jdata["Records"], meta_struct.Records);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MULTI_NODE_CPU_INPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MULTI_NODE_CPU_INPUT& meta_struct = *data;
        jdata["NumNodeInputs"] = decoded_value.NumNodeInputs;
        FieldToJson(jdata["pNodeInputs"], meta_struct.pNodeInputs);
        jdata["NodeInputStrideInBytes"] = decoded_value.NodeInputStrideInBytes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MULTI_NODE_GPU_INPUT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MULTI_NODE_GPU_INPUT& meta_struct = *data;
        jdata["NumNodeInputs"] = decoded_value.NumNodeInputs;
        FieldToJson(jdata["NodeInputs"], meta_struct.NodeInputs);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_GRAPH_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_GRAPH_DESC& meta_struct = *data;
        jdata["Mode"] = decoded_value.Mode;
        switch(decoded_value.Mode)
        {
            case D3D12_DISPATCH_MODE_NODE_CPU_INPUT:
            {
                FieldToJson(jdata["NodeCPUInput"], meta_struct.node_cpu_input);
                break;
            }
            case D3D12_DISPATCH_MODE_NODE_GPU_INPUT:
            {
                jdata["NodeGPUInput"] = decoded_value.NodeGPUInput;
                break;
            }
            case D3D12_DISPATCH_MODE_MULTI_NODE_CPU_INPUT:
            {
                FieldToJson(jdata["MultiNodeCPUInput"], meta_struct.multi_node_cpu_input);
                break;
            }
            case D3D12_DISPATCH_MODE_MULTI_NODE_GPU_INPUT:
            {
                jdata["MultiNodeGPUInput"] = decoded_value.MultiNodeGPUInput;
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DISPATCH_MODE in D3D12_DISPATCH_GRAPH_DESC.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SHADER_CACHE_SESSION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& meta_struct = *data;
        FieldToJson(jdata["Identifier"], meta_struct.Identifier);
        jdata["Mode"] = decoded_value.Mode;
        jdata["Flags"] = D3D12_SHADER_CACHE_FLAGS_t{ decoded_value.Flags };
        jdata["MaximumInMemoryCacheSizeBytes"] = decoded_value.MaximumInMemoryCacheSizeBytes;
        jdata["MaximumInMemoryCacheEntries"] = decoded_value.MaximumInMemoryCacheEntries;
        jdata["MaximumValueFileSizeBytes"] = decoded_value.MaximumValueFileSizeBytes;
        jdata["Version"] = decoded_value.Version;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_SUBRESOURCE_RANGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& meta_struct = *data;
        jdata["IndexOrFirstMipLevel"] = decoded_value.IndexOrFirstMipLevel;
        jdata["NumMipLevels"] = decoded_value.NumMipLevels;
        jdata["FirstArraySlice"] = decoded_value.FirstArraySlice;
        jdata["NumArraySlices"] = decoded_value.NumArraySlices;
        jdata["FirstPlane"] = decoded_value.FirstPlane;
        jdata["NumPlanes"] = decoded_value.NumPlanes;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_GLOBAL_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_GLOBAL_BARRIER& meta_struct = *data;
        jdata["SyncBefore"] = decoded_value.SyncBefore;
        jdata["SyncAfter"] = decoded_value.SyncAfter;
        jdata["AccessBefore"] = decoded_value.AccessBefore;
        jdata["AccessAfter"] = decoded_value.AccessAfter;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_TEXTURE_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_TEXTURE_BARRIER& meta_struct = *data;
        jdata["SyncBefore"] = decoded_value.SyncBefore;
        jdata["SyncAfter"] = decoded_value.SyncAfter;
        jdata["AccessBefore"] = decoded_value.AccessBefore;
        jdata["AccessAfter"] = decoded_value.AccessAfter;
        jdata["LayoutBefore"] = decoded_value.LayoutBefore;
        jdata["LayoutAfter"] = decoded_value.LayoutAfter;
        HandleToJson(jdata["pResource"], meta_struct.pResource);
        FieldToJson(jdata["Subresources"], meta_struct.Subresources);
        jdata["Flags"] = D3D12_TEXTURE_BARRIER_FLAGS_t{ decoded_value.Flags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BUFFER_BARRIER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BUFFER_BARRIER& meta_struct = *data;
        jdata["SyncBefore"] = decoded_value.SyncBefore;
        jdata["SyncAfter"] = decoded_value.SyncAfter;
        jdata["AccessBefore"] = decoded_value.AccessBefore;
        jdata["AccessAfter"] = decoded_value.AccessAfter;
        HandleToJson(jdata["pResource"], meta_struct.pResource);
        jdata["Offset"] = decoded_value.Offset;
        jdata["Size"] = decoded_value.Size;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_BARRIER_GROUP& decoded_value = *data->decoded_value;
        const Decoded_D3D12_BARRIER_GROUP& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["NumBarriers"] = decoded_value.NumBarriers;
        switch(decoded_value.Type)
        {
            case D3D12_BARRIER_TYPE_GLOBAL:
            {
                FieldToJson(jdata["pGlobalBarriers"], meta_struct.global_barriers);
                break;
            }
            case D3D12_BARRIER_TYPE_TEXTURE:
            {
                FieldToJson(jdata["pTextureBarriers"], meta_struct.texture_barriers);
                break;
            }
            case D3D12_BARRIER_TYPE_BUFFER:
            {
                FieldToJson(jdata["pBufferBarriers"], meta_struct.buffer_barriers);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_BARRIER_TYPE in D3D12_BARRIER_GROUP.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADERCACHE_ABI_SUPPORT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_FEATURE_DATA_SHADERCACHE_ABI_SUPPORT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_FEATURE_DATA_SHADERCACHE_ABI_SUPPORT& meta_struct = *data;
        FieldToJson(jdata["szAdapterFamily"], meta_struct.szAdapterFamily);
        jdata["MinimumABISupportVersion"] = decoded_value.MinimumABISupportVersion;
        jdata["MaximumABISupportVersion"] = decoded_value.MaximumABISupportVersion;
        jdata["CompilerVersion.Version"] = decoded_value.CompilerVersion.Version;
        jdata["ApplicationProfileVersion.Version"] = decoded_value.ApplicationProfileVersion.Version;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_APPLICATION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_APPLICATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_APPLICATION_DESC& meta_struct = *data;
        FieldToJson(jdata["pExeFilename"], meta_struct.pExeFilename);
        FieldToJson(jdata["pName"], meta_struct.pName);
        jdata["Version.Version"] = decoded_value.Version.Version;
        FieldToJson(jdata["pEngineName"], meta_struct.pEngineName);
        jdata["EngineVersion.Version"] = decoded_value.EngineVersion.Version;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_BY_KEY_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_EXISTING_COLLECTION_BY_KEY_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_EXISTING_COLLECTION_BY_KEY_DESC& meta_struct = *data;
        FieldToJson(jdata["pKey"], meta_struct.pKey);
        jdata["KeySize"] = decoded_value.KeySize;
        jdata["NumExports"] = decoded_value.NumExports;
        FieldToJson(jdata["pExports"], meta_struct.pExports);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_SUBRESOURCE_DATA& decoded_value = *data->decoded_value;
        const Decoded_D3D12_SUBRESOURCE_DATA& meta_struct = *data;
        jdata["pData"] = meta_struct.pData;
        jdata["RowPitch"] = decoded_value.RowPitch;
        jdata["SlicePitch"] = decoded_value.SlicePitch;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MEMCPY_DEST& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MEMCPY_DEST& meta_struct = *data;
        jdata["pData"] = meta_struct.pData;
        jdata["RowPitch"] = decoded_value.RowPitch;
        jdata["SlicePitch"] = decoded_value.SlicePitch;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEVICE_CONFIGURATION_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& meta_struct = *data;
        jdata["Flags"] = D3D12_DEVICE_FLAGS_t{ decoded_value.Flags };
        jdata["GpuBasedValidationFlags"] = decoded_value.GpuBasedValidationFlags;
        jdata["SDKVersion"] = decoded_value.SDKVersion;
        jdata["NumEnabledExperimentalFeatures"] = decoded_value.NumEnabledExperimentalFeatures;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DISPATCH_MESH_ARGUMENTS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& meta_struct = *data;
        jdata["ThreadGroupCountX"] = decoded_value.ThreadGroupCountX;
        jdata["ThreadGroupCountY"] = decoded_value.ThreadGroupCountY;
        jdata["ThreadGroupCountZ"] = decoded_value.ThreadGroupCountZ;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D_SHADER_MACRO& decoded_value = *data->decoded_value;
        const Decoded_D3D_SHADER_MACRO& meta_struct = *data;
        FieldToJson(jdata["Name"], meta_struct.Name);
        FieldToJson(jdata["Definition"], meta_struct.Definition);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        jdata["MaxMessagesPerCommandList"] = decoded_value.MaxMessagesPerCommandList;
        jdata["DefaultShaderPatchMode"] = decoded_value.DefaultShaderPatchMode;
        jdata["PipelineStateCreateFlags"] = D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_t{ decoded_value.PipelineStateCreateFlags };
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& meta_struct = *data;
        FieldToJson(jdata["SlowdownFactor"], decoded_value.SlowdownFactor);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& decoded_value = *data->decoded_value;
        const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& meta_struct = *data;
        jdata["ShaderPatchMode"] = decoded_value.ShaderPatchMode;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_MESSAGE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_MESSAGE& meta_struct = *data;
        jdata["Category"] = decoded_value.Category;
        jdata["Severity"] = decoded_value.Severity;
        jdata["ID"] = decoded_value.ID;
        FieldToJson(jdata["pDescription"], meta_struct.pDescription);
        jdata["DescriptionByteLength"] = decoded_value.DescriptionByteLength;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& meta_struct = *data;
        jdata["NumCategories"] = decoded_value.NumCategories;
        FieldToJson(jdata["pCategoryList"], meta_struct.pCategoryList);
        jdata["NumSeverities"] = decoded_value.NumSeverities;
        FieldToJson(jdata["pSeverityList"], meta_struct.pSeverityList);
        jdata["NumIDs"] = decoded_value.NumIDs;
        FieldToJson(jdata["pIDList"], meta_struct.pIDList);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_INFO_QUEUE_FILTER& decoded_value = *data->decoded_value;
        const Decoded_D3D12_INFO_QUEUE_FILTER& meta_struct = *data;
        FieldToJson(jdata["AllowList"], meta_struct.AllowList);
        FieldToJson(jdata["DenyList"], meta_struct.DenyList);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS& meta_struct = *data;
        jdata["PresentCount"] = decoded_value.PresentCount;
        jdata["PresentRefreshCount"] = decoded_value.PresentRefreshCount;
        jdata["SyncRefreshCount"] = decoded_value.SyncRefreshCount;
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime);
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MAPPED_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MAPPED_RECT& meta_struct = *data;
        jdata["Pitch"] = decoded_value.Pitch;
        FieldToJson(jdata["pBits"], meta_struct.pBits);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description);
        jdata["VendorId"] = decoded_value.VendorId;
        jdata["DeviceId"] = decoded_value.DeviceId;
        jdata["SubSysId"] = decoded_value.SubSysId;
        jdata["Revision"] = decoded_value.Revision;
        jdata["DedicatedVideoMemory"] = decoded_value.DedicatedVideoMemory;
        jdata["DedicatedSystemMemory"] = decoded_value.DedicatedSystemMemory;
        jdata["SharedSystemMemory"] = decoded_value.SharedSystemMemory;
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName);
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates);
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop);
        jdata["Rotation"] = decoded_value.Rotation;
        jdata["Monitor"] = meta_struct.Monitor;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SHARED_RESOURCE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SHARED_RESOURCE& meta_struct = *data;
        jdata["Handle"] = meta_struct.Handle;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SURFACE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SURFACE_DESC& meta_struct = *data;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Format"] = decoded_value.Format;
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC& meta_struct = *data;
        FieldToJson(jdata["BufferDesc"], meta_struct.BufferDesc);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
        jdata["BufferUsage"] = decoded_value.BufferUsage;
        jdata["BufferCount"] = decoded_value.BufferCount;
        jdata["OutputWindow"] = meta_struct.OutputWindow;
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed);
        jdata["SwapEffect"] = decoded_value.SwapEffect;
        jdata["Flags"] = decoded_value.Flags;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC1& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description);
        jdata["VendorId"] = decoded_value.VendorId;
        jdata["DeviceId"] = decoded_value.DeviceId;
        jdata["SubSysId"] = decoded_value.SubSysId;
        jdata["Revision"] = decoded_value.Revision;
        jdata["DedicatedVideoMemory"] = decoded_value.DedicatedVideoMemory;
        jdata["DedicatedSystemMemory"] = decoded_value.DedicatedSystemMemory;
        jdata["SharedSystemMemory"] = decoded_value.SharedSystemMemory;
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid);
        jdata["Flags"] = decoded_value.Flags;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DISPLAY_COLOR_SPACE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DISPLAY_COLOR_SPACE& meta_struct = *data;
        FieldToJson(jdata["PrimaryCoordinates"], meta_struct.PrimaryCoordinates);
        FieldToJson(jdata["WhitePoints"], meta_struct.WhitePoints);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_MOVE_RECT& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_MOVE_RECT& meta_struct = *data;
        FieldToJson(jdata["SourcePoint"], meta_struct.SourcePoint);
        FieldToJson(jdata["DestinationRect"], meta_struct.DestinationRect);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_DESC& meta_struct = *data;
        FieldToJson(jdata["ModeDesc"], meta_struct.ModeDesc);
        jdata["Rotation"] = decoded_value.Rotation;
        Bool32ToJson(jdata["DesktopImageInSystemMemory"], decoded_value.DesktopImageInSystemMemory);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_POSITION& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_POSITION& meta_struct = *data;
        FieldToJson(jdata["Position"], meta_struct.Position);
        Bool32ToJson(jdata["Visible"], decoded_value.Visible);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_POINTER_SHAPE_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Pitch"] = decoded_value.Pitch;
        FieldToJson(jdata["HotSpot"], meta_struct.HotSpot);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTDUPL_FRAME_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTDUPL_FRAME_INFO& meta_struct = *data;
        FieldToJson(jdata["LastPresentTime"], meta_struct.LastPresentTime);
        FieldToJson(jdata["LastMouseUpdateTime"], meta_struct.LastMouseUpdateTime);
        jdata["AccumulatedFrames"] = decoded_value.AccumulatedFrames;
        Bool32ToJson(jdata["RectsCoalesced"], decoded_value.RectsCoalesced);
        Bool32ToJson(jdata["ProtectedContentMaskedOut"], decoded_value.ProtectedContentMaskedOut);
        FieldToJson(jdata["PointerPosition"], meta_struct.PointerPosition);
        jdata["TotalMetadataBufferSize"] = decoded_value.TotalMetadataBufferSize;
        jdata["PointerShapeBufferSize"] = decoded_value.PointerShapeBufferSize;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC1& meta_struct = *data;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate);
        jdata["Format"] = decoded_value.Format;
        jdata["ScanlineOrdering"] = decoded_value.ScanlineOrdering;
        jdata["Scaling"] = decoded_value.Scaling;
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_DESC1& meta_struct = *data;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        jdata["Format"] = decoded_value.Format;
        Bool32ToJson(jdata["Stereo"], decoded_value.Stereo);
        FieldToJson(jdata["SampleDesc"], meta_struct.SampleDesc);
        jdata["BufferUsage"] = decoded_value.BufferUsage;
        jdata["BufferCount"] = decoded_value.BufferCount;
        jdata["Scaling"] = decoded_value.Scaling;
        jdata["SwapEffect"] = decoded_value.SwapEffect;
        jdata["AlphaMode"] = decoded_value.AlphaMode;
        jdata["Flags"] = decoded_value.Flags;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& meta_struct = *data;
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate);
        jdata["ScanlineOrdering"] = decoded_value.ScanlineOrdering;
        jdata["Scaling"] = decoded_value.Scaling;
        Bool32ToJson(jdata["Windowed"], decoded_value.Windowed);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_PRESENT_PARAMETERS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_PRESENT_PARAMETERS& meta_struct = *data;
        jdata["DirtyRectsCount"] = decoded_value.DirtyRectsCount;
        FieldToJson(jdata["pDirtyRects"], meta_struct.pDirtyRects);
        FieldToJson(jdata["pScrollRect"], meta_struct.pScrollRect);
        FieldToJson(jdata["pScrollOffset"], meta_struct.pScrollOffset);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC2& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC2& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description);
        jdata["VendorId"] = decoded_value.VendorId;
        jdata["DeviceId"] = decoded_value.DeviceId;
        jdata["SubSysId"] = decoded_value.SubSysId;
        jdata["Revision"] = decoded_value.Revision;
        jdata["DedicatedVideoMemory"] = decoded_value.DedicatedVideoMemory;
        jdata["DedicatedSystemMemory"] = decoded_value.DedicatedSystemMemory;
        jdata["SharedSystemMemory"] = decoded_value.SharedSystemMemory;
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid);
        jdata["Flags"] = decoded_value.Flags;
        jdata["GraphicsPreemptionGranularity"] = decoded_value.GraphicsPreemptionGranularity;
        jdata["ComputePreemptionGranularity"] = decoded_value.ComputePreemptionGranularity;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MATRIX_3X2_F& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MATRIX_3X2_F& meta_struct = *data;
        FieldToJson(jdata["_11"], decoded_value._11);
        FieldToJson(jdata["_12"], decoded_value._12);
        FieldToJson(jdata["_21"], decoded_value._21);
        FieldToJson(jdata["_22"], decoded_value._22);
        FieldToJson(jdata["_31"], decoded_value._31);
        FieldToJson(jdata["_32"], decoded_value._32);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_DECODE_SWAP_CHAIN_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& meta_struct = *data;
        jdata["Flags"] = decoded_value.Flags;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_FRAME_STATISTICS_MEDIA& decoded_value = *data->decoded_value;
        const Decoded_DXGI_FRAME_STATISTICS_MEDIA& meta_struct = *data;
        jdata["PresentCount"] = decoded_value.PresentCount;
        jdata["PresentRefreshCount"] = decoded_value.PresentRefreshCount;
        jdata["SyncRefreshCount"] = decoded_value.SyncRefreshCount;
        FieldToJson(jdata["SyncQPCTime"], meta_struct.SyncQPCTime);
        FieldToJson(jdata["SyncGPUTime"], meta_struct.SyncGPUTime);
        jdata["CompositionMode"] = decoded_value.CompositionMode;
        jdata["ApprovedPresentDuration"] = decoded_value.ApprovedPresentDuration;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_QUERY_VIDEO_MEMORY_INFO& decoded_value = *data->decoded_value;
        const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& meta_struct = *data;
        jdata["Budget"] = decoded_value.Budget;
        jdata["CurrentUsage"] = decoded_value.CurrentUsage;
        jdata["AvailableForReservation"] = decoded_value.AvailableForReservation;
        jdata["CurrentReservation"] = decoded_value.CurrentReservation;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10& meta_struct = *data;
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary);
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary);
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary);
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint);
        jdata["MaxMasteringLuminance"] = decoded_value.MaxMasteringLuminance;
        jdata["MinMasteringLuminance"] = decoded_value.MinMasteringLuminance;
        jdata["MaxContentLightLevel"] = decoded_value.MaxContentLightLevel;
        jdata["MaxFrameAverageLightLevel"] = decoded_value.MaxFrameAverageLightLevel;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_HDR_METADATA_HDR10PLUS& decoded_value = *data->decoded_value;
        const Decoded_DXGI_HDR_METADATA_HDR10PLUS& meta_struct = *data;
        FieldToJson(jdata["Data"], meta_struct.Data);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_ADAPTER_DESC3& decoded_value = *data->decoded_value;
        const Decoded_DXGI_ADAPTER_DESC3& meta_struct = *data;
        FieldToJson(jdata["Description"], meta_struct.Description);
        jdata["VendorId"] = decoded_value.VendorId;
        jdata["DeviceId"] = decoded_value.DeviceId;
        jdata["SubSysId"] = decoded_value.SubSysId;
        jdata["Revision"] = decoded_value.Revision;
        jdata["DedicatedVideoMemory"] = decoded_value.DedicatedVideoMemory;
        jdata["DedicatedSystemMemory"] = decoded_value.DedicatedSystemMemory;
        jdata["SharedSystemMemory"] = decoded_value.SharedSystemMemory;
        FieldToJson(jdata["AdapterLuid"], meta_struct.AdapterLuid);
        jdata["Flags"] = decoded_value.Flags;
        jdata["GraphicsPreemptionGranularity"] = decoded_value.GraphicsPreemptionGranularity;
        jdata["ComputePreemptionGranularity"] = decoded_value.ComputePreemptionGranularity;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_OUTPUT_DESC1& decoded_value = *data->decoded_value;
        const Decoded_DXGI_OUTPUT_DESC1& meta_struct = *data;
        FieldToJson(jdata["DeviceName"], meta_struct.DeviceName);
        FieldToJson(jdata["DesktopCoordinates"], meta_struct.DesktopCoordinates);
        Bool32ToJson(jdata["AttachedToDesktop"], decoded_value.AttachedToDesktop);
        jdata["Rotation"] = decoded_value.Rotation;
        jdata["Monitor"] = meta_struct.Monitor;
        jdata["BitsPerColor"] = decoded_value.BitsPerColor;
        jdata["ColorSpace"] = decoded_value.ColorSpace;
        FieldToJson(jdata["RedPrimary"], meta_struct.RedPrimary);
        FieldToJson(jdata["GreenPrimary"], meta_struct.GreenPrimary);
        FieldToJson(jdata["BluePrimary"], meta_struct.BluePrimary);
        FieldToJson(jdata["WhitePoint"], meta_struct.WhitePoint);
        FieldToJson(jdata["MinLuminance"], decoded_value.MinLuminance);
        FieldToJson(jdata["MaxLuminance"], decoded_value.MaxLuminance);
        FieldToJson(jdata["MaxFullFrameLuminance"], decoded_value.MaxFullFrameLuminance);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RATIONAL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RATIONAL& meta_struct = *data;
        jdata["Numerator"] = decoded_value.Numerator;
        jdata["Denominator"] = decoded_value.Denominator;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_SAMPLE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_SAMPLE_DESC& meta_struct = *data;
        jdata["Count"] = decoded_value.Count;
        jdata["Quality"] = decoded_value.Quality;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_RGB& decoded_value = *data->decoded_value;
        const Decoded_DXGI_RGB& meta_struct = *data;
        FieldToJson(jdata["Red"], decoded_value.Red);
        FieldToJson(jdata["Green"], decoded_value.Green);
        FieldToJson(jdata["Blue"], decoded_value.Blue);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3DCOLORVALUE& decoded_value = *data->decoded_value;
        const Decoded_D3DCOLORVALUE& meta_struct = *data;
        FieldToJson(jdata["r"], decoded_value.r);
        FieldToJson(jdata["g"], decoded_value.g);
        FieldToJson(jdata["b"], decoded_value.b);
        FieldToJson(jdata["a"], decoded_value.a);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL& meta_struct = *data;
        FieldToJson(jdata["Scale"], meta_struct.Scale);
        FieldToJson(jdata["Offset"], meta_struct.Offset);
        FieldToJson(jdata["GammaCurve"], meta_struct.GammaCurve);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_GAMMA_CONTROL_CAPABILITIES& decoded_value = *data->decoded_value;
        const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& meta_struct = *data;
        Bool32ToJson(jdata["ScaleAndOffsetSupported"], decoded_value.ScaleAndOffsetSupported);
        FieldToJson(jdata["MaxConvertedValue"], decoded_value.MaxConvertedValue);
        FieldToJson(jdata["MinConvertedValue"], decoded_value.MinConvertedValue);
        jdata["NumGammaControlPoints"] = decoded_value.NumGammaControlPoints;
        FieldToJson(jdata["ControlPointPositions"], meta_struct.ControlPointPositions);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_MODE_DESC& decoded_value = *data->decoded_value;
        const Decoded_DXGI_MODE_DESC& meta_struct = *data;
        jdata["Width"] = decoded_value.Width;
        jdata["Height"] = decoded_value.Height;
        FieldToJson(jdata["RefreshRate"], meta_struct.RefreshRate);
        jdata["Format"] = decoded_value.Format;
        jdata["ScanlineOrdering"] = decoded_value.ScanlineOrdering;
        jdata["Scaling"] = decoded_value.Scaling;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_DC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts);
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_AC_HUFFMAN_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& meta_struct = *data;
        FieldToJson(jdata["CodeCounts"], meta_struct.CodeCounts);
        FieldToJson(jdata["CodeValues"], meta_struct.CodeValues);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const DXGI_JPEG_QUANTIZATION_TABLE& decoded_value = *data->decoded_value;
        const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& meta_struct = *data;
        FieldToJson(jdata["Elements"], meta_struct.Elements);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagRECT& decoded_value = *data->decoded_value;
        const Decoded_tagRECT& meta_struct = *data;
        jdata["left"] = decoded_value.left;
        jdata["top"] = decoded_value.top;
        jdata["right"] = decoded_value.right;
        jdata["bottom"] = decoded_value.bottom;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const tagPOINT& decoded_value = *data->decoded_value;
        const Decoded_tagPOINT& meta_struct = *data;
        jdata["x"] = decoded_value.x;
        jdata["y"] = decoded_value.y;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* data)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const _SECURITY_ATTRIBUTES& decoded_value = *data->decoded_value;
        const Decoded__SECURITY_ATTRIBUTES& meta_struct = *data;
        jdata["nLength"] = decoded_value.nLength;
        jdata["lpSecurityDescriptor"] = meta_struct.lpSecurityDescriptor;
        Bool32ToJson(jdata["bInheritHandle"], decoded_value.bInheritHandle);
    }
}

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup custom_dx12_struct_decoders_to_json_bodies Custom implementations for
/// troublesome structs.
/// We put the custom implementations in the generator Python rather than
/// creating a whole new compilation unit for them.
/** @{*/

// Decoded_LARGE_INTEGER won't be generated as it is a <winnt.h> struct rather than D3D12.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* data)
{
    if (data && data->decoded_value)
    {
        const LARGE_INTEGER& decoded_value = *data->decoded_value;
        jdata = decoded_value.QuadPart;
    }
}

// Generated version tries to read the struct members rather than doing the "fake enum" thing.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* data)
{
    if (data && data->decoded_value)
    {
        const GUID& decoded_value = *data->decoded_value;
        FieldToJson(jdata, decoded_value);
    }
}

/// Dump all the fields of the custom struct, even though not all need be populated.
/// @note D3D12 doesn't define names for these: the underlying struct is just a void pointer
/// and a byte count with the structure defined in documentation. See:
/// <https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc>
/// See also: framework\decode\custom_dx12_struct_decoders.cpp
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data)
{
    if (data && data->decoded_value)
    {
        const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
        jdata["SizeInBytes"] = decoded_value.SizeInBytes; // Basic data plumbs to raw struct.
        //FieldToJson(jdata["root_signature_ptr"], meta_struct.root_signature_ptr);
        FieldToJson(jdata[format::kNameWarning], "D3D12_PIPELINE_STATE_STREAM_DESC.root_signature_ptr is not supported.");
        FieldToJson(jdata["root_signature_ptr"], "@todo Get this field to convert cleanly.");
        FieldToJson(jdata["vs_bytecode"], meta_struct.vs_bytecode);
        FieldToJson(jdata["ps_bytecode"], meta_struct.ps_bytecode);
        FieldToJson(jdata["ds_bytecode"], meta_struct.ds_bytecode);
        FieldToJson(jdata["hs_bytecode"], meta_struct.hs_bytecode);
        FieldToJson(jdata["gs_bytecode"], meta_struct.gs_bytecode);
        FieldToJson(jdata["cs_bytecode"], meta_struct.cs_bytecode);
        FieldToJson(jdata["as_bytecode"], meta_struct.as_bytecode);
        FieldToJson(jdata["ms_bytecode"], meta_struct.ms_bytecode);
        FieldToJson(jdata["stream_output"], meta_struct.stream_output);
        FieldToJson(jdata["blend"], meta_struct.blend);
        FieldToJson(jdata["rasterizer"], meta_struct.rasterizer);
        FieldToJson(jdata["depth_stencil"], meta_struct.depth_stencil);
        FieldToJson(jdata["input_layout"], meta_struct.input_layout);
        FieldToJson(jdata["render_target_formats"], meta_struct.render_target_formats);
        FieldToJson(jdata["sample_desc"], meta_struct.sample_desc);
        FieldToJson(jdata["cached_pso"], meta_struct.cached_pso);
        FieldToJson(jdata["depth_stencil1"], meta_struct.depth_stencil1);
        FieldToJson(jdata["view_instancing"], meta_struct.view_instancing);
    }
}

// The decoded struct has a custom implementation.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* data)
{
    if (data && data->decoded_value)
    {
        const D3D12_STATE_SUBOBJECT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_SUBOBJECT& meta_struct = *data;
        jdata["Type"] = decoded_value.Type;
        switch(decoded_value.Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            FieldToJson(jdata["state_object_config"], meta_struct.state_object_config);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            FieldToJson(jdata["global_root_signature"], meta_struct.global_root_signature);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            FieldToJson(jdata["local_root_signature"], meta_struct.local_root_signature);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            FieldToJson(jdata["node_mask"], meta_struct.node_mask);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            FieldToJson(jdata["dxil_library_desc"], meta_struct.dxil_library_desc);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            FieldToJson(jdata["existing_collection_desc"], meta_struct.existing_collection_desc);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["subobject_to_exports_association"], meta_struct.subobject_to_exports_association);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["dxil_subobject_to_exports_association"], meta_struct.dxil_subobject_to_exports_association);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            FieldToJson(jdata["raytracing_shader_config"], meta_struct.raytracing_shader_config);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            FieldToJson(jdata["raytracing_pipeline_config"], meta_struct.raytracing_pipeline_config);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            FieldToJson(jdata["hit_group_desc"], meta_struct.hit_group_desc);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            FieldToJson(jdata["raytracing_pipeline_config1"], meta_struct.raytracing_pipeline_config1);
            break;
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_STATE_SUBOBJECT_TYPE in D3D12_STATE_SUBOBJECT.");
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* data)
{
    if (data && data->decoded_value)
    {
        const D3D12_CPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
        const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        // FieldToJson(jdata[format::kNameInfo], "heap_id and index were copied out of ptr by a custom encoder at capture time, and ptr was never stored in the capture file.");
        jdata["heap_id"] = meta_struct.heap_id;
        jdata["index"] = meta_struct.index;
    }
}

/** @} */

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)
