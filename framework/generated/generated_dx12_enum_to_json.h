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

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FORMAT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FORMAT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BLEND value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BLEND* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FEATURE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FEATURE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1 value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2 value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TIGHT_ALIGNMENT_TIER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TIGHT_ALIGNMENT_TIER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PROCESS_PRIORITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PROCESS_PRIORITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_STATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_STATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_POSTAMBLE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_POSTAMBLE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SERIALIZED_BLOCK_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_SERIALIZED_BLOCK_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MARKER_API value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MARKER_API* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_NAME value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_NAME* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SCALING value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SCALING* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FEATURE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_FEATURE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3 value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING* pEnum)
{
    to_json(jdata, *pEnum);
}

inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION value)
{
    to_json(jdata, gfxrecon::util::ToString(value));
}
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION* pEnum)
{
    to_json(jdata, *pEnum);
}


enum class D3D12_COMMAND_QUEUE_FLAGS_t : std::underlying_type<D3D12_COMMAND_QUEUE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_COMMAND_QUEUE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_PIPELINE_STATE_FLAGS_t : std::underlying_type<D3D12_PIPELINE_STATE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_PIPELINE_STATE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SHADER_MIN_PRECISION_SUPPORT_t : std::underlying_type<D3D12_SHADER_MIN_PRECISION_SUPPORT>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SHADER_MIN_PRECISION_SUPPORT(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_FORMAT_SUPPORT1_t : std::underlying_type<D3D12_FORMAT_SUPPORT1>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_FORMAT_SUPPORT1(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_FORMAT_SUPPORT2_t : std::underlying_type<D3D12_FORMAT_SUPPORT2>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_FORMAT_SUPPORT2(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS_t : std::underlying_type<D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SHADER_CACHE_SUPPORT_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_SUPPORT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SHADER_CACHE_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_COMMAND_LIST_SUPPORT_FLAGS_t : std::underlying_type<D3D12_COMMAND_LIST_SUPPORT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_COMMAND_LIST_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_HEAP_FLAGS_t : std::underlying_type<D3D12_HEAP_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_HEAP_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RESOURCE_FLAGS_t : std::underlying_type<D3D12_RESOURCE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RESOURCE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_TILE_RANGE_FLAGS_t : std::underlying_type<D3D12_TILE_RANGE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_TILE_RANGE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_TILE_MAPPING_FLAGS_t : std::underlying_type<D3D12_TILE_MAPPING_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_TILE_MAPPING_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_TILE_COPY_FLAGS_t : std::underlying_type<D3D12_TILE_COPY_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_TILE_COPY_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RESOURCE_STATES_t : std::underlying_type<D3D12_RESOURCE_STATES>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RESOURCE_STATES(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RESOURCE_BARRIER_FLAGS_t : std::underlying_type<D3D12_RESOURCE_BARRIER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RESOURCE_BARRIER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_VIEW_INSTANCING_FLAGS_t : std::underlying_type<D3D12_VIEW_INSTANCING_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_VIEW_INSTANCING_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_BUFFER_SRV_FLAGS_t : std::underlying_type<D3D12_BUFFER_SRV_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_BUFFER_SRV_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SAMPLER_FLAGS_t : std::underlying_type<D3D12_SAMPLER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SAMPLER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_BUFFER_UAV_FLAGS_t : std::underlying_type<D3D12_BUFFER_UAV_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_BUFFER_UAV_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DSV_FLAGS_t : std::underlying_type<D3D12_DSV_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DSV_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_CLEAR_FLAGS_t : std::underlying_type<D3D12_CLEAR_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_CLEAR_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_FENCE_FLAGS_t : std::underlying_type<D3D12_FENCE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_FENCE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DESCRIPTOR_HEAP_FLAGS_t : std::underlying_type<D3D12_DESCRIPTOR_HEAP_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DESCRIPTOR_HEAP_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_ROOT_SIGNATURE_FLAGS_t : std::underlying_type<D3D12_ROOT_SIGNATURE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_ROOT_SIGNATURE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DESCRIPTOR_RANGE_FLAGS_t : std::underlying_type<D3D12_DESCRIPTOR_RANGE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DESCRIPTOR_RANGE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_ROOT_DESCRIPTOR_FLAGS_t : std::underlying_type<D3D12_ROOT_DESCRIPTOR_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_ROOT_DESCRIPTOR_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_MULTIPLE_FENCE_WAIT_FLAGS_t : std::underlying_type<D3D12_MULTIPLE_FENCE_WAIT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RESIDENCY_FLAGS_t : std::underlying_type<D3D12_RESIDENCY_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RESIDENCY_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_COMMAND_LIST_FLAGS_t : std::underlying_type<D3D12_COMMAND_LIST_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_COMMAND_LIST_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_COMMAND_POOL_FLAGS_t : std::underlying_type<D3D12_COMMAND_POOL_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_COMMAND_POOL_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_COMMAND_RECORDER_FLAGS_t : std::underlying_type<D3D12_COMMAND_RECORDER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_COMMAND_RECORDER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_PROTECTED_SESSION_STATUS_t : std::underlying_type<D3D12_PROTECTED_SESSION_STATUS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_PROTECTED_SESSION_STATUS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS_t : std::underlying_type<D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t : std::underlying_type<D3D12_PROTECTED_RESOURCE_SESSION_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_META_COMMAND_PARAMETER_FLAGS_t : std::underlying_type<D3D12_META_COMMAND_PARAMETER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_META_COMMAND_PARAMETER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_GRAPHICS_STATES_t : std::underlying_type<D3D12_GRAPHICS_STATES>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_GRAPHICS_STATES(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_STATE_OBJECT_FLAGS_t : std::underlying_type<D3D12_STATE_OBJECT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_STATE_OBJECT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_EXPORT_FLAGS_t : std::underlying_type<D3D12_EXPORT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_EXPORT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RAYTRACING_PIPELINE_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_PIPELINE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RAYTRACING_PIPELINE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_WORK_GRAPH_FLAGS_t : std::underlying_type<D3D12_WORK_GRAPH_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_WORK_GRAPH_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RAYTRACING_GEOMETRY_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_GEOMETRY_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RAYTRACING_GEOMETRY_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RAYTRACING_INSTANCE_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_INSTANCE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RAYTRACING_INSTANCE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t : std::underlying_type<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS_t : std::underlying_type<D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RAY_FLAGS_t : std::underlying_type<D3D12_RAY_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RAY_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DRED_FLAGS_t : std::underlying_type<D3D12_DRED_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DRED_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DRED_PAGE_FAULT_FLAGS_t : std::underlying_type<D3D12_DRED_PAGE_FAULT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DRED_PAGE_FAULT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RENDER_PASS_FLAGS_t : std::underlying_type<D3D12_RENDER_PASS_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RENDER_PASS_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SET_WORK_GRAPH_FLAGS_t : std::underlying_type<D3D12_SET_WORK_GRAPH_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SET_WORK_GRAPH_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SHADER_CACHE_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SHADER_CACHE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_TEXTURE_BARRIER_FLAGS_t : std::underlying_type<D3D12_TEXTURE_BARRIER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_TEXTURE_BARRIER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SHADER_CACHE_KIND_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_KIND_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SHADER_CACHE_KIND_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_SHADER_CACHE_CONTROL_FLAGS_t : std::underlying_type<D3D12_SHADER_CACHE_CONTROL_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_SHADER_CACHE_CONTROL_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS_t : std::underlying_type<D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DEVICE_FACTORY_FLAGS_t : std::underlying_type<D3D12_DEVICE_FACTORY_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DEVICE_FACTORY_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_DEVICE_FLAGS_t : std::underlying_type<D3D12_DEVICE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_DEVICE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_STATE_OBJECT_DATABASE_FLAGS_t : std::underlying_type<D3D12_STATE_OBJECT_DATABASE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_DATABASE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_STATE_OBJECT_DATABASE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D_SHADER_VARIABLE_FLAGS_t : std::underlying_type<D3D_SHADER_VARIABLE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D_SHADER_VARIABLE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D_SHADER_INPUT_FLAGS_t : std::underlying_type<D3D_SHADER_INPUT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D_SHADER_INPUT_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D_SHADER_CBUFFER_FLAGS_t : std::underlying_type<D3D_SHADER_CBUFFER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D_SHADER_CBUFFER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D_PARAMETER_FLAGS_t : std::underlying_type<D3D_PARAMETER_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D_PARAMETER_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_GPU_BASED_VALIDATION_FLAGS_t : std::underlying_type<D3D12_GPU_BASED_VALIDATION_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_GPU_BASED_VALIDATION_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_RLDO_FLAGS_t : std::underlying_type<D3D12_RLDO_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_RLDO_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_t : std::underlying_type<D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class D3D12_MESSAGE_CALLBACK_FLAGS_t : std::underlying_type<D3D12_MESSAGE_CALLBACK_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_D3D12_MESSAGE_CALLBACK_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t : std::underlying_type<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class DXGI_OFFER_RESOURCE_FLAGS_t : std::underlying_type<DXGI_OFFER_RESOURCE_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_DXGI_OFFER_RESOURCE_FLAGS(static_cast<uint32_t>(flags));
    }
}
enum class DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS_t : std::underlying_type<DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS>::type {};
inline void to_json(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS_t flags)
{
    if (!gfxrecon::util::JsonOptions::expand_flags)
    {
        jdata = gfxrecon::util::to_hex_fixed_width(static_cast<uint32_t>(flags));
    }
    else
    {
        jdata = gfxrecon::util::ToString_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(static_cast<uint32_t>(flags));
    }
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
// IID struct-as-enum special case:
inline void FieldToJson(nlohmann::ordered_json& jdata, const IID& value)
{
    jdata = ToString(value);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
