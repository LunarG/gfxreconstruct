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

#if defined(D3D12_SUPPORT)

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

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* pObj, const util::JsonOptions& options);
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
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO* pObj, const util::JsonOptions& options);
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
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC* pObj, const util::JsonOptions& options);
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
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC* pObj, const util::JsonOptions& options);
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
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_INPUT_ELEMENT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SO_DECLARATION_ENTRY* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIEWPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DRAW_INSTANCED_INDIRECT_ARGS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BOX* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCILOP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCIL_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_BLEND_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BLEND_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SUBRESOURCE_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_MAPPED_SUBRESOURCE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE1D_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE2D_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE3D_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFEREX_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXCUBE_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXCUBE_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_SRV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_RTV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_DSV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCIL_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_UAV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SAMPLER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_TIMESTAMP_DISJOINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_PIPELINE_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_SO_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_COUNTER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_COUNTER_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_CLASS_INSTANCE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_THREADING* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_DOUBLES* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_ARCHITECTURE_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_MARKER_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS3* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_SHADER_CACHE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS5* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_CD3D11_VIDEO_DEFAULT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_CONFIG* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AES_CTR_IV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_ENCRYPTED_BLOCK_INFO* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_EXTENSION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CAPS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_CONTENT_PROTECTION_CAPS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CUSTOM_RATE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_FILTER_RANGE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR_RGBA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR_YCbCrA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_STREAM* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_OMAC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_OUTPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VDOV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VPIV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VPOV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_VPOV* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_BLEND_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BLEND_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_SAMPLE_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILED_RESOURCE_COORDINATE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILE_REGION_SIZE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SUBRESOURCE_TILING* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILE_SHAPE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_PACKED_MIP_DESC* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE2D_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE3D_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_SRV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_SRV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_RTV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_RTV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_VIEW_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_UAV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_UAV1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DESC1* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC2* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS4* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RESOURCE_FLAGS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* pObj, const util::JsonOptions& options);
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
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagSIZE* pObj, const util::JsonOptions& options);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* pObj, const util::JsonOptions& options);

// Reference versions of above which simply pipe through to the pointer versions.
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
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
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
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
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
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
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
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
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_INPUT_ELEMENT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SO_DECLARATION_ENTRY& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIEWPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DRAW_INSTANCED_INDIRECT_ARGS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BOX& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCILOP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCIL_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_BLEND_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BLEND_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SUBRESOURCE_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_MAPPED_SUBRESOURCE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE1D_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE2D_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE3D_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFEREX_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXCUBE_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXCUBE_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_SRV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_RTV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2DMS_ARRAY_DSV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_DEPTH_STENCIL_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BUFFER_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX1D_ARRAY_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX3D_UAV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SAMPLER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_TIMESTAMP_DISJOINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_PIPELINE_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DATA_SO_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_COUNTER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_COUNTER_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_CLASS_INSTANCE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_THREADING& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_DOUBLES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_FORMAT_SUPPORT2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_ARCHITECTURE_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_MARKER_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D9_OPTIONS1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS3& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_SHADER_CACHE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS5& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_CD3D11_VIDEO_DEFAULT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_CONFIG& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AES_CTR_IV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_ENCRYPTED_BLOCK_INFO& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_EXTENSION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CAPS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_CONTENT_PROTECTION_CAPS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CUSTOM_RATE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_FILTER_RANGE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR_RGBA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR_YCbCrA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_COLOR& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_STREAM& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_OMAC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_QUERY_CURRENT_ACCESSIBILITY_ENCRYPTION_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_OUTPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VDOV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VPIV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_VPOV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_VPOV& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_BLEND_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_BLEND_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_SAMPLE_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILED_RESOURCE_COORDINATE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILE_REGION_SIZE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SUBRESOURCE_TILING& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TILE_SHAPE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_PACKED_MIP_DESC& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE2D_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEXTURE3D_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RASTERIZER_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_SRV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_SRV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_RTV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_RTV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RENDER_TARGET_VIEW_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_UAV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_TEX2D_ARRAY_UAV1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_QUERY_DESC1& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_VIDEO_DECODER_HISTOGRAM& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC2& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_FEATURE_DATA_D3D11_OPTIONS4& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_RESOURCE_FLAGS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
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
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagSIZE& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }

// Custom, manually written implementations whose prototypes haven't been generated above:

/// <winnt.h> Named union type with two structs and a uint64_t inside.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* pObj, const util::JsonOptions& options);
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D11_AUTHENTICATED_PROTECTION_FLAGS* data, const util::JsonOptions& options);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
