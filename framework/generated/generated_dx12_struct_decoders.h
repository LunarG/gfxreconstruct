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
** This file is generated from dx12_struct_decoders_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_STRUCT_DECODERS_H
#define  GFXRECON_GENERATED_DX12_STRUCT_DECODERS_H

#if defined(D3D12_SUPPORT)

#ifdef WIN32
#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <d3d11_4.h>
#include <d3d11on12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgitype.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>
#else
#include "format/platform_types.h"
#endif // WIN32

#include "decode/custom_dx12_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "generated/generated_dx12_struct_decoders_forward.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_D3D12_COMMAND_QUEUE_DESC
{
    using struct_type = D3D12_COMMAND_QUEUE_DESC;

    D3D12_COMMAND_QUEUE_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_INPUT_ELEMENT_DESC
{
    using struct_type = D3D12_INPUT_ELEMENT_DESC;

    D3D12_INPUT_ELEMENT_DESC* decoded_value{ nullptr };

    StringDecoder SemanticName;
};

struct Decoded_D3D12_SO_DECLARATION_ENTRY
{
    using struct_type = D3D12_SO_DECLARATION_ENTRY;

    D3D12_SO_DECLARATION_ENTRY* decoded_value{ nullptr };

    StringDecoder SemanticName;
};

struct Decoded_D3D12_VIEWPORT
{
    using struct_type = D3D12_VIEWPORT;

    D3D12_VIEWPORT* decoded_value{ nullptr };
};

struct Decoded_D3D12_BOX
{
    using struct_type = D3D12_BOX;

    D3D12_BOX* decoded_value{ nullptr };
};

struct Decoded_LUID
{
    using struct_type = LUID;

    LUID* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCILOP_DESC
{
    using struct_type = D3D12_DEPTH_STENCILOP_DESC;

    D3D12_DEPTH_STENCILOP_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_DESC
{
    using struct_type = D3D12_DEPTH_STENCIL_DESC;

    D3D12_DEPTH_STENCIL_DESC* decoded_value{ nullptr };

    Decoded_D3D12_DEPTH_STENCILOP_DESC* FrontFace{ nullptr };
    Decoded_D3D12_DEPTH_STENCILOP_DESC* BackFace{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_DESC1
{
    using struct_type = D3D12_DEPTH_STENCIL_DESC1;

    D3D12_DEPTH_STENCIL_DESC1* decoded_value{ nullptr };

    Decoded_D3D12_DEPTH_STENCILOP_DESC* FrontFace{ nullptr };
    Decoded_D3D12_DEPTH_STENCILOP_DESC* BackFace{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCILOP_DESC1
{
    using struct_type = D3D12_DEPTH_STENCILOP_DESC1;

    D3D12_DEPTH_STENCILOP_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_DESC2
{
    using struct_type = D3D12_DEPTH_STENCIL_DESC2;

    D3D12_DEPTH_STENCIL_DESC2* decoded_value{ nullptr };

    Decoded_D3D12_DEPTH_STENCILOP_DESC1* FrontFace{ nullptr };
    Decoded_D3D12_DEPTH_STENCILOP_DESC1* BackFace{ nullptr };
};

struct Decoded_D3D12_RENDER_TARGET_BLEND_DESC
{
    using struct_type = D3D12_RENDER_TARGET_BLEND_DESC;

    D3D12_RENDER_TARGET_BLEND_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_BLEND_DESC
{
    using struct_type = D3D12_BLEND_DESC;

    D3D12_BLEND_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_BLEND_DESC>* RenderTarget{ nullptr };
};

struct Decoded_D3D12_RASTERIZER_DESC
{
    using struct_type = D3D12_RASTERIZER_DESC;

    D3D12_RASTERIZER_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_RASTERIZER_DESC1
{
    using struct_type = D3D12_RASTERIZER_DESC1;

    D3D12_RASTERIZER_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D12_RASTERIZER_DESC2
{
    using struct_type = D3D12_RASTERIZER_DESC2;

    D3D12_RASTERIZER_DESC2* decoded_value{ nullptr };
};

struct Decoded_D3D12_SHADER_BYTECODE
{
    using struct_type = D3D12_SHADER_BYTECODE;

    D3D12_SHADER_BYTECODE* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pShaderBytecode;
};

struct Decoded_D3D12_STREAM_OUTPUT_DESC
{
    using struct_type = D3D12_STREAM_OUTPUT_DESC;

    D3D12_STREAM_OUTPUT_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_SO_DECLARATION_ENTRY>* pSODeclaration{ nullptr };
    PointerDecoder<UINT> pBufferStrides;
};

struct Decoded_D3D12_INPUT_LAYOUT_DESC
{
    using struct_type = D3D12_INPUT_LAYOUT_DESC;

    D3D12_INPUT_LAYOUT_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_INPUT_ELEMENT_DESC>* pInputElementDescs{ nullptr };
};

struct Decoded_D3D12_CACHED_PIPELINE_STATE
{
    using struct_type = D3D12_CACHED_PIPELINE_STATE;

    D3D12_CACHED_PIPELINE_STATE* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pCachedBlob;
};

struct Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC
{
    using struct_type = D3D12_GRAPHICS_PIPELINE_STATE_DESC;

    D3D12_GRAPHICS_PIPELINE_STATE_DESC* decoded_value{ nullptr };

    format::HandleId pRootSignature{ format::kNullHandleId };
    Decoded_D3D12_SHADER_BYTECODE* VS{ nullptr };
    Decoded_D3D12_SHADER_BYTECODE* PS{ nullptr };
    Decoded_D3D12_SHADER_BYTECODE* DS{ nullptr };
    Decoded_D3D12_SHADER_BYTECODE* HS{ nullptr };
    Decoded_D3D12_SHADER_BYTECODE* GS{ nullptr };
    Decoded_D3D12_STREAM_OUTPUT_DESC* StreamOutput{ nullptr };
    Decoded_D3D12_BLEND_DESC* BlendState{ nullptr };
    Decoded_D3D12_RASTERIZER_DESC* RasterizerState{ nullptr };
    Decoded_D3D12_DEPTH_STENCIL_DESC* DepthStencilState{ nullptr };
    Decoded_D3D12_INPUT_LAYOUT_DESC* InputLayout{ nullptr };
    PointerDecoder<DXGI_FORMAT> RTVFormats;
    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
    Decoded_D3D12_CACHED_PIPELINE_STATE* CachedPSO{ nullptr };
};

struct Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC
{
    using struct_type = D3D12_COMPUTE_PIPELINE_STATE_DESC;

    D3D12_COMPUTE_PIPELINE_STATE_DESC* decoded_value{ nullptr };

    format::HandleId pRootSignature{ format::kNullHandleId };
    Decoded_D3D12_SHADER_BYTECODE* CS{ nullptr };
    Decoded_D3D12_CACHED_PIPELINE_STATE* CachedPSO{ nullptr };
};

struct Decoded_D3D12_RT_FORMAT_ARRAY
{
    using struct_type = D3D12_RT_FORMAT_ARRAY;

    D3D12_RT_FORMAT_ARRAY* decoded_value{ nullptr };

    PointerDecoder<DXGI_FORMAT> RTFormats;
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS;

    D3D12_FEATURE_DATA_D3D12_OPTIONS* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS1;

    D3D12_FEATURE_DATA_D3D12_OPTIONS1* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS2;

    D3D12_FEATURE_DATA_D3D12_OPTIONS2* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE
{
    using struct_type = D3D12_FEATURE_DATA_ROOT_SIGNATURE;

    D3D12_FEATURE_DATA_ROOT_SIGNATURE* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_ARCHITECTURE
{
    using struct_type = D3D12_FEATURE_DATA_ARCHITECTURE;

    D3D12_FEATURE_DATA_ARCHITECTURE* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1
{
    using struct_type = D3D12_FEATURE_DATA_ARCHITECTURE1;

    D3D12_FEATURE_DATA_ARCHITECTURE1* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS
{
    using struct_type = D3D12_FEATURE_DATA_FEATURE_LEVELS;

    D3D12_FEATURE_DATA_FEATURE_LEVELS* decoded_value{ nullptr };

    PointerDecoder<D3D_FEATURE_LEVEL> pFeatureLevelsRequested;
};

struct Decoded_D3D12_FEATURE_DATA_SHADER_MODEL
{
    using struct_type = D3D12_FEATURE_DATA_SHADER_MODEL;

    D3D12_FEATURE_DATA_SHADER_MODEL* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT
{
    using struct_type = D3D12_FEATURE_DATA_FORMAT_SUPPORT;

    D3D12_FEATURE_DATA_FORMAT_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS
{
    using struct_type = D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS;

    D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_FORMAT_INFO
{
    using struct_type = D3D12_FEATURE_DATA_FORMAT_INFO;

    D3D12_FEATURE_DATA_FORMAT_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT
{
    using struct_type = D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT;

    D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_SHADER_CACHE
{
    using struct_type = D3D12_FEATURE_DATA_SHADER_CACHE;

    D3D12_FEATURE_DATA_SHADER_CACHE* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY
{
    using struct_type = D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY;

    D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS3;

    D3D12_FEATURE_DATA_D3D12_OPTIONS3* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS
{
    using struct_type = D3D12_FEATURE_DATA_EXISTING_HEAPS;

    D3D12_FEATURE_DATA_EXISTING_HEAPS* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_DISPLAYABLE
{
    using struct_type = D3D12_FEATURE_DATA_DISPLAYABLE;

    D3D12_FEATURE_DATA_DISPLAYABLE* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS4;

    D3D12_FEATURE_DATA_D3D12_OPTIONS4* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_SERIALIZATION
{
    using struct_type = D3D12_FEATURE_DATA_SERIALIZATION;

    D3D12_FEATURE_DATA_SERIALIZATION* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_CROSS_NODE
{
    using struct_type = D3D12_FEATURE_DATA_CROSS_NODE;

    D3D12_FEATURE_DATA_CROSS_NODE* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS5;

    D3D12_FEATURE_DATA_D3D12_OPTIONS5* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS6;

    D3D12_FEATURE_DATA_D3D12_OPTIONS6* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS7;

    D3D12_FEATURE_DATA_D3D12_OPTIONS7* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND
{
    using struct_type = D3D12_FEATURE_DATA_QUERY_META_COMMAND;

    D3D12_FEATURE_DATA_QUERY_META_COMMAND* decoded_value{ nullptr };

    Decoded_GUID* CommandId{ nullptr };
    PointerDecoder<uint8_t> pQueryInputData;
    PointerDecoder<uint8_t> pQueryOutputData;
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS8;

    D3D12_FEATURE_DATA_D3D12_OPTIONS8* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS9;

    D3D12_FEATURE_DATA_D3D12_OPTIONS9* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS10;

    D3D12_FEATURE_DATA_D3D12_OPTIONS10* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS11;

    D3D12_FEATURE_DATA_D3D12_OPTIONS11* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS12;

    D3D12_FEATURE_DATA_D3D12_OPTIONS12* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS13;

    D3D12_FEATURE_DATA_D3D12_OPTIONS13* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS14;

    D3D12_FEATURE_DATA_D3D12_OPTIONS14* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS15;

    D3D12_FEATURE_DATA_D3D12_OPTIONS15* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS16;

    D3D12_FEATURE_DATA_D3D12_OPTIONS16* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS17;

    D3D12_FEATURE_DATA_D3D12_OPTIONS17* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS18;

    D3D12_FEATURE_DATA_D3D12_OPTIONS18* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS19;

    D3D12_FEATURE_DATA_D3D12_OPTIONS19* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS20;

    D3D12_FEATURE_DATA_D3D12_OPTIONS20* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21
{
    using struct_type = D3D12_FEATURE_DATA_D3D12_OPTIONS21;

    D3D12_FEATURE_DATA_D3D12_OPTIONS21* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_PREDICATION
{
    using struct_type = D3D12_FEATURE_DATA_PREDICATION;

    D3D12_FEATURE_DATA_PREDICATION* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY
{
    using struct_type = D3D12_FEATURE_DATA_HARDWARE_COPY;

    D3D12_FEATURE_DATA_HARDWARE_COPY* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED
{
    using struct_type = D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED;

    D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED* decoded_value{ nullptr };
};

struct Decoded_D3D12_RESOURCE_ALLOCATION_INFO
{
    using struct_type = D3D12_RESOURCE_ALLOCATION_INFO;

    D3D12_RESOURCE_ALLOCATION_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D12_RESOURCE_ALLOCATION_INFO1
{
    using struct_type = D3D12_RESOURCE_ALLOCATION_INFO1;

    D3D12_RESOURCE_ALLOCATION_INFO1* decoded_value{ nullptr };
};

struct Decoded_D3D12_HEAP_PROPERTIES
{
    using struct_type = D3D12_HEAP_PROPERTIES;

    D3D12_HEAP_PROPERTIES* decoded_value{ nullptr };
};

struct Decoded_D3D12_HEAP_DESC
{
    using struct_type = D3D12_HEAP_DESC;

    D3D12_HEAP_DESC* decoded_value{ nullptr };

    Decoded_D3D12_HEAP_PROPERTIES* Properties{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO
{
    using struct_type = D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO;

    D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO* decoded_value{ nullptr };

    Decoded_D3D12_HEAP_PROPERTIES* DestHeapProperties{ nullptr };
};

struct Decoded_D3D12_MIP_REGION
{
    using struct_type = D3D12_MIP_REGION;

    D3D12_MIP_REGION* decoded_value{ nullptr };
};

struct Decoded_D3D12_RESOURCE_DESC
{
    using struct_type = D3D12_RESOURCE_DESC;

    D3D12_RESOURCE_DESC* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
};

struct Decoded_D3D12_RESOURCE_DESC1
{
    using struct_type = D3D12_RESOURCE_DESC1;

    D3D12_RESOURCE_DESC1* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
    Decoded_D3D12_MIP_REGION* SamplerFeedbackMipRegion{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_VALUE
{
    using struct_type = D3D12_DEPTH_STENCIL_VALUE;

    D3D12_DEPTH_STENCIL_VALUE* decoded_value{ nullptr };
};

struct Decoded_D3D12_RANGE
{
    using struct_type = D3D12_RANGE;

    D3D12_RANGE* decoded_value{ nullptr };
};

struct Decoded_D3D12_RANGE_UINT64
{
    using struct_type = D3D12_RANGE_UINT64;

    D3D12_RANGE_UINT64* decoded_value{ nullptr };
};

struct Decoded_D3D12_SUBRESOURCE_RANGE_UINT64
{
    using struct_type = D3D12_SUBRESOURCE_RANGE_UINT64;

    D3D12_SUBRESOURCE_RANGE_UINT64* decoded_value{ nullptr };

    Decoded_D3D12_RANGE_UINT64* Range{ nullptr };
};

struct Decoded_D3D12_SUBRESOURCE_INFO
{
    using struct_type = D3D12_SUBRESOURCE_INFO;

    D3D12_SUBRESOURCE_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D12_TILED_RESOURCE_COORDINATE
{
    using struct_type = D3D12_TILED_RESOURCE_COORDINATE;

    D3D12_TILED_RESOURCE_COORDINATE* decoded_value{ nullptr };
};

struct Decoded_D3D12_TILE_REGION_SIZE
{
    using struct_type = D3D12_TILE_REGION_SIZE;

    D3D12_TILE_REGION_SIZE* decoded_value{ nullptr };
};

struct Decoded_D3D12_SUBRESOURCE_TILING
{
    using struct_type = D3D12_SUBRESOURCE_TILING;

    D3D12_SUBRESOURCE_TILING* decoded_value{ nullptr };
};

struct Decoded_D3D12_TILE_SHAPE
{
    using struct_type = D3D12_TILE_SHAPE;

    D3D12_TILE_SHAPE* decoded_value{ nullptr };
};

struct Decoded_D3D12_PACKED_MIP_INFO
{
    using struct_type = D3D12_PACKED_MIP_INFO;

    D3D12_PACKED_MIP_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D12_RESOURCE_TRANSITION_BARRIER
{
    using struct_type = D3D12_RESOURCE_TRANSITION_BARRIER;

    D3D12_RESOURCE_TRANSITION_BARRIER* decoded_value{ nullptr };

    format::HandleId pResource{ format::kNullHandleId };
};

struct Decoded_D3D12_RESOURCE_ALIASING_BARRIER
{
    using struct_type = D3D12_RESOURCE_ALIASING_BARRIER;

    D3D12_RESOURCE_ALIASING_BARRIER* decoded_value{ nullptr };

    format::HandleId pResourceBefore{ format::kNullHandleId };
    format::HandleId pResourceAfter{ format::kNullHandleId };
};

struct Decoded_D3D12_RESOURCE_UAV_BARRIER
{
    using struct_type = D3D12_RESOURCE_UAV_BARRIER;

    D3D12_RESOURCE_UAV_BARRIER* decoded_value{ nullptr };

    format::HandleId pResource{ format::kNullHandleId };
};

struct Decoded_D3D12_SUBRESOURCE_FOOTPRINT
{
    using struct_type = D3D12_SUBRESOURCE_FOOTPRINT;

    D3D12_SUBRESOURCE_FOOTPRINT* decoded_value{ nullptr };
};

struct Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT
{
    using struct_type = D3D12_PLACED_SUBRESOURCE_FOOTPRINT;

    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* decoded_value{ nullptr };

    Decoded_D3D12_SUBRESOURCE_FOOTPRINT* Footprint{ nullptr };
};

struct Decoded_D3D12_SAMPLE_POSITION
{
    using struct_type = D3D12_SAMPLE_POSITION;

    D3D12_SAMPLE_POSITION* decoded_value{ nullptr };
};

struct Decoded_D3D12_VIEW_INSTANCE_LOCATION
{
    using struct_type = D3D12_VIEW_INSTANCE_LOCATION;

    D3D12_VIEW_INSTANCE_LOCATION* decoded_value{ nullptr };
};

struct Decoded_D3D12_VIEW_INSTANCING_DESC
{
    using struct_type = D3D12_VIEW_INSTANCING_DESC;

    D3D12_VIEW_INSTANCING_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_VIEW_INSTANCE_LOCATION>* pViewInstanceLocations{ nullptr };
};

struct Decoded_D3D12_BUFFER_SRV
{
    using struct_type = D3D12_BUFFER_SRV;

    D3D12_BUFFER_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_SRV
{
    using struct_type = D3D12_TEX1D_SRV;

    D3D12_TEX1D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_ARRAY_SRV
{
    using struct_type = D3D12_TEX1D_ARRAY_SRV;

    D3D12_TEX1D_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_SRV
{
    using struct_type = D3D12_TEX2D_SRV;

    D3D12_TEX2D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_ARRAY_SRV
{
    using struct_type = D3D12_TEX2D_ARRAY_SRV;

    D3D12_TEX2D_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX3D_SRV
{
    using struct_type = D3D12_TEX3D_SRV;

    D3D12_TEX3D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEXCUBE_SRV
{
    using struct_type = D3D12_TEXCUBE_SRV;

    D3D12_TEXCUBE_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEXCUBE_ARRAY_SRV
{
    using struct_type = D3D12_TEXCUBE_ARRAY_SRV;

    D3D12_TEXCUBE_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_SRV
{
    using struct_type = D3D12_TEX2DMS_SRV;

    D3D12_TEX2DMS_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_ARRAY_SRV
{
    using struct_type = D3D12_TEX2DMS_ARRAY_SRV;

    D3D12_TEX2DMS_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC
{
    using struct_type = D3D12_CONSTANT_BUFFER_VIEW_DESC;

    D3D12_CONSTANT_BUFFER_VIEW_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_SAMPLER_DESC
{
    using struct_type = D3D12_SAMPLER_DESC;

    D3D12_SAMPLER_DESC* decoded_value{ nullptr };

    PointerDecoder<FLOAT> BorderColor;
};

struct Decoded_D3D12_BUFFER_UAV
{
    using struct_type = D3D12_BUFFER_UAV;

    D3D12_BUFFER_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_UAV
{
    using struct_type = D3D12_TEX1D_UAV;

    D3D12_TEX1D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_ARRAY_UAV
{
    using struct_type = D3D12_TEX1D_ARRAY_UAV;

    D3D12_TEX1D_ARRAY_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_UAV
{
    using struct_type = D3D12_TEX2D_UAV;

    D3D12_TEX2D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_ARRAY_UAV
{
    using struct_type = D3D12_TEX2D_ARRAY_UAV;

    D3D12_TEX2D_ARRAY_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_UAV
{
    using struct_type = D3D12_TEX2DMS_UAV;

    D3D12_TEX2DMS_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_ARRAY_UAV
{
    using struct_type = D3D12_TEX2DMS_ARRAY_UAV;

    D3D12_TEX2DMS_ARRAY_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX3D_UAV
{
    using struct_type = D3D12_TEX3D_UAV;

    D3D12_TEX3D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D12_BUFFER_RTV
{
    using struct_type = D3D12_BUFFER_RTV;

    D3D12_BUFFER_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_RTV
{
    using struct_type = D3D12_TEX1D_RTV;

    D3D12_TEX1D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_ARRAY_RTV
{
    using struct_type = D3D12_TEX1D_ARRAY_RTV;

    D3D12_TEX1D_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_RTV
{
    using struct_type = D3D12_TEX2D_RTV;

    D3D12_TEX2D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_RTV
{
    using struct_type = D3D12_TEX2DMS_RTV;

    D3D12_TEX2DMS_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_ARRAY_RTV
{
    using struct_type = D3D12_TEX2D_ARRAY_RTV;

    D3D12_TEX2D_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_ARRAY_RTV
{
    using struct_type = D3D12_TEX2DMS_ARRAY_RTV;

    D3D12_TEX2DMS_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX3D_RTV
{
    using struct_type = D3D12_TEX3D_RTV;

    D3D12_TEX3D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_DSV
{
    using struct_type = D3D12_TEX1D_DSV;

    D3D12_TEX1D_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX1D_ARRAY_DSV
{
    using struct_type = D3D12_TEX1D_ARRAY_DSV;

    D3D12_TEX1D_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_DSV
{
    using struct_type = D3D12_TEX2D_DSV;

    D3D12_TEX2D_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2D_ARRAY_DSV
{
    using struct_type = D3D12_TEX2D_ARRAY_DSV;

    D3D12_TEX2D_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_DSV
{
    using struct_type = D3D12_TEX2DMS_DSV;

    D3D12_TEX2DMS_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEX2DMS_ARRAY_DSV
{
    using struct_type = D3D12_TEX2DMS_ARRAY_DSV;

    D3D12_TEX2DMS_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D12_DESCRIPTOR_HEAP_DESC
{
    using struct_type = D3D12_DESCRIPTOR_HEAP_DESC;

    D3D12_DESCRIPTOR_HEAP_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_DESCRIPTOR_RANGE
{
    using struct_type = D3D12_DESCRIPTOR_RANGE;

    D3D12_DESCRIPTOR_RANGE* decoded_value{ nullptr };
};

struct Decoded_D3D12_ROOT_DESCRIPTOR_TABLE
{
    using struct_type = D3D12_ROOT_DESCRIPTOR_TABLE;

    D3D12_ROOT_DESCRIPTOR_TABLE* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_RANGE>* pDescriptorRanges{ nullptr };
};

struct Decoded_D3D12_ROOT_CONSTANTS
{
    using struct_type = D3D12_ROOT_CONSTANTS;

    D3D12_ROOT_CONSTANTS* decoded_value{ nullptr };
};

struct Decoded_D3D12_ROOT_DESCRIPTOR
{
    using struct_type = D3D12_ROOT_DESCRIPTOR;

    D3D12_ROOT_DESCRIPTOR* decoded_value{ nullptr };
};

struct Decoded_D3D12_STATIC_SAMPLER_DESC
{
    using struct_type = D3D12_STATIC_SAMPLER_DESC;

    D3D12_STATIC_SAMPLER_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_STATIC_SAMPLER_DESC1
{
    using struct_type = D3D12_STATIC_SAMPLER_DESC1;

    D3D12_STATIC_SAMPLER_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D12_ROOT_SIGNATURE_DESC
{
    using struct_type = D3D12_ROOT_SIGNATURE_DESC;

    D3D12_ROOT_SIGNATURE_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER>* pParameters{ nullptr };
    StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC>* pStaticSamplers{ nullptr };
};

struct Decoded_D3D12_DESCRIPTOR_RANGE1
{
    using struct_type = D3D12_DESCRIPTOR_RANGE1;

    D3D12_DESCRIPTOR_RANGE1* decoded_value{ nullptr };
};

struct Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1
{
    using struct_type = D3D12_ROOT_DESCRIPTOR_TABLE1;

    D3D12_ROOT_DESCRIPTOR_TABLE1* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_RANGE1>* pDescriptorRanges{ nullptr };
};

struct Decoded_D3D12_ROOT_DESCRIPTOR1
{
    using struct_type = D3D12_ROOT_DESCRIPTOR1;

    D3D12_ROOT_DESCRIPTOR1* decoded_value{ nullptr };
};

struct Decoded_D3D12_ROOT_SIGNATURE_DESC1
{
    using struct_type = D3D12_ROOT_SIGNATURE_DESC1;

    D3D12_ROOT_SIGNATURE_DESC1* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER1>* pParameters{ nullptr };
    StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC>* pStaticSamplers{ nullptr };
};

struct Decoded_D3D12_ROOT_SIGNATURE_DESC2
{
    using struct_type = D3D12_ROOT_SIGNATURE_DESC2;

    D3D12_ROOT_SIGNATURE_DESC2* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_ROOT_PARAMETER1>* pParameters{ nullptr };
    StructPointerDecoder<Decoded_D3D12_STATIC_SAMPLER_DESC1>* pStaticSamplers{ nullptr };
};

struct Decoded_D3D12_GPU_DESCRIPTOR_HANDLE
{
    using struct_type = D3D12_GPU_DESCRIPTOR_HANDLE;

    D3D12_GPU_DESCRIPTOR_HANDLE* decoded_value{ nullptr };
};

struct Decoded_D3D12_DISCARD_REGION
{
    using struct_type = D3D12_DISCARD_REGION;

    D3D12_DISCARD_REGION* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_tagRECT>* pRects{ nullptr };
};

struct Decoded_D3D12_QUERY_HEAP_DESC
{
    using struct_type = D3D12_QUERY_HEAP_DESC;

    D3D12_QUERY_HEAP_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS
{
    using struct_type = D3D12_QUERY_DATA_PIPELINE_STATISTICS;

    D3D12_QUERY_DATA_PIPELINE_STATISTICS* decoded_value{ nullptr };
};

struct Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1
{
    using struct_type = D3D12_QUERY_DATA_PIPELINE_STATISTICS1;

    D3D12_QUERY_DATA_PIPELINE_STATISTICS1* decoded_value{ nullptr };
};

struct Decoded_D3D12_QUERY_DATA_SO_STATISTICS
{
    using struct_type = D3D12_QUERY_DATA_SO_STATISTICS;

    D3D12_QUERY_DATA_SO_STATISTICS* decoded_value{ nullptr };
};

struct Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW
{
    using struct_type = D3D12_STREAM_OUTPUT_BUFFER_VIEW;

    D3D12_STREAM_OUTPUT_BUFFER_VIEW* decoded_value{ nullptr };
};

struct Decoded_D3D12_DRAW_ARGUMENTS
{
    using struct_type = D3D12_DRAW_ARGUMENTS;

    D3D12_DRAW_ARGUMENTS* decoded_value{ nullptr };
};

struct Decoded_D3D12_DRAW_INDEXED_ARGUMENTS
{
    using struct_type = D3D12_DRAW_INDEXED_ARGUMENTS;

    D3D12_DRAW_INDEXED_ARGUMENTS* decoded_value{ nullptr };
};

struct Decoded_D3D12_DISPATCH_ARGUMENTS
{
    using struct_type = D3D12_DISPATCH_ARGUMENTS;

    D3D12_DISPATCH_ARGUMENTS* decoded_value{ nullptr };
};

struct Decoded_D3D12_VERTEX_BUFFER_VIEW
{
    using struct_type = D3D12_VERTEX_BUFFER_VIEW;

    D3D12_VERTEX_BUFFER_VIEW* decoded_value{ nullptr };
};

struct Decoded_D3D12_INDEX_BUFFER_VIEW
{
    using struct_type = D3D12_INDEX_BUFFER_VIEW;

    D3D12_INDEX_BUFFER_VIEW* decoded_value{ nullptr };
};

struct Decoded_D3D12_COMMAND_SIGNATURE_DESC
{
    using struct_type = D3D12_COMMAND_SIGNATURE_DESC;

    D3D12_COMMAND_SIGNATURE_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_INDIRECT_ARGUMENT_DESC>* pArgumentDescs{ nullptr };
};

struct Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER
{
    using struct_type = D3D12_WRITEBUFFERIMMEDIATE_PARAMETER;

    D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT
{
    using struct_type = D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT;

    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC
{
    using struct_type = D3D12_PROTECTED_RESOURCE_SESSION_DESC;

    D3D12_PROTECTED_RESOURCE_SESSION_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_META_COMMAND_PARAMETER_DESC
{
    using struct_type = D3D12_META_COMMAND_PARAMETER_DESC;

    D3D12_META_COMMAND_PARAMETER_DESC* decoded_value{ nullptr };

    WStringDecoder Name;
};

struct Decoded_D3D12_META_COMMAND_DESC
{
    using struct_type = D3D12_META_COMMAND_DESC;

    D3D12_META_COMMAND_DESC* decoded_value{ nullptr };

    Decoded_GUID* Id{ nullptr };
    WStringDecoder Name;
};

struct Decoded_D3D12_PROGRAM_IDENTIFIER
{
    using struct_type = D3D12_PROGRAM_IDENTIFIER;

    D3D12_PROGRAM_IDENTIFIER* decoded_value{ nullptr };

    PointerDecoder<UINT64> OpaqueData;
};

struct Decoded_D3D12_NODE_ID
{
    using struct_type = D3D12_NODE_ID;

    D3D12_NODE_ID* decoded_value{ nullptr };

    WStringDecoder Name;
};

struct Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS
{
    using struct_type = D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS;

    D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* decoded_value{ nullptr };
};

struct Decoded_D3D12_STATE_OBJECT_CONFIG
{
    using struct_type = D3D12_STATE_OBJECT_CONFIG;

    D3D12_STATE_OBJECT_CONFIG* decoded_value{ nullptr };
};

struct Decoded_D3D12_GLOBAL_ROOT_SIGNATURE
{
    using struct_type = D3D12_GLOBAL_ROOT_SIGNATURE;

    D3D12_GLOBAL_ROOT_SIGNATURE* decoded_value{ nullptr };

    format::HandleId pGlobalRootSignature{ format::kNullHandleId };
};

struct Decoded_D3D12_LOCAL_ROOT_SIGNATURE
{
    using struct_type = D3D12_LOCAL_ROOT_SIGNATURE;

    D3D12_LOCAL_ROOT_SIGNATURE* decoded_value{ nullptr };

    format::HandleId pLocalRootSignature{ format::kNullHandleId };
};

struct Decoded_D3D12_NODE_MASK
{
    using struct_type = D3D12_NODE_MASK;

    D3D12_NODE_MASK* decoded_value{ nullptr };
};

struct Decoded_D3D12_SAMPLE_MASK
{
    using struct_type = D3D12_SAMPLE_MASK;

    D3D12_SAMPLE_MASK* decoded_value{ nullptr };
};

struct Decoded_D3D12_IB_STRIP_CUT_VALUE
{
    using struct_type = D3D12_IB_STRIP_CUT_VALUE;

    D3D12_IB_STRIP_CUT_VALUE* decoded_value{ nullptr };
};

struct Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC
{
    using struct_type = D3D12_PRIMITIVE_TOPOLOGY_DESC;

    D3D12_PRIMITIVE_TOPOLOGY_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEPTH_STENCIL_FORMAT
{
    using struct_type = D3D12_DEPTH_STENCIL_FORMAT;

    D3D12_DEPTH_STENCIL_FORMAT* decoded_value{ nullptr };
};

struct Decoded_D3D12_EXPORT_DESC
{
    using struct_type = D3D12_EXPORT_DESC;

    D3D12_EXPORT_DESC* decoded_value{ nullptr };

    WStringDecoder Name;
    WStringDecoder ExportToRename;
};

struct Decoded_D3D12_DXIL_LIBRARY_DESC
{
    using struct_type = D3D12_DXIL_LIBRARY_DESC;

    D3D12_DXIL_LIBRARY_DESC* decoded_value{ nullptr };

    Decoded_D3D12_SHADER_BYTECODE* DXILLibrary{ nullptr };
    StructPointerDecoder<Decoded_D3D12_EXPORT_DESC>* pExports{ nullptr };
};

struct Decoded_D3D12_EXISTING_COLLECTION_DESC
{
    using struct_type = D3D12_EXISTING_COLLECTION_DESC;

    D3D12_EXISTING_COLLECTION_DESC* decoded_value{ nullptr };

    format::HandleId pExistingCollection{ format::kNullHandleId };
    StructPointerDecoder<Decoded_D3D12_EXPORT_DESC>* pExports{ nullptr };
};

struct Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION
{
    using struct_type = D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION;

    D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* decoded_value{ nullptr };

    WStringDecoder SubobjectToAssociate;
    WStringArrayDecoder pExports;
};

struct Decoded_D3D12_HIT_GROUP_DESC
{
    using struct_type = D3D12_HIT_GROUP_DESC;

    D3D12_HIT_GROUP_DESC* decoded_value{ nullptr };

    WStringDecoder HitGroupExport;
    WStringDecoder AnyHitShaderImport;
    WStringDecoder ClosestHitShaderImport;
    WStringDecoder IntersectionShaderImport;
};

struct Decoded_D3D12_RAYTRACING_SHADER_CONFIG
{
    using struct_type = D3D12_RAYTRACING_SHADER_CONFIG;

    D3D12_RAYTRACING_SHADER_CONFIG* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG
{
    using struct_type = D3D12_RAYTRACING_PIPELINE_CONFIG;

    D3D12_RAYTRACING_PIPELINE_CONFIG* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1
{
    using struct_type = D3D12_RAYTRACING_PIPELINE_CONFIG1;

    D3D12_RAYTRACING_PIPELINE_CONFIG1* decoded_value{ nullptr };
};

struct Decoded_D3D12_NODE_OUTPUT_OVERRIDES
{
    using struct_type = D3D12_NODE_OUTPUT_OVERRIDES;

    D3D12_NODE_OUTPUT_OVERRIDES* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pNewName{ nullptr };
    PointerDecoder<BOOL> pAllowSparseNodes;
    PointerDecoder<UINT> pMaxRecords;
    PointerDecoder<UINT> pMaxRecordsSharedWithOutputIndex;
};

struct Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES
{
    using struct_type = D3D12_BROADCASTING_LAUNCH_OVERRIDES;

    D3D12_BROADCASTING_LAUNCH_OVERRIDES* decoded_value{ nullptr };

    PointerDecoder<UINT> pLocalRootArgumentsTableIndex;
    PointerDecoder<BOOL> pProgramEntry;
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pNewName{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pShareInputOf{ nullptr };
    PointerDecoder<UINT> pDispatchGrid;
    PointerDecoder<UINT> pMaxDispatchGrid;
    StructPointerDecoder<Decoded_D3D12_NODE_OUTPUT_OVERRIDES>* pOutputOverrides{ nullptr };
};

struct Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES
{
    using struct_type = D3D12_COALESCING_LAUNCH_OVERRIDES;

    D3D12_COALESCING_LAUNCH_OVERRIDES* decoded_value{ nullptr };

    PointerDecoder<UINT> pLocalRootArgumentsTableIndex;
    PointerDecoder<BOOL> pProgramEntry;
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pNewName{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pShareInputOf{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_OUTPUT_OVERRIDES>* pOutputOverrides{ nullptr };
};

struct Decoded_D3D12_THREAD_LAUNCH_OVERRIDES
{
    using struct_type = D3D12_THREAD_LAUNCH_OVERRIDES;

    D3D12_THREAD_LAUNCH_OVERRIDES* decoded_value{ nullptr };

    PointerDecoder<UINT> pLocalRootArgumentsTableIndex;
    PointerDecoder<BOOL> pProgramEntry;
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pNewName{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pShareInputOf{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_OUTPUT_OVERRIDES>* pOutputOverrides{ nullptr };
};

struct Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES
{
    using struct_type = D3D12_COMMON_COMPUTE_NODE_OVERRIDES;

    D3D12_COMMON_COMPUTE_NODE_OVERRIDES* decoded_value{ nullptr };

    PointerDecoder<UINT> pLocalRootArgumentsTableIndex;
    PointerDecoder<BOOL> pProgramEntry;
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pNewName{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pShareInputOf{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE_OUTPUT_OVERRIDES>* pOutputOverrides{ nullptr };
};

struct Decoded_D3D12_WORK_GRAPH_DESC
{
    using struct_type = D3D12_WORK_GRAPH_DESC;

    D3D12_WORK_GRAPH_DESC* decoded_value{ nullptr };

    WStringDecoder ProgramName;
    StructPointerDecoder<Decoded_D3D12_NODE_ID>* pEntrypoints{ nullptr };
    StructPointerDecoder<Decoded_D3D12_NODE>* pExplicitlyDefinedNodes{ nullptr };
};

struct Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE
{
    using struct_type = D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE;

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* decoded_value{ nullptr };
};

struct Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE
{
    using struct_type = D3D12_GPU_VIRTUAL_ADDRESS_RANGE;

    D3D12_GPU_VIRTUAL_ADDRESS_RANGE* decoded_value{ nullptr };
};

struct Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE
{
    using struct_type = D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE;

    D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC
{
    using struct_type = D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC;

    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* decoded_value{ nullptr };

    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* VertexBuffer{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_AABB
{
    using struct_type = D3D12_RAYTRACING_AABB;

    D3D12_RAYTRACING_AABB* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC
{
    using struct_type = D3D12_RAYTRACING_GEOMETRY_AABBS_DESC;

    D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* decoded_value{ nullptr };

    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* AABBs{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER
{
    using struct_type = D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER;

    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER
{
    using struct_type = D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER;

    D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* decoded_value{ nullptr };

    Decoded_GUID* DriverOpaqueGUID{ nullptr };
    PointerDecoder<BYTE> DriverOpaqueVersioningData;
};

struct Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER
{
    using struct_type = D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER;

    D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* decoded_value{ nullptr };

    Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* DriverMatchingIdentifier{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_INSTANCE_DESC
{
    using struct_type = D3D12_RAYTRACING_INSTANCE_DESC;

    D3D12_RAYTRACING_INSTANCE_DESC* decoded_value{ nullptr };

    PointerDecoder<FLOAT> Transform;
};

struct Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC
{
    using struct_type = D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC;

    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* decoded_value{ nullptr };

    Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* Inputs{ nullptr };
};

struct Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO
{
    using struct_type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO;

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D12_AUTO_BREADCRUMB_NODE
{
    using struct_type = D3D12_AUTO_BREADCRUMB_NODE;

    D3D12_AUTO_BREADCRUMB_NODE* decoded_value{ nullptr };

    StringDecoder pCommandListDebugNameA;
    WStringDecoder pCommandListDebugNameW;
    StringDecoder pCommandQueueDebugNameA;
    WStringDecoder pCommandQueueDebugNameW;
    format::HandleId pCommandList{ format::kNullHandleId };
    format::HandleId pCommandQueue{ format::kNullHandleId };
    PointerDecoder<UINT32> pLastBreadcrumbValue;
    PointerDecoder<D3D12_AUTO_BREADCRUMB_OP> pCommandHistory;
    StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* pNext{ nullptr };
};

struct Decoded_D3D12_DRED_BREADCRUMB_CONTEXT
{
    using struct_type = D3D12_DRED_BREADCRUMB_CONTEXT;

    D3D12_DRED_BREADCRUMB_CONTEXT* decoded_value{ nullptr };

    WStringDecoder pContextString;
};

struct Decoded_D3D12_AUTO_BREADCRUMB_NODE1
{
    using struct_type = D3D12_AUTO_BREADCRUMB_NODE1;

    D3D12_AUTO_BREADCRUMB_NODE1* decoded_value{ nullptr };

    StringDecoder pCommandListDebugNameA;
    WStringDecoder pCommandListDebugNameW;
    StringDecoder pCommandQueueDebugNameA;
    WStringDecoder pCommandQueueDebugNameW;
    format::HandleId pCommandList{ format::kNullHandleId };
    format::HandleId pCommandQueue{ format::kNullHandleId };
    PointerDecoder<UINT> pLastBreadcrumbValue;
    PointerDecoder<D3D12_AUTO_BREADCRUMB_OP> pCommandHistory;
    StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* pNext{ nullptr };
    StructPointerDecoder<Decoded_D3D12_DRED_BREADCRUMB_CONTEXT>* pBreadcrumbContexts{ nullptr };
};

struct Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA
{
    using struct_type = D3D12_DEVICE_REMOVED_EXTENDED_DATA;

    D3D12_DEVICE_REMOVED_EXTENDED_DATA* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* pHeadAutoBreadcrumbNode{ nullptr };
};

struct Decoded_D3D12_DRED_ALLOCATION_NODE
{
    using struct_type = D3D12_DRED_ALLOCATION_NODE;

    D3D12_DRED_ALLOCATION_NODE* decoded_value{ nullptr };

    StringDecoder ObjectNameA;
    WStringDecoder ObjectNameW;
    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>* pNext{ nullptr };
};

struct Decoded_D3D12_DRED_ALLOCATION_NODE1
{
    using struct_type = D3D12_DRED_ALLOCATION_NODE1;

    D3D12_DRED_ALLOCATION_NODE1* decoded_value{ nullptr };

    StringDecoder ObjectNameA;
    WStringDecoder ObjectNameW;
    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* pNext{ nullptr };
    format::HandleId pObject{ format::kNullHandleId };
};

struct Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT
{
    using struct_type = D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT;

    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE>* pHeadAutoBreadcrumbNode{ nullptr };
};

struct Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1
{
    using struct_type = D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1;

    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_AUTO_BREADCRUMB_NODE1>* pHeadAutoBreadcrumbNode{ nullptr };
};

struct Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT
{
    using struct_type = D3D12_DRED_PAGE_FAULT_OUTPUT;

    D3D12_DRED_PAGE_FAULT_OUTPUT* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>* pHeadExistingAllocationNode{ nullptr };
    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE>* pHeadRecentFreedAllocationNode{ nullptr };
};

struct Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1
{
    using struct_type = D3D12_DRED_PAGE_FAULT_OUTPUT1;

    D3D12_DRED_PAGE_FAULT_OUTPUT1* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* pHeadExistingAllocationNode{ nullptr };
    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* pHeadRecentFreedAllocationNode{ nullptr };
};

struct Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2
{
    using struct_type = D3D12_DRED_PAGE_FAULT_OUTPUT2;

    D3D12_DRED_PAGE_FAULT_OUTPUT2* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* pHeadExistingAllocationNode{ nullptr };
    StructPointerDecoder<Decoded_D3D12_DRED_ALLOCATION_NODE1>* pHeadRecentFreedAllocationNode{ nullptr };
};

struct Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1
{
    using struct_type = D3D12_DEVICE_REMOVED_EXTENDED_DATA1;

    D3D12_DEVICE_REMOVED_EXTENDED_DATA1* decoded_value{ nullptr };

    Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* AutoBreadcrumbsOutput{ nullptr };
    Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* PageFaultOutput{ nullptr };
};

struct Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2
{
    using struct_type = D3D12_DEVICE_REMOVED_EXTENDED_DATA2;

    D3D12_DEVICE_REMOVED_EXTENDED_DATA2* decoded_value{ nullptr };

    Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* AutoBreadcrumbsOutput{ nullptr };
    Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* PageFaultOutput{ nullptr };
};

struct Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3
{
    using struct_type = D3D12_DEVICE_REMOVED_EXTENDED_DATA3;

    D3D12_DEVICE_REMOVED_EXTENDED_DATA3* decoded_value{ nullptr };

    Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* AutoBreadcrumbsOutput{ nullptr };
    Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* PageFaultOutput{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT
{
    using struct_type = D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT;

    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* decoded_value{ nullptr };
};

struct Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES
{
    using struct_type = D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES;

    D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_GUID>* pTypes{ nullptr };
};

struct Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1
{
    using struct_type = D3D12_PROTECTED_RESOURCE_SESSION_DESC1;

    D3D12_PROTECTED_RESOURCE_SESSION_DESC1* decoded_value{ nullptr };

    Decoded_GUID* ProtectionType{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS
{
    using struct_type = D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS;

    D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* decoded_value{ nullptr };

    Decoded_D3D12_CLEAR_VALUE* ClearValue{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS
{
    using struct_type = D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS;

    D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* decoded_value{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS
{
    using struct_type = D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS;

    D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* decoded_value{ nullptr };

    Decoded_tagRECT* SrcRect{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS
{
    using struct_type = D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS;

    D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* decoded_value{ nullptr };

    format::HandleId pSrcResource{ format::kNullHandleId };
    format::HandleId pDstResource{ format::kNullHandleId };
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS>* pSubresourceParameters{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS
{
    using struct_type = D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS;

    D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* decoded_value{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC
{
    using struct_type = D3D12_RENDER_PASS_RENDER_TARGET_DESC;

    D3D12_RENDER_PASS_RENDER_TARGET_DESC* decoded_value{ nullptr };

    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* cpuDescriptor{ nullptr };
    Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* BeginningAccess{ nullptr };
    Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* EndingAccess{ nullptr };
};

struct Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC
{
    using struct_type = D3D12_RENDER_PASS_DEPTH_STENCIL_DESC;

    D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* decoded_value{ nullptr };

    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* cpuDescriptor{ nullptr };
    Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* DepthBeginningAccess{ nullptr };
    Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* StencilBeginningAccess{ nullptr };
    Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* DepthEndingAccess{ nullptr };
    Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* StencilEndingAccess{ nullptr };
};

struct Decoded_D3D12_DISPATCH_RAYS_DESC
{
    using struct_type = D3D12_DISPATCH_RAYS_DESC;

    D3D12_DISPATCH_RAYS_DESC* decoded_value{ nullptr };

    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* RayGenerationShaderRecord{ nullptr };
    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* MissShaderTable{ nullptr };
    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* HitGroupTable{ nullptr };
    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* CallableShaderTable{ nullptr };
};

struct Decoded_D3D12_SET_WORK_GRAPH_DESC
{
    using struct_type = D3D12_SET_WORK_GRAPH_DESC;

    D3D12_SET_WORK_GRAPH_DESC* decoded_value{ nullptr };

    Decoded_D3D12_PROGRAM_IDENTIFIER* ProgramIdentifier{ nullptr };
    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* BackingMemory{ nullptr };
    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* NodeLocalRootArgumentsTable{ nullptr };
};

struct Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC
{
    using struct_type = D3D12_SET_RAYTRACING_PIPELINE_DESC;

    D3D12_SET_RAYTRACING_PIPELINE_DESC* decoded_value{ nullptr };

    Decoded_D3D12_PROGRAM_IDENTIFIER* ProgramIdentifier{ nullptr };
};

struct Decoded_D3D12_SET_GENERIC_PIPELINE_DESC
{
    using struct_type = D3D12_SET_GENERIC_PIPELINE_DESC;

    D3D12_SET_GENERIC_PIPELINE_DESC* decoded_value{ nullptr };

    Decoded_D3D12_PROGRAM_IDENTIFIER* ProgramIdentifier{ nullptr };
};

struct Decoded_D3D12_NODE_CPU_INPUT
{
    using struct_type = D3D12_NODE_CPU_INPUT;

    D3D12_NODE_CPU_INPUT* decoded_value{ nullptr };

    uint64_t pRecords{ 0 };
};

struct Decoded_D3D12_NODE_GPU_INPUT
{
    using struct_type = D3D12_NODE_GPU_INPUT;

    D3D12_NODE_GPU_INPUT* decoded_value{ nullptr };

    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* Records{ nullptr };
};

struct Decoded_D3D12_MULTI_NODE_CPU_INPUT
{
    using struct_type = D3D12_MULTI_NODE_CPU_INPUT;

    D3D12_MULTI_NODE_CPU_INPUT* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D12_NODE_CPU_INPUT>* pNodeInputs{ nullptr };
};

struct Decoded_D3D12_MULTI_NODE_GPU_INPUT
{
    using struct_type = D3D12_MULTI_NODE_GPU_INPUT;

    D3D12_MULTI_NODE_GPU_INPUT* decoded_value{ nullptr };

    Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* NodeInputs{ nullptr };
};

struct Decoded_D3D12_SHADER_CACHE_SESSION_DESC
{
    using struct_type = D3D12_SHADER_CACHE_SESSION_DESC;

    D3D12_SHADER_CACHE_SESSION_DESC* decoded_value{ nullptr };

    Decoded_GUID* Identifier{ nullptr };
};

struct Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE
{
    using struct_type = D3D12_BARRIER_SUBRESOURCE_RANGE;

    D3D12_BARRIER_SUBRESOURCE_RANGE* decoded_value{ nullptr };
};

struct Decoded_D3D12_GLOBAL_BARRIER
{
    using struct_type = D3D12_GLOBAL_BARRIER;

    D3D12_GLOBAL_BARRIER* decoded_value{ nullptr };
};

struct Decoded_D3D12_TEXTURE_BARRIER
{
    using struct_type = D3D12_TEXTURE_BARRIER;

    D3D12_TEXTURE_BARRIER* decoded_value{ nullptr };

    format::HandleId pResource{ format::kNullHandleId };
    Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* Subresources{ nullptr };
};

struct Decoded_D3D12_BUFFER_BARRIER
{
    using struct_type = D3D12_BUFFER_BARRIER;

    D3D12_BUFFER_BARRIER* decoded_value{ nullptr };

    format::HandleId pResource{ format::kNullHandleId };
};

struct Decoded_D3D12_SUBRESOURCE_DATA
{
    using struct_type = D3D12_SUBRESOURCE_DATA;

    D3D12_SUBRESOURCE_DATA* decoded_value{ nullptr };

    uint64_t pData{ 0 };
};

struct Decoded_D3D12_MEMCPY_DEST
{
    using struct_type = D3D12_MEMCPY_DEST;

    D3D12_MEMCPY_DEST* decoded_value{ nullptr };

    uint64_t pData{ 0 };
};

struct Decoded_D3D12_DEVICE_CONFIGURATION_DESC
{
    using struct_type = D3D12_DEVICE_CONFIGURATION_DESC;

    D3D12_DEVICE_CONFIGURATION_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D12_DISPATCH_MESH_ARGUMENTS
{
    using struct_type = D3D12_DISPATCH_MESH_ARGUMENTS;

    D3D12_DISPATCH_MESH_ARGUMENTS* decoded_value{ nullptr };
};

struct Decoded_D3D_SHADER_MACRO
{
    using struct_type = D3D_SHADER_MACRO;

    D3D_SHADER_MACRO* decoded_value{ nullptr };

    StringDecoder Name;
    StringDecoder Definition;
};

struct Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS
{
    using struct_type = D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS;

    D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR
{
    using struct_type = D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR;

    D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* decoded_value{ nullptr };
};

struct Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS
{
    using struct_type = D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS;

    D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* decoded_value{ nullptr };
};

struct Decoded_D3D12_MESSAGE
{
    using struct_type = D3D12_MESSAGE;

    D3D12_MESSAGE* decoded_value{ nullptr };

    StringDecoder pDescription;
};

struct Decoded_D3D12_INFO_QUEUE_FILTER_DESC
{
    using struct_type = D3D12_INFO_QUEUE_FILTER_DESC;

    D3D12_INFO_QUEUE_FILTER_DESC* decoded_value{ nullptr };

    PointerDecoder<D3D12_MESSAGE_CATEGORY> pCategoryList;
    PointerDecoder<D3D12_MESSAGE_SEVERITY> pSeverityList;
    PointerDecoder<D3D12_MESSAGE_ID> pIDList;
};

struct Decoded_D3D12_INFO_QUEUE_FILTER
{
    using struct_type = D3D12_INFO_QUEUE_FILTER;

    D3D12_INFO_QUEUE_FILTER* decoded_value{ nullptr };

    Decoded_D3D12_INFO_QUEUE_FILTER_DESC* AllowList{ nullptr };
    Decoded_D3D12_INFO_QUEUE_FILTER_DESC* DenyList{ nullptr };
};

struct Decoded_D3D11_INPUT_ELEMENT_DESC
{
    using struct_type = D3D11_INPUT_ELEMENT_DESC;

    D3D11_INPUT_ELEMENT_DESC* decoded_value{ nullptr };

    StringDecoder SemanticName;
};

struct Decoded_D3D11_SO_DECLARATION_ENTRY
{
    using struct_type = D3D11_SO_DECLARATION_ENTRY;

    D3D11_SO_DECLARATION_ENTRY* decoded_value{ nullptr };

    StringDecoder SemanticName;
};

struct Decoded_D3D11_VIEWPORT
{
    using struct_type = D3D11_VIEWPORT;

    D3D11_VIEWPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_DRAW_INSTANCED_INDIRECT_ARGS
{
    using struct_type = D3D11_DRAW_INSTANCED_INDIRECT_ARGS;

    D3D11_DRAW_INSTANCED_INDIRECT_ARGS* decoded_value{ nullptr };
};

struct Decoded_D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS
{
    using struct_type = D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS;

    D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS* decoded_value{ nullptr };
};

struct Decoded_D3D11_BOX
{
    using struct_type = D3D11_BOX;

    D3D11_BOX* decoded_value{ nullptr };
};

struct Decoded_D3D11_DEPTH_STENCILOP_DESC
{
    using struct_type = D3D11_DEPTH_STENCILOP_DESC;

    D3D11_DEPTH_STENCILOP_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_DEPTH_STENCIL_DESC
{
    using struct_type = D3D11_DEPTH_STENCIL_DESC;

    D3D11_DEPTH_STENCIL_DESC* decoded_value{ nullptr };

    Decoded_D3D11_DEPTH_STENCILOP_DESC* FrontFace{ nullptr };
    Decoded_D3D11_DEPTH_STENCILOP_DESC* BackFace{ nullptr };
};

struct Decoded_D3D11_RENDER_TARGET_BLEND_DESC
{
    using struct_type = D3D11_RENDER_TARGET_BLEND_DESC;

    D3D11_RENDER_TARGET_BLEND_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_BLEND_DESC
{
    using struct_type = D3D11_BLEND_DESC;

    D3D11_BLEND_DESC* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_BLEND_DESC>* RenderTarget{ nullptr };
};

struct Decoded_D3D11_RASTERIZER_DESC
{
    using struct_type = D3D11_RASTERIZER_DESC;

    D3D11_RASTERIZER_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_MAPPED_SUBRESOURCE
{
    using struct_type = D3D11_MAPPED_SUBRESOURCE;

    D3D11_MAPPED_SUBRESOURCE* decoded_value{ nullptr };

    uint64_t pData{ 0 };
};

struct Decoded_D3D11_BUFFER_DESC
{
    using struct_type = D3D11_BUFFER_DESC;

    D3D11_BUFFER_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEXTURE1D_DESC
{
    using struct_type = D3D11_TEXTURE1D_DESC;

    D3D11_TEXTURE1D_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEXTURE2D_DESC
{
    using struct_type = D3D11_TEXTURE2D_DESC;

    D3D11_TEXTURE2D_DESC* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
};

struct Decoded_D3D11_TEXTURE3D_DESC
{
    using struct_type = D3D11_TEXTURE3D_DESC;

    D3D11_TEXTURE3D_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_BUFFEREX_SRV
{
    using struct_type = D3D11_BUFFEREX_SRV;

    D3D11_BUFFEREX_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_SRV
{
    using struct_type = D3D11_TEX1D_SRV;

    D3D11_TEX1D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_ARRAY_SRV
{
    using struct_type = D3D11_TEX1D_ARRAY_SRV;

    D3D11_TEX1D_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_SRV
{
    using struct_type = D3D11_TEX2D_SRV;

    D3D11_TEX2D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_SRV
{
    using struct_type = D3D11_TEX2D_ARRAY_SRV;

    D3D11_TEX2D_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX3D_SRV
{
    using struct_type = D3D11_TEX3D_SRV;

    D3D11_TEX3D_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEXCUBE_SRV
{
    using struct_type = D3D11_TEXCUBE_SRV;

    D3D11_TEXCUBE_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEXCUBE_ARRAY_SRV
{
    using struct_type = D3D11_TEXCUBE_ARRAY_SRV;

    D3D11_TEXCUBE_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_SRV
{
    using struct_type = D3D11_TEX2DMS_SRV;

    D3D11_TEX2DMS_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_ARRAY_SRV
{
    using struct_type = D3D11_TEX2DMS_ARRAY_SRV;

    D3D11_TEX2DMS_ARRAY_SRV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_RTV
{
    using struct_type = D3D11_TEX1D_RTV;

    D3D11_TEX1D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_ARRAY_RTV
{
    using struct_type = D3D11_TEX1D_ARRAY_RTV;

    D3D11_TEX1D_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_RTV
{
    using struct_type = D3D11_TEX2D_RTV;

    D3D11_TEX2D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_RTV
{
    using struct_type = D3D11_TEX2DMS_RTV;

    D3D11_TEX2DMS_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_RTV
{
    using struct_type = D3D11_TEX2D_ARRAY_RTV;

    D3D11_TEX2D_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_ARRAY_RTV
{
    using struct_type = D3D11_TEX2DMS_ARRAY_RTV;

    D3D11_TEX2DMS_ARRAY_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX3D_RTV
{
    using struct_type = D3D11_TEX3D_RTV;

    D3D11_TEX3D_RTV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_DSV
{
    using struct_type = D3D11_TEX1D_DSV;

    D3D11_TEX1D_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_ARRAY_DSV
{
    using struct_type = D3D11_TEX1D_ARRAY_DSV;

    D3D11_TEX1D_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_DSV
{
    using struct_type = D3D11_TEX2D_DSV;

    D3D11_TEX2D_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_DSV
{
    using struct_type = D3D11_TEX2D_ARRAY_DSV;

    D3D11_TEX2D_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_DSV
{
    using struct_type = D3D11_TEX2DMS_DSV;

    D3D11_TEX2DMS_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2DMS_ARRAY_DSV
{
    using struct_type = D3D11_TEX2DMS_ARRAY_DSV;

    D3D11_TEX2DMS_ARRAY_DSV* decoded_value{ nullptr };
};

struct Decoded_D3D11_BUFFER_UAV
{
    using struct_type = D3D11_BUFFER_UAV;

    D3D11_BUFFER_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_UAV
{
    using struct_type = D3D11_TEX1D_UAV;

    D3D11_TEX1D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX1D_ARRAY_UAV
{
    using struct_type = D3D11_TEX1D_ARRAY_UAV;

    D3D11_TEX1D_ARRAY_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_UAV
{
    using struct_type = D3D11_TEX2D_UAV;

    D3D11_TEX2D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_UAV
{
    using struct_type = D3D11_TEX2D_ARRAY_UAV;

    D3D11_TEX2D_ARRAY_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX3D_UAV
{
    using struct_type = D3D11_TEX3D_UAV;

    D3D11_TEX3D_UAV* decoded_value{ nullptr };
};

struct Decoded_D3D11_SAMPLER_DESC
{
    using struct_type = D3D11_SAMPLER_DESC;

    D3D11_SAMPLER_DESC* decoded_value{ nullptr };

    PointerDecoder<FLOAT> BorderColor;
};

struct Decoded_D3D11_QUERY_DESC
{
    using struct_type = D3D11_QUERY_DESC;

    D3D11_QUERY_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_QUERY_DATA_TIMESTAMP_DISJOINT
{
    using struct_type = D3D11_QUERY_DATA_TIMESTAMP_DISJOINT;

    D3D11_QUERY_DATA_TIMESTAMP_DISJOINT* decoded_value{ nullptr };
};

struct Decoded_D3D11_QUERY_DATA_PIPELINE_STATISTICS
{
    using struct_type = D3D11_QUERY_DATA_PIPELINE_STATISTICS;

    D3D11_QUERY_DATA_PIPELINE_STATISTICS* decoded_value{ nullptr };
};

struct Decoded_D3D11_QUERY_DATA_SO_STATISTICS
{
    using struct_type = D3D11_QUERY_DATA_SO_STATISTICS;

    D3D11_QUERY_DATA_SO_STATISTICS* decoded_value{ nullptr };
};

struct Decoded_D3D11_COUNTER_DESC
{
    using struct_type = D3D11_COUNTER_DESC;

    D3D11_COUNTER_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_COUNTER_INFO
{
    using struct_type = D3D11_COUNTER_INFO;

    D3D11_COUNTER_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D11_CLASS_INSTANCE_DESC
{
    using struct_type = D3D11_CLASS_INSTANCE_DESC;

    D3D11_CLASS_INSTANCE_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_THREADING
{
    using struct_type = D3D11_FEATURE_DATA_THREADING;

    D3D11_FEATURE_DATA_THREADING* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_DOUBLES
{
    using struct_type = D3D11_FEATURE_DATA_DOUBLES;

    D3D11_FEATURE_DATA_DOUBLES* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_FORMAT_SUPPORT;

    D3D11_FEATURE_DATA_FORMAT_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT2
{
    using struct_type = D3D11_FEATURE_DATA_FORMAT_SUPPORT2;

    D3D11_FEATURE_DATA_FORMAT_SUPPORT2* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS
{
    using struct_type = D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS;

    D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS;

    D3D11_FEATURE_DATA_D3D11_OPTIONS* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_ARCHITECTURE_INFO
{
    using struct_type = D3D11_FEATURE_DATA_ARCHITECTURE_INFO;

    D3D11_FEATURE_DATA_ARCHITECTURE_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS
{
    using struct_type = D3D11_FEATURE_DATA_D3D9_OPTIONS;

    D3D11_FEATURE_DATA_D3D9_OPTIONS* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT;

    D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT;

    D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS1
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS1;

    D3D11_FEATURE_DATA_D3D11_OPTIONS1* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT;

    D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_MARKER_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_MARKER_SUPPORT;

    D3D11_FEATURE_DATA_MARKER_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS1
{
    using struct_type = D3D11_FEATURE_DATA_D3D9_OPTIONS1;

    D3D11_FEATURE_DATA_D3D9_OPTIONS1* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS2
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS2;

    D3D11_FEATURE_DATA_D3D11_OPTIONS2* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS3
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS3;

    D3D11_FEATURE_DATA_D3D11_OPTIONS3* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT
{
    using struct_type = D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT;

    D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_SHADER_CACHE
{
    using struct_type = D3D11_FEATURE_DATA_SHADER_CACHE;

    D3D11_FEATURE_DATA_SHADER_CACHE* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS5
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS5;

    D3D11_FEATURE_DATA_D3D11_OPTIONS5* decoded_value{ nullptr };
};

struct Decoded_CD3D11_VIDEO_DEFAULT
{
    using struct_type = CD3D11_VIDEO_DEFAULT;

    CD3D11_VIDEO_DEFAULT* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_DESC
{
    using struct_type = D3D11_VIDEO_DECODER_DESC;

    D3D11_VIDEO_DECODER_DESC* decoded_value{ nullptr };

    Decoded_GUID* Guid{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_CONFIG
{
    using struct_type = D3D11_VIDEO_DECODER_CONFIG;

    D3D11_VIDEO_DECODER_CONFIG* decoded_value{ nullptr };

    Decoded_GUID* guidConfigBitstreamEncryption{ nullptr };
    Decoded_GUID* guidConfigMBcontrolEncryption{ nullptr };
    Decoded_GUID* guidConfigResidDiffEncryption{ nullptr };
};

struct Decoded_D3D11_AES_CTR_IV
{
    using struct_type = D3D11_AES_CTR_IV;

    D3D11_AES_CTR_IV* decoded_value{ nullptr };
};

struct Decoded_D3D11_ENCRYPTED_BLOCK_INFO
{
    using struct_type = D3D11_ENCRYPTED_BLOCK_INFO;

    D3D11_ENCRYPTED_BLOCK_INFO* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC
{
    using struct_type = D3D11_VIDEO_DECODER_BUFFER_DESC;

    D3D11_VIDEO_DECODER_BUFFER_DESC* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pIV;
    Decoded_D3D11_ENCRYPTED_BLOCK_INFO* EncryptedBlockInfo{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_EXTENSION
{
    using struct_type = D3D11_VIDEO_DECODER_EXTENSION;

    D3D11_VIDEO_DECODER_EXTENSION* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pPrivateInputData;
    PointerDecoder<uint8_t> pPrivateOutputData;
    HandlePointerDecoder<ID3D11Resource*> ppResourceList;
};

struct Decoded_D3D11_VIDEO_PROCESSOR_CAPS
{
    using struct_type = D3D11_VIDEO_PROCESSOR_CAPS;

    D3D11_VIDEO_PROCESSOR_CAPS* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS
{
    using struct_type = D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS;

    D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_CONTENT_PROTECTION_CAPS
{
    using struct_type = D3D11_VIDEO_CONTENT_PROTECTION_CAPS;

    D3D11_VIDEO_CONTENT_PROTECTION_CAPS* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_CUSTOM_RATE
{
    using struct_type = D3D11_VIDEO_PROCESSOR_CUSTOM_RATE;

    D3D11_VIDEO_PROCESSOR_CUSTOM_RATE* decoded_value{ nullptr };

    Decoded_DXGI_RATIONAL* CustomRate{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_FILTER_RANGE
{
    using struct_type = D3D11_VIDEO_PROCESSOR_FILTER_RANGE;

    D3D11_VIDEO_PROCESSOR_FILTER_RANGE* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC
{
    using struct_type = D3D11_VIDEO_PROCESSOR_CONTENT_DESC;

    D3D11_VIDEO_PROCESSOR_CONTENT_DESC* decoded_value{ nullptr };

    Decoded_DXGI_RATIONAL* InputFrameRate{ nullptr };
    Decoded_DXGI_RATIONAL* OutputFrameRate{ nullptr };
};

struct Decoded_D3D11_VIDEO_COLOR_RGBA
{
    using struct_type = D3D11_VIDEO_COLOR_RGBA;

    D3D11_VIDEO_COLOR_RGBA* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_COLOR_YCbCrA
{
    using struct_type = D3D11_VIDEO_COLOR_YCbCrA;

    D3D11_VIDEO_COLOR_YCbCrA* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE
{
    using struct_type = D3D11_VIDEO_PROCESSOR_COLOR_SPACE;

    D3D11_VIDEO_PROCESSOR_COLOR_SPACE* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_PROCESSOR_STREAM
{
    using struct_type = D3D11_VIDEO_PROCESSOR_STREAM;

    D3D11_VIDEO_PROCESSOR_STREAM* decoded_value{ nullptr };

    HandlePointerDecoder<ID3D11VideoProcessorInputView*> ppPastSurfaces;
    format::HandleId pInputSurface{ format::kNullHandleId };
    HandlePointerDecoder<ID3D11VideoProcessorInputView*> ppFutureSurfaces;
    HandlePointerDecoder<ID3D11VideoProcessorInputView*> ppPastSurfacesRight;
    format::HandleId pInputSurfaceRight{ format::kNullHandleId };
    HandlePointerDecoder<ID3D11VideoProcessorInputView*> ppFutureSurfacesRight;
};

struct Decoded_D3D11_OMAC
{
    using struct_type = D3D11_OMAC;

    D3D11_OMAC* decoded_value{ nullptr };

    PointerDecoder<BYTE> Omac;
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_INPUT;

    D3D11_AUTHENTICATED_QUERY_INPUT* decoded_value{ nullptr };

    Decoded_GUID* QueryType{ nullptr };
    uint64_t hChannel{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_OMAC* omac{ nullptr };
    Decoded_GUID* QueryType{ nullptr };
    uint64_t hChannel{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    Decoded_D3D11_AUTHENTICATED_PROTECTION_FLAGS* ProtectionFlags{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    uint64_t DeviceHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT;

    D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* Input{ nullptr };
    uint64_t DecoderHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    uint64_t DecoderHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
    uint64_t DeviceHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT;

    D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* Input{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    uint64_t ProcessHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT;

    D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* Input{ nullptr };
    uint64_t DeviceHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    uint64_t DeviceHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT;

    D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* Input{ nullptr };
    uint64_t DeviceHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    uint64_t DeviceHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT;

    D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* Input{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    Decoded_GUID* EncryptionGuid{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT;

    D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* Output{ nullptr };
    Decoded_GUID* EncryptionGuid{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_OMAC* omac{ nullptr };
    Decoded_GUID* ConfigureType{ nullptr };
    uint64_t hChannel{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_OUTPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_OUTPUT;

    D3D11_AUTHENTICATED_CONFIGURE_OUTPUT* decoded_value{ nullptr };

    Decoded_D3D11_OMAC* omac{ nullptr };
    Decoded_GUID* ConfigureType{ nullptr };
    uint64_t hChannel{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* Parameters{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* Parameters{ nullptr };
    Decoded_D3D11_AUTHENTICATED_PROTECTION_FLAGS* Protections{ nullptr };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* Parameters{ nullptr };
    uint64_t DecoderHandle{ 0 };
    uint64_t CryptoSessionHandle{ 0 };
    uint64_t DeviceHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* Parameters{ nullptr };
    uint64_t ProcessHandle{ 0 };
};

struct Decoded_D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT
{
    using struct_type = D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT;

    D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT* decoded_value{ nullptr };

    Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* Parameters{ nullptr };
    Decoded_GUID* EncryptionGuid{ nullptr };
};

struct Decoded_D3D11_TEX2D_VDOV
{
    using struct_type = D3D11_TEX2D_VDOV;

    D3D11_TEX2D_VDOV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_VPIV
{
    using struct_type = D3D11_TEX2D_VPIV;

    D3D11_TEX2D_VPIV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_VPOV
{
    using struct_type = D3D11_TEX2D_VPOV;

    D3D11_TEX2D_VPOV* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_VPOV
{
    using struct_type = D3D11_TEX2D_ARRAY_VPOV;

    D3D11_TEX2D_ARRAY_VPOV* decoded_value{ nullptr };
};

struct Decoded_D3D11_RENDER_TARGET_BLEND_DESC1
{
    using struct_type = D3D11_RENDER_TARGET_BLEND_DESC1;

    D3D11_RENDER_TARGET_BLEND_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D11_BLEND_DESC1
{
    using struct_type = D3D11_BLEND_DESC1;

    D3D11_BLEND_DESC1* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_BLEND_DESC1>* RenderTarget{ nullptr };
};

struct Decoded_D3D11_RASTERIZER_DESC1
{
    using struct_type = D3D11_RASTERIZER_DESC1;

    D3D11_RASTERIZER_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK
{
    using struct_type = D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK;

    D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK* decoded_value{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC1
{
    using struct_type = D3D11_VIDEO_DECODER_BUFFER_DESC1;

    D3D11_VIDEO_DECODER_BUFFER_DESC1* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pIV;
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK>* pSubSampleMappingBlock{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION
{
    using struct_type = D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION;

    D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* decoded_value{ nullptr };

    format::HandleId pCryptoSession{ format::kNullHandleId };
    PointerDecoder<uint8_t> pBlob;
    StructPointerDecoder<Decoded_GUID>* pKeyInfoId{ nullptr };
    PointerDecoder<uint8_t> pPrivateData;
};

struct Decoded_D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT
{
    using struct_type = D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT;

    D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT* decoded_value{ nullptr };
};

struct Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA
{
    using struct_type = D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA;

    D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA* decoded_value{ nullptr };

    PointerDecoder<BYTE> pbInput;
};

struct Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA
{
    using struct_type = D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA;

    D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA* decoded_value{ nullptr };

    PointerDecoder<BYTE> pbOutput;
};

struct Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA
{
    using struct_type = D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA;

    D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA>* pInputData{ nullptr };
    StructPointerDecoder<Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA>* pOutputData{ nullptr };
};

struct Decoded_D3D11_VIDEO_SAMPLE_DESC
{
    using struct_type = D3D11_VIDEO_SAMPLE_DESC;

    D3D11_VIDEO_SAMPLE_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_TILED_RESOURCE_COORDINATE
{
    using struct_type = D3D11_TILED_RESOURCE_COORDINATE;

    D3D11_TILED_RESOURCE_COORDINATE* decoded_value{ nullptr };
};

struct Decoded_D3D11_TILE_REGION_SIZE
{
    using struct_type = D3D11_TILE_REGION_SIZE;

    D3D11_TILE_REGION_SIZE* decoded_value{ nullptr };
};

struct Decoded_D3D11_SUBRESOURCE_TILING
{
    using struct_type = D3D11_SUBRESOURCE_TILING;

    D3D11_SUBRESOURCE_TILING* decoded_value{ nullptr };
};

struct Decoded_D3D11_TILE_SHAPE
{
    using struct_type = D3D11_TILE_SHAPE;

    D3D11_TILE_SHAPE* decoded_value{ nullptr };
};

struct Decoded_D3D11_PACKED_MIP_DESC
{
    using struct_type = D3D11_PACKED_MIP_DESC;

    D3D11_PACKED_MIP_DESC* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEXTURE2D_DESC1
{
    using struct_type = D3D11_TEXTURE2D_DESC1;

    D3D11_TEXTURE2D_DESC1* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
};

struct Decoded_D3D11_TEXTURE3D_DESC1
{
    using struct_type = D3D11_TEXTURE3D_DESC1;

    D3D11_TEXTURE3D_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D11_RASTERIZER_DESC2
{
    using struct_type = D3D11_RASTERIZER_DESC2;

    D3D11_RASTERIZER_DESC2* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_SRV1
{
    using struct_type = D3D11_TEX2D_SRV1;

    D3D11_TEX2D_SRV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_SRV1
{
    using struct_type = D3D11_TEX2D_ARRAY_SRV1;

    D3D11_TEX2D_ARRAY_SRV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_RTV1
{
    using struct_type = D3D11_TEX2D_RTV1;

    D3D11_TEX2D_RTV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_RTV1
{
    using struct_type = D3D11_TEX2D_ARRAY_RTV1;

    D3D11_TEX2D_ARRAY_RTV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_UAV1
{
    using struct_type = D3D11_TEX2D_UAV1;

    D3D11_TEX2D_UAV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_TEX2D_ARRAY_UAV1
{
    using struct_type = D3D11_TEX2D_ARRAY_UAV1;

    D3D11_TEX2D_ARRAY_UAV1* decoded_value{ nullptr };
};

struct Decoded_D3D11_QUERY_DESC1
{
    using struct_type = D3D11_QUERY_DESC1;

    D3D11_QUERY_DESC1* decoded_value{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM
{
    using struct_type = D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM;

    D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM* decoded_value{ nullptr };

    Decoded_D3D11_VIDEO_DECODER_DESC* DecoderDesc{ nullptr };
};

struct Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC2
{
    using struct_type = D3D11_VIDEO_DECODER_BUFFER_DESC2;

    D3D11_VIDEO_DECODER_BUFFER_DESC2* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pIV;
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK>* pSubSampleMappingBlock{ nullptr };
};

struct Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS4
{
    using struct_type = D3D11_FEATURE_DATA_D3D11_OPTIONS4;

    D3D11_FEATURE_DATA_D3D11_OPTIONS4* decoded_value{ nullptr };
};

struct Decoded_D3D11_RESOURCE_FLAGS
{
    using struct_type = D3D11_RESOURCE_FLAGS;

    D3D11_RESOURCE_FLAGS* decoded_value{ nullptr };
};

struct Decoded_DXGI_FRAME_STATISTICS
{
    using struct_type = DXGI_FRAME_STATISTICS;

    DXGI_FRAME_STATISTICS* decoded_value{ nullptr };

    Decoded_LARGE_INTEGER* SyncQPCTime{ nullptr };
    Decoded_LARGE_INTEGER* SyncGPUTime{ nullptr };
};

struct Decoded_DXGI_MAPPED_RECT
{
    using struct_type = DXGI_MAPPED_RECT;

    DXGI_MAPPED_RECT* decoded_value{ nullptr };

    PointerDecoder<BYTE> pBits;
};

struct Decoded_DXGI_ADAPTER_DESC
{
    using struct_type = DXGI_ADAPTER_DESC;

    DXGI_ADAPTER_DESC* decoded_value{ nullptr };

    WStringDecoder Description;
    Decoded_LUID* AdapterLuid{ nullptr };
};

struct Decoded_DXGI_OUTPUT_DESC
{
    using struct_type = DXGI_OUTPUT_DESC;

    DXGI_OUTPUT_DESC* decoded_value{ nullptr };

    WStringDecoder DeviceName;
    Decoded_tagRECT* DesktopCoordinates{ nullptr };
    uint64_t Monitor{ 0 };
};

struct Decoded_DXGI_SHARED_RESOURCE
{
    using struct_type = DXGI_SHARED_RESOURCE;

    DXGI_SHARED_RESOURCE* decoded_value{ nullptr };

    uint64_t Handle{ 0 };
};

struct Decoded_DXGI_SURFACE_DESC
{
    using struct_type = DXGI_SURFACE_DESC;

    DXGI_SURFACE_DESC* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
};

struct Decoded_DXGI_SWAP_CHAIN_DESC
{
    using struct_type = DXGI_SWAP_CHAIN_DESC;

    DXGI_SWAP_CHAIN_DESC* decoded_value{ nullptr };

    Decoded_DXGI_MODE_DESC* BufferDesc{ nullptr };
    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
    uint64_t OutputWindow{ 0 };
};

struct Decoded_DXGI_ADAPTER_DESC1
{
    using struct_type = DXGI_ADAPTER_DESC1;

    DXGI_ADAPTER_DESC1* decoded_value{ nullptr };

    WStringDecoder Description;
    Decoded_LUID* AdapterLuid{ nullptr };
};

struct Decoded_DXGI_DISPLAY_COLOR_SPACE
{
    using struct_type = DXGI_DISPLAY_COLOR_SPACE;

    DXGI_DISPLAY_COLOR_SPACE* decoded_value{ nullptr };

    PointerDecoder<FLOAT> PrimaryCoordinates;
    PointerDecoder<FLOAT> WhitePoints;
};

struct Decoded_DXGI_OUTDUPL_MOVE_RECT
{
    using struct_type = DXGI_OUTDUPL_MOVE_RECT;

    DXGI_OUTDUPL_MOVE_RECT* decoded_value{ nullptr };

    Decoded_tagPOINT* SourcePoint{ nullptr };
    Decoded_tagRECT* DestinationRect{ nullptr };
};

struct Decoded_DXGI_OUTDUPL_DESC
{
    using struct_type = DXGI_OUTDUPL_DESC;

    DXGI_OUTDUPL_DESC* decoded_value{ nullptr };

    Decoded_DXGI_MODE_DESC* ModeDesc{ nullptr };
};

struct Decoded_DXGI_OUTDUPL_POINTER_POSITION
{
    using struct_type = DXGI_OUTDUPL_POINTER_POSITION;

    DXGI_OUTDUPL_POINTER_POSITION* decoded_value{ nullptr };

    Decoded_tagPOINT* Position{ nullptr };
};

struct Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO
{
    using struct_type = DXGI_OUTDUPL_POINTER_SHAPE_INFO;

    DXGI_OUTDUPL_POINTER_SHAPE_INFO* decoded_value{ nullptr };

    Decoded_tagPOINT* HotSpot{ nullptr };
};

struct Decoded_DXGI_OUTDUPL_FRAME_INFO
{
    using struct_type = DXGI_OUTDUPL_FRAME_INFO;

    DXGI_OUTDUPL_FRAME_INFO* decoded_value{ nullptr };

    Decoded_LARGE_INTEGER* LastPresentTime{ nullptr };
    Decoded_LARGE_INTEGER* LastMouseUpdateTime{ nullptr };
    Decoded_DXGI_OUTDUPL_POINTER_POSITION* PointerPosition{ nullptr };
};

struct Decoded_DXGI_MODE_DESC1
{
    using struct_type = DXGI_MODE_DESC1;

    DXGI_MODE_DESC1* decoded_value{ nullptr };

    Decoded_DXGI_RATIONAL* RefreshRate{ nullptr };
};

struct Decoded_DXGI_SWAP_CHAIN_DESC1
{
    using struct_type = DXGI_SWAP_CHAIN_DESC1;

    DXGI_SWAP_CHAIN_DESC1* decoded_value{ nullptr };

    Decoded_DXGI_SAMPLE_DESC* SampleDesc{ nullptr };
};

struct Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC
{
    using struct_type = DXGI_SWAP_CHAIN_FULLSCREEN_DESC;

    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* decoded_value{ nullptr };

    Decoded_DXGI_RATIONAL* RefreshRate{ nullptr };
};

struct Decoded_DXGI_PRESENT_PARAMETERS
{
    using struct_type = DXGI_PRESENT_PARAMETERS;

    DXGI_PRESENT_PARAMETERS* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_tagRECT>* pDirtyRects{ nullptr };
    StructPointerDecoder<Decoded_tagRECT>* pScrollRect{ nullptr };
    StructPointerDecoder<Decoded_tagPOINT>* pScrollOffset{ nullptr };
};

struct Decoded_DXGI_ADAPTER_DESC2
{
    using struct_type = DXGI_ADAPTER_DESC2;

    DXGI_ADAPTER_DESC2* decoded_value{ nullptr };

    WStringDecoder Description;
    Decoded_LUID* AdapterLuid{ nullptr };
};

struct Decoded_DXGI_MATRIX_3X2_F
{
    using struct_type = DXGI_MATRIX_3X2_F;

    DXGI_MATRIX_3X2_F* decoded_value{ nullptr };
};

struct Decoded_DXGI_DECODE_SWAP_CHAIN_DESC
{
    using struct_type = DXGI_DECODE_SWAP_CHAIN_DESC;

    DXGI_DECODE_SWAP_CHAIN_DESC* decoded_value{ nullptr };
};

struct Decoded_DXGI_FRAME_STATISTICS_MEDIA
{
    using struct_type = DXGI_FRAME_STATISTICS_MEDIA;

    DXGI_FRAME_STATISTICS_MEDIA* decoded_value{ nullptr };

    Decoded_LARGE_INTEGER* SyncQPCTime{ nullptr };
    Decoded_LARGE_INTEGER* SyncGPUTime{ nullptr };
};

struct Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO
{
    using struct_type = DXGI_QUERY_VIDEO_MEMORY_INFO;

    DXGI_QUERY_VIDEO_MEMORY_INFO* decoded_value{ nullptr };
};

struct Decoded_DXGI_HDR_METADATA_HDR10
{
    using struct_type = DXGI_HDR_METADATA_HDR10;

    DXGI_HDR_METADATA_HDR10* decoded_value{ nullptr };

    PointerDecoder<UINT16> RedPrimary;
    PointerDecoder<UINT16> GreenPrimary;
    PointerDecoder<UINT16> BluePrimary;
    PointerDecoder<UINT16> WhitePoint;
};

struct Decoded_DXGI_HDR_METADATA_HDR10PLUS
{
    using struct_type = DXGI_HDR_METADATA_HDR10PLUS;

    DXGI_HDR_METADATA_HDR10PLUS* decoded_value{ nullptr };

    PointerDecoder<BYTE> Data;
};

struct Decoded_DXGI_ADAPTER_DESC3
{
    using struct_type = DXGI_ADAPTER_DESC3;

    DXGI_ADAPTER_DESC3* decoded_value{ nullptr };

    WStringDecoder Description;
    Decoded_LUID* AdapterLuid{ nullptr };
};

struct Decoded_DXGI_OUTPUT_DESC1
{
    using struct_type = DXGI_OUTPUT_DESC1;

    DXGI_OUTPUT_DESC1* decoded_value{ nullptr };

    WStringDecoder DeviceName;
    Decoded_tagRECT* DesktopCoordinates{ nullptr };
    uint64_t Monitor{ 0 };
    PointerDecoder<FLOAT> RedPrimary;
    PointerDecoder<FLOAT> GreenPrimary;
    PointerDecoder<FLOAT> BluePrimary;
    PointerDecoder<FLOAT> WhitePoint;
};

struct Decoded_DXGI_RATIONAL
{
    using struct_type = DXGI_RATIONAL;

    DXGI_RATIONAL* decoded_value{ nullptr };
};

struct Decoded_DXGI_SAMPLE_DESC
{
    using struct_type = DXGI_SAMPLE_DESC;

    DXGI_SAMPLE_DESC* decoded_value{ nullptr };
};

struct Decoded_DXGI_RGB
{
    using struct_type = DXGI_RGB;

    DXGI_RGB* decoded_value{ nullptr };
};

struct Decoded_D3DCOLORVALUE
{
    using struct_type = D3DCOLORVALUE;

    D3DCOLORVALUE* decoded_value{ nullptr };
};

struct Decoded_DXGI_GAMMA_CONTROL
{
    using struct_type = DXGI_GAMMA_CONTROL;

    DXGI_GAMMA_CONTROL* decoded_value{ nullptr };

    Decoded_DXGI_RGB* Scale{ nullptr };
    Decoded_DXGI_RGB* Offset{ nullptr };
    StructPointerDecoder<Decoded_DXGI_RGB>* GammaCurve{ nullptr };
};

struct Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES
{
    using struct_type = DXGI_GAMMA_CONTROL_CAPABILITIES;

    DXGI_GAMMA_CONTROL_CAPABILITIES* decoded_value{ nullptr };

    PointerDecoder<float> ControlPointPositions;
};

struct Decoded_DXGI_MODE_DESC
{
    using struct_type = DXGI_MODE_DESC;

    DXGI_MODE_DESC* decoded_value{ nullptr };

    Decoded_DXGI_RATIONAL* RefreshRate{ nullptr };
};

struct Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE
{
    using struct_type = DXGI_JPEG_DC_HUFFMAN_TABLE;

    DXGI_JPEG_DC_HUFFMAN_TABLE* decoded_value{ nullptr };

    PointerDecoder<BYTE> CodeCounts;
    PointerDecoder<BYTE> CodeValues;
};

struct Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE
{
    using struct_type = DXGI_JPEG_AC_HUFFMAN_TABLE;

    DXGI_JPEG_AC_HUFFMAN_TABLE* decoded_value{ nullptr };

    PointerDecoder<BYTE> CodeCounts;
    PointerDecoder<BYTE> CodeValues;
};

struct Decoded_DXGI_JPEG_QUANTIZATION_TABLE
{
    using struct_type = DXGI_JPEG_QUANTIZATION_TABLE;

    DXGI_JPEG_QUANTIZATION_TABLE* decoded_value{ nullptr };

    PointerDecoder<BYTE> Elements;
};

struct Decoded_GUID
{
    using struct_type = GUID;

    GUID* decoded_value{ nullptr };

    PointerDecoder<unsigned char> Data4;
};

struct Decoded_tagRECT
{
    using struct_type = tagRECT;

    tagRECT* decoded_value{ nullptr };
};

struct Decoded_tagPOINT
{
    using struct_type = tagPOINT;

    tagPOINT* decoded_value{ nullptr };
};

struct Decoded_tagSIZE
{
    using struct_type = tagSIZE;

    tagSIZE* decoded_value{ nullptr };
};

struct Decoded__SECURITY_ATTRIBUTES
{
    using struct_type = _SECURITY_ATTRIBUTES;

    _SECURITY_ATTRIBUTES* decoded_value{ nullptr };

    uint64_t lpSecurityDescriptor{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
