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
** This file is generated from dx12_enum_to_json_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_ENUM_TO_JSON_H
#define  GFXRECON_GENERATED_DX12_ENUM_TO_JSON_H

#if defined(D3D12_SUPPORT)

/// @file Functions to convert enums to JSON. While trivial these do tidy up
/// the FieldToJsons of structs which use them and the JSON consumer too.
/// They also mean that generators don't need separate cases for enums.

#include "util/json_util.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "util/defines.h"
#include "util/to_string.h"
#include "format/platform_types.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FORMAT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FORMAT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1 value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2 value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TIGHT_ALIGNMENT_TIER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TIGHT_ALIGNMENT_TIER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PROCESS_PRIORITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PROCESS_PRIORITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_STATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_STATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_POSTAMBLE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_POSTAMBLE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SERIALIZED_BLOCK_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SERIALIZED_BLOCK_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MARKER_API value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MARKER_API* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_NAME value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_NAME* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SCALING value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SCALING* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FEATURE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FEATURE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3 value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING* pEnum)
{
    FieldToJson(jdata, *pEnum);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION value)
{
    FieldToJson(jdata, ToString(value));
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION* pEnum)
{
    FieldToJson(jdata, *pEnum);
}


enum class D3D12_COMMAND_QUEUE_FLAGS_t : std::underlying_type<D3D12_COMMAND_QUEUE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_COMMAND_QUEUE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_PIPELINE_STATE_FLAGS_t : std::underlying_type<D3D12_PIPELINE_STATE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_PIPELINE_STATE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SHADER_MIN_PRECISION_SUPPORT_t : std::underlying_type<D3D12_SHADER_MIN_PRECISION_SUPPORT>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SHADER_MIN_PRECISION_SUPPORT(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_FORMAT_SUPPORT1_t : std::underlying_type<D3D12_FORMAT_SUPPORT1>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_FORMAT_SUPPORT1(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_FORMAT_SUPPORT2_t : std::underlying_type<D3D12_FORMAT_SUPPORT2>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_FORMAT_SUPPORT2(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS_t : std::underlying_type<D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SHADER_CACHE_SUPPORT_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_SUPPORT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_COMMAND_LIST_SUPPORT_FLAGS_t : std::underlying_type<D3D12_COMMAND_LIST_SUPPORT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_COMMAND_LIST_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_HEAP_FLAGS_t : std::underlying_type<D3D12_HEAP_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_HEAP_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RESOURCE_FLAGS_t : std::underlying_type<D3D12_RESOURCE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_TILE_RANGE_FLAGS_t : std::underlying_type<D3D12_TILE_RANGE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_TILE_RANGE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_TILE_MAPPING_FLAGS_t : std::underlying_type<D3D12_TILE_MAPPING_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_TILE_MAPPING_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_TILE_COPY_FLAGS_t : std::underlying_type<D3D12_TILE_COPY_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_TILE_COPY_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RESOURCE_STATES_t : std::underlying_type<D3D12_RESOURCE_STATES>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_STATES(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RESOURCE_BARRIER_FLAGS_t : std::underlying_type<D3D12_RESOURCE_BARRIER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_BARRIER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_VIEW_INSTANCING_FLAGS_t : std::underlying_type<D3D12_VIEW_INSTANCING_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_VIEW_INSTANCING_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_BUFFER_SRV_FLAGS_t : std::underlying_type<D3D12_BUFFER_SRV_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_BUFFER_SRV_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SAMPLER_FLAGS_t : std::underlying_type<D3D12_SAMPLER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SAMPLER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_BUFFER_UAV_FLAGS_t : std::underlying_type<D3D12_BUFFER_UAV_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_BUFFER_UAV_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DSV_FLAGS_t : std::underlying_type<D3D12_DSV_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DSV_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_CLEAR_FLAGS_t : std::underlying_type<D3D12_CLEAR_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_CLEAR_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_FENCE_FLAGS_t : std::underlying_type<D3D12_FENCE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_FENCE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DESCRIPTOR_HEAP_FLAGS_t : std::underlying_type<D3D12_DESCRIPTOR_HEAP_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DESCRIPTOR_HEAP_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_ROOT_SIGNATURE_FLAGS_t : std::underlying_type<D3D12_ROOT_SIGNATURE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_ROOT_SIGNATURE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DESCRIPTOR_RANGE_FLAGS_t : std::underlying_type<D3D12_DESCRIPTOR_RANGE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DESCRIPTOR_RANGE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_ROOT_DESCRIPTOR_FLAGS_t : std::underlying_type<D3D12_ROOT_DESCRIPTOR_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_ROOT_DESCRIPTOR_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_MULTIPLE_FENCE_WAIT_FLAGS_t : std::underlying_type<D3D12_MULTIPLE_FENCE_WAIT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RESIDENCY_FLAGS_t : std::underlying_type<D3D12_RESIDENCY_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RESIDENCY_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_COMMAND_LIST_FLAGS_t : std::underlying_type<D3D12_COMMAND_LIST_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_COMMAND_LIST_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_COMMAND_POOL_FLAGS_t : std::underlying_type<D3D12_COMMAND_POOL_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_COMMAND_POOL_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_COMMAND_RECORDER_FLAGS_t : std::underlying_type<D3D12_COMMAND_RECORDER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_COMMAND_RECORDER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_PROTECTED_SESSION_STATUS_t : std::underlying_type<D3D12_PROTECTED_SESSION_STATUS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_SESSION_STATUS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS_t : std::underlying_type<D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t : std::underlying_type<D3D12_PROTECTED_RESOURCE_SESSION_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_META_COMMAND_PARAMETER_FLAGS_t : std::underlying_type<D3D12_META_COMMAND_PARAMETER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_META_COMMAND_PARAMETER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_GRAPHICS_STATES_t : std::underlying_type<D3D12_GRAPHICS_STATES>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_GRAPHICS_STATES(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_STATE_OBJECT_FLAGS_t : std::underlying_type<D3D12_STATE_OBJECT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_STATE_OBJECT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_EXPORT_FLAGS_t : std::underlying_type<D3D12_EXPORT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_EXPORT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RAYTRACING_PIPELINE_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_PIPELINE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_PIPELINE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_WORK_GRAPH_FLAGS_t : std::underlying_type<D3D12_WORK_GRAPH_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_WORK_GRAPH_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RAYTRACING_GEOMETRY_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_GEOMETRY_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_GEOMETRY_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RAYTRACING_INSTANCE_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_INSTANCE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_INSTANCE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS_t : std::underlying_type<D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RAY_FLAGS_t : std::underlying_type<D3D12_RAY_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RAY_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DRED_FLAGS_t : std::underlying_type<D3D12_DRED_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DRED_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DRED_PAGE_FAULT_FLAGS_t : std::underlying_type<D3D12_DRED_PAGE_FAULT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DRED_PAGE_FAULT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RENDER_PASS_FLAGS_t : std::underlying_type<D3D12_RENDER_PASS_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RENDER_PASS_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SET_WORK_GRAPH_FLAGS_t : std::underlying_type<D3D12_SET_WORK_GRAPH_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SET_WORK_GRAPH_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SHADER_CACHE_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_TEXTURE_BARRIER_FLAGS_t : std::underlying_type<D3D12_TEXTURE_BARRIER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_TEXTURE_BARRIER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SHADER_CACHE_KIND_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_KIND_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_KIND_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_SHADER_CACHE_CONTROL_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_CONTROL_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_CONTROL_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS_t : std::underlying_type<D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DEVICE_FACTORY_FLAGS_t : std::underlying_type<D3D12_DEVICE_FACTORY_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DEVICE_FACTORY_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_DEVICE_FLAGS_t : std::underlying_type<D3D12_DEVICE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_DEVICE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_STATE_OBJECT_DATABASE_FLAGS_t : std::underlying_type<D3D12_STATE_OBJECT_DATABASE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_STATE_OBJECT_DATABASE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D_SHADER_VARIABLE_FLAGS_t : std::underlying_type<D3D_SHADER_VARIABLE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D_SHADER_VARIABLE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D_SHADER_INPUT_FLAGS_t : std::underlying_type<D3D_SHADER_INPUT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D_SHADER_INPUT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D_SHADER_CBUFFER_FLAGS_t : std::underlying_type<D3D_SHADER_CBUFFER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D_SHADER_CBUFFER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D_PARAMETER_FLAGS_t : std::underlying_type<D3D_PARAMETER_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D_PARAMETER_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_GPU_BASED_VALIDATION_FLAGS_t : std::underlying_type<D3D12_GPU_BASED_VALIDATION_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_GPU_BASED_VALIDATION_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_RLDO_FLAGS_t : std::underlying_type<D3D12_RLDO_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_RLDO_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_t : std::underlying_type<D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class D3D12_MESSAGE_CALLBACK_FLAGS_t : std::underlying_type<D3D12_MESSAGE_CALLBACK_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_D3D12_MESSAGE_CALLBACK_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t : std::underlying_type<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class DXGI_OFFER_RESOURCE_FLAGS_t : std::underlying_type<DXGI_OFFER_RESOURCE_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_DXGI_OFFER_RESOURCE_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}
enum class DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS_t : std::underlying_type<DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS>::type {};
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS_t flags)
{
    std::string representation;
    if (!JsonOptions::expand_flags)
    {
        representation = to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        representation = ToString_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
    FieldToJson(jdata, representation);
}

// IID struct-as-enum special case:
inline void FieldToJson(nlohmann::ordered_json& jdata, const IID& value)
{
    FieldToJson(jdata, ToString(value));
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
