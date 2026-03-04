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
GFXRECON_BEGIN_NAMESPACE(decode)

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_ROOT_SIGNATURE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_SERIALIZED_ROOT_SIGNATURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_SERIALIZED_ROOT_SIGNATURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_TIGHT_ALIGNMENT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_SCHEDULING_QUEUE_GROUPINGS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SERIALIZED_BLOCK* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADERCACHE_ABI_SUPPORT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_APPLICATION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_BY_KEY_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT* pObj);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES* pObj);

// Reference versions of above which simply pipe through to the pointer versions.
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_QUEUE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_ELEMENT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SO_DECLARATION_ENTRY& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEWPORT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BOX& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LUID& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCILOP_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_DESC2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BLEND_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RASTERIZER_DESC2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_BYTECODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INPUT_LAYOUT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CACHED_PIPELINE_STATE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_ROOT_SIGNATURE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_SERIALIZED_ROOT_SIGNATURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_SERIALIZED_ROOT_SIGNATURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RT_FORMAT_ARRAY& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_DISPLAYABLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS8& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS9& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS10& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS11& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS12& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS13& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS14& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS15& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS16& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS17& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS18& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS19& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS20& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS21& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_TIGHT_ALIGNMENT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PREDICATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_COPY& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_APPLICATION_SPECIFIC_DRIVER_STATE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_BYTECODE_BYPASS_HASH_SUPPORTED& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_PROPERTIES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HEAP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PLACED_RESOURCE_SUPPORT_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MIP_REGION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VALUE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RANGE_UINT64& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILED_RESOURCE_COORDINATE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_REGION_SIZE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_TILING& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TILE_SHAPE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PACKED_MIP_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_UAV_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_POSITION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCE_LOCATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VIEW_INSTANCING_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXCUBE_ARRAY_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLER_DESC2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_UAV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX3D_RTV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_TARGET_VIEW_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX1D_ARRAY_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2D_ARRAY_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEX2DMS_ARRAY_DSV& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_CONSTANTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATIC_SAMPLER_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DESCRIPTOR_RANGE1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_DESCRIPTOR1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_PARAMETER1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_ROOT_SIGNATURE_DESC2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISCARD_REGION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_HEAP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_ARGUMENTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_ARGUMENTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERTEX_BUFFER_VIEW& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDEX_BUFFER_VIEW& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INDIRECT_ARGUMENT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMAND_SIGNATURE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_HARDWARE_SCHEDULING_QUEUE_GROUPINGS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_META_COMMAND_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROGRAM_IDENTIFIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_ID& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_CONFIG& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_MASK& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SAMPLE_MASK& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_IB_STRIP_CUT_VALUE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PRIMITIVE_TOPOLOGY_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEPTH_STENCIL_FORMAT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXPORT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_LIBRARY_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_HIT_GROUP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_OUTPUT_OVERRIDES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BROADCASTING_LAUNCH_OVERRIDES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COALESCING_LAUNCH_OVERRIDES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_THREAD_LAUNCH_OVERRIDES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_COMMON_COMPUTE_NODE_OVERRIDES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_NODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_WORK_GRAPH_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GENERIC_PROGRAM_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_OBJECT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_AABB& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_LINKAGE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_SERIALIZED_BLOCK& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_HISTOGRAM_ENTRY& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_ALLOCATION_NODE1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA3& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_RAYS_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_WORK_GRAPH_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_RAYTRACING_PIPELINE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_GENERIC_PIPELINE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SET_PROGRAM_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_CPU_INPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_NODE_GPU_INPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_CPU_INPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MULTI_NODE_GPU_INPUT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_GRAPH_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SHADER_CACHE_SESSION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_SUBRESOURCE_RANGE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_GLOBAL_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BUFFER_BARRIER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_FEATURE_DATA_SHADERCACHE_ABI_SUPPORT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_APPLICATION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_EXISTING_COLLECTION_BY_KEY_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_SUBRESOURCE_DATA& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MEMCPY_DEST& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEVICE_CONFIGURATION_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D_SHADER_MACRO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_MESSAGE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_INFO_QUEUE_FILTER& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MAPPED_RECT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SHARED_RESOURCE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SURFACE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DISPLAY_COLOR_SPACE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_MOVE_RECT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_POSITION& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTDUPL_FRAME_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_PRESENT_PARAMETERS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC2& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MATRIX_3X2_F& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_FRAME_STATISTICS_MEDIA& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_HDR_METADATA_HDR10PLUS& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_ADAPTER_DESC3& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_OUTPUT_DESC1& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RATIONAL& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_SAMPLE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_RGB& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3DCOLORVALUE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_MODE_DESC& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagRECT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_tagPOINT& obj){ FieldToJson(jdata, &obj); }
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded__SECURITY_ATTRIBUTES& obj){ FieldToJson(jdata, &obj); }

// Custom, manually written implementations whose prototypes haven't been generated above:

/// <winnt.h> Named union type with two structs and a uint64_t inside.
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* pObj);
inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER& obj){ FieldToJson(jdata, &obj); }

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
