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

using util::JsonOptions;

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup ManualD3D12StructFieldToJsons Manual functions to convert raw structs.
/** @{ */
static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
{
    using namespace util;
    FieldToJson(jdata["AdditionalWidth"],  data.AdditionalWidth,  options);
    FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
}

static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
{
    using namespace util;
    FieldToJson(jdata["AdditionalWidth"], data.AdditionalWidth, options);
    FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
}

/// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
{
    FieldToJson(jdata["Depth"], obj.Depth, options);
    FieldToJson(jdata["Stencil"], obj.Stencil, options);
}
/** @} */

inline bool RepresentBinaryFile(const util::JsonOptions& json_options, nlohmann::ordered_json& jdata, std::string_view filename_base, const uint64_t instance_counter, const PointerDecoder<uint8_t>& data)
{
    return RepresentBinaryFile(json_options, jdata, filename_base, instance_counter, data.GetLength(), data.GetPointer());
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["Priority"], data->decoded_value->Priority, options);
        FieldToJson_D3D12_COMMAND_QUEUE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SemanticName"], data->SemanticName, options);
        FieldToJson(jdata["SemanticIndex"], data->decoded_value->SemanticIndex, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["InputSlot"], data->decoded_value->InputSlot, options);
        FieldToJson(jdata["AlignedByteOffset"], data->decoded_value->AlignedByteOffset, options);
        FieldToJson(jdata["InputSlotClass"], data->decoded_value->InputSlotClass, options);
        FieldToJson(jdata["InstanceDataStepRate"], data->decoded_value->InstanceDataStepRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Stream"], data->decoded_value->Stream, options);
        FieldToJson(jdata["SemanticName"], data->SemanticName, options);
        FieldToJson(jdata["SemanticIndex"], data->decoded_value->SemanticIndex, options);
        FieldToJson(jdata["StartComponent"], data->decoded_value->StartComponent, options);
        FieldToJson(jdata["ComponentCount"], data->decoded_value->ComponentCount, options);
        FieldToJson(jdata["OutputSlot"], data->decoded_value->OutputSlot, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["TopLeftX"], data->decoded_value->TopLeftX, options);
        FieldToJson(jdata["TopLeftY"], data->decoded_value->TopLeftY, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["MinDepth"], data->decoded_value->MinDepth, options);
        FieldToJson(jdata["MaxDepth"], data->decoded_value->MaxDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["left"], data->decoded_value->left, options);
        FieldToJson(jdata["top"], data->decoded_value->top, options);
        FieldToJson(jdata["front"], data->decoded_value->front, options);
        FieldToJson(jdata["right"], data->decoded_value->right, options);
        FieldToJson(jdata["bottom"], data->decoded_value->bottom, options);
        FieldToJson(jdata["back"], data->decoded_value->back, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["LowPart"], data->decoded_value->LowPart, options);
        FieldToJson(jdata["HighPart"], data->decoded_value->HighPart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["StencilFailOp"], data->decoded_value->StencilFailOp, options);
        FieldToJson(jdata["StencilDepthFailOp"], data->decoded_value->StencilDepthFailOp, options);
        FieldToJson(jdata["StencilPassOp"], data->decoded_value->StencilPassOp, options);
        FieldToJson(jdata["StencilFunc"], data->decoded_value->StencilFunc, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DepthEnable"], data->decoded_value->DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], data->decoded_value->DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], data->decoded_value->DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], data->decoded_value->StencilEnable, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], data->decoded_value->StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], data->decoded_value->StencilWriteMask, options);
        FieldToJson(jdata["FrontFace"], data->FrontFace, options);
        FieldToJson(jdata["BackFace"], data->BackFace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DepthEnable"], data->decoded_value->DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], data->decoded_value->DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], data->decoded_value->DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], data->decoded_value->StencilEnable, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], data->decoded_value->StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], data->decoded_value->StencilWriteMask, options);
        FieldToJson(jdata["FrontFace"], data->FrontFace, options);
        FieldToJson(jdata["BackFace"], data->BackFace, options);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], data->decoded_value->DepthBoundsTestEnable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["StencilFailOp"], data->decoded_value->StencilFailOp, options);
        FieldToJson(jdata["StencilDepthFailOp"], data->decoded_value->StencilDepthFailOp, options);
        FieldToJson(jdata["StencilPassOp"], data->decoded_value->StencilPassOp, options);
        FieldToJson(jdata["StencilFunc"], data->decoded_value->StencilFunc, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilReadMask"], data->decoded_value->StencilReadMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["StencilWriteMask"], data->decoded_value->StencilWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DepthEnable"], data->decoded_value->DepthEnable, options);
        FieldToJson(jdata["DepthWriteMask"], data->decoded_value->DepthWriteMask, options);
        FieldToJson(jdata["DepthFunc"], data->decoded_value->DepthFunc, options);
        Bool32ToJson(jdata["StencilEnable"], data->decoded_value->StencilEnable, options);
        FieldToJson(jdata["FrontFace"], data->FrontFace, options);
        FieldToJson(jdata["BackFace"], data->BackFace, options);
        Bool32ToJson(jdata["DepthBoundsTestEnable"], data->decoded_value->DepthBoundsTestEnable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["BlendEnable"], data->decoded_value->BlendEnable, options);
        Bool32ToJson(jdata["LogicOpEnable"], data->decoded_value->LogicOpEnable, options);
        FieldToJson(jdata["SrcBlend"], data->decoded_value->SrcBlend, options);
        FieldToJson(jdata["DestBlend"], data->decoded_value->DestBlend, options);
        FieldToJson(jdata["BlendOp"], data->decoded_value->BlendOp, options);
        FieldToJson(jdata["SrcBlendAlpha"], data->decoded_value->SrcBlendAlpha, options);
        FieldToJson(jdata["DestBlendAlpha"], data->decoded_value->DestBlendAlpha, options);
        FieldToJson(jdata["BlendOpAlpha"], data->decoded_value->BlendOpAlpha, options);
        FieldToJson(jdata["LogicOp"], data->decoded_value->LogicOp, options);
        FieldToJsonAsFixedWidthBinary(jdata["RenderTargetWriteMask"], data->decoded_value->RenderTargetWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["AlphaToCoverageEnable"], data->decoded_value->AlphaToCoverageEnable, options);
        Bool32ToJson(jdata["IndependentBlendEnable"], data->decoded_value->IndependentBlendEnable, options);
        FieldToJson(jdata["RenderTarget"], data->RenderTarget, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FillMode"], data->decoded_value->FillMode, options);
        FieldToJson(jdata["CullMode"], data->decoded_value->CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], data->decoded_value->FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], data->decoded_value->DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], data->decoded_value->DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], data->decoded_value->SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], data->decoded_value->DepthClipEnable, options);
        Bool32ToJson(jdata["MultisampleEnable"], data->decoded_value->MultisampleEnable, options);
        Bool32ToJson(jdata["AntialiasedLineEnable"], data->decoded_value->AntialiasedLineEnable, options);
        FieldToJson(jdata["ForcedSampleCount"], data->decoded_value->ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], data->decoded_value->ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FillMode"], data->decoded_value->FillMode, options);
        FieldToJson(jdata["CullMode"], data->decoded_value->CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], data->decoded_value->FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], data->decoded_value->DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], data->decoded_value->DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], data->decoded_value->SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], data->decoded_value->DepthClipEnable, options);
        Bool32ToJson(jdata["MultisampleEnable"], data->decoded_value->MultisampleEnable, options);
        Bool32ToJson(jdata["AntialiasedLineEnable"], data->decoded_value->AntialiasedLineEnable, options);
        FieldToJson(jdata["ForcedSampleCount"], data->decoded_value->ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], data->decoded_value->ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FillMode"], data->decoded_value->FillMode, options);
        FieldToJson(jdata["CullMode"], data->decoded_value->CullMode, options);
        Bool32ToJson(jdata["FrontCounterClockwise"], data->decoded_value->FrontCounterClockwise, options);
        FieldToJson(jdata["DepthBias"], data->decoded_value->DepthBias, options);
        FieldToJson(jdata["DepthBiasClamp"], data->decoded_value->DepthBiasClamp, options);
        FieldToJson(jdata["SlopeScaledDepthBias"], data->decoded_value->SlopeScaledDepthBias, options);
        Bool32ToJson(jdata["DepthClipEnable"], data->decoded_value->DepthClipEnable, options);
        FieldToJson(jdata["LineRasterizationMode"], data->decoded_value->LineRasterizationMode, options);
        FieldToJson(jdata["ForcedSampleCount"], data->decoded_value->ForcedSampleCount, options);
        FieldToJson(jdata["ConservativeRaster"], data->decoded_value->ConservativeRaster, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        static thread_local uint64_t D3D12_SHADER_BYTECODE_pShaderBytecode_counter{ 0 };
        const bool written = RepresentBinaryFile(options, jdata["pShaderBytecode"], "D3D12_SHADER_BYTECODE.pShaderBytecode", D3D12_SHADER_BYTECODE_pShaderBytecode_counter, data->pShaderBytecode);
        D3D12_SHADER_BYTECODE_pShaderBytecode_counter += written;

        FieldToJson(jdata["BytecodeLength"], data->decoded_value->BytecodeLength, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pSODeclaration"], data->pSODeclaration, options);
        FieldToJson(jdata["NumEntries"], data->decoded_value->NumEntries, options);
        FieldToJson(jdata["pBufferStrides"], data->pBufferStrides, options);
        FieldToJson(jdata["NumStrides"], data->decoded_value->NumStrides, options);
        FieldToJson(jdata["RasterizedStream"], data->decoded_value->RasterizedStream, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pInputElementDescs"], data->pInputElementDescs, options);
        FieldToJson(jdata["NumElements"], data->decoded_value->NumElements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pCachedBlob"], data->pCachedBlob, options);
        FieldToJson(jdata["CachedBlobSizeInBytes"], data->decoded_value->CachedBlobSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pRootSignature"], data->pRootSignature, options);
        FieldToJson(jdata["VS"], data->VS, options);
        FieldToJson(jdata["PS"], data->PS, options);
        FieldToJson(jdata["DS"], data->DS, options);
        FieldToJson(jdata["HS"], data->HS, options);
        FieldToJson(jdata["GS"], data->GS, options);
        FieldToJson(jdata["StreamOutput"], data->StreamOutput, options);
        FieldToJson(jdata["BlendState"], data->BlendState, options);
        FieldToJsonAsFixedWidthBinary(jdata["SampleMask"], data->decoded_value->SampleMask, options);
        FieldToJson(jdata["RasterizerState"], data->RasterizerState, options);
        FieldToJson(jdata["DepthStencilState"], data->DepthStencilState, options);
        FieldToJson(jdata["InputLayout"], data->InputLayout, options);
        FieldToJson(jdata["IBStripCutValue"], data->decoded_value->IBStripCutValue, options);
        FieldToJson(jdata["PrimitiveTopologyType"], data->decoded_value->PrimitiveTopologyType, options);
        FieldToJson(jdata["NumRenderTargets"], data->decoded_value->NumRenderTargets, options);
        FieldToJson(jdata["RTVFormats"], data->RTVFormats, options);
        FieldToJson(jdata["DSVFormat"], data->decoded_value->DSVFormat, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
        FieldToJson(jdata["CachedPSO"], data->CachedPSO, options);
        FieldToJson_D3D12_PIPELINE_STATE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pRootSignature"], data->pRootSignature, options);
        FieldToJson(jdata["CS"], data->CS, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
        FieldToJson(jdata["CachedPSO"], data->CachedPSO, options);
        FieldToJson_D3D12_PIPELINE_STATE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RTFormats"], data->RTFormats, options);
        FieldToJson(jdata["NumRenderTargets"], data->decoded_value->NumRenderTargets, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DoublePrecisionFloatShaderOps"], data->decoded_value->DoublePrecisionFloatShaderOps, options);
        Bool32ToJson(jdata["OutputMergerLogicOp"], data->decoded_value->OutputMergerLogicOp, options);
        FieldToJson_D3D12_SHADER_MIN_PRECISION_SUPPORT(jdata["MinPrecisionSupport"], data->decoded_value->MinPrecisionSupport, options);
        FieldToJson(jdata["TiledResourcesTier"], data->decoded_value->TiledResourcesTier, options);
        FieldToJson(jdata["ResourceBindingTier"], data->decoded_value->ResourceBindingTier, options);
        Bool32ToJson(jdata["PSSpecifiedStencilRefSupported"], data->decoded_value->PSSpecifiedStencilRefSupported, options);
        Bool32ToJson(jdata["TypedUAVLoadAdditionalFormats"], data->decoded_value->TypedUAVLoadAdditionalFormats, options);
        Bool32ToJson(jdata["ROVsSupported"], data->decoded_value->ROVsSupported, options);
        FieldToJson(jdata["ConservativeRasterizationTier"], data->decoded_value->ConservativeRasterizationTier, options);
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], data->decoded_value->MaxGPUVirtualAddressBitsPerResource, options);
        Bool32ToJson(jdata["StandardSwizzle64KBSupported"], data->decoded_value->StandardSwizzle64KBSupported, options);
        FieldToJson(jdata["CrossNodeSharingTier"], data->decoded_value->CrossNodeSharingTier, options);
        Bool32ToJson(jdata["CrossAdapterRowMajorTextureSupported"], data->decoded_value->CrossAdapterRowMajorTextureSupported, options);
        Bool32ToJson(jdata["VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation"], data->decoded_value->VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, options);
        FieldToJson(jdata["ResourceHeapTier"], data->decoded_value->ResourceHeapTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["WaveOps"], data->decoded_value->WaveOps, options);
        FieldToJson(jdata["WaveLaneCountMin"], data->decoded_value->WaveLaneCountMin, options);
        FieldToJson(jdata["WaveLaneCountMax"], data->decoded_value->WaveLaneCountMax, options);
        FieldToJson(jdata["TotalLaneCount"], data->decoded_value->TotalLaneCount, options);
        Bool32ToJson(jdata["ExpandedComputeResourceStates"], data->decoded_value->ExpandedComputeResourceStates, options);
        Bool32ToJson(jdata["Int64ShaderOps"], data->decoded_value->Int64ShaderOps, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DepthBoundsTestSupported"], data->decoded_value->DepthBoundsTestSupported, options);
        FieldToJson(jdata["ProgrammableSamplePositionsTier"], data->decoded_value->ProgrammableSamplePositionsTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["HighestVersion"], data->decoded_value->HighestVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        Bool32ToJson(jdata["TileBasedRenderer"], data->decoded_value->TileBasedRenderer, options);
        Bool32ToJson(jdata["UMA"], data->decoded_value->UMA, options);
        Bool32ToJson(jdata["CacheCoherentUMA"], data->decoded_value->CacheCoherentUMA, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        Bool32ToJson(jdata["TileBasedRenderer"], data->decoded_value->TileBasedRenderer, options);
        Bool32ToJson(jdata["UMA"], data->decoded_value->UMA, options);
        Bool32ToJson(jdata["CacheCoherentUMA"], data->decoded_value->CacheCoherentUMA, options);
        Bool32ToJson(jdata["IsolatedMMU"], data->decoded_value->IsolatedMMU, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumFeatureLevels"], data->decoded_value->NumFeatureLevels, options);
        FieldToJson(jdata["pFeatureLevelsRequested"], data->pFeatureLevelsRequested, options);
        FieldToJson(jdata["MaxSupportedFeatureLevel"], data->decoded_value->MaxSupportedFeatureLevel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["HighestShaderModel"], data->decoded_value->HighestShaderModel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson_D3D12_FORMAT_SUPPORT1(jdata["Support1"], data->decoded_value->Support1, options);
        FieldToJson_D3D12_FORMAT_SUPPORT2(jdata["Support2"], data->decoded_value->Support2, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["SampleCount"], data->decoded_value->SampleCount, options);
        FieldToJson_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["NumQualityLevels"], data->decoded_value->NumQualityLevels, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["PlaneCount"], data->decoded_value->PlaneCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerResource"], data->decoded_value->MaxGPUVirtualAddressBitsPerResource, options);
        FieldToJson(jdata["MaxGPUVirtualAddressBitsPerProcess"], data->decoded_value->MaxGPUVirtualAddressBitsPerProcess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson_D3D12_SHADER_CACHE_SUPPORT_FLAGS(jdata["SupportFlags"], data->decoded_value->SupportFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CommandListType"], data->decoded_value->CommandListType, options);
        FieldToJson(jdata["Priority"], data->decoded_value->Priority, options);
        Bool32ToJson(jdata["PriorityForTypeIsSupported"], data->decoded_value->PriorityForTypeIsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["CopyQueueTimestampQueriesSupported"], data->decoded_value->CopyQueueTimestampQueriesSupported, options);
        Bool32ToJson(jdata["CastingFullyTypedFormatSupported"], data->decoded_value->CastingFullyTypedFormatSupported, options);
        FieldToJson_D3D12_COMMAND_LIST_SUPPORT_FLAGS(jdata["WriteBufferImmediateSupportFlags"], data->decoded_value->WriteBufferImmediateSupportFlags, options);
        FieldToJson(jdata["ViewInstancingTier"], data->decoded_value->ViewInstancingTier, options);
        Bool32ToJson(jdata["BarycentricsSupported"], data->decoded_value->BarycentricsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DisplayableTexture"], data->decoded_value->DisplayableTexture, options);
        FieldToJson(jdata["SharedResourceCompatibilityTier"], data->decoded_value->SharedResourceCompatibilityTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["MSAA64KBAlignedTextureSupported"], data->decoded_value->MSAA64KBAlignedTextureSupported, options);
        FieldToJson(jdata["SharedResourceCompatibilityTier"], data->decoded_value->SharedResourceCompatibilityTier, options);
        Bool32ToJson(jdata["Native16BitShaderOpsSupported"], data->decoded_value->Native16BitShaderOpsSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        FieldToJson(jdata["HeapSerializationTier"], data->decoded_value->HeapSerializationTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SharingTier"], data->decoded_value->SharingTier, options);
        Bool32ToJson(jdata["AtomicShaderInstructions"], data->decoded_value->AtomicShaderInstructions, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["SRVOnlyTiledResourceTier3"], data->decoded_value->SRVOnlyTiledResourceTier3, options);
        FieldToJson(jdata["RenderPassesTier"], data->decoded_value->RenderPassesTier, options);
        FieldToJson(jdata["RaytracingTier"], data->decoded_value->RaytracingTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["AdditionalShadingRatesSupported"], data->decoded_value->AdditionalShadingRatesSupported, options);
        Bool32ToJson(jdata["PerPrimitiveShadingRateSupportedWithViewportIndexing"], data->decoded_value->PerPrimitiveShadingRateSupportedWithViewportIndexing, options);
        FieldToJson(jdata["VariableShadingRateTier"], data->decoded_value->VariableShadingRateTier, options);
        FieldToJson(jdata["ShadingRateImageTileSize"], data->decoded_value->ShadingRateImageTileSize, options);
        Bool32ToJson(jdata["BackgroundProcessingSupported"], data->decoded_value->BackgroundProcessingSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MeshShaderTier"], data->decoded_value->MeshShaderTier, options);
        FieldToJson(jdata["SamplerFeedbackTier"], data->decoded_value->SamplerFeedbackTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CommandId"], data->CommandId, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
        FieldToJson(jdata["pQueryInputData"], data->pQueryInputData, options);
        FieldToJson(jdata["QueryInputDataSizeInBytes"], data->decoded_value->QueryInputDataSizeInBytes, options);
        FieldToJson(jdata["pQueryOutputData"], data->pQueryOutputData, options);
        FieldToJson(jdata["QueryOutputDataSizeInBytes"], data->decoded_value->QueryOutputDataSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["UnalignedBlockTexturesSupported"], data->decoded_value->UnalignedBlockTexturesSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["MeshShaderPipelineStatsSupported"], data->decoded_value->MeshShaderPipelineStatsSupported, options);
        Bool32ToJson(jdata["MeshShaderSupportsFullRangeRenderTargetArrayIndex"], data->decoded_value->MeshShaderSupportsFullRangeRenderTargetArrayIndex, options);
        Bool32ToJson(jdata["AtomicInt64OnTypedResourceSupported"], data->decoded_value->AtomicInt64OnTypedResourceSupported, options);
        Bool32ToJson(jdata["AtomicInt64OnGroupSharedSupported"], data->decoded_value->AtomicInt64OnGroupSharedSupported, options);
        Bool32ToJson(jdata["DerivativesInMeshAndAmplificationShadersSupported"], data->decoded_value->DerivativesInMeshAndAmplificationShadersSupported, options);
        FieldToJson(jdata["WaveMMATier"], data->decoded_value->WaveMMATier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["VariableRateShadingSumCombinerSupported"], data->decoded_value->VariableRateShadingSumCombinerSupported, options);
        Bool32ToJson(jdata["MeshShaderPerPrimitiveShadingRateSupported"], data->decoded_value->MeshShaderPerPrimitiveShadingRateSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["AtomicInt64OnDescriptorHeapResourceSupported"], data->decoded_value->AtomicInt64OnDescriptorHeapResourceSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MSPrimitivesPipelineStatisticIncludesCulledPrimitives"], data->decoded_value->MSPrimitivesPipelineStatisticIncludesCulledPrimitives, options);
        Bool32ToJson(jdata["EnhancedBarriersSupported"], data->decoded_value->EnhancedBarriersSupported, options);
        Bool32ToJson(jdata["RelaxedFormatCastingSupported"], data->decoded_value->RelaxedFormatCastingSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["UnrestrictedBufferTextureCopyPitchSupported"], data->decoded_value->UnrestrictedBufferTextureCopyPitchSupported, options);
        Bool32ToJson(jdata["UnrestrictedVertexElementAlignmentSupported"], data->decoded_value->UnrestrictedVertexElementAlignmentSupported, options);
        Bool32ToJson(jdata["InvertedViewportHeightFlipsYSupported"], data->decoded_value->InvertedViewportHeightFlipsYSupported, options);
        Bool32ToJson(jdata["InvertedViewportDepthFlipsZSupported"], data->decoded_value->InvertedViewportDepthFlipsZSupported, options);
        Bool32ToJson(jdata["TextureCopyBetweenDimensionsSupported"], data->decoded_value->TextureCopyBetweenDimensionsSupported, options);
        Bool32ToJson(jdata["AlphaBlendFactorSupported"], data->decoded_value->AlphaBlendFactorSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["AdvancedTextureOpsSupported"], data->decoded_value->AdvancedTextureOpsSupported, options);
        Bool32ToJson(jdata["WriteableMSAATexturesSupported"], data->decoded_value->WriteableMSAATexturesSupported, options);
        Bool32ToJson(jdata["IndependentFrontAndBackStencilRefMaskSupported"], data->decoded_value->IndependentFrontAndBackStencilRefMaskSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["TriangleFanSupported"], data->decoded_value->TriangleFanSupported, options);
        Bool32ToJson(jdata["DynamicIndexBufferStripCutSupported"], data->decoded_value->DynamicIndexBufferStripCutSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["DynamicDepthBiasSupported"], data->decoded_value->DynamicDepthBiasSupported, options);
        Bool32ToJson(jdata["GPUUploadHeapSupported"], data->decoded_value->GPUUploadHeapSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["NonNormalizedCoordinateSamplersSupported"], data->decoded_value->NonNormalizedCoordinateSamplersSupported, options);
        Bool32ToJson(jdata["ManualWriteTrackingResourceSupported"], data->decoded_value->ManualWriteTrackingResourceSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["RenderPassesValid"], data->decoded_value->RenderPassesValid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["MismatchingOutputDimensionsSupported"], data->decoded_value->MismatchingOutputDimensionsSupported, options);
        FieldToJson(jdata["SupportedSampleCountsWithNoOutputs"], data->decoded_value->SupportedSampleCountsWithNoOutputs, options);
        Bool32ToJson(jdata["PointSamplingAddressesNeverRoundUp"], data->decoded_value->PointSamplingAddressesNeverRoundUp, options);
        Bool32ToJson(jdata["RasterizerDesc2Supported"], data->decoded_value->RasterizerDesc2Supported, options);
        Bool32ToJson(jdata["NarrowQuadrilateralLinesSupported"], data->decoded_value->NarrowQuadrilateralLinesSupported, options);
        Bool32ToJson(jdata["AnisoFilterWithPointMipSupported"], data->decoded_value->AnisoFilterWithPointMipSupported, options);
        FieldToJson(jdata["MaxSamplerDescriptorHeapSize"], data->decoded_value->MaxSamplerDescriptorHeapSize, options);
        FieldToJson(jdata["MaxSamplerDescriptorHeapSizeWithStaticSamplers"], data->decoded_value->MaxSamplerDescriptorHeapSizeWithStaticSamplers, options);
        FieldToJson(jdata["MaxViewDescriptorHeapSize"], data->decoded_value->MaxViewDescriptorHeapSize, options);
        Bool32ToJson(jdata["ComputeOnlyCustomHeapSupported"], data->decoded_value->ComputeOnlyCustomHeapSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["ComputeOnlyWriteWatchSupported"], data->decoded_value->ComputeOnlyWriteWatchSupported, options);
        FieldToJson(jdata["RecreateAtTier"], data->decoded_value->RecreateAtTier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["WorkGraphsTier"], data->decoded_value->WorkGraphsTier, options);
        FieldToJson(jdata["ExecuteIndirectTier"], data->decoded_value->ExecuteIndirectTier, options);
        Bool32ToJson(jdata["SampleCmpGradientAndBiasSupported"], data->decoded_value->SampleCmpGradientAndBiasSupported, options);
        Bool32ToJson(jdata["ExtendedCommandInfoSupported"], data->decoded_value->ExtendedCommandInfoSupported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJson(jdata["Alignment"], data->decoded_value->Alignment, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Offset"], data->decoded_value->Offset, options);
        FieldToJson(jdata["Alignment"], data->decoded_value->Alignment, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["CPUPageProperty"], data->decoded_value->CPUPageProperty, options);
        FieldToJson(jdata["MemoryPoolPreference"], data->decoded_value->MemoryPoolPreference, options);
        FieldToJsonAsFixedWidthBinary(jdata["CreationNodeMask"], data->decoded_value->CreationNodeMask, options);
        FieldToJsonAsFixedWidthBinary(jdata["VisibleNodeMask"], data->decoded_value->VisibleNodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJson(jdata["Properties"], data->Properties, options);
        FieldToJson(jdata["Alignment"], data->decoded_value->Alignment, options);
        FieldToJson_D3D12_HEAP_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["Dimension"], data->decoded_value->Dimension, options);
        FieldToJson(jdata["DestHeapProperties"], data->DestHeapProperties, options);
        Bool32ToJson(jdata["Supported"], data->decoded_value->Supported, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Depth"], data->decoded_value->Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Dimension"], data->decoded_value->Dimension, options);
        FieldToJson(jdata["Alignment"], data->decoded_value->Alignment, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["DepthOrArraySize"], data->decoded_value->DepthOrArraySize, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
        FieldToJson(jdata["Layout"], data->decoded_value->Layout, options);
        FieldToJson_D3D12_RESOURCE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Dimension"], data->decoded_value->Dimension, options);
        FieldToJson(jdata["Alignment"], data->decoded_value->Alignment, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["DepthOrArraySize"], data->decoded_value->DepthOrArraySize, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
        FieldToJson(jdata["Layout"], data->decoded_value->Layout, options);
        FieldToJson_D3D12_RESOURCE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["SamplerFeedbackMipRegion"], data->SamplerFeedbackMipRegion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Depth"], data->decoded_value->Depth, options);
        FieldToJson(jdata["Stencil"], data->decoded_value->Stencil, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        if(graphics::dx12::IsDepthStencilFormat(data->decoded_value->Format))
        {
            FieldToJson(jdata["DepthStencil"], data->decoded_value->DepthStencil, options);
        }
        else
        {
            FieldToJson(jdata["Color"], data->decoded_value->Color, options);
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Begin"], data->decoded_value->Begin, options);
        FieldToJson(jdata["End"], data->decoded_value->End, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Begin"], data->decoded_value->Begin, options);
        FieldToJson(jdata["End"], data->decoded_value->End, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Subresource"], data->decoded_value->Subresource, options);
        FieldToJson(jdata["Range"], data->Range, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Offset"], data->decoded_value->Offset, options);
        FieldToJson(jdata["RowPitch"], data->decoded_value->RowPitch, options);
        FieldToJson(jdata["DepthPitch"], data->decoded_value->DepthPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["X"], data->decoded_value->X, options);
        FieldToJson(jdata["Y"], data->decoded_value->Y, options);
        FieldToJson(jdata["Z"], data->decoded_value->Z, options);
        FieldToJson(jdata["Subresource"], data->decoded_value->Subresource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumTiles"], data->decoded_value->NumTiles, options);
        Bool32ToJson(jdata["UseBox"], data->decoded_value->UseBox, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Depth"], data->decoded_value->Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["WidthInTiles"], data->decoded_value->WidthInTiles, options);
        FieldToJson(jdata["HeightInTiles"], data->decoded_value->HeightInTiles, options);
        FieldToJson(jdata["DepthInTiles"], data->decoded_value->DepthInTiles, options);
        FieldToJson(jdata["StartTileIndexInOverallResource"], data->decoded_value->StartTileIndexInOverallResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["WidthInTexels"], data->decoded_value->WidthInTexels, options);
        FieldToJson(jdata["HeightInTexels"], data->decoded_value->HeightInTexels, options);
        FieldToJson(jdata["DepthInTexels"], data->decoded_value->DepthInTexels, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumStandardMips"], data->decoded_value->NumStandardMips, options);
        FieldToJson(jdata["NumPackedMips"], data->decoded_value->NumPackedMips, options);
        FieldToJson(jdata["NumTilesForPackedMips"], data->decoded_value->NumTilesForPackedMips, options);
        FieldToJson(jdata["StartTileIndexInOverallResource"], data->decoded_value->StartTileIndexInOverallResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pResource"], data->pResource, options);
        FieldToJson(jdata["Subresource"], data->decoded_value->Subresource, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["StateBefore"], data->decoded_value->StateBefore, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["StateAfter"], data->decoded_value->StateAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pResourceBefore"], data->pResourceBefore, options);
        FieldToJson(jdata["pResourceAfter"], data->pResourceAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pResource"], data->pResource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson_D3D12_RESOURCE_BARRIER_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            {
                FieldToJson(jdata["Transition"], data->Transition, options);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            {
                FieldToJson(jdata["Aliasing"], data->Aliasing, options);
                break;
            }
            case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            {
                FieldToJson(jdata["UAV"], data->UAV, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RESOURCE_BARRIER_TYPE in D3D12_RESOURCE_BARRIER.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Depth"], data->decoded_value->Depth, options);
        FieldToJson(jdata["RowPitch"], data->decoded_value->RowPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Offset"], data->decoded_value->Offset, options);
        FieldToJson(jdata["Footprint"], data->Footprint, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pResource"], data->pResource, options);
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            {
                FieldToJson(jdata["SubresourceIndex"], data->decoded_value->SubresourceIndex, options);
                break;
            }
            case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            {
                FieldToJson(jdata["PlacedFootprint"], data->PlacedFootprint, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_TEXTURE_COPY_TYPE in D3D12_TEXTURE_COPY_LOCATION.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["X"], data->decoded_value->X, options);
        FieldToJson(jdata["Y"], data->decoded_value->Y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ViewportArrayIndex"], data->decoded_value->ViewportArrayIndex, options);
        FieldToJson(jdata["RenderTargetArrayIndex"], data->decoded_value->RenderTargetArrayIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ViewInstanceCount"], data->decoded_value->ViewInstanceCount, options);
        FieldToJson(jdata["pViewInstanceLocations"], data->pViewInstanceLocations, options);
        FieldToJson_D3D12_VIEW_INSTANCING_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstElement"], data->decoded_value->FirstElement, options);
        FieldToJson(jdata["NumElements"], data->decoded_value->NumElements, options);
        FieldToJson(jdata["StructureByteStride"], data->decoded_value->StructureByteStride, options);
        FieldToJson_D3D12_BUFFER_SRV_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MostDetailedMip"], data->decoded_value->MostDetailedMip, options);
        FieldToJson(jdata["MipLevels"], data->decoded_value->MipLevels, options);
        FieldToJson(jdata["First2DArrayFace"], data->decoded_value->First2DArrayFace, options);
        FieldToJson(jdata["NumCubes"], data->decoded_value->NumCubes, options);
        FieldToJson(jdata["ResourceMinLODClamp"], data->decoded_value->ResourceMinLODClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["UnusedField_NothingToDefine"], data->decoded_value->UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["Location"], data->decoded_value->Location, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ViewDimension"], data->decoded_value->ViewDimension, options);
        FieldToJson(jdata["Shader4ComponentMapping"], data->decoded_value->Shader4ComponentMapping, options);
        switch(data->decoded_value->ViewDimension)
        {
            case D3D12_SRV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], data->Buffer, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], data->Texture1D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], data->Texture1DArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], data->Texture2D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], data->Texture2DArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], data->Texture2DMS, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], data->Texture2DMSArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], data->Texture3D, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBE:
            {
                FieldToJson(jdata["TextureCube"], data->TextureCube, options);
                break;
            }
            case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            {
                FieldToJson(jdata["TextureCubeArray"], data->TextureCubeArray, options);
                break;
            }
            case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            {
                FieldToJson(jdata["RaytracingAccelerationStructure"], data->RaytracingAccelerationStructure, options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["BufferLocation"], data->decoded_value->BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Filter"], data->decoded_value->Filter, options);
        FieldToJson(jdata["AddressU"], data->decoded_value->AddressU, options);
        FieldToJson(jdata["AddressV"], data->decoded_value->AddressV, options);
        FieldToJson(jdata["AddressW"], data->decoded_value->AddressW, options);
        FieldToJson(jdata["MipLODBias"], data->decoded_value->MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], data->decoded_value->MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], data->decoded_value->ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], data->BorderColor, options);
        FieldToJson(jdata["MinLOD"], data->decoded_value->MinLOD, options);
        FieldToJson(jdata["MaxLOD"], data->decoded_value->MaxLOD, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Filter"], data->decoded_value->Filter, options);
        FieldToJson(jdata["AddressU"], data->decoded_value->AddressU, options);
        FieldToJson(jdata["AddressV"], data->decoded_value->AddressV, options);
        FieldToJson(jdata["AddressW"], data->decoded_value->AddressW, options);
        FieldToJson(jdata["MipLODBias"], data->decoded_value->MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], data->decoded_value->MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], data->decoded_value->ComparisonFunc, options);
        if(data->decoded_value->Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
        {
            FieldToJson(jdata["UintBorderColor"], data->decoded_value->UintBorderColor, options);
        }
        else
        {
            FieldToJson(jdata["FloatBorderColor"], data->decoded_value->FloatBorderColor, options);
        }
        FieldToJson(jdata["MinLOD"], data->decoded_value->MinLOD, options);
        FieldToJson(jdata["MaxLOD"], data->decoded_value->MaxLOD, options);
        FieldToJson_D3D12_SAMPLER_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstElement"], data->decoded_value->FirstElement, options);
        FieldToJson(jdata["NumElements"], data->decoded_value->NumElements, options);
        FieldToJson(jdata["StructureByteStride"], data->decoded_value->StructureByteStride, options);
        FieldToJson(jdata["CounterOffsetInBytes"], data->decoded_value->CounterOffsetInBytes, options);
        FieldToJson_D3D12_BUFFER_UAV_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["UnusedField_NothingToDefine"], data->decoded_value->UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstWSlice"], data->decoded_value->FirstWSlice, options);
        FieldToJson(jdata["WSize"], data->decoded_value->WSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ViewDimension"], data->decoded_value->ViewDimension, options);
        switch(data->decoded_value->ViewDimension)
        {
            case D3D12_UAV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero-valued ViewDimension is meaningless. Is struct corrupted?", options);
                break;
            }
            case D3D12_UAV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], data->Buffer, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], data->Texture1D, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], data->Texture1DArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], data->Texture2D, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], data->Texture2DArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], data->Texture2DMS, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], data->Texture2DMSArray, options);
                break;
            }
            case D3D12_UAV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], data->Texture3D, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "ViewDimension with unknown value. Is struct corrupted?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(data->decoded_value->ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstElement"], data->decoded_value->FirstElement, options);
        FieldToJson(jdata["NumElements"], data->decoded_value->NumElements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["UnusedField_NothingToDefine"], data->decoded_value->UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
        FieldToJson(jdata["PlaneSlice"], data->decoded_value->PlaneSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstWSlice"], data->decoded_value->FirstWSlice, options);
        FieldToJson(jdata["WSize"], data->decoded_value->WSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ViewDimension"], data->decoded_value->ViewDimension, options);
        switch(data->decoded_value->ViewDimension)
        {
            case D3D12_RTV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC.", options);
                break;
            }
            case D3D12_RTV_DIMENSION_BUFFER:
            {
                FieldToJson(jdata["Buffer"], data->Buffer, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], data->Texture1D, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], data->Texture1DArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], data->Texture2D, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], data->Texture2DArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], data->Texture2DMS, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], data->Texture2DMSArray, options);
                break;
            }
            case D3D12_RTV_DIMENSION_TEXTURE3D:
            {
                FieldToJson(jdata["Texture3D"], data->Texture3D, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Corrupt struct?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(data->decoded_value->ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MipSlice"], data->decoded_value->MipSlice, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["UnusedField_NothingToDefine"], data->decoded_value->UnusedField_NothingToDefine, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["ArraySize"], data->decoded_value->ArraySize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ViewDimension"], data->decoded_value->ViewDimension, options);
        FieldToJson_D3D12_DSV_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        switch(data->decoded_value->ViewDimension)
        {
            case D3D12_DSV_DIMENSION_UNKNOWN:
            {
                FieldToJson(jdata[format::kNameWarning], "Zero D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC.", options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1D:
            {
                FieldToJson(jdata["Texture1D"], data->Texture1D, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            {
                FieldToJson(jdata["Texture1DArray"], data->Texture1DArray, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2D:
            {
                FieldToJson(jdata["Texture2D"], data->Texture2D, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            {
                FieldToJson(jdata["Texture2DArray"], data->Texture2DArray, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            {
                FieldToJson(jdata["Texture2DMS"], data->Texture2DMS, options);
                break;
            }
            case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            {
                FieldToJson(jdata["Texture2DMSArray"], data->Texture2DMSArray, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC. Corrupt struct?", options);
                FieldToJson(jdata["Unknown value"], uint32_t(data->decoded_value->ViewDimension), options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["NumDescriptors"], data->decoded_value->NumDescriptors, options);
        FieldToJson_D3D12_DESCRIPTOR_HEAP_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RangeType"], data->decoded_value->RangeType, options);
        FieldToJson(jdata["NumDescriptors"], data->decoded_value->NumDescriptors, options);
        FieldToJson(jdata["BaseShaderRegister"], data->decoded_value->BaseShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], data->decoded_value->OffsetInDescriptorsFromTableStart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumDescriptorRanges"], data->decoded_value->NumDescriptorRanges, options);
        FieldToJson(jdata["pDescriptorRanges"], data->pDescriptorRanges, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ShaderRegister"], data->decoded_value->ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson(jdata["Num32BitValues"], data->decoded_value->Num32BitValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ShaderRegister"], data->decoded_value->ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ParameterType"], data->decoded_value->ParameterType, options);
        switch(data->decoded_value->ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], data->DescriptorTable, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], data->Constants, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], data->Descriptor, options);
                break;
            }
        }
        FieldToJson(jdata["ShaderVisibility"], data->decoded_value->ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Filter"], data->decoded_value->Filter, options);
        FieldToJson(jdata["AddressU"], data->decoded_value->AddressU, options);
        FieldToJson(jdata["AddressV"], data->decoded_value->AddressV, options);
        FieldToJson(jdata["AddressW"], data->decoded_value->AddressW, options);
        FieldToJson(jdata["MipLODBias"], data->decoded_value->MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], data->decoded_value->MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], data->decoded_value->ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], data->decoded_value->BorderColor, options);
        FieldToJson(jdata["MinLOD"], data->decoded_value->MinLOD, options);
        FieldToJson(jdata["MaxLOD"], data->decoded_value->MaxLOD, options);
        FieldToJson(jdata["ShaderRegister"], data->decoded_value->ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson(jdata["ShaderVisibility"], data->decoded_value->ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Filter"], data->decoded_value->Filter, options);
        FieldToJson(jdata["AddressU"], data->decoded_value->AddressU, options);
        FieldToJson(jdata["AddressV"], data->decoded_value->AddressV, options);
        FieldToJson(jdata["AddressW"], data->decoded_value->AddressW, options);
        FieldToJson(jdata["MipLODBias"], data->decoded_value->MipLODBias, options);
        FieldToJson(jdata["MaxAnisotropy"], data->decoded_value->MaxAnisotropy, options);
        FieldToJson(jdata["ComparisonFunc"], data->decoded_value->ComparisonFunc, options);
        FieldToJson(jdata["BorderColor"], data->decoded_value->BorderColor, options);
        FieldToJson(jdata["MinLOD"], data->decoded_value->MinLOD, options);
        FieldToJson(jdata["MaxLOD"], data->decoded_value->MaxLOD, options);
        FieldToJson(jdata["ShaderRegister"], data->decoded_value->ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson(jdata["ShaderVisibility"], data->decoded_value->ShaderVisibility, options);
        FieldToJson_D3D12_SAMPLER_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumParameters"], data->decoded_value->NumParameters, options);
        FieldToJson(jdata["pParameters"], data->pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], data->decoded_value->NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], data->pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RangeType"], data->decoded_value->RangeType, options);
        FieldToJson(jdata["NumDescriptors"], data->decoded_value->NumDescriptors, options);
        FieldToJson(jdata["BaseShaderRegister"], data->decoded_value->BaseShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson_D3D12_DESCRIPTOR_RANGE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["OffsetInDescriptorsFromTableStart"], data->decoded_value->OffsetInDescriptorsFromTableStart, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumDescriptorRanges"], data->decoded_value->NumDescriptorRanges, options);
        FieldToJson(jdata["pDescriptorRanges"], data->pDescriptorRanges, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ShaderRegister"], data->decoded_value->ShaderRegister, options);
        FieldToJson(jdata["RegisterSpace"], data->decoded_value->RegisterSpace, options);
        FieldToJson_D3D12_ROOT_DESCRIPTOR_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ParameterType"], data->decoded_value->ParameterType, options);
        switch (data->decoded_value->ParameterType)
        {
            case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            {
                FieldToJson(jdata["DescriptorTable"], data->DescriptorTable, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            {
                FieldToJson(jdata["Constants"], data->Constants, options);
                break;
            }
            case D3D12_ROOT_PARAMETER_TYPE_CBV:
            case D3D12_ROOT_PARAMETER_TYPE_SRV:
            case D3D12_ROOT_PARAMETER_TYPE_UAV:
            {
                FieldToJson(jdata["Descriptor"], data->Descriptor, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1.", options);
                FieldToJson(jdata["Unknown value"], uint32_t(data->decoded_value->ParameterType), options);
                break;
            }
        }
        FieldToJson(jdata["ShaderVisibility"], data->decoded_value->ShaderVisibility, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumParameters"], data->decoded_value->NumParameters, options);
        FieldToJson(jdata["pParameters"], data->pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], data->decoded_value->NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], data->pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumParameters"], data->decoded_value->NumParameters, options);
        FieldToJson(jdata["pParameters"], data->pParameters, options);
        FieldToJson(jdata["NumStaticSamplers"], data->decoded_value->NumStaticSamplers, options);
        FieldToJson(jdata["pStaticSamplers"], data->pStaticSamplers, options);
        FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Version"], data->decoded_value->Version, options);
        switch (data->decoded_value->Version)
        {
            case D3D_ROOT_SIGNATURE_VERSION_1_0:
            {
                FieldToJson(jdata["Desc_1_0"], data->Desc_1_0, options);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_1:
            {
                FieldToJson(jdata["Desc_1_1"], data->Desc_1_1, options);
                break;
            }
            case D3D_ROOT_SIGNATURE_VERSION_1_2:
            {
                FieldToJson(jdata["Desc_1_2"], data->Desc_1_2, options);
                GFXRECON_LOG_ERROR("Unknown D3D_ROOT_SIGNATURE_VERSION_1_2 in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ptr"], data->decoded_value->ptr, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumRects"], data->decoded_value->NumRects, options);
        FieldToJson(jdata["pRects"], data->pRects, options);
        FieldToJson(jdata["FirstSubresource"], data->decoded_value->FirstSubresource, options);
        FieldToJson(jdata["NumSubresources"], data->decoded_value->NumSubresources, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["Count"], data->decoded_value->Count, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IAVertices"], data->decoded_value->IAVertices, options);
        FieldToJson(jdata["IAPrimitives"], data->decoded_value->IAPrimitives, options);
        FieldToJson(jdata["VSInvocations"], data->decoded_value->VSInvocations, options);
        FieldToJson(jdata["GSInvocations"], data->decoded_value->GSInvocations, options);
        FieldToJson(jdata["GSPrimitives"], data->decoded_value->GSPrimitives, options);
        FieldToJson(jdata["CInvocations"], data->decoded_value->CInvocations, options);
        FieldToJson(jdata["CPrimitives"], data->decoded_value->CPrimitives, options);
        FieldToJson(jdata["PSInvocations"], data->decoded_value->PSInvocations, options);
        FieldToJson(jdata["HSInvocations"], data->decoded_value->HSInvocations, options);
        FieldToJson(jdata["DSInvocations"], data->decoded_value->DSInvocations, options);
        FieldToJson(jdata["CSInvocations"], data->decoded_value->CSInvocations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IAVertices"], data->decoded_value->IAVertices, options);
        FieldToJson(jdata["IAPrimitives"], data->decoded_value->IAPrimitives, options);
        FieldToJson(jdata["VSInvocations"], data->decoded_value->VSInvocations, options);
        FieldToJson(jdata["GSInvocations"], data->decoded_value->GSInvocations, options);
        FieldToJson(jdata["GSPrimitives"], data->decoded_value->GSPrimitives, options);
        FieldToJson(jdata["CInvocations"], data->decoded_value->CInvocations, options);
        FieldToJson(jdata["CPrimitives"], data->decoded_value->CPrimitives, options);
        FieldToJson(jdata["PSInvocations"], data->decoded_value->PSInvocations, options);
        FieldToJson(jdata["HSInvocations"], data->decoded_value->HSInvocations, options);
        FieldToJson(jdata["DSInvocations"], data->decoded_value->DSInvocations, options);
        FieldToJson(jdata["CSInvocations"], data->decoded_value->CSInvocations, options);
        FieldToJson(jdata["ASInvocations"], data->decoded_value->ASInvocations, options);
        FieldToJson(jdata["MSInvocations"], data->decoded_value->MSInvocations, options);
        FieldToJson(jdata["MSPrimitives"], data->decoded_value->MSPrimitives, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumPrimitivesWritten"], data->decoded_value->NumPrimitivesWritten, options);
        FieldToJson(jdata["PrimitivesStorageNeeded"], data->decoded_value->PrimitivesStorageNeeded, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["BufferLocation"], data->decoded_value->BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJsonAsHex(jdata["BufferFilledSizeLocation"], data->decoded_value->BufferFilledSizeLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["VertexCountPerInstance"], data->decoded_value->VertexCountPerInstance, options);
        FieldToJson(jdata["InstanceCount"], data->decoded_value->InstanceCount, options);
        FieldToJson(jdata["StartVertexLocation"], data->decoded_value->StartVertexLocation, options);
        FieldToJson(jdata["StartInstanceLocation"], data->decoded_value->StartInstanceLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IndexCountPerInstance"], data->decoded_value->IndexCountPerInstance, options);
        FieldToJson(jdata["InstanceCount"], data->decoded_value->InstanceCount, options);
        FieldToJson(jdata["StartIndexLocation"], data->decoded_value->StartIndexLocation, options);
        FieldToJson(jdata["BaseVertexLocation"], data->decoded_value->BaseVertexLocation, options);
        FieldToJson(jdata["StartInstanceLocation"], data->decoded_value->StartInstanceLocation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ThreadGroupCountX"], data->decoded_value->ThreadGroupCountX, options);
        FieldToJson(jdata["ThreadGroupCountY"], data->decoded_value->ThreadGroupCountY, options);
        FieldToJson(jdata["ThreadGroupCountZ"], data->decoded_value->ThreadGroupCountZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["BufferLocation"], data->decoded_value->BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJson(jdata["StrideInBytes"], data->decoded_value->StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["BufferLocation"], data->decoded_value->BufferLocation, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        switch (data->decoded_value->Type)
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
                FieldToJson(vb["Slot"], data->decoded_value->VertexBuffer.Slot, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
            {
                // No parameters to output.
                FieldToJson(jdata["comment"], "There must be a D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED in the same sequence.", options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
            {
                auto& c = jdata["Constant"];
                FieldToJson(c["RootParameterIndex"], data->decoded_value->Constant.RootParameterIndex, options);
                FieldToJson(c["DestOffsetIn32BitValues"], data->decoded_value->Constant.DestOffsetIn32BitValues, options);
                FieldToJson(c["Num32BitValuesToSet"], data->decoded_value->Constant.Num32BitValuesToSet, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
            {
                auto& cbv = jdata["ConstantBufferView"];
                FieldToJson(cbv["RootParameterIndex"], data->decoded_value->ConstantBufferView.RootParameterIndex, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
            {
                auto& srv = jdata["ShaderResourceView"];
                FieldToJson(srv["RootParameterIndex"], data->decoded_value->ShaderResourceView.RootParameterIndex, options);
                break;
            }
            case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
            {
                auto& uav = jdata["UnorderedAccessView"];
                FieldToJson(uav["RootParameterIndex"], data->decoded_value->UnorderedAccessView.RootParameterIndex, options);
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
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ByteStride"], data->decoded_value->ByteStride, options);
        FieldToJson(jdata["NumArgumentDescs"], data->decoded_value->NumArgumentDescs, options);
        FieldToJson(jdata["pArgumentDescs"], data->pArgumentDescs, options);
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["Dest"], data->decoded_value->Dest, options);
        FieldToJson(jdata["Value"], data->decoded_value->Value, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(jdata["Support"], data->decoded_value->Support, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Name"], data->Name, options);
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson_D3D12_META_COMMAND_PARAMETER_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson_D3D12_RESOURCE_STATES(jdata["RequiredResourceState"], data->decoded_value->RequiredResourceState, options);
        FieldToJson(jdata["StructureOffset"], data->decoded_value->StructureOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Id"], data->Id, options);
        FieldToJson(jdata["Name"], data->Name, options);
        FieldToJson_D3D12_GRAPHICS_STATES(jdata["InitializationDirtyState"], data->decoded_value->InitializationDirtyState, options);
        FieldToJson_D3D12_GRAPHICS_STATES(jdata["ExecutionDirtyState"], data->decoded_value->ExecutionDirtyState, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["OpaqueData"], data->OpaqueData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Name"], data->Name, options);
        FieldToJson(jdata["ArrayIndex"], data->decoded_value->ArrayIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MinSizeInBytes"], data->decoded_value->MinSizeInBytes, options);
        FieldToJson(jdata["MaxSizeInBytes"], data->decoded_value->MaxSizeInBytes, options);
        FieldToJson(jdata["SizeGranularityInBytes"], data->decoded_value->SizeGranularityInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson_D3D12_STATE_OBJECT_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pGlobalRootSignature"], data->pGlobalRootSignature, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLocalRootSignature"], data->pLocalRootSignature, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsFixedWidthBinary(jdata["SampleMask"], data->decoded_value->SampleMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IndexBufferStripCutValue"], data->decoded_value->IndexBufferStripCutValue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["PrimitiveTopology"], data->decoded_value->PrimitiveTopology, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DepthStencilFormat"], data->decoded_value->DepthStencilFormat, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Name"], data->Name, options);
        FieldToJson(jdata["ExportToRename"], data->ExportToRename, options);
        FieldToJson_D3D12_EXPORT_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DXILLibrary"], data->DXILLibrary, options);
        FieldToJson(jdata["NumExports"], data->decoded_value->NumExports, options);
        FieldToJson(jdata["pExports"], data->pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pExistingCollection"], data->pExistingCollection, options);
        FieldToJson(jdata["NumExports"], data->decoded_value->NumExports, options);
        FieldToJson(jdata["pExports"], data->pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pSubobjectToAssociate"], data->pSubobjectToAssociate, options);
        FieldToJson(jdata["NumExports"], data->decoded_value->NumExports, options);
        FieldToJson(jdata["pExports"], data->pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SubobjectToAssociate"], data->SubobjectToAssociate, options);
        FieldToJson(jdata["NumExports"], data->decoded_value->NumExports, options);
        FieldToJson(jdata["pExports"], data->pExports, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["HitGroupExport"], data->HitGroupExport, options);
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["AnyHitShaderImport"], data->AnyHitShaderImport, options);
        FieldToJson(jdata["ClosestHitShaderImport"], data->ClosestHitShaderImport, options);
        FieldToJson(jdata["IntersectionShaderImport"], data->IntersectionShaderImport, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MaxPayloadSizeInBytes"], data->decoded_value->MaxPayloadSizeInBytes, options);
        FieldToJson(jdata["MaxAttributeSizeInBytes"], data->decoded_value->MaxAttributeSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MaxTraceRecursionDepth"], data->decoded_value->MaxTraceRecursionDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MaxTraceRecursionDepth"], data->decoded_value->MaxTraceRecursionDepth, options);
        FieldToJson_D3D12_RAYTRACING_PIPELINE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["OutputIndex"], data->decoded_value->OutputIndex, options);
        FieldToJson(jdata["pNewName"], data->pNewName, options);
        Bool32ToJson(jdata["pAllowSparseNodes"], data->pAllowSparseNodes, options);
        FieldToJson(jdata["pMaxRecords"], data->pMaxRecords, options);
        FieldToJson(jdata["pMaxRecordsSharedWithOutputIndex"], data->pMaxRecordsSharedWithOutputIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], data->pLocalRootArgumentsTableIndex, options);
        Bool32ToJson(jdata["pProgramEntry"], data->pProgramEntry, options);
        FieldToJson(jdata["pNewName"], data->pNewName, options);
        FieldToJson(jdata["pShareInputOf"], data->pShareInputOf, options);
        FieldToJson(jdata["pDispatchGrid"], data->pDispatchGrid, options);
        FieldToJson(jdata["pMaxDispatchGrid"], data->pMaxDispatchGrid, options);
        FieldToJson(jdata["NumOutputOverrides"], data->decoded_value->NumOutputOverrides, options);
        FieldToJson(jdata["pOutputOverrides"], data->pOutputOverrides, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], data->pLocalRootArgumentsTableIndex, options);
        Bool32ToJson(jdata["pProgramEntry"], data->pProgramEntry, options);
        FieldToJson(jdata["pNewName"], data->pNewName, options);
        FieldToJson(jdata["pShareInputOf"], data->pShareInputOf, options);
        FieldToJson(jdata["NumOutputOverrides"], data->decoded_value->NumOutputOverrides, options);
        FieldToJson(jdata["pOutputOverrides"], data->pOutputOverrides, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], data->pLocalRootArgumentsTableIndex, options);
        Bool32ToJson(jdata["pProgramEntry"], data->pProgramEntry, options);
        FieldToJson(jdata["pNewName"], data->pNewName, options);
        FieldToJson(jdata["pShareInputOf"], data->pShareInputOf, options);
        FieldToJson(jdata["NumOutputOverrides"], data->decoded_value->NumOutputOverrides, options);
        FieldToJson(jdata["pOutputOverrides"], data->pOutputOverrides, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLocalRootArgumentsTableIndex"], data->pLocalRootArgumentsTableIndex, options);
        Bool32ToJson(jdata["pProgramEntry"], data->pProgramEntry, options);
        FieldToJson(jdata["pNewName"], data->pNewName, options);
        FieldToJson(jdata["pShareInputOf"], data->pShareInputOf, options);
        FieldToJson(jdata["NumOutputOverrides"], data->decoded_value->NumOutputOverrides, options);
        FieldToJson(jdata["pOutputOverrides"], data->pOutputOverrides, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Shader"], data->Shader, options);
        FieldToJson(jdata["OverridesType"], data->decoded_value->OverridesType, options);
        switch(data->decoded_value->OverridesType)
        {
            case D3D12_NODE_OVERRIDES_TYPE_BROADCASTING_LAUNCH:
            {
                FieldToJson(jdata["pBroadcastingLaunchOverrides"], data->broadcasting_launch_overrides, options);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_COALESCING_LAUNCH:
            {
                FieldToJson(jdata["pCoalescingLaunchOverrides"], data->coalescing_launch_overrides, options);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_THREAD_LAUNCH:
            {
                FieldToJson(jdata["pThreadLaunchOverrides"], data->thread_launch_overrides, options);
                break;
            }
            case D3D12_NODE_OVERRIDES_TYPE_COMMON_COMPUTE:
            {
                FieldToJson(jdata["pCommonComputeNodeOverrides"], data->common_compute_node_overrides, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_NODE_OVERRIDES_TYPE in D3D12_SHADER_NODE.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeType"], data->decoded_value->NodeType, options);
        switch(data->decoded_value->NodeType)
        {
            case D3D12_NODE_TYPE_SHADER:
            {
                FieldToJson(jdata["Shader"], data->shader, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_NODE_TYPE in D3D12_NODE.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ProgramName"], data->ProgramName, options);
        FieldToJson_D3D12_WORK_GRAPH_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["NumEntrypoints"], data->decoded_value->NumEntrypoints, options);
        FieldToJson(jdata["pEntrypoints"], data->pEntrypoints, options);
        FieldToJson(jdata["NumExplicitlyDefinedNodes"], data->decoded_value->NumExplicitlyDefinedNodes, options);
        FieldToJson(jdata["pExplicitlyDefinedNodes"], data->pExplicitlyDefinedNodes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ProgramName"], data->ProgramName, options);
        FieldToJson(jdata["NumExports"], data->decoded_value->NumExports, options);
        FieldToJson(jdata["pExports"], data->pExports, options);
        FieldToJson(jdata["NumSubobjects"], data->decoded_value->NumSubobjects, options);
        FieldToJson(jdata["ppSubobjects"], data->ppSubobjects, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["NumSubobjects"], data->decoded_value->NumSubobjects, options);
        FieldToJson(jdata["pSubobjects"], data->pSubobjects, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["StartAddress"], data->decoded_value->StartAddress, options);
        FieldToJson(jdata["StrideInBytes"], data->decoded_value->StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["StartAddress"], data->decoded_value->StartAddress, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["StartAddress"], data->decoded_value->StartAddress, options);
        FieldToJson(jdata["SizeInBytes"], data->decoded_value->SizeInBytes, options);
        FieldToJson(jdata["StrideInBytes"], data->decoded_value->StrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["Transform3x4"], data->decoded_value->Transform3x4, options);
        FieldToJson(jdata["IndexFormat"], data->decoded_value->IndexFormat, options);
        FieldToJson(jdata["VertexFormat"], data->decoded_value->VertexFormat, options);
        FieldToJson(jdata["IndexCount"], data->decoded_value->IndexCount, options);
        FieldToJson(jdata["VertexCount"], data->decoded_value->VertexCount, options);
        FieldToJsonAsHex(jdata["IndexBuffer"], data->decoded_value->IndexBuffer, options);
        FieldToJson(jdata["VertexBuffer"], data->VertexBuffer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MinX"], data->decoded_value->MinX, options);
        FieldToJson(jdata["MinY"], data->decoded_value->MinY, options);
        FieldToJson(jdata["MinZ"], data->decoded_value->MinZ, options);
        FieldToJson(jdata["MaxX"], data->decoded_value->MaxX, options);
        FieldToJson(jdata["MaxY"], data->decoded_value->MaxY, options);
        FieldToJson(jdata["MaxZ"], data->decoded_value->MaxZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["AABBCount"], data->decoded_value->AABBCount, options);
        FieldToJson(jdata["AABBs"], data->AABBs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ByteOffset"], data->decoded_value->ByteOffset, options);
        FieldToJson(jdata["SubdivisionLevel"], data->decoded_value->SubdivisionLevel, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["OpacityMicromapIndexBuffer"], data->OpacityMicromapIndexBuffer, options);
        FieldToJson(jdata["OpacityMicromapIndexFormat"], data->decoded_value->OpacityMicromapIndexFormat, options);
        FieldToJson(jdata["OpacityMicromapBaseLocation"], data->decoded_value->OpacityMicromapBaseLocation, options);
        FieldToJsonAsHex(jdata["OpacityMicromapArray"], data->decoded_value->OpacityMicromapArray, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pTriangles"], data->pTriangles, options);
        FieldToJson(jdata["pOmmLinkage"], data->pOmmLinkage, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["DestBuffer"], data->decoded_value->DestBuffer, options);
        FieldToJson(jdata["InfoType"], data->decoded_value->InfoType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CompactedSizeInBytes"], data->decoded_value->CompactedSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DecodedSizeInBytes"], data->decoded_value->DecodedSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["NumDescs"], data->decoded_value->NumDescs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SerializedSizeInBytes"], data->decoded_value->SerializedSizeInBytes, options);
        ; ///< @todo ALERT: Union member 0 of D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC needs special handling.
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DriverOpaqueGUID"], data->DriverOpaqueGUID, options);
        FieldToJson(jdata["DriverOpaqueVersioningData"], data->DriverOpaqueVersioningData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DriverMatchingIdentifier"], data->DriverMatchingIdentifier, options);
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], data->decoded_value->SerializedSizeInBytesIncludingHeader, options);
        FieldToJson(jdata["DeserializedSizeInBytes"], data->decoded_value->DeserializedSizeInBytes, options);
        FieldToJson(jdata["NumBottomLevelAccelerationStructurePointersAfterHeader"], data->decoded_value->NumBottomLevelAccelerationStructurePointersAfterHeader, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DriverMatchingIdentifier"], data->DriverMatchingIdentifier, options);
        FieldToJson(jdata["SerializedSizeInBytesIncludingHeader"], data->decoded_value->SerializedSizeInBytesIncludingHeader, options);
        FieldToJson(jdata["DeserializedSizeInBytes"], data->decoded_value->DeserializedSizeInBytes, options);
        ; ///< @todo ALERT: Union member 0 of D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1 needs special handling.
        FieldToJson(jdata["HeaderPostambleType"], data->decoded_value->HeaderPostambleType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SERIALIZED_BLOCK* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["NumBlockPointersAfterHeader"], data->decoded_value->NumBlockPointersAfterHeader, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CurrentSizeInBytes"], data->decoded_value->CurrentSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Transform"], data->Transform, options);
        FieldToJson(jdata["InstanceID"], data->decoded_value->InstanceID, options);
        FieldToJsonAsFixedWidthBinary(jdata["InstanceMask"], data->decoded_value->InstanceMask, options);
        FieldToJson(jdata["InstanceContributionToHitGroupIndex"], data->decoded_value->InstanceContributionToHitGroupIndex, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJsonAsHex(jdata["AccelerationStructure"], data->decoded_value->AccelerationStructure, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson_D3D12_RAYTRACING_GEOMETRY_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            {
                FieldToJson(jdata["Triangles"], data->Triangles, options);
                break;
            }
            case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            {
                FieldToJson(jdata["AABBs"], data->AABBs, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_GEOMETRY_TYPE in D3D12_RAYTRACING_GEOMETRY_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Count"], data->decoded_value->Count, options);
        FieldToJson(jdata["SubdivisionLevel"], data->decoded_value->SubdivisionLevel, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumOmmHistogramEntries"], data->decoded_value->NumOmmHistogramEntries, options);
        FieldToJson(jdata["pOmmHistogram"], data->pOmmHistogram, options);
        FieldToJsonAsHex(jdata["InputBuffer"], data->decoded_value->InputBuffer, options);
        FieldToJson(jdata["PerOmmDescs"], data->PerOmmDescs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["NumDescs"], data->decoded_value->NumDescs, options);
        FieldToJson(jdata["DescsLayout"], data->decoded_value->DescsLayout, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            {
                FieldToJsonAsHex(jdata["InstanceDescs"], data->decoded_value->InstanceDescs, options);
                break;
            }
            case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            {
                switch(data->decoded_value->DescsLayout)
                {
                    case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    {
                        FieldToJson(jdata["pGeometryDescs"], data->pGeometryDescs, options);
                        break;
                    }
                    case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    {
                        FieldToJson(jdata["ppGeometryDescs"], data->ppGeometryDescs, options);
                        break;
                    }
                }
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE in D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["DestAccelerationStructureData"], data->decoded_value->DestAccelerationStructureData, options);
        FieldToJson(jdata["Inputs"], data->Inputs, options);
        FieldToJsonAsHex(jdata["SourceAccelerationStructureData"], data->decoded_value->SourceAccelerationStructureData, options);
        FieldToJsonAsHex(jdata["ScratchAccelerationStructureData"], data->decoded_value->ScratchAccelerationStructureData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ResultDataMaxSizeInBytes"], data->decoded_value->ResultDataMaxSizeInBytes, options);
        FieldToJson(jdata["ScratchDataSizeInBytes"], data->decoded_value->ScratchDataSizeInBytes, options);
        FieldToJson(jdata["UpdateScratchDataSizeInBytes"], data->decoded_value->UpdateScratchDataSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["DestBuffer"], data->decoded_value->DestBuffer, options);
        FieldToJson(jdata["InfoType"], data->decoded_value->InfoType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CurrentSizeInBytes"], data->decoded_value->CurrentSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DecodedSizeInBytes"], data->decoded_value->DecodedSizeInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pCommandListDebugNameA"], data->pCommandListDebugNameA, options);
        FieldToJson(jdata["pCommandListDebugNameW"], data->pCommandListDebugNameW, options);
        FieldToJson(jdata["pCommandQueueDebugNameA"], data->pCommandQueueDebugNameA, options);
        FieldToJson(jdata["pCommandQueueDebugNameW"], data->pCommandQueueDebugNameW, options);
        FieldToJson(jdata["pCommandList"], data->pCommandList, options);
        FieldToJson(jdata["pCommandQueue"], data->pCommandQueue, options);
        FieldToJson(jdata["BreadcrumbCount"], data->decoded_value->BreadcrumbCount, options);
        FieldToJson(jdata["pLastBreadcrumbValue"], data->pLastBreadcrumbValue, options);
        FieldToJson(jdata["pCommandHistory"], data->pCommandHistory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["BreadcrumbIndex"], data->decoded_value->BreadcrumbIndex, options);
        FieldToJson(jdata["pContextString"], data->pContextString, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pCommandListDebugNameA"], data->pCommandListDebugNameA, options);
        FieldToJson(jdata["pCommandListDebugNameW"], data->pCommandListDebugNameW, options);
        FieldToJson(jdata["pCommandQueueDebugNameA"], data->pCommandQueueDebugNameA, options);
        FieldToJson(jdata["pCommandQueueDebugNameW"], data->pCommandQueueDebugNameW, options);
        FieldToJson(jdata["pCommandList"], data->pCommandList, options);
        FieldToJson(jdata["pCommandQueue"], data->pCommandQueue, options);
        FieldToJson(jdata["BreadcrumbCount"], data->decoded_value->BreadcrumbCount, options);
        FieldToJson(jdata["pLastBreadcrumbValue"], data->pLastBreadcrumbValue, options);
        FieldToJson(jdata["pCommandHistory"], data->pCommandHistory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
        FieldToJson(jdata["BreadcrumbContextsCount"], data->decoded_value->BreadcrumbContextsCount, options);
        FieldToJson(jdata["pBreadcrumbContexts"], data->pBreadcrumbContexts, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson_D3D12_DRED_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], data->pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ObjectNameA"], data->ObjectNameA, options);
        FieldToJson(jdata["ObjectNameW"], data->ObjectNameW, options);
        FieldToJson(jdata["AllocationType"], data->decoded_value->AllocationType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ObjectNameA"], data->ObjectNameA, options);
        FieldToJson(jdata["ObjectNameW"], data->ObjectNameW, options);
        FieldToJson(jdata["AllocationType"], data->decoded_value->AllocationType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
        FieldToJson(jdata["pObject"], data->pObject, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], data->pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pHeadAutoBreadcrumbNode"], data->pHeadAutoBreadcrumbNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["PageFaultVA"], data->decoded_value->PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], data->pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], data->pHeadRecentFreedAllocationNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["PageFaultVA"], data->decoded_value->PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], data->pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], data->pHeadRecentFreedAllocationNode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsHex(jdata["PageFaultVA"], data->decoded_value->PageFaultVA, options);
        FieldToJson(jdata["pHeadExistingAllocationNode"], data->pHeadExistingAllocationNode, options);
        FieldToJson(jdata["pHeadRecentFreedAllocationNode"], data->pHeadRecentFreedAllocationNode, options);
        FieldToJson_D3D12_DRED_PAGE_FAULT_FLAGS(jdata["PageFaultFlags"], data->decoded_value->PageFaultFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        HresultToJson(jdata["DeviceRemovedReason"], data->decoded_value->DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], data->AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], data->PageFaultOutput, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        HresultToJson(jdata["DeviceRemovedReason"], data->decoded_value->DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], data->AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], data->PageFaultOutput, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        HresultToJson(jdata["DeviceRemovedReason"], data->decoded_value->DeviceRemovedReason, options);
        FieldToJson(jdata["AutoBreadcrumbsOutput"], data->AutoBreadcrumbsOutput, options);
        FieldToJson(jdata["PageFaultOutput"], data->PageFaultOutput, options);
        FieldToJson(jdata["DeviceState"], data->decoded_value->DeviceState, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Version"], data->decoded_value->Version, options);
        switch(data->decoded_value->Version)
        {
            case D3D12_DRED_VERSION_1_0:
            {
                FieldToJson(jdata["Dred_1_0"], data->Dred_1_0, options);
                break;
            }
            case D3D12_DRED_VERSION_1_1:
            {
                FieldToJson(jdata["Dred_1_1"], data->Dred_1_1, options);
                break;
            }
            case D3D12_DRED_VERSION_1_2:
            {
                FieldToJson(jdata["Dred_1_2"], data->Dred_1_2, options);
                break;
            }
            case D3D12_DRED_VERSION_1_3:
            {
                FieldToJson(jdata["Dred_1_3"], data->Dred_1_3, options);
                FieldToJson(jdata[format::kNameWarning], "Dred_1_3 is not supported by GFXR at this time. Please file an issue quoting this text if this is a blocker for you.", options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DRED_VERSION in D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        FieldToJson(jdata["Count"], data->decoded_value->Count, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NodeIndex"], data->decoded_value->NodeIndex, options);
        FieldToJson(jdata["Count"], data->decoded_value->Count, options);
        FieldToJson(jdata["pTypes"], data->pTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJsonAsFixedWidthBinary(jdata["NodeMask"], data->decoded_value->NodeMask, options);
        FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["ProtectionType"], data->ProtectionType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ClearValue"], data->ClearValue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["AdditionalWidth"], data->decoded_value->AdditionalWidth, options);
        FieldToJson(jdata["AdditionalHeight"], data->decoded_value->AdditionalHeight, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR:
            {
                FieldToJson(jdata["Clear"], data->Clear, options);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            if(data->decoded_value->PreserveLocal.AdditionalWidth != 0U || data->decoded_value->PreserveLocal.AdditionalHeight != 0U)
            {
                FieldToJson(jdata[format::kNameWarning], "Additional width and height should be zero (see DirectX Specs).", options);
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], data->decoded_value->PreserveLocal, options);
                break;
            }
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE in D3D12_RENDER_PASS_BEGINNING_ACCESS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SrcSubresource"], data->decoded_value->SrcSubresource, options);
        FieldToJson(jdata["DstSubresource"], data->decoded_value->DstSubresource, options);
        FieldToJson(jdata["DstX"], data->decoded_value->DstX, options);
        FieldToJson(jdata["DstY"], data->decoded_value->DstY, options);
        FieldToJson(jdata["SrcRect"], data->SrcRect, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pSrcResource"], data->pSrcResource, options);
        FieldToJson(jdata["pDstResource"], data->pDstResource, options);
        FieldToJson(jdata["SubresourceCount"], data->decoded_value->SubresourceCount, options);
        FieldToJson(jdata["pSubresourceParameters"], data->pSubresourceParameters, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ResolveMode"], data->decoded_value->ResolveMode, options);
        Bool32ToJson(jdata["PreserveResolveSource"], data->decoded_value->PreserveResolveSource, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["AdditionalWidth"], data->decoded_value->AdditionalWidth, options);
        FieldToJson(jdata["AdditionalHeight"], data->decoded_value->AdditionalHeight, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS:
            // No parameters to these cases.
            break;

            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
            {
                FieldToJson(jdata["Resolve"], data->Resolve, options);
                break;
            }
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
            case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
            {
                FieldToJson(jdata["PreserveLocal"], data->decoded_value->PreserveLocal, options);
                break;
            }

            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_ENDING_ACCESS_TYPE in D3D12_RENDER_PASS_ENDING_ACCESS.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["cpuDescriptor"], data->cpuDescriptor, options);
        FieldToJson(jdata["BeginningAccess"], data->BeginningAccess, options);
        FieldToJson(jdata["EndingAccess"], data->EndingAccess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["cpuDescriptor"], data->cpuDescriptor, options);
        FieldToJson(jdata["DepthBeginningAccess"], data->DepthBeginningAccess, options);
        FieldToJson(jdata["StencilBeginningAccess"], data->StencilBeginningAccess, options);
        FieldToJson(jdata["DepthEndingAccess"], data->DepthEndingAccess, options);
        FieldToJson(jdata["StencilEndingAccess"], data->StencilEndingAccess, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RayGenerationShaderRecord"], data->RayGenerationShaderRecord, options);
        FieldToJson(jdata["MissShaderTable"], data->MissShaderTable, options);
        FieldToJson(jdata["HitGroupTable"], data->HitGroupTable, options);
        FieldToJson(jdata["CallableShaderTable"], data->CallableShaderTable, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Depth"], data->decoded_value->Depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ProgramIdentifier"], data->ProgramIdentifier, options);
        FieldToJson_D3D12_SET_WORK_GRAPH_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["BackingMemory"], data->BackingMemory, options);
        FieldToJson(jdata["NodeLocalRootArgumentsTable"], data->NodeLocalRootArgumentsTable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ProgramIdentifier"], data->ProgramIdentifier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ProgramIdentifier"], data->ProgramIdentifier, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_PROGRAM_TYPE_GENERIC_PIPELINE:
            {
                FieldToJson(jdata["GenericPipeline"], data->generic_pipeline, options);
                break;
            }
            case D3D12_PROGRAM_TYPE_RAYTRACING_PIPELINE:
            {
                FieldToJson(jdata["RaytracingPipeline"], data->raytracing_pipeline, options);
                break;
            }
            case D3D12_PROGRAM_TYPE_WORK_GRAPH:
            {
                FieldToJson(jdata["WorkGraph"], data->work_graph, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_PROGRAM_TYPE in D3D12_SET_PROGRAM_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["EntrypointIndex"], data->decoded_value->EntrypointIndex, options);
        FieldToJson(jdata["NumRecords"], data->decoded_value->NumRecords, options);
        FieldToJson(jdata["pRecords"], data->pRecords, options);
        FieldToJson(jdata["RecordStrideInBytes"], data->decoded_value->RecordStrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["EntrypointIndex"], data->decoded_value->EntrypointIndex, options);
        FieldToJson(jdata["NumRecords"], data->decoded_value->NumRecords, options);
        FieldToJson(jdata["Records"], data->Records, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumNodeInputs"], data->decoded_value->NumNodeInputs, options);
        FieldToJson(jdata["pNodeInputs"], data->pNodeInputs, options);
        FieldToJson(jdata["NodeInputStrideInBytes"], data->decoded_value->NodeInputStrideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumNodeInputs"], data->decoded_value->NumNodeInputs, options);
        FieldToJson(jdata["NodeInputs"], data->NodeInputs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Mode"], data->decoded_value->Mode, options);
        switch(data->decoded_value->Mode)
        {
            case D3D12_DISPATCH_MODE_NODE_CPU_INPUT:
            {
                FieldToJson(jdata["NodeCPUInput"], data->node_cpu_input, options);
                break;
            }
            case D3D12_DISPATCH_MODE_NODE_GPU_INPUT:
            {
                FieldToJson(jdata["NodeGPUInput"], data->decoded_value->NodeGPUInput, options);
                break;
            }
            case D3D12_DISPATCH_MODE_MULTI_NODE_CPU_INPUT:
            {
                FieldToJson(jdata["MultiNodeCPUInput"], data->multi_node_cpu_input, options);
                break;
            }
            case D3D12_DISPATCH_MODE_MULTI_NODE_GPU_INPUT:
            {
                FieldToJson(jdata["MultiNodeGPUInput"], data->decoded_value->MultiNodeGPUInput, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DISPATCH_MODE in D3D12_DISPATCH_GRAPH_DESC.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Identifier"], data->Identifier, options);
        FieldToJson(jdata["Mode"], data->decoded_value->Mode, options);
        FieldToJson_D3D12_SHADER_CACHE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["MaximumInMemoryCacheSizeBytes"], data->decoded_value->MaximumInMemoryCacheSizeBytes, options);
        FieldToJson(jdata["MaximumInMemoryCacheEntries"], data->decoded_value->MaximumInMemoryCacheEntries, options);
        FieldToJson(jdata["MaximumValueFileSizeBytes"], data->decoded_value->MaximumValueFileSizeBytes, options);
        FieldToJson(jdata["Version"], data->decoded_value->Version, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IndexOrFirstMipLevel"], data->decoded_value->IndexOrFirstMipLevel, options);
        FieldToJson(jdata["NumMipLevels"], data->decoded_value->NumMipLevels, options);
        FieldToJson(jdata["FirstArraySlice"], data->decoded_value->FirstArraySlice, options);
        FieldToJson(jdata["NumArraySlices"], data->decoded_value->NumArraySlices, options);
        FieldToJson(jdata["FirstPlane"], data->decoded_value->FirstPlane, options);
        FieldToJson(jdata["NumPlanes"], data->decoded_value->NumPlanes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SyncBefore"], data->decoded_value->SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], data->decoded_value->SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], data->decoded_value->AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], data->decoded_value->AccessAfter, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SyncBefore"], data->decoded_value->SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], data->decoded_value->SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], data->decoded_value->AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], data->decoded_value->AccessAfter, options);
        FieldToJson(jdata["LayoutBefore"], data->decoded_value->LayoutBefore, options);
        FieldToJson(jdata["LayoutAfter"], data->decoded_value->LayoutAfter, options);
        FieldToJson(jdata["pResource"], data->pResource, options);
        FieldToJson(jdata["Subresources"], data->Subresources, options);
        FieldToJson_D3D12_TEXTURE_BARRIER_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SyncBefore"], data->decoded_value->SyncBefore, options);
        FieldToJson(jdata["SyncAfter"], data->decoded_value->SyncAfter, options);
        FieldToJson(jdata["AccessBefore"], data->decoded_value->AccessBefore, options);
        FieldToJson(jdata["AccessAfter"], data->decoded_value->AccessAfter, options);
        FieldToJson(jdata["pResource"], data->pResource, options);
        FieldToJson(jdata["Offset"], data->decoded_value->Offset, options);
        FieldToJson(jdata["Size"], data->decoded_value->Size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["NumBarriers"], data->decoded_value->NumBarriers, options);
        switch(data->decoded_value->Type)
        {
            case D3D12_BARRIER_TYPE_GLOBAL:
            {
                FieldToJson(jdata["pGlobalBarriers"], data->global_barriers, options);
                break;
            }
            case D3D12_BARRIER_TYPE_TEXTURE:
            {
                FieldToJson(jdata["pTextureBarriers"], data->texture_barriers, options);
                break;
            }
            case D3D12_BARRIER_TYPE_BUFFER:
            {
                FieldToJson(jdata["pBufferBarriers"], data->buffer_barriers, options);
                break;
            }
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_BARRIER_TYPE in D3D12_BARRIER_GROUP.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pData"], data->pData, options);
        FieldToJson(jdata["RowPitch"], data->decoded_value->RowPitch, options);
        FieldToJson(jdata["SlicePitch"], data->decoded_value->SlicePitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pData"], data->pData, options);
        FieldToJson(jdata["RowPitch"], data->decoded_value->RowPitch, options);
        FieldToJson(jdata["SlicePitch"], data->decoded_value->SlicePitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson_D3D12_DEVICE_FLAGS(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["GpuBasedValidationFlags"], data->decoded_value->GpuBasedValidationFlags, options);
        FieldToJson(jdata["SDKVersion"], data->decoded_value->SDKVersion, options);
        FieldToJson(jdata["NumEnabledExperimentalFeatures"], data->decoded_value->NumEnabledExperimentalFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ThreadGroupCountX"], data->decoded_value->ThreadGroupCountX, options);
        FieldToJson(jdata["ThreadGroupCountY"], data->decoded_value->ThreadGroupCountY, options);
        FieldToJson(jdata["ThreadGroupCountZ"], data->decoded_value->ThreadGroupCountZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Name"], data->Name, options);
        FieldToJson(jdata["Definition"], data->Definition, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["MaxMessagesPerCommandList"], data->decoded_value->MaxMessagesPerCommandList, options);
        FieldToJson(jdata["DefaultShaderPatchMode"], data->decoded_value->DefaultShaderPatchMode, options);
        FieldToJson_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(jdata["PipelineStateCreateFlags"], data->decoded_value->PipelineStateCreateFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SlowdownFactor"], data->decoded_value->SlowdownFactor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ShaderPatchMode"], data->decoded_value->ShaderPatchMode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Category"], data->decoded_value->Category, options);
        FieldToJson(jdata["Severity"], data->decoded_value->Severity, options);
        FieldToJson(jdata["ID"], data->decoded_value->ID, options);
        FieldToJson(jdata["pDescription"], data->pDescription, options);
        FieldToJson(jdata["DescriptionByteLength"], data->decoded_value->DescriptionByteLength, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["NumCategories"], data->decoded_value->NumCategories, options);
        FieldToJson(jdata["pCategoryList"], data->pCategoryList, options);
        FieldToJson(jdata["NumSeverities"], data->decoded_value->NumSeverities, options);
        FieldToJson(jdata["pSeverityList"], data->pSeverityList, options);
        FieldToJson(jdata["NumIDs"], data->decoded_value->NumIDs, options);
        FieldToJson(jdata["pIDList"], data->pIDList, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["AllowList"], data->AllowList, options);
        FieldToJson(jdata["DenyList"], data->DenyList, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["PresentCount"], data->decoded_value->PresentCount, options);
        FieldToJson(jdata["PresentRefreshCount"], data->decoded_value->PresentRefreshCount, options);
        FieldToJson(jdata["SyncRefreshCount"], data->decoded_value->SyncRefreshCount, options);
        FieldToJson(jdata["SyncQPCTime"], data->SyncQPCTime, options);
        FieldToJson(jdata["SyncGPUTime"], data->SyncGPUTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Pitch"], data->decoded_value->Pitch, options);
        FieldToJson(jdata["pBits"], data->pBits, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Description"], data->Description, options);
        FieldToJson(jdata["VendorId"], data->decoded_value->VendorId, options);
        FieldToJson(jdata["DeviceId"], data->decoded_value->DeviceId, options);
        FieldToJson(jdata["SubSysId"], data->decoded_value->SubSysId, options);
        FieldToJson(jdata["Revision"], data->decoded_value->Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], data->decoded_value->DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], data->decoded_value->DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], data->decoded_value->SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], data->AdapterLuid, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DeviceName"], data->DeviceName, options);
        FieldToJson(jdata["DesktopCoordinates"], data->DesktopCoordinates, options);
        Bool32ToJson(jdata["AttachedToDesktop"], data->decoded_value->AttachedToDesktop, options);
        FieldToJson(jdata["Rotation"], data->decoded_value->Rotation, options);
        FieldToJson(jdata["Monitor"], data->Monitor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Handle"], data->Handle, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["BufferDesc"], data->BufferDesc, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
        FieldToJson(jdata["BufferUsage"], data->decoded_value->BufferUsage, options);
        FieldToJson(jdata["BufferCount"], data->decoded_value->BufferCount, options);
        FieldToJson(jdata["OutputWindow"], data->OutputWindow, options);
        Bool32ToJson(jdata["Windowed"], data->decoded_value->Windowed, options);
        FieldToJson(jdata["SwapEffect"], data->decoded_value->SwapEffect, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Description"], data->Description, options);
        FieldToJson(jdata["VendorId"], data->decoded_value->VendorId, options);
        FieldToJson(jdata["DeviceId"], data->decoded_value->DeviceId, options);
        FieldToJson(jdata["SubSysId"], data->decoded_value->SubSysId, options);
        FieldToJson(jdata["Revision"], data->decoded_value->Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], data->decoded_value->DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], data->decoded_value->DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], data->decoded_value->SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], data->AdapterLuid, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["PrimaryCoordinates"], data->PrimaryCoordinates, options);
        FieldToJson(jdata["WhitePoints"], data->WhitePoints, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["SourcePoint"], data->SourcePoint, options);
        FieldToJson(jdata["DestinationRect"], data->DestinationRect, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ModeDesc"], data->ModeDesc, options);
        FieldToJson(jdata["Rotation"], data->decoded_value->Rotation, options);
        Bool32ToJson(jdata["DesktopImageInSystemMemory"], data->decoded_value->DesktopImageInSystemMemory, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Position"], data->Position, options);
        Bool32ToJson(jdata["Visible"], data->decoded_value->Visible, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Type"], data->decoded_value->Type, options);
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Pitch"], data->decoded_value->Pitch, options);
        FieldToJson(jdata["HotSpot"], data->HotSpot, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["LastPresentTime"], data->LastPresentTime, options);
        FieldToJson(jdata["LastMouseUpdateTime"], data->LastMouseUpdateTime, options);
        FieldToJson(jdata["AccumulatedFrames"], data->decoded_value->AccumulatedFrames, options);
        Bool32ToJson(jdata["RectsCoalesced"], data->decoded_value->RectsCoalesced, options);
        Bool32ToJson(jdata["ProtectedContentMaskedOut"], data->decoded_value->ProtectedContentMaskedOut, options);
        FieldToJson(jdata["PointerPosition"], data->PointerPosition, options);
        FieldToJson(jdata["TotalMetadataBufferSize"], data->decoded_value->TotalMetadataBufferSize, options);
        FieldToJson(jdata["PointerShapeBufferSize"], data->decoded_value->PointerShapeBufferSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["RefreshRate"], data->RefreshRate, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ScanlineOrdering"], data->decoded_value->ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], data->decoded_value->Scaling, options);
        Bool32ToJson(jdata["Stereo"], data->decoded_value->Stereo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        Bool32ToJson(jdata["Stereo"], data->decoded_value->Stereo, options);
        FieldToJson(jdata["SampleDesc"], data->SampleDesc, options);
        FieldToJson(jdata["BufferUsage"], data->decoded_value->BufferUsage, options);
        FieldToJson(jdata["BufferCount"], data->decoded_value->BufferCount, options);
        FieldToJson(jdata["Scaling"], data->decoded_value->Scaling, options);
        FieldToJson(jdata["SwapEffect"], data->decoded_value->SwapEffect, options);
        FieldToJson(jdata["AlphaMode"], data->decoded_value->AlphaMode, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RefreshRate"], data->RefreshRate, options);
        FieldToJson(jdata["ScanlineOrdering"], data->decoded_value->ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], data->decoded_value->Scaling, options);
        Bool32ToJson(jdata["Windowed"], data->decoded_value->Windowed, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DirtyRectsCount"], data->decoded_value->DirtyRectsCount, options);
        FieldToJson(jdata["pDirtyRects"], data->pDirtyRects, options);
        FieldToJson(jdata["pScrollRect"], data->pScrollRect, options);
        FieldToJson(jdata["pScrollOffset"], data->pScrollOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Description"], data->Description, options);
        FieldToJson(jdata["VendorId"], data->decoded_value->VendorId, options);
        FieldToJson(jdata["DeviceId"], data->decoded_value->DeviceId, options);
        FieldToJson(jdata["SubSysId"], data->decoded_value->SubSysId, options);
        FieldToJson(jdata["Revision"], data->decoded_value->Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], data->decoded_value->DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], data->decoded_value->DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], data->decoded_value->SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], data->AdapterLuid, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["GraphicsPreemptionGranularity"], data->decoded_value->GraphicsPreemptionGranularity, options);
        FieldToJson(jdata["ComputePreemptionGranularity"], data->decoded_value->ComputePreemptionGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["_11"], data->decoded_value->_11, options);
        FieldToJson(jdata["_12"], data->decoded_value->_12, options);
        FieldToJson(jdata["_21"], data->decoded_value->_21, options);
        FieldToJson(jdata["_22"], data->decoded_value->_22, options);
        FieldToJson(jdata["_31"], data->decoded_value->_31, options);
        FieldToJson(jdata["_32"], data->decoded_value->_32, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["PresentCount"], data->decoded_value->PresentCount, options);
        FieldToJson(jdata["PresentRefreshCount"], data->decoded_value->PresentRefreshCount, options);
        FieldToJson(jdata["SyncRefreshCount"], data->decoded_value->SyncRefreshCount, options);
        FieldToJson(jdata["SyncQPCTime"], data->SyncQPCTime, options);
        FieldToJson(jdata["SyncGPUTime"], data->SyncGPUTime, options);
        FieldToJson(jdata["CompositionMode"], data->decoded_value->CompositionMode, options);
        FieldToJson(jdata["ApprovedPresentDuration"], data->decoded_value->ApprovedPresentDuration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Budget"], data->decoded_value->Budget, options);
        FieldToJson(jdata["CurrentUsage"], data->decoded_value->CurrentUsage, options);
        FieldToJson(jdata["AvailableForReservation"], data->decoded_value->AvailableForReservation, options);
        FieldToJson(jdata["CurrentReservation"], data->decoded_value->CurrentReservation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["RedPrimary"], data->RedPrimary, options);
        FieldToJson(jdata["GreenPrimary"], data->GreenPrimary, options);
        FieldToJson(jdata["BluePrimary"], data->BluePrimary, options);
        FieldToJson(jdata["WhitePoint"], data->WhitePoint, options);
        FieldToJson(jdata["MaxMasteringLuminance"], data->decoded_value->MaxMasteringLuminance, options);
        FieldToJson(jdata["MinMasteringLuminance"], data->decoded_value->MinMasteringLuminance, options);
        FieldToJson(jdata["MaxContentLightLevel"], data->decoded_value->MaxContentLightLevel, options);
        FieldToJson(jdata["MaxFrameAverageLightLevel"], data->decoded_value->MaxFrameAverageLightLevel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Data"], data->Data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Description"], data->Description, options);
        FieldToJson(jdata["VendorId"], data->decoded_value->VendorId, options);
        FieldToJson(jdata["DeviceId"], data->decoded_value->DeviceId, options);
        FieldToJson(jdata["SubSysId"], data->decoded_value->SubSysId, options);
        FieldToJson(jdata["Revision"], data->decoded_value->Revision, options);
        FieldToJson(jdata["DedicatedVideoMemory"], data->decoded_value->DedicatedVideoMemory, options);
        FieldToJson(jdata["DedicatedSystemMemory"], data->decoded_value->DedicatedSystemMemory, options);
        FieldToJson(jdata["SharedSystemMemory"], data->decoded_value->SharedSystemMemory, options);
        FieldToJson(jdata["AdapterLuid"], data->AdapterLuid, options);
        FieldToJson(jdata["Flags"], data->decoded_value->Flags, options);
        FieldToJson(jdata["GraphicsPreemptionGranularity"], data->decoded_value->GraphicsPreemptionGranularity, options);
        FieldToJson(jdata["ComputePreemptionGranularity"], data->decoded_value->ComputePreemptionGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["DeviceName"], data->DeviceName, options);
        FieldToJson(jdata["DesktopCoordinates"], data->DesktopCoordinates, options);
        Bool32ToJson(jdata["AttachedToDesktop"], data->decoded_value->AttachedToDesktop, options);
        FieldToJson(jdata["Rotation"], data->decoded_value->Rotation, options);
        FieldToJson(jdata["Monitor"], data->Monitor, options);
        FieldToJson(jdata["BitsPerColor"], data->decoded_value->BitsPerColor, options);
        FieldToJson(jdata["ColorSpace"], data->decoded_value->ColorSpace, options);
        FieldToJson(jdata["RedPrimary"], data->RedPrimary, options);
        FieldToJson(jdata["GreenPrimary"], data->GreenPrimary, options);
        FieldToJson(jdata["BluePrimary"], data->BluePrimary, options);
        FieldToJson(jdata["WhitePoint"], data->WhitePoint, options);
        FieldToJson(jdata["MinLuminance"], data->decoded_value->MinLuminance, options);
        FieldToJson(jdata["MaxLuminance"], data->decoded_value->MaxLuminance, options);
        FieldToJson(jdata["MaxFullFrameLuminance"], data->decoded_value->MaxFullFrameLuminance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Numerator"], data->decoded_value->Numerator, options);
        FieldToJson(jdata["Denominator"], data->decoded_value->Denominator, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Count"], data->decoded_value->Count, options);
        FieldToJson(jdata["Quality"], data->decoded_value->Quality, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Red"], data->decoded_value->Red, options);
        FieldToJson(jdata["Green"], data->decoded_value->Green, options);
        FieldToJson(jdata["Blue"], data->decoded_value->Blue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["r"], data->decoded_value->r, options);
        FieldToJson(jdata["g"], data->decoded_value->g, options);
        FieldToJson(jdata["b"], data->decoded_value->b, options);
        FieldToJson(jdata["a"], data->decoded_value->a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Scale"], data->Scale, options);
        FieldToJson(jdata["Offset"], data->Offset, options);
        FieldToJson(jdata["GammaCurve"], data->GammaCurve, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        Bool32ToJson(jdata["ScaleAndOffsetSupported"], data->decoded_value->ScaleAndOffsetSupported, options);
        FieldToJson(jdata["MaxConvertedValue"], data->decoded_value->MaxConvertedValue, options);
        FieldToJson(jdata["MinConvertedValue"], data->decoded_value->MinConvertedValue, options);
        FieldToJson(jdata["NumGammaControlPoints"], data->decoded_value->NumGammaControlPoints, options);
        FieldToJson(jdata["ControlPointPositions"], data->ControlPointPositions, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Width"], data->decoded_value->Width, options);
        FieldToJson(jdata["Height"], data->decoded_value->Height, options);
        FieldToJson(jdata["RefreshRate"], data->RefreshRate, options);
        FieldToJson(jdata["Format"], data->decoded_value->Format, options);
        FieldToJson(jdata["ScanlineOrdering"], data->decoded_value->ScanlineOrdering, options);
        FieldToJson(jdata["Scaling"], data->decoded_value->Scaling, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CodeCounts"], data->CodeCounts, options);
        FieldToJson(jdata["CodeValues"], data->CodeValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["CodeCounts"], data->CodeCounts, options);
        FieldToJson(jdata["CodeValues"], data->CodeValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["Elements"], data->Elements, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["left"], data->decoded_value->left, options);
        FieldToJson(jdata["top"], data->decoded_value->top, options);
        FieldToJson(jdata["right"], data->decoded_value->right, options);
        FieldToJson(jdata["bottom"], data->decoded_value->bottom, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["nLength"], data->decoded_value->nLength, options);
        FieldToJson(jdata["lpSecurityDescriptor"], data->lpSecurityDescriptor, options);
        Bool32ToJson(jdata["bInheritHandle"], data->decoded_value->bInheritHandle, options);
    }
}

// TODO Move all these manual functions out of the generator and into a .cpp file.

/// @defgroup custom_dx12_struct_decoders_to_json_bodies Custom implementations for
/// troublesome structs.
/// We put the custom implementations in the generator Python rather than
/// creating a whole new compilation unit for them.
/** @{*/

// Decoded_LARGE_INTEGER won't be generated as it is a <winnt.h> struct rather than D3D12.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        FieldToJson(jdata, data->decoded_value->QuadPart, options);
    }
}

// Generated version tries to read the struct members rather than doing the "fake enum" thing.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const GUID& decoded_value = *data->decoded_value;
        FieldToJson(jdata, decoded_value, options);
    }
}

/// Dump all the fields of the custom struct, even though not all need be populated.
/// @note D3D12 doesn't define names for these: the underlying struct is just a void pointer
/// and a byte count with the structure defined in documentation. See:
/// <https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc>
/// See also: framework\decode\custom_dx12_struct_decoders.cpp
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
        const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
        FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct.
        //FieldToJson(jdata["root_signature_ptr"], meta_struct.root_signature_ptr, options);
        FieldToJson(jdata[format::kNameWarning], "D3D12_PIPELINE_STATE_STREAM_DESC.root_signature_ptr is not supported.", options);
        FieldToJson(jdata["root_signature_ptr"], "@todo Get this field to convert cleanly.", options);
        FieldToJson(jdata["vs_bytecode"], meta_struct.vs_bytecode, options);
        FieldToJson(jdata["ps_bytecode"], meta_struct.ps_bytecode, options);
        FieldToJson(jdata["ds_bytecode"], meta_struct.ds_bytecode, options);
        FieldToJson(jdata["hs_bytecode"], meta_struct.hs_bytecode, options);
        FieldToJson(jdata["gs_bytecode"], meta_struct.gs_bytecode, options);
        FieldToJson(jdata["cs_bytecode"], meta_struct.cs_bytecode, options);
        FieldToJson(jdata["as_bytecode"], meta_struct.as_bytecode, options);
        FieldToJson(jdata["ms_bytecode"], meta_struct.ms_bytecode, options);
        FieldToJson(jdata["stream_output"], meta_struct.stream_output, options);
        FieldToJson(jdata["blend"], meta_struct.blend, options);
        FieldToJson(jdata["rasterizer"], meta_struct.rasterizer, options);
        FieldToJson(jdata["depth_stencil"], meta_struct.depth_stencil, options);
        FieldToJson(jdata["input_layout"], meta_struct.input_layout, options);
        FieldToJson(jdata["render_target_formats"], meta_struct.render_target_formats, options);
        FieldToJson(jdata["sample_desc"], meta_struct.sample_desc, options);
        FieldToJson(jdata["cached_pso"], meta_struct.cached_pso, options);
        FieldToJson(jdata["depth_stencil1"], meta_struct.depth_stencil1, options);
        FieldToJson(jdata["view_instancing"], meta_struct.view_instancing, options);
    }
}

// The decoded struct has a custom implementation.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const D3D12_STATE_SUBOBJECT& decoded_value = *data->decoded_value;
        const Decoded_D3D12_STATE_SUBOBJECT& meta_struct = *data;
        FieldToJson(jdata["Type"], decoded_value.Type, options);
        switch(decoded_value.Type)
        {
            case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
            FieldToJson(jdata["state_object_config"], meta_struct.state_object_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
            FieldToJson(jdata["global_root_signature"], meta_struct.global_root_signature, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
            FieldToJson(jdata["local_root_signature"], meta_struct.local_root_signature, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
            FieldToJson(jdata["node_mask"], meta_struct.node_mask, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
            FieldToJson(jdata["dxil_library_desc"], meta_struct.dxil_library_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
            FieldToJson(jdata["existing_collection_desc"], meta_struct.existing_collection_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["subobject_to_exports_association"], meta_struct.subobject_to_exports_association, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
            FieldToJson(jdata["dxil_subobject_to_exports_association"], meta_struct.dxil_subobject_to_exports_association, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
            FieldToJson(jdata["raytracing_shader_config"], meta_struct.raytracing_shader_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
            FieldToJson(jdata["raytracing_pipeline_config"], meta_struct.raytracing_pipeline_config, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
            FieldToJson(jdata["hit_group_desc"], meta_struct.hit_group_desc, options);
            break;
            case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
            FieldToJson(jdata["raytracing_pipeline_config1"], meta_struct.raytracing_pipeline_config1, options);
            break;
            default:
            {
                FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_STATE_SUBOBJECT_TYPE in D3D12_STATE_SUBOBJECT.", options);
                break;
            }
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
{
    using namespace util;
    if (data && data->decoded_value)
    {
        const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;
        // FieldToJson(jdata[format::kNameInfo], "heap_id and index were copied out of ptr by a custom encoder at capture time, and ptr was never stored in the capture file.", options);
        FieldToJson(jdata["heap_id"], meta_struct.heap_id, options);
        FieldToJson(jdata["index"], meta_struct.index, options);
    }
}

/** @} */

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)
