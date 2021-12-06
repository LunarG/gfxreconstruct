/*
** Copyright (c) 2021 LunarG, Inc.
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
** This file is generated from dx12_struct_to_string_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_TO_STRING_H
#define  GFXRECON_GENERATED_DX12_STRUCT_TO_STRING_H

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
#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <> std::string ToString<DXGI_FRAME_STATISTICS>(const DXGI_FRAME_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MAPPED_RECT>(const DXGI_MAPPED_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<LUID>(const LUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_DESC>(const DXGI_ADAPTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTPUT_DESC>(const DXGI_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SHARED_RESOURCE>(const DXGI_SHARED_RESOURCE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SURFACE_DESC>(const DXGI_SURFACE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_CHAIN_DESC>(const DXGI_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_DESC1>(const DXGI_ADAPTER_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_DISPLAY_COLOR_SPACE>(const DXGI_DISPLAY_COLOR_SPACE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_MOVE_RECT>(const DXGI_OUTDUPL_MOVE_RECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_DESC>(const DXGI_OUTDUPL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_POINTER_POSITION>(const DXGI_OUTDUPL_POINTER_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_POINTER_SHAPE_INFO>(const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_FRAME_INFO>(const DXGI_OUTDUPL_FRAME_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MODE_DESC1>(const DXGI_MODE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_CHAIN_DESC1>(const DXGI_SWAP_CHAIN_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_CHAIN_FULLSCREEN_DESC>(const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_PRESENT_PARAMETERS>(const DXGI_PRESENT_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_DESC2>(const DXGI_ADAPTER_DESC2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MATRIX_3X2_F>(const DXGI_MATRIX_3X2_F& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_DECODE_SWAP_CHAIN_DESC>(const DXGI_DECODE_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_FRAME_STATISTICS_MEDIA>(const DXGI_FRAME_STATISTICS_MEDIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_QUERY_VIDEO_MEMORY_INFO>(const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_HDR_METADATA_HDR10>(const DXGI_HDR_METADATA_HDR10& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_HDR_METADATA_HDR10PLUS>(const DXGI_HDR_METADATA_HDR10PLUS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_DESC3>(const DXGI_ADAPTER_DESC3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTPUT_DESC1>(const DXGI_OUTPUT_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_RATIONAL>(const DXGI_RATIONAL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SAMPLE_DESC>(const DXGI_SAMPLE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_RGB>(const DXGI_RGB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3DCOLORVALUE>(const D3DCOLORVALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_GAMMA_CONTROL>(const DXGI_GAMMA_CONTROL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_GAMMA_CONTROL_CAPABILITIES>(const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MODE_DESC>(const DXGI_MODE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_JPEG_DC_HUFFMAN_TABLE>(const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_JPEG_AC_HUFFMAN_TABLE>(const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_JPEG_QUANTIZATION_TABLE>(const DXGI_JPEG_QUANTIZATION_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_QUEUE_DESC>(const D3D12_COMMAND_QUEUE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INPUT_ELEMENT_DESC>(const D3D12_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SO_DECLARATION_ENTRY>(const D3D12_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEWPORT>(const D3D12_VIEWPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BOX>(const D3D12_BOX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEPTH_STENCILOP_DESC>(const D3D12_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC>(const D3D12_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEPTH_STENCIL_DESC1>(const D3D12_DEPTH_STENCIL_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_TARGET_BLEND_DESC>(const D3D12_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BLEND_DESC>(const D3D12_BLEND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RASTERIZER_DESC>(const D3D12_RASTERIZER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_BYTECODE>(const D3D12_SHADER_BYTECODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STREAM_OUTPUT_DESC>(const D3D12_STREAM_OUTPUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INPUT_LAYOUT_DESC>(const D3D12_INPUT_LAYOUT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CACHED_PIPELINE_STATE>(const D3D12_CACHED_PIPELINE_STATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GRAPHICS_PIPELINE_STATE_DESC>(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMPUTE_PIPELINE_STATE_DESC>(const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RT_FORMAT_ARRAY>(const D3D12_RT_FORMAT_ARRAY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS>(const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS1>(const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS2>(const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_ROOT_SIGNATURE>(const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE>(const D3D12_FEATURE_DATA_ARCHITECTURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_ARCHITECTURE1>(const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_FEATURE_LEVELS>(const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_MODEL>(const D3D12_FEATURE_DATA_SHADER_MODEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_SUPPORT>(const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS>(const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_FORMAT_INFO>(const D3D12_FEATURE_DATA_FORMAT_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT>(const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_SHADER_CACHE>(const D3D12_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY>(const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS3>(const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_EXISTING_HEAPS>(const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS4>(const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_SERIALIZATION>(const D3D12_FEATURE_DATA_SERIALIZATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_CROSS_NODE>(const D3D12_FEATURE_DATA_CROSS_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS5>(const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS6>(const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS7>(const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_QUERY_META_COMMAND>(const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS8>(const D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_D3D12_OPTIONS9>(const D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_WAVE_MMA>(const D3D12_FEATURE_DATA_WAVE_MMA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO>(const D3D12_RESOURCE_ALLOCATION_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_ALLOCATION_INFO1>(const D3D12_RESOURCE_ALLOCATION_INFO1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_PROPERTIES>(const D3D12_HEAP_PROPERTIES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_DESC>(const D3D12_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MIP_REGION>(const D3D12_MIP_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_DESC>(const D3D12_RESOURCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_DESC1>(const D3D12_RESOURCE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEPTH_STENCIL_VALUE>(const D3D12_DEPTH_STENCIL_VALUE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RANGE>(const D3D12_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RANGE_UINT64>(const D3D12_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SUBRESOURCE_RANGE_UINT64>(const D3D12_SUBRESOURCE_RANGE_UINT64& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SUBRESOURCE_INFO>(const D3D12_SUBRESOURCE_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILED_RESOURCE_COORDINATE>(const D3D12_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_REGION_SIZE>(const D3D12_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SUBRESOURCE_TILING>(const D3D12_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_SHAPE>(const D3D12_TILE_SHAPE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PACKED_MIP_INFO>(const D3D12_PACKED_MIP_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_TRANSITION_BARRIER>(const D3D12_RESOURCE_TRANSITION_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_ALIASING_BARRIER>(const D3D12_RESOURCE_ALIASING_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_UAV_BARRIER>(const D3D12_RESOURCE_UAV_BARRIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SUBRESOURCE_FOOTPRINT>(const D3D12_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>(const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SAMPLE_POSITION>(const D3D12_SAMPLE_POSITION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEW_INSTANCE_LOCATION>(const D3D12_VIEW_INSTANCE_LOCATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEW_INSTANCING_DESC>(const D3D12_VIEW_INSTANCING_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_SRV>(const D3D12_BUFFER_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_SRV>(const D3D12_TEX1D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_ARRAY_SRV>(const D3D12_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_SRV>(const D3D12_TEX2D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_ARRAY_SRV>(const D3D12_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX3D_SRV>(const D3D12_TEX3D_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEXCUBE_SRV>(const D3D12_TEXCUBE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEXCUBE_ARRAY_SRV>(const D3D12_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_SRV>(const D3D12_TEX2DMS_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_ARRAY_SRV>(const D3D12_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CONSTANT_BUFFER_VIEW_DESC>(const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SAMPLER_DESC>(const D3D12_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_UAV>(const D3D12_BUFFER_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_UAV>(const D3D12_TEX1D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_ARRAY_UAV>(const D3D12_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_UAV>(const D3D12_TEX2D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_ARRAY_UAV>(const D3D12_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX3D_UAV>(const D3D12_TEX3D_UAV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_RTV>(const D3D12_BUFFER_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_RTV>(const D3D12_TEX1D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_ARRAY_RTV>(const D3D12_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_RTV>(const D3D12_TEX2D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_RTV>(const D3D12_TEX2DMS_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_ARRAY_RTV>(const D3D12_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_ARRAY_RTV>(const D3D12_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX3D_RTV>(const D3D12_TEX3D_RTV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_DSV>(const D3D12_TEX1D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX1D_ARRAY_DSV>(const D3D12_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_DSV>(const D3D12_TEX2D_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2D_ARRAY_DSV>(const D3D12_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_DSV>(const D3D12_TEX2DMS_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEX2DMS_ARRAY_DSV>(const D3D12_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_DESC>(const D3D12_DESCRIPTOR_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_RANGE>(const D3D12_DESCRIPTOR_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE>(const D3D12_ROOT_DESCRIPTOR_TABLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_CONSTANTS>(const D3D12_ROOT_CONSTANTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR>(const D3D12_ROOT_DESCRIPTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATIC_SAMPLER_DESC>(const D3D12_STATIC_SAMPLER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC>(const D3D12_ROOT_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_RANGE1>(const D3D12_DESCRIPTOR_RANGE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_TABLE1>(const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR1>(const D3D12_ROOT_DESCRIPTOR1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_SIGNATURE_DESC1>(const D3D12_ROOT_SIGNATURE_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_DESCRIPTOR_HANDLE>(const D3D12_GPU_DESCRIPTOR_HANDLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DISCARD_REGION>(const D3D12_DISCARD_REGION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_HEAP_DESC>(const D3D12_QUERY_HEAP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_DATA_PIPELINE_STATISTICS>(const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_DATA_PIPELINE_STATISTICS1>(const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_DATA_SO_STATISTICS>(const D3D12_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STREAM_OUTPUT_BUFFER_VIEW>(const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRAW_ARGUMENTS>(const D3D12_DRAW_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRAW_INDEXED_ARGUMENTS>(const D3D12_DRAW_INDEXED_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DISPATCH_ARGUMENTS>(const D3D12_DISPATCH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VERTEX_BUFFER_VIEW>(const D3D12_VERTEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INDEX_BUFFER_VIEW>(const D3D12_INDEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_SIGNATURE_DESC>(const D3D12_COMMAND_SIGNATURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>(const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_DESC>(const D3D12_META_COMMAND_PARAMETER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_DESC>(const D3D12_META_COMMAND_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATE_OBJECT_CONFIG>(const D3D12_STATE_OBJECT_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GLOBAL_ROOT_SIGNATURE>(const D3D12_GLOBAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_LOCAL_ROOT_SIGNATURE>(const D3D12_LOCAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_NODE_MASK>(const D3D12_NODE_MASK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_EXPORT_DESC>(const D3D12_EXPORT_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DXIL_LIBRARY_DESC>(const D3D12_DXIL_LIBRARY_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_EXISTING_COLLECTION_DESC>(const D3D12_EXISTING_COLLECTION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION>(const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HIT_GROUP_DESC>(const D3D12_HIT_GROUP_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_SHADER_CONFIG>(const D3D12_RAYTRACING_SHADER_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG>(const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_CONFIG1>(const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE>(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC>(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_AABB>(const D3D12_RAYTRACING_AABB& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_AABBS_DESC>(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>(const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER>(const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_INSTANCE_DESC>(const D3D12_RAYTRACING_INSTANCE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE>(const D3D12_AUTO_BREADCRUMB_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_BREADCRUMB_CONTEXT>(const D3D12_DRED_BREADCRUMB_CONTEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_AUTO_BREADCRUMB_NODE1>(const D3D12_AUTO_BREADCRUMB_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE>(const D3D12_DRED_ALLOCATION_NODE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_ALLOCATION_NODE1>(const D3D12_DRED_ALLOCATION_NODE1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT>(const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT1>(const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_PAGE_FAULT_OUTPUT2>(const D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA1>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA2>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEVICE_REMOVED_EXTENDED_DATA3>(const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES>(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_DESC1>(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS>(const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_RENDER_TARGET_DESC>(const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>(const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DISPATCH_RAYS_DESC>(const D3D12_DISPATCH_RAYS_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_CACHE_SESSION_DESC>(const D3D12_SHADER_CACHE_SESSION_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SUBRESOURCE_DATA>(const D3D12_SUBRESOURCE_DATA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MEMCPY_DEST>(const D3D12_MEMCPY_DEST& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DISPATCH_MESH_ARGUMENTS>(const D3D12_DISPATCH_MESH_ARGUMENTS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_MACRO>(const D3D_SHADER_MACRO& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR>(const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS>(const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MESSAGE>(const D3D12_MESSAGE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INFO_QUEUE_FILTER_DESC>(const D3D12_INFO_QUEUE_FILTER_DESC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INFO_QUEUE_FILTER>(const D3D12_INFO_QUEUE_FILTER& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<GUID>(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<tagRECT>(const tagRECT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<tagPOINT>(const tagPOINT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
