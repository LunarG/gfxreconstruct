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
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <d3d11_4.h>
#include <d3d11on12.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>
#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string ToString(const DXGI_FRAME_STATISTICS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_MAPPED_RECT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const LUID& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_ADAPTER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTPUT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SHARED_RESOURCE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SURFACE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_ADAPTER_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTDUPL_MOVE_RECT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTDUPL_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTDUPL_POINTER_POSITION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTDUPL_FRAME_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_MODE_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SWAP_CHAIN_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_PRESENT_PARAMETERS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_ADAPTER_DESC2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_MATRIX_3X2_F& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_DECODE_SWAP_CHAIN_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_FRAME_STATISTICS_MEDIA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_QUERY_VIDEO_MEMORY_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_HDR_METADATA_HDR10& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_HDR_METADATA_HDR10PLUS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_ADAPTER_DESC3& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_OUTPUT_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_RATIONAL& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_SAMPLE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_RGB& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3DCOLORVALUE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_GAMMA_CONTROL& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_GAMMA_CONTROL_CAPABILITIES& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_MODE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_JPEG_DC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_JPEG_AC_HUFFMAN_TABLE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const DXGI_JPEG_QUANTIZATION_TABLE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_COMMAND_QUEUE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_VIEWPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BOX& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCIL_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCILOP_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCIL_DESC2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BLEND_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RASTERIZER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SHADER_BYTECODE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_STREAM_OUTPUT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_INPUT_LAYOUT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_CACHED_PIPELINE_STATE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_COMPUTE_PIPELINE_STATE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RT_FORMAT_ARRAY& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_ARCHITECTURE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_ARCHITECTURE1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_FEATURE_LEVELS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_SHADER_MODEL& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_FORMAT_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_EXISTING_HEAPS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_DISPLAYABLE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_SERIALIZATION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_CROSS_NODE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_ALLOCATION_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_ALLOCATION_INFO1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_HEAP_PROPERTIES& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_HEAP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_MIP_REGION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEPTH_STENCIL_VALUE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RANGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RANGE_UINT64& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SUBRESOURCE_RANGE_UINT64& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SUBRESOURCE_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TILE_SHAPE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_PACKED_MIP_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_TRANSITION_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_ALIASING_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RESOURCE_UAV_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SAMPLE_POSITION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_VIEW_INSTANCE_LOCATION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_VIEW_INSTANCING_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUFFER_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX3D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEXCUBE_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_CONSTANT_BUFFER_VIEW_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SAMPLER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUFFER_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_ARRAY_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX3D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUFFER_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX3D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DESCRIPTOR_HEAP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DESCRIPTOR_RANGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_DESCRIPTOR_TABLE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_CONSTANTS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_DESCRIPTOR& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_STATIC_SAMPLER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_SIGNATURE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DESCRIPTOR_RANGE1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_DESCRIPTOR_TABLE1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_DESCRIPTOR1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_ROOT_SIGNATURE_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DISCARD_REGION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_QUERY_HEAP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRAW_ARGUMENTS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRAW_INDEXED_ARGUMENTS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DISPATCH_ARGUMENTS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_VERTEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_INDEX_BUFFER_VIEW& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_COMMAND_SIGNATURE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_META_COMMAND_PARAMETER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_META_COMMAND_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_STATE_OBJECT_CONFIG& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GLOBAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_LOCAL_ROOT_SIGNATURE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_NODE_MASK& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_EXPORT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DXIL_LIBRARY_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_EXISTING_COLLECTION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_HIT_GROUP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_SHADER_CONFIG& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_PIPELINE_CONFIG& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_AABB& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_AUTO_BREADCRUMB_NODE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_BREADCRUMB_CONTEXT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_AUTO_BREADCRUMB_NODE1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_ALLOCATION_NODE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_ALLOCATION_NODE1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DRED_PAGE_FAULT_OUTPUT2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DISPATCH_RAYS_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SHADER_CACHE_SESSION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BARRIER_SUBRESOURCE_RANGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_GLOBAL_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_TEXTURE_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_BUFFER_BARRIER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_SUBRESOURCE_DATA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_MEMCPY_DEST& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEVICE_CONFIGURATION_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DISPATCH_MESH_ARGUMENTS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D_SHADER_MACRO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_MESSAGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_INFO_QUEUE_FILTER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D12_INFO_QUEUE_FILTER& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_INPUT_ELEMENT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_SO_DECLARATION_ENTRY& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIEWPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_DRAW_INSTANCED_INDIRECT_ARGS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BOX& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_DEPTH_STENCILOP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_DEPTH_STENCIL_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RENDER_TARGET_BLEND_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BLEND_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RASTERIZER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_MAPPED_SUBRESOURCE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BUFFER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXTURE1D_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXTURE2D_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXTURE3D_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BUFFEREX_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX3D_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXCUBE_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXCUBE_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_ARRAY_SRV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_ARRAY_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX3D_RTV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2DMS_ARRAY_DSV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BUFFER_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX1D_ARRAY_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX3D_UAV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_SAMPLER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_QUERY_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_QUERY_DATA_TIMESTAMP_DISJOINT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_QUERY_DATA_PIPELINE_STATISTICS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_QUERY_DATA_SO_STATISTICS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_COUNTER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_COUNTER_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_CLASS_INSTANCE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_THREADING& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_DOUBLES& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_FORMAT_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_FORMAT_SUPPORT2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_ARCHITECTURE_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D9_OPTIONS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_MARKER_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D9_OPTIONS1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS3& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_SHADER_CACHE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS5& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const CD3D11_VIDEO_DEFAULT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_CONFIG& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AES_CTR_IV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_ENCRYPTED_BLOCK_INFO& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_EXTENSION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_CAPS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_CONTENT_PROTECTION_CAPS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_CUSTOM_RATE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_FILTER_RANGE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_CONTENT_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_COLOR_RGBA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_COLOR_YCbCrA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_COLOR_SPACE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_STREAM& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_OMAC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_OUTPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_VDOV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_VPIV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_VPOV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_VPOV& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RENDER_TARGET_BLEND_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_BLEND_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RASTERIZER_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_SAMPLE_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TILED_RESOURCE_COORDINATE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TILE_REGION_SIZE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_SUBRESOURCE_TILING& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TILE_SHAPE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_PACKED_MIP_DESC& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXTURE2D_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEXTURE3D_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RASTERIZER_DESC2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_SRV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_SRV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_RTV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_RTV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_UAV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_TEX2D_ARRAY_UAV1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_QUERY_DESC1& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_VIDEO_DECODER_BUFFER_DESC2& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_FEATURE_DATA_D3D11_OPTIONS4& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const D3D11_RESOURCE_FLAGS& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const tagRECT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const tagPOINT& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);
std::string ToString(const tagSIZE& obj, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
