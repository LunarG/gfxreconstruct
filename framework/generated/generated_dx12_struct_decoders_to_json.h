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
** This file is generated from dx12_struct_decoders_to_json_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_DECODERS_TO_JSON_H
#define  GFXRECON_GENERATED_DX12_STRUCT_DECODERS_TO_JSON_H

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

/// @file Functions to convert decoded structs to JSON.
/// Note these Decoded_StructX versions have the pointer tree linking the
/// structs set-up during decode, unlike the raw structs, which is why they
/// should be used when dumping a JSON representation while following the
/// pointers.

#include "generated/generated_dx12_struct_decoders_forward.h"
#include "decode/custom_dx12_struct_decoders_forward.h"
#include "generated_dx12_enum_to_json.h"
#include "util/defines.h"
#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
struct JsonOptions;
GFXRECON_END_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(decode)

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* pObj, const util::JsonOptions& options);

// Reference versions of above which simply pipe through to the pointer versions.
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }

// Custom, manually written implementations whose prototypes haven't been generated above:

/// <winnt.h> Named union type with two structs and a uint64_t inside.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* pObj, const util::JsonOptions& options);
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#endif
