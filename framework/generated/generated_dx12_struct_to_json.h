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
** This file is generated from dx12_struct_to_json_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_TO_JSON_H
#define  GFXRECON_GENERATED_DX12_STRUCT_TO_JSON_H

/// @file Functions to convert raw structs to JSON. Note, during decode time,
/// for replay or convert, you want to call the Decoded_StructX versions as
/// they have the pointer tree linking the structs set-up.

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>
#include "util/defines.h"
#include "util/json_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_STATISTICS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MAPPED_RECT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const LUID& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTPUT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SHARED_RESOURCE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SURFACE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_MOVE_RECT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_POSITION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FRAME_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_PRESENT_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MATRIX_3X2_F& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_DECODE_SWAP_CHAIN_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_STATISTICS_MEDIA& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_HDR10& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_HDR10PLUS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_DESC3& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTPUT_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RATIONAL& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SAMPLE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RGB& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3DCOLORVALUE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GAMMA_CONTROL& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_JPEG_QUANTIZATION_TABLE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_ELEMENT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SO_DECLARATION_ENTRY& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEWPORT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BOX& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCILOP_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCILOP_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_DESC2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_TARGET_BLEND_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RASTERIZER_DESC2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_BYTECODE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STREAM_OUTPUT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_LAYOUT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CACHED_PIPELINE_STATE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RT_FORMAT_ARRAY& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_STREAM_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ARCHITECTURE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SHADER_MODEL& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_FORMAT_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SHADER_CACHE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_DISPLAYABLE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_SERIALIZATION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_CROSS_NODE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS16& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS17& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS18& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_D3D12_OPTIONS19& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALLOCATION_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALLOCATION_INFO1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_PROPERTIES& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MIP_REGION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RANGE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RANGE_UINT64& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_RANGE_UINT64& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCE_COORDINATE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_REGION_SIZE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_TILING& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_SHAPE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PACKED_MIP_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_TRANSITION_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_ALIASING_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_UAV_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_FOOTPRINT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLE_POSITION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCE_LOCATION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXCUBE_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXCUBE_ARRAY_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_UAV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX3D_RTV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX1D_ARRAY_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2D_ARRAY_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEX2DMS_ARRAY_DSV& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_TABLE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_CONSTANTS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_SAMPLER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_SAMPLER_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_DESC2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISCARD_REGION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_DATA_SO_STATISTICS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRAW_ARGUMENTS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRAW_INDEXED_ARGUMENTS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_ARGUMENTS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERTEX_BUFFER_VIEW& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_VIEW& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_SIGNATURE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_CONFIG& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GLOBAL_ROOT_SIGNATURE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOCAL_ROOT_SIGNATURE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_MASK& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DXIL_LIBRARY_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXISTING_COLLECTION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SHADER_CONFIG& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_AABB& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_NODE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_BREADCRUMB_CONTEXT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_NODE1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_NODE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_NODE1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_RAYS_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SESSION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SUBRESOURCE_RANGE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GLOBAL_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_BARRIER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SUBRESOURCE_DATA& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMCPY_DEST& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_CONFIGURATION_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MESH_ARGUMENTS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MACRO& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INFO_QUEUE_FILTER_DESC& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INFO_QUEUE_FILTER& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const tagRECT& obj, const JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const tagPOINT& obj, const JsonOptions& options);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
