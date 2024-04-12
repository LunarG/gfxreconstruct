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
** This file is generated from dx12_enum_to_string_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_ENUM_TO_STRING_H
#define  GFXRECON_GENERATED_DX12_ENUM_TO_STRING_H

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#ifdef WIN32
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
#endif // WIN32

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string ToString(DXGI_RESIDENCY value);
std::string ToString(DXGI_SWAP_EFFECT value);
std::string ToString(DXGI_SWAP_CHAIN_FLAG value);
std::string ToString(DXGI_ADAPTER_FLAG value);
std::string ToString(DXGI_OUTDUPL_POINTER_SHAPE_TYPE value);
std::string ToString(DXGI_ALPHA_MODE value);
std::string ToString(DXGI_OFFER_RESOURCE_PRIORITY value);
std::string ToString(DXGI_SCALING value);
std::string ToString(DXGI_GRAPHICS_PREEMPTION_GRANULARITY value);
std::string ToString(DXGI_COMPUTE_PREEMPTION_GRANULARITY value);
std::string ToString(DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS value);
std::string ToString_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(uint32_t flags);
std::string ToString(DXGI_FRAME_PRESENTATION_MODE value);
std::string ToString(DXGI_OVERLAY_SUPPORT_FLAG value);
std::string ToString(DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG value);
std::string ToString(DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG value);
std::string ToString(DXGI_MEMORY_SEGMENT_GROUP value);
std::string ToString(DXGI_OUTDUPL_FLAG value);
std::string ToString(DXGI_HDR_METADATA_TYPE value);
std::string ToString(DXGI_OFFER_RESOURCE_FLAGS value);
std::string ToString_DXGI_OFFER_RESOURCE_FLAGS(uint32_t flags);
std::string ToString(DXGI_RECLAIM_RESOURCE_RESULTS value);
std::string ToString(DXGI_FEATURE value);
std::string ToString(DXGI_ADAPTER_FLAG3 value);
std::string ToString(DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS value);
std::string ToString_DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS(uint32_t flags);
std::string ToString(DXGI_GPU_PREFERENCE value);
std::string ToString(DXGI_COLOR_SPACE_TYPE value);
std::string ToString(DXGI_FORMAT value);
std::string ToString(DXGI_MODE_SCANLINE_ORDER value);
std::string ToString(DXGI_MODE_SCALING value);
std::string ToString(DXGI_MODE_ROTATION value);
std::string ToString(D3D12_COMMAND_LIST_TYPE value);
std::string ToString(D3D12_COMMAND_QUEUE_FLAGS value);
std::string ToString_D3D12_COMMAND_QUEUE_FLAGS(uint32_t flags);
std::string ToString(D3D12_COMMAND_QUEUE_PRIORITY value);
std::string ToString(D3D12_PRIMITIVE_TOPOLOGY_TYPE value);
std::string ToString(D3D12_INPUT_CLASSIFICATION value);
std::string ToString(D3D12_FILL_MODE value);
std::string ToString(D3D12_CULL_MODE value);
std::string ToString(D3D12_COMPARISON_FUNC value);
std::string ToString(D3D12_DEPTH_WRITE_MASK value);
std::string ToString(D3D12_STENCIL_OP value);
std::string ToString(D3D12_BLEND value);
std::string ToString(D3D12_BLEND_OP value);
std::string ToString(D3D12_COLOR_WRITE_ENABLE value);
std::string ToString(D3D12_LOGIC_OP value);
std::string ToString(D3D12_CONSERVATIVE_RASTERIZATION_MODE value);
std::string ToString(D3D12_LINE_RASTERIZATION_MODE value);
std::string ToString(D3D12_INDEX_BUFFER_STRIP_CUT_VALUE value);
std::string ToString(D3D12_PIPELINE_STATE_FLAGS value);
std::string ToString_D3D12_PIPELINE_STATE_FLAGS(uint32_t flags);
std::string ToString(D3D12_PIPELINE_STATE_SUBOBJECT_TYPE value);
std::string ToString(D3D12_FEATURE value);
std::string ToString(D3D12_SHADER_MIN_PRECISION_SUPPORT value);
std::string ToString_D3D12_SHADER_MIN_PRECISION_SUPPORT(uint32_t flags);
std::string ToString(D3D12_TILED_RESOURCES_TIER value);
std::string ToString(D3D12_RESOURCE_BINDING_TIER value);
std::string ToString(D3D12_CONSERVATIVE_RASTERIZATION_TIER value);
std::string ToString(D3D12_FORMAT_SUPPORT1 value);
std::string ToString_D3D12_FORMAT_SUPPORT1(uint32_t flags);
std::string ToString(D3D12_FORMAT_SUPPORT2 value);
std::string ToString_D3D12_FORMAT_SUPPORT2(uint32_t flags);
std::string ToString(D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS value);
std::string ToString_D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS(uint32_t flags);
std::string ToString(D3D12_CROSS_NODE_SHARING_TIER value);
std::string ToString(D3D12_RESOURCE_HEAP_TIER value);
std::string ToString(D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER value);
std::string ToString(D3D12_VIEW_INSTANCING_TIER value);
std::string ToString(D3D_ROOT_SIGNATURE_VERSION value);
std::string ToString(D3D_SHADER_MODEL value);
std::string ToString(D3D12_SHADER_CACHE_SUPPORT_FLAGS value);
std::string ToString_D3D12_SHADER_CACHE_SUPPORT_FLAGS(uint32_t flags);
std::string ToString(D3D12_COMMAND_LIST_SUPPORT_FLAGS value);
std::string ToString_D3D12_COMMAND_LIST_SUPPORT_FLAGS(uint32_t flags);
std::string ToString(D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER value);
std::string ToString(D3D12_HEAP_SERIALIZATION_TIER value);
std::string ToString(D3D12_RENDER_PASS_TIER value);
std::string ToString(D3D12_RAYTRACING_TIER value);
std::string ToString(D3D12_VARIABLE_SHADING_RATE_TIER value);
std::string ToString(D3D12_MESH_SHADER_TIER value);
std::string ToString(D3D12_SAMPLER_FEEDBACK_TIER value);
std::string ToString(D3D12_WAVE_MMA_TIER value);
std::string ToString(D3D12_TRI_STATE value);
std::string ToString(D3D12_HEAP_TYPE value);
std::string ToString(D3D12_CPU_PAGE_PROPERTY value);
std::string ToString(D3D12_MEMORY_POOL value);
std::string ToString(D3D12_HEAP_FLAGS value);
std::string ToString_D3D12_HEAP_FLAGS(uint32_t flags);
std::string ToString(D3D12_RESOURCE_DIMENSION value);
std::string ToString(D3D12_TEXTURE_LAYOUT value);
std::string ToString(D3D12_RESOURCE_FLAGS value);
std::string ToString_D3D12_RESOURCE_FLAGS(uint32_t flags);
std::string ToString(D3D12_TILE_RANGE_FLAGS value);
std::string ToString_D3D12_TILE_RANGE_FLAGS(uint32_t flags);
std::string ToString(D3D12_TILE_MAPPING_FLAGS value);
std::string ToString_D3D12_TILE_MAPPING_FLAGS(uint32_t flags);
std::string ToString(D3D12_TILE_COPY_FLAGS value);
std::string ToString_D3D12_TILE_COPY_FLAGS(uint32_t flags);
std::string ToString(D3D12_RESOURCE_STATES value);
std::string ToString_D3D12_RESOURCE_STATES(uint32_t flags);
std::string ToString(D3D12_RESOURCE_BARRIER_TYPE value);
std::string ToString(D3D12_RESOURCE_BARRIER_FLAGS value);
std::string ToString_D3D12_RESOURCE_BARRIER_FLAGS(uint32_t flags);
std::string ToString(D3D12_TEXTURE_COPY_TYPE value);
std::string ToString(D3D12_RESOLVE_MODE value);
std::string ToString(D3D12_VIEW_INSTANCING_FLAGS value);
std::string ToString_D3D12_VIEW_INSTANCING_FLAGS(uint32_t flags);
std::string ToString(D3D12_SHADER_COMPONENT_MAPPING value);
std::string ToString(D3D12_BUFFER_SRV_FLAGS value);
std::string ToString_D3D12_BUFFER_SRV_FLAGS(uint32_t flags);
std::string ToString(D3D12_SRV_DIMENSION value);
std::string ToString(D3D12_FILTER value);
std::string ToString(D3D12_FILTER_TYPE value);
std::string ToString(D3D12_FILTER_REDUCTION_TYPE value);
std::string ToString(D3D12_TEXTURE_ADDRESS_MODE value);
std::string ToString(D3D12_SAMPLER_FLAGS value);
std::string ToString_D3D12_SAMPLER_FLAGS(uint32_t flags);
std::string ToString(D3D12_BUFFER_UAV_FLAGS value);
std::string ToString_D3D12_BUFFER_UAV_FLAGS(uint32_t flags);
std::string ToString(D3D12_UAV_DIMENSION value);
std::string ToString(D3D12_RTV_DIMENSION value);
std::string ToString(D3D12_DSV_FLAGS value);
std::string ToString_D3D12_DSV_FLAGS(uint32_t flags);
std::string ToString(D3D12_DSV_DIMENSION value);
std::string ToString(D3D12_CLEAR_FLAGS value);
std::string ToString_D3D12_CLEAR_FLAGS(uint32_t flags);
std::string ToString(D3D12_FENCE_FLAGS value);
std::string ToString_D3D12_FENCE_FLAGS(uint32_t flags);
std::string ToString(D3D12_DESCRIPTOR_HEAP_TYPE value);
std::string ToString(D3D12_DESCRIPTOR_HEAP_FLAGS value);
std::string ToString_D3D12_DESCRIPTOR_HEAP_FLAGS(uint32_t flags);
std::string ToString(D3D12_DESCRIPTOR_RANGE_TYPE value);
std::string ToString(D3D12_SHADER_VISIBILITY value);
std::string ToString(D3D12_ROOT_PARAMETER_TYPE value);
std::string ToString(D3D12_ROOT_SIGNATURE_FLAGS value);
std::string ToString_D3D12_ROOT_SIGNATURE_FLAGS(uint32_t flags);
std::string ToString(D3D12_STATIC_BORDER_COLOR value);
std::string ToString(D3D12_DESCRIPTOR_RANGE_FLAGS value);
std::string ToString_D3D12_DESCRIPTOR_RANGE_FLAGS(uint32_t flags);
std::string ToString(D3D12_ROOT_DESCRIPTOR_FLAGS value);
std::string ToString_D3D12_ROOT_DESCRIPTOR_FLAGS(uint32_t flags);
std::string ToString(D3D12_QUERY_HEAP_TYPE value);
std::string ToString(D3D12_QUERY_TYPE value);
std::string ToString(D3D12_PREDICATION_OP value);
std::string ToString(D3D12_INDIRECT_ARGUMENT_TYPE value);
std::string ToString(D3D12_WRITEBUFFERIMMEDIATE_MODE value);
std::string ToString(D3D12_MULTIPLE_FENCE_WAIT_FLAGS value);
std::string ToString_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(uint32_t flags);
std::string ToString(D3D12_RESIDENCY_PRIORITY value);
std::string ToString(D3D12_RESIDENCY_FLAGS value);
std::string ToString_D3D12_RESIDENCY_FLAGS(uint32_t flags);
std::string ToString(D3D12_COMMAND_LIST_FLAGS value);
std::string ToString_D3D12_COMMAND_LIST_FLAGS(uint32_t flags);
std::string ToString(D3D12_COMMAND_POOL_FLAGS value);
std::string ToString_D3D12_COMMAND_POOL_FLAGS(uint32_t flags);
std::string ToString(D3D12_COMMAND_RECORDER_FLAGS value);
std::string ToString_D3D12_COMMAND_RECORDER_FLAGS(uint32_t flags);
std::string ToString(D3D12_PROTECTED_SESSION_STATUS value);
std::string ToString_D3D12_PROTECTED_SESSION_STATUS(uint32_t flags);
std::string ToString(D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS value);
std::string ToString_D3D12_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAGS(uint32_t flags);
std::string ToString(D3D12_PROTECTED_RESOURCE_SESSION_FLAGS value);
std::string ToString_D3D12_PROTECTED_RESOURCE_SESSION_FLAGS(uint32_t flags);
std::string ToString(D3D12_LIFETIME_STATE value);
std::string ToString(D3D12_META_COMMAND_PARAMETER_TYPE value);
std::string ToString(D3D12_META_COMMAND_PARAMETER_FLAGS value);
std::string ToString_D3D12_META_COMMAND_PARAMETER_FLAGS(uint32_t flags);
std::string ToString(D3D12_META_COMMAND_PARAMETER_STAGE value);
std::string ToString(D3D12_GRAPHICS_STATES value);
std::string ToString_D3D12_GRAPHICS_STATES(uint32_t flags);
std::string ToString(D3D12_STATE_SUBOBJECT_TYPE value);
std::string ToString(D3D12_STATE_OBJECT_FLAGS value);
std::string ToString_D3D12_STATE_OBJECT_FLAGS(uint32_t flags);
std::string ToString(D3D12_EXPORT_FLAGS value);
std::string ToString_D3D12_EXPORT_FLAGS(uint32_t flags);
std::string ToString(D3D12_HIT_GROUP_TYPE value);
std::string ToString(D3D12_RAYTRACING_PIPELINE_FLAGS value);
std::string ToString_D3D12_RAYTRACING_PIPELINE_FLAGS(uint32_t flags);
std::string ToString(D3D12_STATE_OBJECT_TYPE value);
std::string ToString(D3D12_RAYTRACING_GEOMETRY_FLAGS value);
std::string ToString_D3D12_RAYTRACING_GEOMETRY_FLAGS(uint32_t flags);
std::string ToString(D3D12_RAYTRACING_GEOMETRY_TYPE value);
std::string ToString(D3D12_RAYTRACING_INSTANCE_FLAGS value);
std::string ToString_D3D12_RAYTRACING_INSTANCE_FLAGS(uint32_t flags);
std::string ToString(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value);
std::string ToString_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(uint32_t flags);
std::string ToString(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE value);
std::string ToString(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE value);
std::string ToString(D3D12_ELEMENTS_LAYOUT value);
std::string ToString(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE value);
std::string ToString(D3D12_SERIALIZED_DATA_TYPE value);
std::string ToString(D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS value);
std::string ToString_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(uint32_t flags);
std::string ToString(D3D12_RAY_FLAGS value);
std::string ToString_D3D12_RAY_FLAGS(uint32_t flags);
std::string ToString(D3D12_HIT_KIND value);
std::string ToString(D3D12_AUTO_BREADCRUMB_OP value);
std::string ToString(D3D12_DRED_VERSION value);
std::string ToString(D3D12_DRED_FLAGS value);
std::string ToString_D3D12_DRED_FLAGS(uint32_t flags);
std::string ToString(D3D12_DRED_ENABLEMENT value);
std::string ToString(D3D12_DRED_ALLOCATION_TYPE value);
std::string ToString(D3D12_DRED_PAGE_FAULT_FLAGS value);
std::string ToString_D3D12_DRED_PAGE_FAULT_FLAGS(uint32_t flags);
std::string ToString(D3D12_DRED_DEVICE_STATE value);
std::string ToString(D3D12_BACKGROUND_PROCESSING_MODE value);
std::string ToString(D3D12_MEASUREMENTS_ACTION value);
std::string ToString(D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE value);
std::string ToString(D3D12_RENDER_PASS_ENDING_ACCESS_TYPE value);
std::string ToString(D3D12_RENDER_PASS_FLAGS value);
std::string ToString_D3D12_RENDER_PASS_FLAGS(uint32_t flags);
std::string ToString(D3D12_SHADER_CACHE_MODE value);
std::string ToString(D3D12_SHADER_CACHE_FLAGS value);
std::string ToString_D3D12_SHADER_CACHE_FLAGS(uint32_t flags);
std::string ToString(D3D12_BARRIER_LAYOUT value);
std::string ToString(D3D12_BARRIER_SYNC value);
std::string ToString(D3D12_BARRIER_ACCESS value);
std::string ToString(D3D12_BARRIER_TYPE value);
std::string ToString(D3D12_TEXTURE_BARRIER_FLAGS value);
std::string ToString_D3D12_TEXTURE_BARRIER_FLAGS(uint32_t flags);
std::string ToString(D3D12_SHADER_CACHE_KIND_FLAGS value);
std::string ToString_D3D12_SHADER_CACHE_KIND_FLAGS(uint32_t flags);
std::string ToString(D3D12_SHADER_CACHE_CONTROL_FLAGS value);
std::string ToString_D3D12_SHADER_CACHE_CONTROL_FLAGS(uint32_t flags);
std::string ToString(D3D12_DEVICE_FACTORY_FLAGS value);
std::string ToString_D3D12_DEVICE_FACTORY_FLAGS(uint32_t flags);
std::string ToString(D3D12_DEVICE_FLAGS value);
std::string ToString_D3D12_DEVICE_FLAGS(uint32_t flags);
std::string ToString(D3D12_AXIS_SHADING_RATE value);
std::string ToString(D3D12_SHADING_RATE value);
std::string ToString(D3D12_SHADING_RATE_COMBINER value);
std::string ToString(D3D_DRIVER_TYPE value);
std::string ToString(D3D_FEATURE_LEVEL value);
std::string ToString(D3D_PRIMITIVE_TOPOLOGY value);
std::string ToString(D3D_PRIMITIVE value);
std::string ToString(D3D_SRV_DIMENSION value);
std::string ToString(D3D_INCLUDE_TYPE value);
std::string ToString(D3D_SHADER_VARIABLE_CLASS value);
std::string ToString(D3D_SHADER_VARIABLE_FLAGS value);
std::string ToString_D3D_SHADER_VARIABLE_FLAGS(uint32_t flags);
std::string ToString(D3D_SHADER_VARIABLE_TYPE value);
std::string ToString(D3D_SHADER_INPUT_FLAGS value);
std::string ToString_D3D_SHADER_INPUT_FLAGS(uint32_t flags);
std::string ToString(D3D_SHADER_INPUT_TYPE value);
std::string ToString(D3D_SHADER_CBUFFER_FLAGS value);
std::string ToString_D3D_SHADER_CBUFFER_FLAGS(uint32_t flags);
std::string ToString(D3D_CBUFFER_TYPE value);
std::string ToString(D3D_NAME value);
std::string ToString(D3D_RESOURCE_RETURN_TYPE value);
std::string ToString(D3D_REGISTER_COMPONENT_TYPE value);
std::string ToString(D3D_TESSELLATOR_DOMAIN value);
std::string ToString(D3D_TESSELLATOR_PARTITIONING value);
std::string ToString(D3D_TESSELLATOR_OUTPUT_PRIMITIVE value);
std::string ToString(D3D_MIN_PRECISION value);
std::string ToString(D3D_INTERPOLATION_MODE value);
std::string ToString(D3D_PARAMETER_FLAGS value);
std::string ToString_D3D_PARAMETER_FLAGS(uint32_t flags);
std::string ToString(D3D_FORMAT_LAYOUT value);
std::string ToString(D3D_FORMAT_TYPE_LEVEL value);
std::string ToString(D3D_FORMAT_COMPONENT_NAME value);
std::string ToString(D3D_FORMAT_COMPONENT_INTERPRETATION value);
std::string ToString(D3D12_GPU_BASED_VALIDATION_FLAGS value);
std::string ToString_D3D12_GPU_BASED_VALIDATION_FLAGS(uint32_t flags);
std::string ToString(D3D12_RLDO_FLAGS value);
std::string ToString_D3D12_RLDO_FLAGS(uint32_t flags);
std::string ToString(D3D12_DEBUG_DEVICE_PARAMETER_TYPE value);
std::string ToString(D3D12_DEBUG_FEATURE value);
std::string ToString(D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE value);
std::string ToString(D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS value);
std::string ToString_D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS(uint32_t flags);
std::string ToString(D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE value);
std::string ToString(D3D12_MESSAGE_CATEGORY value);
std::string ToString(D3D12_MESSAGE_SEVERITY value);
std::string ToString(D3D12_MESSAGE_ID value);
std::string ToString(D3D12_MESSAGE_CALLBACK_FLAGS value);
std::string ToString_D3D12_MESSAGE_CALLBACK_FLAGS(uint32_t flags);
std::string ToString(const IID& riid);
inline std::string ToString(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize){ return ToString(obj); }

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#endif
