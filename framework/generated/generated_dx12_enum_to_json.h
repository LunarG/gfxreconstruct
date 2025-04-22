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

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FORMAT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FORMAT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_QUEUE_PRIORITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PRIMITIVE_TOPOLOGY_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INPUT_CLASSIFICATION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILL_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CULL_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMPARISON_FUNC* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_WRITE_MASK* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STENCIL_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BLEND_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COLOR_WRITE_ENABLE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LOGIC_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LINE_RASTERIZATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STANDARD_MULTISAMPLE_QUALITY_LEVELS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FEATURE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_MIN_PRECISION_SUPPORT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILED_RESOURCES_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BINDING_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CONSERVATIVE_RASTERIZATION_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1 value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT1* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2 value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FORMAT_SUPPORT2* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CROSS_NODE_SHARING_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_HEAP_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPHS_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_ROOT_SIGNATURE_VERSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_MODEL* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_SUPPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_SUPPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_SERIALIZATION_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VARIABLE_SHADING_RATE_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESH_SHADER_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FEEDBACK_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WAVE_MMA_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TRI_STATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RECREATE_AT_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXECUTE_INDIRECT_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CPU_PAGE_PROPERTY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEMORY_POOL* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HEAP_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_LAYOUT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_RANGE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_MAPPING_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TILE_COPY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_STATES* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOLVE_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VIEW_INSTANCING_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_COMPONENT_MAPPING* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_SRV_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SRV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FILTER_REDUCTION_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_ADDRESS_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUFFER_UAV_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UAV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RTV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DSV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_FENCE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_HEAP_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_VISIBILITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_SIGNATURE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATIC_BORDER_COLOR* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DESCRIPTOR_RANGE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_DESCRIPTOR_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_HEAP_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_QUERY_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PREDICATION_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WRITEBUFFERIMMEDIATE_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MULTIPLE_FENCE_WAIT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_PRIORITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESIDENCY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_LIST_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_POOL_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_COMMAND_RECORDER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_SESSION_STATUS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_LIFETIME_STATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_META_COMMAND_PARAMETER_STAGE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GRAPHICS_STATES* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_SUBOBJECT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_EXPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_GROUP_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_PIPELINE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_OVERRIDES_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_NODE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_WORK_GRAPH_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_STATE_OBJECT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_INSTANCE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ELEMENTS_LAYOUT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SERIALIZED_DATA_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_HIT_KIND* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AUTO_BREADCRUMB_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_VERSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ENABLEMENT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_ALLOCATION_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_PAGE_FAULT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DRED_DEVICE_STATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BACKGROUND_PROCESSING_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MEASUREMENTS_ACTION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SET_WORK_GRAPH_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_PROGRAM_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DISPATCH_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_LAYOUT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_SYNC* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_ACCESS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_BARRIER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_KIND_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_CACHE_CONTROL_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FACTORY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEVICE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_AXIS_SHADING_RATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADING_RATE_COMBINER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_DRIVER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FEATURE_LEVEL* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE_TOPOLOGY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PRIMITIVE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SRV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INCLUDE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_CLASS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_VARIABLE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_INPUT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_SHADER_CBUFFER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_CBUFFER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_NAME value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_NAME* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_RESOURCE_RETURN_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_REGISTER_COMPONENT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_DOMAIN* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_PARTITIONING* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_TESSELLATOR_OUTPUT_PRIMITIVE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_MIN_PRECISION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_INTERPOLATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_PARAMETER_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_LAYOUT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_TYPE_LEVEL* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_NAME* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D_FORMAT_COMPONENT_INTERPRETATION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RLDO_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_PARAMETER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_FEATURE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_DEVICE_BYTECODE_VALIDATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CATEGORY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_SEVERITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_ID* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_MESSAGE_CALLBACK_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_INPUT_CLASSIFICATION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_INPUT_CLASSIFICATION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILL_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILL_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CULL_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CULL_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RESOURCE_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RESOURCE_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DSV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DSV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RTV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RTV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_UAV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_UAV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_USAGE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_USAGE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BIND_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BIND_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CPU_ACCESS_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CPU_ACCESS_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RESOURCE_MISC_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RESOURCE_MISC_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_MAP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_MAP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_MAP_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_MAP_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RAISE_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_RAISE_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CLEAR_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CLEAR_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COMPARISON_FUNC value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COMPARISON_FUNC* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DEPTH_WRITE_MASK value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DEPTH_WRITE_MASK* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_STENCIL_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_STENCIL_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BLEND value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BLEND* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BLEND_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BLEND_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COLOR_WRITE_ENABLE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COLOR_WRITE_ENABLE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURECUBE_FACE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURECUBE_FACE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUFFEREX_SRV_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUFFEREX_SRV_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DSV_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DSV_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUFFER_UAV_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUFFER_UAV_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER_REDUCTION_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FILTER_REDUCTION_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURE_ADDRESS_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURE_ADDRESS_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FORMAT_SUPPORT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FORMAT_SUPPORT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FORMAT_SUPPORT2 value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FORMAT_SUPPORT2* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_ASYNC_GETDATA_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_ASYNC_GETDATA_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_QUERY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_QUERY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_QUERY_MISC_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_QUERY_MISC_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COUNTER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COUNTER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COUNTER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COUNTER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_STANDARD_MULTISAMPLE_QUALITY_LEVELS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_STANDARD_MULTISAMPLE_QUALITY_LEVELS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DEVICE_CONTEXT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_DEVICE_CONTEXT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FEATURE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FEATURE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHADER_MIN_PRECISION_SUPPORT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHADER_MIN_PRECISION_SUPPORT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILED_RESOURCES_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILED_RESOURCES_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONSERVATIVE_RASTERIZATION_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONSERVATIVE_RASTERIZATION_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHADER_CACHE_SUPPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHADER_CACHE_SUPPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHARED_RESOURCE_TIER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_SHARED_RESOURCE_TIER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_BUFFER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_BUFFER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FORMAT_SUPPORT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FORMAT_SUPPORT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_DEVICE_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_DEVICE_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FEATURE_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FEATURE_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FILTER_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FILTER_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FORMAT_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FORMAT_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_AUTO_STREAM_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_AUTO_STREAM_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_PROCESSOR_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_PROCESSOR_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONTENT_PROTECTION_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONTENT_PROTECTION_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FILTER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_FILTER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_FRAME_FORMAT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_FRAME_FORMAT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_USAGE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_USAGE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_NOMINAL_RANGE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_NOMINAL_RANGE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_OUTPUT_RATE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_OUTPUT_RATE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_FORMAT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_FORMAT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ROTATION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_ROTATION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_AUTHENTICATED_CHANNEL_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_AUTHENTICATED_CHANNEL_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUS_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_BUS_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VDOV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VDOV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VPIV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VPIV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VPOV_DIMENSION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VPOV_DIMENSION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CREATE_DEVICE_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CREATE_DEVICE_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COPY_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_COPY_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_LOGIC_OP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_LOGIC_OP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_CAPS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_CAPS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_PROCESSOR_BEHAVIOR_HINTS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CRYPTO_SESSION_STATUS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CRYPTO_SESSION_STATUS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_MAPPING_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_MAPPING_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_RANGE_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_RANGE_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_COPY_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TILE_COPY_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONTEXT_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONTEXT_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURE_LAYOUT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_TEXTURE_LAYOUT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONSERVATIVE_RASTERIZATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CONSERVATIVE_RASTERIZATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FENCE_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FENCE_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FEATURE_VIDEO value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_FEATURE_VIDEO* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RESIDENCY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_EFFECT* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_POINTER_SHAPE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ALPHA_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_PRIORITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SCALING value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SCALING* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GRAPHICS_PREEMPTION_GRANULARITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COMPUTE_PREEMPTION_GRANULARITY* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FRAME_PRESENTATION_MODE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_SUPPORT_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MEMORY_SEGMENT_GROUP* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OUTDUPL_FLAG* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HDR_METADATA_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_OFFER_RESOURCE_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_RECLAIM_RESOURCE_RESULTS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FEATURE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_FEATURE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3 value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_ADAPTER_FLAG3* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_GPU_PREFERENCE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_COLOR_SPACE_TYPE* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCANLINE_ORDER* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_SCALING* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}

inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}
inline void FieldToJson(nlohmann::ordered_json& jdata, const DXGI_MODE_ROTATION* pEnum, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, *pEnum, options);
}


inline void FieldToJson_D3D12_COMMAND_QUEUE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_COMMAND_QUEUE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_PIPELINE_STATE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_PIPELINE_STATE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SHADER_MIN_PRECISION_SUPPORT(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SHADER_MIN_PRECISION_SUPPORT(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_FORMAT_SUPPORT1(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_FORMAT_SUPPORT1(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_FORMAT_SUPPORT2(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_FORMAT_SUPPORT2(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SHADER_CACHE_SUPPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_SUPPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_COMMAND_LIST_SUPPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_COMMAND_LIST_SUPPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_HEAP_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_HEAP_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RESOURCE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_TILE_RANGE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_TILE_RANGE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_TILE_MAPPING_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_TILE_MAPPING_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_TILE_COPY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_TILE_COPY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RESOURCE_STATES(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_STATES(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RESOURCE_BARRIER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RESOURCE_BARRIER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_VIEW_INSTANCING_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_VIEW_INSTANCING_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_BUFFER_SRV_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_BUFFER_SRV_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SAMPLER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SAMPLER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_BUFFER_UAV_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_BUFFER_UAV_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DSV_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DSV_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_CLEAR_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_CLEAR_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_FENCE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_FENCE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DESCRIPTOR_HEAP_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DESCRIPTOR_HEAP_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_ROOT_SIGNATURE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_ROOT_SIGNATURE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DESCRIPTOR_RANGE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DESCRIPTOR_RANGE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_ROOT_DESCRIPTOR_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_ROOT_DESCRIPTOR_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RESIDENCY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RESIDENCY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_COMMAND_LIST_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_COMMAND_LIST_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_COMMAND_POOL_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_COMMAND_POOL_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_COMMAND_RECORDER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_COMMAND_RECORDER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_PROTECTED_SESSION_STATUS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_SESSION_STATUS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_META_COMMAND_PARAMETER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_META_COMMAND_PARAMETER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_GRAPHICS_STATES(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_GRAPHICS_STATES(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_STATE_OBJECT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_STATE_OBJECT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_EXPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_EXPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RAYTRACING_PIPELINE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_PIPELINE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_WORK_GRAPH_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_WORK_GRAPH_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RAYTRACING_GEOMETRY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_GEOMETRY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RAYTRACING_INSTANCE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_INSTANCE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RAY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RAY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DRED_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DRED_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DRED_PAGE_FAULT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DRED_PAGE_FAULT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RENDER_PASS_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RENDER_PASS_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SET_WORK_GRAPH_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SET_WORK_GRAPH_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SHADER_CACHE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_TEXTURE_BARRIER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_TEXTURE_BARRIER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SHADER_CACHE_KIND_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_KIND_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_SHADER_CACHE_CONTROL_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_SHADER_CACHE_CONTROL_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DEVICE_FACTORY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DEVICE_FACTORY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_DEVICE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_DEVICE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D_SHADER_VARIABLE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D_SHADER_VARIABLE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D_SHADER_INPUT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D_SHADER_INPUT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D_SHADER_CBUFFER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D_SHADER_CBUFFER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D_PARAMETER_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D_PARAMETER_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_GPU_BASED_VALIDATION_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_GPU_BASED_VALIDATION_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_RLDO_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_RLDO_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D12_MESSAGE_CALLBACK_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D12_MESSAGE_CALLBACK_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_FORMAT_SUPPORT(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_FORMAT_SUPPORT(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_FORMAT_SUPPORT2(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_FORMAT_SUPPORT2(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_SHADER_MIN_PRECISION_SUPPORT(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_SHADER_MIN_PRECISION_SUPPORT(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_SHADER_CACHE_SUPPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_SHADER_CACHE_SUPPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_COPY_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_COPY_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_CRYPTO_SESSION_STATUS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_CRYPTO_SESSION_STATUS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_DXGI_OFFER_RESOURCE_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_DXGI_OFFER_RESOURCE_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}
inline void FieldToJson_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
{
    std::string representation;
    if (!options.expand_flags)
    {
        representation = to_hex_fixed_width(flags);
    }
    else
    {
        representation = ToString_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(flags);
    }
    FieldToJson(jdata, representation, options);
}

// IID struct-as-enum special case:
inline void FieldToJson(nlohmann::ordered_json& jdata, const IID& value, const JsonOptions& options = JsonOptions())
{
    FieldToJson(jdata, ToString(value), options);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT)

#endif
