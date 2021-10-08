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
** This file is generated from dx12_enum_to_string_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_ENUM_TO_STRING_H
#define  GFXRECON_GENERATED_DX12_ENUM_TO_STRING_H

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
#include "util/to_stringh.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <> std::string ToString<DXGI_RESIDENCY>(const DXGI_RESIDENCY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_EFFECT>(const DXGI_SWAP_EFFECT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_CHAIN_FLAG>(const DXGI_SWAP_CHAIN_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_FLAG>(const DXGI_ADAPTER_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_POINTER_SHAPE_TYPE>(const DXGI_OUTDUPL_POINTER_SHAPE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ALPHA_MODE>(const DXGI_ALPHA_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OFFER_RESOURCE_PRIORITY>(const DXGI_OFFER_RESOURCE_PRIORITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SCALING>(const DXGI_SCALING& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_GRAPHICS_PREEMPTION_GRANULARITY>(const DXGI_GRAPHICS_PREEMPTION_GRANULARITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_COMPUTE_PREEMPTION_GRANULARITY>(const DXGI_COMPUTE_PREEMPTION_GRANULARITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>(const DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_FRAME_PRESENTATION_MODE>(const DXGI_FRAME_PRESENTATION_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OVERLAY_SUPPORT_FLAG>(const DXGI_OVERLAY_SUPPORT_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG>(const DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG>(const DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MEMORY_SEGMENT_GROUP>(const DXGI_MEMORY_SEGMENT_GROUP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OUTDUPL_FLAG>(const DXGI_OUTDUPL_FLAG& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_HDR_METADATA_TYPE>(const DXGI_HDR_METADATA_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OFFER_RESOURCE_FLAGS>(const DXGI_OFFER_RESOURCE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_OFFER_RESOURCE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_RECLAIM_RESOURCE_RESULTS>(const DXGI_RECLAIM_RESOURCE_RESULTS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_FEATURE>(const DXGI_FEATURE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_ADAPTER_FLAG3>(const DXGI_ADAPTER_FLAG3& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS>(const DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_GPU_PREFERENCE>(const DXGI_GPU_PREFERENCE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_COLOR_SPACE_TYPE>(const DXGI_COLOR_SPACE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_FORMAT>(const DXGI_FORMAT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MODE_SCANLINE_ORDER>(const DXGI_MODE_SCANLINE_ORDER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MODE_SCALING>(const DXGI_MODE_SCALING& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<DXGI_MODE_ROTATION>(const DXGI_MODE_ROTATION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_LIST_TYPE>(const D3D12_COMMAND_LIST_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_QUEUE_FLAGS>(const D3D12_COMMAND_QUEUE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_QUEUE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_QUEUE_PRIORITY>(const D3D12_COMMAND_QUEUE_PRIORITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PRIMITIVE_TOPOLOGY_TYPE>(const D3D12_PRIMITIVE_TOPOLOGY_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INPUT_CLASSIFICATION>(const D3D12_INPUT_CLASSIFICATION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FILL_MODE>(const D3D12_FILL_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CULL_MODE>(const D3D12_CULL_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMPARISON_FUNC>(const D3D12_COMPARISON_FUNC& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEPTH_WRITE_MASK>(const D3D12_DEPTH_WRITE_MASK& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STENCIL_OP>(const D3D12_STENCIL_OP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BLEND>(const D3D12_BLEND& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BLEND_OP>(const D3D12_BLEND_OP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COLOR_WRITE_ENABLE>(const D3D12_COLOR_WRITE_ENABLE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_LOGIC_OP>(const D3D12_LOGIC_OP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CONSERVATIVE_RASTERIZATION_MODE>(const D3D12_CONSERVATIVE_RASTERIZATION_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE>(const D3D12_INDEX_BUFFER_STRIP_CUT_VALUE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PIPELINE_STATE_FLAGS>(const D3D12_PIPELINE_STATE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PIPELINE_STATE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PIPELINE_STATE_SUBOBJECT_TYPE>(const D3D12_PIPELINE_STATE_SUBOBJECT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FEATURE>(const D3D12_FEATURE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_MIN_PRECISION_SUPPORT>(const D3D12_SHADER_MIN_PRECISION_SUPPORT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_MIN_PRECISION_SUPPORT>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILED_RESOURCES_TIER>(const D3D12_TILED_RESOURCES_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_BINDING_TIER>(const D3D12_RESOURCE_BINDING_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CONSERVATIVE_RASTERIZATION_TIER>(const D3D12_CONSERVATIVE_RASTERIZATION_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FORMAT_SUPPORT1>(const D3D12_FORMAT_SUPPORT1& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FORMAT_SUPPORT1>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FORMAT_SUPPORT2>(const D3D12_FORMAT_SUPPORT2& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FORMAT_SUPPORT2>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS>(const D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CROSS_NODE_SHARING_TIER>(const D3D12_CROSS_NODE_SHARING_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_HEAP_TIER>(const D3D12_RESOURCE_HEAP_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER>(const D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEW_INSTANCING_TIER>(const D3D12_VIEW_INSTANCING_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_ROOT_SIGNATURE_VERSION>(const D3D_ROOT_SIGNATURE_VERSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_MODEL>(const D3D_SHADER_MODEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_CACHE_SUPPORT_FLAGS>(const D3D12_SHADER_CACHE_SUPPORT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_CACHE_SUPPORT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_LIST_SUPPORT_FLAGS>(const D3D12_COMMAND_LIST_SUPPORT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_LIST_SUPPORT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER>(const D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_SERIALIZATION_TIER>(const D3D12_HEAP_SERIALIZATION_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_TIER>(const D3D12_RENDER_PASS_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_TIER>(const D3D12_RAYTRACING_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VARIABLE_SHADING_RATE_TIER>(const D3D12_VARIABLE_SHADING_RATE_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MESH_SHADER_TIER>(const D3D12_MESH_SHADER_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SAMPLER_FEEDBACK_TIER>(const D3D12_SAMPLER_FEEDBACK_TIER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_TYPE>(const D3D12_HEAP_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CPU_PAGE_PROPERTY>(const D3D12_CPU_PAGE_PROPERTY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MEMORY_POOL>(const D3D12_MEMORY_POOL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_FLAGS>(const D3D12_HEAP_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HEAP_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_DIMENSION>(const D3D12_RESOURCE_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEXTURE_LAYOUT>(const D3D12_TEXTURE_LAYOUT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_FLAGS>(const D3D12_RESOURCE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_RANGE_FLAGS>(const D3D12_TILE_RANGE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_RANGE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_MAPPING_FLAGS>(const D3D12_TILE_MAPPING_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_MAPPING_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_COPY_FLAGS>(const D3D12_TILE_COPY_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TILE_COPY_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_STATES>(const D3D12_RESOURCE_STATES& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_STATES>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_BARRIER_TYPE>(const D3D12_RESOURCE_BARRIER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_BARRIER_FLAGS>(const D3D12_RESOURCE_BARRIER_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOURCE_BARRIER_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEXTURE_COPY_TYPE>(const D3D12_TEXTURE_COPY_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESOLVE_MODE>(const D3D12_RESOLVE_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEW_INSTANCING_FLAGS>(const D3D12_VIEW_INSTANCING_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_VIEW_INSTANCING_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_COMPONENT_MAPPING>(const D3D12_SHADER_COMPONENT_MAPPING& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_SRV_FLAGS>(const D3D12_BUFFER_SRV_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_SRV_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SRV_DIMENSION>(const D3D12_SRV_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FILTER>(const D3D12_FILTER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FILTER_TYPE>(const D3D12_FILTER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FILTER_REDUCTION_TYPE>(const D3D12_FILTER_REDUCTION_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_TEXTURE_ADDRESS_MODE>(const D3D12_TEXTURE_ADDRESS_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_UAV_FLAGS>(const D3D12_BUFFER_UAV_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BUFFER_UAV_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_UAV_DIMENSION>(const D3D12_UAV_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RTV_DIMENSION>(const D3D12_RTV_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DSV_FLAGS>(const D3D12_DSV_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DSV_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DSV_DIMENSION>(const D3D12_DSV_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CLEAR_FLAGS>(const D3D12_CLEAR_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_CLEAR_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FENCE_FLAGS>(const D3D12_FENCE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_FENCE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_TYPE>(const D3D12_DESCRIPTOR_HEAP_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_FLAGS>(const D3D12_DESCRIPTOR_HEAP_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_HEAP_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_RANGE_TYPE>(const D3D12_DESCRIPTOR_RANGE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADER_VISIBILITY>(const D3D12_SHADER_VISIBILITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_PARAMETER_TYPE>(const D3D12_ROOT_PARAMETER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_SIGNATURE_FLAGS>(const D3D12_ROOT_SIGNATURE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_SIGNATURE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATIC_BORDER_COLOR>(const D3D12_STATIC_BORDER_COLOR& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_RANGE_FLAGS>(const D3D12_DESCRIPTOR_RANGE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DESCRIPTOR_RANGE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_FLAGS>(const D3D12_ROOT_DESCRIPTOR_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ROOT_DESCRIPTOR_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_HEAP_TYPE>(const D3D12_QUERY_HEAP_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_QUERY_TYPE>(const D3D12_QUERY_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PREDICATION_OP>(const D3D12_PREDICATION_OP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_INDIRECT_ARGUMENT_TYPE>(const D3D12_INDIRECT_ARGUMENT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_WRITEBUFFERIMMEDIATE_MODE>(const D3D12_WRITEBUFFERIMMEDIATE_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MULTIPLE_FENCE_WAIT_FLAGS>(const D3D12_MULTIPLE_FENCE_WAIT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MULTIPLE_FENCE_WAIT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESIDENCY_PRIORITY>(const D3D12_RESIDENCY_PRIORITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESIDENCY_FLAGS>(const D3D12_RESIDENCY_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RESIDENCY_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_LIST_FLAGS>(const D3D12_COMMAND_LIST_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_LIST_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_POOL_FLAGS>(const D3D12_COMMAND_POOL_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_POOL_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_RECORDER_FLAGS>(const D3D12_COMMAND_RECORDER_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_COMMAND_RECORDER_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_SESSION_STATUS>(const D3D12_PROTECTED_SESSION_STATUS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_SESSION_STATUS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS>(const D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_FLAGS>(const D3D12_PROTECTED_RESOURCE_SESSION_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_PROTECTED_RESOURCE_SESSION_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_LIFETIME_STATE>(const D3D12_LIFETIME_STATE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_TYPE>(const D3D12_META_COMMAND_PARAMETER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_FLAGS>(const D3D12_META_COMMAND_PARAMETER_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_META_COMMAND_PARAMETER_STAGE>(const D3D12_META_COMMAND_PARAMETER_STAGE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GRAPHICS_STATES>(const D3D12_GRAPHICS_STATES& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GRAPHICS_STATES>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATE_SUBOBJECT_TYPE>(const D3D12_STATE_SUBOBJECT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATE_OBJECT_FLAGS>(const D3D12_STATE_OBJECT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATE_OBJECT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_EXPORT_FLAGS>(const D3D12_EXPORT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_EXPORT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HIT_GROUP_TYPE>(const D3D12_HIT_GROUP_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_FLAGS>(const D3D12_RAYTRACING_PIPELINE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_PIPELINE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_STATE_OBJECT_TYPE>(const D3D12_STATE_OBJECT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_FLAGS>(const D3D12_RAYTRACING_GEOMETRY_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_GEOMETRY_TYPE>(const D3D12_RAYTRACING_GEOMETRY_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_INSTANCE_FLAGS>(const D3D12_RAYTRACING_INSTANCE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_INSTANCE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_ELEMENTS_LAYOUT>(const D3D12_ELEMENTS_LAYOUT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE>(const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SERIALIZED_DATA_TYPE>(const D3D12_SERIALIZED_DATA_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS>(const D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAY_FLAGS>(const D3D12_RAY_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RAY_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_HIT_KIND>(const D3D12_HIT_KIND& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_AUTO_BREADCRUMB_OP>(const D3D12_AUTO_BREADCRUMB_OP& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_VERSION>(const D3D12_DRED_VERSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_FLAGS>(const D3D12_DRED_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_ENABLEMENT>(const D3D12_DRED_ENABLEMENT& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DRED_ALLOCATION_TYPE>(const D3D12_DRED_ALLOCATION_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_BACKGROUND_PROCESSING_MODE>(const D3D12_BACKGROUND_PROCESSING_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MEASUREMENTS_ACTION>(const D3D12_MEASUREMENTS_ACTION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE>(const D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_ENDING_ACCESS_TYPE>(const D3D12_RENDER_PASS_ENDING_ACCESS_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_FLAGS>(const D3D12_RENDER_PASS_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RENDER_PASS_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_AXIS_SHADING_RATE>(const D3D12_AXIS_SHADING_RATE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADING_RATE>(const D3D12_SHADING_RATE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_SHADING_RATE_COMBINER>(const D3D12_SHADING_RATE_COMBINER& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_DRIVER_TYPE>(const D3D_DRIVER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_FEATURE_LEVEL>(const D3D_FEATURE_LEVEL& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_PRIMITIVE_TOPOLOGY>(const D3D_PRIMITIVE_TOPOLOGY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_PRIMITIVE>(const D3D_PRIMITIVE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SRV_DIMENSION>(const D3D_SRV_DIMENSION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_INCLUDE_TYPE>(const D3D_INCLUDE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_VARIABLE_CLASS>(const D3D_SHADER_VARIABLE_CLASS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_VARIABLE_FLAGS>(const D3D_SHADER_VARIABLE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_VARIABLE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_VARIABLE_TYPE>(const D3D_SHADER_VARIABLE_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_INPUT_FLAGS>(const D3D_SHADER_INPUT_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_INPUT_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_INPUT_TYPE>(const D3D_SHADER_INPUT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_CBUFFER_FLAGS>(const D3D_SHADER_CBUFFER_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_SHADER_CBUFFER_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_CBUFFER_TYPE>(const D3D_CBUFFER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_NAME>(const D3D_NAME& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_RESOURCE_RETURN_TYPE>(const D3D_RESOURCE_RETURN_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_REGISTER_COMPONENT_TYPE>(const D3D_REGISTER_COMPONENT_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_TESSELLATOR_DOMAIN>(const D3D_TESSELLATOR_DOMAIN& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_TESSELLATOR_PARTITIONING>(const D3D_TESSELLATOR_PARTITIONING& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_TESSELLATOR_OUTPUT_PRIMITIVE>(const D3D_TESSELLATOR_OUTPUT_PRIMITIVE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_MIN_PRECISION>(const D3D_MIN_PRECISION& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_INTERPOLATION_MODE>(const D3D_INTERPOLATION_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_PARAMETER_FLAGS>(const D3D_PARAMETER_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D_PARAMETER_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_BASED_VALIDATION_FLAGS>(const D3D12_GPU_BASED_VALIDATION_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_BASED_VALIDATION_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RLDO_FLAGS>(const D3D12_RLDO_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_RLDO_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_DEVICE_PARAMETER_TYPE>(const D3D12_DEBUG_DEVICE_PARAMETER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_FEATURE>(const D3D12_DEBUG_FEATURE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE>(const D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS>(const D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS>(uint32_t flags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE>(const D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MESSAGE_CATEGORY>(const D3D12_MESSAGE_CATEGORY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MESSAGE_SEVERITY>(const D3D12_MESSAGE_SEVERITY& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);
template <> std::string ToString<D3D12_MESSAGE_ID>(const D3D12_MESSAGE_ID& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
